#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

u32 title_input_isValidPenDownEventById(u32 slotIndex);
u32 title_spi_isValidPenDownEvent(InputSlotPair *inputSlotPair);
u32 title_spi_isPenDownEvent(InputSlotPair *inputSlotPair);
u32 title_spi_isPenReleaseTimeout(InputSlotPair *inputSlotPair);
