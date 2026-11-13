#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct MissionRunPrm MissionRunPrm;
typedef struct MissionRunMapObject MissionRunMapObject;
typedef struct MapObjectList MapObjectList;

#include "01/code_0218b9b4.h"
#include "Main/Sound/sound_source_list.h"

MapObjectList *CreateHanachanFollowerUpdateList(void);
MapObjectList *CreateHanachanFollowerDrawList(void);
MapObjectKindData *CreateHanachanFollowerKindData(void);
MapObjectList *CreateHanachanUpdateList(void);
MapObjectList *CreateHanachanDrawList(void);
MapObjectKindData *CreateHanachanKindData(void);
void DrawHanachan(void *mapObjectList, MissionRunMapObject *mapObject);
void InitHanachanFollower(MapObjectList *mapObjectList);
void InitHanachan(MapObjectList *mapObjectList);
void HanachanKartHitCallback(MissionRunMapObject *mapObject, MissionRunPrm *kart);
void InitHanachanFollowerMapObject(MissionRunMapObject *mapObject);
void InitHanachanMapObject(MissionRunMapObject *mapObject);
void UpdateHanachanFollower(u32 unused, MissionRunMapObject *mapObject);
void InitHanachanFollowerObjects(MapObjectList *mapObjectList);
void UpdateHanachan(u32 unused, MissionRunMapObject *mapObject);
void InitHanachanObjects(MapObjectList *mapObjectList);
void StartHanachanFollowerWaitAnimState(MissionRunMapObject *mapObject);
void StartFollowerChainStartupFirst(MissionRunMapObject *mapObject);
void StartFollowerChainStartupSecond(MissionRunMapObject *mapObject);
void StartHanachanFollowerStartupFirst(MissionRunMapObject *mapObject);
void StartHanachanFollowerStartupSecond(MissionRunMapObject *mapObject);
void StartFollowerWaitForRaceStart(MissionRunMapObject *mapObject);
s32 UpdateFollowerStartupEffects(MissionRunMapObject *mapObject);
s32 UpdateFollowerWaitForRaceStart(MissionRunMapObject *mapObject);
void StartHanachanChainStartupFirst(MissionRunMapObject *mapObject);
void StartHanachanChainStartupSecond(MissionRunMapObject *mapObject);
void StartHanachanStartupFirst(MissionRunMapObject *mapObject);
void StartHanachanStartupSecond(MissionRunMapObject *mapObject);
void StartHanachanWaitForRaceStart(MissionRunMapObject *mapObject);
s32 UpdateHanachanWaitForRaceStart(MissionRunMapObject *mapObject);
void HanachanStandingsEndCallback(void);
void StartHanachanKartNotEliminatedState(MissionRunMapObject *mapObject);

extern const u32 gHanachanSkipKindSoundFlag;
extern SoundStartParams gHanachanEndSoundParams;
extern MapObjectKindDescriptor gHanachanKindDescriptor;
extern MapObjectKindDescriptor gHanachanFollowerKindDescriptor;
