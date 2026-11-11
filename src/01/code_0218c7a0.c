#include "01/code_0218c7a0.h"
#include "01/code_021882b8.h"
#include "01/code_02188cd8.h"

#include "01/code_02185ef4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b60c.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209b000.h"
#include "01/code_02181000.h"
#include "01/code_0218d4c8.h"
#include "01/code_0218e000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_02110000.h"
#include "01/code_0218155c.h"
#include "01/code_0219b250.h"
#include "01/code_0218dce4.h"
#include "01/code_02188484.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2300.h"
#include "01/code_02188000.h"
#include "01/code_0218d000.h"
#include "01/code_02188da4.h"
#include "01/code_02187000.h"
#include "01/code_0218d520.h"
#include "01/code_0218ddb4.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "01/code_0218d374.h"
#include "code_02147cd8.h"

void StartHanachanKartNotEliminatedState(MissionRunMapObject *mapObject) {
    int i;
    MapObjectList *list;
    MissionRunMapObject *follower;
    SoundStartParams soundRequest;

    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074);
    SetMapObjectModelNsbtpFrameIndex(mapObject->mNsbmd, 0);
    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mMapObjectCount && (follower = list->mMapObjects[i]) != NULL; i++) {
            StartMapObjectState(follower, 1, NULL);
            StartAnimationNoEndCallback(follower, follower->mPrm->mUnk_070, follower->mPrm->mUnk_074);
            SetMapObjectModelNsbtpFrameIndex((follower->mNsbmd), 0);
        }
    }
    soundRequest = gHanachanEndSoundParams;
    soundRequest.mPositionSource = &mapObject->mUnk_000.mPos;
    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&mapObject->mUnk_000.mPos);
    StartSndHandleSoundUnchecked(&soundRequest, GetSecondSndHandleSlot());
}

void HanachanStandingsEndCallback(void) {
    MapObjectList *list;
    MissionRunMapObject *follower;
    int i;

    ResetMissionRunMapObjects();
    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mMapObjectCount && (follower = list->mMapObjects[i]) != NULL; i++) {
            PlaceHanachanFollowerBehind(follower);
            CopyHanachanFollowerPreviousAngle(follower);
        }
    }
}

s32 UpdateHanachanWaitForRaceStart(MissionRunMapObject *mapObject) {
    int raceStarted;
    raceStarted = IsRaceStarted();
    if (raceStarted == 1) {
        StartHanachanMoveState(mapObject);
    }
    return 0;
}

void StartHanachanWaitForRaceStart(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, UpdateHanachanWaitForRaceStart);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_064, mapObject->mPrm->mUnk_068);
}

void StartHanachanStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_058, mapObject->mPrm->mUnk_05c,
                                  &StartHanachanWaitForRaceStart);
}

void StartHanachanStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_04c, mapObject->mPrm->mUnk_050);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_054, &StartHanachanStartupSecond);
}

void StartHanachanChainStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_040, mapObject->mPrm->mUnk_044);
}

void StartHanachanChainStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_034, mapObject->mPrm->mUnk_038);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_03c, &StartHanachanChainStartupSecond);
}

s32 UpdateFollowerWaitForRaceStart(MissionRunMapObject *mapObject) {
    int raceStarted;
    raceStarted = IsRaceStarted();
    if (raceStarted == 1) {
        StartHanachanFollowerMoveState(mapObject);
    }
    return 0;
}

s32 UpdateFollowerStartupEffects(MissionRunMapObject *mapObject) {
    int nsbcaFrameIndex;
    nsbcaFrameIndex = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
    if (nsbcaFrameIndex == 0x33) {
        ReleaseEffects(mapObject);
        StartEffectAtOffset(mapObject, (0xfffff666u), 0, (0x00000400u), (0x00000434u), 0);
    } else {
        nsbcaFrameIndex = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
        if (nsbcaFrameIndex == 0x66) {
            ReleaseEffects(mapObject);
            StartEffectAtOffset(mapObject, (0x0000099au), 0, (0x00000400u), (0x00000434u), 0);
        }
    }
    return 0;
}

void StartFollowerWaitForRaceStart(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, UpdateFollowerWaitForRaceStart);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_064, mapObject->mPrm->mUnk_068);
}

void StartHanachanFollowerStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, UpdateFollowerStartupEffects);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_058, mapObject->mPrm->mUnk_05c,
                                  &StartFollowerWaitForRaceStart);
}

void StartHanachanFollowerStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_04c, mapObject->mPrm->mUnk_050);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_054, &StartHanachanFollowerStartupSecond);
}

void StartFollowerChainStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_040, mapObject->mPrm->mUnk_044);
}

void StartFollowerChainStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_034, mapObject->mPrm->mUnk_038);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_03c, &StartFollowerChainStartupSecond);
}

void StartHanachanFollowerWaitAnimState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_064, mapObject->mPrm->mUnk_068);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_054, &StartHanachanFollowerStartupSecond);
}

void InitHanachanObjects(MapObjectList *mapObjectList) {
    int i;
    MissionRunMapObject *mapObject;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[i]) != NULL; i++) {
            mapObject->mUnk_2c4 = TRUE;
            if (GetRaceUseChainCameras() != 0) {
                StartHanachanChainStartupFirst(mapObject);
            } else {
                StartHanachanStartupFirst(mapObject);
            }
        }
    }
    SetStandingsEndCallback((void (*)(void)) HanachanStandingsEndCallback);
}

void UpdateHanachan(u32 unused, MissionRunMapObject *mapObject) {
    int result;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        result = IsWinnerDecided();
    } else {
        result = 0;
    }
    if (result != 0) {
        if (IsStateNumberBelow(mapObject, 1) != 0) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                result = IsKartEliminated((u16) gRaceSetup->mEntryIndex);
            } else {
                result = 0;
            }
            if (result != 0) {
                StartHanachanKartEliminatedState(mapObject);
            } else {
                StartHanachanKartNotEliminatedState(mapObject);
            }
        }
    } else {
        if (IsStateNumberBelow(mapObject, 1) != 0) {
            StartHanachanMoveStateByBalloons(mapObject);
        }
    }
    if (CollideSphereWithMapObjects(&mapObject->mPosWithOffset, &mapObject->mUnk_000.mPosStep,
                                    mapObject->mPrm->mUnk_100, mapObject->mUnk_000.mCollisionSlotIndex, 9, NULL) == 2) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x253);
    }
    AdvanceMissionRunMapObject(unused, mapObject);
}

void InitHanachanFollowerObjects(MapObjectList *mapObjectList) {
    int i;
    MissionRunMapObject *mapObject;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[i]) != NULL; i++) {
            if (GetRaceUseChainCameras() != 0) {
                StartFollowerChainStartupFirst(mapObject);
            } else if (i == 0) {
                StartHanachanFollowerStartupFirst(mapObject);
            } else {
                StartHanachanFollowerWaitAnimState(mapObject);
            }
        }
    }
}

void UpdateHanachanFollower(u32 unused, MissionRunMapObject *mapObject) {
    int collisionResult;
    PlaceHanachanFollowerBehindXz(mapObject);
    TurnHanachanFollowerToPrevious(mapObject);
    collisionResult =
        CollideSphereWithMapObjects(&mapObject->mPosWithOffset, &mapObject->mUnk_000.mPosStep,
                                    mapObject->mPrm->mUnk_100, mapObject->mUnk_000.mCollisionSlotIndex, 9, NULL);
    if (collisionResult == 2) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x253);
    }
    AdvanceMissionRunMapObject(unused, mapObject);
}

void InitHanachanMapObject(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstFollower;
    MissionRunMapObject *secondFollower;
    MissionRunMapObject *thirdFollower;
    MissionRunMapObject *fourthFollower;

    firstFollower = (MissionRunMapObject *) CreateMapObjectFromObject(&mapObject->mUnk_000, 0x1fe);
    secondFollower = (MissionRunMapObject *) CreateMapObjectFromObject(&mapObject->mUnk_000, 0x1fe);
    thirdFollower = (MissionRunMapObject *) CreateMapObjectFromObject(&mapObject->mUnk_000, 0x1fe);
    fourthFollower = (MissionRunMapObject *) CreateMapObjectFromObject(&mapObject->mUnk_000, 0x1fe);
    firstFollower->mUnk_0a4 = mapObject;
    secondFollower->mUnk_0a4 = firstFollower;
    thirdFollower->mUnk_0a4 = secondFollower;
    fourthFollower->mUnk_0a4 = thirdFollower;
    mapObject->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&mapObject->mUnk_000.mSound->mSoundSource, 0xd, &mapObject->mUnk_000.mPos);
    mapObject->mUnk_000.mFarDistanceSquared = gSoundFalloffs[13].mFarDistanceSquared;
}

