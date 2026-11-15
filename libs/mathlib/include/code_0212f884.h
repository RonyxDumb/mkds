#pragma once

#include "types.h"

u64 _dadd(u32 leftLow, u32 leftHigh, u32 rightLow, u32 rightHigh);
u32 _d2f(u32 low, u32 high);
u32 DoubleToFloatNan(u32 low, u32 high);
u32 DoubleToFloatRange(u32 low, u32 high, u32 scratch);
