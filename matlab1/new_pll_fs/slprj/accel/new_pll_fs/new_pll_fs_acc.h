/*
 * new_pll_fs_acc.h
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
#ifndef RTW_HEADER_new_pll_fs_acc_h_
#define RTW_HEADER_new_pll_fs_acc_h_
#ifndef new_pll_fs_acc_COMMON_INCLUDES_
# define new_pll_fs_acc_COMMON_INCLUDES_
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
#endif                                 /* new_pll_fs_acc_COMMON_INCLUDES_ */

#include "new_pll_fs_acc_types.h"

/* Block signals (auto storage) */
typedef struct {
  creal_T B_4_2_0[2048];               /* '<S35>/FFT' */
  creal_T B_3_2_0[2048];               /* '<S27>/FFT' */
  real_T B_6_0_0;                      /* '<S23>/Gain' */
  real_T B_6_1_0;                      /* '<S23>/Abs' */
  real_T B_6_2_0;                      /* '<S23>/Constant' */
  real_T B_6_5_0;                      /* '<S23>/IC' */
  real_T B_6_11_0;                     /* '<Root>/Gain1' */
  real_T B_6_15_0;                     /* '<Root>/Sample Frequency' */
  real_T B_6_16_0;                     /* '<Root>/Quantizer' */
  real_T B_6_17_0;                     /* '<S45>/Gain' */
  real_T B_6_18_0;                     /* '<S45>/Abs' */
  real_T B_6_19_0;                     /* '<S45>/Constant' */
  real_T B_6_22_0;                     /* '<S45>/IC' */
  real_T B_6_26_0;                     /* '<S17>/Inherit Shape' */
  real_T B_6_27_0;                     /* '<Root>/Saturation' */
  real_T B_6_32_0;                     /* '<Root>/Product1' */
  real_T B_6_34_0;                     /* '<Root>/Gain' */
  real_T B_6_35_0;                     /* '<S1>/State-Space' */
  real_T B_6_36_0;                     /* '<S2>/State-Space' */
  real_T B_6_37_0;                     /* '<Root>/Analog Filter Design' */
  real_T B_6_38_0;                     /* '<S3>/Carrier frequency1' */
  real_T B_6_41_0;                     /* '<S3>/Sum' */
  real_T B_6_47_0;                     /* '<Root>/Transfer Fcn' */
  real_T B_6_48_0;                     /* '<S7>/SwitchControl' */
  real_T B_6_51_0;                     /* '<S8>/SwitchControl' */
  real_T B_6_54_0;                     /* '<S9>/SwitchControl' */
  real_T B_6_57_0;                     /* '<S10>/SwitchControl' */
  real_T B_6_60_0;                     /* '<S11>/SwitchControl' */
  real_T B_6_65_0;                     /* '<S13>/SwitchControl' */
  real_T B_6_66_0;                     /* '<S12>/SwitchControl' */
  real_T B_6_69_0;                     /* '<S17>/Sum' */
  real_T B_5_0_0[2];                   /* '<S16>/MATLAB Fcn' */
  real_T B_4_0_0[2048];                /* '<S32>/Buffer' */
  real_T B_4_1_1[2048];                /* '<S33>/Window' */
  real_T B_4_7_0[2];                   /* '<S37>/Input sample time' */
  real_T B_4_8_0[2];                   /* '<S37>/Input  dimensions' */
  real_T B_4_9_0;                      /* '<S37>/Select number  of rows in  input matrix' */
  real_T B_4_11_0[2048];               /* '<S33>/Product' */
  real_T B_3_0_0[2048];                /* '<S24>/Buffer' */
  real_T B_3_1_1[2048];                /* '<S25>/Window' */
  real_T B_3_7_0[2];                   /* '<S29>/Input sample time' */
  real_T B_3_8_0[2];                   /* '<S29>/Input  dimensions' */
  real_T B_3_9_0;                      /* '<S29>/Select number  of rows in  input matrix' */
  real_T B_3_11_0[2048];               /* '<S25>/Product' */
  real_T B_2_3_0;                      /* '<S6>/Integrator2' */
  real_T B_2_5_0;                      /* '<S6>/Kd1' */
  real_T B_2_7_0;                      /* '<S6>/Wn' */
  real_T B_2_8_0;                      /* '<S6>/Product1' */
  real_T B_2_12_0;                     /* '<S6>/Product3' */
  real_T B_2_13_0;                     /* '<S6>/Product5' */
  real_T B_2_15_0;                     /* '<S6>/Product4' */
  real_T B_2_17_0;                     /* '<S6>/Product7' */
  real_T B_1_1_0;                      /* '<S5>/Integrator1' */
  real_T B_1_5_0;                      /* '<S5>/Wn' */
  real_T B_1_6_0;                      /* '<S5>/Product1' */
  real_T B_1_10_0;                     /* '<S5>/Product3' */
  real_T B_1_11_0;                     /* '<S5>/Product5' */
  real_T B_1_13_0;                     /* '<S5>/Product4' */
  real_T B_0_0_0;                      /* '<S4>/Integrator1' */
  real_T B_0_10_0;                     /* '<S4>/Product1' */
  real_T B_0_13_0;                     /* '<S4>/Product5' */
  real_T B_0_14_0;                     /* '<S4>/Product4' */
  real_T B_6_9_0;                      /* '<S3>/Inherit Shape' */
  real_T B_4_4_0[2048];                /* '<S33>/Digital Filter' */
  real_T B_3_4_0[2048];                /* '<S25>/Digital Filter' */
  real_T B_2_0_0;                      /* '<S6>/Integrator' */
  real_T B_2_1_0;                      /* '<S6>/Integrator1' */
  real_T B_1_0_0;                      /* '<S5>/Integrator' */
  real_T B_0_1_0;                      /* '<S4>/Integrator' */
  real_T B_4_3_0[2048];                /* '<S35>/Magnitude Squared' */
  real_T B_3_3_0[2048];                /* '<S27>/Magnitude Squared' */
  uint8_T B_6_45_0;                    /* '<S7>/Constant' */
  uint8_T B_6_46_0;                    /* '<S7>/S-Function' */
  uint8_T B_6_49_0;                    /* '<S8>/Constant' */
  uint8_T B_6_50_0;                    /* '<S8>/S-Function' */
  uint8_T B_6_52_0;                    /* '<S9>/Constant' */
  uint8_T B_6_53_0;                    /* '<S9>/S-Function' */
  uint8_T B_6_55_0;                    /* '<S10>/Constant' */
  uint8_T B_6_56_0;                    /* '<S10>/S-Function' */
  uint8_T B_6_58_0;                    /* '<S11>/Constant' */
  uint8_T B_6_59_0;                    /* '<S11>/S-Function' */
  uint8_T B_6_61_0;                    /* '<S12>/Constant' */
  uint8_T B_6_62_0;                    /* '<S12>/S-Function' */
  uint8_T B_6_63_0;                    /* '<S13>/Constant' */
  uint8_T B_6_64_0;                    /* '<S13>/S-Function' */
  boolean_T B_6_3_0;                   /* '<S23>/Relational Operator' */
  boolean_T B_6_20_0;                  /* '<S45>/Relational Operator' */
} BlockIO;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Buffer_CircBuff[4096];        /* '<S32>/Buffer' */
  real_T DigitalFilter_FILT_STATES[4096];/* '<S33>/Digital Filter' */
  real_T Buffer_CircBuff_l[4096];      /* '<S24>/Buffer' */
  real_T DigitalFilter_FILT_STATES_e[4096];/* '<S25>/Digital Filter' */
  real_T IC_FirstOutputTime;           /* '<S23>/IC' */
  real_T IC_FirstOutputTime_h;         /* '<S45>/IC' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  void * Buffer_IN_BUF_PTR;            /* '<S32>/Buffer' */
  void * Buffer_OUT_BUF_PTR;           /* '<S32>/Buffer' */
  void *FrameScope_PWORK[3];           /* '<S15>/Frame Scope' */
  void * Buffer_IN_BUF_PTR_e;          /* '<S24>/Buffer' */
  void * Buffer_OUT_BUF_PTR_o;         /* '<S24>/Buffer' */
  void *FrameScope_PWORK_j[3];         /* '<S14>/Frame Scope' */
  struct {
    void *LoggedData;
  } Scope_PWORK_b;                     /* '<S6>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     /* '<S5>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_d;                     /* '<S4>/Scope' */

  int32_T Buffer_bufferLength;         /* '<S32>/Buffer' */
  int32_T Buffer_SHIFT_PER_ELEM;       /* '<S32>/Buffer' */
  int32_T DigitalFilter_CIRCBUFFIDX;   /* '<S33>/Digital Filter' */
  int32_T Buffer_bufferLength_p;       /* '<S24>/Buffer' */
  int32_T Buffer_SHIFT_PER_ELEM_b;     /* '<S24>/Buffer' */
  int32_T DigitalFilter_CIRCBUFFIDX_m; /* '<S25>/Digital Filter' */
  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S23>/Integrator' */

  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK_n;                /* '<S45>/Integrator' */

  int_T Abs_MODE;                      /* '<S23>/Abs' */
  int_T Abs_MODE_f;                    /* '<S45>/Abs' */
  int_T Saturation_MODE;               /* '<Root>/Saturation' */
  int_T Integrator1_MODE;              /* '<S6>/Integrator1' */
  int_T Integrator1_MODE_m;            /* '<S5>/Integrator1' */
  int_T Integrator1_MODE_d;            /* '<S4>/Integrator1' */
  int_T Integrator_MODE;               /* '<S4>/Integrator' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<Root>/Triggered Subsystem' */
  boolean_T RelationalOperator_Mode;   /* '<S23>/Relational Operator' */
  boolean_T RelationalOperator_Mode_m; /* '<S45>/Relational Operator' */
  boolean_T Window_FLAG;               /* '<S33>/Window' */
  boolean_T Window_FLAG_m;             /* '<S25>/Window' */
  char pad_Window_FLAG_m[7];
} D_Work;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S23>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S45>/Integrator' */
  real_T StateSpace_CSTATE;            /* '<S1>/State-Space' */
  real_T StateSpace_CSTATE_m[2];       /* '<S2>/State-Space' */
  real_T AnalogFilterDesign_CSTATE[2]; /* '<Root>/Analog Filter Design' */
  real_T Integrator_CSTATE_p;          /* '<Root>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T Integrator_CSTATE_k;          /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S6>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S6>/Integrator2' */
  real_T Integrator_CSTATE_j;          /* '<S5>/Integrator' */
  real_T Integrator1_CSTATE_l;         /* '<S5>/Integrator1' */
  real_T Integrator1_CSTATE_ls;        /* '<S4>/Integrator1' */
  real_T Integrator_CSTATE_jp;         /* '<S4>/Integrator' */
} ContinuousStates;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S23>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S45>/Integrator' */
  real_T StateSpace_CSTATE;            /* '<S1>/State-Space' */
  real_T StateSpace_CSTATE_m[2];       /* '<S2>/State-Space' */
  real_T AnalogFilterDesign_CSTATE[2]; /* '<Root>/Analog Filter Design' */
  real_T Integrator_CSTATE_p;          /* '<Root>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T Integrator_CSTATE_k;          /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S6>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S6>/Integrator2' */
  real_T Integrator_CSTATE_j;          /* '<S5>/Integrator' */
  real_T Integrator1_CSTATE_l;         /* '<S5>/Integrator1' */
  real_T Integrator1_CSTATE_ls;        /* '<S4>/Integrator1' */
  real_T Integrator_CSTATE_jp;         /* '<S4>/Integrator' */
} StateDerivatives;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S23>/Integrator' */
  boolean_T Integrator_CSTATE_d;       /* '<S45>/Integrator' */
  boolean_T StateSpace_CSTATE;         /* '<S1>/State-Space' */
  boolean_T StateSpace_CSTATE_m[2];    /* '<S2>/State-Space' */
  boolean_T AnalogFilterDesign_CSTATE[2];/* '<Root>/Analog Filter Design' */
  boolean_T Integrator_CSTATE_p;       /* '<Root>/Integrator' */
  boolean_T TransferFcn_CSTATE;        /* '<Root>/Transfer Fcn' */
  boolean_T Integrator_CSTATE_k;       /* '<S6>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S6>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S6>/Integrator2' */
  boolean_T Integrator_CSTATE_j;       /* '<S5>/Integrator' */
  boolean_T Integrator1_CSTATE_l;      /* '<S5>/Integrator1' */
  boolean_T Integrator1_CSTATE_ls;     /* '<S4>/Integrator1' */
  boolean_T Integrator_CSTATE_jp;      /* '<S4>/Integrator' */
} StateDisabled;

