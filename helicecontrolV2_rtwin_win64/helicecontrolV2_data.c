/*
 * helicecontrolV2_data.c
 *
 * Code generation for model "helicecontrolV2".
 *
 * Model version              : 1.13
 * Simulink Coder version : 8.7 (R2014b) 08-Sep-2014
 * C source code generated on : Mon May 09 21:20:10 2016
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "helicecontrolV2.h"
#include "helicecontrolV2_private.h"

/* Block parameters (auto storage) */
P_helicecontrolV2_T helicecontrolV2_P = {
  10.0,                                /* Mask Parameter: PacketInput_MaxMissedTicks
                                        * Referenced by: '<Root>/Packet Input'
                                        */
  0.0,                                 /* Mask Parameter: PacketInput_YieldWhenWaiting
                                        * Referenced by: '<Root>/Packet Input'
                                        */
  1,                                   /* Mask Parameter: PacketInput_PacketID
                                        * Referenced by: '<Root>/Packet Input'
                                        */
  0U,                                  /* Mask Parameter: Counter_InitialCount
                                        * Referenced by: '<Root>/Counter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/  '
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Constant5'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Constant4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/ '
                                        */
  -48.0,                               /* Expression: -48
                                        * Referenced by: '<Root>/Constant'
                                        */
  19.0,                                /* Expression: 19
                                        * Referenced by: '<Root>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S2>/Gain4'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S2>/Gain1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/Gain2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Gain3'
                                        */
  21.0,                                /* Expression: 21
                                        * Referenced by: '<S2>/Switch2'
                                        */
  0.01,                                /* Expression: .01
                                        * Referenced by: '<Root>/Gain4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Discrete FIR Filter1'
                                        */

  /*  Expression: [0.4 0.3 0.2 0.05 0.03 0.02]
   * Referenced by: '<Root>/Discrete FIR Filter1'
   */
  { 0.4, 0.3, 0.2, 0.05, 0.03, 0.02 },
  -48.0                                /* Expression: -48
                                        * Referenced by: '<Root>/Constant1'
                                        */
};
