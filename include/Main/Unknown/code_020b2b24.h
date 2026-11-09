#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

u16 ChoisesSGetInputSlotNewBits(InputSlot *slot, u32 mask);
u16 ChoisesSGetNewBits(s32 slotIndex, u32 mask);
