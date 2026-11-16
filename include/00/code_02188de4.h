#pragma once

#include "types.h"

struct Unk02188ec0;

// Bytes handed out by func_ov000_02188de4: a leading byte, then the payload.
typedef struct Unk02188de4 {
    /* 00 */ u8 field0;
    /* 01 */ u8 field1;
    /* 02 */ u8 field2[0x50];
} Unk02188de4;

// One of the 0x100-byte entries at the start of Unk02188ec0.
typedef struct Unk02188db0 {
    /* 00 */ u8 pad_00[0x40];
    /* 40 */ u8 field40[0x20];
    /* 60 */ u8 field60[0x20];
    /* 80 */ u8 field80[0x40];
    /* c0 */ u8 fieldC0[4];
    /* c4 */ u8 fieldC4[4];
    /* c8 */ u8 fieldC8[4];
    /* cc */ u8 fieldCC[4];
    /* d0 */ u8 fieldD0;
    /* d1 */ u8 fieldD1[0x14];
    /* e5 */ u8 pad_e5;
    /* e6 */ u8 fieldE6 : 2;
    /* e7 */ u8 fieldE7;
    /* e8 */ u8 pad_e8[0x18];
} Unk02188db0;

// Declared here until the code that defines it is decompiled.

u32 func_ov000_02188de4(struct Unk02188ec0 *object, u32 a, Unk02188de4 *out);
