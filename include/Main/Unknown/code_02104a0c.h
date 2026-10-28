#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_020f2dac.h"

// Element of data_027e00cc[8]: 0x14c bytes (the size in data_0217bc34[8]), handled by func_02104a0c to
// func_02104f58: the Unk020f2df0 part, words at 0x130 and 0x138, the Unk021052fc at 0x134, a vector at 0x13c and a
// word at 0x148.
typedef struct Unk02104c68 {
    /* 000 */ Unk020f2df0 mUnk_000;
    /* 130 */ s32 mUnk_130;
    /* 134 */ Unk021052fc *mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ Vec3 mUnk_13c;
    /* 148 */ s32 mUnk_148;
} Unk02104c68;

// Three words; the same ones as in data_0215a6c0 and data_0215a6cc.
typedef struct Unk0215a6c0 {
    /* 00 */ u32 mUnk_00[3];
} Unk0215a6c0;

extern Unk0215a6c0 data_0217c748;

extern Unk0215a6c0 data_0217c73c;

// Object behind data_0217c730; mUnk_00 is the first of the three-word copies,
// mUnk_24 and mUnk_2e are the two halfwords func_02105214 sets.
typedef struct Unk0217c730 {
    /* 00 */ Unk0215a6c0 mUnk_00;
    /* 0c */ u8 mUnk_0c[0x18];
    /* 24 */ u16 mUnk_24;
    /* 26 */ u8 mUnk_26[8];
    /* 2e */ u16 mUnk_2e;
} Unk0217c730;

extern Unk0217c730 data_0217c730;

extern u16 data_0215a584;
extern Unk0215a6c0 data_0215a6c0;
extern Unk0215a6c0 data_0215a6cc;

void func_02105214(void);
void func_021051d4(Unk020edb8c *p0, Unk020f40dc *p1);
void func_0210515c(s32 a);
void func_02104ff8(void);
void func_02104f84(s32 a);
void func_02104f58(Unk02104c68 *p);
void func_02104f14(Unk02104c68 *p);
void func_02104ee0(Unk02104c68 *p, s32 a);
void func_02104e58(Unk02104c68 *p);
void func_02104d78(Unk020edb8c *p0, Unk02104c68 *p1);
s32 func_02104c68(Unk020edb8c *p0, Unk02104c68 *p1);
void func_02104a0c(Unk02104c68 *p);
