#pragma once

#include "types.h"

u64 DoubleDivReversed(u32 leftLow, u32 leftHigh, u32 rightLow, u32 rightHigh);
u64 _ddiv(u32 leftLow, u32 leftHigh, u32 rightLow, u32 rightHigh);
u64 DoubleDivReturn(u32 unusedLow, u32 unusedHigh);
u64 DoubleDivRoundUpResult(u32 unusedLow, u32 resultHigh);
void DoubleDivSetOverflowInexact(u32 *statusWord, u32 status);
u64 DoubleDivRoundDownTail(u32 unusedLow, u32 resultHigh, u32 scratch);
u64 DoubleDivRoundUpTail(u32 unusedLow, u32 resultHigh);
u64 DoubleDivSpecial(u32 low, u32 high);
