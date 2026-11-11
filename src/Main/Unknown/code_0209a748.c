#include "Main/Unknown/code_0209a748.h"
#include "code_02146d78.h"

#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020f36d8.h" // ItemObject
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020d88fc.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "code_02146cbc.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8ddc.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_02077bc0.h"

void InitCrab(Crab *crab) {
    InitGroupFollower(&crab->mFollower, crab->mMapObject.mCourseMapRow, 0);
}

static inline u32 CrabNextRandomBelow(RandomState64 *random, u32 limit) {
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    if (limit == 0) {
        return random->mValue >> 32;
    } else {
        return ((random->mValue >> 32) * limit) >> 32;
    }
}

void StartCrabLaunch(Crab *crab, Vec3 *sourcePosition, Vec3 *sourceDirection, Vec3 *sourceVelocity) {
    Vec3 sideDirection;
    RandomState64 *mapObjectRandom;
    s32 valueX;
    s32 valueZ;

    if (sourcePosition != NULL && sourceDirection != NULL) {
        VEC_Subtract(&crab->mMapObject.mPos, sourcePosition, &sideDirection);
        valueZ = sourceDirection->z;
        valueX = sourceDirection->x;
        if ((s64) sideDirection.z * valueX - (s64) sideDirection.x * valueZ < 0) {
            sideDirection.z = -valueX;
            sideDirection.x = valueZ;
            sideDirection.y = 0;
            crab->mRotateZAnglePerFrame = 0x71c;
        } else {
            sideDirection.z = valueX;
            sideDirection.x = -valueZ;
            sideDirection.y = 0;
            crab->mRotateZAnglePerFrame = 0xf8e4;
        }
        crab->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(sideDirection.x, 0x1800);
        crab->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(sideDirection.y, 0x1800);
        crab->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(sideDirection.z, 0x1800);
    } else {
        mapObjectRandom = GetMapObjectRandom();
        valueZ = (u16) CrabNextRandomBelow(mapObjectRandom, 0x10000);
        valueX = FX_CosIdx((u16) valueZ);
        valueX = MUL_FIXED12_NO_ROUND(valueX, 0x1800);
        crab->mMapObject.mPosStep.x = valueX;
        crab->mMapObject.mPosStep.z = valueX;
        mapObjectRandom = GetMapObjectRandom();
        if ((u16) CrabNextRandomBelow(mapObjectRandom, 2) != 0) {
            crab->mRotateZAnglePerFrame = 0x71c;
        } else {
            crab->mRotateZAnglePerFrame = 0xf8e4;
        }
    }
    if (sourceVelocity != NULL) {
        crab->mMapObject.mPosStep.x += sourceVelocity->x / 2;
        crab->mMapObject.mPosStep.z += sourceVelocity->z / 2;
    }
    crab->mMapObject.mPosStep.y = 0x4000;
    crab->mTimer = 0x12c;
    crab->mState = 2;
    crab->mMapObject.mFlags |= data_usa_0215659c;
}

u8 CollideKartWithCrab(Crab *crab, Kart *kart, u8 *hitFlag, u8 *passedValue) {
    u32 result;

    result = *passedValue;
    if (*hitFlag == 1) {
        StartCrabLaunch(crab, &kart->mPos, &kart->mEasedTurnedForward, &kart->mVelocity);
        StartSoundIfKartStarOrKiller(&crab->mMapObject, kart);
    }
    return result;
}

u8 CollideItemObjectWithCrab(Crab *crab, ItemObject *itemObject, u8 *hitFlag, u8 *passedValue) {
    Vec3 direction;
    Kart *entryKart;
    u32 result;

    result = *passedValue;
    if (*hitFlag == 1) {
        if (itemObject != NULL) {
            if ((s64) itemObject->mVelocity.x * itemObject->mVelocity.x +
                    (s64) itemObject->mVelocity.y * itemObject->mVelocity.y +
                    (s64) itemObject->mVelocity.z * itemObject->mVelocity.z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&itemObject->mVelocity, &direction);
                StartCrabLaunch(crab, &itemObject->mPos, &direction, NULL);
            } else {
                StartCrabLaunch(crab, NULL, NULL, NULL);
            }
            StartMissionRunKouraEffects(itemObject);
        } else {
            entryKart = GetKart((u16) gRaceSetup->mEntryIndex);
            StartCrabLaunch(crab, &entryKart->mPos, &entryKart->mEasedTurnedForward, &entryKart->mVelocity);
        }
    }
    return result;
}

