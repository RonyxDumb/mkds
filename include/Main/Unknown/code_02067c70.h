#pragma once

#include "types.h"

// Collision response 12 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): stores 0xc through the second parameter and returns 5.
u32 driver_initReaction12(u32 arg0, u32 arg1);
// Collision response 10 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): stores 0xa through the second parameter and returns 2.
u32 driver_initDoubleBackwardFlipReaction(u32 arg0, u32 arg1);
// Collision response 9 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): stores 9 through the second parameter and returns 2.
u32 driver_initSingleBackwardFlip2Reaction(u32 arg0, u32 arg1);
// Collision response 8 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): stores 8 through the second parameter and returns 2.
u32 driver_initSingleBackwardFlip1Reaction(u32 arg0, u32 arg1);
