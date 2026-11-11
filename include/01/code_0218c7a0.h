#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct MissionRunPrm MissionRunPrm;
typedef struct Unk02188950 Unk02188950;
typedef struct MapObjectList MapObjectList;

void *CreateHanachanFollowerUpdateList(void);
void *CreateHanachanFollowerDrawList(void);
void CreateHanachanFollowerKindData(void);
void *CreateHanachanUpdateList(void);
void *CreateHanachanDrawList(void);
void CreateHanachanKindData(void);
void DrawHanachan(void *mapObjectList, Unk02188950 *mapObject);
void InitHanachanFollower(MapObjectList *mapObjectList);
void InitHanachan(MapObjectList *mapObjectList);
void HanachanKartHitCallback(Unk02188950 *mapObject, MissionRunPrm *kart);
void InitHanachanFollowerMapObject(Unk02188950 *mapObject);
void InitHanachanMapObject(Unk02188950 *mapObject);
void UpdateHanachanFollower(u32 unused, Unk02188950 *mapObject);
void InitHanachanFollowerObjects(MapObjectList *mapObjectList);
void UpdateHanachan(u32 unused, Unk02188950 *mapObject);
void InitHanachanObjects(MapObjectList *mapObjectList);
void StartHanachanFollowerWaitAnimState(Unk02188950 *mapObject);
void StartFollowerChainStartupFirst(Unk02188950 *mapObject);
void StartFollowerChainStartupSecond(Unk02188950 *mapObject);
void StartHanachanFollowerStartupFirst(Unk02188950 *mapObject);
void StartHanachanFollowerStartupSecond(Unk02188950 *mapObject);
void StartFollowerWaitForRaceStart(Unk02188950 *mapObject);
s32 UpdateFollowerStartupEffects(Unk02188950 *mapObject);
s32 UpdateFollowerWaitForRaceStart(Unk02188950 *mapObject);
void StartHanachanChainStartupFirst(Unk02188950 *mapObject);
void StartHanachanChainStartupSecond(Unk02188950 *mapObject);
void StartHanachanStartupFirst(Unk02188950 *mapObject);
void StartHanachanStartupSecond(Unk02188950 *mapObject);
void StartHanachanWaitForRaceStart(Unk02188950 *mapObject);
s32 UpdateHanachanWaitForRaceStart(Unk02188950 *mapObject);
void HanachanStandingsEndCallback(void);
void StartHanachanKartNotEliminatedState(Unk02188950 *mapObject);
