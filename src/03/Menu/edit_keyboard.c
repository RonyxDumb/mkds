#include "03/Menu/edit_keyboard.h"
#include "03/code_021c04ec.h"
#include "03/code_021c0000.h"
#include "03/unk_021da000.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/System/task_input.h"
#include "03/System/rect.h"
#include "03/unk_021d5f00.h"
#include "03/unk_021d6000.h"
#include "03/Graphics/nce_oam.h"
#include "03/System/tasks.h"
#include "03/code_021bf000.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/Graphics/text_canvas.h"
#include "03/code_021d1000.h"
#include "03/System/exp_heap.h"
#include "03/code_021d1c18.h"
#include "03/unk_021d5000.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/edit_addr_keyboard.h"
#include "03/Graphics/hl_scr.h"
#include "03/System/application.h"
#include "code_02147cd8.h"
#include "03/code_021d1970.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d3000.h"
#include "code_02142eac.h"
#include "gx_load2d.h"
#include "03/unk_021d67d8.h"
#include "registers.h"

u16 gEditKeyboardPage0KeyTexts[50] = {
    0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2d, 0x3d, 0x71, 0x77, 0x65, 0x72, 0x74,
    0x79, 0x75, 0x69, 0x6f, 0x70, 0x5b, 0x5d, 0x61, 0x73, 0x64, 0x66, 0x67, 0x68, 0x6a, 0x6b, 0x6c, 0x3b,
    0x27, 0x60, 0x7a, 0x78, 0x63, 0x76, 0x62, 0x6e, 0x6d, 0x2c, 0x2e, 0x2f, 0x5c, 0x20, 0,    0,
};
u16 gEditKeyboardPage1KeyTexts[50] = {
    0x21, 0x40, 0x23, 0x24, 0x25, 0x5e, 0x26, 0x2a, 0x28, 0x29, 0x5f, 0x2b, 0x51, 0x57, 0x45, 0x52, 0x54,
    0x59, 0x55, 0x49, 0x4f, 0x50, 0x7b, 0x7d, 0x41, 0x53, 0x44, 0x46, 0x47, 0x48, 0x4a, 0x4b, 0x4c, 0x3a,
    0x22, 0x7e, 0x5a, 0x58, 0x43, 0x56, 0x42, 0x4e, 0x4d, 0x3c, 0x3e, 0x3f, 0x7c, 0x20, 0,    0,
};
u16 gEditKeyboardPage2KeyTexts[50] = {
    0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2d, 0x3d, 0x51, 0x57, 0x45, 0x52, 0x54,
    0x59, 0x55, 0x49, 0x4f, 0x50, 0x5b, 0x5d, 0x41, 0x53, 0x44, 0x46, 0x47, 0x48, 0x4a, 0x4b, 0x4c, 0x3b,
    0x27, 0x60, 0x5a, 0x58, 0x43, 0x56, 0x42, 0x4e, 0x4d, 0x2c, 0x2e, 0x2f, 0x5c, 0x20, 0,    0,
};
u8 gEditKeyboardPage2Inputs[0x30] = {
    0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2d, 0x3d, 0x51, 0x57, 0x45, 0x52,
    0x54, 0x59, 0x55, 0x49, 0x4f, 0x50, 0x5b, 0x5d, 0x41, 0x53, 0x44, 0x46, 0x47, 0x48, 0x4a, 0x4b,
    0x4c, 0x3b, 0x27, 0x60, 0x5a, 0x58, 0x43, 0x56, 0x42, 0x4e, 0x4d, 0x2c, 0x2e, 0x2f, 0x5c, 0,
};
u8 gEditKeyboardPage0Inputs[0x30] = {
    0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2d, 0x3d, 0x71, 0x77, 0x65, 0x72,
    0x74, 0x79, 0x75, 0x69, 0x6f, 0x70, 0x5b, 0x5d, 0x61, 0x73, 0x64, 0x66, 0x67, 0x68, 0x6a, 0x6b,
    0x6c, 0x3b, 0x27, 0x60, 0x7a, 0x78, 0x63, 0x76, 0x62, 0x6e, 0x6d, 0x2c, 0x2e, 0x2f, 0x5c, 0,
};
u8 gEditKeyboardPage1Inputs[0x30] = {
    0x21, 0x40, 0x23, 0x24, 0x25, 0x5e, 0x26, 0x2a, 0x28, 0x29, 0x5f, 0x2b, 0x51, 0x57, 0x45, 0x52,
    0x54, 0x59, 0x55, 0x49, 0x4f, 0x50, 0x7b, 0x7d, 0x41, 0x53, 0x44, 0x46, 0x47, 0x48, 0x4a, 0x4b,
    0x4c, 0x3a, 0x22, 0x7e, 0x5a, 0x58, 0x43, 0x56, 0x42, 0x4e, 0x4d, 0x3c, 0x3e, 0x3f, 0x7c, 0,
};
u32 gEditKeyboardExtraKeySoundSeqs[4] = {0, 0, 0, 2};
u8 *gEditKeyboardPageInputs[3] = {gEditKeyboardPage0Inputs, gEditKeyboardPage1Inputs, gEditKeyboardPage2Inputs};
u16 *gEditKeyboardPageKeyTexts[3] = {gEditKeyboardPage0KeyTexts, gEditKeyboardPage1KeyTexts,
                                     gEditKeyboardPage2KeyTexts};
