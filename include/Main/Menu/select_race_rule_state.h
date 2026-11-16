#pragma once

#include "types.h"
#include "reset_interrupts_halt.h"
#include "Main/Menu/menu_screens_work.h"

// A rectangle of a ScreenMap for one row, with the top bits it is filled with plain and highlighted.
typedef struct SelectRaceRuleNscrRect {
    /* 00 */ u32 mFirstColumn;
    /* 04 */ u32 mFirstRow;
    /* 08 */ u32 mColumnCount;
    /* 0c */ u32 mRowCount;
    /* 10 */ u16 mTopBits;
    /* 12 */ u16 mHighlightedTopBits;
} SelectRaceRuleNscrRect;

void AdvanceSelectRaceRuleWaitConfirmOpen(void);
u16 GetSelectRaceRuleHumanCount(void);
void AdvanceSelectRaceRuleValueObjects(void);
void SetAndPrintSelectRaceRuleRaceCount(s16 count);
void SetAndPrintSelectRaceRuleWinCount(s16 count);
void AdvanceSelectRaceRuleHighlight(void);
void LookupSelectRaceRuleNscrRect(SelectRaceRuleNscrRect *outRect, s32 row);

void AdvanceSelectRaceRuleWaitPress(void);
void AdvanceSelectRaceRuleChoose(void);
void AdvanceSelectRaceRuleWaitReturn(void);
void AdvanceSelectRaceRuleSlideIn(void);

void AdvanceSelectRaceRuleWaitFade(void);

void ReleaseSelectRaceRule(void);
void InitSelectRaceRule(void *parentHeap, s32 mainOam, void *oamList, s32 mode);
void RequestSelectRaceRuleSlideOut(void);
void RequestSelectRaceRuleWaitConfirmAnswer(void);
void RequestSelectRaceRuleWaitConfirmChoices(void);
void RequestSelectRaceRuleWaitConfirmOpen(void);
void RequestSelectRaceRuleWaitPress(void);
void RequestSelectRaceRuleChoose(void);
void RequestSelectRaceRuleWaitReturn(void);
void RequestSelectRaceRuleSlideIn(void);
void ResetSelectRaceRulePositions(void);
void SetSelectRaceRuleHumanCount(void);
void ReadRaceSetupCopyIntoSelectRaceRule(void);
void AdvanceSelectRaceRuleTeamInput(void);
void PrintSelectRaceRuleRow4Message(void);
void AdvanceSelectRaceRuleChangeObjects(void);
void WriteSelectRaceRuleToRaceSetupCopy(void);
void AssignListedCpuSlots(void);
void SetListedCpuSlotWrapper(u16 entryIndex, u32 value);
void AdvanceSelectRaceRuleRowObjects(void);
void DecrementSelectRaceRuleCourseCount(void);
void IncrementSelectRaceRuleCourseCount(void);
void MoveSelectRaceRuleValuePrevious(s32 playSound);
void MoveSelectRaceRuleValueNext(s32 playSound);
BOOL IsSelectRaceRuleTeamsValid(void);
BOOL DoesSelectRaceRuleHumanCountMatch(void);
BOOL IsSelectRaceRuleValueAllowed(void);
void AssignSelectRaceRuleNonHumanTeams(void);
void AssignSelectRaceRuleHumanTeams(void);
void ChangeSelectRaceRulePlayerTeam(u16 entryIndex, u32 teamIndex);
BOOL PickSelectRaceRuleCpuEntry(u16 *entryOut);

u32 GetLargerTeamIndex(void);

u32 GetOtherTeamIndex(u32 team);

BOOL IsSelectRaceRuleEntryHuman(u16 entryIndex);

void SetSelectRaceRulePlayerTeam(u16 entryIndex, u32 team);

BOOL IsPlayerTeamPlayerCountNotOne(s32 entryIndex);
u16 GetSelectRaceRuleTeamPlayerCount(s32 team);

// The two entry indices of one row of the race rule menu.
typedef struct SelectRaceRuleRowEntries {
    /* 00 */ u16 mEntryIndices[2];
} SelectRaceRuleRowEntries;

