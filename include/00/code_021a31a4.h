#pragma once

#include "types.h"

typedef struct Unk021b5dd0 {
    /* 000 */ u8 pad_000[0x610];
    /* 610 */ u16 mUnk_610;
    /* 612 */ u8 pad_612[2];
} Unk021b5dd0;

extern Unk021b5dd0 *data_ov000_021b5dd0;

void func_ov000_021a31a4(Unk021b5dd0 *state);
