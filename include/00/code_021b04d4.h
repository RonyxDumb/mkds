#pragma once

#include "types.h"
#include "00/unk_021b6380.h"
#include "code_0200dc3c.h"
#include "code_0200e0ec.h" // Unk0200db5c
#include "code_0214d018.h"
#include "00/code_021a91b4.h"
#include "Main/Unknown/unk_0216f000.h"
#include "00/code_021af550.h"
#include "00/unk_021b6000.h"

// Object linked from Unk0200db5c.mUnk_a4.
typedef struct Unk021b04f8 {
    /* 00 */ Unk0200db5c *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08;
} Unk021b04f8;

extern Unk021b69dc data_ov000_021b69dc[8];
extern u32 data_ov000_021b637c;
extern u32 data_ov000_021b638c;
extern u32 data_ov000_021b6390;

void func_ov000_021b04d4(void);
void func_ov000_021b04f8(u32 a);
