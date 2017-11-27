/*
 * Fu02_acc.h
 *
 * Real-Time Workshop code generation for Simulink model "Fu02_acc.mdl".
 *
 * Model Version                        : 1.8
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Tue Feb 12 16:10:37 2008
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Tue Feb 12 16:10:37 2008
 */

#ifndef _RTW_HEADER_Fu02_acc_h_
# define _RTW_HEADER_Fu02_acc_h_

#ifndef _Fu02_acc_COMMON_INCLUDES_
# define _Fu02_acc_COMMON_INCLUDES_
#include <math.h>
#include <stdlib.h>

#define S_FUNCTION_NAME                 simulink_only_sfcn
#define S_FUNCTION_LEVEL                2
#define RTW_GENERATED_S_FUNCTION

#include "simstruc.h"
#include "rtlibsrc.h"

#endif                                  /* _Fu02_acc_COMMON_INCLUDES_ */

#include "Fu02_acc_types.h"

/* Intrinsic types */
#ifndef POINTER_T
# define POINTER_T
typedef void * pointer_T;
#endif

/* Block signals for system: '<S4>/Triggered Subsystem' */
typedef struct _rtB_Fu02_Triggered_Subsystem {
  real_T In1;                           /* '<S7>/In1' */
} rtB_Fu02_Triggered_Subsystem;

/* Zero-crossing (trigger) state for system: '<S4>/Triggered Subsystem' */
typedef struct _rtNSZC_Fu02_Triggered_Subsystem {
  real_T Triggered_a_NSZC;              /* '<S4>/Triggered Subsystem' */
} rtNSZC_Fu02_Triggered_Subsystem;

/* Zero-crossing (trigger) state for system: '<S4>/Triggered Subsystem' */
typedef struct _rtZCE_Fu02_Triggered_Subsystem {
  ZCSigState Triggered_a_ZCE;           /* '<S4>/Triggered Subsystem' */
} rtZCE_Fu02_Triggered_Subsystem;

/* Block signals for system: '<S4>/Triggered Subsystem1' */
typedef struct _rtB_Fu02_Triggered_Subsystem1 {
  real_T In1;                           /* '<S8>/In1' */
} rtB_Fu02_Triggered_Subsystem1;

/* Zero-crossing (trigger) state for system: '<S4>/Triggered Subsystem1' */
typedef struct _rtNSZC_Fu02_Triggered_Subsystem1 {
  real_T Triggered_b_NSZC;              /* '<S4>/Triggered Subsystem1' */
} rtNSZC_Fu02_Triggered_Subsystem1;

/* Zero-crossing (trigger) state for system: '<S4>/Triggered Subsystem1' */
typedef struct _rtZCE_Fu02_Triggered_Subsystem1 {
  ZCSigState Triggered_b_ZCE;           /* '<S4>/Triggered Subsystem1' */
} rtZCE_Fu02_Triggered_Subsystem1;

/* Block signals (auto storage) */
typedef struct _Fu02_BlockIO {
  real_T Gain;                          /* '<S21>/Gain' */
  real_T Abs;                           /* '<S21>/Abs' */
  real_T Constant_a;                    /* '<S21>/Constant' */
  real_T IC;                            /* '<S21>/IC' */
  real_T Inherit_Shape1_b;              /* '<S15>/Inherit Shape1' */
  real_T Sampling;                      /* '<Root>/Sampling' */
  real_T Constant1;                     /* '<Root>/Constant1' */
  real_T Constant_b;                    /* '<Root>/Constant' */
  real_T Sum_a;                         /* '<Root>/Sum' */
  real_T Carrier_frequency1;            /* '<S3>/Carrier frequency1' */
  real_T Sum_b;                         /* '<S3>/Sum' */
  real_T MATLAB_Fcn;                    /* '<S2>/MATLAB Fcn' */
  real_T Fcn;                           /* '<S1>/Fcn' */
  real_T temp15;                        /* '<Root>/Integrator' */
  boolean_T Relational_Operator;        /* '<S21>/Relational Operator' */
  char pad_Relational_Operator[7];
  rtB_Fu02_Triggered_Subsystem1 Triggered_f; /* '<S6>/Triggered Subsystem1' */
  rtB_Fu02_Triggered_Subsystem Triggered_e; /* '<S6>/Triggered Subsystem' */
  rtB_Fu02_Triggered_Subsystem1 Triggered_d; /* '<S5>/Triggered Subsystem1' */
  rtB_Fu02_Triggered_Subsystem Triggered_c; /* '<S5>/Triggered Subsystem' */
  rtB_Fu02_Triggered_Subsystem1 Triggered_b; /* '<S4>/Triggered Subsystem1' */
  rtB_Fu02_Triggered_Subsystem Triggered_a; /* '<S4>/Triggered Subsystem' */
} Fu02_BlockIO;

