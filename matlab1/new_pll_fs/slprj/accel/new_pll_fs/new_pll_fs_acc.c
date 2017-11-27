/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) product.
 */

/*
 * new_pll_fs_acc.c
 *
 * Real-Time Workshop code generation for Simulink model "new_pll_fs_acc.mdl".
 *
 * Model version              : 1.52
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Thu Apr 29 14:20:16 2010
 *
 * Target selection: accel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit xPC Target (AMD Athlon)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include <math.h>
#include "new_pll_fs_acc.h"
#include "new_pll_fs_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat                     S-Function
#define AccDefine1                     Accelerator_S-Function

void MWDSPCG_FFT_Interleave_R2BR_D(const real_T x[], creal_T y[], const int32_T
  nChans, const int32_T nRows)
{
  int32_T br_j;
  int32_T yIdx;
  int32_T uIdx;
  int32_T j;
  int32_T nChansBy2;
  int32_T bit_fftLen;

  /* Bit-reverses the input data simultaneously with the interleaving operation,
     obviating the need for explicit data reordering later.  This requires an
     FFT with bit-rev inputs.
   */
  br_j = 0;
  yIdx = 0;
  uIdx = 0;
  for (nChansBy2 = nChans >> 1U; nChansBy2; nChansBy2 = nChansBy2 - 1) {
    for (j = nRows - 1; j > 0; j = j - 1) {
      y[yIdx + br_j].re = x[uIdx];
      y[yIdx + br_j].im = x[uIdx + nRows];
      uIdx = uIdx + 1;

      /* Compute next bit-reversed destination index */
      bit_fftLen = nRows;
      do {
        bit_fftLen = (int32_T)((uint32_T)bit_fftLen >> 1);
        br_j = br_j ^ bit_fftLen;
      } while (!(br_j & bit_fftLen));
    }

    y[yIdx + br_j].re = x[uIdx];
    y[yIdx + br_j].im = x[uIdx + nRows];
    uIdx = (nRows + 1) + uIdx;
    yIdx = (nRows << 1U) + yIdx;
    br_j = 0;
  }

  /* For an odd number of channels, prepare the last channel
     for a double-length real signal algorithm.  No actual
     interleaving is required, just a copy of the last column
     of real data, but now placed in bit-rev order.
     We need to cast the real u pointer to a cDType_T pointer,
     in order to fake the interleaving, and cut the number
     of elements in half (half as many complex interleaved
     elements as compared to real non-interleaved elements).
   */
  if (nChans & 1) {
    for (j = (nRows >> 1U) - 1; j > 0; j = j - 1) {
      y[yIdx + br_j].re = x[uIdx];
      y[yIdx + br_j].im = x[uIdx + 1];
      uIdx = uIdx + 2;

      /* Compute next bit-reversed destination index */
      nChansBy2 = nRows >> 1U;
      do {
        nChansBy2 = (int32_T)((uint32_T)nChansBy2 >> 1);
        br_j = br_j ^ nChansBy2;
      } while (!(br_j & nChansBy2));
    }

    y[yIdx + br_j].re = x[uIdx];
    y[yIdx + br_j].im = x[uIdx + 1];
  }
}

void MWDSPCG_R2DIT_TBLS_Z(creal_T y[], const int32_T nChans, const int32_T nRows,
  const int32_T fftLen, const int32_T offset, const real_T tablePtr[], const
  int32_T twiddleStep, const boolean_T isInverse)
{
  int32_T nHalf;
  real_T twidRe;
  real_T twidIm;
  int32_T nQtr;
  real_T fwdInvFactor;
  int32_T iCh;
  int32_T offsetCh;
  int32_T idelta;
  int32_T ix;
  int32_T k;
  int32_T kratio;
  int32_T istart;
  int32_T i1;
  int32_T j;
  int32_T i2;
  real_T tmp;
  real_T tmp_0;

  /* Signal Processing Blockset Decimation in Time FFT  */
  /* Computation performed using table lookup optimized for speed  */
  /* Output type: complex real_T */
  nHalf = (fftLen >> 1U) * twiddleStep;
  nQtr = nHalf >> 1U;
  fwdInvFactor = isInverse ? -1.0 : 1.0;

  /* For each channel */
  offsetCh = offset;
  for (iCh = 0; iCh < nChans; iCh = iCh + 1) {
    /* Perform butterflies for the first stage, where no multiply is required. */
    for (ix = offsetCh; ix < (fftLen - 1) + offsetCh; ix = ix + 2) {
      istart = ix + 1;
      twidRe = y[istart].re;
      twidIm = y[istart].im;
      y[istart].re = y[ix].re - twidRe;
      y[istart].im = y[ix].im - twidIm;
      y[ix].re = y[ix].re + twidRe;
      y[ix].im = y[ix].im + twidIm;
    }

    idelta = 2;
    k = fftLen >> 2U;
    kratio = k * twiddleStep;
    while (k > 0) {
      i1 = offsetCh;

      /* Perform the first butterfly in each remaining stage, where no multiply is required. */
      for (ix = 0; ix < k; ix = ix + 1) {
        istart = i1 + idelta;
        twidRe = y[istart].re;
        twidIm = y[istart].im;
        y[istart].re = y[i1].re - twidRe;
        y[istart].im = y[i1].im - twidIm;
        y[i1].re = y[i1].re + twidRe;
        y[i1].im = y[i1].im + twidIm;
        i1 = (idelta << 1U) + i1;
      }

      istart = offsetCh + 1;

      /* Perform remaining butterflies */
      for (j = kratio; j < nHalf; j = j + kratio) {
        i1 = istart;
        twidRe = tablePtr[j];
        twidIm = tablePtr[j + nQtr] * fwdInvFactor;
        for (ix = 0; ix < k; ix = ix + 1) {
          i2 = i1 + idelta;
          tmp = y[i2].re * twidRe - y[i2].im * twidIm;
          tmp_0 = y[i2].re * twidIm + y[i2].im * twidRe;
          y[i2].re = y[i1].re - tmp;
          y[i2].im = y[i1].im - tmp_0;
          y[i1].re = y[i1].re + tmp;
          y[i1].im = y[i1].im + tmp_0;
          i1 = (idelta << 1U) + i1;
        }

        istart = istart + 1;
      }

      idelta = idelta << 1U;
      k = k >> 1U;
      kratio = kratio >> 1U;
    }

    /* Point to next channel */
    offsetCh = offsetCh + nRows;
  }
}

