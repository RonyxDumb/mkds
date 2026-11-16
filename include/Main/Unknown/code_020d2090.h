#pragma once

#include "types.h"

typedef struct ItemObject ItemObject;
typedef struct MapObject MapObject;

void *mobj_getSharedMapObjFile(const char *name);
void *mobj_getMapObjFile(const char *name);

void r2d_updateRaceNumber(void);
void r2d_initRaceNumber(void);
u32 mobj_parseDecimalBits(s32 number);
BOOL mobj_destroysItemOnHit(MapObject *mapObject, ItemObject *itemObject);
