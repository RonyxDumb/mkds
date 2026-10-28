#pragma once

#include "types.h"

struct Unk02021dc8;
struct Unk020b4934;
struct Unk020b4a44;

// Object behind data_ov000_021b4c88; func_ov000_0218554c fills 0x34 to 0x48.
typedef struct Unk021b4c88 {
    /* 00 */ u8 mUnk_00[0x34];
    /* 34 */ struct Unk02021dc8 *mUnk_34;
    /* 38 */ struct Unk020b4934 *mUnk_38;
    /* 3c */ struct Unk020b4a44 *mUnk_3c;
    /* 40 */ void *mUnk_40;
    /* 44 */ u8 mUnk_44[4];
    /* 48 */ void *mUnk_48;
} Unk021b4c88;

extern Unk021b4c88 *data_ov000_021b4c88;

void func_ov000_021855f8(void);
