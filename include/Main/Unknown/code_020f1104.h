#pragma once

#include "types.h"

typedef struct ItemKouraR ItemKouraR;

void AddItemKouraRTowardKartToVelocity(ItemKouraR *item);
void SetItemKouraRKartItems(ItemKouraR *item, int kartIndex);
void SetItemKouraRKartItemsAndClearTowardKartVelocity(ItemKouraR *item, int kartIndex);
