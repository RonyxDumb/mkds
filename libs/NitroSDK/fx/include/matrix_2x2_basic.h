#pragma once

#include "types.h"
#include "model_material_set.h" // MtxFx22

void MTX_Identity22_(MtxFx22 *dst);

void MTX_Rot22_(MtxFx22 *dst, s32 sinVal, s32 cosVal);
