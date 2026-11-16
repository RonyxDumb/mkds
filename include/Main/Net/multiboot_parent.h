#pragma once

#include "types.h"

typedef struct FSArchive FSArchive;

s32 UnkStruct_ReadFn_RomUnk_0(FSArchive *archive, void *dst, u32 src, u32 length);
s32 AdvanceMultiBootParent(void);
s32 AdvanceChildMaskCovered(void);
u8 CompactMaskBits(u8 mask);
s32 AdvanceScanConnect(u16 entryIndex);
