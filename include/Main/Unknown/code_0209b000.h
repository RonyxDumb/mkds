#pragma once

#include "types.h"

typedef struct MapObjectModel MapObjectModel;
typedef struct MapObjectList MapObjectList;

void CreateMapObjectModelNsbcaAnimation(MapObjectModel *a, const char *b);
MapObjectModel *CreateMapObjectModelAnimated(MapObjectList *a, const char *b);
MapObjectModel *CreateMapObjectModelNsbmdNsbtp(MapObjectList *a, const char *b, const char *c);
MapObjectModel *CreateMapObjectModelNsbmd(MapObjectList *a, const char *b);
MapObjectModel *CreateMapObjectModelShadow(MapObjectList *a, const char *b);
void CreateMapObjectModelNsbtpAnimation(MapObjectModel *a, const char *b);
void CreateMapObjectModelNsbtaAnimation(MapObjectModel *a, const char *b);
