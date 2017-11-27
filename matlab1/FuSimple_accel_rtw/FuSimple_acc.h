/*
 * FuSimple_acc.h
 *
 * Real-Time Workshop code generation for Simulink model "FuSimple_acc.mdl".
 *
 * Model Version              : 1.48
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Wed Apr 21 16:48:28 2010
 */
#ifndef _RTW_HEADER_FuSimple_acc_h_
#define _RTW_HEADER_FuSimple_acc_h_
#ifndef _FuSimple_acc_COMMON_INCLUDES_
# define _FuSimple_acc_COMMON_INCLUDES_
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define S_FUNCTION_NAME                simulink_only_sfcn
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtlibsrc.h"
#include "rt_nonfinite.h"
#endif                                 /* _FuSimple_acc_COMMON_INCLUDES_ */

#include "FuSimple_acc_types.h"

/* Block signals (auto storage) */
typedef struct {
  creal_T B_5_2_0[2048];               /* '<S32>/FFT' */
  creal_T B_4_2_0[2048];               /* '<S26>/FFT' */
  real_T B_6_0_0;                      /* '<S42>/Gain' */
  real_T B_6_1_0;                      /* '<S42>/Abs' */
  real_T B_6_2_0;                      /* '<S42>/Constant' */
  real_T B_6_5_0;                      /* '<S42>/IC' */
  real_T B_6_12_0;                     /* '<Root>/Quantizer' */
  real_T B_6_14_0;                     /* '<Root>/Fin1' */
  real_T B_6_17_0;                     /* '<Root>/Pulse Generator1' */
  real_T B_6_19_0;                     /* '<Root>/Sum' */
  real_T B_6_20_0;                     /* '<Root>/Fs' */
  real_T B_6_21_0;                     /* '<S22>/Gain' */
  real_T B_6_22_0;                     /* '<S22>/Abs' */
  real_T B_6_23_0;                     /* '<S22>/Constant' */
  real_T B_6_26_0;                     /* '<S22>/IC' */
  real_T B_6_30_0;                     /* '<S17>/Inherit Shape1' */
  real_T B_6_32_0;                     /* '<S2>/Product1' */
  real_T B_6_42_0;                     /* '<S5>/SwitchControl' */
  real_T B_6_43_0;                     /* '<S3>/SwitchControl' */
  real_T B_6_46_0;                     /* '<S1>/Output' */
  real_T B_6_48_0;                     /* '<Root>/Sum2' */
  real_T B_6_49_0;                     /* '<Root>/Sum1' */
  real_T B_6_52_0;                     /* '<Root>/Gain' */
  real_T B_6_57_0;                     /* '<S14>/Sum' */
  real_T B_6_58_0;                     /* '<S12>/Carrier frequency1' */
  real_T B_6_60_0;                     /* '<S12>/Sum' */
  real_T B_5_1_1[2048];                /* '<S30>/Window' */
  real_T B_5_7_0[2048];                /* '<S30>/Product2' */
  real_T B_4_1_1[2048];                /* '<S24>/Window' */
  real_T B_4_7_0[2048];                /* '<S24>/Product2' */
  real_T B_3_0_0;                      /* '<S8>/Integrator' */
  real_T B_3_1_0;                      /* '<S8>/Integrator1' */
  real_T B_3_3_0;                      /* '<S8>/Integrator2' */
  real_T B_3_5_0;                      /* '<S8>/Kd1' */
  real_T B_3_7_0;                      /* '<S8>/Wn' */
  real_T B_3_8_0;                      /* '<S8>/Product1' */
  real_T B_3_12_0;                     /* '<S8>/Product3' */
  real_T B_3_13_0;                     /* '<S8>/Product5' */
  real_T B_3_15_0;                     /* '<S8>/Product4' */
  real_T B_3_17_0;                     /* '<S8>/Product7' */
  real_T B_2_0_0;                      /* '<S7>/Integrator' */
  real_T B_2_1_0;                      /* '<S7>/Integrator1' */
  real_T B_2_5_0;                      /* '<S7>/Wn' */
  real_T B_2_6_0;                      /* '<S7>/Product1' */
  real_T B_2_10_0;                     /* '<S7>/Product3' */
  real_T B_2_11_0;                     /* '<S7>/Product5' */
  real_T B_2_13_0;                     /* '<S7>/Product4' */
  real_T B_1_0_0;                      /* '<S6>/Integrator1' */
  real_T B_1_1_0;                      /* '<S6>/Integrator' */
  real_T B_1_10_0;                     /* '<S6>/Product1' */
  real_T B_1_13_0;                     /* '<S6>/Product5' */
  real_T B_1_14_0;                     /* '<S6>/Product4' */
  real_T B_0_0_0[2];                   /* '<S13>/MATLAB Fcn' */
  real_T B_6_9_0;                      /* '<S37>/Inherit Shape1' */
  real_T B_6_11_0;                     /* '<Root>/Fcn' */
  real_T B_6_18_0;                     /* '<S9>/SwitchControl' */
  real_T B_6_44_0;                     /* '<S4>/SwitchControl' */
  real_T B_5_4_0[2048];                /* '<S30>/Digital Filter' */
  real_T B_4_4_0[2048];                /* '<S24>/Digital Filter' */
  real_T B_5_3_0[2048];                /* '<S32>/Magnitude Squared' */
  real_T B_4_3_0[2048];                /* '<S26>/Magnitude Squared' */
  uint8_T B_6_15_0;                    /* '<S9>/Constant' */
  uint8_T B_6_16_0;                    /* '<S9>/S-Function' */
  uint8_T B_6_34_0;                    /* '<S4>/Constant' */
  uint8_T B_6_35_0;                    /* '<S4>/S-Function' */
  uint8_T B_6_37_0;                    /* '<S3>/Constant' */
  uint8_T B_6_38_0;                    /* '<S3>/S-Function' */
  uint8_T B_6_40_0;                    /* '<S5>/Constant' */
  uint8_T B_6_41_0;                    /* '<S5>/S-Function' */
  boolean_T B_6_3_0;                   /* '<S42>/Relational Operator' */
  boolean_T B_6_24_0;                  /* '<S22>/Relational Operator' */
  char pad_B_6_24_0[6];
} BlockIO;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Buffer_CircBuff[4096];        /* '<S29>/Buffer' */
  real_T DigitalFilter_FILT_STATES[4096];/* '<S30>/Digital Filter' */
  real_T Buffer_CircBuff_p[4096];      /* '<S23>/Buffer' */
  real_T DigitalFilter_FILT_STATES_p[4096];/* '<S24>/Digital Filter' */
  real_T IC_FirstOutputTime;           /* '<S42>/IC' */
  real_T nextTime;                     /* '<Root>/Pulse Generator1' */
  real_T IC_FirstOutputTime_m;         /* '<S22>/IC' */
  struct {
    real_T NextOutput;
  } WhiteNoise_RWORK;                  /* '<S1>/White Noise' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  pointer_T Buffer_IN_BUF_PTR;         /* '<S29>/Buffer' */
  pointer_T Buffer_OUT_BUF_PTR;        /* '<S29>/Buffer' */
  void *FrameScope_PWORK[3];           /* '<S11>/Frame Scope' */
  pointer_T Buffer_IN_BUF_PTR_n;       /* '<S23>/Buffer' */
  pointer_T Buffer_OUT_BUF_PTR_o;      /* '<S23>/Buffer' */
  void *FrameScope_PWORK_e[3];         /* '<S10>/Frame Scope' */
  struct {
    void *LoggedData;
  } Scope_PWORK_b;                     /* '<S8>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     /* '<S7>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_p;                     /* '<S6>/Scope' */

  int32_T justEnabled;                 /* '<Root>/Pulse Generator1' */
  int32_T currentValue;                /* '<Root>/Pulse Generator1' */
  int32_T numCompleteCycles;           /* '<Root>/Pulse Generator1' */
  int32_T Buffer_bufferLength;         /* '<S29>/Buffer' */
  int32_T Buffer_SHIFT_PER_ELEM;       /* '<S29>/Buffer' */
  int32_T DigitalFilter_CIRCBUFFIDX;   /* '<S30>/Digital Filter' */
  int32_T Buffer_bufferLength_a;       /* '<S23>/Buffer' */
  int32_T Buffer_SHIFT_PER_ELEM_j;     /* '<S23>/Buffer' */
  int32_T DigitalFilter_CIRCBUFFIDX_f; /* '<S24>/Digital Filter' */
  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S42>/Integrator' */

  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK_e;                /* '<S22>/Integrator' */

  struct {
    int_T RandSeed;
  } WhiteNoise_IWORK;                  /* '<S1>/White Noise' */

  int_T Abs_MODE;                      /* '<S42>/Abs' */
  int_T Abs_MODE_h;                    /* '<S22>/Abs' */
  int_T Integrator1_MODE;              /* '<S8>/Integrator1' */
  int_T Integrator1_MODE_e;            /* '<S7>/Integrator1' */
  int_T Integrator1_MODE_a;            /* '<S6>/Integrator1' */
  int_T Integrator_MODE;               /* '<S6>/Integrator' */
  int8_T FETDSP1_SubsysRanBC;          /* '<S2>/FET DSP1' */
  boolean_T RelationalOperator_Mode;   /* '<S42>/Relational Operator' */
  boolean_T RelationalOperator_Mode_l; /* '<S22>/Relational Operator' */
  char pad_RelationalOperator_Mode_l[5];
} D_Work;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S42>/Integrator' */
  real_T Integrator_CSTATE_j;          /* '<S22>/Integrator' */
  real_T Integrator_CSTATE_a;          /* '<S8>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S8>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S8>/Integrator2' */
  real_T Integrator_CSTATE_g;          /* '<S7>/Integrator' */
  real_T Integrator1_CSTATE_g;         /* '<S7>/Integrator1' */
  real_T Integrator1_CSTATE_n;         /* '<S6>/Integrator1' */
  real_T Integrator_CSTATE_c;          /* '<S6>/Integrator' */
} ContinuousStates;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S42>/Integrator' */
  real_T Integrator_CSTATE_j;          /* '<S22>/Integrator' */
  real_T Integrator_CSTATE_a;          /* '<S8>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S8>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S8>/Integrator2' */
  real_T Integrator_CSTATE_g;          /* '<S7>/Integrator' */
  real_T Integrator1_CSTATE_g;         /* '<S7>/Integrator1' */
  real_T Integrator1_CSTATE_n;         /* '<S6>/Integrator1' */
  real_T Integrator_CSTATE_c;          /* '<S6>/Integrator' */
} StateDerivatives;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S42>/Integrator' */
  boolean_T Integrator_CSTATE_j;       /* '<S22>/Integrator' */
  boolean_T Integrator_CSTATE_a;       /* '<S8>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S8>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S8>/Integrator2' */
  boolean_T Integrator_CSTATE_g;       /* '<S7>/Integrator' */
  boolean_T Integrator1_CSTATE_g;      /* '<S7>/Integrator1' */
  boolean_T Integrator1_CSTATE_n;      /* '<S6>/Integrator1' */
  boolean_T Integrator_CSTATE_c;       /* '<S6>/Integrator' */
} StateDisabled;

