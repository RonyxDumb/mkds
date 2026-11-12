#pragma once

#include "types.h"

void ResultsBattleWriteSceneTextRegistersWrapper(void);

typedef struct SceneNumbers SceneNumbers;

void ReleaseResultsBattle(void);
void AdvanceResultsBattle(SceneNumbers *sceneNumbers);
void InitResultsBattle(void *heap, void *mainOam, void *subOam);

// Halfwords the first three functions index with a count minus one or two.
extern u16 gResultsBattleKartFirstCellIndices[];
extern u16 gResultsBattleTeamFirstCellIndices[];
// 8-byte entries.
extern u8 gResultsBattleOwnEntryLabelTextRows[];
extern u8 gResultsBattleRankZeroLabelTextRows[];

void SetupResultsBattleTeamIcons(void *heap);
void SetupResultsBattleKartIcons(void *heap);
void SetupResultsBattleRankZeroNames(void *heap);
void SetupResultsBattleOwnEntry(void *heap);
void QueueResultsBattleCharacterIcon(s32 cellFileSetIndex, s32 entryIndex, s32 cellIndex, s32 iconSetSelector);
void PrintResultsBattleScoreAndShowRank(s32 entryIndex);
void SetResultsBattleEntryCellsVisible(s32 entryIndex);

void StartResultsBattleChoices(void);

s32 IsResultsBattleTimerBelow300(void);
s32 IsResultsBattleTimerRunOut(void);
s32 AreResultsBattleRanksAllZero(void);
void FillResultsBattleEntries(void);
void AssignResultsBattleTeamOrderByScore(void);
void AssignResultsBattleTeamOrder(void);
void WriteGhostGetScanRegisters(void);
