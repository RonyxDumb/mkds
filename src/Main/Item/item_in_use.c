#include "Main/Item/item_object_bounce_hit_release_fade.h"
#include "Main/Item/item_in_use.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"
#include "Main/Race/race_rank_list.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Item/item_object_release.h"
#include "Main/Item/item_slot_tables.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "ITCM/collision_slots.h"
#include "Main/Item/pooled_map_object.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Item/item_object.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_object_reset_collide.h"
#include "Main/Graphics/light_color.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Item/item_pool.h"
#include "fixed_vector_math.h"
#include "Main/Item/item_link_following.h"

void (*gItemInUseAdvanceTable[5])(ItemInUse *) = {NULL, AdvanceItemInUseOne, AdvanceItemInUseOneWithOrientation,
                                                  AdvanceItemInUseTrail, AdvanceItemInUseCircle};
void (*gItemInUseRemoveTable[5])(ItemInUse *, s32, ItemObject *) = {NULL, RemoveItemInUseOne, RemoveItemInUseOne,
                                                                    RemoveItemInUseTrail, RemoveItemInUseCircle};
void (*gItemInUseStartTable[5])(ItemInUse *) = {NULL, StartItemInUseOne, StartItemInUseOneWithOrientation,
                                                StartItemInUseTrail, StartItemInUseCircle};

