#pragma once

#include "types.h"
#include "00/unk_021b5000.h"

extern u8 data_ov000_021b07bc[];
extern u8 data_ov000_021b07c4[];

typedef struct Unk021a5a78 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk021a5a78;

void func_ov000_021a5948(const void *a, const u8 *b, u32 c);
void func_ov000_021a5a78(Unk021a5a78 *a, void (*b)(Unk021a586c *));
