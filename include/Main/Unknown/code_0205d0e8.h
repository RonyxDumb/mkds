#pragma once

#include "types.h"

typedef struct Unk0217aa1c_144_00 Unk0217aa1c_144_00;

void rres_205D0E8(u8 from, u8 to);
s32 rres_calculateMrRank(void);
s32 rres_calculateGpRank(void);
u8 rres_getPlace(u32 kart);
u8 rres_getWinCount(u32 kart);
u16 rres_getTotalRankPoints(u32 kart);
s32 rres_205D480(void);
s32 rres_getGlobalRank(u32 kart);
void rres_setTeamsResult(s32 winningTeam);
void rres_205D6D0(s32 team);
void rres_setGlobalPlace(s32 kart, u8 rank);
void rres_getRaceTime(Unk0217aa1c_144_00 *finishTime, u32 kart, u32 course);
void rres_setRaceTime(u32 kart, Unk0217aa1c_144_00 *finishTime);
void rres_setBattleResult(u32 kart, s32 b);
void rres_clearTotalRankPoints(u32 kart);
void rres_setPlaceAndPoints(u32 kart, s32 rank, u32 points);
u8 rres_205DB28(void);
void rres_reset(void);
