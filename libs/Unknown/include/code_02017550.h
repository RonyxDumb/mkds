#pragma once

#include "types.h"
#include "code_0212da38.h" // Unk02017328

// Object with an Unk02017328 at 0x0c, initialised with link offset 4; mUnk_18 and mUnk_1c bound the range func_02017640
// tests an address against.
typedef struct Unk02017584 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[8];
    /* 0c */ Unk02017328 mUnk_0c;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
} Unk02017584;

extern u32 data_02173264;
extern Unk02017328 data_02173268;

void *func_02017550(void *a);
void func_02017568(Unk02017584 *a);
void func_02017584(Unk02017584 *a, u32 b, u32 c, u32 d, u16 e);
Unk02017328 *func_02017614(u32 a);
Unk02017584 *func_02017640(Unk02017328 *a, u32 b);