/* Zero-crossing (trigger) state */
typedef struct {
  real_T Abs_AbsZc_ZC;                 /* '<S23>/Abs' */
  real_T RelationalOperator_RelopInput_ZC;/* '<S23>/Relational Operator' */
  real_T Integrator_Reset_ZC;          /* '<S23>/Integrator' */
  real_T Abs_AbsZc_ZC_e;               /* '<S45>/Abs' */
  real_T RelationalOperator_RelopInput_ZC_g;/* '<S45>/Relational Operator' */
  real_T Integrator_Reset_ZC_f;        /* '<S45>/Integrator' */
  real_T Saturation_UprLim_ZC;         /* '<Root>/Saturation' */
  real_T Saturation_LwrLim_ZC;         /* '<Root>/Saturation' */
  real_T TriggeredSubsystem_Trig_ZC;   /* '<Root>/Triggered Subsystem' */
  real_T Integrator1_IntgUpLimit_ZC;   /* '<S6>/Integrator1' */
  real_T Integrator1_IntgLoLimit_ZC;   /* '<S6>/Integrator1' */
  real_T Integrator1_LeaveSaturate_ZC; /* '<S6>/Integrator1' */
  real_T Integrator1_IntgUpLimit_ZC_b; /* '<S5>/Integrator1' */
  real_T Integrator1_IntgLoLimit_ZC_m; /* '<S5>/Integrator1' */
  real_T Integrator1_LeaveSaturate_ZC_m;/* '<S5>/Integrator1' */
  real_T Integrator1_IntgUpLimit_ZC_d; /* '<S4>/Integrator1' */
  real_T Integrator1_IntgLoLimit_ZC_i; /* '<S4>/Integrator1' */
  real_T Integrator1_LeaveSaturate_ZC_j;/* '<S4>/Integrator1' */
  real_T Integrator_IntgUpLimit_ZC;    /* '<S4>/Integrator' */
  real_T Integrator_IntgLoLimit_ZC;    /* '<S4>/Integrator' */
} ZCSignalValues;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Abs_AbsZc_ZCE;            /* '<S23>/Abs' */
  ZCSigState RelationalOperator_RelopInput_ZCE;/* '<S23>/Relational Operator' */
  ZCSigState Integrator_Reset_ZCE;     /* '<S23>/Integrator' */
  ZCSigState Abs_AbsZc_ZCE_k;          /* '<S45>/Abs' */
  ZCSigState RelationalOperator_RelopInput_ZCE_n;/* '<S45>/Relational Operator' */
  ZCSigState Integrator_Reset_ZCE_i;   /* '<S45>/Integrator' */
  ZCSigState Saturation_UprLim_ZCE;    /* '<Root>/Saturation' */
  ZCSigState Saturation_LwrLim_ZCE;    /* '<Root>/Saturation' */
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<Root>/Triggered Subsystem' */
  ZCSigState Integrator1_IntgUpLimit_ZCE;/* '<S6>/Integrator1' */
  ZCSigState Integrator1_IntgLoLimit_ZCE;/* '<S6>/Integrator1' */
  ZCSigState Integrator1_LeaveSaturate_ZCE;/* '<S6>/Integrator1' */
  ZCSigState Integrator1_IntgUpLimit_ZCE_a;/* '<S5>/Integrator1' */
  ZCSigState Integrator1_IntgLoLimit_ZCE_d;/* '<S5>/Integrator1' */
  ZCSigState Integrator1_LeaveSaturate_ZCE_a;/* '<S5>/Integrator1' */
  ZCSigState Integrator1_IntgUpLimit_ZCE_g;/* '<S4>/Integrator1' */
  ZCSigState Integrator1_IntgLoLimit_ZCE_f;/* '<S4>/Integrator1' */
  ZCSigState Integrator1_LeaveSaturate_ZCE_ap;/* '<S4>/Integrator1' */
  ZCSigState Integrator_IntgUpLimit_ZCE;/* '<S4>/Integrator' */
  ZCSigState Integrator_IntgLoLimit_ZCE;/* '<S4>/Integrator' */
} PrevZCSigStates;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S24>/Buffer'
   *   '<S25>/Digital Filter'
   *   '<S32>/Buffer'
   *   '<S33>/Digital Filter'
   */
  real_T pooled1;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S25>/Window'
   *   '<S33>/Window'
   */
  real_T pooled2[2048];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S27>/FFT'
   *   '<S35>/FFT'
   */
  real_T pooled3[1536];
} ConstParam;

