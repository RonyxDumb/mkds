#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h" // GroupFollower
#include "Main/Unknown/code_020f9c6c.h" // CourseMapRow

// Object of kind 0x158 (Airship) with the GroupFollower base at 0xc8 (aship_render, aship_globalLogicInit).
typedef struct Airship {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s16 mWobbleAngle;
    /* aa */ u8 mUnk_aa[2];
    /* ac */ s32 mWobbleOffset;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mWobbleMid;
    /* b8 */ s32 mWobbleAmplitude;
    /* bc */ u32 mWobbleAmplitudePerFrame;
    /* c0 */ s32 mWobbleAnglePerFrame;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ GroupFollower mUnk_c8;
    /* State number of this kind's own per-frame switch in aship_update; this object does not use
       MapObject.mUnk_80's state machine; also written by the group pre-step */
    /* ec */ s32 mState;
} Airship;

// Array of object pointers: pointer to the array and the number of entries (aship_globalLogicInit).
typedef struct AirshipObjectList {
    /* 00 */ Airship **mUnk_00;
    /* 04 */ u16 mUnk_04;
} AirshipObjectList;

void aship_loadModel(void *a);
void aship_render(void *a, Airship *airship);
void aship_globalLogicInit(AirshipObjectList *list);
s32 aship_FX_CosIdx(s32 angle);
s32 aship_FX_MulInline(s32 multiplicand, s32 multiplier);
