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

void CreateSlideButtons(u32 kind) {
    s32 buttonCount;
    s32 i;
    u8 *imageCursor;

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
                                    gSlideButtonOriginYs[positionIndex * 2]);
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
