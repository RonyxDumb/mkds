#include "Main/MapObjects/bound.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/sun.h"
#include "Main/MapObjects/sun_fireball.h"
#include "Main/Race/kart_highest_lap.h"
#include "Main/System/heap_call.h"
#include "Main/Kart/code_0207a000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/map_object_matrix.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Item/item_link_following.h"
#include "Main/Item/bouncing_item_box.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/Kart/karts.h"

static inline u32 CollideKartWithBound_inline(RandomState64 *randomState64) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    return randomState64->mValue >> 32;
}

void InitBound(Bound *bound) {
    bound->mMapObject.mFlags |= data_usa_021565d4;
    RefreshMapObjectMatrixFromHitNormal(&bound->mMapObject);
    bound->mInitialScaleX = bound->mMapObject.mScale.x;
}

// Shared by Bound, Cream and Berry: sets the object's motion from the Kart, starts the wobble and plays a sound.
s32 CollideKartWithBound(Bound *bound, Kart *kart, u8 *firstResponse, u8 *response) {
    Vec3 component;
    Vec3 remainder;
    Vec3 offset;
    Vec3 contactPos;
    Vec3 *kartVector;
    u8 responseValue;
    s32 dot;
    u32 firstResponseValue;

    firstResponseValue = *firstResponse;
    responseValue = *response;
    if (firstResponseValue == 3 || firstResponseValue == 4) {
        if (bound->mKartTimers[kart->mIndex] == 0) {
            VEC_Subtract(&kart->mPos, &bound->mMapObject.mPos, &offset);
            dot = VEC_DotProduct(&kart->mVelocityDirection, &offset);
            component.x = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.x, dot);
            component.y = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.y, dot);
            component.z = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.z, dot);
            remainder.x = offset.x - component.x;
            remainder.y = offset.y - component.y;
            remainder.z = offset.z - component.z;
            dot = VEC_DotProduct(&bound->mMapObject.mMatrix.mRows[1], &remainder);
            component.x = MUL_FIXED12_NO_ROUND(bound->mMapObject.mMatrix.mRows[1].x, dot);
            component.y = MUL_FIXED12_NO_ROUND(bound->mMapObject.mMatrix.mRows[1].y, dot);
            component.z = MUL_FIXED12_NO_ROUND(bound->mMapObject.mMatrix.mRows[1].z, dot);
            remainder.x -= component.x;
            remainder.y -= component.y;
            remainder.z -= component.z;
            if (LENGTH_SQUARED(remainder) < 0x10) {
                kartVector = &kart->mUnk_120;
                bound->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(kart->mUnk_120.x, 0xc000);
                bound->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(kartVector->y, 0xc000);
                bound->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(kartVector->z, 0xc000);
            } else {
                Vec3NormalizeAndGetLengthUnchecked(&remainder, &remainder);
                bound->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(remainder.x, 0xc000);
                bound->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(remainder.y, 0xc000);
                bound->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(remainder.z, 0xc000);
            }
            VEC_Subtract(&component, &bound->mMapObject.mMatrix.mRows[1], &component);
            VEC_MultAdd(0x19a, &component, &bound->mMapObject.mPosStep, &bound->mMapObject.mPosStep);
            bound->mKartTimers[kart->mIndex] = 0x1f;
            if (gRaceSetup->mMode == MODE_BATTLE) {
                CallStandingsKartOffsetCallback(kart->mIndex, &bound->mMapObject.mPosStep);
            }
        } else {
            bound->mMapObject.mPosStep.x = 0;
            bound->mMapObject.mPosStep.y = 0;
            bound->mMapObject.mPosStep.z = 0;
        }
        if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind != PLAYER_KIND_GHOST && bound->mWobbling == FALSE) {
            bound->mWobbleXAngle = 0x8000;
            bound->mWobbleXMid = 0x1000;
            bound->mWobbleXAmplitude = 0x400;
            bound->mWobbleXAmplitudePerFrame = -0x29;
            bound->mWobbleXAnglePerFrame = 0x1000;
            bound->mUnk_0d4 = 0;
            bound->mWobbleYAngle = 0;
            bound->mWobbleYMid = 0x1000;
            bound->mWobbleYAmplitude = 0x400;
            bound->mWobbleYAmplitudePerFrame = -0x29;
            bound->mWobbleYAnglePerFrame = 0x1000;
            bound->mUnk_0f4 = 0;
            bound->mWobbling = TRUE;
            switch (bound->mMapObject.mKind) {
                case MAP_OBJECT_KIND_CREAM:
                    StartSoundFullVolumeWrapper(kart, 0x156);
                    break;
                case MAP_OBJECT_KIND_BERRY:
                    StartSoundFullVolumeWrapper(kart, 0x155);
                    break;
                case 0x1a8:
                    StartSoundFullVolumeWrapper(kart, 0x1cf);
                    break;
            }
            if ((u16) (bound->mMapObject.mKind + 0xfe4c) <= 1) {
                StartOrthoQuadsCreamEffect(
                    kart->mIndex,
                    (u16) (((u64) CollideKartWithBound_inline(&gRaceProgress->mLocalRandom) * 3) >> 32) + 1);
                VEC_Subtract(&bound->mMapObject.mPos, &kart->mCollisionCenter, &contactPos);
                if (!(LENGTH_SQUARED(contactPos) < 0x10)) {
                    Vec3NormalizeAndGetLengthUnchecked(&contactPos, &contactPos);
                }
                VEC_MultAdd(kart->mRadius, &contactPos, &kart->mCollisionCenter, &contactPos);
                if (kart->mIndex == gRaceSetup->mEntryIndex) {
                    StartEffect(0x74, &contactPos);
                } else {
                    StartEffect(0x75, &contactPos);
                }
            }
        }
        return responseValue;
    }
    bound->mMapObject.mPosStep.x = 0;
    bound->mMapObject.mPosStep.y = 0;
    bound->mMapObject.mPosStep.z = 0;
    return 2;
}

