#include "03/System/task_input.h"
#include "03/System/task_input_init.h"
#include "03/System/exp_heap.h"
#include "03/Menu/wifi_menu_shared.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "tp.h"
#include "registers.h"
#include "03/System/rect.h"
#include "03/types_021d299c.h"
#include "code_02147cd8.h"

u8 gTouchRepeatFrames;
KeyTouchInput *gKeyTouchInput;
u8 gKeyRepeatFrames[14];

void InitKeyTouchInput(void) {
    TPCalibrateParam calibration;

    gKeyTouchInput = AllocZeroedExpHeapBlock(0x3a, 4);
    if (TP_GetUserInfo(&calibration) == 0) {
        OS_Terminate();
    }
    TP_SetCalibrateParam(&calibration);
    TP_RequestAutoSamplingStartAsync(0, 4, gKeyTouchInput->mTouchSamples, 5);
    TP_WaitBusy(2);
    if (TP_CheckError(2) != 0) {
        OS_Terminate();
    }
    UpdateKeyTouchInput();
}

void ReleaseKeyTouchInput(void) {
    do {
        TP_RequestAutoSamplingStopAsync();
        TP_WaitBusy(4);
    } while (TP_CheckError(4) != 0);
    FreeExpHeapBlockAndClearPointer(&gKeyTouchInput);
}

void UpdateKeyTouchInput(void) {
    UpdateKeyInput();
    UpdateTouchInput();
}

void UpdateKeyInput(void) {
    KeyTouchInput *input = gKeyTouchInput;
    u16 keys = ((*(u16 *) 0x4000130 | *(u16 *) 0x27fffa8) ^ 0x2fff) & 0x2fff;
    s32 keyIndex;
    u16 keyBit;

    input->mKeysPressed = keys & (keys ^ input->mKeysDown);
    gKeyTouchInput->mKeysReleased = input->mKeysDown & (keys ^ input->mKeysDown);
    gKeyTouchInput->mKeysDown = keys;
    gKeyTouchInput->mKeysPressedOrRepeated = gKeyTouchInput->mKeysPressed;
    for (keyIndex = 0; keyIndex < 14; keyIndex++) {
        keyBit = 1 << keyIndex;
        if ((keys & keyBit) == 0) {
            gKeyRepeatFrames[keyIndex] = 0;
        } else {
            gKeyRepeatFrames[keyIndex]++;
            if (gKeyRepeatFrames[keyIndex] == 0x28) {
                gKeyTouchInput->mKeysPressedOrRepeated |= keyBit;
            } else if (gKeyRepeatFrames[keyIndex] == 0x2f) {
                gKeyTouchInput->mKeysPressedOrRepeated |= keyBit;
                gKeyRepeatFrames[keyIndex] = 0x28;
            }
        }
    }
}

void UpdateTouchInput(void) {
    u8 found;
    u32 wasDown;
    u32 value;
    s32 sampleCount;
    TPData point;
    KeyTouchInput *input;

    if (gKeyTouchInput->mBits.mDown != 0) {
        wasDown = 1;
    } else {
        wasDown = 0;
    }
    found = 0;
    value = TP_GetLatestIndexInAuto();
    input = gKeyTouchInput;
    input->mPrevTouchX = input->mTouchX;
    input->mPrevTouchY = input->mTouchY;
    sampleCount = 0;
    do {
        TPData *sample = &gKeyTouchInput->mTouchSamples[value];

        if (sample->mTouch == 1 && sample->mValidity == 0) {
            found = 1;
            TP_GetCalibratedPoint(&point, sample);
            SetPosition(point.mX, point.mY, &gKeyTouchInput->mTouchX);
            break;
        }
        sampleCount++;
        value = FX_ModS32(value + 4, 5);
    } while (sampleCount < 4);
    value = found ^ wasDown;
    gKeyTouchInput->mBits.mPressed = found & value;
    gKeyTouchInput->mBits.mReleased = wasDown & value;
    gKeyTouchInput->mBits.mDown = found;
    gKeyTouchInput->mBits.mPressedOrRepeated = gKeyTouchInput->mBits.mPressed;
    if (found == 0) {
        gTouchRepeatFrames = 0;
        return;
    }
    gTouchRepeatFrames++;
    if (gTouchRepeatFrames == 0x28) {
        gKeyTouchInput->mBits.mPressedOrRepeated = 1;
    } else if (gTouchRepeatFrames == 0x2f) {
        gKeyTouchInput->mBits.mPressedOrRepeated = 1;
        gTouchRepeatFrames = 0x28;
    }
}

