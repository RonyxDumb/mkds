#pragma once

#include "types.h"

void savd_setKartUnlockLevel(u32 value);
u8 savd_getKartUnlockLevel(void);
u8 savd_calcKartUnlockLevel(u8 *bytes);
BOOL savd_isUnlockBitSet(u32 flagIndex);
BOOL savd_isBitSet2(s32 bitIndex, u8 *bytes);
void savd_setUnlockBit(s32 flagIndex);
void savd_repairErrorsAsync(void);
void savd_repairErrorsTask(void);
void savd_loadAsync(void);
void savd_loadTask(void);
void savd_eraseAllAsync(void);
