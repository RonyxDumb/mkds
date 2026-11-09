#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

BOOL MenuIsPairRecentlyLost(InputSlotPair *pair);
BOOL MenuIsPairNew(InputSlotPair *pair);
BOOL MenuIsPairNewUnlessRecentlyLost(InputSlotPair *pair);
BOOL MenuIsSlotPairNew(u32 slotIndex);
