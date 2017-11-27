/*
 * new_pll_fs_acc_private.h
 *
 * Real-Time Workshop code generation for Simulink model "new_pll_fs_acc.mdl".
 *
 * Model version              : 1.52
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Thu Apr 29 14:20:16 2010
 *
 * Target selection: accel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit xPC Target (AMD Athlon)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_new_pll_fs_acc_private_h_
#define RTW_HEADER_new_pll_fs_acc_private_h_
#include "rtwtypes.h"
#ifndef RTW_COMMON_DEFINES_
# define RTW_COMMON_DEFINES_
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
 }
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((ptr));\
 (ptr) = (NULL);\
 }
#else

/* Visual and other windows compilers delcare free without const! */
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((void *)(ptr));\
 (ptr) = (NULL);\
 }
#endif
#endif                                 /* RTW_COMMON_DEFINES_ */

#include "dsp_rt.h"                    /* Signal Processing Blockset general run time support functions */
#include "dsp_ic_rt.h"                 /* Signal Processing Blockset run time support library */
#include "dsprebuff_rt.h"              /* Signal Processing Blockset run time support library */
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern void MWDSPCG_FFT_Interleave_R2BR_D(const real_T x[], creal_T y[], const
  int32_T nChans, const int32_T nRows);
extern void MWDSPCG_R2DIT_TBLS_Z(creal_T y[], const int32_T nChans, const
  int32_T nRows, const int32_T fftLen, const int32_T offset, const real_T
  tablePtr[], const int32_T twiddleStep, const boolean_T isInverse);
extern void MWDSPCG_FFT_DblLen_Z_Tbl(creal_T y[], const int32_T nChans, const
  int32_T nRows, const real_T twiddleTable[], const int32_T twiddleStep);
void new_pll_fs_SpectrumScope_Init(SimStruct *const S);
void new_pll_fs_SpectrumScope_Update(SimStruct *const S);
void new_pll_fs_SpectrumScope(SimStruct *const S);
void new_pll_fs_SpectrumScope1_Init(SimStruct *const S);
void new_pll_fs_SpectrumScope1_Update(SimStruct *const S);
void new_pll_fs_SpectrumScope1(SimStruct *const S);
void new_pll_fs_SpectrumScope_Term(SimStruct *const S);
void new_pll_fs_SpectrumScope1_Term(SimStruct *const S);

#endif                                 /* RTW_HEADER_new_pll_fs_acc_private_h_ */
