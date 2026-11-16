#pragma once

#include "types.h"

void ReadSaveChunkImpl_from_thumb(u32 firstAddress, u32 secondAddress, u32 *destination, u32 byteCount,
                              void (*callback)(u32 *, u32), u32 expectedFirstWord, s32 hasPrefix);
void ReadSaveChunkImpl2_from_thumb(u32 address, void *destination, u32 byteCount, void (*callback)(u32 *, u32),
                            u32 expectedFirstWord);

u32 StartBackupRead(u32 address, u32 *destination, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                    u32 expectedFirstWord, s32 hasPrefix);
void FinishBackupRead(void *arg);
BOOL CheckBackupBlockPrefix(u8 *cursor);
void InitializePrepareBackup_from_thumb(void);
void InitializeSaveDataIoManager_from_thumb(void *heap);
void SX1Zero_from_thumb(void);
void StopFileReadThread(void);
void StartFileReadThread(void);
void SomeThreadEntry2(void *unused);

extern u8 g_str_rom_0[];
