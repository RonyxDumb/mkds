#pragma once

#include "types.h"

typedef struct Kart Kart;

void CollideKartWithMapObjects(Kart *kart);
void ApplyKartLanding(Kart *kart, Vec3 *groundNormal);
