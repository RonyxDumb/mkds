#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

u16 MenuGetInputSlotNewBits(InputSlot *slot, u32 mask);
u16 MenuGetNewBits(u32 slotIndex, u32 mask);
