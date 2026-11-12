#pragma once

#include "types.h"

typedef struct NsbmdModel NsbmdModel;
typedef struct Nsbmd Nsbmd;

void DrawNsbmdModelWithMaxAlphaMapObjectPos(NsbmdModel *model, u32 maxAlpha, Vec3 *position);
void CreateNsbmd(Nsbmd **slot, void *file, void *unused);
