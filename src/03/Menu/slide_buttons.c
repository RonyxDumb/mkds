#include "03/Menu/slide_buttons.h"
#include "03/code_021bf000.h"

#include "03/code_021be610.h"
#include "03/code_021d1000.h"
#include "03/Graphics/nce_oam.h"
#include "03/code_021d1790.h"
#include "03/code_021d1970.h"
#include "03/code_021d197c.h"
#include "03/code_021d1c18.h"
#include "03/System/rect.h"
#include "03/System/task_input.h"
#include "03/code_021d3000.h"
#include "03/System/tasks.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/System/exp_heap.h"
#include "code_02147cd8.h"
#include "03/code_021d2ecc.h"

const u8 gAnimatedIconPalettes[3] = {0xe, 4, 5};
const u16 gAnimatedIconPosition[2] = {0xe6, 0x8b};
const u16 gSlideButtonsPosition[2] = {0, 0xa8};
const u16 gSlideButtonSize[2] = {0x78, 0x10};
const u16 gSlideButtonOrigins[4] = {8, 0xac, 0x84, 0xac};
const u8 gSlideButtonImages[14] = {0x27, 0x1f, 0x25, 0, 0x27, 0, 0x23, 0x1d, 0x21, 0, 0x59, 0, 0x27, 0x21};
const u8 gSlideButtonPositionIndices[14] = {0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1};
const u8 gSlideButtonCounts[7] = {2, 1, 1, 2, 1, 1, 2};
AnimatedIcon *gAnimatedIcon;
SlideButtons *gSlideButtons;

void CreateSlideButtons(u32 kind) {
    s32 buttonCount;
    s32 i;
    const u8 *imageCursor;

    buttonCount = gSlideButtonCounts[kind];
    gSlideButtons = AllocZeroedExpHeapBlock(0x1c, 4);
    gSlideButtons->mButtonResult = -2;
    gSlideButtons->mKind = kind;
    i = 0;
    if (buttonCount > 0) {
        imageCursor = gSlideButtonImages + kind * 2;
        do {
            gSlideButtons->mButtons[i] = CreateOamRangeFromNceImage(0, *imageCursor, 1);
            SetOamRangePriority(gSlideButtons->mButtons[i], -1, 1);
            imageCursor++;
            i++;
        } while (i < buttonCount);
    }
    gSlideButtons->mUnk_08 = CreateOamRangeFromNceImage(0, 1, 1);
    SetOamRangePriority(gSlideButtons->mUnk_08, -1, 1);
    SetSlideButtonsY(0xc0);
    gSlideButtons->mStepTask = (TaskEntry *) AddTask(0, AdvanceSlideButtonsIn, NULL, 0x78);
}

void StartSlideButtonsOut(void) {
    gSlideButtons->mSlidingOut = 1;
    SetTaskCallback(gSlideButtons->mStepTask, AdvanceSlideButtonsOut);
}

int GetButtonResult(void) {
    return gSlideButtons->mButtonResult;
}

void SetButtonResultIfNone(s32 result) {
    SlideButtons *slideButtons = gSlideButtons;
    if (slideButtons->mButtonResult == -1) {
        slideButtons->mButtonResult = result;
    }
}

void SetButtonResult(s8 result) {
    gSlideButtons->mButtonResult = result;
}

BOOL IsSlideButtonsNotSlidingOut(void) {
    if (gSlideButtons == NULL) {
        return 1;
    }
    if (gSlideButtons->mSlidingOut == 0) {
        return 1;
    }
    return 0;
}

void EnableButtonTouch(void) {
    gSlideButtons->mTouchDisabled = 0;
}

void DisableButtonTouch(void) {
    gSlideButtons->mTouchDisabled = 1;
}