// Shared by Bound, Cream and Berry: when *b is 2, starts a smaller wobble; returns *c.
u8 CollideItemObjectWithBound(Bound *bound, void *itemObject, u8 *firstResponse, u8 *response) {
    u32 responseValue;

    responseValue = *response;
    if (*firstResponse == 2 && bound->mWobbling == FALSE) {
        bound->mWobbleXAngle = 0x8000;
        bound->mWobbleXMid = 0x1000;
        bound->mWobbleXAmplitude = 0x200;
        bound->mWobbleXAmplitudePerFrame = -0x14;
        bound->mWobbleXAnglePerFrame = 0x1000;
        bound->mUnk_0d4 = 0;
        bound->mWobbleYAngle = 0;
        bound->mWobbleYMid = 0x1000;
        bound->mWobbleYAmplitude = 0x200;
        bound->mWobbleYAmplitudePerFrame = -0x14;
        bound->mWobbleYAnglePerFrame = 0x1000;
        bound->mUnk_0f4 = 0;
        bound->mWobbling = TRUE;
        bound->mMapObject.mDistanceSquaredAndFlags |= data_usa_021565d0;
    }
    return responseValue;
}

BOOL ComputeSphereHitOnBound(Bound *bound, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *pushOut) {
    if ((bound->mMapObject.mFlags & 0x800) == 0 && bound->mWobbling == TRUE) {
        bound->mSphereHit = ComputeSphereHitOnRotatedCylinder(
            sphereCenter, &bound->mMapObject.mPos, &bound->mMapObject.mMatrix.mRows[0],
            MUL_FIXED12_NO_ROUND(bound->mMapObject.mExtent.x, bound->mWobbleScaleX), bound->mMapObject.mExtent.y, 0,
            sphereRadius, pushOut);
    } else {
        bound->mSphereHit = ComputeSphereHitOnRotatedCylinder(
            sphereCenter, &bound->mMapObject.mPos, &bound->mMapObject.mMatrix.mRows[0], bound->mMapObject.mExtent.x,
            bound->mMapObject.mExtent.y, 0, sphereRadius, pushOut);
    }
    return bound->mSphereHit != 0;
}

void CreateBound(void *mapObjectList) {
    gBound = CreateMapObjectModelAnimated(mapObjectList, gBoundNsbmdName);
    CreateMapObjectModelNsbtpAnimation(gBound, gBoundNsbtpName);
}

