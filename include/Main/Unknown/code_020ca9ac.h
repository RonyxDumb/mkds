#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

u16 EmblemChoisesGetInputSlotNewBits(InputSlot *slot, u32 mask);
u16 EmblemChoisesGetNewBits(u32 slotIndex, u32 mask);
