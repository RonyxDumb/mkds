#pragma once

#include "types.h"

void MIi_CpuClear32(u32 data, void *destp, u32 size);
void MIi_CpuCopy32(const void *srcp, void *destp, u32 size);
void MIi_CpuSend32(const void *srcp, vu32 *destp, u32 size);
void MIi_CpuClearFast(u32 data, void *destp, u32 size);
void MIi_CpuCopyFast(const void *srcp, void *destp, u32 size);
void MI_Copy32B(const void *pSrc, void *pDest);
void MI_Copy36B(const void *pSrc, void *pDest);
void MI_Copy48B(const void *pSrc, void *pDest);
void MI_Copy64B(const void *pSrc, void *pDest);
void MI_CpuFill8(void *dstp, u8 data, u32 size);
void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
void MI_Zero36B(void *pDest);
u32 MI_SwapWord(u32 setData, volatile u32 *destp);
void MI_UncompressLZ8(const void *srcp, void *destp);

// Calls MIi_CpuClearFast with 0, passed through a stack offset of its own.
static inline void MemFillWordsByBlock_inline(void *dest, u32 size) {
    volatile u32 zero = 0;
    MIi_CpuClearFast(zero, dest, size);
}
