#include "Main/Unknown/code_020e0058.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"

#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020e01ec.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e337c.h"
#include "Main/Unknown/code_020e3618.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0217c000.h"

void SetCollisionHitLink(CollisionMapObject *object, Vec3 *position, Vec3 *velocity, CollisionHitLink *link) {
    Vec3 offset;
    s32 localZ;
    s32 localY;

    VEC_Subtract(position, &object->mMapObject.mPos, &offset);
    localZ = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[2]);
    localY = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[1]);
    link->mLocalPosition.x = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[0]);
    link->mLocalPosition.y = localY;
    link->mLocalPosition.z = localZ;
    if (velocity != NULL && object->mCollisionData.mUnk_130 != FALSE) {
        localZ = Vec3DotUnrounded(velocity, &object->mMapObject.mMatrix.mRows[2]);
        localY = Vec3DotUnrounded(velocity, &object->mMapObject.mMatrix.mRows[1]);
        link->mLocalVelocity.x = Vec3DotUnrounded(velocity, &object->mMapObject.mMatrix.mRows[0]);
        link->mLocalVelocity.y = localY;
        link->mLocalVelocity.z = localZ;
    } else {
        link->mLocalVelocity.x = 0;
        link->mLocalVelocity.y = 0;
        link->mLocalVelocity.z = 0;
    }
    link->mObject = object;
}

void GetCollisionHitLinkPosition(CollisionHitLink *link, Vec3 *outPosition) {
    CollisionMapObject *object = link->mObject;

    if (object == NULL) {
        return;
    }
    MTX_MultVec33(&link->mLocalPosition, &object->mMapObject.mMatrix.mAxes, outPosition);
    VEC_Add(&object->mMapObject.mPos, outPosition, outPosition);
}

BOOL GetCollisionHitLinkPosAndVelocity(CollisionHitLink *link, Vec3 *outPosition, Vec3 *outVelocity) {
    CollisionMapObject *object = link->mObject;

    if (object != NULL) {
        MTX_MultVec33(&link->mLocalPosition, &object->mMapObject.mMatrix.mAxes, outPosition);
        VEC_Add(&object->mMapObject.mPos, outPosition, outPosition);
        if (object->mCollisionData.mUnk_130 != FALSE) {
            MTX_MultVec33(&link->mLocalVelocity, &object->mMapObject.mMatrix.mAxes, outVelocity);
            if (outVelocity->y < object->mCollisionData.mUnk_120) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

// Any map object: the clock gears compare against their radius, every other object returns its collision flag.
s32 IsHitLinkOutsideGearRadiusOrFlagged(CollisionHitLink *link) {
    Rotary *object = (Rotary *) link->mObject;
    s64 horizontalDistanceSquared;
    s64 limitSquared;

    if (object->mCollisionMapObject.mCollisionData.mUnk_138 != 0 &&
        object->mCollisionMapObject.mMapObject.mKind == MAP_OBJECT_KIND_ROTARY_GEAR) {
        horizontalDistanceSquared = HORIZONTAL_LENGTH_SQUARED(link->mLocalPosition);
        limitSquared = (s64) object->mGearRadius * object->mGearRadius;
        return horizontalDistanceSquared >= limitSquared;
    }
    return object->mCollisionMapObject.mCollisionData.mUnk_138;
}

void *CreateKoopaBlockKindData(void) {
    MapObjectKindData *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);

    *kindData = data_021588a8;
    return kindData;
}

void *CreateKoopaBlockDrawList(void) {
    MapObjectDrawList *drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);

    gKoopaBlockDrawList = drawList;
    *drawList = data_0215887c;
    SetDrawListSlot(&gKoopaBlockDrawList);
    return gKoopaBlockDrawList;
}

void *CreateKoopaBlockUpdateList(void) {
    MapObjectList *updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);

    gKoopaBlockUpdateList = updateList;
    *updateList = data_02158854;
    SetUpdateListSlot(&gKoopaBlockUpdateList);
    return gKoopaBlockUpdateList;
}

