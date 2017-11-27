#ifndef _RTW_HEADER_new_pll_fs_acc_h_
#define _RTW_HEADER_new_pll_fs_acc_h_

/* Block signals (auto storage) */
typedef struct {
  real_T Gain;                         /* '<S24>/Gain' */
  real_T Abs;                          /* '<S24>/Abs' */
  real_T IC;                           /* '<S24>/IC' */
  real_T Quantizer;                    /* '<Root>/Quantizer' */
  real_T Gain_f;                       /* '<S34>/Gain' */
  real_T Abs_j;                        /* '<S34>/Abs' */
  real_T IC_b;                         /* '<S34>/IC' */
  real_T InheritShape1;                /* '<S29>/Inherit Shape1' */
  real_T Saturation;                   /* '<S4>/Saturation' */
  real_T Product1;                     /* '<S4>/Product1' */
  real_T Sum;                          /* '<S3>/Sum' */
  real_T Sum_p;                        /* '<S26>/Sum' */
  real_T Product1_b;                   /* '<S7>/Product1' */
  real_T Product3;                     /* '<S7>/Product3' */
  real_T Product5;                     /* '<S7>/Product5' */
  real_T Product4;                     /* '<S7>/Product4' */
  real_T Product7;                     /* '<S7>/Product7' */
  real_T Product1_a;                   /* '<S6>/Product1' */
  real_T Product3_l;                   /* '<S6>/Product3' */
  real_T Product5_g;                   /* '<S6>/Product5' */
  real_T Product4_b;                   /* '<S6>/Product4' */
  real_T Product1_e;                   /* '<S5>/Product1' */
  real_T Product5_p;                   /* '<S5>/Product5' */
  real_T Product4_i;                   /* '<S5>/Product4' */
  real_T MATLABFcn[2];                 /* '<S25>/MATLAB Fcn' */
  boolean_T RelationalOperator;        /* '<S24>/Relational Operator' */
  boolean_T RelationalOperator_h;      /* '<S34>/Relational Operator' */
} BlockIO;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T IC_FirstOutputTime;           /* '<S24>/IC' */
  real_T IC_FirstOutputTime_e;         /* '<S34>/IC' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_b;                     /* '<S7>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     /* '<S6>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_d;                     /* '<S5>/Scope' */

  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S24>/Integrator' */

  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK_k;                /* '<S34>/Integrator' */

  int_T Abs_MODE;                      /* '<S24>/Abs' */
  int_T Abs_MODE_g;                    /* '<S34>/Abs' */
  int_T Saturation_MODE;               /* '<S4>/Saturation' */
  int_T Integrator1_MODE;              /* '<S7>/Integrator1' */
  int_T Integrator1_MODE_m;            /* '<S6>/Integrator1' */
  int_T Integrator1_MODE_d;            /* '<S5>/Integrator1' */
  int_T Integrator_MODE;               /* '<S5>/Integrator' */
  boolean_T RelationalOperator_Mode;   /* '<S24>/Relational Operator' */
  boolean_T RelationalOperator_Mode_l; /* '<S34>/Relational Operator' */
} D_Work;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S24>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S34>/Integrator' */
  real_T StateSpace_CSTATE;            /* '<S1>/State-Space' */
  real_T StateSpace_CSTATE_m[2];       /* '<S2>/State-Space' */
  real_T AnalogFilterDesign_CSTATE[8]; /* '<Root>/Analog Filter Design' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T Integrator_CSTATE_k;          /* '<S7>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S7>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S7>/Integrator2' */
  real_T Integrator_CSTATE_j;          /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE_l;         /* '<S6>/Integrator1' */
  real_T Integrator1_CSTATE_ls;        /* '<S5>/Integrator1' */
  real_T Integrator_CSTATE_jp;         /* '<S5>/Integrator' */
} ContinuousStates;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S24>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S34>/Integrator' */
  real_T StateSpace_CSTATE;            /* '<S1>/State-Space' */
  real_T StateSpace_CSTATE_m[2];       /* '<S2>/State-Space' */
  real_T AnalogFilterDesign_CSTATE[8]; /* '<Root>/Analog Filter Design' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T Integrator_CSTATE_k;          /* '<S7>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S7>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S7>/Integrator2' */
  real_T Integrator_CSTATE_j;          /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE_l;         /* '<S6>/Integrator1' */
  real_T Integrator1_CSTATE_ls;        /* '<S5>/Integrator1' */
  real_T Integrator_CSTATE_jp;         /* '<S5>/Integrator' */
} StateDerivatives;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S24>/Integrator' */
  boolean_T Integrator_CSTATE_e;       /* '<S34>/Integrator' */
  boolean_T StateSpace_CSTATE;         /* '<S1>/State-Space' */
  boolean_T StateSpace_CSTATE_m[2];    /* '<S2>/State-Space' */
  boolean_T AnalogFilterDesign_CSTATE[8];/* '<Root>/Analog Filter Design' */
  boolean_T TransferFcn_CSTATE;        /* '<Root>/Transfer Fcn' */
  boolean_T Integrator_CSTATE_k;       /* '<S7>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S7>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S7>/Integrator2' */
  boolean_T Integrator_CSTATE_j;       /* '<S6>/Integrator' */
  boolean_T Integrator1_CSTATE_l;      /* '<S6>/Integrator1' */
  boolean_T Integrator1_CSTATE_ls;     /* '<S5>/Integrator1' */
  boolean_T Integrator_CSTATE_jp;      /* '<S5>/Integrator' */
} StateDisabled;

