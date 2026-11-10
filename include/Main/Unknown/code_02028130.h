#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

int AdvanceSelectKart(void);
u16 SelectKartGetNewBits(u32 slotIndex, u32 mask);
u16 SelectKartGetInputSlotNewBits(InputSlot *inputSlot, u32 mask);
