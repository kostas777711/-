/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) Accelerator product.
 */

/*
 * Real-Time Workshop code generation for Simulink model "FuSimple_acc.mdl".
 *
 * Model Version                        : 1.46
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Wed Mar 11 12:29:22 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Wed Mar 11 12:29:22 2009
 */

#include <math.h>
#include <string.h>
#include "FuSimple_acc.h"
#include "FuSimple_acc_private.h"
#include <stdio.h>
#include "simstruc.h"

#define CodeFormat                      S-Function
#define AccDefine1                      Accelerator_S-Function

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;

/* Initial conditions for atomic system: '<Root>/Spectrum Scope' */
void FuSimple_Spectrum_Scope_a_Init(SimStruct *S)
{
  /* simstruct variables */
  FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);
  FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *) ssGetDefaultParam(S);

  /* Level1 S-Function Block: <S12>/Frame Scope (sdspfscope2) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 6, 0, SS_CALL_MDL_INITIALIZE_CONDITIONS);

  /* DSP Blockset Buffer/Unbuffer (sdsprebuff2) - '<S27>/Buffer' */

  /* Copy ICs into circular buffer */
  {
    const int_T bufLenBytes = 4096 * sizeof(real_T);
    byte_T *circBufPtr = (byte_T *)&FuSimple_DWork->Buffer_a_CircBuff[0];
    const byte_T *icPtr = (const byte_T *)&FuSimple_P->Buffer_a_IC;
    int_T i = 1;
    while (i-- > 0) {
      MWDSP_CopyScalarICs(circBufPtr, icPtr, 2048, sizeof(real_T));
      circBufPtr += bufLenBytes;
    }
  }

  /* Initialize DWork for IN_BUF_PTR and OUT_BUF_PTR */
  {
    *&FuSimple_DWork->Buffer_a_IN_BUF_PTR = (void *)( (byte_T
      *)&FuSimple_DWork->Buffer_a_CircBuff[0] + 2048 * sizeof(real_T) );
    *&FuSimple_DWork->Buffer_a_OUT_BUF_PTR = (void *)( (byte_T
      *)&FuSimple_DWork->Buffer_a_CircBuff[0] + 64 * sizeof(real_T) );
  }

  /* Calculate shiftPerElement
   * (assuming that number of bits
   *  per element is power of two)
   */
  {
    int_T expn;
    const double frac = frexp((double)sizeof(real_T), &expn);
    *&FuSimple_DWork->Buffer_a_ShiftPerElem = expn - 1;
    UNUSED_ARG(frac);
  }

  /* DSP Blockset Filter Implementation (sdspfilter) - '<S28>/Digital Filter' */
  {
    real_T *statePtr = (real_T *)
      &FuSimple_DWork->Digital_Filter_a_FILT_STATES[0];
    /* Scalar expansion of ICs with extra zero element per channel */
    int_T chanCount = 2048;
    while (chanCount--) {
      *statePtr++ = *(const real_T *)&FuSimple_P->Digital_Filter_a_ICRTP;
      *statePtr++ = 0.0;
    }
  }
}

/* Outputs for atomic system: '<Root>/Spectrum Scope' */
void FuSimple_Spectrum_Scope_a(SimStruct *S, int_T tid)
{
  /* simstruct variables */
  FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
  FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);
  FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *) ssGetDefaultParam(S);

  /* local block i/o variables */
  creal_T rtb_FFT_a[2048];
  real_T rtb_S_Function_e;
  real_T rtb_Math_Function1_a;
  real_T rtb_Window_a_o1[2048];
  real_T rtb_Zero_Pad_a[2048];

  if (ssIsSampleHit(S, 3, tid)) {       /* Sample time: [1.9840000000000002E-001, 0.0] */

    /* Level1 S-Function Block: <S12>/Frame Scope (sdspfscope2) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 6, 0, SS_CALL_MDL_OUTPUTS);
  }

  /* DSP Blockset Buffer/Unbuffer (sdsprebuff2) - '<S27>/Buffer' */
  {
    /* Copy input samples to buffer */
    if (ssIsSampleHit(S, 2, tid)) {
      MWDSP_Buf_CopyScalar_OL_1ch((const byte_T *)&FuSimple_B->Gain_d, (byte_T
        **)&FuSimple_DWork->Buffer_a_IN_BUF_PTR, (byte_T
        *)&FuSimple_DWork->Buffer_a_CircBuff[0],
       *&FuSimple_DWork->Buffer_a_ShiftPerElem, 4096 * sizeof(real_T));
    }

    /* Copy output samples from buffer */
    if (ssIsSampleHit(S, 3, tid)) {
      MWDSP_Buf_OutputFrame_1ch((byte_T *)&FuSimple_B->Buffer_a[0], (byte_T
        **)&FuSimple_DWork->Buffer_a_OUT_BUF_PTR, (byte_T
        *)&FuSimple_DWork->Buffer_a_CircBuff[0],
       *&FuSimple_DWork->Buffer_a_ShiftPerElem, 4096 * sizeof(real_T) ,2048, 64
       * sizeof(real_T));
    }
  }

  if (ssIsSampleHit(S, 3, tid)) {       /* Sample time: [1.9840000000000002E-001, 0.0] */

    /* DSP Blockset Window (sdspwindow2) - '<S28>/Window' */

    {
      int_T i;
      for (i=0; i<2048; i++) {
        rtb_Window_a_o1[i] = FuSimple_B->Buffer_a[i] *
          FuSimple_B->Window_a_o2[i];
      }
    }

    /* DSP Blockset Pad (sdsppad) - '<S29>/Zero Pad' */
    /* Input dimensions: [2048 x 1], output dimensions: [2048 x 1] */
    memcpy( &rtb_Zero_Pad_a[0], &rtb_Window_a_o1[0], (2048 * sizeof(real_T)) );

    /* DSP Blockset FFT (sdspfft2) - '<S29>/FFT' */
    /* Real input, 1 channels, 2048 rows, linear output order */
    /* Interleave data to prepare for real-data algorithms: */
    MWDSP_FFTInterleave_BR_D(&rtb_FFT_a[0], &rtb_Zero_Pad_a[0], 1, 2048);
    /* Apply half-length algorithm to single real signal: */
    {
      creal_T *lastCol = &rtb_FFT_a[0]; /* Point to last column of input */
      MWDSP_R2DIT_TBLS_Z(lastCol, 1, 2048, 1024,
       &FuSimple_P->FFT_a_TwiddleTable[0], 2, 0); /* Radix-2 DIT FFT using TableSpeed twiddle computation */
      MWDSP_DblLen_TBL_Z(lastCol, 2048, &FuSimple_P->FFT_a_TwiddleTable[0], 1);
    }

    /* Math: '<S29>/Magnitude Squared'
     *
     * Regarding '<S29>/Magnitude Squared':
     *   Op: magnitude^2
     */

    {
      int_T i1;

      const creal_T *u0 = &rtb_FFT_a[0];
      real_T *y0 = &FuSimple_B->Magnitude_Squared_a[0];

      for (i1=0; i1 < 2048; i1++) {
        y0[i1] = u0[i1].re * u0[i1].re + u0[i1].im * u0[i1].im;
      }
    }

    /* DSP Blockset Filter Implementation (sdspfilter) - '<S28>/Digital Filter' */
    /* Filter algorithm: FIR Direct-Form (double precision floating-point) */
    /* Complexities: input - real, num coeffs - real */
    /* Implementing filter algorithm */
    MWDSP_FIR_DF_DD(&FuSimple_B->Magnitude_Squared_a[0],
     &FuSimple_B->Digital_Filter_a[0],
     &FuSimple_DWork->Digital_Filter_a_FILT_STATES[0],
     &FuSimple_DWork->Digital_Filter_a_DF_INDX, 2, 1, 2048,
     &FuSimple_P->Digital_Filter_a_RTP1COEFF[0], 1);

    /* S-Function Block (sdotproduct): <S32>/S-Function */
    rtb_S_Function_e = FuSimple_B->Window_a_o2[0] * FuSimple_B->Window_a_o2[0];
    {
      int_T i1;

      const real_T *u0 = &FuSimple_B->Window_a_o2[1];
      const real_T *u1 = &FuSimple_B->Window_a_o2[1];

      for (i1=0; i1 < 2047; i1++) {
        rtb_S_Function_e += u0[i1] * u1[i1];
      }
    }

    /* Math: '<S30>/Math Function1'
     *
     * Regarding '<S30>/Math Function1':
     *   Op: reciprocal
     */

    rtb_Math_Function1_a = 1.0/(rtb_S_Function_e);

    /* Product: '<S28>/Product2' */
    {
      int_T i1;

      const real_T *u0 = &FuSimple_B->Digital_Filter_a[0];
      real_T *y0 = &FuSimple_B->Product2_d[0];

      for (i1=0; i1 < 2048; i1++) {
        y0[i1] = u0[i1] * rtb_Math_Function1_a;
      }
    }
  }
}

