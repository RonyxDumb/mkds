#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

u32 TitleIsSlotPairNew(u32 slotIndex);
u32 TitleIsPairNewUnlessRecentlyLost(InputSlotPair *inputSlotPair);
u32 TitleIsPairNew(InputSlotPair *inputSlotPair);
u32 TitleIsPairRecentlyLost(InputSlotPair *inputSlotPair);
