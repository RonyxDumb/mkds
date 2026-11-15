#include "Main/Item/item_gesso.h"
#include "Main/Item/item_in_use.h"
#include "Main/Course/course_color_blend.h"
#include "Main/Item/item_slot_tables.h"
#include "fx_mtx33.h"
#include "code_02147cd8.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Item/item_object.h"
#include "Main/Item/entry_kart_sound.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Race/entry_race_ended.h"
#include "Main/Kart/camera.h"
#include "03/code_021b7000.h"
#include "03/unk_021d8000.h"
#include "03/code_021b7bb4.h"
#include "Main/Kart/karts.h"
#include "Main/System/heap.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/Item/item_f_box.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_link_following.h"
#include "Main/Item/bouncing_item_box.h"
#include "Main/System/heap_call.h"
#include "ITCM/collision_slots.h"

const ItemInfo gItemInfoGesso = {
    1, 1, 0xa, 1, 0, 1, (void (*)(ItemInUse *, HeldItem *)) GessoMarkItemInUseAsActiveItem};
const ItemKind gItemKindGesso = {0x1b4,
                                 1,
                                 1,
                                 -1,
                                 -1,
                                 ComputeItemGessoFrameCount,
                                 (void (*)(void *)) ResetItemGesso,
                                 NULL,
                                 NULL,
                                 (s32(*)(void *, void *)) InitItemGesso,
                                 (void (*)(ItemObject *)) AdvanceItemGesso,
                                 (void (*)(void *, void *, void *)) DrawItemGesso,
                                 ComputeViewTest,
                                 NULL,
                                 NULL,
                                 NULL,
                                 0,
                                 0,
                                 (void *(*) (void *, void *, s32)) CopyItemGessoData,
                                 0,
                                 (void (*)(void *)) InitItemGessoFromData,
                                 1,
                                 NULL,
                                 0x4b0000,
                                 2,
                                 0x319a,
                                 0,
                                 0,
                                 0x1000,
                                 0x2000,
                                 0x666,
                                 0x11f,
                                 0,
                                 0,
                                 0,
                                 {0},
                                 3,
                                 1,
                                 1,
                                 1,
                                 1,
                                 0};
const ItemGessoStep gItemGessoSteps[17] = {
    {0, 0x3800, 0xccd, 0xeb8, 2, 0x10}, {0, -8192, 0x19a, 0xf85, 8, 0xa},    {0, 0x3800, 0x800, 0x1000, 0xa, 6},
    {0, 0, 0x1000, 0, 0, 0xa},          {0, -20480, 0x1000, 0x1000, 3, 0},   {0, -20480, 0x1000, 0xee1, 0, 0xa},
    {-6963, 0x19a, 0xe66, 0xe66, 2, 7}, {0x333, -9011, 0x2e1, 0xf33, 4, 5},  {0x3000, 0x1800, 0xccd, 0xe66, 3, 8},
    {-819, -9421, 0x2e1, 0xf85, 4, 6},  {-6144, 0x1000, 0xccd, 0xdec, 3, 3}, {0, -8192, 0x148, 0xf33, 4, 5},
    {0, -5734, 0, 0xe66, 2, 2},         {0, -5734, 0, 0xe66, 2, 2},          {0, 0x2666, 0x666, 0xe66, 3, 0xa},
    {0, -410, 0x666, 0x99a, 6, 0xa},    {0, 0x3000, 0x800, 0x1000, 6, 6}};
s32 gItemGessoFrameCount;
u16 *gItemTeresaFrameScales;

void GessoMarkItemInUseAsActiveItem(ItemInUse *itemInUse) {
    itemInUse->mIsActiveItem = TRUE;
}

void ResetItemGesso(ItemGesso *gesso) {
    s32 quadIndex;

    gesso->mKart = NULL;
    for (quadIndex = 0; quadIndex < 8; quadIndex++) {
        gesso->mOrthoQuadCounts[quadIndex] = 0;
    }
    gesso->mStepIndex = -1;
    gesso->mItemObject.mAlpha = ITEM_OBJECT_ALPHA_OPAQUE;
    gesso->mShear = 0;
    gesso->mEnded = FALSE;
}

