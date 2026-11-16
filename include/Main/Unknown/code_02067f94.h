#pragma once

#include "types.h"
#include "Main/Kart/KartStates.h"

typedef struct Kart Kart;

void driver_handleDoubleBackwardFlipReaction(Kart *kart, const Vec3 *direction);
void driver_handleSingleBackwardFlip2Reaction(Kart *kart, s32 b, Unk0206b020 *mapObject);
void driver_handleSingleBackwardFlip1Reaction(Kart *kart, const Vec3 *direction);
