#include "03/code_021cea3c.h"

#include "03/unk_021d6000.h"
#include "03/code_021ce5b8.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "03/code_021ce000.h"
#include "03/code_021d1770.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "g2.h"
#include "registers.h"
#include "03/code_021d1790.h"
#include "03/code_021d1c18.h"
#include "03/code_021d1970.h"
#include "03/code_021d250c.h"
#include "03/code_021d2940.h"
#include "03/types_021d299c.h"

int GetMessageBoxResult(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gMessageBox;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 27u;
    value0 = *(const s8 *) ((value1) + (value0));
    return value0;
}

BOOL IsMessageBoxOpen(void) {
    if (gMessageBox != NULL) {
        return 1;
    }
    return 0;
}

void AdvanceMessageBoxBrightnessDown(TaskEntry *taskEntry) {
    gMessageBox->mBrightness--;
    G2x_ChangeBlendBrightness_(&reg_G2_BLDCNT, gMessageBox->mBrightness);
    if (gMessageBox->mBrightness <= -12) {
        SetTaskCallback(taskEntry, AdvanceMessageBoxSlideIn);
    }
}

void AdvanceMessageBoxSlideIn(u32 task) {
    u32 xPos;
    s32 yPos;

    GetOamRangeEntryPosition(gMessageBox->mBox, 0, &xPos, &yPos);
    yPos -= 0xc;
    if (yPos > gMessageBoxPositions[gMessageBox->mKind][1]) {
        PlaceMessageBox(yPos);
        return;
    }
    PlaceMessageBox(gMessageBoxPositions[gMessageBox->mKind][1]);
    if (gMessageBox->mKind == 5) {
        gMessageBox->mTask = AddTask(0, AdvanceMessageBoxTimed, NULL, 0x78);
    } else {
        gMessageBox->mTask = AddTask(0, AdvanceMessageBoxInput, NULL, 0x78);
    }
    RequestTaskRemoval(1, task);
}

void AdvanceMessageBoxInput(void) {
    s32 i;
    s32 j;
    Rect buttonRect;

    for (i = 0; i < gMessageBoxButtonCounts[gMessageBox->mKind]; i++) {
        ComputeRectFromOriginAndSize(
            gMessageBoxButtonPositions[gMessageBox->mKind][gMessageBoxButtonSlots[gMessageBox->mKind][i]],
            gMessageBoxButtonSizes[gMessageBox->mKind], &buttonRect);
        if (IsTouchPressedInRect(&buttonRect) != 0) {
            gMessageBox->mResult = i;
            break;
        }
    }
    if (AreKeysPressed(1) != 0) {
        gMessageBox->mResult = gMessageBoxKeyResults[gMessageBox->mKind][0];
    }
    if (AreKeysPressed(2) != 0) {
        gMessageBox->mResult = gMessageBoxKeyResults[gMessageBox->mKind][1];
    }
    for (j = 0; j < gMessageBoxButtonCounts[gMessageBox->mKind]; j++) {
        if (j == gMessageBox->mResult) {
            ShowMessageBoxButtonPressed(j);
            return;
        }
    }
    gMessageBox->mResult = -1;
}

void AdvanceMessageBoxTimed(u32 task) {
    gMessageBox->mResult = -1;
    gMessageBox->mTimedFrames++;
    if (gMessageBox->mTimedFrames >= 0x78) {
        RequestTaskRemoval(0, task);
        gMessageBox->mTask = AddTask(1, AdvanceMessageBoxCloseWait, NULL, 0x78);
    }
}

