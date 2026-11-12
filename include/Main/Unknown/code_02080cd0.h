#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/kart_effects_ahead.h"

void ResetPointLinkCursor(PointLinkCursor *linkCursor, RacePointLink *pointLink);
void InitRacePointLinkCursor(PointLinkCursor *racePointLinkCursor, u16 kartIndex);
BOOL IsPastBattlePointLink(LinkCursor *linkCursor, Vec3 *position);
BOOL IsWithinBattlePointLinkDistance(LinkCursor *linkCursor, Vec3 *position);
void SetEffectScaleFromKartScaleZ(ParticleEmitter *effect, Kart *kart);
void ReleaseKartNearRankEffect(Kart *kart);
void StopKartNearRankEffect(Kart *kart);
void StartKartNearRankEffect(Kart *kart);
void ReleaseKartAheadEffect(Kart *kart);
void StopKartAheadEffect(Kart *kart);
void StartKartAheadEffectIfSelectedEntry(Kart *kart);
