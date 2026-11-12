#pragma once
#include "types.h"

typedef struct KartIconRow {
    /* 00 */ u16 mBnclIndex;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mNclrIndex;
    /* 08 */ u16 mNclrStart;
    /* 0a */ u16 mUnk_0a;
} KartIconRow;

// Objects whose layout isn't known yet.
extern u8 gCupMarkBnclIndices[];

extern u16 gSelectCupNameMBnclIndices[];

extern u32 gSelectRaceRuleTeamsToSetupCopy[];

extern u16 gSelectCupMCellSlots[];

extern u16 data_0215cefc[];

extern u16 gSelectCupMCourseCells[];

extern u16 gSelectCupMCourseLabels[];

extern u16 data_0215cf06[];

extern u16 data_0215cf0e[];

extern u16 data_0215cef4[];

extern u16 data_0215cf14[];

extern u32 data_0215cf2c[];

extern u16 data_0215cf4c[][4];

extern u32 data_0215cf8c[][4];

extern u16 gSelectCupGridTrophyCells[];

extern u16 gSelectCupGridCourseLabelCells[];

extern u16 gSelectCupGridCourseLabelIndices[];

extern u16 gSelectCupGridRecordCells[];

extern u16 gSelectCupGridCupCellIndices[4][6];

extern u16 gSelectCupCourseLabelCells[];

extern u16 gSelectCupCourseLabelIndices[];

extern u16 gSelectCupCourseRecordCells[];

extern u32 gCupRowsByCupIndex[];

extern u16 gSelectCupCourseTrophyCells[];

extern u16 gCupCourseNameMessageIndices[][4];

extern u32 data_0215cbec[][4];

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

extern u32 gSelectCupGridEngineSlots[3];

extern s32 gSelectCupGridRecordEngineClasses[4];

extern u32 gSelectCupGridCupIndices[8];

extern u32 gSelectCupGridRecordCellSlots[8];

extern u32 gSelectCupGridFirstCourseIds[8];

extern u32 gSelectCupGridMirrorFlagIndices[8];

extern u16 gSelectCupGridCupMessageIndices[8][4];

extern u32 gSelectCupGridEngineFlagIndices[8][3];

extern u32 gSelectCupGridCourseIds[8][4];

extern s16 gSelectCupCourseRectCourseIndices[4];

extern u16 gSelectCupCourseLabelWidths[4];

extern u16 gSelectCupCourseLabelHeights[4];

extern u16 data_0215cb3c[8][4];

extern s16 data_0215cb7c[8];

extern u32 gCharacterKartIndices[];

extern KartIconRow gKartIconRows[];

extern s16 gSelectCupGridDownOffsets[];

extern s16 gSelectCupGridLeftOffsets[];

extern s16 gSelectCupGridRightOffsets[];

extern s16 gSelectCupGridUpOffsets[];

extern u32 gSelectCupGridRectCupIndices[];

extern u32 gSelectCupGridIndicesByCup[];

extern u16 gSelectCupGridCourseLabelWidths[];

extern u16 gSelectCupGridCourseLabelHeights[];
