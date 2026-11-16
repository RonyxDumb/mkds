#pragma once

#include "types.h"
#include "uncompress_contexts.h"

s32 MI_ReadUncompLZ8(MIUncompContextLZ *context, const u8 *data, u32 len);
