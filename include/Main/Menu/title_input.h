#pragma once

#include "types.h"
#include "Main/Menu/data_02175628.h"

unsigned int TitleGetPairHasPair(InputSlotPair *pair);

typedef struct InputSlot InputSlot;

u16 TitleGetNewBits(u32 slotIndex, u32 mask);
u16 TitleGetInputSlotNewBits(InputSlot *slot, u32 mask);

unsigned int GetTitleInputSlot(void);

u32 TitleMenuInputReturnArgumentWrapper(u32 value);
