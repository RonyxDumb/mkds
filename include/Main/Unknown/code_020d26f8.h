#pragma once

#include "types.h"

typedef struct MapObject MapObject;
typedef struct Kart Kart;

u32 mobj_tryDestroyByDriver(MapObject *mapObject, Kart *kart);
