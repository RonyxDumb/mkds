#pragma once

#include "types.h"

typedef struct Rotary Rotary;

void RotaryPauseNop(void *stateObject);

void UpdateRotarySlowDown(void *stateObject);

void EnterRotarySlowDown(void *stateObject);

void UpdateRotarySteady(void *stateObject);

void RotarySteadyNop(void *stateObject);

void UpdateRotaryRampUp(void *stateObject);

void EnterRotaryRampUp(void *stateObject);
