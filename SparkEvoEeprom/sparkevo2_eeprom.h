#pragma once

#include <stddef.h>

typedef unsigned char byte;

#define EEPROM0_VERSION 1
#define EEPROM_VERSION  1

typedef struct {
  byte STRUCT_VERSION;
  byte DEVICE_TYPE;
  int DEVICE_SERIAL_NUMBER;
  int HW_REVISION;
  unsigned int LICENSE_NUMBER;
} Eeprom0Struct;

typedef struct {
  byte STRUCT_VERSION;
  unsigned short LOCK_PIN;
  // map switch
  bool MAPRT_SWITCH_ENABLED;
  byte MAPRT_SWITCH_MAP1;
  byte MAPRT_SWITCH_MAP2;
  // gear shift
  bool GEAR_SHIFT_ENABLED;
  unsigned int GEAR_SHIFT_DELAY;
  // configuration
  byte PULSE_WIDTH;
  byte INPUT_SIGNAL_PER_TURN;
  bool INPUT_POLARITY;
  bool EXTERNAL_BATTERY;
  // output enable
  bool POWERJET_ENABLED;
  unsigned int POWERJET_RPM_THRESHOLD;
  unsigned int POWERJET_DUTY;
  // statistics
  unsigned int STATS_RUNTIME;
  unsigned int STATS_MAX_RPM;
  unsigned int STATS_OUTPUT_ERRORS;
  unsigned int STATS_STARTUPS;
  // map system
  float BASE_TIMING_ANGLE;
  float BASE_INJECTOR_ANGLE;
  byte CURRENT_MAPRT_ID;
  byte CURRENT_MAPRTI_ID;
  byte CURRENT_MAPRTA_ID;
  unsigned int BASE_LIMITER_RPM; // rpm limiter for base timing map
  bool LIMITER_ENABLED;
  bool INJECTION_ENABLED;
} EepromStruct;

inline Eeprom0Struct getDefaultEeprom0()
{
  Eeprom0Struct eeprom0;
  eeprom0.STRUCT_VERSION = EEPROM0_VERSION;
  eeprom0.DEVICE_TYPE = 0;
  eeprom0.DEVICE_SERIAL_NUMBER = 0;
  eeprom0.HW_REVISION = 0;
  eeprom0.LICENSE_NUMBER = 0;
  
  return eeprom0;
}

inline EepromStruct getDefaultEeprom(void)
{
  EepromStruct eeprom;
  eeprom.STRUCT_VERSION = EEPROM_VERSION;
  eeprom.LOCK_PIN = 0;
  eeprom.MAPRT_SWITCH_ENABLED = false;
  eeprom.MAPRT_SWITCH_MAP1 = 0;
  eeprom.MAPRT_SWITCH_MAP2 = 0;
  eeprom.GEAR_SHIFT_ENABLED = false;
  eeprom.GEAR_SHIFT_DELAY = 0;
  eeprom.PULSE_WIDTH = 0;
  eeprom.INPUT_SIGNAL_PER_TURN = 0;
  eeprom.INPUT_POLARITY = false;
  eeprom.EXTERNAL_BATTERY = false;
  eeprom.POWERJET_ENABLED = false;
  eeprom.POWERJET_RPM_THRESHOLD = 0;
  eeprom.POWERJET_DUTY = 0;
  eeprom.STATS_RUNTIME = 0;
  eeprom.STATS_MAX_RPM = 0;
  eeprom.STATS_OUTPUT_ERRORS = 0;
  eeprom.STATS_STARTUPS = 0;
  eeprom.BASE_TIMING_ANGLE = 0;
  eeprom.BASE_INJECTOR_ANGLE = 0;
  eeprom.CURRENT_MAPRT_ID = 0;
  eeprom.CURRENT_MAPRTI_ID = 0;
  eeprom.CURRENT_MAPRTA_ID = 0;
  eeprom.BASE_LIMITER_RPM = 0;
  eeprom.LIMITER_ENABLED = false;
  eeprom.INJECTION_ENABLED = false;
  
  return eeprom;
}