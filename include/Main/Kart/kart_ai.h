#pragma once

#include "types.h"
#include "Main/System/backup_net_camera_work.h"

RandomState64 *GetKartAiRandom(void);
BOOL IsOneKartNotHumanOrPeer(void);
s32 GetKartRaceProgressScaled(u16 kartIndex);
unsigned int GetKartAiEngineOrDifficultyIndex(void);
unsigned int GetKartAiTableIndex(unsigned int kartIndex);
s32 GetKartIndexAtRank(unsigned int rank);
KartAiParamRow *GetKartAiParamRow(void);
s32 GetKartAtNonCpuRank(void);
s32 GetCpuKartAheadOfRank(s32 rank);
s32 GetFirstCpuKartByRank(void);
s32 GetFirstRankProgressRatio(void);
s32 GetCpuKartByRankPlusOffset(unsigned int rank, unsigned int offset);
s32 GetKartRankAmongCpuKarts(u16 kartIndex);
void UpdateKartAiRankLists(void);
void UpdateKartAiShared(void);
s16 GetNonCpuKartCountOutsideKartTeam(u32 kartIndex);
void DecrementKartAiNonCpuCount(u32 kartIndex);
s32 PickKartAiTableIndex(u16 kartIndex, u32 *nextNonCpuTableIndexPointer);
void InitKartAiTableIndices(void);
void InitKartAiGrandPrixPoints(void);
void InitKartAiNonCpuCounts(void);
void CreateGlobalAEBC_from_thumb(void);
void MaybeLoadKartAIData_from_thumb(void);

// The row of 'kartAIparam.bin' for this race; NULL in battle and when RaceSetup.mRaceKind is 5 or 6.
extern KartAiParamRow *g_KartAIParamPtr;
extern struct KartAiShared *g_GlobalAEBC;

// Values of KartAiShared.mEngineOrDifficultyIndex, the row of the CPU tables: slow engine or easy, medium or normal,
// fast engine or hard.
#define KART_AI_LEVEL_LOW 0
#define KART_AI_LEVEL_MEDIUM 1
#define KART_AI_LEVEL_HIGH 2
// Smallest KartAiShared.mFirstRankProgressRatio while the first rank is held.
#define KART_AI_FIRST_RANK_RATIO_MIN 0x19a
