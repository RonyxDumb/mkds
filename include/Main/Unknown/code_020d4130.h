#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e6b58.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/unk_0217a000.h" // Camera

void mobj_updateVisibility(void);
void mobj_updateVisibilityNoFade(void);
void mobj_updateAll(void);
void mobj_renderAll(Camera *view);
void mobj_renderDColObjects(Camera *view);
s32 mobj_collideDriver(Kart *kart, Vec3 *position, Vec3 *hitOffset);
s32 mobj_queryBySphere(Vec3 *position, s32 radius, s32 kind);