void DrawBound(MapObjectList *mapObjectList, Bound *bound) {
    s32 gxParams[4];
    s32 scaleX;
    s32 scaleY;

    gxParams[0] = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParams[0], 1);
    bound->mMapObject.mMatrix.mRows[3].x = bound->mMapObject.mPos.x >> 4;
    bound->mMapObject.mMatrix.mRows[3].y = bound->mMapObject.mPos.y >> 4;
    bound->mMapObject.mMatrix.mRows[3].z = bound->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &bound->mMapObject.mMatrix, 0xc);
    if (bound->mWobbling == TRUE) {
        scaleX = bound->mWobbleScaleX;
        scaleY = bound->mWobbleScaleY;
        gxParams[1] = scaleX;
        gxParams[2] = scaleY;
        gxParams[3] = scaleX;
        NNS_G3dGeBufferOP_N(0x1b, &gxParams[1], 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &bound->mMapObject.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gBound, bound->mNsbtpFrameIndex);
    DrawMapObjectModel(mapObjectList, gBound, bound);
}

void CreateCream(void *mapObjectList) {
    gCream = CreateMapObjectModelAnimated(mapObjectList, gCreamNsbmdName);
    CreateOrthoQuadCreamEffect(data_usa_02167328);
}

void CreateBerry(void *mapObjectList) {
    gBerry = CreateMapObjectModelAnimated(mapObjectList, gBerryNsbmdName);
    CreateOrthoQuadCreamEffect(gCreamEffectNsbmdName);
}

void DrawCream(MapObjectList *mapObjectList, Bound *bound) {
    s32 gxParams[4];
    s32 scaleX;
    s32 scaleY;

    gxParams[0] = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParams[0], 1);
    bound->mMapObject.mMatrix.mRows[3].x = bound->mMapObject.mPos.x >> 4;
    bound->mMapObject.mMatrix.mRows[3].y = bound->mMapObject.mPos.y >> 4;
    bound->mMapObject.mMatrix.mRows[3].z = bound->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &bound->mMapObject.mMatrix, 0xc);
    if (bound->mWobbling == TRUE) {
        scaleX = bound->mWobbleScaleX;
        scaleY = bound->mWobbleScaleY;
        gxParams[1] = scaleX;
        gxParams[2] = scaleY;
        gxParams[3] = scaleX;
        NNS_G3dGeBufferOP_N(0x1b, &gxParams[1], 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &bound->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gCream, bound);
}

void DrawBerry(MapObjectList *mapObjectList, Bound *bound) {
    s32 gxParams[4];
    s32 scaleX;
    s32 scaleY;

    gxParams[0] = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParams[0], 1);
    bound->mMapObject.mMatrix.mRows[3].x = bound->mMapObject.mPos.x >> 4;
    bound->mMapObject.mMatrix.mRows[3].y = bound->mMapObject.mPos.y >> 4;
    bound->mMapObject.mMatrix.mRows[3].z = bound->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &bound->mMapObject.mMatrix, 0xc);
    if (bound->mWobbling == TRUE) {
        scaleX = bound->mWobbleScaleX;
        scaleY = bound->mWobbleScaleY;
        gxParams[1] = scaleX;
        gxParams[2] = scaleY;
        gxParams[3] = scaleX;
        NNS_G3dGeBufferOP_N(0x1b, &gxParams[1], 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &bound->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gBerry, bound);
}

void InitBoundAndCreamAndBerryObjects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    Bound *bound;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (bound = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        if (bound->mMapObject.mCourseMapRow->mGroupIndex >= 0) {
            InitGroupFollower(&bound->mUnk_0f8, bound->mMapObject.mCourseMapRow, 0);
            bound->mUnk_0f8.mSpeed = 0x3000;
            bound->mUnk_0f8.mProgressStep = MUL_FIXED12_NO_ROUND(
                bound->mUnk_0f8.mPath->mSegments[bound->mUnk_0f8.mSegmentIndex].mInverseProgressLength, 0x3000);
        } else {
            bound->mUnk_0f8.mGroupIndex = 0xffff;
        }
    }
}

s16 BoundFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 BoundFX_MulInline(s32 value, s32 scale) {
    return MUL_FIXED12_ROUNDED(value, scale);
}

