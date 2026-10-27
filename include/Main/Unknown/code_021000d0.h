#pragma once

#include "types.h"

// Row of the table searched by func_021000d0 and func_02100138.
typedef struct Unk0216b288 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
} Unk0216b288;

extern Unk0216b288 data_0216b288[];

// Object behind Unk0216b288::mUnk_04.
typedef struct Unk021000d0 {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ void *mUnk_24;
    /* 28 */ u8 mUnk_28[0x8];
    /* 30 */ void *mUnk_30;
} Unk021000d0;

void *func_02100138(u32 param_1);
void *func_021000d0(u32 param_1);
