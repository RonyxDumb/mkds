#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020a3f2c.h"

u32 shine_onDriverCollide(Shine16 *p, Kart *o, u8 *a, u8 *b);
void shine_loadShineModel(void *a);
void shine_applyShineMaterial(void *a);
void shine_renderShine(void *a, Shine16 *p);
