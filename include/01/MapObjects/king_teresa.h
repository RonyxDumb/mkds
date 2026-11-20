#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;
typedef struct ItemObject ItemObject;
typedef struct MapObjectList MapObjectList;
typedef struct Kart Kart;

#include "01/MapObjects/kuriking_state_shared.h"

// Values of MissionRunMapObject.mMoveStage of King Teresa: 0 is no stage; hiding for the next group steps 1 to 2 to 3
// (3 stays), and StartKingTeresaMoveToGroupEntry then uses the first, second or third set of speed and turn parameters.
enum {
    KING_TERESA_MOVE_STAGE_NONE,
    KING_TERESA_MOVE_STAGE_FIRST,
    KING_TERESA_MOVE_STAGE_SECOND,
    KING_TERESA_MOVE_STAGE_THIRD,
};

// mStateFrames of the end reached state at which its sound starts.
#define KING_TERESA_END_SOUND_FRAME 50

MapObjectList *CreateKingTeresaUpdateList(void);
MapObjectList *CreateKingTeresaDrawList(void);
MapObjectKindData *CreateKingTeresaKindData(void);
void DrawKingTeresa(void *mapObjectList, MissionRunMapObject *mapObject);
void InitKingTeresa(MapObjectList *mapObjectList);
void UpdateKingTeresa(u32 unused, MissionRunMapObject *mapObject);
void InitKingTeresaObjects(MapObjectList *mapObjectList);
void KingTeresaBossTransferCallback(MissionRunMapObject *mapObject, Kart *kart);
void KingTeresaHitReactionCallback(MissionRunMapObject *mapObject, Kart *kart);
void KingTeresaParkBossCoinsCallback(MissionRunMapObject *mapObject, Kart *kart);
void InitKingTeresaMapObject(MissionRunMapObject *mapObject);
void StartKingTeresaZeroAlphaWait(MissionRunMapObject *mapObject);
void ShowKingTeresaAfterWait(MissionRunMapObject *mapObject);
void StartKingTeresaFirstAnimation(MissionRunMapObject *mapObject);
void StartKingTeresaSecondAnimation(MissionRunMapObject *mapObject);
void KingTeresaStandingsEndCallback(void);
void StartKingTeresaWinnerDecidedHold(MissionRunMapObject *mapObject);
void ShowKingTeresaAtEndReached(MissionRunMapObject *mapObject);
s32 AdvanceKingTeresaEndReachedSound(MissionRunMapObject *mapObject);
void HideKingTeresaAtEndReached(MissionRunMapObject *mapObject);
void StartKingTeresaKartEliminatedHold(MissionRunMapObject *mapObject);
void StartKingTeresaHideThenWaitHidden(MissionRunMapObject *mapObject);
void StartKingTeresaWaitHidden(MissionRunMapObject *mapObject);
void HideKingTeresaWithoutEffects(MissionRunMapObject *mapObject);
void StartKingTeresaHideThenCoinsFadeIn(MissionRunMapObject *mapObject);
void StartKingTeresaCoinsFadeIn(MissionRunMapObject *mapObject);
void StartKingTeresaStopForBossCoins(MissionRunMapObject *mapObject);
void StartKingTeresaShowBossCoins(MissionRunMapObject *mapObject);
u32 AdvanceKingTeresaSinkToCourseRow(MissionRunMapObject *mapObject);
void StartKingTeresaHideForNextGroup(MissionRunMapObject *mapObject);
void ShowKingTeresaAtGroupEntry(MissionRunMapObject *mapObject);
void StartKingTeresaMoveToGroupEntry(MissionRunMapObject *mapObject);
u32 ClearFadeFogHoldFramesWrapper(void);
void StartKingTeresaHitReaction(MissionRunMapObject *mapObject);
void ShowKingTeresaNearKart(MissionRunMapObject *mapObject);
void StartKingTeresaWaitToApproach(MissionRunMapObject *mapObject);
s32 AdvanceKingTeresaWaitToApproach(MissionRunMapObject *mapObject);
void StartKingTeresaApproachKart(MissionRunMapObject *mapObject);
s32 AdvanceKingTeresaApproachKart(MissionRunMapObject *mapObject);
void StartKingTeresaMoveToForwardPoint(MissionRunMapObject *mapObject);
s32 AdvanceKingTeresaFaceKart(MissionRunMapObject *mapObject);
s32 AdvanceKingTeresaFollowForwardPoint(MissionRunMapObject *mapObject);
void StartKingTeresaTurnTowardKart(MissionRunMapObject *mapObject);
void StartKingTeresaCoinsFadeOut(MissionRunMapObject *mapObject);
void StartKingTeresaTurnAwayFromKart(MissionRunMapObject *mapObject);
s32 AdvanceKingTeresaFollowKartClearFog(MissionRunMapObject *mapObject);
s32 AdvanceKingTeresaFollowKart(MissionRunMapObject *mapObject);
void SetKingTeresaVelocityToKartStep(MissionRunMapObject *mapObject);
void SetKingTeresaVelocityWithKartTurn(MissionRunMapObject *mapObject);
void HideKingTeresaWithEffects(MissionRunMapObject *mapObject);

extern MapObjectKindDescriptor gKingTeresaKindDescriptor;
extern const u16 gKingTeresaHiddenFlag;
extern const u16 gKingTeresaSkipListCallbackFlag;
extern const u16 gKingTeresaSkipViewTestFlag;
extern const u16 gKingTeresaNoPushOutFlag;

extern const u16 gMapObjectMirrorFlag;
extern const u32 gMapObjectItemHitReportFlag;
