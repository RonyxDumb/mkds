#pragma once

#include "types.h"
#include "01/MapObjects/mission_run_map_object.h"

typedef struct Kart Kart;
typedef struct MissionRunMapObject MissionRunMapObject;
typedef struct MapObjectList MapObjectList;

#include "01/MapObjects/kuriking_state_shared.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"

// Values of MissionRunMapObject.mFollowerIndex: the follower's place behind mFollowedObject; the distances
// (mFollower*Distance), animation frame offset and turn delay scale with it.
enum {
    HANACHAN_FOLLOWER_FIRST = 1,
    HANACHAN_FOLLOWER_SECOND,
    HANACHAN_FOLLOWER_THIRD,
    HANACHAN_FOLLOWER_FOURTH,
};

// MissionRunMapObject.mStateNumber while UpdateHanachanMoveState slows Hanachan for a kart inside one of its kart
// ranges.
#define HANACHAN_STATE_KART_RANGE_ANIMATION 3

MapObjectList *CreateHanachanFollowerUpdateList(void);
MapObjectList *CreateHanachanFollowerDrawList(void);
MapObjectKindData *CreateHanachanFollowerKindData(void);
MapObjectList *CreateHanachanUpdateList(void);
MapObjectList *CreateHanachanDrawList(void);
MapObjectKindData *CreateHanachanKindData(void);
void DrawHanachan(void *mapObjectList, MissionRunMapObject *mapObject);
void InitHanachanFollower(MapObjectList *mapObjectList);
void InitHanachan(MapObjectList *mapObjectList);
void HanachanKartHitCallback(MissionRunMapObject *mapObject, Kart *kart);
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
