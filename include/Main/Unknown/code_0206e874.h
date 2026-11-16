#pragma once

#include "types.h"

typedef struct Kart Kart;

void driver_handleMapObjCollision(Kart *kart);
void driver_206EDAC(Kart *kart, Vec3 *groundNormal);
