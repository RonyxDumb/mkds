#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h"

RandomState64 *GetKartAiRandom(void);
BOOL sub_2085390(void);
s32 GetKartRaceProgressScaled(u32 kartIndex);
unsigned int sub_20853DC(void);
unsigned int GetKartAiTableIndex(unsigned int kartIndex);
s32 GetKartIndexAtRank(unsigned int rank);
KartAiParamRow *GetKartAiParamRow(void);
s32 sub_2085434(void);
s32 sub_2085458(s32 a);
s32 GetFirstKind1KartByRank(void);
s32 sub_208548C(void);
s32 sub_20854A0(unsigned int p0, unsigned int p1);
s32 GetKartRankAmongKind1(u16 kartIndex);
void UpdateKartAiRankLists(void);
void UpdateKartAiShared(void);
s16 sub_2085824(u32 kartIndex);
void DecrementKartAiNonCpuCount(u32 kartIndex);
s32 PickKartAiTableIndex(u16 kartIndex, u32 *nextNonCpuTableIndexPointer);
void InitKartAiTableIndices(void);
void func_02085bec(void);
void InitKartAiNonCpuCounts(void);
void InitKartAiShared(void);
void loadKartAIParams(void);
