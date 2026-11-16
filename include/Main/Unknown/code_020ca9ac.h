#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

u16 echoi_pad_isSetPadTrig(InputSlot *slot, u32 mask);
u16 echoi_input_isSetPadTrigById(u32 slotIndex, u32 mask);
