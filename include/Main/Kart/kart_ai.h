#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217a000.h"

RandomState64 *GetKartAiRandom(void);
BOOL IsOneKartNotHumanOrPeer(void);
s32 GetKartRaceProgressScaled(u16 kartIndex);
unsigned int GetKartAiEngineOrDifficultyIndex(void);
unsigned int GetKartAiTableIndex(unsigned int kartIndex);
s32 GetKartIndexAtRank(unsigned int rank);
KartAiParamRow *GetKartAiParamRow(void);
s32 GetKartAtNonCpuRank(void);
s32 GetKind1KartAheadOfRank(s32 rank);
s32 GetFirstKind1KartByRank(void);
s32 GetFirstRankProgressRatio(void);
s32 GetKind1KartByRankPlusOffset(unsigned int rank, unsigned int offset);
s32 GetKartRankAmongKind1(u16 kartIndex);
void UpdateKartAiRankLists(void);
void UpdateKartAiShared(void);
s16 GetNonCpuKartCountOutsideKartTeam(u32 kartIndex);
void DecrementKartAiNonCpuCount(u32 kartIndex);
s32 PickKartAiTableIndex(u16 kartIndex, u32 *nextNonCpuTableIndexPointer);
void InitKartAiTableIndices(void);
void InitKartAiGrandPrixPoints(void);
void InitKartAiNonCpuCounts(void);
void InitKartAiShared(void);
void SetKartAiParamRow(void);

// The row of 'kartAIparam.bin' for this race; NULL in battle and when RaceSetup.mRaceKind is 5 or 6.
extern KartAiParamRow *gKartAiParamRow;
extern struct KartAiShared *gKartAiShared;
