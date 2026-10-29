#pragma once

#include "types.h"

void RLUnCompReadByCallbackWrite16bit(void);
void SoftReset(void);
void LZ77UnCompReadByCallbackWrite16bit(void);
void HuffUnCompReadByCallback(void);
void LZ77UnCompReadNormalWrite8bit(void);
u32 Sqrt(u32 a);
void RLUnCompReadNormalWrite8bit(void);
void BitUnPack(void);
void WaitByLoop(s32 n);
s32 Mod(s32 a, s32 b);
s32 IsDebugger(void);
s32 Div(s32 a, s32 b);
u16 GetCRC16(void);
void Halt(void);
void CpuFastSet(void);
void IntrWait(void);
