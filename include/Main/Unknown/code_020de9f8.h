#pragma once

#include "types.h"

typedef struct ItemBox ItemBox;

// Second argument of ibox_onDriverCollide: a halfword at 0x74 and a word at 0x7c.
typedef struct Unk020dea50_1 {
    /* 00 */ u8 field0[0x74];
    /* 74 */ u16 field74;
    /* 76 */ u8 field76[6];
    /* 7c */ u32 field7C;
} Unk020dea50_1;

u8 ibox_onDriverCollide(ItemBox *itemBox, Unk020dea50_1 *kart, void *c, u8 *d);
u32 sub_20DE9F8(ItemBox *itemBox);
