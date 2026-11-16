#pragma once

#include "types.h"
#include "01/MapObjects/mission_run_map_object.h"

typedef struct MissionRunMapObject MissionRunMapObject;
typedef struct Kart Kart;
typedef struct MapObjectList MapObjectList;

#include "Main/MapObjects/map_object_kind_update_list.h"

extern MapObjectKindDescriptor gKurikingKindDescriptor;

MapObjectList *CreateKurikingUpdateList(void);
MapObjectList *CreateKurikingDrawList(void);
MapObjectKindData *CreateKurikingKindData(void);
void DrawKuriking(
    void *mapObjectList,
    MissionRunMapObject *mapObject); /* only calls the two draw helpers shared with five other ov001 draw callbacks */
void InitKuriking(MapObjectList *mapObjectList);
void UpdateKuriking(
    u32 unused,
    MissionRunMapObject *mapObject); /* skipped for objects with MAP_OBJECT_FLAG_NO_UPDATE set (parked ones) */
void InitKurikingObjects(MapObjectList *mapObjectList);
void KurikingKartHitCallback(MissionRunMapObject *mapObject, Kart *kart);
void KurikingKartHitSoundCallback(MissionRunMapObject *mapObject, Kart *kart);
void InitKurikingMapObject(MissionRunMapObject *mapObject);
void StartKurikingChainStartupFirst(MissionRunMapObject *mapObject);
void StartKurikingChainStartupSecond(MissionRunMapObject *mapObject);
void StartKurikingStartupFirst(MissionRunMapObject *mapObject);
void StartKurikingStartupSecond(MissionRunMapObject *mapObject);
void StartKurikingWaitForRaceStart(MissionRunMapObject *mapObject);
s32 UpdateKurikingStartupEffects(MissionRunMapObject *mapObject);
s32 KurikingStopStateWhenRaceStarted(MissionRunMapObject *mapObject);
void KurikingStandingsEndCallback(void);
void StartKurikingKartNotEliminatedState(MissionRunMapObject *mapObject);
void StartKurikingEndEffects(MissionRunMapObject *mapObject);

extern const u16 gKurikingSkipViewTestFlag;
extern const u16 gKurikingJumpFlag;
extern const u16 gKurikingDisabledFlag;
extern const u16 gKurikingSkipListCallbackFlag;
