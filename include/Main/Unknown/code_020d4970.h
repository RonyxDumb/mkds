#pragma once

#include "types.h"

typedef struct Water Water;

// Publishes the WaterEfct object as gMObjSplashState.
void mobj_setSplashStatePointer(void *waterEfct);
// Publishes the Water object as gMObjWaterState.
void mobj_setWaterStatePointer(Water *water);
