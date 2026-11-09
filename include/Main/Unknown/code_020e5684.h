#pragma once

#include "types.h"
#include "Main/Unknown/code_020d6dc0.h" // Quaternion
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList, MapObjectKindData
#include "Main/Unknown/unk_02158000.h" // MapObjectDrawList
#include "Main/Unknown/code_020ec538.h" // PushedObject

// Object InitSecondHand sets up, 0xd0 bytes.
typedef struct SecondHand {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ Quaternion mUnk_a0;
    /* b0 */ Quaternion mUnk_b0;
    /* c0 */ u16 mUnk_c0;
    /* c2 */ u16 mUnk_c2;
    /* c4 */ u16 mUnk_c4;
    /* c6 */ s16 mUnk_c6;
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
} SecondHand;

// Object InitObPakkunSf sets up.
typedef struct ObPakkunSf {
    /* 00 */ PushedObject mPushedObject;
    /* b8 */ u16 mFramesSinceInit;
} ObPakkunSf;

// Second argument of InitSecondHand: a vector at 0x0c, halfwords from 0x28.
typedef struct Unk020e5684 {
    /* 00 */ u8 mUnk_00[0x0c];
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ u8 mUnk_18[0x10];
    /* 28 */ s16 mUnk_28;
    /* 2a */ s16 mUnk_2a;
    /* 2c */ s16 mUnk_2c;
    /* 2e */ s16 mUnk_2e;
    /* 30 */ s16 mUnk_30;
} Unk020e5684;

void CreateSecondHand(void);

void CreateObPakkunSf(void);

extern MapObjectList *data_0217b81c;
extern MapObjectDrawList *data_0217b824;
extern MapObjectList *data_0217b828;
extern MapObjectDrawList *data_0217b82c;
extern MapObjectList *data_0217b834;
extern MapObjectDrawList *data_0217b840;

void InitSecondHand(SecondHand *secondHand, Unk020e5684 *courseRow);
void ComputeSphereHitOnSecondHand(SecondHand *secondHand, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset);
void UpdateSecondHand(u32 a, SecondHand *secondHand);
void DrawSecondHand(u32 a, SecondHand *secondHand, u32 b, u32 alpha);
MapObjectList *CreateSecondHandUpdateList(void);
MapObjectDrawList *CreateSecondHandDrawList(void);
MapObjectKindData *CreateSecondHandKindData(void);
void InitObPakkunSf(ObPakkunSf *obPakkunSf);
