#pragma once

#include "types.h"

u32 savc_write(u32 address, u32 *source, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                     s32 hasPrefix);
u32 savc_beginWrite(void);
void savc_writeReadCallback(void);
void savc_writeCallback(void (*callback)(u32 *, u32));