BOOL SetupNextItemGessoStep(ItemGesso *gesso) {
    const ItemGessoStep *step;
    s32 stepIndex;
    BOOL fadesOut;

    gesso->mStepIndex = gesso->mStepIndex + 1;
    if (gesso->mStepIndex >= 0x11) {
        goto done;
    }
    step = &gItemGessoSteps[gesso->mStepIndex];
    gesso->mTargetVelocityX = step->mTargetVelocityX;
    gesso->mTargetVelocityY = step->mTargetVelocityY;
    gesso->mApproachRate = step->mApproachRate;
    gesso->mDamping = step->mDamping;
    gesso->mStepTimer = step->mApproachFrameCount;
    gesso->mDampFrameCount = step->mDampFrameCount;
    stepIndex = gesso->mStepIndex;
    if (stepIndex != 0xc && stepIndex != 0xd) {
        if (gesso->mTargetVelocityY > 0) {
            gesso->mTargetScaleX = ITEM_GESSO_TALL_SCALE_X;
            gesso->mTargetScaleY = ITEM_GESSO_TALL_SCALE_Y;
            gesso->mScaleYAndApproachRate.z = 0x4cd;
        } else if (stepIndex == 4) {
            gesso->mTargetScaleX = TO_FIXED12(1);
            gesso->mTargetScaleY = TO_FIXED12(1);
            gesso->mScaleYAndApproachRate.z = 0x1000;
        } else {
            gesso->mTargetScaleX = ITEM_GESSO_SQUAT_SCALE_X;
            gesso->mTargetScaleY = ITEM_GESSO_SQUAT_SCALE_Y;
            gesso->mScaleYAndApproachRate.z = 0x28f;
        }
    } else if (stepIndex == 0xc) {
        gesso->mTargetScaleX = ITEM_GESSO_SPREAD_SCALE_X;
        gesso->mTargetScaleY = ITEM_GESSO_SPREAD_SCALE_Y;
        gesso->mScaleYAndApproachRate.z = 0x800;
    } else {
        gesso->mTargetScaleX = ITEM_GESSO_HALF_SCALE;
        gesso->mTargetScaleY = ITEM_GESSO_HALF_SCALE;
        gesso->mScaleYAndApproachRate.z = 0x99a;
    }
    stepIndex = gesso->mStepIndex;
    fadesOut = TRUE;
    if (stepIndex != 2 && stepIndex != 0x10) {
        fadesOut = FALSE;
    }
    gesso->mFadesOut = fadesOut;
    if (step->mTargetVelocityY > 0 && gesso->mStepIndex != 0 && gesso->mStepIndex != 0xe && gesso->mVisible != FALSE) {
        StartEntryKartSound(gesso->mKart, 0xf1);
    }
    return FALSE;
done:
    return TRUE;
}

u32 SetupItemGesso(ItemGesso *gesso, s32 fromData) {
    Camera *camera;
    s32 entryIndex;
    s32 kartIndex;

    entryIndex = gRaceSetup->mEntryIndex;
    camera = GetChaseCamera();
    StartGessoBlockTimer(0);
    if (entryIndex < 0) {
        kartIndex = (u16) (gesso->mItemObject.mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK);
    } else {
        kartIndex = entryIndex;
    }
    gesso->mKart = GetKart(kartIndex);
    gesso->mItemObject.mPos = gesso->mKart->mDrawMatrixPos;
    VEC_MultAdd(0x5800, &camera->mUp, &gesso->mItemObject.mPos, &gesso->mItemObject.mPos);
    VEC_MultAdd(GetEntryRaceEnded() != 0 ? 0x5800 : 0xa800, &camera->mForward, &gesso->mItemObject.mPos,
                &gesso->mItemObject.mPos);
    VEC_Subtract(&gesso->mItemObject.mPos, &camera->mPos, &gesso->mViewOffset);
    MTX_MultVec33(&gesso->mViewOffset, &camera->mViewMatrix.mAxes, &gesso->mViewOffset);
    if (fromData != 0) {
        if (gesso->mItemObject.mFlags & ITEM_OBJECT_FLAG_FROM_DATA) {
            SetupNextItemGessoStep(gesso);
            gesso->mStepTimer = gesso->mStepTimer - 1;
        }
    } else {
        SetupNextItemGessoStep(gesso);
    }
    gesso->mVelocityX = gesso->mTargetVelocityX;
    gesso->mVelocityY = gesso->mTargetVelocityY;
    gesso->mScaleX = gesso->mTargetScaleX;
    gesso->mScaleYAndApproachRate.x = gesso->mTargetScaleY;
    if ((gesso->mItemObject.mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER) == 0) {
        kartIndex = (u16) (gesso->mItemObject.mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK);
    } else {
        kartIndex = 8;
    }
    gesso->mVisible = entryIndex == (u16) kartIndex;
    FreeItemObjectCollisionSlot(&gesso->mItemObject);
    return (u32) InitCourseColorBlend(&gesso->mItemObject.mColorBlend, 1);
}