BOOL AreKeysDown(u32 keys) {
    if (keys == (keys & gKeyTouchInput->mKeysDown)) {
        return 1;
    }
    return 0;
}

BOOL AreKeysPressed(u32 keys) {
    if (keys == (keys & gKeyTouchInput->mKeysPressed)) {
        return 1;
    }
    return 0;
}

BOOL AreKeysPressedOrRepeated(u32 keys) {
    if (keys == (keys & gKeyTouchInput->mKeysPressedOrRepeated)) {
        return 1;
    }
    return 0;
}

BOOL AreKeysReleased(u32 keys) {
    if (keys == (keys & gKeyTouchInput->mKeysReleased)) {
        return 1;
    }
    return 0;
}

BOOL IsTouchDownInRect(const Rect *rect) {
    KeyTouchInput *input = gKeyTouchInput;
    if (input->mBits.mDown == 0) {
        return 0;
    }
    if (rect->mX > input->mTouchX) {
        return 0;
    }
    if (rect->mRight < input->mTouchX) {
        return 0;
    }
    if (rect->mY > input->mTouchY) {
        return 0;
    }
    if (rect->mBottom >= input->mTouchY) {
        return 1;
    }
    return 0;
}

BOOL IsTouchPressedInRect(const Rect *rect) {
    KeyTouchInput *input = gKeyTouchInput;
    if ((((u32) input->mTouchFlags << 30) >> 31) == 0) {
        return 0;
    }
    if (rect->mX > input->mTouchX) {
        return 0;
    }
    if (rect->mRight < input->mTouchX) {
        return 0;
    }
    if (rect->mY > input->mTouchY) {
        return 0;
    }
    if (rect->mBottom >= input->mTouchY) {
        return 1;
    }
    return 0;
}

BOOL IsTouchPressedOrRepeatedInRect(const Rect *rect) {
    KeyTouchInput *input = gKeyTouchInput;
    if ((((u32) input->mTouchFlags << 29) >> 31) == 0) {
        return 0;
    }
    if (rect->mX > input->mTouchX) {
        return 0;
    }
    if (rect->mRight < input->mTouchX) {
        return 0;
    }
    if (rect->mY > input->mTouchY) {
        return 0;
    }
    if (rect->mBottom >= input->mTouchY) {
        return 1;
    }
    return 0;
}

BOOL IsTouchReleasedInRect(const Rect *rect) {
    KeyTouchInput *input = gKeyTouchInput;
    if ((((u32) input->mTouchFlags << 28) >> 31) == 0) {
        return 0;
    }
    if (rect->mX > input->mTouchX) {
        return 0;
    }
    if (rect->mRight < input->mTouchX) {
        return 0;
    }
    if (rect->mY > input->mTouchY) {
        return 0;
    }
    if (rect->mBottom >= input->mTouchY) {
        return 1;
    }
    return 0;
}

BOOL IsTouchPressedInOriginSizeRect(const OriginSizeRect *input) {
    Rect rect;
    rect.mX = input->mX;
    rect.mY = input->mY;
    rect.mRight = input->mX + input->mWidth;
    rect.mBottom = input->mY + input->mHeight;
    return IsTouchPressedInRect(&rect);
}

BOOL GetTouchPoint(u16 *output) {
    KeyTouchInput *state = gKeyTouchInput;
    if (state->mBits.mDown == 0) {
        output[0] = state->mPrevTouchX;
        output[1] = state->mPrevTouchY;
        return FALSE;
    }
    output[0] = state->mTouchX;
    output[1] = state->mTouchY;
    return TRUE;
}
