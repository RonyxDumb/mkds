#pragma once

#include "types.h"
#include "Main/MapObjects/pushed_motion.h"
#include "Main/MapObjects/attractor.h" // MapObject

void EnterPushedObjectState2(void *stateObject);

void UpdatePushedObjectState1(void *stateObject);

void EnterPushedObjectState1(void *stateObject);

extern const u8 gPushedObjectState1Flag[2];
