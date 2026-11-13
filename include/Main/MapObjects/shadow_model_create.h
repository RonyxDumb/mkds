#pragma once

#include "types.h"

typedef struct ShadowModel ShadowModel;

void CreateShadowModel(ShadowModel **slot, void *file, u32 polygonId);

extern const u32 gWoodbox1HitFlag;
