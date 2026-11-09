#pragma once

#include "types.h"

BOOL MenuIsPairRecentlyLost(u16 *pair);
BOOL MenuIsPairNew(u16 *pair);
BOOL MenuIsPairNewUnlessRecentlyLost(u16 *pair);
BOOL MenuIsSlotPairNew(u32 slotIndex);
