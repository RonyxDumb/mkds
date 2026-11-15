#include "03/Menu/message_box.h"

#include "03/unk_021d6000.h"
#include "03/Net/usb_scan.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "03/code_021ce000.h"
#include "03/Graphics/nce_oam.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"
#include "03/Graphics/text_canvas.h"
#include "03/System/exp_heap.h"
#include "03/System/tasks.h"
#include "g2.h"
#include "registers.h"
#include "03/code_021d1790.h"
#include "03/code_021d1c18.h"
#include "03/code_021d1970.h"
#include "03/System/rect.h"
#include "03/System/task_input.h"
#include "03/types_021d299c.h"

const u16 gMessageBoxTextOffset[2] = {8, 8};
const u8 gMessageBoxButtonCounts[6] = {2, 1, 2, 1, 2, 0};
const u8 gMessageBoxImageIds[6] = {0, 0, 0x46, 0x46, 0x4f, 0x2f};
const u16 gMessageBoxWindowRect[4] = {4, 0x1d, 0xfc, 0x44};
const u8 gMessageBoxButtonSlots[6][2] = {{0, 1}, {1, 0}, {0, 1}, {1, 0}, {0, 1}, {0, 0}};
const u16 gMessageBoxButtonSizes[5][2] = {{0x6c, 0x10}, {0x6c, 0x10}, {0x78, 0x10}, {0x78, 0x10}, {0x78, 0x10}};
const u8 gMessageBoxButtonImageIds[6][2] = {{0x1b, 0x19}, {0x57, 0}, {0x23, 0x1d}, {0x59, 0}, {0x23, 0x1d}, {0, 0}};
Bytes6 gMessageBoxWindowExtraBitFlags = {{1, 1, 0, 0, 1, 1}};
const u16 gMessageBoxTextSizes[6][2] = {{0xd8, 0x50}, {0xd8, 0x50}, {0xe6, 0x4f},
                                        {0xe6, 0x4f}, {0xe6, 0x48}, {0xda, 0x5c}};
const u16 gMessageBoxPositions[6][2] = {{0xb, 0x27}, {0xb, 0x27}, {4, 0x4c}, {4, 0x4c}, {4, 0x54}, {0xb, 0x27}};
const u16 gMessageBoxSizes[6][2] = {{0xea, 0x72}, {0xea, 0x72}, {0xf8, 0x70}, {0xf8, 0x70}, {0x64, 0x70}, {0xea, 0x72}};
const u16 gMessageBoxButtonPositions[5][2][2] = {{{0x10, 0x84}, {0x84, 0x84}},
                                                 {{0x10, 0x84}, {0x84, 0x84}},
                                                 {{9, 0xa7}, {0x83, 0xa7}},
                                                 {{9, 0xa7}, {0x83, 0xa7}},
                                                 {{9, 0xa7}, {0x83, 0xa7}}};
const s8 gMessageBoxKeyResults[6][2] = {{1, 0}, {0, -1}, {1, 0}, {0, -1}, {1, 0}, {0, 0}};
MessageBox *gMessageBox;

int GetMessageBoxResult(void) {
    u32 boxResult;
    u32 boxData;
    boxResult = (u32) &gMessageBox;
    boxData = *(const u32 *) ((boxResult) + 0u);
    boxResult = 27u;
    boxResult = *(const s8 *) ((boxData) + (boxResult));
    return boxResult;
}

BOOL IsMessageBoxOpen(void) {
    if (gMessageBox != NULL) {
        return 1;
    }
    return 0;
}

void AdvanceMessageBoxBrightnessDown(TaskEntry *taskEntry, void *arg) {
    gMessageBox->mBrightness--;
    G2x_ChangeBlendBrightness_(&reg_G2_BLDCNT, gMessageBox->mBrightness);
    if (gMessageBox->mBrightness <= -12) {
        SetTaskCallback(taskEntry, AdvanceMessageBoxSlideIn);
    }
}

