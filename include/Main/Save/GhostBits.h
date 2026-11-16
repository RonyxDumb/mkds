#pragma once

#include "types.h"

void savd_initNksy(s32 copyOwnerName);
BOOL savd_isDownloadGhostAvailable(u32 bitIndex);
void savd_setPersonalGhostUnavailable(s32 bitIndex);
BOOL savd_isPersonalGhostAvailable(u8 bitIndex);
void savd_resetBit(s32 bitIndex, u8 *bytes, s32 c);
BOOL savd_isBitSet(s32 bitIndex, u8 *bytes, s32 c);
void savd_setBit(s32 bitIndex, u8 *bytes, s32 c);
