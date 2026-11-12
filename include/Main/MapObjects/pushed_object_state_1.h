#pragma once

#include "types.h"
#include "Main/MapObjects/pushed_motion.h"
#include "Main/MapObjects/attractor.h" // MapObject

void EnterPushedObjectState2(u32 objectAddress);

void UpdatePushedObjectState1(PushedObject *object);

void EnterPushedObjectState1(MapObject *object);
