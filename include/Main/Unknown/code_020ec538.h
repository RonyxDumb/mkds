#pragma once

#include "types.h"
#include "Main/Unknown/code_020ec1fc.h"

// Second argument of rdmo_20EC538 and rdmo_20EC6E4: vectors at 0x50, 0x5c and 0x80, words
// at 0xa4 and 0xac.
typedef struct Unk020ec6e4 {
    /* 000 */ u8 field0[0x50];
    /* 050 */ Vec3 field50;
    /* 05c */ Vec3 field5C;
    /* 068 */ u8 field68[0x18];
    /* 080 */ Vec3 field80;
    /* 08c */ u8 field8C[0x18];
    /* 0a4 */ s32 fieldA4;
    /* 0a8 */ u8 fieldA8[4];
    /* 0ac */ s32 fieldAC;
} Unk020ec6e4;

extern const Vec3 gVec3UnitX;
extern const Vec3 data_02159588;
extern const Vec3 data_02159594;

void rdmo_20EC538(Unk020e43a8 *object, const Unk020ec6e4 *other);
void rdmo_20EC6E4(Unk020e43a8 *object, Unk020ec6e4 *other);
BOOL rdmo_dieUpdate(Unk020e43a8 *object);
void rdmo_initParams(Unk020e43a8 *object, s32 lowestY, u32 gravity, u16 angleStep, u32 upwardSpeed, s32 pushSpeed);
