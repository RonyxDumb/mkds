#pragma once

#include "types.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"

// 0x18 bytes. Growable array: count, capacity, element size, growth step, per-element callback, element data.
typedef struct Unk0218dc94 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ void (*mUnk_10)(void *);
    /* 14 */ u8 *mUnk_14;
} Unk0218dc94;

void *func_ov000_0218dc94(s32 param_1, s32 param_2, void (*param_3)(void *));
