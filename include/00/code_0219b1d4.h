#pragma once

#include "types.h"

// Entry of the list at data_ov000_021b52c4, 0x40 bytes.
typedef struct Unk0219b1d4 {
    /* 00 */ s32 mDescriptor;
    /* 04 */ s32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ u32 field14[3];
    /* 20 */ s32 field20;
    /* 24 */ s32 field24;
    /* 28 */ u32 field28;
    /* 2c */ u32 field2C;
    /* 30 */ u16 field30;
    /* 32 */ u8 field32;
    /* 33 */ u8 field33;
    /* 34 */ void (*field34)(s32 a, void *b);
    /* 38 */ void (*field38)(s32 a, s32 b, void *c, void *d);
    /* 3c */ void *field3C;
} Unk0219b1d4;

void func_ov000_0219b1d4(Unk0219b1d4 *object);