u8 gEditKeyboardExtraKeyCounts[5] = {1, 1, 1, 1, 0};
u8 gEditKeyboardKeyCounts[5] = {0xc, 0xc, 0xc, 0xb, 0};
u8 gEditKeyboardRow4KeyCounts[5] = {0, 0, 0, 0, 2};

void CreateEditKeyboard(void) {
    u16 textRect[4] = {0};
    u32 entryCount;
    u16 text[2];
    EditKeyboard *keyboard;
    int i;
    int j;
    int k;
    int charIndex;

    textRect[2] = gEditKeyboardKeySize[0][0];
    textRect[3] = gEditKeyboardKeySize[0][1];
    keyboard = AllocZeroedExpHeapBlock(0x128, 4);
    gEditKeyboard = keyboard;
    keyboard->mInput = 0xff;
    gEditKeyboard->mCursorKeyIndex = 0;
    gEditKeyboard->mRemoveCharEnabled = 1;
    gEditKeyboard->mAddCharEnabled = 1;
    for (i = 0; i < 0x2f; i++) {
        gEditKeyboard->mKeys[i] = CreateOamEntryFromNceImage(0, 0x34);
        gEditKeyboard->mKeys[i]->mAttr01 = (gEditKeyboard->mKeys[i]->mAttr01 & 0xc1fffcff) | 0x200;
        gEditKeyboard->mKeys[i]->mAttr2 = (gEditKeyboard->mKeys[i]->mAttr2 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 4; i++) {
        gEditKeyboard->mExtraKeys[i] = CreateOamEntryFromNceImage(0, gEditKeyboardExtraKeyImages[i]);
        gEditKeyboard->mExtraKeys[i]->mAttr01 = (gEditKeyboard->mExtraKeys[i]->mAttr01 & 0xc1fffcff) | 0x200;
        gEditKeyboard->mExtraKeys[i]->mAttr2 = (gEditKeyboard->mExtraKeys[i]->mAttr2 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 2; i++) {
        gEditKeyboard->mRow4Keys[i] = CreateOamRangeFromNceImage(0, gEditKeyboardRow4KeyImages[i], 1);
        SetOamRangeEffect(gEditKeyboard->mRow4Keys[i], -1, 0x200, 0);
        SetOamRangePriority(gEditKeyboard->mRow4Keys[i], -1, 3);
    }
    text[1] = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            gEditKeyboard->mRowTexts[i][j] = CreateObjTextCanvas(0, gEditKeyboardRowTextAreaSize[0],
                                                                 gEditKeyboardRowTextAreaSize[1], 0, &entryCount, 0);
            charIndex = j * 12;
            for (k = 0, textRect[0] = 0; k < 12; k++, charIndex++, textRect[0] += 0x12) {
                text[0] = gEditKeyboardPageKeyTexts[i][charIndex];
                DrawCanvasTextRect(gEditKeyboard->mRowTexts[i][j], textRect[0], textRect[1], textRect[2], textRect[3],
                                   2, 0x480, text);
            }
            if (i == 0) {
                gEditKeyboard->mRowTextRanges[j] = CreateOamRange(0, entryCount, 1);
            }
        }
    }
    gEditKeyboard->mCursor = CreateOamRangeFromNceImage(0, 0x40, 1);
    SetOamRangeEffect(gEditKeyboard->mCursor, -1, 0x200, 0);
    SetOamRangePriority(gEditKeyboard->mCursor, -1, 2);
    gEditKeyboard->mStepTask = (TaskEntry *) AddTask(0, AdvanceEditKeyboardSlideInRow0, NULL, 0x78);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 0, 0xc0);
}

void StartEditKeyboardSlideOut(void) {
    DeleteOamRange(gEditKeyboard->mCursor);
    SetTaskCallback(gEditKeyboard->mStepTask, AdvanceEditKeyboardSlideOutRow4);
}

u8 GetEditKeyboardInput(void) {
    return gEditKeyboard->mInput;
}

void SetEditKeyboardRemoveCharEnabled(u8 canRemove) {
    gEditKeyboard->mRemoveCharEnabled = canRemove;
}

void SetEditKeyboardAddCharEnabled(u8 canAdd) {
    gEditKeyboard->mAddCharEnabled = canAdd;
}

