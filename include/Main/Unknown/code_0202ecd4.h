#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

u16 ScrollListGetNewBits(u32 slotIndex, u32 mask);
u16 ScrollListGetInputSlotNewBits(InputSlot *slot, u32 mask);
void AdvanceScrollListRightColumnTimer(void);
void SetScrollListRightColumnHighBits(s32 highBits);
void PlaceScrollListCursor(void);
