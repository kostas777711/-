/*
 * rfsstudy_acc.h
 *
 * Real-Time Workshop code generation for Simulink model "rfsstudy_acc.mdl".
 *
 * Model Version                        : 1.44
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Wed Mar 11 12:07:04 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Wed Mar 11 12:07:05 2009
 */

#ifndef _RTW_HEADER_rfsstudy_acc_h_
# define _RTW_HEADER_rfsstudy_acc_h_

#ifndef _rfsstudy_acc_COMMON_INCLUDES_
# define _rfsstudy_acc_COMMON_INCLUDES_
#include <math.h>
#include <stdlib.h>

#define S_FUNCTION_NAME                 simulink_only_sfcn
#define S_FUNCTION_LEVEL                2
#define RTW_GENERATED_S_FUNCTION

#include "simstruc.h"
#include "rtlibsrc.h"

#endif                                  /* _rfsstudy_acc_COMMON_INCLUDES_ */

#include "rfsstudy_acc_types.h"

/* Intrinsic types */
#ifndef POINTER_T
# define POINTER_T
typedef void * pointer_T;
#endif

/* Block signals (auto storage) */
typedef struct _rfsstudy_BlockIO {
  real_T Fin;                           /* '<Root>/Fin' */
  real_T Gain_a;                        /* '<S22>/Gain' */
  real_T Abs_a;                         /* '<S22>/Abs' */
  real_T Constant_a;                    /* '<S22>/Constant' */
  real_T IC_a;                          /* '<S22>/IC' */
  real_T Quantizer;                     /* '<Root>/Quantizer' */
  real_T Fs;                            /* '<Root>/Fs' */
  real_T Gain_b;                        /* '<S31>/Gain' */
  real_T Abs_b;                         /* '<S31>/Abs' */
  real_T Constant_b;                    /* '<S31>/Constant' */
  real_T IC_b;                          /* '<S31>/IC' */
  real_T Inherit_Shape1_d;              /* '<S25>/Inherit Shape1' */
  real_T Product;                       /* '<Root>/Product' */
  real_T Gain_c;                        /* '<S1>/Gain' */
  real_T Gain1;                         /* '<Root>/Gain1' */
  real_T Carrier_frequency1_a;          /* '<S5>/Carrier frequency1' */
  real_T Sum_a;                         /* '<S5>/Sum' */
  real_T Carrier_frequency1_b;          /* '<S6>/Carrier frequency1' */
  real_T Sum_b;                         /* '<S6>/Sum' */
  real_T Buffer[2048];                  /* '<S8>/Buffer' */
  real_T Window_o2[2048];               /* '<S9>/Window' */
  real_T Magnitude_Squared[2048];       /* '<S10>/Magnitude Squared' */
  real_T Digital_Filter[2048];          /* '<S9>/Digital Filter' */
  real_T Product2[2048];                /* '<S9>/Product2' */
  real_T MATLAB_Fcn[2];                 /* '<S2>/MATLAB Fcn' */
  real_T temp25;                        /* '<Root>/Sum1' */
  boolean_T Relational_Operator_a;      /* '<S22>/Relational Operator' */
  boolean_T Relational_Operator_b;      /* '<S31>/Relational Operator' */
  char pad_Relational_Operator_b[6];
} rfsstudy_BlockIO;

/* Block states (auto storage) for system: '<Root>' */
typedef struct rfsstudy_D_Work_tag {
  real_T Buffer_CircBuff[4096];         /* <S8>/Buffer */
  real_T Digital_Filter_FILT_STATES[4096]; /* <S9>/Digital Filter */
  real_T IC_a_FirstOutputTime;          /* <S22>/IC */
  real_T IC_b_FirstOutputTime;          /* <S31>/IC */
  struct {
    real_T NextOutput;
  } White_Noise_RWORK;                  /* '<S1>/White Noise' */
  pointer_T Buffer_IN_BUF_PTR;          /* <S8>/Buffer */
  pointer_T Buffer_OUT_BUF_PTR;         /* <S8>/Buffer */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                       /* '<Root>/Scope1' */
  int32_T Buffer_ShiftPerElem;          /* <S8>/Buffer */
  int32_T Digital_Filter_DF_INDX;       /* <S9>/Digital Filter */
  struct {
    int_T IcNeedsLoading;
  } Integrator_a_IWORK;                 /* '<S22>/Integrator' */
  struct {
    int_T IcNeedsLoading;
  } Integrator_b_IWORK;                 /* '<S31>/Integrator' */
  struct {
    int_T RandSeed;
  } White_Noise_IWORK;                  /* '<S1>/White Noise' */
  int_T Abs_a_MODE;                     /* <S22>/Abs */
  int_T Relational_Operator_a_MODE;     /* <S22>/Relational Operator */
  int_T Abs_b_MODE;                     /* <S31>/Abs */
  int_T Relational_Operator_b_MODE;     /* <S31>/Relational Operator */
} rfsstudy_D_Work;

