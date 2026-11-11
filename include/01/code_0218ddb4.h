#pragma once

#include "types.h"

typedef struct Unk02188950 Unk02188950;
typedef struct MapObjectList MapObjectList;
typedef struct Kart Kart;

void *CreateKingTeresaUpdateList(void);
void *CreateKingTeresaDrawList(void);
void CreateKingTeresaKindData(void);
void DrawKingTeresa(void *mapObjectList, Unk02188950 *mapObject);
void InitKingTeresa(MapObjectList *mapObjectList);
void UpdateKingTeresa(u32 unused, Unk02188950 *mapObject);
void InitKingTeresaObjects(MapObjectList *mapObjectList);
void KingTeresaBossTransferCallback(Unk02188950 *mapObject, Kart *kart);
void KingTeresaHitReactionCallback(Unk02188950 *mapObject);
void KingTeresaParkBossCoinsCallback(Unk02188950 *mapObject, Kart *kart);
void InitKingTeresaMapObject(Unk02188950 *mapObject);
void StartKingTeresaZeroAlphaWait(Unk02188950 *mapObject);
void ShowKingTeresaAfterWait(Unk02188950 *mapObject);
void StartKingTeresaFirstAnimation(Unk02188950 *mapObject);
void StartKingTeresaSecondAnimation(Unk02188950 *mapObject);
void KingTeresaStandingsEndCallback(void);
void StartKingTeresaWinnerDecidedHold(Unk02188950 *mapObject);
void ShowKingTeresaAtEndReached(Unk02188950 *mapObject);
s32 AdvanceKingTeresaEndReachedSound(Unk02188950 *mapObject);
void HideKingTeresaAtEndReached(Unk02188950 *mapObject);
void StartKingTeresaKartEliminatedHold(Unk02188950 *mapObject);
void StartKingTeresaHideThenState1(Unk02188950 *mapObject);
void StartKingTeresaState1ShadowOffset(Unk02188950 *mapObject);
void HideKingTeresaWithoutEffects(Unk02188950 *mapObject);
void StartKingTeresaHideThenCoinsFadeIn(Unk02188950 *mapObject);
void StartKingTeresaCoinsFadeIn(Unk02188950 *mapObject);
void StartKingTeresaStopForBossCoins(Unk02188950 *mapObject);
void StartKingTeresaShowBossCoins(Unk02188950 *mapObject);
u32 AdvanceKingTeresaSinkToCourseRow(Unk02188950 *mapObject);
void StartKingTeresaHideForNextGroup(Unk02188950 *mapObject);
void ShowKingTeresaAtGroupEntry(Unk02188950 *mapObject);
void StartKingTeresaMoveToGroupEntry(Unk02188950 *mapObject);
u32 ClearFadeFogHoldFramesWrapper(void);
void StartKingTeresaHitReaction(Unk02188950 *mapObject);
void ShowKingTeresaNearKart(Unk02188950 *mapObject);
void StartKingTeresaWaitToApproach(Unk02188950 *mapObject);
s32 AdvanceKingTeresaWaitToApproach(Unk02188950 *mapObject);
void StartKingTeresaApproachKart(Unk02188950 *mapObject);
s32 AdvanceKingTeresaApproachKart(Unk02188950 *mapObject);
void StartKingTeresaMoveToForwardPoint(Unk02188950 *mapObject);
s32 AdvanceKingTeresaFaceKart(Unk02188950 *mapObject);
s32 AdvanceKingTeresaFollowForwardPoint(Unk02188950 *mapObject);
void StartKingTeresaTurnTowardKart(Unk02188950 *mapObject);
void StartKingTeresaCoinsFadeOut(Unk02188950 *mapObject);
void StartKingTeresaTurnAwayFromKart(Unk02188950 *mapObject);
s32 AdvanceKingTeresaFollowKartClearFog(Unk02188950 *mapObject);
s32 AdvanceKingTeresaFollowKart(Unk02188950 *mapObject);
void SetKingTeresaVelocityToKartStep(Unk02188950 *mapObject);
void SetKingTeresaVelocityWithKartTurn(Unk02188950 *mapObject);
void HideKingTeresaWithEffects(Unk02188950 *mapObject);
