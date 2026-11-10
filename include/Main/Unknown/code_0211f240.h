#pragma once

#include "types.h"

void InitMenuNop(void);
void QueueTrophyIcon(int iconIndex, int paletteIndex, void *cells, void *cellLayout, u32 destIndex, u16 paletteSlot,
                     int queueSelector);
