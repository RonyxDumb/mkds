#include "Main/Unknown/code_020df890.h"
#include "Main/Unknown/code_02036820.h"
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

void UpdateKoopaBlockState2(KoopaBlock *koopaBlock) {
    GroupFollower *follower;
    s32 progress;
    s32 speed;
    u16 angle;
    s32 sine;

    follower = &koopaBlock->mFollower;
    progress = GetGroupFollowerProgress(follower);
    angle = MUL_FIXED12_NO_ROUND(progress, 0x40000);
    sine = FX_SinIdx(angle);
    speed = MUL_FIXED12_NO_ROUND(-sine, koopaBlock->mFollowSpeed);
    follower->mSpeed = speed > 0x200 ? speed : 0x200;
    if (speed <= 0x200) {
        speed = 0x200;
    }
    follower->mProgressStep =
        MUL_FIXED12_NO_ROUND(speed, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
}

void DrawAllKoopaBlocks(void *viewMatrix) {
    DrawVisibleMapObjects(gKoopaBlockDrawList, viewMatrix, DrawMapObjectModelAtPos);
}

BOOL IsKoopaBlockKind(u32 kind) {
    switch (kind) {
        case 0xca:
            return 1;
        default:
            return 0;
    }
}

s32 GetKoopaBlockProgress(KoopaBlock *koopaBlock) {
    s32 progress;
    GroupFollower *follower;

    follower = &koopaBlock->mFollower;
    progress = GetGroupFollowerProgress(follower);
    if (follower->mForward == 0) {
        progress = 0x1000 - progress;
    }
    return progress;
}

#pragma thumb on
void CreateKoopaBlock(void) {
    void *file;

    file = FindCourseMapObjFile("koopa_block.nsbmd");
    CreateNsbmd(&gKoopaBlock, file, NULL);
    SetNsbmdPolygonIdLightEmiAll(gKoopaBlock, 0x3f, 2, 0x294a);
    SetMapObjectsModel(gKoopaBlockDrawList, gKoopaBlock);
}

void InitKoopaBlock(KoopaBlock *koopaBlock, CourseMapRow *courseRow) {
    InitStateMachine(&koopaBlock->mCollisionMapObject.mMapObject.mStateMachine, gKoopaBlockStateTable, 3, koopaBlock);
    koopaBlock->mFollowSpeed = (courseRow->mUnk_28 << 12) / 100;
    InitGroupFollower(&koopaBlock->mFollower, courseRow, koopaBlock->mFollowSpeed);
    koopaBlock->mPauseTimer = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mPrevMatrix =
        koopaBlock->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    koopaBlock->mCollisionMapObject.mCollisionData.mAngleChangeVector.x = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mAngleChangeVector.y = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mAngleChangeVector.z = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mUnk_130 = FALSE;
    koopaBlock->mCollisionMapObject.mCollisionData.mUnk_100 =
        MUL_FIXED12_NO_ROUND(koopaBlock->mCollisionMapObject.mMapObject.mScale.x, 0x190000);
    koopaBlock->mCollisionMapObject.mCollisionData.mHalfSizeY =
        MUL_FIXED12_NO_ROUND(koopaBlock->mCollisionMapObject.mMapObject.mScale.y, 0x64000) >> 1;
    koopaBlock->mCollisionMapObject.mCollisionData.mPositiveHalfSizeZ =
        MUL_FIXED12_NO_ROUND(koopaBlock->mCollisionMapObject.mMapObject.mScale.z, 0xaf000);
    koopaBlock->mCollisionMapObject.mCollisionData.mNegativeHalfSizeZ =
        MUL_FIXED12_NO_ROUND(koopaBlock->mCollisionMapObject.mMapObject.mScale.z, 0xaf000);
    koopaBlock->mCollisionMapObject.mCollisionData.mUnk_110 = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mUnk_114.x = 1;
    koopaBlock->mCollisionMapObject.mCollisionData.mUnk_114.y = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mUnk_114.z = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mUnk_120 = 0x800;
    SetupGroupFollowerAtEntry(&koopaBlock->mFollower, 0, 1);
    GetGroupFollowerLinearPosStep(&koopaBlock->mFollower, &koopaBlock->mCollisionMapObject.mMapObject.mPos,
                                  &koopaBlock->mCollisionMapObject.mMapObject.mPosStep);
    koopaBlock->mCollisionMapObject.mCollisionData.mUnk_e8 = koopaBlock->mCollisionMapObject.mMapObject.mPos;
    koopaBlock->mCollisionMapObject.mCollisionData.mUnk_134 = COLLISION_SHAPE_BOX;
    koopaBlock->mCollisionMapObject.mCollisionData.mUnk_138 = 0;
    koopaBlock->mCollisionMapObject.mMapObject.mFlags |= data_0215881c;
    koopaBlock->mCollisionMapObject.mMapObject.mFlags &= ~2;
    koopaBlock->mCollisionMapObject.mMapObject.mFlags &= ~8;
    koopaBlock->mCollisionMapObject.mMapObject.mAlpha = 0x1f;
    koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextState = 0;
    koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    koopaBlock->mCollisionMapObject.mMapObject.mFarDistanceSquared = gSoundFalloffs[3].mFarDistanceSquared;
}
#pragma thumb off

MapObjectKindData *CreateMkdEfBubbleKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_021587dc;
    return kindData;
}