BOOL CopyKartToItemInUse(ItemInUse *itemInUse) {
    Kart *kart;
    Vec3 scale;
    s32 scaleUnchanged;

    kart = itemInUse->mKart;
    itemInUse->mKartOrientation = kart->mDrawBaseMatrix.mAxes;
    itemInUse->mKartDrawMatrixPos = kart->mDrawMatrixPos;
    itemInUse->mKartVelocity = kart->mVelocity;
    itemInUse->mKartVelocityLength = kart->mVelocityLength;
    itemInUse->mBehindDistance = MUL_FIXED12_ROUNDED(kart->mPhysicalParam->mBehindDistance, kart->mScale.z);
    itemInUse->mKartHopHeight = kart->mHopHeight;
    itemInUse->mMovingForward = Vec3DotUnrounded(&itemInUse->mKartOrientation.mRows[2], &itemInUse->mKartVelocity) > 0;
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
    void (*startFunc)(ItemInUse *);
    s32 useKind;
    s32 itemInfoIndex;
    void (*useHook)(struct ItemInUse *, struct HeldItem *);
    BOOL isWiFi;
    ItemObject **objects;
    s32 objectCount;
    ItemObject *object;
    s32 objectIndex;
    u16 *kartModelHalfwords;
    s32 poolIndex;

    itemInfoIndex = heldItem->mItemInfoIndex;
    useKind = gItemInfos[itemInfoIndex].mUseKind;
    isWiFi = gRaceSetup->mMode == MODE_WIFI;
    if (heldItem->mUsesTimer != 0) {
        if (heldItem->mTimer > heldItem->mUseTimerLimit) {
            return;
        }
    }
    startFunc = gItemInUseStartTable[useKind];
    useHook = gItemInfos[itemInfoIndex].mUseHook;
    if (!isWiFi) {
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
    itemInUse->mObjectHeight = gItemInfos[itemInfoIndex].mObjectKind == ITEM_OBJECT_KIND_BOUNCING_ITEM_BOX
                                   ? ITEM_IN_USE_OBJECT_HEIGHT_BOUNCING_ITEM_BOX
                                   : ITEM_IN_USE_OBJECT_HEIGHT;
    poolIndex = itemInUse->mObjectKind;
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
    for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
        object = objects[objectIndex];
        object->mAgeFrames = 0;
        object->mPrevPos = object->mPos;
        object->mVelocity = itemInUse->mKartVelocity;
        SetItemObjectScaleByRatios(object, itemInUse->mKartScaleFactorTimesBase.x,
                                   itemInUse->mKartScaleFactorTimesBase.y);
        object->mKartLightColor = kartModelHalfwords;
        object->mFlags |= ITEM_OBJECT_FLAG_IN_USE;
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
    return SQUARE_SUM3(deltaX, deltaY, deltaZ) <
           (s64) combinedRadius * combinedRadius;
}

void CollideItemObjects(ItemObject *object, ItemObject *other) {
    Vec3 savedVelocity;
    s32 objectHitType;
    s32 otherHitType;

    if ((other->mFlags & ITEM_OBJECT_FLAG_IN_USE) != 0) {
        if (object->mCreationNumber > other->mCreationNumber) {
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
    objectHitType = GetItemObjectHitType(object, other);
    otherHitType = GetItemObjectHitType(other, object);
    ApplyItemObjectHitType(object, objectHitType, &other->mPos, &other->mVelocity, NULL);
    ApplyItemObjectHitType(other, otherHitType, &object->mPos, &savedVelocity, NULL);
    if (other->mKind != ITEM_OBJECT_KIND_KOURA_R) {
        return;
    }
    StartTargetKartSoundOnOwnItemHit(other, otherHitType, object);
}

void UpdateItemInUseObjects(ItemInUse *itemInUse) {
    ItemObject **objects;
    s32 objectCount;
    ItemObject *object;
    s32 index;
    s32 courseHitAttributeBit;
    s32 outOfView;
    s32 reverseIndex;
    enum { INDEX_FIRST } idx;

    objects = itemInUse->mObjects;
    objectCount = itemInUse->mObjectCount;
    courseHitAttributeBit = GetKartCourseHitAttributeBit(itemInUse->mKart);
    outOfView = IsKartOutOfView(itemInUse->mKart);
    for (index = 0; index < objectCount; index++) {
        object = objects[index];
        object->mAgeFrames = object->mAgeFrames + 1;
        VEC_Subtract(&object->mPos, &object->mPrevPos, &object->mVelocity);
        object->mPrevPos = object->mPos;
        if (itemInUse->mObjectStartFramesLeft == 0) {
            object->mNormal = itemInUse->mKartOrientation.mRows[1];
            if (object->mNormal.y < 0xff4) {
                object->mFlags |= ITEM_OBJECT_FLAG_KEEP_NORMAL;
            }
        }
        if (courseHitAttributeBit != 0) {
            object->mFlags |= ITEM_OBJECT_FLAG_COURSE_HIT_ATTRIBUTE;
        } else {
            object->mFlags &= ~ITEM_OBJECT_FLAG_COURSE_HIT_ATTRIBUTE;
        }
        if (outOfView != 0) {
            object->mFlags |= ITEM_OBJECT_FLAG_OUT_OF_VIEW;
        } else {
            object->mFlags &= ~ITEM_OBJECT_FLAG_OUT_OF_VIEW;
        }
    }
    for (reverseIndex = objectCount - 1; reverseIndex >= 0; reverseIndex--) {
        object = objects[reverseIndex];
        if (object->mCollisionSlotIndex == -1) {
            if (IsItemObjectScaleAtSetupSize(object) != FALSE) {
                idx = object->mKind;
                if (gItemKinds[idx].mSetupRadius != 0) {
                    CreateItemObjectCollisionSlot(object);
                }
            }
            continue;
        }
        FindCollisionSlotsOverlappingSlot(object->mCollisionSlotIndex, 0x6000);
        for (index = 0; index < gFoundCollisionSlotCount; index++) {
            if ((gFoundCollisionSlotFlags[index] & 0x4000) != 0) {
                ItemObject *other = gFoundCollisionSlotObjects[index];
                if (other->mCollisionSlotIndex == -1) {
                    continue;
                }
                if ((other->mOwnerKartIndexAndFlags & ITEM_OWNER_EXCLUDED) != 0 &&
                    itemInUse->mKartIndex == (u16) (other->mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK)) {
                    continue;
                }
                CollideItemObjects(object, other);
            } else if ((gFoundCollisionSlotFlags[index] & 0x2000) != 0) {
                MapObject *other = gFoundCollisionSlotObjects[index];
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
    enum { KIND_FIRST } kind;

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
    if (itemInUse->mObjectStartFramesLeft != ITEM_IN_USE_FIRST_LAUNCH_FRAME &&
        itemInUse->mObjectStartFramesLeft != ITEM_IN_USE_SECOND_LAUNCH_FRAME &&
        itemInUse->mObjectStartFramesLeft != ITEM_IN_USE_THIRD_LAUNCH_FRAME) {
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
        VEC_MultAdd(forwardWeight, &itemInUse->mKartOrientation.mRows[2], &itemInUse->mKartMovement, &throwDirection);
    } else {
        Vec3 *kartVector;

        kartVector = &itemInUse->mKart->mPointMotion;
        if (SQUARE_SUM3(kartVector->x, kartVector->y, kartVector->z) >=
            0x10) {
            speed = baseSpeed + MUL_FIXED12_NO_ROUND(kartMoveLength, speedFactor);
            VEC_MultAdd(forwardWeight, &itemInUse->mKartOrientation.mRows[2], kartVector, &throwDirection);
        } else {
            speed = baseSpeed - kartMoveLength;
            throwDirection = itemInUse->mKartOrientation.mRows[2];
        }
    }
    if ((itemInUse->mKart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) == 0) {
        throwDirection.y = 0;
    }
    if (SQUARE_SUM3(throwDirection.x, throwDirection.y, throwDirection.z) >=
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
        VEC_MultAdd(forwardWeight, &itemInUse->mKartOrientation.mRows[2], &throwDirection, &throwDirection);
        throwDirection.x = -throwDirection.x;
        throwDirection.y = -throwDirection.y;
        throwDirection.z = -throwDirection.z;
    } else {
        speed += MUL_FIXED12_NO_ROUND(kartMoveLength, speedFactor);
        throwDirection.x = -itemInUse->mKartOrientation.mRows[2].x;
        throwDirection.y = -itemInUse->mKartOrientation.mRows[2].y;
        throwDirection.z = -itemInUse->mKartOrientation.mRows[2].z;
    }
    if ((itemInUse->mKart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) == 0) {
        throwDirection.y = 0;
    }
    if (SQUARE_SUM3(throwDirection.x, throwDirection.y, throwDirection.z) >=
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
        itemInUse->mKartItems->mActiveItem = ITEM_INFO_NONE;
        itemInUse->mIsActiveItem = FALSE;
    }
}

void StartItemInUseObjectCountdown(ItemInUse *itemInUse) {
    itemInUse->mObjectStartFramesLeft = ITEM_IN_USE_OBJECT_START_FRAMES;
    if (itemInUse->mIsActiveItem != FALSE) {
        itemInUse->mKartItems->mActiveItem = ITEM_INFO_NONE;
        itemInUse->mIsActiveItem = FALSE;
    }
}

void RemoveItemInUseObject(ItemInUse *itemInUse, ItemObject *object) {
    s32 objectCount;
    ItemObject *target;
    s32 objectIndex;

    target = object;
    objectCount = itemInUse->mObjectCount;
    for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
        if (itemInUse->mObjects[objectIndex] == target) {
            gItemInUseRemoveTable[itemInUse->mUseKind](itemInUse, objectIndex, target);
            if (itemInUse->mObjectCount != 0) {
                return;
            }
            ResetItemInUse(itemInUse);
            return;
        }
    }
}

void *BuildItemObjectMatrix(ItemObject *object, Vec3 *viewAxis) {
    if (object->mNormal.y < 0xfae || (object->mFlags & ITEM_OBJECT_FLAG_KEEP_NORMAL) != 0) {
        object->mTransformMtx.mRows[2] = *viewAxis;
        Vec3CrossUnrounded(&object->mNormal, &object->mTransformMtx.mRows[2], &object->mTransformMtx.mRows[0]);
        if ((s64) object->mTransformMtx.mRows[0].x * object->mTransformMtx.mRows[0].x +
                (s64) object->mTransformMtx.mRows[0].y * object->mTransformMtx.mRows[0].y +
                (s64) object->mTransformMtx.mRows[0].z * object->mTransformMtx.mRows[0].z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&object->mTransformMtx.mRows[0], &object->mTransformMtx.mRows[0]);
        }
        Vec3CrossUnrounded(&object->mTransformMtx.mRows[2], &object->mTransformMtx.mRows[0],
                           &object->mTransformMtx.mRows[1]);
        {
            Vec3 *position;

            position = object->mPosPointer;
            object->mTransformMtx.mRows[3].x = position->x >> 4;
            object->mTransformMtx.mRows[3].y = position->y >> 4;
            object->mTransformMtx.mRows[3].z = position->z >> 4;
        }
        return &object->mTransformMtx.mRows[0];
    } else {
        return SetViewAxis2MatrixPos(object->mPosPointer);
    }
}

void DrawItemPoolModels(ItemPool *pool, Vec3 *viewAxis) {
    s16 alpha;
    s32 objectIndex;
    NsbmdModel *model;
    s32 takenCount;
    s32 activeCount;
    ItemObject *object;
    void *matrix;

    model = gItemModels[pool->mKind];
    takenCount = pool->mTakenCount;
    activeCount = pool->mActiveCount;
    QueueNsbmdModelMaterial(model);
    model->mPolygonAttributes &= ~POLYGON_ATTR_ID_MASK;
    model->mPolygonAttributes |= ITEM_MODEL_POLYGON_ID << POLYGON_ATTR_ID_SHIFT;
    for (objectIndex = 0; objectIndex < takenCount; objectIndex++) {
        object = pool->mObjects[objectIndex];
        if ((object->mFlags & ITEM_OBJECT_FLAG_OUT_OF_VIEW) != 0) {
            continue;
        }
        if ((object->mFlags & ITEM_OBJECT_FLAG_IN_USE) != 0) {
            SendLight01Color(object->mKartLightColor);
        } else {
            SendLight01Color(&object->mColorBlend.mColor);
        }
        if ((alpha = object->mAlpha) != 0x1f) {
            model->mPolygonAttributes &= ~POLYGON_ATTR_ALPHA_MASK;
            model->mPolygonAttributes |= (u16) alpha << POLYGON_ATTR_ALPHA_SHIFT;
        }
        if (objectIndex == activeCount) {
            model->mPolygonAttributes &= ~POLYGON_ATTR_ID_MASK;
            model->mPolygonAttributes |= ITEM_MODEL_POLYGON_ID_BEYOND_ACTIVE << POLYGON_ATTR_ID_SHIFT;
        }
        if (object->mNormal.y < 0xfae || (object->mFlags & ITEM_OBJECT_FLAG_KEEP_NORMAL) != 0) {
            object->mTransformMtx.mRows[2] = *viewAxis;
            Vec3CrossUnrounded(&object->mNormal, &object->mTransformMtx.mRows[2], &object->mTransformMtx.mRows[0]);
            if ((s64) object->mTransformMtx.mRows[0].x * object->mTransformMtx.mRows[0].x +
                    (s64) object->mTransformMtx.mRows[0].y * object->mTransformMtx.mRows[0].y +
                    (s64) object->mTransformMtx.mRows[0].z * object->mTransformMtx.mRows[0].z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&object->mTransformMtx.mRows[0], &object->mTransformMtx.mRows[0]);
            }
            Vec3CrossUnrounded(&object->mTransformMtx.mRows[2], &object->mTransformMtx.mRows[0],
                               &object->mTransformMtx.mRows[1]);
            {
                Vec3 *position;

                position = object->mPosPointer;
                object->mTransformMtx.mRows[3].x = position->x >> 4;
                object->mTransformMtx.mRows[3].y = position->y >> 4;
                object->mTransformMtx.mRows[3].z = position->z >> 4;
            }
            matrix = &object->mTransformMtx.mRows[0];
        } else {
            matrix = SetViewAxis2MatrixPos(object->mPosPointer);
        }
        DrawNsbmdModelWithMatrixAndMaxAlpha(model, matrix, &object->mScale, 0, 0x1f);
        if ((alpha = object->mAlpha) != 0x1f) {
            model->mPolygonAttributes &= ~POLYGON_ATTR_ALPHA_MASK;
            model->mPolygonAttributes |= POLYGON_ATTR_ALPHA_MASK;
        }
    }
}

void DrawItemPoolWithCallback(ItemPool *pool, void *callbackArg, void (*drawCallback)(void *, void *, void *)) {
    s32 takenCount;
    s32 objectIndex;
    ItemObject *object;

    takenCount = pool->mTakenCount;
    for (objectIndex = 0; objectIndex < takenCount; objectIndex++) {
        object = pool->mObjects[objectIndex];
        if ((object->mFlags & ITEM_OBJECT_FLAG_OUT_OF_VIEW) != 0) {
            continue;
        }
        if ((object->mFlags & ITEM_OBJECT_FLAG_IN_USE) != 0) {
            SendLight01Color(object->mKartLightColor);
        } else {
            SendLight01Color(&object->mColorBlend.mColor);
        }
        drawCallback(object, callbackArg, gItemModels[pool->mKind]);
    }
}

void DrawItemObjectModel(ItemObject *object, NsbmdModel *model, Vec3 *viewAxis) {
    s16 alpha;
    void *matrix;

    if ((alpha = object->mAlpha) != 0x1f) {
        model->mPolygonAttributes &= ~POLYGON_ATTR_ALPHA_MASK;
        model->mPolygonAttributes |= (u16) alpha << POLYGON_ATTR_ALPHA_SHIFT;
    }
    QueueNsbmdModelMaterial(model);
    if (object->mNormal.y < 0xfae || (object->mFlags & ITEM_OBJECT_FLAG_KEEP_NORMAL) != 0) {
        object->mTransformMtx.mRows[2] = *viewAxis;
        Vec3CrossUnrounded(&object->mNormal, &object->mTransformMtx.mRows[2], &object->mTransformMtx.mRows[0]);
        if ((s64) object->mTransformMtx.mRows[0].x * object->mTransformMtx.mRows[0].x +
                (s64) object->mTransformMtx.mRows[0].y * object->mTransformMtx.mRows[0].y +
                (s64) object->mTransformMtx.mRows[0].z * object->mTransformMtx.mRows[0].z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&object->mTransformMtx.mRows[0], &object->mTransformMtx.mRows[0]);
        }
        Vec3CrossUnrounded(&object->mTransformMtx.mRows[2], &object->mTransformMtx.mRows[0],
                           &object->mTransformMtx.mRows[1]);
        {
            Vec3 *position;

            position = object->mPosPointer;
            object->mTransformMtx.mRows[3].x = position->x >> 4;
            object->mTransformMtx.mRows[3].y = position->y >> 4;
            object->mTransformMtx.mRows[3].z = position->z >> 4;
        }
        matrix = &object->mTransformMtx.mRows[0];
    } else {
        matrix = SetViewAxis2MatrixPos(object->mPosPointer);
    }
    DrawNsbmdModelWithMatrixAndMaxAlpha(model, matrix, &object->mScale, 0, 0x1f);
    if ((alpha = object->mAlpha) != 0x1f) {
        model->mPolygonAttributes &= ~POLYGON_ATTR_ALPHA_MASK;
        model->mPolygonAttributes |= POLYGON_ATTR_ALPHA_MASK;
    }
}
