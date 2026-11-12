#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Item/item_in_use.h" // KartModelsEntry

void *GetKartModelResMdl(u32 kartIndex);

KartModelsEntry *GetKartModelsEntry(u32 kartIndex);
