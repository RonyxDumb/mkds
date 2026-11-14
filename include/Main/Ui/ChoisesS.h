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

// Object behind gChoisesS, 0x1a4 bytes allocated by InitChoisesS.
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

void func_020b24cc(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing);
u32 func_020b24a4(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text);
void InitChoisesS(void);
void ClearChoisesSPointer(void);

unsigned int func_020b24e4(void);
unsigned int GetCourseNumber(void);

BOOL func_020b250c(void);

unsigned int func_020b252c(void);

void UpdateChoisesS(void);

unsigned int func_020b29b0(void);

u32 func_020b29c4(void);

unsigned int GetRaceDone(void);
void func_020b2a60(unsigned int p0);

typedef struct InputSlotPair InputSlotPair;

u32 func_020b2a74(s32 slotIndex);
u32 func_020b2a94(InputSlotPair *inputSlotPair);
u32 func_020b2ac8(InputSlotPair *inputSlotPair);
u32 func_020b2aec(InputSlotPair *inputSlotPair);

unsigned int func_020b2b1c(const void *inputSlotPair);

s32 func_020b2c24(void);
s32 func_020b2bf0(void);
u32 func_020b2bc8(void);
u32 func_020b2b70(void);

unsigned int func_020b2c54(void);

s32 GetEntryEndKind(void);
u32 GetChoisesSListIndex(void);
void func_020b2c80();

unsigned int GetEntryIndex(void);

void func_020b2e00(u16 *screenMap, s32 column, s32 row);
void func_020b2da4(void);

int func_020b2e34(void);
unsigned int GetChoisesSPrevOpenDuringRace(void);
void func_020b2e64(u32 openFlag);

u32 func_020b2e98(void);

unsigned int GetChoisesSOpenDuringRace(void);

void *GetChoisesSValueMessage(s32 listIndex, s32 value);
void ClearChoisesSListValueCounts(void);
void AppendChoisesSListValue(s32 listIndex, s32 value);
s32 MoveChoisesSSelectedValue(s32 step);
u32 func_020b302c(void);
void ResetChoisesSSelection(void);
void func_020b2f88(s32 openFlag);
u32 func_020b2f58(void);
s8 GetMissionRunTableRow(void);
s8 GetMissionRunTableColumn(void);
u32 func_020b2ecc(void);