BOOL HasEditKeyboard(void) {
    if (gEditKeyboard != NULL) {
        return 1;
    }
    return 0;
}

static inline void EditKeyboardInG2_GetOBJPosition(OamEntry *object, u32 *x, u32 *y) {
    *x = (object->mAttr01 & 0x1ff0000) >> 16;
    *y = object->mAttr01 & 0xff;
}

void AdvanceEditKeyboardSlideInRow0(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    EditKeyboardInG2_GetOBJPosition(gEditKeyboard->mKeys[0], (u32 *) &xPos, (u32 *) &yPos);
    yPos -= 12;
    if (yPos > gEditKeyboardKeyPositions[0][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 0, yPos);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 0, gEditKeyboardKeyPositions[0][1]);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 1, 0xc0);
    SetTaskCallback(task, AdvanceEditKeyboardSlideInRow1);
}

void AdvanceEditKeyboardSlideInRow1(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    EditKeyboardInG2_GetOBJPosition(gEditKeyboard->mKeys[12], (u32 *) &xPos, (u32 *) &yPos);
    yPos -= 12;
    if (yPos > gEditKeyboardKeyPositions[12][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 1, yPos);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 1, gEditKeyboardKeyPositions[12][1]);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 2, 0xc0);
    SetTaskCallback(task, AdvanceEditKeyboardSlideInRow2);
}

void AdvanceEditKeyboardSlideInRow2(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    EditKeyboardInG2_GetOBJPosition(gEditKeyboard->mKeys[24], (u32 *) &xPos, (u32 *) &yPos);
    yPos -= 12;
    if (yPos > gEditKeyboardKeyPositionsSecond[8][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 2, yPos);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 2, gEditKeyboardKeyPositionsSecond[8][1]);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 3, 0xc0);
    SetTaskCallback(task, AdvanceEditKeyboardSlideInRow3);
}

void AdvanceEditKeyboardSlideInRow3(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    EditKeyboardInG2_GetOBJPosition(gEditKeyboard->mKeys[36], (u32 *) &xPos, (u32 *) &yPos);
    yPos -= 12;
    if (yPos > gEditKeyboardKeyPositionsThird[4][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 3, yPos);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 3, gEditKeyboardKeyPositionsThird[4][1]);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 4, 0xc0);
    SetTaskCallback(task, AdvanceEditKeyboardSlideInRow4);
}

void AdvanceEditKeyboardSlideInRow4(TaskEntry *task) {
    u32 x;
    s32 yPos;
    GetOamRangeEntryPosition(gEditKeyboard->mRow4Keys[0], 0, &x, &yPos);
    yPos -= 12;
    if (yPos > gEditKeyboardRow4KeyPositions[0][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 4, yPos);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 4, gEditKeyboardRow4KeyPositions[0][1]);
    PlaceEditKeyboardCursor();
    SetTaskCallback(task, AdvanceEditKeyboardInput);
}

void AdvanceEditKeyboardInput(void) {
    AdvanceEditKeyboardTouchPressed();
    AdvanceEditKeyboardTouchReleased();
    AdvanceEditKeyboardTouchDown();
    UpdateEditKeyboardPad();
}