u32 InitItemGesso(ItemInUse *itemInUse, ItemGesso *gesso) {
    Kart *kart = itemInUse->mKart;
    u32 setupResult = SetupItemGesso(gesso, 0x0u);
    StartEntryKartSound(kart, 0xf2u);
    return 0x1u;
}

void AdvanceItemGesso(ItemGesso *gesso) {
    Kart *kart;
    Camera *camera;
    s32 ageFrames;
    s32 kartIndex;
    s32 kartCount;
    Kart *kartAtIndex;
    s32 value;
    Vec3 viewOffset;
    s32 deltaX;
    s32 deltaY;
    s32 factor;

    kart = gesso->mKart;
    camera = GetChaseCamera();
    ageFrames = gesso->mItemObject.mAgeFrames;
    if (ageFrames == 0x3f) {
        SetupItemGessoKarts(gesso);
    }
    if (ageFrames == 0x8f) {
        kartCount = gRaceSetup->mKartCount;
        for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
            if (gesso->mOrthoQuadCounts[kartIndex] == 0) {
                continue;
            }
            kartAtIndex = GetKart(kartIndex);
            if (kartAtIndex->mEntryFlags & KART_ENTRY_REMOVED_PARKED_OR_TERESA) {
                continue;
            }
            if (kartAtIndex->mEffectFlags & (KART_EFFECT_STAR | KART_EFFECT_RESPAWN_DROP | KART_EFFECT_KILLER)) {
                continue;
            }
            if (kartAtIndex->mDriveFlags & KART_DRIVE_KEYED_PLACEMENT) {
                continue;
            }
            StartKartGesso(kartAtIndex, gesso->mOrthoQuadCounts[kartIndex]);
            StartEntryKartSound(kartAtIndex, 0xf0);
        }
    }
    if (gesso->mEnded != FALSE) {
        if (ageFrames <= gItemGessoFrameCount) {
            return;
        }
        ReleaseItemPoolObject(gItemPools + gesso->mItemObject.mKind, &gesso->mItemObject);
        return;
    }
    if (gesso->mStepIndex >= 4 && gesso->mStepIndex < 0xd) {
        if ((kart->mEntryFlags & KART_ENTRY_REMOVED_PARKED_OR_TERESA) ||
            (kart->mEffectFlags & (KART_EFFECT_STAR | KART_EFFECT_RESPAWN_DROP | KART_EFFECT_KILLER)) ||
            (kart->mDriveFlags & KART_DRIVE_KEYED_PLACEMENT)) {
            gesso->mStepIndex = 0xd;
            SetupNextItemGessoStep(gesso);
            if (gesso->mVisible != FALSE) {
                StartEntryKartSound(kart, 0xf3);
            }
        }
    }
    if (kart->mEffectFlags & KART_EFFECT_RESPAWN_DROP) {
        gesso->mEnded = TRUE;
        gesso->mVisible = FALSE;
    }
    value = gesso->mVelocityX;
    if (gesso->mItemObject.mAlpha < ITEM_OBJECT_ALPHA_OPAQUE && gesso->mFadesOut == 0 && gesso->mVisible != FALSE) {
        gesso->mItemObject.mAlpha = gesso->mItemObject.mAlpha + 7;
        if (gesso->mItemObject.mAlpha > ITEM_OBJECT_ALPHA_OPAQUE) {
            gesso->mItemObject.mAlpha = ITEM_OBJECT_ALPHA_OPAQUE;
        }
    }
    gesso->mStepTimer = gesso->mStepTimer - 1;
    if (gesso->mStepTimer > 0) {
        factor = gesso->mApproachRate;
        deltaX = gesso->mTargetVelocityX - gesso->mVelocityX;
        deltaY = gesso->mTargetVelocityY - gesso->mVelocityY;
        gesso->mVelocityX += MUL_FIXED12_NO_ROUND(factor, deltaX);
        gesso->mVelocityY += MUL_FIXED12_NO_ROUND(factor, deltaY);
    } else {
        factor = gesso->mDamping;
        gesso->mVelocityX = MUL_FIXED12_NO_ROUND(gesso->mVelocityX, factor);
        gesso->mVelocityY = MUL_FIXED12_NO_ROUND(gesso->mVelocityY, factor);
        if (gesso->mFadesOut != 0) {
            gesso->mItemObject.mAlpha = gesso->mItemObject.mAlpha - gesso->mDampFrameCount;
            if (gesso->mItemObject.mAlpha >= 1) {
                gesso->mStepTimer = 0;
            } else {
                gesso->mStepTimer = -1 - gesso->mDampFrameCount;
                gesso->mVisible = FALSE;
                gesso->mItemObject.mAlpha = 1;
            }
        }
        if (gesso->mStepTimer < -gesso->mDampFrameCount) {
            if (SetupNextItemGessoStep(gesso) != FALSE) {
                gesso->mEnded = TRUE;
                gesso->mVisible = FALSE;
                return;
            }
        }
    }
    gesso->mViewOffset.x += gesso->mVelocityX;
    gesso->mViewOffset.y += gesso->mVelocityY;
    value = MUL_FIXED12_NO_ROUND(gesso->mVelocityX - MUL_FIXED12_NO_ROUND(value, 0xccd), 0x19a);
    if (value > 0x19a) {
        value = 0x19a;
    } else if (value < -0x19a) {
        value = -0x19a;
    }
    gesso->mShear += value;
    gesso->mShear = MUL_FIXED12_NO_ROUND(gesso->mShear, 0xeb8);
    if (gesso->mShear > 0x266) {
        gesso->mShear = 0x266;
    } else if (gesso->mShear < -0x266) {
        gesso->mShear = -0x266;
    }
    factor = gesso->mScaleYAndApproachRate.z;
    deltaX = gesso->mTargetScaleX - gesso->mScaleX;
    deltaY = gesso->mTargetScaleY - gesso->mScaleYAndApproachRate.x;
    gesso->mScaleX += MUL_FIXED12_NO_ROUND(factor, deltaX);
    gesso->mScaleYAndApproachRate.x += MUL_FIXED12_NO_ROUND(factor, deltaY);
    viewOffset = gesso->mViewOffset;
    value = MUL_FIXED12_NO_ROUND(gesso->mShear, 0x800);
    viewOffset.x -= MUL_FIXED12_NO_ROUND(value, viewOffset.x);
    gesso->mItemObject.mPos.x = MUL_FIXED12_NO_ROUND(camera->mSide.x, -viewOffset.x);
    gesso->mItemObject.mPos.y = MUL_FIXED12_NO_ROUND(camera->mSide.y, -viewOffset.x);
    gesso->mItemObject.mPos.z = MUL_FIXED12_NO_ROUND(camera->mSide.z, -viewOffset.x);
    VEC_MultAdd(viewOffset.y, &camera->mUp, &gesso->mItemObject.mPos, &gesso->mItemObject.mPos);
    VEC_MultAdd(-viewOffset.z, &camera->mForward, &gesso->mItemObject.mPos, &gesso->mItemObject.mPos);
    VEC_Add(&camera->mPos, &gesso->mItemObject.mPos, &gesso->mItemObject.mPos);
}

