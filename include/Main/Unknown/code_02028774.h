#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

BOOL SelectKartIsSlotPairNew(u32 slot);
BOOL SelectKartIsPairNewUnlessLost(InputSlotPair *pair);
BOOL SelectKartIsPairNew(InputSlotPair *pair);
BOOL SelectKartIsPairRecentlyLost(InputSlotPair *pair);
