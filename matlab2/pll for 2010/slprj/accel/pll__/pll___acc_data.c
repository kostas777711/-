/*
 * pll___acc_data.c
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

#include "pll___acc.h"
#include "pll___acc_private.h"

/* Block parameters (auto storage) */
Parameters rtDefaultParameters = {
  1.0000000000000002E+000,             /* Expression: 1+eps
                                        * Referenced by: '<S9>/Gain'
                                        */
  1.0,                                 /* Expression: modu
                                        * Referenced by: '<S9>/Constant'
                                        */
  0.0,                                 /* Expression: init
                                        * Referenced by: '<S9>/IC'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  1.0000000000000002E+000,             /* Expression: 1+eps
                                        * Referenced by: '<S15>/Gain'
                                        */
  1.0,                                 /* Expression: modu
                                        * Referenced by: '<S15>/Constant'
                                        */
  0.0,                                 /* Expression: init
                                        * Referenced by: '<S15>/IC'
                                        */
  0.0078125,                           /* Expression: 2/(2^8)
                                        * Referenced by: '<Root>/Quantizer'
                                        */
  3245.0,                              /* Expression: 3245
                                        * Referenced by: '<Root>/Fdisired'
                                        */
  10000.0,                             /* Expression: 10000
                                        * Referenced by: '<Root>/Fsample'
                                        */
  200.0,                               /* Expression: 200
                                        * Referenced by: '<Root>/Gain'
                                        */
  -1000.0,                             /* Computed Parameter: P_12
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  1.0,                                 /* Computed Parameter: P_13
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  1000.0,                              /* Computed Parameter: P_14
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  0.0,                                 /* Expression: Fc
                                        * Referenced by: '<S1>/Carrier frequency1'
                                        */
  1.0,                                 /* Expression: Kc
                                        * Referenced by: '<S1>/Sensitivity'
                                        */
  0.0,                                 /* Expression: Fc
                                        * Referenced by: '<S2>/Carrier frequency1'
                                        */
  1.0                                  /* Expression: Kc
                                        * Referenced by: '<S2>/Sensitivity'
                                        */
};
