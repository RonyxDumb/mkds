#pragma once

#include "types.h"
#include "00/code_0218d000.h"
#include "00/code_0218dc44.h"
#include "00/code_02196000.h"
#include "00/code_02196ae0.h"

// Entry of the list behind data_ov000_021b4e5c; the function at 0x18 takes the arguments of the entry's type.
typedef union Unk021969d8Func {
    void (*mUnk_00)(u32 a, u32 b, s32 c, const u8 *d, u32 e);
    void (*mUnk_01)(u32 a, u32 b, u32 c, u32 d, s32 e, s32 f, const u8 *g, s32 h, u32 i);
    void (*mUnk_02)(u32 a, u32 b, u32 c, u32 d, s32 e, s32 f, u32 g);
    void (*mUnk_03)(u32 a, u32 b, s32 c, u32 d);
} Unk021969d8Func;

typedef struct Unk021969d8Entry {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ Unk021969d8Func mUnk_18;
} Unk021969d8Entry;

typedef struct Unk02196960Key {
    /* 00 */ u8 mUnk_00[0x10];
} Unk02196960Key;

extern void *data_ov000_021b4e5c;
extern u8 *data_ov000_021b3b30;
extern Unk02196960Key data_ov000_021b3b78;
extern u8 data_ov000_021b3b88[];
extern u8 data_ov000_021b3b98[];

void func_ov000_02196960(void);
void func_ov000_021969d8(s32 a, s32 b, s32 c, const u8 *d, s32 e);
s32 func_ov000_02196a84(u8 *a, s32 b);
