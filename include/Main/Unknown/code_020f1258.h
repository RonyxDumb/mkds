#pragma once

#include "types.h"

typedef struct ItemKouraR ItemKouraR;

BOOL SteerItemKouraRToKart(ItemKouraR *item, s32 speed, s32 gain, s32 flag);
int TrySetItemKouraRKartItems(ItemKouraR *item, int kartIndex, s32 maxDistanceSquared, u32 checkRank);
