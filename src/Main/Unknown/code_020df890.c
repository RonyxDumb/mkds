#include "Main/Unknown/code_020df890.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d9000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02146000.h"

#pragma thumb off

void kblock_slowDownStateUpdate(Unk020e005c *koopaBlock) {
    GroupFollower *follower;
    s32 progress;
    s32 speed;
    u16 angle;
    s32 sine;

    follower = &koopaBlock->field144;
    progress = pw_getProgress(follower);
    angle = (s32) (((s64) progress * 0x40000) >> 12);
    sine = FX_SinCosTable_[(angle >> 4) * 2];
    speed = ((s64) -sine * koopaBlock->field168) >> 12;
    follower->mSpeed = speed > 0x200 ? speed : 0x200;
    if (speed <= 0x200) {
        speed = 0x200;
    }
    follower->mProgressStep =
        ((s64) speed * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
}

void kblock_renderAll(void *viewMatrix) {
    dcol_render(kblock_sRenderPart, viewMatrix, dcol_commonRender);
}

u32 kblock_isKoopaBlock(u32 kind) {
    switch (kind) {
        case 0xca:
            return 1;
        default:
            return 0;
    }
}

s32 kblock_getRouteProgress(Unk020e005c *koopaBlock) {
    s32 progress;
    GroupFollower *follower;

    follower = &koopaBlock->field144;
    progress = pw_getProgress(follower);
    if (follower->mForward == 0) {
        progress = 0x1000 - progress;
    }
    return progress;
}

#pragma thumb on
void kblock_loadModel(void) {
    void *file;

    file = mobj_getMapObjFile("koopa_block.nsbmd");
    model2_createFromNsbmd(&kblock_sModel, file, NULL);
    model_setPolyIdLightFlagsEmi(kblock_sModel, 0x3f, 2, 0x294a);
    dcol_setModel(kblock_sRenderPart, kblock_sModel);
}

void kblock_init(Unk020e005c *koopaBlock, CourseMapRow *courseRow) {
    sm_init(&koopaBlock->mStateMachine, kblock_sStates, 3, koopaBlock);
    koopaBlock->field168 = (courseRow->field28 << 12) / 100;
    pw_initFromObject(&koopaBlock->field144, courseRow, koopaBlock->field168);
    koopaBlock->field16C = 0;
    *(Unk020e43a8_28 *) &koopaBlock->fieldA0 = *(Unk020e43a8_28 *) &koopaBlock->field28;
    koopaBlock->field124.x = 0;
    koopaBlock->field124.y = 0;
    koopaBlock->field124.z = 0;
    koopaBlock->field130 = FALSE;
    koopaBlock->field100 = ((s64) koopaBlock->field1C * 0x190000) >> 12;
    koopaBlock->field104 = (s32) (((s64) koopaBlock->field20 * 0x64000) >> 12) >> 1;
    koopaBlock->field108 = ((s64) koopaBlock->field24 * 0xaf000) >> 12;
    koopaBlock->field10C = ((s64) koopaBlock->field24 * 0xaf000) >> 12;
    koopaBlock->field110 = 0;
    koopaBlock->field114.x = 1;
    koopaBlock->field114.y = 0;
    koopaBlock->field114.z = 0;
    koopaBlock->field120 = 0x800;
    pw_init(&koopaBlock->field144, 0, 1);
    pw_calcCurrentPointLinearXYZSpecial(&koopaBlock->field144, &koopaBlock->mPos, &koopaBlock->field10);
    koopaBlock->fieldE8 = koopaBlock->mPos;
    koopaBlock->field134 = 0;
    koopaBlock->field138 = 0;
    koopaBlock->mFlags |= data_0215881c;
    koopaBlock->mFlags &= ~2;
    koopaBlock->mFlags &= ~8;
    koopaBlock->mAlpha = 0x1f;
    koopaBlock->mStateMachine.mNextState = 0;
    koopaBlock->mStateMachine.mNextStateRequested = 1;
    koopaBlock->mFarDistanceSquared = gSfxParams[3].field20;
}
#pragma thumb off

MapObjectKindData *efbub_setupConfig(void) {
    MapObjectKindData *kindData;

    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = data_021587dc;
    return kindData;
}

MapObjectDrawList *efbub_setupRenderPart(void) {
    data_0217b774 = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    *data_0217b774 = data_021587b0;
    mobj_renderPartSetThisPointer(&data_0217b774);
    return data_0217b774;
}

Unk020dfc44 *efbub_setupLogicPart(void) {
    data_0217b76c = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    *data_0217b76c = data_02158784;
    mobj_logicPartSetThisPointer(&data_0217b76c);
    data_0217b76c->field28 = FX_Div(0x4000000, 0x1333);
    return data_0217b76c;
}

void efbub_render(void *a, MkdEfBubbleObject *bubble, void *c, s32 alpha) {
    s32 v;
    s32 w;
    s32 rotationMatrix[9];
    s32 n;

    if (bubble->field0.mStateMachine.mState != 0) {
        return;
    }
    w = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &w, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getBillboardAtPos(&bubble->field0.mPos), 0xc);
    if (bubble->fieldA8 != 0) {
        n = bubble->fieldA8 >> 4;
        MTX_RotZ33_(rotationMatrix, FX_SinCosTable_[n * 2], FX_SinCosTable_[n * 2 + 1]);
        NNS_G3dGeBufferOP_N(0x1a, rotationMatrix, 9);
    }
    NNS_G3dGeBufferOP_N(0x1b, &bubble->field0.mScale, 3);
    DrawNsbmdWithMaxAlpha(gMkdEfBubble, alpha);
    v = bubble->field0.mPos.y - bubble->fieldAC;
    if (v > 0x10000) {
        v = 0x1000 - ((v - 0x10000) >> 8);
        bubble->fieldB0.field30 = 0xd;
    } else {
        n = 0xd - ((0x10000 - v) >> 13);
        v = 0x1000;
        if (n < 1) {
            n = 1;
        }
        bubble->fieldB0.field30 = n;
    }
    if (v <= 0) {
        return;
    }
    oshd_renderMat(&bubble->fieldB0, &v, 0, alpha);
}

