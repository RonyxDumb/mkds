#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

u32 ScrollListGetSlotPairY(u32 slot);
unsigned int ScrollListGetPairY(InputSlotPair *pair);
u32 ScrollListGetSlotPairX(u32 slot);
unsigned int ScrollListGetPairX(InputSlotPair *pair);
