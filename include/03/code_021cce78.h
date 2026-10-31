#pragma once

#include "types.h"
#include "03/code_021cca74.h"
#include "03/types_021da26c.h"
#include "03/unk_021d6000.h"
#include "03/unk_021da000.h"
#include "code_02142eac.h"

// Object found through the pointers at 0x10 of an Unk021ccf30.
typedef struct Unk021ccf30_10 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u8 mUnk_04[6];
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ u8 mUnk_0c[0x20];
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u8 mUnk_2e[0xe];
    /* 3c */ u16 mUnk_3c;
} Unk021ccf30_10;

typedef struct Unk021ccf30 {
    /* 00 */ u8 mUnk_00[0xe];
    /* 0e */ u16 mUnk_0e;
    /* 10 */ Unk021ccf30_10 *mUnk_10[0x10];
    /* 50 */ u16 mUnk_50[0x10];
} Unk021ccf30;

extern u8 data_ov003_021d662c[];
extern u8 data_ov003_021d6634[];

void func_ov003_021cce78(void);
void func_ov003_021ccea4(u32 a, u32 b, u16 c, u16 d, u32 e);
void func_ov003_021ccf30(Unk021ccf30 *a);
void func_ov003_021cd080(Unk021425e8 *a);
