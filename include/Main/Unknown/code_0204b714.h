#pragma once

#include "types.h"

u32 savc_read(u32 address, u32 *destination, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                    u32 expectedFirstWord, s32 hasPrefix);
void savc_readCallback(void (*callback)(u32 *, u32));
BOOL savc_checkHeaderSignature(u8 *cursor);
void savc_initBackup(void);
void savc_init(void *heap);
void savc_resetStatus(void);
void WFSi_EndTaskThread(void);
void WFSi_CreateTaskThread(void);
void WFSi_TaskThread(void *a);
