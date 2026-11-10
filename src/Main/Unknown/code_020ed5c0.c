#include "Main/Unknown/code_020ed5c0.h"
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
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_020be7fc.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/unk_0216c000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02071000.h"
#include "Main/Unknown/code_020be000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020f5000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020ee684.h"
#include "code_02147cd8.h"

BOOL CopyKartToItemInUse(ItemInUse *itemInUse) {
    Kart *kart;
    Vec3 scale;
    s32 scaleUnchanged;

    kart = itemInUse->mKart;
    itemInUse->mKartOrientation = kart->mUnk_150_m.mUnk_00_m;
    itemInUse->mKartDrawMatrixPos = kart->mDrawMatrixPos;
    itemInUse->mKartVelocity = kart->mVelocity;
    itemInUse->mKartVelocityLength = kart->mVelocityLength;
    itemInUse->mUnk_078 = MUL_FIXED12_ROUNDED(kart->mPhysicalParam->mUnk_08, kart->mScale.z);
    itemInUse->mKartHopHeight = kart->mHopHeight;
    itemInUse->mMovingForward =
        Vec3DotUnrounded(&itemInUse->mKartOrientation.mUnk_00[2], &itemInUse->mKartVelocity) > 0;
    VEC_Subtract(&itemInUse->mKartDrawMatrixPos, &kart->mPrevPos, &itemInUse->mKartMovement);
    scale.x = MUL_FIXED12_NO_ROUND(kart->mScaleFactor.x, kart->mScaleBase.x);
    scale.y = MUL_FIXED12_NO_ROUND(kart->mScaleFactor.y, kart->mScaleBase.y);
    scale.z = MUL_FIXED12_NO_ROUND(kart->mScaleFactor.z, kart->mScaleBase.z);
    scaleUnchanged =
        (itemInUse->mKartScaleFactorTimesBase.x == scale.x && itemInUse->mKartScaleFactorTimesBase.y == scale.y &&
         itemInUse->mKartScaleFactorTimesBase.z == scale.z)
            ? 1
            : 0;
    if (scaleUnchanged == 0) {
        itemInUse->mKartScaleFactorTimesBase = scale;
        return TRUE;
    }
    return FALSE;
}

void StartItemInUse(ItemInUse *itemInUse, HeldItem *heldItem) {
    void (*startFunc)(void *);
    s32 useKind;
    s32 itemInfoIndex;
    void (*useHook)(struct ItemInUse *, struct HeldItem *);
    BOOL isMode5;
    ItemObject **objects;
    s32 objectCount;
    ItemObject *object;
    s32 i;
    u16 *kartModelHalfwords;
    s32 poolIndex;

    itemInfoIndex = heldItem->mItemInfoIndex;
    useKind = gItemInfos[itemInfoIndex].mUseKind;
    isMode5 = gRaceSetup->mMode == 5;
    if (heldItem->mUnk_0c != 0) {
        if (heldItem->mTimer > heldItem->mUseTimerLimit) {
            return;
        }
    }
    startFunc = gItemInUseStartTable[useKind];
    useHook = gItemInfos[itemInfoIndex].mUseHook;
    if (!isMode5) {
        StartRaceRankListItemInUse(itemInUse->mKartIndex, itemInfoIndex, heldItem->mObjectCount);
    }
    if (useKind == ITEM_USE_KIND_HOOK_ONLY) {
        if (startFunc != NULL) {
            startFunc(itemInUse);
        }
        if (useHook != NULL) {
            useHook(itemInUse, heldItem);
        }
        StartKartSeqArcSoundOffset7(itemInUse->mKart);
        return;
    }
    itemInUse->mObjectKind = gItemInfos[itemInfoIndex].mObjectKind;
    itemInUse->mObjectCount = gItemInfos[itemInfoIndex].mObjectCount;
    itemInUse->mUseKind = useKind;
    itemInUse->mItemInfoIndex = itemInfoIndex;
    itemInUse->mIsActiveItem = FALSE;
    itemInUse->mUnk_0e8 = gItemInfos[itemInfoIndex].mObjectKind == 8 ? 0xb400 : 0x4333;
    poolIndex = *(vs32 *) &itemInUse->mObjectKind;
    TakeItemPoolObjects(&gItemPools[poolIndex], itemInUse->mObjectCount, itemInUse->mObjects, itemInUse->mKart->mIndex,
                        &itemInUse->mKartDrawMatrixPos);
    CopyKartToItemInUse(itemInUse);
    if (startFunc != NULL) {
        startFunc(itemInUse);
    }
    if (useHook != NULL) {
        useHook(itemInUse, heldItem);
    }
    SetupKartAiItemInUseEntry(itemInUse->mKart);
    ResetHeldItem(heldItem);
    if (itemInUse->mIsActiveItem != FALSE) {
        SetActiveItem(itemInUse->mKartItems, itemInUse->mItemInfoIndex);
    }
    objects = itemInUse->mObjects;
    kartModelHalfwords = &itemInUse->mKart->mKartModelsEntry->mCourseColorBlend.mColor;
    objectCount = itemInUse->mObjectCount;
    for (i = 0; i < objectCount; i++) {
        object = objects[i];
        object->mAgeFrames = 0;
        object->mPrevPos = object->mPos;
        object->mVelocity = itemInUse->mKartVelocity;
        SetItemObjectScaleByRatios(object, itemInUse->mKartScaleFactorTimesBase.x,
                                   itemInUse->mKartScaleFactorTimesBase.y);
        object->mKartLightColor = kartModelHalfwords;
        object->mFlags |= 0x1000;
    }
}

