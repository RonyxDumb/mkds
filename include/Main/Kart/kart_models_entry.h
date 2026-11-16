#pragma once

#include "types.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Item/item_in_use.h" // KartModelsEntry

void *GetKartModelResMdl(u16 kartIndex);

KartModelsEntry *GetKartModelsEntry(u32 kartIndex);
