#pragma once

#include "types.h"
#include "model_material_set.h" // MtxFx43
#include "matrix44_concat.h" // MtxFx44

void MTX_Identity44_(MtxFx44 *dst);
void MTX_Copy44To43_(const MtxFx44 *src, MtxFx43 *dst);
