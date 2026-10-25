#pragma once

#include "types.h"

// Object behind func_ov001_02188c90 and the per-state functions around func_ov001_021900ac.
typedef struct Unk02188950_a0 {
    /* 000 */ u8 mUnk_000[0x88];
    /* 088 */ s32 mUnk_088;
    /* 08c */ s32 mUnk_08c;
    /* 090 */ s32 mUnk_090;
    /* 094 */ s32 mUnk_094;
    /* 098 */ s32 mUnk_098;
    /* 09c */ s32 mUnk_09c;
    /* 0a0 */ s32 mUnk_0a0;
    /* 0a4 */ u8 mUnk_0a4[0x4];
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ u8 mUnk_0b0[0x10];
    /* 0c0 */ s32 mUnk_0c0;
    /* 0c4 */ s32 mUnk_0c4;
    /* 0c8 */ s32 mUnk_0c8;
    /* 0cc */ s32 mUnk_0cc;
    /* 0d0 */ s32 mUnk_0d0;
    /* 0d4 */ s32 mUnk_0d4;
    /* 0d8 */ s32 mUnk_0d8;
    /* 0dc */ u8 mUnk_0dc[0x28];
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ s32 mUnk_10c;
    /* 110 */ s32 mUnk_110;
    /* 114 */ s32 mUnk_114;
    /* 118 */ s32 mUnk_118;
    /* 11c */ s32 mUnk_11c;
    /* 120 */ s32 mUnk_120;
    /* 124 */ s32 mUnk_124;
    /* 128 */ s32 mUnk_128;
    /* 12c */ s32 mUnk_12c;
    /* 130 */ s32 mUnk_130;
    /* 134 */ u8 mUnk_134[0xb8];
    /* 1ec */ u32 mUnk_1ec;
    /* 1f0 */ u8 mUnk_1f0[0xcc];
    /* 2bc */ u32 mUnk_2bc;
    /* 2c0 */ u32 mUnk_2c0;
    /* 2c4 */ u32 mUnk_2c4;
} Unk02188950_a0;

typedef struct Unk02188950 {
    /* 000 */ u8 mUnk_000[0x4];
    /* 004 */ Vec3 mUnk_004;
    /* 010 */ u8 mUnk_010[0x90];
    /* 0a0 */ Unk02188950_a0 *mUnk_0a0;
    /* 0a4 */ struct Unk0218dabc *mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ u8 mUnk_0b0[0x8c];
    /* 13c */ s32 mUnk_13c;
    /* 140 */ s32 mUnk_140;
    /* 144 */ s32 mUnk_144;
    /* 148 */ u8 mUnk_148[0x4];
    /* 14c */ s32 mUnk_14c;
    /* 150 */ s32 mUnk_150;
    /* 154 */ u8 mUnk_154[0x2c];
    /* 180 */ s32 mUnk_180;
    /* 184 */ s32 mUnk_184;
    /* 188 */ Vec3 mUnk_188;
    /* 194 */ s32 mUnk_194;
    /* 198 */ s32 mUnk_198;
    /* 19c */ s32 mUnk_19c;
    /* 1a0 */ s32 mUnk_1a0;
    /* 1a4 */ s32 mUnk_1a4;
    /* 1a8 */ s32 mUnk_1a8;
    /* 1ac */ Vec3 mUnk_1ac;
    /* 1b8 */ s32 mUnk_1b8;
    /* 1bc */ s32 mUnk_1bc;
    /* 1c0 */ s32 mUnk_1c0;
    /* 1c4 */ s32 mUnk_1c4;
    /* 1c8 */ Vec3 mUnk_1c8;
    /* 1d4 */ u8 mUnk_1d4[0x74];
    /* 248 */ s32 mUnk_248;
    /* 24c */ u8 mUnk_24c[0xb8];
    /* 304 */ struct Unk0218d950 *mUnk_304;
} Unk02188950;

void func_ov001_02188950(Unk02188950 *param_1, Vec3 *param_2);
void func_ov001_02188968(Unk02188950 *param_1, Vec3 *param_2);
void func_ov001_02188980(Unk02188950 *param_1, Vec3 *param_2);
void func_ov001_02188998(Unk02188950 *param_1, Vec3 *param_2);
void func_ov001_021889c8(Unk02188950 *param_1);
void func_ov001_021889ec(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5);
void func_ov001_02188a30(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5);
void func_ov001_02188a8c(Unk02188950 *param_1, s32 param_2, s32 param_3);
void func_ov001_02188adc(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6);
void func_ov001_02188b2c(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4);
void func_ov001_02188b78(Unk02188950 *param_1, s32 param_2, s32 param_3);
void func_ov001_02188bc4(Unk02188950 *param_1, s32 param_2, s32 param_3);
void func_ov001_02188c0c(Unk02188950 *param_1, s32 param_2, s32 param_3);
void func_ov001_02188c48(Unk02188950 *param_1, s32 param_2, s32 param_3);
void func_ov001_02188c90(Unk02188950 *param_1);
