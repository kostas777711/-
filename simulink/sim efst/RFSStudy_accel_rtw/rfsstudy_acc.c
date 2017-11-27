/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) Accelerator product.
 */

/*
 * Real-Time Workshop code generation for Simulink model "rfsstudy_acc.mdl".
 *
 * Model Version                        : 1.44
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Wed Mar 11 12:07:04 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Wed Mar 11 12:07:05 2009
 */

#include <math.h>
#include <string.h>
#include "rfsstudy_acc.h"
#include "rfsstudy_acc_private.h"
#include <stdio.h>
#include "simstruc.h"

#define CodeFormat                      S-Function
#define AccDefine1                      Accelerator_S-Function

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;

/* Initial conditions for atomic system: '<Root>/Spectrum Scope1' */
void rfsstudy_Spectrum_Scope_Init(SimStruct *S)
{
  /* simstruct variables */
  rfsstudy_D_Work *rfsstudy_DWork = (rfsstudy_D_Work *) ssGetRootDWork(S);
  rfsstudy_Parameters *rfsstudy_P = (rfsstudy_Parameters *) ssGetDefaultParam(S);

  /* Level1 S-Function Block: <S4>/Frame Scope (sdspfscope2) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 1, 0, SS_CALL_MDL_INITIALIZE_CONDITIONS);

  /* DSP Blockset Buffer/Unbuffer (sdsprebuff2) - '<S8>/Buffer' */

  /* Copy ICs into circular buffer */
  {
    const int_T bufLenBytes = 4096 * sizeof(real_T);
    byte_T *circBufPtr = (byte_T *)&rfsstudy_DWork->Buffer_CircBuff[0];
    const byte_T *icPtr = (const byte_T *)&rfsstudy_P->Buffer_IC;
    int_T i = 1;
    while (i-- > 0) {
      MWDSP_CopyScalarICs(circBufPtr, icPtr, 2048, sizeof(real_T));
      circBufPtr += bufLenBytes;
    }
  }

  /* Initialize DWork for IN_BUF_PTR and OUT_BUF_PTR */
  {
    *&rfsstudy_DWork->Buffer_IN_BUF_PTR = (void *)( (byte_T
      *)&rfsstudy_DWork->Buffer_CircBuff[0] + 2048 * sizeof(real_T) );
    *&rfsstudy_DWork->Buffer_OUT_BUF_PTR = (void *)( (byte_T
      *)&rfsstudy_DWork->Buffer_CircBuff[0] + 64 * sizeof(real_T) );
  }

  /* Calculate shiftPerElement
   * (assuming that number of bits
   *  per element is power of two)
   */
  {
    int_T expn;
    const double frac = frexp((double)sizeof(real_T), &expn);
    *&rfsstudy_DWork->Buffer_ShiftPerElem = expn - 1;
    UNUSED_ARG(frac);
  }

  /* DSP Blockset Filter Implementation (sdspfilter) - '<S9>/Digital Filter' */
  {
    real_T *statePtr = (real_T *) &rfsstudy_DWork->Digital_Filter_FILT_STATES[0];
    /* Scalar expansion of ICs with extra zero element per channel */
    int_T chanCount = 2048;
    while (chanCount--) {
      *statePtr++ = *(const real_T *)&rfsstudy_P->Digital_Filter_ICRTP;
      *statePtr++ = 0.0;
    }
  }
}

