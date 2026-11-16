#include "Main/Item/ItemInUse.h"
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
    itemInUse->mKartOrientation = *(KartOrientation *) &kart->field150;
    itemInUse->mKartDrawMatrixPos = kart->mDrawMatrixPos;
    itemInUse->mKartVelocity = kart->mVelocity;
    itemInUse->mKartVelocityLength = kart->mVelocityLength;
    itemInUse->field78 = ((s64) kart->mPhysicalParam->field8 * kart->mScale.z + 0x800) >> 12;
    itemInUse->mKartHopHeight = kart->mHopHeight;
    itemInUse->mMovingForward = vec_dotProduct(&itemInUse->mKartOrientation.field18, &itemInUse->mKartVelocity) > 0;
    VEC_Subtract(&itemInUse->mKartDrawMatrixPos, &kart->mPrevPos, &itemInUse->mKartMovement);
    scale.x = ((s64) kart->mScaleFactor.x * kart->mScaleBase.x) >> 12;
    scale.y = ((s64) kart->mScaleFactor.y * kart->mScaleBase.y) >> 12;
    scale.z = ((s64) kart->mScaleFactor.z * kart->mScaleBase.z) >> 12;
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

void it_20EE2E4(ItemInUse *itemInUse, HeldItem *heldItem) {
    void (*startFunc)(void *);
    s32 useKind;
    s32 itemInfoIndex;
    void (*useHook)(void *, void *);
    BOOL isMode5;
    ItemObject **objects;
    s32 objectCount;
    ItemObject *object;
    s32 i;
    u16 *kartModelHalfwords;
    s32 poolIndex;

    itemInfoIndex = heldItem->mItemInfoIndex;
    useKind = it_sItemConfigs[itemInfoIndex].mUseKind;
    isMode5 = gRaceMultiConfig->mMode == 5;
    if (heldItem->fieldC != 0) {
        if (heldItem->mTimer > heldItem->field12) {
            return;
        }
    }
    startFunc = gItemInUseStartTable[useKind];
    useHook = it_sItemConfigs[itemInfoIndex].mUseHook;
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
        driver_tryEmitItemUseVoice(itemInUse->mKart);
        return;
    }
    itemInUse->mObjectKind = it_sItemConfigs[itemInfoIndex].mObjectKind;
    itemInUse->mObjectCount = it_sItemConfigs[itemInfoIndex].mObjectCount;
    itemInUse->mUseKind = useKind;
    itemInUse->mItemInfoIndex = itemInfoIndex;
    itemInUse->field170 = NULL;
    itemInUse->fieldE8 = it_sItemConfigs[itemInfoIndex].mObjectKind == 8 ? 0xb400 : 0x4333;
    poolIndex = *(vs32 *) &itemInUse->mObjectKind;
    it_itemsetAcquireItems(&it_sItemsets[poolIndex], itemInUse->mObjectCount, itemInUse->mObjects, itemInUse->mKart->mIndex,
                        &itemInUse->mKartDrawMatrixPos);
    CopyKartToItemInUse(itemInUse);
    if (startFunc != NULL) {
        startFunc(itemInUse);
    }
    if (useHook != NULL) {
        useHook(itemInUse, heldItem);
    }
    driver_notifyDragItemChanged(itemInUse->mKart);
    it_resetSlot(heldItem);
    if (itemInUse->field170 != NULL) {
        SetActiveItem(itemInUse->mKartItems, itemInUse->mItemInfoIndex);
    }
    objects = itemInUse->mObjects;
    kartModelHalfwords = &itemInUse->mKart->mKartModelsEntry->field40;
    objectCount = itemInUse->mObjectCount;
    for (i = 0; i < objectCount; i++) {
        object = objects[i];
        object->mAgeFrames = 0;
        object->mPrevPos = object->mPos;
        object->mVelocity = itemInUse->mKartVelocity;
        SetItemObjectScaleByRatios(object, itemInUse->mKartScaleFactorTimesBase.x,
                                   itemInUse->mKartScaleFactorTimesBase.y);
        object->field90 = kartModelHalfwords;
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
        if (object->field48 > other->field48) {
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
    it_20F77F8(object, n, &other->mPos, &other->mVelocity, NULL);
    it_20F77F8(other, m, &object->mPos, &savedVelocity, NULL);
    if (other->mKind != 1) {
        return;
    }
    func_020f5614(other, m, object);
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
    a = func_0206c0a8(itemInUse->mKart);
    b = func_0206c094(itemInUse->mKart);
    for (i = 0; i < objectCount; i++) {
        object = objects[i];
        object->mAgeFrames = object->mAgeFrames + 1;
        VEC_Subtract(&object->mPos, &object->mPrevPos, &object->mVelocity);
        object->mPrevPos = object->mPos;
        if (itemInUse->mObjectStartFramesLeft == 0) {
            object->mNormal = itemInUse->mKartOrientation.fieldC;
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
            if (func_020f91e0(object) != FALSE) {
                idx = object->mKind;
                if (it_sItemParams[idx].field68 != 0) {
                    CreateItemObjectCollisionSlot(object);
                }
            }
            continue;
        }
        col_queryByColEntry(object->mCollisionSlotIndex, 0x6000);
        for (i = 0; i < gColQueryResultCount; i++) {
            if ((gColQueryResultFlags[i] & 0x4000) != 0) {
                ItemObject *other = gColQueryResultObjects[i];
                if (other->mCollisionSlotIndex == -1) {
                    continue;
                }
                if ((other->field78 & 0x4000) != 0 && itemInUse->mKartIndex == (u16) (other->field78 & ~0xff00)) {
                    continue;
                }
                CollideItemObjects(object, other);
            } else if ((gColQueryResultFlags[i] & 0x2000) != 0) {
                MapObject *other = gColQueryResultObjects[i];
                if (mobj_destroysItemOnHit(other, object) == FALSE) {
                    continue;
                }
                it_20F944C(object, other);
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
        it_resetDragItem(itemInUse);
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
    it_startThrowAnim(object, objectIndex + 1, &kart->mDrawMatrixPos, &kart->mVelocity, &kart->mGroundNormal);
    kind = object->mKind;
    if (it_sItemParams[kind].field38 != NULL) {
        it_sItemParams[kind].field38(object);
    }
    if (itemInUse->mObjectCount != 0) {
        return;
    }
    it_resetDragItem(itemInUse);
}

s32 ComputeItemThrowForward(ItemInUse *itemInUse, s32 baseSpeed, s32 speedFactor, s32 forwardWeight,
                            Vec3 *outDirection) {
    Vec3 throwDirection;
    s32 kartMoveLength;
    s32 speed;

    kartMoveLength = VEC_Mag(&itemInUse->mKartMovement);
    if (itemInUse->mMovingForward != 0) {
        speed = baseSpeed + (s32) (((s64) kartMoveLength * speedFactor) >> 12);
        VEC_MultAdd(forwardWeight, &itemInUse->mKartOrientation.field18, &itemInUse->mKartMovement, &throwDirection);
    } else {
        Vec3 *kartVector;

        kartVector = &itemInUse->mKart->field1FC;
        if ((s64) kartVector->x * kartVector->x + (s64) kartVector->y * kartVector->y +
                (s64) kartVector->z * kartVector->z >=
            0x10) {
            speed = baseSpeed + (s32) (((s64) kartMoveLength * speedFactor) >> 12);
            VEC_MultAdd(forwardWeight, &itemInUse->mKartOrientation.field18, kartVector, &throwDirection);
        } else {
            speed = baseSpeed - kartMoveLength;
            throwDirection = itemInUse->mKartOrientation.field18;
        }
    }
    if ((itemInUse->mKart->field48 & 1) == 0) {
        throwDirection.y = 0;
    }
    if ((s64) throwDirection.x * throwDirection.x + (s64) throwDirection.y * throwDirection.y +
            (s64) throwDirection.z * throwDirection.z >=
        0x10) {
        vec_normalize(&throwDirection, outDirection);
    }
    return speed;
}

s32 ComputeItemThrowBackward(ItemInUse *itemInUse, s32 speed, s32 speedFactor, s32 forwardWeight, Vec3 *outDirection) {
    Vec3 throwDirection;
    s32 kartMoveLength;

    kartMoveLength = VEC_Mag(&itemInUse->mKartMovement);
    if (itemInUse->mMovingForward != 0) {
        speed -= kartMoveLength;
        VEC_Subtract(&itemInUse->mKartMovement, &itemInUse->mKart->field1FC, &throwDirection);
        VEC_MultAdd(forwardWeight, &itemInUse->mKartOrientation.field18, &throwDirection, &throwDirection);
        throwDirection.x = -throwDirection.x;
        throwDirection.y = -throwDirection.y;
        throwDirection.z = -throwDirection.z;
    } else {
        speed += (s32) (((s64) kartMoveLength * speedFactor) >> 12);
        throwDirection.x = -itemInUse->mKartOrientation.field18.x;
        throwDirection.y = -itemInUse->mKartOrientation.field18.y;
        throwDirection.z = -itemInUse->mKartOrientation.field18.z;
    }
    if ((itemInUse->mKart->field48 & 1) == 0) {
        throwDirection.y = 0;
    }
    if ((s64) throwDirection.x * throwDirection.x + (s64) throwDirection.y * throwDirection.y +
            (s64) throwDirection.z * throwDirection.z >=
        0x10) {
        vec_normalize(&throwDirection, outDirection);
    }
    return speed;
}

void it_destroyDragItem(ItemInUse *itemInUse) {
    while (itemInUse->mObjectCount > 0) {
        itemInUse->mObjectCount--;
        it_itemsetDestroyItem(&it_sItemsets[itemInUse->mObjects[itemInUse->mObjectCount]->mKind],
                              itemInUse->mObjects[itemInUse->mObjectCount]);
    }
    it_resetDragItem(itemInUse);
    if (itemInUse->field170 != NULL) {
        itemInUse->mKartItems->mActiveItem = 0x13;
        itemInUse->field170 = NULL;
    }
}

void StartItemInUseObjectCountdown(ItemInUse *itemInUse) {
    itemInUse->mObjectStartFramesLeft = 0xa;
    if (itemInUse->field170 != NULL) {
        itemInUse->mKartItems->mActiveItem = 0x13;
        itemInUse->field170 = NULL;
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
            it_resetDragItem(itemInUse);
            return;
        }
    }
}

void *BuildItemObjectMatrix(ItemObject *object, Vec3 *viewAxis) {
    if (object->mNormal.y < 0xfae || (object->mFlags & 0x80) != 0) {
        object->field94.field0[2] = *viewAxis;
        vec_crossProduct(&object->mNormal, &object->field94.field0[2], &object->field94.field0[0]);
        if ((s64) object->field94.field0[0].x * object->field94.field0[0].x +
                (s64) object->field94.field0[0].y * object->field94.field0[0].y +
                (s64) object->field94.field0[0].z * object->field94.field0[0].z >=
            0x10) {
            vec_normalize(&object->field94.field0[0], &object->field94.field0[0]);
        }
        vec_crossProduct(&object->field94.field0[2], &object->field94.field0[0], &object->field94.field0[1]);
        {
            Vec3 *position;

            position = object->fieldD0;
            object->field94.field0[3].x = position->x >> 4;
            object->field94.field0[3].y = position->y >> 4;
            object->field94.field0[3].z = position->z >> 4;
        }
        return &object->field94.field0[0];
    } else {
        return bbm_20E6B94(object->fieldD0);
    }
}

void it_20ED79C(ItemPool *pool, Vec3 *viewAxis) {
    s16 d8;
    s32 i;
    NsbmdModel *model;
    s32 takenCount;
    s32 activeCount;
    ItemObject *object;
    void *matrix;

    model = it_sBillboardModels[pool->mKind];
    takenCount = pool->mTakenCount;
    activeCount = pool->mActiveCount;
    bbm_applyMaterial(model);
    model->field14 &= ~0x3f000000;
    model->field14 |= 0x4000000;
    for (i = 0; i < takenCount; i++) {
        object = pool->mObjects[i];
        if ((object->mFlags & 0x10000) != 0) {
            continue;
        }
        if ((object->mFlags & 0x1000) != 0) {
            light_apply(object->field90);
        } else {
            light_apply(&object->mColorBlend.mColor);
        }
        if ((d8 = object->mAlpha) != 0x1f) {
            model->field14 &= ~0x1f0000;
            model->field14 |= (u16) d8 << 16;
        }
        if (i == activeCount) {
            model->field14 &= ~0x3f000000;
            model->field14 |= 0x3000000;
        }
        if (object->mNormal.y < 0xfae || (object->mFlags & 0x80) != 0) {
            object->field94.field0[2] = *viewAxis;
            vec_crossProduct(&object->mNormal, &object->field94.field0[2], &object->field94.field0[0]);
            if ((s64) object->field94.field0[0].x * object->field94.field0[0].x +
                    (s64) object->field94.field0[0].y * object->field94.field0[0].y +
                    (s64) object->field94.field0[0].z * object->field94.field0[0].z >=
                0x10) {
                vec_normalize(&object->field94.field0[0], &object->field94.field0[0]);
            }
            vec_crossProduct(&object->field94.field0[2], &object->field94.field0[0], &object->field94.field0[1]);
            {
                Vec3 *position;

                position = object->fieldD0;
                object->field94.field0[3].x = position->x >> 4;
                object->field94.field0[3].y = position->y >> 4;
                object->field94.field0[3].z = position->z >> 4;
            }
            matrix = &object->field94.field0[0];
        } else {
            matrix = bbm_20E6B94(object->fieldD0);
        }
        bbm_renderTransformedScaled(model, matrix, &object->mScale, 0, 0x1f);
        if ((d8 = object->mAlpha) != 0x1f) {
            model->field14 &= ~0x1f0000;
            model->field14 |= 0x1f0000;
        }
    }
}

void it_20ED718(ItemPool *pool, void *callbackArg, void (*drawCallback)(void *, void *, void *)) {
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
            light_apply(object->field90);
        } else {
            light_apply(&object->mColorBlend.mColor);
        }
        drawCallback(object, callbackArg, it_sBillboardModels[pool->mKind]);
    }
}

void DrawItemObjectModel(ItemObject *object, NsbmdModel *model, Vec3 *viewAxis) {
    s16 d;
    void *matrix;

    if ((d = object->mAlpha) != 0x1f) {
        model->field14 &= ~0x1f0000;
        model->field14 |= (u16) d << 16;
    }
    bbm_applyMaterial(model);
    if (object->mNormal.y < 0xfae || (object->mFlags & 0x80) != 0) {
        object->field94.field0[2] = *viewAxis;
        vec_crossProduct(&object->mNormal, &object->field94.field0[2], &object->field94.field0[0]);
        if ((s64) object->field94.field0[0].x * object->field94.field0[0].x +
                (s64) object->field94.field0[0].y * object->field94.field0[0].y +
                (s64) object->field94.field0[0].z * object->field94.field0[0].z >=
            0x10) {
            vec_normalize(&object->field94.field0[0], &object->field94.field0[0]);
        }
        vec_crossProduct(&object->field94.field0[2], &object->field94.field0[0], &object->field94.field0[1]);
        {
            Vec3 *position;

            position = object->fieldD0;
            object->field94.field0[3].x = position->x >> 4;
            object->field94.field0[3].y = position->y >> 4;
            object->field94.field0[3].z = position->z >> 4;
        }
        matrix = &object->field94.field0[0];
    } else {
        matrix = bbm_20E6B94(object->fieldD0);
    }
    bbm_renderTransformedScaled(model, matrix, &object->mScale, 0, 0x1f);
    if ((d = object->mAlpha) != 0x1f) {
        model->field14 &= ~0x1f0000;
        model->field14 |= 0x1f0000;
    }
}
