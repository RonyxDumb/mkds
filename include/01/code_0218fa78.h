#pragma once

#include "types.h"
#include "01/code_02188950.h"

// List of objects: an array of pointers and its length.
typedef struct Unk0218fa78 {
    /* 00 */ Unk02188950 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0218fa78;

// Offsets 0x50..0x5b of the object are a position.
typedef struct Unk0218fd20 {
    /* 00 */ u8 mUnk_00[0x50];
    /* 50 */ Vec3 mUnk_50;
} Unk0218fd20;

void func_ov001_0218fee0(Unk02188950 *param_1);
void func_ov001_0218fd20(Unk02188950 *param_1, Unk0218fd20 *param_2);
void func_ov001_0218fcc4(Unk0218fa78 *param_1);
void func_ov001_0218fc4c(u32 param_1, Unk02188950 *param_2);
void func_ov001_0218fbe0(Unk0218fa78 *param_1);
void func_ov001_0218fb24(u32 param_1, Unk02188950 *param_2);
void func_ov001_0218fa78(Unk0218fa78 *param_1);
