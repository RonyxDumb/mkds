#pragma once

#include "types.h"

// The 0x14-byte objects of data_0215ce70 and data_0215ce0c.
typedef struct Unk0215ce70 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk0215ce70;

extern Unk0215ce70 data_0215ce0c[];

extern Unk0215ce70 data_0215ce70[];

// The object at data_0216dc0c->mUnk_0c.
typedef struct Unk0216dc0c_0c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
} Unk0216dc0c_0c;

typedef struct Unk0216dc0c {
    /* 00 */ u8 mUnk_00[0x0c];
    /* 0c */ Unk0216dc0c_0c *mUnk_0c;
} Unk0216dc0c;

extern Unk0216dc0c data_0216dc0c;

u16 func_0211d650(void);
void func_0211d66c(void);
void func_0211d844(s32 a);
void func_0211d910(s32 a);
void func_0211d9dc(void);
void func_0211db30(Unk0215ce70 *a, s32 b);
