#pragma once

#include "types.h"

void Crt0_Reset32sAndAlphaFlags(void);
u32 ChangeSomeAlphaFlags(u32 clearMask, u32 xorMask);
u32 FloatFlagsClearXor(u32 clearFlags, u32 xorFlags);