/* Zero-crossing (trigger) state */
typedef struct {
  real_T Abs_NSZC;                     /* '<S42>/Abs' */
  real_T RelationalOperator_NSZC;      /* '<S42>/Relational Operator' */
  real_T Abs_NSZC_g;                   /* '<S22>/Abs' */
  real_T RelationalOperator_NSZC_l;    /* '<S22>/Relational Operator' */
  real_T Integrator1_NSZC[3];          /* '<S8>/Integrator1' */
  real_T Integrator1_NSZC_a[3];        /* '<S7>/Integrator1' */
  real_T Integrator1_NSZC_ay[3];       /* '<S6>/Integrator1' */
  real_T Integrator_NSZC[2];           /* '<S6>/Integrator' */
  real_T FETDSP1_NSZC;                 /* '<S2>/FET DSP1' */
} NonsampledZCs;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_ZCE;           /* '<S42>/Integrator' */
  ZCSigState Integrator_ZCE_l;         /* '<S22>/Integrator' */
  ZCSigState FETDSP1_ZCE;              /* '<S2>/FET DSP1' */
} PrevZCSigStates;

/* Parameters (auto storage) */
struct Parameters {
  real_T P_0;                          /* Expression: 1+eps
                                        * '<S42>/Gain'
                                        */
  real_T P_1;                          /* Expression: modu
                                        * '<S42>/Constant'
                                        */
  real_T P_2;                          /* Expression: init
                                        * '<S42>/IC'
                                        */
  real_T P_3;                          /* Expression: 2/(2^12)
                                        * '<Root>/Quantizer'
                                        */
  real_T P_4;                          /* Expression: 1112
                                        * '<Root>/Fin'
                                        */
  real_T P_5;                          /* Expression: 0
                                        * '<Root>/Fin1'
                                        */
  real_T P_6;                          /* Expression: 100
                                        * '<Root>/Pulse Generator1'
                                        */
  real_T P_7;                          /* Expression: 1/90
                                        * '<Root>/Pulse Generator1'
                                        */
  real_T P_8;                          /* Expression: 50
                                        * '<Root>/Pulse Generator1'
                                        */
  real_T P_9;                          /* Expression: 10000
                                        * '<Root>/Fs'
                                        */
  real_T P_10;                         /* Expression: 1+eps
                                        * '<S22>/Gain'
                                        */
  real_T P_11;                         /* Expression: modu
                                        * '<S22>/Constant'
                                        */
  real_T P_12;                         /* Expression: init
                                        * '<S22>/IC'
                                        */
  real_T P_13;                         /* Expression: 0
                                        * '<S1>/White Noise'
                                        */
  real_T P_14;                         /* Computed Parameter: StdDev
                                        * '<S1>/White Noise'
                                        */
  real_T P_15;                         /* Expression: seed
                                        * '<S1>/White Noise'
                                        */
  real_T P_16;                         /* Expression: [sqrt(Cov)]/[sqrt(Ts)]
                                        * '<S1>/Output'
                                        */
  real_T P_17;                         /* Expression: 0*30000
                                        * '<Root>/Band'
                                        */
  real_T P_18;                         /* Expression: 0.1
                                        * '<Root>/Gain'
                                        */
  real_T P_19;                         /* Expression: Fc
                                        * '<S14>/Carrier frequency1'
                                        */
  real_T P_20;                         /* Expression: Kc
                                        * '<S14>/Sensitivity'
                                        */
  real_T P_21;                         /* Expression: Fc
                                        * '<S12>/Carrier frequency1'
                                        */
  real_T P_22;                         /* Expression: Kc
                                        * '<S12>/Sensitivity'
                                        */
  real_T P_23;                         /* Expression: 100
                                        * '<S6>/Integrator1'
                                        */
  real_T P_24;                         /* Expression: 5000
                                        * '<S6>/Integrator1'
                                        */
  real_T P_25;                         /* Expression: 10
                                        * '<S6>/Integrator1'
                                        */
  real_T P_26;                         /* Expression: 2500
                                        * '<S6>/Integrator'
                                        */
  real_T P_27;                         /* Expression: 5000
                                        * '<S6>/Integrator'
                                        */
  real_T P_28;                         /* Expression: 10
                                        * '<S6>/Integrator'
                                        */
  real_T P_29;                         /* Expression: 0.61
                                        * '<S6>/Kd'
                                        */
  real_T P_30;                         /* Expression: 1
                                        * '<S6>/Kv'
                                        */
  real_T P_31;                         /* Expression: 2*pi*250
                                        * '<S6>/Wn'
                                        */
  real_T P_32;                         /* Expression: .7
                                        * '<S6>/Z'
                                        */
  real_T P_33;                         /* Expression: 2
                                        * '<S6>/cZ'
                                        */
  real_T P_34;                         /* Expression: 0
                                        * '<S7>/Integrator'
                                        */
  real_T P_35;                         /* Expression: 1000
                                        * '<S7>/Integrator1'
                                        */
  real_T P_36;                         /* Expression: 5000
                                        * '<S7>/Integrator1'
                                        */
  real_T P_37;                         /* Expression: 10
                                        * '<S7>/Integrator1'
                                        */
  real_T P_38;                         /* Expression: 1
                                        * '<S7>/Kd'
                                        */
  real_T P_39;                         /* Expression: 1
                                        * '<S7>/Kv'
                                        */
  real_T P_40;                         /* Expression: 2*pi*250
                                        * '<S7>/Wn'
                                        */
  real_T P_41;                         /* Expression: .7
                                        * '<S7>/Z'
                                        */
  real_T P_42;                         /* Expression: 2
                                        * '<S7>/cZ'
                                        */
  real_T P_43;                         /* Expression: 0
                                        * '<S8>/Integrator'
                                        */
  real_T P_44;                         /* Expression: 1000
                                        * '<S8>/Integrator1'
                                        */
  real_T P_45;                         /* Expression: 5000
                                        * '<S8>/Integrator1'
                                        */
  real_T P_46;                         /* Expression: 10
                                        * '<S8>/Integrator1'
                                        */
  real_T P_47;                         /* Expression: 0
                                        * '<S8>/Integrator2'
                                        */
  real_T P_48;                         /* Expression: 1
                                        * '<S8>/Kd'
                                        */
  real_T P_49;                         /* Expression: 5
                                        * '<S8>/Kd1'
                                        */
  real_T P_50;                         /* Expression: 1
                                        * '<S8>/Kv'
                                        */
  real_T P_51;                         /* Expression: 2*pi*250
                                        * '<S8>/Wn'
                                        */
  real_T P_52;                         /* Expression: .7
                                        * '<S8>/Z'
                                        */
  real_T P_53;                         /* Expression: 2
                                        * '<S8>/cZ'
                                        */
  real_T P_54;                         /* Computed Parameter: IC
                                        * '<S23>/Buffer'
                                        */
  real_T P_55[2048];                   /* Computed Parameter: WindowSamples
                                        * '<S24>/Window'
                                        */
  real_T P_56[1536];                   /* Computed Parameter: TwiddleTable
                                        * '<S26>/FFT'
                                        */
  real_T P_57;                         /* Expression: a.IC
                                        * '<S24>/Digital Filter'
                                        */
  real_T P_58[2];                      /* Expression: NumCoeffs
                                        * '<S24>/Digital Filter'
                                        */
  real_T P_59;                         /* Computed Parameter: IC
                                        * '<S29>/Buffer'
                                        */
  real_T P_60[2048];                   /* Computed Parameter: WindowSamples
                                        * '<S30>/Window'
                                        */
  real_T P_61[1536];                   /* Computed Parameter: TwiddleTable
                                        * '<S32>/FFT'
                                        */
  real_T P_62;                         /* Expression: a.IC
                                        * '<S30>/Digital Filter'
                                        */
  real_T P_63[2];                      /* Expression: NumCoeffs
                                        * '<S30>/Digital Filter'
                                        */
  uint8_T P_64;                        /* Expression: uint8(1)
                                        * '<S9>/Constant'
                                        */
  uint8_T P_65;                        /* Expression: uint8(0)
                                        * '<S9>/SwitchControl'
                                        */
  uint8_T P_66;                        /* Expression: uint8(1)
                                        * '<S4>/Constant'
                                        */
  uint8_T P_67;                        /* Expression: uint8(1)
                                        * '<S3>/Constant'
                                        */
  uint8_T P_68;                        /* Expression: uint8(1)
                                        * '<S5>/Constant'
                                        */
  uint8_T P_69;                        /* Expression: uint8(1)
                                        * '<S5>/SwitchControl'
                                        */
  uint8_T P_70;                        /* Expression: uint8(1)
                                        * '<S3>/SwitchControl'
                                        */
  uint8_T P_71;                        /* Expression: uint8(1)
                                        * '<S4>/SwitchControl'
                                        */
};

extern Parameters rtDefaultParameters; /* parameters */

#endif                                 /* _RTW_HEADER_FuSimple_acc_h_ */
