#pragma once

#include "types.h"

typedef struct Unk020e49c0 {
    /* 00 */ u8 field0[0x2];
    /* 02 */ u16 field2;
    /* 04 */ u32 field4;
    /* 08 */ u8 field8[0x4];
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u8 field1C[0x4a];
    /* 66 */ u16 field66;
    /* 68 */ u8 field68[0x50];
    /* b8 */ u32 fieldB8;
    /* bc */ u8 fieldBC[0x4];
    /* c0 */ u32 fieldC0;
} Unk020e49c0;

void puku_state3Init(Unk020e49c0 *pukupuku);
