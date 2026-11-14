#pragma once

#include "types.h"
#include "01/code_02188950.h"

// Values of mUnk_0a8. On a hand: 0 to 3 are the collision shapes set by SetIwanteNoneCollision to
// SetIwanteHitReactionCollision (1 to 3 stay bare).
// On the object the hands follow: 4 and 5 name the hand that is currently the first or second one.
enum {
    IWANTE_HAND_SHAPE_NONE,
    IWANTE_HAND_SECOND = 4,
    IWANTE_HAND_FIRST,
};

typedef struct MapObjectList MapObjectList;
typedef struct ItemObject ItemObject;

#include "01/MapObjects/map_object_animation.h"

#include "01/callees_0219b000.h"
#include "01/code_02185000.h"
#include "01/code_02186000.h"
#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "01/code_02188260.h"
#include "01/code_02188da4.h"
#include "01/code_02188e24.h"
#include "01/code_02190000.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "01/code_02188158.h"
#include "01/code_02191000.h"
#include "01/code_02192000.h"
#include "01/code_02187bfc.h"
#include "01/Race/race_hud_king_cells.h"
#include "01/code_02188484.h"
#include "01/code_0218f000.h"
#include "01/unk_021a6000.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"

#include "01/code_0218b9b4.h"
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
void IwanteItemResponse2Callback(MissionRunMapObject *mapObject);
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
void IwanteKartResponse11Callback(MissionRunMapObject *mapObject);
void IwanteKartHitCallback(MissionRunMapObject *mapObject);
void IwanteKartResponse2Callback(MissionRunMapObject *mapObject);
void InitIwanteSoundSource(MissionRunMapObject *mapObject);

extern MapObjectKindDescriptor gIwanteKindDescriptor;
extern SoundStartParams gIwanteEndSoundParams;
extern const u32 gIwanteSkipKindSoundFlag;
extern const u16 gIwanteDisabledFlag;
extern const u16 gIwanteSkipListCallbackFlag;
extern const u16 gIwanteSkipViewTestFlag;
