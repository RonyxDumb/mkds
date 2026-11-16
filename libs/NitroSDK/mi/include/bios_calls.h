#pragma once

#include "types.h"

void SVC_UncompressRL16FromDevice(void);
void SVC_SoftReset(void);
void SVC_UncompressLZ16FromDevice(void);
void SVC_UncompressHuffmanFromDevice(void);
void SVC_UncompressLZ8(void);
u32 SVC_Sqrt(u32 value);
void SVC_UncompressRL8(void);
void SVC_UnpackBits(void);
void SVC_WaitByLoop(s32 loopCount);
s32 SVC_DivRem(s32 dividend, s32 divisor);
s32 SVC_IsMmemExpanded(void);
s32 SVC_Div(s32 dividend, s32 divisor);
u16 SVC_GetCRC16(void);
void SVC_Halt(void);
void SVC_CpuSetFast(void);
void SVC_WaitIntr(void);

void SVC_CpuSet(const void *src, void *dst, u32 ctrl);
void SVC_WaitVBlankIntr(void);
