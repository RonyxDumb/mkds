#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020fe4b4.h"

#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02102000.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02102eb8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02077bc0.h"

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
            if (kartAtIndex->mUnk_7c & 0x402020) {
                continue;
            }
            if (kartAtIndex->mUnk_4c & 0x10000840) {
                continue;
            }
            if (kartAtIndex->mUnk_48 & 0x10000) {
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
        if ((kart->mUnk_7c & 0x402020) || (kart->mUnk_4c & 0x10000840) || (kart->mUnk_48 & 0x10000)) {
            gesso->mStepIndex = 0xd;
            SetupNextItemGessoStep(gesso);
            if (gesso->mVisible != FALSE) {
                StartEntryKartSound(kart, 0xf3);
            }
        }
    }
    if (kart->mUnk_4c & KART_4C_RESPAWN_DROP) {
        gesso->mEnded = TRUE;
        gesso->mVisible = FALSE;
    }
    value = gesso->mVelocityX;
    if (gesso->mItemObject.mAlpha < 0x1f && gesso->mFadesOut == 0 && gesso->mVisible != FALSE) {
        gesso->mItemObject.mAlpha = gesso->mItemObject.mAlpha + 7;
        if (gesso->mItemObject.mAlpha > 0x1f) {
            gesso->mItemObject.mAlpha = 0x1f;
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
            gesso->mItemObject.mAlpha = gesso->mItemObject.mAlpha - gesso->mUnk_170;
            if (gesso->mItemObject.mAlpha >= 1) {
                gesso->mStepTimer = 0;
            } else {
                gesso->mStepTimer = -1 - gesso->mUnk_170;
                gesso->mVisible = FALSE;
                gesso->mItemObject.mAlpha = 1;
            }
        }
        if (gesso->mStepTimer < -gesso->mUnk_170) {
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
    factor = gesso->mUnk_184.z;
    deltaX = gesso->mTargetScaleX - gesso->mScaleX;
    deltaY = gesso->mTargetScaleY - gesso->mUnk_184.x;
    gesso->mScaleX += MUL_FIXED12_NO_ROUND(factor, deltaX);
    gesso->mUnk_184.x += MUL_FIXED12_NO_ROUND(factor, deltaY);
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

void DrawItemGesso(ItemGesso *gesso, s32 unusedArg2, NsbmdModel *model) {
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
    scale.y = MUL_FIXED12_NO_ROUND(gesso->mUnk_184.x, gesso->mItemObject.mScale.y);
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
    if (gesso->mItemObject.mAlpha == 0x1f) {
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
    ItemGessoStep *step;

    gItemGessoFrameCount = 0xf;
    for (stepIndex = 0, step = gItemGessoSteps; stepIndex < 0x11; stepIndex++) {
        gItemGessoFrameCount += step->mApproachFrameCount + step->mDampFrameCount;
        step++;
    }
}
#pragma thumb off

void CreateItemTeresaFrameScaleTable(void) {
    s32 frameIndex;

    gItemTeresaFrameScales = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x52);
    for (frameIndex = 0; frameIndex <= 0x28; frameIndex++) {
        gItemTeresaFrameScales[frameIndex] = ((0x28 - frameIndex) << 12) / (0x29 - frameIndex);
    }
    for (frameIndex -= 5; frameIndex <= 0x28; frameIndex++) {
        gItemTeresaFrameScales[frameIndex] =
            (gItemTeresaFrameScales[frameIndex] + gItemTeresaFrameScales[frameIndex - 1]) >> 1;
    }
}
