#include "Main/Unknown/code_020a6cb4.h"
#include "Main/Unknown/code_020a10f0.h"

#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a3f2c.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020a7148.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_02077bc0.h"

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
    s32 i;
    s32 v1;
    ShineBattle *e;
    BOOL f;
    u32 n;
    u32 m;
    u32 r;
    u16 v2;
    u32 k;
    RandomState64 *mapObjectRandom;

    v1 = 0;
    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (e = mapObjectList->mMapObjects[i]) != NULL; i++) {
            f = FALSE;
            if (e->mHasShine == FALSE) {
                if (e->mSkipRandomPick == FALSE) {
                    f = TRUE;
                }
            }
            v1 += f;
        }
    }
    if (v1 > 0) {
        n = (u16) v1;
        if (n == 0x10000) {
            mapObjectRandom = GetMapObjectRandom();
            mapObjectRandom->mValue =
                (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
            v2 = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 0x10000) >> 32;
        } else {
            mapObjectRandom = GetMapObjectRandom();
            if ((u16) n == 0) {
                r = 0;
            } else {
                mapObjectRandom->mValue =
                    (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                m = (u16) n;
                if (m == 0) {
                    r = mapObjectRandom->mValue >> 32;
                } else {
                    r = ((mapObjectRandom->mValue >> 32) * m) >> 32;
                }
            }
            v2 = r;
        }
        k = v2;
        if (mapObjectList != NULL) {
            for (i = 0; i < mapObjectList->mMapObjectCount && (e = mapObjectList->mMapObjects[i]) != NULL; i++) {
                if (e->mHasShine == FALSE && e->mSkipRandomPick == FALSE) {
                    if (k-- == 0) {
                        StartShine16(&e->mUnk_00.mPos, i, 1);
                        e->mHasShine = TRUE;
                        return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}

void StartShineBattle(MapObjectList *mapObjectList) {
    s32 i;
    s32 n;
    s32 j;
    s32 v;
    BOOL f;
    ShineBattle *e;

    n = gRaceSetup->mKartCount;
    for (i = 0; i < n; i++) {
        if (i == gRaceSetup->mEntryIndex) {
            f = FALSE;
            v = gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mKind;
            if ((u32) v <= 3) {
                if ((1 << v) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                    f = TRUE;
                }
            }
            if (f != FALSE) {
                continue;
            }
        }
        StartShineBalloon(GetKart((u16) i));
    }
    if (mapObjectList == NULL) {
        return;
    }
    for (j = 0; j < mapObjectList->mMapObjectCount && (e = mapObjectList->mMapObjects[j]) != NULL; j++) {
        e->mSkipRandomPick = TRUE;
        if (e->mUnk_00.mCourseMapRow->mUnk_28 != 0) {
            n = gRaceSetup->mKartCount;
            v = GetShineCount();
            if (v + GetTotalBalloonOrShineCount() < n + 1) {
                StartShine16(&e->mUnk_00.mPos, j, GetRaceUseChainCameras());
                e->mHasShine = TRUE;
            }
        }
    }
}

void UpdateShineBattle(MapObjectList *mapObjectList, ShineBattle *shineBattle) {
    s32 n;
    s32 v;

    if (GetShineCount() >= 3) {
        return;
    }
    n = gRaceSetup->mKartCount;
    v = GetShineCount();
    if (v + GetTotalBalloonOrShineCount() >= n + 1) {
        return;
    }
    shineBattle->mShineStartFrames += 1;
    if (shineBattle->mShineStartFrames <= 0x5a) {
        return;
    }
    shineBattle->mShineStartFrames = 0;
    while (GetShineCount() < 3 &&
           (n = gRaceSetup->mKartCount, v = GetShineCount(), v + GetTotalBalloonOrShineCount() < n + 1)) {
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
    ShineBattle *e;
    s32 i;

    mapObjectList = FindMapObjectKindUpdateList(0x6b);
    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (e = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (i == spawnObjectIndex) {
            e->mHasShine = FALSE;
            e->mSkipRandomPick = TRUE;
        } else {
            e->mSkipRandomPick = FALSE;
        }
    }
}