void UpdateKoopaBlock(void *unused, KoopaBlock *koopaBlock) {
    GroupFollower *follower = &koopaBlock->mFollower;

    if (koopaBlock->mPauseTimer != 0) {
        SoundStartParams soundRequest;
        s32 falloffIndex;

        koopaBlock->mPauseTimer--;
        koopaBlock->mCollisionMapObject.mMapObject.mPosStep.x = 0;
        koopaBlock->mCollisionMapObject.mMapObject.mPosStep.y = 0;
        koopaBlock->mCollisionMapObject.mMapObject.mPosStep.z = 0;
        if (koopaBlock->mPauseTimer != 0) {
            return;
        }
        if ((koopaBlock->mCollisionMapObject.mMapObject.mDistanceSquaredAndFlags & 4) != 0) {
            return;
        }
        falloffIndex =
            koopaBlock->mCollisionMapObject.mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared
                ? 2
                : (koopaBlock->mCollisionMapObject.mMapObject.mFarDistanceSquared ==
                           gSoundFalloffs[3].mFarDistanceSquared
                       ? 3
                       : 4);
        soundRequest.mSoundId = 0x17e;
        soundRequest.mPositionSource = &koopaBlock->mCollisionMapObject.mMapObject.mPos;
        soundRequest.mFalloffIndex = falloffIndex;
        soundRequest.mDistanceSquared =
            GetHorizontalCameraDistanceSquared(&koopaBlock->mCollisionMapObject.mMapObject.mPos);
        StartSoundFromParams(&soundRequest);
        return;
    }
    if (AdvanceGroupFollower(follower) != FALSE) {
        if (koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mState == 2) {
            koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextState = 0;
            koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
        }
        koopaBlock->mPauseTimer = follower->mFromEntry->mUnk_0e;
    }
    koopaBlock->mCollisionMapObject.mCollisionData.mUnk_e8 = koopaBlock->mCollisionMapObject.mMapObject.mPos;
    GetGroupFollowerLinearPosition(follower, &koopaBlock->mCollisionMapObject.mMapObject.mPos);
    AdvanceStateMachine(&koopaBlock->mCollisionMapObject.mMapObject.mStateMachine);
    VEC_Subtract(&koopaBlock->mCollisionMapObject.mMapObject.mPos,
                 &koopaBlock->mCollisionMapObject.mCollisionData.mUnk_e8,
                 &koopaBlock->mCollisionMapObject.mMapObject.mPosStep);
    VEC_MultAdd(-koopaBlock->mCollisionMapObject.mCollisionData.mHalfSizeY,
                &koopaBlock->mCollisionMapObject.mMapObject.mMatrix.mRows[1],
                &koopaBlock->mCollisionMapObject.mMapObject.mPos,
                &koopaBlock->mCollisionMapObject.mCollisionData.mCenterPos);
}

u32 KoopaBlockState0ReturnArgument(u32 value) {
    return value;
}

void UpdateKoopaBlockState0(KoopaBlock *koopaBlock) {
    GroupFollower *follower = &koopaBlock->mFollower;
    s32 progress = GetGroupFollowerProgress(follower);
    s32 angle = (u16) (((s64) progress << 18) >> 12);
    s16 sine = FX_SinIdx(angle);
    s32 speed = MUL_FIXED12_NO_ROUND(sine, koopaBlock->mFollowSpeed);
    s32 inverseProgressLength;

    follower->mSpeed = speed > 0x200 ? speed : 0x200;
    inverseProgressLength = follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength;
    if (speed <= 0x200) {
        speed = 0x200;
    }
    follower->mProgressStep = MUL_FIXED12_NO_ROUND(speed, inverseProgressLength);
    if (GetGroupFollowerProgress(follower) >= 0x100) {
        koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextState = 1;
        koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterKoopaBlockState1(KoopaBlock *koopaBlock) {
    s32 speed = koopaBlock->mFollowSpeed;

    koopaBlock->mFollower.mSpeed = speed;
    koopaBlock->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
        speed, koopaBlock->mFollower.mPath->mSegments[koopaBlock->mFollower.mSegmentIndex].mInverseProgressLength);
}

void UpdateKoopaBlockState1(KoopaBlock *koopaBlock) {
    GroupFollower *follower = &koopaBlock->mFollower;

    if (follower->mToEntry->mUnk_0e == 0) {
        GroupPath *path = follower->mPath;
        BOOL onEndSegment;
        BOOL onEndSegmentOfOpenPath = FALSE;

        if (path->mWraps == 0) {
            if (follower->mForward != 0) {
                onEndSegment = follower->mSegmentIndex == path->mSegmentCount - 1;
            } else {
                onEndSegment = follower->mSegmentIndex == 0;
            }
            if (onEndSegment) {
                onEndSegmentOfOpenPath = TRUE;
            }
        }
        if (onEndSegmentOfOpenPath == FALSE) {
            return;
        }
    }
    if (GetGroupFollowerProgress(follower) >= 0xf00) {
        koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextState = 2;
        koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 KoopaBlockState2ReturnArgument(u32 value) {
    return value;
}
