#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

u16 TitleGetNewBits(u32 slotIndex, u32 mask);
u16 TitleGetInputSlotNewBits(InputSlot *slot, u32 mask);
