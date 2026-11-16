#pragma once

#include "types.h"

s32 *ResetRaceEndSeqState(void);
u32 GetSomeCXSseqId(void);

void CreateSetGlobalCX(void *heapMemory, u32 heapSize);
u32 LoadPerRaceModeResultSseqs(s32 index);

u32 GetResultSceneSeqId(void);

void SetEntryKartFinishResult(u32 finishResult);

extern u32 g_MissionRunBossResultSseqIdTable[6];
extern u32 g_PerRaceModeResultSseqIdTable[6][6];
