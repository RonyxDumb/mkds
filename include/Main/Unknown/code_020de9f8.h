#pragma once

#include "types.h"

typedef struct ItemBox ItemBox;
typedef struct Kart Kart;

u8 CollideKartWithItemBox(ItemBox *itemBox, Kart *kart, void *c, u8 *d);
u32 func_020de9f8(ItemBox *itemBox);
