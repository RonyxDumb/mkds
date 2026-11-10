#pragma once

#include "types.h"

void RaiseKartAppearLimit(u32 value);
u8 GetKartAppearLimit(void);
u8 GetKartAppearLimitFromBits(u8 *bytes);
BOOL IsBackupFlagSet(u32 flagIndex);
BOOL IsBitSetInBytes(s32 bitIndex, u8 *bytes);
void SetBackupFlag(s32 flagIndex);
void StartResetFailedBackupBlocks(void);
void ResetFailedBackupBlocks(void);
void StartReadBackupFirstBlockAndRecords(void);
void ReadBackupFirstBlockAndRecords(void);
void ResetBackupAndStartWrite(void);
