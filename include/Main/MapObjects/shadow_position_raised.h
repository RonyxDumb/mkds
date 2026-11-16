#pragma once

#include "types.h"

typedef struct ShadowMatrix ShadowMatrix;

void SetShadowPositionRaised(ShadowMatrix *shadow, Vec3 *position);

void SetShadowPositionXZ(ShadowMatrix *shadow, Vec3 *position);