void SetSlideButtonsY(s32 yPosition) {
    s32 buttonCount;
    s32 i;
    s32 buttonY;

    buttonCount = gSlideButtonCounts[gSlideButtons->mKind];
    buttonY = yPosition + gSlideButtonOrigins[1] - gSlideButtonsPosition[1];
    SetOamRangePosition(gSlideButtons->mUnk_08, -1, gSlideButtonsPosition[0], yPosition);
    for (i = 0; i < buttonCount; i++) {
        SetOamRangePosition(gSlideButtons->mButtons[i], -1,
                            gSlideButtonOrigins[(gSlideButtonPositionIndices + gSlideButtons->mKind * 2)[i] * 2],
                            buttonY);
    }
}

void AdvanceSlideButtonsIn(TaskEntry *task) {
    u32 xPosition;
    s32 yPosition;

    GetOamRangeEntryPosition(gSlideButtons->mUnk_08, 0, &xPosition, &yPosition);
    yPosition = yPosition - 4;
    SetSlideButtonsY(yPosition);
    if (yPosition <= gSlideButtonsPosition[1]) {
        SetSlideButtonsY(gSlideButtonsPosition[1]);
        SetTaskCallback(task, AdvanceSlideButtonsWait);
    }
}

void AdvanceSlideButtonsWait(TaskEntry *task) {
    u32 a = 0;

    gSlideButtons->mButtonResult = -1;
    gSlideButtons->mStepFrames = gSlideButtons->mStepFrames + 1;
    if (gSlideButtons->mStepFrames >= 4) {
        gSlideButtons->mStepFrames = a;
        SetTaskCallback(task, AdvanceButtonTouch);
    }
}

void AdvanceButtonTouch(void) {
    Rect rect;
    s32 buttonCount;
    s32 i;
    u32 positionIndex;
    u32 touchedImage;

    buttonCount = gSlideButtonCounts[gSlideButtons->mKind];
    if (gSlideButtons->mTouchDisabled == 0) {
        if (gSlideButtons->mButtonResult != -1) {
            return;
        }
        for (i = 0; i < buttonCount; i++) {
            ComputeRectFromOriginAndSize(
                &gSlideButtonOrigins[(gSlideButtonPositionIndices + gSlideButtons->mKind * 2)[i] * 2], gSlideButtonSize,
                &rect);
            if (IsTouchPressedInRect(&rect) != 0) {
                if (gSlideButtons->mResetTask != 0) {
                    break;
                }
                touchedImage = (gSlideButtonImages + gSlideButtons->mKind * 2)[i] + 1;
                CopyNceImageToOamEntries(0, touchedImage, GetOamRangeEntry(gSlideButtons->mButtons[i], 0));
                positionIndex = (gSlideButtonPositionIndices + gSlideButtons->mKind * 2)[i];
                SetOamRangePosition(gSlideButtons->mButtons[i], -1, gSlideButtonOrigins[positionIndex * 2],
                                    (&gSlideButtonOrigins[1])[positionIndex * 2]);
                SetOamRangePriority(gSlideButtons->mButtons[i], -1, 1);
                gSlideButtons->mResetTask = AddTask(0, AdvanceButtonReset, NULL, 0x6e);
                gSlideButtons->mButtonResult = i;
                return;
            }
        }
    }
    gSlideButtons->mButtonResult = -1;
}

void AdvanceSlideButtonsOut(TaskEntry *task) {
    u32 stackValue;
    int yPosition;
    GetOamRangeEntryPosition(gSlideButtons->mUnk_08, 0, &stackValue, &yPosition);
    yPosition = yPosition + 4;
    SetSlideButtonsY(yPosition);
    if (192 <= yPosition) {
        SetTaskCallback(task, ReleaseSlideButtons);
    }
}

void ReleaseSlideButtons(u32 task) {
    SlideButtons *slideButtons;
    s32 i;

    RequestTaskRemoval(0, task);
    slideButtons = gSlideButtons;
    if (slideButtons->mResetTask != 0) {
        RequestTaskRemoval(0, slideButtons->mResetTask);
    }
    for (i = 0; i < 2; i++) {
        if (gSlideButtons->mButtons[i] != 0) {
            DeleteOamRange(gSlideButtons->mButtons[i]);
        }
    }
    DeleteOamRange(gSlideButtons->mUnk_08);
    FreeExpHeapBlockAndClearPointer(&gSlideButtons);
}

