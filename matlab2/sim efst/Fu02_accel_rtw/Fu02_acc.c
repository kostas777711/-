/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) Accelerator product.
 */

/*
 * Real-Time Workshop code generation for Simulink model "Fu02_acc.mdl".
 *
 * Model Version                        : 1.8
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Tue Feb 12 16:10:37 2008
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Tue Feb 12 16:10:37 2008
 */

#include <math.h>
#include <string.h>
#include "Fu02_acc.h"
#include "Fu02_acc_private.h"
#include <stdio.h>
#include "simstruc.h"

#define CodeFormat                      S-Function
#define AccDefine1                      Accelerator_S-Function

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;

/* ZeroCrossings for trigger system:   
 *   '<S4>/Triggered Subsystem'
 *   '<S5>/Triggered Subsystem'
 *   '<S6>/Triggered Subsystem'
 */
void Fu02_Triggered_Subsystem_ZC(SimStruct *S, real_T fu0,
 rtNSZC_Fu02_Triggered_Subsystem *localNSZC)
{
  /* SubSystem Block: <S4>/Triggered Subsystem */
  localNSZC->Triggered_a_NSZC = fu0;
}

/* Output and update for trigger system:   
 *   '<S4>/Triggered Subsystem'
 *   '<S5>/Triggered Subsystem'
 *   '<S6>/Triggered Subsystem'
 */
void Fu02_Triggered_Subsystem(SimStruct *S, int_T tid, real_T fu0, real_T fu1,
 rtB_Fu02_Triggered_Subsystem *localB, rtZCE_Fu02_Triggered_Subsystem *localZCE)
{
  if (ssIsMajorTimeStep(S)) {
    ZCEventType trigEvent;

    if (ssIsContinuousTask(S, tid)) {   /* Sample time: [0.0, 0.0] */
      trigEvent = rt_ZCFcn(RISING_ZERO_CROSSING, &(localZCE->Triggered_a_ZCE),
        fu0);
    } else {
      trigEvent = NO_ZCEVENT;
    }
    /* conditionally execute */
    if (trigEvent && ssIsSampleHit(S, 1, tid)) {

      /* Inport: '<S7>/In1' */
      localB->In1 = fu1;
    }
  }
}

/* ZeroCrossings for trigger system:   
 *   '<S4>/Triggered Subsystem1'
 *   '<S5>/Triggered Subsystem1'
 *   '<S6>/Triggered Subsystem1'
 */
void Fu02_Triggered_Subsystem1_ZC(SimStruct *S, real_T fu0,
 rtNSZC_Fu02_Triggered_Subsystem1 *localNSZC)
{
  /* SubSystem Block: <S4>/Triggered Subsystem1 */
  localNSZC->Triggered_b_NSZC = fu0;
}

/* Output and update for trigger system:   
 *   '<S4>/Triggered Subsystem1'
 *   '<S5>/Triggered Subsystem1'
 *   '<S6>/Triggered Subsystem1'
 */
