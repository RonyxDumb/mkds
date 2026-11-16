#pragma once

#include "types.h"

typedef struct MapObjectList MapObjectList;

void mobj_logicPartIncreaseInstanceCount(MapObjectList *p, s32 n);
void mobj_logicPartResetInstanceCount(MapObjectList *p);
