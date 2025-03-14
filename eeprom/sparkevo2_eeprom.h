#pragma once

#include <stddef.h>
#include <stdint.h>

#define EEPROM0_VERSION 1
#define EEPROM_VERSION  1

#define DEVICE_TYPE_ITRONIX 4
#define DEVICE_TYPE_ITRONIX_IGNITION 5
#define DEVICE_TYPE_ITRONIX_ECU 6
#define DEVICE_TYPE_ITRONIX_BATTERY 7

typedef struct {
  uint8_t STRUCT_VERSION;
  uint8_t DEVICE_TYPE;
  int DEVICE_SERIAL_NUMBER;
  int HW_REVISION;
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
