#pragma once

#include "types.h"

void InitWLMenuSceneCallback(void);
BOOL TryXorBackupWordsAtFoundIndex(u32 *cursor, u32 byteCount, u32 expectedFirstWord);
void XorBackupWordsAtTickIndex(u32 *cursor, u32 byteCount);
s32 FindBackupXorIndex(u32 value, u32 expected);
BOOL ClearTickBytesAndCheckBlockCrc(u8 *bytes, u32 byteCount, u32 skipTickBytes);
void WriteBlockTail(u8 *bytes, u32 byteCount, u32 skipTickBytes);
u16 ComputeBytesCrc(u8 *cursor, u32 byteCount);
void EndBackupAccessWithError(s32 errorCode);
BOOL TryLockBackup(void);
void UnlockBackup(void);

extern const u32 gBackupXorKeys11[11];
extern const u32 gBackupXorKeys17[17];
extern const u32 gBackupXorKeys19[19];
extern const u32 gBackupXorKeys29[29];
