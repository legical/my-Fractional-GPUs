// This file is automatically generated by rmconfig - DO NOT EDIT!
//
// Prototypes for rmconfig utility functions such as _IsGK104(), etc.
//
// Only for use within resman.
//
// Profile:  shipping-gpus-openrm
// Template: templates/gt_rmconfig_util.h
//
// Chips:    TU10X, GA100, GA102, GA103, GA104, GA106, GA107, AD102, AD103, AD104, GH10X
//

#ifndef _G_RMCFG_UTIL_H_
#define _G_RMCFG_UTIL_H_

//
// Any needed prototypes for helper functions for IsCHIP(), eg rmcfg_IsGK104()
// These cannot be put in rmconfig_private.h as they need the OBJ typedefs.
//

NvBool rmcfg_IsTU102(POBJGPU pGpu);
NvBool rmcfg_IsTU104(POBJGPU pGpu);
NvBool rmcfg_IsTU104orBetter(POBJGPU pGpu);
NvBool rmcfg_IsTU106(POBJGPU pGpu);
NvBool rmcfg_IsTU106orBetter(POBJGPU pGpu);
NvBool rmcfg_IsTU116(POBJGPU pGpu);
NvBool rmcfg_IsTU116orBetter(POBJGPU pGpu);
NvBool rmcfg_IsTU117(POBJGPU pGpu);
NvBool rmcfg_IsTU117orBetter(POBJGPU pGpu);
NvBool rmcfg_IsTU10X(POBJGPU pGpu);
NvBool rmcfg_IsGA100(POBJGPU pGpu);
NvBool rmcfg_IsGA100orBetter(POBJGPU pGpu);
NvBool rmcfg_IsGA102(POBJGPU pGpu);
NvBool rmcfg_IsGA102orBetter(POBJGPU pGpu);
NvBool rmcfg_IsGA103(POBJGPU pGpu);
NvBool rmcfg_IsGA103orBetter(POBJGPU pGpu);
NvBool rmcfg_IsGA104(POBJGPU pGpu);
NvBool rmcfg_IsGA104orBetter(POBJGPU pGpu);
NvBool rmcfg_IsGA106(POBJGPU pGpu);
NvBool rmcfg_IsGA106orBetter(POBJGPU pGpu);
NvBool rmcfg_IsGA107(POBJGPU pGpu);
NvBool rmcfg_IsGA107orBetter(POBJGPU pGpu);
NvBool rmcfg_IsGA10BorBetter(POBJGPU pGpu);
NvBool rmcfg_IsGA10X(POBJGPU pGpu);
NvBool rmcfg_IsGA10XorBetter(POBJGPU pGpu);
NvBool rmcfg_IsGA102ForBetter(POBJGPU pGpu);
NvBool rmcfg_IsGA10XForBetter(POBJGPU pGpu);
NvBool rmcfg_IsAD102(POBJGPU pGpu);
NvBool rmcfg_IsAD102orBetter(POBJGPU pGpu);
NvBool rmcfg_IsAD103(POBJGPU pGpu);
NvBool rmcfg_IsAD103orBetter(POBJGPU pGpu);
NvBool rmcfg_IsAD104(POBJGPU pGpu);
NvBool rmcfg_IsAD104orBetter(POBJGPU pGpu);
NvBool rmcfg_IsAD10X(POBJGPU pGpu);
NvBool rmcfg_IsAD10XorBetter(POBJGPU pGpu);
NvBool rmcfg_IsGH100(POBJGPU pGpu);
NvBool rmcfg_IsGH100orBetter(POBJGPU pGpu);
NvBool rmcfg_IsGH10X(POBJGPU pGpu);
NvBool rmcfg_IsGH10XorBetter(POBJGPU pGpu);
NvBool rmcfg_IsDISPLAYLESS(POBJGPU pGpu);
NvBool rmcfg_IsdTURING(POBJGPU pGpu);
NvBool rmcfg_IsTURING_CLASSIC_GPUS(POBJGPU pGpu);
NvBool rmcfg_IsdAMPERE(POBJGPU pGpu);
NvBool rmcfg_IsdAMPEREorBetter(POBJGPU pGpu);
NvBool rmcfg_IsAMPERE_CLASSIC_GPUS(POBJGPU pGpu);
NvBool rmcfg_IsAMPERE_CLASSIC_GPUSorBetter(POBJGPU pGpu);
NvBool rmcfg_IsdADA(POBJGPU pGpu);
NvBool rmcfg_IsdADAorBetter(POBJGPU pGpu);
NvBool rmcfg_IsADA_CLASSIC_GPUS(POBJGPU pGpu);
NvBool rmcfg_IsADA_CLASSIC_GPUSorBetter(POBJGPU pGpu);
NvBool rmcfg_IsdHOPPER(POBJGPU pGpu);
NvBool rmcfg_IsdHOPPERorBetter(POBJGPU pGpu);
NvBool rmcfg_IsHOPPER_CLASSIC_GPUS(POBJGPU pGpu);
NvBool rmcfg_IsHOPPER_CLASSIC_GPUSorBetter(POBJGPU pGpu);


#endif  // _G_RMCFG_UTIL_H_
