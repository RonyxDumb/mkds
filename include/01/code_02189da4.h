#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct Unk02188950 Unk02188950;
typedef struct MapObjectList MapObjectList;
typedef struct Unk0201ca6c Unk0201ca6c;
typedef struct ItemObject ItemObject;

void *CreateBombKingUpdateList(void);
void *CreateBombKingDrawList(void);
void CreateBombKingKindData(void);
void DrawBombKing(void *mapObjectList, Unk02188950 *mapObject);
void InitBombKing(MapObjectList *list);
void BombKingItemHitCallback(Unk02188950 *mapObject, ItemObject *itemObject);
void BombKingItemBounceCallback(Unk02188950 *mapObject, ItemObject *itemObject);
void SetBombKingEffectScale(Unk0201ca6c *emitter);
void InitBombKingMapObject(Unk02188950 *mapObject);
void UpdateBombKing(u32 unused, Unk02188950 *mapObject);
void InitBombKingObjects(MapObjectList *list);
void StartBombKingChainStartupFirst(Unk02188950 *mapObject);
void StartBombKingChainStartupSecond(Unk02188950 *mapObject);
void StartBombKingStartupFirst(Unk02188950 *mapObject);
void StartBombKingStartupSecond(Unk02188950 *mapObject);
void StartBombKingWaitForRaceStart(Unk02188950 *mapObject);
s32 StopStateWhenRaceStarted(Unk02188950 *mapObject);
void BombKingStandingsEndCallback(void);
void StartBombKingKartNotEliminatedState(Unk02188950 *mapObject);
void StartBombKingNotEliminatedEffects(Unk02188950 *mapObject);
