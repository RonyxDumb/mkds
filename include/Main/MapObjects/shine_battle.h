#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/sanbo_pieces.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

#define SHINE_BATTLE_START_FRAMES 0x5a

// The shine battle map object: whether a shine is held, the random pick skip and the shine start frames.
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
