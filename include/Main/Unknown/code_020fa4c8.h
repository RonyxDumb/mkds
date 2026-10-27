#pragma once

#include "types.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02012b30.h"

extern Unk020ea670 *data_0217bd38;

// Object func_020e6b38 returns: a vector at 0x18.
typedef struct Unk020e6b38 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ Vec3 mUnk_18;
} Unk020e6b38;

// Stack object of func_020fb038: the two vectors func_02039860 and func_020d7b88 write.
typedef struct Unk020fb038 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ u8 mUnk_18[8];
} Unk020fb038;

// Element of data_027e00cc[5]: 0x31c bytes (the size in data_0217bc34[5]), taken by the functions of this file
// from func_020fad9c to func_020fc268 and by the ones code_020fc000.h declares.
typedef struct Unk020fc2e8 {
    /* 000 */ Unk020f41c4_A mUnk_000;
    /* 12c */ u8 mUnk_12c[4];
    /* 130 */ u32 mUnk_130;
    /* 134 */ u8 mUnk_134[0x34];
    /* 168 */ Unk0206bcb0 *mUnk_168;
    /* 16c */ u8 mUnk_16c[0xb0];
    /* 21c */ s32 mUnk_21c;
    /* 220 */ u8 mUnk_220[8];
    /* 228 */ Unk020f40dc_Owner *mUnk_228;
    /* 22c */ Vec3 mUnk_22c;
    /* 238 */ Vec3 mUnk_238;
    /* 244 */ u8 mUnk_244[0xc];
    /* 250 */ s32 mUnk_250;
    /* 254 */ s32 mUnk_254;
    /* 258 */ s32 mUnk_258;
    /* 25c */ s32 mUnk_25c;
    /* 260 */ s32 mUnk_260;
    /* 264 */ u32 mUnk_264;
    /* 268 */ u8 mUnk_268[4];
    /* 26c */ s32 mUnk_26c;
    /* 270 */ s32 mUnk_270;
    /* 274 */ u16 mUnk_274;
    /* 276 */ u16 mUnk_276;
    /* 278 */ s32 mUnk_278;
    /* 27c */ s32 mUnk_27c;
    /* 280 */ u16 mUnk_280;
    /* 282 */ u8 mUnk_282[2];
    /* 284 */ s32 mUnk_284;
    /* 288 */ u16 mUnk_288;
    /* 28a */ u8 mUnk_28a[2];
    /* 28c */ Vec3 mUnk_28c;
    /* 298 */ Vec3 mUnk_298;
    /* 2a4 */ Vec3 mUnk_2a4;
    /* 2b0 */ struct Unk0208e490 *mUnk_2b0;
    /* 2b4 */ u8 mUnk_2b4[0x30];
    /* 2e4 */ s32 mUnk_2e4;
    /* 2e8 */ u8 mUnk_2e8[4];
    /* 2ec */ u32 mUnk_2ec;
    /* 2f0 */ u8 mUnk_2f0[6];
    /* 2f6 */ u16 mUnk_2f6;
    /* 2f8 */ u16 mUnk_2f8;
    /* 2fa */ u16 mUnk_2fa;
    /* 2fc */ s32 mUnk_2fc;
    /* 300 */ u8 mUnk_300[0x1c];
} Unk020fc2e8;

s32 func_020fa4c8(Unk0206bcb0 *param_1);
void func_020fa78c(s32 param_1, s32 param_2, s32 param_3);
void func_020fa8ac(void);
void func_020fa920(void);
void func_020fa9e4(void);
s32 func_020faa78(s32 param_1);
s32 func_020fab34(s32 *param_1);
s32 func_020faca4(s32 param_1);
void func_020fad00(void);
Vec3 *func_020fad9c(Unk020fc2e8 *param_1, s32 *param_2, s32 *param_3);
s32 func_020fadcc(Unk020fc2e8 *param_1);
s32 func_020fade4(Unk020fc2e8 *param_1);
void func_020fae74(Unk020fc2e8 *param_1, s32 param_2, s32 param_3);
void func_020faed0(Unk020fc2e8 *param_1, s32 param_2, s32 param_3);
void func_020fb038(Unk020fc2e8 *param_1);
void *func_020fb208(void *param_1, Unk020fc2e8 *param_2, void *param_3);
void func_020fb2b4(Unk020fc2e8 *param_1);
void func_020fb35c(Unk020fc2e8 *param_1);
void func_020fb46c(Unk020fc2e8 *param_1);
void func_020fb5dc(Unk020fc2e8 *param_1);
void func_020fb61c(Unk020fc2e8 *param_1);
void func_020fb770(Unk020fc2e8 *param_1);
void func_020fb7f8(Unk020fc2e8 *param_1);
void func_020fba6c(Unk020fc2e8 *param_1);
void func_020fbae0(Unk020fc2e8 *param_1);
void func_020fbc18(Unk020fc2e8 *param_1);
void func_020fbd4c(Unk020fc2e8 *param_1);
void func_020fbd98(Unk020fc2e8 *param_1);
void func_020fc268(Unk020fc2e8 *param_1);