void AdvanceEditKeyboardTouchPressed(void) {
    Rect keyRect;
    s32 i;
    s32 j;
    if (IsTouchPressedInRect(&gTouchScreenRect) == 0) {
        return;
    }
    i = 0;
    gEditKeyboard->mPressedKeyIndex = -1;
    for (; i < 0x2f; i++) {
        ComputeRectFromOriginAndSize(gEditKeyboardKeyPositions[i], gEditKeyboardKeySize[0], &keyRect);
        if (IsTouchPressedInRect(&keyRect) != 0) {
            if (gEditKeyboard->mAddCharEnabled == 0) {
                StartSoundSeq(9);
                return;
            }
            StartSoundSeq(0);
            gEditKeyboard->mPressedKeyIndex = i;
            return;
        }
    }
    for (j = 0; j < 4; j++) {
        ComputeRectFromOriginAndSize(gEditKeyboardExtraKeyPositions[j], gEditKeyboardExtraKeySizes[j], &keyRect);
        if (IsTouchPressedInRect(&keyRect) != 0) {
            if ((j == 3 && gEditKeyboard->mRemoveCharEnabled == 0) || (j == 2 && gEditKeyboard->mAddCharEnabled == 0)) {
                StartSoundSeq(9);
                return;
            }
            StartSoundSeq(gEditKeyboardExtraKeySoundSeqs[j]);
            gEditKeyboard->mPressedKeyIndex = j + 0x2f;
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        ComputeRectFromOriginAndSize(gEditKeyboardRow4KeyPositions[i], gEditKeyboardRow4KeySize[0], &keyRect);
        if (IsTouchPressedInRect(&keyRect) != 0) {
            StartSoundSeq(0);
            gEditKeyboard->mPressedKeyIndex = i + 0x33;
            return;
        }
    }
}

void AdvanceEditKeyboardTouchReleased(void) {
    Rect keyRect;
    s32 i;
    u16(*extraKeySizes)[2];
    u16(*extraKeyOrigins)[2];
    s32 extraKeyIndex;
    gEditKeyboard->mInput = 0;
    if (IsTouchReleasedInRect(&gTouchScreenRect) == 0) {
        return;
    }
    for (i = 0; i < 0x2f; i++) {
        ComputeRectFromOriginAndSize(gEditKeyboardKeyPositions[i], gEditKeyboardKeySize[0], &keyRect);
        if (IsTouchReleasedInRect(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != i) {
                return;
            }
            gEditKeyboard->mInput = gEditKeyboardPageInputs[gEditKeyboard->mPage][i];
            if (gEditKeyboard->mPage == 1) {
                ChangeEditKeyboardPage(0);
            }
            gEditKeyboard->mCursorKeyIndex = i;
            PlaceEditKeyboardCursor();
            return;
        }
    }
    extraKeyIndex = 2;
    extraKeySizes = gEditKeyboardLastExtraKeySizes;
    extraKeyOrigins = gEditKeyboardLastExtraKeyPositions;
    for (; extraKeyIndex < 4; extraKeySizes++, extraKeyOrigins++, extraKeyIndex++) {
        ComputeRectFromOriginAndSize(*extraKeyOrigins, *extraKeySizes, &keyRect);
        if (IsTouchReleasedInRect(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != extraKeyIndex + 0x2f) {
                return;
            }
            gEditKeyboard->mInput = gEditKeyboardExtraKeyInputs[extraKeyIndex];
            if (gEditKeyboard->mPage == 1) {
                ChangeEditKeyboardPage(0);
            }
            gEditKeyboard->mCursorKeyIndex = extraKeyIndex + 0x2f;
            PlaceEditKeyboardCursor();
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        ComputeRectFromOriginAndSize(gEditKeyboardRow4KeyPositions[i], gEditKeyboardRow4KeySize[0], &keyRect);
        if (IsTouchReleasedInRect(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != i + 0x33) {
                return;
            }
            gEditKeyboard->mInput = gEditKeyboardRow4Inputs[i];
            gEditKeyboard->mCursorKeyIndex = i + 0x33;
            PlaceEditKeyboardCursor();
            return;
        }
    }
    ComputeRectFromOriginAndSize(gEditKeyboardExtraKeyPositions[0], gEditKeyboardExtraKeySizes[0], &keyRect);
    if (IsTouchReleasedInRect(&keyRect) != 0) {
        if (gEditKeyboard->mPressedKeyIndex != 0x2f) {
            return;
        }
        ToggleEditKeyboardPage2();
        gEditKeyboard->mCursorKeyIndex = 0x2f;
        PlaceEditKeyboardCursor();
        return;
    }
    ComputeRectFromOriginAndSize(gEditKeyboardPage1KeyPosition[0], gEditKeyboardPage1KeySize[0], &keyRect);
    if (IsTouchReleasedInRect(&keyRect) != 0) {
        if (gEditKeyboard->mPressedKeyIndex != 0x30) {
            return;
        }
        ToggleEditKeyboardPage1();
        gEditKeyboard->mCursorKeyIndex = 0x30;
        PlaceEditKeyboardCursor();
    }
}

void ToggleEditKeyboardPage2(void) {
    u32 page;
    if (gEditKeyboard->mPage == 2) {
        page = 0;
    } else {
        page = 2;
    }
    ChangeEditKeyboardPage(page);
    StartSoundSeq(1);
}

void ToggleEditKeyboardPage1(void) {
    ChangeEditKeyboardPage((gEditKeyboard->mPage != 1));
    StartSoundSeq(1);
}

void AdvanceEditKeyboardTouchDown(void) {
    Rect keyRect;
    s32 i;
    s32 extraKeyIndex;

    if (IsTouchDownInRect(&gTouchScreenRect) == 0) {
        goto fail;
    }
    for (i = 0; i < 0x2f; i++) {
        ComputeRectFromOriginAndSize(gEditKeyboardKeyPositions[i], gEditKeyboardKeySize[0], &keyRect);
        if (IsTouchDownInRect(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != i) {
                goto fail;
            }
            ChangeEditKeyboardHighlight(i);
            goto done;
        }
    }
    for (extraKeyIndex = 2; extraKeyIndex < 4; extraKeyIndex++) {
        ComputeRectFromOriginAndSize(gEditKeyboardExtraKeyPositions[extraKeyIndex],
                                     gEditKeyboardExtraKeySizes[extraKeyIndex], &keyRect);
        if (IsTouchDownInRect(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != extraKeyIndex + 0x2f) {
                goto fail;
            }
            ChangeEditKeyboardHighlight(extraKeyIndex + 0x2f);
            if (extraKeyIndex == 3) {
                gEditKeyboard->mRepeatCalls++;
                if (gEditKeyboard->mRepeatCalls >= 0x28) {
                    if (gEditKeyboard->mRemoveCharEnabled == 0) {
                        StartSoundSeq(9);
                        gEditKeyboard->mPressedKeyIndex = -1;
                        return;
                    }
                    gEditKeyboard->mInput = 0x80;
                    gEditKeyboard->mRepeatCalls -= 7;
                    return;
                }
            }
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        ComputeRectFromOriginAndSize(gEditKeyboardRow4KeyPositions[i], gEditKeyboardRow4KeySize[0], &keyRect);
        if (IsTouchDownInRect(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != i + 0x33) {
                goto fail;
            }
            ChangeEditKeyboardHighlight(i + 0x33);
            goto done;
        }
    }
fail:
    ChangeEditKeyboardHighlight(-1);
done:
    gEditKeyboard->mRepeatCalls = 0;
}

void ChangeEditKeyboardHighlight(int keyIndex) {
    if (keyIndex != gEditKeyboard->mHighlightedKeyIndex) {
        SetEditKeyboardKeyHighlight(keyIndex, 1);
        SetEditKeyboardKeyHighlight(gEditKeyboard->mHighlightedKeyIndex, 0);
        gEditKeyboard->mHighlightedKeyIndex = keyIndex;
    }
}

static inline void EditKeyboardOutG2_GetOBJPosition(OamEntry *object, u32 *x, u32 *y) {
    *x = (object->mAttr01 & 0x1ff0000) >> 16;
    *y = object->mAttr01 & 0xff;
}

void UpdateEditKeyboardPad(void) {
    s32 cursorKeyIndex;
    if (AreKeysPressedOrRepeated(0x20) != 0) {
        MoveEditKeyboardCursor(0);
    }
    if (AreKeysPressedOrRepeated(0x40) != 0) {
        MoveEditKeyboardCursor(1);
    }
    if (AreKeysPressedOrRepeated(0x10) != 0) {
        MoveEditKeyboardCursor(2);
    }
    if (AreKeysPressedOrRepeated(0x80) != 0) {
        MoveEditKeyboardCursor(3);
    }
    if (AreKeysPressed(1) != 0) {
        cursorKeyIndex = gEditKeyboard->mCursorKeyIndex;
        if (cursorKeyIndex < 0x2f) {
            if (gEditKeyboard->mAddCharEnabled == 0) {
                StartSoundSeq(9);
                return;
            }
            gEditKeyboard->mInput = gEditKeyboardPageInputs[gEditKeyboard->mPage][cursorKeyIndex];
            if (gEditKeyboard->mPage == 1) {
                ChangeEditKeyboardPage(0);
            }
            return;
        }
        if (cursorKeyIndex - 0x2f < 4) {
            switch (cursorKeyIndex - 0x2f) {
                case 0:
                    ToggleEditKeyboardPage2();
                    return;
                case 1:
                    ToggleEditKeyboardPage1();
                    return;
                case 2:
                    if (gEditKeyboard->mAddCharEnabled == 0) {
                        StartSoundSeq(9);
                        return;
                    }
                    break;
                case 3:
                    if (gEditKeyboard->mRemoveCharEnabled == 0) {
                        StartSoundSeq(9);
                        return;
                    }
                    break;
            }
            if (gEditKeyboard->mPage == 1) {
                ChangeEditKeyboardPage(0);
            }
            gEditKeyboard->mInput = gEditKeyboardExtraKeyInputs[cursorKeyIndex - 0x2f];
            return;
        }
        gEditKeyboard->mInput = gEditKeyboardRow4Inputs[cursorKeyIndex - 0x33];
    }
    if (AreKeysPressedOrRepeated(2) != 0) {
        if (gEditKeyboard->mRemoveCharEnabled == 0) {
            if (gEditKeyboard->mRemoveDisabledSoundPlayed != 0) {
                return;
            }
            StartSoundSeq(9);
            gEditKeyboard->mRemoveDisabledSoundPlayed = 1;
            return;
        }
        gEditKeyboard->mInput = 0x80;
    } else if (AreKeysReleased(2) != 0) {
        gEditKeyboard->mRemoveDisabledSoundPlayed = 0;
    }
    if (AreKeysPressed(0x400) != 0) {
        ToggleEditKeyboardPage2();
    }
    if (AreKeysPressed(0x800) != 0) {
        ToggleEditKeyboardPage1();
    }
}

void SetEditKeyboardRowY(u32 page, s32 row, u32 yPos) {
    u8 keyCounts[5];
    u8 extraKeyCounts[5];
    u8 row4KeyCounts[5];
    s32 i;
    s32 keyIndex;
    s32 extraKeyIndex;
    OamEntry *key;
    *(EditKeyboardRowCounts *) keyCounts = *(EditKeyboardRowCounts *) gEditKeyboardKeyCounts;
    *(EditKeyboardRowCounts *) extraKeyCounts = *(EditKeyboardRowCounts *) gEditKeyboardExtraKeyCounts;
    *(EditKeyboardRowCounts *) row4KeyCounts = *(EditKeyboardRowCounts *) gEditKeyboardRow4KeyCounts;
    keyIndex = row * 12;
    for (i = 0; i < keyCounts[(u32) row]; i++, keyIndex++) {
        key = gEditKeyboard->mKeys[keyIndex];
        key->mAttr01 = key->mAttr01 & 0xc1fffcff;
        key = gEditKeyboard->mKeys[keyIndex];
        key->mAttr01 =
            ((gEditKeyboardKeyPositions[keyIndex][0] & 0x1ff) << 16) | ((key->mAttr01 & 0xfe00ff00) | (yPos & 0xff));
    }
    if (row < 4) {
        ArrangeObjTextCanvasRange(gEditKeyboard->mRowTexts[page][row], gEditKeyboardKeyPositions[row * 12][0], yPos,
                                  gEditKeyboard->mRowTextRanges[row], 2);
    }
    extraKeyIndex = FX_ModS32(row + 3, 4);
    for (i = 0; i < extraKeyCounts[(u32) row]; i++) {
        key = gEditKeyboard->mExtraKeys[extraKeyIndex];
        key->mAttr01 = key->mAttr01 & 0xc1fffcff;
        key = gEditKeyboard->mExtraKeys[extraKeyIndex];
        key->mAttr01 = ((gEditKeyboardExtraKeyPositions[extraKeyIndex][0] & 0x1ff) << 16) |
                       ((key->mAttr01 & 0xfe00ff00) | (yPos & 0xff));
    }
    for (i = 0; i < row4KeyCounts[(u32) row]; i++) {
        SetOamRangeEffect(gEditKeyboard->mRow4Keys[i], -1, 0, 0);
        SetOamRangePosition(gEditKeyboard->mRow4Keys[i], -1, gEditKeyboardRow4KeyPositions[i][0], yPos);
    }
}

void ChangeEditKeyboardPage(int page) {
    BOOL page2Selected;
    BOOL page1Selected;
    s32 i;
    s32 firstKeyIndex;
    page2Selected = FALSE;
    page1Selected = FALSE;
    gEditKeyboard->mPage = page;
    i = 0;
    if (i < 4) {
        firstKeyIndex = 0;
        do {
            SetEditKeyboardRowY(page, i, gEditKeyboardKeyPositions[firstKeyIndex][1]);
            firstKeyIndex = (s32) (firstKeyIndex + 12);
            i++;
        } while (i < 4);
    }
    if (page == 2) {
        page2Selected = TRUE;
    } else if (page == 1) {
        page1Selected = TRUE;
    }
    SetEditKeyboardKeyHighlight(0x2f, page2Selected);
    SetEditKeyboardKeyHighlight(0x30, page1Selected);
}

void SetEditKeyboardKeyHighlight(int keyIndex, int highlight) {
    OamEntry *key;
    s32 extraKeyIndex;
    if (keyIndex < 0) {
        return;
    }
    if (keyIndex < 0x2f) {
        key = gEditKeyboard->mKeys[keyIndex];
        key->mAttr01 = key->mAttr01 & 0xfffff3ff;
        key->mAttr2 = (key->mAttr2 & 0xffff0fff) | (gEditKeyboardKeyPalettes[highlight] << 12);
        return;
    }
    extraKeyIndex = keyIndex - 0x2f;
    if (extraKeyIndex < 4) {
        key = gEditKeyboard->mExtraKeys[extraKeyIndex];
        key->mAttr01 = key->mAttr01 & 0xfffff3ff;
        key->mAttr2 = (key->mAttr2 & 0xffff0fff) | (gEditKeyboardKeyPalettes[highlight] << 12);
        return;
    }
    SetOamRangeMode(gEditKeyboard->mRow4Keys[keyIndex - 0x33], -1, 0, gEditKeyboardRow4HighlightValues[highlight]);
}

void PlaceEditKeyboardCursor(void) {
    u32 imageIndex;
    switch (gEditKeyboard->mCursorKeyIndex) {
        case 0x2f:
            imageIndex = 0x42;
            break;
        case 0x30:
            imageIndex = 0x41;
            break;
        case 0x31:
            imageIndex = 0x43;
            break;
        case 0x32:
            imageIndex = 0x41;
            break;
        case 0x33:
        case 0x34:
            imageIndex = 0x45;
            break;
        default:
            imageIndex = 0x40;
            break;
    }
    CopyNceImageToOamEntries(0, imageIndex, GetOamRangeEntry(gEditKeyboard->mCursor, 0));
    SetOamRangePriority(gEditKeyboard->mCursor, -1, 2);
    SetOamRangePosition(gEditKeyboard->mCursor, -1, gEditKeyboardCursorPositions[gEditKeyboard->mCursorKeyIndex][0],
                        gEditKeyboardCursorPositions[gEditKeyboard->mCursorKeyIndex][1]);
}

void MoveEditKeyboardCursor(int direction) {
    s8 previousKeyIndex;
    previousKeyIndex = gEditKeyboard->mCursorKeyIndex;
    gEditKeyboard->mCursorKeyIndex = gEditKeyboardCursorMoves[previousKeyIndex][direction];
    if (gEditKeyboard->mCursorKeyIndex == 0x2e && direction == 3) {
        gEditKeyboard->mPreviousKeyIndex = previousKeyIndex;
    } else if (gEditKeyboard->mCursorKeyIndex == 0x33 && (direction == 1 || direction == 3)) {
        gEditKeyboard->mPreviousKeyIndex = previousKeyIndex;
    } else if (gEditKeyboard->mCursorKeyIndex == 0x34 && (direction == 1 || direction == 3)) {
        if (previousKeyIndex != 0x2e) {
            gEditKeyboard->mPreviousKeyIndex = previousKeyIndex;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == -1) {
        if (gEditKeyboard->mPreviousKeyIndex == 0x23 || gEditKeyboard->mPreviousKeyIndex == 0x32) {
            gEditKeyboard->mCursorKeyIndex = 0x23;
        } else {
            gEditKeyboard->mCursorKeyIndex = 0x22;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == -2) {
        switch (gEditKeyboard->mPreviousKeyIndex) {
            case 0:
            case 0x31:
                gEditKeyboard->mCursorKeyIndex = 0x31;
                break;
            case 1:
            case 0x24:
                gEditKeyboard->mCursorKeyIndex = 0x24;
                break;
            case 3:
            case 0x26:
                gEditKeyboard->mCursorKeyIndex = 0x26;
                break;
            case 4:
            case 0x27:
                gEditKeyboard->mCursorKeyIndex = 0x27;
                break;
            case 5:
            case 0x28:
                gEditKeyboard->mCursorKeyIndex = 0x28;
                break;
            default:
                gEditKeyboard->mCursorKeyIndex = 0x25;
                break;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == -3) {
        switch (gEditKeyboard->mPreviousKeyIndex) {
            case 6:
            case 0x29:
                gEditKeyboard->mCursorKeyIndex = 0x29;
                break;
            case 7:
            case 0x2a:
                gEditKeyboard->mCursorKeyIndex = 0x2a;
                break;
            case 9:
            case 0x2c:
                gEditKeyboard->mCursorKeyIndex = 0x2c;
                break;
            case 10:
            case 0x2d:
                gEditKeyboard->mCursorKeyIndex = 0x2d;
                break;
            case 11:
            case 0x22:
            case 0x23:
            case 0x32:
                gEditKeyboard->mCursorKeyIndex = 0x2e;
                break;
            default:
                gEditKeyboard->mCursorKeyIndex = 0x2b;
                break;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == -4) {
        switch (gEditKeyboard->mPreviousKeyIndex) {
            case 0:
            case 0x31:
                gEditKeyboard->mCursorKeyIndex = 0;
                break;
            case 1:
            case 0x24:
                gEditKeyboard->mCursorKeyIndex = 1;
                break;
            case 3:
            case 0x26:
                gEditKeyboard->mCursorKeyIndex = 3;
                break;
            case 4:
            case 0x27:
                gEditKeyboard->mCursorKeyIndex = 4;
                break;
            case 5:
            case 0x28:
                gEditKeyboard->mCursorKeyIndex = 5;
                break;
            default:
                gEditKeyboard->mCursorKeyIndex = 2;
                break;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == -5) {
        switch (gEditKeyboard->mPreviousKeyIndex) {
            case 6:
            case 0x29:
                gEditKeyboard->mCursorKeyIndex = 6;
                break;
            case 7:
            case 0x2a:
                gEditKeyboard->mCursorKeyIndex = 7;
                break;
            case 9:
            case 0x2c:
                gEditKeyboard->mCursorKeyIndex = 9;
                break;
            case 10:
            case 0x2d:
                gEditKeyboard->mCursorKeyIndex = 10;
                break;
            case 11:
            case 0x22:
                gEditKeyboard->mCursorKeyIndex = 11;
                break;
            case 0x23:
            case 0x32:
                gEditKeyboard->mCursorKeyIndex = 0x32;
                break;
            default:
                gEditKeyboard->mCursorKeyIndex = 8;
                break;
        }
    }
    PlaceEditKeyboardCursor();
    StartSoundSeq(8);
}

void AdvanceEditKeyboardSlideOutRow4(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    EditKeyboardOutG2_GetOBJPosition(GetOamRangeEntry(gEditKeyboard->mRow4Keys[0], 0), (u32 *) &xPos, (u32 *) &yPos);
    yPos += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 4, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, AdvanceEditKeyboardSlideOutRow3);
    }
}

void AdvanceEditKeyboardSlideOutRow3(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    EditKeyboardOutG2_GetOBJPosition(gEditKeyboard->mKeys[36], (u32 *) &xPos, (u32 *) &yPos);
    yPos += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 3, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, AdvanceEditKeyboardSlideOutRow2);
    }
}

void AdvanceEditKeyboardSlideOutRow2(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    EditKeyboardOutG2_GetOBJPosition(gEditKeyboard->mKeys[24], (u32 *) &xPos, (u32 *) &yPos);
    yPos += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 2, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, AdvanceEditKeyboardSlideOutRow1);
    }
}

void AdvanceEditKeyboardSlideOutRow1(TaskEntry *task) {
    s32 x;
    s32 yPos;
    EditKeyboardOutG2_GetOBJPosition(gEditKeyboard->mKeys[12], (u32 *) &x, (u32 *) &yPos);
    yPos += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 1, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, AdvanceEditKeyboardSlideOutRow0);
    }
}