/* Block states (auto storage) for system: '<Root>' */
typedef struct Fu02_D_Work_tag {
  real_T IC_FirstOutputTime;            /* <S21>/IC */
  struct {
    void *LoggedData;
  } Scope_PWORK;                        /* '<S1>/Scope' */
  struct {
    int_T IcNeedsLoading;
  } Integrator_a_IWORK;                 /* '<S21>/Integrator' */
  int_T Abs_MODE;                       /* <S21>/Abs */
  int_T Relational_Operator_MODE;       /* <S21>/Relational Operator */
} Fu02_D_Work;

/* Continuous states (auto storage) */
typedef struct _Fu02_ContinuousStates {
  real_T Integrator_a_CSTATE;           /* '<S21>/Integrator' */
  real_T Integrator_b_CSTATE;           /* '<Root>/Integrator' */
} Fu02_ContinuousStates;

/* State derivatives (auto storage) */
typedef struct _Fu02_StateDerivatives {
  real_T Integrator_a_CSTATE;           /* '<S21>/Integrator' */
  real_T Integrator_b_CSTATE;           /* '<Root>/Integrator' */
} Fu02_StateDerivatives;

/* State disabled  */
typedef struct _Fu02_StateDisabled {
  boolean_T Integrator_a_CSTATE;        /* '<S21>/Integrator' */
  boolean_T Integrator_b_CSTATE;        /* '<Root>/Integrator' */
} Fu02_StateDisabled;

/* Zero-crossing (trigger) state */
typedef struct _Fu02_NonsampledZCs {
  real_T Abs_NSZC;                      /* '<S21>/Abs' */
  real_T Relational_Operator_NSZC;      /* '<S21>/Relational Operator' */
  real_T Triggered_g_NSZC;              /* '<Root>/Triggered Subsystem' */
  rtNSZC_Fu02_Triggered_Subsystem1 Triggered_f; /* '<S4>/Triggered Subsystem1' */
  rtNSZC_Fu02_Triggered_Subsystem Triggered_e; /* '<S4>/Triggered Subsystem' */
  rtNSZC_Fu02_Triggered_Subsystem1 Triggered_d; /* '<S4>/Triggered Subsystem1' */
  rtNSZC_Fu02_Triggered_Subsystem Triggered_c; /* '<S4>/Triggered Subsystem' */
  rtNSZC_Fu02_Triggered_Subsystem1 Triggered_b; /* '<S4>/Triggered Subsystem1' */
  rtNSZC_Fu02_Triggered_Subsystem Triggered_a; /* '<S4>/Triggered Subsystem' */
} Fu02_NonsampledZCs;

/* Zero-crossing (trigger) state */
typedef struct _Fu02_PrevZCSigStates {
  ZCSigState Integrator_a_ZCE;          /* '<S21>/Integrator' */
  ZCSigState Triggered_g_ZCE;           /* '<Root>/Triggered Subsystem' */
  rtZCE_Fu02_Triggered_Subsystem1 Triggered_f; /* '<S4>/Triggered Subsystem1' */
  rtZCE_Fu02_Triggered_Subsystem Triggered_e; /* '<S4>/Triggered Subsystem' */
  rtZCE_Fu02_Triggered_Subsystem1 Triggered_d; /* '<S4>/Triggered Subsystem1' */
  rtZCE_Fu02_Triggered_Subsystem Triggered_c; /* '<S4>/Triggered Subsystem' */
  rtZCE_Fu02_Triggered_Subsystem1 Triggered_b; /* '<S4>/Triggered Subsystem1' */
  rtZCE_Fu02_Triggered_Subsystem Triggered_a; /* '<S4>/Triggered Subsystem' */
} Fu02_PrevZCSigStates;