void Fu02_Triggered_Subsystem1(SimStruct *S, int_T tid, real_T fu0, real_T fu1,
 rtB_Fu02_Triggered_Subsystem1 *localB, rtZCE_Fu02_Triggered_Subsystem1
 *localZCE)
{
  if (ssIsMajorTimeStep(S)) {
    ZCEventType trigEvent;

    if (ssIsContinuousTask(S, tid)) {   /* Sample time: [0.0, 0.0] */
      trigEvent = rt_ZCFcn(FALLING_ZERO_CROSSING, &(localZCE->Triggered_b_ZCE),
        fu0);
    } else {
      trigEvent = NO_ZCEVENT;
    }
    /* conditionally execute */
    if (trigEvent && ssIsSampleHit(S, 1, tid)) {

      /* Inport: '<S8>/In1' */
      localB->In1 = fu1;
    }
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  /* simstruct variables */
  Fu02_BlockIO *Fu02_B = (Fu02_BlockIO *) _ssGetBlockIO(S);
  Fu02_ContinuousStates *Fu02_X = (Fu02_ContinuousStates*) ssGetContStates(S);
  Fu02_D_Work *Fu02_DWork = (Fu02_D_Work *) ssGetRootDWork(S);
  Fu02_PrevZCSigStates *Fu02_PrevZCSigState = (Fu02_PrevZCSigStates *)
    _ssGetPrevZCSigState(S);
  Fu02_Parameters *Fu02_P = (Fu02_Parameters *) ssGetDefaultParam(S);

  /* local block i/o variables */
  real_T rtb_Reshape;
  real_T rtb_Math_Function;

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Gain: '<S21>/Gain'
     *
     * Regarding '<S21>/Gain':
     *   Gain value: Fu02_P->Gain_Gain
     */
    Fu02_B->Gain = Fu02_X->Integrator_a_CSTATE * Fu02_P->Gain_Gain;

    /* Abs: '<S21>/Abs' */
    if (ssIsMajorTimeStep(S)) {
      Fu02_DWork->Abs_MODE = Fu02_B->Gain >= 0.0;
    }
    Fu02_B->Abs = (Fu02_DWork->Abs_MODE)? Fu02_B->Gain:-(Fu02_B->Gain);
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Constant: '<S21>/Constant' */
    Fu02_B->Constant_a = Fu02_P->Constant_a_Value;

    /* RelationalOperator: '<S21>/Relational Operator' */
    if (ssIsMajorTimeStep(S)) {
      Fu02_DWork->Relational_Operator_MODE = (int_T)(Fu02_B->Abs >=
        Fu02_B->Constant_a);
    }
    Fu02_B->Relational_Operator = (real_T)(Fu02_DWork->Relational_Operator_MODE);
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Math: '<S21>/Math Function'
     *
     * Regarding '<S21>/Math Function':
     *   Op: rem
     */

    {
      real_T y;
      real_T yDiv;
      real_T z;
      yDiv = Fu02_B->Gain / Fu02_B->Constant_a;
      y = floor(fabs(yDiv));
      z = ((yDiv < 0.0) ? -y : y);
      if (Fu02_B->Constant_a == 0.0) {
        rtb_Math_Function = rtNaN;
      } else {
        rtb_Math_Function = Fu02_B->Gain - Fu02_B->Constant_a * z;
      }
    }

    /* InitialCondition: '<S21>/IC' */
    if ( Fu02_DWork->IC_FirstOutputTime == rtMinusInf ) {
      Fu02_DWork->IC_FirstOutputTime = ssGetTaskTime(S,tid);
    }
    if ( Fu02_DWork->IC_FirstOutputTime == ssGetTaskTime(S,tid) ) {
      Fu02_B->IC = Fu02_P->IC_Value;
    } else {
      Fu02_B->IC = rtb_Math_Function;
    }

    /* Integrator: '<S21>/Integrator' */
    if (ssIsMajorTimeStep(S)) {
      ZCEventType zcEvent;
      boolean_T resetIntg = FALSE;

      /* evaluate zero-crossings */
      zcEvent = ((ZCEventType) (Fu02_B->Relational_Operator &&
        !Fu02_PrevZCSigState->Integrator_a_ZCE));
      Fu02_PrevZCSigState->Integrator_a_ZCE = (ZCSigState)
        Fu02_B->Relational_Operator;
      if (zcEvent|| Fu02_DWork->Integrator_a_IWORK.IcNeedsLoading) {
        resetIntg = TRUE;
        Fu02_X->Integrator_a_CSTATE = Fu02_B->IC;
      }

      if (resetIntg) {
        ssSetSolverNeedsReset(S);
        ssSetBlkStateChange(S);
      }

      Fu02_DWork->Integrator_a_IWORK.IcNeedsLoading = 0;
    }
    Fu02_B->temp15 = Fu02_X->Integrator_a_CSTATE;

    /* Level2 S-Function Block: <S20>/Inherit Shape1 (scominhshape) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 7, 7, SS_CALL_MDL_OUTPUTS);

    /* Fcn: '<S3>/sin'
     *
     * Regarding '<S3>/sin':
     *   Expression: Ac*cos(u[1]*pi2+Ph)
     */
    Fu02_B->temp15 = 1.0 * cos( Fu02_B->temp15 * 6.2831853071795862E+000 +
      0.0);

    /* Level2 S-Function Block: <S15>/Inherit Shape1 (scominhshape) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 7, 9, SS_CALL_MDL_OUTPUTS);

    /* Sin: '<Root>/Sampling' */

    Fu02_B->Sampling = Fu02_P->Sampling_Amp *
      sin(Fu02_P->Sampling_Freq * ssGetTaskTime(S,tid) + Fu02_P->Sampling_Phase)
      + Fu02_P->Sampling_Bias;
  }

  /* SubSystem: '<S4>/Triggered Subsystem' */
  Fu02_Triggered_Subsystem(S, tid, Fu02_B->Sampling, Fu02_B->Inherit_Shape1_b,
   &Fu02_B->Triggered_a, &Fu02_PrevZCSigState->Triggered_a);

  /* SubSystem: '<S4>/Triggered Subsystem1' */
  Fu02_Triggered_Subsystem1(S, tid, Fu02_B->Sampling, Fu02_B->Triggered_a.In1,
   &Fu02_B->Triggered_b, &Fu02_PrevZCSigState->Triggered_b);

  /* SubSystem: '<S5>/Triggered Subsystem' */
  Fu02_Triggered_Subsystem(S, tid, Fu02_B->Sampling, Fu02_B->Triggered_b.In1,
   &Fu02_B->Triggered_c, &Fu02_PrevZCSigState->Triggered_c);

  /* SubSystem: '<S5>/Triggered Subsystem1' */
  Fu02_Triggered_Subsystem1(S, tid, Fu02_B->Sampling, Fu02_B->Triggered_c.In1,
   &Fu02_B->Triggered_d, &Fu02_PrevZCSigState->Triggered_d);

  /* SubSystem: '<S6>/Triggered Subsystem' */
  Fu02_Triggered_Subsystem(S, tid, Fu02_B->Sampling, Fu02_B->Triggered_d.In1,
   &Fu02_B->Triggered_e, &Fu02_PrevZCSigState->Triggered_e);

  /* SubSystem: '<S6>/Triggered Subsystem1' */
  Fu02_Triggered_Subsystem1(S, tid, Fu02_B->Sampling, Fu02_B->Triggered_e.In1,
   &Fu02_B->Triggered_f, &Fu02_PrevZCSigState->Triggered_f);

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Fcn: '<S1>/Fcn'
     *
     * Regarding '<S1>/Fcn':
     *   Expression: (1000/(2*pi))*acos( (u(1)+u(3)) / (2*u(2)) )
     */
    Fu02_B->Fcn = 1000.0 / ( 2.0 * 3.1415926535897931E+000) * acos( (
      Fu02_B->Triggered_f.In1 +
      Fu02_B->Triggered_b.In1 ) / ( 2.0 * Fu02_B->Triggered_d.In1 ) );

    /* Display: '<Root>/Display' */
    /* Call into Simulink for Display */
    ssCallAccelRunBlock(S, 7, 18, SS_CALL_MDL_OUTPUTS);

    /* Constant: '<Root>/Constant1' */
    Fu02_B->Constant1 = Fu02_P->Constant1_Value;
  }

  /* SubSystem: '<Root>/Triggered Subsystem' */

  /* Output and update for trigger system: '<Root>/Triggered Subsystem' */
  {
    /* simstruct variables */
    Fu02_BlockIO *Fu02_B = (Fu02_BlockIO *) _ssGetBlockIO(S);
    Fu02_PrevZCSigStates *Fu02_PrevZCSigState = (Fu02_PrevZCSigStates *)
      _ssGetPrevZCSigState(S);

    if (ssIsMajorTimeStep(S)) {
      ZCEventType trigEvent;

      if (ssIsContinuousTask(S, tid)) { /* Sample time: [0.0, 0.0] */
        trigEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
          &(Fu02_PrevZCSigState->Triggered_g_ZCE), Fu02_B->Sampling);
      } else {
        trigEvent = NO_ZCEVENT;
      }
      /* conditionally execute */
      if (trigEvent && ssIsSampleHit(S, 1, tid)) {

        /* MATLABFcn: '<S2>/MATLAB Fcn' */
        /* Call into Simulink to run the Matlab Fcn block. */
        ssCallAccelRunBlock(S, 6, 0, SS_CALL_MDL_OUTPUTS);
      }
    }
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Display: '<Root>/Display1' */
    /* Call into Simulink for Display */
    ssCallAccelRunBlock(S, 7, 21, SS_CALL_MDL_OUTPUTS);

    /* Constant: '<Root>/Constant' */
    Fu02_B->Constant_b = Fu02_P->Constant_b_Value;

    /* Scope: '<S1>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 7, 23, SS_CALL_MDL_OUTPUTS);
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Integrator: '<Root>/Integrator' */
    Fu02_B->temp15 = Fu02_X->Integrator_b_CSTATE;
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Sum: '<Root>/Sum' */
    Fu02_B->Sum_a = - Fu02_B->Fcn + Fu02_B->Constant_b;

    /* Constant: '<S3>/Carrier frequency1' */
    Fu02_B->Carrier_frequency1 = Fu02_P->Carrier_frequency1_Value;
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* S-Function Block: <S14>/Reshape */
    rtb_Reshape = Fu02_B->temp15;

    /* Sum: '<S3>/Sum' incorporates:
     *   Gain: '<S3>/Sensitivity'
     *
     * Regarding '<S3>/Sensitivity':
     *   Gain value: Fu02_P->Sensitivity_Gain
     */
    Fu02_B->Sum_b = (rtb_Reshape * Fu02_P->Sensitivity_Gain)
      + Fu02_B->Carrier_frequency1;
  }
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE
static void mdlUpdate(SimStruct *S, int_T tid)
{
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES
static void mdlDerivatives(SimStruct *S)
{
  /* simstruct variables */
  Fu02_BlockIO *Fu02_B = (Fu02_BlockIO *) _ssGetBlockIO(S);
  Fu02_StateDerivatives *Fu02_Xdot = (Fu02_StateDerivatives*) ssGetdX(S);

  /* Integrator Block: <S21>/Integrator */
  {

    Fu02_Xdot->Integrator_a_CSTATE = Fu02_B->Sum_b;
  }

  /* Integrator Block: <Root>/Integrator */
  {

    Fu02_Xdot->Integrator_b_CSTATE = Fu02_B->Sum_a;
  }
}

/* ZeroCrossings for root system: '<Root>' */
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings(SimStruct *S)
{
  /* simstruct variables */
  Fu02_BlockIO *Fu02_B = (Fu02_BlockIO *) _ssGetBlockIO(S);
  Fu02_NonsampledZCs *Fu02_NonsampledZC = (Fu02_NonsampledZCs *)
    ssGetNonsampledZCs(S);

  /* Abs Block: <S21>/Abs */
  Fu02_NonsampledZC->Abs_NSZC = Fu02_B->Gain;

  /* RelationalOperator Block: <S21>/Relational Operator */
  Fu02_NonsampledZC->Relational_Operator_NSZC = Fu02_B->Abs - Fu02_B->Constant_a;

  /* SubSystem Block: <S4>/Triggered Subsystem */
  /* compute zero crossings */
  Fu02_Triggered_Subsystem_ZC(S, Fu02_B->Sampling,
   &Fu02_NonsampledZC->Triggered_a);

  /* SubSystem Block: <S4>/Triggered Subsystem1 */
  /* compute zero crossings */
  Fu02_Triggered_Subsystem1_ZC(S, Fu02_B->Sampling,
   &Fu02_NonsampledZC->Triggered_b);

  /* SubSystem Block: <S5>/Triggered Subsystem */
  /* compute zero crossings */
  Fu02_Triggered_Subsystem_ZC(S, Fu02_B->Sampling,
   &Fu02_NonsampledZC->Triggered_c);

  /* SubSystem Block: <S5>/Triggered Subsystem1 */
  /* compute zero crossings */
  Fu02_Triggered_Subsystem1_ZC(S, Fu02_B->Sampling,
   &Fu02_NonsampledZC->Triggered_d);

  /* SubSystem Block: <S6>/Triggered Subsystem */
  /* compute zero crossings */
  Fu02_Triggered_Subsystem_ZC(S, Fu02_B->Sampling,
   &Fu02_NonsampledZC->Triggered_e);

  /* SubSystem Block: <S6>/Triggered Subsystem1 */
  /* compute zero crossings */
  Fu02_Triggered_Subsystem1_ZC(S, Fu02_B->Sampling,
   &Fu02_NonsampledZC->Triggered_f);

  /* SubSystem Block: <Root>/Triggered Subsystem */
  /* compute zero crossings */

  /* ZeroCrossings for trigger system: '<Root>/Triggered Subsystem' */
  {
    /* simstruct variables */
    Fu02_BlockIO *Fu02_B = (Fu02_BlockIO *) _ssGetBlockIO(S);
    Fu02_NonsampledZCs *Fu02_NonsampledZC = (Fu02_NonsampledZCs *)
      ssGetNonsampledZCs(S);

    /* SubSystem Block: <Root>/Triggered Subsystem */
    Fu02_NonsampledZC->Triggered_g_NSZC = Fu02_B->Sampling;
  }
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{

  /* checksum */
  ssSetChecksumVal(S, 0, 2883921424U);
  ssSetChecksumVal(S, 1, 1033910958U);
  ssSetChecksumVal(S, 2, 4078516784U);
  ssSetChecksumVal(S, 3, 921651127U);

  /* options */
  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);

  /* Accelerator check memory map size match for DWork */
  if (ssGetSizeofDWork(S) != sizeof(Fu02_D_Work)) {
    ssSetErrorStatus(S,"Unexpected error: Internal DWork sizes do "
     "not match for accelerator mex file.");
  }

  /* Accelerator check memory map size match for BlockIO */
  if (ssGetSizeofGlobalBlockIO(S) != sizeof(Fu02_BlockIO)) {
    ssSetErrorStatus(S,"Unexpected error: Internal BlockIO sizes do "
     "not match for accelerator mex file.");
  }

  /* model parameters */
  _ssSetDefaultParam(S, (real_T *) &Fu02_DefaultParameters);

  /* non-finites */
  rtInf = mxGetInf();
  rtMinusInf = -mxGetInf();
  rtNaN = mxGetNaN();
}

/* Empty mdlInitializeSampleTimes function (never called) */
static void mdlInitializeSampleTimes(SimStruct *S) { }

/* Empty mdlTerminate function (never called) */
static void mdlTerminate(SimStruct *S) { }

/* MATLAB MEX Glue */
#include "simulink.c"