void efbub_globalPreUpdate(void) {
    anim_update(gMkdEfBubbleNsbta);
}

void efbub_update(void *a, MkdEfBubbleObject *bubble) {
    sm_execute(&bubble->field0.mStateMachine);
    if (bubble->fieldF0 != 0) {
        return;
    }
    if ((bubble->field0.mFlags & 0x12) != 0) {
        bubble->fieldE8->field24 |= 8;
        bubble->fieldEC->field24 |= 8;
        return;
    }
    bubble->fieldE8->field24 &= ~8;
    bubble->fieldEC->field24 &= ~8;
    ptcm_setEmitterPosition(bubble->fieldE8, &bubble->field0.mPos);
    ptcm_setEmitterPosition(bubble->fieldEC, &bubble->field0.mPos);
}

void efbub_state0Init(MkdEfBubbleObject *bubble) {
    Unk0210b7a8 soundRequest;
    s32 falloffIndex;
    BOOL effectMissing;

    bubble->fieldA8 = 0;
    bubble->field0.mPos.y = bubble->fieldA4;
    bubble->field0.field10.y = 0x4b33;
    bubble->field0.mFlags &= ~2;
    bubble->field0.mFlags &= ~8;
    bubble->field0.mAlpha = 0x1f;
    if ((bubble->field0.mDistanceSquaredAndFlags & 4) == 0) {
        if (bubble->field0.mFarDistanceSquared == gSfxParams[2].field20) {
            falloffIndex = 2;
        } else if (bubble->field0.mFarDistanceSquared == gSfxParams[3].field20) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x18c;
        soundRequest.mPositionSource = &bubble->field0.mPos;
        soundRequest.field8 = falloffIndex;
        soundRequest.mDistanceSquared = mobj_calcXZCamDist(&bubble->field0.mPos);
        func_0210b7a8(&soundRequest);
    }
    bubble->fieldE4 = 0;
    if (bubble->fieldE8 == NULL) {
        bubble->fieldE8 = ptcm_createEmitter(0x45, &bubble->field0.mPos);
    }
    if (bubble->fieldEC == NULL) {
        bubble->fieldEC = ptcm_createEmitter(0x46, &bubble->field0.mPos);
    }
    if (bubble->fieldE8 == NULL || bubble->fieldEC == NULL) {
        effectMissing = TRUE;
    } else {
        effectMissing = FALSE;
    }
    bubble->fieldF0 = effectMissing;
}

void efbub_state0Update(MkdEfBubbleObject *bubble) {
    if (bubble->field0.field10.y < 0x1333) {
        if (bubble->field0.field10.y <= -0x1333) {
            bubble->fieldA8 = 0x8000;
        } else {
            bubble->fieldA8 = (s32) (((s64) (0x1333 - bubble->field0.field10.y) * data_0217b76c->field28) >> 12) >> 12;
        }
    }
    bubble->field0.field10.y -= 0x199;
    if (bubble->field0.field10.y < -0x3000) {
        bubble->field0.field10.y = -0x3000;
    }
    bubble->field0.mPos.y += bubble->field0.field10.y;
    if (bubble->field0.mPos.y < bubble->fieldA4) {
        bubble->field0.mStateMachine.mNextState = 1;
        bubble->field0.mStateMachine.mNextStateRequested = 1;
    }
}
