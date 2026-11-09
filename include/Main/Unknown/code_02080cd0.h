#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207ffa4.h"

void ResetPointLinkCursor(PointLinkCursor *linkCursor, RacePointLink *pointLink);
void InitRacePointLinkCursor(PointLinkCursor *racePointLinkCursor, u16 kartIndex);
BOOL IsPastBattlePointLink(LinkCursor *linkCursor, Vec3 *position);
BOOL IsWithinBattlePointLinkDistance(LinkCursor *linkCursor, Vec3 *position);
void func_02080e88(Unk0201ca6c *effect, Kart *kart);
void func_02080e9c(Kart *kart);
void func_02080ee4(Kart *kart);
void func_02080f44(Kart *kart);
void func_02080fb8(Kart *kart);
void func_02081000(Kart *kart);
void StartKartAheadEffectIfSelectedEntry(Kart *kart);
