#pragma once

#include "types.h"

typedef struct NsbmdModel NsbmdModel;

void sub_20EA5B0(NsbmdModel *model, u32 maxAlpha, Vec3 *position);
void model2_createFromNsbmd(void **slot, void *file, void *unused);
