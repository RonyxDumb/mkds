#pragma once

#include "types.h"
#include "01/MapObjects/mission_run_map_object.h"

// Values of mHandShape and mHandOrder. A hand's mHandShape is the collision shape set by SetIwanteNoneCollision to
// SetIwanteHitReactionCollision. mHandOrder uses 4 and 5 for the hand that is currently the second or first one.
enum {
    IWANTE_HAND_SHAPE_NONE,
    IWANTE_HAND_SHAPE_WALK_A,
    IWANTE_HAND_SHAPE_WALK_B,
    IWANTE_HAND_SHAPE_HIT_REACTION,
    IWANTE_HAND_SECOND = 4,
    IWANTE_HAND_FIRST,
};

typedef struct MapObjectList MapObjectList;
typedef struct ItemObject ItemObject;

#include "01/MapObjects/map_object_animation.h"

#include "01/callees_0219b000.h"
#include "01/MapObjects/mission_run_hit_count.h"
#include "01/MapObjects/mission_run_state_callbacks.h"
#include "01/MapObjects/mission_run_frame_callbacks.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "01/MapObjects/mission_run_range_and_collision_callbacks.h"
#include "01/MapObjects/item_bomb_throw_or_release.h"
#include "01/Race/race_hud_king_cells.h"
#include "01/MapObjects/mission_run_collision_shadow_offsets.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"

#include "01/MapObjects/kuriking_state_shared.h"
#include "Main/Sound/sound_source_list.h"

extern MapObjectKindDescriptor gIwanteHandsKindDescriptor;