/* Continuous states (auto storage) */
typedef struct _rfsstudy_ContinuousStates {
  real_T Integrator_a_CSTATE;           /* '<S22>/Integrator' */
  real_T Integrator_b_CSTATE;           /* '<S31>/Integrator' */
} rfsstudy_ContinuousStates;

/* State derivatives (auto storage) */
typedef struct _rfsstudy_StateDerivatives {
  real_T Integrator_a_CSTATE;           /* '<S22>/Integrator' */
  real_T Integrator_b_CSTATE;           /* '<S31>/Integrator' */
} rfsstudy_StateDerivatives;

/* State disabled  */
typedef struct _rfsstudy_StateDisabled {
  boolean_T Integrator_a_CSTATE;        /* '<S22>/Integrator' */
  boolean_T Integrator_b_CSTATE;        /* '<S31>/Integrator' */
} rfsstudy_StateDisabled;

/* Zero-crossing (trigger) state */
typedef struct _rfsstudy_NonsampledZCs {
  real_T Abs_a_NSZC;                    /* '<S22>/Abs' */
  real_T Relational_Operator_a_NSZC;    /* '<S22>/Relational Operator' */
  real_T Abs_b_NSZC;                    /* '<S31>/Abs' */
  real_T Relational_Operator_b_NSZC;    /* '<S31>/Relational Operator' */
  real_T FET_DSP_NSZC;                  /* '<Root>/FET DSP' */
} rfsstudy_NonsampledZCs;

/* Zero-crossing (trigger) state */
typedef struct _rfsstudy_PrevZCSigStates {
  ZCSigState Integrator_a_ZCE;          /* '<S22>/Integrator' */
  ZCSigState Integrator_b_ZCE;          /* '<S31>/Integrator' */
  ZCSigState FET_DSP_ZCE;               /* '<Root>/FET DSP' */
} rfsstudy_PrevZCSigStates;

