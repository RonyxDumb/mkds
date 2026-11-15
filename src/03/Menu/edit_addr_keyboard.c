#include "03/Menu/edit_addr_keyboard.h"

#include "03/code_021d197c.h"
#include "03/System/exp_heap.h"
#include "03/code_021d2ecc.h"
#include "03/Menu/edit_keyboard.h"
#include "03/code_021c0000.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1790.h"
#include "03/code_021d1970.h"
#include "03/code_021d1c18.h"
#include "03/unk_021da000.h"
#include "03/System/task_input.h"
#include "03/unk_021d6000.h"
#include "03/Graphics/text_canvas.h"
#include "03/code_021c1000.h"
#include "03/System/rect.h"
#include "03/Graphics/nce_oam.h"
#include "03/System/tasks.h"
#include "03/code_021c04ec.h"

const u16 gEditAddrKeyboardDigitKeyPositions[10][2] = {{0x52, 0x4c}, {0x72, 0x4c}, {0x92, 0x4c}, {0x52, 0x63},
                                                       {0x72, 0x63}, {0x92, 0x63}, {0x52, 0x7a}, {0x72, 0x7a},
                                                       {0x92, 0x7a}, {0x52, 0x91}};
const u16 gEditAddrKeyboardKeyTexts[13] = {'7', '8', '9', '4', '5', '6', '1', '2', '3', '0', ' ', ' ', 0};
const u8 gEditAddrKeyboardRow4HighlightValues[2] = {4, 5};
EditKeyboardRowCounts gEditAddrKeyboardExtraKeyCounts = {{0, 0, 0, 2, 0}};
EditKeyboardRowCounts gEditAddrKeyboardDigitKeyCounts = {{3, 3, 3, 1, 0}};
u16 gEditAddrKeyboardTextRectStart[4] = {0, 1, 0, 0};
const u8 gEditAddrKeyboardRow4KeyImages[2] = {0x3c, 0x3d};
const u8 gEditAddrKeyboardExtraKeyImages[2] = {0x37, 0x38};
const u16 gEditAddrKeyboardCursorX[28] = {0x50, 0x4a, 0x70, 0x4a, 0x90, 0x4a, 0x50, 0x61, 0x70, 0x61,
                                          0x90, 0x61, 0x50, 0x78, 0x70, 0x78, 0x90, 0x78, 0x50, 0x8f,
                                          0x70, 0x8f, 0x90, 0x8f, 2,    0xa8, 0x82, 0xa8};
const u16 gEditAddrKeyboardExtraKeyPositions[2][2] = {{0x72, 0x91}, {0x92, 0x91}};
const u16 gEditAddrKeyboardExtraKeySize[2] = {0x1c, 0x14};
const s8 gEditAddrKeyboardCursorMoves[56] = {
    2, 0xc, 1, 3, 0, 0xd, 2,   4, 1,   0xd, 0, 5, 5,   0,   4,   6, 3, 1,   5,   7, 4,   2, 3,   8,  8,   3, 7, 9, 6, 4,
    8, 0xa, 7, 5, 6, 0xb, 0xb, 6, 0xa, 0xc, 9, 7, 0xb, 0xd, 0xa, 8, 9, 0xd, 0xd, 9, 0xd, 0, 0xc, -1, 0xc, -2};
const u8 gEditAddrKeyboardDigitInputs[10] = {0x37, 0x38, 0x39, 0x34, 0x35, 0x36, 0x31, 0x32, 0x33, 0x30};
const u8 gEditAddrKeyboardExtraKeyInputs[2] = {EDIT_ADDR_KEYBOARD_INPUT_REMOVE_CHAR,
                                               EDIT_ADDR_KEYBOARD_INPUT_NEXT_GROUP};
const u16 gEditAddrKeyboardRow4KeyPositions[2][2] = {{4, 0xaa}, {0x84, 0xaa}};
const u8 gEditAddrKeyboardRow4KeyInputs[2] = {EDIT_ADDR_KEYBOARD_INPUT_CANCEL, EDIT_ADDR_KEYBOARD_INPUT_OK};
const u16 gEditAddrKeyboardRowTextAreaSize[2] = {0xc, 4};
const u8 gEditAddrKeyboardKeyPalettes[2] = {2, 3};
const u16 gEditAddrKeyboardRow4KeySize[2] = {0x78, 0x12};
const u16 gEditAddrKeyboardDigitKeySize[2] = {0x1c, 0x14};
EditKeyboardRowCounts gEditAddrKeyboardRow4KeyCounts = {{0, 0, 0, 0, 2}};
struct EditAddrKeyboard *gEditAddrKeyboard;