BOOL IsItemObjectNearPoint(ItemObject *object, Vec3 *point, s32 radius) {
    s32 deltaX;
    s32 deltaY;
    s32 deltaZ;
    s32 combinedRadius;

    combinedRadius = radius + object->mRadius;
    deltaX = object->mPos.x - point->x;
    deltaY = object->mPos.y - point->y;
    deltaZ = object->mPos.z - point->z;
    return (s64) deltaX * deltaX + (s64) deltaY * deltaY + (s64) deltaZ * deltaZ <
           (s64) combinedRadius * combinedRadius;
}

void CollideItemObjects(ItemObject *object, ItemObject *other) {
    Vec3 savedVelocity;
    s32 n;
    s32 m;

    if ((other->mFlags & 0x1000) != 0) {
        if (object->mUnk_48 > other->mUnk_48) {
            return;
        }
    }
    if (IsItemObjectNearPoint(object, &other->mPos, other->mRadius) == FALSE) {
        if (IsItemObjectNearPoint(object, &other->mPrevPos, other->mRadius) == FALSE) {
            return;
        }
        if (IsItemObjectNearPoint(other, &object->mPrevPos, object->mRadius) == FALSE) {
            return;
        }
    }
    savedVelocity = object->mVelocity;
    n = GetItemObjectHitType(object, other);
    m = GetItemObjectHitType(other, object);
    ApplyItemObjectHitType(object, n, &other->mPos, &other->mVelocity, NULL);
    ApplyItemObjectHitType(other, m, &object->mPos, &savedVelocity, NULL);
    if (other->mKind != 1) {
        return;
    }
    StartTargetKartSoundOnOwnItemHit(other, m, object);
}