/* Parameters (auto storage) */
struct _rfsstudy_Parameters {
  real_T Fin_Value;                     /* Expression: 2201
                                         * '<Root>/Fin'
                                         */
  real_T Gain_a_Gain;                   /* Expression: 1+eps
                                         * '<S22>/Gain'
                                         */
  real_T Constant_a_Value;              /* Expression: modu
                                         * '<S22>/Constant'
                                         */
  real_T IC_a_Value;                    /* Expression: init
                                         * '<S22>/IC'
                                         */
  real_T Sine_Wave1_Amp;                /* Expression: 0.00
                                         * '<Root>/Sine Wave1'
                                         */
  real_T Sine_Wave1_Bias;               /* Expression: 0
                                         * '<Root>/Sine Wave1'
                                         */
  real_T Sine_Wave1_Freq;               /* Expression: 2*pi*500
                                         * '<Root>/Sine Wave1'
                                         */
  real_T Sine_Wave1_Phase;              /* Expression: 0
                                         * '<Root>/Sine Wave1'
                                         */
  real_T Quantizer_Interval;            /* Expression: 2/(2^12)
                                         * '<Root>/Quantizer'
                                         */
  real_T Fs_Value;                      /* Expression: 10000
                                         * '<Root>/Fs'
                                         */
  real_T Gain_b_Gain;                   /* Expression: 1+eps
                                         * '<S31>/Gain'
                                         */
  real_T Constant_b_Value;              /* Expression: modu
                                         * '<S31>/Constant'
                                         */
  real_T IC_b_Value;                    /* Expression: init
                                         * '<S31>/IC'
                                         */
  real_T Sine_Wave_Amp;                 /* Expression: 0.0
                                         * '<Root>/Sine Wave'
                                         */
  real_T Sine_Wave_Bias;                /* Expression: 0
                                         * '<Root>/Sine Wave'
                                         */
  real_T Sine_Wave_Freq;                /* Expression: 2*pi*500
                                         * '<Root>/Sine Wave'
                                         */
  real_T Sine_Wave_Phase;               /* Expression: 0
                                         * '<Root>/Sine Wave'
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
  real_T Gain1_Gain;                    /* Expression: 0.1
                                         * '<Root>/Gain1'
                                         */
  real_T Carrier_frequency1_a_Value;    /* Expression: Fc
                                         * '<S5>/Carrier frequency1'
                                         */
  real_T Check_Signal_Attributes_a_P1; /* Expression: SigAttribCheckMethod
                                        * '<S14>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P2; /* Expression: Complexity
                                        * '<S14>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P3; /* Expression: Frame
                                        * '<S14>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P4; /* Expression: DimsCheckMethod
                                        * '<S14>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P5; /* Expression: Dimensions
                                        * '<S14>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P6; /* Expression: DatatypeCheckMethod
                                        * '<S14>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P7; /* Expression: DatatypeGeneral
                                        * '<S14>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P8; /* Expression: DtypeFloatSpecific
                                        * '<S14>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P9; /* Expression: DtypeFixedSpecific
                                        * '<S14>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_a_P10; /* Expression: DtypeIntSpecific
                                         * '<S14>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_a_P11; /* Expression: SampleMode
                                         * '<S14>/Check Signal Attributes'
                                         */
  real_T Reshape_a_P1;                  /* Expression: OutputDimensionality
                                         * '<S15>/Reshape'
                                         */
  real_T Reshape_a_P2[2];               /* Expression: OutputDimensions
                                         * '<S15>/Reshape'
                                         */
  real_T Sensitivity_a_Gain;            /* Expression: Kc
                                         * '<S5>/Sensitivity'
                                         */
  real_T Check_Signal_Attributes_b_P1; /* Expression: SigAttribCheckMethod
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P2; /* Expression: Complexity
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P3; /* Expression: Frame
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P4; /* Expression: DimsCheckMethod
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P5; /* Expression: Dimensions
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P6; /* Expression: DatatypeCheckMethod
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P7; /* Expression: DatatypeGeneral
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P8; /* Expression: DtypeFloatSpecific
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P9; /* Expression: DtypeFixedSpecific
                                        * '<S19>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_b_P10; /* Expression: DtypeIntSpecific
                                         * '<S19>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_b_P11; /* Expression: SampleMode
                                         * '<S19>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_c_P1; /* Expression: SigAttribCheckMethod
                                        * '<S20>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P2; /* Expression: Complexity
                                        * '<S20>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P3; /* Expression: Frame
                                        * '<S20>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P4; /* Expression: DimsCheckMethod
                                        * '<S20>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P5; /* Expression: Dimensions
                                        * '<S20>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P6; /* Expression: DatatypeCheckMethod
                                        * '<S20>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P7; /* Expression: DatatypeGeneral
                                        * '<S20>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P8; /* Expression: DtypeFloatSpecific
                                        * '<S20>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P9; /* Expression: DtypeFixedSpecific
                                        * '<S20>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_c_P10; /* Expression: DtypeIntSpecific
                                         * '<S20>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_c_P11; /* Expression: SampleMode
                                         * '<S20>/Check Signal Attributes'
                                         */
  real_T Carrier_frequency1_b_Value;    /* Expression: Fc
                                         * '<S6>/Carrier frequency1'
                                         */
  real_T Check_Signal_Attributes_d_P1; /* Expression: SigAttribCheckMethod
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P2; /* Expression: Complexity
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P3; /* Expression: Frame
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P4; /* Expression: DimsCheckMethod
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P5; /* Expression: Dimensions
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P6; /* Expression: DatatypeCheckMethod
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P7; /* Expression: DatatypeGeneral
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P8; /* Expression: DtypeFloatSpecific
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P9; /* Expression: DtypeFixedSpecific
                                        * '<S23>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_d_P10; /* Expression: DtypeIntSpecific
                                         * '<S23>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_d_P11; /* Expression: SampleMode
                                         * '<S23>/Check Signal Attributes'
                                         */
  real_T Reshape_b_P1;                  /* Expression: OutputDimensionality
                                         * '<S24>/Reshape'
                                         */
  real_T Reshape_b_P2[2];               /* Expression: OutputDimensions
                                         * '<S24>/Reshape'
                                         */
  real_T Sensitivity_b_Gain;            /* Expression: Kc
                                         * '<S6>/Sensitivity'
                                         */
  real_T Check_Signal_Attributes_e_P1; /* Expression: SigAttribCheckMethod
                                        * '<S28>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P2; /* Expression: Complexity
                                        * '<S28>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P3; /* Expression: Frame
                                        * '<S28>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P4; /* Expression: DimsCheckMethod
                                        * '<S28>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P5; /* Expression: Dimensions
                                        * '<S28>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P6; /* Expression: DatatypeCheckMethod
                                        * '<S28>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P7; /* Expression: DatatypeGeneral
                                        * '<S28>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P8; /* Expression: DtypeFloatSpecific
                                        * '<S28>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P9; /* Expression: DtypeFixedSpecific
                                        * '<S28>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_e_P10; /* Expression: DtypeIntSpecific
                                         * '<S28>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_e_P11; /* Expression: SampleMode
                                         * '<S28>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_f_P1; /* Expression: SigAttribCheckMethod
                                        * '<S29>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P2; /* Expression: Complexity
                                        * '<S29>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P3; /* Expression: Frame
                                        * '<S29>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P4; /* Expression: DimsCheckMethod
                                        * '<S29>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P5; /* Expression: Dimensions
                                        * '<S29>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P6; /* Expression: DatatypeCheckMethod
                                        * '<S29>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P7; /* Expression: DatatypeGeneral
                                        * '<S29>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P8; /* Expression: DtypeFloatSpecific
                                        * '<S29>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P9; /* Expression: DtypeFixedSpecific
                                        * '<S29>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_f_P10; /* Expression: DtypeIntSpecific
                                         * '<S29>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_f_P11; /* Expression: SampleMode
                                         * '<S29>/Check Signal Attributes'
                                         */
  real_T Buffer_IC;                     /* Computed Parameter: IC
                                         * '<S8>/Buffer'
                                         */
  real_T Window_WindowSamples[2048];    /* Computed Parameter: WindowSamples
                                         * '<S9>/Window'
                                         */
  real_T Zero_Pad_PadValue;             /* Expression: 0
                                         * '<S10>/Zero Pad'
                                         */
  real_T FFT_TwiddleTable[1536];        /* Computed Parameter: TwiddleTable
                                         * '<S10>/FFT'
                                         */
  real_T Digital_Filter_ICRTP;          /* Computed Parameter: ICRTP
                                         * '<S9>/Digital Filter'
                                         */
  real_T Digital_Filter_RTP1COEFF[2];   /* Expression: a.Coeff1
                                         * '<S9>/Digital Filter'
                                         */
  real_T Check_Signal_Attributes_g_P1; /* Expression: SigAttribCheckMethod
                                        * '<S12>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P2; /* Expression: Complexity
                                        * '<S12>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P3; /* Expression: Frame
                                        * '<S12>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P4; /* Expression: DimsCheckMethod
                                        * '<S12>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P5; /* Expression: Dimensions
                                        * '<S12>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P6; /* Expression: DatatypeCheckMethod
                                        * '<S12>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P7; /* Expression: DatatypeGeneral
                                        * '<S12>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P8; /* Expression: DtypeFloatSpecific
                                        * '<S12>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P9; /* Expression: DtypeFixedSpecific
                                        * '<S12>/Check Signal Attributes'
                                        */
  real_T Check_Signal_Attributes_g_P10; /* Expression: DtypeIntSpecific
                                         * '<S12>/Check Signal Attributes'
                                         */
  real_T Check_Signal_Attributes_g_P11; /* Expression: SampleMode
                                         * '<S12>/Check Signal Attributes'
                                         */
};

extern rfsstudy_Parameters rfsstudy_DefaultParameters; /* parameters */

/* External data declarations for dependent source files */

/* non-finites */
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;

#endif                                  /* _RTW_HEADER_rfsstudy_acc_h_ */