void DrawItemGesso(ItemGesso *gesso, s32 unusedSecond, NsbmdModel *model) {
    Vec3 scale;
    MtxFx43 matrix;
    s32 scaleFactor;
    s32 value;

    if (gesso->mKart == NULL) {
        return;
    }
    if (gesso->mVisible == FALSE) {
        return;
    }
    matrix = *SetViewTransposeMatrixPos(&gesso->mItemObject.mPos);
    value = gesso->mShear;
    if (value <= 0) {
        value = -value;
    }
    value = 0x1000 - MUL_FIXED12_NO_ROUND(value, 0xa4);
    matrix.mRows[1].x = MUL_FIXED12_NO_ROUND(matrix.mRows[1].x, value);
    matrix.mRows[1].y = MUL_FIXED12_NO_ROUND(matrix.mRows[1].y, value);
    matrix.mRows[1].z = MUL_FIXED12_NO_ROUND(matrix.mRows[1].z, value);
    VEC_MultAdd(gesso->mShear, &matrix.mRows[0], &matrix.mRows[1], &matrix.mRows[1]);
    scale.x = MUL_FIXED12_NO_ROUND(gesso->mScaleX, gesso->mItemObject.mScale.x);
    scale.y = MUL_FIXED12_NO_ROUND(gesso->mScaleYAndApproachRate.x, gesso->mItemObject.mScale.y);
    scale.z = gesso->mItemObject.mScale.z;
    scaleFactor = GetEntryRaceEnded() != 0 ? 0xccd : 0x119a;
    scale.x = MUL_FIXED12_NO_ROUND(scale.x, scaleFactor);
    scale.y = MUL_FIXED12_NO_ROUND(scale.y, scaleFactor);
    value = gesso->mItemObject.mAlpha;
    if (value != 0x1f) {
        model->mPolygonAttributes = model->mPolygonAttributes & ~0x1f0000;
        model->mPolygonAttributes = model->mPolygonAttributes | ((u16) value << 16);
    }
    QueueNsbmdModelMaterial(model);
    DrawNsbmdModelWithMatrixAndMaxAlpha(model, &matrix, &scale, 0, 0x1f);
    if (gesso->mItemObject.mAlpha == ITEM_OBJECT_ALPHA_OPAQUE) {
        return;
    }
    model->mPolygonAttributes = model->mPolygonAttributes & ~0x1f0000;
    model->mPolygonAttributes = model->mPolygonAttributes | 0x1f0000;
}

