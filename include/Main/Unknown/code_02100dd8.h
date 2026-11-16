#pragma once

#include "types.h"

typedef struct Unk02100dd8 {
    /* 00 */ u8 field0[0x19c];
    /* 19c */ u32 field19C;
} Unk02100dd8;

void EnterItemTeresaState3(Unk02100dd8 *teresa);
