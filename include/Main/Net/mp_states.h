#pragma once

#include "types.h"
#include "Main/MapObjects/data_02165000.h"

void EnterMPState15Nop(void *stateObject);
void UpdateMPState14(void *stateObject);
void EnterMPState14(void *stateObject);
void UpdateMPState13(void *stateObject);
void EnterMPState13(void *stateObject);
void UpdateMPState12(void *stateObject);
void EnterMPState12(void *stateObject);
void UpdateMPState11(void *stateObject);
void EnterMPState11(void *stateObject);
void UpdateMPState10(void *stateObject);
void EnterMPState10(void *stateObject);
void UpdateMPState9(void *stateObject);
void EnterMPState9(void *stateObject);
void UpdateMPState8(void *stateObject);
BOOL GetEntryChunk(u8 *entry, s32 chunkIndex, s32 chunkSize, u8 **outChunk, u16 *outSize);
BOOL QueueMPChunk(u8 chunkNumber, u8 *data, u16 size, u8 playerIndex, u8 destBitmap);
void QueueMPChunkCallback(void);
void EnterMPState8(void *stateObject);
void UpdateMPState7(void *stateObject);
void EnterMPState7(void *stateObject);
void UpdateMPState4(void *stateObject);
void EnterMPState4(void *stateObject);
void UpdateMPState2(void *stateObject);
void EnterMPState2(void *stateObject);
void UpdateMPState1(void *stateObject);
void UpdateMPState3(void *stateObject);
void EnterMPState3(void *stateObject);
void UpdateMPState6(void *stateObject);
void UpdateMPState5(void *stateObject);
void RequestMPState15AfterCombine(void);

extern QueueMPDataToPortParams gQueueMPChunkParams;
