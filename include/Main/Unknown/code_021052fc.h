#pragma once

#include "types.h"

// Object whose counters run and wrap and whose three fixed-point words follow the
// vector at mUnk_fc.
typedef struct Unk021052fc {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ u8 mUnk_10[0xc];
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ u8 mUnk_28[0x3c];
    /* 64 */ s16 mUnk_64;
    /* 66 */ u16 mUnk_66;
    /* 68 */ u8 mUnk_68[0x38];
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u16 mUnk_a2;
    /* a4 */ u16 mUnk_a4;
    /* a6 */ u8 mUnk_a6[0xa];
    /* b0 */ u16 mUnk_b0;
    /* b2 */ u8 mUnk_b2[0x4a];
    /* fc */ Vec3 *mUnk_fc;
} Unk021052fc;

void func_02105338(Unk021052fc *p, s32 a, Vec3 *v);
void func_021052fc(Unk021052fc *p);
