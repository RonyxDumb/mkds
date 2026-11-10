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
    s32 i;
    s32 kartCount;
    Kart *kartAtIndex;
    s32 v;
    Vec3 viewOffset;
    s32 m;
    s32 n;
    s32 factor;

    kart = gesso->mKart;
    camera = GetChaseCamera();
    ageFrames = gesso->mItemObject.mAgeFrames;
    if (ageFrames == 0x3f) {
        SetupItemGessoKarts(gesso);
    }
    if (ageFrames == 0x8f) {
        kartCount = gRaceSetup->mKartCount;
        for (i = 0; i < kartCount; i++) {
            if (gesso->mOrthoQuadCounts[i] == 0) {
                continue;
            }
            kartAtIndex = GetKart(i);
            if (kartAtIndex->mUnk_7c & 0x402020) {
                continue;
            }
            if (kartAtIndex->mUnk_4c & 0x10000840) {
                continue;
            }
            if (kartAtIndex->mUnk_48 & 0x10000) {
                continue;
            }
            StartKartGesso(kartAtIndex, gesso->mOrthoQuadCounts[i]);
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
    v = gesso->mVelocityX;
    if (gesso->mItemObject.mAlpha < 0x1f && gesso->mFadesOut == 0 && gesso->mVisible != FALSE) {
        gesso->mItemObject.mAlpha = gesso->mItemObject.mAlpha + 7;
        if (gesso->mItemObject.mAlpha > 0x1f) {
            gesso->mItemObject.mAlpha = 0x1f;
        }
    }
    gesso->mStepTimer = gesso->mStepTimer - 1;
    if (gesso->mStepTimer > 0) {
        factor = gesso->mApproachRate;
        m = gesso->mTargetVelocityX - gesso->mVelocityX;
        n = gesso->mTargetVelocityY - gesso->mVelocityY;
        gesso->mVelocityX += MUL_FIXED12_NO_ROUND(factor, m);
        gesso->mVelocityY += MUL_FIXED12_NO_ROUND(factor, n);
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
    v = MUL_FIXED12_NO_ROUND(gesso->mVelocityX - MUL_FIXED12_NO_ROUND(v, 0xccd), 0x19a);
    if (v > 0x19a) {
        v = 0x19a;
    } else if (v < -0x19a) {
        v = -0x19a;
    }
    gesso->mShear += v;
    gesso->mShear = MUL_FIXED12_NO_ROUND(gesso->mShear, 0xeb8);
    if (gesso->mShear > 0x266) {
        gesso->mShear = 0x266;
    } else if (gesso->mShear < -0x266) {
        gesso->mShear = -0x266;
    }
    factor = gesso->mUnk_184.z;
    m = gesso->mTargetScaleX - gesso->mScaleX;
    n = gesso->mTargetScaleY - gesso->mUnk_184.x;
    gesso->mScaleX += MUL_FIXED12_NO_ROUND(factor, m);
    gesso->mUnk_184.x += MUL_FIXED12_NO_ROUND(factor, n);
    viewOffset = gesso->mViewOffset;
    v = MUL_FIXED12_NO_ROUND(gesso->mShear, 0x800);
    viewOffset.x -= MUL_FIXED12_NO_ROUND(v, viewOffset.x);
    gesso->mItemObject.mPos.x = MUL_FIXED12_NO_ROUND(camera->mSide.x, -viewOffset.x);
    gesso->mItemObject.mPos.y = MUL_FIXED12_NO_ROUND(camera->mSide.y, -viewOffset.x);
    gesso->mItemObject.mPos.z = MUL_FIXED12_NO_ROUND(camera->mSide.z, -viewOffset.x);
    VEC_MultAdd(viewOffset.y, &camera->mUp, &gesso->mItemObject.mPos, &gesso->mItemObject.mPos);
    VEC_MultAdd(-viewOffset.z, &camera->mForward, &gesso->mItemObject.mPos, &gesso->mItemObject.mPos);
    VEC_Add(&camera->mPos, &gesso->mItemObject.mPos, &gesso->mItemObject.mPos);
}

void DrawItemGesso(ItemGesso *gesso, s32 param_2, NsbmdModel *model) {
    Vec3 scale;
    MtxFx43 matrix;
    s32 scaleFactor;
    s32 d;

    if (gesso->mKart == NULL) {
        return;
    }
    if (gesso->mVisible == FALSE) {
        return;
    }
    matrix = *SetViewTransposeMatrixPos(&gesso->mItemObject.mPos);
    d = gesso->mShear;
    if (d <= 0) {
        d = -d;
    }
    d = 0x1000 - MUL_FIXED12_NO_ROUND(d, 0xa4);
    matrix.mUnk_00[1].x = MUL_FIXED12_NO_ROUND(matrix.mUnk_00[1].x, d);
    matrix.mUnk_00[1].y = MUL_FIXED12_NO_ROUND(matrix.mUnk_00[1].y, d);
    matrix.mUnk_00[1].z = MUL_FIXED12_NO_ROUND(matrix.mUnk_00[1].z, d);
    VEC_MultAdd(gesso->mShear, &matrix.mUnk_00[0], &matrix.mUnk_00[1], &matrix.mUnk_00[1]);
    scale.x = MUL_FIXED12_NO_ROUND(gesso->mScaleX, gesso->mItemObject.mScale.x);
    scale.y = MUL_FIXED12_NO_ROUND(gesso->mUnk_184.x, gesso->mItemObject.mScale.y);
    scale.z = gesso->mItemObject.mScale.z;
    scaleFactor = func_0203c5e4() != 0 ? 0xccd : 0x119a;
    scale.x = MUL_FIXED12_NO_ROUND(scale.x, scaleFactor);
    scale.y = MUL_FIXED12_NO_ROUND(scale.y, scaleFactor);
    d = gesso->mItemObject.mAlpha;
    if (d != 0x1f) {
        model->mPolygonAttributes = model->mPolygonAttributes & ~0x1f0000;
        model->mPolygonAttributes = model->mPolygonAttributes | ((u16) d << 16);
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
    s32 i;
    ItemGessoStep *step;

    gItemGessoFrameCount = 0xf;
    for (i = 0, step = gItemGessoSteps; i < 0x11; i++) {
        gItemGessoFrameCount += step->mApproachFrameCount + step->mDampFrameCount;
        step++;
    }
}
#pragma thumb off

void CreateItemTeresaFrameScaleTable(void) {
    s32 i;

    gItemTeresaFrameScales = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x52);
    for (i = 0; i <= 0x28; i++) {
        gItemTeresaFrameScales[i] = ((0x28 - i) << 12) / (0x29 - i);
    }
    for (i -= 5; i <= 0x28; i++) {
        gItemTeresaFrameScales[i] = (gItemTeresaFrameScales[i] + gItemTeresaFrameScales[i - 1]) >> 1;
    }
}