/* Parameters (auto storage) */
struct Parameters_ {
  real_T P_0;                          /* Expression: 100
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T P_1;                          /* Expression: 5000
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T P_2;                          /* Expression: 10
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T P_3;                          /* Expression: 2500
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T P_4;                          /* Expression: 5000
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T P_5;                          /* Expression: 10
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T P_6;                          /* Expression: 0.61
                                        * Referenced by: '<S4>/Kd'
                                        */
  real_T P_7;                          /* Expression: 1
                                        * Referenced by: '<S4>/Kv'
                                        */
  real_T P_8;                          /* Expression: 2*pi*250
                                        * Referenced by: '<S4>/Wn'
                                        */
  real_T P_9;                          /* Expression: .7
                                        * Referenced by: '<S4>/Z'
                                        */
  real_T P_10;                         /* Expression: 2
                                        * Referenced by: '<S4>/cZ'
                                        */
  real_T P_11;                         /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
  real_T P_12;                         /* Expression: 1000
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  real_T P_13;                         /* Expression: 5000
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  real_T P_14;                         /* Expression: 10
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  real_T P_15;                         /* Expression: 1
                                        * Referenced by: '<S5>/Kd'
                                        */
  real_T P_16;                         /* Expression: 1
                                        * Referenced by: '<S5>/Kv'
                                        */
  real_T P_17;                         /* Expression: 2*pi*250
                                        * Referenced by: '<S5>/Wn'
                                        */
  real_T P_18;                         /* Expression: .7
                                        * Referenced by: '<S5>/Z'
                                        */
  real_T P_19;                         /* Expression: 2
                                        * Referenced by: '<S5>/cZ'
                                        */
  real_T P_20;                         /* Expression: 0
                                        * Referenced by: '<S6>/Integrator'
                                        */
  real_T P_21;                         /* Expression: 1000
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T P_22;                         /* Expression: 5000
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T P_23;                         /* Expression: 10
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T P_24;                         /* Expression: 0
                                        * Referenced by: '<S6>/Integrator2'
                                        */
  real_T P_25;                         /* Expression: 1
                                        * Referenced by: '<S6>/Kd'
                                        */
  real_T P_26;                         /* Expression: 5
                                        * Referenced by: '<S6>/Kd1'
                                        */
  real_T P_27;                         /* Expression: 1
                                        * Referenced by: '<S6>/Kv'
                                        */
  real_T P_28;                         /* Expression: 2*pi*250
                                        * Referenced by: '<S6>/Wn'
                                        */
  real_T P_29;                         /* Expression: .7
                                        * Referenced by: '<S6>/Z'
                                        */
  real_T P_30;                         /* Expression: 2
                                        * Referenced by: '<S6>/cZ'
                                        */
  real_T P_31[2];                      /* Expression: NumCoeffs
                                        * Referenced by: '<S25>/Digital Filter'
                                        */
  real_T P_32[2];                      /* Expression: NumCoeffs
                                        * Referenced by: '<S33>/Digital Filter'
                                        */
  real_T P_33;                         /* Expression: 1+eps
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T P_34;                         /* Expression: modu
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T P_35;                         /* Expression: init
                                        * Referenced by: '<S23>/IC'
                                        */
  real_T P_36;                         /* Expression: 0.1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T P_37;                         /* Expression: 1345
                                        * Referenced by: '<Root>/Desired frequency'
                                        */
  real_T P_38;                         /* Expression: 1/(2*pi)
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T P_39;                         /* Expression: 10000
                                        * Referenced by: '<Root>/Sample Frequency'
                                        */
  real_T P_40;                         /* Expression: 2/(2^8)
                                        * Referenced by: '<Root>/Quantizer'
                                        */
  real_T P_41;                         /* Expression: 1+eps
                                        * Referenced by: '<S45>/Gain'
                                        */
  real_T P_42;                         /* Expression: modu
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T P_43;                         /* Expression: init
                                        * Referenced by: '<S45>/IC'
                                        */
  real_T P_44;                         /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T P_45;                         /* Expression: -1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T P_46;                         /* Expression: 200
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T P_47;                         /* Computed Parameter: P_47
                                        * Referenced by: '<S1>/State-Space'
                                        */
  real_T P_48;                         /* Computed Parameter: P_48
                                        * Referenced by: '<S1>/State-Space'
                                        */
  real_T P_49;                         /* Computed Parameter: P_49
                                        * Referenced by: '<S1>/State-Space'
                                        */
  real_T P_50;                         /* Computed Parameter: P_50
                                        * Referenced by: '<S1>/State-Space'
                                        */
  real_T P_51;                         /* Expression: x0c
                                        * Referenced by: '<S1>/State-Space'
                                        */
  real_T P_52[3];                      /* Computed Parameter: P_52
                                        * Referenced by: '<S2>/State-Space'
                                        */
  real_T P_53;                         /* Computed Parameter: P_53
                                        * Referenced by: '<S2>/State-Space'
                                        */
  real_T P_54;                         /* Computed Parameter: P_54
                                        * Referenced by: '<S2>/State-Space'
                                        */
  real_T P_56;                         /* Expression: x0c
                                        * Referenced by: '<S2>/State-Space'
                                        */
  real_T P_57[3];                      /* Computed Parameter: P_57
                                        * Referenced by: '<Root>/Analog Filter Design'
                                        */
  real_T P_58;                         /* Computed Parameter: P_58
                                        * Referenced by: '<Root>/Analog Filter Design'
                                        */
  real_T P_59;                         /* Computed Parameter: P_59
                                        * Referenced by: '<Root>/Analog Filter Design'
                                        */
  real_T P_61;                         /* Expression: 0
                                        * Referenced by: '<Root>/Analog Filter Design'
                                        */
  real_T P_62;                         /* Expression: Fc
                                        * Referenced by: '<S3>/Carrier frequency1'
                                        */
  real_T P_63;                         /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T P_64;                         /* Expression: Kc
                                        * Referenced by: '<S3>/Sensitivity'
                                        */
  real_T P_65;                         /* Computed Parameter: P_65
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T P_66;                         /* Computed Parameter: P_66
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T P_67;                         /* Computed Parameter: P_67
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T P_70;                         /* Expression: Fc
                                        * Referenced by: '<S17>/Carrier frequency1'
                                        */
  real_T P_71;                         /* Expression: Kc
                                        * Referenced by: '<S17>/Sensitivity'
                                        */
  uint8_T P_72;                        /* Expression: uint8(1)
                                        * Referenced by: '<S7>/Constant'
                                        */
  uint8_T P_73;                        /* Expression: uint8(0)
                                        * Referenced by: '<S7>/SwitchControl'
                                        */
  uint8_T P_74;                        /* Expression: uint8(1)
                                        * Referenced by: '<S8>/Constant'
                                        */
  uint8_T P_75;                        /* Expression: uint8(1)
                                        * Referenced by: '<S8>/SwitchControl'
                                        */
  uint8_T P_76;                        /* Expression: uint8(1)
                                        * Referenced by: '<S9>/Constant'
                                        */
  uint8_T P_77;                        /* Expression: uint8(0)
                                        * Referenced by: '<S9>/SwitchControl'
                                        */
  uint8_T P_78;                        /* Expression: uint8(1)
                                        * Referenced by: '<S10>/Constant'
                                        */
  uint8_T P_79;                        /* Expression: uint8(0)
                                        * Referenced by: '<S10>/SwitchControl'
                                        */
  uint8_T P_80;                        /* Expression: uint8(1)
                                        * Referenced by: '<S11>/Constant'
                                        */
  uint8_T P_81;                        /* Expression: uint8(0)
                                        * Referenced by: '<S11>/SwitchControl'
                                        */
  uint8_T P_82;                        /* Expression: uint8(1)
                                        * Referenced by: '<S12>/Constant'
                                        */
  uint8_T P_83;                        /* Expression: uint8(1)
                                        * Referenced by: '<S13>/Constant'
                                        */
  uint8_T P_84;                        /* Expression: uint8(1)
                                        * Referenced by: '<S13>/SwitchControl'
                                        */
  uint8_T P_85;                        /* Expression: uint8(1)
                                        * Referenced by: '<S12>/SwitchControl'
                                        */
  char pad_P_85[2];
};

extern Parameters rtDefaultParameters; /* parameters */

/* Constant parameters (auto storage) */
extern const ConstParam rtConstP;

#endif                                 /* RTW_HEADER_new_pll_fs_acc_h_ */
