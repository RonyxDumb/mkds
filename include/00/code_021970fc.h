#pragma once

#include "types.h"
#include "00/unk_021b3000.h"
#include "00/code_021970e4.h"
#include "code_02135014.h"
#include "code_02139f70.h"

typedef struct Unk021b3c88 {
    /* 00 */ s8 mUnk_00[0x100];
} Unk021b3c88;

extern const Unk021b3c88 data_ov000_021b3c88;
extern s32 data_ov000_021b4e70;
extern s8 data_ov000_021b5084[];
extern const u8 data_ov000_021b3e04[];
extern const u8 data_ov000_021b3e00[];

const s8 *func_ov000_021970fc(const s8 *text, const u8 *key);
void func_ov000_02197190(u32 a, s8 *b);
