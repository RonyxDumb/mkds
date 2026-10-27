#pragma once

#include "types.h"
#include "code_0212da38.h" // Unk02017328

// data_0217d048 is addressed in rows of twelve bytes; func_0210bfbc and func_0210c0bc address the
// container of one of those rows.
typedef struct Unk0210bfbc {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ Unk02017328 mUnk_0c;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u8 mUnk_1c[0xc];
    /* 28 */ u32 mUnk_28;
    /* 2c */ void (*mUnk_2c)(void *a, void *b, u32 c);
    /* 30 */ void (*mUnk_30)(void *a, void *b, void *c);
    /* 34 */ u16 mUnk_34;
    /* 36 */ u8 mUnk_36[2];
    /* 38 */ u32 mUnk_38;
} Unk0210bfbc;

// Returned by func_0210e128 and passed to func_0210bcf4; func_0210c084 writes its byte at 0x19.
// func_0210bf24 subtracts one Unk02017328 from mUnk_10 to reach the Unk0210bfbc holding it.
typedef struct Unk0210bf24 {
    /* 00 */ void *mUnk_00;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ u8 mUnk_08[8];
    /* 10 */ Unk02017328 *mUnk_10;
    /* 14 */ s16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 mUnk_19;
    /* 1a */ u8 mUnk_1a;
} Unk0210bf24;

// What func_0212d580 points at; only its byte at 4 is read.
typedef struct Unk0212d580 {
    /* 0 */ u8 mUnk_00[4];
    /* 4 */ u8 mUnk_04;
} Unk0212d580;

// Held on the stack by func_0210bcf4 and func_0210ca4c and passed to the three functions
// data_0217d018, data_0217d014 and data_0217d01c point at.
typedef struct Unk0210bcf4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[8];
    /* 10 */ u32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
} Unk0210bcf4;

void func_0210c0bc(Unk0210bfbc *p);
void func_0210c084(Unk0210bf24 *p, u32 b);
void func_0210bfbc(Unk0210bfbc *p);
void func_0210bf24(u32 a, u32 b, u32 c, u32 d);
u32 func_0210bee8(u32 a, u32 b, u32 c, u32 d, u32 e);
u32 func_0210bcf4(u32 a, u32 b, u32 c, u32 d, u32 e);
