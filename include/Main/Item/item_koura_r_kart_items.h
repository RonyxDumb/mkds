#pragma once

#include "types.h"

typedef struct ItemKouraR ItemKouraR;

void AddItemKouraRTowardKartToVelocity(ItemKouraR *item);
void SetItemKouraRKartItems(ItemKouraR *item, int kartIndex);
void SetItemKouraRKartItemsAndClearTowardKartVelocity(ItemKouraR *item, int kartIndex);

BOOL TrySetItemKouraRNearestKartItems(ItemKouraR *item, u32 checkRank);

u32 TrySetItemKouraRKartItemsByFrame(ItemKouraR *item, u32 checkRank);

BOOL SteerItemKouraRToKart(ItemKouraR *item, s32 speed, s32 gain, s32 flag);
int TrySetItemKouraRKartItems(ItemKouraR *item, int kartIndex, s32 maxDistanceSquared, u32 checkRank);

void ResetItemKouraRKartItems(ItemKouraR *item);
