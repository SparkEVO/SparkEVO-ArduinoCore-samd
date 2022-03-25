#include "sparkevo2_eeprom.h"

ReadOnlyEepromStruct eeprom0;
EepromStruct eeprom;

extern EepromStruct GetDefaultEeprom0()
{
  Eeprom0Struct eeprom0;
  eeprom0.STRUCT_VERSION = EEPROM0_VERSION;
  eeprom0.DEVICE_TYPE = 0;
  eeprom0.DEVICE_SERIAL_NUMBER = 0;
  eeprom0.HW_REVISION = 0;
  eeprom0.LICENSE_NUMBER = 0;
  
  return eeprom0;
}

extern EepromStruct GetDefaultEeprom()
{
  EepromStruct eeprom;
  eeprom.STRUCT_VERSION = EEPROM_VERSION;
  eeprom.MAP_SWITCH_ENABLED = false;
  eeprom.MAP_SWITCH_MAP1 = 0;
  eeprom.MAP_SWITCH_MAP2 = 0;
  eeprom.GEAR_SHIFT_ENABLED = false;
  eeprom.GEAR_SHIFT_DELAY = 0;
  eeprom.PULSE_WIDTH = 0;
  eeprom.INPUT_SIGNAL_PER_TURN = 0;
  eeprom.INPUT_POLARITY = 0;
  eeprom.EXTERNAL_BATTERY = false;
  eeprom.POWERJET_ENABLED = false;
  eeprom.POWERJET_RPM_THRESHOLD = 0;
  eeprom.POWERJET_DUTY = 0;
  eeprom.STATS_RUNTIME = 0;
  eeprom.STATS_MAX_RPM = 0;
  eeprom.STATS_OUTPUT_ERRORS = 0;
  eeprom.STATS_STARTUPS = 0;
  eeprom.BASE_TIMING_ANGLE = 0;
  eeprom.CURRENT_MAP_ID = 0;
  eeprom.LIMITER_ENABLED = false;
  eeprom.RPM_LIMIT = 0;
  eeprom.INJECTION_ENABLED = false;
  
  return eeprom;
}