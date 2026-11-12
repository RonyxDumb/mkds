#include "03/Menu/edit_keyboard_touch.h"
#include "03/Menu/edit_keyboard.h"
#include "03/Menu/edit_keyboard_slide_out.h"
#include "03/unk_021da000.h"
#include "03/unk_021d5f00.h"
#include "03/unk_021d6000.h"
#include "03/System/task_input.h"
#include "03/System/rect.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"

const u16 gEditKeyboardExtraKeySizes[1][2] = {{0x1b, 0x12}};
const u16 gEditKeyboardPage1KeySize[1][2] = {{0x20, 0x12}};
const u16 gEditKeyboardLastExtraKeySizes[2][2] = {{0x28, 0x12}, {0x20, 0x12}};
const u16 gEditKeyboardKeyPositions[16][2] = {{4, 0x51}, {0x16, 0x51}, {0x28, 0x51}, {0x3a, 0x51}, {0x4c, 0x51}, {0x5e, 0x51}, {0x70, 0x51}, {0x82, 0x51}, {0x94, 0x51}, {0xa6, 0x51}, {0xb8, 0x51}, {0xca, 0x51}, {0x20, 0x67}, {0x32, 0x67}, {0x44, 0x67}, {0x56, 0x67}};
const u16 gEditKeyboardKeyPositionsSecond[16][2] = {{0x68, 0x67}, {0x7a, 0x67}, {0x8c, 0x67}, {0x9e, 0x67}, {0xb0, 0x67}, {0xc2, 0x67}, {0xd4, 0x67}, {0xe6, 0x67}, {0x25, 0x7d}, {0x37, 0x7d}, {0x49, 0x7d}, {0x5b, 0x7d}, {0x6d, 0x7d}, {0x7f, 0x7d}, {0x91, 0x7d}, {0xa3, 0x7d}};

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
    const u16(*extraKeySizes)[2];
    const u16(*extraKeyOrigins)[2];
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