void AdvanceMessageBoxSlideIn(TaskEntry *task, void *arg) {
    s32 xPos;
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

void AdvanceMessageBoxInput(TaskEntry *task, void *arg) {
    s32 touchIndex;
    s32 buttonIndex;
    Rect buttonRect;

    for (touchIndex = 0; touchIndex < gMessageBoxButtonCounts[gMessageBox->mKind]; touchIndex++) {
        ComputeRectFromOriginAndSize(
            gMessageBoxButtonPositions[gMessageBox->mKind][gMessageBoxButtonSlots[gMessageBox->mKind][touchIndex]],
            gMessageBoxButtonSizes[gMessageBox->mKind], &buttonRect);
        if (IsTouchPressedInRect(&buttonRect) != 0) {
            gMessageBox->mResult = touchIndex;
            break;
        }
    }
    if (AreKeysPressed(1) != 0) {
        gMessageBox->mResult = gMessageBoxKeyResults[gMessageBox->mKind][0];
    }
    if (AreKeysPressed(2) != 0) {
        gMessageBox->mResult = gMessageBoxKeyResults[gMessageBox->mKind][1];
    }
    for (buttonIndex = 0; buttonIndex < gMessageBoxButtonCounts[gMessageBox->mKind]; buttonIndex++) {
        if (buttonIndex == gMessageBox->mResult) {
            ShowMessageBoxButtonPressed(buttonIndex);
            return;
        }
    }
    gMessageBox->mResult = -1;
}

void AdvanceMessageBoxTimed(TaskEntry *task, void *arg) {
    gMessageBox->mResult = -1;
    gMessageBox->mTimedFrames++;
    if (gMessageBox->mTimedFrames >= 0x78) {
        RequestTaskRemoval(0, task);
        gMessageBox->mTask = AddTask(1, AdvanceMessageBoxCloseWait, NULL, 0x78);
    }
}

void PlaceMessageBox(s32 yPos) {
    s32 buttonIndex;
    u8 kind;
    u16 windowRect[4];
    s32 bottom;
    s32 top;

    SetOamRangePosition(gMessageBox->mBox, -1, gMessageBoxPositions[gMessageBox->mKind][0], yPos);
    SetOamRangePosition(gMessageBox->mText, -1, gMessageBoxTextOffset[0] + gMessageBoxPositions[gMessageBox->mKind][0],
                        yPos + gMessageBoxTextOffset[1]);
    ClipOamRangeAboveY(gMessageBox->mBox, yPos);
    ClipOamRangeAboveY(gMessageBox->mText, yPos);
    for (buttonIndex = 0; buttonIndex < gMessageBoxButtonCounts[gMessageBox->mKind]; buttonIndex++) {
        SetOamRangePosition(
            gMessageBox->mButtons[buttonIndex], -1,
            gMessageBoxButtonPositions[gMessageBox->mKind][gMessageBoxButtonSlots[gMessageBox->mKind][buttonIndex]][0],
            yPos +
                gMessageBoxButtonPositions[gMessageBox->mKind][gMessageBoxButtonSlots[gMessageBox->mKind][buttonIndex]]
                                          [1] -
                gMessageBoxPositions[gMessageBox->mKind][1]);
        ClipOamRangeAboveY(gMessageBox->mButtons[buttonIndex], yPos);
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
    s32 entryIndex;
    s32 xPos;
    s32 yPos;
    s32 effect;

    entryCount = GetOamRangeEntryCount(range);
    for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
        GetOamRangeEntryPosition(range, entryIndex, &xPos, &yPos);
        if (yPos >= minY && yPos < 0xc0) {
            effect = 0;
        } else {
            effect = 0x200;
        }
        SetOamRangeEffect(range, entryIndex, effect, 0);
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

void AdvanceMessageBoxCloseWait(TaskEntry *taskEntry, void *arg) {
    gMessageBox->mCloseWaitFrames++;
    if (gMessageBox->mCloseWaitFrames >= 8) {
        SetTaskCallback(taskEntry, AdvanceMessageBoxSlideOut);
    }
}

void AdvanceMessageBoxSlideOut(TaskEntry *taskEntry, void *arg) {
    s32 xPos;
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

void AdvanceMessageBoxBrightnessUp(TaskEntry *taskEntry, void *arg) {
    gMessageBox->mBrightness++;
    G2x_ChangeBlendBrightness_(&reg_G2_BLDCNT, gMessageBox->mBrightness);
    if (gMessageBox->mBrightness >= 0) {
        SetTaskCallback(taskEntry, AdvanceMessageBoxRelease);
    }
}

void AdvanceMessageBoxRelease(TaskEntry *task, void *arg) {
    s32 buttonIndex;

    reg_GX_DISPCNT = reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
    DeleteOamRange(gMessageBox->mBox);
    DeleteOamRange(gMessageBox->mText);
    for (buttonIndex = 0; buttonIndex < gMessageBoxButtonCounts[gMessageBox->mKind]; buttonIndex++) {
        if (gMessageBox->mButtons[buttonIndex] != NULL) {
            DeleteOamRange(gMessageBox->mButtons[buttonIndex]);
        }
    }
    DeleteObjTextCanvas(gMessageBox->mTextCanvas);
    RequestTaskRemoval(1, task);
    FreeExpHeapBlockAndClearPointer(&gMessageBox);
}
