#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/data_02180728.h"

typedef struct ChoisesSList {
    /* 00 */ s32 mValues[6];
    /* 18 */ s32 mValueCount;
} ChoisesSList;

// Object behind gChoisesS, 0x1a4 bytes allocated by InitChoisesS.
typedef struct ChoisesS {
    // Non-zero from opening the list screen in the race until it is closed there; other race code stops meanwhile.
    /* 000 */ s32 mOpenDuringRace;
    /* 004 */ s32 mPrevOpenDuringRace;
    /* 008 */ s32 mOpenAfterRace;
    // Set once a non-zero pick is stored (not by the auto pick); open and close requests and list input are ignored.
    /* 00c */ s32 mPickLocked;
    /* 010 */ BOOL mPickStartedOnSelected;
    // Calls since a list entry was picked, 0 when none; past 0xf mPickedValue is latched and this goes back to 0.
    /* 014 */ s32 mPickFrames;
    // Calls since a close was asked for, 0 when none; past 4 the close is requested and this goes back to 0.
    /* 018 */ s32 mCloseFrames;
    // Calls counted in mode 5 near the end of the race; past 0x384 mPickedValue is set with no input.
    /* 01c */ s32 mAutoPickFrames;
    /* 020 */ BOOL mOtherMissionRecordsFilled5To7;
    // The value handed to the race scene, 0 = none; usually copied from mSelectedValue when a pick completes.
    /* 024 */ s32 mPickedValue;
    /* 028 */ s32 mSelectedValue;
    /* 02c */ s32 mUnk_02c;
    /* 030 */ s32 mUnk_030;
    // Counts calls and wraps at 0x32; zeroed when the selection steps; the list draw writes two tiles below 0x1e.
    /* 034 */ s32 mCycleFrames;
    /* 038 */ ChoisesSList mLists[4];
    /* 0a8 */ void *mFont;
    /* 0ac */ u8 mCharCanvases[4][0x20];
    /* 12c */ TextCanvas mTextCanvases[4];
    /* 16c */ Nclr *mChoisesSBNclr;
    /* 170 */ Ncgr *mChoisesSBNcgr;
    /* 174 */ u16 *mList1Chars;
    /* 178 */ u16 *mList2Chars;
    /* 17c */ Nscr *mList0Nscr;
    /* 180 */ Nscr *mList1Nscr;
    /* 184 */ Nscr *mList2Nscr;
    /* 188 */ Nscr *mList3Nscr;
    /* 18c */ Nscr *mChoisesSNscrs[6];
} ChoisesS;

void ChoisesSInitTextCanvas(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing);
u32 ChoisesSDrawTextOnCanvas(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text);
void InitChoisesS(void);
void ClearChoisesSPointer(void);

extern struct ChoisesS *gChoisesS;
extern char gChoisesSNscr1Name[];
extern char gChoisesSNscr2Name[];
extern char gChoisesSNscr3Name[];
extern char gChoisesSNscr4Name[];
extern char gChoisesSNscr5Name[];
extern char gChoisesSNscr6Name[];

unsigned int ChoisesSGetCurrentRaceKind(void);
unsigned int GetCourseNumber(void);

BOOL IsGrandPrixLastCourse(void);

unsigned int ChoisesSGetCurrentMode(void);

void *ChoisesSGetCurrentHeap(void);

void UpdateChoisesSScreenMap(void);

void UpdateChoisesS(void);

unsigned int ChoisesSGetConnectionKind(void);

BOOL IsChoisesSOpenAllowedDuringRace(void);

unsigned int GetRaceDone(void);
void ChoisesSSetLVselIndex6Requested(unsigned int value);

typedef struct InputSlotPair InputSlotPair;

u32 ChoisesSIsSlotPairNew(s32 slotIndex);
u32 ChoisesSIsPairNewUnlessRecentlyLost(InputSlotPair *inputSlotPair);
u32 ChoisesSIsPairNew(InputSlotPair *inputSlotPair);
u32 ChoisesSIsPairRecentlyLost(InputSlotPair *inputSlotPair);

unsigned int ChoisesSGetPairHasPair(InputSlotPair *inputSlotPair);

typedef struct InputSlot InputSlot;

u16 ChoisesSGetInputSlotNewBits(InputSlot *slot, u32 mask);
u16 ChoisesSGetNewBits(s32 slotIndex, u32 mask);

unsigned int GetChoisesSInputSlot(void);
unsigned int ChoisesSGetUnfilledNotEliminated(void);

s32 ChoisesSIsBackupCommandRunning(void);
s32 ChoisesSIsBackupBusy(void);
u32 IsRaceDoneOrReplayPastStartFrames(void);
u32 IsChoisesSOpenAllowedAfterRace(void);

unsigned int ChoisesSIsBackupEnabled(void);

void WriteChoisesSListScreenMap(void);

s32 GetEntryEndKind(void);
u32 GetChoisesSListIndex(void);
void WriteChoisesSSelectedValueTiles(s32 selectedIndex);

unsigned int GetEntryIndex(void);

void WriteChoisesSValueTiles(u16 *screenMap, s32 column, s32 row);
void WriteChoisesSListTiles(void);

int GetChoisesSPickedValue(void);
unsigned int GetChoisesSPrevOpenDuringRace(void);
void SetChoisesSOpenDuringRace(u32 openFlag);

u32 IsChoisesSOpen(void);

unsigned int GetChoisesSOpenDuringRace(void);

void *GetChoisesSValueMessage(s32 listIndex, s32 value);
void ClearChoisesSListValueCounts(void);
void AppendChoisesSListValue(s32 listIndex, s32 value);
s32 MoveChoisesSSelectedValue(s32 step);
u32 MoveChoisesSSelectedValueByTouch(void);
void ResetChoisesSSelection(void);
void SetChoisesSOpen(s32 openFlag);
u32 IsMissionRunTableRow6Or7Column9(void);
s8 GetMissionRunTableRow(void);
s8 GetMissionRunTableColumn(void);
BOOL IsAllMissionRecords5To7AtEndKind0(void);
