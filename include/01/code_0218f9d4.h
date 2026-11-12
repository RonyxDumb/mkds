#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct MapObjectList MapObjectList;
typedef struct ItemObject ItemObject;

#include "01/code_02185ef4.h"

#include "01/callees_0219b000.h"
#include "01/code_02185000.h"
#include "01/code_02186000.h"
#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "01/code_02188260.h"
#include "01/code_02188da4.h"
#include "01/code_02188e24.h"
#include "01/code_02190000.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_02188158.h"
#include "01/code_02191000.h"
#include "01/code_02192000.h"
#include "01/code_02187bfc.h"
#include "01/code_02188e88.h"
#include "01/code_02188484.h"
#include "01/code_0218f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Race/race.h"

void *CreateIwanteHandsUpdateList(void);
void *CreateIwanteUpdateList(void);
void *CreateIwanteDrawList(void);
void CreateIwanteKindData(void);
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
