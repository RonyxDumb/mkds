#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct MissionRunMapObject MissionRunMapObject;
typedef struct MapObjectList MapObjectList;
typedef struct ParticleEmitter ParticleEmitter;
typedef struct ItemObject ItemObject;

void *CreateBombKingUpdateList(void);
void *CreateBombKingDrawList(void);
void CreateBombKingKindData(void);
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
