#pragma once

#include "types.h"

typedef struct Unk02188ec0 Unk02188ec0;

// Object behind data_ov000_021b4d0c, 0x58 bytes.
typedef struct Unk0218a064 {
    /* 00 */ u8 pad_00[4];
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u32 field1C;
    /* 20 */ u32 field20;
    /* 24 */ u8 pad_24[0x34];
} Unk0218a064;

void func_ov000_0218a064(const u32 *a, Unk02188ec0 *object, Unk0218a064 *out);
