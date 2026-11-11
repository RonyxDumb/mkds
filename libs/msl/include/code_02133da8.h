#pragma once

#include "types.h"

void _fp_init(void);
u32 FloatStatusClearXor(u32 clearMask, u32 xorMask);
u32 FloatFlagsClearXor(u32 clearFlags, u32 xorFlags);
