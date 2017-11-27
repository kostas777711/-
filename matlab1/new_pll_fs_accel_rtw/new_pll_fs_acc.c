/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) Accelerator product.
 */

/*
 * new_pll_fs_acc.c
 *
 * Real-Time Workshop code generation for Simulink model "new_pll_fs_acc.mdl".
 *
 * Model Version              : 1.45
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Thu Apr 22 21:25:01 2010
 */
#include <math.h>
#include "new_pll_fs_acc.h"
#include "new_pll_fs_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat                     S-Function
#define AccDefine1                     Accelerator_S-Function

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *rtS, int_T tid)
{
  /* local block i/o variables */
  real_T rtb_StateSpace;
  real_T rtb_StateSpace_o;
  real_T rtb_AnalogFilterDesign;
  real_T rtb_TransferFcn;
  real_T rtb_SwitchControl;
  real_T rtb_SwitchControl_a;
  real_T rtb_Integrator;
  real_T rtb_Integrator1;
  real_T rtb_Integrator2;
  real_T rtb_Integrator_d;
  real_T rtb_Integrator1_o;
  real_T rtb_Integrator1_o2;
  real_T rtb_Integrator_o;
  real_T rtb_sin;
  real_T rtb_Gain1;
  real_T rtb_Sum1;
  real_T rtb_Product2_e;
  real_T rtb_Product3;

  /* Gain: '<S24>/Gain' */
  ((BlockIO *) _ssGetBlockIO(rtS))->Gain = ((Parameters *) ssGetDefaultParam(rtS))
    ->Gain_Gain * ((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE;

  /* Abs: '<S24>/Abs' */
  if (ssIsMajorTimeStep(rtS)) {
    ((D_Work *) ssGetRootDWork(rtS))->Abs_MODE = ((BlockIO *) _ssGetBlockIO(rtS))
      ->Gain >= 0.0 ? 1 : 0;
  }

  ((BlockIO *) _ssGetBlockIO(rtS))->Abs = ((D_Work *) ssGetRootDWork(rtS))
    ->Abs_MODE > 0 ? ((BlockIO *) _ssGetBlockIO(rtS))->Gain : -((BlockIO *)
    _ssGetBlockIO(rtS))->Gain;
  if (ssIsSampleHit(rtS, 1, 0)) {      /* Sample time: [0.0s, 1.0s] */
    /* RelationalOperator: '<S24>/Relational Operator' incorporates:
     *  Constant: '<S24>/Constant'
     */
    if (ssIsMajorTimeStep(rtS)) {
      ((D_Work *) ssGetRootDWork(rtS))->RelationalOperator_Mode = (((BlockIO *)
        _ssGetBlockIO(rtS))->Abs >= ((Parameters *) ssGetDefaultParam(rtS))
        ->Constant_Value);
    }

    ((BlockIO *) _ssGetBlockIO(rtS))->RelationalOperator = ((D_Work *)
      ssGetRootDWork(rtS))->RelationalOperator_Mode;
  }

  /* Math: '<S24>/Math Function' incorporates:
   *  Constant: '<S24>/Constant'
   */

  /* Operator : rem */
  {
    real_T u2Fix;
    real_T uDiv;
    real_T uDivFix;

    {
      real_T t;
      t = floor(fabs(((Parameters *) ssGetDefaultParam(rtS))->Constant_Value));
      u2Fix = ((((Parameters *) ssGetDefaultParam(rtS))->Constant_Value < 0.0) ?
               -t : t);
    }

    if (((Parameters *) ssGetDefaultParam(rtS))->Constant_Value == 0.0) {
      rtb_Gain1 = rtNaN;
    } else if (((Parameters *) ssGetDefaultParam(rtS))->Constant_Value == u2Fix )
    {
      /* Integer denominator.  Use conventional formula.*/
      uDiv = ((BlockIO *) _ssGetBlockIO(rtS))->Gain / ((Parameters *)
        ssGetDefaultParam(rtS))->Constant_Value;

      {
        real_T t;
        t = floor(fabs(uDiv));
        uDivFix = ((uDiv < 0.0) ? -t : t);
      }

      rtb_Gain1 = (((BlockIO *) _ssGetBlockIO(rtS))->Gain - uDivFix *
                   ((Parameters *) ssGetDefaultParam(rtS))->Constant_Value);
    } else {
      /* Noninteger denominator. Check for nearly integer quotient.*/
      real_T uDivRound;
      uDiv = ((BlockIO *) _ssGetBlockIO(rtS))->Gain / ((Parameters *)
        ssGetDefaultParam(rtS))->Constant_Value;

      {
        real_T t;
        t = floor((fabs(uDiv) + 0.5));
        uDivRound = ((uDiv < 0.0) ? -t : t);
      }

      if (fabs((uDiv - uDivRound)) <= DBL_EPSILON * fabs(uDiv)) {
        rtb_Gain1 = 0.0;
      } else {
        {
          real_T t;
          t = floor(fabs(uDiv));
          uDivFix = ((uDiv < 0.0) ? -t : t);
        }

        rtb_Gain1 = (uDiv - uDivFix) * ((Parameters *) ssGetDefaultParam(rtS))
          ->Constant_Value;
      }
    }
  }

  /* InitialCondition: '<S24>/IC' */
  if ((((D_Work *) ssGetRootDWork(rtS))->IC_FirstOutputTime == rtMinusInf) ||
      (((D_Work *) ssGetRootDWork(rtS))->IC_FirstOutputTime == ssGetTaskTime(rtS,
        0))) {
    ((D_Work *) ssGetRootDWork(rtS))->IC_FirstOutputTime = ssGetTaskTime(rtS,0);
    ((BlockIO *) _ssGetBlockIO(rtS))->IC = ((Parameters *) ssGetDefaultParam(rtS))
      ->IC_Value;
  } else {
    ((BlockIO *) _ssGetBlockIO(rtS))->IC = rtb_Gain1;
  }

  /* Integrator: '<S24>/Integrator' */
  if (ssIsMajorTimeStep(rtS)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = ((ZCEventType) (((BlockIO *) _ssGetBlockIO(rtS))
                ->RelationalOperator && !((PrevZCSigStates *)
      _ssGetPrevZCSigState(rtS))->Integrator_ZCE));

    /* evaluate zero-crossings */
    ((PrevZCSigStates *) _ssGetPrevZCSigState(rtS))->Integrator_ZCE =
      (ZCSigState) ((BlockIO *) _ssGetBlockIO(rtS))->RelationalOperator;
    if (zcEvent || ((D_Work *) ssGetRootDWork(rtS))
        ->Integrator_IWORK.IcNeedsLoading) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE = ((BlockIO
        *) _ssGetBlockIO(rtS))->IC;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(rtS);
      ssSetBlkStateChange(rtS);
    }

    ((D_Work *) ssGetRootDWork(rtS))->Integrator_IWORK.IcNeedsLoading = 0;
  }

  rtb_Gain1 = ((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE;

  /* Communications Blockset Inherit Shape (scominhshape) - '<S23>/Inherit Shape1' */

  /* Fcn: '<S3>/sin' */
  rtb_Gain1 = cos(rtb_Gain1 * 6.2831853071795862);

  /* Communications Blockset Inherit Shape (scominhshape) - '<S19>/Inherit Shape1' */

  /* Scope: '<Root>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(rtS, 10, 10, SS_CALL_MDL_OUTPUTS);

  /* Quantizer: '<Root>/Quantizer' */
  {
    real_T yre;
    yre = ((Parameters *) ssGetDefaultParam(rtS))->Quantizer_Interval * floor
      (fabs((rtb_Gain1/(((Parameters *) ssGetDefaultParam(rtS))
                        ->Quantizer_Interval))) + 0.5);
    ((BlockIO *) _ssGetBlockIO(rtS))->Quantizer = ((rtb_Gain1 >= 0.0) ? yre :
      -yre);
  }

  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Fdisired'
     *  Constant: '<Root>/Fdisired+'
     */
    rtb_Sum1 = ((Parameters *) ssGetDefaultParam(rtS))->Fdisired_Value +
      ((Parameters *) ssGetDefaultParam(rtS))->Fdisired_Value_l;
  }

  /* Gain: '<S34>/Gain' */
  ((BlockIO *) _ssGetBlockIO(rtS))->Gain_f = ((Parameters *) ssGetDefaultParam
    (rtS))->Gain_Gain_b * ((ContinuousStates *) ssGetContStates(rtS))
    ->Integrator_CSTATE_e;

  /* Abs: '<S34>/Abs' */
  if (ssIsMajorTimeStep(rtS)) {
    ((D_Work *) ssGetRootDWork(rtS))->Abs_MODE_g = ((BlockIO *) _ssGetBlockIO
      (rtS))->Gain_f >= 0.0 ? 1 : 0;
  }

  ((BlockIO *) _ssGetBlockIO(rtS))->Abs_j = ((D_Work *) ssGetRootDWork(rtS))
    ->Abs_MODE_g > 0 ? ((BlockIO *) _ssGetBlockIO(rtS))->Gain_f : -((BlockIO *)
    _ssGetBlockIO(rtS))->Gain_f;
  if (ssIsSampleHit(rtS, 1, 0)) {      /* Sample time: [0.0s, 1.0s] */
    /* RelationalOperator: '<S34>/Relational Operator' incorporates:
     *  Constant: '<S34>/Constant'
     */
    if (ssIsMajorTimeStep(rtS)) {
      ((D_Work *) ssGetRootDWork(rtS))->RelationalOperator_Mode_l = (((BlockIO *)
        _ssGetBlockIO(rtS))->Abs_j >= ((Parameters *) ssGetDefaultParam(rtS))
        ->Constant_Value_c);
    }

    ((BlockIO *) _ssGetBlockIO(rtS))->RelationalOperator_h = ((D_Work *)
      ssGetRootDWork(rtS))->RelationalOperator_Mode_l;
  }

  /* Math: '<S34>/Math Function' incorporates:
   *  Constant: '<S34>/Constant'
   */

  /* Operator : rem */
  {
    real_T u2Fix;
    real_T uDiv;
    real_T uDivFix;

    {
      real_T t;
      t = floor(fabs(((Parameters *) ssGetDefaultParam(rtS))->Constant_Value_c));
      u2Fix = ((((Parameters *) ssGetDefaultParam(rtS))->Constant_Value_c < 0.0)
               ? -t : t);
    }

    if (((Parameters *) ssGetDefaultParam(rtS))->Constant_Value_c == 0.0) {
      rtb_sin = rtNaN;
    } else if (((Parameters *) ssGetDefaultParam(rtS))->Constant_Value_c ==
               u2Fix ) {
      /* Integer denominator.  Use conventional formula.*/
      uDiv = ((BlockIO *) _ssGetBlockIO(rtS))->Gain_f / ((Parameters *)
        ssGetDefaultParam(rtS))->Constant_Value_c;

      {
        real_T t;
        t = floor(fabs(uDiv));
        uDivFix = ((uDiv < 0.0) ? -t : t);
      }

      rtb_sin = (((BlockIO *) _ssGetBlockIO(rtS))->Gain_f - uDivFix *
                 ((Parameters *) ssGetDefaultParam(rtS))->Constant_Value_c);
    } else {
      /* Noninteger denominator. Check for nearly integer quotient.*/
      real_T uDivRound;
      uDiv = ((BlockIO *) _ssGetBlockIO(rtS))->Gain_f / ((Parameters *)
        ssGetDefaultParam(rtS))->Constant_Value_c;

      {
        real_T t;
        t = floor((fabs(uDiv) + 0.5));
        uDivRound = ((uDiv < 0.0) ? -t : t);
      }

      if (fabs((uDiv - uDivRound)) <= DBL_EPSILON * fabs(uDiv)) {
        rtb_sin = 0.0;
      } else {
        {
          real_T t;
          t = floor(fabs(uDiv));
          uDivFix = ((uDiv < 0.0) ? -t : t);
        }

        rtb_sin = (uDiv - uDivFix) * ((Parameters *) ssGetDefaultParam(rtS))
          ->Constant_Value_c;
      }
    }
  }

  /* InitialCondition: '<S34>/IC' */
  if ((((D_Work *) ssGetRootDWork(rtS))->IC_FirstOutputTime_e == rtMinusInf) ||
      (((D_Work *) ssGetRootDWork(rtS))->IC_FirstOutputTime_e == ssGetTaskTime
       (rtS,0))) {
    ((D_Work *) ssGetRootDWork(rtS))->IC_FirstOutputTime_e = ssGetTaskTime(rtS,0);
    ((BlockIO *) _ssGetBlockIO(rtS))->IC_b = ((Parameters *) ssGetDefaultParam
      (rtS))->IC_Value_n;
  } else {
    ((BlockIO *) _ssGetBlockIO(rtS))->IC_b = rtb_sin;
  }

  /* Integrator: '<S34>/Integrator' */
  if (ssIsMajorTimeStep(rtS)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = ((ZCEventType) (((BlockIO *) _ssGetBlockIO(rtS))
                ->RelationalOperator_h && !((PrevZCSigStates *)
      _ssGetPrevZCSigState(rtS))->Integrator_ZCE_k));

    /* evaluate zero-crossings */
    ((PrevZCSigStates *) _ssGetPrevZCSigState(rtS))->Integrator_ZCE_k =
      (ZCSigState) ((BlockIO *) _ssGetBlockIO(rtS))->RelationalOperator_h;
    if (zcEvent || ((D_Work *) ssGetRootDWork(rtS))
        ->Integrator_IWORK_k.IcNeedsLoading) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE_e =
        ((BlockIO *) _ssGetBlockIO(rtS))->IC_b;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(rtS);
      ssSetBlkStateChange(rtS);
    }

    ((D_Work *) ssGetRootDWork(rtS))->Integrator_IWORK_k.IcNeedsLoading = 0;
  }

  rtb_sin = ((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE_e;

  /* Communications Blockset Inherit Shape (scominhshape) - '<S33>/Inherit Shape1' */

  /* Fcn: '<S26>/sin' */
  rtb_sin = cos(rtb_sin * 6.2831853071795862);

  /* Communications Blockset Inherit Shape (scominhshape) - '<S29>/Inherit Shape1' */
  ((BlockIO *) _ssGetBlockIO(rtS))->InheritShape1 = rtb_sin;
  ((BlockIO *) _ssGetBlockIO(rtS))->InheritShape1 = rtb_sin;

  /* Saturate: '<S4>/Saturation' */
  if (ssIsMajorTimeStep(rtS)) {
    ((D_Work *) ssGetRootDWork(rtS))->Saturation_MODE = ((BlockIO *)
      _ssGetBlockIO(rtS))->InheritShape1 >= ((Parameters *) ssGetDefaultParam
      (rtS))->Saturation_UpperSat ? 1 : ((BlockIO *) _ssGetBlockIO(rtS))
      ->InheritShape1 > ((Parameters *) ssGetDefaultParam(rtS))
      ->Saturation_LowerSat ? 0 : -1;
  }

  ((BlockIO *) _ssGetBlockIO(rtS))->Saturation = ((D_Work *) ssGetRootDWork(rtS))
    ->Saturation_MODE == 1 ? ((Parameters *) ssGetDefaultParam(rtS))
    ->Saturation_UpperSat : ((D_Work *) ssGetRootDWork(rtS))->Saturation_MODE ==
    -1 ? ((Parameters *) ssGetDefaultParam(rtS))->Saturation_LowerSat :
    ((BlockIO *) _ssGetBlockIO(rtS))->InheritShape1;
  if (ssIsSampleHit(rtS, 1, 0)) {      /* Sample time: [0.0s, 1.0s] */
    if (ssIsMajorTimeStep(rtS) && (rt_ZCFcn(RISING_ZERO_CROSSING,
          &((PrevZCSigStates *) _ssGetPrevZCSigState(rtS))->FETDSP1_ZCE,
          (((BlockIO *) _ssGetBlockIO(rtS))->Saturation)) != NO_ZCEVENT)) {
      /* Output and update for trigger system: '<S4>/FET DSP1' */

      /* MATLABFcn: '<S25>/MATLAB Fcn' */
      /* Call into Simulink to run the Matlab Fcn block. */
      ssCallAccelRunBlock(rtS, 0, 0, SS_CALL_MDL_OUTPUTS);
    }

    /* Scope: '<Root>/Scope1' */

    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(rtS, 10, 28, SS_CALL_MDL_OUTPUTS);
  }

  /* Gain: '<Root>/Gain1' */
  rtb_Gain1 *= ((Parameters *) ssGetDefaultParam(rtS))->Gain1_Gain;
  if (ssIsSampleHit(rtS, 1, 0)) {      /* Sample time: [0.0s, 1.0s] */
    /* Product: '<S4>/Product1' */
    ((BlockIO *) _ssGetBlockIO(rtS))->Product1 = ((BlockIO *) _ssGetBlockIO(rtS))
      ->MATLABFcn[0] * ((BlockIO *) _ssGetBlockIO(rtS))->MATLABFcn[1];
  }

  /* StateSpace Block: '<S1>/State-Space' */
  {
    rtb_StateSpace = ((Parameters *) ssGetDefaultParam(rtS))->StateSpace_C*
      ((ContinuousStates *) ssGetContStates(rtS))->StateSpace_CSTATE;
  }

  /* StateSpace Block: '<S2>/State-Space' */
  {
    rtb_StateSpace_o = ((Parameters *) ssGetDefaultParam(rtS))->StateSpace_C_p[0]*
      ((ContinuousStates *) ssGetContStates(rtS))->StateSpace_CSTATE_m[0]
      + ((Parameters *) ssGetDefaultParam(rtS))->StateSpace_C_p[1]*
      ((ContinuousStates *) ssGetContStates(rtS))->StateSpace_CSTATE_m[1];
  }

  /* StateSpace Block: '<Root>/Analog Filter Design' */
  {
    rtb_AnalogFilterDesign = ((Parameters *) ssGetDefaultParam(rtS))
      ->AnalogFilterDesign_C*((ContinuousStates *) ssGetContStates(rtS))
      ->AnalogFilterDesign_CSTATE[7];
  }

  /* TransferFcn Block: '<Root>/Transfer Fcn' */
  rtb_TransferFcn = ((Parameters *) ssGetDefaultParam(rtS))->TransferFcn_C*
    ((ContinuousStates *) ssGetContStates(rtS))->TransferFcn_CSTATE;

  /* Outputs for atomic system: '<Root>/Lead Lag1' */

  /* Integrator: '<S7>/Integrator' */
  rtb_Integrator = ((ContinuousStates *) ssGetContStates(rtS))
    ->Integrator_CSTATE_k;

  /* Integrator: '<S7>/Integrator1' */
  if (ssIsMajorTimeStep(rtS)) {
    if (((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE >=
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat_h ) {
      ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE =
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat_h;
    } else if (((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE <=
               ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_LowerSat_i )
    {
      ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE =
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_LowerSat_i;
    }
  }

  rtb_Integrator1 = ((ContinuousStates *) ssGetContStates(rtS))
    ->Integrator1_CSTATE;

  /* Scope: '<S7>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(rtS, 3, 2, SS_CALL_MDL_OUTPUTS);

  /* Integrator: '<S7>/Integrator2' */
  rtb_Integrator2 = ((ContinuousStates *) ssGetContStates(rtS))
    ->Integrator2_CSTATE;
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Product: '<S7>/Product1' incorporates:
     *  Constant: '<S7>/Wn'
     */
    ((BlockIO *) _ssGetBlockIO(rtS))->Product1_b = ((BlockIO *) _ssGetBlockIO
      (rtS))->Product1 * ((Parameters *) ssGetDefaultParam(rtS))->Wn_Value_h;

    /* Product: '<S7>/Product3' incorporates:
     *  Constant: '<S7>/Kd'
     *  Constant: '<S7>/Kv'
     */
    ((BlockIO *) _ssGetBlockIO(rtS))->Product3 = ((Parameters *)
      ssGetDefaultParam(rtS))->Kv_Value_c * ((Parameters *) ssGetDefaultParam
      (rtS))->Kd_Value_m;

    /* Product: '<S7>/Product5' incorporates:
     *  Constant: '<S7>/Z'
     *  Constant: '<S7>/cZ'
     *  Product: '<S7>/Product2'
     */
    ((BlockIO *) _ssGetBlockIO(rtS))->Product5 = ((Parameters *)
      ssGetDefaultParam(rtS))->Z_Value_n * ((Parameters *) ssGetDefaultParam(rtS))
      ->cZ_Value_i * ((BlockIO *) _ssGetBlockIO(rtS))->Product1;
  }

  /* Product: '<S7>/Product4' incorporates:
   *  Constant: '<S7>/Wn'
   *  Sum: '<S7>/Sum'
   */
  ((BlockIO *) _ssGetBlockIO(rtS))->Product4 = (rtb_Integrator + ((BlockIO *)
    _ssGetBlockIO(rtS))->Product5) * ((Parameters *) ssGetDefaultParam(rtS))
    ->Wn_Value_h / ((BlockIO *) _ssGetBlockIO(rtS))->Product3;

  /* Product: '<S7>/Product7' incorporates:
   *  Constant: '<S7>/Kd1'
   *  Constant: '<S7>/Wn'
   *  Sum: '<S7>/Sum1'
   */
  ((BlockIO *) _ssGetBlockIO(rtS))->Product7 = (rtb_Integrator1 -
    rtb_Integrator2) * ((Parameters *) ssGetDefaultParam(rtS))->Wn_Value_h *
    ((Parameters *) ssGetDefaultParam(rtS))->Kd1_Value;

  /* Outputs for atomic system: '<Root>/Lead Lag' */

  /* Integrator: '<S6>/Integrator' */
  rtb_Integrator_d = ((ContinuousStates *) ssGetContStates(rtS))
    ->Integrator_CSTATE_j;

  /* Integrator: '<S6>/Integrator1' */
  if (ssIsMajorTimeStep(rtS)) {
    if (((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_l >=
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat_n ) {
      ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_l =
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat_n;
    } else if (((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_l
               <= ((Parameters *) ssGetDefaultParam(rtS))
               ->Integrator1_LowerSat_m ) {
      ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_l =
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_LowerSat_m;
    }
  }

  rtb_Integrator1_o = ((ContinuousStates *) ssGetContStates(rtS))
    ->Integrator1_CSTATE_l;

  /* Scope: '<S6>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(rtS, 2, 2, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Product: '<S6>/Product1' incorporates:
     *  Constant: '<S6>/Wn'
     */
    ((BlockIO *) _ssGetBlockIO(rtS))->Product1_a = ((BlockIO *) _ssGetBlockIO
      (rtS))->Product1 * ((Parameters *) ssGetDefaultParam(rtS))->Wn_Value_n;

    /* Product: '<S6>/Product3' incorporates:
     *  Constant: '<S6>/Kd'
     *  Constant: '<S6>/Kv'
     */
    ((BlockIO *) _ssGetBlockIO(rtS))->Product3_l = ((Parameters *)
      ssGetDefaultParam(rtS))->Kv_Value_d * ((Parameters *) ssGetDefaultParam
      (rtS))->Kd_Value_b;

    /* Product: '<S6>/Product5' incorporates:
     *  Constant: '<S6>/Z'
     *  Constant: '<S6>/cZ'
     *  Product: '<S6>/Product2'
     */
    ((BlockIO *) _ssGetBlockIO(rtS))->Product5_g = ((Parameters *)
      ssGetDefaultParam(rtS))->Z_Value_g * ((Parameters *) ssGetDefaultParam(rtS))
      ->cZ_Value_d * ((BlockIO *) _ssGetBlockIO(rtS))->Product1;
  }

  /* Product: '<S6>/Product4' incorporates:
   *  Constant: '<S6>/Wn'
   *  Sum: '<S6>/Sum'
   */
  ((BlockIO *) _ssGetBlockIO(rtS))->Product4_b = (rtb_Integrator_d + ((BlockIO *)
    _ssGetBlockIO(rtS))->Product5_g) * ((Parameters *) ssGetDefaultParam(rtS))
    ->Wn_Value_n / ((BlockIO *) _ssGetBlockIO(rtS))->Product3_l;

  /* Outputs for atomic system: '<Root>/LPF Type1' */

  /* Integrator: '<S5>/Integrator1' */
  if (ssIsMajorTimeStep(rtS)) {
    if (((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_ls >=
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat ) {
      ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_ls =
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat;
    } else if (((ContinuousStates *) ssGetContStates(rtS))
               ->Integrator1_CSTATE_ls <= ((Parameters *) ssGetDefaultParam(rtS))
               ->Integrator1_LowerSat ) {
      ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_ls =
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_LowerSat;
    }
  }

  rtb_Integrator1_o2 = ((ContinuousStates *) ssGetContStates(rtS))
    ->Integrator1_CSTATE_ls;

  /* Integrator: '<S5>/Integrator' */
  if (ssIsMajorTimeStep(rtS)) {
    if (((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE_jp >=
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator_UpperSat ) {
      ((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE_jp =
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator_UpperSat;
    } else if (((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE_jp
               <= ((Parameters *) ssGetDefaultParam(rtS))->Integrator_LowerSat )
    {
      ((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE_jp =
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator_LowerSat;
    }
  }

  rtb_Integrator_o = ((ContinuousStates *) ssGetContStates(rtS))
    ->Integrator_CSTATE_jp;

  /* Scope: '<S5>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(rtS, 1, 2, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Product: '<S5>/Product2' incorporates:
     *  Constant: '<S5>/Z'
     *  Constant: '<S5>/cZ'
     */
    rtb_Product2_e = ((Parameters *) ssGetDefaultParam(rtS))->Z_Value *
      ((Parameters *) ssGetDefaultParam(rtS))->cZ_Value;

    /* Product: '<S5>/Product1' incorporates:
     *  Constant: '<S5>/Wn'
     *  Product: '<S5>/Product'
     */
    ((BlockIO *) _ssGetBlockIO(rtS))->Product1_e = ((Parameters *)
      ssGetDefaultParam(rtS))->Wn_Value / rtb_Product2_e * ((BlockIO *)
      _ssGetBlockIO(rtS))->Product1;

    /* Product: '<S5>/Product3' incorporates:
     *  Constant: '<S5>/Kd'
     *  Constant: '<S5>/Kv'
     */
    rtb_Product3 = ((Parameters *) ssGetDefaultParam(rtS))->Kv_Value *
      ((Parameters *) ssGetDefaultParam(rtS))->Kd_Value;
  }

  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Product: '<S5>/Product5' incorporates:
     *  Constant: '<S5>/Wn'
     */
    ((BlockIO *) _ssGetBlockIO(rtS))->Product5_p = ((Parameters *)
      ssGetDefaultParam(rtS))->Wn_Value * rtb_Product2_e * rtb_Product3;
  }

  /* Product: '<S5>/Product4' incorporates:
   *  Sum: '<S5>/Sum'
   */
  ((BlockIO *) _ssGetBlockIO(rtS))->Product4_i = (rtb_Integrator_o -
    rtb_Integrator1_o2) * ((BlockIO *) _ssGetBlockIO(rtS))->Product5_p;

  /* Switch: '<S13>/SwitchControl' incorporates:
   *  Constant: '<S13>/Constant'
   */
  if (((Parameters *) ssGetDefaultParam(rtS))->Constant_Value_l > ((Parameters *)
       ssGetDefaultParam(rtS))->SwitchControl_Threshold) {
    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (((Parameters *) ssGetDefaultParam(rtS))->Constant_Value_m > ((Parameters
          *) ssGetDefaultParam(rtS))->SwitchControl_Threshold_e1) {
      /* Switch: '<S8>/SwitchControl' incorporates:
       *  Constant: '<S8>/Constant'
       */
      if (((Parameters *) ssGetDefaultParam(rtS))->Constant_Value_d >
          ((Parameters *) ssGetDefaultParam(rtS))->SwitchControl_Threshold_o) {
        rtb_SwitchControl_a = rtb_TransferFcn;
      } else {
        rtb_SwitchControl_a = rtb_Integrator2;
      }
    } else {
      /* Switch: '<S9>/SwitchControl' incorporates:
       *  Constant: '<S9>/Constant'
       */
      if (((Parameters *) ssGetDefaultParam(rtS))->Constant_Value_cr >
          ((Parameters *) ssGetDefaultParam(rtS))->SwitchControl_Threshold_c) {
        rtb_SwitchControl_a = rtb_Integrator1_o;
      } else {
        rtb_SwitchControl_a = rtb_Integrator1_o2;
      }
    }

    rtb_SwitchControl = rtb_SwitchControl_a;
  } else {
    /* Switch: '<S14>/SwitchControl' incorporates:
     *  Constant: '<S14>/Constant'
     */
    if (((Parameters *) ssGetDefaultParam(rtS))->Constant_Value_lw >
        ((Parameters *) ssGetDefaultParam(rtS))->SwitchControl_Threshold_i) {
      rtb_SwitchControl_a = ((BlockIO *) _ssGetBlockIO(rtS))->Product1;
    } else {
      /* Switch: '<S11>/SwitchControl' incorporates:
       *  Constant: '<S11>/Constant'
       */
      if (((Parameters *) ssGetDefaultParam(rtS))->Constant_Value_g >
          ((Parameters *) ssGetDefaultParam(rtS))->SwitchControl_Threshold_e) {
        /* Switch: '<S10>/SwitchControl' incorporates:
         *  Constant: '<S10>/Constant'
         */
        if (((Parameters *) ssGetDefaultParam(rtS))->Constant_Value_p >
            ((Parameters *) ssGetDefaultParam(rtS))->SwitchControl_Threshold_d)
        {
          rtb_SwitchControl_a = rtb_AnalogFilterDesign;
        } else {
          rtb_SwitchControl_a = rtb_StateSpace;
        }
      } else {
        rtb_SwitchControl_a = rtb_StateSpace_o;
      }
    }

    rtb_SwitchControl = rtb_SwitchControl_a;
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S3>/Carrier frequency1'
   *  Gain: '<S3>/Sensitivity'
   */
  ((BlockIO *) _ssGetBlockIO(rtS))->Sum = ((Parameters *) ssGetDefaultParam(rtS))
    ->Sensitivity_Gain * rtb_SwitchControl + ((Parameters *) ssGetDefaultParam
    (rtS))->Carrierfrequency1_Value;
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Sum: '<S26>/Sum' incorporates:
     *  Constant: '<Root>/Fsample1'
     *  Constant: '<S26>/Carrier frequency1'
     *  Gain: '<S26>/Sensitivity'
     */
    ((BlockIO *) _ssGetBlockIO(rtS))->Sum_p = ((Parameters *) ssGetDefaultParam
      (rtS))->Sensitivity_Gain_g * ((Parameters *) ssGetDefaultParam(rtS))
      ->Fsample1_Value + ((Parameters *) ssGetDefaultParam(rtS))
      ->Carrierfrequency1_Value_j;
  }

  /* tid is required for a uniform function interface. This system
   * is single rate, and in this case, tid is not accessed. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *rtS, int_T tid)
{
  /* Update for atomic system: '<Root>/Lead Lag1' */

  /* Limited Integrator Block: '<S7>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE ==
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat_h) {
      switch (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE) {
       case INTG_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4 < 0.0) {
          ssSetSolverNeedsReset(rtS);
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE =
            INTG_LEAVING_UPPER_SAT;
        }

        break;

       case INTG_LEAVING_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4 >= 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(rtS);
        }

        break;

       default:
        ssSetSolverNeedsReset(rtS);
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4 < 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE =
            INTG_LEAVING_UPPER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE = INTG_UPPER_SAT;
        }

        break;
      }
    } else if (((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE ==
               ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_LowerSat_i)
    {
      switch (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE) {
       case INTG_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4 > 0.0) {
          ssSetSolverNeedsReset(rtS);
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE =
            INTG_LEAVING_LOWER_SAT;
        }

        break;

       case INTG_LEAVING_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4 <= 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(rtS);
        }

        break;

       default:
        ssSetSolverNeedsReset(rtS);
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4 > 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE =
            INTG_LEAVING_LOWER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE = INTG_LOWER_SAT;
        }

        break;
      }
    } else {
      ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE = INTG_NORMAL;
    }
  }

  /* Update for atomic system: '<Root>/Lead Lag' */

  /* Limited Integrator Block: '<S6>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_l ==
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat_n) {
      switch (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m) {
       case INTG_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4_b < 0.0) {
          ssSetSolverNeedsReset(rtS);
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m =
            INTG_LEAVING_UPPER_SAT;
        }

        break;

       case INTG_LEAVING_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4_b >= 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(rtS);
        }

        break;

       default:
        ssSetSolverNeedsReset(rtS);
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4_b < 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m =
            INTG_LEAVING_UPPER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m = INTG_UPPER_SAT;
        }

        break;
      }
    } else if (((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_l
               == ((Parameters *) ssGetDefaultParam(rtS))
               ->Integrator1_LowerSat_m) {
      switch (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m) {
       case INTG_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4_b > 0.0) {
          ssSetSolverNeedsReset(rtS);
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m =
            INTG_LEAVING_LOWER_SAT;
        }

        break;

       case INTG_LEAVING_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4_b <= 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(rtS);
        }

        break;

       default:
        ssSetSolverNeedsReset(rtS);
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4_b > 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m =
            INTG_LEAVING_LOWER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m = INTG_LOWER_SAT;
        }

        break;
      }
    } else {
      ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m = INTG_NORMAL;
    }
  }

  /* Update for atomic system: '<Root>/LPF Type1' */

  /* Limited Integrator Block: '<S5>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_ls ==
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat) {
      switch (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d) {
       case INTG_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4_i < 0.0) {
          ssSetSolverNeedsReset(rtS);
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d =
            INTG_LEAVING_UPPER_SAT;
        }

        break;

       case INTG_LEAVING_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4_i >= 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(rtS);
        }

        break;

       default:
        ssSetSolverNeedsReset(rtS);
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4_i < 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d =
            INTG_LEAVING_UPPER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d = INTG_UPPER_SAT;
        }

        break;
      }
    } else if (((ContinuousStates *) ssGetContStates(rtS))
               ->Integrator1_CSTATE_ls == ((Parameters *) ssGetDefaultParam(rtS))
               ->Integrator1_LowerSat) {
      switch (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d) {
       case INTG_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4_i > 0.0) {
          ssSetSolverNeedsReset(rtS);
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d =
            INTG_LEAVING_LOWER_SAT;
        }

        break;

       case INTG_LEAVING_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4_i <= 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(rtS);
        }

        break;

       default:
        ssSetSolverNeedsReset(rtS);
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product4_i > 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d =
            INTG_LEAVING_LOWER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d = INTG_LOWER_SAT;
        }

        break;
      }
    } else {
      ((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d = INTG_NORMAL;
    }
  }

  /* Limited Integrator Block: '<S5>/Integrator' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE_jp ==
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator_UpperSat) {
      switch (((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE) {
       case INTG_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product1_e < 0.0) {
          ssSetSolverNeedsReset(rtS);
          ((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE =
            INTG_LEAVING_UPPER_SAT;
        }

        break;

       case INTG_LEAVING_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product1_e >= 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(rtS);
        }

        break;

       default:
        ssSetSolverNeedsReset(rtS);
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product1_e < 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE =
            INTG_LEAVING_UPPER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE = INTG_UPPER_SAT;
        }

        break;
      }
    } else if (((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE_jp
               == ((Parameters *) ssGetDefaultParam(rtS))->Integrator_LowerSat)
    {
      switch (((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE) {
       case INTG_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product1_e > 0.0) {
          ssSetSolverNeedsReset(rtS);
          ((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE =
            INTG_LEAVING_LOWER_SAT;
        }

        break;

       case INTG_LEAVING_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product1_e <= 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(rtS);
        }

        break;

       default:
        ssSetSolverNeedsReset(rtS);
        if (((BlockIO *) _ssGetBlockIO(rtS))->Product1_e > 0.0) {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE =
            INTG_LEAVING_LOWER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE = INTG_LOWER_SAT;
        }

        break;
      }
    } else {
      ((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE = INTG_NORMAL;
    }
  }

  /* tid is required for a uniform function interface. This system
   * is single rate, and in this case, tid is not accessed. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES

static void mdlDerivatives(SimStruct *rtS)
{
  /* Integrator Block: '<S24>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(rtS))->Integrator_CSTATE = ((BlockIO *)
      _ssGetBlockIO(rtS))->Sum;
  }

  /* Integrator Block: '<S34>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(rtS))->Integrator_CSTATE_e = ((BlockIO *)
      _ssGetBlockIO(rtS))->Sum_p;
  }

  /* StateSpace Block: '<S1>/State-Space' */
  {
    ((StateDerivatives *) ssGetdX(rtS))->StateSpace_CSTATE = ((BlockIO *)
      _ssGetBlockIO(rtS))->Product1;
    ((StateDerivatives *) ssGetdX(rtS))->StateSpace_CSTATE += (((Parameters *)
      ssGetDefaultParam(rtS))->StateSpace_A)*((ContinuousStates *)
      ssGetContStates(rtS))->StateSpace_CSTATE;
  }

  /* StateSpace Block: '<S2>/State-Space' */
  {
    ((StateDerivatives *) ssGetdX(rtS))->StateSpace_CSTATE_m[0] = ((BlockIO *)
      _ssGetBlockIO(rtS))->Product1;
    ((StateDerivatives *) ssGetdX(rtS))->StateSpace_CSTATE_m[0] += (((Parameters
      *) ssGetDefaultParam(rtS))->StateSpace_A_d[0])*((ContinuousStates *)
      ssGetContStates(rtS))->StateSpace_CSTATE_m[0]
      + (((Parameters *) ssGetDefaultParam(rtS))->StateSpace_A_d[1])*
      ((ContinuousStates *) ssGetContStates(rtS))->StateSpace_CSTATE_m[1];
    ((StateDerivatives *) ssGetdX(rtS))->StateSpace_CSTATE_m[1]=
      ((ContinuousStates *) ssGetContStates(rtS))->StateSpace_CSTATE_m[0];
  }

  /* StateSpace Block: '<Root>/Analog Filter Design' */
  {
    ((StateDerivatives *) ssGetdX(rtS))->AnalogFilterDesign_CSTATE[0] =
      ((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_B*((BlockIO *)
      _ssGetBlockIO(rtS))->Product1;
    ((StateDerivatives *) ssGetdX(rtS))->AnalogFilterDesign_CSTATE[0] +=
      (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[0])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[0]
      + (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[1])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[1];
    ((StateDerivatives *) ssGetdX(rtS))->AnalogFilterDesign_CSTATE[1] =
      (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[2])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[0];
    ((StateDerivatives *) ssGetdX(rtS))->AnalogFilterDesign_CSTATE[2] =
      (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[3])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[1]
      + (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[4])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[2]
      + (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[5])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[3];
    ((StateDerivatives *) ssGetdX(rtS))->AnalogFilterDesign_CSTATE[3] =
      (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[6])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[2];
    ((StateDerivatives *) ssGetdX(rtS))->AnalogFilterDesign_CSTATE[4] =
      (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[7])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[3]
      + (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[8])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[4]
      + (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[9])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[5];
    ((StateDerivatives *) ssGetdX(rtS))->AnalogFilterDesign_CSTATE[5] =
      (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[10])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[4];
    ((StateDerivatives *) ssGetdX(rtS))->AnalogFilterDesign_CSTATE[6] =
      (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[11])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[5]
      + (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[12])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[6]
      + (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[13])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[7];
    ((StateDerivatives *) ssGetdX(rtS))->AnalogFilterDesign_CSTATE[7] =
      (((Parameters *) ssGetDefaultParam(rtS))->AnalogFilterDesign_A[14])*
      ((ContinuousStates *) ssGetContStates(rtS))->AnalogFilterDesign_CSTATE[6];
  }

  /* TransferFcn Block: '<Root>/Transfer Fcn' */
  {
    ((StateDerivatives *) ssGetdX(rtS))->TransferFcn_CSTATE = ((BlockIO *)
      _ssGetBlockIO(rtS))->Product1;
    ((StateDerivatives *) ssGetdX(rtS))->TransferFcn_CSTATE += (((Parameters *)
      ssGetDefaultParam(rtS))->TransferFcn_A)*((ContinuousStates *)
      ssGetContStates(rtS))->TransferFcn_CSTATE;
  }

  /* Derivatives for atomic system: '<Root>/Lead Lag1' */

  /* Integrator Block: '<S7>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(rtS))->Integrator_CSTATE_k = ((BlockIO *)
      _ssGetBlockIO(rtS))->Product1_b;
  }

  /* Limited Integrator Block: '<S7>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE != INTG_UPPER_SAT)
        && (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE != INTG_LOWER_SAT)
        ) {
      ((StateDerivatives *) ssGetdX(rtS))->Integrator1_CSTATE = ((BlockIO *)
        _ssGetBlockIO(rtS))->Product4;
      ((StateDisabled *) ssGetContStateDisabled(rtS))->Integrator1_CSTATE =
        FALSE;
    } else {
      /* in saturation */
      ((StateDerivatives *) ssGetdX(rtS))->Integrator1_CSTATE = 0.0;
      if ((((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE == INTG_UPPER_SAT)
          || (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE ==
              INTG_LOWER_SAT)) {
        ((StateDisabled *) ssGetContStateDisabled(rtS))->Integrator1_CSTATE =
          TRUE;
      }
    }
  }

  /* Integrator Block: '<S7>/Integrator2' */
  {
    ((StateDerivatives *) ssGetdX(rtS))->Integrator2_CSTATE = ((BlockIO *)
      _ssGetBlockIO(rtS))->Product7;
  }

  /* Derivatives for atomic system: '<Root>/Lead Lag' */

  /* Integrator Block: '<S6>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(rtS))->Integrator_CSTATE_j = ((BlockIO *)
      _ssGetBlockIO(rtS))->Product1_a;
  }

  /* Limited Integrator Block: '<S6>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m != INTG_UPPER_SAT)
        && (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m !=
            INTG_LOWER_SAT) ) {
      ((StateDerivatives *) ssGetdX(rtS))->Integrator1_CSTATE_l = ((BlockIO *)
        _ssGetBlockIO(rtS))->Product4_b;
      ((StateDisabled *) ssGetContStateDisabled(rtS))->Integrator1_CSTATE_l =
        FALSE;
    } else {
      /* in saturation */
      ((StateDerivatives *) ssGetdX(rtS))->Integrator1_CSTATE_l = 0.0;
      if ((((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m ==
           INTG_UPPER_SAT) || (((D_Work *) ssGetRootDWork(rtS))
           ->Integrator1_MODE_m == INTG_LOWER_SAT)) {
        ((StateDisabled *) ssGetContStateDisabled(rtS))->Integrator1_CSTATE_l =
          TRUE;
      }
    }
  }

  /* Derivatives for atomic system: '<Root>/LPF Type1' */

  /* Limited Integrator Block: '<S5>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d != INTG_UPPER_SAT)
        && (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d !=
            INTG_LOWER_SAT) ) {
      ((StateDerivatives *) ssGetdX(rtS))->Integrator1_CSTATE_ls = ((BlockIO *)
        _ssGetBlockIO(rtS))->Product4_i;
      ((StateDisabled *) ssGetContStateDisabled(rtS))->Integrator1_CSTATE_ls =
        FALSE;
    } else {
      /* in saturation */
      ((StateDerivatives *) ssGetdX(rtS))->Integrator1_CSTATE_ls = 0.0;
      if ((((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d ==
           INTG_UPPER_SAT) || (((D_Work *) ssGetRootDWork(rtS))
           ->Integrator1_MODE_d == INTG_LOWER_SAT)) {
        ((StateDisabled *) ssGetContStateDisabled(rtS))->Integrator1_CSTATE_ls =
          TRUE;
      }
    }
  }

  /* Limited Integrator Block: '<S5>/Integrator' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE != INTG_UPPER_SAT)
        && (((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE != INTG_LOWER_SAT)
        ) {
      ((StateDerivatives *) ssGetdX(rtS))->Integrator_CSTATE_jp = ((BlockIO *)
        _ssGetBlockIO(rtS))->Product1_e;
      ((StateDisabled *) ssGetContStateDisabled(rtS))->Integrator_CSTATE_jp =
        FALSE;
    } else {
      /* in saturation */
      ((StateDerivatives *) ssGetdX(rtS))->Integrator_CSTATE_jp = 0.0;
      if ((((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE == INTG_UPPER_SAT) ||
          (((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE == INTG_LOWER_SAT))
      {
        ((StateDisabled *) ssGetContStateDisabled(rtS))->Integrator_CSTATE_jp =
          TRUE;
      }
    }
  }
}

/* ZeroCrossings for root system: '<Root>' */
#define MDL_ZERO_CROSSINGS

static void mdlZeroCrossings(SimStruct *rtS)
{
  /* ZeroCrossings for Abs: '<S24>/Abs' */
  ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Abs_NSZC = ((BlockIO *)
    _ssGetBlockIO(rtS))->Gain;

  /* ZeroCrossings for RelationalOperator: '<S24>/Relational Operator' incorporates:
   *  Constant: '<S24>/Constant'
   */
  ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->RelationalOperator_NSZC =
    ((BlockIO *) _ssGetBlockIO(rtS))->Abs - ((Parameters *) ssGetDefaultParam
    (rtS))->Constant_Value;

  /* ZeroCrossings for Abs: '<S34>/Abs' */
  ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Abs_NSZC_a = ((BlockIO *)
    _ssGetBlockIO(rtS))->Gain_f;

  /* ZeroCrossings for RelationalOperator: '<S34>/Relational Operator' incorporates:
   *  Constant: '<S34>/Constant'
   */
  ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->RelationalOperator_NSZC_c =
    ((BlockIO *) _ssGetBlockIO(rtS))->Abs_j - ((Parameters *) ssGetDefaultParam
    (rtS))->Constant_Value_c;

  /* ZeroCrossings for Saturate: '<S4>/Saturation' */
  ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Saturation_NSZC[0] = ((BlockIO *)
    _ssGetBlockIO(rtS))->InheritShape1 - ((Parameters *) ssGetDefaultParam(rtS)
    )->Saturation_UpperSat;
  ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Saturation_NSZC[1] = ((BlockIO *)
    _ssGetBlockIO(rtS))->InheritShape1 - ((Parameters *) ssGetDefaultParam(rtS)
    )->Saturation_LowerSat;
  ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->FETDSP1_NSZC = ((BlockIO *)
    _ssGetBlockIO(rtS))->Saturation;

  /* ZeroCrossings for atomic system: '<Root>/Lead Lag1' */

  /* Limited Integrator Block: '<S7>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for limited integrator */
    if (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE ==
        INTG_LEAVING_UPPER_SAT &&
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE >=
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat_h) {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC[0] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC[0] =
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE -
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat_h;
    }

    if (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE ==
        INTG_LEAVING_LOWER_SAT &&
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE <=
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_LowerSat_i) {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC[1] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC[1] =
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE -
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_LowerSat_i;
    }

    /* zero crossings for input of limited integrator */
    {
      boolean_T anyStateSaturated = FALSE;
      if ((((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE == INTG_UPPER_SAT)
          ||
          (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE == INTG_LOWER_SAT))
      {
        anyStateSaturated = TRUE;
      }

      if (anyStateSaturated) {
        ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC[2] =
          ((BlockIO *) _ssGetBlockIO(rtS))->Product4;
      } else {
        ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC[2] = 0.0;
      }
    }
  }

  /* ZeroCrossings for atomic system: '<Root>/Lead Lag' */

  /* Limited Integrator Block: '<S6>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for limited integrator */
    if (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m ==
        INTG_LEAVING_UPPER_SAT &&
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_l >=
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat_n) {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC_e[0] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC_e[0] =
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_l -
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat_n;
    }

    if (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m ==
        INTG_LEAVING_LOWER_SAT &&
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_l <=
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_LowerSat_m) {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC_e[1] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC_e[1] =
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_l -
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_LowerSat_m;
    }

    /* zero crossings for input of limited integrator */
    {
      boolean_T anyStateSaturated = FALSE;
      if ((((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m ==
           INTG_UPPER_SAT) ||
          (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_m ==
           INTG_LOWER_SAT)) {
        anyStateSaturated = TRUE;
      }

      if (anyStateSaturated) {
        ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC_e[2] =
          ((BlockIO *) _ssGetBlockIO(rtS))->Product4_b;
      } else {
        ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC_e[2] = 0.0;
      }
    }
  }

  /* ZeroCrossings for atomic system: '<Root>/LPF Type1' */

  /* Limited Integrator Block: '<S5>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for limited integrator */
    if (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d ==
        INTG_LEAVING_UPPER_SAT &&
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_ls >=
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat) {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC_k[0] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC_k[0] =
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_ls -
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_UpperSat;
    }

    if (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d ==
        INTG_LEAVING_LOWER_SAT &&
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_ls <=
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_LowerSat) {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC_k[1] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC_k[1] =
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator1_CSTATE_ls -
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator1_LowerSat;
    }

    /* zero crossings for input of limited integrator */
    {
      boolean_T anyStateSaturated = FALSE;
      if ((((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d ==
           INTG_UPPER_SAT) ||
          (((D_Work *) ssGetRootDWork(rtS))->Integrator1_MODE_d ==
           INTG_LOWER_SAT)) {
        anyStateSaturated = TRUE;
      }

      if (anyStateSaturated) {
        ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC_k[2] =
          ((BlockIO *) _ssGetBlockIO(rtS))->Product4_i;
      } else {
        ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator1_NSZC_k[2] = 0.0;
      }
    }
  }

  /* Limited Integrator Block: '<S5>/Integrator' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for limited integrator */
    if (((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE ==
        INTG_LEAVING_UPPER_SAT &&
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE_jp >=
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator_UpperSat) {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator_NSZC[0] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator_NSZC[0] =
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE_jp -
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator_UpperSat;
    }

    if (((D_Work *) ssGetRootDWork(rtS))->Integrator_MODE ==
        INTG_LEAVING_LOWER_SAT &&
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE_jp <=
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator_LowerSat) {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator_NSZC[1] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(rtS))->Integrator_NSZC[1] =
        ((ContinuousStates *) ssGetContStates(rtS))->Integrator_CSTATE_jp -
        ((Parameters *) ssGetDefaultParam(rtS))->Integrator_LowerSat;
    }
  }
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *rtS)
{
  /* checksum */
  ssSetChecksumVal(rtS, 0, 519793609U);
  ssSetChecksumVal(rtS, 1, 3102964591U);
  ssSetChecksumVal(rtS, 2, 1728750255U);
  ssSetChecksumVal(rtS, 3, 3491277303U);

  /* options */
  ssSetOptions(rtS, SS_OPTION_EXCEPTION_FREE_CODE);

  /* Accelerator check memory map size match for DWork */
  if (ssGetSizeofDWork(S) != sizeof(D_Work)) {
    ssSetErrorStatus(S,"Unexpected error: Internal DWork sizes do "
                     "not match for accelerator mex file.");
  }

  /* Accelerator check memory map size match for BlockIO */
  if (ssGetSizeofGlobalBlockIO(S) != sizeof(BlockIO)) {
    ssSetErrorStatus(S,"Unexpected error: Internal BlockIO sizes do "
                     "not match for accelerator mex file.");
  }

  /* model parameters */
  _ssSetDefaultParam(rtS, (real_T *) &rtDefaultParameters);

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Empty mdlInitializeSampleTimes function (never called) */
static void mdlInitializeSampleTimes(SimStruct *rtS)
{
}

/* Empty mdlTerminate function (never called) */
static void mdlTerminate(SimStruct *S)
{
}

/* MATLAB MEX Glue */
#include "simulink.c"
