#pragma once

#include "types.h"
#include "uncompress_contexts.h"

s32 LzDecompressContext_DoCycle(MIUncompContextLZ *context, const u8 *data, u32 len);
