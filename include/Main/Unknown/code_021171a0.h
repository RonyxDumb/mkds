#pragma once

#include "types.h"

typedef struct Unk02021dc8 Unk02021dc8;

typedef struct LayoutEntryTable LayoutEntryTable;

void QueueKartIcon(s32 iconIndex, Unk02021dc8 *destinationNcer, LayoutEntryTable *destinationBncl,
                   u32 destinationBnclIndex, u16 paletteIndex, s32 f);
