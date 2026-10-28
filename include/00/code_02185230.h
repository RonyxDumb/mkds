#pragma once

#include "types.h"

struct Unk02021dc8;
struct Unk020b4934;
struct Unk020b4a44;

// Object behind data_ov000_021b4c84; func_ov000_021851a0 fills 0x20 to 0x30.
typedef struct Unk021b4c84 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x18];
    /* 20 */ struct Unk02021dc8 *mUnk_20;
    /* 24 */ struct Unk020b4934 *mUnk_24;
    /* 28 */ struct Unk020b4a44 *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ void *mUnk_30;
} Unk021b4c84;

extern Unk021b4c84 *data_ov000_021b4c84;

void func_ov000_02185230(void);
