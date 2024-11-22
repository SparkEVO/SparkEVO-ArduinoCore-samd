#pragma once

#include <stddef.h>
#include <stdint.h>

#define EEPROM0_VERSION 1

// config
#define EEPROM_ADDR_EEPROM0 1
#define EEPROM_ADDR_RADIOFREQUENCY 10  			// 1 byte (0 = EU, 1 = US)
#define EEPROM_ADDR_RADIOADDRESS 11    			// 1 byte
#define EEPROM_ADDR_MASTERADDRESS 12   			// 1 byte
#define EEPROM_ADDR_TIMESHOTMODE 13    			// 1 byte
#define EEPROM_ADDR_TRIGGERMODE 14     			// 1 byte
#define EEPROM_ADDR_TRANSPONDEROUTMODE 15   	// 1 byte
#define EEPROM_ADDR_TRANSPONDEROUTDURATION 16	// 1 byte
#define EEPROM_ADDR_TRANSPONDEROUTINVERTED 17  	// 1 byte

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
