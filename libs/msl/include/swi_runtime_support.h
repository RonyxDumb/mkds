#pragma once

#include "types.h"
#include "float_trap_dispatch.h" // FloatTrapTable

extern u32 gFloatStatus;
extern FloatTrapTable gFloatTrapTable;
extern void (*gStaticInitializers[])(void);

void SwiWriteByte(const void *bytePtr);
u32 SwiReadByte(void);
void SwiCall24(void);
s32 SwiCloseFile(void);
s32 SwiWriteBytes(s32 fileHandle, const u8 *buffer, const u32 *countPtr, u32 lastArg);
s32 SwiReadBytes(s32 fileHandle, u8 *buffer, u32 *countPtr);
void RunListNodeCallbacks(void);
void __call_static_initializers(void);
u32 *GetFloatStatus(void);
FloatTrapTable *GetFloatTrapTable(void);
void ExitViaSwi(void);
