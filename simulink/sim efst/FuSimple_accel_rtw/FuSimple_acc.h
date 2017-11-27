/*
 * FuSimple_acc.h
 *
 * Real-Time Workshop code generation for Simulink model "FuSimple_acc.mdl".
 *
 * Model Version                        : 1.46
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Wed Mar 11 12:29:22 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Wed Mar 11 12:29:22 2009
 */

#ifndef _RTW_HEADER_FuSimple_acc_h_
# define _RTW_HEADER_FuSimple_acc_h_

#ifndef _FuSimple_acc_COMMON_INCLUDES_
# define _FuSimple_acc_COMMON_INCLUDES_
#include <math.h>
#include <stdlib.h>
#include <float.h>

#define S_FUNCTION_NAME                 simulink_only_sfcn
#define S_FUNCTION_LEVEL                2
#define RTW_GENERATED_S_FUNCTION

#include "simstruc.h"
#include "rtlibsrc.h"

#endif                                  /* _FuSimple_acc_COMMON_INCLUDES_ */

#include "FuSimple_acc_types.h"

/* Intrinsic types */
#ifndef POINTER_T
# define POINTER_T
typedef void * pointer_T;
#endif

/* Block signals (auto storage) */
typedef struct _FuSimple_BlockIO {
  real_T Gain_a;                        /* '<S48>/Gain' */
  real_T Abs_a;                         /* '<S48>/Abs' */
  real_T Constant_a;                    /* '<S48>/Constant' */
  real_T IC_a;                          /* '<S48>/IC' */
  real_T Quantizer;                     /* '<Root>/Quantizer' */
  real_T Fin;                           /* '<Root>/Fin' */
  real_T Fin1;                          /* '<Root>/Fin1' */
  real_T Pulse_Generator1;              /* '<Root>/Pulse Generator1' */
  real_T Sum_a;                         /* '<Root>/Sum' */
  real_T Fs;                            /* '<Root>/Fs' */
  real_T Gain_b;                        /* '<S25>/Gain' */
  real_T Abs_b;                         /* '<S25>/Abs' */
  real_T Constant_b;                    /* '<S25>/Constant' */
  real_T IC_b;                          /* '<S25>/IC' */
  real_T Inherit_Shape1_d;              /* '<S19>/Inherit Shape1' */
  real_T Product1_a;                    /* '<S2>/Product1' */
  real_T Gain_c;                        /* '<S1>/Gain' */
  real_T Band;                          /* '<Root>/Band' */
  real_T Sum2;                          /* '<Root>/Sum2' */
  real_T Gain_d;                        /* '<Root>/Gain' */
  real_T Carrier_frequency1_a;          /* '<S16>/Carrier frequency1' */
  real_T Sum_b;                         /* '<S16>/Sum' */
  real_T Carrier_frequency1_b;          /* '<S14>/Carrier frequency1' */
  real_T Sum_c;                         /* '<S14>/Sum' */
  real_T Buffer_b[2048];                /* '<S34>/Buffer' */
  real_T Window_b_o2[2048];             /* '<S35>/Window' */
  real_T Magnitude_Squared_b[2048];     /* '<S36>/Magnitude Squared' */
  real_T Digital_Filter_b[2048];        /* '<S35>/Digital Filter' */
  real_T Product2_e[2048];              /* '<S35>/Product2' */
  real_T Buffer_a[2048];                /* '<S27>/Buffer' */
  real_T Window_a_o2[2048];             /* '<S28>/Window' */
  real_T Magnitude_Squared_a[2048];     /* '<S29>/Magnitude Squared' */
  real_T Digital_Filter_a[2048];        /* '<S28>/Digital Filter' */
  real_T Product2_d[2048];              /* '<S28>/Product2' */
  real_T Integrator_e;                  /* '<S8>/Integrator' */
  real_T Integrator1_c;                 /* '<S8>/Integrator1' */
  real_T Integrator2;                   /* '<S8>/Integrator2' */
  real_T Kd_c;                          /* '<S8>/Kd' */
  real_T Kd1;                           /* '<S8>/Kd1' */
  real_T Kv_c;                          /* '<S8>/Kv' */
  real_T Wn_c;                          /* '<S8>/Wn' */
  real_T Product1_d;                    /* '<S8>/Product1' */
  real_T Z_c;                           /* '<S8>/Z' */
  real_T cZ_c;                          /* '<S8>/cZ' */
  real_T Product3_c;                    /* '<S8>/Product3' */
  real_T Product5_c;                    /* '<S8>/Product5' */
  real_T Product4_c;                    /* '<S8>/Product4' */
  real_T Product7;                      /* '<S8>/Product7' */
  real_T Integrator_d;                  /* '<S7>/Integrator' */
  real_T Integrator1_b;                 /* '<S7>/Integrator1' */
  real_T Kd_b;                          /* '<S7>/Kd' */
  real_T Kv_b;                          /* '<S7>/Kv' */
  real_T Wn_b;                          /* '<S7>/Wn' */
  real_T Product1_c;                    /* '<S7>/Product1' */
  real_T Z_b;                           /* '<S7>/Z' */
  real_T cZ_b;                          /* '<S7>/cZ' */
  real_T Product3_b;                    /* '<S7>/Product3' */
  real_T Product5_b;                    /* '<S7>/Product5' */
  real_T Product4_b;                    /* '<S7>/Product4' */
  real_T Integrator1_a;                 /* '<S6>/Integrator1' */
  real_T Integrator_c;                  /* '<S6>/Integrator' */
  real_T Kd_a;                          /* '<S6>/Kd' */
  real_T Kv_a;                          /* '<S6>/Kv' */
  real_T Wn_a;                          /* '<S6>/Wn' */
  real_T Z_a;                           /* '<S6>/Z' */
  real_T cZ_a;                          /* '<S6>/cZ' */
  real_T Product1_b;                    /* '<S6>/Product1' */
  real_T Product5_a;                    /* '<S6>/Product5' */
  real_T Product4_a;                    /* '<S6>/Product4' */
  real_T Switch_c;                      /* '<S3>/Switch' */
  real_T MATLAB_Fcn[2];                 /* '<S15>/MATLAB Fcn' */
  real_T Fcn;                           /* '<Root>/Fcn' */
  real_T temp72;                        /* '<S42>/Inherit Shape1' */
  real_T temp73;                        /* '<Root>/Sum1' */
  boolean_T Relational_Operator_a;      /* '<S48>/Relational Operator' */
  boolean_T S_Function_a;               /* '<S9>/S-Function' */
  boolean_T Relational_Operator_b;      /* '<S25>/Relational Operator' */
  boolean_T S_Function_b;               /* '<S4>/S-Function' */
  boolean_T S_Function_c;               /* '<S3>/S-Function' */
  boolean_T S_Function_d;               /* '<S5>/S-Function' */
  char pad_S_Function_d[2];
} FuSimple_BlockIO;

