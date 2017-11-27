/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) product.
 */

/*
 * pll___acc.c
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
#include <math.h>
#include "pll___acc.h"
#include "pll___acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat                     S-Function
#define AccDefine1                     Accelerator_S-Function

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  /* local block i/o variables */
  real_T B_1_19_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_1_0_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_0 * ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE;
  if (ssIsMajorTimeStep(S)) {
    ((D_Work *) ssGetRootDWork(S))->Abs_MODE = ((BlockIO *) _ssGetBlockIO(S))
      ->B_1_0_0 >= 0.0 ? 1 : 0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_1_1_0 = ((D_Work *) ssGetRootDWork(S))
    ->Abs_MODE > 0 ? ((BlockIO *) _ssGetBlockIO(S))->B_1_0_0 : -((BlockIO *)
    _ssGetBlockIO(S))->B_1_0_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_1_2_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1;
    if (ssIsMajorTimeStep(S)) {
      ((D_Work *) ssGetRootDWork(S))->RelationalOperator_Mode = (((BlockIO *)
        _ssGetBlockIO(S))->B_1_1_0 >= ((BlockIO *) _ssGetBlockIO(S))->B_1_2_0);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_1_3_0 = ((D_Work *) ssGetRootDWork(S))
      ->RelationalOperator_Mode;
  }

  B_1_19_0 = muDoubleScalarRem(((BlockIO *) _ssGetBlockIO(S))->B_1_0_0,
    ((BlockIO *) _ssGetBlockIO(S))->B_1_2_0);
  if ((((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime == (rtMinusInf)) ||
      (((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime == ssGetTaskTime(S,0)))
  {
    ((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime = ssGetTaskTime(S,0);
    ((BlockIO *) _ssGetBlockIO(S))->B_1_5_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_2;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_1_5_0 = B_1_19_0;
  }

  /* Integrator: '<S9>/Integrator' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = ((ZCEventType) (((BlockIO *) _ssGetBlockIO(S))->B_1_3_0 &&
                (((PrevZCSigStates *) _ssGetPrevZCSigState(S))
                 ->Integrator_Reset_ZCE != POS_ZCSIG)));

    /* evaluate zero-crossings */
    ((PrevZCSigStates *) _ssGetPrevZCSigState(S))->Integrator_Reset_ZCE =
      (ZCSigState) ((BlockIO *) _ssGetBlockIO(S))->B_1_3_0;
    if (zcEvent || ((D_Work *) ssGetRootDWork(S))
        ->Integrator_IWORK.IcNeedsLoading) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE = ((BlockIO *)
        _ssGetBlockIO(S))->B_1_5_0;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
      ssSetBlkStateChange(S);
    }

    ((D_Work *) ssGetRootDWork(S))->Integrator_IWORK.IcNeedsLoading = 0;
  }

  B_1_19_0 = ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE;

  /* Communications Blockset Inherit Shape (scominhshape) - '<S6>/B_1_1' */
  B_1_19_0 = muDoubleScalarCos(B_1_19_0 * 6.2831853071795862);

  /* Communications Blockset Inherit Shape (scominhshape) - '<S1>/B_1_2' */
  ((BlockIO *) _ssGetBlockIO(S))->B_1_9_0 = B_1_19_0;
  if (ssIsMajorTimeStep(S)) {
    ((D_Work *) ssGetRootDWork(S))->Saturation_MODE = ((BlockIO *) _ssGetBlockIO
      (S))->B_1_9_0 >= ((Parameters *) ssGetDefaultParam(S))->P_3 ? 1 :
      ((BlockIO *) _ssGetBlockIO(S))->B_1_9_0 > ((Parameters *)
      ssGetDefaultParam(S))->P_4 ? 0 : -1;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_1_10_0 = ((D_Work *) ssGetRootDWork(S))
    ->Saturation_MODE == 1 ? ((Parameters *) ssGetDefaultParam(S))->P_3 :
    ((D_Work *) ssGetRootDWork(S))->Saturation_MODE == -1 ? ((Parameters *)
    ssGetDefaultParam(S))->P_4 : ((BlockIO *) _ssGetBlockIO(S))->B_1_9_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_1_11_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_5 * ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_m;
  if (ssIsMajorTimeStep(S)) {
    ((D_Work *) ssGetRootDWork(S))->Abs_MODE_f = ((BlockIO *) _ssGetBlockIO(S)
      )->B_1_11_0 >= 0.0 ? 1 : 0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_1_12_0 = ((D_Work *) ssGetRootDWork(S))
    ->Abs_MODE_f > 0 ? ((BlockIO *) _ssGetBlockIO(S))->B_1_11_0 : -((BlockIO *)
    _ssGetBlockIO(S))->B_1_11_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_1_13_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_6;
    if (ssIsMajorTimeStep(S)) {
      ((D_Work *) ssGetRootDWork(S))->RelationalOperator_Mode_o = (((BlockIO *)
        _ssGetBlockIO(S))->B_1_12_0 >= ((BlockIO *) _ssGetBlockIO(S))->B_1_13_0);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_1_14_0 = ((D_Work *) ssGetRootDWork(S))
      ->RelationalOperator_Mode_o;
  }

  B_1_19_0 = muDoubleScalarRem(((BlockIO *) _ssGetBlockIO(S))->B_1_11_0,
    ((BlockIO *) _ssGetBlockIO(S))->B_1_13_0);
  if ((((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime_b == (rtMinusInf)) ||
      (((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime_b == ssGetTaskTime(S,0)))
  {
    ((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime_b = ssGetTaskTime(S,0);
    ((BlockIO *) _ssGetBlockIO(S))->B_1_16_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_7;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_1_16_0 = B_1_19_0;
  }

  /* Integrator: '<S15>/Integrator' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = ((ZCEventType) (((BlockIO *) _ssGetBlockIO(S))->B_1_14_0 &&
                (((PrevZCSigStates *) _ssGetPrevZCSigState(S))
                 ->Integrator_Reset_ZCE_m != POS_ZCSIG)));

    /* evaluate zero-crossings */
    ((PrevZCSigStates *) _ssGetPrevZCSigState(S))->Integrator_Reset_ZCE_m =
      (ZCSigState) ((BlockIO *) _ssGetBlockIO(S))->B_1_14_0;
    if (zcEvent || ((D_Work *) ssGetRootDWork(S))
        ->Integrator_IWORK_g.IcNeedsLoading) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_m = ((BlockIO
        *) _ssGetBlockIO(S))->B_1_16_0;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
      ssSetBlkStateChange(S);
    }

    ((D_Work *) ssGetRootDWork(S))->Integrator_IWORK_g.IcNeedsLoading = 0;
  }

  B_1_19_0 = ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_m;

  /* Communications Blockset Inherit Shape (scominhshape) - '<S12>/B_1_4' */
  B_1_19_0 = muDoubleScalarCos(B_1_19_0 * 6.2831853071795862);

  /* Communications Blockset Inherit Shape (scominhshape) - '<S2>/B_1_5' */
  ((BlockIO *) _ssGetBlockIO(S))->B_1_20_0 = B_1_19_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_1_21_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_1_20_0 < 0.0 ? (-muDoubleScalarFloor(muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_1_20_0 / ((Parameters *) ssGetDefaultParam(S))->P_8) +
    0.5)) * ((Parameters *) ssGetDefaultParam(S))->P_8 : muDoubleScalarFloor
    (muDoubleScalarAbs(((BlockIO *) _ssGetBlockIO(S))->B_1_20_0 / ((Parameters *)
       ssGetDefaultParam(S))->P_8) + 0.5) * ((Parameters *) ssGetDefaultParam(S))
    ->P_8;
  if (ssIsSampleHit(S, 1, 0)) {
    if (ssIsMajorTimeStep(S) && (rt_ZCFcn(RISING_ZERO_CROSSING,
          &((PrevZCSigStates *) _ssGetPrevZCSigState(S))
          ->TriggeredSubsystem_Trig_ZCE,
          (((BlockIO *) _ssGetBlockIO(S))->B_1_10_0)) != NO_ZCEVENT)) {
      /* MATLABFcn: '<S3>/MATLAB Fcn' */
      /* Call into Simulink to run the Matlab Fcn block. */
      ssCallAccelRunBlock(S, 0, 0, SS_CALL_MDL_OUTPUTS);
      ((D_Work *) ssGetRootDWork(S))->TriggeredSubsystem_SubsysRanBC = 4;
    }
  }

  /* Scope: '<Root>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 1, 23, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_1_25_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_10;
    ((BlockIO *) _ssGetBlockIO(S))->B_1_28_0 = (((Parameters *)
      ssGetDefaultParam(S))->P_9 - ((BlockIO *) _ssGetBlockIO(S))->B_1_25_0 *
      ((BlockIO *) _ssGetBlockIO(S))->B_0_0_0[0]) * ((BlockIO *) _ssGetBlockIO(S))
      ->B_0_0_0[1];
    ((BlockIO *) _ssGetBlockIO(S))->B_1_29_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_11 * ((BlockIO *) _ssGetBlockIO(S))->B_1_28_0;
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  ((BlockIO *) _ssGetBlockIO(S))->B_1_30_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_14*((ContinuousStates *) ssGetContStates(S))->TransferFcn_CSTATE;

  /* Integrator: '<Root>/Integrator' */
  ((BlockIO *) _ssGetBlockIO(S))->B_1_31_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE_h;

  /* Scope: '<Root>/Scope1' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 1, 32, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_1_35_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_19 * ((BlockIO *) _ssGetBlockIO(S))->B_1_25_0 + ((Parameters *)
      ssGetDefaultParam(S))->P_18;
    ((BlockIO *) _ssGetBlockIO(S))->B_1_36_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_20;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_1_38_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_21 * ((BlockIO *) _ssGetBlockIO(S))->B_1_31_0 + ((BlockIO *)
    _ssGetBlockIO(S))->B_1_36_0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES

static void mdlDerivatives(SimStruct *S)
{
  /* Derivatives for Integrator: '<S9>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE = ((BlockIO *)
      _ssGetBlockIO(S))->B_1_35_0;
  }

  /* Derivatives for Integrator: '<S15>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_m = ((BlockIO *)
      _ssGetBlockIO(S))->B_1_38_0;
  }

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  {
    ((StateDerivatives *) ssGetdX(S))->TransferFcn_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_12)*((ContinuousStates *) ssGetContStates(S))
      ->TransferFcn_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->TransferFcn_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_13*((BlockIO *) _ssGetBlockIO(S))->B_1_29_0;
  }

  /* Derivatives for Integrator: '<Root>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_h = ((BlockIO *)
      _ssGetBlockIO(S))->B_1_30_0;
  }
}

/* ZeroCrossings for root system: '<Root>' */
#define MDL_ZERO_CROSSINGS

static void mdlZeroCrossings(SimStruct *S)
{
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))->Abs_AbsZc_ZC = ((BlockIO *)
    _ssGetBlockIO(S))->B_1_0_0;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
    ->RelationalOperator_RelopInput_ZC = ((BlockIO *) _ssGetBlockIO(S))->B_1_1_0
    - ((BlockIO *) _ssGetBlockIO(S))->B_1_2_0;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))->Saturation_UprLim_ZC =
    ((BlockIO *) _ssGetBlockIO(S))->B_1_9_0 - ((Parameters *) ssGetDefaultParam
    (S))->P_3;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))->Saturation_LwrLim_ZC =
    ((BlockIO *) _ssGetBlockIO(S))->B_1_9_0 - ((Parameters *) ssGetDefaultParam
    (S))->P_4;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))->Abs_AbsZc_ZC_n = ((BlockIO *)
    _ssGetBlockIO(S))->B_1_11_0;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
    ->RelationalOperator_RelopInput_ZC_c = ((BlockIO *) _ssGetBlockIO(S))
    ->B_1_12_0 - ((BlockIO *) _ssGetBlockIO(S))->B_1_13_0;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))->TriggeredSubsystem_Trig_ZC =
    ((BlockIO *) _ssGetBlockIO(S))->B_1_10_0;
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{
  /* checksum */
  ssSetChecksumVal(S, 0, 780630147U);
  ssSetChecksumVal(S, 1, 2506018965U);
  ssSetChecksumVal(S, 2, 3382245016U);
  ssSetChecksumVal(S, 3, 1270709113U);

  /* options */
  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);

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
  _ssSetDefaultParam(S, (real_T *) &rtDefaultParameters);

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* mdlInitializeSampleTimes function (used to set up function-call connections) */
static void mdlInitializeSampleTimes(SimStruct *S)
{
}

/* Empty mdlTerminate function (never called) */
static void mdlTerminate(SimStruct *S)
{
}

/* MATLAB MEX Glue */
#include "simulink.c"
