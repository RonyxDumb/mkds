#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

u16 rchoi_pad_isSetPadTrig(InputSlot *slot, u32 mask);
u16 rchoi_input_isSetPadTrigById(s32 slotIndex, u32 mask);
