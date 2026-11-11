#include "01/code_0218b2dc.h"
#include "01/code_021882b8.h"
#include "01/code_02188cd8.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_0210b000.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b60c.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0218b9b4.h"
#include "01/unk_021a6000.h"
#include "01/code_02188000.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_020d4000.h"
#include "01/code_02185ef4.h"
#include "01/code_02187d14.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020ac000.h"
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
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02109000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_021000d0.h"
#include "code_02147cd8.h"

Unk021a7b64 gKurikingKindDescriptor = {
    0, 0x30c, InitKurikingMapObject,    CreateKurikingKindData, CreateKurikingDrawList,
    0, 0,     CreateKurikingUpdateList, {0, 0, 0, 0, 0},
};

void StartKurikingEndEffects(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(Unk02188950 *))(0));
    StartEffect(0x418, &mapObject->mUnk_000.mPos);
    StartEffect(0x417, &mapObject->mUnk_000.mPos);
    StartEffect(0x416, &mapObject->mUnk_000.mPos);
    {
        SoundStartParams soundRequest = {0x225, 0, 0xf, 0};

        soundRequest.mPositionSource = &mapObject->mUnk_000.mPos;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(soundRequest.mPositionSource);
        StartSndHandleSoundUnchecked(&soundRequest, GetSecondSndHandleSlot());
    }
    mapObject->mUnk_000.mFlags |= gKurikingSkipViewTestFlag;
    mapObject->mUnk_000.mFlags |= gKurikingSkipListCallbackFlag;
    mapObject->mUnk_000.mFlags |= gKurikingDisabledFlag;
}

void StartKurikingKartNotEliminatedState(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074);
    StartStateFrameCountCallback(mapObject, 0x3c, &StartKurikingEndEffects);
}

void KurikingStandingsEndCallback(void) {
    ResetMissionRunMapObjects();
}

s32 KurikingStopStateWhenRaceStarted(Unk02188950 *mapObject) {
    int raceStarted;
    raceStarted = IsRaceStarted();
    if (raceStarted == 1) {
        StopMapObjectState(mapObject);
    }
    return 0;
}

s32 UpdateKurikingStartupEffects(Unk02188950 *mapObject) {
    int nsbcaFrameIndex;
    nsbcaFrameIndex = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
    if (nsbcaFrameIndex == 0x4d) {
        ReleaseEffects(mapObject);
        StartEffectAtRowHeight(mapObject, (0xfffff99au), 0, (0xfffff99au), (0x0000042bu), 0);
        StartMapObjectSound(&mapObject->mUnk_000, (0x0000021eu));
    } else {
        nsbcaFrameIndex = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
        if (nsbcaFrameIndex == 0x68) {
            ReleaseEffects(mapObject);
            StartEffectAtRowHeight(mapObject, (0xfffff99au), 0, (0xfffff99au), (0x0000042cu), 0);
            StartMapObjectSound(&mapObject->mUnk_000, (0x0000021fu));
        }
    }
    return 0;
}

void StartKurikingWaitForRaceStart(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, KurikingStopStateWhenRaceStarted);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_064, mapObject->mPrm->mUnk_068);
}

void StartKurikingStartupSecond(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, UpdateKurikingStartupEffects);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_058, mapObject->mPrm->mUnk_05c,
                                  &StartKurikingWaitForRaceStart);
}

void StartKurikingStartupFirst(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_04c, mapObject->mPrm->mUnk_050);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_054, &StartKurikingStartupSecond);
}

void StartKurikingChainStartupSecond(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_040, mapObject->mPrm->mUnk_044);
}

void StartKurikingChainStartupFirst(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_034, mapObject->mPrm->mUnk_038);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_03c, &StartKurikingChainStartupSecond);
}

void InitKurikingMapObject(Unk02188950 *mapObject) {
    CreateParkedMapObjects(MAP_OBJECT_KIND_KURIBO, 0x32, mapObject);
    mapObject->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&mapObject->mUnk_000.mSound->mSoundSource, 0xf, &mapObject->mUnk_000.mPos);
    mapObject->mUnk_000.mFarDistanceSquared = gSoundFalloffWordsSecond[15];
}

void KurikingKartHitSoundCallback(Unk02188950 *mapObject, void *kart) {
    SetKartCollisionCallback(mapObject, KurikingKartHitSoundCallback);
    if (mapObject->mTimer == 0) {
        StartSoundFullVolumeWrapper(kart, 0x224);
    }
}

void KurikingKartHitCallback(Unk02188950 *mapObject, void *kart) {
    mapObject->mUnk_000.mPosStep.x =
        MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_130, FX_SinIdx((u16) mapObject->mMoveAngle));
    mapObject->mUnk_000.mPosStep.y = 0;
    mapObject->mUnk_000.mPosStep.z =
        MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_130, FX_CosIdx((u16) mapObject->mMoveAngle));
    mapObject->mUnk_2d8 = 0xd;
    StartCameraWobbleAtDistance(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    SetKartCollisionCallback(mapObject, KurikingKartHitSoundCallback);
    if (mapObject->mTimer == 0) {
        StartSoundFullVolumeWrapper(kart, 0x224);
    }
}

