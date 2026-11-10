#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

void PlaceScrollListScrollEntry(void);
void AdvanceScrollListInput(void);
u32 ScrollListSlotHasPairOrLost(u32 slotIndex);
u32 ScrollListHasPairOrLost(InputSlotPair *pair);
