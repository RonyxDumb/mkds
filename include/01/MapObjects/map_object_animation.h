#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"

typedef struct ParticleEmitter ParticleEmitter;
typedef struct Kart Kart;
typedef struct ItemObject ItemObject;
typedef struct Vec3s16 Vec3s16;

// Values of MissionGateObject.mState: the gate waits for the mission count, then is done; a kart hit plays the
// animation first.
enum {
    MISSION_GATE_STATE_WAIT_COUNT,
    MISSION_GATE_STATE_DONE,
    MISSION_GATE_STATE_PLAY_ANIMATION,
};

// Object passed to the per-frame functions UpdateMissionGate and DrawMissionGate.
typedef struct MissionGateObject {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ MapObject *mNegativeSideObject;
    /* 0a4 */ MapObject *mPositiveSideObject;
    /* 0a8 */ u16 mNsbmaFrameIndex;
    /* 0aa */ u8 mUnk_0aa[0x2];
    /* 0ac */ s32 mState;
} MissionGateObject;

#include "01/MapObjects/map_object_model_animation_load.h"
#include "01/Race/mission_run_state.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/MapObjects/map_object_matrix.h"
#include "Main/MapObjects/map_object_model_frame.h"

void InitMissionRunMapObject(void *mapObjectList, MissionRunMapObject *mapObject, const char *nsbmdName,
                             const char *nsbcaName, const char *prmName);
void StartEffectWithRotatedDirection(MissionRunMapObject *mapObject, int offsetX, int offsetY, int offsetZ,
                                     int emitterParamX, int emitterParamY, int emitterParamZ, int effectId, u32 timer);

void StartEffectInSlot(MissionRunMapObject *mapObject, s32 effectIndex, s32 offsetX, s32 offsetY, s32 offsetZ,
                       u32 effectId, s32 timer);

#include "01/MapObjects/mission_run_map_object.h"
#include "Main/Kart/kart_drift.h"

#include "Main/MapObjects/map_object_kind_update_list.h"

extern MapObjectKindDescriptor gEmptyMapObjectKindDescriptor;

MapObjectList *CreateEmptyMapObjectUpdateList(void);
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

#include "01/Menu/select_ghost.h"

// Frames (MissionRunMapObject.mTimer) after a kart hit during which the object keeps its response and plays no hit
// sound again.
#define MAP_OBJECT_KART_HIT_COOLDOWN_FRAMES 0x1f

extern Vec3 gItemBombUpNormal;
extern Vec3 gItemKinokoUpNormal;
extern u16 gShadowScaleToggle;
