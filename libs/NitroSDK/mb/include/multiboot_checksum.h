#pragma once

#include "types.h"

typedef struct FSFile FSFile;

u32 ComputeRomBinarySize_from_thumb(FSFile *file);
u16 MBi_calc_cksum(const u16 *data, s32 byteCount);
