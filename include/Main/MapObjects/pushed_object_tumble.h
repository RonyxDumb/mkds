#pragma once

#include "types.h"
#include "Main/MapObjects/pushed_motion.h"
#include "Main/MapObjects/attractor.h" // MapObject

void EnterPushedObjectPark(void *stateObject);

void UpdatePushedObjectTumble(void *stateObject);

void EnterPushedObjectTumble(void *stateObject);

extern const u8 gPushedObjectInactiveFlag[2];
