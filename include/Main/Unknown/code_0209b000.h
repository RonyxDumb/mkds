#pragma once

#include "types.h"

typedef struct MapObjectModel MapObjectModel;
typedef struct MapObjectList MapObjectList;

void CreateMapObjectModelNsbcaAnimation(MapObjectModel *a, const char *b);
void *CreateMapObjectModelAnimated(MapObjectList *a, const char *b);
void *CreateMapObjectModelNsbmdNsbtp(MapObjectList *a, const char *b, const char *c);
void *CreateMapObjectModelNsbmd(MapObjectList *a, const char *b);
void *CreateMapObjectModelShadow(MapObjectList *a, const char *b);
void CreateMapObjectModelNsbtpAnimation(MapObjectModel *a, const char *b);
void CreateMapObjectModelNsbtaAnimation(MapObjectModel *a, const char *b);
