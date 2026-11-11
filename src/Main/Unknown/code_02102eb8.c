#include "Main/Unknown/code_02102eb8.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020f81c0.h"

#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f8000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02073eb8.h"
#include "03/code_021b7000.h"
#include "03/unk_021d8000.h"
#include "Main/Unknown/code_02133000.h"
#include "03/code_021b7bb4.h"
#include "Main/Unknown/code_02077bc0.h"

void ResetItemGesso(ItemGesso *gesso) {
    s32 quadIndex;

    gesso->mKart = NULL;
    for (quadIndex = 0; quadIndex < 8; quadIndex++) {
        gesso->mOrthoQuadCounts[quadIndex] = 0;
    }
    gesso->mStepIndex = -1;
    gesso->mItemObject.mAlpha = 0x1f;
    gesso->mShear = 0;
    gesso->mEnded = FALSE;
}

BOOL SetupNextItemGessoStep(ItemGesso *gesso) {
    ItemGessoStep *step;
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
    gesso->mUnk_170 = step->mDampFrameCount;
    stepIndex = gesso->mStepIndex;
    if (stepIndex != 0xc && stepIndex != 0xd) {
        if (gesso->mTargetVelocityY > 0) {
            gesso->mTargetScaleX = 0xe66;
            gesso->mTargetScaleY = 0x1266;
            gesso->mUnk_184.z = 0x4cd;
        } else if (stepIndex == 4) {
            gesso->mTargetScaleX = 0x1000;
            gesso->mTargetScaleY = 0x1000;
            gesso->mUnk_184.z = 0x1000;
        } else {
            gesso->mTargetScaleX = 0x1333;
            gesso->mTargetScaleY = 0xc29;
            gesso->mUnk_184.z = 0x28f;
        }
    } else if (stepIndex == 0xc) {
        gesso->mTargetScaleX = 0x199a;
        gesso->mTargetScaleY = 0x119a;
        gesso->mUnk_184.z = 0x800;
    } else {
        gesso->mTargetScaleX = 0x800;
        gesso->mTargetScaleY = 0x800;
        gesso->mUnk_184.z = 0x99a;
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
        kartIndex = (u16) (gesso->mItemObject.mOwnerKartIndexAndFlags & ~0xff00);
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
        if (gesso->mItemObject.mFlags & 0x10000000) {
            SetupNextItemGessoStep(gesso);
            gesso->mStepTimer = gesso->mStepTimer - 1;
        }
    } else {
        SetupNextItemGessoStep(gesso);
    }
    gesso->mVelocityX = gesso->mTargetVelocityX;
    gesso->mVelocityY = gesso->mTargetVelocityY;
    gesso->mScaleX = gesso->mTargetScaleX;
    gesso->mUnk_184.x = gesso->mTargetScaleY;
    if ((gesso->mItemObject.mOwnerKartIndexAndFlags & 0x8000) == 0) {
        kartIndex = (u16) (gesso->mItemObject.mOwnerKartIndexAndFlags & ~0xff00);
    } else {
        kartIndex = 8;
    }
    gesso->mVisible = entryIndex == (u16) kartIndex;
    FreeItemObjectCollisionSlot(&gesso->mItemObject);
    return (u32) InitCourseColorBlend(&gesso->mItemObject.mColorBlend, 1);
}
