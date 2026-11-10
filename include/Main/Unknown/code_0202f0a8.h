#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

u32 ScrollListIsSlotPairNew(u32 slotIndex);
u32 ScrollListIsPairNewUnlessLost(InputSlotPair *pair);
u32 ScrollListIsPairNew(InputSlotPair *pair);
void CallScrollListCallback(s32 action, s32 slot, s32 row, s32 selectedSlot);
