#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Item/item_in_use.h" // KartModelsEntry

void *GetKartModelResMdl(u16 kartIndex);

KartModelsEntry *GetKartModelsEntry(u32 kartIndex);
