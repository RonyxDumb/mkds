#pragma once

#include "types.h"
#include "Main/Unknown/code_020d6dc0.h" // Quaternion
#include "Main/Unknown/code_020e6fd4.h" // MapObject
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

// 0x28-byte object CreateSecondHandUpdateList loads from data_021590ec.
typedef struct Unk020e59e4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
} Unk020e59e4;

// 0x2c-byte object CreateSecondHandDrawList loads from data_02159114.
typedef struct Unk020e5a40 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
} Unk020e5a40;

// 0x40-byte object CreateSecondHandKindData loads from data_02159140.
typedef struct Unk020e5a9c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
} Unk020e5a9c;

void CreateObPakkunSf(void);

extern Unk020e59e4 *data_0217b81c;
extern Unk020e5a40 *data_0217b824;
extern Unk020e59e4 *data_0217b828;
extern Unk020e5a40 *data_0217b82c;
extern Unk020e59e4 *data_0217b834;
extern Unk020e5a40 *data_0217b840;

void InitSecondHand(SecondHand *secondHand, Unk020e5684 *courseRow);
void ComputeSphereHitOnSecondHand(SecondHand *secondHand, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset);
void UpdateSecondHand(u32 a, SecondHand *secondHand);
void DrawSecondHand(u32 a, SecondHand *secondHand, u32 b, u32 alpha);
Unk020e59e4 *CreateSecondHandUpdateList(void);
Unk020e5a40 *CreateSecondHandDrawList(void);
Unk020e5a9c *CreateSecondHandKindData(void);
void InitObPakkunSf(ObPakkunSf *obPakkunSf);
