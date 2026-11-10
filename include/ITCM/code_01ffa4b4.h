#pragma once

#include "types.h"

typedef struct Kart Kart;

void CollideKartWithCourse(Kart *kart, Vec3 *groundNormal);