/* Parameters (auto storage) */
struct _Fu02_Parameters {
  real_T Gain_Gain;                     /* Expression: 1+eps
                                         * '<S21>/Gain'
                                         */
  real_T Constant_a_Value;              /* Expression: modu
                                         * '<S21>/Constant'
                                         */
  real_T IC_Value;                      /* Expression: init
                                         * '<S21>/IC'
                                         */
  real_T Sampling_Amp;                  /* Expression: 1
                                         * '<Root>/Sampling'
                                         */
  real_T Sampling_Bias;                 /* Expression: 0
                                         * '<Root>/Sampling'
                                         */
  real_T Sampling_Freq;                 /* Expression: 2*pi*1000
                                         * '<Root>/Sampling'
                                         */
  real_T Sampling_Phase;                /* Expression: 0
                                         * '<Root>/Sampling'
                                         */
  real_T Constant1_Value;               /* Expression: 0
                                         * '<Root>/Constant1'
                                         */
  real_T Constant_b_Value;              /* Expression: 123.4567
                                         * '<Root>/Constant'
                                         */
  real_T Integrator_b_IC;               /* Expression: 0
                                         * '<Root>/Integrator'
                                         */
  real_T Carrier_frequency1_Value;      /* Expression: Fc
                                         * '<S3>/Carrier frequency1'
                                         */
  real_T Check_Signal_Attributes_a_P1; /* Expression: SigAttribCheckMethod
                                        * '<S13>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P2; /* Expression: Complexity
                                        * '<S13>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P3; /* Expression: Frame
                                        * '<S13>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P4; /* Expression: DimsCheckMethod
                                        * '<S13>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P5; /* Expression: Dimensions
                                        * '<S13>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P6; /* Expression: DatatypeCheckMethod
                                        * '<S13>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P7; /* Expression: DatatypeGeneral
                                        * '<S13>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P8; /* Expression: DtypeFloatSpecific
                                        * '<S13>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P9; /* Expression: DtypeFixedSpecific
                                        * '<S13>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P10; /* Expression: DtypeIntSpecific
                                         * '<S13>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_a_P11; /* Expression: SampleMode
                                         * '<S13>/Check Signal Attributes'
                                         */
  real_T Reshape_P1;                    /* Expression: OutputDimensionality
                                         * '<S14>/Reshape'
                                         */
  real_T Reshape_P2[2];                 /* Expression: OutputDimensions
                                         * '<S14>/Reshape'
                                         */
  real_T Sensitivity_Gain;              /* Expression: Kc
                                         * '<S3>/Sensitivity'
                                         */
  real_T Check_Signal_Attributes_b_P1; /* Expression: SigAttribCheckMethod
                                        * '<S18>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P2; /* Expression: Complexity
                                        * '<S18>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P3; /* Expression: Frame
                                        * '<S18>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P4; /* Expression: DimsCheckMethod
                                        * '<S18>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P5; /* Expression: Dimensions
                                        * '<S18>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P6; /* Expression: DatatypeCheckMethod
                                        * '<S18>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P7; /* Expression: DatatypeGeneral
                                        * '<S18>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P8; /* Expression: DtypeFloatSpecific
                                        * '<S18>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P9; /* Expression: DtypeFixedSpecific
                                        * '<S18>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P10; /* Expression: DtypeIntSpecific
                                         * '<S18>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_b_P11; /* Expression: SampleMode
                                         * '<S18>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_c_P1; /* Expression: SigAttribCheckMethod
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P2; /* Expression: Complexity
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P3; /* Expression: Frame
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P4; /* Expression: DimsCheckMethod
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P5; /* Expression: Dimensions
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P6; /* Expression: DatatypeCheckMethod
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P7; /* Expression: DatatypeGeneral
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P8; /* Expression: DtypeFloatSpecific
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P9; /* Expression: DtypeFixedSpecific
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P10; /* Expression: DtypeIntSpecific
                                         * '<S19>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_c_P11; /* Expression: SampleMode
                                         * '<S19>/Check Signal Attributes'
                                         */
};

extern Fu02_Parameters Fu02_DefaultParameters; /* parameters */

/* External data declarations for dependent source files */

/* non-finites */
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;

#endif                                  /* _RTW_HEADER_Fu02_acc_h_ */
