#pragma once

#include "types.h"

typedef struct MapObjectModel MapObjectModel;
typedef struct MapObjectList MapObjectList;

void CreateMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, const char *name);
MapObjectModel *CreateMapObjectModelAnimated(MapObjectList *mapObjectList, const char *name);
MapObjectModel *CreateMapObjectModelNsbmdNsbtp(MapObjectList *mapObjectList, const char *modelName,
                                               const char *animationName);
MapObjectModel *CreateMapObjectModelNsbmd(MapObjectList *mapObjectList, const char *name);
MapObjectModel *CreateMapObjectModelShadow(MapObjectList *mapObjectList, const char *name);
void CreateMapObjectModelNsbtpAnimation(MapObjectModel *mapObjectModel, const char *name);
void CreateMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel, const char *name);
