#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object of kind 0xd2 (Dram) and the functions of this file: 0xc0 bytes.
typedef struct Dram {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mRampFrameCount;
    /* a2 */ u16 mSteadyFrameCount;
    /* a4 */ u16 mDelayFrameCount;
    /* a6 */ u16 mAngleX;
    /* a8 */ s16 mAnglePerFrame;
    /* aa */ u8 mUnk_aa[2];
    /* ac */ s32 mRamp;
    /* b0 */ s32 mRampPerFrame;
    /* b4 */ s16 mAnglePerFrameChoices[3];
    /* ba */ u8 mUnk_ba[2];
    /* bc */ s32 mAngleRemaining;
} Dram;

void UpdateDramState4(Dram *dram);
void EnterDramState5(Dram *dram);
