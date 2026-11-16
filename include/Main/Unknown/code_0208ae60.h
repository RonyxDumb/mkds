#pragma once

#include "types.h"

struct KartPhysicalParam;

s32 physp_getField8(void);
s32 *physp_getDriverCharPhysicalParams(unsigned int p0);
struct KartPhysicalParam *physp_getDriverKartPhysicalParams(u32 arg0);
