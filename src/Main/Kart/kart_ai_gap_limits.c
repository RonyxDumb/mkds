#include "Main/Kart/kart_ai_gap_limits.h"

const s32 gKartAiGapLimitsKartCount1[1] = {0};
const s32 gKartAiGapLimitsKartCount2[2] = {0, 0x333};
const s32 gKartAiGapLimitsKartCount3[3] = {0, 0x1ec, 0x400};
const s32 gKartAiGapLimitsKartCount4[4] = {0, 0x19a, 0x385, 0x59a};
const s32 gKartAiGapLimitsKartCount5[5] = {0, 0x19a, 0x333, 0x4cd, 0x733};
const s32 gKartAiGapLimitsKartCount6[6] = {0, 0x19a, 0x333, 0x4cd, 0x733, 0x99a};
const s32 gKartAiGapLimitsKartCount7[7] = {0, 0x19a, 0x2b8, 0x400, 0x666, 0x8cd, 0xb33};
const s32 gKartAiGapLimitsKartCount8[8] = {0, 0x19a, 0x2b8, 0x400, 0x59a, 0x800, 0xa66, 0xccd};
u16 gKartAiRankOffset = 3;
const s32 *gKartAiEndedGapLimits = gKartAiGapLimitsKartCount8;
u16 g_CpuMode2SomeArray[3] = {2, 3, 4};
u16 g_CpuMode1SomeArray[3] = {1, 2, 3};
u16 gKartAiRaceStartBoostHardChoices[3] = {3, 4, 5};
const s32 *gKartAiGapLimitTables[9] = {NULL,
                                       gKartAiGapLimitsKartCount1,
                                       gKartAiGapLimitsKartCount2,
                                       gKartAiGapLimitsKartCount3,
                                       gKartAiGapLimitsKartCount4,
                                       gKartAiGapLimitsKartCount5,
                                       gKartAiGapLimitsKartCount6,
                                       gKartAiGapLimitsKartCount7,
                                       gKartAiGapLimitsKartCount8};
