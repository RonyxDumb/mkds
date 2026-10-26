#pragma once

#include "types.h"

// Header found by func_02013b20: a count at 0x00, an s16 at 0x04 and at 0x06 the offset of the table.
typedef struct Unk02013b3c_e {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk02013b3c_e;

// Entry of the table returned by func_02013b3c.
typedef struct Unk02013b3c_t {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk02013b3c_t;

Unk02013b3c_t *func_02013b3c(const void *a, u16 b, u32 c);
