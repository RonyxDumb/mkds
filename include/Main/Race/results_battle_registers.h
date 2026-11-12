#pragma once

#include "types.h"
#include "Main/Menu/data_02174000.h"

void ResultsBattleWriteSceneTextRegistersWrapper(void);

typedef struct SceneNumbers SceneNumbers;

void ReleaseResultsBattle(void);
void AdvanceResultsBattle(SceneNumbers *sceneNumbers);
void InitResultsBattle(void *heap, void *mainOam, void *subOam);


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

extern const u16 gResultsBattleSubLabelCanvasEntries[16][4];
extern const u8 gResultsBattleRankZeroLabelTextRows[64];
extern const u16 gResultsBattleTeamFirstCellIndices[8];
// Halfwords the first three functions index with a count minus one or two.
extern const u16 gResultsBattleKartFirstCellIndices[8];
// 8-byte entries.
extern const u8 gResultsBattleOwnEntryLabelTextRows[8];
extern struct ResultsBattle *gResultsBattle;