void MWDSPCG_FFT_DblLen_Z_Tbl(creal_T y[], const int32_T nChans, const int32_T
  nRows, const real_T twiddleTable[], const int32_T twiddleStep)
{
  real_T tempOut0Re;
  real_T tempOut0Im;
  real_T tempOut1Re;
  real_T tempOut1Im;
  real_T temp2Re;
  int32_T N2;
  int32_T N4;
  int32_T W4;
  int32_T yIdx;
  int32_T ix;
  int32_T k;
  real_T tempOut1Im_0;

  /* In-place "double-length" data recovery
     Table-based mem-optimized twiddle computation

     Used to recover linear-ordered length-N point complex FFT result
     from a linear-ordered complex length-N/2 point FFT, performed
     on N interleaved real values.
   */
  N2 = nRows >> 1U;
  N4 = N2 >> 1U;
  W4 = N4 * twiddleStep;
  yIdx = (nChans - 1) * nRows;
  if (nRows > 2) {
    tempOut0Re = y[N4 + yIdx].re;
    tempOut0Im = y[N4 + yIdx].im;
    y[(N2 + N4) + yIdx].re = tempOut0Re;
    y[(N2 + N4) + yIdx].im = tempOut0Im;
    y[N4 + yIdx].re = tempOut0Re;
    y[N4 + yIdx].im = -tempOut0Im;
  }

  if (nRows > 1) {
    tempOut0Re = y[yIdx].re;
    tempOut0Re = tempOut0Re - y[yIdx].im;
    y[N2 + yIdx].re = tempOut0Re;
    y[N2 + yIdx].im = 0.0;
  }

  tempOut0Re = y[yIdx].re;
  tempOut0Re = tempOut0Re + y[yIdx].im;
  y[yIdx].re = tempOut0Re;
  y[yIdx].im = 0.0;
  k = twiddleStep;
  for (ix = 1; ix < N4; ix = ix + 1) {
    tempOut0Re = y[ix + yIdx].re;
    tempOut0Re = y[(N2 - ix) + yIdx].re + tempOut0Re;
    tempOut0Re = tempOut0Re / 2.0;
    temp2Re = tempOut0Re;
    tempOut0Re = y[ix + yIdx].im;
    tempOut0Re = tempOut0Re - y[(N2 - ix) + yIdx].im;
    tempOut0Re = tempOut0Re / 2.0;
    tempOut0Im = tempOut0Re;
    tempOut0Re = y[ix + yIdx].im;
    tempOut0Re = y[(N2 - ix) + yIdx].im + tempOut0Re;
    tempOut0Re = tempOut0Re / 2.0;
    tempOut1Re = tempOut0Re;
    tempOut0Re = y[(N2 - ix) + yIdx].re;
    tempOut0Re = tempOut0Re - y[ix + yIdx].re;
    tempOut0Re = tempOut0Re / 2.0;
    y[ix + yIdx].re = tempOut1Re;
    y[ix + yIdx].im = tempOut0Re;
    tempOut0Re = y[ix + yIdx].re * twiddleTable[k] - (-twiddleTable[W4 - k]) *
      y[ix + yIdx].im;
    tempOut1Im_0 = y[ix + yIdx].im * twiddleTable[k] + (-twiddleTable[W4 - k]) *
      y[ix + yIdx].re;
    tempOut1Re = tempOut0Re;
    tempOut1Im = tempOut1Im_0;
    y[ix + yIdx].re = temp2Re + tempOut0Re;
    y[ix + yIdx].im = tempOut0Im + tempOut1Im_0;
    tempOut0Re = y[ix + yIdx].re;
    tempOut1Im_0 = -y[ix + yIdx].im;
    y[(nRows - ix) + yIdx].re = tempOut0Re;
    y[(nRows - ix) + yIdx].im = tempOut1Im_0;
    y[(N2 + ix) + yIdx].re = temp2Re - tempOut1Re;
    y[(N2 + ix) + yIdx].im = tempOut0Im - tempOut1Im;
    tempOut0Re = y[(N2 + ix) + yIdx].re;
    tempOut1Im_0 = y[(N2 + ix) + yIdx].im;
    y[(N2 - ix) + yIdx].re = tempOut0Re;
    y[(N2 - ix) + yIdx].im = -tempOut1Im_0;
    k = k + twiddleStep;
  }
}

