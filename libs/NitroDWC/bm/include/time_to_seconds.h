#pragma once

#include "types.h"
#include "clock_chip_access.h" // RTCTime

unsigned int ComputeTimeSeconds_from_thumb(const RTCTime *values);