void MoveSelectRaceRuleRowPrevious(void);
void MoveSelectRaceRuleRowNext(void);

unsigned short GetSelectRaceRuleCpuCount(void);

extern struct SelectRaceRule *gSelectRaceRule;

extern const u16 gSelectRaceRuleTeamCellsHighlighted[2];
extern const u16 gSelectRaceRuleTeamCellsPlain[2];
extern const u16 gSelectRaceRuleRow2ValueMessageIndices[3];
extern const u16 gSelectRaceRuleRow3ValueMessageIndices[3];
extern const u16 gSelectRaceRuleRow4ValueMessageIndices[3];
extern const u16 gSelectRaceRuleRow0ValueMessageIndices[4];
extern const u16 gSelectRaceRuleRow1ValueMessageIndices[4];
extern const u32 gSelectRaceRuleTeamsFromSetupCopy[2];
extern const u32 gSelectRaceRuleTeamsToSetupCopy[2];
extern const u16 gSelectRaceRuleCountTeamChangeCells[2][2];
extern const u16 gSelectRaceRuleRowMessageIndices[6];
extern const u16 gSelectRaceRuleRowValueCounts[6];
extern const u32 gSelectRaceRuleCourseListModeValues[3];
extern const u32 gSelectRaceRuleRuleKindValues[3];
extern const u32 gSelectRaceRuleCourseListModes[3];
extern const u32 gSelectRaceRuleRuleKinds[3];
extern const u32 gSelectRaceRuleEngineIndexValues[3];
extern const u32 gSelectRaceRuleCpuDifficultyValues[4];
extern const u32 gSelectRaceRuleEngineIndices[4];
extern const u32 gSelectRaceRuleCpuDifficulties[4];
extern const u32 gSelectRaceRuleNextRectRows[5];
extern const SelectRaceRuleRowEntries gSelectRaceRuleRowEntries[5];
extern const u16 gSelectRaceRuleLabelWidths[5][2];
extern const u16 gSelectRaceRuleLabelHeights[5][2];
extern const u16 gSelectRaceRuleStepCellsHighlighted[5][2];
extern const u32 gSelectRaceRuleRowRectRows[5];
extern const char *gSelectRaceRuleSBnblName;
extern const char *gSelectRaceRuleSBNclrName;
extern const char *gSelectRaceRuleMultiSimpleSNscrName;
extern const char *gSelectRaceRuleMultiSimpleSBnclName;
extern const char *gSelectRaceRuleSBNcgrName;
extern const char *gSelectRaceRuleSBnllName;
extern const char *gSelectRaceRuleSONclrName;
extern const char *gSelectRaceRuleSMenuNscrName;
extern const char *gSelectRaceRuleSBnclName;
extern const char *gSelectRaceRuleSNcgrName;
extern const char *gSelectRaceRuleMultiSimpleSBnllName;
extern const char *gSelectRaceRuleMultiSimpleSBnblName;
extern const char *gSelectRaceRuleSNcerName;
extern const char *gSelectRaceRuleMultiSimpleSBNcgrName;
extern const u16 *gSelectRaceRuleValueMessageIndices[5];

extern char gSelectRaceRuleSBnblPath[31];
extern char gSelectRaceRuleSBNclrPath[33];
extern char gSelectRaceRuleMultiSimpleSNscrPath[44];
extern char gSelectRaceRuleMultiSimpleSBnclPath[44];
extern char gSelectRaceRuleSBNcgrPath[33];
extern char gSelectRaceRuleSBnllPath[31];
extern char gSelectRaceRuleSONclrPath[33];
extern char gSelectRaceRuleSMenuNscrPath[36];
extern char gSelectRaceRuleSBnclPath[31];
extern char gSelectRaceRuleSNcgrPath[35];
extern char gSelectRaceRuleMultiSimpleSBnllPath[44];
extern char gSelectRaceRuleMultiSimpleSBnblPath[44];
extern char gSelectRaceRuleSNcerPath[35];
extern char gSelectRaceRuleMultiSimpleSBNcgrPath[46];