void CreateEditAddrKeyboard(void) {
    EditAddrKeyboardTextArgs textArgs;
    EditAddrKeyboard *keyboard;
    int keyIndex;
    int textIndex;
    int column;
    textArgs.mTextRect[0] = gEditAddrKeyboardTextRectStart[0];
    textArgs.mTextRect[1] = gEditAddrKeyboardTextRectStart[1];
    textArgs.mTextRect[2] = gEditAddrKeyboardTextRectStart[2];
    textArgs.mTextRect[3] = gEditAddrKeyboardTextRectStart[3];
    textArgs.mTextRect[2] = gEditAddrKeyboardDigitKeySize[0];
    textArgs.mTextRect[3] = gEditAddrKeyboardDigitKeySize[1];
    keyboard = AllocZeroedExpHeapBlock(0x6c, 4);
    gEditAddrKeyboard = keyboard;
    keyboard->mInput = EDIT_ADDR_KEYBOARD_INPUT_NOT_READY;
    gEditAddrKeyboard->mCursorKeyIndex = 0;
    gEditAddrKeyboard->mRemoveCharEnabled = 1;
    gEditAddrKeyboard->mAddCharEnabled = 1;
    gEditAddrKeyboard->mNextGroupEnabled = 1;
    for (keyIndex = 0; keyIndex < 10; keyIndex++) {
        gEditAddrKeyboard->mDigitKeys[keyIndex] = CreateOamEntryFromNceImage(0, 0x36);
        gEditAddrKeyboard->mDigitKeys[keyIndex]->mAttr01 =
            (gEditAddrKeyboard->mDigitKeys[keyIndex]->mAttr01 & OAM_ATTR01_NOT_EFFECT_MASK) | OAM_ATTR01_EFFECT_HIDDEN;
        gEditAddrKeyboard->mDigitKeys[keyIndex]->mAttr2 =
            (gEditAddrKeyboard->mDigitKeys[keyIndex]->mAttr2 & OAM_ATTR2_NOT_PRIORITY_MASK) | 0xc00;
    }
    for (keyIndex = 0; keyIndex < 2; keyIndex++) {
        gEditAddrKeyboard->mExtraKeys[keyIndex] =
            CreateOamEntryFromNceImage(0, gEditAddrKeyboardExtraKeyImages[keyIndex]);
        gEditAddrKeyboard->mExtraKeys[keyIndex]->mAttr01 =
            (gEditAddrKeyboard->mExtraKeys[keyIndex]->mAttr01 & OAM_ATTR01_NOT_EFFECT_MASK) | OAM_ATTR01_EFFECT_HIDDEN;
        gEditAddrKeyboard->mExtraKeys[keyIndex]->mAttr2 =
            (gEditAddrKeyboard->mExtraKeys[keyIndex]->mAttr2 & OAM_ATTR2_NOT_PRIORITY_MASK) | 0xc00;
    }
    for (keyIndex = 0; keyIndex < 2; keyIndex++) {
        gEditAddrKeyboard->mRow4Keys[keyIndex] =
            CreateOamRangeFromNceImage(0, gEditAddrKeyboardRow4KeyImages[keyIndex], 1);
        SetOamRangeEffect(gEditAddrKeyboard->mRow4Keys[keyIndex], -1, 0x200, 0);
        SetOamRangePriority(gEditAddrKeyboard->mRow4Keys[keyIndex], -1, 3);
    }
    textArgs.mText[1] = 0;
    for (keyIndex = 0; keyIndex < 4; keyIndex++) {
        gEditAddrKeyboard->mRowTexts[keyIndex] = CreateObjTextCanvas(
            0, gEditAddrKeyboardRowTextAreaSize[0], gEditAddrKeyboardRowTextAreaSize[1], 0, &textArgs.mEntryCount, 0);
        textIndex = keyIndex * 3;
        for (column = 0, textArgs.mTextRect[0] = 0; column < 3; column++, textIndex++, textArgs.mTextRect[0] += 0x20) {
            textArgs.mText[0] = gEditAddrKeyboardKeyTexts[textIndex];
            DrawCanvasTextRect(gEditAddrKeyboard->mRowTexts[keyIndex], textArgs.mTextRect[0], textArgs.mTextRect[1],
                               textArgs.mTextRect[2], textArgs.mTextRect[3], 2, 0x480, textArgs.mText);
        }
        gEditAddrKeyboard->mRowTextRanges[keyIndex] = CreateOamRange(0, textArgs.mEntryCount, 0);
    }
    gEditAddrKeyboard->mCursor = CreateOamRangeFromNceImage(0, 0x44, 1);
    SetOamRangeEffect(gEditAddrKeyboard->mCursor, -1, 0x200, 0);
    SetOamRangePriority(gEditAddrKeyboard->mCursor, -1, 2);
    gEditAddrKeyboard->mStepTask = AddTask(0, AdvanceEditAddrKeyboardSlideInRow0, NULL, 0x78);
    SetEditAddrKeyboardRowY(0, 0xc0);
}

