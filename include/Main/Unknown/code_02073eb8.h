#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"

// Object behind data_0217ac94.
typedef struct Unk0217ac94 {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ Vec3 mUnk_24;
    /* 30 */ Unk020d4f94 mUnk_30;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ u8 mUnk_68[0x20];
    /* 88 */ s32 mUnk_88;
    /* 8c */ u8 mUnk_8c[0x34];
    /* c0 */ Vec3 mUnk_c0;
    /* cc */ s32 mUnk_cc;
    /* d0 */ s32 mUnk_d0;
    /* d4 */ u8 mUnk_d4[8];
    /* dc */ s32 mUnk_dc;
    /* e0 */ u8 mUnk_e0[8];
    /* e8 */ s32 mUnk_e8;
    /* ec */ u8 mUnk_ec[4];
    /* f0 */ s32 mUnk_f0;
    /* f4 */ u8 mUnk_f4[0x40];
    /* 134 */ Vec3 mUnk_134;
    /* 140 */ s32 mUnk_140;
    /* 144 */ s32 mUnk_144;
    /* 148 */ s32 mUnk_148;
    /* 14c */ s32 mUnk_14c;
    /* 150 */ s16 mUnk_150;
    /* 152 */ u8 mUnk_152[2];
    /* 154 */ s32 mUnk_154;
    /* 158 */ s32 mUnk_158;
    /* 15c */ u8 mUnk_15c[0xc];
    /* 168 */ s32 mUnk_168;
    /* 16c */ u8 mUnk_16c[0x10];
    /* 17c */ Vec3 mUnk_17c;
    /* 188 */ Vec3 mUnk_188;
    /* 194 */ u8 mUnk_194[0xb4];
    /* 248 */ s32 mUnk_248;
} Unk0217ac94;

void func_02073eb8(Unk0217ac94 *p);
void func_02073f90(void);
void func_02073fb0(u32 a, s32 b);
void func_02073fc8(s32 a, u32 b, s32 c);
void func_0207409c(Vec3 *a, void *b);
void func_020741a0(Vec3 *a, Vec3 *b, Unk0217ac94 *c, Unk0206bcb0 *d, Vec3 *e, const Vec3 *f, s32 g);
void func_020745d4(Vec3 *a, Vec3 *b, s32 *c, Unk0206bcb0 *d, s32 e, s32 f);
void func_020747f4(s32 a);
void func_02074828(void);
