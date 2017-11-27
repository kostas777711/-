/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) Accelerator product.
 */

/*
 * FuSimple_acc.c
 *
 * Real-Time Workshop code generation for Simulink model "FuSimple_acc.mdl".
 *
 * Model Version              : 1.48
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Wed Apr 21 16:48:28 2010
 */
#include <math.h>
#include "FuSimple_acc.h"
#include "FuSimple_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat                     S-Function
#define AccDefine1                     Accelerator_S-Function

/* Initial conditions for atomic system: '<Root>/Spectrum Scope' */
void FuSimple_SpectrumScope_Init(SimStruct *S)
{
  /* Signal Processing Blockset Buffer/Unbuffer (sdsprebuff2) - '<S23>/B_4_0' */
  ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_a = 2048;

  /* Copy ICs into circular buffer */
  {
    const int_T bufLenBytes = 4096 * sizeof(real_T);
    byte_T *circBufPtr = (byte_T *)&((D_Work *) ssGetRootDWork(S))
      ->Buffer_CircBuff_p[0];
    const byte_T *icPtr = (const byte_T *)&((Parameters *) ssGetDefaultParam(S)
      )->P_54;
    int_T i = 1;
    while (i-- > 0) {
      MWDSP_CopyScalarICs(circBufPtr, icPtr, 4096, sizeof(real_T));
      circBufPtr += bufLenBytes;
    }
  }

  *&((D_Work *) ssGetRootDWork(S))->Buffer_IN_BUF_PTR_n = (void *)( (byte_T *)
    &((D_Work *) ssGetRootDWork(S))->Buffer_CircBuff_p[0] + 2048 * sizeof(real_T)
    );
  *&((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o = (void *)( (byte_T *)
    &((D_Work *) ssGetRootDWork(S))->Buffer_CircBuff_p[0] + 64 * sizeof(real_T) );

  {
    int32_T bytesPerElem = sizeof(real_T);
    int32_T i= 0;
    while (bytesPerElem > 0) {
      bytesPerElem = bytesPerElem / 2;
      i++;
    }

    ((D_Work *) ssGetRootDWork(S))->Buffer_SHIFT_PER_ELEM_j = i - 1;
  }

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S24>/B_4_4' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &((D_Work *) ssGetRootDWork(S))
      ->DigitalFilter_FILT_STATES_p[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T chanCount = 2048;
    while (chanCount--) {
      *statePtr++ = *(const real_T *)&((Parameters *) ssGetDefaultParam(S))
        ->P_57;
      *statePtr++ = 0.0;
    }
  }
}

/* Outputs for atomic system: '<Root>/Spectrum Scope' */
void FuSimple_SpectrumScope(SimStruct *S)
{
  /* Signal Processing Blockset Buffer/Unbuffer (sdsprebuff2) - '<S23>/B_4_0' */
  {
    /* Copy input samples to buffer */
    if (ssIsSampleHit(S, 2, 0)) {
      real_T **inBufPtr = (real_T **)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_IN_BUF_PTR_n;
      real_T *memBase = (real_T *)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_CircBuff_p[0];
      **inBufPtr = ((BlockIO *) _ssGetBlockIO(S))->B_6_52_0;
      *inBufPtr = (memBase + 4095 - *inBufPtr) ? (*inBufPtr+1) : memBase;

      /* buffer overrun protection */
      {
        const int_T bufLenTimesBpe = 4096 * sizeof(real_T);
        ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_a += 1;
        if (((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_a > 4096) {
          ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o = (byte_T *)
            ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o + (((D_Work *)
            ssGetRootDWork(S))->Buffer_bufferLength_a - 4096) * sizeof(real_T);
          if ((byte_T *)((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o >
              ((byte_T *)&((D_Work *) ssGetRootDWork(S))->Buffer_CircBuff_p[0] +
               bufLenTimesBpe)) {
            ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o = (byte_T *)
              ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o -
              bufLenTimesBpe;
          }

          ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_a = 4096;
        }
      }
    }

    /* Copy output samples from buffer */
    if (ssIsSampleHit(S, 3, 0)) {
      /* buffer underrun protection */
      {
        const int_T bufLenTimesBpe = 4096 * sizeof(real_T);
        ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_a -= 1984;
        if (((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_a < 64) {
          ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o = (byte_T *)
            ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o + (((D_Work *)
            ssGetRootDWork(S))->Buffer_bufferLength_a - 64) * sizeof(real_T);
          if ((byte_T *)((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o <
              (byte_T *)&((D_Work *) ssGetRootDWork(S))->Buffer_CircBuff_p[0]) {
            ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o = (byte_T *)
              ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o +
              bufLenTimesBpe;
          }

          ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_a = 64;
        }
      }

      MWDSP_Buf_OutputFrame_1ch((byte_T *)((BlockIO *) _ssGetBlockIO(S))
        ->B_4_3_0, (byte_T **)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_OUT_BUF_PTR_o, (byte_T *)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_CircBuff_p[0], ((D_Work *) ssGetRootDWork(S))
        ->Buffer_SHIFT_PER_ELEM_j, 4096 * sizeof(real_T) ,2048, 64 * sizeof
        (real_T));
    }
  }

  if (ssIsSampleHit(S, 3, 0)) {        /* Sample time: [1.9840000000000002E-001s, 0.0s] */
    /* Signal Processing Blockset Window (sdspwindow2) - '<S24>/B_4_1' */
    {
      int_T i;
      for (i=0; i<2048; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_4_3_0[i] *= ((BlockIO *) _ssGetBlockIO
          (S))->B_4_1_1[i];
      }
    }

    /* Signal Processing Blockset FFT (sdspfft2) - '<S26>/B_4_2' */
    /* Real input, 1 channels, 2048 rows, linear output order */
    /* Interleave data to prepare for real-data algorithms: */
    MWDSP_FFTInterleave_BR_D(((BlockIO *) _ssGetBlockIO(S))->B_4_2_0, ((BlockIO *)
      _ssGetBlockIO(S))->B_4_3_0, 1, 2048);

    /* Apply half-length algorithm to single real signal: */
    {
      creal_T *lastCol = ((BlockIO *) _ssGetBlockIO(S))->B_4_2_0;/* Point to last column of input */
      MWDSP_R2DIT_TBLS_Z(lastCol, 1, 2048, 1024, &((Parameters *)
        ssGetDefaultParam(S))->P_56[0], 2, 0);/* Radix-2 DIT FFT using TableSpeed twiddle computation */
      MWDSP_DblLen_TBL_Z(lastCol, 2048, &((Parameters *) ssGetDefaultParam(S))
                         ->P_56[0], 1);
    }
  }

  {
    int32_T i;
    if (ssIsSampleHit(S, 3, 0)) {
      for (i = 0; i < 2048; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_4_3_0[i] = ((BlockIO *) _ssGetBlockIO
          (S))->B_4_2_0[i].re * ((BlockIO *) _ssGetBlockIO(S))->B_4_2_0[i].re +
          ((BlockIO *) _ssGetBlockIO(S))->B_4_2_0[i].im * ((BlockIO *)
          _ssGetBlockIO(S))->B_4_2_0[i].im;
      }
    }
  }

  if (ssIsSampleHit(S, 3, 0)) {        /* Sample time: [1.9840000000000002E-001s, 0.0s] */
    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S24>/B_4_4' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(((BlockIO *) _ssGetBlockIO(S))->B_4_3_0, ((BlockIO *)
      _ssGetBlockIO(S))->B_4_4_0, &((D_Work *) ssGetRootDWork(S))
                    ->DigitalFilter_FILT_STATES_p[0], &((D_Work *)
      ssGetRootDWork(S))->DigitalFilter_CIRCBUFFIDX_f, 2, 1, 2048, &((Parameters
      *) ssGetDefaultParam(S))->P_58[0], 1);
  }

  {
    int32_T i;
    real_T B[2048];
    real_T B_0;
    if (ssIsSampleHit(S, 3, 0)) {
      for (i = 0; i < 2048; i++) {
        B[i] = ((BlockIO *) _ssGetBlockIO(S))->B_4_1_1[i];
      }

      B_0 = 0.0;
      for (i = 0; i < 2048; i++) {
        B_0 += B[i] * ((BlockIO *) _ssGetBlockIO(S))->B_4_1_1[i];
      }

      B_0 = 1.0 / B_0;
      for (i = 0; i < 2048; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_4_7_0[i] = ((BlockIO *) _ssGetBlockIO
          (S))->B_4_4_0[i] * B_0;
      }
    }
  }
}

/* Update for atomic system: '<Root>/Spectrum Scope' */
void FuSimple_SpectrumScope_Update(SimStruct *S)
{
  if (ssIsSampleHit(S, 3, 0)) {
  }

  if (ssIsSampleHit(S, 3, 0)) {
  }

  if (ssIsSampleHit(S, 3, 0)) {        /* Sample time: [1.9840000000000002E-001s, 0.0s] */
    /* Call into Simulink */
    ssCallAccelRunBlock(S, 4, 8, SS_CALL_MDL_UPDATE);
  }
}

/* Terminate for atomic system: '<Root>/Spectrum Scope' */
void FuSimple_SpectrumScope_Term(SimStruct *S)
{
  /* Call into Simulink */
  ssCallAccelRunBlock(S, 4, 8, SS_CALL_MDL_TERMINATE);
}

/* Initial conditions for atomic system: '<Root>/Spectrum Scope1' */
void FuSimple_SpectrumScope1_Init(SimStruct *S)
{
  /* Signal Processing Blockset Buffer/Unbuffer (sdsprebuff2) - '<S29>/B_5_0' */
  ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength = 2048;

  /* Copy ICs into circular buffer */
  {
    const int_T bufLenBytes = 4096 * sizeof(real_T);
    byte_T *circBufPtr = (byte_T *)&((D_Work *) ssGetRootDWork(S))
      ->Buffer_CircBuff[0];
    const byte_T *icPtr = (const byte_T *)&((Parameters *) ssGetDefaultParam(S)
      )->P_59;
    int_T i = 1;
    while (i-- > 0) {
      MWDSP_CopyScalarICs(circBufPtr, icPtr, 4096, sizeof(real_T));
      circBufPtr += bufLenBytes;
    }
  }

  *&((D_Work *) ssGetRootDWork(S))->Buffer_IN_BUF_PTR = (void *)( (byte_T *)
    &((D_Work *) ssGetRootDWork(S))->Buffer_CircBuff[0] + 2048 * sizeof(real_T) );
  *&((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR = (void *)( (byte_T *)
    &((D_Work *) ssGetRootDWork(S))->Buffer_CircBuff[0] + 64 * sizeof(real_T) );

  {
    int32_T bytesPerElem = sizeof(real_T);
    int32_T i= 0;
    while (bytesPerElem > 0) {
      bytesPerElem = bytesPerElem / 2;
      i++;
    }

    ((D_Work *) ssGetRootDWork(S))->Buffer_SHIFT_PER_ELEM = i - 1;
  }

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S30>/B_5_4' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &((D_Work *) ssGetRootDWork(S))
      ->DigitalFilter_FILT_STATES[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T chanCount = 2048;
    while (chanCount--) {
      *statePtr++ = *(const real_T *)&((Parameters *) ssGetDefaultParam(S))
        ->P_62;
      *statePtr++ = 0.0;
    }
  }
}

/* Outputs for atomic system: '<Root>/Spectrum Scope1' */
void FuSimple_SpectrumScope1(SimStruct *S)
{
  /* Signal Processing Blockset Buffer/Unbuffer (sdsprebuff2) - '<S29>/B_5_0' */
  {
    /* Copy input samples to buffer */
    if (ssIsSampleHit(S, 2, 0)) {
      real_T **inBufPtr = (real_T **)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_IN_BUF_PTR;
      real_T *memBase = (real_T *)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_CircBuff[0];
      **inBufPtr = ((BlockIO *) _ssGetBlockIO(S))->B_6_32_0;
      *inBufPtr = (memBase + 4095 - *inBufPtr) ? (*inBufPtr+1) : memBase;

      /* buffer overrun protection */
      {
        const int_T bufLenTimesBpe = 4096 * sizeof(real_T);
        ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength += 1;
        if (((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength > 4096) {
          ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR = (byte_T *)
            ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR + (((D_Work *)
            ssGetRootDWork(S))->Buffer_bufferLength - 4096) * sizeof(real_T);
          if ((byte_T *)((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR >
              ((byte_T *)&((D_Work *) ssGetRootDWork(S))->Buffer_CircBuff[0] +
               bufLenTimesBpe)) {
            ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR = (byte_T *)
              ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR -
              bufLenTimesBpe;
          }

          ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength = 4096;
        }
      }
    }

    /* Copy output samples from buffer */
    if (ssIsSampleHit(S, 3, 0)) {
      /* buffer underrun protection */
      {
        const int_T bufLenTimesBpe = 4096 * sizeof(real_T);
        ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength -= 1984;
        if (((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength < 64) {
          ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR = (byte_T *)
            ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR + (((D_Work *)
            ssGetRootDWork(S))->Buffer_bufferLength - 64) * sizeof(real_T);
          if ((byte_T *)((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR <
              (byte_T *)&((D_Work *) ssGetRootDWork(S))->Buffer_CircBuff[0]) {
            ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR = (byte_T *)
              ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR +
              bufLenTimesBpe;
          }

          ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength = 64;
        }
      }

      MWDSP_Buf_OutputFrame_1ch((byte_T *)((BlockIO *) _ssGetBlockIO(S))
        ->B_5_3_0, (byte_T **)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_OUT_BUF_PTR, (byte_T *)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_CircBuff[0], ((D_Work *) ssGetRootDWork(S))
        ->Buffer_SHIFT_PER_ELEM, 4096 * sizeof(real_T) ,2048, 64 * sizeof(real_T));
    }
  }

  if (ssIsSampleHit(S, 3, 0)) {        /* Sample time: [1.9840000000000002E-001s, 0.0s] */
    /* Signal Processing Blockset Window (sdspwindow2) - '<S30>/B_5_1' */
    {
      int_T i;
      for (i=0; i<2048; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_5_3_0[i] *= ((BlockIO *) _ssGetBlockIO
          (S))->B_5_1_1[i];
      }
    }

    /* Signal Processing Blockset FFT (sdspfft2) - '<S32>/B_5_2' */
    /* Real input, 1 channels, 2048 rows, linear output order */
    /* Interleave data to prepare for real-data algorithms: */
    MWDSP_FFTInterleave_BR_D(((BlockIO *) _ssGetBlockIO(S))->B_5_2_0, ((BlockIO *)
      _ssGetBlockIO(S))->B_5_3_0, 1, 2048);

    /* Apply half-length algorithm to single real signal: */
    {
      creal_T *lastCol = ((BlockIO *) _ssGetBlockIO(S))->B_5_2_0;/* Point to last column of input */
      MWDSP_R2DIT_TBLS_Z(lastCol, 1, 2048, 1024, &((Parameters *)
        ssGetDefaultParam(S))->P_61[0], 2, 0);/* Radix-2 DIT FFT using TableSpeed twiddle computation */
      MWDSP_DblLen_TBL_Z(lastCol, 2048, &((Parameters *) ssGetDefaultParam(S))
                         ->P_61[0], 1);
    }
  }

  {
    int32_T i;
    if (ssIsSampleHit(S, 3, 0)) {
      for (i = 0; i < 2048; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_5_3_0[i] = ((BlockIO *) _ssGetBlockIO
          (S))->B_5_2_0[i].re * ((BlockIO *) _ssGetBlockIO(S))->B_5_2_0[i].re +
          ((BlockIO *) _ssGetBlockIO(S))->B_5_2_0[i].im * ((BlockIO *)
          _ssGetBlockIO(S))->B_5_2_0[i].im;
      }
    }
  }

  if (ssIsSampleHit(S, 3, 0)) {        /* Sample time: [1.9840000000000002E-001s, 0.0s] */
    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S30>/B_5_4' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(((BlockIO *) _ssGetBlockIO(S))->B_5_3_0, ((BlockIO *)
      _ssGetBlockIO(S))->B_5_4_0, &((D_Work *) ssGetRootDWork(S))
                    ->DigitalFilter_FILT_STATES[0], &((D_Work *) ssGetRootDWork
      (S))->DigitalFilter_CIRCBUFFIDX, 2, 1, 2048, &((Parameters *)
      ssGetDefaultParam(S))->P_63[0], 1);
  }

  {
    int32_T i;
    real_T B[2048];
    real_T B_0;
    if (ssIsSampleHit(S, 3, 0)) {
      for (i = 0; i < 2048; i++) {
        B[i] = ((BlockIO *) _ssGetBlockIO(S))->B_5_1_1[i];
      }

      B_0 = 0.0;
      for (i = 0; i < 2048; i++) {
        B_0 += B[i] * ((BlockIO *) _ssGetBlockIO(S))->B_5_1_1[i];
      }

      B_0 = 1.0 / B_0;
      for (i = 0; i < 2048; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_5_7_0[i] = ((BlockIO *) _ssGetBlockIO
          (S))->B_5_4_0[i] * B_0;
      }
    }
  }
}

/* Update for atomic system: '<Root>/Spectrum Scope1' */
void FuSimple_SpectrumScope1_Update(SimStruct *S)
{
  if (ssIsSampleHit(S, 3, 0)) {
  }

  if (ssIsSampleHit(S, 3, 0)) {
  }

  if (ssIsSampleHit(S, 3, 0)) {        /* Sample time: [1.9840000000000002E-001s, 0.0s] */
    /* Call into Simulink */
    ssCallAccelRunBlock(S, 5, 8, SS_CALL_MDL_UPDATE);
  }
}

/* Terminate for atomic system: '<Root>/Spectrum Scope1' */
void FuSimple_SpectrumScope1_Term(SimStruct *S)
{
  /* Call into Simulink */
  ssCallAccelRunBlock(S, 5, 8, SS_CALL_MDL_TERMINATE);
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  /* local block i/o variables */
  real_T B_6_29_0;
  real_T B_1_5_0;
  real_T B_1_8_0;
  real_T B_1_11_0;
  real_T B_6_55_0;
  real_T B_6_45_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_6_0_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_0 * ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE;
  if (ssIsMajorTimeStep(S)) {
    ((D_Work *) ssGetRootDWork(S))->Abs_MODE = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_0_0 >= 0.0 ? 1 : 0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_6_1_0 = ((D_Work *) ssGetRootDWork(S))
    ->Abs_MODE > 0 ? ((BlockIO *) _ssGetBlockIO(S))->B_6_0_0 : -((BlockIO *)
    _ssGetBlockIO(S))->B_6_0_0;
  if (ssIsSampleHit(S, 1, 0)) {        /* Sample time: [0.0s, 1.0s] */
    ((BlockIO *) _ssGetBlockIO(S))->B_6_2_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_1;
    if (ssIsMajorTimeStep(S)) {
      ((D_Work *) ssGetRootDWork(S))->RelationalOperator_Mode = (((BlockIO *)
        _ssGetBlockIO(S))->B_6_1_0 >= ((BlockIO *) _ssGetBlockIO(S))->B_6_2_0);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_6_3_0 = ((D_Work *) ssGetRootDWork(S))
      ->RelationalOperator_Mode;
  }

  /* Math: '<S42>/Math Function' */

  /* Operator : rem */
  {
    real_T u2Fix;
    real_T uDiv;
    real_T uDivFix;

    {
      real_T t;
      t = floor(fabs(((BlockIO *) _ssGetBlockIO(S))->B_6_2_0));
      u2Fix = ((((BlockIO *) _ssGetBlockIO(S))->B_6_2_0 < 0.0) ? -t : t);
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_6_2_0 == 0.0) {
      B_6_29_0 = rtNaN;
    } else if (((BlockIO *) _ssGetBlockIO(S))->B_6_2_0 == u2Fix ) {
      /* Integer denominator.  Use conventional formula.*/
      uDiv = ((BlockIO *) _ssGetBlockIO(S))->B_6_0_0 / ((BlockIO *)
        _ssGetBlockIO(S))->B_6_2_0;

      {
        real_T t;
        t = floor(fabs(uDiv));
        uDivFix = ((uDiv < 0.0) ? -t : t);
      }

      B_6_29_0 = (((BlockIO *) _ssGetBlockIO(S))->B_6_0_0 - uDivFix * ((BlockIO *)
        _ssGetBlockIO(S))->B_6_2_0);
    } else {
      /* Noninteger denominator. Check for nearly integer quotient.*/
      real_T uDivRound;
      uDiv = ((BlockIO *) _ssGetBlockIO(S))->B_6_0_0 / ((BlockIO *)
        _ssGetBlockIO(S))->B_6_2_0;

      {
        real_T t;
        t = floor((fabs(uDiv) + 0.5));
        uDivRound = ((uDiv < 0.0) ? -t : t);
      }

      if (fabs((uDiv - uDivRound)) <= DBL_EPSILON * fabs(uDiv)) {
        B_6_29_0 = 0.0;
      } else {
        {
          real_T t;
          t = floor(fabs(uDiv));
          uDivFix = ((uDiv < 0.0) ? -t : t);
        }

        B_6_29_0 = (uDiv - uDivFix) * ((BlockIO *) _ssGetBlockIO(S))->B_6_2_0;
      }
    }
  }

  if ((((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime == rtMinusInf) ||
      (((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime == ssGetTaskTime(S,0)))
  {
    ((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime = ssGetTaskTime(S,0);
    ((BlockIO *) _ssGetBlockIO(S))->B_6_5_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_2;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_5_0 = B_6_29_0;
  }

  /* Integrator: '<S42>/Integrator' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = ((ZCEventType) (((BlockIO *) _ssGetBlockIO(S))->B_6_3_0 &&
                !((PrevZCSigStates *) _ssGetPrevZCSigState(S))->Integrator_ZCE));

    /* evaluate zero-crossings */
    ((PrevZCSigStates *) _ssGetPrevZCSigState(S))->Integrator_ZCE = (ZCSigState)
      ((BlockIO *) _ssGetBlockIO(S))->B_6_3_0;
    if (zcEvent || ((D_Work *) ssGetRootDWork(S))
        ->Integrator_IWORK.IcNeedsLoading) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE = ((BlockIO *)
        _ssGetBlockIO(S))->B_6_5_0;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
      ssSetBlkStateChange(S);
    }

    ((D_Work *) ssGetRootDWork(S))->Integrator_IWORK.IcNeedsLoading = 0;
  }

  B_6_29_0 = ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE;

  /* Communications Blockset Inherit Shape (scominhshape) - '<S41>/B_6_5' */
  B_6_29_0 = cos(B_6_29_0 * 6.2831853071795862);

  /* Communications Blockset Inherit Shape (scominhshape) - '<S37>/B_6_7' */
  ((BlockIO *) _ssGetBlockIO(S))->B_6_9_0 = B_6_29_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_6_9_0 = B_6_29_0;

  /* Scope: '<Root>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 6, 10, SS_CALL_MDL_OUTPUTS);
  ((BlockIO *) _ssGetBlockIO(S))->B_6_11_0 = 0.0 * pow(((BlockIO *)
    _ssGetBlockIO(S))->B_6_9_0, 3.0) + ((BlockIO *) _ssGetBlockIO(S))->B_6_9_0;

  /* Quantizer: '<Root>/Quantizer' */
  {
    real_T yre;
    yre = ((Parameters *) ssGetDefaultParam(S))->P_3 * floor(fabs((((BlockIO *)
      _ssGetBlockIO(S))->B_6_11_0/(((Parameters *) ssGetDefaultParam(S))->P_3)))
      + 0.5);
    ((BlockIO *) _ssGetBlockIO(S))->B_6_12_0 = ((((BlockIO *) _ssGetBlockIO(S)
      )->B_6_11_0 >= 0.0) ? yre : -yre);
  }

  if (ssIsSampleHit(S, 1, 0)) {        /* Sample time: [0.0s, 1.0s] */
    B_6_55_0 = ((Parameters *) ssGetDefaultParam(S))->P_4;
    ((BlockIO *) _ssGetBlockIO(S))->B_6_14_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_5;
    ((BlockIO *) _ssGetBlockIO(S))->B_6_15_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_64;
    ((BlockIO *) _ssGetBlockIO(S))->B_6_16_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_15_0;
  }

  if (ssIsSampleHit(S, 4, 0)) {        /* Sample time: [-2.0s, 0.0s] */
    /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
    real_T time = ssGetTaskTime(S,0);
    real_T delay = 0.0;
    if ((int_T)((D_Work *) ssGetRootDWork(S))->justEnabled ) {
      ((D_Work *) ssGetRootDWork(S))->justEnabled = 0;
      if (time >= delay) {
        real_T ratio = (time - delay)/ ((Parameters *) ssGetDefaultParam(S))
          ->P_7;
        ((D_Work *) ssGetRootDWork(S))->numCompleteCycles = (int_T)floor(ratio);
        if (fabs((((D_Work *) ssGetRootDWork(S))->numCompleteCycles+1)- ratio ) <
            DBL_EPSILON * ratio ) {
          ((D_Work *) ssGetRootDWork(S))->numCompleteCycles = ((D_Work *)
            ssGetRootDWork(S))->numCompleteCycles+1;
        }

        ((D_Work *) ssGetRootDWork(S))->numCompleteCycles = ((D_Work *)
          ssGetRootDWork(S))->numCompleteCycles;
        if (time < delay + ((D_Work *) ssGetRootDWork(S))->numCompleteCycles *
            ((Parameters *) ssGetDefaultParam(S))->P_7
            + ((Parameters *) ssGetDefaultParam(S))->P_8 * ((Parameters *)
             ssGetDefaultParam(S))->P_7/100) {
          ((D_Work *) ssGetRootDWork(S))->currentValue = 1;
          ((D_Work *) ssGetRootDWork(S))->nextTime = delay + ((D_Work *)
            ssGetRootDWork(S))->numCompleteCycles * ((Parameters *)
            ssGetDefaultParam(S))->P_7
            + ((Parameters *) ssGetDefaultParam(S))->P_8 * ((Parameters *)
            ssGetDefaultParam(S))->P_7/100;
        } else {
          ((D_Work *) ssGetRootDWork(S))->currentValue = 0;
          ((D_Work *) ssGetRootDWork(S))->nextTime = delay + (((D_Work *)
            ssGetRootDWork(S))->numCompleteCycles + 1) * ((Parameters *)
            ssGetDefaultParam(S))->P_7;
        }
      } else {
        ((D_Work *) ssGetRootDWork(S))->numCompleteCycles = 0;
        ((D_Work *) ssGetRootDWork(S))->currentValue = 0;
        ((D_Work *) ssGetRootDWork(S))->nextTime = delay;
      }
    } else {
      /* Determine if any values need to change */
      if (((D_Work *) ssGetRootDWork(S))->nextTime <= time) {
        if (((D_Work *) ssGetRootDWork(S))->currentValue == 1) {
          ((D_Work *) ssGetRootDWork(S))->currentValue = 0;
          ((D_Work *) ssGetRootDWork(S))->nextTime = delay + (((D_Work *)
            ssGetRootDWork(S))->numCompleteCycles + 1) * ((Parameters *)
            ssGetDefaultParam(S))->P_7;
        } else {
          if (((D_Work *) ssGetRootDWork(S))->nextTime != delay) {
            ((D_Work *) ssGetRootDWork(S))->numCompleteCycles += 1;
          }

          ((D_Work *) ssGetRootDWork(S))->currentValue = 1;
          ((D_Work *) ssGetRootDWork(S))->nextTime = delay + ((D_Work *)
            ssGetRootDWork(S))->numCompleteCycles * ((Parameters *)
            ssGetDefaultParam(S))->P_7
            + 0.01 * ((Parameters *) ssGetDefaultParam(S))->P_8 * ((Parameters *)
            ssGetDefaultParam(S))->P_7;
        }
      }
    }

    /* Set the next hit time */
    {
      real_T tNext = ((D_Work *) ssGetRootDWork(S))->nextTime;
      _ssSetVarNextHitTime(S, (int_T)0.0, tNext);
    }

    /* Output the values */
    if (((D_Work *) ssGetRootDWork(S))->currentValue == 1) {
      ((BlockIO *) _ssGetBlockIO(S))->B_6_17_0 = ((Parameters *)
        ssGetDefaultParam(S))->P_6;
    } else {
      ((BlockIO *) _ssGetBlockIO(S))->B_6_17_0 = 0.0;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ssCallAccelRunBlock(S, 6, 18, SS_CALL_MDL_OUTPUTS);
    ((BlockIO *) _ssGetBlockIO(S))->B_6_19_0 = B_6_55_0 + ((BlockIO *)
      _ssGetBlockIO(S))->B_6_18_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_6_20_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_9;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_6_21_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_10 * ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_j;
  if (ssIsMajorTimeStep(S)) {
    ((D_Work *) ssGetRootDWork(S))->Abs_MODE_h = ((BlockIO *) _ssGetBlockIO(S)
      )->B_6_21_0 >= 0.0 ? 1 : 0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_6_22_0 = ((D_Work *) ssGetRootDWork(S))
    ->Abs_MODE_h > 0 ? ((BlockIO *) _ssGetBlockIO(S))->B_6_21_0 : -((BlockIO *)
    _ssGetBlockIO(S))->B_6_21_0;
  if (ssIsSampleHit(S, 1, 0)) {        /* Sample time: [0.0s, 1.0s] */
    ((BlockIO *) _ssGetBlockIO(S))->B_6_23_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_11;
    if (ssIsMajorTimeStep(S)) {
      ((D_Work *) ssGetRootDWork(S))->RelationalOperator_Mode_l = (((BlockIO *)
        _ssGetBlockIO(S))->B_6_22_0 >= ((BlockIO *) _ssGetBlockIO(S))->B_6_23_0);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_6_24_0 = ((D_Work *) ssGetRootDWork(S))
      ->RelationalOperator_Mode_l;
  }

  /* Math: '<S22>/Math Function' */

  /* Operator : rem */
  {
    real_T u2Fix;
    real_T uDiv;
    real_T uDivFix;

    {
      real_T t;
      t = floor(fabs(((BlockIO *) _ssGetBlockIO(S))->B_6_23_0));
      u2Fix = ((((BlockIO *) _ssGetBlockIO(S))->B_6_23_0 < 0.0) ? -t : t);
    }

    if (((BlockIO *) _ssGetBlockIO(S))->B_6_23_0 == 0.0) {
      B_6_29_0 = rtNaN;
    } else if (((BlockIO *) _ssGetBlockIO(S))->B_6_23_0 == u2Fix ) {
      /* Integer denominator.  Use conventional formula.*/
      uDiv = ((BlockIO *) _ssGetBlockIO(S))->B_6_21_0 / ((BlockIO *)
        _ssGetBlockIO(S))->B_6_23_0;

      {
        real_T t;
        t = floor(fabs(uDiv));
        uDivFix = ((uDiv < 0.0) ? -t : t);
      }

      B_6_29_0 = (((BlockIO *) _ssGetBlockIO(S))->B_6_21_0 - uDivFix * ((BlockIO
        *) _ssGetBlockIO(S))->B_6_23_0);
    } else {
      /* Noninteger denominator. Check for nearly integer quotient.*/
      real_T uDivRound;
      uDiv = ((BlockIO *) _ssGetBlockIO(S))->B_6_21_0 / ((BlockIO *)
        _ssGetBlockIO(S))->B_6_23_0;

      {
        real_T t;
        t = floor((fabs(uDiv) + 0.5));
        uDivRound = ((uDiv < 0.0) ? -t : t);
      }

      if (fabs((uDiv - uDivRound)) <= DBL_EPSILON * fabs(uDiv)) {
        B_6_29_0 = 0.0;
      } else {
        {
          real_T t;
          t = floor(fabs(uDiv));
          uDivFix = ((uDiv < 0.0) ? -t : t);
        }

        B_6_29_0 = (uDiv - uDivFix) * ((BlockIO *) _ssGetBlockIO(S))->B_6_23_0;
      }
    }
  }

  if ((((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime_m == rtMinusInf) ||
      (((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime_m == ssGetTaskTime(S,0)))
  {
    ((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime_m = ssGetTaskTime(S,0);
    ((BlockIO *) _ssGetBlockIO(S))->B_6_26_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_12;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_26_0 = B_6_29_0;
  }

  /* Integrator: '<S22>/Integrator' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = ((ZCEventType) (((BlockIO *) _ssGetBlockIO(S))->B_6_24_0 &&
                !((PrevZCSigStates *) _ssGetPrevZCSigState(S))->Integrator_ZCE_l));

    /* evaluate zero-crossings */
    ((PrevZCSigStates *) _ssGetPrevZCSigState(S))->Integrator_ZCE_l =
      (ZCSigState) ((BlockIO *) _ssGetBlockIO(S))->B_6_24_0;
    if (zcEvent || ((D_Work *) ssGetRootDWork(S))
        ->Integrator_IWORK_e.IcNeedsLoading) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_j = ((BlockIO
        *) _ssGetBlockIO(S))->B_6_26_0;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
      ssSetBlkStateChange(S);
    }

    ((D_Work *) ssGetRootDWork(S))->Integrator_IWORK_e.IcNeedsLoading = 0;
  }

  B_6_29_0 = ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_j;

  /* Communications Blockset Inherit Shape (scominhshape) - '<S21>/B_6_19' */
  B_6_29_0 = cos(B_6_29_0 * 6.2831853071795862);

  /* Communications Blockset Inherit Shape (scominhshape) - '<S17>/B_6_21' */
  ((BlockIO *) _ssGetBlockIO(S))->B_6_30_0 = B_6_29_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_6_30_0 = B_6_29_0;
  if (ssIsSampleHit(S, 1, 0)) {
    if (ssIsMajorTimeStep(S) && (rt_ZCFcn(RISING_ZERO_CROSSING,
          &((PrevZCSigStates *) _ssGetPrevZCSigState(S))->FETDSP1_ZCE,
          (((BlockIO *) _ssGetBlockIO(S))->B_6_30_0)) != NO_ZCEVENT)) {
      /* Output and update for trigger system: '<S2>/FET DSP1' */

      /* MATLABFcn: '<S13>/MATLAB Fcn' */
      /* Call into Simulink to run the Matlab Fcn block. */
      ssCallAccelRunBlock(S, 0, 0, SS_CALL_MDL_OUTPUTS);
      ((D_Work *) ssGetRootDWork(S))->FETDSP1_SubsysRanBC =
        SUBSYS_RAN_BC_ONE_SHOT;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_6_32_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_0_0_0[0] * ((BlockIO *) _ssGetBlockIO(S))->B_0_0_0[1];
  }

  /* Outputs for atomic system: '<Root>/Lead Lag1' */

  /* Integrator: '<S8>/Integrator' */
  ((BlockIO *) _ssGetBlockIO(S))->B_3_0_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE_a;

  /* Integrator: '<S8>/Integrator1' */
  if (ssIsMajorTimeStep(S)) {
    if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE >=
        ((Parameters *) ssGetDefaultParam(S))->P_45 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE =
        ((Parameters *) ssGetDefaultParam(S))->P_45;
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE <=
               ((Parameters *) ssGetDefaultParam(S))->P_46 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE =
        ((Parameters *) ssGetDefaultParam(S))->P_46;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_3_1_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE;

  /* Scope: '<S8>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 3, 2, SS_CALL_MDL_OUTPUTS);

  /* Integrator: '<S8>/Integrator2' */
  ((BlockIO *) _ssGetBlockIO(S))->B_3_3_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator2_CSTATE;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_3_5_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_49;
    ((BlockIO *) _ssGetBlockIO(S))->B_3_7_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_51;
    ((BlockIO *) _ssGetBlockIO(S))->B_3_8_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_32_0 * ((BlockIO *) _ssGetBlockIO(S))->B_3_7_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_3_12_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_50 * ((Parameters *) ssGetDefaultParam(S))->P_48;
    ((BlockIO *) _ssGetBlockIO(S))->B_3_13_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_52 * ((Parameters *) ssGetDefaultParam(S))->P_53 * ((BlockIO *)
      _ssGetBlockIO(S))->B_6_32_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_3_15_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_3_0_0 + ((BlockIO *) _ssGetBlockIO(S))->B_3_13_0) * ((BlockIO *)
    _ssGetBlockIO(S))->B_3_7_0 / ((BlockIO *) _ssGetBlockIO(S))->B_3_12_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_3_17_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_3_1_0 - ((BlockIO *) _ssGetBlockIO(S))->B_3_3_0) * ((BlockIO *)
    _ssGetBlockIO(S))->B_3_7_0 * ((BlockIO *) _ssGetBlockIO(S))->B_3_5_0;
  if (ssIsSampleHit(S, 1, 0)) {        /* Sample time: [0.0s, 1.0s] */
    ((BlockIO *) _ssGetBlockIO(S))->B_6_34_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_66;
    ((BlockIO *) _ssGetBlockIO(S))->B_6_35_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_34_0;
  }

  /* Outputs for atomic system: '<Root>/Lead Lag' */

  /* Integrator: '<S7>/Integrator' */
  ((BlockIO *) _ssGetBlockIO(S))->B_2_0_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE_g;

  /* Integrator: '<S7>/Integrator1' */
  if (ssIsMajorTimeStep(S)) {
    if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_g >=
        ((Parameters *) ssGetDefaultParam(S))->P_36 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_g =
        ((Parameters *) ssGetDefaultParam(S))->P_36;
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_g <=
               ((Parameters *) ssGetDefaultParam(S))->P_37 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_g =
        ((Parameters *) ssGetDefaultParam(S))->P_37;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_2_1_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE_g;

  /* Scope: '<S7>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 2, 2, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_2_5_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_40;
    ((BlockIO *) _ssGetBlockIO(S))->B_2_6_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_32_0 * ((BlockIO *) _ssGetBlockIO(S))->B_2_5_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_2_10_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_39 * ((Parameters *) ssGetDefaultParam(S))->P_38;
    ((BlockIO *) _ssGetBlockIO(S))->B_2_11_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_41 * ((Parameters *) ssGetDefaultParam(S))->P_42 * ((BlockIO *)
      _ssGetBlockIO(S))->B_6_32_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_2_13_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_2_0_0 + ((BlockIO *) _ssGetBlockIO(S))->B_2_11_0) * ((BlockIO *)
    _ssGetBlockIO(S))->B_2_5_0 / ((BlockIO *) _ssGetBlockIO(S))->B_2_10_0;
  if (ssIsSampleHit(S, 1, 0)) {        /* Sample time: [0.0s, 1.0s] */
    ((BlockIO *) _ssGetBlockIO(S))->B_6_37_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_67;
    ((BlockIO *) _ssGetBlockIO(S))->B_6_38_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_37_0;
  }

  /* Outputs for atomic system: '<Root>/LPF Type1' */

  /* Integrator: '<S6>/Integrator1' */
  if (ssIsMajorTimeStep(S)) {
    if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_n >=
        ((Parameters *) ssGetDefaultParam(S))->P_24 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_n =
        ((Parameters *) ssGetDefaultParam(S))->P_24;
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_n <=
               ((Parameters *) ssGetDefaultParam(S))->P_25 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_n =
        ((Parameters *) ssGetDefaultParam(S))->P_25;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_1_0_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE_n;

  /* Integrator: '<S6>/Integrator' */
  if (ssIsMajorTimeStep(S)) {
    if (((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_c >=
        ((Parameters *) ssGetDefaultParam(S))->P_27 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_c =
        ((Parameters *) ssGetDefaultParam(S))->P_27;
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_c <=
               ((Parameters *) ssGetDefaultParam(S))->P_28 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_c =
        ((Parameters *) ssGetDefaultParam(S))->P_28;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_1_1_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE_c;

  /* Scope: '<S6>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 1, 2, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    B_1_5_0 = ((Parameters *) ssGetDefaultParam(S))->P_31;
    B_1_8_0 = ((Parameters *) ssGetDefaultParam(S))->P_32 * ((Parameters *)
      ssGetDefaultParam(S))->P_33;
    ((BlockIO *) _ssGetBlockIO(S))->B_1_10_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_31 / B_1_8_0 * ((BlockIO *) _ssGetBlockIO(S))->B_6_32_0;
    B_1_11_0 = ((Parameters *) ssGetDefaultParam(S))->P_30 * ((Parameters *)
      ssGetDefaultParam(S))->P_29;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_1_13_0 = B_1_5_0 * B_1_8_0 * B_1_11_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_1_14_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_1_1_0 - ((BlockIO *) _ssGetBlockIO(S))->B_1_0_0) * ((BlockIO *)
    _ssGetBlockIO(S))->B_1_13_0;
  if (ssIsSampleHit(S, 1, 0)) {        /* Sample time: [0.0s, 1.0s] */
    ((BlockIO *) _ssGetBlockIO(S))->B_6_40_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_68;
    ((BlockIO *) _ssGetBlockIO(S))->B_6_41_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_40_0;
  }

  ssCallAccelRunBlock(S, 6, 42, SS_CALL_MDL_OUTPUTS);
  ssCallAccelRunBlock(S, 6, 43, SS_CALL_MDL_OUTPUTS);
  ssCallAccelRunBlock(S, 6, 44, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 2, 0)) {        /* Sample time: [0.0001s, 0.0s] */
    /* RandomNumber: '<S1>/White Noise' */
    B_6_45_0 = ((D_Work *) ssGetRootDWork(S))->WhiteNoise_RWORK.NextOutput;
  }

  if (ssIsSampleHit(S, 2, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_46_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_16 * B_6_45_0;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_48_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_46_0 + ((Parameters *) ssGetDefaultParam(S))->P_17;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_6_49_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_6_44_0 + ((BlockIO *) _ssGetBlockIO(S))->B_6_48_0;

  /* Scope: '<Root>/Scope1' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 6, 50, SS_CALL_MDL_OUTPUTS);

  /* Scope: '<Root>/Scope2' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 6, 51, SS_CALL_MDL_OUTPUTS);
  ((BlockIO *) _ssGetBlockIO(S))->B_6_52_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_18 * ((BlockIO *) _ssGetBlockIO(S))->B_6_9_0;

  /* SubSystem: '<Root>/Spectrum Scope' */
  if (ssIsSampleHit(S, 2, 0) || ssIsSampleHit(S, 3, 0)) {
    FuSimple_SpectrumScope(S);
  }

  /* SubSystem: '<Root>/Spectrum Scope1' */
  if (ssIsSampleHit(S, 2, 0) || ssIsSampleHit(S, 3, 0)) {
    FuSimple_SpectrumScope1(S);
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_57_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_20 * ((BlockIO *) _ssGetBlockIO(S))->B_6_20_0 + ((Parameters *)
      ssGetDefaultParam(S))->P_19;
    ((BlockIO *) _ssGetBlockIO(S))->B_6_58_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_21;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_6_60_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_22 * ((BlockIO *) _ssGetBlockIO(S))->B_6_49_0 + ((BlockIO *)
    _ssGetBlockIO(S))->B_6_58_0;

  /* tid is required for a uniform function interface. This system
   * is single rate, and in this case, tid is not accessed. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  if (ssIsSampleHit(S, 1, 0)) {
  }

  if (ssIsSampleHit(S, 1, 0)) {
  }

  /* Update for atomic system: '<Root>/Lead Lag1' */

  /* Limited Integrator Block: '<S8>/B_3_1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE ==
        ((Parameters *) ssGetDefaultParam(S))->P_45) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE) {
       case INTG_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_3_15_0 < 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE =
            INTG_LEAVING_UPPER_SAT;
        }

        break;

       case INTG_LEAVING_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_3_15_0 >= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(S);
        }

        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_3_15_0 < 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE =
            INTG_LEAVING_UPPER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE = INTG_UPPER_SAT;
        }

        break;
      }
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE ==
               ((Parameters *) ssGetDefaultParam(S))->P_46) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE) {
       case INTG_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_3_15_0 > 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE =
            INTG_LEAVING_LOWER_SAT;
        }

        break;

       case INTG_LEAVING_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_3_15_0 <= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(S);
        }

        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_3_15_0 > 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE =
            INTG_LEAVING_LOWER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE = INTG_LOWER_SAT;
        }

        break;
      }
    } else {
      ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE = INTG_NORMAL;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
  }

  /* Update for atomic system: '<Root>/Lead Lag' */

  /* Limited Integrator Block: '<S7>/B_2_1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_g ==
        ((Parameters *) ssGetDefaultParam(S))->P_36) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e) {
       case INTG_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_2_13_0 < 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e =
            INTG_LEAVING_UPPER_SAT;
        }

        break;

       case INTG_LEAVING_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_2_13_0 >= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(S);
        }

        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_2_13_0 < 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e =
            INTG_LEAVING_UPPER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e = INTG_UPPER_SAT;
        }

        break;
      }
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_g ==
               ((Parameters *) ssGetDefaultParam(S))->P_37) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e) {
       case INTG_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_2_13_0 > 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e =
            INTG_LEAVING_LOWER_SAT;
        }

        break;

       case INTG_LEAVING_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_2_13_0 <= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(S);
        }

        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_2_13_0 > 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e =
            INTG_LEAVING_LOWER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e = INTG_LOWER_SAT;
        }

        break;
      }
    } else {
      ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e = INTG_NORMAL;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
  }

  /* Update for atomic system: '<Root>/LPF Type1' */

  /* Limited Integrator Block: '<S6>/B_1_0' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_n ==
        ((Parameters *) ssGetDefaultParam(S))->P_24) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a) {
       case INTG_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_14_0 < 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a =
            INTG_LEAVING_UPPER_SAT;
        }

        break;

       case INTG_LEAVING_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_14_0 >= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(S);
        }

        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_14_0 < 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a =
            INTG_LEAVING_UPPER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a = INTG_UPPER_SAT;
        }

        break;
      }
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_n ==
               ((Parameters *) ssGetDefaultParam(S))->P_25) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a) {
       case INTG_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_14_0 > 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a =
            INTG_LEAVING_LOWER_SAT;
        }

        break;

       case INTG_LEAVING_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_14_0 <= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(S);
        }

        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_14_0 > 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a =
            INTG_LEAVING_LOWER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a = INTG_LOWER_SAT;
        }

        break;
      }
    } else {
      ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a = INTG_NORMAL;
    }
  }

  /* Limited Integrator Block: '<S6>/B_1_1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_c ==
        ((Parameters *) ssGetDefaultParam(S))->P_27) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator_MODE) {
       case INTG_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_10_0 < 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE =
            INTG_LEAVING_UPPER_SAT;
        }

        break;

       case INTG_LEAVING_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_10_0 >= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(S);
        }

        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_10_0 < 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE =
            INTG_LEAVING_UPPER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE = INTG_UPPER_SAT;
        }

        break;
      }
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_c ==
               ((Parameters *) ssGetDefaultParam(S))->P_28) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator_MODE) {
       case INTG_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_10_0 > 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE =
            INTG_LEAVING_LOWER_SAT;
        }

        break;

       case INTG_LEAVING_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_10_0 <= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(S);
        }

        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_10_0 > 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE =
            INTG_LEAVING_LOWER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE = INTG_LOWER_SAT;
        }

        break;
      }
    } else {
      ((D_Work *) ssGetRootDWork(S))->Integrator_MODE = INTG_NORMAL;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
  }

  if (ssIsSampleHit(S, 1, 0)) {
  }

  if (ssIsSampleHit(S, 2, 0)) {        /* Sample time: [0.0001s, 0.0s] */
    /* RandomNumber Block: '<S1>/B_6_36' */
    ((D_Work *) ssGetRootDWork(S))->WhiteNoise_RWORK.NextOutput = rt_NormalRand
      ((uint32_T *)&((D_Work *) ssGetRootDWork(S))->WhiteNoise_IWORK.RandSeed)*
      ((Parameters *) ssGetDefaultParam(S))->P_14+((Parameters *)
      ssGetDefaultParam(S))->P_13;
  }

  if (ssIsSampleHit(S, 2, 0)) {
  }

  if (ssIsSampleHit(S, 1, 0)) {
  }

  /* atomic SubSystem Block: '<Root>/B_6_42' */
  if (ssIsSampleHit(S, 2, 0) || ssIsSampleHit(S, 3, 0)) {
    FuSimple_SpectrumScope_Update(S);
  }

  /* atomic SubSystem Block: '<Root>/B_6_43' */
  if (ssIsSampleHit(S, 2, 0) || ssIsSampleHit(S, 3, 0)) {
    FuSimple_SpectrumScope1_Update(S);
  }

  if (ssIsSampleHit(S, 1, 0)) {
  }

  /* tid is required for a uniform function interface. This system
   * is single rate, and in this case, tid is not accessed. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES

static void mdlDerivatives(SimStruct *S)
{
  /* Integrator Block: '<S42>/B_6_4' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE = ((BlockIO *)
      _ssGetBlockIO(S))->B_6_60_0;
  }

  /* Integrator Block: '<S22>/B_6_18' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_j = ((BlockIO *)
      _ssGetBlockIO(S))->B_6_57_0;
  }

  /* Derivatives for atomic system: '<Root>/Lead Lag1' */

  /* Integrator Block: '<S8>/B_3_0' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_a = ((BlockIO *)
      _ssGetBlockIO(S))->B_3_8_0;
  }

  /* Limited Integrator Block: '<S8>/B_3_1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE != INTG_UPPER_SAT)
        && (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE != INTG_LOWER_SAT) )
    {
      ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE = ((BlockIO *)
        _ssGetBlockIO(S))->B_3_15_0;
      ((StateDisabled *) ssGetContStateDisabled(S))->Integrator1_CSTATE = FALSE;
    } else {
      /* in saturation */
      ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE = 0.0;
      if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE == INTG_UPPER_SAT) ||
          (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE == INTG_LOWER_SAT))
      {
        ((StateDisabled *) ssGetContStateDisabled(S))->Integrator1_CSTATE = TRUE;
      }
    }
  }

  /* Integrator Block: '<S8>/B_3_3' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator2_CSTATE = ((BlockIO *)
      _ssGetBlockIO(S))->B_3_17_0;
  }

  /* Derivatives for atomic system: '<Root>/Lead Lag' */

  /* Integrator Block: '<S7>/B_2_0' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_g = ((BlockIO *)
      _ssGetBlockIO(S))->B_2_6_0;
  }

  /* Limited Integrator Block: '<S7>/B_2_1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e != INTG_UPPER_SAT)
        && (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e != INTG_LOWER_SAT)
        ) {
      ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_g = ((BlockIO *)
        _ssGetBlockIO(S))->B_2_13_0;
      ((StateDisabled *) ssGetContStateDisabled(S))->Integrator1_CSTATE_g =
        FALSE;
    } else {
      /* in saturation */
      ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_g = 0.0;
      if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e == INTG_UPPER_SAT)
          || (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e ==
              INTG_LOWER_SAT)) {
        ((StateDisabled *) ssGetContStateDisabled(S))->Integrator1_CSTATE_g =
          TRUE;
      }
    }
  }

  /* Derivatives for atomic system: '<Root>/LPF Type1' */

  /* Limited Integrator Block: '<S6>/B_1_0' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a != INTG_UPPER_SAT)
        && (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a != INTG_LOWER_SAT)
        ) {
      ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_n = ((BlockIO *)
        _ssGetBlockIO(S))->B_1_14_0;
      ((StateDisabled *) ssGetContStateDisabled(S))->Integrator1_CSTATE_n =
        FALSE;
    } else {
      /* in saturation */
      ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_n = 0.0;
      if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a == INTG_UPPER_SAT)
          || (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a ==
              INTG_LOWER_SAT)) {
        ((StateDisabled *) ssGetContStateDisabled(S))->Integrator1_CSTATE_n =
          TRUE;
      }
    }
  }

  /* Limited Integrator Block: '<S6>/B_1_1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((((D_Work *) ssGetRootDWork(S))->Integrator_MODE != INTG_UPPER_SAT)
        && (((D_Work *) ssGetRootDWork(S))->Integrator_MODE != INTG_LOWER_SAT) )
    {
      ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_c = ((BlockIO *)
        _ssGetBlockIO(S))->B_1_10_0;
      ((StateDisabled *) ssGetContStateDisabled(S))->Integrator_CSTATE_c = FALSE;
    } else {
      /* in saturation */
      ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_c = 0.0;
      if ((((D_Work *) ssGetRootDWork(S))->Integrator_MODE == INTG_UPPER_SAT) ||
          (((D_Work *) ssGetRootDWork(S))->Integrator_MODE == INTG_LOWER_SAT)) {
        ((StateDisabled *) ssGetContStateDisabled(S))->Integrator_CSTATE_c =
          TRUE;
      }
    }
  }
}

/* ZeroCrossings for root system: '<Root>' */
#define MDL_ZERO_CROSSINGS

static void mdlZeroCrossings(SimStruct *S)
{
  ((NonsampledZCs *) ssGetNonsampledZCs(S))->Abs_NSZC = ((BlockIO *)
    _ssGetBlockIO(S))->B_6_0_0;
  ((NonsampledZCs *) ssGetNonsampledZCs(S))->RelationalOperator_NSZC = ((BlockIO
    *) _ssGetBlockIO(S))->B_6_1_0 - ((BlockIO *) _ssGetBlockIO(S))->B_6_2_0;
  ((NonsampledZCs *) ssGetNonsampledZCs(S))->Abs_NSZC_g = ((BlockIO *)
    _ssGetBlockIO(S))->B_6_21_0;
  ((NonsampledZCs *) ssGetNonsampledZCs(S))->RelationalOperator_NSZC_l =
    ((BlockIO *) _ssGetBlockIO(S))->B_6_22_0 - ((BlockIO *) _ssGetBlockIO(S))
    ->B_6_23_0;
  ((NonsampledZCs *) ssGetNonsampledZCs(S))->FETDSP1_NSZC = ((BlockIO *)
    _ssGetBlockIO(S))->B_6_30_0;

  /* ZeroCrossings for atomic system: '<Root>/Lead Lag1' */

  /* Limited Integrator Block: '<S8>/B_3_1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for limited integrator */
    if (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE ==
        INTG_LEAVING_UPPER_SAT &&
        ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE >=
        ((Parameters *) ssGetDefaultParam(S))->P_45) {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC[0] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC[0] =
        ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE -
        ((Parameters *) ssGetDefaultParam(S))->P_45;
    }

    if (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE ==
        INTG_LEAVING_LOWER_SAT &&
        ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE <=
        ((Parameters *) ssGetDefaultParam(S))->P_46) {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC[1] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC[1] =
        ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE -
        ((Parameters *) ssGetDefaultParam(S))->P_46;
    }

    /* zero crossings for input of limited integrator */
    {
      boolean_T anyStateSaturated = FALSE;
      if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE == INTG_UPPER_SAT) ||
          (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE == INTG_LOWER_SAT))
      {
        anyStateSaturated = TRUE;
      }

      if (anyStateSaturated) {
        ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC[2] =
          ((BlockIO *) _ssGetBlockIO(S))->B_3_15_0;
      } else {
        ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC[2] = 0.0;
      }
    }
  }

  /* ZeroCrossings for atomic system: '<Root>/Lead Lag' */

  /* Limited Integrator Block: '<S7>/B_2_1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for limited integrator */
    if (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e ==
        INTG_LEAVING_UPPER_SAT &&
        ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_g >=
        ((Parameters *) ssGetDefaultParam(S))->P_36) {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC_a[0] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC_a[0] =
        ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_g -
        ((Parameters *) ssGetDefaultParam(S))->P_36;
    }

    if (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e ==
        INTG_LEAVING_LOWER_SAT &&
        ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_g <=
        ((Parameters *) ssGetDefaultParam(S))->P_37) {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC_a[1] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC_a[1] =
        ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_g -
        ((Parameters *) ssGetDefaultParam(S))->P_37;
    }

    /* zero crossings for input of limited integrator */
    {
      boolean_T anyStateSaturated = FALSE;
      if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e == INTG_UPPER_SAT)
          ||
          (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_e == INTG_LOWER_SAT))
      {
        anyStateSaturated = TRUE;
      }

      if (anyStateSaturated) {
        ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC_a[2] =
          ((BlockIO *) _ssGetBlockIO(S))->B_2_13_0;
      } else {
        ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC_a[2] = 0.0;
      }
    }
  }

  /* ZeroCrossings for atomic system: '<Root>/LPF Type1' */

  /* Limited Integrator Block: '<S6>/B_1_0' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for limited integrator */
    if (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a ==
        INTG_LEAVING_UPPER_SAT &&
        ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_n >=
        ((Parameters *) ssGetDefaultParam(S))->P_24) {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC_ay[0] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC_ay[0] =
        ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_n -
        ((Parameters *) ssGetDefaultParam(S))->P_24;
    }

    if (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a ==
        INTG_LEAVING_LOWER_SAT &&
        ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_n <=
        ((Parameters *) ssGetDefaultParam(S))->P_25) {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC_ay[1] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC_ay[1] =
        ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_n -
        ((Parameters *) ssGetDefaultParam(S))->P_25;
    }

    /* zero crossings for input of limited integrator */
    {
      boolean_T anyStateSaturated = FALSE;
      if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a == INTG_UPPER_SAT)
          ||
          (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_a == INTG_LOWER_SAT))
      {
        anyStateSaturated = TRUE;
      }

      if (anyStateSaturated) {
        ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC_ay[2] =
          ((BlockIO *) _ssGetBlockIO(S))->B_1_14_0;
      } else {
        ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator1_NSZC_ay[2] = 0.0;
      }
    }
  }

  /* Limited Integrator Block: '<S6>/B_1_1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for limited integrator */
    if (((D_Work *) ssGetRootDWork(S))->Integrator_MODE ==
        INTG_LEAVING_UPPER_SAT &&
        ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_c >=
        ((Parameters *) ssGetDefaultParam(S))->P_27) {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator_NSZC[0] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator_NSZC[0] =
        ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_c -
        ((Parameters *) ssGetDefaultParam(S))->P_27;
    }

    if (((D_Work *) ssGetRootDWork(S))->Integrator_MODE ==
        INTG_LEAVING_LOWER_SAT &&
        ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_c <=
        ((Parameters *) ssGetDefaultParam(S))->P_28) {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator_NSZC[1] = 0.0;
    } else {
      ((NonsampledZCs *) ssGetNonsampledZCs(S))->Integrator_NSZC[1] =
        ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_c -
        ((Parameters *) ssGetDefaultParam(S))->P_28;
    }
  }
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{
  /* checksum */
  ssSetChecksumVal(S, 0, 25256869U);
  ssSetChecksumVal(S, 1, 2126651854U);
  ssSetChecksumVal(S, 2, 3742848185U);
  ssSetChecksumVal(S, 3, 3649177843U);

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

/* Empty mdlInitializeSampleTimes function (never called) */
static void mdlInitializeSampleTimes(SimStruct *S)
{
}

/* Empty mdlTerminate function (never called) */
static void mdlTerminate(SimStruct *S)
{
}

/* MATLAB MEX Glue */
#include "simulink.c"
