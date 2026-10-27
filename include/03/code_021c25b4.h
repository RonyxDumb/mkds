#pragma once

#include "types.h"
#include "03/code_021d1d88.h"

typedef struct Unk021da190 {
    /* 00 */ u8 pad_00[0x60];
    /* 60 */ Unk021d1d88 *mUnk_60;
} Unk021da190;

extern Unk021da190 *data_ov003_021da190;

void func_ov003_021c25b4(void);