void InitHanachanFollowerMapObject(MissionRunMapObject *mapObject) {
    mapObject->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&mapObject->mUnk_000.mSound->mSoundSource, 0xd, &mapObject->mUnk_000.mPos);
    mapObject->mUnk_000.mFarDistanceSquared = gSoundFalloffs[13].mFarDistanceSquared;
}

void HanachanKartHitCallback(MissionRunMapObject *mapObject, MissionRunPrm *kart) {
    s32 moveAngle;
    s32 diff;

    if (kart->mUnk_29c == 1) {
        if (mapObject->mTimer > 0) {
            mapObject->mUnk_2d8 = 0xc;
        } else {
            moveAngle = mapObject->mMoveAngle;
            diff = (u16) (FX_Atan2Idx(kart->mUnk_080 - mapObject->mUnk_000.mPos.x,
                                      kart->mUnk_088 - mapObject->mUnk_000.mPos.z) -
                          moveAngle);
            if (diff > 0x8000) {
                diff -= 0x10000;
            }
            if (diff > 0) {
                mapObject->mUnk_000.mPosStep.x =
                    MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_0fc, SIN_OF_ANGLE((u16) moveAngle + 0x4000));
                mapObject->mUnk_000.mPosStep.y = 0;
                mapObject->mUnk_000.mPosStep.z =
                    MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_0fc, COS_OF_ANGLE((u16) mapObject->mMoveAngle + 0x4000));
            } else {
                mapObject->mUnk_000.mPosStep.x =
                    MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_0fc, SIN_OF_ANGLE((u16) moveAngle - 0x4000));
                mapObject->mUnk_000.mPosStep.y = 0;
                mapObject->mUnk_000.mPosStep.z =
                    MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_0fc, COS_OF_ANGLE((u16) mapObject->mMoveAngle - 0x4000));
            }
            mapObject->mUnk_2d8 = 0xc;
            StartCameraWobbleAtDistance(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
            mapObject->mUnk_000.mDistanceSquaredAndFlags |= gHanachanSkipKindSoundFlag;
            StartSoundFullVolumeWrapper(kart, 0x252);
        }
    } else {
        mapObject->mUnk_2d8 = 0xa;
        StartCameraWobbleAtDistance(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
        mapObject->mUnk_000.mDistanceSquaredAndFlags |= gHanachanSkipKindSoundFlag;
        StartSoundFullVolumeWrapper(kart, 0x251);
    }
    SetKartCollisionCallback(mapObject, HanachanKartHitCallback);
}

void InitHanachan(MapObjectList *mapObjectList) {
    MissionRunMapObject *obj;
    s32 i;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[i]) != NULL; i++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(obj);
            }
            InitMissionRunMapObject(mapObjectList, obj, gHanachanNsbmdName, gHanachanNsbcaName, gHanachanPrmName);
            LoadMissionRunMapObjectShadow(mapObjectList, obj, gHanachanShadowNsbmdName);
            LoadMapObjectModelNsbtpAnimation(obj->mNsbmd, gHanachanNsbtpName);
            SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_008, obj->mPrm->mUnk_00c, obj->mPrm->mUnk_00c);
            SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
            SetKartCollisionCallback(obj, HanachanKartHitCallback);
            SetItemCollisionCallback(obj, HanachanItemHitCallback);
            obj->mUnk_0a8 = obj->mPrm->mUnk_12c;
        }
    }
}