void StartEditAddrKeyboardSlideOut(void) {
    DeleteOamRange(gEditAddrKeyboard->mCursor);
    SetTaskCallback(gEditAddrKeyboard->mStepTask, AdvanceEditAddrKeyboardSlideOutRow4);
}

u8 GetEditAddrKeyboardInput(void) {
    return gEditAddrKeyboard->mInput;
}

void SetEditAddrKeyboardRemoveCharEnabled(u8 canRemove) {
    gEditAddrKeyboard->mRemoveCharEnabled = canRemove;
}

void SetEditAddrKeyboardAddCharEnabled(u8 canAdd) {
    gEditAddrKeyboard->mAddCharEnabled = canAdd;
}

void SetEditAddrKeyboardNextGroupEnabled(u8 canNextGroup) {
    gEditAddrKeyboard->mNextGroupEnabled = canNextGroup;
}

BOOL HasEditAddrKeyboard(void) {
    if (gEditAddrKeyboard != NULL) {
        return 1;
    }
    return 0;
}

static inline void EditAddrInG2_GetOBJPosition(OamEntry *oam, u32 *x, u32 *y) {
    *x = (oam->mAttr01 & OAM_ATTR01_X_MASK) >> 16;
    *y = oam->mAttr01 & OAM_ATTR01_Y_MASK;
}

