#pragma once

#include "types.h"
#include "code_0200fc8c.h"

// Rectangle of the ScreenMap behind one row, with the top bits it is filled with plain and highlighted.
typedef struct SelectRaceRuleNscrRect {
    /* 00 */ u32 mFirstColumn;
    /* 04 */ u32 mFirstRow;
    /* 08 */ u32 mColumnCount;
    /* 0c */ u32 mRowCount;
    /* 10 */ u16 mTopBits;
    /* 12 */ u16 mHighlightedTopBits;
} SelectRaceRuleNscrRect;

extern SelectRaceRuleNscrRect gSelectRaceRuleSMenuNscrRects[];
extern SelectRaceRuleNscrRect gSelectRaceRuleMultiSimpleNscrRects[];

void AdvanceSelectRaceRuleState5(void);
u16 GetSelectRaceRuleHumanCount(void);
void AdvanceSelectRaceRuleValueObjects(void);
void SetAndPrintSelectRaceRuleRaceCount(s16 count);
void SetAndPrintSelectRaceRuleWinCount(s16 count);
void AdvanceSelectRaceRuleHighlight(void);
void LookupSelectRaceRuleNscrRect(SelectRaceRuleNscrRect *outRect, s32 row);

void AdvanceSelectRaceRuleState4(void);
void AdvanceSelectRaceRuleState3(void);
void AdvanceSelectRaceRuleState2(void);
void AdvanceSelectRaceRuleState1(void);

void AdvanceSelectRaceRuleState0(void);

void ReleaseSelectRaceRule(void);
void InitSelectRaceRule(void *parentHeap, s32 unusedArg1, void *oamList, s32 mode);
void RequestSelectRaceRuleState8(void);
void RequestSelectRaceRuleState7(void);
void RequestSelectRaceRuleState6(void);
void RequestSelectRaceRuleState5(void);
void RequestSelectRaceRuleState4(void);
void RequestSelectRaceRuleState3(void);
void RequestSelectRaceRuleState2(void);
void RequestSelectRaceRuleState1(void);
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

typedef struct SelectRaceRuleRowEntries {
    /* 00 */ u16 mEntryIndices[2];
} SelectRaceRuleRowEntries;

extern SelectRaceRuleRowEntries gSelectRaceRuleRowEntries[];

void MoveSelectRaceRuleRowPrevious(void);
void MoveSelectRaceRuleRowNext(void);

unsigned short GetSelectRaceRuleCpuCount(void);
