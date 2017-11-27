/*
 * FuSimple_acc_private.h
 *
 * Real-Time Workshop code generation for Simulink model "FuSimple_acc.mdl".
 *
 * Model Version              : 1.48
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Wed Apr 21 16:48:28 2010
 */
#ifndef _RTW_HEADER_FuSimple_acc_private_h_
#define _RTW_HEADER_FuSimple_acc_private_h_
#include "rtwtypes.h"
#ifndef _RTW_COMMON_DEFINES_
# define _RTW_COMMON_DEFINES_
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
 return;\
 }
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != NULL) {\
 free((ptr));\
 (ptr) = NULL;\
 }
#else

/* Visual and other windows compilers delcare free without const! */
#define rt_FREE(ptr)                   if((ptr) != NULL) {\
 free((void *)(ptr));\
 (ptr) = NULL;\
 }
#endif
#endif                                 /* _RTW_COMMON_DEFINES_ */

#include "dsp_rt.h"                    /* Signal Processing Blockset general run time support functions */
#include "dsprebuff_rt.h"              /* Signal Processing Blockset run time support library */
#include "dsp_ic_rt.h"                 /* Signal Processing Blockset run time support library */
#include "dspfft_rt.h"                 /* Signal Processing Blockset run time support library */
#include "dspfilter_rt.h"              /* Signal Processing Blockset run time support library */
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

void FuSimple_SpectrumScope_Init(SimStruct *S);
void FuSimple_SpectrumScope_Update(SimStruct *S);
void FuSimple_SpectrumScope(SimStruct *S);
void FuSimple_SpectrumScope1_Init(SimStruct *S);
void FuSimple_SpectrumScope1_Update(SimStruct *S);
void FuSimple_SpectrumScope1(SimStruct *S);
void FuSimple_SpectrumScope_Term(SimStruct *S);
void FuSimple_SpectrumScope1_Term(SimStruct *S);

#endif                                 /* _RTW_HEADER_FuSimple_acc_private_h_ */