MapObjectList *CreateIwanteHandsUpdateList(void);
MapObjectList *CreateIwanteUpdateList(void);
MapObjectList *CreateIwanteDrawList(void);
MapObjectKindData *CreateIwanteKindData(void);
void DrawIwante(void *mapObjectList, MissionRunMapObject *mapObject);
void InitIwante(MapObjectList *mapObjectList);
void UpdateIwante(u32 mapObjectList, MissionRunMapObject *mapObject);
void InitIwanteObjects(MapObjectList *mapObjectList);
void UpdateIwanteHands(u32 mapObjectList, MissionRunMapObject *mapObject);
void InitIwanteHandsObjects(MapObjectList *mapObjectList);
void IwanteItemHitCallback(MissionRunMapObject *mapObject, ItemObject *itemObject);
void IwanteItemResponse2Callback(MissionRunMapObject *mapObject, ItemObject *itemObject);
void StartIwanteChainCameraHold(MissionRunMapObject *mapObject);
void StartIwanteChainCameraCourseWait(MissionRunMapObject *mapObject);
void StartIwanteNoChainCameraWait(MissionRunMapObject *mapObject);
void StartIwanteNoChainCameraAnimation(MissionRunMapObject *mapObject);
void StartIwanteNoChainCameraEffects(MissionRunMapObject *mapObject);
void StartIwanteCourseHitEffects(MissionRunMapObject *mapObject);
void ApplyIwanteHandsHit(MissionRunMapObject *mapObject);
void StartIwanteHandsWaitForRaceStart(MissionRunMapObject *mapObject);
u32 AdvanceIwanteHandsWaitForRaceStart(MissionRunMapObject *mapObject);
void StartIwanteHandsHitReaction(MissionRunMapObject *mapObject);
int AdvanceIwanteHandsNextByHitCount(MissionRunMapObject *mapObject);
void StartIwanteHandsFromPrm(MissionRunMapObject *mapObject);
void StartIwanteHandsToggleStateHold(MissionRunMapObject *mapObject);
void StartIwanteHandsToggleState(MissionRunMapObject *mapObject);
int AdvanceIwanteHandsStopAfterToggle(MissionRunMapObject *mapObject);
void StartIwanteHandsApproachKart(MissionRunMapObject *mapObject);
int AdvanceIwanteHandsApproachKart(MissionRunMapObject *mapObject);
void StartIwanteHandsTurnToKart(MissionRunMapObject *mapObject);
int AdvanceIwanteHandsToggleState(MissionRunMapObject *mapObject);
int AdvanceIwanteHandsApproachUntilIdle(MissionRunMapObject *mapObject);
void StartIwanteHandsChangeToWalkA(MissionRunMapObject *mapObject);
int AdvanceIwanteHandsStartMoveVertical(MissionRunMapObject *mapObject);
void StartIwanteHandsMoveVertical(MissionRunMapObject *mapObject);
s32 AdvanceIwanteHandsRepeatVertical(MissionRunMapObject *mapObject);
void StartIwanteHandsChangeToWalkB(MissionRunMapObject *mapObject);
s32 AdvanceIwanteHandsStartFromPrm(MissionRunMapObject *mapObject);
void StartIwanteHandsFallOrMoveToPoints(MissionRunMapObject *mapObject);
s32 AdvanceIwanteHandsRestartWhenIdle(MissionRunMapObject *mapObject);
s32 AdvanceIwanteHandsStopAfterPoints(MissionRunMapObject *mapObject);
void IwanteStandingsEndCallback(void);
void StartIwanteKartEliminatedHold(MissionRunMapObject *mapObject);
void StartIwanteHideAtEndReached(MissionRunMapObject *mapObject);
void HideIwanteAtEndReached(MissionRunMapObject *mapObject);
void StartIwanteHandHitReactionHold(MissionRunMapObject *mapObject);
void StartIwanteHandHitHold(MissionRunMapObject *mapObject);
void StartIwanteHandHitReaction(MissionRunMapObject *mapObject);
s32 AdvanceIwanteHandHitCollision(MissionRunMapObject *mapObject);
s32 AdvanceIwanteHandHitCollisionSound(MissionRunMapObject *mapObject);
void StartIwanteHandHitSecondAnimation(MissionRunMapObject *mapObject);
void StartIwanteHandHitThirdAnimation(MissionRunMapObject *mapObject);
void StartIwanteHandDirectFallOnKart(MissionRunMapObject *mapObject);
void StartIwanteHandLandOnKartAndStop(MissionRunMapObject *mapObject);
void StartIwanteHandTurnToKart(MissionRunMapObject *mapObject);
void StartIwanteHandMoveToKart(MissionRunMapObject *mapObject);
s32 AdvanceIwanteHandKartSound(MissionRunMapObject *mapObject);
void StartIwanteHandFallOnKart(MissionRunMapObject *mapObject);
void StartIwanteHandLandOnKart(MissionRunMapObject *mapObject);
void StartIwanteHandLandBeforeSideways(MissionRunMapObject *mapObject);
void StartIwanteHandMoveSideways(MissionRunMapObject *mapObject);
void StartIwanteHandSidewaysStop(MissionRunMapObject *mapObject);
s32 AdvanceIwanteHandSidewaysSound(MissionRunMapObject *mapObject);
int AdvanceIwanteHandSidewaysStop(MissionRunMapObject *mapObject);
void StartIwanteHandMoveToPoints(MissionRunMapObject *mapObject);
void StartIwanteHandReachMovePoint(MissionRunMapObject *mapObject);
void StartIwanteHandFall(MissionRunMapObject *mapObject);
void StartIwanteHandLand(MissionRunMapObject *mapObject);
void StartIwanteHandChangeToWalkA(MissionRunMapObject *mapObject);
void StartIwanteHandChangeToWalkB(MissionRunMapObject *mapObject);
void StartIwanteHandMoveVertical(MissionRunMapObject *mapObject);
void StartIwanteHandMoveVerticalBack(MissionRunMapObject *mapObject);
u32 AdvanceIwanteHandVerticalSound(MissionRunMapObject *mapObject);
void StopIwanteHandOnCourseHit(MissionRunMapObject *mapObject);
void StartIwanteHandWalkAHold(MissionRunMapObject *mapObject);
void StartIwanteHandWalkBHold(MissionRunMapObject *mapObject);
void StartIwanteHandChangeToWalkAWalk(MissionRunMapObject *mapObject);
void StartIwanteHandChangeToWalkBWalk(MissionRunMapObject *mapObject);
void StartIwanteHandWalkAWalk(MissionRunMapObject *mapObject);
void StartIwanteHandWalkBWalk(MissionRunMapObject *mapObject);
void StartIwanteHandWalkWithEffects(MissionRunMapObject *mapObject);
void StartIwanteHandWalk(MissionRunMapObject *mapObject);
void SetIwanteWalkAHitCollision(MissionRunMapObject *mapObject);
void SetIwanteHitReactionCollision(MissionRunMapObject *mapObject);
void SetIwanteWalkBCollision(MissionRunMapObject *mapObject);
void SetIwanteWalkACollision(MissionRunMapObject *mapObject);
void SetIwanteNoChainCameraWalkA(MissionRunMapObject *mapObject);
void SetIwanteNoneCollision(MissionRunMapObject *mapObject);
void SetIwanteHandsPoints(void);
void SetIwanteHandsApproachPoint(void);
void IwanteKartResponse11Callback(MissionRunMapObject *mapObject, Kart *kart);
void IwanteKartHitCallback(MissionRunMapObject *mapObject, Kart *kart);
void IwanteKartResponse2Callback(MissionRunMapObject *mapObject, Kart *kart);
void InitIwanteSoundSource(MissionRunMapObject *mapObject);

extern MapObjectKindDescriptor gIwanteKindDescriptor;
extern SoundStartParams gIwanteEndSoundParams;
extern const u32 gIwanteSkipKindSoundFlag;
extern const u16 gIwanteDisabledFlag;
extern const u16 gIwanteSkipListCallbackFlag;
extern const u16 gIwanteSkipViewTestFlag;
