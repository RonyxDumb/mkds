#pragma once

#include "types.h"

void StartBackupWriteOneCopy(u32 address, void *source, u32 byteCount, void (*callback)(u32 *, u32));
void StartBackupWriteTwoCopies(u32 firstAddress, u32 secondAddress, u32 *source, u32 byteCount,
                               void (*callback)(u32 *, u32), s32 hasPrefix);

u32 StartBackupWrite(u32 address, u32 *source, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                     s32 hasPrefix);
u32 StartBackupOneByteRead(void);
void FinishBackupOneByteRead(void);
void FinishBackupWrite(void (*callback)(u32 *, u32));

extern const u16 gCrcXorValue;
