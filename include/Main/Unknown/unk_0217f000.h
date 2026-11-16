#pragma once

#include "types.h"

typedef struct CARDiCommon CARDiCommon;

// The enable flag: CARD_Enable stores it, OS_IsThreadAvailable_15 returns it.
extern u8 CARDi_EnableFlag[];
