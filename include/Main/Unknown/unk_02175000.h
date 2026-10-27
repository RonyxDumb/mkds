#pragma once

#include "types.h"

// Object behind data_021759d0; the 0x14 bytes at 0x2a are the source of a block move into data_0217aa08.
typedef struct Unk021759d0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x18];
    /* 20 */ s32 mUnk_20;
    /* 24 */ u8 mUnk_24[0x6];
    /* 2a */ u8 mUnk_2a[0x14];
} Unk021759d0;

// Objects whose layout isn't known yet.
extern u8 data_021755a0[];
extern u8 data_021755a8[];
extern u8 data_021755b4[];
extern u8 data_02175624[];
extern u8 data_021759c8[];
extern u8 data_021759cc[];
extern Unk021759d0 *data_021759d0;
extern vu16 data_021758e8[];
extern vu16 data_02175928[];
extern u8 data_02175ec0[];
extern u8 data_02175dd8[];
