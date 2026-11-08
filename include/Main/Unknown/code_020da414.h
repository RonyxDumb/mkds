#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020d6dc0.h" // Quaternion
#include "Main/Unknown/code_020e005c.h" // GroupFollower

typedef struct CourseMapRow CourseMapRow;

// Object allocated by func_020da414; 0x40 bytes.
typedef struct Unk020da414 {
    /* 00 */ s32 mUnk_00[0x10];
} Unk020da414;

// Object of kind 0x191 (Kuribo), at least 0x108 bytes; also created in pools by ov001.
typedef struct Kuribo {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mStartY;
    /* a4 */ Quaternion mOrientation;
    /* b4 */ Quaternion mTargetOrientation;
    /* c4 */ s32 mScaleFactorY;
    /* c8 */ s32 mUnk_c8;
    /* cc */ GroupFollower mFollower;
    /* f0 */ u16 mFrameIndex;
    /* f2 */ u8 mUnk_f2[2];
    /* f4 */ s32 mFrameRandomized;
    /* f8 */ u16 mOrientationBlendAmount;
    /* fa */ u8 mUnk_fa[2];
    /* fc */ s32 mUnk_fc;
    /* 100 */ u16 mModelAlpha;
    /* 102 */ s16 mUnk_102;
    /* 104 */ s32 mUnk_104;
} Kuribo;

/* also runs for source-created objects with b == NULL (then only mUnk_100 is set) */
void InitKuribo(Kuribo *kuribo, CourseMapRow *row);
Unk020da414 *func_020da414(void);