void InitKurikingObjects(MapObjectList *mapObjectList) {
    s32 i;
    Unk02188950 *obj;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[i]) != NULL; i++) {
            StartMapObjectModelNsbtaAnimation(obj->mNsbmd, obj->mPrm->mUnk_080, obj->mPrm->mUnk_050, 0);
            if (GetRaceUseChainCameras()) {
                StartKurikingChainStartupFirst(obj);
            } else {
                StartKurikingStartupFirst(obj);
            }
        }
    }
    SetStandingsEndCallback((void (*)(void)) KurikingStandingsEndCallback);
}

void UpdateKuriking(u32 unused, Unk02188950 *mapObject) {
    s32 var;

    if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) {
        if (IsStateNumberBelow(mapObject, 1)) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0) {
                StartKurikingChaseKartState(mapObject);
            } else {
                StartKurikingKartNotEliminatedState(mapObject);
            }
        }
    } else {
        if (IsPointInRange(mapObject, &GetCurrentGroupEntry(mapObject)->mPos, mapObject->mPrm->mUnk_0b4, 0)) {
            var = GetCurrentGroupEntryValue(mapObject);
            if (var >= 200) {
                if (IsStateNumberBelow(mapObject, 8)) {
                    GrowKuriking(mapObject);
                    SetKartCollisionCallback(mapObject, KurikingKartHitSoundCallback);
                }
            } else if (var >= 100) {
                if (IsStateNumberBelow(mapObject, 7)) {
                    StartKurikingTurnToRowState(mapObject);
                    SetKartCollisionCallback(mapObject, KurikingKartHitSoundCallback);
                }
            } else if (var >= 1) {
                if (IsStateNumberBelow(mapObject, 1)) {
                    StartKurikingFaceKartState(mapObject);
                    SetKartCollisionCallback(mapObject, KurikingKartHitSoundCallback);
                }
            }
            IncrementEntryIndex(mapObject);
            if (mapObject->mEntryIndex == 0) {
                IncrementEntryGroupIndex(mapObject, 3);
            }
        }
        if (IsStateNumberBelow(mapObject, 2)) {
            if (GetEntryKartInRange(mapObject, mapObject->mPrm->mUnk_124, mapObject->mPrm->mUnk_128)) {
                StartKurikingKartInRangeState(mapObject);
                SetKartCollisionCallback(mapObject, KurikingKartHitCallback);
            }
        }
        if (IsStateNumberBelow(mapObject, 1)) {
            StartKurikingWalkState(mapObject);
            SetKartCollisionCallback(mapObject, KurikingKartHitCallback);
        }
        mapObject->mUnk_2b8 = 1;
    }
    AdvanceMissionRunMapObject(unused, mapObject);
    AdvanceMapObjectModelNsbtaAnimation(mapObject->mNsbmd);
    var = mapObject->mUnk_134 + 1;
    if (var >= GetAbsoluteCounter(mapObject) * 30) {
        var = GetAbsoluteCounter(mapObject) * 30;
    }
    mapObject->mUnk_134 = var;
    var = mapObject->mUnk_134;
    if (var >= GetMapObjectModelNsbmaFrameCount(mapObject->mNsbmd) - 1) {
        var = GetMapObjectModelNsbmaFrameCount(mapObject->mNsbmd) - 1;
    }
    mapObject->mUnk_134 = var;
    SetMapObjectModelNsbmaFrameIndex(mapObject->mNsbmd, (u16) mapObject->mUnk_134);
}

void InitKuriking(MapObjectList *mapObjectList) {
    s32 i;
    Unk02188950 *obj;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[i]) != NULL; i++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(obj);
            }
            InitMissionRunMapObject(mapObjectList, obj, ("kuriking.nsbmd"), ("kuriking.nsbca"), ("kuriking.prm"));
            LoadMissionRunMapObjectShadow(mapObjectList, obj, ("sh_circle.nsbmd"));
            LoadMapObjectModelNsbtaAnimation(obj->mNsbmd, "kuriking.nsbta");
            LoadMapObjectModelNsbtpAnimation(obj->mNsbmd, "kuriking.nsbtp");
            LoadMapObjectModelNsbmaAnimation(obj->mNsbmd, "kuriking.nsbma");
            SetKurikingCollisionAndShadow(obj);
            SetKartCollisionCallback(obj, KurikingKartHitSoundCallback);
        }
    }
}

void DrawKuriking(void *mapObjectList, Unk02188950 *mapObject) {
    DrawMissionRunMapObject(mapObjectList, mapObject);
    DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 0);
}

void CreateKurikingKindData(void) {
    void *kartCollision = &CollideKartWithMissionRunMapObject;
    void *itemCollision = &CollideItemWithMissionRunMapObject;
    void *sphereHit = &ComputeSphereHitOnMissionRunMapObject;
    void *kindData =
        CreateMapObjectKindDataWithSoundIds(kartCollision, itemCollision, sphereHit, 0x2u, 0x1u, 0x0u, 0x0u);
}

void *CreateKurikingDrawList(void) {
    return CreateMapObjectDrawList1(InitKuriking, DrawKuriking, ToggleShadowScale);
}

void *CreateKurikingUpdateList(void) {
    return CreateMapObjectUpdateList(InitKurikingObjects, UpdateKuriking, NULL);
}
