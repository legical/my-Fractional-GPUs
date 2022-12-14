#include <algorithm>
#include <cmath>
#include <vector>

#include "caffe/layer.hpp"
#include "caffe/layers/lstm_layer.hpp"

#ifdef USE_FGPU
#include <fractional_gpu_cuda.cuh>
#endif

namespace caffe {

template <typename Dtype>
__device__ Dtype sigmoid(const Dtype x) {
  return Dtype(1) / (Dtype(1) + exp(-x));
}

template <typename Dtype>
__device__ Dtype tanh(const Dtype x) {
  return Dtype(2) * sigmoid(Dtype(2) * x) - Dtype(1);
}

#ifndef USE_FGPU
template <typename Dtype>
__global__ void LSTMActsForward(const int nthreads, const int dim,
                                const Dtype* X, Dtype* X_acts) {
  CUDA_KERNEL_LOOP(index, nthreads) {
    const int x_dim = 4 * dim;
    const int d = index % x_dim;
    if (d < 3 * dim) {
      X_acts[index] = sigmoid(X[index]);
    } else {
      X_acts[index] = tanh(X[index]);
    }
  }
}

template <typename Dtype>
__global__ void LSTMUnitForward(const int nthreads, const int dim,
    const Dtype* C_prev, const Dtype* X, const Dtype* cont,
    Dtype* C, Dtype* H) {
  CUDA_KERNEL_LOOP(index, nthreads) {
    const int n = index / dim;
    const int d = index % dim;
    const Dtype* X_offset = X + 4 * dim * n;
    const Dtype i = X_offset[d];
    const Dtype f = X_offset[1 * dim + d];
    const Dtype o = X_offset[2 * dim + d];
    const Dtype g = X_offset[3 * dim + d];
    const Dtype c_prev = C_prev[index];
    const Dtype c = cont[n] * f * c_prev + i * g;
    C[index] = c;
    const Dtype tanh_c = tanh(c);
    H[index] = o * tanh_c;
  }
}

template <typename Dtype>
__global__ void LSTMUnitBackward(const int nthreads, const int dim,
    const Dtype* C_prev, const Dtype* X, const Dtype* C, const Dtype* H,
    const Dtype* cont, const Dtype* C_diff, const Dtype* H_diff,
    Dtype* C_prev_diff, Dtype* X_diff) {
  CUDA_KERNEL_LOOP(index, nthreads) {
    const int n = index / dim;
    const int d = index % dim;
    const Dtype* X_offset = X + 4 * dim * n;
    const Dtype i = X_offset[d];
    const Dtype f = X_offset[1 * dim + d];
    const Dtype o = X_offset[2 * dim + d];
    const Dtype g = X_offset[3 * dim + d];
    const Dtype c_prev = C_prev[index];
    const Dtype c = C[index];
    const Dtype tanh_c = tanh(c);
    Dtype* c_prev_diff = C_prev_diff + index;
    Dtype* X_diff_offset = X_diff + 4 * dim * n;
    Dtype* i_diff = X_diff_offset + d;
    Dtype* f_diff = X_diff_offset + 1 * dim + d;
    Dtype* o_diff = X_diff_offset + 2 * dim + d;
    Dtype* g_diff = X_diff_offset + 3 * dim + d;
    const Dtype c_term_diff =
        C_diff[index] + H_diff[index] * o * (1 - tanh_c * tanh_c);
    const Dtype cont_n = cont[n];
    *c_prev_diff = cont_n * c_term_diff * f;
    *i_diff = c_term_diff * g;
    *f_diff = cont_n * c_term_diff * c_prev;
    *o_diff = H_diff[index] * tanh_c;
    *g_diff = c_term_diff * i;
  }
}

template <typename Dtype>
__global__ void LSTMActsBackward(const int nthreads, const int dim,
    const Dtype* X_acts, const Dtype* X_acts_diff, Dtype* X_diff) {
  CUDA_KERNEL_LOOP(index, nthreads) {
    const int x_dim = 4 * dim;
    const int d = index % x_dim;
    const Dtype X_act = X_acts[index];
    if (d < 3 * dim) {
      X_diff[index] = X_acts_diff[index] * X_act * (Dtype(1) - X_act);
    } else {
      X_diff[index] = X_acts_diff[index] * (Dtype(1) - X_act * X_act);
    }
  }
}
#else // USE_FGPU

template <typename Dtype>
__global__ FGPU_DEFINE_KERNEL(LSTMActsForward, const int nthreads, const int dim,
                                const Dtype* X, Dtype* X_acts) {

  fgpu_dev_ctx_t *ctx;
  dim3 _blockIdx, _gridDim;
  ctx = FGPU_DEVICE_INIT();
  _gridDim = FGPU_GET_GRIDDIM(ctx);

  FGPU_FOR_EACH_DEVICE_BLOCK(_blockIdx) {

    CUDA_KERNEL_LOOP(index, nthreads, _blockIdx, _gridDim) {
      const int x_dim = 4 * dim;
      const int d = index % x_dim;
      Dtype X_val = FGPU_COLOR_LOAD(ctx, &X[index]);
      if (d < 3 * dim) {
        FGPU_COLOR_STORE(ctx, &X_acts[index], sigmoid(X_val));
      } else {
        FGPU_COLOR_STORE(ctx, &X_acts[index], tanh(X_val));
      }
    }

  }
}

template <typename Dtype>
__global__ FGPU_DEFINE_KERNEL(LSTMUnitForward, const int nthreads, const int dim,
    const Dtype* C_prev, const Dtype* X, const Dtype* cont,
    Dtype* C, Dtype* H) {

  fgpu_dev_ctx_t *ctx;
  dim3 _blockIdx, _gridDim;
  ctx = FGPU_DEVICE_INIT();
  _gridDim = FGPU_GET_GRIDDIM(ctx);

  FGPU_FOR_EACH_DEVICE_BLOCK(_blockIdx) {

    CUDA_KERNEL_LOOP(index, nthreads, _blockIdx, _gridDim) {
      const int n = index / dim;
      const int d = index % dim;
      const Dtype* X_offset = X + 4 * dim * n;
      const Dtype i = FGPU_COLOR_LOAD(ctx, &X_offset[d]);
      const Dtype f = FGPU_COLOR_LOAD(ctx, &X_offset[1 * dim + d]);
      const Dtype o = FGPU_COLOR_LOAD(ctx, &X_offset[2 * dim + d]);
      const Dtype g = FGPU_COLOR_LOAD(ctx, &X_offset[3 * dim + d]);
      const Dtype c_prev = FGPU_COLOR_LOAD(ctx, &C_prev[index]);
      const Dtype c = FGPU_COLOR_LOAD(ctx, &cont[n]) * f * c_prev + i * g;
      FGPU_COLOR_STORE(ctx, &C[index], c);
      const Dtype tanh_c = tanh(c);
      FGPU_COLOR_STORE(ctx, &H[index],  o * tanh_c);
    }

  }
}

template <typename Dtype>
__global__ FGPU_DEFINE_KERNEL(LSTMUnitBackward, const int nthreads, const int dim,
    const Dtype* C_prev, const Dtype* X, const Dtype* C, const Dtype* H,
    const Dtype* cont, const Dtype* C_diff, const Dtype* H_diff,
    Dtype* C_prev_diff, Dtype* X_diff) {

  fgpu_dev_ctx_t *ctx;
  dim3 _blockIdx, _gridDim;
  ctx = FGPU_DEVICE_INIT();
  _gridDim = FGPU_GET_GRIDDIM(ctx);

  FGPU_FOR_EACH_DEVICE_BLOCK(_blockIdx) {

    CUDA_KERNEL_LOOP(index, nthreads, _blockIdx, _gridDim) {
      const int n = index / dim;
      const int d = index % dim;
      const Dtype* X_offset = X + 4 * dim * n;
      const Dtype i = FGPU_COLOR_LOAD(ctx, &X_offset[d]);
      const Dtype f = FGPU_COLOR_LOAD(ctx, &X_offset[1 * dim + d]);
      const Dtype o = FGPU_COLOR_LOAD(ctx, &X_offset[2 * dim + d]);
      const Dtype g = FGPU_COLOR_LOAD(ctx, &X_offset[3 * dim + d]);
      const Dtype c_prev = FGPU_COLOR_LOAD(ctx, &C_prev[index]);
      const Dtype c = FGPU_COLOR_LOAD(ctx, &C[index]);
      const Dtype tanh_c = tanh(c);
      Dtype* c_prev_diff = C_prev_diff + index;
      Dtype* X_diff_offset = X_diff + 4 * dim * n;
      Dtype* i_diff = X_diff_offset + d;
      Dtype* f_diff = X_diff_offset + 1 * dim + d;
      Dtype* o_diff = X_diff_offset + 2 * dim + d;
      Dtype* g_diff = X_diff_offset + 3 * dim + d;
      Dtype H_diff_val = FGPU_COLOR_LOAD(ctx, &H_diff[index]);
      const Dtype c_term_diff =
          FGPU_COLOR_LOAD(ctx, &C_diff[index]) + H_diff_val * o * (1 - tanh_c * tanh_c);
      const Dtype cont_n = FGPU_COLOR_LOAD(ctx, &cont[n]);
      FGPU_COLOR_STORE(ctx, c_prev_diff, cont_n * c_term_diff * f);
      FGPU_COLOR_STORE(ctx, i_diff, c_term_diff * g);
      FGPU_COLOR_STORE(ctx, f_diff, cont_n * c_term_diff * c_prev);
      FGPU_COLOR_STORE(ctx, o_diff, H_diff_val * tanh_c);
      FGPU_COLOR_STORE(ctx, g_diff, c_term_diff * i);
    }

  }
}

template <typename Dtype>
__global__ FGPU_DEFINE_KERNEL(LSTMActsBackward, const int nthreads, const int dim,
    const Dtype* X_acts, const Dtype* X_acts_diff, Dtype* X_diff) {

  fgpu_dev_ctx_t *ctx;
  dim3 _blockIdx, _gridDim;
  ctx = FGPU_DEVICE_INIT();
  _gridDim = FGPU_GET_GRIDDIM(ctx);

  FGPU_FOR_EACH_DEVICE_BLOCK(_blockIdx) {

    CUDA_KERNEL_LOOP(index, nthreads, _blockIdx, _gridDim) {
      const int x_dim = 4 * dim;
      const int d = index % x_dim;
      const Dtype X_act = FGPU_COLOR_LOAD(ctx, &X_acts[index]);
      if (d < 3 * dim) {
        FGPU_COLOR_STORE(ctx, &X_diff[index],
                FGPU_COLOR_LOAD(ctx, &X_acts_diff[index]) * X_act * (Dtype(1) - X_act));
      } else {
        FGPU_COLOR_STORE(ctx, &X_diff[index], 
                FGPU_COLOR_LOAD(ctx, &X_acts_diff[index]) * (Dtype(1) - X_act * X_act));
      }
    }

  }
}

#endif // USE_FGPU

template <typename Dtype>
void LSTMUnitLayer<Dtype>::Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top) {
  const int count = top[1]->count();
  const Dtype* C_prev = bottom[0]->gpu_data();
  const Dtype* X = bottom[1]->gpu_data();
  const Dtype* cont = bottom[2]->gpu_data();
  Dtype* X_acts = X_acts_.mutable_gpu_data();
  Dtype* C = top[0]->mutable_gpu_data();
  Dtype* H = top[1]->mutable_gpu_data();
  const int X_count = bottom[1]->count();
#ifndef USE_FGPU
  // NOLINT_NEXT_LINE(whitespace/operators)
  LSTMActsForward<Dtype><<<CAFFE_GET_BLOCKS(X_count), CAFFE_CUDA_NUM_THREADS>>>(
      X_count, hidden_dim_, X, X_acts);
  CUDA_POST_KERNEL_CHECK;
  // NOLINT_NEXT_LINE(whitespace/operators)
  LSTMUnitForward<Dtype><<<CAFFE_GET_BLOCKS(count), CAFFE_CUDA_NUM_THREADS>>>(
      count, hidden_dim_, C_prev, X_acts, cont, C, H);
  CUDA_POST_KERNEL_CHECK;
#else
  FGPU_CHECK(FGPU_LAUNCH_KERNEL(LSTMActsForward<Dtype>,
      CAFFE_GET_BLOCKS(X_count), CAFFE_CUDA_NUM_THREADS, 0,
      X_count, hidden_dim_, X, X_acts));
  FGPU_CHECK(FGPU_LAUNCH_KERNEL(LSTMUnitForward<Dtype>,
      CAFFE_GET_BLOCKS(count), CAFFE_CUDA_NUM_THREADS, 0,
      count, hidden_dim_, C_prev, X_acts, cont, C, H));
#endif
}