void AdvanceEditKeyboardSlideOutRow0(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    EditKeyboardOutG2_GetOBJPosition(gEditKeyboard->mKeys[0], (u32 *) &xPos, (u32 *) &yPos);
    yPos += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 0, yPos);
    if (yPos >= 0xc0) {
        SetTaskCallback(task, ReleaseEditKeyboard);
    }
}

void ReleaseEditKeyboard(u32 task) {
    s32 i;
    s32 j;
    RequestTaskRemoval(0, task);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            DeleteObjTextCanvas(gEditKeyboard->mRowTexts[i][j]);
            if (i == 0) {
                DeleteOamRange(gEditKeyboard->mRowTextRanges[j]);
            }
        }
    }
    for (i = 0; i < 2; i++) {
        DeleteOamRange(gEditKeyboard->mRow4Keys[i]);
    }
    for (i = 0; i < 4; i++) {
        DeleteOamEntry((u32 *) gEditKeyboard->mExtraKeys[i]);
    }
    for (i = 0; i < 0x2f; i++) {
        DeleteOamEntry((u32 *) gEditKeyboard->mKeys[i]);
    }
    FreeExpHeapBlockAndClearPointer(&gEditKeyboard);
}

void CreateLinkLevel(int row) {
    if (gLinkLevel == NULL) {
        gLinkLevel = AllocExpHeapBlock(0xc, 4);
        gLinkLevel->mImageRow = row;
        gLinkLevel->mOamEntry = CreateOamEntryFromNceImage(0, gLinkLevelImages[row][0]);
        gLinkLevel->mOamEntry->mAttr01 =
            ((gLinkLevelPosition[0] & 0x1ff) << 16) |
            ((gLinkLevel->mOamEntry->mAttr01 & 0xfe00ff00) | (gLinkLevelPosition[1] & 0xff));
        gLinkLevel->mOamEntry->mAttr2 = (gLinkLevel->mOamEntry->mAttr2 & 0xfffff3ff) | 0x800;
        gLinkLevel->mTask = AddTask(0, UpdateLinkLevel, NULL, 0x78);
    }
}

