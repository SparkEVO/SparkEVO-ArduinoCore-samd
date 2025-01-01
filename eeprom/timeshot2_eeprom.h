#pragma once

#include <stddef.h>
#include <stdint.h>

#define EEPROM0_VERSION 1

// config
#define EEPROM_ADDR_EEPROM0 1
#define EEPROM_ADDR_RADIOFREQUENCYID 20			// 1 byte (1 = EU, 2 = US)
#define EEPROM_ADDR_RADIOFREQUENCYOFFSET 21		// 1 byte (0-127 => [-128;0], 128-255 => [1;+128])
#define EEPROM_ADDR_RADIOADDRESS 22				// 1 byte
#define EEPROM_ADDR_MASTERADDRESS 23			// 1 byte
#define EEPROM_ADDR_TIMESHOTMODE 24				// 1 byte
#define EEPROM_ADDR_TRIGGERMODE 25				// 1 byte
#define EEPROM_ADDR_ENABLEMASTERLIDAR 26		// 1 byte ("drag" mode)
#define EEPROM_ADDR_OUTPUTSIGNALMODE 27			// 1 byte
#define EEPROM_ADDR_OUTPUTSIGNALDURATION 28		// 1 byte
#define EEPROM_ADDR_OUTPUTSIGNALINVERTED 29		// 1 byte

// stats
#define EEPROM_ADDR_RECORDSARRAY 50  			// sequence of 4 bytes
#define EEPROM_LENGTH_RECORDSARRAY 50			// length of RECORDSARRAY

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
