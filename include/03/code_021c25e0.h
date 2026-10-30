#pragma once

#include "types.h"

typedef struct Unk021da194 {
    /* 00000 */ u8 pad_00000[0x1e280];
    /* 1e280 */ u8 mUnk_1e280[0x18];
    /* 1e298 */ void (*mUnk_1e298)(s32 a);
    /* 1e29c */ u32 mUnk_1e29c;
    /* 1e2a0 */ u8 mUnk_1e2a0;
    /* 1e2a1 */ u8 mUnk_1e2a1;
} Unk021da194;

extern Unk021da194 *data_ov003_021da194;

void func_ov003_021c25e0(u32 a);

// Not decompiled yet.
void func_ov003_021d0e9c(u8 *a, u8 *b);
void func_ov003_021d0ee0(void);
