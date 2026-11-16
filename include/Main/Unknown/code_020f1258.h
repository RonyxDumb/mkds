#pragma once

#include "types.h"

typedef struct ItemKouraR ItemKouraR;

BOOL sub_20F14A0(ItemKouraR *item, s32 speed, s32 gain, s32 d);
int TrySetItemKouraRKartItems(ItemKouraR *item, int kartIndex, s32 maxDistanceSquared, u32 checkRank);
