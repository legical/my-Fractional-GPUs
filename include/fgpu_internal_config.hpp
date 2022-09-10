/* This file contains configurable macros */
#ifndef __FGPU_INTERNAL_CONFIG_HPP__
#define __FGPU_INTERNAL_CONFIG_HPP__

#include <g_nvconfig.h>
#include <fgpu_internal_build_config.hpp>

/* Cache line size on GPU. Needed for performance improvement. */
#define FGPU_DEVICE_CACHELINE_SIZE      32

/* Each memory allocation needs to be aliged to a boundary */
#define FGPU_DEVICE_ADDRESS_ALIGNMENT   16

/* Maximum number of colors supported */
#define FGPU_MAX_NUM_COLORS             8

/* Maximum number of persistent blocks */
#define FGPU_MAX_NUM_PBLOCKS            6400

/* Maximum number of pending CUDA tasks */
#define FGPU_MAX_PENDING_TASKS          100

/**
 * @note Can be set to -1 if no preference. Preference is like a hint
 * default: 2
 * 此参数用于向 FGPU 提供有关所需分区数的提示。
 * 这仅指定分区总数的上限。如果它是 -1，则实际上不会向 FGPU 传递任何提示。
 * 如果仅启用计算分区，则分区数 = MIN(SM数, FGPU_PREFERRED_NUM_COLORS)
 * 如果同时启用了计算和内存带宽分区，则分区数 = MIN(SM数,内存着色数,FGPU_PREFERRED_NUM_COLORS)
 *   *目前，不可能有不同数量的计算和内存分区。
 *   *此外，目前每个分区具有相同数量的SM和相等的内存带宽。
 */
#define FGPU_PREFERRED_NUM_COLORS	2

#endif /* __FGPU_INTERNAL_CONFIG_HPP__ */
