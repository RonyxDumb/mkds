#pragma once

#include "types.h"
#include "code_02134008.h" // FloatTrapTable

extern u32 gFloatStatus;
extern FloatTrapTable gFloatTrapTable;
extern void (*data_usa_02161748[])(void);

void SwiWriteByte(const void *bytePtr);
u32 SwiReadByte(void);
void SwiCall24(void);
s32 SwiCloseFile(void);
s32 SwiWriteBytes(s32 unusedArg1, const u8 *buffer, const u32 *countPtr);
s32 SwiReadBytes(s32 unusedArg1, u8 *buffer, u32 *countPtr);
void RunListNodeCallbacks(void);
void __call_static_initializers(void);
u32 *GetFloatStatus(void);
FloatTrapTable *GetFloatTrapTable(void);
void ExitViaSwi(void);
