#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct MapObject MapObject;

void StartKartPushDoubleFlipOnHit(Kart *kart, const Vec3 *direction);
void StartKartPushFlipOnHitByMapObject(Kart *kart, s32 direction, MapObject *mapObject);
void StartKartPushFlipOnHit(Kart *kart, const Vec3 *direction);
