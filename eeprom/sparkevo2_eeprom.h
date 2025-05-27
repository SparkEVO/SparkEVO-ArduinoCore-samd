#pragma once

#include <stddef.h>
#include <stdint.h>

#define EEPROM0_STRUCTVERSION 1
#define FEATURES_STRUCTVERSION 1

#define DEVICE_TYPE_ITRONIX 4
#define DEVICE_TYPE_ITRONIX_IGNITION 5
#define DEVICE_TYPE_ITRONIX_ECU 6
#define DEVICE_TYPE_ITRONIX_BATTERY 7

#define PARTNERID_CRE 1
#define PARTNERID_RAPPA 2

typedef struct {
  uint8_t STRUCT_VERSION;
  uint8_t DEVICE_TYPE;
  int DEVICE_SERIAL_NUMBER;
  int HW_REVISION;
  unsigned int LICENSE_CODE;
} __attribute__((packed)) Eeprom0Struct;

inline Eeprom0Struct getDefaultEeprom0()
{
  Eeprom0Struct eeprom0;
  eeprom0.STRUCT_VERSION = EEPROM0_STRUCTVERSION;
  eeprom0.DEVICE_TYPE = 0;
  eeprom0.DEVICE_SERIAL_NUMBER = 0;
  eeprom0.HW_REVISION = 0;
  eeprom0.LICENSE_CODE = 0;
  
  return eeprom0;
}

typedef struct {
  uint8_t STRUCT_VERSION;
  unsigned short PARTNER_ID;
  unsigned short VARIANT_ID;
  uint8_t ENABLE_MODE; // 0 = needs pin to enable, 1 = never available 
  bool ENABLE_BLE; // Use BLE connection
  bool ENABLE_CONFIG_W; // Edit of Configuration
  uint8_t ENABLED_TIMINGMAPS_R; // View/Load Timing Maps and Rev Limiter and Base Timing (1 bit for each map)
  uint8_t ENABLED_TIMINGMAPS_W; // Edit Timing Maps and Rev Limiter and Base Timing (1 bit for each map)
  uint8_t ENABLED_INJECTORMAPS_R; // View/Load Injector Maps (1 bit for each map)
  uint8_t ENABLED_INJECTORMAPS_W; // Edit Injector Maps (1 bit for each map)
  uint8_t ENABLE_POWERJET; // Configure powerjet
  uint8_t ENABLED_POWERJETMAPS_R; // View/Load Injector Maps (1 bit for each map)
  uint8_t ENABLED_POWERJETMAPS_W; // Edit Injector Maps (1 bit for each map)
  uint8_t ENABLE_POWERVALVE; // Configure powervalve
  uint8_t ENABLED_POWERVALVEMAPS_R; // View/Load Power Valve Maps (1 bit for each map)
  uint8_t ENABLED_POWERVALVEMAPS_W; // Edit of Power Valve Maps (1 bit for each map)
  bool ENABLE_MULTIPRP; // Configure the Multi Purpose pin
  bool ENABLE_QUICKSHIFT; // Quick Shift
  bool ENABLE_MAPSWITCH; // Map Switch
  bool ENABLE_MAPJUMP; // Map Jump
  bool ENABLE_LOGGER; // Datalogger
  // custom settings
  uint8_t POWERVALVE_MAX_APERTURE_PERCENT; 
  MultiPurposeFunctionType MULTIPRP_DEFAULT_TYPE;
} __attribute__((packed)) FeaturesStruct;

inline FeaturesStruct getDefaultFeatures()
{
  FeaturesStruct features;
  features.STRUCT_VERSION = FEATURES_STRUCTVERSION;
  features.PARTNER_ID = 0;
  features.VARIANT_ID = 0;
  features.ENABLE_MODE = 0;
  features.ENABLE_BLE = true;
  features.ENABLE_CONFIG_W = true;
  features.ENABLED_TIMINGMAPS_R = UINT8_MAX;
  features.ENABLED_TIMINGMAPS_W = UINT8_MAX;
  features.ENABLED_INJECTORMAPS_R = UINT8_MAX;
  features.ENABLED_INJECTORMAPS_W = UINT8_MAX;
  features.ENABLE_POWERJET = false;
  features.ENABLED_POWERJETMAPS_R = UINT8_MAX;
  features.ENABLED_POWERJETMAPS_W = UINT8_MAX;
  features.ENABLE_POWERVALVE = false;
  features.ENABLED_POWERVALVEMAPS_R = UINT8_MAX;
  features.ENABLED_POWERVALVEMAPS_W = UINT8_MAX;
  features.ENABLE_MULTIPRP = true;
  features.ENABLE_QUICKSHIFT = true;
  features.ENABLE_MAPSWITCH = true;
  features.ENABLE_MAPJUMP = true;
  features.ENABLE_LOGGER = true;
  features.POWERVALVE_MAX_APERTURE_PERCENT = 100;
  features.MULTIPRP_DEFAULT_TYPE = 0;
  
  return features;
}
