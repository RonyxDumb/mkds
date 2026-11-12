#include "Main/Unknown/code_0209f650.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0209bf70.h"

u16 FX_Atan2Idx(s32 a, s32 b);

static inline u16 TownMonteMapObjectRandomBelowU16(u32 limit) {
    RandomState64 *mapObjectRandom;
    u32 limitU16;
    u32 value;

    if (limit == 0x10000) {
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        return ((mapObjectRandom->mValue >> 32) * 0x10000) >> 32;
    } else {
        mapObjectRandom = GetMapObjectRandom();
        limitU16 = (u16) limit;
        if (limitU16 == 0) {
            value = 0;
        } else {
            mapObjectRandom->mValue =
                mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
            if (limitU16 == 0) {
                value = mapObjectRandom->mValue >> 32;
            } else {
                value = ((mapObjectRandom->mValue >> 32) * limitU16) >> 32;
            }
        }
    }
    return value;
}

static inline void AdvanceTownMonteBounce(TownMonte *townMonte) {
    townMonte->mUnk_a4 += townMonte->mUnk_a8;
    townMonte->mUnk_a8 += 0x4000;
    if (townMonte->mUnk_a4 == 0) {
        townMonte->mUnk_a4 += townMonte->mUnk_a8;
        townMonte->mUnk_a8 += 0x4000;
    } else if (townMonte->mUnk_a4 >= 0x16c000) {
        townMonte->mUnk_a8 = 0x4000 - townMonte->mUnk_a8;
        townMonte->mMirror = townMonte->mMirror == 0 ? 1 : 0;
    }
}

static inline void AdvanceAirshipWobble(Airship *airship) {
    s32 nextValue;

    airship->mWobbleAngle = (u16) airship->mWobbleAngle + airship->mWobbleAnglePerFrame;
    airship->mWobbleOffsetDelta =
        airship->mWobbleMid +
        AirshipFX_MulInline(airship->mWobbleAmplitude / 2, 0x1000 - AirshipFX_CosIdx((u16) airship->mWobbleAngle)) -
        airship->mWobbleOffset;
    airship->mWobbleOffset += airship->mWobbleOffsetDelta;
    if (airship->mWobbleAmplitude > 0) {
        nextValue = airship->mWobbleAmplitude + airship->mWobbleAmplitudePerFrame;
        if (nextValue <= 0) {
            nextValue = 0;
        }
        airship->mWobbleAmplitude = nextValue;
    } else if (airship->mWobbleAmplitude < 0) {
        nextValue = airship->mWobbleAmplitude + airship->mWobbleAmplitudePerFrame;
        if (nextValue >= 0) {
            nextValue = 0;
        }
        airship->mWobbleAmplitude = nextValue;
    }
    if (airship->mWobbleAnglePerFrame > 0) {
        nextValue = airship->mWobbleAnglePerFrame + airship->mUnk_c4;
        if (nextValue <= 0) {
            nextValue = 0;
        }
        airship->mWobbleAnglePerFrame = nextValue;
    } else if (airship->mWobbleAnglePerFrame < 0) {
        nextValue = airship->mWobbleAnglePerFrame + airship->mUnk_c4;
        if (nextValue >= 0) {
            nextValue = 0;
        }
        airship->mWobbleAnglePerFrame = nextValue;
    }
}

