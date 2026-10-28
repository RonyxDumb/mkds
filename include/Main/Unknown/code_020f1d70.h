#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"

// Element of data_027e00cc[0], [1] and [5] up to 0x168: the word and the three vectors from 0x12c and the words
// and halfword from 0x154 that the functions of this file read after the shared part.
typedef struct Unk020f1d70 {
    /* 000 */ Unk020f41c4_A mUnk_000;
    /* 12c */ s32 mUnk_12c;
    /* 130 */ Vec3 mUnk_130;
    /* 13c */ Vec3 mUnk_13c;
    /* 148 */ Vec3 mUnk_148;
    /* 154 */ s32 mUnk_154;
    /* 158 */ s32 mUnk_158;
    /* 15c */ s32 mUnk_15c;
    /* 160 */ s32 mUnk_160;
    /* 164 */ u16 mUnk_164;
    /* 166 */ u8 mUnk_166[2];
} Unk020f1d70;

typedef struct Unk020edb8c {
    u8 mUnk_00[0xc];
    Unk020f40dc_Owner *mUnk_0c;
    Unk0206bcb0 *mUnk_10;
    u8 mUnk_14[0x18];
    Vec3 mUnk_2c;
    Vec3 mUnk_38;
    Vec3 mUnk_44;
    u8 mUnk_50[0x18];
    s32 mUnk_68;
    Vec3 mUnk_6c;
    u8 mUnk_78[4];
    s32 mUnk_7c;
    s32 mUnk_80;
    u8 mUnk_84[8];
    s32 mUnk_8c;
} Unk020edb8c;

void func_020f1d70(void *a0, const Vec3 *b);
void func_020f1ea4(void *a0, s32 b, s32 c, s32 d);
void func_020f1f98(Unk020f1d70 *a, Vec3 *b, Vec3 *c);
void func_020f2028(Unk020f41c4_A *a);
void func_020f2150(void *a0);
void func_020f2228(Unk020f1d70 *a, s32 b);
void func_020f2768(Unk020f1d70 *a, Vec3 *b, Vec3 *c);
void func_020f288c(Unk020f1d70 *a, Vec3 *b);
void func_020f29e8(u32 a);
void func_020f2a6c(Vec3 *a, Vec3 *b, Vec3 *c);
void func_020f2b94(void *a0, void *b0, s32 c, s32 d, s32 e, s32 f);
