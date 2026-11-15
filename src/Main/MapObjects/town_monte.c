#include "Main/MapObjects/town_monte.h"
#include "Main/MapObjects/chandelier.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Race/kart_highest_lap.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "code_02148538.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

void *gTownMonte;
MapObjectKindData *gCourseMapRowKindData[19];

MapObjectKindDescriptor gTownMonteKindDescriptor = {
    0, {0, 0}, 0xb0, 0, CreateEmptyMapObjectKindData, CreateTownMonteDrawList, 0, 0, CreateTownMonteUpdateList};

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
    townMonte->mBounceOffset += townMonte->mBounceSpeed;
    townMonte->mBounceSpeed += TOWN_MONTE_BOUNCE_SPEED_STEP;
    if (townMonte->mBounceOffset == 0) {
        townMonte->mBounceOffset += townMonte->mBounceSpeed;
        townMonte->mBounceSpeed += TOWN_MONTE_BOUNCE_SPEED_STEP;
    } else if (townMonte->mBounceOffset >= TOWN_MONTE_BOUNCE_OFFSET_MAX) {
        townMonte->mBounceSpeed = TOWN_MONTE_BOUNCE_SPEED_STEP - townMonte->mBounceSpeed;
        townMonte->mMirror = townMonte->mMirror == 0 ? 1 : 0;
    }
}

static inline void AdvanceAirshipWobble(Airship *airship) {
    s32 nextValue;

    airship->mWobbleAngle = airship->mWobbleAngle + airship->mWobbleAnglePerFrame;
    airship->mWobbleOffsetDelta =
        airship->mWobbleMid +
        AirshipFX_MulInline(airship->mWobbleAmplitude / 2, 0x1000 - AirshipFX_CosIdx(airship->mWobbleAngle)) -
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
        nextValue = airship->mWobbleAnglePerFrame + airship->mWobbleAnglePerFrameStep;
        if (nextValue <= 0) {
            nextValue = 0;
        }
        airship->mWobbleAnglePerFrame = nextValue;
    } else if (airship->mWobbleAnglePerFrame < 0) {
        nextValue = airship->mWobbleAnglePerFrame + airship->mWobbleAnglePerFrameStep;
        if (nextValue >= 0) {
            nextValue = 0;
        }
        airship->mWobbleAnglePerFrame = nextValue;
    }
}

static inline BOOL IsAnyKartHighestLapAtLeastTwo(void) {
    s32 kartIndex;

    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        if (GetKartHighestLap(kartIndex) >= 2) {
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateAirship(void *mapObjectList, Airship *airship) {
    switch (airship->mState) {
        case AIRSHIP_STATE_WAIT_SECOND_LAP:
            if (IsAnyKartHighestLapAtLeastTwo() != FALSE) {
                airship->mState = AIRSHIP_STATE_RISE;
            }
            break;
        case AIRSHIP_STATE_RISE:
            airship->mModelHeightOffset += 0x1000;
            if (airship->mModelHeightOffset >= 0) {
                airship->mModelHeightOffset = 0;
                airship->mState = AIRSHIP_STATE_FOLLOW_PATH;
            }
            AdvanceAirshipWobble(airship);
            break;
        case AIRSHIP_STATE_FOLLOW_PATH:
            AdvanceGroupFollower(&airship->mGroupFollower);
            GetGroupFollowerCurvePosStep(&airship->mGroupFollower, &airship->mMapObject.mPos,
                                         &airship->mMapObject.mPosStep);
            AdvanceAirshipWobble(airship);
            break;
    }
    airship->mMapObject.mAngle = FX_Atan2Idx(airship->mMapObject.mPosStep.x, airship->mMapObject.mPosStep.z);
}

MapObjectList *CreateAirshipDrawList(void) {
    return CreateMapObjectDrawList1(CreateAirship, DrawAirship, NULL);
}

MapObjectList *CreateAirshipUpdateList(void) {
    return CreateMapObjectUpdateList(InitAirshipObjects, UpdateAirship, NULL);
}

void InitCourseMapRowKindData(MapObject *mapObject) {
    s32 kindDataIndex;

    kindDataIndex = mapObject->mCourseMapRow->mSettings[0];
    if (gCourseMapRowKindData[kindDataIndex] == NULL) {
        gCourseMapRowKindData[kindDataIndex] =
            HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gCourseMapRowKindData[kindDataIndex]));
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

MapObjectKindData *CreateCourseMapRowKindData(void) {
    s32 kindIndex;

    for (kindIndex = 0; kindIndex < 19; kindIndex++) {
        gCourseMapRowKindData[kindIndex] = NULL;
    }
    return gCourseMapRowKindData[0] = CreateEmptyMapObjectKindData();
}

void ResetViewRotatedMatrixAxis1Wrapper(MapObjectList *mapObjectList) {
    ResetViewRotatedMatrixAxis1();
}

void CreateTownMonte(MapObjectList *mapObjectList) {
    mapObjectList->mAfterObjects = ResetViewRotatedMatrixAxis1Wrapper;
    SetMapObjectModelPolygonId(
        gTownMonte = CreateMapObjectModelNsbmdNsbtp(mapObjectList, "TownMonte.nsbmd", "TownMonte.nsbtp"), 0x3f);
}

void DrawTownMonte(void *mapObjectList, TownMonte *townMonte) {
    s32 gxParam;
    s32 tilt;
    MtxFx43 *viewMatrix;

    tilt = FROM_FIXED12(TOWN_MONTE_BOUNCE_OFFSET_MAX - townMonte->mBounceOffset);
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
        townMonte->mBounceOffset = 0;
        townMonte->mBounceSpeed = 0;
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
                townMonte->mSoundId = TOWN_MONTE_SOUND_FIRST;
            } else if (townMonte->mNsbtpFrameIndex == 1) {
                townMonte->mSoundId = TOWN_MONTE_SOUND_SECOND;
            } else if (townMonte->mNsbtpFrameIndex == 2) {
                mapObjectRandom = GetMapObjectRandom();
                mapObjectRandom->mValue =
                    mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                townMonte->mSoundId = (u16) (((mapObjectRandom->mValue >> 32) * 2) >> 32) != 0
                                          ? TOWN_MONTE_SOUND_FIRST
                                          : TOWN_MONTE_SOUND_SECOND;
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
    if (townMonte->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) {
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

MapObjectList *CreateTownMonteDrawList(void) {
    return CreateMapObjectDrawList2(CreateTownMonte, DrawTownMonte, NULL);
}

MapObjectList *CreateTownMonteUpdateList(void) {
    return CreateMapObjectUpdateList(InitTownMonteObjects, UpdateTownMonte, NULL);
}
