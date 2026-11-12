#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject

// Object of the list FindMapObjectKindUpdateList(0x6b): the shared MapObject part, then three words.
typedef struct ShineBattle {
    /* 00 */ MapObject mMapObject;
    /* a0 */ BOOL mHasShine;
    /* a4 */ BOOL mSkipRandomPick;
    /* a8 */ s32 mShineStartFrames;
} ShineBattle;

void ClearShineBattleObjectShine(s32 spawnObjectIndex);
void *CreateShineBattleUpdateList(void);
MapObjectKindData *CreateShineBattleKindData(void);
void UpdateShineBattle(MapObjectList *mapObjectList, ShineBattle *shineBattle);
void StartShineBattle(MapObjectList *mapObjectList);
BOOL TryStartShine16AtRandomObject(MapObjectList *mapObjectList);
