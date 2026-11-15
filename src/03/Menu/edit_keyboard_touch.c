#include "03/Menu/edit_keyboard_touch.h"
#include "03/Menu/edit_keyboard.h"
#include "03/Menu/edit_keyboard_slide_out.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/edit_keyboard_row_counts.h"
#include "03/Menu/wifi_menu_tables.h"
#include "03/System/task_input.h"
#include "03/System/rect.h"
#include "code_0212df7c.h"
#include "03/Sound/sound_seq.h"

const u16 gEditKeyboardExtraKeySizes[1][2] = {{0x1b, 0x12}};
const u16 gEditKeyboardPage1KeySize[1][2] = {{0x20, 0x12}};
const u16 gEditKeyboardLastExtraKeySizes[2][2] = {{0x28, 0x12}, {0x20, 0x12}};
const u16 gEditKeyboardKeyPositions[16][2] = {
    {4, 0x51},    {0x16, 0x51}, {0x28, 0x51}, {0x3a, 0x51}, {0x4c, 0x51}, {0x5e, 0x51}, {0x70, 0x51}, {0x82, 0x51},
    {0x94, 0x51}, {0xa6, 0x51}, {0xb8, 0x51}, {0xca, 0x51}, {0x20, 0x67}, {0x32, 0x67}, {0x44, 0x67}, {0x56, 0x67}};
const u16 gEditKeyboardKeyPositionsSecond[16][2] = {
    {0x68, 0x67}, {0x7a, 0x67}, {0x8c, 0x67}, {0x9e, 0x67}, {0xb0, 0x67}, {0xc2, 0x67}, {0xd4, 0x67}, {0xe6, 0x67},
    {0x25, 0x7d}, {0x37, 0x7d}, {0x49, 0x7d}, {0x5b, 0x7d}, {0x6d, 0x7d}, {0x7f, 0x7d}, {0x91, 0x7d}, {0xa3, 0x7d}};

void AdvanceEditKeyboardInput(TaskEntry *task, void *arg) {
    AdvanceEditKeyboardTouchPressed();
    AdvanceEditKeyboardTouchReleased();
    AdvanceEditKeyboardTouchDown();
    UpdateEditKeyboardPad();
}

void AdvanceEditKeyboardTouchPressed(void) {
    Rect keyRect;
    s32 keyIndex;
    s32 extraKeyIndex;
    if (IsTouchPressedInRect(&gTouchScreenRect) == 0) {
        return;
    }
    keyIndex = 0;
    gEditKeyboard->mPressedKeyIndex = -1;
    for (; keyIndex < 0x2f; keyIndex++) {
        ComputeRectFromOriginAndSize(gEditKeyboardKeyPositions[keyIndex], gEditKeyboardKeySize[0], &keyRect);
        if (IsTouchPressedInRect(&keyRect) != 0) {
            if (gEditKeyboard->mAddCharEnabled == 0) {
                StartSoundSeq(9);
                return;
            }
            StartSoundSeq(0);
            gEditKeyboard->mPressedKeyIndex = keyIndex;
            return;
        }
    }
    for (extraKeyIndex = 0; extraKeyIndex < 4; extraKeyIndex++) {
        ComputeRectFromOriginAndSize(gEditKeyboardExtraKeyPositions[extraKeyIndex],
                                     gEditKeyboardExtraKeySizes[extraKeyIndex], &keyRect);
        if (IsTouchPressedInRect(&keyRect) != 0) {
            if ((extraKeyIndex == 3 && gEditKeyboard->mRemoveCharEnabled == 0) ||
                (extraKeyIndex == 2 && gEditKeyboard->mAddCharEnabled == 0)) {
                StartSoundSeq(9);
                return;
            }
            StartSoundSeq(gEditKeyboardExtraKeySoundSeqs[extraKeyIndex]);
            gEditKeyboard->mPressedKeyIndex = extraKeyIndex + 0x2f;
            return;
        }
    }
    for (keyIndex = 0; keyIndex < 2; keyIndex++) {
        ComputeRectFromOriginAndSize(gEditKeyboardRow4KeyPositions[keyIndex], gEditKeyboardRow4KeySize[0], &keyRect);
        if (IsTouchPressedInRect(&keyRect) != 0) {
            StartSoundSeq(0);
            gEditKeyboard->mPressedKeyIndex = keyIndex + 0x33;
            return;
        }
    }
}

