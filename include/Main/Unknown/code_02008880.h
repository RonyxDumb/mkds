#pragma once

#include "types.h"

typedef struct FSFile FSFile;

u32 func_02008880(FSFile *a);
u16 ComputeU16Checksum(const u16 *data, s32 byteCount);
