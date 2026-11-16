#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart

typedef struct Unk0206390c_04 {
    /* 00 */ u8 field0[4];
    /* 04 */ u8 *field4;
} Unk0206390c_04;

typedef struct Unk0206390c {
    /* 00 */ u8 field0[4];
    /* 04 */ Unk0206390c_04 *field4;
    /* 08 */ u32 field8;
    /* 0c */ u8 fieldC[0x18];
    /* 24 */ s32 field24;
    /* 28 */ u8 field28[0x6a];
    /* 92 */ u8 field92;
    /* 93 */ u8 field93[0x1b];
    /* ae */ u8 fieldAE;
} Unk0206390c;

extern const u32 aKilleritem[];

void driver_killerItemRenderObjCallback(Unk0206390c *renderState);
void func_02063a68(Kart *kart);
void func_02063ad0(Kart *kart);
