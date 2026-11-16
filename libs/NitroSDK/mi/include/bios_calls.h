#pragma once

#include "types.h"

void RLUnCompReadByCallbackWrite16bit(void);
void SoftReset(void);
void LZ77UnCompReadByCallbackWrite16bit(void);
void HuffUnCompReadByCallback(void);
void LZ77UnCompReadNormalWrite8bit(void);
u32 Sqrt(u32 value);
void RLUnCompReadNormalWrite8bit(void);
void BitUnPack(void);
void WaitByLoop(s32 loopCount);
s32 Mod(s32 dividend, s32 divisor);
s32 IsDebugger(void);
s32 Div(s32 dividend, s32 divisor);
u16 GetCRC16(void);
void Halt(void);
void CpuFastSet(void);
void IntrWait(void);

void CpuSet(const void *src, void *dst, u32 ctrl);
void VBlankIntrWait(void);
