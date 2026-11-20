#pragma once

#include "types.h"

#include "particle_system.h"
#include "Main/Graphics/emitters.h"

// SPLManager.mMiscPolygonAttr of the race and mission run effects: polygon attribute bit 15, which turns fog on for the
// particles (the race effects clear it on the rainbow course).
#define EFFECT_POLYGON_ATTR_FOG 0x8000

SPLManager *GetRaceEffectSPLManager(s32 *outIndex, s32 effectId);
void *StartEffectWithKartVelocity(u32 effectId, Vec3 *position, u32 kartIndex, s32 velocityScale);
void PlaceEffect(void *emitter, const Vec3 *position);
ParticleEmitter *StartRaceFogOffEffect(s32 resourceId, const Vec3 *position);
void StopEffectAndClearPointer(void **emitterSlot);
void DeleteEffectAndClearPointer(ParticleEmitter **emitterSlot);
void DeleteEffect(ParticleEmitter *emitter);
// Creates the emitter for effectId at position and returns it (NULL when none is made).
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
extern AwardSecondEffectIds gAwardSecondEffectIds;

extern Vec3 gAwardEmitterPosition;

extern void (*gAdvanceEmittersFunction)(void);
extern struct SPLManager *gMissionRunSPLManager;
