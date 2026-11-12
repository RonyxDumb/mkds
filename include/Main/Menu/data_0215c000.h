#pragma once
#include "types.h"

typedef struct KartIconRow {
    /* 00 */ u16 mBnclIndex;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mNclrIndex;
    /* 08 */ u16 mNclrStart;
    /* 0a */ u16 mUnk_0a;
} KartIconRow;

extern u32 gSelectRaceRuleTeamsToSetupCopy[];

extern u16 gSelectCupGridCupCellIndices[4][6];

extern u16 gSelectRaceRuleTeamCellsHighlighted[];

extern u16 gSelectRaceRuleTeamCellsPlain[];

extern u32 gSelectRaceRuleTeamsFromSetupCopy[];

extern u16 gSelectRaceRuleCountTeamChangeCells[][2];

extern u16 gSelectRaceRuleRowMessageIndices[];

extern u16 gSelectRaceRuleRowValueCounts[];

extern u32 gSelectRaceRuleCourseListModeValues[];

extern u32 gSelectRaceRuleRuleKindValues[];

extern u32 gSelectRaceRuleCourseListModes[];

extern u32 gSelectRaceRuleRuleKinds[];

extern u32 gSelectRaceRuleEngineIndexValues[];

extern u32 gSelectRaceRuleCpuDifficultyValues[];

extern u32 gSelectRaceRuleEngineIndices[];

extern u32 data_0215cd24[];

extern u32 gSelectRaceRuleCpuDifficulties[];

extern u16 data_0215cd4e[];

extern u16 gSelectRaceRuleLabelWidths[][2];

// Element of data_0215cd74: read as a word and as two halfwords.
typedef union Unk0215cd74 {
    /* 00 */ u32 mUnk_00;
    /* 00 */ u16 h[2];
} Unk0215cd74;

extern Unk0215cd74 data_0215cd74[];

extern u16 gSelectRaceRuleStepCellsHighlighted[][2];

extern u16 gSelectRaceRuleStepCellsChanging[][2];

extern u16 gSelectRaceRuleStepCellsPlain[][2];

extern u32 gSelectRaceRulePreviousRectRows[];

extern u32 gSelectRaceRuleEntryInputSlots[];

extern u32 gSelectCupGridCourseIds[8][4];
