#pragma once

#include "types.h"
#include "clock_chip_access.h" // RTCTime

unsigned int TimeToSeconds(const RTCTime *values);
