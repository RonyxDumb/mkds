#pragma once

#include "types.h"
#include "Main/Unknown/code_020e0680.h"

void UpdateChoropuState7(Unk020e2f0c *choropu);
u8 CollideKartWithChoropu(Unk020e2f0c *choropu, Kart *kart, u8 *c, u8 *d);
u8 CollideItemObjectWithChoropu(Unk020e2f0c *choropu, ItemObject *itemObject, u8 *c, u8 *d);
