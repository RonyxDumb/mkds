#pragma once

#include "types.h"

unsigned int RotaryState3ReturnArgument(unsigned int value);

typedef struct Rotary Rotary;

void UpdateRotaryState2(Rotary *object);

void EnterRotaryState2(Rotary *object);

void UpdateRotaryState1(Rotary *object);

unsigned int RotaryState1ReturnArgument(unsigned int value);

void UpdateRotaryState0(Rotary *object);

void EnterRotaryState0(Rotary *object);
