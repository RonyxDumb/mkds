#pragma once

#include "types.h"

typedef struct Sman Sman;
typedef struct Kart Kart;
typedef struct MapObject MapObject;
typedef struct ItemObject ItemObject;

u8 CollideItemObjectWithSman(Sman *sman, ItemObject *itemObject, u8 *firstResponse, u8 *secondResponse);
u8 CollideKartWithSman(Sman *sman, Kart *kart, u8 *firstResponse, u8 *secondResponse);
void InitSman(MapObject *mapObject);
