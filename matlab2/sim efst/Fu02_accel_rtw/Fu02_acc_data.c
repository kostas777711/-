/*
 * Fu02_acc_data.c
 *
 * Real-Time Workshop code generation for Simulink model "Fu02_acc.mdl".
 *
 * Model Version                        : 1.8
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Tue Feb 12 16:10:37 2008
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Tue Feb 12 16:10:37 2008
 */

#include "Fu02_acc.h"
#include "Fu02_acc_private.h"

/* Block parameters (auto storage) */
Fu02_Parameters Fu02_DefaultParameters = {
  1.0000000000000002E+000 ,             /* Gain_Gain : '<S21>/Gain' */
  1.0 ,                                 /* Constant_a_Value : '<S21>/Constant' */
  0.0 ,                                 /* IC_Value : '<S21>/IC' */
  1.0 ,                                 /* Sampling_Amp : '<Root>/Sampling' */
  0.0 ,                                 /* Sampling_Bias : '<Root>/Sampling' */
  6.2831853071795858E+003 ,             /* Sampling_Freq : '<Root>/Sampling' */
  0.0 ,                                 /* Sampling_Phase : '<Root>/Sampling' */
  0.0 ,                                 /* Constant1_Value : '<Root>/Constant1' */
  123.4567 ,                            /* Constant_b_Value : '<Root>/Constant' */
  0.0 ,                                 /* Integrator_b_IC : '<Root>/Integrator' */
  10.0 ,                                /* Carrier_frequency1_Value : '<S3>/Carrier frequency1' */
  1.0 ,                                 /* Check_Signal_Attributes_a_P1 : '<S13>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_a_P2 : '<S13>/Check Signal Attributes' */
  3.0 ,                                 /* Check_Signal_Attributes_a_P3 : '<S13>/Check Signal Attributes' */
  2.0 ,                                 /* Check_Signal_Attributes_a_P4 : '<S13>/Check Signal Attributes' */
  3.0 ,                                 /* Check_Signal_Attributes_a_P5 : '<S13>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_a_P6 : '<S13>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_a_P7 : '<S13>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_a_P8 : '<S13>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_a_P9 : '<S13>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_a_P10 : '<S13>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_a_P11 : '<S13>/Check Signal Attributes' */
  1.0 ,                                 /* Reshape_P1 : '<S14>/Reshape' */
  /*  Reshape_P2 : '<S14>/Reshape' */
  { 1.0, 1.0 } ,
  100.0 ,                               /* Sensitivity_Gain : '<S3>/Sensitivity' */
  2.0 ,                                 /* Check_Signal_Attributes_b_P1 : '<S18>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_b_P2 : '<S18>/Check Signal Attributes' */
  2.0 ,                                 /* Check_Signal_Attributes_b_P3 : '<S18>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_b_P4 : '<S18>/Check Signal Attributes' */
  3.0 ,                                 /* Check_Signal_Attributes_b_P5 : '<S18>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_b_P6 : '<S18>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_b_P7 : '<S18>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_b_P8 : '<S18>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_b_P9 : '<S18>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_b_P10 : '<S18>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_b_P11 : '<S18>/Check Signal Attributes' */
  2.0 ,                                 /* Check_Signal_Attributes_c_P1 : '<S19>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_c_P2 : '<S19>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_c_P3 : '<S19>/Check Signal Attributes' */
  2.0 ,                                 /* Check_Signal_Attributes_c_P4 : '<S19>/Check Signal Attributes' */
  10.0 ,                                /* Check_Signal_Attributes_c_P5 : '<S19>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_c_P6 : '<S19>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_c_P7 : '<S19>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_c_P8 : '<S19>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_c_P9 : '<S19>/Check Signal Attributes' */
  1.0 ,                                 /* Check_Signal_Attributes_c_P10 : '<S19>/Check Signal Attributes' */
  1.0                                   /* Check_Signal_Attributes_c_P11 : '<S19>/Check Signal Attributes' */
};

