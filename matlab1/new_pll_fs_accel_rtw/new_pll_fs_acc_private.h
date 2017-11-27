/*
 * new_pll_fs_acc_private.h
 *
 * Real-Time Workshop code generation for Simulink model "new_pll_fs_acc.mdl".
 *
 * Model Version              : 1.45
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Thu Apr 22 21:25:01 2010
 */
#ifndef _RTW_HEADER_new_pll_fs_acc_private_h_
#define _RTW_HEADER_new_pll_fs_acc_private_h_
#include "rtwtypes.h"
#ifndef _RTW_COMMON_DEFINES_
# define _RTW_COMMON_DEFINES_
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
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
#endif                                 /* _RTW_HEADER_new_pll_fs_acc_private_h_ */