/* Block states (auto storage) for system: '<Root>' */
typedef struct FuSimple_D_Work_tag {
  real_T Buffer_a_CircBuff[4096];       /* <S27>/Buffer */
  real_T Buffer_b_CircBuff[4096];       /* <S34>/Buffer */
  real_T Digital_Filter_a_FILT_STATES[4096]; /* <S28>/Digital Filter */
  real_T Digital_Filter_b_FILT_STATES[4096]; /* <S35>/Digital Filter */
  real_T IC_a_FirstOutputTime;          /* <S48>/IC */
  real_T IC_b_FirstOutputTime;          /* <S25>/IC */
  struct {
    real_T nextTime;
  } Pulse_Generator1_RWORK;             /* '<Root>/Pulse Generator1' */
  struct {
    real_T NextOutput;
  } White_Noise_RWORK;                  /* '<S1>/White Noise' */
  pointer_T Buffer_a_IN_BUF_PTR;        /* <S27>/Buffer */
  pointer_T Buffer_b_IN_BUF_PTR;        /* <S34>/Buffer */
  pointer_T Buffer_a_OUT_BUF_PTR;       /* <S27>/Buffer */
  pointer_T Buffer_b_OUT_BUF_PTR;       /* <S34>/Buffer */
  struct {
    void *LoggedData;
  } Scope_b_PWORK;                      /* '<S6>/Scope' */
  struct {
    void *LoggedData;
  } Scope_c_PWORK;                      /* '<S7>/Scope' */
  struct {
    void *LoggedData;
  } Scope_d_PWORK;                      /* '<S8>/Scope' */
  struct {
    void *LoggedData;
  } Scope_a_PWORK;                      /* '<Root>/Scope' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                       /* '<Root>/Scope1' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                       /* '<Root>/Scope2' */
  int32_T Buffer_a_ShiftPerElem;        /* <S27>/Buffer */
  int32_T Buffer_b_ShiftPerElem;        /* <S34>/Buffer */
  int32_T Digital_Filter_a_DF_INDX;     /* <S28>/Digital Filter */
  int32_T Digital_Filter_b_DF_INDX;     /* <S35>/Digital Filter */
  struct {
    int_T IcNeedsLoading;
  } Integrator_a_IWORK;                 /* '<S48>/Integrator' */
  struct {
    int_T justEnabled;
    int_T currValue;
    int_T numCompleteCycles;
  } Pulse_Generator1_IWORK;             /* '<Root>/Pulse Generator1' */
  struct {
    int_T IcNeedsLoading;
  } Integrator_b_IWORK;                 /* '<S25>/Integrator' */
  struct {
    int_T RandSeed;
  } White_Noise_IWORK;                  /* '<S1>/White Noise' */
  int_T Integrator1_a_MODE;             /* <S6>/Integrator1 */
  int_T Abs_a_MODE;                     /* <S48>/Abs */
  int_T Integrator_c_MODE;              /* <S6>/Integrator */
  int_T Integrator1_b_MODE;             /* <S7>/Integrator1 */
  int_T Integrator1_c_MODE;             /* <S8>/Integrator1 */
  int_T Relational_Operator_a_MODE;     /* <S48>/Relational Operator */
  int_T Abs_b_MODE;                     /* <S25>/Abs */
  int_T Relational_Operator_b_MODE;     /* <S25>/Relational Operator */
} FuSimple_D_Work;

