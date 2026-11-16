#pragma once

#include "types.h"

// Collision response 2 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): stores 2 through the second parameter and returns 0xb.
u32 driver_initReaction2(u32 arg0, u32 arg1);
// Collision response 0 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): stores 0 through the second parameter and returns 0. Same bytes as
// driver_initReaction1, the table entry for index 1.
u32 driver_initNoReaction(u32 arg0, u32 arg1);
