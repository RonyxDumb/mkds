#pragma once

#include "types.h"

// Object whose member at 0x4 func_02111324 writes.
typedef struct Unk02111324 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk02111324;

void func_02111324(Unk02111324 *a);
void *func_02111318(void);
void *func_0211130c(void);