void AdvanceEditAddrKeyboardSlideInRow0(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditAddrInG2_GetOBJPosition(gEditAddrKeyboard->mDigitKeys[0], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos - 0xc;
    if (yPos > gEditAddrKeyboardDigitKeyPositions[0][1]) {
        SetEditAddrKeyboardRowY(0, yPos);
        return;
    }
    SetEditAddrKeyboardRowY(0, gEditAddrKeyboardDigitKeyPositions[0][1]);
    SetEditAddrKeyboardRowY(1, 0xc0);
    SetTaskCallback(task, AdvanceEditAddrKeyboardSlideInRow1);
}

void AdvanceEditAddrKeyboardSlideInRow1(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditAddrInG2_GetOBJPosition(gEditAddrKeyboard->mDigitKeys[3], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos - 0xc;
    if (yPos > gEditAddrKeyboardDigitKeyPositions[3][1]) {
        SetEditAddrKeyboardRowY(1, yPos);
        return;
    }
    SetEditAddrKeyboardRowY(1, gEditAddrKeyboardDigitKeyPositions[3][1]);
    SetEditAddrKeyboardRowY(2, 0xc0);
    SetTaskCallback(task, AdvanceEditAddrKeyboardSlideInRow2);
}

void AdvanceEditAddrKeyboardSlideInRow2(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditAddrInG2_GetOBJPosition(gEditAddrKeyboard->mDigitKeys[6], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos - 0xc;
    if (yPos > gEditAddrKeyboardDigitKeyPositions[6][1]) {
        SetEditAddrKeyboardRowY(2, yPos);
        return;
    }
    SetEditAddrKeyboardRowY(2, gEditAddrKeyboardDigitKeyPositions[6][1]);
    SetEditAddrKeyboardRowY(3, 0xc0);
    SetTaskCallback(task, AdvanceEditAddrKeyboardSlideInRow3);
}

void AdvanceEditAddrKeyboardSlideInRow3(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditAddrInG2_GetOBJPosition(gEditAddrKeyboard->mDigitKeys[9], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos - 0xc;
    if (yPos > gEditAddrKeyboardDigitKeyPositions[9][1]) {
        SetEditAddrKeyboardRowY(3, yPos);
        return;
    }
    SetEditAddrKeyboardRowY(3, gEditAddrKeyboardDigitKeyPositions[9][1]);
    SetEditAddrKeyboardRowY(4, 0xc0);
    SetTaskCallback(task, AdvanceEditAddrKeyboardSlideInRow4);
}

void AdvanceEditAddrKeyboardSlideInRow4(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gEditAddrKeyboard->mRow4Keys[0], 0, &xPos, &yPos);
    yPos = yPos - 0xc;
    if (yPos > gEditAddrKeyboardRow4KeyPositions[0][1]) {
        SetEditAddrKeyboardRowY(4, yPos);
        return;
    }
    SetEditAddrKeyboardRowY(4, gEditAddrKeyboardRow4KeyPositions[0][1]);
    PlaceEditAddrKeyboardCursor();
    SetTaskCallback(task, AdvanceEditAddrKeyboardInput);
}

void AdvanceEditAddrKeyboardInput(TaskEntry *task, void *arg) {
    AdvanceEditAddrKeyboardTouchPressed();
    AdvanceEditAddrKeyboardTouchReleased();
    AdvanceEditAddrKeyboardTouchDown();
    AdvanceEditAddrKeyboardKeys();
}

void AdvanceEditAddrKeyboardTouchPressed(void) {
    Rect keyRect;
    const u16 *extraKeyOrigin;
    int secondaryKeyIndex;
    int keyIndex;
    const u16 *keyOrigin;
    if (IsTouchPressedInRect(&gTouchScreenRect) == 0) {
        return;
    }
    gEditAddrKeyboard->mPressedKeyIndex = -1;
    for (keyIndex = 0, keyOrigin = gEditAddrKeyboardDigitKeyPositions[0]; keyIndex < 10; keyOrigin += 2, keyIndex++) {
        ComputeRectFromOriginAndSize(keyOrigin, gEditAddrKeyboardDigitKeySize, &keyRect);
        if (IsTouchPressedInRect(&keyRect) != 0) {
            if (gEditAddrKeyboard->mAddCharEnabled == 0) {
                StartSoundSeq(9);
                return;
            }
            StartSoundSeq(0);
            gEditAddrKeyboard->mPressedKeyIndex = keyIndex;
            return;
        }
    }
    for (secondaryKeyIndex = 0, extraKeyOrigin = gEditAddrKeyboardExtraKeyPositions[0]; secondaryKeyIndex < 2;
         extraKeyOrigin += 2, secondaryKeyIndex++) {
        ComputeRectFromOriginAndSize(extraKeyOrigin, gEditAddrKeyboardExtraKeySize, &keyRect);
        if (IsTouchPressedInRect(&keyRect) != 0) {
            if ((secondaryKeyIndex == 0 && gEditAddrKeyboard->mRemoveCharEnabled == 0) ||
                (secondaryKeyIndex == 1 && gEditAddrKeyboard->mNextGroupEnabled == 0)) {
                StartSoundSeq(9);
                return;
            }
            StartSoundSeq(0);
            gEditAddrKeyboard->mPressedKeyIndex = secondaryKeyIndex + 10;
            return;
        }
    }
    for (secondaryKeyIndex = 0, keyOrigin = gEditAddrKeyboardRow4KeyPositions[0]; secondaryKeyIndex < 2;
         keyOrigin += 2, secondaryKeyIndex++) {
        ComputeRectFromOriginAndSize(keyOrigin, gEditAddrKeyboardRow4KeySize, &keyRect);
        if (IsTouchPressedInRect(&keyRect) != 0) {
            StartSoundSeq(0);
            gEditAddrKeyboard->mPressedKeyIndex = secondaryKeyIndex + 12;
            return;
        }
    }
}

void AdvanceEditAddrKeyboardTouchReleased(void) {
    Rect keyRect;
    const u16 *extraKeyOrigin;
    int secondaryKeyIndex;
    int keyIndex;
    const u16 *keyOrigin;
    gEditAddrKeyboard->mInput = EDIT_ADDR_KEYBOARD_INPUT_NONE;
    if (IsTouchReleasedInRect(&gTouchScreenRect) == 0) {
        return;
    }
    for (keyIndex = 0, keyOrigin = gEditAddrKeyboardDigitKeyPositions[0]; keyIndex < 10; keyOrigin += 2, keyIndex++) {
        ComputeRectFromOriginAndSize(keyOrigin, gEditAddrKeyboardDigitKeySize, &keyRect);
        if (IsTouchReleasedInRect(&keyRect) != 0) {
            if (gEditAddrKeyboard->mPressedKeyIndex != keyIndex) {
                return;
            }
            gEditAddrKeyboard->mInput = gEditAddrKeyboardDigitInputs[keyIndex];
            gEditAddrKeyboard->mCursorKeyIndex = keyIndex;
            PlaceEditAddrKeyboardCursor();
            return;
        }
    }
    for (secondaryKeyIndex = 0, extraKeyOrigin = gEditAddrKeyboardExtraKeyPositions[0]; secondaryKeyIndex < 2;
         extraKeyOrigin += 2, secondaryKeyIndex++) {
        ComputeRectFromOriginAndSize(extraKeyOrigin, gEditAddrKeyboardExtraKeySize, &keyRect);
        if (IsTouchReleasedInRect(&keyRect) != 0) {
            if (gEditAddrKeyboard->mPressedKeyIndex != secondaryKeyIndex + 10) {
                return;
            }
            gEditAddrKeyboard->mInput = gEditAddrKeyboardExtraKeyInputs[secondaryKeyIndex];
            gEditAddrKeyboard->mCursorKeyIndex = secondaryKeyIndex + 10;
            PlaceEditAddrKeyboardCursor();
            return;
        }
    }
    for (secondaryKeyIndex = 0, keyOrigin = gEditAddrKeyboardRow4KeyPositions[0]; secondaryKeyIndex < 2;
         keyOrigin += 2, secondaryKeyIndex++) {
        ComputeRectFromOriginAndSize(keyOrigin, gEditAddrKeyboardRow4KeySize, &keyRect);
        if (IsTouchReleasedInRect(&keyRect) != 0) {
            if (gEditAddrKeyboard->mPressedKeyIndex != secondaryKeyIndex + 12) {
                return;
            }
            gEditAddrKeyboard->mInput = gEditAddrKeyboardRow4KeyInputs[secondaryKeyIndex];
            gEditAddrKeyboard->mCursorKeyIndex = secondaryKeyIndex + 12;
            PlaceEditAddrKeyboardCursor();
            return;
        }
    }
}

void AdvanceEditAddrKeyboardTouchDown(void) {
    Rect keyRect;
    const u16 *extraKeyOrigin;
    int secondaryKeyIndex;
    int keyIndex;
    const u16 *keyOrigin;
    if (IsTouchDownInRect(&gTouchScreenRect) == 0) {
        goto label_1;
    }
    for (keyIndex = 0, keyOrigin = gEditAddrKeyboardDigitKeyPositions[0]; keyIndex < 10; keyOrigin += 2, keyIndex++) {
        ComputeRectFromOriginAndSize(keyOrigin, gEditAddrKeyboardDigitKeySize, &keyRect);
        if (IsTouchDownInRect(&keyRect) != 0) {
            if (gEditAddrKeyboard->mPressedKeyIndex != keyIndex) {
                goto label_1;
            }
            ChangeEditAddrKeyboardHighlight(keyIndex);
            goto label_2;
        }
    }
    for (secondaryKeyIndex = 0, extraKeyOrigin = gEditAddrKeyboardExtraKeyPositions[0]; secondaryKeyIndex < 2;
         extraKeyOrigin += 2, secondaryKeyIndex++) {
        ComputeRectFromOriginAndSize(extraKeyOrigin, gEditAddrKeyboardExtraKeySize, &keyRect);
        if (IsTouchDownInRect(&keyRect) != 0) {
            if (gEditAddrKeyboard->mPressedKeyIndex != secondaryKeyIndex + 10) {
                goto label_1;
            }
            ChangeEditAddrKeyboardHighlight(secondaryKeyIndex + 10);
            if (secondaryKeyIndex != 0) {
                goto label_2;
            }
            gEditAddrKeyboard->mRepeatCalls = gEditAddrKeyboard->mRepeatCalls + 1;
            if (gEditAddrKeyboard->mRepeatCalls >= 0x28) {
                if (gEditAddrKeyboard->mRemoveCharEnabled == 0) {
                    StartSoundSeq(9);
                    gEditAddrKeyboard->mPressedKeyIndex = -1;
                    return;
                }
                gEditAddrKeyboard->mInput = EDIT_ADDR_KEYBOARD_INPUT_REMOVE_CHAR;
                gEditAddrKeyboard->mRepeatCalls = gEditAddrKeyboard->mRepeatCalls - 7;
                return;
            }
            return;
        }
    }
    for (secondaryKeyIndex = 0, keyOrigin = gEditAddrKeyboardRow4KeyPositions[0]; secondaryKeyIndex < 2;
         keyOrigin += 2, secondaryKeyIndex++) {
        ComputeRectFromOriginAndSize(keyOrigin, gEditAddrKeyboardRow4KeySize, &keyRect);
        if (IsTouchDownInRect(&keyRect) != 0) {
            secondaryKeyIndex += 12;
            if (gEditAddrKeyboard->mPressedKeyIndex != secondaryKeyIndex) {
                goto label_1;
            }
            ChangeEditAddrKeyboardHighlight(secondaryKeyIndex);
            goto label_2;
        }
    }
label_1:
    ChangeEditAddrKeyboardHighlight(-1);
label_2:
    gEditAddrKeyboard->mRepeatCalls = 0;
}

void ChangeEditAddrKeyboardHighlight(int keyIndex) {
    if (keyIndex != gEditAddrKeyboard->mHighlightedKeyIndex) {
        SetEditAddrKeyboardKeyHighlight(keyIndex, 1);
        SetEditAddrKeyboardKeyHighlight(gEditAddrKeyboard->mHighlightedKeyIndex, 0);
        gEditAddrKeyboard->mHighlightedKeyIndex = keyIndex;
    }
}

static inline void EditAddrOutG2_GetOBJPosition(OamEntry *oam, u32 *x, u32 *y) {
    *x = (oam->mAttr01 & OAM_ATTR01_X_MASK) >> 16;
    *y = oam->mAttr01 & OAM_ATTR01_Y_MASK;
}

void AdvanceEditAddrKeyboardKeys(void) {
    int keyIndex;
    if (AreKeysPressedOrRepeated(0x20) != 0) {
        MoveEditAddrKeyboardCursor(0);
    }
    if (AreKeysPressedOrRepeated(0x40) != 0) {
        MoveEditAddrKeyboardCursor(1);
    }
    if (AreKeysPressedOrRepeated(0x10) != 0) {
        MoveEditAddrKeyboardCursor(2);
    }
    if (AreKeysPressedOrRepeated(0x80) != 0) {
        MoveEditAddrKeyboardCursor(3);
    }
    if (AreKeysPressed(1) != 0) {
        keyIndex = gEditAddrKeyboard->mCursorKeyIndex;
        if (keyIndex < 10) {
            if (gEditAddrKeyboard->mAddCharEnabled != 0) {
                gEditAddrKeyboard->mInput = gEditAddrKeyboardDigitInputs[keyIndex];
                return;
            }
            StartSoundSeq(9);
            return;
        }
        if (keyIndex - 10 < 2) {
            if ((keyIndex - 10 == 0 && gEditAddrKeyboard->mRemoveCharEnabled == 0) ||
                (keyIndex - 10 == 1 && gEditAddrKeyboard->mNextGroupEnabled == 0)) {
                StartSoundSeq(9);
                return;
            }
            gEditAddrKeyboard->mInput = gEditAddrKeyboardExtraKeyInputs[keyIndex - 10];
            return;
        }
        gEditAddrKeyboard->mInput = gEditAddrKeyboardRow4KeyInputs[keyIndex - 12];
    }
    if (AreKeysPressedOrRepeated(2) != 0) {
        if (gEditAddrKeyboard->mRemoveCharEnabled == 0) {
            if (gEditAddrKeyboard->mRemoveDisabledSoundPlayed == 0) {
                StartSoundSeq(9);
                gEditAddrKeyboard->mRemoveDisabledSoundPlayed = 1;
            }
        } else {
            gEditAddrKeyboard->mInput = EDIT_ADDR_KEYBOARD_INPUT_REMOVE_CHAR;
        }
    } else if (AreKeysReleased(2) != 0) {
        gEditAddrKeyboard->mRemoveDisabledSoundPlayed = 0;
    }
}

void SetEditAddrKeyboardRowY(int row, u32 yPos) {
    EditKeyboardRowCounts digitKeyCounts;
    EditKeyboardRowCounts extraKeyCounts;
    EditKeyboardRowCounts row4KeyCounts;
    BOOL effectAndAffineIndex;
    int rowKeyIndex;
    int keyIndex;
    OamEntry *key;
    digitKeyCounts = gEditAddrKeyboardDigitKeyCounts;
    extraKeyCounts = gEditAddrKeyboardExtraKeyCounts;
    row4KeyCounts = gEditAddrKeyboardRow4KeyCounts;
    keyIndex = row * 3;
    for (rowKeyIndex = 0; rowKeyIndex < digitKeyCounts.mCounts[(u32) row]; rowKeyIndex++, keyIndex++) {
        key = gEditAddrKeyboard->mDigitKeys[keyIndex];
        key->mAttr01 = key->mAttr01 & OAM_ATTR01_NOT_EFFECT_MASK;
        key = gEditAddrKeyboard->mDigitKeys[keyIndex];
        key->mAttr01 = ((gEditAddrKeyboardDigitKeyPositions[keyIndex][0] & 0x1ff) << 16) |
                       ((key->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) | (yPos & 0xff));
    }
    if (row < 4) {
        ArrangeObjTextCanvasRange(gEditAddrKeyboard->mRowTexts[row], gEditAddrKeyboardDigitKeyPositions[row * 3][0],
                                  yPos, gEditAddrKeyboard->mRowTextRanges[row], 2);
    }
    for (rowKeyIndex = 0; rowKeyIndex < extraKeyCounts.mCounts[(u32) row]; rowKeyIndex++) {
        key = gEditAddrKeyboard->mExtraKeys[rowKeyIndex];
        key->mAttr01 = key->mAttr01 & OAM_ATTR01_NOT_EFFECT_MASK;
        key = gEditAddrKeyboard->mExtraKeys[rowKeyIndex];
        key->mAttr01 = ((gEditAddrKeyboardExtraKeyPositions[rowKeyIndex][0] & 0x1ff) << 16) |
                       ((key->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) | (yPos & 0xff));
    }
    effectAndAffineIndex = FALSE;
    for (rowKeyIndex = 0; rowKeyIndex < row4KeyCounts.mCounts[(u32) row]; rowKeyIndex++) {
        SetOamRangeEffect(gEditAddrKeyboard->mRow4Keys[rowKeyIndex], -1, effectAndAffineIndex, effectAndAffineIndex);
        SetOamRangePosition(gEditAddrKeyboard->mRow4Keys[rowKeyIndex], -1,
                            gEditAddrKeyboardRow4KeyPositions[rowKeyIndex][0], yPos);
    }
}

void SetEditAddrKeyboardKeyHighlight(int keyIndex, int highlight) {
    OamEntry *key;
    int extraKeyIndex;
    if (keyIndex < 0) {
        return;
    }
    if (keyIndex < 10) {
        key = gEditAddrKeyboard->mDigitKeys[keyIndex];
        key->mAttr01 &= OAM_ATTR01_NOT_MODE_MASK;
        key->mAttr2 = (key->mAttr2 & OAM_ATTR2_NOT_PALETTE_MASK) | (gEditAddrKeyboardKeyPalettes[highlight] << 12);
        return;
    }
    extraKeyIndex = keyIndex - 10;
    if (extraKeyIndex < 2) {
        key = gEditAddrKeyboard->mExtraKeys[extraKeyIndex];
        key->mAttr01 &= OAM_ATTR01_NOT_MODE_MASK;
        key->mAttr2 = (key->mAttr2 & OAM_ATTR2_NOT_PALETTE_MASK) | (gEditAddrKeyboardKeyPalettes[highlight] << 12);
        return;
    }
    SetOamRangeMode(gEditAddrKeyboard->mRow4Keys[keyIndex - 12], -1, 0,
                    gEditAddrKeyboardRow4HighlightValues[highlight]);
}

void PlaceEditAddrKeyboardCursor(void) {
    int imageIndex;
    if (gEditAddrKeyboard->mCursorKeyIndex <= 11) {
        imageIndex = 0x44;
    } else {
        imageIndex = 0x45;
    }
    CopyNceImageToOamEntries(0, imageIndex, GetOamRangeEntry(gEditAddrKeyboard->mCursor, 0));
    SetOamRangePriority(gEditAddrKeyboard->mCursor, -1, 2);
    SetOamRangePosition(gEditAddrKeyboard->mCursor, -1,
                        gEditAddrKeyboardCursorX[gEditAddrKeyboard->mCursorKeyIndex * 2],
                        (gEditAddrKeyboardCursorX + 1)[gEditAddrKeyboard->mCursorKeyIndex * 2]);
}

void MoveEditAddrKeyboardCursor(u32 direction) {
    s8 previousKeyIndex;
    s8 nextKeyIndex;
    previousKeyIndex = gEditAddrKeyboard->mCursorKeyIndex;
    gEditAddrKeyboard->mCursorKeyIndex = (gEditAddrKeyboardCursorMoves + previousKeyIndex * 4)[direction];
    nextKeyIndex = gEditAddrKeyboard->mCursorKeyIndex;
    if (nextKeyIndex == 0xd && (direction == 1 || direction == 3)) {
        gEditAddrKeyboard->mPreviousKeyIndex = previousKeyIndex;
    } else if (nextKeyIndex == -1) {
        if (gEditAddrKeyboard->mPreviousKeyIndex == 1 || gEditAddrKeyboard->mPreviousKeyIndex == 10) {
            gEditAddrKeyboard->mCursorKeyIndex = 10;
        } else {
            gEditAddrKeyboard->mCursorKeyIndex = 11;
        }
    } else if (nextKeyIndex == -2) {
        if (gEditAddrKeyboard->mPreviousKeyIndex == 1 || gEditAddrKeyboard->mPreviousKeyIndex == 10) {
            gEditAddrKeyboard->mCursorKeyIndex = 1;
        } else {
            gEditAddrKeyboard->mCursorKeyIndex = 2;
        }
    }
    PlaceEditAddrKeyboardCursor();
    StartSoundSeq(8);
}

void AdvanceEditAddrKeyboardSlideOutRow4(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditAddrOutG2_GetOBJPosition(GetOamRangeEntry(gEditAddrKeyboard->mRow4Keys[0], 0), (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos + 0xc;
    SetEditAddrKeyboardRowY(4, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, AdvanceEditAddrKeyboardSlideOutRow3);
    }
}

void AdvanceEditAddrKeyboardSlideOutRow3(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditAddrOutG2_GetOBJPosition(gEditAddrKeyboard->mDigitKeys[9], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos + 0xc;
    SetEditAddrKeyboardRowY(3, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, AdvanceEditAddrKeyboardSlideOutRow2);
    }
}

void AdvanceEditAddrKeyboardSlideOutRow2(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditAddrOutG2_GetOBJPosition(gEditAddrKeyboard->mDigitKeys[6], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos + 0xc;
    SetEditAddrKeyboardRowY(2, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, AdvanceEditAddrKeyboardSlideOutRow1);
    }
}

void AdvanceEditAddrKeyboardSlideOutRow1(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditAddrOutG2_GetOBJPosition(gEditAddrKeyboard->mDigitKeys[3], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos + 0xc;
    SetEditAddrKeyboardRowY(1, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, AdvanceEditAddrKeyboardSlideOutRow0);
    }
}

void AdvanceEditAddrKeyboardSlideOutRow0(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditAddrOutG2_GetOBJPosition(gEditAddrKeyboard->mDigitKeys[0], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos + 0xc;
    SetEditAddrKeyboardRowY(0, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, ReleaseEditAddrKeyboard);
    }
}

void ReleaseEditAddrKeyboard(TaskEntry *task, void *arg) {
    int index;
    RequestTaskRemoval(0, task);
    index = 0;
    do {
        DeleteOamRange(gEditAddrKeyboard->mRowTextRanges[index]);
        DeleteObjTextCanvas(gEditAddrKeyboard->mRowTexts[index]);
        index = index + 1;
    } while (index < 4);
    index = 0;
    do {
        DeleteOamRange(gEditAddrKeyboard->mRow4Keys[index]);
        index = index + 1;
    } while (index < 2);
    index = 0;
    do {
        DeleteOamEntry(gEditAddrKeyboard->mExtraKeys[index]);
        index = index + 1;
    } while (index < 2);
    index = 0;
    do {
        DeleteOamEntry(gEditAddrKeyboard->mDigitKeys[index]);
        index = index + 1;
    } while (index < 10);
    FreeExpHeapBlockAndClearPointer(&gEditAddrKeyboard);
}
