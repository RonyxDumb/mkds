#pragma once

#include "types.h"

// Two of these sit at data_021755a8 and data_021755b4; func_020390f0 steps one.
typedef struct Unk021755a8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ s16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
} Unk021755a8;

extern Unk021755a8 data_021755a8;
extern Unk021755a8 data_021755b4;

void func_02039044(void);
void func_0203907c(void);
void func_020390f0(Unk021755a8 *a);
