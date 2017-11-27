/*
 * new_pll_fs_acc_data.c
 *
 * Real-Time Workshop code generation for Simulink model "new_pll_fs_acc.mdl".
 *
 * Model Version              : 1.45
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Thu Apr 22 21:25:01 2010
 */

#include "new_pll_fs_acc.h"
#include "new_pll_fs_acc_private.h"

/* Block parameters (auto storage) */
Parameters rtDefaultParameters = {
  1.0000000000000002E+000,             /* Gain_Gain : '<S24>/Gain'
                                        */
  1.0,                                 /* Constant_Value : '<S24>/Constant'
                                        */
  0.0,                                 /* IC_Value : '<S24>/IC'
                                        */
  0.00048828125,                       /* Quantizer_Interval : '<Root>/Quantizer'
                                        */
  1112.0,                              /* Fdisired_Value : '<Root>/Fdisired'
                                        */
  0.0,                                 /* Fdisired_Value_l : '<Root>/Fdisired+'
                                        */
  1000.0,                              /* Fsample1_Value : '<Root>/Fsample1'
                                        */
  1.0000000000000002E+000,             /* Gain_Gain_b : '<S34>/Gain'
                                        */
  1.0,                                 /* Constant_Value_c : '<S34>/Constant'
                                        */
  0.0,                                 /* IC_Value_n : '<S34>/IC'
                                        */
  1.0,                                 /* Saturation_UpperSat : '<S4>/Saturation'
                                        */
  -1.0,                                /* Saturation_LowerSat : '<S4>/Saturation'
                                        */
  0.1,                                 /* Gain1_Gain : '<Root>/Gain1'
                                        */
  -8.3333333333333329E+001,            /* StateSpace_A : '<S1>/State-Space'
                                        */
  8.3333333333333329E+001,             /* StateSpace_C : '<S1>/State-Space'
                                        */
  0.0,                                 /* StateSpace_X0 : '<S1>/State-Space'
                                        */

  /*  StateSpace_A_d : '<S2>/State-Space'
   */
  { -4.4422120121759672E+003, -9.8696044010893572E+006 },

  /*  StateSpace_C_p : '<S2>/State-Space'
   */
  { 0.0, 9.8696044010893572E+006 },
  0.0,                                 /* StateSpace_X0_n : '<S2>/State-Space'
                                        */

  /*  AnalogFilterDesign_A : '<Root>/Analog Filter Design'
   */
  { -5.8847116824193826E+001, -3.0000000000000007E+001, 30.0, 30.0,
    -4.9888176738152723E+001, -30.0, 30.0, 30.0, -3.3334213981176120E+001, -30.0,
    2.9999999999999993E+001, 3.0000000000000007E+001, -1.1705419320967692E+001,
    -3.0000000000000007E+001, 2.9999999999999993E+001 },
  30.0,                                /* AnalogFilterDesign_B : '<Root>/Analog Filter Design'
                                        */
  1.0000000000000004E+000,             /* AnalogFilterDesign_C : '<Root>/Analog Filter Design'
                                        */
  0.0,                                 /* AnalogFilterDesign_X0 : '<Root>/Analog Filter Design'
                                        */
  0.0,                                 /* Carrierfrequency1_Value : '<S3>/Carrier frequency1'
                                        */
  -10000.0,                            /* TransferFcn_A : '<Root>/Transfer Fcn'
                                        */
  10000.0,                             /* TransferFcn_C : '<Root>/Transfer Fcn'
                                        */
  1.0,                                 /* Sensitivity_Gain : '<S3>/Sensitivity'
                                        */
  0.0,                                 /* Carrierfrequency1_Value_j : '<S26>/Carrier frequency1'
                                        */
  1.0,                                 /* Sensitivity_Gain_g : '<S26>/Sensitivity'
                                        */
  100.0,                               /* Integrator1_IC : '<S5>/Integrator1'
                                        */
  5000.0,                              /* Integrator1_UpperSat : '<S5>/Integrator1'
                                        */
  10.0,                                /* Integrator1_LowerSat : '<S5>/Integrator1'
                                        */
  2500.0,                              /* Integrator_IC : '<S5>/Integrator'
                                        */
  5000.0,                              /* Integrator_UpperSat : '<S5>/Integrator'
                                        */
  10.0,                                /* Integrator_LowerSat : '<S5>/Integrator'
                                        */
  0.61,                                /* Kd_Value : '<S5>/Kd'
                                        */
  1.0,                                 /* Kv_Value : '<S5>/Kv'
                                        */
  1.5707963267948965E+003,             /* Wn_Value : '<S5>/Wn'
                                        */
  0.7,                                 /* Z_Value : '<S5>/Z'
                                        */
  2.0,                                 /* cZ_Value : '<S5>/cZ'
                                        */
  0.0,                                 /* Integrator_IC_e : '<S6>/Integrator'
                                        */
  1000.0,                              /* Integrator1_IC_j : '<S6>/Integrator1'
                                        */
  5000.0,                              /* Integrator1_UpperSat_n : '<S6>/Integrator1'
                                        */
  10.0,                                /* Integrator1_LowerSat_m : '<S6>/Integrator1'
                                        */
  1.0,                                 /* Kd_Value_b : '<S6>/Kd'
                                        */
  1.0,                                 /* Kv_Value_d : '<S6>/Kv'
                                        */
  1.5707963267948965E+003,             /* Wn_Value_n : '<S6>/Wn'
                                        */
  0.7,                                 /* Z_Value_g : '<S6>/Z'
                                        */
  2.0,                                 /* cZ_Value_d : '<S6>/cZ'
                                        */
  0.0,                                 /* Integrator_IC_k : '<S7>/Integrator'
                                        */
  1000.0,                              /* Integrator1_IC_l : '<S7>/Integrator1'
                                        */
  5000.0,                              /* Integrator1_UpperSat_h : '<S7>/Integrator1'
                                        */
  10.0,                                /* Integrator1_LowerSat_i : '<S7>/Integrator1'
                                        */
  0.0,                                 /* Integrator2_IC : '<S7>/Integrator2'
                                        */
  1.0,                                 /* Kd_Value_m : '<S7>/Kd'
                                        */
  5.0,                                 /* Kd1_Value : '<S7>/Kd1'
                                        */
  1.0,                                 /* Kv_Value_c : '<S7>/Kv'
                                        */
  1.5707963267948965E+003,             /* Wn_Value_h : '<S7>/Wn'
                                        */
  0.7,                                 /* Z_Value_n : '<S7>/Z'
                                        */
  2.0,                                 /* cZ_Value_i : '<S7>/cZ'
                                        */
  1U,                                  /* Constant_Value_d : '<S8>/Constant'
                                        */
  1U,                                  /* Constant_Value_m : '<S12>/Constant'
                                        */
  1U,                                  /* Constant_Value_cr : '<S9>/Constant'
                                        */
  1U,                                  /* Constant_Value_l : '<S13>/Constant'
                                        */
  1U,                                  /* Constant_Value_lw : '<S14>/Constant'
                                        */
  1U,                                  /* Constant_Value_p : '<S10>/Constant'
                                        */
  1U,                                  /* Constant_Value_g : '<S11>/Constant'
                                        */
  1U,                                  /* SwitchControl_Threshold : '<S13>/SwitchControl'
                                        */
  1U,                                  /* SwitchControl_Threshold_d : '<S10>/SwitchControl'
                                        */
  1U,                                  /* SwitchControl_Threshold_e : '<S11>/SwitchControl'
                                        */
  0U,                                  /* SwitchControl_Threshold_i : '<S14>/SwitchControl'
                                        */
  1U,                                  /* SwitchControl_Threshold_c : '<S9>/SwitchControl'
                                        */
  1U,                                  /* SwitchControl_Threshold_o : '<S8>/SwitchControl'
                                        */
  0U                                   /* SwitchControl_Threshold_e1 : '<S12>/SwitchControl'
                                        */
};
