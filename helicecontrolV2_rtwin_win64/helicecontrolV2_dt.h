/*
 * helicecontrolV2_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&helicecontrolV2_B.Switch), 0, 0, 4 },

  { (char_T *)(&helicecontrolV2_B.PacketInput), 2, 0, 1 },

  { (char_T *)(&helicecontrolV2_B.SwitchCaseActionSubsystem4.In1), 0, 0, 1 },

  { (char_T *)(&helicecontrolV2_B.SwitchCaseActionSubsystem3.In1), 0, 0, 1 },

  { (char_T *)(&helicecontrolV2_B.SwitchCaseActionSubsystem2.In1), 0, 0, 1 },

  { (char_T *)(&helicecontrolV2_B.SwitchCaseActionSubsystem1.In1), 0, 0, 1 },

  { (char_T *)(&helicecontrolV2_B.SwitchCaseActionSubsystem.In1), 0, 0, 1 }
  ,

  { (char_T *)(&helicecontrolV2_DW.DiscreteFIRFilter1_states[0]), 0, 0, 5 },

  { (char_T *)(&helicecontrolV2_DW.PacketInput_PWORK), 11, 0, 5 },

  { (char_T *)(&helicecontrolV2_DW.DiscreteFIRFilter1_circBuf), 6, 0, 1 },

  { (char_T *)(&helicecontrolV2_DW.Counter_Count), 3, 0, 1 },

  { (char_T *)
    (&helicecontrolV2_DW.SwitchCaseActionSubsystem4.SwitchCaseActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&helicecontrolV2_DW.SwitchCaseActionSubsystem3.SwitchCaseActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&helicecontrolV2_DW.SwitchCaseActionSubsystem2.SwitchCaseActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&helicecontrolV2_DW.SwitchCaseActionSubsystem1.SwitchCaseActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&helicecontrolV2_DW.SwitchCaseActionSubsystem.SwitchCaseActionSubsystem_SubsysRanBC),
    2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  16U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&helicecontrolV2_P.PacketInput_MaxMissedTicks), 0, 0, 2 },

  { (char_T *)(&helicecontrolV2_P.PacketInput_PacketID), 6, 0, 1 },

  { (char_T *)(&helicecontrolV2_P.Counter_InitialCount), 3, 0, 1 },

  { (char_T *)(&helicecontrolV2_P._Value), 0, 0, 22 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] helicecontrolV2_dt.h */
