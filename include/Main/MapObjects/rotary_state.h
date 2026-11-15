#pragma once

#include "types.h"

typedef struct Rotary Rotary;

void RotaryState3Nop(Rotary *object);

void UpdateRotaryState2(Rotary *object);

void EnterRotaryState2(Rotary *object);

void UpdateRotaryState1(Rotary *object);

void RotaryState1Nop(Rotary *object);

void UpdateRotaryState0(Rotary *object);

void EnterRotaryState0(Rotary *object);
