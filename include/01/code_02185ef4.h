#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/MapObjects/attractor.h"

typedef struct ParticleEmitter ParticleEmitter;
typedef struct Kart Kart;
typedef struct ItemObject ItemObject;
typedef struct Vec3s16 Vec3s16;

// Object passed to the per-frame functions UpdateMissionGate and DrawMissionGate.
typedef struct MissionGateObject {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ MapObject *mNegativeSideObject;
    /* 0a4 */ MapObject *mPositiveSideObject;
    /* 0a8 */ u16 mNsbmaFrameIndex;
    /* 0aa */ u8 mUnk_0aa[0x2];
    /* 0ac */ s32 mState;
} MissionGateObject;

#include "01/code_0219b250.h"
#include "01/code_0218155c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/MapObjects/map_object_matrix.h"
#include "Main/Unknown/code_0209b000.h"

void InitMissionRunMapObject(void *mapObjectList, MissionRunMapObject *mapObject, const char *nsbmdName,
                             const char *nsbcaName, const char *prmName);
void StartEffectWithRotatedDirection(MissionRunMapObject *mapObject, int offsetX, int offsetY, int offsetZ,
                                     int emitterParamX, int emitterParamY, int emitterParamZ, int effectId, u32 timer);

void StartEffectInSlot(MissionRunMapObject *mapObject, s32 effectIndex, s32 offsetX, s32 offsetY, s32 offsetZ,
                       u32 effectId, s32 timer);

#include "01/code_02188950.h"
#include "Main/Kart/kart_drift.h"
#include "01/code_02187000.h"

void *CreateEmptyMapObjectUpdateList(void);
s32 CollideItemWithMissionRunMapObject(MissionRunMapObject *mapObject, ItemObject *itemObject, u8 *firstResponsePointer,
                                       u8 *responsePointer);
s32 CollideKartWithMissionRunMapObject(MissionRunMapObject *mapObject, Kart *kart, u8 *firstResponsePointer,
                                       u8 *responsePointer);
s32 ComputeSphereHitOnMissionRunMapObject(MissionRunMapObject *mapObject, Vec3 *sphereCenter, s32 sphereRadius,
                                          Vec3 *overlapOffset);
void DrawMissionRunMapObjectShadow(void *mapObjectList, MissionRunMapObject *mapObject, s32 invertDepth);
void DrawMissionRunMapObject(void *mapObjectList, MissionRunMapObject *mapObject);
void AdvanceMissionRunMapObject(u32 unused, MissionRunMapObject *mapObject);
u16 StepAngleSidewaysToPoint(Vec3 *targetPoint, Vec3 *origin, s32 signedMaxStep, s32 angleOffset, s32 angle);
u16 StepAngleTowardDirection(Vec3 *target, Vec3 *origin, s32 maxStep, s32 angle);
int StepIntTowardTarget(int target, int step, int current);
void ToggleShadowScale(void);
void LoadMissionRunMapObjectShadow(void *mapObjectList, MissionRunMapObject *mapObject, const char *shadowNsbmdName);
BOOL IsNotRisingWithBelowZeroBit(MissionRunMapObject *mapObject);
u32 IsStateNumberBelow(MissionRunMapObject *mapObject, int stateNumberLimit);
void DisableMissionRunMapObjectGravity(MissionRunMapObject *mapObject);
void StartMapObjectState(MissionRunMapObject *mapObject, int stateNumber, s32 (*nextFunc)(MissionRunMapObject *));
void SetEffectDirection(ParticleEmitter *emitter, const Vec3s16 *direction);
void StartModelEffectAtWaterHeight(MissionRunMapObject *mapObject, u32 modelEffectKind, int timer);
void StartEffectAtWaterHeight(MissionRunMapObject *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId,
                              u32 timer);
void StartEffectAtRowHeight(MissionRunMapObject *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId,
                            u32 timer);
void StartEffectAtScaledOffset(MissionRunMapObject *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId,
                               u32 timer);
void StartEffectAtOffset(MissionRunMapObject *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId,
                         u32 timer);
void ComputeEffectPosition(MissionRunMapObject *mapObject, int effectIndex, Vec3 *position);
void ReleaseEffects(MissionRunMapObject *mapObject);
void ThrowItemKinokoFromPosition(void *kinoko, Vec3 *position, Vec3 *velocity, s32 timer);
void ThrowItemBombFromPosition(void *bomb, Vec3 *position, Vec3 *velocity, s32 timer);

#include "01/code_0219b540.h"
