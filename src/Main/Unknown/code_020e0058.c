#include "Main/Unknown/code_020e0058.h"
#include "Main/System/Heap.h"
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

void func_020e0584(Unk020e005c *object, Vec3 *position, Vec3 *velocity, Unk020e04b0 *link) {
    Vec3 offset;
    s32 f;
    s32 g;

    VEC_Subtract(position, &object->mPos, &offset);
    f = vec_dotProduct(&offset, &object->field40);
    g = vec_dotProduct(&offset, &object->field34);
    link->field4.x = vec_dotProduct(&offset, &object->field28);
    link->field4.y = g;
    link->field4.z = f;
    if (velocity != NULL && object->field130 != FALSE) {
        f = vec_dotProduct(velocity, &object->field40);
        g = vec_dotProduct(velocity, &object->field34);
        link->field10.x = vec_dotProduct(velocity, &object->field28);
        link->field10.y = g;
        link->field10.z = f;
    } else {
        link->field10.x = 0;
        link->field10.y = 0;
        link->field10.z = 0;
    }
    link->field0 = object;
}

void func_020e0538(Unk020e04b0 *link, Vec3 *outPosition) {
    Unk020e005c *object = link->field0;

    if (object == NULL) {
        return;
    }
    MTX_MultVec33(&link->field4, &object->field28.x, outPosition);
    VEC_Add(&object->mPos, outPosition, outPosition);
}

BOOL func_020e04b0(Unk020e04b0 *link, Vec3 *outPosition, Vec3 *outVelocity) {
    Unk020e005c *object = link->field0;

    if (object != NULL) {
        MTX_MultVec33(&link->field4, &object->field28.x, outPosition);
        VEC_Add(&object->mPos, outPosition, outPosition);
        if (object->field130 != FALSE) {
            MTX_MultVec33(&link->field10, &object->field28.x, outVelocity);
            if (outVelocity->y < object->field120) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

s32 func_020e0448(Unk020e0448 *link) {
    Unk020e3ef4 *object = link->field0;
    s64 horizontalDistanceSquared;
    s64 limitSquared;

    if (object->field138 != 0 && object->field0.mKind == 0xcb) {
        horizontalDistanceSquared = (s64) link->field4.x * link->field4.x + (s64) link->field4.z * link->field4.z;
        limitSquared = (s64) object->field154 * object->field154;
        return horizontalDistanceSquared >= limitSquared;
    }
    return object->field138;
}

void *kblock_setupConfig(void) {
    void *kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);

    *(Unk020e03f8 *) kindData = *(const Unk020e03f8 *) data_021588a8;
    return kindData;
}

void *kblock_setupRenderPart(void) {
    void *drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);

    kblock_sRenderPart = drawList;
    *(Unk020e039c *) drawList = *(const Unk020e039c *) data_0215887c;
    mobj_renderPartSetThisPointer(&kblock_sRenderPart);
    return kblock_sRenderPart;
}

void *kblock_setupLogicPart(void) {
    void *updateList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);

    kblock_sLogicPart = updateList;
    *(Unk020e0340 *) updateList = *(const Unk020e0340 *) data_02158854;
    mobj_logicPartSetThisPointer(&kblock_sLogicPart);
    return kblock_sLogicPart;
}

void kblock_update(void *a0, Unk020e005c *koopaBlock) {
    GroupFollower *follower = &koopaBlock->field144;

    if (koopaBlock->field16C != 0) {
        Unk0210b7a8 soundRequest;
        s32 falloffIndex;

        koopaBlock->field16C--;
        koopaBlock->field10.x = 0;
        koopaBlock->field10.y = 0;
        koopaBlock->field10.z = 0;
        if (koopaBlock->field16C != 0) {
            return;
        }
        if ((koopaBlock->mDistanceSquaredAndFlags & 4) != 0) {
            return;
        }
        falloffIndex = koopaBlock->mFarDistanceSquared == gSfxParams[2].field20
                           ? 2
                           : (koopaBlock->mFarDistanceSquared == gSfxParams[3].field20 ? 3 : 4);
        soundRequest.mSoundId = 0x17e;
        soundRequest.mPositionSource = &koopaBlock->mPos;
        soundRequest.field8 = falloffIndex;
        soundRequest.mDistanceSquared = mobj_calcXZCamDist(&koopaBlock->mPos);
        func_0210b7a8(&soundRequest);
        return;
    }
    if (pw_update(follower) != FALSE) {
        if (koopaBlock->mStateMachine.mState == 2) {
            koopaBlock->mStateMachine.mNextState = 0;
            koopaBlock->mStateMachine.mNextStateRequested = 1;
        }
        koopaBlock->field16C = follower->mFromEntry->fieldE;
    }
    koopaBlock->fieldE8 = koopaBlock->mPos;
    pw_calcCurrentPointLinearXYZ(follower, &koopaBlock->mPos);
    sm_execute(&koopaBlock->mStateMachine);
    VEC_Subtract(&koopaBlock->mPos, &koopaBlock->fieldE8, &koopaBlock->field10);
    VEC_MultAdd(-koopaBlock->field104, &koopaBlock->field34, &koopaBlock->mPos, &koopaBlock->fieldF4);
}

u32 kblock_speedUpStateInit(u32 value) {
    return value;
}

void kblock_speedUpStateUpdate(Unk020e005c *koopaBlock) {
    GroupFollower *follower = &koopaBlock->field144;
    s32 progress = pw_getProgress(follower);
    s32 angle = (u16) (((s64) progress << 18) >> 12);
    s16 sine = FX_SinCosTable_[(angle >> 4) * 2];
    s32 speed = ((s64) sine * koopaBlock->field168) >> 12;
    s32 m;

    follower->mSpeed = speed > 0x200 ? speed : 0x200;
    m = follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength;
    if (speed <= 0x200) {
        speed = 0x200;
    }
    follower->mProgressStep = ((s64) speed * m) >> 12;
    if (pw_getProgress(follower) >= 0x100) {
        koopaBlock->mStateMachine.mNextState = 1;
        koopaBlock->mStateMachine.mNextStateRequested = 1;
    }
}

void kblock_moveStateInit(Unk020e005c *koopaBlock) {
    s32 speed = koopaBlock->field168;

    koopaBlock->field144.mSpeed = speed;
    koopaBlock->field144.mProgressStep =
        ((s64) speed *
         koopaBlock->field144.mPath->mSegments[koopaBlock->field144.mSegmentIndex].mInverseProgressLength) >>
        12;
}

void kblock_moveStateUpdate(Unk020e005c *koopaBlock) {
    GroupFollower *follower = &koopaBlock->field144;

    if (follower->mToEntry->fieldE == 0) {
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
    if (pw_getProgress(follower) >= 0xf00) {
        koopaBlock->mStateMachine.mNextState = 2;
        koopaBlock->mStateMachine.mNextStateRequested = 1;
    }
}

u32 kblock_slowDownStateInit(u32 value) {
    return value;
}
