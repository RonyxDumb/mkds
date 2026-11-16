#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/kart_effects_ahead.h"

void ResetPointLinkCursor(PointLinkCursor *linkCursor, RacePointLink *pointLink);
void InitRacePointLinkCursor(PointLinkCursor *racePointLinkCursor, u16 kartIndex);
BOOL IsPastBattlePointLink(LinkCursor *linkCursor, Vec3 *position);
BOOL IsWithinBattlePointLinkDistance(LinkCursor *linkCursor, Vec3 *position);
void SetEffectScaleFromKartScaleZ(ParticleEmitter *effect, Kart *kart);
void StructMQRacerEntry_SomeFn_23(Kart *kart);
void StructMQRacerEntry_SomeFn_3(Kart *kart);
void StructMQRacerEntry_SomeFn_62(Kart *kart);
void StructMQRacerEntry_SomeFn_22(Kart *kart);
void StructMQRacerEntry_SomeFn_69(Kart *kart);
void StartKartAheadEffectIfSelectedEntry(Kart *kart);
