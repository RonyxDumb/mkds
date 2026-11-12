#include "Main/MapObjects/mkd_ef_burner.h"
#include "fx_mtx33.h"
#include "Main/Unknown/code_020d2000.h"

#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/MapObjects/bound.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"

void InitMkdEfBurner(MapObject *mapObject) {
    MapObject *burnerMapObject = mapObject;
    u32 unused;
    CreateMapObjectSoundSourceFalloff2(burnerMapObject);
}

u8 CollideKartWithMkdEfBurner(MkdEfBurner *mkdEfBurner, Kart *kart, u8 *firstResponse, u8 *response) {
    u8 responseValue;

    responseValue = *response;
    if (mkdEfBurner->mKartTimers[kart->mIndex] == 0 &&
        StartSoundIfKartStarOrKiller(&mkdEfBurner->mMapObject, kart) != 0) {
        mkdEfBurner->mMapObject.mDistanceSquaredAndFlags |= data_usa_02156470;
        mkdEfBurner->mKartTimers[kart->mIndex] = 0x1f;
    }
    return responseValue;
}

void CreateMkdEfBurner(MapObjectList *mapObjectList) {
    gMkdEfBurner = CreateMapObjectModelAnimated(mapObjectList, gMkdEfBurnerNsbmdName);
    CreateMapObjectModelNsbtaAnimation(gMkdEfBurner, gMkdEfBurnerNsbtaName);
    SetMapObjectModelPolygonId(gMkdEfBurner, 0x3f);
    mapObjectList->mSortByDistance = 1;
}

void SetupDrawMkdEfBurner(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gMkdEfBurner);
}

void DrawMkdEfBurner(void *mapObjectList, MkdEfBurner *mkdEfBurner) {
    s32 gxParam;
    Vec3 gxTranslation;
    Vec3 gxScale;

    if (mkdEfBurner->mScaleFixed12 <= 0) {
        return;
    }
    SetMapObjectModelPolygonId(gMkdEfBurner, AllocPolygonIdWrapping());
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&mkdEfBurner->mMapObject.mPos), 0xc);
    gxTranslation.y = mkdEfBurner->mMapObject.mExtent.y >> 4;
    gxTranslation.x = 0;
    gxTranslation.z = 0;
    NNS_G3dGeBufferOP_N(0x1c, &gxTranslation, 3);
    gxScale.x = mkdEfBurner->mScaleFixed12;
    gxScale.y = gxScale.x;
    gxScale.z = gxScale.x;
    NNS_G3dGeBufferOP_N(0x1b, &gxScale, 3);
    NNS_G3dGeBufferOP_N(0x1b, &mkdEfBurner->mMapObject.mScale, 3);
    SetMapObjectModelNsbtaFrameIndex(gMkdEfBurner, mkdEfBurner->mNsbtaFrameIndex);
    DrawMapObjectModel(mapObjectList, gMkdEfBurner, mkdEfBurner);
}

void InitMkdEfBurnerObjects(MapObjectList *mapObjectList) {
    BOOL followerSpeed;
    s32 mapObjectIndex;
    MkdEfBurner *mkdEfBurner;
    u16 mapObjectFlag;
    s32 speed;

    if (mapObjectList == NULL) {
        return;
    }
    followerSpeed = FALSE;
    mapObjectFlag = data_usa_0215646c;
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (mkdEfBurner = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        mkdEfBurner->mMapObject.mPos.y =
            mkdEfBurner->mMapObject.mCourseMapRow->mPosition.y - mkdEfBurner->mMapObject.mExtent.y;
        if (mkdEfBurner->mMapObject.mCourseMapRow->mGroupIndex < 0) {
            mkdEfBurner->mFollower.mGroupIndex = 0xffff;
        } else {
            InitGroupFollower(&mkdEfBurner->mFollower, mkdEfBurner->mMapObject.mCourseMapRow, followerSpeed);
            speed = TO_FIXED12(mkdEfBurner->mMapObject.mCourseMapRow->mSettings[3]) / 100;
            mkdEfBurner->mFollower.mSpeed = speed;
            mkdEfBurner->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
                speed,
                mkdEfBurner->mFollower.mPath->mSegments[mkdEfBurner->mFollower.mSegmentIndex].mInverseProgressLength);
        }
        if (mkdEfBurner->mMapObject.mCourseMapRow->mSettings[0] == 0 &&
            mkdEfBurner->mMapObject.mCourseMapRow->mSettings[1] == 0 &&
            mkdEfBurner->mMapObject.mCourseMapRow->mSettings[2] == 0) {
            mkdEfBurner->mScaleFixed12 = 0x1000;
            mkdEfBurner->mState = 4;
            mkdEfBurner->mMapObject.mFlags &= ~1;
        } else {
            mkdEfBurner->mStateFrames++;
            if (mkdEfBurner->mStateFrames >= mkdEfBurner->mMapObject.mCourseMapRow->mSettings[2]) {
                mkdEfBurner->mStateFrames = 0;
                mkdEfBurner->mState = 1;
                mkdEfBurner->mMapObject.mFlags |= mapObjectFlag;
                mkdEfBurner->mMapObject.mExtent.y = 0;
            }
        }
    }
}

