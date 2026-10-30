#pragma once

#include "types.h"
#include "00/unk_021b5000.h"
#include "00/unk_021b6000.h"
#include "00/code_021af550.h"
#include "00/code_021b04d4.h"

// State of the generator that func_ov000_021b02fc seeds.
typedef struct Unk021b63e0 {
    /* 00 */ u64 mUnk_00;
    /* 08 */ u64 mUnk_08;
    /* 10 */ u64 mUnk_10;
} Unk021b63e0;

extern Unk021b63e0 data_ov000_021b63e0;
extern s32 data_ov000_021b6398;
extern u32 data_ov000_021b63bc;
extern void (*data_ov000_021b6384)(void);
extern u32 (*data_ov000_021b6388)(void);
extern u8 data_ov000_021b73a0[];

// Thread entry functions (not lifted yet).
void func_ov000_021ae3a4(void *param_1);
void func_ov000_021ad898(void *param_1);

void func_ov000_021b02fc(Unk021b5fa8 *param_1);
