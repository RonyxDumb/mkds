#pragma once

#include "types.h"

typedef struct Unk0219887c {
    /* 00 */ u8 mUnk_00[0x40];
    /* 40 */ u8 *mUnk_40;
} Unk0219887c;

u8 *func_ov000_0219887c(Unk0219887c *object);
void func_ov000_021988a4(Unk0219887c *param_1, void *param_2);
void func_ov000_021988d4(int param_1, u32 param_2);
u32 func_ov000_021988d8(u32 *param_1);
int func_ov000_021988dc(int param_1);
u16 func_ov000_021988e4(void *param_1);
