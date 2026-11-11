#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct MapObjectList MapObjectList;

// Offsets 0x50..0x5b of the object are a position.
typedef struct Unk0218fd20 {
    /* 00 */ u8 mUnk_00[0x50];
    /* 50 */ Vec3 mUnk_50;
} Unk0218fd20;

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
#include "Main/Unknown/code_02061654.h"

void *CreateIwanteHandsUpdateList(void);
void *CreateIwanteUpdateList(void);
void *CreateIwanteDrawList(void);
void CreateIwanteKindData(void);
void DrawIwante(void *mapObjectList, Unk02188950 *mapObject);
void InitIwante(MapObjectList *mapObjectList);
void UpdateIwante(u32 mapObjectList, Unk02188950 *mapObject);
void InitIwanteObjects(MapObjectList *mapObjectList);
void UpdateIwanteHands(u32 mapObjectList, Unk02188950 *mapObject);
void InitIwanteHandsObjects(MapObjectList *mapObjectList);
void IwanteItemHitCallback(Unk02188950 *mapObject, Unk0218fd20 *itemObject);
void IwanteItemResponse2Callback(Unk02188950 *mapObject);
void StartIwanteChainCameraHold(Unk02188950 *mapObject);
void StartIwanteChainCameraCourseWait(Unk02188950 *mapObject);
void StartIwanteNoChainCameraWait(Unk02188950 *mapObject);
void StartIwanteNoChainCameraAnimation(Unk02188950 *mapObject);
void StartIwanteNoChainCameraEffects(Unk02188950 *mapObject);
void StartIwanteCourseHitEffects(Unk02188950 *mapObject);
void ApplyIwanteHandsHit(Unk02188950 *mapObject);
void StartIwanteHandsWaitForRaceStart(Unk02188950 *mapObject);
u32 AdvanceIwanteHandsWaitForRaceStart(Unk02188950 *mapObject);
void StartIwanteHandsHitReaction(Unk02188950 *mapObject);
int AdvanceIwanteHandsNextByHitCount(Unk02188950 *mapObject);
void StartIwanteHandsFromPrm(Unk02188950 *mapObject);
void StartIwanteHandsToggleStateHold(Unk02188950 *mapObject);
void StartIwanteHandsToggleState(Unk02188950 *mapObject);
int AdvanceIwanteHandsStopAfterToggle(Unk02188950 *mapObject);
void StartIwanteHandsApproachKart(Unk02188950 *mapObject);
int AdvanceIwanteHandsApproachKart(Unk02188950 *mapObject);
void StartIwanteHandsTurnToKart(Unk02188950 *mapObject);
int AdvanceIwanteHandsToggleState(Unk02188950 *mapObject);
int AdvanceIwanteHandsApproachUntilIdle(Unk02188950 *mapObject);
void StartIwanteHandsChangeToWalkA(Unk02188950 *mapObject);
int AdvanceIwanteHandsStartMoveVertical(Unk02188950 *mapObject);
void StartIwanteHandsMoveVertical(Unk02188950 *mapObject);
s32 AdvanceIwanteHandsRepeatVertical(Unk02188950 *mapObject);
void StartIwanteHandsChangeToWalkB(Unk02188950 *mapObject);
s32 AdvanceIwanteHandsStartFromPrm(Unk02188950 *mapObject);
void StartIwanteHandsFallOrMoveToPoints(Unk02188950 *mapObject);
s32 AdvanceIwanteHandsRestartWhenIdle(Unk02188950 *mapObject);
s32 AdvanceIwanteHandsStopAfterPoints(Unk02188950 *mapObject);
void IwanteStandingsEndCallback(void);
void StartIwanteKartEliminatedHold(Unk02188950 *mapObject);
void StartIwanteHideAtEndReached(Unk02188950 *mapObject);
void HideIwanteAtEndReached(Unk02188950 *mapObject);
void StartIwanteHandHitReactionHold(Unk02188950 *mapObject);
void StartIwanteHandHitHold(Unk02188950 *mapObject);
void StartIwanteHandHitReaction(Unk02188950 *mapObject);
s32 AdvanceIwanteHandHitCollision(Unk02188950 *mapObject);
s32 AdvanceIwanteHandHitCollisionSound(Unk02188950 *mapObject);
void StartIwanteHandHitSecondAnimation(Unk02188950 *mapObject);
void StartIwanteHandHitThirdAnimation(Unk02188950 *mapObject);
void StartIwanteHandDirectFallOnKart(Unk02188950 *mapObject);
void StartIwanteHandLandOnKartAndStop(Unk02188950 *mapObject);
void StartIwanteHandTurnToKart(Unk02188950 *mapObject);
void StartIwanteHandMoveToKart(Unk02188950 *mapObject);
s32 AdvanceIwanteHandKartSound(Unk02188950 *mapObject);
void StartIwanteHandFallOnKart(Unk02188950 *mapObject);
void StartIwanteHandLandOnKart(Unk02188950 *mapObject);
void StartIwanteHandLandBeforeSideways(Unk02188950 *mapObject);
void StartIwanteHandMoveSideways(Unk02188950 *mapObject);
void StartIwanteHandSidewaysStop(Unk02188950 *mapObject);
s32 AdvanceIwanteHandSidewaysSound(Unk02188950 *mapObject);
int AdvanceIwanteHandSidewaysStop(Unk02188950 *mapObject);
void StartIwanteHandMoveToPoints(Unk02188950 *mapObject);
void StartIwanteHandReachMovePoint(Unk02188950 *mapObject);
void StartIwanteHandFall(Unk02188950 *mapObject);
void StartIwanteHandLand(Unk02188950 *mapObject);
void StartIwanteHandChangeToWalkA(Unk02188950 *mapObject);
void StartIwanteHandChangeToWalkB(Unk02188950 *mapObject);
void StartIwanteHandMoveVertical(Unk02188950 *mapObject);
void StartIwanteHandMoveVerticalBack(Unk02188950 *mapObject);
u32 AdvanceIwanteHandVerticalSound(Unk02188950 *mapObject);
void StopIwanteHandOnCourseHit(Unk02188950 *mapObject);
void StartIwanteHandWalkAHold(Unk02188950 *mapObject);
void StartIwanteHandWalkBHold(Unk02188950 *mapObject);
void StartIwanteHandChangeToWalkAWalk(Unk02188950 *mapObject);
void StartIwanteHandChangeToWalkBWalk(Unk02188950 *mapObject);
void StartIwanteHandWalkAWalk(Unk02188950 *mapObject);
void StartIwanteHandWalkBWalk(Unk02188950 *mapObject);
void StartIwanteHandWalkWithEffects(Unk02188950 *mapObject);
void StartIwanteHandWalk(Unk02188950 *mapObject);
void SetIwanteWalkAHitCollision(Unk02188950 *mapObject);
void SetIwanteHitReactionCollision(Unk02188950 *mapObject);
void SetIwanteWalkBCollision(Unk02188950 *mapObject);
void SetIwanteWalkACollision(Unk02188950 *mapObject);
void SetIwanteNoChainCameraWalkA(Unk02188950 *mapObject);
void SetIwanteNoneCollision(Unk02188950 *mapObject);
void SetIwanteHandsPoints(void);
void SetIwanteHandsApproachPoint(void);
void IwanteKartResponse11Callback(Unk02188950 *mapObject);
void IwanteKartHitCallback(Unk02188950 *mapObject);
void IwanteKartResponse2Callback(Unk02188950 *mapObject);
void InitIwanteSoundSource(Unk02188950 *mapObject);