void AdvanceEditKeyboardTouchReleased(void) {
    Rect keyRect;
    s32 keyIndex;
    const u16(*extraKeySizes)[2];
    const u16(*extraKeyOrigins)[2];
    s32 extraKeyIndex;
    gEditKeyboard->mInput = 0;
    if (IsTouchReleasedInRect(&gTouchScreenRect) == 0) {
        return;
    }
    for (keyIndex = 0; keyIndex < 0x2f; keyIndex++) {
        ComputeRectFromOriginAndSize(gEditKeyboardKeyPositions[keyIndex], gEditKeyboardKeySize[0], &keyRect);
        if (IsTouchReleasedInRect(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != keyIndex) {
                return;
            }
            gEditKeyboard->mInput = gEditKeyboardPageInputs[gEditKeyboard->mPage][keyIndex];
            if (gEditKeyboard->mPage == EDIT_KEYBOARD_PAGE1) {
                ChangeEditKeyboardPage(0);
            }
            gEditKeyboard->mCursorKeyIndex = keyIndex;
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
            if (gEditKeyboard->mPage == EDIT_KEYBOARD_PAGE1) {
                ChangeEditKeyboardPage(0);
            }
            gEditKeyboard->mCursorKeyIndex = extraKeyIndex + 0x2f;
            PlaceEditKeyboardCursor();
            return;
        }
    }
    for (keyIndex = 0; keyIndex < 2; keyIndex++) {
        ComputeRectFromOriginAndSize(gEditKeyboardRow4KeyPositions[keyIndex], gEditKeyboardRow4KeySize[0], &keyRect);
        if (IsTouchReleasedInRect(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != keyIndex + 0x33) {
                return;
            }
            gEditKeyboard->mInput = gEditKeyboardRow4Inputs[keyIndex];
            gEditKeyboard->mCursorKeyIndex = keyIndex + 0x33;
            PlaceEditKeyboardCursor();
            return;
        }
    }
    ComputeRectFromOriginAndSize(gEditKeyboardExtraKeyPositions[0], gEditKeyboardExtraKeySizes[0], &keyRect);
    if (IsTouchReleasedInRect(&keyRect) != 0) {
        if (gEditKeyboard->mPressedKeyIndex != EDIT_KEY_PAGE2_TOGGLE) {
            return;
        }
        ToggleEditKeyboardPage2();
        gEditKeyboard->mCursorKeyIndex = EDIT_KEY_PAGE2_TOGGLE;
        PlaceEditKeyboardCursor();
        return;
    }
    ComputeRectFromOriginAndSize(gEditKeyboardPage1KeyPosition[0], gEditKeyboardPage1KeySize[0], &keyRect);
    if (IsTouchReleasedInRect(&keyRect) != 0) {
        if (gEditKeyboard->mPressedKeyIndex != EDIT_KEY_PAGE1_TOGGLE) {
            return;
        }
        ToggleEditKeyboardPage1();
        gEditKeyboard->mCursorKeyIndex = EDIT_KEY_PAGE1_TOGGLE;
        PlaceEditKeyboardCursor();
    }
}

void ToggleEditKeyboardPage2(void) {
    u32 page;
    if (gEditKeyboard->mPage == EDIT_KEYBOARD_PAGE2) {
        page = EDIT_KEYBOARD_PAGE_MAIN;
    } else {
        page = EDIT_KEYBOARD_PAGE2;
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
    s32 keyIndex;
    s32 extraKeyIndex;

    if (IsTouchDownInRect(&gTouchScreenRect) == 0) {
        goto fail;
    }
    for (keyIndex = 0; keyIndex < 0x2f; keyIndex++) {
        ComputeRectFromOriginAndSize(gEditKeyboardKeyPositions[keyIndex], gEditKeyboardKeySize[0], &keyRect);
        if (IsTouchDownInRect(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != keyIndex) {
                goto fail;
            }
            ChangeEditKeyboardHighlight(keyIndex);
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
                if (gEditKeyboard->mRepeatCalls >= EDIT_KEYBOARD_REPEAT_DELAY_CALLS) {
                    if (gEditKeyboard->mRemoveCharEnabled == 0) {
                        StartSoundSeq(9);
                        gEditKeyboard->mPressedKeyIndex = -1;
                        return;
                    }
                    gEditKeyboard->mInput = EDIT_KEYBOARD_INPUT_REMOVE_CHAR;
                    gEditKeyboard->mRepeatCalls -= 7;
                    return;
                }
            }
            return;
        }
    }
    for (keyIndex = 0; keyIndex < 2; keyIndex++) {
        ComputeRectFromOriginAndSize(gEditKeyboardRow4KeyPositions[keyIndex], gEditKeyboardRow4KeySize[0], &keyRect);
        if (IsTouchDownInRect(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != keyIndex + 0x33) {
                goto fail;
            }
            ChangeEditKeyboardHighlight(keyIndex + 0x33);
            goto done;
        }
    }
fail:
    ChangeEditKeyboardHighlight(-1);
done:
    gEditKeyboard->mRepeatCalls = 0;
}
