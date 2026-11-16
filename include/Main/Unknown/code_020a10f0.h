#pragma once

#include "types.h"

void mgcnt_updateDriverBalloonShineCount(u16 kartIndex, s32 amount);
u16 mgcnt_getDriverBalloonShineCount(u16 kartIndex);
u16 mgcnt_getMaxOwnedShineCount(void);
u16 mgcnt_getTotalOwnedShineCount(void);
