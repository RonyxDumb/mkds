#pragma once

#include "types.h"
#include "code_02022030.h"

// Object at Unk021a5a58_2c.mUnk_2c.
typedef struct Unk021a5a58_2c_2c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[0x4];
    /* 08 */ s16 mUnk_08[4];
} Unk021a5a58_2c_2c;

// Object at LldEntry.mUnk_2c.
typedef struct Unk021a5a58_2c {
    /* 00 */ u8 mUnk_00[0x8];
    /* 08 */ BOOL mUnk_08;
    /* 0c */ u8 mUnk_0c[0x8];
    /* 14 */ s32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x14];
    /* 2c */ Unk021a5a58_2c_2c *mUnk_2c;
    /* 30 */ u8 mUnk_30[0x24];
} Unk021a5a58_2c;

// Object that the per-entry update callbacks around AdvanceEmblemButtonHold work on.
typedef struct LldEntry {
    /* 00 */ u16 mAnimIndex;
    /* 02 */ u8 mUnk_02[0x2];
    /* 04 */ s32 mPosX;
    /* 08 */ s32 mPosY;
    /* 0c */ BOOL mShown;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mScale;
    /* 1c */ s32 mBoundsLeft;
    /* 20 */ s32 mBoundsRight;
    /* 24 */ s32 mBoundsTop;
    /* 28 */ s32 mBoundsBottom;
    /* 2c */ Unk02022030 mUnk_2c;
    /* 80 */ struct Lld *mLld;
    /* 84 */ s32 (*mCallback)(struct LldEntry *);
} LldEntry;

void StartEmblemButtonBounceAndToggle(void *lld, s32 index);
void StartEmblemButtonHold(void *lld, s32 index);
BOOL AdvanceEmblemButtonHold(LldEntry *entry);
void StartEmblemModeButtonPress(void *lld, s32 index);
void ResetEmblemButton(void *lld, s32 index);
BOOL AdvanceEmblemModeButtonPress(LldEntry *entry);
void StartEmblemButtonBounce(void *lld, s32 index);
BOOL AdvanceEmblemButtonBounce(LldEntry *entry);
void StartEmblemButtonBounceThenWait(void *lld, s32 index);
BOOL AdvanceEmblemButtonBounceThenWait(LldEntry *entry);
void StartEmblemColorCursorShrinkAndGrow(void *lld, s32 index);
BOOL AdvanceEmblemColorCursorGrow(LldEntry *entry);
BOOL AdvanceEmblemColorCursorShrink(LldEntry *entry);
s32 AdvanceEmblemCursor(s32 down, s32 x, s32 y, s32 d, s32 dx, s32 dy);
void CreateEmblemCursorAndGrid(s32 originX, s32 originY, s32 side, s32 scrSide, s32 tableCount);
BOOL SetEmblemCursorCellValueFromGrid(void);
s32 FillEmblemGridAtCursorCell(void);
BOOL IsEmblemPointInGrid(s32 x, s32 y);
s32 GetEmblemCursorPrevPointY(void);
s32 GetEmblemCursorPrevPointX(void);
s32 GetEmblemCursorPointY(void);
s32 GetEmblemCursorPointX(void);
void SetEmblemCursorCellFromPoint(s32 x, s32 y);
s32 GetEmblemCursorSizeIndex(void);
void SetEmblemCursorSizeIndex(s32 sizeIndex);
s32 GetEmblemCursorMode(void);
void SetEmblemCursorMode(s32 mode);
u8 GetEmblemCursorCellValue(void);
void SetEmblemCursorCellValue(u8 cellValue);
void SetEmblemCursorCellShift(s32 shift);
void ClampEmblemCursorCell(void);