void UpdateItemInUseObjects(ItemInUse *itemInUse) {
    ItemObject **objects;
    s32 objectCount;
    ItemObject *object;
    s32 i;
    s32 a;
    s32 b;
    s32 j;
    enum { K0 } idx;

    objects = itemInUse->mObjects;
    objectCount = itemInUse->mObjectCount;
    a = GetKartCourseHitAttributeBit(itemInUse->mKart);
    b = IsKartOutOfView(itemInUse->mKart);
    for (i = 0; i < objectCount; i++) {
        object = objects[i];
        object->mAgeFrames = object->mAgeFrames + 1;
        VEC_Subtract(&object->mPos, &object->mPrevPos, &object->mVelocity);
        object->mPrevPos = object->mPos;
        if (itemInUse->mObjectStartFramesLeft == 0) {
            object->mNormal = itemInUse->mKartOrientation.mUnk_00[1];
            if (object->mNormal.y < 0xff4) {
                object->mFlags |= 0x80;
            }
        }
        if (a != 0) {
            object->mFlags |= 0x40000;
        } else {
            object->mFlags &= ~0x40000;
        }
        if (b != 0) {
            object->mFlags |= 0x10000;
        } else {
            object->mFlags &= ~0x10000;
        }
    }
    for (j = objectCount - 1; j >= 0; j--) {
        object = objects[j];
        if (object->mCollisionSlotIndex == -1) {
            if (IsItemObjectScaleAtSetupSize(object) != FALSE) {
                idx = object->mKind;
                if (gItemKinds[idx].mUnk_68 != 0) {
                    CreateItemObjectCollisionSlot(object);
                }
            }
            continue;
        }
        FindCollisionSlotsOverlappingSlot(object->mCollisionSlotIndex, 0x6000);
        for (i = 0; i < gFoundCollisionSlotCount; i++) {
            if ((gFoundCollisionSlotFlags[i] & 0x4000) != 0) {
                ItemObject *other = gFoundCollisionSlotObjects[i];
                if (other->mCollisionSlotIndex == -1) {
                    continue;
                }
                if ((other->mOwnerKartIndexAndFlags & 0x4000) != 0 &&
                    itemInUse->mKartIndex == (u16) (other->mOwnerKartIndexAndFlags & ~0xff00)) {
                    continue;
                }
                CollideItemObjects(object, other);
            } else if ((gFoundCollisionSlotFlags[i] & 0x2000) != 0) {
                MapObject *other = gFoundCollisionSlotObjects[i];
                if (DoesMapObjectRespondToItemObject(other, object) == FALSE) {
                    continue;
                }
                ApplyMapObjectHitToItemObject(object, other);
            }
            if (object->mCollisionSlotIndex == -1) {
                break;
            }
        }
    }
}

void AdvanceItemInUse(ItemInUse *itemInUse) {
    s32 useKind;
    s32 objectIndex;
    s32 objectCount;
    ItemObject *object;
    Kart *kart;
    enum { K0 } kind;

    useKind = itemInUse->mUseKind;
    if (CopyKartToItemInUse(itemInUse) != FALSE) {
        objectCount = itemInUse->mObjectCount;
        for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
            SetItemObjectScaleByRatios(itemInUse->mObjects[objectIndex], itemInUse->mKartScaleFactorTimesBase.x,
                                       itemInUse->mKartScaleFactorTimesBase.y);
        }
    }
    if (gItemInUseAdvanceTable[useKind] != NULL) {
        gItemInUseAdvanceTable[useKind](itemInUse);
    }
    UpdateItemInUseObjects(itemInUse);
    if (itemInUse->mObjectCount == 0) {
        ResetItemInUse(itemInUse);
    }
    if (itemInUse->mObjectStartFramesLeft <= 0) {
        return;
    }
    itemInUse->mObjectStartFramesLeft = itemInUse->mObjectStartFramesLeft - 1;
    if (itemInUse->mObjectStartFramesLeft != 8 && itemInUse->mObjectStartFramesLeft != 4 &&
        itemInUse->mObjectStartFramesLeft != 0) {
        return;
    }
    itemInUse->mObjectCount = itemInUse->mObjectCount - 1;
    objectIndex = itemInUse->mObjectCount;
    kart = itemInUse->mKart;
    object = itemInUse->mObjects[objectIndex];
    StartItemInUseObject(itemInUse, object);
    LaunchItemObjectFromPos(object, objectIndex + 1, &kart->mDrawMatrixPos, &kart->mVelocity, &kart->mGroundNormal);
    kind = object->mKind;
    if (gItemKinds[kind].mAfterLaunchCallback != NULL) {
        gItemKinds[kind].mAfterLaunchCallback(object);
    }
    if (itemInUse->mObjectCount != 0) {
        return;
    }
    ResetItemInUse(itemInUse);
}