void CreateCrabAndCrabHand(void *mapObjectList) {
    gCrab = CreateMapObjectModelNsbmdNsbtp(mapObjectList, "crab.nsbmd", "crab.nsbtp");
    gCrabHand = CreateMapObjectModelNsbmdNsbtp(mapObjectList, "crab_hand.nsbmd", "crab_hand.nsbtp");
    SetMapObjectModelPolygonId(gCrab, 0x3f);
    SetMapObjectModelPolygonId(gCrabHand, 0x3f);
}

u32 CrabSetupDrawReturnArgument(u32 value) {
    return value;
}

void DrawCrab(void *mapObjectList, Crab *crab) {
    s32 commandParam;
    MtxFx33 crabRotation;
    MtxFx33 handRotation;

    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    BuildYAxisMatrix(&crab->mMapObject.mMatrix.mRows[1]);
    NNS_G3dGeBufferOP_N(0x19, SetYAxisMatrixPos(&crab->mMapObject.mPos), 0xc);
    if (crab->mRotateZAngle != 0) {
        MTX_RotZ33_(&crabRotation, FX_SinIdx(crab->mRotateZAngle), FX_CosIdx(crab->mRotateZAngle));
        NNS_G3dGeBufferOP_N(0x1a, &crabRotation, 9);
    }
    NNS_G3dGeBufferOP_N(0x1b, &crab->mMapObject.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gCrab, crab->mCrabNsbtpFrameIndexFixed12 >> 12);
    QueueMapObjectModelMaterial(mapObjectList, gCrab);
    DrawMapObjectModel(mapObjectList, gCrab, crab);
    MTX_RotZ33_(&handRotation, FX_SinIdx((u16) crab->mHandWobble.mValue), FX_CosIdx((u16) crab->mHandWobble.mValue));
    NNS_G3dGeBufferOP_N(0x1a, &handRotation, 9);
    SetMapObjectModelNsbtpFrameIndex(gCrabHand, crab->mHandNsbtpFrameIndexFixed12 >> 12);
    QueueMapObjectModelMaterial(mapObjectList, gCrabHand);
    DrawMapObjectModel(mapObjectList, gCrabHand, crab);
}

void InitCrabObjects(Unk0209af98 *mapObjectList) {
    s32 objectIndex;
    Crab *crab;
    RandomState64 *mapObjectRandom;

    if (mapObjectList == NULL) {
        return;
    }
    for (objectIndex = 0;
         objectIndex < mapObjectList->mMapObjectCount && (crab = mapObjectList->mMapObjects[objectIndex]) != NULL;
         objectIndex++) {
        crab->mHandWobble.mAngle = 0;
        crab->mHandWobble.mMid = 0;
        crab->mHandWobble.mAmplitude = 0x1c7;
        crab->mHandWobble.mAmplitudePerFrame = 0;
        crab->mHandWobble.mAnglePerFrame = 0xe39;
        crab->mHandWobble.mUnk_1c = 0;
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        crab->mTimer = (u16) ((u16) (((u64) (u32) (mapObjectRandom->mValue >> 32) * 60) >> 32) + 30);
        crab->mState = 0;
    }
}

s16 CrabFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 CrabFX_MulInline(s32 value, s32 factor) {
    return MUL_FIXED12_ROUNDED(value, factor);
}