void UpdateBoundAndCreamAndBerry(MapObjectList *mapObjectList, Bound *bound) {
    u16 nsbtpFrameCount;
    s32 value;
    s32 kartIndex;
    s32 kartCount;

    if (bound->mUnk_0f8.mGroupIndex != 0xffff) {
        AdvanceGroupFollower(&bound->mUnk_0f8);
        GetGroupFollowerCurvePosStep(&bound->mUnk_0f8, &bound->mMapObject.mPos, &bound->mMapObject.mPosStep);
        nsbtpFrameCount = GetMapObjectModelNsbtpFrameCount(gBound);
        bound->mNsbtpFrameIndex += 1;
        if (bound->mNsbtpFrameIndex >= nsbtpFrameCount) {
            bound->mNsbtpFrameIndex = 1;
        }
    } else {
        bound->mMapObject.mPosStep.x = 0;
        bound->mMapObject.mPosStep.y = 0;
        bound->mMapObject.mPosStep.z = 0;
        bound->mNsbtpFrameIndex = 0;
    }
    if (bound->mWobbling == TRUE) {
        bound->mWobbleXAngle += bound->mWobbleXAnglePerFrame;
        value = BoundFX_MulInline(bound->mWobbleXAmplitude, BoundFX_SinIdx(bound->mWobbleXAngle));
        bound->mUnk_0c0 = bound->mWobbleXMid + value - bound->mWobbleScaleX;
        bound->mWobbleScaleX += bound->mUnk_0c0;
        if (bound->mWobbleXAmplitude > 0) {
            value = bound->mWobbleXAmplitude + bound->mWobbleXAmplitudePerFrame;
            if (value <= 0) {
                value = 0;
            }
            bound->mWobbleXAmplitude = value;
        } else if (bound->mWobbleXAmplitude < 0) {
            value = bound->mWobbleXAmplitude + bound->mWobbleXAmplitudePerFrame;
            if (value >= 0) {
                value = 0;
            }
            bound->mWobbleXAmplitude = value;
        }
        if (bound->mWobbleXAnglePerFrame > 0) {
            value = bound->mWobbleXAnglePerFrame + bound->mUnk_0d4;
            if (value <= 0) {
                value = 0;
            }
            bound->mWobbleXAnglePerFrame = value;
        } else if (bound->mWobbleXAnglePerFrame < 0) {
            value = bound->mWobbleXAnglePerFrame + bound->mUnk_0d4;
            if (value >= 0) {
                value = 0;
            }
            bound->mWobbleXAnglePerFrame = value;
        }
        bound->mWobbleYAngle += bound->mWobbleYAnglePerFrame;
        value = BoundFX_MulInline(bound->mWobbleYAmplitude, BoundFX_SinIdx(bound->mWobbleYAngle));
        bound->mUnk_0e0 = bound->mWobbleYMid + value - bound->mWobbleScaleY;
        bound->mWobbleScaleY += bound->mUnk_0e0;
        if (bound->mWobbleYAmplitude > 0) {
            value = bound->mWobbleYAmplitude + bound->mWobbleYAmplitudePerFrame;
            if (value <= 0) {
                value = 0;
            }
            bound->mWobbleYAmplitude = value;
        } else if (bound->mWobbleYAmplitude < 0) {
            value = bound->mWobbleYAmplitude + bound->mWobbleYAmplitudePerFrame;
            if (value >= 0) {
                value = 0;
            }
            bound->mWobbleYAmplitude = value;
        }
        if (bound->mWobbleYAnglePerFrame > 0) {
            value = bound->mWobbleYAnglePerFrame + bound->mUnk_0f4;
            if (value <= 0) {
                value = 0;
            }
            bound->mWobbleYAnglePerFrame = value;
        } else if (bound->mWobbleYAnglePerFrame < 0) {
            value = bound->mWobbleYAnglePerFrame + bound->mUnk_0f4;
            if (value >= 0) {
                value = 0;
            }
            bound->mWobbleYAnglePerFrame = value;
        }
        if (bound->mWobbleXAmplitude == 0 && bound->mWobbleYAmplitude == 0) {
            bound->mWobbling = FALSE;
            bound->mMapObject.mScale.x = bound->mInitialScaleX;
        } else {
            bound->mMapObject.mScale.x = MUL_FIXED12_NO_ROUND(bound->mInitialScaleX, bound->mWobbleScaleX);
        }
    } else {
        bound->mMapObject.mScale.x = bound->mInitialScaleX;
    }
    kartCount = gRaceSetup->mKartCount;
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        if (bound->mKartTimers[kartIndex] > 0) {
            bound->mKartTimers[kartIndex] -= 1;
        }
    }
}

void CreateBoundKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, ComputeSphereHitOnBound, 1, 1);
    kindData->mCollideItemObjectSoundId = 0x1cf;
}

void CreateCreamKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, ComputeSphereHitOnBound, 1, 1);
    kindData->mCollideItemObjectSoundId = 0x156;
}

void CreateBerryKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, ComputeSphereHitOnBound, 1, 1);
    kindData->mCollideItemObjectSoundId = 0x155;
}

void CreateBoundDrawList(void) {
    CreateMapObjectDrawList1(CreateBound, DrawBound, NULL);
}

void CreateCreamDrawList(void) {
    CreateMapObjectDrawList1(CreateCream, DrawCream, NULL);
}

void CreateBerryDrawList(void) {
    CreateMapObjectDrawList1(CreateBerry, DrawBerry, NULL);
}

void CreateBoundUpdateList(void) {
    CreateMapObjectUpdateList(InitBoundAndCreamAndBerryObjects, UpdateBoundAndCreamAndBerry, NULL);
}

// Starts the wobble of object a of the 0x1a8 list, with a sound unless the object is far; FALSE if already wobbling.
BOOL StartBoundWobble(s32 mapObjectIndex) {
    Bound *bound;
    SoundStartParams soundParams;
    s32 falloffIndex;

    bound = GetMapObjectFromList(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_BOUND), mapObjectIndex);
    if (bound->mWobbling == FALSE) {
        bound->mWobbleXAngle = 0x8000;
        bound->mWobbleXMid = 0x1000;
        bound->mWobbleXAmplitude = 0x400;
        bound->mWobbleXAmplitudePerFrame = -0x29;
        bound->mWobbleXAnglePerFrame = 0x1000;
        bound->mUnk_0d4 = 0;
        bound->mWobbleYAngle = 0;
        bound->mWobbleYMid = 0x1000;
        bound->mWobbleYAmplitude = 0x400;
        bound->mWobbleYAmplitudePerFrame = -0x29;
        bound->mWobbleYAnglePerFrame = 0x1000;
        bound->mUnk_0f4 = 0;
        bound->mWobbling = TRUE;
        if ((bound->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
            if (bound->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                falloffIndex = 2;
            } else if (bound->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            soundParams.mSoundId = 0x1cf;
            soundParams.mPositionSource = &bound->mMapObject.mPos;
            soundParams.mFalloffIndex = falloffIndex;
            soundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&bound->mMapObject.mPos);
            StartSoundFromParams(&soundParams);
        }
        return TRUE;
    }
    return FALSE;
}

#pragma thumb on

void *CreateMapObjectKindData(void *collideKartCallback, void *collideItemObjectCallback, void *sphereHitCallback,
                              u32 wordValue, u16 halfValue) {
    MapObjectKindData *kindData;

    GetHeap(GetCurrentHeapCall());
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    kindData->mCollideKartCallback = collideKartCallback;
    kindData->mCollideItemObjectCallback = collideItemObjectCallback;
    kindData->mPosStepMode = wordValue;
    kindData->mCollidable = halfValue;
    kindData->mSphereHitTest = sphereHitCallback;
    return kindData;
}

MapObjectKindData *CreateEmptyMapObjectKindData(void) {
    return CreateMapObjectKindData(NULL, NULL, NULL, 0, 1);
}

MapObjectKindData *CreateMapObjectKindDataWithSound(void *collideKartCallback, void *collideItemObjectCallback,
                                                    void *sphereHitCallback, u32 wordValue, u16 halfValue,
                                                    u16 soundId) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindData(collideKartCallback, collideItemObjectCallback, sphereHitCallback, wordValue,
                                       halfValue);
    kindData->mSoundId = soundId;
    return kindData;
}

#pragma thumb off