void UpdateMkdEfBurner(void *mapObjectList, MkdEfBurner *mkdEfBurner) {
    u16 nsbtaFrameCount;
    s32 kartIndex;
    u8 kartCount;

    switch (mkdEfBurner->mState) {
        case 0:
            mkdEfBurner->mStateFrames++;
            if (mkdEfBurner->mStateFrames >= mkdEfBurner->mMapObject.mCourseMapRow->mSettings[1]) {
                mkdEfBurner->mStateFrames = 0;
                mkdEfBurner->mState = 1;
                mkdEfBurner->mMapObject.mFlags &= ~1;
            }
            break;
        case 1:
            mkdEfBurner->mScaleFixed12 += 0x7b;
            if (mkdEfBurner->mScaleFixed12 >= 0x1000) {
                mkdEfBurner->mScaleFixed12 = 0x1000;
                mkdEfBurner->mState = 2;
            }
            mkdEfBurner->mMapObject.mExtent.y =
                MUL_FIXED12_NO_ROUND(mkdEfBurner->mMapObject.mKindData->mExtentY, mkdEfBurner->mScaleFixed12);
            break;
        case 2:
            mkdEfBurner->mStateFrames++;
            if (mkdEfBurner->mStateFrames >= mkdEfBurner->mMapObject.mCourseMapRow->mSettings[0]) {
                mkdEfBurner->mStateFrames = 0;
                mkdEfBurner->mState = 3;
            }
            StartMapObjectSoundWhileRequested(&mkdEfBurner->mMapObject, 0x170);
            break;
        case 3:
            mkdEfBurner->mScaleFixed12 -= 0x29;
            if (mkdEfBurner->mScaleFixed12 <= 0) {
                mkdEfBurner->mScaleFixed12 = 0;
                mkdEfBurner->mState = 0;
                mkdEfBurner->mMapObject.mFlags |= data_usa_0215646c;
            }
            mkdEfBurner->mMapObject.mExtent.y =
                MUL_FIXED12_NO_ROUND(mkdEfBurner->mMapObject.mKindData->mExtentY, mkdEfBurner->mScaleFixed12);
            break;
        case 4:
            StartMapObjectSoundWhileRequested(&mkdEfBurner->mMapObject, 0x170);
            break;
    }
    nsbtaFrameCount = GetMapObjectModelNsbtaFrameCount(gMkdEfBurner);
    mkdEfBurner->mNsbtaFrameIndex++;
    if (mkdEfBurner->mNsbtaFrameIndex >= nsbtaFrameCount) {
        mkdEfBurner->mNsbtaFrameIndex = 0;
    }
    if (mkdEfBurner->mFollower.mGroupIndex != 0xffff) {
        AdvanceGroupFollower(&mkdEfBurner->mFollower);
        GetGroupFollowerLinearPosition(&mkdEfBurner->mFollower, &mkdEfBurner->mMapObject.mPos);
        mkdEfBurner->mMapObject.mPos.y = mkdEfBurner->mMapObject.mPos.y - mkdEfBurner->mMapObject.mExtent.y;
    } else {
        mkdEfBurner->mMapObject.mPos.y =
            mkdEfBurner->mMapObject.mCourseMapRow->mPosition.y - mkdEfBurner->mMapObject.mExtent.y;
    }
    kartCount = gRaceSetup->mKartCount;
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        if (mkdEfBurner->mKartTimers[kartIndex] > 0) {
            mkdEfBurner->mKartTimers[kartIndex]--;
        }
    }
}

void CreateMkdEfBurnerKindData(void) {
    CreateMapObjectKindDataWithSound(&CollideKartWithMkdEfBurner, NULL, NULL, 2, 0, (0x0000018du));
}

void CreateMkdEfBurnerDrawList(void) {
    CreateMapObjectDrawList1(&CreateMkdEfBurner, &DrawMkdEfBurner, &SetupDrawMkdEfBurner);
}

void CreateMkdEfBurnerUpdateList(void) {
    CreateMapObjectUpdateList(&InitMkdEfBurnerObjects, &UpdateMkdEfBurner, NULL);
}

u16 CountMkdEfBurnerScaleThresholds(MkdEfBurner *burner) {
    if (burner->mScaleFixed12 >= 0x1000) {
        return 3;
    }
    if (burner->mScaleFixed12 >= 0x99a) {
        return 2;
    }
    return burner->mScaleFixed12 >= 0x4cd;
}
