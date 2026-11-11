#pragma once

#include "types.h"

typedef struct DGTHash1Context DGTHash1Context;

void MD5Update(DGTHash1Context *ctx, const u8 *src, u32 count);