s32 ComputeItemThrowForward(ItemInUse *itemInUse, s32 baseSpeed, s32 speedFactor, s32 forwardWeight,
                            Vec3 *outDirection) {
    Vec3 throwDirection;
    s32 kartMoveLength;
    s32 speed;

    kartMoveLength = VEC_Mag(&itemInUse->mKartMovement);
    if (itemInUse->mMovingForward != 0) {
        speed = baseSpeed + MUL_FIXED12_NO_ROUND(kartMoveLength, speedFactor);
        VEC_MultAdd(forwardWeight, &itemInUse->mKartOrientation.mUnk_00[2], &itemInUse->mKartMovement, &throwDirection);
    } else {
        Vec3 *kartVector;

        kartVector = &itemInUse->mKart->mPointMotion;
        if ((s64) kartVector->x * kartVector->x + (s64) kartVector->y * kartVector->y +
                (s64) kartVector->z * kartVector->z >=
            0x10) {
            speed = baseSpeed + MUL_FIXED12_NO_ROUND(kartMoveLength, speedFactor);
            VEC_MultAdd(forwardWeight, &itemInUse->mKartOrientation.mUnk_00[2], kartVector, &throwDirection);
        } else {
            speed = baseSpeed - kartMoveLength;
            throwDirection = itemInUse->mKartOrientation.mUnk_00[2];
        }
    }
    if ((itemInUse->mKart->mUnk_48 & KART_48_ON_BOOST_SURFACE) == 0) {
        throwDirection.y = 0;
    }
    if ((s64) throwDirection.x * throwDirection.x + (s64) throwDirection.y * throwDirection.y +
            (s64) throwDirection.z * throwDirection.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&throwDirection, outDirection);
    }
    return speed;
}

s32 ComputeItemThrowBackward(ItemInUse *itemInUse, s32 speed, s32 speedFactor, s32 forwardWeight, Vec3 *outDirection) {
    Vec3 throwDirection;
    s32 kartMoveLength;

    kartMoveLength = VEC_Mag(&itemInUse->mKartMovement);
    if (itemInUse->mMovingForward != 0) {
        speed -= kartMoveLength;
        VEC_Subtract(&itemInUse->mKartMovement, &itemInUse->mKart->mPointMotion, &throwDirection);
        VEC_MultAdd(forwardWeight, &itemInUse->mKartOrientation.mUnk_00[2], &throwDirection, &throwDirection);
        throwDirection.x = -throwDirection.x;
        throwDirection.y = -throwDirection.y;
        throwDirection.z = -throwDirection.z;
    } else {
        speed += MUL_FIXED12_NO_ROUND(kartMoveLength, speedFactor);
        throwDirection.x = -itemInUse->mKartOrientation.mUnk_00[2].x;
        throwDirection.y = -itemInUse->mKartOrientation.mUnk_00[2].y;
        throwDirection.z = -itemInUse->mKartOrientation.mUnk_00[2].z;
    }
    if ((itemInUse->mKart->mUnk_48 & KART_48_ON_BOOST_SURFACE) == 0) {
        throwDirection.y = 0;
    }
    if ((s64) throwDirection.x * throwDirection.x + (s64) throwDirection.y * throwDirection.y +
            (s64) throwDirection.z * throwDirection.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&throwDirection, outDirection);
    }
    return speed;
}

void ReleaseItemInUse(ItemInUse *itemInUse) {
    while (itemInUse->mObjectCount > 0) {
        itemInUse->mObjectCount--;
        ReleaseItemPoolObject(&gItemPools[itemInUse->mObjects[itemInUse->mObjectCount]->mKind],
                              itemInUse->mObjects[itemInUse->mObjectCount]);
    }
    ResetItemInUse(itemInUse);
    if (itemInUse->mIsActiveItem != FALSE) {
        itemInUse->mKartItems->mActiveItem = 0x13;
        itemInUse->mIsActiveItem = FALSE;
    }
}

void StartItemInUseObjectCountdown(ItemInUse *itemInUse) {
    itemInUse->mObjectStartFramesLeft = 0xa;
    if (itemInUse->mIsActiveItem != FALSE) {
        itemInUse->mKartItems->mActiveItem = 0x13;
        itemInUse->mIsActiveItem = FALSE;
    }
}