void ReleaseLinkLevel(void) {
    if (gLinkLevel != NULL) {
        RemoveTaskEntryWrapper(0, gLinkLevel->mTask);
        DeleteOamEntry((u32 *) gLinkLevel->mOamEntry);
        FreeExpHeapBlockAndClearPointer(&gLinkLevel);
    }
}

void UpdateLinkLevel(void) {
    u32 linkLevel;
    u16 savedIme;
    linkLevel = 0;
    savedIme = reg_OS_IME;
    reg_OS_IME = 0;
    if (WM_GetAllowedChannel() != 0x8000) {
        linkLevel = WM_GetLinkLevel();
    }
    reg_OS_IME;
    reg_OS_IME = savedIme;
    CopyNceImageToOamEntries(0, gLinkLevelImages[gLinkLevel->mImageRow][linkLevel], gLinkLevel->mOamEntry);
    gLinkLevel->mOamEntry->mAttr01 = ((gLinkLevelPosition[0] & 0x1ff) << 16) |
                                     ((gLinkLevel->mOamEntry->mAttr01 & 0xfe00ff00) | (gLinkLevelPosition[1] & 0xff));
    gLinkLevel->mOamEntry->mAttr2 = (gLinkLevel->mOamEntry->mAttr2 & 0xfffff3ff) | 0x800;
}
