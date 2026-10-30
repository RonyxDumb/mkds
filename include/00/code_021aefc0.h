#pragma once

#include "types.h"
#include "00/code_021ae0c4.h"
#include "00/code_021ae314.h"

typedef struct Unk021af1e4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk021af1e4;

extern Unk0200db5c data_ov000_021b661c;
extern u32 data_ov000_021b4c24;

void func_ov000_021aefc0(Unk021a998c *param_1, u32 param_2, u16 param_3);
u32 func_ov000_021af010(u32 param_1);
void func_ov000_021af030(const Unk021ae87c *param_1, Unk021a998c *param_2);
Unk021a998c *func_ov000_021af090(const Unk021ae3f0 *param_1, const Unk021ae87c *param_2);
u32 func_ov000_021af0dc(const Unk021ae3f0 *param_1, const Unk021ae87c *param_2, const Unk021a998c *param_3);
Unk021a998c *func_ov000_021af15c(const Unk021ae3f0 *param_1, const Unk021ae87c *param_2);
void func_ov000_021af1e4(Unk021ae3f0 *param_1, Unk021af1e4 *param_2, u32 param_3);