MapObjectDrawList *CreateMkdEfBubbleDrawList(void) {
    gMkdEfBubbleDrawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *gMkdEfBubbleDrawList = data_021587b0;
    SetDrawListSlot(&gMkdEfBubbleDrawList);
    return gMkdEfBubbleDrawList;
}

MkdEfBubbleUpdateList *CreateMkdEfBubbleUpdateList(void) {
    gMkdEfBubbleUpdateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *gMkdEfBubbleUpdateList = data_02158784;
    SetUpdateListSlot(&gMkdEfBubbleUpdateList);
    gMkdEfBubbleUpdateList->mAngleScale = FX_Div(0x4000000, 0x1333);
    return gMkdEfBubbleUpdateList;
}

void DrawMkdEfBubble(void *unused0, MkdEfBubbleObject *bubble, void *unused1, s32 alpha) {
    s32 v;
    s32 w;
    MtxFx33 rotationMatrix;
    s32 n;

    if (bubble->mMapObject.mStateMachine.mState != 0) {
        return;
    }
    w = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &w, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&bubble->mMapObject.mPos), 0xc);
    if (bubble->mAngleZ != 0) {
        n = bubble->mAngleZ >> 4;
        MTX_RotZ33_(&rotationMatrix, FX_SinCosTable_[n * 2], FX_SinCosTable_[n * 2 + 1]);
        NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
    }
    NNS_G3dGeBufferOP_N(0x1b, &bubble->mMapObject.mScale, 3);
    DrawNsbmdWithMaxAlpha(gMkdEfBubble, alpha);
    v = bubble->mMapObject.mPos.y - bubble->mInitialY;
    if (v > 0x10000) {
        v = 0x1000 - ((v - 0x10000) >> 8);
        bubble->mShadowMatrix.mAlphaCap = 0xd;
    } else {
        n = 0xd - ((0x10000 - v) >> 13);
        v = 0x1000;
        if (n < 1) {
            n = 1;
        }
        bubble->mShadowMatrix.mAlphaCap = n;
    }
    if (v <= 0) {
        return;
    }
    DrawObjShadow(&bubble->mShadowMatrix, &v, 0, alpha);
}

void AdvanceMkdEfBubbleAnimation(void) {
    AdvanceModelAnimation(gMkdEfBubbleNsbta);
}

void UpdateMkdEfBubble(void *unused, MkdEfBubbleObject *bubble) {
    AdvanceStateMachine(&bubble->mMapObject.mStateMachine);
    if (bubble->mEffectMissing != 0) {
        return;
    }
    if ((bubble->mMapObject.mFlags & 0x12) != 0) {
        bubble->mFirstEffect->mUnk_24 |= 8;
        bubble->mSecondEffect->mUnk_24 |= 8;
        return;
    }
    bubble->mFirstEffect->mUnk_24 &= ~8;
    bubble->mSecondEffect->mUnk_24 &= ~8;
    PlaceEffect(bubble->mFirstEffect, &bubble->mMapObject.mPos);
    PlaceEffect(bubble->mSecondEffect, &bubble->mMapObject.mPos);
}

void EnterMkdEfBubbleState0(MkdEfBubbleObject *bubble) {
    SoundStartParams soundRequest;
    s32 falloffIndex;
    BOOL effectMissing;

    bubble->mAngleZ = 0;
    bubble->mMapObject.mPos.y = bubble->mBottomY;
    bubble->mMapObject.mPosStep.y = 0x4b33;
    bubble->mMapObject.mFlags &= ~2;
    bubble->mMapObject.mFlags &= ~8;
    bubble->mMapObject.mAlpha = 0x1f;
    if ((bubble->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
        if (bubble->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
            falloffIndex = 2;
        } else if (bubble->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x18c;
        soundRequest.mPositionSource = &bubble->mMapObject.mPos;
        soundRequest.mFalloffIndex = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&bubble->mMapObject.mPos);
        StartSoundFromParams(&soundRequest);
    }
    bubble->mKartMask = 0;
    if (bubble->mFirstEffect == NULL) {
        bubble->mFirstEffect = StartEffect(0x45, &bubble->mMapObject.mPos);
    }
    if (bubble->mSecondEffect == NULL) {
        bubble->mSecondEffect = StartEffect(0x46, &bubble->mMapObject.mPos);
    }
    if (bubble->mFirstEffect == NULL || bubble->mSecondEffect == NULL) {
        effectMissing = TRUE;
    } else {
        effectMissing = FALSE;
    }
    bubble->mEffectMissing = effectMissing;
}

void UpdateMkdEfBubbleState0(MkdEfBubbleObject *bubble) {
    if (bubble->mMapObject.mPosStep.y < 0x1333) {
        if (bubble->mMapObject.mPosStep.y <= -0x1333) {
            bubble->mAngleZ = 0x8000;
        } else {
            bubble->mAngleZ =
                MUL_FIXED12_NO_ROUND(0x1333 - bubble->mMapObject.mPosStep.y, gMkdEfBubbleUpdateList->mAngleScale) >> 12;
        }
    }
    bubble->mMapObject.mPosStep.y -= 0x199;
    if (bubble->mMapObject.mPosStep.y < -0x3000) {
        bubble->mMapObject.mPosStep.y = -0x3000;
    }
    bubble->mMapObject.mPos.y += bubble->mMapObject.mPosStep.y;
    if (bubble->mMapObject.mPos.y < bubble->mBottomY) {
        bubble->mMapObject.mStateMachine.mNextState = 1;
        bubble->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}
