#pragma once

#include "types.h"

// Object behind data_ov000_021b4d10.
typedef struct Unk021884e4 {
    /* 00 */ void *(*field0)();
    /* 04 */ void (*field4)();
    /* 08 */ u8 field8;
    /* 09 */ u8 field9;
    /* 0a */ u8 fieldA;
    /* 0b */ u8 fieldB;
    /* 0c */ u32 fieldC;
    /* 10 */ u8 pad_10[4];
    /* 14 */ u8 field14;
    /* 15 */ u8 field15;
    /* 16 */ u8 field16;
    /* 17 */ u8 field17;
} Unk021884e4;

u8 func_ov000_021884d8(u8 value);
void func_ov000_021884e4(u8 value);
u32 func_ov000_021884fc(void);
void func_ov000_02188508(u32 arg0);
u8 func_ov000_02188528(void);
void func_ov000_02188534(u8 a);
u32 func_ov000_02188584(u32 a);
void func_ov000_021885ec(void);
