#pragma once

#include "types.h"

s16 FX_Atan2(s32 y, s32 x);
u16 FX_Atan2Idx(s32 y, s32 x);

// Arctangent of x in [0, 1] (index x >> 5 of 12-bit fixed point) as an angle in radians with 12 fractional bits.
extern const s16 FX_AtanTable_[129];
// The same as a 16-bit angle index (0x2000 for x = 1).
extern const s16 FX_AtanIdxTable_[129];
