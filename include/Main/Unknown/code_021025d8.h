#pragma once

#include "types.h"

typedef struct Unk021025d8 {
    /* 00 */ u8 field0[0x12c];
    /* 12c */ u8 field12C[0x14];
    /* 140 */ u32 field140;
    /* 144 */ u32 field144;
    /* 148 */ u8 field148[0xc];
    /* 154 */ u32 field154;
    /* 158 */ u32 field158;
    /* 15c */ u32 field15C;
    /* 160 */ u32 field160;
    /* 164 */ u8 field164[0xe8];
    /* 24c */ u32 field24C;
    /* 250 */ u32 field250;
    /* 254 */ u32 field254;
    /* 258 */ u32 field258;
    /* 25c */ u32 field25C;
    /* 260 */ u32 field260;
    /* 264 */ u32 field264;
    /* 268 */ u32 field268;
    /* 26c */ u32 field26C;
    /* 270 */ u32 field270;
} Unk021025d8;

void ittrsa_21025D8(Unk021025d8 *teresa);
typedef struct Unk02102668 {
    /* 00 */ u8 field0[0x170];
    /* 170 */ u32 field170;
} Unk02102668;

void func_02102668(Unk02102668 *inUse);
