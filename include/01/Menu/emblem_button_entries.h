#pragma once

#include "types.h"
#include "g2d_Animation.h"

// Object that the per-entry update callbacks around AdvanceEmblemButtonHold work on.
typedef struct LldEntry {
    /* 00 */ u16 mAnimIndex;
    /* 02 */ u8 mUnk_02[0x2];
    /* 04 */ s32 mPosX;
    /* 08 */ s32 mPosY;
    /* 0c */ BOOL mShown;
    /* 10 */ s32 mCallbackCallCount;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mScale;
    /* 1c */ s32 mBoundsLeft;
    /* 20 */ s32 mBoundsRight;
    /* 24 */ s32 mBoundsTop;
    /* 28 */ s32 mBoundsBottom;
    /* 2c */ NNSG2dCellAnimation mCellAnim;
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
s32 AdvanceEmblemCursor(s32 down, s32 pointX, s32 pointY, s32 inputBits, s32 dx, s32 dy);
void CreateEmblemCursorAndGrid(s32 originX, s32 originY, s32 side, s32 scrSide, s32 tableCount);
BOOL SetEmblemCursorCellValueFromGrid(void);
s32 FillEmblemGridAtCursorCell(void);
BOOL IsEmblemPointInGrid(s32 pointX, s32 pointY);
s32 GetEmblemCursorPrevPointY(void);
s32 GetEmblemCursorPrevPointX(void);
s32 GetEmblemCursorPointY(void);
s32 GetEmblemCursorPointX(void);
void SetEmblemCursorCellFromPoint(s32 pointX, s32 pointY);
s32 GetEmblemCursorSizeIndex(void);
void SetEmblemCursorSizeIndex(s32 sizeIndex);
s32 GetEmblemCursorMode(void);
void SetEmblemCursorMode(s32 mode);
u8 GetEmblemCursorCellValue(void);
void SetEmblemCursorCellValue(u8 cellValue);
void SetEmblemCursorCellShift(s32 shift);
void ClampEmblemCursorCell(void);
