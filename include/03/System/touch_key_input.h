#pragma once

#include "types.h"
#include "touch_panel_sampling.h"

// A rectangle given by its position and its right and bottom edges.
typedef struct Rect {
    /* 00 */ u16 mX;
    /* 02 */ u16 mY;
    /* 04 */ u16 mRight;
    /* 06 */ u16 mBottom;
} Rect;

// A rectangle given by its position and size.
typedef struct OriginSizeRect {
    /* 00 */ u16 mX;
    /* 02 */ u16 mY;
    /* 04 */ u16 mWidth;
    /* 06 */ u16 mHeight;
} OriginSizeRect;

// The touch and key input state: recent touch samples, touch position and previous touch position, the keys down,
// pressed, pressed or repeated and released, and per-touch flags.
typedef struct KeyTouchInput {
    /* 00 */ TPData mTouchSamples[5];
    /* 28 */ u16 mTouchX;
    /* 2a */ u16 mTouchY;
    /* 2c */ u16 mPrevTouchX;
    /* 2e */ u16 mPrevTouchY;
    /* 30 */ u16 mKeysDown;
    /* 32 */ u16 mKeysPressed;
    /* 34 */ u16 mKeysPressedOrRepeated;
    /* 36 */ u16 mKeysReleased;
    /* 38 */ union {
        u8 mTouchFlags;
        struct {
            u8 mDown : 1;
            u8 mPressed : 1;
            u8 mPressedOrRepeated : 1;
            u8 mReleased : 1;
            u8 mUnused : 4;
        } mBits;
    };
} KeyTouchInput;