/* Continuous states (auto storage) */
typedef struct _FuSimple_ContinuousStates {
  real_T Integrator_a_CSTATE;           /* '<S48>/Integrator' */
  real_T Integrator_b_CSTATE;           /* '<S25>/Integrator' */
  real_T Integrator_e_CSTATE;           /* '<S8>/Integrator' */
  real_T Integrator1_c_CSTATE;          /* '<S8>/Integrator1' */
  real_T Integrator2_CSTATE;            /* '<S8>/Integrator2' */
  real_T Integrator_d_CSTATE;           /* '<S7>/Integrator' */
  real_T Integrator1_b_CSTATE;          /* '<S7>/Integrator1' */
  real_T Integrator1_a_CSTATE;          /* '<S6>/Integrator1' */
  real_T Integrator_c_CSTATE;           /* '<S6>/Integrator' */
} FuSimple_ContinuousStates;

/* State derivatives (auto storage) */
typedef struct _FuSimple_StateDerivatives {
  real_T Integrator_a_CSTATE;           /* '<S48>/Integrator' */
  real_T Integrator_b_CSTATE;           /* '<S25>/Integrator' */
  real_T Integrator_e_CSTATE;           /* '<S8>/Integrator' */
  real_T Integrator1_c_CSTATE;          /* '<S8>/Integrator1' */
  real_T Integrator2_CSTATE;            /* '<S8>/Integrator2' */
  real_T Integrator_d_CSTATE;           /* '<S7>/Integrator' */
  real_T Integrator1_b_CSTATE;          /* '<S7>/Integrator1' */
  real_T Integrator1_a_CSTATE;          /* '<S6>/Integrator1' */
  real_T Integrator_c_CSTATE;           /* '<S6>/Integrator' */
} FuSimple_StateDerivatives;

/* State disabled  */
typedef struct _FuSimple_StateDisabled {
  boolean_T Integrator_a_CSTATE;        /* '<S48>/Integrator' */
  boolean_T Integrator_b_CSTATE;        /* '<S25>/Integrator' */
  boolean_T Integrator_e_CSTATE;        /* '<S8>/Integrator' */
  boolean_T Integrator1_c_CSTATE;       /* '<S8>/Integrator1' */
  boolean_T Integrator2_CSTATE;         /* '<S8>/Integrator2' */
  boolean_T Integrator_d_CSTATE;        /* '<S7>/Integrator' */
  boolean_T Integrator1_b_CSTATE;       /* '<S7>/Integrator1' */
  boolean_T Integrator1_a_CSTATE;       /* '<S6>/Integrator1' */
  boolean_T Integrator_c_CSTATE;        /* '<S6>/Integrator' */
} FuSimple_StateDisabled;

