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
