#pragma once

#include "types.h"

typedef struct MapObject MapObject;

void InitShine16(MapObject *mapObject); /* parks the pooled object, then allocates its 0x44 effect record */
