#pragma once

#include "types.h"

#include "code_020184e4.h"
#include "Main/Graphics/emitters.h"

SPLManager *GetRaceEffectSPLManager(s32 *outIndex, s32 effectId);
void *StartEffectWithKartVelocity(u32 effectId, Vec3 *position, u32 kartIndex, s32 velocityScale);
void PlaceEffect(void *emitter, const Vec3 *position);
ParticleEmitter *StartRaceFogOffEffect(s32 resourceId, Vec3 *position);
void StopEffectAndClearPointer(void **emitterSlot);
void DeleteEffectAndClearPointer(ParticleEmitter **emitterSlot);
void DeleteEffect(ParticleEmitter *emitter);
// Starts effect a at the position b and returns the effect object (NULL when none is made).
void *StartEffect(u32 effectId, const Vec3 *position);
void DrawEffects(MtxFx43 *viewMatrix);
void UpdateEffects(void);
void InitEffects(void *defaultHeap);
void *HeapAllocForSPLManager(u32 size);

extern void *gSPLManagerHeap;
extern struct SPLManager *gRaceEffectSPLManager;
extern struct StadiumEmitters *gStadiumEmitters;
extern struct SPLManager *gRaceEffectFogOffSPLManager;
extern GetSPLManagerFunc *gGetSPLManagerFunction;

extern Vec3 gStadiumEmitterDirectionOrigin;
extern AwardFirstEffectIds gAwardFirstEffectIds;
extern AwardEmitterEffectIds gAwardEmitterEffectIds;

extern Vec3 gAwardEmitterPosition;

extern void (*gAdvanceEmittersFunction)(void);
extern struct SPLManager *gMissionRunSPLManager;
