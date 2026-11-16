#pragma once

#include "types.h"

typedef struct Unk021cca74 {
    /* 00 */ struct OamRange *mResource;
    /* 04 */ u8 field4[8];
    /* 0c */ u32 fieldC;
    /* 10 */ u16 mX;
    /* 12 */ u16 mY;
    /* 14 */ u16 field14[2];
    /* 18 */ u8 field18;
    /* 19 */ u8 field19;
    /* 1a */ u8 mOffset;
    /* 1b */ u8 field1B;
    /* 1c */ u8 field1C;
    /* 1d */ u8 field1D;
    /* 1e */ u8 field1E;
} Unk021cca74;

void func_ov003_021cca74(s32 offset);
void func_ov003_021cca9c(s32 a, u16 *b);
int func_ov003_021ccb1c(int a);
int func_ov003_021ccb50(void);
void func_ov003_021ccbbc(void);
void func_ov003_021ccc08(int a);
void func_ov003_021ccc24(s32 param_1);
void func_ov003_021ccc90(void);
void func_ov003_021ccd18(void);
void func_ov003_021cce38(void);
void func_ov003_021cce48(void);
void func_ov003_021cce58(s32 offset);
u8 func_ov003_021cce60(void);
u8 func_ov003_021cce6c(void);
