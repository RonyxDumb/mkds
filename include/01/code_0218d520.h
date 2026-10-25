#pragma once

#include "types.h"
#include "01/code_02188950.h"

// Object behind Unk02188950::mUnk_0a4.
typedef struct Unk0218dabc {
    /* 000 */ u8 mUnk_000[0x4];
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ u8 mUnk_010[0x174];
    /* 184 */ s32 mUnk_184;
} Unk0218dabc;

typedef struct Unk0218d954 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0xa];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ s32 **mUnk_1c;
} Unk0218d954;

// Object at Unk0218d950::mUnk_10.
typedef struct Unk0218d950_10 {
    /* 00 */ u8 mUnk_00[0x2c];
    /* 2c */ Unk02188950 *mUnk_2c;
} Unk0218d950_10;

// Object behind Unk02188950::mUnk_304.
typedef struct Unk0218d950 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ Unk0218d950_10 *mUnk_10;
    /* 14 */ u8 mUnk_14[0x8];
    /* 1c */ Unk0218d954 *mUnk_1c;
} Unk0218d950;

// Table of objects returned by func_02100138(0x1fe).
typedef struct Unk0218d87c {
    /* 00 */ Unk02188950 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0218d87c;

int func_ov001_0218d520(Unk02188950 *param_1);
void func_ov001_0218d800(Unk02188950 *param_1);
void func_ov001_0218d824(Unk02188950 *param_1, int param_2);
void func_ov001_0218d87c(Unk02188950 *param_1, int param_2);
void func_ov001_0218d8f4(Unk02188950 *param_1, int param_2);
void func_ov001_0218d950(Unk02188950 *param_1);
void func_ov001_0218d9cc(Unk02188950 *param_1);
void func_ov001_0218da1c(Unk02188950 *param_1);
void func_ov001_0218dabc(Unk02188950 *param_1);
void func_ov001_0218dadc(Unk02188950 *param_1);
void func_ov001_0218dba8(Unk02188950 *param_1);
void func_ov001_0218dc20(Unk02188950 *param_1);
