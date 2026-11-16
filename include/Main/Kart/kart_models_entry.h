#pragma once

#include "types.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Item/item_in_use.h" // KartModelsEntry

void *GetCharacterKartModel(u16 kartIndex);

KartModelsEntry *GetAD00SubRacer(u32 kartIndex);
