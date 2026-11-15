#pragma once

#include "types.h"
#include "01/MapObjects/mission_run_map_object.h"

// Calls a key has been held at which it repeats (the held counts also count 1 for the first call), and calls a touch
// must stay within one pixel of its previous point to count as pressed and released.
#define EMBLEM_INPUT_REPEAT_CALLS 0xf
#define EMBLEM_INPUT_STILL_PRESS_CALLS 0x3c

typedef struct EmblemInput {
    /* 0x00 */ s32 mX;
    /* 0x04 */ s32 mY;
    /* 0x08 */ s32 mPressed;
    /* 0x0c */ s32 mReleased;
    /* 0x10 */ s32 mDown;
    /* 0x14 */ s32 mStillCallCount;
    /* 0x18 */ s32 mPrevX;
    /* 0x1c */ s32 mPrevY;
    /* 0x20 */ s32 mPrevPressed;
    /* 0x24 */ s32 mPrevReleased;
    /* 0x28 */ s32 mPrevDown;
    /* 0x2c */ s32 mLeftHeldCount;
    /* 0x30 */ s32 mRightHeldCount;
    /* 0x34 */ s32 mUpHeldCount;
    /* 0x38 */ s32 mDownHeldCount;
    /* 0x3c */ s32 mAHeldCount;
    /* 0x40 */ s32 mBHeldCount;
    /* 0x44 */ s32 mXHeldCount;
    /* 0x48 */ s32 mYHeldCount;
    /* 0x4c */ s32 mLHeldCount;
    /* 0x50 */ s32 mRHeldCount;
} EmblemInput;

#include "01/MapObjects/iwante.h"

BOOL IsEmblemInputRepeat(int mask);
u16 GetEmblemInputBits(u16 mask);
u16 GetEmblemInputNewBits(u16 mask);
u32 GetEmblemInputPrevDown(void);
u32 GetEmblemInputPrevY(void);
u32 GetEmblemInputPrevX(void);
u32 GetEmblemInputDown(void);
u32 GetEmblemInputPressed(void);
u32 GetEmblemInputY(void);
s32 GetEmblemInputX(void);
void AdvanceEmblemInput(void);
void CreateEmblemInput(void);
