#!/bin/bash -ex

BOARD_ID=arduino_zero NAME=samd21_sam_ba make clean all

BOARD_ID=sparkevo_itronix NAME=samd21_sam_ba_sparkevo_itronix make clean all
mv -v samd21_sam_ba_sparkevo_itronix.* ../sparkevo_itronix/

BOARD_ID=sparkevo_timeshot2 NAME=samd21_sam_ba_sparkevo_timeshot2 make clean all
mv -v samd21_sam_ba_sparkevo_timeshot2.* ../sparkevo_timeshot2/

echo Done building bootloaders!

