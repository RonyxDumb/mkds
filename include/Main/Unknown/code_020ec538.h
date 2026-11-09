#pragma once

#include "types.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

typedef struct ItemObject ItemObject;
typedef struct Kart Kart;

// Motion words at 0xa0 of the objects the pushed-motion functions work on.
typedef struct Unk020ec538_a0 {
    /* 00 */ s32 mUnk_0a0;
    /* 04 */ s32 mUnk_0a4;
    /* 08 */ u32 mUnk_0a8;
    /* 0c */ u16 mUnk_0ac;
    /* 0e */ u16 mUnk_0ae;
    /* 10 */ u32 mUnk_0b0;
    /* 14 */ s32 mUnk_0b4;
} Unk020ec538_a0;

// First 0xb8 bytes of the kinds the pushed-motion functions work on; each kind embeds it first.
typedef struct Unk020ec538 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ Unk020ec538_a0 mUnk_a0;
} Unk020ec538;

extern const Vec3 gVec3UnitX;
extern const Vec3 data_02159588;
extern const Vec3 data_02159594;

void SetPushedMotionFromItemObject(Unk020ec538 *object, const ItemObject *other);
void SetPushedMotionFromKart(Unk020ec538 *object, Kart *other);
BOOL AdvancePushedMotion(Unk020ec538 *object);
void InitPushedMotion(Unk020ec538 *object, s32 lowestY, u32 gravity, u16 angleStep, u32 upwardSpeed, s32 pushSpeed);
