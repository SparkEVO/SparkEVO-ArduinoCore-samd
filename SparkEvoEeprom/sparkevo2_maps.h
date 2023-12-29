#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define MAPFILE_STRUCTVERSION_TIMING_COMP 1
#define MAP_TIMING_COMP_POINTS 16


typedef enum {
	STATOR_TYPE_UNKNOWN = 0,
	STATOR_TYPE_PVL_1007DIGITAL_CW,
	STATOR_TYPE_PVL_1007DIGITAL_CCW,
	STATOR_TYPE_PVL_1443ANALOG_CW,
	STATOR_TYPE_PVL_1443ANALOG_CCW,
	STATOR_TYPE_SELETTRA_KZ3200WANALOG_CW,
	STATOR_TYPE_SELETTRA_KZ3200WANALOG_CCW,
	STATOR_TYPE_SELETTRA_NO2019ANALOG_CW,
	STATOR_TYPE_SELETTRA_NO2019ANALOG_CCW,
	STATOR_TYPE_END
} StatorType;

typedef struct 
{
  uint8_t STRUCT_VERSION;
  StatorType STATOR_TYPE;
  uint8_t POINTS_COUNT;
  uint8_t RPM[MAP_TIMING_COMP_POINTS];           // divided by 100 (e.g. 30 ==> 3000) [0;180]
  uint16_t TIMING[MAP_TIMING_COMP_POINTS];       // multiplied by 10 (e.g. 355 ==> 35.5)
} __attribute__((packed)) SparkMapTimingCompensation;


inline SparkMapTimingCompensation* getMapTimingCompensation(StatorType t)
{
	SparkMapTimingCompensation* m = (SparkMapTimingCompensation*)malloc(sizeof(SparkMapTimingCompensation));
	m->STRUCT_VERSION = MAPFILE_STRUCTVERSION_TIMING_COMP;
	m->STATOR_TYPE = t;
	m->POINTS_COUNT = MAP_TIMING_COMP_POINTS;

	if (t == STATOR_TYPE_PVL_1007DIGITAL_CW)
	{
		m->RPM[0]  = 10;  m->TIMING[0] = 70;
		m->RPM[1]  = 20;  m->TIMING[1] = 65;
		m->RPM[2]  = 30;  m->TIMING[2] = 55;
		m->RPM[3]  = 40;  m->TIMING[3] = 55;
		m->RPM[4]  = 50;  m->TIMING[4] = 55;
		m->RPM[5]  = 60;  m->TIMING[5] = 55;
		m->RPM[6]  = 70;  m->TIMING[6] = 55;
		m->RPM[7]  = 80;  m->TIMING[7] = 60;
		m->RPM[8]  = 90;  m->TIMING[8] = 62;
		m->RPM[9]  = 100; m->TIMING[9] = 65;
		m->RPM[10] = 110; m->TIMING[10] = 70;
		m->RPM[11] = 120; m->TIMING[11] = 73;
		m->RPM[12] = 130; m->TIMING[12] = 73;
		m->RPM[13] = 140; m->TIMING[13] = 73;
		m->RPM[14] = 150; m->TIMING[14] = 73;
		m->RPM[15] = 160; m->TIMING[15] = 73;
	}
	else if (t == STATOR_TYPE_PVL_1007DIGITAL_CCW)
	{
		m->RPM[0]  = 10;  m->TIMING[0] = 50;
		m->RPM[1]  = 20;  m->TIMING[1] = 40;
		m->RPM[2]  = 30;  m->TIMING[2] = 30;
		m->RPM[3]  = 40;  m->TIMING[3] = 30;
		m->RPM[4]  = 50;  m->TIMING[4] = 30;
		m->RPM[5]  = 60;  m->TIMING[5] = 30;
		m->RPM[6]  = 70;  m->TIMING[6] = 33;
		m->RPM[7]  = 80;  m->TIMING[7] = 35;
		m->RPM[8]  = 90;  m->TIMING[8] = 45;
		m->RPM[9]  = 100; m->TIMING[9] = 50;
		m->RPM[10] = 110; m->TIMING[10] = 55;
		m->RPM[11] = 120; m->TIMING[11] = 62;
		m->RPM[12] = 130; m->TIMING[12] = 70;
		m->RPM[13] = 140; m->TIMING[13] = 70;
		m->RPM[14] = 150; m->TIMING[14] = 74;
		m->RPM[15] = 160; m->TIMING[15] = 70;
	}
	else {
		free(m);
		return 0;
	}
	
	return m;
}