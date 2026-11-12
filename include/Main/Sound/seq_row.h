#pragma once

#include "types.h"

s32 *ResetRaceEndSeqState(void);
u32 GetSeqRowSceneSeq(void);

void CreateSeqRowHeap(void *heapMemory, u32 heapSize);
u32 LoadSeqRowIfChanged(s32 index);

u32 GetResultSceneSeqId(void);

void SetEntryKartFinishResult(u32 finishResult);