void AdvanceButtonReset(u32 task) {
    SlideButtons *slideButtons;
    s32 i;
    s32 buttonCount;
    u32 imageIndex;
    u32 c;
    u32 d;

    slideButtons = gSlideButtons;
    slideButtons->mStepFrames = slideButtons->mStepFrames + 1;
    if (gSlideButtons->mStepFrames >= 0x10) {
        slideButtons = gSlideButtons;
        buttonCount = gSlideButtonCounts[slideButtons->mKind];
        for (i = 0; i < buttonCount; i++) {
            slideButtons = gSlideButtons;
            imageIndex = (gSlideButtonImages + slideButtons->mKind * 2)[i];
            CopyNceImageToOamEntries(0, imageIndex, GetOamRangeEntry(slideButtons->mButtons[i], 0));
            SetOamRangePriority(gSlideButtons->mButtons[i], -1, 1);
        }
        SetSlideButtonsY(gSlideButtonsPosition[1]);
        gSlideButtons->mStepFrames = 0;
        gSlideButtons->mButtonResult = -1;
        slideButtons = gSlideButtons;
        if (slideButtons->mResetTask != 0) {
            slideButtons->mResetTask = 0;
            RequestTaskRemoval(0, task);
        }
    }
}

void CreateAnimatedIcon(int index) {
    AnimatedIcon *object;
    OamEntry *innerObject;
    u32 c;

    object = AllocZeroedExpHeapBlock(0xc, 4);
    gAnimatedIcon = object;
    object->mPaletteIndex = index;
    gAnimatedIcon->mOamEntry = CreateOamEntryFromNceImage(0, 0x47);
    innerObject = gAnimatedIcon->mOamEntry;
    innerObject->mAttr2 = (innerObject->mAttr2 & 0xfffff3ff) | 0x400;
    innerObject = gAnimatedIcon->mOamEntry;
    innerObject->mAttr01 = innerObject->mAttr01 & 0xfffff3ff;
    innerObject->mAttr2 = (innerObject->mAttr2 & 0xffff0fff) | (gAnimatedIconPalettes[index] << 12);
    innerObject = gAnimatedIcon->mOamEntry;
    innerObject->mAttr01 = ((gAnimatedIconPosition[0] & 0x1ff) << 16) |
                           ((innerObject->mAttr01 & 0xfe00ff00) | (gAnimatedIconPosition[1] & 0xff));
    gAnimatedIcon->mTask = AddTask(1, AdvanceAnimatedIcon, NULL, 0x78);
}

void ReleaseAnimatedIcon(void) {
    RemoveTaskEntryWrapper(1, gAnimatedIcon->mTask);
    DeleteOamEntry((u32 *) gAnimatedIcon->mOamEntry);
    FreeExpHeapBlockAndClearPointer(&gAnimatedIcon);
}

void AdvanceAnimatedIcon(void) {
    AnimatedIcon *object;
    OamEntry *innerObject;
    u32 c;

    gAnimatedIcon->mStepFrames = FX_ModS32(gAnimatedIcon->mStepFrames + 1, 0x28);
    c = FX_DivS32(gAnimatedIcon->mStepFrames, 5) + 0x47;
    CopyNceImageToOamEntries(0, c, gAnimatedIcon->mOamEntry);
    innerObject = gAnimatedIcon->mOamEntry;
    innerObject->mAttr2 = (innerObject->mAttr2 & 0xfffff3ff) | 0x400;
    object = gAnimatedIcon;
    c = gAnimatedIconPalettes[object->mPaletteIndex];
    innerObject = object->mOamEntry;
    innerObject->mAttr01 = innerObject->mAttr01 & 0xfffff3ff;
    innerObject->mAttr2 = (innerObject->mAttr2 & 0xffff0fff) | (c << 12);
    innerObject = gAnimatedIcon->mOamEntry;
    innerObject->mAttr01 = ((gAnimatedIconPosition[0] & 0x1ff) << 16) |
                           ((innerObject->mAttr01 & 0xfe00ff00) | (gAnimatedIconPosition[1] & 0xff));
}