static inline void AdvanceCrabWobble(TeresaWobble *wobble) {
    s32 nextValue;

    wobble->mAngle += wobble->mAnglePerFrame;
    wobble->mValueDelta =
        wobble->mMid + CrabFX_MulInline(wobble->mAmplitude, CrabFX_SinIdx(wobble->mAngle)) - wobble->mValue;
    wobble->mValue += wobble->mValueDelta;
    if (wobble->mAmplitude > 0) {
        nextValue = wobble->mAmplitude + wobble->mAmplitudePerFrame;
        if (nextValue <= 0) {
            nextValue = 0;
        }
        wobble->mAmplitude = nextValue;
    } else if (wobble->mAmplitude < 0) {
        nextValue = wobble->mAmplitude + wobble->mAmplitudePerFrame;
        if (nextValue >= 0) {
            nextValue = 0;
        }
        wobble->mAmplitude = nextValue;
    }
    if (wobble->mAnglePerFrame > 0) {
        nextValue = wobble->mAnglePerFrame + wobble->mUnk_1c;
        if (nextValue <= 0) {
            nextValue = 0;
        }
        wobble->mAnglePerFrame = nextValue;
    } else if (wobble->mAnglePerFrame < 0) {
        nextValue = wobble->mAnglePerFrame + wobble->mUnk_1c;
        if (nextValue >= 0) {
            nextValue = 0;
        }
        wobble->mAnglePerFrame = nextValue;
    }
}

