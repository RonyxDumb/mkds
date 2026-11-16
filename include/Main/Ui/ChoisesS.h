#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02024000.h"

// Seven words: six values and the number of values set.
typedef struct ChoisesSList {
    /* 00 */ s32 mValues[6];
    /* 18 */ s32 mValueCount;
} ChoisesSList;

// Object behind rchoi_sState, 0x1a4 bytes allocated by rchoi_init.
typedef struct ChoisesS {
    // Non-zero from opening the list screen in the race until it is closed there; other race code stops meanwhile.
    /* 000 */ s32 mOpenDuringRace;
    /* 004 */ s32 mPrevOpenDuringRace;
    /* 008 */ s32 mUnk_008;
    // Set once a non-zero pick is stored (not by the auto pick); open and close requests and list input are ignored.
    /* 00c */ s32 mPickLocked;
    /* 010 */ BOOL mUnk_010;
    // Calls since a list entry was picked, 0 when none; past 0xf mPickedValue is latched and this goes back to 0.
    /* 014 */ s32 mPickFrames;
    // Calls since a close was asked for, 0 when none; past 4 the close is requested and this goes back to 0.
    /* 018 */ s32 mCloseFrames;
    // Calls counted in mode 5 near the end of the race; past 0x384 mPickedValue is set with no input.
    /* 01c */ s32 mAutoPickFrames;
    /* 020 */ BOOL mUnk_020;
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

void rchoi_NNS_G2dTextCanvasInit(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing);
u32 rchoi_NNS_G2dTextCanvasDrawText(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text);
void rchoi_init(void);
void rchoi_finalize(void);

unsigned int rchoi_race_getCurrentDisplayMode(void);
unsigned int rchoi_race_getCurrentRaceNr(void);

BOOL func_020b250c(void);

unsigned int rchoi_race_getCurrentRaceMode(void);

void rchoi_update(void);

unsigned int rchoi_sysdat_getOverlayRelatedNum(void);

u32 rchoi_shouldPauseRaceDuringMenu(void);

unsigned int GetRaceDone(void);
void func_020b2a60(unsigned int p0);

typedef struct InputSlotPair InputSlotPair;

u32 rchoi_sub_20ACE14(s32 slotIndex);
u32 func_020b2a94(InputSlotPair *inputSlotPair);
u32 rchoi_spi_isPenDownEvent(InputSlotPair *inputSlotPair);
u32 rchoi_spi_isPenReleaseTimeout(InputSlotPair *inputSlotPair);

unsigned int rchoi_spi_getTpValid(const void *inputSlotPair);

s32 rchoi_savc_isBusy(void);
s32 rchoi_savd_isBusy(void);
u32 func_020b2bc8(void);
u32 rchoi_isMenuAllowed(void);

unsigned int rchoi_savc_isEnabled(void);

s32 rchoi_rstat_getMissionResult(void);
u32 rchoi_getCurChoicesSetId(void);
void rchoi_renderSelection();

unsigned int rchoi_race_getCurrentPlayerDriverId(void);

void rchoi_renderOptionBar(u16 *screenMap, s32 column, s32 row);
void rchoi_renderChoicesUnselected(void);

int rchoi_getActivatedOption(void);
unsigned int rchoi_getPrevIsRacePaused(void);
void rchoi_handleSleep(u32 openFlag);

u32 rchoi_isMenuVisible(void);

unsigned int rchoi_getIsRacePaused(void);

void *rchoi_getOptionString(s32 listIndex, s32 value);
void rchoi_resetChoicesSets(void);
void rchoi_registerOption(s32 listIndex, s32 value);
s32 rchoi_moveCursor(s32 step);
u32 rchoi_handleTouch(void);
void rchoi_resetSelectedOption(void);
void rchoi_setMenuVisible(s32 openFlag);
u32 func_020b2f58(void);
s8 rchoi_race_getCurrentMissionLevel(void);
s8 rchoi_race_getCurrentMissionIdx(void);
u32 rchoi_20B2ECC(void);
