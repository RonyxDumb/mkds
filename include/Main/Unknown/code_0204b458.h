#pragma once

#include "types.h"

u32 StartBackupWrite(u32 address, u32 *source, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                     s32 hasPrefix);
u32 StartBackupOneByteRead(void);
void FinishBackupOneByteRead(void);
void FinishBackupWrite(void (*callback)(u32 *, u32));