/* Initial conditions for atomic system: '<Root>/Spectrum Scope' */
void new_pll_fs_SpectrumScope_Init(SimStruct *const S)
{
  int32_T i;

  /* Signal Processing Blockset Buffer/Unbuffer (sdsprebuff2) - '<S24>/B_3_0' */
  ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_p = 2048;

  /* Copy ICs into circular buffer */
  {
    const int_T bufLenBytes = 4096 * sizeof(real_T);
    byte_T *circBufPtr = (byte_T *)&((D_Work *) ssGetRootDWork(S))
      ->Buffer_CircBuff_l[0];
    const byte_T *icPtr = (const byte_T *)&rtConstP.pooled1;
    int_T i = 1;
    while (i-- > 0) {
      MWDSP_CopyScalarICs(circBufPtr, icPtr, 4096, sizeof(real_T));
      circBufPtr += bufLenBytes;
    }
  }

  *&((D_Work *) ssGetRootDWork(S))->Buffer_IN_BUF_PTR_e = (void *)( (byte_T *)
    &((D_Work *) ssGetRootDWork(S))->Buffer_CircBuff_l[0] + 2048 * sizeof(real_T)
    );
  *&((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o = (void *)( (byte_T *)
    &((D_Work *) ssGetRootDWork(S))->Buffer_CircBuff_l[0] + 64 * sizeof(real_T) );
  ((D_Work *) ssGetRootDWork(S))->Buffer_SHIFT_PER_ELEM_b = sizeof(real_T);
  ((D_Work *) ssGetRootDWork(S))->Window_FLAG_m = FALSE;
  ((D_Work *) ssGetRootDWork(S))->DigitalFilter_CIRCBUFFIDX_m = 0;
  for (i = 0; i < 2048; i++) {
    ((D_Work *) ssGetRootDWork(S))->DigitalFilter_FILT_STATES_e[(i << 1)] = 0.0;
    ((D_Work *) ssGetRootDWork(S))->DigitalFilter_FILT_STATES_e[1 + (i << 1)] =
      0.0;
  }
}

/* Outputs for atomic system: '<Root>/Spectrum Scope' */
void new_pll_fs_SpectrumScope(SimStruct *const S)
{
  int32_T i;
  int32_T j;
  int32_T idx;
  int32_T idxW;
  int32_T idxN;
  real_T B_3_10_0;
  real_T B_3_6_0;

  /* Signal Processing Blockset Buffer/Unbuffer (sdsprebuff2) - '<S24>/B_3_0' */
  {
    /* Copy input samples to buffer */
    if (ssIsSampleHit(S, 2, 0)) {
      real_T **inBufPtr = (real_T **)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_IN_BUF_PTR_e;
      real_T *memBase = (real_T *)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_CircBuff_l[0];
      **inBufPtr = ((BlockIO *) _ssGetBlockIO(S))->B_6_11_0;
      *inBufPtr = (memBase + 4095 - *inBufPtr) ? (*inBufPtr+1) : memBase;

      /* buffer overrun protection */
      {
        const int_T bufLenTimesBpe = 4096 * sizeof(real_T);
        ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_p += 1;
        if (((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_p > 4096) {
          ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o = (byte_T *)
            ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o + (((D_Work *)
            ssGetRootDWork(S))->Buffer_bufferLength_p - 4096) * sizeof(real_T);
          if ((byte_T *)((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o >
              ((byte_T *)&((D_Work *) ssGetRootDWork(S))->Buffer_CircBuff_l[0] +
               bufLenTimesBpe)) {
            ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o = (byte_T *)
              ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o -
              bufLenTimesBpe;
          }

          ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_p = 4096;
        }
      }
    }

    /* Copy output samples from buffer */
    if (ssIsSampleHit(S, 3, 0)) {
      /* buffer underrun protection */
      {
        const int_T bufLenTimesBpe = 4096 * sizeof(real_T);
        ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_p -= 1984;
        if (((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_p < 64) {
          ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o = (byte_T *)
            ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o + (((D_Work *)
            ssGetRootDWork(S))->Buffer_bufferLength_p - 64) * sizeof(real_T);
          if ((byte_T *)((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o <
              (byte_T *)&((D_Work *) ssGetRootDWork(S))->Buffer_CircBuff_l[0]) {
            ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o = (byte_T *)
              ((D_Work *) ssGetRootDWork(S))->Buffer_OUT_BUF_PTR_o +
              bufLenTimesBpe;
          }

          ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength_p = 64;
        }
      }

      MWDSP_Buf_OutputFrame_1ch((byte_T *)((BlockIO *) _ssGetBlockIO(S))
        ->B_3_0_0, (byte_T **)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_OUT_BUF_PTR_o, (byte_T *)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_CircBuff_l[0], ((D_Work *) ssGetRootDWork(S))
        ->Buffer_SHIFT_PER_ELEM_b, 4096 * sizeof(real_T) ,2048, 64 * sizeof
        (real_T));
    }
  }

  if (ssIsSampleHit(S, 3, 0)) {
    idx = 0;
    idxW = 0;
    for (i = 0; i < 2048; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_3_3_0[idx] = ((BlockIO *) _ssGetBlockIO
        (S))->B_3_0_0[idx] * rtConstP.pooled2[idxW];
      idx++;
      idxW++;
    }

    if (!((D_Work *) ssGetRootDWork(S))->Window_FLAG_m) {
      ((D_Work *) ssGetRootDWork(S))->Window_FLAG_m = TRUE;
      idxW = 0;
      for (i = 0; i < 2048; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_3_1_1[idxW] = rtConstP.pooled2[idxW];
        idxW++;
      }
    }

    MWDSPCG_FFT_Interleave_R2BR_D(&((BlockIO *) _ssGetBlockIO(S))->B_3_3_0[0],
                                  &((BlockIO *) _ssGetBlockIO(S))->B_3_2_0[0], 1,
      2048);
    MWDSPCG_R2DIT_TBLS_Z(&((BlockIO *) _ssGetBlockIO(S))->B_3_2_0[0], 1, 2048,
                         1024, 0, &rtConstP.pooled3[0], 2, FALSE);
    MWDSPCG_FFT_DblLen_Z_Tbl(&((BlockIO *) _ssGetBlockIO(S))->B_3_2_0[0], 1,
      2048, &rtConstP.pooled3[0], 1);
    for (i = 0; i < 2048; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_3_3_0[i] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_3_2_0[i].re * ((BlockIO *) _ssGetBlockIO(S))->B_3_2_0[i].re +
        ((BlockIO *) _ssGetBlockIO(S))->B_3_2_0[i].im * ((BlockIO *)
        _ssGetBlockIO(S))->B_3_2_0[i].im;
    }

    idx = 0;
    for (j = 0; j < 2048; j++) {
      idxW = j << 1;
      B_3_6_0 = ((BlockIO *) _ssGetBlockIO(S))->B_3_3_0[idx] * ((Parameters *)
        ssGetDefaultParam(S))->P_31[0];
      i = 1;
      for (idxN = ((D_Work *) ssGetRootDWork(S))->DigitalFilter_CIRCBUFFIDX_m;
           idxN < 1; idxN++) {
        B_3_6_0 += ((D_Work *) ssGetRootDWork(S))->
          DigitalFilter_FILT_STATES_e[idxW + idxN] * ((Parameters *)
          ssGetDefaultParam(S))->P_31[i];
        i++;
      }

      for (idxN = 0; idxN < ((D_Work *) ssGetRootDWork(S))
           ->DigitalFilter_CIRCBUFFIDX_m; idxN++) {
        B_3_6_0 += ((D_Work *) ssGetRootDWork(S))->
          DigitalFilter_FILT_STATES_e[idxW + idxN] * ((Parameters *)
          ssGetDefaultParam(S))->P_31[i];
        i++;
      }

      idxN = ((D_Work *) ssGetRootDWork(S))->DigitalFilter_CIRCBUFFIDX_m - 1;
      if (idxN < 0) {
        idxN = 0;
      }

      ((D_Work *) ssGetRootDWork(S))->DigitalFilter_FILT_STATES_e[idxW + idxN] =
        ((BlockIO *) _ssGetBlockIO(S))->B_3_3_0[idx];
      ((BlockIO *) _ssGetBlockIO(S))->B_3_4_0[idx] = B_3_6_0;
      idx++;
    }

    ((D_Work *) ssGetRootDWork(S))->DigitalFilter_CIRCBUFFIDX_m = idxN;
    B_3_6_0 = 0.0;
    for (i = 0; i < 2048; i++) {
      B_3_6_0 += ((BlockIO *) _ssGetBlockIO(S))->B_3_1_1[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_3_1_1[i];
    }

    B_3_6_0 = 1.0 / B_3_6_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_3_9_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_3_8_0[0];
    B_3_10_0 = ((BlockIO *) _ssGetBlockIO(S))->B_3_7_0[0] / ((BlockIO *)
      _ssGetBlockIO(S))->B_3_9_0;
    for (i = 0; i < 2048; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_3_11_0[i] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_3_4_0[i] * B_3_6_0 * B_3_10_0;
    }
  }
}

/* Update for atomic system: '<Root>/Spectrum Scope' */
void new_pll_fs_SpectrumScope_Update(SimStruct *const S)
{
  if (ssIsSampleHit(S, 3, 0)) {
    /* Update for M-S-Function: '<S14>/Frame Scope' */
    /* Call into Simulink */
    ssCallAccelRunBlock(S, 3, 12, SS_CALL_MDL_UPDATE);
  }
}

/* Termination for atomic system: '<Root>/Spectrum Scope' */
void new_pll_fs_SpectrumScope_Term(SimStruct *const S)
{
  /* Terminate for M-S-Function: '<S14>/Frame Scope' */
  /* Call into Simulink */
  ssCallAccelRunBlock(S, 3, 12, SS_CALL_MDL_TERMINATE);
}

/* Initial conditions for atomic system: '<Root>/Spectrum Scope1' */
void new_pll_fs_SpectrumScope1_Init(SimStruct *const S)
{
  int32_T i;

  /* Signal Processing Blockset Buffer/Unbuffer (sdsprebuff2) - '<S32>/B_4_0' */
  ((D_Work *) ssGetRootDWork(S))->Buffer_bufferLength = 2048;

  /* Copy ICs into circular buffer */
  {
    const int_T bufLenBytes = 4096 * sizeof(real_T);
    byte_T *circBufPtr = (byte_T *)&((D_Work *) ssGetRootDWork(S))
      ->Buffer_CircBuff[0];
    const byte_T *icPtr = (const byte_T *)&rtConstP.pooled1;
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
  ((D_Work *) ssGetRootDWork(S))->Buffer_SHIFT_PER_ELEM = sizeof(real_T);
  ((D_Work *) ssGetRootDWork(S))->Window_FLAG = FALSE;
  ((D_Work *) ssGetRootDWork(S))->DigitalFilter_CIRCBUFFIDX = 0;
  for (i = 0; i < 2048; i++) {
    ((D_Work *) ssGetRootDWork(S))->DigitalFilter_FILT_STATES[(i << 1)] = 0.0;
    ((D_Work *) ssGetRootDWork(S))->DigitalFilter_FILT_STATES[1 + (i << 1)] =
      0.0;
  }
}

/* Outputs for atomic system: '<Root>/Spectrum Scope1' */
void new_pll_fs_SpectrumScope1(SimStruct *const S)
{
  int32_T i;
  int32_T j;
  int32_T idx;
  int32_T idxW;
  int32_T idxN;
  real_T B_4_10_0;
  real_T B_4_6_0;

  /* Signal Processing Blockset Buffer/Unbuffer (sdsprebuff2) - '<S32>/B_4_0' */
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
        ->B_4_0_0, (byte_T **)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_OUT_BUF_PTR, (byte_T *)&((D_Work *) ssGetRootDWork(S))
        ->Buffer_CircBuff[0], ((D_Work *) ssGetRootDWork(S))
        ->Buffer_SHIFT_PER_ELEM, 4096 * sizeof(real_T) ,2048, 64 * sizeof(real_T));
    }
  }

  if (ssIsSampleHit(S, 3, 0)) {
    idx = 0;
    idxW = 0;
    for (i = 0; i < 2048; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_4_3_0[idx] = ((BlockIO *) _ssGetBlockIO
        (S))->B_4_0_0[idx] * rtConstP.pooled2[idxW];
      idx++;
      idxW++;
    }

    if (!((D_Work *) ssGetRootDWork(S))->Window_FLAG) {
      ((D_Work *) ssGetRootDWork(S))->Window_FLAG = TRUE;
      idxW = 0;
      for (i = 0; i < 2048; i++) {
        ((BlockIO *) _ssGetBlockIO(S))->B_4_1_1[idxW] = rtConstP.pooled2[idxW];
        idxW++;
      }
    }

    MWDSPCG_FFT_Interleave_R2BR_D(&((BlockIO *) _ssGetBlockIO(S))->B_4_3_0[0],
                                  &((BlockIO *) _ssGetBlockIO(S))->B_4_2_0[0], 1,
      2048);
    MWDSPCG_R2DIT_TBLS_Z(&((BlockIO *) _ssGetBlockIO(S))->B_4_2_0[0], 1, 2048,
                         1024, 0, &rtConstP.pooled3[0], 2, FALSE);
    MWDSPCG_FFT_DblLen_Z_Tbl(&((BlockIO *) _ssGetBlockIO(S))->B_4_2_0[0], 1,
      2048, &rtConstP.pooled3[0], 1);
    for (i = 0; i < 2048; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_4_3_0[i] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_4_2_0[i].re * ((BlockIO *) _ssGetBlockIO(S))->B_4_2_0[i].re +
        ((BlockIO *) _ssGetBlockIO(S))->B_4_2_0[i].im * ((BlockIO *)
        _ssGetBlockIO(S))->B_4_2_0[i].im;
    }

    idx = 0;
    for (j = 0; j < 2048; j++) {
      idxW = j << 1;
      B_4_6_0 = ((BlockIO *) _ssGetBlockIO(S))->B_4_3_0[idx] * ((Parameters *)
        ssGetDefaultParam(S))->P_32[0];
      i = 1;
      for (idxN = ((D_Work *) ssGetRootDWork(S))->DigitalFilter_CIRCBUFFIDX;
           idxN < 1; idxN++) {
        B_4_6_0 += ((D_Work *) ssGetRootDWork(S))->
          DigitalFilter_FILT_STATES[idxW + idxN] * ((Parameters *)
          ssGetDefaultParam(S))->P_32[i];
        i++;
      }

      for (idxN = 0; idxN < ((D_Work *) ssGetRootDWork(S))
           ->DigitalFilter_CIRCBUFFIDX; idxN++) {
        B_4_6_0 += ((D_Work *) ssGetRootDWork(S))->
          DigitalFilter_FILT_STATES[idxW + idxN] * ((Parameters *)
          ssGetDefaultParam(S))->P_32[i];
        i++;
      }

      idxN = ((D_Work *) ssGetRootDWork(S))->DigitalFilter_CIRCBUFFIDX - 1;
      if (idxN < 0) {
        idxN = 0;
      }

      ((D_Work *) ssGetRootDWork(S))->DigitalFilter_FILT_STATES[idxW + idxN] =
        ((BlockIO *) _ssGetBlockIO(S))->B_4_3_0[idx];
      ((BlockIO *) _ssGetBlockIO(S))->B_4_4_0[idx] = B_4_6_0;
      idx++;
    }

    ((D_Work *) ssGetRootDWork(S))->DigitalFilter_CIRCBUFFIDX = idxN;
    B_4_6_0 = 0.0;
    for (i = 0; i < 2048; i++) {
      B_4_6_0 += ((BlockIO *) _ssGetBlockIO(S))->B_4_1_1[i] * ((BlockIO *)
        _ssGetBlockIO(S))->B_4_1_1[i];
    }

    B_4_6_0 = 1.0 / B_4_6_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_4_9_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_4_8_0[0];
    B_4_10_0 = ((BlockIO *) _ssGetBlockIO(S))->B_4_7_0[0] / ((BlockIO *)
      _ssGetBlockIO(S))->B_4_9_0;
    for (i = 0; i < 2048; i++) {
      ((BlockIO *) _ssGetBlockIO(S))->B_4_11_0[i] = ((BlockIO *) _ssGetBlockIO(S))
        ->B_4_4_0[i] * B_4_6_0 * B_4_10_0;
    }
  }
}

/* Update for atomic system: '<Root>/Spectrum Scope1' */
void new_pll_fs_SpectrumScope1_Update(SimStruct *const S)
{
  if (ssIsSampleHit(S, 3, 0)) {
    /* Update for M-S-Function: '<S15>/Frame Scope' */
    /* Call into Simulink */
    ssCallAccelRunBlock(S, 4, 12, SS_CALL_MDL_UPDATE);
  }
}

/* Termination for atomic system: '<Root>/Spectrum Scope1' */
void new_pll_fs_SpectrumScope1_Term(SimStruct *const S)
{
  /* Terminate for M-S-Function: '<S15>/Frame Scope' */
  /* Call into Simulink */
  ssCallAccelRunBlock(S, 4, 12, SS_CALL_MDL_TERMINATE);
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  /* local block i/o variables */
  real_T B_6_39_0;
  real_T B_6_25_0;
  real_T B_6_13_0;
  real_T B_6_67_0;
  real_T B_0_5_0;
  real_T B_0_8_0;
  real_T B_0_11_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_6_0_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_33 * ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE;
  if (ssIsMajorTimeStep(S)) {
    ((D_Work *) ssGetRootDWork(S))->Abs_MODE = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_0_0 >= 0.0 ? 1 : 0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_6_1_0 = ((D_Work *) ssGetRootDWork(S))
    ->Abs_MODE > 0 ? ((BlockIO *) _ssGetBlockIO(S))->B_6_0_0 : -((BlockIO *)
    _ssGetBlockIO(S))->B_6_0_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_2_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_34;
    if (ssIsMajorTimeStep(S)) {
      ((D_Work *) ssGetRootDWork(S))->RelationalOperator_Mode = (((BlockIO *)
        _ssGetBlockIO(S))->B_6_1_0 >= ((BlockIO *) _ssGetBlockIO(S))->B_6_2_0);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_6_3_0 = ((D_Work *) ssGetRootDWork(S))
      ->RelationalOperator_Mode;
  }

  B_6_25_0 = muDoubleScalarRem(((BlockIO *) _ssGetBlockIO(S))->B_6_0_0,
    ((BlockIO *) _ssGetBlockIO(S))->B_6_2_0);
  if ((((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime == (rtMinusInf)) ||
      (((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime == ssGetTaskTime(S,0)))
  {
    ((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime = ssGetTaskTime(S,0);
    ((BlockIO *) _ssGetBlockIO(S))->B_6_5_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_35;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_5_0 = B_6_25_0;
  }

  /* Integrator: '<S23>/Integrator' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = ((ZCEventType) (((BlockIO *) _ssGetBlockIO(S))->B_6_3_0 &&
                (((PrevZCSigStates *) _ssGetPrevZCSigState(S))
                 ->Integrator_Reset_ZCE != POS_ZCSIG)));

    /* evaluate zero-crossings */
    ((PrevZCSigStates *) _ssGetPrevZCSigState(S))->Integrator_Reset_ZCE =
      (ZCSigState) ((BlockIO *) _ssGetBlockIO(S))->B_6_3_0;
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

  B_6_25_0 = ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE;

  /* Communications Blockset Inherit Shape (scominhshape) - '<S20>/B_6_1' */
  B_6_25_0 = muDoubleScalarCos(B_6_25_0 * 6.2831853071795862);

  /* Communications Blockset Inherit Shape (scominhshape) - '<S3>/B_6_2' */
  ((BlockIO *) _ssGetBlockIO(S))->B_6_9_0 = B_6_25_0;

  /* Scope: '<Root>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 6, 10, SS_CALL_MDL_OUTPUTS);
  ((BlockIO *) _ssGetBlockIO(S))->B_6_11_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_36 * ((BlockIO *) _ssGetBlockIO(S))->B_6_9_0;
  new_pll_fs_SpectrumScope(S);
  if (ssIsSampleHit(S, 1, 0)) {
    B_6_13_0 = ((Parameters *) ssGetDefaultParam(S))->P_37;
    B_6_67_0 = ((Parameters *) ssGetDefaultParam(S))->P_38;
    ((BlockIO *) _ssGetBlockIO(S))->B_6_15_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_39;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_6_16_0 = ((BlockIO *) _ssGetBlockIO(S))
    ->B_6_9_0 < 0.0 ? (-muDoubleScalarFloor(muDoubleScalarAbs(((BlockIO *)
    _ssGetBlockIO(S))->B_6_9_0 / ((Parameters *) ssGetDefaultParam(S))->P_40) +
    0.5)) * ((Parameters *) ssGetDefaultParam(S))->P_40 : muDoubleScalarFloor
    (muDoubleScalarAbs(((BlockIO *) _ssGetBlockIO(S))->B_6_9_0 / ((Parameters *)
       ssGetDefaultParam(S))->P_40) + 0.5) * ((Parameters *) ssGetDefaultParam(S))
    ->P_40;
  ((BlockIO *) _ssGetBlockIO(S))->B_6_17_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_41 * ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_d;
  if (ssIsMajorTimeStep(S)) {
    ((D_Work *) ssGetRootDWork(S))->Abs_MODE_f = ((BlockIO *) _ssGetBlockIO(S)
      )->B_6_17_0 >= 0.0 ? 1 : 0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_6_18_0 = ((D_Work *) ssGetRootDWork(S))
    ->Abs_MODE_f > 0 ? ((BlockIO *) _ssGetBlockIO(S))->B_6_17_0 : -((BlockIO *)
    _ssGetBlockIO(S))->B_6_17_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_19_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_42;
    if (ssIsMajorTimeStep(S)) {
      ((D_Work *) ssGetRootDWork(S))->RelationalOperator_Mode_m = (((BlockIO *)
        _ssGetBlockIO(S))->B_6_18_0 >= ((BlockIO *) _ssGetBlockIO(S))->B_6_19_0);
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_6_20_0 = ((D_Work *) ssGetRootDWork(S))
      ->RelationalOperator_Mode_m;
  }

  B_6_25_0 = muDoubleScalarRem(((BlockIO *) _ssGetBlockIO(S))->B_6_17_0,
    ((BlockIO *) _ssGetBlockIO(S))->B_6_19_0);
  if ((((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime_h == (rtMinusInf)) ||
      (((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime_h == ssGetTaskTime(S,0)))
  {
    ((D_Work *) ssGetRootDWork(S))->IC_FirstOutputTime_h = ssGetTaskTime(S,0);
    ((BlockIO *) _ssGetBlockIO(S))->B_6_22_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_43;
  } else {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_22_0 = B_6_25_0;
  }

  /* Integrator: '<S45>/Integrator' */
  if (ssIsMajorTimeStep(S)) {
    ZCEventType zcEvent;
    boolean_T resetIntg = FALSE;
    zcEvent = ((ZCEventType) (((BlockIO *) _ssGetBlockIO(S))->B_6_20_0 &&
                (((PrevZCSigStates *) _ssGetPrevZCSigState(S))
                 ->Integrator_Reset_ZCE_i != POS_ZCSIG)));

    /* evaluate zero-crossings */
    ((PrevZCSigStates *) _ssGetPrevZCSigState(S))->Integrator_Reset_ZCE_i =
      (ZCSigState) ((BlockIO *) _ssGetBlockIO(S))->B_6_20_0;
    if (zcEvent || ((D_Work *) ssGetRootDWork(S))
        ->Integrator_IWORK_n.IcNeedsLoading) {
      resetIntg = TRUE;
      ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_d = ((BlockIO
        *) _ssGetBlockIO(S))->B_6_22_0;
    }

    if (resetIntg) {
      ssSetSolverNeedsReset(S);
      ssSetBlkStateChange(S);
    }

    ((D_Work *) ssGetRootDWork(S))->Integrator_IWORK_n.IcNeedsLoading = 0;
  }

  B_6_25_0 = ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_d;

  /* Communications Blockset Inherit Shape (scominhshape) - '<S42>/B_6_6' */
  B_6_25_0 = muDoubleScalarCos(B_6_25_0 * 6.2831853071795862);

  /* Communications Blockset Inherit Shape (scominhshape) - '<S17>/B_6_7' */
  ((BlockIO *) _ssGetBlockIO(S))->B_6_26_0 = B_6_25_0;
  if (ssIsMajorTimeStep(S)) {
    ((D_Work *) ssGetRootDWork(S))->Saturation_MODE = ((BlockIO *) _ssGetBlockIO
      (S))->B_6_26_0 >= ((Parameters *) ssGetDefaultParam(S))->P_44 ? 1 :
      ((BlockIO *) _ssGetBlockIO(S))->B_6_26_0 > ((Parameters *)
      ssGetDefaultParam(S))->P_45 ? 0 : -1;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_6_27_0 = ((D_Work *) ssGetRootDWork(S))
    ->Saturation_MODE == 1 ? ((Parameters *) ssGetDefaultParam(S))->P_44 :
    ((D_Work *) ssGetRootDWork(S))->Saturation_MODE == -1 ? ((Parameters *)
    ssGetDefaultParam(S))->P_45 : ((BlockIO *) _ssGetBlockIO(S))->B_6_26_0;
  if (ssIsSampleHit(S, 1, 0)) {
    if (ssIsMajorTimeStep(S) && (rt_ZCFcn(RISING_ZERO_CROSSING,
          &((PrevZCSigStates *) _ssGetPrevZCSigState(S))
          ->TriggeredSubsystem_Trig_ZCE,
          (((BlockIO *) _ssGetBlockIO(S))->B_6_27_0)) != NO_ZCEVENT)) {
      /* MATLABFcn: '<S16>/MATLAB Fcn' */
      /* Call into Simulink to run the Matlab Fcn block. */
      ssCallAccelRunBlock(S, 5, 0, SS_CALL_MDL_OUTPUTS);
      ((D_Work *) ssGetRootDWork(S))->TriggeredSubsystem_SubsysRanBC = 4;
    }

    ((BlockIO *) _ssGetBlockIO(S))->B_6_32_0 = (B_6_13_0 - B_6_67_0 * ((BlockIO *)
      _ssGetBlockIO(S))->B_6_15_0 * ((BlockIO *) _ssGetBlockIO(S))->B_5_0_0[0]) *
      muDoubleScalarAbs(((BlockIO *) _ssGetBlockIO(S))->B_5_0_0[1]);
  }

  new_pll_fs_SpectrumScope1(S);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_34_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_46 * ((BlockIO *) _ssGetBlockIO(S))->B_6_32_0;
  }

  /* StateSpace: '<S1>/State-Space' */
  {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_35_0 = (((Parameters *)
      ssGetDefaultParam(S))->P_49)*((ContinuousStates *) ssGetContStates(S))
      ->StateSpace_CSTATE;
    ((BlockIO *) _ssGetBlockIO(S))->B_6_35_0 += ((Parameters *)
      ssGetDefaultParam(S))->P_50*((BlockIO *) _ssGetBlockIO(S))->B_6_34_0;
  }

  /* StateSpace: '<S2>/State-Space' */
  {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_36_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_54*((ContinuousStates *) ssGetContStates(S))->StateSpace_CSTATE_m
      [1];
  }

  /* StateSpace: '<Root>/Analog Filter Design' */
  {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_37_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_59*((ContinuousStates *) ssGetContStates(S))
      ->AnalogFilterDesign_CSTATE[1];
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_38_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_62;
  }

  /* Integrator: '<Root>/Integrator' */
  B_6_39_0 = ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_p;
  ((BlockIO *) _ssGetBlockIO(S))->B_6_41_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_64 * B_6_39_0 + ((BlockIO *) _ssGetBlockIO(S))->B_6_38_0;

  /* Integrator: '<S4>/Integrator1'
   *
   * Regarding '<S4>/Integrator1':
   *  Limited Integrator
   */
  if (ssIsMajorTimeStep(S)) {
    if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_ls >=
        ((Parameters *) ssGetDefaultParam(S))->P_1 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_ls =
        ((Parameters *) ssGetDefaultParam(S))->P_1;
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_ls <=
               ((Parameters *) ssGetDefaultParam(S))->P_2 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_ls =
        ((Parameters *) ssGetDefaultParam(S))->P_2;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_0_0_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE_ls;

  /* Integrator: '<S4>/Integrator'
   *
   * Regarding '<S4>/Integrator':
   *  Limited Integrator
   */
  if (ssIsMajorTimeStep(S)) {
    if (((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_jp >=
        ((Parameters *) ssGetDefaultParam(S))->P_4 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_jp =
        ((Parameters *) ssGetDefaultParam(S))->P_4;
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_jp <=
               ((Parameters *) ssGetDefaultParam(S))->P_5 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_jp =
        ((Parameters *) ssGetDefaultParam(S))->P_5;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_0_1_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE_jp;

  /* Scope: '<S4>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 0, 2, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    B_0_5_0 = ((Parameters *) ssGetDefaultParam(S))->P_8;
    B_0_8_0 = ((Parameters *) ssGetDefaultParam(S))->P_9 * ((Parameters *)
      ssGetDefaultParam(S))->P_10;
    ((BlockIO *) _ssGetBlockIO(S))->B_0_10_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_8 / B_0_8_0 * ((BlockIO *) _ssGetBlockIO(S))->B_6_34_0;
    B_0_11_0 = ((Parameters *) ssGetDefaultParam(S))->P_7 * ((Parameters *)
      ssGetDefaultParam(S))->P_6;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_0_13_0 = B_0_5_0 * B_0_8_0 * B_0_11_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_0_14_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_0_1_0 - ((BlockIO *) _ssGetBlockIO(S))->B_0_0_0) * ((BlockIO *)
    _ssGetBlockIO(S))->B_0_13_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_1_0_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE_j;

  /* Integrator: '<S5>/Integrator1'
   *
   * Regarding '<S5>/Integrator1':
   *  Limited Integrator
   */
  if (ssIsMajorTimeStep(S)) {
    if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_l >=
        ((Parameters *) ssGetDefaultParam(S))->P_13 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_l =
        ((Parameters *) ssGetDefaultParam(S))->P_13;
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_l <=
               ((Parameters *) ssGetDefaultParam(S))->P_14 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_l =
        ((Parameters *) ssGetDefaultParam(S))->P_14;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_1_1_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE_l;

  /* Scope: '<S5>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 1, 2, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_1_5_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_17;
    ((BlockIO *) _ssGetBlockIO(S))->B_1_6_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_34_0 * ((BlockIO *) _ssGetBlockIO(S))->B_1_5_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_1_10_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_16 * ((Parameters *) ssGetDefaultParam(S))->P_15;
    ((BlockIO *) _ssGetBlockIO(S))->B_1_11_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_18 * ((Parameters *) ssGetDefaultParam(S))->P_19 * ((BlockIO *)
      _ssGetBlockIO(S))->B_6_34_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_1_13_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_1_0_0 + ((BlockIO *) _ssGetBlockIO(S))->B_1_11_0) * ((BlockIO *)
    _ssGetBlockIO(S))->B_1_5_0 / ((BlockIO *) _ssGetBlockIO(S))->B_1_10_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_2_0_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator_CSTATE_k;

  /* Integrator: '<S6>/Integrator1'
   *
   * Regarding '<S6>/Integrator1':
   *  Limited Integrator
   */
  if (ssIsMajorTimeStep(S)) {
    if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE >=
        ((Parameters *) ssGetDefaultParam(S))->P_22 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE =
        ((Parameters *) ssGetDefaultParam(S))->P_22;
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE <=
               ((Parameters *) ssGetDefaultParam(S))->P_23 ) {
      ((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE =
        ((Parameters *) ssGetDefaultParam(S))->P_23;
    }
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_2_1_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator1_CSTATE;

  /* Scope: '<S6>/Scope' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 2, 2, SS_CALL_MDL_OUTPUTS);
  ((BlockIO *) _ssGetBlockIO(S))->B_2_3_0 = ((ContinuousStates *)
    ssGetContStates(S))->Integrator2_CSTATE;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_2_5_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_26;
    ((BlockIO *) _ssGetBlockIO(S))->B_2_7_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_28;
    ((BlockIO *) _ssGetBlockIO(S))->B_2_8_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_34_0 * ((BlockIO *) _ssGetBlockIO(S))->B_2_7_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_2_12_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_27 * ((Parameters *) ssGetDefaultParam(S))->P_25;
    ((BlockIO *) _ssGetBlockIO(S))->B_2_13_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_29 * ((Parameters *) ssGetDefaultParam(S))->P_30 * ((BlockIO *)
      _ssGetBlockIO(S))->B_6_34_0;
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_2_15_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_2_0_0 + ((BlockIO *) _ssGetBlockIO(S))->B_2_13_0) * ((BlockIO *)
    _ssGetBlockIO(S))->B_2_7_0 / ((BlockIO *) _ssGetBlockIO(S))->B_2_12_0;
  ((BlockIO *) _ssGetBlockIO(S))->B_2_17_0 = (((BlockIO *) _ssGetBlockIO(S))
    ->B_2_1_0 - ((BlockIO *) _ssGetBlockIO(S))->B_2_3_0) * ((BlockIO *)
    _ssGetBlockIO(S))->B_2_7_0 * ((BlockIO *) _ssGetBlockIO(S))->B_2_5_0;
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_45_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_72;

    /* S-Function (sfblk_manswitch): '<S7>/S-Function' */
    ((BlockIO *) _ssGetBlockIO(S))->B_6_46_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_45_0;
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  ((BlockIO *) _ssGetBlockIO(S))->B_6_47_0 = ((Parameters *) ssGetDefaultParam(S))
    ->P_67*((ContinuousStates *) ssGetContStates(S))->TransferFcn_CSTATE;
  ssCallAccelRunBlock(S, 6, 48, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_49_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_74;

    /* S-Function (sfblk_manswitch): '<S8>/S-Function' */
    ((BlockIO *) _ssGetBlockIO(S))->B_6_50_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_49_0;
  }

  ssCallAccelRunBlock(S, 6, 51, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_52_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_76;

    /* S-Function (sfblk_manswitch): '<S9>/S-Function' */
    ((BlockIO *) _ssGetBlockIO(S))->B_6_53_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_52_0;
  }

  ssCallAccelRunBlock(S, 6, 54, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_55_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_78;

    /* S-Function (sfblk_manswitch): '<S10>/S-Function' */
    ((BlockIO *) _ssGetBlockIO(S))->B_6_56_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_55_0;
  }

  ssCallAccelRunBlock(S, 6, 57, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_58_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_80;

    /* S-Function (sfblk_manswitch): '<S11>/S-Function' */
    ((BlockIO *) _ssGetBlockIO(S))->B_6_59_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_58_0;
  }

  ssCallAccelRunBlock(S, 6, 60, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_61_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_82;

    /* S-Function (sfblk_manswitch): '<S12>/S-Function' */
    ((BlockIO *) _ssGetBlockIO(S))->B_6_62_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_61_0;
    ((BlockIO *) _ssGetBlockIO(S))->B_6_63_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_83;

    /* S-Function (sfblk_manswitch): '<S13>/S-Function' */
    ((BlockIO *) _ssGetBlockIO(S))->B_6_64_0 = ((BlockIO *) _ssGetBlockIO(S))
      ->B_6_63_0;
  }

  ssCallAccelRunBlock(S, 6, 65, SS_CALL_MDL_OUTPUTS);
  ssCallAccelRunBlock(S, 6, 66, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_6_69_0 = ((Parameters *) ssGetDefaultParam
      (S))->P_71 * ((BlockIO *) _ssGetBlockIO(S))->B_6_15_0 + ((Parameters *)
      ssGetDefaultParam(S))->P_70;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  new_pll_fs_SpectrumScope_Update(S);
  new_pll_fs_SpectrumScope1_Update(S);

  /* Update for Integrator: '<S4>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_ls ==
        ((Parameters *) ssGetDefaultParam(S))->P_1) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d) {
       case INTG_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_0_14_0 < 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d =
            INTG_LEAVING_UPPER_SAT;
        }
        break;

       case INTG_LEAVING_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_0_14_0 >= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(S);
        }
        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_0_14_0 < 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d =
            INTG_LEAVING_UPPER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d = INTG_UPPER_SAT;
        }
        break;
      }
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_ls ==
               ((Parameters *) ssGetDefaultParam(S))->P_2) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d) {
       case INTG_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_0_14_0 > 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d =
            INTG_LEAVING_LOWER_SAT;
        }
        break;

       case INTG_LEAVING_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_0_14_0 <= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(S);
        }
        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_0_14_0 > 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d =
            INTG_LEAVING_LOWER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d = INTG_LOWER_SAT;
        }
        break;
      }
    } else {
      ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d = INTG_NORMAL;
    }
  }

  /* Update for Integrator: '<S4>/Integrator' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_jp ==
        ((Parameters *) ssGetDefaultParam(S))->P_4) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator_MODE) {
       case INTG_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_0_10_0 < 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE =
            INTG_LEAVING_UPPER_SAT;
        }
        break;

       case INTG_LEAVING_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_0_10_0 >= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(S);
        }
        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_0_10_0 < 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE =
            INTG_LEAVING_UPPER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE = INTG_UPPER_SAT;
        }
        break;
      }
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator_CSTATE_jp ==
               ((Parameters *) ssGetDefaultParam(S))->P_5) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator_MODE) {
       case INTG_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_0_10_0 > 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE =
            INTG_LEAVING_LOWER_SAT;
        }
        break;

       case INTG_LEAVING_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_0_10_0 <= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator_MODE = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(S);
        }
        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_0_10_0 > 0.0) {
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

  /* Update for Integrator: '<S5>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_l ==
        ((Parameters *) ssGetDefaultParam(S))->P_13) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m) {
       case INTG_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_13_0 < 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m =
            INTG_LEAVING_UPPER_SAT;
        }
        break;

       case INTG_LEAVING_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_13_0 >= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(S);
        }
        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_13_0 < 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m =
            INTG_LEAVING_UPPER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m = INTG_UPPER_SAT;
        }
        break;
      }
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE_l ==
               ((Parameters *) ssGetDefaultParam(S))->P_14) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m) {
       case INTG_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_13_0 > 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m =
            INTG_LEAVING_LOWER_SAT;
        }
        break;

       case INTG_LEAVING_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_13_0 <= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(S);
        }
        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_1_13_0 > 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m =
            INTG_LEAVING_LOWER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m = INTG_LOWER_SAT;
        }
        break;
      }
    } else {
      ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m = INTG_NORMAL;
    }
  }

  /* Update for Integrator: '<S6>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE ==
        ((Parameters *) ssGetDefaultParam(S))->P_22) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE) {
       case INTG_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_2_15_0 < 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE =
            INTG_LEAVING_UPPER_SAT;
        }
        break;

       case INTG_LEAVING_UPPER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_2_15_0 >= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(S);
        }
        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_2_15_0 < 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE =
            INTG_LEAVING_UPPER_SAT;
        } else {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE = INTG_UPPER_SAT;
        }
        break;
      }
    } else if (((ContinuousStates *) ssGetContStates(S))->Integrator1_CSTATE ==
               ((Parameters *) ssGetDefaultParam(S))->P_23) {
      switch (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE) {
       case INTG_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_2_15_0 > 0.0) {
          ssSetSolverNeedsReset(S);
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE =
            INTG_LEAVING_LOWER_SAT;
        }
        break;

       case INTG_LEAVING_LOWER_SAT:
        if (((BlockIO *) _ssGetBlockIO(S))->B_2_15_0 <= 0.0) {
          ((D_Work *) ssGetRootDWork(S))->Integrator1_MODE = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(S);
        }
        break;

       default:
        ssSetSolverNeedsReset(S);
        if (((BlockIO *) _ssGetBlockIO(S))->B_2_15_0 > 0.0) {
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

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES

static void mdlDerivatives(SimStruct *S)
{
  /* Derivatives for Integrator: '<S23>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE = ((BlockIO *)
      _ssGetBlockIO(S))->B_6_41_0;
  }

  /* Derivatives for Integrator: '<S45>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_d = ((BlockIO *)
      _ssGetBlockIO(S))->B_6_69_0;
  }

  /* Derivatives for StateSpace: '<S1>/State-Space' */
  {
    ((StateDerivatives *) ssGetdX(S))->StateSpace_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_47)*((ContinuousStates *) ssGetContStates(S))
      ->StateSpace_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->StateSpace_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_48*((BlockIO *) _ssGetBlockIO(S))->B_6_34_0;
  }

  /* Derivatives for StateSpace: '<S2>/State-Space' */
  {
    ((StateDerivatives *) ssGetdX(S))->StateSpace_CSTATE_m[0] = (((Parameters *)
      ssGetDefaultParam(S))->P_52[0])*((ContinuousStates *) ssGetContStates(S)
      )->StateSpace_CSTATE_m[0]
      + (((Parameters *) ssGetDefaultParam(S))->P_52[1])*((ContinuousStates *)
      ssGetContStates(S))->StateSpace_CSTATE_m[1];
    ((StateDerivatives *) ssGetdX(S))->StateSpace_CSTATE_m[0] += ((Parameters *)
      ssGetDefaultParam(S))->P_53*((BlockIO *) _ssGetBlockIO(S))->B_6_34_0;
    ((StateDerivatives *) ssGetdX(S))->StateSpace_CSTATE_m[1] = (((Parameters *)
      ssGetDefaultParam(S))->P_52[2])*((ContinuousStates *) ssGetContStates(S)
      )->StateSpace_CSTATE_m[0];
  }

  /* Derivatives for StateSpace: '<Root>/Analog Filter Design' */
  {
    ((StateDerivatives *) ssGetdX(S))->AnalogFilterDesign_CSTATE[0] =
      (((Parameters *) ssGetDefaultParam(S))->P_57[0])*((ContinuousStates *)
      ssGetContStates(S))->AnalogFilterDesign_CSTATE[0]
      + (((Parameters *) ssGetDefaultParam(S))->P_57[1])*((ContinuousStates *)
      ssGetContStates(S))->AnalogFilterDesign_CSTATE[1];
    ((StateDerivatives *) ssGetdX(S))->AnalogFilterDesign_CSTATE[0] +=
      ((Parameters *) ssGetDefaultParam(S))->P_58*((BlockIO *) _ssGetBlockIO(S)
      )->B_6_34_0;
    ((StateDerivatives *) ssGetdX(S))->AnalogFilterDesign_CSTATE[1] =
      (((Parameters *) ssGetDefaultParam(S))->P_57[2])*((ContinuousStates *)
      ssGetContStates(S))->AnalogFilterDesign_CSTATE[0];
  }

  /* Derivatives for Integrator: '<Root>/Integrator' */
  {
    ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_p = ((BlockIO *)
      _ssGetBlockIO(S))->B_6_66_0;
  }

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d != INTG_UPPER_SAT)
        && (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d != INTG_LOWER_SAT)
        ) {
      ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_ls = ((BlockIO *)
        _ssGetBlockIO(S))->B_0_14_0;
      ((StateDisabled *) ssGetContStateDisabled(S))->Integrator1_CSTATE_ls =
        FALSE;
    } else {
      /* in saturation */
      ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_ls = 0.0;
      if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d == INTG_UPPER_SAT)
          || (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d ==
              INTG_LOWER_SAT)) {
        ((StateDisabled *) ssGetContStateDisabled(S))->Integrator1_CSTATE_ls =
          TRUE;
      }
    }
  }

  /* Derivatives for Integrator: '<S4>/Integrator' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((((D_Work *) ssGetRootDWork(S))->Integrator_MODE != INTG_UPPER_SAT)
        && (((D_Work *) ssGetRootDWork(S))->Integrator_MODE != INTG_LOWER_SAT) )
    {
      ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_jp = ((BlockIO *)
        _ssGetBlockIO(S))->B_0_10_0;
      ((StateDisabled *) ssGetContStateDisabled(S))->Integrator_CSTATE_jp =
        FALSE;
    } else {
      /* in saturation */
      ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_jp = 0.0;
      if ((((D_Work *) ssGetRootDWork(S))->Integrator_MODE == INTG_UPPER_SAT) ||
          (((D_Work *) ssGetRootDWork(S))->Integrator_MODE == INTG_LOWER_SAT)) {
        ((StateDisabled *) ssGetContStateDisabled(S))->Integrator_CSTATE_jp =
          TRUE;
      }
    }
  }

  ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_j = ((BlockIO *)
    _ssGetBlockIO(S))->B_1_6_0;

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m != INTG_UPPER_SAT)
        && (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m != INTG_LOWER_SAT)
        ) {
      ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_l = ((BlockIO *)
        _ssGetBlockIO(S))->B_1_13_0;
      ((StateDisabled *) ssGetContStateDisabled(S))->Integrator1_CSTATE_l =
        FALSE;
    } else {
      /* in saturation */
      ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE_l = 0.0;
      if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m == INTG_UPPER_SAT)
          || (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m ==
              INTG_LOWER_SAT)) {
        ((StateDisabled *) ssGetContStateDisabled(S))->Integrator1_CSTATE_l =
          TRUE;
      }
    }
  }

  ((StateDerivatives *) ssGetdX(S))->Integrator_CSTATE_k = ((BlockIO *)
    _ssGetBlockIO(S))->B_2_8_0;

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE != INTG_UPPER_SAT)
        && (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE != INTG_LOWER_SAT) )
    {
      ((StateDerivatives *) ssGetdX(S))->Integrator1_CSTATE = ((BlockIO *)
        _ssGetBlockIO(S))->B_2_15_0;
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

  ((StateDerivatives *) ssGetdX(S))->Integrator2_CSTATE = ((BlockIO *)
    _ssGetBlockIO(S))->B_2_17_0;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  {
    ((StateDerivatives *) ssGetdX(S))->TransferFcn_CSTATE = (((Parameters *)
      ssGetDefaultParam(S))->P_65)*((ContinuousStates *) ssGetContStates(S))
      ->TransferFcn_CSTATE;
    ((StateDerivatives *) ssGetdX(S))->TransferFcn_CSTATE += ((Parameters *)
      ssGetDefaultParam(S))->P_66*((BlockIO *) _ssGetBlockIO(S))->B_6_34_0;
  }
}

/* ZeroCrossings for root system: '<Root>' */
#define MDL_ZERO_CROSSINGS

static void mdlZeroCrossings(SimStruct *S)
{
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))->Abs_AbsZc_ZC = ((BlockIO *)
    _ssGetBlockIO(S))->B_6_0_0;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
    ->RelationalOperator_RelopInput_ZC = ((BlockIO *) _ssGetBlockIO(S))->B_6_1_0
    - ((BlockIO *) _ssGetBlockIO(S))->B_6_2_0;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))->Abs_AbsZc_ZC_e = ((BlockIO *)
    _ssGetBlockIO(S))->B_6_17_0;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
    ->RelationalOperator_RelopInput_ZC_g = ((BlockIO *) _ssGetBlockIO(S))
    ->B_6_18_0 - ((BlockIO *) _ssGetBlockIO(S))->B_6_19_0;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))->Saturation_UprLim_ZC =
    ((BlockIO *) _ssGetBlockIO(S))->B_6_26_0 - ((Parameters *) ssGetDefaultParam
    (S))->P_44;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))->Saturation_LwrLim_ZC =
    ((BlockIO *) _ssGetBlockIO(S))->B_6_26_0 - ((Parameters *) ssGetDefaultParam
    (S))->P_45;
  ((ZCSignalValues *) ssGetSolverZcSignalVector(S))->TriggeredSubsystem_Trig_ZC =
    ((BlockIO *) _ssGetBlockIO(S))->B_6_27_0;

  /* ZeroCrossings for Integrator: '<S4>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for enter into limited region */
    if (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d ==
        INTG_LEAVING_UPPER_SAT && ((ContinuousStates *) ssGetContStates(S))
        ->Integrator1_CSTATE_ls >= ((Parameters *) ssGetDefaultParam(S))->P_1) {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator1_IntgUpLimit_ZC_d = 0.0;
    } else {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator1_IntgUpLimit_ZC_d = ((ContinuousStates *) ssGetContStates(S))
        ->Integrator1_CSTATE_ls - ((Parameters *) ssGetDefaultParam(S))->P_1;
    }

    if (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d ==
        INTG_LEAVING_LOWER_SAT &&((ContinuousStates *) ssGetContStates(S))
        ->Integrator1_CSTATE_ls <= ((Parameters *) ssGetDefaultParam(S))->P_2) {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator1_IntgLoLimit_ZC_i = 0.0;
    } else {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator1_IntgLoLimit_ZC_i = ((ContinuousStates *) ssGetContStates(S))
        ->Integrator1_CSTATE_ls - ((Parameters *) ssGetDefaultParam(S))->P_2;
    }

    /* zero crossings for leaving limited region */
    {
      boolean_T anyStateSaturated = FALSE;
      if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d == INTG_UPPER_SAT)
          ||
          (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_d == INTG_LOWER_SAT))
      {
        anyStateSaturated = TRUE;
      }

      if (anyStateSaturated) {
        ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
          ->Integrator1_LeaveSaturate_ZC_j = ((BlockIO *) _ssGetBlockIO(S))
          ->B_0_14_0;
      } else {
        ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
          ->Integrator1_LeaveSaturate_ZC_j = 0.0;
      }
    }
  }

  /* ZeroCrossings for Integrator: '<S4>/Integrator' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for enter into limited region */
    if (((D_Work *) ssGetRootDWork(S))->Integrator_MODE ==
        INTG_LEAVING_UPPER_SAT && ((ContinuousStates *) ssGetContStates(S))
        ->Integrator_CSTATE_jp >= ((Parameters *) ssGetDefaultParam(S))->P_4) {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator_IntgUpLimit_ZC = 0.0;
    } else {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator_IntgUpLimit_ZC = ((ContinuousStates *) ssGetContStates(S)
        )->Integrator_CSTATE_jp - ((Parameters *) ssGetDefaultParam(S))->P_4;
    }

    if (((D_Work *) ssGetRootDWork(S))->Integrator_MODE ==
        INTG_LEAVING_LOWER_SAT &&((ContinuousStates *) ssGetContStates(S))
        ->Integrator_CSTATE_jp <= ((Parameters *) ssGetDefaultParam(S))->P_5) {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator_IntgLoLimit_ZC = 0.0;
    } else {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator_IntgLoLimit_ZC = ((ContinuousStates *) ssGetContStates(S)
        )->Integrator_CSTATE_jp - ((Parameters *) ssGetDefaultParam(S))->P_5;
    }
  }

  /* ZeroCrossings for Integrator: '<S5>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for enter into limited region */
    if (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m ==
        INTG_LEAVING_UPPER_SAT && ((ContinuousStates *) ssGetContStates(S))
        ->Integrator1_CSTATE_l >= ((Parameters *) ssGetDefaultParam(S))->P_13) {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator1_IntgUpLimit_ZC_b = 0.0;
    } else {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator1_IntgUpLimit_ZC_b = ((ContinuousStates *) ssGetContStates(S))
        ->Integrator1_CSTATE_l - ((Parameters *) ssGetDefaultParam(S))->P_13;
    }

    if (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m ==
        INTG_LEAVING_LOWER_SAT &&((ContinuousStates *) ssGetContStates(S))
        ->Integrator1_CSTATE_l <= ((Parameters *) ssGetDefaultParam(S))->P_14) {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator1_IntgLoLimit_ZC_m = 0.0;
    } else {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator1_IntgLoLimit_ZC_m = ((ContinuousStates *) ssGetContStates(S))
        ->Integrator1_CSTATE_l - ((Parameters *) ssGetDefaultParam(S))->P_14;
    }

    /* zero crossings for leaving limited region */
    {
      boolean_T anyStateSaturated = FALSE;
      if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m == INTG_UPPER_SAT)
          ||
          (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE_m == INTG_LOWER_SAT))
      {
        anyStateSaturated = TRUE;
      }

      if (anyStateSaturated) {
        ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
          ->Integrator1_LeaveSaturate_ZC_m = ((BlockIO *) _ssGetBlockIO(S))
          ->B_1_13_0;
      } else {
        ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
          ->Integrator1_LeaveSaturate_ZC_m = 0.0;
      }
    }
  }

  /* ZeroCrossings for Integrator: '<S6>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for enter into limited region */
    if (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE ==
        INTG_LEAVING_UPPER_SAT && ((ContinuousStates *) ssGetContStates(S))
        ->Integrator1_CSTATE >= ((Parameters *) ssGetDefaultParam(S))->P_22) {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator1_IntgUpLimit_ZC = 0.0;
    } else {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator1_IntgUpLimit_ZC = ((ContinuousStates *) ssGetContStates(S)
        )->Integrator1_CSTATE - ((Parameters *) ssGetDefaultParam(S))->P_22;
    }

    if (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE ==
        INTG_LEAVING_LOWER_SAT &&((ContinuousStates *) ssGetContStates(S))
        ->Integrator1_CSTATE <= ((Parameters *) ssGetDefaultParam(S))->P_23) {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator1_IntgLoLimit_ZC = 0.0;
    } else {
      ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
        ->Integrator1_IntgLoLimit_ZC = ((ContinuousStates *) ssGetContStates(S)
        )->Integrator1_CSTATE - ((Parameters *) ssGetDefaultParam(S))->P_23;
    }

    /* zero crossings for leaving limited region */
    {
      boolean_T anyStateSaturated = FALSE;
      if ((((D_Work *) ssGetRootDWork(S))->Integrator1_MODE == INTG_UPPER_SAT) ||
          (((D_Work *) ssGetRootDWork(S))->Integrator1_MODE == INTG_LOWER_SAT))
      {
        anyStateSaturated = TRUE;
      }

      if (anyStateSaturated) {
        ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
          ->Integrator1_LeaveSaturate_ZC = ((BlockIO *) _ssGetBlockIO(S))
          ->B_2_15_0;
      } else {
        ((ZCSignalValues *) ssGetSolverZcSignalVector(S))
          ->Integrator1_LeaveSaturate_ZC = 0.0;
      }
    }
  }
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{
  /* checksum */
  ssSetChecksumVal(S, 0, 434052570U);
  ssSetChecksumVal(S, 1, 299377420U);
  ssSetChecksumVal(S, 2, 2296692072U);
  ssSetChecksumVal(S, 3, 3370285253U);

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
