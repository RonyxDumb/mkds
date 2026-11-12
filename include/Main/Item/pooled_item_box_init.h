#pragma once

#include "types.h"
#include "Main/Unknown/code_02067cb0.h" // MapObject
#include "Main/MapObjects/map_object_kind_update_list.h" // MapObjectKindDescriptor

typedef struct ItemBox ItemBox;

extern const MapObjectKindDescriptor gPooledItemBoxKindDescriptor;
extern const MapObjectKindData gPooledItemBoxKindData;

BOOL IsRaceSceneNormalOrReplay(void);
BOOL IsMissionRunBossColumn(void);
MapObjectKindData *CreatePooledItemBoxKindData(void);
void InitPooledItemBox(void *mapObject, struct CourseMapRow *row, void *unused);
MapObject *AllocPooledMapObject(void);
void ResetPooledMapObject(ItemBox *pooledObject);
