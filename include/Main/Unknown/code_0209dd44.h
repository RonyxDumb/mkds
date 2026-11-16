#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_0209d694.h" // SunFireball

typedef struct ItemObject ItemObject;

u8 sfsn_onItemCollide(SunFireball *sunFireball, ItemObject *itemObject, u8 *c, u8 *d);
u8 sfsn_onDriverCollide(SunFireball *sunFireball, Kart *kart, u8 *c, u8 *d);
