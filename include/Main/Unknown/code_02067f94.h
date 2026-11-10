#pragma once

#include "types.h"
#include "Main/Unknown/code_0206a354.h"

typedef struct Kart Kart;

void StartKartPushDoubleFlipOnHit(Kart *kart, const Vec3 *direction);
void StartKartPushFlipOnHitByMapObject(Kart *kart, s32 direction, Unk0206b020 *mapObject);
void StartKartPushFlipOnHit(Kart *kart, const Vec3 *direction);