/* Zero-crossing (trigger) state */
typedef struct _FuSimple_NonsampledZCs {
  real_T Abs_a_NSZC;                    /* '<S48>/Abs' */
  real_T Relational_Operator_a_NSZC;    /* '<S48>/Relational Operator' */
  real_T Abs_b_NSZC;                    /* '<S25>/Abs' */
  real_T Relational_Operator_b_NSZC;    /* '<S25>/Relational Operator' */
  real_T Integrator1_c_NSZC[3];         /* '<S8>/Integrator1' */
  real_T Integrator1_b_NSZC[3];         /* '<S7>/Integrator1' */
  real_T Integrator1_a_NSZC[3];         /* '<S6>/Integrator1' */
  real_T Integrator_c_NSZC[2];          /* '<S6>/Integrator' */
  real_T FET_DSP1_NSZC;                 /* '<S2>/FET DSP1' */
} FuSimple_NonsampledZCs;

/* Zero-crossing (trigger) state */
typedef struct _FuSimple_PrevZCSigStates {
  ZCSigState Integrator_a_ZCE;          /* '<S48>/Integrator' */
  ZCSigState Integrator_b_ZCE;          /* '<S25>/Integrator' */
  ZCSigState FET_DSP1_ZCE;              /* '<S2>/FET DSP1' */
} FuSimple_PrevZCSigStates;

