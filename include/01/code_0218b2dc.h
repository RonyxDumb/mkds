#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct Unk02188950 Unk02188950;
typedef struct Unk021a7b64 Unk021a7b64;
typedef struct MapObjectList MapObjectList;

extern Unk021a7b64 gKurikingKindDescriptor;

void *CreateKurikingUpdateList(void);
void *CreateKurikingDrawList(void);
void CreateKurikingKindData(void);
void DrawKuriking(
    void *mapObjectList,
    Unk02188950 *mapObject); /* only calls the two draw helpers shared with five other ov001 draw callbacks */
void InitKuriking(MapObjectList *mapObjectList);
void UpdateKuriking(u32 unused, Unk02188950 *mapObject); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitKurikingObjects(MapObjectList *mapObjectList);
void KurikingKartHitCallback(Unk02188950 *mapObject, void *kart);
void KurikingKartHitSoundCallback(Unk02188950 *mapObject, void *kart);
void InitKurikingMapObject(Unk02188950 *mapObject);
void StartKurikingChainStartupFirst(Unk02188950 *mapObject);
void StartKurikingChainStartupSecond(Unk02188950 *mapObject);
void StartKurikingStartupFirst(Unk02188950 *mapObject);
void StartKurikingStartupSecond(Unk02188950 *mapObject);
void StartKurikingWaitForRaceStart(Unk02188950 *mapObject);
s32 UpdateKurikingStartupEffects(Unk02188950 *mapObject);
s32 KurikingStopStateWhenRaceStarted(Unk02188950 *mapObject);
void KurikingStandingsEndCallback(void);
void StartKurikingKartNotEliminatedState(Unk02188950 *mapObject);
void StartKurikingEndEffects(Unk02188950 *mapObject);
