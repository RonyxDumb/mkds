#pragma once

#include "types.h"

u64 DoubleDivReversed(u32 a, u32 b, u32 c, u32 d);
u64 _ddiv(u32 a, u32 b, u32 c, u32 d);
u64 DoubleDivReturn(u32 a, u32 b);
u64 DoubleDivRoundUpResult(u32 a, u32 b);
void DoubleDivSetOverflowInexact(u32 *p, u32 v);
u64 DoubleDivRoundDownTail(u32 a, u32 b, u32 c);
u64 DoubleDivRoundUpTail(u32 a, u32 b);
u64 DoubleDivSpecial(u32 a, u32 b);