static inline BOOL IsAnyKartHighestLapAtLeastTwo(void) {
    s32 kartIndex;

    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        if (GetKartHighestLap((u16) kartIndex) >= 2) {
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateAirship(void *mapObjectList, Airship *airship) {
    switch (airship->mState) {
        case 0:
            if (IsAnyKartHighestLapAtLeastTwo() != FALSE) {
                airship->mState = 1;
            }
            break;
        case 1:
            airship->mUnk_a0 += 0x1000;
            if (airship->mUnk_a0 >= 0) {
                airship->mUnk_a0 = 0;
                airship->mState = 2;
            }
            AdvanceAirshipWobble(airship);
            break;
        case 2:
            AdvanceGroupFollower(&airship->mUnk_c8);
            GetGroupFollowerCurvePosStep(&airship->mUnk_c8, &airship->mMapObject.mPos, &airship->mMapObject.mPosStep);
            AdvanceAirshipWobble(airship);
            break;
    }
    airship->mMapObject.mAngle = FX_Atan2Idx(airship->mMapObject.mPosStep.x, airship->mMapObject.mPosStep.z);
}

void *CreateAirshipDrawList(void) {
    return CreateMapObjectDrawList1(CreateAirship, DrawAirship, NULL);
}

void *CreateAirshipUpdateList(void) {
    return CreateMapObjectUpdateList(InitAirshipObjects, UpdateAirship, NULL);
}

void InitCourseMapRowKindData(MapObject *mapObject) {
    s32 kindDataIndex;

    kindDataIndex = mapObject->mCourseMapRow->mSettings[0];
    if (gCourseMapRowKindData[kindDataIndex] == NULL) {
        gCourseMapRowKindData[kindDataIndex] = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
        *gCourseMapRowKindData[kindDataIndex] = *gCourseMapRowKindData[0];
    }
    switch (kindDataIndex) {
        case 0x10:
            gCourseMapRowKindData[kindDataIndex]->mSoundId = 0x127;
            break;
        case 0x11:
            gCourseMapRowKindData[kindDataIndex]->mSoundId = 0x100;
            break;
        case 0x12:
            gCourseMapRowKindData[kindDataIndex]->mSoundId = 0x1da;
            break;
        default:
            gCourseMapRowKindData[kindDataIndex]->mSoundId = GetSurfaceSoundIdShortRows(0, 8, kindDataIndex);
            break;
    }
    mapObject->mKindData = gCourseMapRowKindData[kindDataIndex];
}

void CreateCourseMapRowKindData(void) {
    s32 kindIndex;

    for (kindIndex = 0; kindIndex < 19; kindIndex++) {
        gCourseMapRowKindData[kindIndex] = NULL;
    }
    gCourseMapRowKindData[0] = CreateEmptyMapObjectKindData();
}

void ResetViewRotatedMatrixAxis1Wrapper(MapObjectList *mapObjectList) {
    ResetViewRotatedMatrixAxis1();
}

void CreateTownMonte(MapObjectList *mapObjectList) {
    mapObjectList->mAfterObjects = ResetViewRotatedMatrixAxis1Wrapper;
    SetMapObjectModelPolygonId(
        gTownMonte = CreateMapObjectModelNsbmdNsbtp(mapObjectList, gTownMonteNsbmdName, gTownMonteNsbtpName), 0x3f);
}

void DrawTownMonte(void *mapObjectList, TownMonte *townMonte) {
    s32 gxParam;
    s32 tilt;
    MtxFx43 *viewMatrix;

    tilt = FROM_FIXED12(0x16c000 - townMonte->mUnk_a4);
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    if (townMonte->mMirror != 0) {
        viewMatrix = TiltViewRotatedMatrix(&townMonte->mMapObject.mPos, -tilt, tilt);
        NNS_G3dGeBufferOP_N(0x19, viewMatrix, 0xc);
    } else {
        viewMatrix = TiltViewRotatedMatrix(&townMonte->mMapObject.mPos, tilt, tilt);
        NNS_G3dGeBufferOP_N(0x19, viewMatrix, 0xc);
    }
    NNS_G3dGeBufferOP_N(0x1b, &townMonte->mMapObject.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gTownMonte, townMonte->mNsbtpFrameIndex);
    QueueMapObjectModelMaterial(mapObjectList, gTownMonte);
    DrawMapObjectModel(mapObjectList, gTownMonte, townMonte);
}

void InitTownMonteObjects(MapObjectList *mapObjectList) {
    TownMonte *townMonte;
    RandomState64 *mapObjectRandom;
    s32 mapObjectIndex;
    s32 index;
    u32 nsbtpFrameCount;
    u16 count;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (townMonte = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        townMonte->mUnk_a4 = 0;
        townMonte->mUnk_a8 = 0;
        nsbtpFrameCount = GetMapObjectModelNsbtpFrameCount(gTownMonte);
        townMonte->mNsbtpFrameIndex = TownMonteMapObjectRandomBelowU16(nsbtpFrameCount);
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        count = ((mapObjectRandom->mValue >> 32) * 0x1a) >> 32;
        for (index = 0; index < count; index++) {
            AdvanceTownMonteBounce(townMonte);
        }
        if (townMonte->mMapObject.mCourseMapRow->mSettings[0] != 0) {
            if (townMonte->mNsbtpFrameIndex == 0) {
                townMonte->mSoundId = 0x1a7;
            } else if (townMonte->mNsbtpFrameIndex == 1) {
                townMonte->mSoundId = 0x1a8;
            } else if (townMonte->mNsbtpFrameIndex == 2) {
                mapObjectRandom = GetMapObjectRandom();
                mapObjectRandom->mValue =
                    mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                townMonte->mSoundId = (u16) (((mapObjectRandom->mValue >> 32) * 2) >> 32) != 0 ? 0x1a7 : 0x1a8;
            }
        }
    }
}

void UpdateTownMonte(void *mapObjectList, TownMonte *townMonte) {
    SoundStartParams soundStartParams;
    s32 falloffIndex;
    u16 soundId;

    AdvanceTownMonteBounce(townMonte);
    if (townMonte->mSoundId == 0) {
        return;
    }
    if (townMonte->mMapObject.mCourseMapRow->mSettings[0] != GetSeqVariableSinceChangeFrames(0)) {
        return;
    }
    soundId = townMonte->mSoundId;
    if (townMonte->mMapObject.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (townMonte->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
        falloffIndex = 2;
    } else if (townMonte->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
        falloffIndex = 3;
    } else {
        falloffIndex = 4;
    }
    soundStartParams.mSoundId = soundId;
    soundStartParams.mPositionSource = &townMonte->mMapObject.mPos;
    soundStartParams.mFalloffIndex = falloffIndex;
    soundStartParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&townMonte->mMapObject.mPos);
    StartSoundFromParams(&soundStartParams);
}

void *CreateTownMonteDrawList(void) {
    return CreateMapObjectDrawList2(CreateTownMonte, DrawTownMonte, NULL);
}

void *CreateTownMonteUpdateList(void) {
    return CreateMapObjectUpdateList(InitTownMonteObjects, UpdateTownMonte, NULL);
}
