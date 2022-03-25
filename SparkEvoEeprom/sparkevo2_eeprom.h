#pragma once

#include <stddef.h>

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
  // map switch
  bool MAP_SWITCH_ENABLED;
  byte MAP_SWITCH_MAP1;
  byte MAP_SWITCH_MAP2;
  // gear shift
  bool GEAR_SHIFT_ENABLED;
  unsigned int GEAR_SHIFT_DELAY;
  // configuration
  byte PULSE_WIDTH;
  byte INPUT_SIGNAL_PER_TURN;
  bool INPUT_POLARITY;
  bool EXTERNAL_BATTERY;
  // output enable
  bool OUTPUT1_ENABLE;
  unsigned int OUTPUT1_RPM_THRESHOLD;
  // statistics
  unsigned int STATS_RUNTIME;
  unsigned int STATS_MAX_RPM;
  unsigned int STATS_TEMPERATURE_ALARMS;
  unsigned int STATS_OUTPUT_TIMEOUT_ERRORS;
  unsigned int STATS_STARTUPS;
  // map system
  float BASE_TIMING_ANGLE;
  byte CURRENT_MAP_ID;
  // rpm limiter
  bool LIMITER_ENABLED;
  unsigned int  RPM_LIMIT;
} EepromStruct;

extern Eeprom0Struct eeprom0;
extern EepromStruct eeprom;

extern Eeprom0Struct GetDefaultEeprom0(void);
extern EepromStruct GetDefaultEeprom(void);