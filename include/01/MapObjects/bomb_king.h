#pragma once

#include "types.h"
#include "01/MapObjects/mission_run_map_object.h"

typedef struct MissionRunMapObject MissionRunMapObject;
typedef struct MapObjectList MapObjectList;
typedef struct ParticleEmitter ParticleEmitter;
typedef struct ItemObject ItemObject;

#include "01/MapObjects/kuriking_state_shared.h"
#include "Main/Sound/sound_source_list.h"

MapObjectList *CreateBombKingUpdateList(void);
MapObjectList *CreateBombKingDrawList(void);
MapObjectKindData *CreateBombKingKindData(void);
void DrawBombKing(void *mapObjectList, MissionRunMapObject *mapObject);
void InitBombKing(MapObjectList *list);
void BombKingItemHitCallback(MissionRunMapObject *mapObject, ItemObject *itemObject);
void BombKingItemBounceCallback(MissionRunMapObject *mapObject, ItemObject *itemObject);
void SetBombKingEffectScale(ParticleEmitter *emitter);
void InitBombKingMapObject(MissionRunMapObject *mapObject);
void UpdateBombKing(u32 unused, MissionRunMapObject *mapObject);
void InitBombKingObjects(MapObjectList *list);
void StartBombKingChainStartupFirst(MissionRunMapObject *mapObject);
void StartBombKingChainStartupSecond(MissionRunMapObject *mapObject);
void StartBombKingStartupFirst(MissionRunMapObject *mapObject);
void StartBombKingStartupSecond(MissionRunMapObject *mapObject);
void StartBombKingWaitForRaceStart(MissionRunMapObject *mapObject);
s32 StopStateWhenRaceStarted(MissionRunMapObject *mapObject);
void BombKingStandingsEndCallback(void);
void StartBombKingKartNotEliminatedState(MissionRunMapObject *mapObject);
void StartBombKingNotEliminatedEffects(MissionRunMapObject *mapObject);

extern SoundStartParams gBombKingEndSoundParams;
extern MapObjectKindDescriptor gBombKingKindDescriptor;

extern const u32 gBombKingSkipKindSoundFlag;
extern const u16 gBombKingSkipListCallbackFlag;
extern const u16 gBombKingJumpFlag;
extern const u16 gBombKingDisabledFlag;
extern const u16 gBombKingSkipViewTestFlag;
