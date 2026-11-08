#pragma once

#include "types.h"

// Sets mClockEnabled; its only caller reaches it through a literal-pool pointer, not a BL.
void StartRaceClock(void);