/* Outputs for atomic system: '<Root>/Spectrum Scope1' */
void rfsstudy_Spectrum_Scope(SimStruct *S, int_T tid)
{
  /* simstruct variables */
  rfsstudy_BlockIO *rfsstudy_B = (rfsstudy_BlockIO *) _ssGetBlockIO(S);
  rfsstudy_D_Work *rfsstudy_DWork = (rfsstudy_D_Work *) ssGetRootDWork(S);
  rfsstudy_Parameters *rfsstudy_P = (rfsstudy_Parameters *) ssGetDefaultParam(S);

  /* local block i/o variables */
  creal_T rtb_FFT[2048];
  real_T rtb_S_Function;
  real_T rtb_Math_Function1;
  real_T rtb_Window_o1[2048];
  real_T rtb_Zero_Pad[2048];

  if (ssIsSampleHit(S, 3, tid)) {       /* Sample time: [1.9840000000000002E-001, 0.0] */

    /* Level1 S-Function Block: <S4>/Frame Scope (sdspfscope2) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 1, 0, SS_CALL_MDL_OUTPUTS);
  }

  /* DSP Blockset Buffer/Unbuffer (sdsprebuff2) - '<S8>/Buffer' */
  {
    /* Copy input samples to buffer */
    if (ssIsSampleHit(S, 2, tid)) {
      MWDSP_Buf_CopyScalar_OL_1ch((const byte_T *)&rfsstudy_B->Gain1, (byte_T
        **)&rfsstudy_DWork->Buffer_IN_BUF_PTR, (byte_T
        *)&rfsstudy_DWork->Buffer_CircBuff[0],
       *&rfsstudy_DWork->Buffer_ShiftPerElem, 4096 * sizeof(real_T));
    }

    /* Copy output samples from buffer */
    if (ssIsSampleHit(S, 3, tid)) {
      MWDSP_Buf_OutputFrame_1ch((byte_T *)&rfsstudy_B->Buffer[0], (byte_T
        **)&rfsstudy_DWork->Buffer_OUT_BUF_PTR, (byte_T
        *)&rfsstudy_DWork->Buffer_CircBuff[0],
       *&rfsstudy_DWork->Buffer_ShiftPerElem, 4096 * sizeof(real_T) ,2048, 64 *
       sizeof(real_T));
    }
  }

  if (ssIsSampleHit(S, 3, tid)) {       /* Sample time: [1.9840000000000002E-001, 0.0] */

    /* DSP Blockset Window (sdspwindow2) - '<S9>/Window' */

    {
      int_T i;
      for (i=0; i<2048; i++) {
        rtb_Window_o1[i] = rfsstudy_B->Buffer[i] * rfsstudy_B->Window_o2[i];
      }
    }

    /* DSP Blockset Pad (sdsppad) - '<S10>/Zero Pad' */
    /* Input dimensions: [2048 x 1], output dimensions: [2048 x 1] */
    memcpy( &rtb_Zero_Pad[0], &rtb_Window_o1[0], (2048 * sizeof(real_T)) );

    /* DSP Blockset FFT (sdspfft2) - '<S10>/FFT' */
    /* Real input, 1 channels, 2048 rows, linear output order */
    /* Interleave data to prepare for real-data algorithms: */
    MWDSP_FFTInterleave_BR_D(&rtb_FFT[0], &rtb_Zero_Pad[0], 1, 2048);
    /* Apply half-length algorithm to single real signal: */
    {
      creal_T *lastCol = &rtb_FFT[0];   /* Point to last column of input */
      MWDSP_R2DIT_TBLS_Z(lastCol, 1, 2048, 1024,
       &rfsstudy_P->FFT_TwiddleTable[0], 2, 0); /* Radix-2 DIT FFT using TableSpeed twiddle computation */
      MWDSP_DblLen_TBL_Z(lastCol, 2048, &rfsstudy_P->FFT_TwiddleTable[0], 1);
    }

    /* Math: '<S10>/Magnitude Squared'
     *
     * Regarding '<S10>/Magnitude Squared':
     *   Op: magnitude^2
     */

    {
      int_T i1;

      const creal_T *u0 = &rtb_FFT[0];
      real_T *y0 = &rfsstudy_B->Magnitude_Squared[0];

      for (i1=0; i1 < 2048; i1++) {
        y0[i1] = u0[i1].re * u0[i1].re + u0[i1].im * u0[i1].im;
      }
    }

    /* DSP Blockset Filter Implementation (sdspfilter) - '<S9>/Digital Filter' */
    /* Filter algorithm: FIR Direct-Form (double precision floating-point) */
    /* Complexities: input - real, num coeffs - real */
    /* Implementing filter algorithm */
    MWDSP_FIR_DF_DD(&rfsstudy_B->Magnitude_Squared[0],
     &rfsstudy_B->Digital_Filter[0],
     &rfsstudy_DWork->Digital_Filter_FILT_STATES[0],
     &rfsstudy_DWork->Digital_Filter_DF_INDX, 2, 1, 2048,
     &rfsstudy_P->Digital_Filter_RTP1COEFF[0], 1);

    /* S-Function Block (sdotproduct): <S13>/S-Function */
    rtb_S_Function = rfsstudy_B->Window_o2[0] * rfsstudy_B->Window_o2[0];
    {
      int_T i1;

      const real_T *u0 = &rfsstudy_B->Window_o2[1];
      const real_T *u1 = &rfsstudy_B->Window_o2[1];

      for (i1=0; i1 < 2047; i1++) {
        rtb_S_Function += u0[i1] * u1[i1];
      }
    }

    /* Math: '<S11>/Math Function1'
     *
     * Regarding '<S11>/Math Function1':
     *   Op: reciprocal
     */

    rtb_Math_Function1 = 1.0/(rtb_S_Function);

    /* Product: '<S9>/Product2' */
    {
      int_T i1;

      const real_T *u0 = &rfsstudy_B->Digital_Filter[0];
      real_T *y0 = &rfsstudy_B->Product2[0];

      for (i1=0; i1 < 2048; i1++) {
        y0[i1] = u0[i1] * rtb_Math_Function1;
      }
    }
  }
}

/* Update for atomic system: '<Root>/Spectrum Scope1' */
void rfsstudy_Spectrum_Scope_Update(SimStruct *S, int_T tid)
{

  if (ssIsSampleHit(S, 3, tid)) {       /* Sample time: [1.9840000000000002E-001, 0.0] */

    /* Level1 S-Function Block: <S4>/Frame Scope (sdspfscope2) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 1, 0, SS_CALL_MDL_UPDATE);
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  /* simstruct variables */
  rfsstudy_BlockIO *rfsstudy_B = (rfsstudy_BlockIO *) _ssGetBlockIO(S);
  rfsstudy_ContinuousStates *rfsstudy_X = (rfsstudy_ContinuousStates*)
    ssGetContStates(S);
  rfsstudy_D_Work *rfsstudy_DWork = (rfsstudy_D_Work *) ssGetRootDWork(S);
  rfsstudy_PrevZCSigStates *rfsstudy_PrevZCSigState = (rfsstudy_PrevZCSigStates
    *) _ssGetPrevZCSigState(S);
  rfsstudy_Parameters *rfsstudy_P = (rfsstudy_Parameters *) ssGetDefaultParam(S);

  /* local block i/o variables */
  real_T rtb_Sine_Wave;
  real_T rtb_Reshape_a;
  real_T rtb_Reshape_b;
  real_T rtb_White_Noise;
  real_T rtb_temp40;

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Constant: '<Root>/Fin' */
    rfsstudy_B->Fin = rfsstudy_P->Fin_Value;

    /* Display: '<Root>/Display' */
    /* Call into Simulink for Display */
    ssCallAccelRunBlock(S, 2, 1, SS_CALL_MDL_OUTPUTS);
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Gain: '<S22>/Gain'
     *
     * Regarding '<S22>/Gain':
     *   Gain value: rfsstudy_P->Gain_a_Gain
     */
    rfsstudy_B->Gain_a = rfsstudy_X->Integrator_a_CSTATE *
      rfsstudy_P->Gain_a_Gain;

    /* Abs: '<S22>/Abs' */
    if (ssIsMajorTimeStep(S)) {
      rfsstudy_DWork->Abs_a_MODE = rfsstudy_B->Gain_a >= 0.0;
    }
    rfsstudy_B->Abs_a = (rfsstudy_DWork->Abs_a_MODE)?
      rfsstudy_B->Gain_a:-(rfsstudy_B->Gain_a);
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Constant: '<S22>/Constant' */
    rfsstudy_B->Constant_a = rfsstudy_P->Constant_a_Value;

    /* RelationalOperator: '<S22>/Relational Operator' */
    if (ssIsMajorTimeStep(S)) {
      rfsstudy_DWork->Relational_Operator_a_MODE = (int_T)(rfsstudy_B->Abs_a >=
        rfsstudy_B->Constant_a);
    }
    rfsstudy_B->Relational_Operator_a =
      (real_T)(rfsstudy_DWork->Relational_Operator_a_MODE);
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Math: '<S22>/Math Function'
     *
     * Regarding '<S22>/Math Function':
     *   Op: rem
     */

    {
      real_T y;
      real_T yDiv;
      real_T z;
      yDiv = rfsstudy_B->Gain_a / rfsstudy_B->Constant_a;
      y = floor(fabs(yDiv));
      z = ((yDiv < 0.0) ? -y : y);
      if (rfsstudy_B->Constant_a == 0.0) {
        rtb_temp40 = rtNaN;
      } else {
        rtb_temp40 = rfsstudy_B->Gain_a - rfsstudy_B->Constant_a * z;
      }
    }

    /* InitialCondition: '<S22>/IC' */
    if ( rfsstudy_DWork->IC_a_FirstOutputTime == rtMinusInf ) {
      rfsstudy_DWork->IC_a_FirstOutputTime = ssGetTaskTime(S,tid);
    }
    if ( rfsstudy_DWork->IC_a_FirstOutputTime == ssGetTaskTime(S,tid) ) {
      rfsstudy_B->IC_a = rfsstudy_P->IC_a_Value;
    } else {
      rfsstudy_B->IC_a = rtb_temp40;
    }

    /* Integrator: '<S22>/Integrator' */
    if (ssIsMajorTimeStep(S)) {
      ZCEventType zcEvent;
      boolean_T resetIntg = FALSE;

      /* evaluate zero-crossings */
      zcEvent = ((ZCEventType) (rfsstudy_B->Relational_Operator_a &&
        !rfsstudy_PrevZCSigState->Integrator_a_ZCE));
      rfsstudy_PrevZCSigState->Integrator_a_ZCE = (ZCSigState)
        rfsstudy_B->Relational_Operator_a;
      if (zcEvent|| rfsstudy_DWork->Integrator_a_IWORK.IcNeedsLoading) {
        resetIntg = TRUE;
        rfsstudy_X->Integrator_a_CSTATE = rfsstudy_B->IC_a;
      }

      if (resetIntg) {
        ssSetSolverNeedsReset(S);
        ssSetBlkStateChange(S);
      }

      rfsstudy_DWork->Integrator_a_IWORK.IcNeedsLoading = 0;
    }
    rfsstudy_B->temp25 = rfsstudy_X->Integrator_a_CSTATE;

    /* Level2 S-Function Block: <S21>/Inherit Shape1 (scominhshape) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 2, 9, SS_CALL_MDL_OUTPUTS);

    /* Fcn: '<S5>/sin'
     *
     * Regarding '<S5>/sin':
     *   Expression: Ac*cos(u[1]*pi2+Ph)
     */
    rfsstudy_B->temp25 = 1.0 * cos( rfsstudy_B->temp25 *
      6.2831853071795862E+000 + 0.0);

    /* Level2 S-Function Block: <S16>/Inherit Shape1 (scominhshape) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 2, 11, SS_CALL_MDL_OUTPUTS);

    /* Sin: '<Root>/Sine Wave1' */

    rtb_temp40 = rfsstudy_P->Sine_Wave1_Amp *
      sin(rfsstudy_P->Sine_Wave1_Freq * ssGetTaskTime(S,tid) +
      rfsstudy_P->Sine_Wave1_Phase) + rfsstudy_P->Sine_Wave1_Bias;

    /* Sum: '<Root>/Sum3' */
    rtb_temp40 = rfsstudy_B->temp25 + rtb_temp40;

    /* Quantizer: '<Root>/Quantizer' */
    {
      real_T yre;
      yre = rfsstudy_P->Quantizer_Interval *
        floor(fabs((rtb_temp40/(rfsstudy_P->Quantizer_Interval))) + 0.5);
      rfsstudy_B->Quantizer = ((rtb_temp40 >= 0.0) ? yre : -yre);
    }
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Constant: '<Root>/Fs' */
    rfsstudy_B->Fs = rfsstudy_P->Fs_Value;
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Gain: '<S31>/Gain'
     *
     * Regarding '<S31>/Gain':
     *   Gain value: rfsstudy_P->Gain_b_Gain
     */
    rfsstudy_B->Gain_b = rfsstudy_X->Integrator_b_CSTATE *
      rfsstudy_P->Gain_b_Gain;

    /* Abs: '<S31>/Abs' */
    if (ssIsMajorTimeStep(S)) {
      rfsstudy_DWork->Abs_b_MODE = rfsstudy_B->Gain_b >= 0.0;
    }
    rfsstudy_B->Abs_b = (rfsstudy_DWork->Abs_b_MODE)?
      rfsstudy_B->Gain_b:-(rfsstudy_B->Gain_b);
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Constant: '<S31>/Constant' */
    rfsstudy_B->Constant_b = rfsstudy_P->Constant_b_Value;

    /* RelationalOperator: '<S31>/Relational Operator' */
    if (ssIsMajorTimeStep(S)) {
      rfsstudy_DWork->Relational_Operator_b_MODE = (int_T)(rfsstudy_B->Abs_b >=
        rfsstudy_B->Constant_b);
    }
    rfsstudy_B->Relational_Operator_b =
      (real_T)(rfsstudy_DWork->Relational_Operator_b_MODE);
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Math: '<S31>/Math Function'
     *
     * Regarding '<S31>/Math Function':
     *   Op: rem
     */

    {
      real_T y;
      real_T yDiv;
      real_T z;
      yDiv = rfsstudy_B->Gain_b / rfsstudy_B->Constant_b;
      y = floor(fabs(yDiv));
      z = ((yDiv < 0.0) ? -y : y);
      if (rfsstudy_B->Constant_b == 0.0) {
        rtb_temp40 = rtNaN;
      } else {
        rtb_temp40 = rfsstudy_B->Gain_b - rfsstudy_B->Constant_b * z;
      }
    }

    /* InitialCondition: '<S31>/IC' */
    if ( rfsstudy_DWork->IC_b_FirstOutputTime == rtMinusInf ) {
      rfsstudy_DWork->IC_b_FirstOutputTime = ssGetTaskTime(S,tid);
    }
    if ( rfsstudy_DWork->IC_b_FirstOutputTime == ssGetTaskTime(S,tid) ) {
      rfsstudy_B->IC_b = rfsstudy_P->IC_b_Value;
    } else {
      rfsstudy_B->IC_b = rtb_temp40;
    }

    /* Integrator: '<S31>/Integrator' */
    if (ssIsMajorTimeStep(S)) {
      ZCEventType zcEvent;
      boolean_T resetIntg = FALSE;

      /* evaluate zero-crossings */
      zcEvent = ((ZCEventType) (rfsstudy_B->Relational_Operator_b &&
        !rfsstudy_PrevZCSigState->Integrator_b_ZCE));
      rfsstudy_PrevZCSigState->Integrator_b_ZCE = (ZCSigState)
        rfsstudy_B->Relational_Operator_b;
      if (zcEvent|| rfsstudy_DWork->Integrator_b_IWORK.IcNeedsLoading) {
        resetIntg = TRUE;
        rfsstudy_X->Integrator_b_CSTATE = rfsstudy_B->IC_b;
      }

      if (resetIntg) {
        ssSetSolverNeedsReset(S);
        ssSetBlkStateChange(S);
      }

      rfsstudy_DWork->Integrator_b_IWORK.IcNeedsLoading = 0;
    }
    rfsstudy_B->temp25 = rfsstudy_X->Integrator_b_CSTATE;
  }

  /* Level2 S-Function Block: <S30>/Inherit Shape1 (scominhshape) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 2, 23, SS_CALL_MDL_OUTPUTS);

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Fcn: '<S6>/sin'
     *
     * Regarding '<S6>/sin':
     *   Expression: Ac*cos(u[1]*pi2+Ph)
     */
    rfsstudy_B->temp25 = 1.0 * cos( rfsstudy_B->temp25 *
      6.2831853071795862E+000 + 0.0);
  }

  /* Level2 S-Function Block: <S25>/Inherit Shape1 (scominhshape) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 2, 25, SS_CALL_MDL_OUTPUTS);

  /* SubSystem: '<Root>/FET DSP' */

  /* Output and update for trigger system: '<Root>/FET DSP' */
  {
    /* simstruct variables */
    rfsstudy_BlockIO *rfsstudy_B = (rfsstudy_BlockIO *) _ssGetBlockIO(S);
    rfsstudy_PrevZCSigStates *rfsstudy_PrevZCSigState =
      (rfsstudy_PrevZCSigStates *) _ssGetPrevZCSigState(S);

    if (ssIsMajorTimeStep(S)) {
      ZCEventType trigEvent;

      if (ssIsContinuousTask(S, tid)) { /* Sample time: [0.0, 0.0] */
        trigEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
          &(rfsstudy_PrevZCSigState->FET_DSP_ZCE), rfsstudy_B->Inherit_Shape1_d);
      } else {
        trigEvent = NO_ZCEVENT;
      }
      /* conditionally execute */
      if (trigEvent && ssIsSampleHit(S, 1, tid)) {

        /* MATLABFcn: '<S2>/MATLAB Fcn' */
        /* Call into Simulink to run the Matlab Fcn block. */
        ssCallAccelRunBlock(S, 0, 0, SS_CALL_MDL_OUTPUTS);
      }
    }
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Product: '<Root>/Product' */
    rfsstudy_B->Product = rfsstudy_B->MATLAB_Fcn[0] * rfsstudy_B->MATLAB_Fcn[1];
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Sin: '<Root>/Sine Wave' */

    rtb_Sine_Wave = rfsstudy_P->Sine_Wave_Amp *
      sin(rfsstudy_P->Sine_Wave_Freq * ssGetTaskTime(S,tid) +
      rfsstudy_P->Sine_Wave_Phase) + rfsstudy_P->Sine_Wave_Bias;
  }

  if (ssIsSampleHit(S, 2, tid)) {       /* Sample time: [0.0001, 0.0] */

    /* RandomNumber: '<S1>/White Noise' */
    rtb_White_Noise = rfsstudy_DWork->White_Noise_RWORK.NextOutput;

    /* Gain: '<S1>/Gain'
     *
     * Regarding '<S1>/Gain':
     *   Gain value: rfsstudy_P->Gain_c_Gain
     */
    rfsstudy_B->Gain_c = rtb_White_Noise * rfsstudy_P->Gain_c_Gain;
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Sum: '<Root>/Sum1' incorporates:
     *   Sum: '<Root>/Sum2'
     */
    rfsstudy_B->temp25 = (rfsstudy_B->Fin + rtb_Sine_Wave) + rfsstudy_B->Gain_c;

    /* Scope: '<Root>/Scope1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 2, 33, SS_CALL_MDL_OUTPUTS);
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Gain: '<Root>/Gain1'
     *
     * Regarding '<Root>/Gain1':
     *   Gain value: rfsstudy_P->Gain1_Gain
     */
    rfsstudy_B->Gain1 = rfsstudy_B->Product * rfsstudy_P->Gain1_Gain;
  }

  /* SubSystem: '<Root>/Spectrum Scope1' */
  if (ssIsSampleHit(S, 2, tid) || ssIsSampleHit(S, 3, tid)) {
    rfsstudy_Spectrum_Scope(S, tid);
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Constant: '<S5>/Carrier frequency1' */
    rfsstudy_B->Carrier_frequency1_a = rfsstudy_P->Carrier_frequency1_a_Value;
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* S-Function Block: <S15>/Reshape */
    rtb_Reshape_a = rfsstudy_B->temp25;

    /* Sum: '<S5>/Sum' incorporates:
     *   Gain: '<S5>/Sensitivity'
     *
     * Regarding '<S5>/Sensitivity':
     *   Gain value: rfsstudy_P->Sensitivity_a_Gain
     */
    rfsstudy_B->Sum_a = (rtb_Reshape_a * rfsstudy_P->Sensitivity_a_Gain)
      + rfsstudy_B->Carrier_frequency1_a;
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Constant: '<S6>/Carrier frequency1' */
    rfsstudy_B->Carrier_frequency1_b = rfsstudy_P->Carrier_frequency1_b_Value;

    /* S-Function Block: <S24>/Reshape */
    rtb_Reshape_b = rfsstudy_B->Fs;

    /* Sum: '<S6>/Sum' incorporates:
     *   Gain: '<S6>/Sensitivity'
     *
     * Regarding '<S6>/Sensitivity':
     *   Gain value: rfsstudy_P->Sensitivity_b_Gain
     */
    rfsstudy_B->Sum_b = (rtb_Reshape_b * rfsstudy_P->Sensitivity_b_Gain)
      + rfsstudy_B->Carrier_frequency1_b;
  }
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE
static void mdlUpdate(SimStruct *S, int_T tid)
{

  /* simstruct variables */
  rfsstudy_D_Work *rfsstudy_DWork = (rfsstudy_D_Work *) ssGetRootDWork(S);
  rfsstudy_Parameters *rfsstudy_P = (rfsstudy_Parameters *) ssGetDefaultParam(S);

  if (ssIsSampleHit(S, 2, tid)) {       /* Sample time: [0.0001, 0.0] */

    /* RandomNumber Block: <S1>/White Noise */
    rfsstudy_DWork->White_Noise_RWORK.NextOutput = rt_NormalRand((uint_T
      *)&rfsstudy_DWork->White_Noise_IWORK.RandSeed)*rfsstudy_P->White_Noise_StdDev+rfsstudy_P->White_Noise_Mean;
  }

  /* atomic SubSystem Block: <Root>/Spectrum Scope1 */
  if (ssIsSampleHit(S, 2, tid) || ssIsSampleHit(S, 3, tid)) {
    rfsstudy_Spectrum_Scope_Update(S, tid);
  }
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES
static void mdlDerivatives(SimStruct *S)
{
  /* simstruct variables */
  rfsstudy_BlockIO *rfsstudy_B = (rfsstudy_BlockIO *) _ssGetBlockIO(S);
  rfsstudy_StateDerivatives *rfsstudy_Xdot = (rfsstudy_StateDerivatives*)
    ssGetdX(S);

  /* Integrator Block: <S22>/Integrator */
  {

    rfsstudy_Xdot->Integrator_a_CSTATE = rfsstudy_B->Sum_a;
  }

  /* Integrator Block: <S31>/Integrator */
  {

    rfsstudy_Xdot->Integrator_b_CSTATE = rfsstudy_B->Sum_b;
  }
}

/* ZeroCrossings for root system: '<Root>' */
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings(SimStruct *S)
{
  /* simstruct variables */
  rfsstudy_BlockIO *rfsstudy_B = (rfsstudy_BlockIO *) _ssGetBlockIO(S);
  rfsstudy_NonsampledZCs *rfsstudy_NonsampledZC = (rfsstudy_NonsampledZCs *)
    ssGetNonsampledZCs(S);

  /* Abs Block: <S22>/Abs */
  rfsstudy_NonsampledZC->Abs_a_NSZC = rfsstudy_B->Gain_a;

  /* RelationalOperator Block: <S22>/Relational Operator */
  rfsstudy_NonsampledZC->Relational_Operator_a_NSZC = rfsstudy_B->Abs_a -
    rfsstudy_B->Constant_a;

  /* Abs Block: <S31>/Abs */
  rfsstudy_NonsampledZC->Abs_b_NSZC = rfsstudy_B->Gain_b;

  /* RelationalOperator Block: <S31>/Relational Operator */
  rfsstudy_NonsampledZC->Relational_Operator_b_NSZC = rfsstudy_B->Abs_b -
    rfsstudy_B->Constant_b;

  /* SubSystem Block: <Root>/FET DSP */
  /* compute zero crossings */

  /* ZeroCrossings for trigger system: '<Root>/FET DSP' */
  {
    /* simstruct variables */
    rfsstudy_BlockIO *rfsstudy_B = (rfsstudy_BlockIO *) _ssGetBlockIO(S);
    rfsstudy_NonsampledZCs *rfsstudy_NonsampledZC = (rfsstudy_NonsampledZCs *)
      ssGetNonsampledZCs(S);

    /* SubSystem Block: <Root>/FET DSP */
    rfsstudy_NonsampledZC->FET_DSP_NSZC = rfsstudy_B->Inherit_Shape1_d;
  }
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{

  /* checksum */
  ssSetChecksumVal(S, 0, 2497524356U);
  ssSetChecksumVal(S, 1, 1823736211U);
  ssSetChecksumVal(S, 2, 2248161253U);
  ssSetChecksumVal(S, 3, 1377259250U);

  /* options */
  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);

  /* Accelerator check memory map size match for DWork */
  if (ssGetSizeofDWork(S) != sizeof(rfsstudy_D_Work)) {
    ssSetErrorStatus(S,"Unexpected error: Internal DWork sizes do "
     "not match for accelerator mex file.");
  }

  /* Accelerator check memory map size match for BlockIO */
  if (ssGetSizeofGlobalBlockIO(S) != sizeof(rfsstudy_BlockIO)) {
    ssSetErrorStatus(S,"Unexpected error: Internal BlockIO sizes do "
     "not match for accelerator mex file.");
  }

  /* model parameters */
  _ssSetDefaultParam(S, (real_T *) &rfsstudy_DefaultParameters);

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

