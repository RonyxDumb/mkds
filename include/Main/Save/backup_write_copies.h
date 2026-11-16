#pragma once

#include "types.h"

void SV_MaybeCompressWriteNoFlagsBC_from_thumb(u32 address, void *source, u32 byteCount, void (*callback)(u32 *, u32));
void SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb(u32 firstAddress, u32 secondAddress, u32 *source, u32 byteCount,
                               void (*callback)(u32 *, u32), s32 hasPrefix);

u32 SV_MaybeCompressWriteImpl_from_thumb(u32 address, u32 *source, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                     s32 hasPrefix);
u32 StartBackupOneByteRead(void);
void FinishBackupOneByteRead(void *arg);
void dma_fn_from_thumb(void *arg);

extern const u16 g_SomeCRCConst;
