#pragma once

#include "types.h"

typedef struct Interpolation Interpolation;

void AdvanceInterpolation(Interpolation *interpolation);
void SetInterpolationStateIfOpposite(Interpolation *interpolation, s32 requestedState);
