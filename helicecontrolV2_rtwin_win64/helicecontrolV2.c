/*
 * helicecontrolV2.c
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
#include "helicecontrolV2_dt.h"

/* options for Real-Time Windows Target board 0 */
static double RTWinBoardOptions0[] = {
  9600.0,
  8.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 2;
const double RTWinTimers[4] = {
  0.01, 0.0,
  0.1, 0.0,
};

/* list of Real-Time Windows Target boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "Standard_Devices/Serial_Port", 4U, 8, RTWinBoardOptions0 },
};

/* Block signals (auto storage) */
B_helicecontrolV2_T helicecontrolV2_B;

/* Block states (auto storage) */
DW_helicecontrolV2_T helicecontrolV2_DW;

/* Real-time model */
RT_MODEL_helicecontrolV2_T helicecontrolV2_M_;
RT_MODEL_helicecontrolV2_T *const helicecontrolV2_M = &helicecontrolV2_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(helicecontrolV2_M, 1);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (helicecontrolV2_M->Timing.TaskCounters.TID[1])++;
  if ((helicecontrolV2_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    helicecontrolV2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S1>/Switch Case Action Subsystem'
 *    '<S1>/Switch Case Action Subsystem1'
 *    '<S1>/Switch Case Action Subsystem2'
 *    '<S1>/Switch Case Action Subsystem3'
 *    '<S1>/Switch Case Action Subsystem4'
 */
void helicecontrolV2_SwitchCaseActionSubsystem(real_T rtu_In1,
  B_SwitchCaseActionSubsystem_helicecontrolV2_T *localB)
{
  /* Inport: '<S3>/In1' */
  localB->In1 = rtu_In1;
}

/* Model output function for TID0 */
void helicecontrolV2_output0(void)     /* Sample time: [0.01s, 0.0s] */
{
  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model update function for TID0 */
void helicecontrolV2_update0(void)     /* Sample time: [0.01s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++helicecontrolV2_M->Timing.clockTick0)) {
    ++helicecontrolV2_M->Timing.clockTickH0;
  }

  helicecontrolV2_M->Timing.t[0] = helicecontrolV2_M->Timing.clockTick0 *
    helicecontrolV2_M->Timing.stepSize0 + helicecontrolV2_M->Timing.clockTickH0 *
    helicecontrolV2_M->Timing.stepSize0 * 4294967296.0;
}

/* Model output function for TID1 */
void helicecontrolV2_output1(void)     /* Sample time: [0.1s, 0.0s] */
{
  int32_T j;
  int32_T cff;
  real_T rtb_Switch2;
  real_T rtb_Sum;

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (helicecontrolV2_DW.SwitchCaseActionSubsystem.SwitchCaseActionSubsystem_SubsysRanBC);

  /* S-Function Block: <Root>/Packet Input */
  {
    uint8_T indata[1U];
    int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 1U,
      &helicecontrolV2_P.PacketInput_PacketID, (double*) indata, NULL);
    if (status & 0x1) {
      RTWin_ANYTYPEPTR indp;
      indp.p_uint8_T = indata;
      helicecontrolV2_B.PacketInput = *indp.p_int8_T++;
    }
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Sum = (real_T)helicecontrolV2_B.PacketInput +
    helicecontrolV2_P.Constant_Value;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/ '
   *  Constant: '<Root>/  '
   */
  if (rtb_Sum >= helicecontrolV2_P.Switch_Threshold) {
    helicecontrolV2_B.Switch = helicecontrolV2_P._Value_n;
  } else {
    helicecontrolV2_B.Switch = helicecontrolV2_P._Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* S-Function (sdspcount2): '<Root>/Counter' */
  if (helicecontrolV2_B.Switch != 0.0) {
    helicecontrolV2_DW.Counter_Count = helicecontrolV2_P.Counter_InitialCount;
  }

  if (helicecontrolV2_B.PacketInput != 0) {
    if (helicecontrolV2_DW.Counter_Count < 25) {
      helicecontrolV2_DW.Counter_Count++;
    } else {
      helicecontrolV2_DW.Counter_Count = 0U;
    }
  }

  rtb_Switch2 = helicecontrolV2_DW.Counter_Count;

  /* End of S-Function (sdspcount2): '<Root>/Counter' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/ '
   */
  if (helicecontrolV2_B.Switch > helicecontrolV2_P.Switch1_Threshold) {
    rtb_Switch2 = helicecontrolV2_P._Value_n;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtb_Switch2 += helicecontrolV2_P.Constant3_Value;

  /* SwitchCase: '<S1>/Switch Case' */
  if (rtb_Switch2 < 0.0) {
    rtb_Switch2 = ceil(rtb_Switch2);
  } else {
    rtb_Switch2 = floor(rtb_Switch2);
  }

  if (rtIsNaN(rtb_Switch2) || rtIsInf(rtb_Switch2)) {
    rtb_Switch2 = 0.0;
  } else {
    rtb_Switch2 = fmod(rtb_Switch2, 4.294967296E+9);
  }

  switch (rtb_Switch2 < 0.0 ? -(int32_T)(uint32_T)-rtb_Switch2 : (int32_T)
          (uint32_T)rtb_Switch2) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    helicecontrolV2_SwitchCaseActionSubsystem(rtb_Sum,
      &helicecontrolV2_B.SwitchCaseActionSubsystem);

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    helicecontrolV2_SwitchCaseActionSubsystem(rtb_Sum,
      &helicecontrolV2_B.SwitchCaseActionSubsystem1);

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    helicecontrolV2_SwitchCaseActionSubsystem(rtb_Sum,
      &helicecontrolV2_B.SwitchCaseActionSubsystem2);

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem2' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem3' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    helicecontrolV2_SwitchCaseActionSubsystem(rtb_Sum,
      &helicecontrolV2_B.SwitchCaseActionSubsystem3);

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem3' */
    break;

   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem4' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    helicecontrolV2_SwitchCaseActionSubsystem(rtb_Sum,
      &helicecontrolV2_B.SwitchCaseActionSubsystem4);

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem4' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Switch: '<S2>/Switch2' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  if (helicecontrolV2_B.SwitchCaseActionSubsystem4.In1 >=
      helicecontrolV2_P.Switch2_Threshold) {
    rtb_Switch2 = helicecontrolV2_P.Constant4_Value;
  } else {
    rtb_Switch2 = helicecontrolV2_P.Constant5_Value;
  }

  /* End of Switch: '<S2>/Switch2' */

  /* Gain: '<Root>/Gain4' incorporates:
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S2>/Gain2'
   *  Gain: '<S2>/Gain3'
   *  Gain: '<S2>/Gain4'
   *  Product: '<S2>/Product'
   *  Sum: '<S2>/Sum1'
   */
  helicecontrolV2_B.Gain4 = (((helicecontrolV2_P.Gain4_Gain *
    helicecontrolV2_B.SwitchCaseActionSubsystem.In1 +
    helicecontrolV2_P.Gain1_Gain *
    helicecontrolV2_B.SwitchCaseActionSubsystem1.In1) +
    helicecontrolV2_P.Gain2_Gain *
    helicecontrolV2_B.SwitchCaseActionSubsystem2.In1) +
    helicecontrolV2_P.Gain3_Gain *
    helicecontrolV2_B.SwitchCaseActionSubsystem3.In1) * rtb_Switch2 *
    helicecontrolV2_P.Gain4_Gain_a;

  /* DiscreteFir: '<Root>/Discrete FIR Filter1' */
  rtb_Sum = helicecontrolV2_B.Gain4 *
    helicecontrolV2_P.DiscreteFIRFilter1_Coefficients[0];
  cff = 1;
  for (j = helicecontrolV2_DW.DiscreteFIRFilter1_circBuf; j < 5; j++) {
    rtb_Sum += helicecontrolV2_DW.DiscreteFIRFilter1_states[j] *
      helicecontrolV2_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < helicecontrolV2_DW.DiscreteFIRFilter1_circBuf; j++) {
    rtb_Sum += helicecontrolV2_DW.DiscreteFIRFilter1_states[j] *
      helicecontrolV2_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  helicecontrolV2_B.DiscreteFIRFilter1 = rtb_Sum;

  /* End of DiscreteFir: '<Root>/Discrete FIR Filter1' */

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  helicecontrolV2_B.Sum2 = (real_T)helicecontrolV2_B.PacketInput +
    helicecontrolV2_P.Constant1_Value;
}

/* Model update function for TID1 */
void helicecontrolV2_update1(void)     /* Sample time: [0.1s, 0.0s] */
{
  /* Update for DiscreteFir: '<Root>/Discrete FIR Filter1' */
  /* Update circular buffer index */
  helicecontrolV2_DW.DiscreteFIRFilter1_circBuf--;
  if (helicecontrolV2_DW.DiscreteFIRFilter1_circBuf < 0) {
    helicecontrolV2_DW.DiscreteFIRFilter1_circBuf = 4;
  }

  /* Update circular buffer */
  helicecontrolV2_DW.DiscreteFIRFilter1_states[helicecontrolV2_DW.DiscreteFIRFilter1_circBuf]
    = helicecontrolV2_B.Gain4;

  /* End of Update for DiscreteFir: '<Root>/Discrete FIR Filter1' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++helicecontrolV2_M->Timing.clockTick1)) {
    ++helicecontrolV2_M->Timing.clockTickH1;
  }

  helicecontrolV2_M->Timing.t[1] = helicecontrolV2_M->Timing.clockTick1 *
    helicecontrolV2_M->Timing.stepSize1 + helicecontrolV2_M->Timing.clockTickH1 *
    helicecontrolV2_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void helicecontrolV2_output(int_T tid)
{
  switch (tid) {
   case 0 :
    helicecontrolV2_output0();
    break;

   case 1 :
    helicecontrolV2_output1();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void helicecontrolV2_update(int_T tid)
{
  switch (tid) {
   case 0 :
    helicecontrolV2_update0();
    break;

   case 1 :
    helicecontrolV2_update1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void helicecontrolV2_initialize(void)
{
  {
    int32_T i;

    /* InitializeConditions for S-Function (sdspcount2): '<Root>/Counter' */
    helicecontrolV2_DW.Counter_Count = helicecontrolV2_P.Counter_InitialCount;

    /* InitializeConditions for DiscreteFir: '<Root>/Discrete FIR Filter1' */
    helicecontrolV2_DW.DiscreteFIRFilter1_circBuf = 0;
    for (i = 0; i < 5; i++) {
      helicecontrolV2_DW.DiscreteFIRFilter1_states[i] =
        helicecontrolV2_P.DiscreteFIRFilter1_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFir: '<Root>/Discrete FIR Filter1' */
  }
}

/* Model terminate function */
void helicecontrolV2_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  helicecontrolV2_output(tid);
}

void MdlUpdate(int_T tid)
{
  helicecontrolV2_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  helicecontrolV2_initialize();
}

void MdlTerminate(void)
{
  helicecontrolV2_terminate();
}

/* Registration function */
RT_MODEL_helicecontrolV2_T *helicecontrolV2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)helicecontrolV2_M, 0,
                sizeof(RT_MODEL_helicecontrolV2_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = helicecontrolV2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    helicecontrolV2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    helicecontrolV2_M->Timing.sampleTimes =
      (&helicecontrolV2_M->Timing.sampleTimesArray[0]);
    helicecontrolV2_M->Timing.offsetTimes =
      (&helicecontrolV2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    helicecontrolV2_M->Timing.sampleTimes[0] = (0.01);
    helicecontrolV2_M->Timing.sampleTimes[1] = (0.1);

    /* task offsets */
    helicecontrolV2_M->Timing.offsetTimes[0] = (0.0);
    helicecontrolV2_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(helicecontrolV2_M, &helicecontrolV2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = helicecontrolV2_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      helicecontrolV2_M->Timing.perTaskSampleHitsArray;
    helicecontrolV2_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    helicecontrolV2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(helicecontrolV2_M, -1);
  helicecontrolV2_M->Timing.stepSize0 = 0.01;
  helicecontrolV2_M->Timing.stepSize1 = 0.1;

  /* External mode info */
  helicecontrolV2_M->Sizes.checksums[0] = (1111136286U);
  helicecontrolV2_M->Sizes.checksums[1] = (3790569369U);
  helicecontrolV2_M->Sizes.checksums[2] = (1856824603U);
  helicecontrolV2_M->Sizes.checksums[3] = (2958827679U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    helicecontrolV2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &helicecontrolV2_DW.SwitchCaseActionSubsystem.SwitchCaseActionSubsystem_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &helicecontrolV2_DW.SwitchCaseActionSubsystem1.SwitchCaseActionSubsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &helicecontrolV2_DW.SwitchCaseActionSubsystem2.SwitchCaseActionSubsystem_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &helicecontrolV2_DW.SwitchCaseActionSubsystem3.SwitchCaseActionSubsystem_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &helicecontrolV2_DW.SwitchCaseActionSubsystem4.SwitchCaseActionSubsystem_SubsysRanBC;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(helicecontrolV2_M->extModeInfo,
      &helicecontrolV2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(helicecontrolV2_M->extModeInfo,
                        helicecontrolV2_M->Sizes.checksums);
    rteiSetTPtr(helicecontrolV2_M->extModeInfo, rtmGetTPtr(helicecontrolV2_M));
  }

  helicecontrolV2_M->solverInfoPtr = (&helicecontrolV2_M->solverInfo);
  helicecontrolV2_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&helicecontrolV2_M->solverInfo, 0.01);
  rtsiSetSolverMode(&helicecontrolV2_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  helicecontrolV2_M->ModelData.blockIO = ((void *) &helicecontrolV2_B);
  (void) memset(((void *) &helicecontrolV2_B), 0,
                sizeof(B_helicecontrolV2_T));

  /* parameters */
  helicecontrolV2_M->ModelData.defaultParam = ((real_T *)&helicecontrolV2_P);

  /* states (dwork) */
  helicecontrolV2_M->ModelData.dwork = ((void *) &helicecontrolV2_DW);
  (void) memset((void *)&helicecontrolV2_DW, 0,
                sizeof(DW_helicecontrolV2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    helicecontrolV2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  helicecontrolV2_M->Sizes.numContStates = (0);/* Number of continuous states */
  helicecontrolV2_M->Sizes.numY = (0); /* Number of model outputs */
  helicecontrolV2_M->Sizes.numU = (0); /* Number of model inputs */
  helicecontrolV2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  helicecontrolV2_M->Sizes.numSampTimes = (2);/* Number of sample times */
  helicecontrolV2_M->Sizes.numBlocks = (40);/* Number of blocks */
  helicecontrolV2_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  helicecontrolV2_M->Sizes.numBlockPrms = (26);/* Sum of parameter "widths" */
  return helicecontrolV2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
