#pragma once

#include "types.h"
#include "Main/System/input_slots.h"

u32 MenuGetSlotPairY(u32 slotIndex);

unsigned int MenuGetPairY(InputSlotPair *pairAddress);

u32 MenuGetSlotPairX(u32 slotIndex);

unsigned int MenuGetPairX(InputSlotPair *pairAddress);

typedef struct InputSlotPair InputSlotPair;

BOOL MenuIsPairRecentlyLost(InputSlotPair *pair);
BOOL MenuIsPairNew(InputSlotPair *pair);
BOOL MenuIsPairNewUnlessRecentlyLost(InputSlotPair *pair);
BOOL MenuIsSlotPairNew(u32 slotIndex);
