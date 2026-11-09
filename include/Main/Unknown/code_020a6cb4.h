#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of the list FindMapObjectKindUpdateList(0x6b): the shared MapObject part, then three words.
typedef struct ShineBattle {
    /* 00 */ MapObject mUnk_00;
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
