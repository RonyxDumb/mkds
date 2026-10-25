#pragma once

#include "types.h"

// Object behind func_ov001_02188c90 and the per-state functions around func_ov001_021900ac.
typedef struct Unk02188950_a0 {
    /* 000 */ u8 mUnk_000[0x1ec];
    /* 1ec */ u32 mUnk_1ec;
    /* 1f0 */ u8 mUnk_1f0[0xcc];
    /* 2bc */ u32 mUnk_2bc;
    /* 2c0 */ u32 mUnk_2c0;
    /* 2c4 */ u32 mUnk_2c4;
} Unk02188950_a0;

typedef struct Unk02188950 {
    /* 000 */ u8 mUnk_000[0xa0];
    /* 0a0 */ Unk02188950_a0 *mUnk_0a0;
    /* 0a4 */ u8 mUnk_0a4[0x4];
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ u8 mUnk_0ac[0xd4];
    /* 180 */ s32 mUnk_180;
    /* 184 */ u8 mUnk_184[0x4];
    /* 188 */ Vec3 mUnk_188;
    /* 194 */ s32 mUnk_194;
    /* 198 */ s32 mUnk_198;
    /* 19c */ s32 mUnk_19c;
    /* 1a0 */ s32 mUnk_1a0;
    /* 1a4 */ s32 mUnk_1a4;
    /* 1a8 */ u8 mUnk_1a8[0x4];
    /* 1ac */ Vec3 mUnk_1ac;
    /* 1b8 */ s32 mUnk_1b8;
    /* 1bc */ s32 mUnk_1bc;
    /* 1c0 */ s32 mUnk_1c0;
    /* 1c4 */ s32 mUnk_1c4;
    /* 1c8 */ Vec3 mUnk_1c8;
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
