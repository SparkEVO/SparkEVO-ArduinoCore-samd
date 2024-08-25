#pragma once

#include <stddef.h>
#include <stdint.h>

#define EEPROM0_VERSION 1

#define EEPROM_ADDR_EEPROM0 1
#define EEPROM_ADDR_RADIOFREQUENCY 50  // 1 byte (0 = EU, 1 = US)
#define EEPROM_ADDR_RADIOADDRESS 51    // 1 byte
#define EEPROM_ADDR_MASTERADDRESS 52   // 1 byte
#define EEPROM_ADDR_TIMESHOTMODE 53    // 1 byte
#define EEPROM_ADDR_TRIGGERMODE 54     // 1 byte

typedef struct {
  uint8_t STRUCT_VERSION;
  uint8_t DEVICE_TYPE;
  int DEVICE_SERIAL_NUMBER;
  uint8_t HW_REVISION;
  unsigned int LICENSE_NUMBER;
} __attribute__((packed)) Eeprom0Struct;

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
