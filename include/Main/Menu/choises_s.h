#pragma once

#include "types.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/text_canvas.h"

// Values of ChoisesS.mPickedValue and of the list entries: the entry's label on the screen, in the order of the
// message table in GetMenuOptionString_from_thumb. 0 as a pick means nothing was picked; CHOISES_S_PICK_NEXT_LAST is the
// next entry once the course count is reached.
#define CHOISES_S_PICK_NONE 0
#define CHOISES_S_PICK_CONTINUE 0
#define CHOISES_S_PICK_RETRY 1
#define CHOISES_S_PICK_NEXT 2
#define CHOISES_S_PICK_RESTART 3
#define CHOISES_S_PICK_CHANGE_COURSE 4
#define CHOISES_S_PICK_CHANGE_CHARACTERS 5
#define CHOISES_S_PICK_SELECT_MISSION 6
#define CHOISES_S_PICK_NEXT_LAST 7
#define CHOISES_S_PICK_REPLAY 8
#define CHOISES_S_PICK_QUIT 9
#define CHOISES_S_PICK_STAFF_CREDITS 10

// Frames the pick stays before it is latched, frames the close stays, frames the cycle of the list marks lasts and the
// frames of it the mark is lit, and frames before the race picks by itself in the Wi-Fi mode.
#define CHOISES_S_PICK_FRAMES 0xf
#define CHOISES_S_PICK_START_FRAMES 5
#define CHOISES_S_CLOSE_FRAMES 4
#define CHOISES_S_CYCLE_FRAMES 0x32
#define CHOISES_S_CYCLE_LIT_FRAMES 0x1e
#define CHOISES_S_AUTO_PICK_FRAMES 0x384
// mOpenDuringRaceState once the list was open for a frame.
#define CHOISES_S_OPEN_DURING_RACE_SETTLED 2
// Screen x range of the value rects.
#define CHOISES_S_RECT_MIN_X 8
#define CHOISES_S_RECT_MAX_X 0xf8

// A list of up to six choice values and how many are in use.
typedef struct ChoisesSList {
    /* 00 */ s32 mValues[6];
    /* 18 */ s32 mValueCount;
} ChoisesSList;

// The choice list shown during a race: its open and pick state, selected value, lists, font, canvases and screen files.
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
    /* 02c */ s32 mOpenDuringRaceState;
    /* 030 */ s32 mOpenDuringRaceFrames;
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

void RaceOptionMenuEntryDrawContext_Create(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing);
u32 G2d_Text_PrintString3(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text);
void LoadRaceOptionMenus_from_thumb(void);
void ResetRaceMenuOptions_from_thumb(void);

extern struct ChoisesS *g_RaceOptionMenuManager;
extern char gChoisesSNscr1Name[];
extern char gChoisesSNscr2Name[];
extern char gChoisesSNscr3Name[];
extern char gChoisesSNscr4Name[];
extern char gChoisesSNscr5Name[];
extern char gChoisesSNscr6Name[];

unsigned int GetDisplayMode_0(void);
unsigned int GetCourseNumber(void);

BOOL IsGrandPrixLastCourse(void);

unsigned int GetRaceMode(void);

void *GetActiveExecutionContextHeapHandle_3(void);

void LoopFn_RaceMenuOptions2_from_thumb(void);

void LoopFn_RaceMenuOptions_from_thumb(void);

unsigned int GetPMaybeState_0(void);

BOOL IsChoisesSOpenAllowedDuringRace(void);

unsigned int IsRaceEnded(void);
void SetB488_B6(unsigned int value);

typedef struct InputSlotPair InputSlotPair;

u32 ChoisesSIsSlotPairNew(s32 slotIndex);
u32 ChoisesSIsPairNewUnlessRecentlyLost(InputSlotPair *inputSlotPair);
u32 ChoisesSIsPairNew(InputSlotPair *inputSlotPair);
u32 ChoisesSIsPairRecentlyLost(InputSlotPair *inputSlotPair);

unsigned int ChoisesSGetPairHasPair(InputSlotPair *inputSlotPair);

typedef struct InputSlot InputSlot;

u16 ChoisesSGetInputSlotNewBits(InputSlot *slot, u32 mask);
u16 ChoisesSGetNewBits(s32 slotIndex, u32 mask);

unsigned int Const8_0(void);
unsigned int IsCurrentMissionNotBeaten(void);

s32 SaveDataIoManagerIsBusy12(void);
s32 SaveDataHolderIsBusy(void);
u32 IsRaceDoneOrReplayPastStartFrames(void);
u32 IsChoisesSOpenAllowedAfterRace(void);

unsigned int SaveDataIoManagerIsBusy(void);

void WriteChoisesSListScreenMap(void);

s32 GetEntryEndKind(void);
u32 GetCurrentOptionMenuKind_from_thumb(void);
void WriteChoisesSSelectedValueTiles(s32 selectedIndex);

unsigned int GetCurrentPlayerRacerId_0(void);

void WriteChoisesSValueTiles(u16 *screenMap, s32 column, s32 row);
void WriteChoisesSListTiles(void);

int GetChoisesSPickedValue(void);
unsigned int MaybeIsMenuOn_from_thumb(void);
void SetChoisesSOpenDuringRace(u32 openFlag);

u32 IsChoisesSOpen(void);

unsigned int IsRaceOptionMenuOn_from_thumb(void);

void *GetMenuOptionString_from_thumb(s32 listIndex, s32 value);
void ClearRaceOptionMenuEntries_from_thumb(void);
void AppendChoisesSListValue(s32 listIndex, s32 value);
s32 MaybeOnMenuOptionScroll_from_thumb(s32 step);
u32 MoveChoisesSSelectedValueByTouch(void);
void ResetChoisesSSelection(void);
void SetChoisesSOpen(s32 openFlag);
u32 IsCurrentMission_Boss6OrBoss7_from_thumb(void);
s8 GetCurrentMissionLevel_0(void);
s8 GetCurrentMissionLevelStage_0(void);
BOOL IsAllMissionRecords5To7AtGoalEnd(void);