void CopyItemGessoData(void *data, ItemGesso *gesso, void *toData) {
    CopyItemObjectData(data, gesso, toData);
    if (gesso == NULL) {
        return;
    }
    if (toData == NULL) {
        return;
    }
    AddItemDataSizedByKind(gesso->mItemObject.mKind);
}

void InitItemGessoFromData(ItemGesso *gesso) {
    SetupItemObjectFromData(&gesso->mItemObject);
    SetupItemGesso(gesso, 1);
}

#pragma thumb on
void ComputeItemGessoFrameCount(void) {
    s32 stepIndex;
    const ItemGessoStep *step;

    gItemGessoFrameCount = 0xf;
    for (stepIndex = 0, step = gItemGessoSteps; stepIndex < 0x11; stepIndex++) {
        gItemGessoFrameCount += step->mApproachFrameCount + step->mDampFrameCount;
        step++;
    }
}
#pragma thumb off

void CreateItemTeresaFrameScaleTable(void) {
    s32 frameIndex;

    gItemTeresaFrameScales = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x29 * sizeof(*gItemTeresaFrameScales));
    for (frameIndex = 0; frameIndex <= 0x28; frameIndex++) {
        gItemTeresaFrameScales[frameIndex] = TO_FIXED12(0x28 - frameIndex) / (0x29 - frameIndex);
    }
    for (frameIndex -= 5; frameIndex <= 0x28; frameIndex++) {
        gItemTeresaFrameScales[frameIndex] =
            (gItemTeresaFrameScales[frameIndex] + gItemTeresaFrameScales[frameIndex - 1]) >> 1;
    }
}