void InitHanachanFollower(MapObjectList *mapObjectList) {
    void *firstNsbca;
    void *secondNsbca;
    void *firstNsbtp;
    MissionRunMapObject *obj;
    MissionRunMapObject *sourceObject;

    firstNsbca = LoadMissionRunFile(gHanachan1NsbcaName);
    secondNsbca = LoadMissionRunFile(gHanachan2NsbcaName);
    firstNsbtp = LoadMissionRunFile(gHanachan1NsbtpName);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        sourceObject =
            GetMissionRunMapObject(gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0);
    } else {
        sourceObject = NULL;
    }

    obj = mapObjectList->mMapObjects[0];
    obj->mPrm = sourceObject->mPrm;
    obj->mShadowNsbmd = sourceObject->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(mapObjectList, obj, gHanachan1NsbmdName, NULL, NULL);
    InitMapObjectModelNsbcaAnimation(obj->mNsbmd, firstNsbca);
    InitMapObjectModelNsbtpAnimation(obj->mNsbmd, firstNsbtp);
    obj->mUnk_0a8 = 1;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_0dc, obj->mPrm->mUnk_00c, sourceObject->mPrm->mUnk_00c);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
    SetKartCollisionCallback(obj, HanachanKartHitCallback);
    SetItemCollisionCallback(obj, HanachanItemHitCallback);

    obj = mapObjectList->mMapObjects[1];
    obj->mPrm = sourceObject->mPrm;
    obj->mShadowNsbmd = sourceObject->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(mapObjectList, obj, gHanachan2NsbmdName, NULL, NULL);
    InitMapObjectModelNsbcaAnimation(obj->mNsbmd, secondNsbca);
    InitMapObjectModelNsbtpAnimation(obj->mNsbmd, firstNsbtp);
    obj->mUnk_0a8 = 2;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_0e4, obj->mPrm->mUnk_00c, sourceObject->mPrm->mUnk_00c);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xd000);
    SetKartCollisionCallback(obj, HanachanKartHitCallback);
    SetItemCollisionCallback(obj, HanachanItemHitCallback);

    obj = mapObjectList->mMapObjects[2];
    obj->mPrm = sourceObject->mPrm;
    obj->mShadowNsbmd = sourceObject->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(mapObjectList, obj, gHanachan3NsbmdName, NULL, NULL);
    InitMapObjectModelNsbcaAnimation(obj->mNsbmd, firstNsbca);
    InitMapObjectModelNsbtpAnimation(obj->mNsbmd, firstNsbtp);
    obj->mUnk_0a8 = 3;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_0ec, obj->mPrm->mUnk_00c, sourceObject->mPrm->mUnk_00c);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
    SetKartCollisionCallback(obj, HanachanKartHitCallback);
    SetItemCollisionCallback(obj, HanachanItemHitCallback);

    obj = mapObjectList->mMapObjects[3];
    obj->mPrm = sourceObject->mPrm;
    obj->mShadowNsbmd = sourceObject->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(mapObjectList, obj, gHanachan4NsbmdName, NULL, NULL);
    InitMapObjectModelNsbcaAnimation(obj->mNsbmd, secondNsbca);
    InitMapObjectModelNsbtpAnimation(obj->mNsbmd, firstNsbtp);
    obj->mUnk_0a8 = 4;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mUnk_0f4, obj->mPrm->mUnk_00c, sourceObject->mPrm->mUnk_00c);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xd000);
    SetKartCollisionCallback(obj, HanachanKartHitCallback);
    SetItemCollisionCallback(obj, HanachanItemHitCallback);
}

void DrawHanachan(void *mapObjectList, MissionRunMapObject *mapObject) {
    DrawMissionRunMapObject(mapObjectList, mapObject);
    DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 0);
}

void CreateHanachanKindData(void) {
    void *kartCollision = &CollideKartWithMissionRunMapObject;
    void *itemCollision = &CollideItemWithMissionRunMapObject;
    void *sphereHit = &ComputeSphereHitOnMissionRunMapObject;
    void *kindData =
        CreateMapObjectKindDataWithSoundIds(kartCollision, itemCollision, sphereHit, 0x2u, 0x1u, 0x0u, 0x0u);
}

void *CreateHanachanDrawList(void) {
    return CreateMapObjectDrawList1(InitHanachan, DrawHanachan, NULL);
}

void *CreateHanachanUpdateList(void) {
    return CreateMapObjectUpdateList(InitHanachanObjects, UpdateHanachan, NULL);
}

void CreateHanachanFollowerKindData(void) {
    void *kartCollision = &CollideKartWithMissionRunMapObject;
    void *itemCollision = &CollideItemWithMissionRunMapObject;
    void *sphereHit = &ComputeSphereHitOnMissionRunMapObject;
    void *kindData =
        CreateMapObjectKindDataWithSoundIds(kartCollision, itemCollision, sphereHit, 0x2u, 0x1u, 0x0u, 0x0u);
}

void *CreateHanachanFollowerDrawList(void) {
    return CreateMapObjectDrawList1(InitHanachanFollower, DrawHanachan, ToggleShadowScale);
}

void *CreateHanachanFollowerUpdateList(void) {
    return CreateMapObjectUpdateList(InitHanachanFollowerObjects, UpdateHanachanFollower, NULL);
}