/* Update for atomic system: '<Root>/Spectrum Scope' */
void FuSimple_Spectrum_Scope_a_Update(SimStruct *S, int_T tid)
{

  if (ssIsSampleHit(S, 3, tid)) {       /* Sample time: [1.9840000000000002E-001, 0.0] */

    /* Level1 S-Function Block: <S12>/Frame Scope (sdspfscope2) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 6, 0, SS_CALL_MDL_UPDATE);
  }
}

/* Initial conditions for atomic system: '<Root>/Spectrum Scope1' */
void FuSimple_Spectrum_Scope_b_Init(SimStruct *S)
{
  /* simstruct variables */
  FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);
  FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *) ssGetDefaultParam(S);

  /* Level1 S-Function Block: <S13>/Frame Scope (sdspfscope2) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 7, 0, SS_CALL_MDL_INITIALIZE_CONDITIONS);

  /* DSP Blockset Buffer/Unbuffer (sdsprebuff2) - '<S34>/Buffer' */

  /* Copy ICs into circular buffer */
  {
    const int_T bufLenBytes = 4096 * sizeof(real_T);
    byte_T *circBufPtr = (byte_T *)&FuSimple_DWork->Buffer_b_CircBuff[0];
    const byte_T *icPtr = (const byte_T *)&FuSimple_P->Buffer_b_IC;
    int_T i = 1;
    while (i-- > 0) {
      MWDSP_CopyScalarICs(circBufPtr, icPtr, 2048, sizeof(real_T));
      circBufPtr += bufLenBytes;
    }
  }

  /* Initialize DWork for IN_BUF_PTR and OUT_BUF_PTR */
  {
    *&FuSimple_DWork->Buffer_b_IN_BUF_PTR = (void *)( (byte_T
      *)&FuSimple_DWork->Buffer_b_CircBuff[0] + 2048 * sizeof(real_T) );
    *&FuSimple_DWork->Buffer_b_OUT_BUF_PTR = (void *)( (byte_T
      *)&FuSimple_DWork->Buffer_b_CircBuff[0] + 64 * sizeof(real_T) );
  }

  /* Calculate shiftPerElement
   * (assuming that number of bits
   *  per element is power of two)
   */
  {
    int_T expn;
    const double frac = frexp((double)sizeof(real_T), &expn);
    *&FuSimple_DWork->Buffer_b_ShiftPerElem = expn - 1;
    UNUSED_ARG(frac);
  }

  /* DSP Blockset Filter Implementation (sdspfilter) - '<S35>/Digital Filter' */
  {
    real_T *statePtr = (real_T *)
      &FuSimple_DWork->Digital_Filter_b_FILT_STATES[0];
    /* Scalar expansion of ICs with extra zero element per channel */
    int_T chanCount = 2048;
    while (chanCount--) {
      *statePtr++ = *(const real_T *)&FuSimple_P->Digital_Filter_b_ICRTP;
      *statePtr++ = 0.0;
    }
  }
}

/* Outputs for atomic system: '<Root>/Spectrum Scope1' */
void FuSimple_Spectrum_Scope_b(SimStruct *S, int_T tid)
{
  /* simstruct variables */
  FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
  FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);
  FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *) ssGetDefaultParam(S);

  /* local block i/o variables */
  creal_T rtb_FFT_b[2048];
  real_T rtb_S_Function_f;
  real_T rtb_Math_Function1_b;
  real_T rtb_Window_b_o1[2048];
  real_T rtb_Zero_Pad_b[2048];

  if (ssIsSampleHit(S, 3, tid)) {       /* Sample time: [1.9840000000000002E-001, 0.0] */

    /* Level1 S-Function Block: <S13>/Frame Scope (sdspfscope2) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 7, 0, SS_CALL_MDL_OUTPUTS);
  }

  /* DSP Blockset Buffer/Unbuffer (sdsprebuff2) - '<S34>/Buffer' */
  {
    /* Copy input samples to buffer */
    if (ssIsSampleHit(S, 2, tid)) {
      MWDSP_Buf_CopyScalar_OL_1ch((const byte_T *)&FuSimple_B->Product1_a,
       (byte_T **)&FuSimple_DWork->Buffer_b_IN_BUF_PTR, (byte_T
        *)&FuSimple_DWork->Buffer_b_CircBuff[0],
       *&FuSimple_DWork->Buffer_b_ShiftPerElem, 4096 * sizeof(real_T));
    }

    /* Copy output samples from buffer */
    if (ssIsSampleHit(S, 3, tid)) {
      MWDSP_Buf_OutputFrame_1ch((byte_T *)&FuSimple_B->Buffer_b[0], (byte_T
        **)&FuSimple_DWork->Buffer_b_OUT_BUF_PTR, (byte_T
        *)&FuSimple_DWork->Buffer_b_CircBuff[0],
       *&FuSimple_DWork->Buffer_b_ShiftPerElem, 4096 * sizeof(real_T) ,2048, 64
       * sizeof(real_T));
    }
  }

  if (ssIsSampleHit(S, 3, tid)) {       /* Sample time: [1.9840000000000002E-001, 0.0] */

    /* DSP Blockset Window (sdspwindow2) - '<S35>/Window' */

    {
      int_T i;
      for (i=0; i<2048; i++) {
        rtb_Window_b_o1[i] = FuSimple_B->Buffer_b[i] *
          FuSimple_B->Window_b_o2[i];
      }
    }

    /* DSP Blockset Pad (sdsppad) - '<S36>/Zero Pad' */
    /* Input dimensions: [2048 x 1], output dimensions: [2048 x 1] */
    memcpy( &rtb_Zero_Pad_b[0], &rtb_Window_b_o1[0], (2048 * sizeof(real_T)) );

    /* DSP Blockset FFT (sdspfft2) - '<S36>/FFT' */
    /* Real input, 1 channels, 2048 rows, linear output order */
    /* Interleave data to prepare for real-data algorithms: */
    MWDSP_FFTInterleave_BR_D(&rtb_FFT_b[0], &rtb_Zero_Pad_b[0], 1, 2048);
    /* Apply half-length algorithm to single real signal: */
    {
      creal_T *lastCol = &rtb_FFT_b[0]; /* Point to last column of input */
      MWDSP_R2DIT_TBLS_Z(lastCol, 1, 2048, 1024,
       &FuSimple_P->FFT_b_TwiddleTable[0], 2, 0); /* Radix-2 DIT FFT using TableSpeed twiddle computation */
      MWDSP_DblLen_TBL_Z(lastCol, 2048, &FuSimple_P->FFT_b_TwiddleTable[0], 1);
    }

    /* Math: '<S36>/Magnitude Squared'
     *
     * Regarding '<S36>/Magnitude Squared':
     *   Op: magnitude^2
     */

    {
      int_T i1;

      const creal_T *u0 = &rtb_FFT_b[0];
      real_T *y0 = &FuSimple_B->Magnitude_Squared_b[0];

      for (i1=0; i1 < 2048; i1++) {
        y0[i1] = u0[i1].re * u0[i1].re + u0[i1].im * u0[i1].im;
      }
    }

    /* DSP Blockset Filter Implementation (sdspfilter) - '<S35>/Digital Filter' */
    /* Filter algorithm: FIR Direct-Form (double precision floating-point) */
    /* Complexities: input - real, num coeffs - real */
    /* Implementing filter algorithm */
    MWDSP_FIR_DF_DD(&FuSimple_B->Magnitude_Squared_b[0],
     &FuSimple_B->Digital_Filter_b[0],
     &FuSimple_DWork->Digital_Filter_b_FILT_STATES[0],
     &FuSimple_DWork->Digital_Filter_b_DF_INDX, 2, 1, 2048,
     &FuSimple_P->Digital_Filter_b_RTP1COEFF[0], 1);

    /* S-Function Block (sdotproduct): <S39>/S-Function */
    rtb_S_Function_f = FuSimple_B->Window_b_o2[0] * FuSimple_B->Window_b_o2[0];
    {
      int_T i1;

      const real_T *u0 = &FuSimple_B->Window_b_o2[1];
      const real_T *u1 = &FuSimple_B->Window_b_o2[1];

      for (i1=0; i1 < 2047; i1++) {
        rtb_S_Function_f += u0[i1] * u1[i1];
      }
    }

    /* Math: '<S37>/Math Function1'
     *
     * Regarding '<S37>/Math Function1':
     *   Op: reciprocal
     */

    rtb_Math_Function1_b = 1.0/(rtb_S_Function_f);

    /* Product: '<S35>/Product2' */
    {
      int_T i1;

      const real_T *u0 = &FuSimple_B->Digital_Filter_b[0];
      real_T *y0 = &FuSimple_B->Product2_e[0];

      for (i1=0; i1 < 2048; i1++) {
        y0[i1] = u0[i1] * rtb_Math_Function1_b;
      }
    }
  }
}

