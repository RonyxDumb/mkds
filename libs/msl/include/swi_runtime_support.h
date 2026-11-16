#pragma once

#include "types.h"
#include "float_trap_dispatch.h" // FloatTrapTable

extern u32 g_AlphaFlags;
extern FloatTrapTable g_GammaFuncs;
extern void (*gStaticInitializers[])(void);

void SwiWriteByte(const void *bytePtr);
u32 Semihost_Op7(void);
void SwiCall24(void);
s32 SwiCloseFile(void);
s32 SwiWriteBytes(s32 fileHandle, const u8 *buffer, const u32 *countPtr, u32 lastArg);
s32 SwiReadBytes(s32 fileHandle, u8 *buffer, u32 *countPtr);
void RunListNodeCallbacks(void);
void Crt0_RunInitArray(void);
u32 *GetAlphaFlagsRef(void);
FloatTrapTable *GetGammaFuncsRef(void);
void ExitViaSwi(void);