void RemoveItemInUseObject(ItemInUse *itemInUse, ItemObject *object) {
    s32 objectCount;
    ItemObject *target;
    s32 i;

    target = object;
    objectCount = itemInUse->mObjectCount;
    for (i = 0; i < objectCount; i++) {
        if (itemInUse->mObjects[i] == target) {
            ((void (*)(void *, s32, ItemObject *))((void **) gItemInUseRemoveTable)[itemInUse->mUseKind])(itemInUse, i,
                                                                                                          target);
            if (itemInUse->mObjectCount != 0) {
                return;
            }
            ResetItemInUse(itemInUse);
            return;
        }
    }
}

void *BuildItemObjectMatrix(ItemObject *object, Vec3 *viewAxis) {
    if (object->mNormal.y < 0xfae || (object->mFlags & 0x80) != 0) {
        object->mUnk_94.mUnk_00[2] = *viewAxis;
        Vec3CrossUnrounded(&object->mNormal, &object->mUnk_94.mUnk_00[2], &object->mUnk_94.mUnk_00[0]);
        if ((s64) object->mUnk_94.mUnk_00[0].x * object->mUnk_94.mUnk_00[0].x +
                (s64) object->mUnk_94.mUnk_00[0].y * object->mUnk_94.mUnk_00[0].y +
                (s64) object->mUnk_94.mUnk_00[0].z * object->mUnk_94.mUnk_00[0].z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&object->mUnk_94.mUnk_00[0], &object->mUnk_94.mUnk_00[0]);
        }
        Vec3CrossUnrounded(&object->mUnk_94.mUnk_00[2], &object->mUnk_94.mUnk_00[0], &object->mUnk_94.mUnk_00[1]);
        {
            Vec3 *position;

            position = object->mPosPointer;
            object->mUnk_94.mUnk_00[3].x = position->x >> 4;
            object->mUnk_94.mUnk_00[3].y = position->y >> 4;
            object->mUnk_94.mUnk_00[3].z = position->z >> 4;
        }
        return &object->mUnk_94.mUnk_00[0];
    } else {
        return SetViewAxis2MatrixPos(object->mPosPointer);
    }
}

void DrawItemPoolModels(ItemPool *pool, Vec3 *viewAxis) {
    s16 d8;
    s32 i;
    NsbmdModel *model;
    s32 takenCount;
    s32 activeCount;
    ItemObject *object;
    void *matrix;

    model = gItemModels[pool->mKind];
    takenCount = pool->mTakenCount;
    activeCount = pool->mActiveCount;
    QueueNsbmdModelMaterial(model);
    model->mPolygonAttributes &= ~0x3f000000;
    model->mPolygonAttributes |= 0x4000000;
    for (i = 0; i < takenCount; i++) {
        object = pool->mObjects[i];
        if ((object->mFlags & 0x10000) != 0) {
            continue;
        }
        if ((object->mFlags & 0x1000) != 0) {
            SendLight01Color(object->mKartLightColor);
        } else {
            SendLight01Color(&object->mColorBlend.mColor);
        }
        if ((d8 = object->mAlpha) != 0x1f) {
            model->mPolygonAttributes &= ~0x1f0000;
            model->mPolygonAttributes |= (u16) d8 << 16;
        }
        if (i == activeCount) {
            model->mPolygonAttributes &= ~0x3f000000;
            model->mPolygonAttributes |= 0x3000000;
        }
        if (object->mNormal.y < 0xfae || (object->mFlags & 0x80) != 0) {
            object->mUnk_94.mUnk_00[2] = *viewAxis;
            Vec3CrossUnrounded(&object->mNormal, &object->mUnk_94.mUnk_00[2], &object->mUnk_94.mUnk_00[0]);
            if ((s64) object->mUnk_94.mUnk_00[0].x * object->mUnk_94.mUnk_00[0].x +
                    (s64) object->mUnk_94.mUnk_00[0].y * object->mUnk_94.mUnk_00[0].y +
                    (s64) object->mUnk_94.mUnk_00[0].z * object->mUnk_94.mUnk_00[0].z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&object->mUnk_94.mUnk_00[0], &object->mUnk_94.mUnk_00[0]);
            }
            Vec3CrossUnrounded(&object->mUnk_94.mUnk_00[2], &object->mUnk_94.mUnk_00[0], &object->mUnk_94.mUnk_00[1]);
            {
                Vec3 *position;

                position = object->mPosPointer;
                object->mUnk_94.mUnk_00[3].x = position->x >> 4;
                object->mUnk_94.mUnk_00[3].y = position->y >> 4;
                object->mUnk_94.mUnk_00[3].z = position->z >> 4;
            }
            matrix = &object->mUnk_94.mUnk_00[0];
        } else {
            matrix = SetViewAxis2MatrixPos(object->mPosPointer);
        }
        DrawNsbmdModelWithMatrixAndMaxAlpha(model, matrix, &object->mScale, 0, 0x1f);
        if ((d8 = object->mAlpha) != 0x1f) {
            model->mPolygonAttributes &= ~0x1f0000;
            model->mPolygonAttributes |= 0x1f0000;
        }
    }
}

