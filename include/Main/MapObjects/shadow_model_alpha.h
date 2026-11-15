#pragma once

#include "types.h"
#include "Main/Kart/shadow_model_draw.h"

typedef struct ShadowModel ShadowModel;

void DrawShadowModelWithMaxAlpha(ShadowModel *model, int maxAlpha);
