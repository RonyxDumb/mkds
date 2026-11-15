#pragma once

#include "types.h"

struct KartPhysicalParam;

s32 GetFirstBaseSpeedLimit(void);
s32 *GetCharPhysicalParam(unsigned int slotIndex);
struct KartPhysicalParam *GetKartPhysicalParam(u32 kartIndex);
