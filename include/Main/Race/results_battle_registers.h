#pragma once

#include "types.h"
#include "Main/Menu/select_kart_ghost_work.h"

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

s32 IsResultsBattleTimerBelowChoiceStart(void);
s32 IsResultsBattleTimerRunOut(void);
s32 AreResultsBattleRanksAllZero(void);
void FillResultsBattleEntries(void);
void AssignResultsBattleTeamOrderByScore(void);
void AssignResultsBattleTeamOrder(void);
void WriteGhostGetScanRegisters(void);

// One row per RESULTS_BATTLE_FILES_* kind (victory, lose, draw, VS blue, VS red): the file names the main screen loads;
// mBnllName is NULL in the last three rows.
typedef struct ResultsBattleVictoryFileNames {
    /* 00 */ const char *mBNcgrName;
    /* 04 */ const char *mBNclrName;
    /* 08 */ const char *mUpperNscrName;
    /* 0c */ const char *mLowerNscrName;
    /* 10 */ const char *mNcgrName;
    /* 14 */ const char *mNcerName;
    /* 18 */ const char *mONclrName;
    /* 1c */ const char *mBnclName;
    /* 20 */ const char *mBnllName;
} ResultsBattleVictoryFileNames;

extern const u16 gResultsBattleSubLabelCanvasEntries[16][4];
extern const u8 gResultsBattleRankZeroLabelTextRows[64];
extern const u16 gResultsBattleTeamFirstCellIndices[8];
// Cell index of the first icon for each count: SetupResultsBattleKartIcons indexes gResultsBattleKartFirstCellIndices
// with the kart count minus 2, SetupResultsBattleTeamIcons indexes gResultsBattleTeamFirstCellIndices with the count
// minus 1.
extern const u16 gResultsBattleKartFirstCellIndices[8];
// 8-byte rows for SetupLabelCanvas, one per label; SetupResultsBattleOwnEntry steps through them by 8.
extern const u8 gResultsBattleOwnEntryLabelTextRows[8];
extern struct ResultsBattle *gResultsBattle;

extern const ResultsBattleVictoryFileNames gResultsBattleFileNames[5];
extern char gResultsBattleVictoryBNcgrName[];
extern char gResultsBattleVictoryBNclrName[];
extern char gResultsBattleVictoryUpperNscrName[];
extern char gResultsBattleVictoryLowerNscrName[];
extern char gResultsBattleVictoryNcgrName[];
extern char gResultsBattleVictoryNcerName[];
extern char gResultsBattleVictoryONclrName[];
extern char gResultsBattleVictoryBnclName[];
extern char gResultsBattleVictoryBnllName[];
extern char gResultsBattleLoseBNcgrName[];
extern char gResultsBattleLoseBNclrName[];
extern char gResultsBattleLoseUpperNscrName[];
extern char gResultsBattleLoseLowerNscrName[];
extern char gResultsBattleLoseNcgrName[];
extern char gResultsBattleLoseNcerName[];
extern char gResultsBattleLoseONclrName[];
extern char gResultsBattleLoseBnclName[];
extern char gResultsBattleLoseBnllName[];
extern char gResultsBattleDrawBNcgrName[];
extern char gResultsBattleDrawBNclrName[];
extern char gResultsBattleDrawUpperNscrName[];
extern char gResultsBattleDrawLowerNscrName[];
extern char gResultsBattleDrawNcgrName[];
extern char gResultsBattleDrawNcerName[];
extern char gResultsBattleDrawONclrName[];
extern char gResultsBattleDrawBnclName[];
extern char gResultsBattleVsBlueBNcgrName[];
extern char gResultsBattleVsBlueBNclrName[];
extern char gResultsBattleVsBlueUpperNscrName[];
extern char gResultsBattleVsBlueLowerNscrName[];
extern char gResultsBattleVsBlueNcgrName[];
extern char gResultsBattleVsBlueNcerName[];
extern char gResultsBattleVsBlueONclrName[];
extern char gResultsBattleVsBlueBnclName[];
extern char gResultsBattleVsRedBNcgrName[];
extern char gResultsBattleVsRedBNclrName[];
extern char gResultsBattleVsRedUpperNscrName[];
extern char gResultsBattleVsRedLowerNscrName[];
extern char gResultsBattleVsRedNcgrName[];
extern char gResultsBattleVsRedNcerName[];
extern char gResultsBattleVsRedONclrName[];
extern char gResultsBattleVsRedBnclName[];