void PlaceMessageBox(s32 yPos) {
    s32 i;
    u8 kind;
    u16 windowRect[4];
    s32 bottom;
    s32 top;

    SetOamRangePosition(gMessageBox->mBox, -1, gMessageBoxPositions[gMessageBox->mKind][0], yPos);
    SetOamRangePosition(gMessageBox->mText, -1, gMessageBoxTextOffset[0] + gMessageBoxPositions[gMessageBox->mKind][0],
                        yPos + gMessageBoxTextOffset[1]);
    ClipOamRangeAboveY(gMessageBox->mBox, yPos);
    ClipOamRangeAboveY(gMessageBox->mText, yPos);
    for (i = 0; i < gMessageBoxButtonCounts[gMessageBox->mKind]; i++) {
        SetOamRangePosition(
            gMessageBox->mButtons[i], -1,
            gMessageBoxButtonPositions[gMessageBox->mKind][gMessageBoxButtonSlots[gMessageBox->mKind][i]][0],
            yPos + gMessageBoxButtonPositions[gMessageBox->mKind][gMessageBoxButtonSlots[gMessageBox->mKind][i]][1] -
                gMessageBoxPositions[gMessageBox->mKind][1]);
        ClipOamRangeAboveY(gMessageBox->mButtons[i], yPos);
    }
    kind = gMessageBox->mKind;
    top = yPos & 0xff;
    if (top >= 0xc0) {
        bottom = 0;
        top = 0;
    } else {
        bottom = top + gMessageBoxSizes[kind][1];
    }
    if (bottom > 0xc0) {
        bottom = 0xc0;
    }
    SetRectCorners(gMessageBoxPositions[kind][0], top, gMessageBoxPositions[kind][0] + gMessageBoxSizes[kind][0],
                   bottom, windowRect);
    WriteWinRect(0, 0, windowRect);
}

void ClipOamRangeAboveY(OamRange *range, s32 minY) {
    s32 entryCount;
    s32 i;
    u32 xPos;
    s32 yPos;
    s32 effect;

    entryCount = GetOamRangeEntryCount(range);
    for (i = 0; i < entryCount; i++) {
        GetOamRangeEntryPosition(range, i, &xPos, &yPos);
        if (yPos >= minY && yPos < 0xc0) {
            effect = 0;
        } else {
            effect = 0x200;
        }
        SetOamRangeEffect(range, i, effect, 0);
    }
}

void ShowMessageBoxButtonPressed(s32 buttonIndex) {
    CopyNceImageToOamEntries(0, gMessageBoxButtonImageIds[gMessageBox->mKind][buttonIndex] + 1,
                             GetOamRangeEntry(gMessageBox->mButtons[buttonIndex], 0));
    SetOamRangePosition(
        gMessageBox->mButtons[buttonIndex], -1,
        gMessageBoxButtonPositions[gMessageBox->mKind][gMessageBoxButtonSlots[gMessageBox->mKind][buttonIndex]][0],
        gMessageBoxButtonPositions[gMessageBox->mKind][gMessageBoxButtonSlots[gMessageBox->mKind][buttonIndex]][1]);
    SetOamRangePriority(gMessageBox->mButtons[buttonIndex], -1, 0);
}

void AdvanceMessageBoxCloseWait(TaskEntry *taskEntry) {
    gMessageBox->mCloseWaitFrames++;
    if (gMessageBox->mCloseWaitFrames >= 8) {
        SetTaskCallback(taskEntry, AdvanceMessageBoxSlideOut);
    }
}

void AdvanceMessageBoxSlideOut(TaskEntry *taskEntry) {
    u32 xPos;
    s32 yPos;

    GetOamRangeEntryPosition(gMessageBox->mBox, 0, &xPos, &yPos);
    yPos += 0xc;
    PlaceMessageBox(yPos);
    if (yPos >= 192) {
        if (gMessageBox->mAdjustBrightness != 0) {
            SetTaskCallback(taskEntry, AdvanceMessageBoxBrightnessUp);
            return;
        }
        SetTaskCallback(taskEntry, AdvanceMessageBoxRelease);
    }
}

void AdvanceMessageBoxBrightnessUp(TaskEntry *taskEntry) {
    gMessageBox->mBrightness++;
    G2x_ChangeBlendBrightness_(&reg_G2_BLDCNT, gMessageBox->mBrightness);
    if (gMessageBox->mBrightness >= 0) {
        SetTaskCallback(taskEntry, AdvanceMessageBoxRelease);
    }
}

void AdvanceMessageBoxRelease(u32 task) {
    s32 i;

    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    DeleteOamRange(gMessageBox->mBox);
    DeleteOamRange(gMessageBox->mText);
    for (i = 0; i < gMessageBoxButtonCounts[gMessageBox->mKind]; i++) {
        if (gMessageBox->mButtons[i] != NULL) {
            DeleteOamRange(gMessageBox->mButtons[i]);
        }
    }
    DeleteObjTextCanvas(gMessageBox->mTextCanvas);
    RequestTaskRemoval(1, task);
    FreeExpHeapBlockAndClearPointer(&gMessageBox);
}
