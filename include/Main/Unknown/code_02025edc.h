#pragma once

#include "types.h"

typedef struct Interpolation Interpolation;

void interp_update(Interpolation *interpolation);
void interp_setState(Interpolation *interpolation, s32 requestedState);
