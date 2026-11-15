#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/data_020a7000.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "tp.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

#define SHINE_BATTLE_START_FRAMES 0x5a

// Object of the list FindMapObjectKindUpdateList(0x6b): the shared MapObject part, then three words.
typedef struct ShineBattle {
    /* 00 */ MapObject mMapObject;
    /* a0 */ BOOL mHasShine;
    /* a4 */ BOOL mSkipRandomPick;
    /* a8 */ s32 mShineStartFrames;
} ShineBattle;

void ClearShineBattleObjectShine(s32 spawnObjectIndex);
MapObjectList *CreateShineBattleUpdateList(void);
MapObjectKindData *CreateShineBattleKindData(void);
void UpdateShineBattle(MapObjectList *mapObjectList, ShineBattle *shineBattle);
void StartShineBattle(MapObjectList *mapObjectList);
BOOL TryStartShine16AtRandomObject(MapObjectList *mapObjectList);

void InitShineBattleObjects(MapObject *mapObject);

extern const u16 gShine16CollisionFlag;
extern const MapObjectKindDescriptor gShineBattleKindDescriptor;