template <typename Dtype>
void LSTMUnitLayer<Dtype>::Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down,
    const vector<Blob<Dtype>*>& bottom) {
  CHECK(!propagate_down[2]) << "Cannot backpropagate to sequence indicators.";
  if (!propagate_down[0] && !propagate_down[1]) { return; }

  const int count = top[1]->count();
  const Dtype* C_prev = bottom[0]->gpu_data();
  const Dtype* X_acts = X_acts_.gpu_data();
  const Dtype* cont = bottom[2]->gpu_data();
  const Dtype* C = top[0]->gpu_data();
  const Dtype* H = top[1]->gpu_data();
  const Dtype* C_diff = top[0]->gpu_diff();
  const Dtype* H_diff = top[1]->gpu_diff();
  Dtype* C_prev_diff = bottom[0]->mutable_gpu_diff();
  Dtype* X_acts_diff = X_acts_.mutable_gpu_diff();
#ifndef USE_FGPU
  LSTMUnitBackward<Dtype>  // NOLINT_NEXT_LINE(whitespace/operators)
      <<<CAFFE_GET_BLOCKS(count), CAFFE_CUDA_NUM_THREADS>>>(count, hidden_dim_,
      C_prev, X_acts, C, H, cont, C_diff, H_diff, C_prev_diff, X_acts_diff);
  CUDA_POST_KERNEL_CHECK;
#else
  FGPU_CHECK(FGPU_LAUNCH_KERNEL(LSTMUnitBackward<Dtype>,  // NOLINT_NEXT_LINE(whitespace/operators)
      CAFFE_GET_BLOCKS(count), CAFFE_CUDA_NUM_THREADS, 0, count, hidden_dim_,
      C_prev, X_acts, C, H, cont, C_diff, H_diff, C_prev_diff, X_acts_diff));
#endif
  const int X_count = bottom[1]->count();
  Dtype* X_diff = bottom[1]->mutable_gpu_diff();
#ifndef USE_FGPU
  LSTMActsBackward<Dtype>  // NOLINT_NEXT_LINE(whitespace/operators)
      <<<CAFFE_GET_BLOCKS(X_count), CAFFE_CUDA_NUM_THREADS>>>(
      X_count, hidden_dim_, X_acts, X_acts_diff, X_diff);
  CUDA_POST_KERNEL_CHECK;
#else
  FGPU_CHECK(FGPU_LAUNCH_KERNEL(LSTMActsBackward<Dtype>,  // NOLINT_NEXT_LINE(whitespace/operators)
      CAFFE_GET_BLOCKS(X_count), CAFFE_CUDA_NUM_THREADS, 0,
      X_count, hidden_dim_, X_acts, X_acts_diff, X_diff));
#endif
}

INSTANTIATE_LAYER_GPU_FUNCS(LSTMUnitLayer);

}  // namespace caffe
