#pragma once

#include "types.h"

// Declared here until the code that defines them is decompiled.

#include "code_020184e4.h"

extern Vec3 data_021660fc;
extern char aRaceeffect_spa[];
extern char aEffectRaceeffe[];
extern char aDataMissionrun[];

u32 ptcm_getParticleSetByIdNormal(u32 outIndex, u32 effectId);
void *ptcm_208B498(u32 effectId, Vec3 *position, u32 kartIndex, s32 velocityScale);
void ptcm_setEmitterPosition(void *emitter, const Vec3 *position);
Unk0201ca6c *ptcm_createFogOffEmitter(s32 resourceId, Vec3 *position);
void ptcm_killEmitter(void **emitterSlot);
void ptcm_killEmitterDirectSafe(Unk0201ca6c **emitterSlot);
void ptcm_killEmitterDirect(Unk0201ca6c *emitter);
// Starts effect a at the position b and returns the effect object (NULL when none is made).
void *ptcm_createEmitter(u32 effectId, const Vec3 *position);
void ptcm_render(MtxFx43 *viewMatrix);
void ptcm_update(void);
void ptcm_init(void *defaultHeap);
u32 ptcm_alloc(u32 size);