/* Zero-crossing (trigger) state */
typedef struct {
  real_T Abs_NSZC;                     /* '<S24>/Abs' */
  real_T RelationalOperator_NSZC;      /* '<S24>/Relational Operator' */
  real_T Abs_NSZC_a;                   /* '<S34>/Abs' */
  real_T RelationalOperator_NSZC_c;    /* '<S34>/Relational Operator' */
  real_T Saturation_NSZC[2];           /* '<S4>/Saturation' */
  real_T Integrator1_NSZC[3];          /* '<S7>/Integrator1' */
  real_T Integrator1_NSZC_e[3];        /* '<S6>/Integrator1' */
  real_T Integrator1_NSZC_k[3];        /* '<S5>/Integrator1' */
  real_T Integrator_NSZC[2];           /* '<S5>/Integrator' */
  real_T FETDSP1_NSZC;                 /* '<S4>/FET DSP1' */
} NonsampledZCs;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_ZCE;           /* '<S24>/Integrator' */
  ZCSigState Integrator_ZCE_k;         /* '<S34>/Integrator' */
  ZCSigState FETDSP1_ZCE;              /* '<S4>/FET DSP1' */
} PrevZCSigStates;

/* Parameters (auto storage) */
struct Parameters {
  real_T Gain_Gain;                    /* Expression: 1+eps
                                        * '<S24>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: modu
                                        * '<S24>/Constant'
                                        */
  real_T IC_Value;                     /* Expression: init
                                        * '<S24>/IC'
                                        */
  real_T Quantizer_Interval;           /* Expression: 2/(2^12)
                                        * '<Root>/Quantizer'
                                        */
  real_T Fdisired_Value;               /* Expression: 1112
                                        * '<Root>/Fdisired'
                                        */
  real_T Fdisired_Value_l;             /* Expression: 0
                                        * '<Root>/Fdisired+'
                                        */
  real_T Fsample1_Value;               /* Expression: 1000
                                        * '<Root>/Fsample1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 1+eps
                                        * '<S34>/Gain'
                                        */
  real_T Constant_Value_c;             /* Expression: modu
                                        * '<S34>/Constant'
                                        */
  real_T IC_Value_n;                   /* Expression: init
                                        * '<S34>/IC'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * '<S4>/Saturation'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.1
                                        * '<Root>/Gain1'
                                        */
  real_T StateSpace_A;                 /* Computed Parameter: A
                                        * '<S1>/State-Space'
                                        */
  real_T StateSpace_C;                 /* Computed Parameter: C
                                        * '<S1>/State-Space'
                                        */
  real_T StateSpace_X0;                /* Expression: x0c
                                        * '<S1>/State-Space'
                                        */
  real_T StateSpace_A_d[2];            /* Computed Parameter: A
                                        * '<S2>/State-Space'
                                        */
  real_T StateSpace_C_p[2];            /* Computed Parameter: C
                                        * '<S2>/State-Space'
                                        */
  real_T StateSpace_X0_n;              /* Expression: x0c
                                        * '<S2>/State-Space'
                                        */
  real_T AnalogFilterDesign_A[15];     /* Computed Parameter: A
                                        * '<Root>/Analog Filter Design'
                                        */
  real_T AnalogFilterDesign_B;         /* Computed Parameter: B
                                        * '<Root>/Analog Filter Design'
                                        */
  real_T AnalogFilterDesign_C;         /* Computed Parameter: C
                                        * '<Root>/Analog Filter Design'
                                        */
  real_T AnalogFilterDesign_X0;        /* Expression: 0
                                        * '<Root>/Analog Filter Design'
                                        */
  real_T Carrierfrequency1_Value;      /* Expression: Fc
                                        * '<S3>/Carrier frequency1'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: A
                                        * '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: C
                                        * '<Root>/Transfer Fcn'
                                        */
  real_T Sensitivity_Gain;             /* Expression: Kc
                                        * '<S3>/Sensitivity'
                                        */
  real_T Carrierfrequency1_Value_j;    /* Expression: Fc
                                        * '<S26>/Carrier frequency1'
                                        */
  real_T Sensitivity_Gain_g;           /* Expression: Kc
                                        * '<S26>/Sensitivity'
                                        */
  real_T Integrator1_IC;               /* Expression: 100
                                        * '<S5>/Integrator1'
                                        */
  real_T Integrator1_UpperSat;         /* Expression: 5000
                                        * '<S5>/Integrator1'
                                        */
  real_T Integrator1_LowerSat;         /* Expression: 10
                                        * '<S5>/Integrator1'
                                        */
  real_T Integrator_IC;                /* Expression: 2500
                                        * '<S5>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: 5000
                                        * '<S5>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: 10
                                        * '<S5>/Integrator'
                                        */
  real_T Kd_Value;                     /* Expression: 0.61
                                        * '<S5>/Kd'
                                        */
  real_T Kv_Value;                     /* Expression: 1
                                        * '<S5>/Kv'
                                        */
  real_T Wn_Value;                     /* Expression: 2*pi*250
                                        * '<S5>/Wn'
                                        */
  real_T Z_Value;                      /* Expression: .7
                                        * '<S5>/Z'
                                        */
  real_T cZ_Value;                     /* Expression: 2
                                        * '<S5>/cZ'
                                        */
  real_T Integrator_IC_e;              /* Expression: 0
                                        * '<S6>/Integrator'
                                        */
  real_T Integrator1_IC_j;             /* Expression: 1000
                                        * '<S6>/Integrator1'
                                        */
  real_T Integrator1_UpperSat_n;       /* Expression: 5000
                                        * '<S6>/Integrator1'
                                        */
  real_T Integrator1_LowerSat_m;       /* Expression: 10
                                        * '<S6>/Integrator1'
                                        */
  real_T Kd_Value_b;                   /* Expression: 1
                                        * '<S6>/Kd'
                                        */
  real_T Kv_Value_d;                   /* Expression: 1
                                        * '<S6>/Kv'
                                        */
  real_T Wn_Value_n;                   /* Expression: 2*pi*250
                                        * '<S6>/Wn'
                                        */
  real_T Z_Value_g;                    /* Expression: .7
                                        * '<S6>/Z'
                                        */
  real_T cZ_Value_d;                   /* Expression: 2
                                        * '<S6>/cZ'
                                        */
  real_T Integrator_IC_k;              /* Expression: 0
                                        * '<S7>/Integrator'
                                        */
  real_T Integrator1_IC_l;             /* Expression: 1000
                                        * '<S7>/Integrator1'
                                        */
  real_T Integrator1_UpperSat_h;       /* Expression: 5000
                                        * '<S7>/Integrator1'
                                        */
  real_T Integrator1_LowerSat_i;       /* Expression: 10
                                        * '<S7>/Integrator1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * '<S7>/Integrator2'
                                        */
  real_T Kd_Value_m;                   /* Expression: 1
                                        * '<S7>/Kd'
                                        */
  real_T Kd1_Value;                    /* Expression: 5
                                        * '<S7>/Kd1'
                                        */
  real_T Kv_Value_c;                   /* Expression: 1
                                        * '<S7>/Kv'
                                        */
  real_T Wn_Value_h;                   /* Expression: 2*pi*250
                                        * '<S7>/Wn'
                                        */
  real_T Z_Value_n;                    /* Expression: .7
                                        * '<S7>/Z'
                                        */
  real_T cZ_Value_i;                   /* Expression: 2
                                        * '<S7>/cZ'
                                        */
  uint8_T Constant_Value_d;            /* Expression: uint8(1)
                                        * '<S8>/Constant'
                                        */
  uint8_T Constant_Value_m;            /* Expression: uint8(1)
                                        * '<S12>/Constant'
                                        */
  uint8_T Constant_Value_cr;           /* Expression: uint8(1)
                                        * '<S9>/Constant'
                                        */
  uint8_T Constant_Value_l;            /* Expression: uint8(1)
                                        * '<S13>/Constant'
                                        */
  uint8_T Constant_Value_lw;           /* Expression: uint8(1)
                                        * '<S14>/Constant'
                                        */
  uint8_T Constant_Value_p;            /* Expression: uint8(1)
                                        * '<S10>/Constant'
                                        */
  uint8_T Constant_Value_g;            /* Expression: uint8(1)
                                        * '<S11>/Constant'
                                        */
  uint8_T SwitchControl_Threshold;     /* Expression: uint8(1)
                                        * '<S13>/SwitchControl'
                                        */
  uint8_T SwitchControl_Threshold_d;   /* Expression: uint8(1)
                                        * '<S10>/SwitchControl'
                                        */
  uint8_T SwitchControl_Threshold_e;   /* Expression: uint8(1)
                                        * '<S11>/SwitchControl'
                                        */
  uint8_T SwitchControl_Threshold_i;   /* Expression: uint8(0)
                                        * '<S14>/SwitchControl'
                                        */
  uint8_T SwitchControl_Threshold_c;   /* Expression: uint8(1)
                                        * '<S9>/SwitchControl'
                                        */
  uint8_T SwitchControl_Threshold_o;   /* Expression: uint8(1)
                                        * '<S8>/SwitchControl'
                                        */
  uint8_T SwitchControl_Threshold_e1;  /* Expression: uint8(0)
                                        * '<S12>/SwitchControl'
                                        */
};

#endif                                 /* _RTW_HEADER_new_pll_fs_acc_h_ */
