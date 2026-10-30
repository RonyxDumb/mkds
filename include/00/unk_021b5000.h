#pragma once

#include "00/code_0219b8a8.h"
#include "00/code_0219c384.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"
#include "00/code_0219de4c.h"
#include "types.h"
#include "00/code_021a31a4.h"

// Objects whose layout isn't known yet.
extern u8 data_ov000_021b5dec[];
extern u8 data_ov000_021b5df0[];
extern u8 data_ov000_021b5df4[];
extern u8 data_ov000_021b5f50[];
extern u8 data_ov000_021b5f98[];
extern u8 data_ov000_021b5fdc[];

extern u8 data_ov000_021b5f54[];
extern u8 data_ov000_021b5678[0x20];

// Four bytes at data_ov000_021b5668; data_ov000_021b5670 points at them.
typedef struct Unk021b5668 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
} Unk021b5668;

extern Unk021b5668 data_ov000_021b5668;
extern Unk021b5668 *data_ov000_021b5670;
extern void *data_ov000_021b5674;
