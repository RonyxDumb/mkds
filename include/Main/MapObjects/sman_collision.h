#pragma once

#include "types.h"

#define SMAN_TOP_HEIGHT 0xf333
#define SMAN_TOP_HEIGHT_PER_FRAME 0x8000

typedef struct Sman Sman;
typedef struct Kart Kart;
typedef struct MapObject MapObject;
typedef struct ItemObject ItemObject;

u8 CollideItemObjectWithSman(Sman *sman, ItemObject *itemObject, u8 *firstResponse, u8 *secondResponse);
u8 CollideKartWithSman(Sman *sman, Kart *kart, u8 *firstResponse, u8 *secondResponse);
void InitSman(MapObject *mapObject);

extern const u16 gSmanHitFlag;
extern const u16 gSmanInitMapObjectFlag;