/* Parameters (auto storage) */
struct _FuSimple_Parameters {
  real_T Gain_a_Gain;                   /* Expression: 1+eps
                                         * '<S48>/Gain'
                                         */
  real_T Constant_a_Value;              /* Expression: modu
                                         * '<S48>/Constant'
                                         */
  real_T IC_a_Value;                    /* Expression: init
                                         * '<S48>/IC'
                                         */
  real_T Quantizer_Interval;            /* Expression: 2/(2^12)
                                         * '<Root>/Quantizer'
                                         */
  real_T Fin_Value;                     /* Expression: 1501
                                         * '<Root>/Fin'
                                         */
  real_T Fin1_Value;                    /* Expression: 0
                                         * '<Root>/Fin1'
                                         */
  real_T Pulse_Generator1_Amp;          /* Expression: 1000
                                         * '<Root>/Pulse Generator1'
                                         */
  real_T Pulse_Generator1_Period;       /* Expression: 1/30
                                         * '<Root>/Pulse Generator1'
                                         */
  real_T Pulse_Generator1_Duty;         /* Expression: 50
                                         * '<Root>/Pulse Generator1'
                                         */
  real_T Fs_Value;                      /* Expression: 10000
                                         * '<Root>/Fs'
                                         */
  real_T Gain_b_Gain;                   /* Expression: 1+eps
                                         * '<S25>/Gain'
                                         */
  real_T Constant_b_Value;              /* Expression: modu
                                         * '<S25>/Constant'
                                         */
  real_T IC_b_Value;                    /* Expression: init
                                         * '<S25>/IC'
                                         */
  real_T White_Noise_Mean;              /* Expression: 0
                                         * '<S1>/White Noise'
                                         */
  real_T White_Noise_StdDev;            /* Computed Parameter: StdDev
                                         * '<S1>/White Noise'
                                         */
  real_T Gain_c_Gain;                   /* Expression: [sqrt(Cov)]/[sqrt(Ts)]
                                         * '<S1>/Gain'
                                         */
  real_T Band_Value;                    /* Expression: 0*30000
                                         * '<Root>/Band'
                                         */
  real_T Gain_d_Gain;                   /* Expression: 0.1
                                         * '<Root>/Gain'
                                         */
  real_T Carrier_frequency1_a_Value;    /* Expression: Fc
                                         * '<S16>/Carrier frequency1'
                                         */
  real_T Check_Signal_Attributes_a_P1; /* Expression: SigAttribCheckMethod
                                        * '<S17>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P2; /* Expression: Complexity
                                        * '<S17>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P3; /* Expression: Frame
                                        * '<S17>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P4; /* Expression: DimsCheckMethod
                                        * '<S17>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P5; /* Expression: Dimensions
                                        * '<S17>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P6; /* Expression: DatatypeCheckMethod
                                        * '<S17>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P7; /* Expression: DatatypeGeneral
                                        * '<S17>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P8; /* Expression: DtypeFloatSpecific
                                        * '<S17>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P9; /* Expression: DtypeFixedSpecific
                                        * '<S17>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P10; /* Expression: DtypeIntSpecific
                                         * '<S17>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_a_P11; /* Expression: SampleMode
                                         * '<S17>/Check Signal Attributes'
                                         */
  real_T Reshape_a_P1;                  /* Expression: OutputDimensionality
                                         * '<S18>/Reshape'
                                         */
  real_T Reshape_a_P2[2];               /* Expression: OutputDimensions
                                         * '<S18>/Reshape'
                                         */
  real_T Sensitivity_a_Gain;            /* Expression: Kc
                                         * '<S16>/Sensitivity'
                                         */
  real_T Check_Signal_Attributes_b_P1; /* Expression: SigAttribCheckMethod
                                        * '<S22>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P2; /* Expression: Complexity
                                        * '<S22>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P3; /* Expression: Frame
                                        * '<S22>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P4; /* Expression: DimsCheckMethod
                                        * '<S22>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P5; /* Expression: Dimensions
                                        * '<S22>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P6; /* Expression: DatatypeCheckMethod
                                        * '<S22>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P7; /* Expression: DatatypeGeneral
                                        * '<S22>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P8; /* Expression: DtypeFloatSpecific
                                        * '<S22>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P9; /* Expression: DtypeFixedSpecific
                                        * '<S22>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P10; /* Expression: DtypeIntSpecific
                                         * '<S22>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_b_P11; /* Expression: SampleMode
                                         * '<S22>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_c_P1; /* Expression: SigAttribCheckMethod
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P2; /* Expression: Complexity
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P3; /* Expression: Frame
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P4; /* Expression: DimsCheckMethod
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P5; /* Expression: Dimensions
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P6; /* Expression: DatatypeCheckMethod
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P7; /* Expression: DatatypeGeneral
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P8; /* Expression: DtypeFloatSpecific
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P9; /* Expression: DtypeFixedSpecific
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P10; /* Expression: DtypeIntSpecific
                                         * '<S23>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_c_P11; /* Expression: SampleMode
                                         * '<S23>/Check Signal Attributes'
                                         */
  real_T Carrier_frequency1_b_Value;    /* Expression: Fc
                                         * '<S14>/Carrier frequency1'
                                         */
  real_T Check_Signal_Attributes_d_P1; /* Expression: SigAttribCheckMethod
                                        * '<S40>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P2; /* Expression: Complexity
                                        * '<S40>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P3; /* Expression: Frame
                                        * '<S40>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P4; /* Expression: DimsCheckMethod
                                        * '<S40>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P5; /* Expression: Dimensions
                                        * '<S40>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P6; /* Expression: DatatypeCheckMethod
                                        * '<S40>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P7; /* Expression: DatatypeGeneral
                                        * '<S40>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P8; /* Expression: DtypeFloatSpecific
                                        * '<S40>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P9; /* Expression: DtypeFixedSpecific
                                        * '<S40>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P10; /* Expression: DtypeIntSpecific
                                         * '<S40>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_d_P11; /* Expression: SampleMode
                                         * '<S40>/Check Signal Attributes'
                                         */
  real_T Reshape_b_P1;                  /* Expression: OutputDimensionality
                                         * '<S41>/Reshape'
                                         */
  real_T Reshape_b_P2[2];               /* Expression: OutputDimensions
                                         * '<S41>/Reshape'
                                         */
  real_T Sensitivity_b_Gain;            /* Expression: Kc
                                         * '<S14>/Sensitivity'
                                         */
  real_T Check_Signal_Attributes_e_P1; /* Expression: SigAttribCheckMethod
                                        * '<S45>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P2; /* Expression: Complexity
                                        * '<S45>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P3; /* Expression: Frame
                                        * '<S45>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P4; /* Expression: DimsCheckMethod
                                        * '<S45>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P5; /* Expression: Dimensions
                                        * '<S45>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P6; /* Expression: DatatypeCheckMethod
                                        * '<S45>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P7; /* Expression: DatatypeGeneral
                                        * '<S45>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P8; /* Expression: DtypeFloatSpecific
                                        * '<S45>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P9; /* Expression: DtypeFixedSpecific
                                        * '<S45>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P10; /* Expression: DtypeIntSpecific
                                         * '<S45>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_e_P11; /* Expression: SampleMode
                                         * '<S45>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_f_P1; /* Expression: SigAttribCheckMethod
                                        * '<S46>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P2; /* Expression: Complexity
                                        * '<S46>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P3; /* Expression: Frame
                                        * '<S46>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P4; /* Expression: DimsCheckMethod
                                        * '<S46>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P5; /* Expression: Dimensions
                                        * '<S46>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P6; /* Expression: DatatypeCheckMethod
                                        * '<S46>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P7; /* Expression: DatatypeGeneral
                                        * '<S46>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P8; /* Expression: DtypeFloatSpecific
                                        * '<S46>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P9; /* Expression: DtypeFixedSpecific
                                        * '<S46>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P10; /* Expression: DtypeIntSpecific
                                         * '<S46>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_f_P11; /* Expression: SampleMode
                                         * '<S46>/Check Signal Attributes'
                                         */
  real_T Integrator1_a_IC;              /* Expression: 100
                                         * '<S6>/Integrator1'
                                         */
  real_T Integrator1_a_UpperSat;        /* Expression: 5000
                                         * '<S6>/Integrator1'
                                         */
  real_T Integrator1_a_LowerSat;        /* Expression: 10
                                         * '<S6>/Integrator1'
                                         */
  real_T Integrator_c_IC;               /* Expression: 2500
                                         * '<S6>/Integrator'
                                         */
  real_T Integrator_c_UpperSat;         /* Expression: 5000
                                         * '<S6>/Integrator'
                                         */
  real_T Integrator_c_LowerSat;         /* Expression: 10
                                         * '<S6>/Integrator'
                                         */
  real_T Kd_a_Value;                    /* Expression: 0.61
                                         * '<S6>/Kd'
                                         */
  real_T Kv_a_Value;                    /* Expression: 1
                                         * '<S6>/Kv'
                                         */
  real_T Wn_a_Value;                    /* Expression: 2*pi*250
                                         * '<S6>/Wn'
                                         */
  real_T Z_a_Value;                     /* Expression: .7
                                         * '<S6>/Z'
                                         */
  real_T cZ_a_Value;                    /* Expression: 2
                                         * '<S6>/cZ'
                                         */
  real_T Integrator_d_IC;               /* Expression: 0
                                         * '<S7>/Integrator'
                                         */
  real_T Integrator1_b_IC;              /* Expression: 1000
                                         * '<S7>/Integrator1'
                                         */
  real_T Integrator1_b_UpperSat;        /* Expression: 5000
                                         * '<S7>/Integrator1'
                                         */
  real_T Integrator1_b_LowerSat;        /* Expression: 10
                                         * '<S7>/Integrator1'
                                         */
  real_T Kd_b_Value;                    /* Expression: 1
                                         * '<S7>/Kd'
                                         */
  real_T Kv_b_Value;                    /* Expression: 1
                                         * '<S7>/Kv'
                                         */
  real_T Wn_b_Value;                    /* Expression: 2*pi*250
                                         * '<S7>/Wn'
                                         */
  real_T Z_b_Value;                     /* Expression: .7
                                         * '<S7>/Z'
                                         */
  real_T cZ_b_Value;                    /* Expression: 2
                                         * '<S7>/cZ'
                                         */
  real_T Integrator_e_IC;               /* Expression: 0
                                         * '<S8>/Integrator'
                                         */
  real_T Integrator1_c_IC;              /* Expression: 1000
                                         * '<S8>/Integrator1'
                                         */
  real_T Integrator1_c_UpperSat;        /* Expression: 5000
                                         * '<S8>/Integrator1'
                                         */
  real_T Integrator1_c_LowerSat;        /* Expression: 10
                                         * '<S8>/Integrator1'
                                         */
  real_T Integrator2_IC;                /* Expression: 0
                                         * '<S8>/Integrator2'
                                         */
  real_T Kd_c_Value;                    /* Expression: 1
                                         * '<S8>/Kd'
                                         */
  real_T Kd1_Value;                     /* Expression: 5
                                         * '<S8>/Kd1'
                                         */
  real_T Kv_c_Value;                    /* Expression: 1
                                         * '<S8>/Kv'
                                         */
  real_T Wn_c_Value;                    /* Expression: 2*pi*250
                                         * '<S8>/Wn'
                                         */
  real_T Z_c_Value;                     /* Expression: .7
                                         * '<S8>/Z'
                                         */
  real_T cZ_c_Value;                    /* Expression: 2
                                         * '<S8>/cZ'
                                         */
  real_T Buffer_a_IC;                   /* Computed Parameter: IC
                                         * '<S27>/Buffer'
                                         */
  real_T Window_a_WindowSamples[2048]; /* Computed Parameter: WindowSamples
                                        * '<S28>/Window'
                                        */
  real_T Zero_Pad_a_PadValue;           /* Expression: 0
                                         * '<S29>/Zero Pad'
                                         */
  real_T FFT_a_TwiddleTable[1536];      /* Computed Parameter: TwiddleTable
                                         * '<S29>/FFT'
                                         */
  real_T Digital_Filter_a_ICRTP;        /* Computed Parameter: ICRTP
                                         * '<S28>/Digital Filter'
                                         */
  real_T Digital_Filter_a_RTP1COEFF[2]; /* Expression: a.Coeff1
                                         * '<S28>/Digital Filter'
                                         */
  real_T Check_Signal_Attributes_g_P1; /* Expression: SigAttribCheckMethod
                                        * '<S31>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P2; /* Expression: Complexity
                                        * '<S31>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P3; /* Expression: Frame
                                        * '<S31>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P4; /* Expression: DimsCheckMethod
                                        * '<S31>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P5; /* Expression: Dimensions
                                        * '<S31>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P6; /* Expression: DatatypeCheckMethod
                                        * '<S31>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P7; /* Expression: DatatypeGeneral
                                        * '<S31>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P8; /* Expression: DtypeFloatSpecific
                                        * '<S31>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P9; /* Expression: DtypeFixedSpecific
                                        * '<S31>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P10; /* Expression: DtypeIntSpecific
                                         * '<S31>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_g_P11; /* Expression: SampleMode
                                         * '<S31>/Check Signal Attributes'
                                         */
  real_T Buffer_b_IC;                   /* Computed Parameter: IC
                                         * '<S34>/Buffer'
                                         */
  real_T Window_b_WindowSamples[2048]; /* Computed Parameter: WindowSamples
                                        * '<S35>/Window'
                                        */
  real_T Zero_Pad_b_PadValue;           /* Expression: 0
                                         * '<S36>/Zero Pad'
                                         */
  real_T FFT_b_TwiddleTable[1536];      /* Computed Parameter: TwiddleTable
                                         * '<S36>/FFT'
                                         */
  real_T Digital_Filter_b_ICRTP;        /* Computed Parameter: ICRTP
                                         * '<S35>/Digital Filter'
                                         */
  real_T Digital_Filter_b_RTP1COEFF[2]; /* Expression: a.Coeff1
                                         * '<S35>/Digital Filter'
                                         */
  real_T Check_Signal_Attributes_h_P1; /* Expression: SigAttribCheckMethod
                                        * '<S38>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_h_P2; /* Expression: Complexity
                                        * '<S38>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_h_P3; /* Expression: Frame
                                        * '<S38>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_h_P4; /* Expression: DimsCheckMethod
                                        * '<S38>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_h_P5; /* Expression: Dimensions
                                        * '<S38>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_h_P6; /* Expression: DatatypeCheckMethod
                                        * '<S38>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_h_P7; /* Expression: DatatypeGeneral
                                        * '<S38>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_h_P8; /* Expression: DtypeFloatSpecific
                                        * '<S38>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_h_P9; /* Expression: DtypeFixedSpecific
                                        * '<S38>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_h_P10; /* Expression: DtypeIntSpecific
                                         * '<S38>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_h_P11; /* Expression: SampleMode
                                         * '<S38>/Check Signal Attributes'
                                         */
  boolean_T S_Function_a_P1;            /* Expression: boolean(1)
                                         * '<S9>/S-Function'
                                         */
  boolean_T S_Function_b_P1;            /* Expression: boolean(1)
                                         * '<S4>/S-Function'
                                         */
  boolean_T S_Function_c_P1;            /* Expression: boolean(0)
                                         * '<S3>/S-Function'
                                         */
  boolean_T S_Function_d_P1;            /* Expression: boolean(0)
                                         * '<S5>/S-Function'
                                         */
  char pad_S_Function_d_P1[4];
};

extern FuSimple_Parameters FuSimple_DefaultParameters; /* parameters */

/* External data declarations for dependent source files */

/* non-finites */
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;

#endif                                  /* _RTW_HEADER_FuSimple_acc_h_ */
