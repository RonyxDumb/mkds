#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

BOOL MultiSelectNSIsSlotPairNew(u32 slotIndex);
BOOL MultiSelectNSIsPairNewUnlessLost(InputSlotPair *pair);
BOOL MultiSelectNSIsPairNew(InputSlotPair *pair);
BOOL MultiSelectNSIsPairRecentlyLost(InputSlotPair *pair);
