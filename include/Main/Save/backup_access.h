#pragma once

#include "types.h"

void Scene_WLMenu_Initialize(void);
BOOL TryXorBackupWordsAtFoundIndex(u32 *cursor, u32 byteCount, u32 expectedFirstWord);
void EncryptSaveData_from_thumb(u32 *cursor, u32 byteCount);
s32 FindTable0IndexForValue_from_thumb(u32 value, u32 expected);
BOOL ClearTickBytesAndCheckBlockCrc(u8 *bytes, u32 byteCount, u32 skipTickBytes);
void CalculateCRCChecksum_from_thumb(u8 *bytes, u32 byteCount, u32 skipTickBytes);
u16 ComputeCRC_from_thumb(u8 *cursor, u32 byteCount);
void EndBackupAccessWithError(s32 errorCode);
BOOL AllocateLockCardBackupResource_from_thumb(void);
void CleanupUnlockBackup_from_thumb(void);

extern const u32 g_EncTableB[11];
extern const u32 g_EncTableC[17];
extern const u32 g_EncTableA[19];
extern const u32 g_EncTable0[29];
