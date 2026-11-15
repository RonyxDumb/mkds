#pragma once

#include "types.h"

typedef struct Rotary Rotary;

void RotaryState3Nop(void *stateObject);

void UpdateRotaryState2(void *stateObject);

void EnterRotaryState2(void *stateObject);

void UpdateRotaryState1(void *stateObject);

void RotaryState1Nop(void *stateObject);

void UpdateRotaryState0(void *stateObject);

void EnterRotaryState0(void *stateObject);