/* Update for atomic system: '<Root>/Spectrum Scope1' */
void FuSimple_Spectrum_Scope_b_Update(SimStruct *S, int_T tid)
{

  if (ssIsSampleHit(S, 3, tid)) {       /* Sample time: [1.9840000000000002E-001, 0.0] */

    /* Level1 S-Function Block: <S13>/Frame Scope (sdspfscope2) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 7, 0, SS_CALL_MDL_UPDATE);
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  /* simstruct variables */
  FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
  FuSimple_ContinuousStates *FuSimple_X = (FuSimple_ContinuousStates*)
    ssGetContStates(S);
  FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);
  FuSimple_PrevZCSigStates *FuSimple_PrevZCSigState = (FuSimple_PrevZCSigStates
    *) _ssGetPrevZCSigState(S);
  FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *) ssGetDefaultParam(S);

  /* local block i/o variables */
  real_T rtb_Reshape_a;
  real_T rtb_Reshape_b;
  real_T rtb_Product2_a;
  real_T rtb_Switch_d;
  real_T rtb_White_Noise;
  real_T rtb_temp105;

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Gain: '<S48>/Gain'
     *
     * Regarding '<S48>/Gain':
     *   Gain value: FuSimple_P->Gain_a_Gain
     */
    FuSimple_B->Gain_a = FuSimple_X->Integrator_a_CSTATE *
      FuSimple_P->Gain_a_Gain;

    /* Abs: '<S48>/Abs' */
    if (ssIsMajorTimeStep(S)) {
      FuSimple_DWork->Abs_a_MODE = FuSimple_B->Gain_a >= 0.0;
    }
    FuSimple_B->Abs_a = (FuSimple_DWork->Abs_a_MODE)?
      FuSimple_B->Gain_a:-(FuSimple_B->Gain_a);
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Constant: '<S48>/Constant' */
    FuSimple_B->Constant_a = FuSimple_P->Constant_a_Value;

    /* RelationalOperator: '<S48>/Relational Operator' */
    if (ssIsMajorTimeStep(S)) {
      FuSimple_DWork->Relational_Operator_a_MODE = (int_T)(FuSimple_B->Abs_a >=
        FuSimple_B->Constant_a);
    }
    FuSimple_B->Relational_Operator_a =
      (real_T)(FuSimple_DWork->Relational_Operator_a_MODE);
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Math: '<S48>/Math Function'
     *
     * Regarding '<S48>/Math Function':
     *   Op: rem
     */

    {
      real_T y;
      real_T yDiv;
      real_T z;
      yDiv = FuSimple_B->Gain_a / FuSimple_B->Constant_a;
      y = floor(fabs(yDiv));
      z = ((yDiv < 0.0) ? -y : y);
      if (FuSimple_B->Constant_a == 0.0) {
        rtb_temp105 = rtNaN;
      } else {
        rtb_temp105 = FuSimple_B->Gain_a - FuSimple_B->Constant_a * z;
      }
    }

    /* InitialCondition: '<S48>/IC' */
    if ( FuSimple_DWork->IC_a_FirstOutputTime == rtMinusInf ) {
      FuSimple_DWork->IC_a_FirstOutputTime = ssGetTaskTime(S,tid);
    }
    if ( FuSimple_DWork->IC_a_FirstOutputTime == ssGetTaskTime(S,tid) ) {
      FuSimple_B->IC_a = FuSimple_P->IC_a_Value;
    } else {
      FuSimple_B->IC_a = rtb_temp105;
    }

    /* Integrator: '<S48>/Integrator' */
    if (ssIsMajorTimeStep(S)) {
      ZCEventType zcEvent;
      boolean_T resetIntg = FALSE;

      /* evaluate zero-crossings */
      zcEvent = ((ZCEventType) (FuSimple_B->Relational_Operator_a &&
        !FuSimple_PrevZCSigState->Integrator_a_ZCE));
      FuSimple_PrevZCSigState->Integrator_a_ZCE = (ZCSigState)
        FuSimple_B->Relational_Operator_a;
      if (zcEvent|| FuSimple_DWork->Integrator_a_IWORK.IcNeedsLoading) {
        resetIntg = TRUE;
        FuSimple_X->Integrator_a_CSTATE = FuSimple_B->IC_a;
      }

      if (resetIntg) {
        ssSetSolverNeedsReset(S);
        ssSetBlkStateChange(S);
      }

      FuSimple_DWork->Integrator_a_IWORK.IcNeedsLoading = 0;
    }
    FuSimple_B->temp72 = FuSimple_X->Integrator_a_CSTATE;

    /* Level2 S-Function Block: <S47>/Inherit Shape1 (scominhshape) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 8, 7, SS_CALL_MDL_OUTPUTS);

    /* Fcn: '<S14>/sin'
     *
     * Regarding '<S14>/sin':
     *   Expression: Ac*cos(u[1]*pi2+Ph)
     */
    FuSimple_B->temp72 = 1.0 * cos( FuSimple_B->temp72 *
      6.2831853071795862E+000 + 0.0);

    /* Level2 S-Function Block: <S42>/Inherit Shape1 (scominhshape) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 8, 9, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<Root>/Scope' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 8, 10, SS_CALL_MDL_OUTPUTS);

    /* Fcn: '<Root>/Fcn'
     *
     * Regarding '<Root>/Fcn':
     *   Expression: u(1)+0.000*(u(1)^3)
     */
    FuSimple_B->Fcn = FuSimple_B->temp72 + 0.0 * pow(
      FuSimple_B->temp72 , 3.0);

    /* Quantizer: '<Root>/Quantizer' */
    {
      real_T yre;
      yre = FuSimple_P->Quantizer_Interval *
        floor(fabs((FuSimple_B->Fcn/(FuSimple_P->Quantizer_Interval))) + 0.5);
      FuSimple_B->Quantizer = ((FuSimple_B->Fcn >= 0.0) ? yre : -yre);
    }
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Constant: '<Root>/Fin' */
    FuSimple_B->Fin = FuSimple_P->Fin_Value;

    /* Constant: '<Root>/Fin1' */
    FuSimple_B->Fin1 = FuSimple_P->Fin1_Value;
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* S-Function Block (sfun_manswitch): <S9>/S-Function */
    FuSimple_B->S_Function_a = FuSimple_P->S_Function_a_P1;
  }

  if (ssIsSampleHit(S, 4, tid)) {       /* Sample time: [-2.0, 0.0] */

    /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
    real_T time = ssGetTaskTime(S,tid);
    real_T delay = 0.0;
    if ( (int_T)FuSimple_DWork->Pulse_Generator1_IWORK.justEnabled ) {
      FuSimple_DWork->Pulse_Generator1_IWORK.justEnabled = 0;
      if (time >= delay) {
        real_T ratio = (time - delay)/ FuSimple_P->Pulse_Generator1_Period;

        FuSimple_DWork->Pulse_Generator1_IWORK.numCompleteCycles =
          (int)floor(ratio);

        if ( fabs((FuSimple_DWork->Pulse_Generator1_IWORK.numCompleteCycles+1)-
          ratio ) < DBL_EPSILON * ratio )
        {
          FuSimple_DWork->Pulse_Generator1_IWORK.numCompleteCycles =
            FuSimple_DWork->Pulse_Generator1_IWORK.numCompleteCycles+1;
        }
        FuSimple_DWork->Pulse_Generator1_IWORK.numCompleteCycles =
          FuSimple_DWork->Pulse_Generator1_IWORK.numCompleteCycles;
        if (time < delay +
         FuSimple_DWork->Pulse_Generator1_IWORK.numCompleteCycles *
         FuSimple_P->Pulse_Generator1_Period
         + FuSimple_P->Pulse_Generator1_Duty *
         FuSimple_P->Pulse_Generator1_Period/100) {
          FuSimple_DWork->Pulse_Generator1_IWORK.currValue = 1;
          FuSimple_DWork->Pulse_Generator1_RWORK.nextTime = delay +
            FuSimple_DWork->Pulse_Generator1_IWORK.numCompleteCycles *
            FuSimple_P->Pulse_Generator1_Period
            + FuSimple_P->Pulse_Generator1_Duty *
            FuSimple_P->Pulse_Generator1_Period/100;
        } else {
          FuSimple_DWork->Pulse_Generator1_IWORK.currValue = 0;
          FuSimple_DWork->Pulse_Generator1_RWORK.nextTime = delay +
            (FuSimple_DWork->Pulse_Generator1_IWORK.numCompleteCycles + 1) *
            FuSimple_P->Pulse_Generator1_Period;
        }
      } else {
        FuSimple_DWork->Pulse_Generator1_IWORK.numCompleteCycles = 0;
        FuSimple_DWork->Pulse_Generator1_IWORK.currValue = 0;
        FuSimple_DWork->Pulse_Generator1_RWORK.nextTime = delay;
      }
    } else {
      /* Determine if any values need to change */
      if (FuSimple_DWork->Pulse_Generator1_RWORK.nextTime <= time) {
        if (FuSimple_DWork->Pulse_Generator1_IWORK.currValue == 1) {
          FuSimple_DWork->Pulse_Generator1_IWORK.currValue = 0;
          FuSimple_DWork->Pulse_Generator1_RWORK.nextTime = delay +
            (FuSimple_DWork->Pulse_Generator1_IWORK.numCompleteCycles + 1) *
            FuSimple_P->Pulse_Generator1_Period;
        } else {
          if ( FuSimple_DWork->Pulse_Generator1_RWORK.nextTime != delay) {
            FuSimple_DWork->Pulse_Generator1_IWORK.numCompleteCycles += 1;
          }
          FuSimple_DWork->Pulse_Generator1_IWORK.currValue = 1;
          FuSimple_DWork->Pulse_Generator1_RWORK.nextTime = delay +
            FuSimple_DWork->Pulse_Generator1_IWORK.numCompleteCycles *
            FuSimple_P->Pulse_Generator1_Period
            + 0.01 * FuSimple_P->Pulse_Generator1_Duty *
            FuSimple_P->Pulse_Generator1_Period;
        }
      }
    }

    /* Set the next hit time */
    {
      real_T tNext = FuSimple_DWork->Pulse_Generator1_RWORK.nextTime;
      _ssSetVarNextHitTime(S, (int_T)0.0, tNext);
    }

    /* Output the values */
    if (FuSimple_DWork->Pulse_Generator1_IWORK.currValue == 1){
      FuSimple_B->Pulse_Generator1 = FuSimple_P->Pulse_Generator1_Amp;
    } else {
      FuSimple_B->Pulse_Generator1 = 0;
    }
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Switch: '<S9>/Switch' */
    if (FuSimple_B->S_Function_a) {
      rtb_temp105 = FuSimple_B->Fin1;
    } else {
      rtb_temp105 = FuSimple_B->Pulse_Generator1;
    }

    /* Sum: '<Root>/Sum' */
    FuSimple_B->Sum_a = FuSimple_B->Fin + rtb_temp105;
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Constant: '<Root>/Fs' */
    FuSimple_B->Fs = FuSimple_P->Fs_Value;
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Gain: '<S25>/Gain'
     *
     * Regarding '<S25>/Gain':
     *   Gain value: FuSimple_P->Gain_b_Gain
     */
    FuSimple_B->Gain_b = FuSimple_X->Integrator_b_CSTATE *
      FuSimple_P->Gain_b_Gain;

    /* Abs: '<S25>/Abs' */
    if (ssIsMajorTimeStep(S)) {
      FuSimple_DWork->Abs_b_MODE = FuSimple_B->Gain_b >= 0.0;
    }
    FuSimple_B->Abs_b = (FuSimple_DWork->Abs_b_MODE)?
      FuSimple_B->Gain_b:-(FuSimple_B->Gain_b);
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Constant: '<S25>/Constant' */
    FuSimple_B->Constant_b = FuSimple_P->Constant_b_Value;

    /* RelationalOperator: '<S25>/Relational Operator' */
    if (ssIsMajorTimeStep(S)) {
      FuSimple_DWork->Relational_Operator_b_MODE = (int_T)(FuSimple_B->Abs_b >=
        FuSimple_B->Constant_b);
    }
    FuSimple_B->Relational_Operator_b =
      (real_T)(FuSimple_DWork->Relational_Operator_b_MODE);
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Math: '<S25>/Math Function'
     *
     * Regarding '<S25>/Math Function':
     *   Op: rem
     */

    {
      real_T y;
      real_T yDiv;
      real_T z;
      yDiv = FuSimple_B->Gain_b / FuSimple_B->Constant_b;
      y = floor(fabs(yDiv));
      z = ((yDiv < 0.0) ? -y : y);
      if (FuSimple_B->Constant_b == 0.0) {
        rtb_temp105 = rtNaN;
      } else {
        rtb_temp105 = FuSimple_B->Gain_b - FuSimple_B->Constant_b * z;
      }
    }

    /* InitialCondition: '<S25>/IC' */
    if ( FuSimple_DWork->IC_b_FirstOutputTime == rtMinusInf ) {
      FuSimple_DWork->IC_b_FirstOutputTime = ssGetTaskTime(S,tid);
    }
    if ( FuSimple_DWork->IC_b_FirstOutputTime == ssGetTaskTime(S,tid) ) {
      FuSimple_B->IC_b = FuSimple_P->IC_b_Value;
    } else {
      FuSimple_B->IC_b = rtb_temp105;
    }

    /* Integrator: '<S25>/Integrator' */
    if (ssIsMajorTimeStep(S)) {
      ZCEventType zcEvent;
      boolean_T resetIntg = FALSE;

      /* evaluate zero-crossings */
      zcEvent = ((ZCEventType) (FuSimple_B->Relational_Operator_b &&
        !FuSimple_PrevZCSigState->Integrator_b_ZCE));
      FuSimple_PrevZCSigState->Integrator_b_ZCE = (ZCSigState)
        FuSimple_B->Relational_Operator_b;
      if (zcEvent|| FuSimple_DWork->Integrator_b_IWORK.IcNeedsLoading) {
        resetIntg = TRUE;
        FuSimple_X->Integrator_b_CSTATE = FuSimple_B->IC_b;
      }

      if (resetIntg) {
        ssSetSolverNeedsReset(S);
        ssSetBlkStateChange(S);
      }

      FuSimple_DWork->Integrator_b_IWORK.IcNeedsLoading = 0;
    }
    FuSimple_B->temp73 = FuSimple_X->Integrator_b_CSTATE;
  }

  /* Level2 S-Function Block: <S24>/Inherit Shape1 (scominhshape) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 8, 27, SS_CALL_MDL_OUTPUTS);

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Fcn: '<S16>/sin'
     *
     * Regarding '<S16>/sin':
     *   Expression: Ac*cos(u[1]*pi2+Ph)
     */
    FuSimple_B->temp73 = 1.0 * cos( FuSimple_B->temp73 *
      6.2831853071795862E+000 + 0.0);
  }

  /* Level2 S-Function Block: <S19>/Inherit Shape1 (scominhshape) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 8, 29, SS_CALL_MDL_OUTPUTS);

  /* SubSystem: '<S2>/FET DSP1' */

  /* Output and update for trigger system: '<S2>/FET DSP1' */
  {
    /* simstruct variables */
    FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
    FuSimple_PrevZCSigStates *FuSimple_PrevZCSigState =
      (FuSimple_PrevZCSigStates *) _ssGetPrevZCSigState(S);

    if (ssIsMajorTimeStep(S)) {
      ZCEventType trigEvent;

      if (ssIsContinuousTask(S, tid)) { /* Sample time: [0.0, 0.0] */
        trigEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
          &(FuSimple_PrevZCSigState->FET_DSP1_ZCE),
          FuSimple_B->Inherit_Shape1_d);
      } else {
        trigEvent = NO_ZCEVENT;
      }
      /* conditionally execute */
      if (trigEvent && ssIsSampleHit(S, 1, tid)) {

        /* MATLABFcn: '<S15>/MATLAB Fcn' */
        /* Call into Simulink to run the Matlab Fcn block. */
        ssCallAccelRunBlock(S, 0, 0, SS_CALL_MDL_OUTPUTS);
      }
    }
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Product: '<S2>/Product1' */
    FuSimple_B->Product1_a = FuSimple_B->MATLAB_Fcn[0] *
      FuSimple_B->MATLAB_Fcn[1];
  }

  /* SubSystem: '<Root>/Lead Lag1' */
  if (ssIsContinuousTask(S, tid) || ssIsSampleHit(S, 1, tid)) {

    /* Outputs for atomic system: '<Root>/Lead Lag1' */
    {
      /* simstruct variables */
      FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
      FuSimple_ContinuousStates *FuSimple_X = (FuSimple_ContinuousStates*)
        ssGetContStates(S);
      FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *)
        ssGetDefaultParam(S);

      if (ssIsContinuousTask(S, tid)) { /* Sample time: [0.0, 0.0] */

        /* Integrator: '<S8>/Integrator' */
        FuSimple_B->Integrator_e = FuSimple_X->Integrator_e_CSTATE;

        /* Integrator: '<S8>/Integrator1' */
        if (ssIsMajorTimeStep(S)) {
          if (FuSimple_X->Integrator1_c_CSTATE >=
           FuSimple_P->Integrator1_c_UpperSat ) {
            FuSimple_X->Integrator1_c_CSTATE =
              FuSimple_P->Integrator1_c_UpperSat;
          } else if (FuSimple_X->Integrator1_c_CSTATE <=
           FuSimple_P->Integrator1_c_LowerSat ) {
            FuSimple_X->Integrator1_c_CSTATE =
              FuSimple_P->Integrator1_c_LowerSat;
          }
        }
        FuSimple_B->Integrator1_c = FuSimple_X->Integrator1_c_CSTATE;

        /* Scope: '<S8>/Scope' */
        /* Call into Simulink for Scope */
        ssCallAccelRunBlock(S, 5, 2, SS_CALL_MDL_OUTPUTS);

        /* Integrator: '<S8>/Integrator2' */
        FuSimple_B->Integrator2 = FuSimple_X->Integrator2_CSTATE;
      }

      if (ssIsSampleHit(S, 1, tid)) {   /* Sample time: [0.0, 1.0] */

        /* Constant: '<S8>/Kd' */
        FuSimple_B->Kd_c = FuSimple_P->Kd_c_Value;

        /* Constant: '<S8>/Kd1' */
        FuSimple_B->Kd1 = FuSimple_P->Kd1_Value;

        /* Constant: '<S8>/Kv' */
        FuSimple_B->Kv_c = FuSimple_P->Kv_c_Value;

        /* Constant: '<S8>/Wn' */
        FuSimple_B->Wn_c = FuSimple_P->Wn_c_Value;

        /* Product: '<S8>/Product1' */
        FuSimple_B->Product1_d = FuSimple_B->Product1_a * FuSimple_B->Wn_c;

        /* Constant: '<S8>/Z' */
        FuSimple_B->Z_c = FuSimple_P->Z_c_Value;

        /* Constant: '<S8>/cZ' */
        FuSimple_B->cZ_c = FuSimple_P->cZ_c_Value;

        /* Product: '<S8>/Product3' */
        FuSimple_B->Product3_c = FuSimple_B->Kv_c * FuSimple_B->Kd_c;

        /* Product: '<S8>/Product5' incorporates:
         *   Product: '<S8>/Product2'
         */
        FuSimple_B->Product5_c = FuSimple_B->Product1_a * (FuSimple_B->Z_c *
          FuSimple_B->cZ_c);
      }

      if (ssIsContinuousTask(S, tid)) { /* Sample time: [0.0, 0.0] */

        /* Product: '<S8>/Product4' incorporates:
         *   Sum: '<S8>/Sum'
         */
        FuSimple_B->Product4_c = (FuSimple_B->Integrator_e +
          FuSimple_B->Product5_c) * FuSimple_B->Wn_c / FuSimple_B->Product3_c;

        /* Product: '<S8>/Product7' incorporates:
         *   Sum: '<S8>/Sum1'
         */
        FuSimple_B->Product7 = (FuSimple_B->Integrator1_c -
          FuSimple_B->Integrator2) * FuSimple_B->Wn_c * FuSimple_B->Kd1;
      }
    }
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* S-Function Block (sfun_manswitch): <S4>/S-Function */
    FuSimple_B->S_Function_b = FuSimple_P->S_Function_b_P1;
  }

  /* SubSystem: '<Root>/Lead Lag' */
  if (ssIsContinuousTask(S, tid) || ssIsSampleHit(S, 1, tid)) {

    /* Outputs for atomic system: '<Root>/Lead Lag' */
    {
      /* simstruct variables */
      FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
      FuSimple_ContinuousStates *FuSimple_X = (FuSimple_ContinuousStates*)
        ssGetContStates(S);
      FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *)
        ssGetDefaultParam(S);

      if (ssIsContinuousTask(S, tid)) { /* Sample time: [0.0, 0.0] */

        /* Integrator: '<S7>/Integrator' */
        FuSimple_B->Integrator_d = FuSimple_X->Integrator_d_CSTATE;

        /* Integrator: '<S7>/Integrator1' */
        if (ssIsMajorTimeStep(S)) {
          if (FuSimple_X->Integrator1_b_CSTATE >=
           FuSimple_P->Integrator1_b_UpperSat ) {
            FuSimple_X->Integrator1_b_CSTATE =
              FuSimple_P->Integrator1_b_UpperSat;
          } else if (FuSimple_X->Integrator1_b_CSTATE <=
           FuSimple_P->Integrator1_b_LowerSat ) {
            FuSimple_X->Integrator1_b_CSTATE =
              FuSimple_P->Integrator1_b_LowerSat;
          }
        }
        FuSimple_B->Integrator1_b = FuSimple_X->Integrator1_b_CSTATE;

        /* Scope: '<S7>/Scope' */
        /* Call into Simulink for Scope */
        ssCallAccelRunBlock(S, 4, 2, SS_CALL_MDL_OUTPUTS);
      }

      if (ssIsSampleHit(S, 1, tid)) {   /* Sample time: [0.0, 1.0] */

        /* Constant: '<S7>/Kd' */
        FuSimple_B->Kd_b = FuSimple_P->Kd_b_Value;

        /* Constant: '<S7>/Kv' */
        FuSimple_B->Kv_b = FuSimple_P->Kv_b_Value;

        /* Constant: '<S7>/Wn' */
        FuSimple_B->Wn_b = FuSimple_P->Wn_b_Value;

        /* Product: '<S7>/Product1' */
        FuSimple_B->Product1_c = FuSimple_B->Product1_a * FuSimple_B->Wn_b;

        /* Constant: '<S7>/Z' */
        FuSimple_B->Z_b = FuSimple_P->Z_b_Value;

        /* Constant: '<S7>/cZ' */
        FuSimple_B->cZ_b = FuSimple_P->cZ_b_Value;

        /* Product: '<S7>/Product3' */
        FuSimple_B->Product3_b = FuSimple_B->Kv_b * FuSimple_B->Kd_b;

        /* Product: '<S7>/Product5' incorporates:
         *   Product: '<S7>/Product2'
         */
        FuSimple_B->Product5_b = FuSimple_B->Product1_a * (FuSimple_B->Z_b *
          FuSimple_B->cZ_b);
      }

      if (ssIsContinuousTask(S, tid)) { /* Sample time: [0.0, 0.0] */

        /* Product: '<S7>/Product4' incorporates:
         *   Sum: '<S7>/Sum'
         */
        FuSimple_B->Product4_b = (FuSimple_B->Integrator_d +
          FuSimple_B->Product5_b) * FuSimple_B->Wn_b / FuSimple_B->Product3_b;
      }
    }
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* S-Function Block (sfun_manswitch): <S3>/S-Function */
    FuSimple_B->S_Function_c = FuSimple_P->S_Function_c_P1;
  }

  /* SubSystem: '<Root>/LPF Type1' */
  if (ssIsContinuousTask(S, tid) || ssIsSampleHit(S, 1, tid)) {

    /* Outputs for atomic system: '<Root>/LPF Type1' */
    {
      /* simstruct variables */
      FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
      FuSimple_ContinuousStates *FuSimple_X = (FuSimple_ContinuousStates*)
        ssGetContStates(S);
      FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *)
        ssGetDefaultParam(S);

      if (ssIsContinuousTask(S, tid)) { /* Sample time: [0.0, 0.0] */

        /* Integrator: '<S6>/Integrator1' */
        if (ssIsMajorTimeStep(S)) {
          if (FuSimple_X->Integrator1_a_CSTATE >=
           FuSimple_P->Integrator1_a_UpperSat ) {
            FuSimple_X->Integrator1_a_CSTATE =
              FuSimple_P->Integrator1_a_UpperSat;
          } else if (FuSimple_X->Integrator1_a_CSTATE <=
           FuSimple_P->Integrator1_a_LowerSat ) {
            FuSimple_X->Integrator1_a_CSTATE =
              FuSimple_P->Integrator1_a_LowerSat;
          }
        }
        FuSimple_B->Integrator1_a = FuSimple_X->Integrator1_a_CSTATE;

        /* Integrator: '<S6>/Integrator' */
        if (ssIsMajorTimeStep(S)) {
          if (FuSimple_X->Integrator_c_CSTATE >=
           FuSimple_P->Integrator_c_UpperSat ) {
            FuSimple_X->Integrator_c_CSTATE = FuSimple_P->Integrator_c_UpperSat;
          } else if (FuSimple_X->Integrator_c_CSTATE <=
           FuSimple_P->Integrator_c_LowerSat ) {
            FuSimple_X->Integrator_c_CSTATE = FuSimple_P->Integrator_c_LowerSat;
          }
        }
        FuSimple_B->Integrator_c = FuSimple_X->Integrator_c_CSTATE;

        /* Scope: '<S6>/Scope' */
        /* Call into Simulink for Scope */
        ssCallAccelRunBlock(S, 3, 2, SS_CALL_MDL_OUTPUTS);
      }

      if (ssIsSampleHit(S, 1, tid)) {   /* Sample time: [0.0, 1.0] */

        /* Constant: '<S6>/Kd' */
        FuSimple_B->Kd_a = FuSimple_P->Kd_a_Value;

        /* Constant: '<S6>/Kv' */
        FuSimple_B->Kv_a = FuSimple_P->Kv_a_Value;

        /* Constant: '<S6>/Wn' */
        FuSimple_B->Wn_a = FuSimple_P->Wn_a_Value;

        /* Constant: '<S6>/Z' */
        FuSimple_B->Z_a = FuSimple_P->Z_a_Value;

        /* Constant: '<S6>/cZ' */
        FuSimple_B->cZ_a = FuSimple_P->cZ_a_Value;

        /* Product: '<S6>/Product2' */
        rtb_Product2_a = FuSimple_B->Z_a * FuSimple_B->cZ_a;

        /* Product: '<S6>/Product1' incorporates:
         *   Product: '<S6>/Product'
         */
        FuSimple_B->Product1_b = FuSimple_B->Product1_a * (FuSimple_B->Wn_a /
          rtb_Product2_a);

        /* Product: '<S6>/Product5' incorporates:
         *   Product: '<S6>/Product3'
         */
        FuSimple_B->Product5_a = FuSimple_B->Wn_a * rtb_Product2_a *
          (FuSimple_B->Kv_a * FuSimple_B->Kd_a);
      }

      if (ssIsContinuousTask(S, tid)) { /* Sample time: [0.0, 0.0] */

        /* Product: '<S6>/Product4' incorporates:
         *   Sum: '<S6>/Sum'
         */
        FuSimple_B->Product4_a = (FuSimple_B->Integrator_c -
          FuSimple_B->Integrator1_a) * FuSimple_B->Product5_a;
      }
    }
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* S-Function Block (sfun_manswitch): <S5>/S-Function */
    FuSimple_B->S_Function_d = FuSimple_P->S_Function_d_P1;
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Switch: '<S4>/Switch' */
    if (FuSimple_B->S_Function_b) {
      rtb_temp105 = FuSimple_B->Integrator2;
    } else {

      {
        /* simstruct variables */
        FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);

        /* Switch: '<S3>/Switch' */
        if (FuSimple_B->S_Function_c) {
          FuSimple_B->Switch_c = FuSimple_B->Integrator1_b;
        } else {

          {
            /* simstruct variables */
            FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);

            /* Switch: '<S5>/Switch' */
            if (FuSimple_B->S_Function_d) {
              rtb_Switch_d = FuSimple_B->Integrator1_a;
            } else {
              rtb_Switch_d = FuSimple_B->Sum_a;
            }
          }

          FuSimple_B->Switch_c = rtb_Switch_d;
        }
      }

      rtb_temp105 = FuSimple_B->Switch_c;
    }
  }

  if (ssIsSampleHit(S, 2, tid)) {       /* Sample time: [0.0001, 0.0] */

    /* RandomNumber: '<S1>/White Noise' */
    rtb_White_Noise = FuSimple_DWork->White_Noise_RWORK.NextOutput;

    /* Gain: '<S1>/Gain'
     *
     * Regarding '<S1>/Gain':
     *   Gain value: FuSimple_P->Gain_c_Gain
     */
    FuSimple_B->Gain_c = rtb_White_Noise * FuSimple_P->Gain_c_Gain;
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Constant: '<Root>/Band' */
    FuSimple_B->Band = FuSimple_P->Band_Value;

    /* Sum: '<Root>/Sum2' */
    FuSimple_B->Sum2 = FuSimple_B->Gain_c + FuSimple_B->Band;
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* Sum: '<Root>/Sum1' */
    FuSimple_B->temp73 = rtb_temp105 + FuSimple_B->Sum2;

    /* Scope: '<Root>/Scope1' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 8, 45, SS_CALL_MDL_OUTPUTS);

    /* Scope: '<Root>/Scope2' */
    /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 8, 46, SS_CALL_MDL_OUTPUTS);

    /* Gain: '<Root>/Gain'
     *
     * Regarding '<Root>/Gain':
     *   Gain value: FuSimple_P->Gain_d_Gain
     */
    FuSimple_B->Gain_d = FuSimple_B->temp72 * FuSimple_P->Gain_d_Gain;
  }

  /* SubSystem: '<Root>/Spectrum Scope' */
  if (ssIsSampleHit(S, 2, tid) || ssIsSampleHit(S, 3, tid)) {
    FuSimple_Spectrum_Scope_a(S, tid);
  }

  /* SubSystem: '<Root>/Spectrum Scope1' */
  if (ssIsSampleHit(S, 2, tid) || ssIsSampleHit(S, 3, tid)) {
    FuSimple_Spectrum_Scope_b(S, tid);
  }

  if (ssIsSampleHit(S, 1, tid)) {       /* Sample time: [0.0, 1.0] */

    /* Constant: '<S16>/Carrier frequency1' */
    FuSimple_B->Carrier_frequency1_a = FuSimple_P->Carrier_frequency1_a_Value;

    /* S-Function Block: <S18>/Reshape */
    rtb_Reshape_a = FuSimple_B->Fs;

    /* Sum: '<S16>/Sum' incorporates:
     *   Gain: '<S16>/Sensitivity'
     *
     * Regarding '<S16>/Sensitivity':
     *   Gain value: FuSimple_P->Sensitivity_a_Gain
     */
    FuSimple_B->Sum_b = (rtb_Reshape_a * FuSimple_P->Sensitivity_a_Gain)
      + FuSimple_B->Carrier_frequency1_a;

    /* Constant: '<S14>/Carrier frequency1' */
    FuSimple_B->Carrier_frequency1_b = FuSimple_P->Carrier_frequency1_b_Value;
  }

  if (ssIsContinuousTask(S, tid)) {     /* Sample time: [0.0, 0.0] */

    /* S-Function Block: <S41>/Reshape */
    rtb_Reshape_b = FuSimple_B->temp73;

    /* Sum: '<S14>/Sum' incorporates:
     *   Gain: '<S14>/Sensitivity'
     *
     * Regarding '<S14>/Sensitivity':
     *   Gain value: FuSimple_P->Sensitivity_b_Gain
     */
    FuSimple_B->Sum_c = (rtb_Reshape_b * FuSimple_P->Sensitivity_b_Gain)
      + FuSimple_B->Carrier_frequency1_b;
  }
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE
static void mdlUpdate(SimStruct *S, int_T tid)
{

  /* simstruct variables */
  FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);
  FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *) ssGetDefaultParam(S);

  /* atomic SubSystem Block: <Root>/Lead Lag1 */
  if (ssIsContinuousTask(S, tid) || ssIsSampleHit(S, 1, tid)) {

    /* Update for atomic system: '<Root>/Lead Lag1' */
    {

      /* simstruct variables */
      FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
      FuSimple_ContinuousStates *FuSimple_X = (FuSimple_ContinuousStates*)
        ssGetContStates(S);
      FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);
      FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *)
        ssGetDefaultParam(S);

      if (ssIsContinuousTask(S, tid)) { /* Sample time: [0.0, 0.0] */

        /* Limited Integrator Block: <S8>/Integrator1 */
        {
          enum {INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
            INTG_UPPER_SAT, INTG_LOWER_SAT };

          if (FuSimple_X->Integrator1_c_CSTATE ==
           FuSimple_P->Integrator1_c_UpperSat) {
            switch(FuSimple_DWork->Integrator1_c_MODE) {
             case INTG_UPPER_SAT:
              if (FuSimple_B->Product4_c < 0.0) {
                ssSetSolverNeedsReset(S);
                FuSimple_DWork->Integrator1_c_MODE = INTG_LEAVING_UPPER_SAT;
              }
              break;
             case INTG_LEAVING_UPPER_SAT:
              if (FuSimple_B->Product4_c >= 0.0) {
                FuSimple_DWork->Integrator1_c_MODE = INTG_UPPER_SAT;
                ssSetSolverNeedsReset(S);
              }
              break;
             default:
              ssSetSolverNeedsReset(S);
              if (FuSimple_B->Product4_c < 0.0) {
                FuSimple_DWork->Integrator1_c_MODE = INTG_LEAVING_UPPER_SAT;
              } else {
                FuSimple_DWork->Integrator1_c_MODE = INTG_UPPER_SAT;
              }
              break;
            }
          } else if (FuSimple_X->Integrator1_c_CSTATE ==
           FuSimple_P->Integrator1_c_LowerSat) {
            switch(FuSimple_DWork->Integrator1_c_MODE) {
             case INTG_LOWER_SAT:
              if (FuSimple_B->Product4_c > 0.0) {
                ssSetSolverNeedsReset(S);
                FuSimple_DWork->Integrator1_c_MODE = INTG_LEAVING_LOWER_SAT;
              }
              break;
             case INTG_LEAVING_LOWER_SAT:
              if (FuSimple_B->Product4_c <= 0.0) {
                FuSimple_DWork->Integrator1_c_MODE = INTG_LOWER_SAT;
                ssSetSolverNeedsReset(S);
              }
              break;
             default:
              ssSetSolverNeedsReset(S);
              if (FuSimple_B->Product4_c > 0.0) {
                FuSimple_DWork->Integrator1_c_MODE = INTG_LEAVING_LOWER_SAT;
              } else {
                FuSimple_DWork->Integrator1_c_MODE = INTG_LOWER_SAT;
              }
              break;
            }
          } else {
            FuSimple_DWork->Integrator1_c_MODE = INTG_NORMAL;
          }
        }
      }
    }
  }

  /* atomic SubSystem Block: <Root>/Lead Lag */
  if (ssIsContinuousTask(S, tid) || ssIsSampleHit(S, 1, tid)) {

    /* Update for atomic system: '<Root>/Lead Lag' */
    {

      /* simstruct variables */
      FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
      FuSimple_ContinuousStates *FuSimple_X = (FuSimple_ContinuousStates*)
        ssGetContStates(S);
      FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);
      FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *)
        ssGetDefaultParam(S);

      if (ssIsContinuousTask(S, tid)) { /* Sample time: [0.0, 0.0] */

        /* Limited Integrator Block: <S7>/Integrator1 */
        {
          enum {INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
            INTG_UPPER_SAT, INTG_LOWER_SAT };

          if (FuSimple_X->Integrator1_b_CSTATE ==
           FuSimple_P->Integrator1_b_UpperSat) {
            switch(FuSimple_DWork->Integrator1_b_MODE) {
             case INTG_UPPER_SAT:
              if (FuSimple_B->Product4_b < 0.0) {
                ssSetSolverNeedsReset(S);
                FuSimple_DWork->Integrator1_b_MODE = INTG_LEAVING_UPPER_SAT;
              }
              break;
             case INTG_LEAVING_UPPER_SAT:
              if (FuSimple_B->Product4_b >= 0.0) {
                FuSimple_DWork->Integrator1_b_MODE = INTG_UPPER_SAT;
                ssSetSolverNeedsReset(S);
              }
              break;
             default:
              ssSetSolverNeedsReset(S);
              if (FuSimple_B->Product4_b < 0.0) {
                FuSimple_DWork->Integrator1_b_MODE = INTG_LEAVING_UPPER_SAT;
              } else {
                FuSimple_DWork->Integrator1_b_MODE = INTG_UPPER_SAT;
              }
              break;
            }
          } else if (FuSimple_X->Integrator1_b_CSTATE ==
           FuSimple_P->Integrator1_b_LowerSat) {
            switch(FuSimple_DWork->Integrator1_b_MODE) {
             case INTG_LOWER_SAT:
              if (FuSimple_B->Product4_b > 0.0) {
                ssSetSolverNeedsReset(S);
                FuSimple_DWork->Integrator1_b_MODE = INTG_LEAVING_LOWER_SAT;
              }
              break;
             case INTG_LEAVING_LOWER_SAT:
              if (FuSimple_B->Product4_b <= 0.0) {
                FuSimple_DWork->Integrator1_b_MODE = INTG_LOWER_SAT;
                ssSetSolverNeedsReset(S);
              }
              break;
             default:
              ssSetSolverNeedsReset(S);
              if (FuSimple_B->Product4_b > 0.0) {
                FuSimple_DWork->Integrator1_b_MODE = INTG_LEAVING_LOWER_SAT;
              } else {
                FuSimple_DWork->Integrator1_b_MODE = INTG_LOWER_SAT;
              }
              break;
            }
          } else {
            FuSimple_DWork->Integrator1_b_MODE = INTG_NORMAL;
          }
        }
      }
    }
  }

  /* atomic SubSystem Block: <Root>/LPF Type1 */
  if (ssIsContinuousTask(S, tid) || ssIsSampleHit(S, 1, tid)) {

    /* Update for atomic system: '<Root>/LPF Type1' */
    {

      /* simstruct variables */
      FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
      FuSimple_ContinuousStates *FuSimple_X = (FuSimple_ContinuousStates*)
        ssGetContStates(S);
      FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);
      FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *)
        ssGetDefaultParam(S);

      if (ssIsContinuousTask(S, tid)) { /* Sample time: [0.0, 0.0] */

        /* Limited Integrator Block: <S6>/Integrator1 */
        {
          enum {INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
            INTG_UPPER_SAT, INTG_LOWER_SAT };

          if (FuSimple_X->Integrator1_a_CSTATE ==
           FuSimple_P->Integrator1_a_UpperSat) {
            switch(FuSimple_DWork->Integrator1_a_MODE) {
             case INTG_UPPER_SAT:
              if (FuSimple_B->Product4_a < 0.0) {
                ssSetSolverNeedsReset(S);
                FuSimple_DWork->Integrator1_a_MODE = INTG_LEAVING_UPPER_SAT;
              }
              break;
             case INTG_LEAVING_UPPER_SAT:
              if (FuSimple_B->Product4_a >= 0.0) {
                FuSimple_DWork->Integrator1_a_MODE = INTG_UPPER_SAT;
                ssSetSolverNeedsReset(S);
              }
              break;
             default:
              ssSetSolverNeedsReset(S);
              if (FuSimple_B->Product4_a < 0.0) {
                FuSimple_DWork->Integrator1_a_MODE = INTG_LEAVING_UPPER_SAT;
              } else {
                FuSimple_DWork->Integrator1_a_MODE = INTG_UPPER_SAT;
              }
              break;
            }
          } else if (FuSimple_X->Integrator1_a_CSTATE ==
           FuSimple_P->Integrator1_a_LowerSat) {
            switch(FuSimple_DWork->Integrator1_a_MODE) {
             case INTG_LOWER_SAT:
              if (FuSimple_B->Product4_a > 0.0) {
                ssSetSolverNeedsReset(S);
                FuSimple_DWork->Integrator1_a_MODE = INTG_LEAVING_LOWER_SAT;
              }
              break;
             case INTG_LEAVING_LOWER_SAT:
              if (FuSimple_B->Product4_a <= 0.0) {
                FuSimple_DWork->Integrator1_a_MODE = INTG_LOWER_SAT;
                ssSetSolverNeedsReset(S);
              }
              break;
             default:
              ssSetSolverNeedsReset(S);
              if (FuSimple_B->Product4_a > 0.0) {
                FuSimple_DWork->Integrator1_a_MODE = INTG_LEAVING_LOWER_SAT;
              } else {
                FuSimple_DWork->Integrator1_a_MODE = INTG_LOWER_SAT;
              }
              break;
            }
          } else {
            FuSimple_DWork->Integrator1_a_MODE = INTG_NORMAL;
          }
        }

        /* Limited Integrator Block: <S6>/Integrator */
        {
          enum {INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
            INTG_UPPER_SAT, INTG_LOWER_SAT };

          if (FuSimple_X->Integrator_c_CSTATE ==
           FuSimple_P->Integrator_c_UpperSat) {
            switch(FuSimple_DWork->Integrator_c_MODE) {
             case INTG_UPPER_SAT:
              if (FuSimple_B->Product1_b < 0.0) {
                ssSetSolverNeedsReset(S);
                FuSimple_DWork->Integrator_c_MODE = INTG_LEAVING_UPPER_SAT;
              }
              break;
             case INTG_LEAVING_UPPER_SAT:
              if (FuSimple_B->Product1_b >= 0.0) {
                FuSimple_DWork->Integrator_c_MODE = INTG_UPPER_SAT;
                ssSetSolverNeedsReset(S);
              }
              break;
             default:
              ssSetSolverNeedsReset(S);
              if (FuSimple_B->Product1_b < 0.0) {
                FuSimple_DWork->Integrator_c_MODE = INTG_LEAVING_UPPER_SAT;
              } else {
                FuSimple_DWork->Integrator_c_MODE = INTG_UPPER_SAT;
              }
              break;
            }
          } else if (FuSimple_X->Integrator_c_CSTATE ==
           FuSimple_P->Integrator_c_LowerSat) {
            switch(FuSimple_DWork->Integrator_c_MODE) {
             case INTG_LOWER_SAT:
              if (FuSimple_B->Product1_b > 0.0) {
                ssSetSolverNeedsReset(S);
                FuSimple_DWork->Integrator_c_MODE = INTG_LEAVING_LOWER_SAT;
              }
              break;
             case INTG_LEAVING_LOWER_SAT:
              if (FuSimple_B->Product1_b <= 0.0) {
                FuSimple_DWork->Integrator_c_MODE = INTG_LOWER_SAT;
                ssSetSolverNeedsReset(S);
              }
              break;
             default:
              ssSetSolverNeedsReset(S);
              if (FuSimple_B->Product1_b > 0.0) {
                FuSimple_DWork->Integrator_c_MODE = INTG_LEAVING_LOWER_SAT;
              } else {
                FuSimple_DWork->Integrator_c_MODE = INTG_LOWER_SAT;
              }
              break;
            }
          } else {
            FuSimple_DWork->Integrator_c_MODE = INTG_NORMAL;
          }
        }
      }
    }
  }

  if (ssIsSampleHit(S, 2, tid)) {       /* Sample time: [0.0001, 0.0] */

    /* RandomNumber Block: <S1>/White Noise */
    FuSimple_DWork->White_Noise_RWORK.NextOutput = rt_NormalRand((uint_T
      *)&FuSimple_DWork->White_Noise_IWORK.RandSeed)*FuSimple_P->White_Noise_StdDev+FuSimple_P->White_Noise_Mean;
  }

  /* atomic SubSystem Block: <Root>/Spectrum Scope */
  if (ssIsSampleHit(S, 2, tid) || ssIsSampleHit(S, 3, tid)) {
    FuSimple_Spectrum_Scope_a_Update(S, tid);
  }

  /* atomic SubSystem Block: <Root>/Spectrum Scope1 */
  if (ssIsSampleHit(S, 2, tid) || ssIsSampleHit(S, 3, tid)) {
    FuSimple_Spectrum_Scope_b_Update(S, tid);
  }
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES
static void mdlDerivatives(SimStruct *S)
{
  /* simstruct variables */
  FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
  FuSimple_StateDerivatives *FuSimple_Xdot = (FuSimple_StateDerivatives*)
    ssGetdX(S);

  /* Integrator Block: <S48>/Integrator */
  {

    FuSimple_Xdot->Integrator_a_CSTATE = FuSimple_B->Sum_c;
  }

  /* Integrator Block: <S25>/Integrator */
  {

    FuSimple_Xdot->Integrator_b_CSTATE = FuSimple_B->Sum_b;
  }

  /* atomic SubSystem Block: <Root>/Lead Lag1 */
  /* compute derivatives */

  /* Derivatives for atomic system: '<Root>/Lead Lag1' */
  {
    /* simstruct variables */
    FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
    FuSimple_StateDerivatives *FuSimple_Xdot = (FuSimple_StateDerivatives*)
      ssGetdX(S);
    FuSimple_StateDisabled *FuSimple_Xdis = (FuSimple_StateDisabled*)
      ssGetContStateDisabled(S);
    FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);

    /* Integrator Block: <S8>/Integrator */
    {

      FuSimple_Xdot->Integrator_e_CSTATE = FuSimple_B->Product1_d;
    }

    /* Limited Integrator Block: <S8>/Integrator1 */
    {
      enum {INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
        INTG_UPPER_SAT, INTG_LOWER_SAT };

      if ((FuSimple_DWork->Integrator1_c_MODE != INTG_UPPER_SAT)
       && (FuSimple_DWork->Integrator1_c_MODE != INTG_LOWER_SAT) ) {
        FuSimple_Xdot->Integrator1_c_CSTATE = FuSimple_B->Product4_c;
        FuSimple_Xdis->Integrator1_c_CSTATE = FALSE;
      } else {
        /* in saturation */
        FuSimple_Xdot->Integrator1_c_CSTATE = 0.0;
        if ((FuSimple_DWork->Integrator1_c_MODE == INTG_UPPER_SAT) ||
         (FuSimple_DWork->Integrator1_c_MODE == INTG_LOWER_SAT)) {
          FuSimple_Xdis->Integrator1_c_CSTATE = TRUE;
        }
      }
    }

    /* Integrator Block: <S8>/Integrator2 */
    {

      FuSimple_Xdot->Integrator2_CSTATE = FuSimple_B->Product7;
    }
  }

  /* atomic SubSystem Block: <Root>/Lead Lag */
  /* compute derivatives */

  /* Derivatives for atomic system: '<Root>/Lead Lag' */
  {
    /* simstruct variables */
    FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
    FuSimple_StateDerivatives *FuSimple_Xdot = (FuSimple_StateDerivatives*)
      ssGetdX(S);
    FuSimple_StateDisabled *FuSimple_Xdis = (FuSimple_StateDisabled*)
      ssGetContStateDisabled(S);
    FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);

    /* Integrator Block: <S7>/Integrator */
    {

      FuSimple_Xdot->Integrator_d_CSTATE = FuSimple_B->Product1_c;
    }

    /* Limited Integrator Block: <S7>/Integrator1 */
    {
      enum {INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
        INTG_UPPER_SAT, INTG_LOWER_SAT };

      if ((FuSimple_DWork->Integrator1_b_MODE != INTG_UPPER_SAT)
       && (FuSimple_DWork->Integrator1_b_MODE != INTG_LOWER_SAT) ) {
        FuSimple_Xdot->Integrator1_b_CSTATE = FuSimple_B->Product4_b;
        FuSimple_Xdis->Integrator1_b_CSTATE = FALSE;
      } else {
        /* in saturation */
        FuSimple_Xdot->Integrator1_b_CSTATE = 0.0;
        if ((FuSimple_DWork->Integrator1_b_MODE == INTG_UPPER_SAT) ||
         (FuSimple_DWork->Integrator1_b_MODE == INTG_LOWER_SAT)) {
          FuSimple_Xdis->Integrator1_b_CSTATE = TRUE;
        }
      }
    }
  }

  /* atomic SubSystem Block: <Root>/LPF Type1 */
  /* compute derivatives */

  /* Derivatives for atomic system: '<Root>/LPF Type1' */
  {
    /* simstruct variables */
    FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
    FuSimple_StateDerivatives *FuSimple_Xdot = (FuSimple_StateDerivatives*)
      ssGetdX(S);
    FuSimple_StateDisabled *FuSimple_Xdis = (FuSimple_StateDisabled*)
      ssGetContStateDisabled(S);
    FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);

    /* Limited Integrator Block: <S6>/Integrator1 */
    {
      enum {INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
        INTG_UPPER_SAT, INTG_LOWER_SAT };

      if ((FuSimple_DWork->Integrator1_a_MODE != INTG_UPPER_SAT)
       && (FuSimple_DWork->Integrator1_a_MODE != INTG_LOWER_SAT) ) {
        FuSimple_Xdot->Integrator1_a_CSTATE = FuSimple_B->Product4_a;
        FuSimple_Xdis->Integrator1_a_CSTATE = FALSE;
      } else {
        /* in saturation */
        FuSimple_Xdot->Integrator1_a_CSTATE = 0.0;
        if ((FuSimple_DWork->Integrator1_a_MODE == INTG_UPPER_SAT) ||
         (FuSimple_DWork->Integrator1_a_MODE == INTG_LOWER_SAT)) {
          FuSimple_Xdis->Integrator1_a_CSTATE = TRUE;
        }
      }
    }

    /* Limited Integrator Block: <S6>/Integrator */
    {
      enum {INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
        INTG_UPPER_SAT, INTG_LOWER_SAT };

      if ((FuSimple_DWork->Integrator_c_MODE != INTG_UPPER_SAT)
       && (FuSimple_DWork->Integrator_c_MODE != INTG_LOWER_SAT) ) {
        FuSimple_Xdot->Integrator_c_CSTATE = FuSimple_B->Product1_b;
        FuSimple_Xdis->Integrator_c_CSTATE = FALSE;
      } else {
        /* in saturation */
        FuSimple_Xdot->Integrator_c_CSTATE = 0.0;
        if ((FuSimple_DWork->Integrator_c_MODE == INTG_UPPER_SAT) ||
         (FuSimple_DWork->Integrator_c_MODE == INTG_LOWER_SAT)) {
          FuSimple_Xdis->Integrator_c_CSTATE = TRUE;
        }
      }
    }
  }
}

