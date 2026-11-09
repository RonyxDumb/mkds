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

void SetCollisionHitLink(Unk020e1d10 *object, Vec3 *position, Vec3 *velocity, CollisionHitLink *link) {
    Vec3 offset;
    s32 localZ;
    s32 localY;

    VEC_Subtract(position, &object->mMapObject.mPos, &offset);
    localZ = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mUnk_00[2]);
    localY = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mUnk_00[1]);
    link->mLocalPosition.x = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mUnk_00[0]);
    link->mLocalPosition.y = localY;
    link->mLocalPosition.z = localZ;
    if (velocity != NULL && object->mCollisionData.mUnk_130 != FALSE) {
        localZ = Vec3DotUnrounded(velocity, &object->mMapObject.mMatrix.mUnk_00[2]);
        localY = Vec3DotUnrounded(velocity, &object->mMapObject.mMatrix.mUnk_00[1]);
        link->mLocalVelocity.x = Vec3DotUnrounded(velocity, &object->mMapObject.mMatrix.mUnk_00[0]);
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
    Unk020e1d10 *object = link->mObject;

    if (object == NULL) {
        return;
    }
    MTX_MultVec33(&link->mLocalPosition, &object->mMapObject.mMatrix.mUnk_00_m, outPosition);
    VEC_Add(&object->mMapObject.mPos, outPosition, outPosition);
}

BOOL GetCollisionHitLinkPosAndVelocity(CollisionHitLink *link, Vec3 *outPosition, Vec3 *outVelocity) {
    Unk020e1d10 *object = link->mObject;

    if (object != NULL) {
        MTX_MultVec33(&link->mLocalPosition, &object->mMapObject.mMatrix.mUnk_00_m, outPosition);
        VEC_Add(&object->mMapObject.mPos, outPosition, outPosition);
        if (object->mCollisionData.mUnk_130 != FALSE) {
            MTX_MultVec33(&link->mLocalVelocity, &object->mMapObject.mMatrix.mUnk_00_m, outVelocity);
            if (outVelocity->y < object->mCollisionData.mUnk_120) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

s32 func_020e0448(Unk020e0448 *link) {
    Rotary *object = link->mUnk_00;
    s64 horizontalDistanceSquared;
    s64 limitSquared;

    if (object->mUnk_000.mCollisionData.mUnk_138 != 0 && object->mUnk_000.mMapObject.mKind == 0xcb) {
        horizontalDistanceSquared = (s64) link->mUnk_04.x * link->mUnk_04.x + (s64) link->mUnk_04.z * link->mUnk_04.z;
        limitSquared = (s64) object->mUnk_154 * object->mUnk_154;
        return horizontalDistanceSquared >= limitSquared;
    }
    return object->mUnk_000.mCollisionData.mUnk_138;
}

void *CreateKoopaBlockKindData(void) {
    Unk020e03f8 *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);

    *kindData = data_021588a8;
    return kindData;
}

void *CreateKoopaBlockDrawList(void) {
    Unk020e039c *drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);

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

void UpdateKoopaBlock(void *unused, Unk020e005c *koopaBlock) {
    GroupFollower *follower = &koopaBlock->mUnk_144;

    if (koopaBlock->mUnk_16c != 0) {
        SoundStartParams soundRequest;
        s32 falloffIndex;

        koopaBlock->mUnk_16c--;
        koopaBlock->mUnk_000.mMapObject.mUnk_10.x = 0;
        koopaBlock->mUnk_000.mMapObject.mUnk_10.y = 0;
        koopaBlock->mUnk_000.mMapObject.mUnk_10.z = 0;
        if (koopaBlock->mUnk_16c != 0) {
            return;
        }
        if ((koopaBlock->mUnk_000.mMapObject.mDistanceSquaredAndFlags & 4) != 0) {
            return;
        }
        falloffIndex = koopaBlock->mUnk_000.mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20
                           ? 2
                           : (koopaBlock->mUnk_000.mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20 ? 3 : 4);
        soundRequest.mSoundId = 0x17e;
        soundRequest.mPositionSource = &koopaBlock->mUnk_000.mMapObject.mPos;
        soundRequest.mFalloffIndex = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&koopaBlock->mUnk_000.mMapObject.mPos);
        StartSoundFromParams(&soundRequest);
        return;
    }
    if (AdvanceGroupFollower(follower) != FALSE) {
        if (koopaBlock->mUnk_000.mMapObject.mStateMachine.mState == 2) {
            koopaBlock->mUnk_000.mMapObject.mStateMachine.mNextState = 0;
            koopaBlock->mUnk_000.mMapObject.mStateMachine.mNextStateRequested = 1;
        }
        koopaBlock->mUnk_16c = follower->mFromEntry->mUnk_0e;
    }
    koopaBlock->mUnk_000.mCollisionData.mUnk_e8 = koopaBlock->mUnk_000.mMapObject.mPos;
    GetGroupFollowerLinearPosition(follower, &koopaBlock->mUnk_000.mMapObject.mPos);
    AdvanceStateMachine(&koopaBlock->mUnk_000.mMapObject.mStateMachine);
    VEC_Subtract(&koopaBlock->mUnk_000.mMapObject.mPos, &koopaBlock->mUnk_000.mCollisionData.mUnk_e8,
                 &koopaBlock->mUnk_000.mMapObject.mUnk_10);
    VEC_MultAdd(-koopaBlock->mUnk_000.mCollisionData.mHalfSizeY, &koopaBlock->mUnk_000.mMapObject.mMatrix.mUnk_00[1],
                &koopaBlock->mUnk_000.mMapObject.mPos, &koopaBlock->mUnk_000.mCollisionData.mCenterPos);
}

u32 KoopaBlockState0ReturnArgument(u32 value) {
    return value;
}

void UpdateKoopaBlockState0(Unk020e005c *koopaBlock) {
    GroupFollower *follower = &koopaBlock->mUnk_144;
    s32 progress = GetGroupFollowerProgress(follower);
    s32 angle = (u16) (((s64) progress << 18) >> 12);
    s16 sine = gPairsByAngle[(angle >> 4) * 2];
    s32 speed = MUL_FIXED12_NO_ROUND(sine, koopaBlock->mUnk_168);
    s32 inverseProgressLength;

    follower->mSpeed = speed > 0x200 ? speed : 0x200;
    inverseProgressLength = follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength;
    if (speed <= 0x200) {
        speed = 0x200;
    }
    follower->mProgressStep = MUL_FIXED12_NO_ROUND(speed, inverseProgressLength);
    if (GetGroupFollowerProgress(follower) >= 0x100) {
        koopaBlock->mUnk_000.mMapObject.mStateMachine.mNextState = 1;
        koopaBlock->mUnk_000.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterKoopaBlockState1(Unk020e005c *koopaBlock) {
    s32 speed = koopaBlock->mUnk_168;

    koopaBlock->mUnk_144.mSpeed = speed;
    koopaBlock->mUnk_144.mProgressStep = MUL_FIXED12_NO_ROUND(
        speed, koopaBlock->mUnk_144.mPath->mSegments[koopaBlock->mUnk_144.mSegmentIndex].mInverseProgressLength);
}

void UpdateKoopaBlockState1(Unk020e005c *koopaBlock) {
    GroupFollower *follower = &koopaBlock->mUnk_144;

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
        koopaBlock->mUnk_000.mMapObject.mStateMachine.mNextState = 2;
        koopaBlock->mUnk_000.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 KoopaBlockState2ReturnArgument(u32 value) {
    return value;
}
