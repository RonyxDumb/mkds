#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

u32 ChoisesSIsSlotPairNew(s32 slotIndex);
u32 ChoisesSIsPairNewUnlessRecentlyLost(InputSlotPair *inputSlotPair);
u32 ChoisesSIsPairNew(InputSlotPair *inputSlotPair);
u32 ChoisesSIsPairRecentlyLost(InputSlotPair *inputSlotPair);
