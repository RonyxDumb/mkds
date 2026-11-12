#include "Main/MapObjects/shine_battle.h"
#include "Main/Unknown/code_020a10f0.h"

#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/MapObjects/shine16.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020a7148.h"
#include "Main/MapObjects/bound.h"
#include "Main/Kart/karts.h"

void InitShineBattleObjects(MapObject *mapObject) {
    if (CountMapObjectsOfKind(MAP_OBJECT_KIND_SHINE16) == 0) {
        CreateParkedMapObjects(MAP_OBJECT_KIND_SHINE16, 0x14, mapObject);
        CreateParkedMapObjects(MAP_OBJECT_KIND_SHINE_BALLOON, gRaceSetup->mKartCount, mapObject);
        SetStandingsKartHitCallback(ShineKartHitCallback);
        SetStandingsKartEliminatedCallback(ShineKartEliminatedCallback);
        SetStandingsEndCallback(ShineEndCallback);
        return;
    }
    ParkMapObject(mapObject);
}

BOOL TryStartShine16AtRandomObject(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    s32 candidateCount;
    ShineBattle *shineBattle;
    BOOL eligible;
    u32 range;
    u32 rangeLow;
    u32 randomValue;
    u16 pickedIndex;
    u32 remaining;
    RandomState64 *mapObjectRandom;

    candidateCount = 0;
    if (mapObjectList != NULL) {
        for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                                 (shineBattle = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
             mapObjectIndex++) {
            eligible = FALSE;
            if (shineBattle->mHasShine == FALSE) {
                if (shineBattle->mSkipRandomPick == FALSE) {
                    eligible = TRUE;
                }
            }
            candidateCount += eligible;
        }
    }
    if (candidateCount > 0) {
        range = (u16) candidateCount;
        if (range == 0x10000) {
            mapObjectRandom = GetMapObjectRandom();
            mapObjectRandom->mValue =
                (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
            pickedIndex = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 0x10000) >> 32;
        } else {
            mapObjectRandom = GetMapObjectRandom();
            if ((u16) range == 0) {
                randomValue = 0;
            } else {
                mapObjectRandom->mValue =
                    (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                rangeLow = (u16) range;
                if (rangeLow == 0) {
                    randomValue = mapObjectRandom->mValue >> 32;
                } else {
                    randomValue = ((mapObjectRandom->mValue >> 32) * rangeLow) >> 32;
                }
            }
            pickedIndex = randomValue;
        }
        remaining = pickedIndex;
        if (mapObjectList != NULL) {
            for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                                     (shineBattle = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
                 mapObjectIndex++) {
                if (shineBattle->mHasShine == FALSE && shineBattle->mSkipRandomPick == FALSE) {
                    if (remaining-- == 0) {
                        StartShine16(&shineBattle->mMapObject.mPos, mapObjectIndex, 1);
                        shineBattle->mHasShine = TRUE;
                        return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}

void StartShineBattle(MapObjectList *mapObjectList) {
    s32 kartIndex;
    s32 kartCount;
    s32 mapObjectIndex;
    s32 value;
    BOOL flag;
    ShineBattle *shineBattle;

    kartCount = gRaceSetup->mKartCount;
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        if (kartIndex == gRaceSetup->mEntryIndex) {
            flag = FALSE;
            value = GetCurrentEntry(kartIndex)->mPlayer.mKind;
            if ((u32) value <= 3) {
                if ((1 << value) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                    flag = TRUE;
                }
            }
            if (flag != FALSE) {
                continue;
            }
        }
        StartShineBalloon(GetKart((u16) kartIndex));
    }
    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (shineBattle = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        shineBattle->mSkipRandomPick = TRUE;
        if (shineBattle->mMapObject.mCourseMapRow->mSettings[0] != 0) {
            kartCount = gRaceSetup->mKartCount;
            value = GetShineCount();
            if (value + GetTotalBalloonOrShineCount() < kartCount + 1) {
                StartShine16(&shineBattle->mMapObject.mPos, mapObjectIndex, GetRaceUseChainCameras());
                shineBattle->mHasShine = TRUE;
            }
        }
    }
}

void UpdateShineBattle(MapObjectList *mapObjectList, ShineBattle *shineBattle) {
    s32 kartCount;
    s32 shineCount;

    if (GetShineCount() >= 3) {
        return;
    }
    kartCount = gRaceSetup->mKartCount;
    shineCount = GetShineCount();
    if (shineCount + GetTotalBalloonOrShineCount() >= kartCount + 1) {
        return;
    }
    shineBattle->mShineStartFrames += 1;
    if (shineBattle->mShineStartFrames <= 0x5a) {
        return;
    }
    shineBattle->mShineStartFrames = 0;
    while (GetShineCount() < 3 && (kartCount = gRaceSetup->mKartCount, shineCount = GetShineCount(),
                                   shineCount + GetTotalBalloonOrShineCount() < kartCount + 1)) {
        if (TryStartShine16AtRandomObject(mapObjectList) == FALSE) {
            return;
        }
    }
}

MapObjectKindData *CreateShineBattleKindData(void) {
    if (gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
        return CreateEmptyMapObjectKindData();
    }
    return 0;
}

void *CreateShineBattleUpdateList(void) {
    return CreateMapObjectUpdateList(StartShineBattle, UpdateShineBattle, NULL);
}

void ClearShineBattleObjectShine(s32 spawnObjectIndex) {
    MapObjectList *mapObjectList;
    ShineBattle *shineBattle;
    s32 mapObjectIndex;

    mapObjectList = FindMapObjectKindUpdateList(0x6b);
    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (shineBattle = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        if (mapObjectIndex == spawnObjectIndex) {
            shineBattle->mHasShine = FALSE;
            shineBattle->mSkipRandomPick = TRUE;
        } else {
            shineBattle->mSkipRandomPick = FALSE;
        }
    }
}
