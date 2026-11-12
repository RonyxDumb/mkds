#pragma once

#include "types.h"
#include "03/Graphics/nce_oam.h"

u8 GetOamRangeEntryCount(OamRange *range);
OamEntry *GetOamRangeEntry(OamRange *range, int index);
