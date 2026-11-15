#include "03/Menu/edit_keyboard_slide_out.h"
#include "03/Menu/edit_keyboard.h"
#include "03/unk_021da000.h"
#include "03/Graphics/nce_oam.h"
#include "03/System/tasks.h"
#include "03/code_021d1970.h"
#include "03/code_021d197c.h"
#include "03/code_021d2ecc.h"
#include "03/System/exp_heap.h"
#include "03/Graphics/text_canvas.h"

const u8 gEditKeyboardRow4KeyImages[2] = {0x3c, 0x3d};
const u8 gEditKeyboardRow4Inputs[2] = {0x82, 0x83};
const u8 gEditKeyboardKeyPalettes[2] = {2, 3};
const u8 gEditKeyboardRow4HighlightValues[2] = {4, 5};
const u8 gEditKeyboardExtraKeyImages[4] = {0x3a, 0x3b, 0x35, 0x39};
const u16 gEditKeyboardRow4KeySize[1][2] = {{0x78, 0x12}};
const u16 gEditKeyboardKeySize[1][2] = {{0x11, 0x12}};
const u16 gEditKeyboardRowTextAreaSize[2] = {0x1c, 2};
const u8 gEditKeyboardExtraKeyInputs[5] = {0xff, 0xff, 0x20, 0x80, 0};
const u16 gEditKeyboardRow4KeyPositions[2][2] = {{4, 0xaa}, {0x84, 0xaa}};

static inline void EditKeyboardOutG2_GetOBJPosition(OamEntry *object, u32 *x, u32 *y) {
    *x = (object->mAttr01 & 0x1ff0000) >> 16;
    *y = object->mAttr01 & 0xff;
}

void AdvanceEditKeyboardSlideOutRow4(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditKeyboardOutG2_GetOBJPosition(GetOamRangeEntry(gEditKeyboard->mRow4Keys[0], 0), (u32 *) &xPos, (u32 *) &yPos);
    yPos += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 4, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, AdvanceEditKeyboardSlideOutRow3);
    }
}

void AdvanceEditKeyboardSlideOutRow3(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditKeyboardOutG2_GetOBJPosition(gEditKeyboard->mKeys[36], (u32 *) &xPos, (u32 *) &yPos);
    yPos += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 3, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, AdvanceEditKeyboardSlideOutRow2);
    }
}

void AdvanceEditKeyboardSlideOutRow2(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditKeyboardOutG2_GetOBJPosition(gEditKeyboard->mKeys[24], (u32 *) &xPos, (u32 *) &yPos);
    yPos += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 2, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, AdvanceEditKeyboardSlideOutRow1);
    }
}

void AdvanceEditKeyboardSlideOutRow1(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditKeyboardOutG2_GetOBJPosition(gEditKeyboard->mKeys[12], (u32 *) &xPos, (u32 *) &yPos);
    yPos += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 1, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, AdvanceEditKeyboardSlideOutRow0);
    }
}

void AdvanceEditKeyboardSlideOutRow0(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditKeyboardOutG2_GetOBJPosition(gEditKeyboard->mKeys[0], (u32 *) &xPos, (u32 *) &yPos);
    yPos += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 0, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, ReleaseEditKeyboard);
    }
}

void ReleaseEditKeyboard(TaskEntry *task, void *arg) {
    s32 index;
    s32 rowIndex;
    RequestTaskRemoval(0, task);
    for (index = 0; index < 3; index++) {
        for (rowIndex = 0; rowIndex < 4; rowIndex++) {
            DeleteObjTextCanvas(gEditKeyboard->mRowTexts[index][rowIndex]);
            if (index == 0) {
                DeleteOamRange(gEditKeyboard->mRowTextRanges[rowIndex]);
            }
        }
    }
    for (index = 0; index < 2; index++) {
        DeleteOamRange(gEditKeyboard->mRow4Keys[index]);
    }
    for (index = 0; index < 4; index++) {
        DeleteOamEntry(gEditKeyboard->mExtraKeys[index]);
    }
    for (index = 0; index < 0x2f; index++) {
        DeleteOamEntry(gEditKeyboard->mKeys[index]);
    }
    FreeExpHeapBlockAndClearPointer(&gEditKeyboard);
}