void UpdateCrab(void *mapObjectList, Crab *crab) {
    Vec3 upVector;
    RandomState64 *mapObjectRandom;

    switch (crab->mState) {
        case 0:
            crab->mHandNsbtpFrameIndexFixed12 += 0x200;
            if (crab->mHandNsbtpFrameIndexFixed12 >=
                (s32) (GetMapObjectModelNsbtpFrameCount(gCrabHand) > 0
                           ? 0.5f + (GetMapObjectModelNsbtpFrameCount(gCrabHand) << 12)
                           : (GetMapObjectModelNsbtpFrameCount(gCrabHand) << 12) - 0.5f)) {
                crab->mHandNsbtpFrameIndexFixed12 = 0;
            }
            if (crab->mTimer-- > 0) {
                return;
            }
            if (crab->mHandNsbtpFrameIndexFixed12 == 0) {
                crab->mState = 1;
            }
            break;
        case 1:
            crab->mFollower.mSpeed = 0x800;
            crab->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
                crab->mFollower.mPath->mSegments[crab->mFollower.mSegmentIndex].mInverseProgressLength, 0x800);
            if (AdvanceGroupFollower(&crab->mFollower) != FALSE) {
                crab->mHandWobble.mAngle = 0;
                crab->mHandWobble.mMid = 0;
                crab->mHandWobble.mAmplitude = 0x1c7;
                crab->mHandWobble.mAmplitudePerFrame = 0;
                crab->mHandWobble.mAnglePerFrame = 0xe39;
                crab->mHandWobble.mUnk_1c = 0;
                mapObjectRandom = GetMapObjectRandom();
                mapObjectRandom->mValue =
                    mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                crab->mTimer = (u16) ((u16) (((u64) (u32) (mapObjectRandom->mValue >> 32) * 60) >> 32) + 30);
                crab->mState = 0;
            }
            crab->mCrabNsbtpFrameIndexFixed12 += 0x200;
            if (crab->mCrabNsbtpFrameIndexFixed12 >=
                (s32) (GetMapObjectModelNsbtpFrameCount(gCrab) > 0
                           ? 0.5f + (GetMapObjectModelNsbtpFrameCount(gCrab) << 12)
                           : (GetMapObjectModelNsbtpFrameCount(gCrab) << 12) - 0.5f)) {
                crab->mCrabNsbtpFrameIndexFixed12 = 0;
            }
            AdvanceCrabWobble(&crab->mHandWobble);
            GetGroupFollowerLinearPosition(&crab->mFollower, &crab->mMapObject.mPos);
            upVector = *GetGroupFollowerSegmentUp(&crab->mFollower);
            VEC_Subtract(&upVector, &crab->mMapObject.mMatrix.mRows[1], &upVector);
            upVector.x = MUL_FIXED12_NO_ROUND(upVector.x, 0x800);
            upVector.y = MUL_FIXED12_NO_ROUND(upVector.y, 0x800);
            upVector.z = MUL_FIXED12_NO_ROUND(upVector.z, 0x800);
            VEC_Add(&crab->mMapObject.mMatrix.mRows[1], &upVector, &crab->mMapObject.mMatrix.mRows[1]);
            if ((s64) crab->mMapObject.mMatrix.mRows[1].x * crab->mMapObject.mMatrix.mRows[1].x +
                    (s64) crab->mMapObject.mMatrix.mRows[1].y * crab->mMapObject.mMatrix.mRows[1].y +
                    (s64) crab->mMapObject.mMatrix.mRows[1].z * crab->mMapObject.mMatrix.mRows[1].z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&crab->mMapObject.mMatrix.mRows[1],
                                                   &crab->mMapObject.mMatrix.mRows[1]);
            }
            break;
        case 2:
            if (crab->mTimer-- > 0) {
                crab->mMapObject.mPosStep.y -= 0x400;
                VEC_Add(&crab->mMapObject.mPos, &crab->mMapObject.mPosStep, &crab->mMapObject.mPos);
                crab->mRotateZAngle += crab->mRotateZAnglePerFrame;
                return;
            }
            SetupGroupFollowerAtEntry(&crab->mFollower, 0, 0);
            GetGroupFollowerLinearXz(&crab->mFollower, &crab->mMapObject.mPos);
            crab->mMapObject.mPos.y = crab->mMapObject.mCourseMapRow->mPosition.y - 0x5000;
            crab->mCrabWobble.mAngle = 0;
            crab->mCrabWobble.mMid = 0;
            crab->mCrabWobble.mAmplitude = 0x2aab;
            crab->mCrabWobble.mAmplitudePerFrame = -0xb6;
            crab->mCrabWobble.mAnglePerFrame = 0x71c;
            crab->mCrabWobble.mUnk_1c = 0;
            AdvanceCrabWobble(&crab->mCrabWobble);
            crab->mRotateZAngle = crab->mCrabWobble.mValue;
            crab->mState = 3;
            break;
        case 3:
            crab->mHandNsbtpFrameIndexFixed12 += 0x200;
            if (crab->mHandNsbtpFrameIndexFixed12 >=
                (s32) (GetMapObjectModelNsbtpFrameCount(gCrabHand) > 0
                           ? 0.5f + (GetMapObjectModelNsbtpFrameCount(gCrabHand) << 12)
                           : (GetMapObjectModelNsbtpFrameCount(gCrabHand) << 12) - 0.5f)) {
                crab->mHandNsbtpFrameIndexFixed12 = 0;
            }
            AdvanceCrabWobble(&crab->mCrabWobble);
            crab->mRotateZAngle = crab->mCrabWobble.mValue;
            crab->mMapObject.mPos.y += 0x200;
            if (crab->mMapObject.mPos.y < crab->mMapObject.mCourseMapRow->mPosition.y) {
                return;
            }
            crab->mMapObject.mPos.y = crab->mMapObject.mCourseMapRow->mPosition.y;
            crab->mMapObject.mPosStep.x = 0;
            crab->mMapObject.mPosStep.y = 0;
            crab->mMapObject.mPosStep.z = 0;
            crab->mRotateZAngle = 0;
            crab->mHandWobble.mAngle = 0;
            crab->mHandWobble.mMid = 0;
            crab->mHandWobble.mAmplitude = 0x1c7;
            crab->mHandWobble.mAmplitudePerFrame = 0;
            crab->mHandWobble.mAnglePerFrame = 0xe39;
            crab->mHandWobble.mUnk_1c = 0;
            mapObjectRandom = GetMapObjectRandom();
            mapObjectRandom->mValue =
                mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
            crab->mTimer = (u16) ((u16) (((u64) (u32) (mapObjectRandom->mValue >> 32) * 60) >> 32) + 30);
            crab->mState = 0;
            crab->mMapObject.mFlags &= ~1;
            break;
    }
}

void CreateCrabKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindDataWithSound(CollideKartWithCrab, CollideItemObjectWithCrab, NULL, 2, 1, 0x10e);
    kindData->mCollideItemObjectSoundId = 0x10f;
}

void *CreateCrabDrawList(void) {
    return CreateMapObjectDrawList2(CreateCrabAndCrabHand, DrawCrab, CrabSetupDrawReturnArgument);
}

void *CreateCrabUpdateList(void) {
    return CreateMapObjectUpdateList(InitCrabObjects, UpdateCrab, NULL);
}
