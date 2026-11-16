#pragma once

#include "types.h"

typedef struct MapObject MapObject;

void shine_init(MapObject *p); /* parks the pooled object, then allocates its 0x44 effect record */