/* ZeroCrossings for root system: '<Root>' */
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings(SimStruct *S)
{
  /* simstruct variables */
  FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
  FuSimple_NonsampledZCs *FuSimple_NonsampledZC = (FuSimple_NonsampledZCs *)
    ssGetNonsampledZCs(S);

  /* Abs Block: <S48>/Abs */
  FuSimple_NonsampledZC->Abs_a_NSZC = FuSimple_B->Gain_a;

  /* RelationalOperator Block: <S48>/Relational Operator */
  FuSimple_NonsampledZC->Relational_Operator_a_NSZC = FuSimple_B->Abs_a -
    FuSimple_B->Constant_a;

  /* Abs Block: <S25>/Abs */
  FuSimple_NonsampledZC->Abs_b_NSZC = FuSimple_B->Gain_b;

  /* RelationalOperator Block: <S25>/Relational Operator */
  FuSimple_NonsampledZC->Relational_Operator_b_NSZC = FuSimple_B->Abs_b -
    FuSimple_B->Constant_b;

  /* SubSystem Block: <S2>/FET DSP1 */
  /* compute zero crossings */

  /* ZeroCrossings for trigger system: '<S2>/FET DSP1' */
  {
    /* simstruct variables */
    FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
    FuSimple_NonsampledZCs *FuSimple_NonsampledZC = (FuSimple_NonsampledZCs *)
      ssGetNonsampledZCs(S);

    /* SubSystem Block: <S2>/FET DSP1 */
    FuSimple_NonsampledZC->FET_DSP1_NSZC = FuSimple_B->Inherit_Shape1_d;
  }

  /* SubSystem Block: <Root>/Lead Lag1 */
  /* compute zero crossings */

  /* ZeroCrossings for atomic system: '<Root>/Lead Lag1' */
  {
    /* simstruct variables */
    FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
    FuSimple_ContinuousStates *FuSimple_X = (FuSimple_ContinuousStates*)
      ssGetContStates(S);
    FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);
    FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *)
      ssGetDefaultParam(S);
    FuSimple_NonsampledZCs *FuSimple_NonsampledZC = (FuSimple_NonsampledZCs *)
      ssGetNonsampledZCs(S);

    /* SubSystem Block: <Root>/Lead Lag1 */

    /* Limited Integrator Block: <S8>/Integrator1 */
    {
      enum {INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
        INTG_UPPER_SAT, INTG_LOWER_SAT };

      /* zero crossings for limited integrator */
      if (FuSimple_DWork->Integrator1_c_MODE == INTG_LEAVING_UPPER_SAT &&
       FuSimple_X->Integrator1_c_CSTATE >= FuSimple_P->Integrator1_c_UpperSat) {
        FuSimple_NonsampledZC->Integrator1_c_NSZC[0] = 0.0;
      } else {
        FuSimple_NonsampledZC->Integrator1_c_NSZC[0] =
          FuSimple_X->Integrator1_c_CSTATE - FuSimple_P->Integrator1_c_UpperSat;
      }
      if (FuSimple_DWork->Integrator1_c_MODE == INTG_LEAVING_LOWER_SAT &&
       FuSimple_X->Integrator1_c_CSTATE <= FuSimple_P->Integrator1_c_LowerSat) {
        FuSimple_NonsampledZC->Integrator1_c_NSZC[1] = 0.0;
      } else {
        FuSimple_NonsampledZC->Integrator1_c_NSZC[1] =
          FuSimple_X->Integrator1_c_CSTATE - FuSimple_P->Integrator1_c_LowerSat;
      }

      /* zero crossings for input of limited integrator */
      {
        boolean_T anyStateSaturated = FALSE;

        if ((FuSimple_DWork->Integrator1_c_MODE == INTG_UPPER_SAT) ||
         (FuSimple_DWork->Integrator1_c_MODE == INTG_LOWER_SAT)) {
          anyStateSaturated = TRUE;
        }
        if (anyStateSaturated) {
          FuSimple_NonsampledZC->Integrator1_c_NSZC[2] = FuSimple_B->Product4_c;
        } else {
          FuSimple_NonsampledZC->Integrator1_c_NSZC[2] = 0.0;
        }
      }
    }
  }

  /* SubSystem Block: <Root>/Lead Lag */
  /* compute zero crossings */

  /* ZeroCrossings for atomic system: '<Root>/Lead Lag' */
  {
    /* simstruct variables */
    FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
    FuSimple_ContinuousStates *FuSimple_X = (FuSimple_ContinuousStates*)
      ssGetContStates(S);
    FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);
    FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *)
      ssGetDefaultParam(S);
    FuSimple_NonsampledZCs *FuSimple_NonsampledZC = (FuSimple_NonsampledZCs *)
      ssGetNonsampledZCs(S);

    /* SubSystem Block: <Root>/Lead Lag */

    /* Limited Integrator Block: <S7>/Integrator1 */
    {
      enum {INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
        INTG_UPPER_SAT, INTG_LOWER_SAT };

      /* zero crossings for limited integrator */
      if (FuSimple_DWork->Integrator1_b_MODE == INTG_LEAVING_UPPER_SAT &&
       FuSimple_X->Integrator1_b_CSTATE >= FuSimple_P->Integrator1_b_UpperSat) {
        FuSimple_NonsampledZC->Integrator1_b_NSZC[0] = 0.0;
      } else {
        FuSimple_NonsampledZC->Integrator1_b_NSZC[0] =
          FuSimple_X->Integrator1_b_CSTATE - FuSimple_P->Integrator1_b_UpperSat;
      }
      if (FuSimple_DWork->Integrator1_b_MODE == INTG_LEAVING_LOWER_SAT &&
       FuSimple_X->Integrator1_b_CSTATE <= FuSimple_P->Integrator1_b_LowerSat) {
        FuSimple_NonsampledZC->Integrator1_b_NSZC[1] = 0.0;
      } else {
        FuSimple_NonsampledZC->Integrator1_b_NSZC[1] =
          FuSimple_X->Integrator1_b_CSTATE - FuSimple_P->Integrator1_b_LowerSat;
      }

      /* zero crossings for input of limited integrator */
      {
        boolean_T anyStateSaturated = FALSE;

        if ((FuSimple_DWork->Integrator1_b_MODE == INTG_UPPER_SAT) ||
         (FuSimple_DWork->Integrator1_b_MODE == INTG_LOWER_SAT)) {
          anyStateSaturated = TRUE;
        }
        if (anyStateSaturated) {
          FuSimple_NonsampledZC->Integrator1_b_NSZC[2] = FuSimple_B->Product4_b;
        } else {
          FuSimple_NonsampledZC->Integrator1_b_NSZC[2] = 0.0;
        }
      }
    }
  }

  /* SubSystem Block: <Root>/LPF Type1 */
  /* compute zero crossings */

  /* ZeroCrossings for atomic system: '<Root>/LPF Type1' */
  {
    /* simstruct variables */
    FuSimple_BlockIO *FuSimple_B = (FuSimple_BlockIO *) _ssGetBlockIO(S);
    FuSimple_ContinuousStates *FuSimple_X = (FuSimple_ContinuousStates*)
      ssGetContStates(S);
    FuSimple_D_Work *FuSimple_DWork = (FuSimple_D_Work *) ssGetRootDWork(S);
    FuSimple_Parameters *FuSimple_P = (FuSimple_Parameters *)
      ssGetDefaultParam(S);
    FuSimple_NonsampledZCs *FuSimple_NonsampledZC = (FuSimple_NonsampledZCs *)
      ssGetNonsampledZCs(S);

    /* SubSystem Block: <Root>/LPF Type1 */

    /* Limited Integrator Block: <S6>/Integrator1 */
    {
      enum {INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
        INTG_UPPER_SAT, INTG_LOWER_SAT };

      /* zero crossings for limited integrator */
      if (FuSimple_DWork->Integrator1_a_MODE == INTG_LEAVING_UPPER_SAT &&
       FuSimple_X->Integrator1_a_CSTATE >= FuSimple_P->Integrator1_a_UpperSat) {
        FuSimple_NonsampledZC->Integrator1_a_NSZC[0] = 0.0;
      } else {
        FuSimple_NonsampledZC->Integrator1_a_NSZC[0] =
          FuSimple_X->Integrator1_a_CSTATE - FuSimple_P->Integrator1_a_UpperSat;
      }
      if (FuSimple_DWork->Integrator1_a_MODE == INTG_LEAVING_LOWER_SAT &&
       FuSimple_X->Integrator1_a_CSTATE <= FuSimple_P->Integrator1_a_LowerSat) {
        FuSimple_NonsampledZC->Integrator1_a_NSZC[1] = 0.0;
      } else {
        FuSimple_NonsampledZC->Integrator1_a_NSZC[1] =
          FuSimple_X->Integrator1_a_CSTATE - FuSimple_P->Integrator1_a_LowerSat;
      }

      /* zero crossings for input of limited integrator */
      {
        boolean_T anyStateSaturated = FALSE;

        if ((FuSimple_DWork->Integrator1_a_MODE == INTG_UPPER_SAT) ||
         (FuSimple_DWork->Integrator1_a_MODE == INTG_LOWER_SAT)) {
          anyStateSaturated = TRUE;
        }
        if (anyStateSaturated) {
          FuSimple_NonsampledZC->Integrator1_a_NSZC[2] = FuSimple_B->Product4_a;
        } else {
          FuSimple_NonsampledZC->Integrator1_a_NSZC[2] = 0.0;
        }
      }
    }

    /* Limited Integrator Block: <S6>/Integrator */
    {
      enum {INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
        INTG_UPPER_SAT, INTG_LOWER_SAT };

      /* zero crossings for limited integrator */
      if (FuSimple_DWork->Integrator_c_MODE == INTG_LEAVING_UPPER_SAT &&
       FuSimple_X->Integrator_c_CSTATE >= FuSimple_P->Integrator_c_UpperSat) {
        FuSimple_NonsampledZC->Integrator_c_NSZC[0] = 0.0;
      } else {
        FuSimple_NonsampledZC->Integrator_c_NSZC[0] =
          FuSimple_X->Integrator_c_CSTATE - FuSimple_P->Integrator_c_UpperSat;
      }
      if (FuSimple_DWork->Integrator_c_MODE == INTG_LEAVING_LOWER_SAT &&
       FuSimple_X->Integrator_c_CSTATE <= FuSimple_P->Integrator_c_LowerSat) {
        FuSimple_NonsampledZC->Integrator_c_NSZC[1] = 0.0;
      } else {
        FuSimple_NonsampledZC->Integrator_c_NSZC[1] =
          FuSimple_X->Integrator_c_CSTATE - FuSimple_P->Integrator_c_LowerSat;
      }
    }
  }
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{

  /* checksum */
  ssSetChecksumVal(S, 0, 580443319U);
  ssSetChecksumVal(S, 1, 3816181311U);
  ssSetChecksumVal(S, 2, 4187514310U);
  ssSetChecksumVal(S, 3, 1763561433U);

  /* options */
  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);

  /* Accelerator check memory map size match for DWork */
  if (ssGetSizeofDWork(S) != sizeof(FuSimple_D_Work)) {
    ssSetErrorStatus(S,"Unexpected error: Internal DWork sizes do "
     "not match for accelerator mex file.");
  }

  /* Accelerator check memory map size match for BlockIO */
  if (ssGetSizeofGlobalBlockIO(S) != sizeof(FuSimple_BlockIO)) {
    ssSetErrorStatus(S,"Unexpected error: Internal BlockIO sizes do "
     "not match for accelerator mex file.");
  }

  /* model parameters */
  _ssSetDefaultParam(S, (real_T *) &FuSimple_DefaultParameters);

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

