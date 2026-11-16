#pragma once

#include "types.h"

struct KartPhysicalParam;

s32 GetFATGigi(void);
s32 *GetCharacterPhysicalParam(unsigned int slotIndex);
struct KartPhysicalParam *GetKartPhysicalParam(u32 kartIndex);
