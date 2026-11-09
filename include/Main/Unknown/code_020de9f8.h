#pragma once

#include "types.h"

typedef struct ItemBox ItemBox;
typedef struct Kart Kart;

u8 CollideKartWithItemBox(ItemBox *itemBox, Kart *kart, void *firstResponsePtr, u8 *secondResponsePtr);
u32 GetItemBoxMaxGroupDistance(ItemBox *itemBox);
