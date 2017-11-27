/*
 * pll___acc.h
 *
 * Real-Time Workshop code generation for Simulink model "pll___acc.mdl".
 *
 * Model version              : 1.15
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Thu Apr 29 14:43:05 2010
 *
 * Target selection: accel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_pll___acc_h_
#define RTW_HEADER_pll___acc_h_
#ifndef pll___acc_COMMON_INCLUDES_
# define pll___acc_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#define S_FUNCTION_NAME                simulink_only_sfcn
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "mwmathutil.h"
#endif                                 /* pll___acc_COMMON_INCLUDES_ */

#include "pll___acc_types.h"

/* Block signals (auto storage) */
typedef struct {
  real_T B_1_0_0;                      /* '<S9>/Gain' */
  real_T B_1_1_0;                      /* '<S9>/Abs' */
  real_T B_1_2_0;                      /* '<S9>/Constant' */
  real_T B_1_5_0;                      /* '<S9>/IC' */
  real_T B_1_9_0;                      /* '<S1>/Inherit Shape' */
  real_T B_1_10_0;                     /* '<Root>/Saturation' */
  real_T B_1_11_0;                     /* '<S15>/Gain' */
  real_T B_1_12_0;                     /* '<S15>/Abs' */
  real_T B_1_13_0;                     /* '<S15>/Constant' */
  real_T B_1_16_0;                     /* '<S15>/IC' */
  real_T B_1_21_0;                     /* '<Root>/Quantizer' */
  real_T B_1_25_0;                     /* '<Root>/Fsample' */
  real_T B_1_28_0;                     /* '<Root>/Product1' */
  real_T B_1_29_0;                     /* '<Root>/Gain' */
  real_T B_1_30_0;                     /* '<Root>/Transfer Fcn' */
  real_T B_1_31_0;                     /* '<Root>/Integrator' */
  real_T B_1_35_0;                     /* '<S1>/Sum' */
  real_T B_1_36_0;                     /* '<S2>/Carrier frequency1' */
  real_T B_1_38_0;                     /* '<S2>/Sum' */
  real_T B_0_0_0[2];                   /* '<S3>/MATLAB Fcn' */
  real_T B_1_20_0;                     /* '<S2>/Inherit Shape' */
  boolean_T B_1_3_0;                   /* '<S9>/Relational Operator' */
  boolean_T B_1_14_0;                  /* '<S15>/Relational Operator' */
  char pad_B_1_14_0[6];
} BlockIO;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T IC_FirstOutputTime;           /* '<S9>/IC' */
  real_T IC_FirstOutputTime_b;         /* '<S15>/IC' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S9>/Integrator' */

  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK_g;                /* '<S15>/Integrator' */

  int_T Abs_MODE;                      /* '<S9>/Abs' */
  int_T Saturation_MODE;               /* '<Root>/Saturation' */
  int_T Abs_MODE_f;                    /* '<S15>/Abs' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<Root>/Triggered Subsystem' */
  boolean_T RelationalOperator_Mode;   /* '<S9>/Relational Operator' */
  boolean_T RelationalOperator_Mode_o; /* '<S15>/Relational Operator' */
  char pad_RelationalOperator_Mode_o;
} D_Work;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S9>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S15>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T Integrator_CSTATE_h;          /* '<Root>/Integrator' */
} ContinuousStates;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S9>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S15>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T Integrator_CSTATE_h;          /* '<Root>/Integrator' */
} StateDerivatives;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S9>/Integrator' */
  boolean_T Integrator_CSTATE_m;       /* '<S15>/Integrator' */
  boolean_T TransferFcn_CSTATE;        /* '<Root>/Transfer Fcn' */
  boolean_T Integrator_CSTATE_h;       /* '<Root>/Integrator' */
} StateDisabled;

/* Zero-crossing (trigger) state */
typedef struct {
  real_T Abs_AbsZc_ZC;                 /* '<S9>/Abs' */
  real_T RelationalOperator_RelopInput_ZC;/* '<S9>/Relational Operator' */
  real_T Integrator_Reset_ZC;          /* '<S9>/Integrator' */
  real_T Saturation_UprLim_ZC;         /* '<Root>/Saturation' */
  real_T Saturation_LwrLim_ZC;         /* '<Root>/Saturation' */
  real_T Abs_AbsZc_ZC_n;               /* '<S15>/Abs' */
  real_T RelationalOperator_RelopInput_ZC_c;/* '<S15>/Relational Operator' */
  real_T Integrator_Reset_ZC_p;        /* '<S15>/Integrator' */
  real_T TriggeredSubsystem_Trig_ZC;   /* '<Root>/Triggered Subsystem' */
} ZCSignalValues;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Abs_AbsZc_ZCE;            /* '<S9>/Abs' */
  ZCSigState RelationalOperator_RelopInput_ZCE;/* '<S9>/Relational Operator' */
  ZCSigState Integrator_Reset_ZCE;     /* '<S9>/Integrator' */
  ZCSigState Saturation_UprLim_ZCE;    /* '<Root>/Saturation' */
  ZCSigState Saturation_LwrLim_ZCE;    /* '<Root>/Saturation' */
  ZCSigState Abs_AbsZc_ZCE_d;          /* '<S15>/Abs' */
  ZCSigState RelationalOperator_RelopInput_ZCE_b;/* '<S15>/Relational Operator' */
  ZCSigState Integrator_Reset_ZCE_m;   /* '<S15>/Integrator' */
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<Root>/Triggered Subsystem' */
} PrevZCSigStates;

/* Parameters (auto storage) */
struct Parameters_ {
  real_T P_0;                          /* Expression: 1+eps
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T P_1;                          /* Expression: modu
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T P_2;                          /* Expression: init
                                        * Referenced by: '<S9>/IC'
                                        */
  real_T P_3;                          /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T P_4;                          /* Expression: -1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T P_5;                          /* Expression: 1+eps
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T P_6;                          /* Expression: modu
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T P_7;                          /* Expression: init
                                        * Referenced by: '<S15>/IC'
                                        */
  real_T P_8;                          /* Expression: 2/(2^8)
                                        * Referenced by: '<Root>/Quantizer'
                                        */
  real_T P_9;                          /* Expression: 3245
                                        * Referenced by: '<Root>/Fdisired'
                                        */
  real_T P_10;                         /* Expression: 10000
                                        * Referenced by: '<Root>/Fsample'
                                        */
  real_T P_11;                         /* Expression: 200
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T P_12;                         /* Computed Parameter: P_12
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T P_13;                         /* Computed Parameter: P_13
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T P_14;                         /* Computed Parameter: P_14
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T P_17;                         /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T P_18;                         /* Expression: Fc
                                        * Referenced by: '<S1>/Carrier frequency1'
                                        */
  real_T P_19;                         /* Expression: Kc
                                        * Referenced by: '<S1>/Sensitivity'
                                        */
  real_T P_20;                         /* Expression: Fc
                                        * Referenced by: '<S2>/Carrier frequency1'
                                        */
  real_T P_21;                         /* Expression: Kc
                                        * Referenced by: '<S2>/Sensitivity'
                                        */
};

extern Parameters rtDefaultParameters; /* parameters */

#endif                                 /* RTW_HEADER_pll___acc_h_ */
