#pragma once

#include "00/code_0219b8a8.h"
#include "00/code_0219c384.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"
#include "00/code_0219de4c.h"
#include "types.h"
#include "00/code_021a31a4.h"
#include "00/code_021a377c.h"

// One element of the table at data_ov000_021b5dfc.
typedef struct Unk021b5dfc {
    /* 0 */ u32 mUnk_00;
} Unk021b5dfc;

// Objects whose layout isn't known yet.
extern u8 data_ov000_021b5dec[];
extern u8 data_ov000_021b5df0[];
extern s32 data_ov000_021b5df8;
extern Unk021b5dfc data_ov000_021b5dfc[];
extern u8 data_ov000_021b5f50[];
extern u8 data_ov000_021b5f98[];
extern u8 data_ov000_021b5fdc[];

extern u8 data_ov000_021b5f54[];
extern u8 data_ov000_021b5678[0x20];

// Four bytes at data_ov000_021b5668.
typedef struct Unk021b5668 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
} Unk021b5668;

extern Unk021b5668 data_ov000_021b5668;

typedef struct Unk021b5670 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u64 mUnk_10;
    /* 18 */ u64 mUnk_18;
} Unk021b5670;

extern Unk021b5670 *data_ov000_021b5670;
extern void *data_ov000_021b5674;
