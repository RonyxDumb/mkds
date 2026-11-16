#include "Main/Unknown/code_02102eb8.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020f81c0.h"

#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f8000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Item/ItemGesso.h"
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

void itgsso_21031AC(ItemGesso *gesso) {
    s32 i;

    gesso->mKart = NULL;
    for (i = 0; i < 8; i++) {
        gesso->mOrthoQuadCounts[i] = 0;
    }
    gesso->mStepIndex = -1;
    gesso->field0.mAlpha = 0x1f;
    gesso->field19C = 0;
    gesso->field160 = FALSE;
}

BOOL itgsso_210300C(ItemGesso *gesso) {
    ItemGessoStep *step;
    s32 stepIndex;
    BOOL f;

    gesso->mStepIndex = gesso->mStepIndex + 1;
    if (gesso->mStepIndex >= 0x11) {
        goto done;
    }
    step = &gItemGessoSteps[gesso->mStepIndex];
    gesso->mTargetVelocityX = step->mTargetVelocityX;
    gesso->mTargetVelocityY = step->mTargetVelocityY;
    gesso->mApproachRate = step->mApproachRate;
    gesso->mDamping = step->mDamping;
    gesso->mStepTimer = step->field8;
    gesso->field170 = step->fieldA;
    stepIndex = gesso->mStepIndex;
    if (stepIndex != 0xc && stepIndex != 0xd) {
        if (gesso->mTargetVelocityY > 0) {
            gesso->field174 = 0xe66;
            gesso->field178 = 0x1266;
            gesso->field184.z = 0x4cd;
        } else if (stepIndex == 4) {
            gesso->field174 = 0x1000;
            gesso->field178 = 0x1000;
            gesso->field184.z = 0x1000;
        } else {
            gesso->field174 = 0x1333;
            gesso->field178 = 0xc29;
            gesso->field184.z = 0x28f;
        }
    } else if (stepIndex == 0xc) {
        gesso->field174 = 0x199a;
        gesso->field178 = 0x119a;
        gesso->field184.z = 0x800;
    } else {
        gesso->field174 = 0x800;
        gesso->field178 = 0x800;
        gesso->field184.z = 0x99a;
    }
    stepIndex = gesso->mStepIndex;
    f = TRUE;
    if (stepIndex != 2 && stepIndex != 0x10) {
        f = FALSE;
    }
    gesso->field194 = f;
    if (step->mTargetVelocityY > 0 && gesso->mStepIndex != 0 && gesso->mStepIndex != 0xe && gesso->mVisible != FALSE) {
        sub_20F8E3C((u32) gesso->mKart, 0xf1);
    }
    return FALSE;
done:
    return TRUE;
}

u32 itgsso_2102EB8(ItemGesso *gesso, s32 fromData) {
    Camera *camera;
    s32 entryIndex;
    s32 kartIndex;

    entryIndex = gRaceMultiConfig->mEntryIndex;
    camera = cam_getPlayerCamera();
    sub_20F82A4(0);
    if (entryIndex < 0) {
        kartIndex = (u16) (gesso->field0.field78 & ~0xff00);
    } else {
        kartIndex = entryIndex;
    }
    gesso->mKart = driver_getById(kartIndex);
    gesso->field0.mPos = gesso->mKart->mDrawMatrixPos;
    VEC_MultAdd(0x5800, &camera->mUp, &gesso->field0.mPos, &gesso->field0.mPos);
    VEC_MultAdd(rstat_getUncontrollable() != 0 ? 0x5800 : 0xa800, &camera->mForward, &gesso->field0.mPos,
                &gesso->field0.mPos);
    VEC_Subtract(&gesso->field0.mPos, &camera->mPos, &gesso->mViewOffset);
    MTX_MultVec33(&gesso->mViewOffset, &camera->mViewMatrix.field0[0].x, &gesso->mViewOffset);
    if (fromData != 0) {
        if (gesso->field0.mFlags & 0x10000000) {
            itgsso_210300C(gesso);
            gesso->mStepTimer = gesso->mStepTimer - 1;
        }
    } else {
        itgsso_210300C(gesso);
    }
    gesso->mVelocityX = gesso->mTargetVelocityX;
    gesso->mVelocityY = gesso->mTargetVelocityY;
    gesso->field180 = gesso->field174;
    gesso->field184.x = gesso->field178;
    if ((gesso->field0.field78 & 0x8000) == 0) {
        kartIndex = (u16) (gesso->field0.field78 & ~0xff00);
    } else {
        kartIndex = 8;
    }
    gesso->mVisible = entryIndex == (u16) kartIndex;
    FreeItemObjectCollisionSlot((s32) gesso);
    return (u32) light_init(&gesso->field0.mColorBlend, 1);
}