void DrawItemPoolWithCallback(ItemPool *pool, void *callbackArg, void (*drawCallback)(void *, void *, void *)) {
    s32 takenCount;
    s32 i;
    ItemObject *object;

    takenCount = pool->mTakenCount;
    for (i = 0; i < takenCount; i++) {
        object = pool->mObjects[i];
        if ((object->mFlags & 0x10000) != 0) {
            continue;
        }
        if ((object->mFlags & 0x1000) != 0) {
            SendLight01Color(object->mKartLightColor);
        } else {
            SendLight01Color(&object->mColorBlend.mColor);
        }
        drawCallback(object, callbackArg, gItemModels[pool->mKind]);
    }
}

void DrawItemObjectModel(ItemObject *object, NsbmdModel *model, Vec3 *viewAxis) {
    s16 d;
    void *matrix;

    if ((d = object->mAlpha) != 0x1f) {
        model->mPolygonAttributes &= ~0x1f0000;
        model->mPolygonAttributes |= (u16) d << 16;
    }
    QueueNsbmdModelMaterial(model);
    if (object->mNormal.y < 0xfae || (object->mFlags & 0x80) != 0) {
        object->mUnk_94.mUnk_00[2] = *viewAxis;
        Vec3CrossUnrounded(&object->mNormal, &object->mUnk_94.mUnk_00[2], &object->mUnk_94.mUnk_00[0]);
        if ((s64) object->mUnk_94.mUnk_00[0].x * object->mUnk_94.mUnk_00[0].x +
                (s64) object->mUnk_94.mUnk_00[0].y * object->mUnk_94.mUnk_00[0].y +
                (s64) object->mUnk_94.mUnk_00[0].z * object->mUnk_94.mUnk_00[0].z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&object->mUnk_94.mUnk_00[0], &object->mUnk_94.mUnk_00[0]);
        }
        Vec3CrossUnrounded(&object->mUnk_94.mUnk_00[2], &object->mUnk_94.mUnk_00[0], &object->mUnk_94.mUnk_00[1]);
        {
            Vec3 *position;

            position = object->mPosPointer;
            object->mUnk_94.mUnk_00[3].x = position->x >> 4;
            object->mUnk_94.mUnk_00[3].y = position->y >> 4;
            object->mUnk_94.mUnk_00[3].z = position->z >> 4;
        }
        matrix = &object->mUnk_94.mUnk_00[0];
    } else {
        matrix = SetViewAxis2MatrixPos(object->mPosPointer);
    }
    DrawNsbmdModelWithMatrixAndMaxAlpha(model, matrix, &object->mScale, 0, 0x1f);
    if ((d = object->mAlpha) != 0x1f) {
        model->mPolygonAttributes &= ~0x1f0000;
        model->mPolygonAttributes |= 0x1f0000;
    }
}
