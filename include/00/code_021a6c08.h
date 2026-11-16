#pragma once

#include "types.h"

typedef struct Unk021a6bb4 {
    /* 00 */ u8 field0[6];
    /* 06 */ u16 field6;
    /* 08 */ u8 field8[0x10];
    /* 18 */ u8 field18[6];
    /* 1e */ u8 field1E[0xe];
    /* 2c */ u8 field2C[1];
} Unk021a6bb4;

void func_ov000_021a6c08(u8 c);
s32 func_ov000_021a6c68(void);
u8 func_ov000_021a6c90(void);
