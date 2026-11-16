#include "Main/MapObjects/wanwan_chain_init.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "fixed_vector_math.h"

#pragma thumb on

const Vec3 gWanwanChainInitialPullScale = {0x100, 0x400, 0x100};

void InitWanwanChain(WanwanChain *chain, Vec3 *start, Vec3 *end, s32 length, s32 pointCount, s32 value,
                     Vec3 *modelScale) {
    s32 segmentCount;
    void *heap;

    chain->mLength = length;
    chain->mPointCount = pointCount;
    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    chain->mPoints = Mem_AllocateHeap(heap, pointCount * 12);
    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    chain->mVelocities = Mem_AllocateHeap(heap, pointCount * 12);
    chain->mModelScale = *modelScale;
    chain->mMinYOffset = MUL_FIXED12_NO_ROUND(value, modelScale->y);
    segmentCount = pointCount - 1;
    chain->mStepFraction = FIXED12_UNIT / segmentCount;
    chain->mLinkLength = MUL_FIXED12_NO_ROUND(length, 0x119a) / segmentCount;
    chain->mLinkLengthSquared = (s64) chain->mLinkLength * chain->mLinkLength;
    SetWanwanChainPointsEvenly(chain, start, end);
    chain->mMinY = start->y + chain->mMinYOffset;
    chain->mDownwardStep = WANWAN_CHAIN_DOWNWARD_STEP_INITIAL;
    chain->mDamping = WANWAN_CHAIN_DAMPING;
    chain->mPullScale = gWanwanChainInitialPullScale;
    chain->mFirstLinkConstrained = 1;
}

void SetWanwanChainPointsEvenly(WanwanChain *chain, Vec3 *start, Vec3 *end) {
    Vec3 step;
    Vec3 *zeroedPoints;
    s32 index;
    s32 stepFraction;

    VecFx32_Subtract(end, start, &step);
    stepFraction = chain->mStepFraction;
    step.x = MUL_FIXED12_NO_ROUND(step.x, stepFraction);
    step.y = MUL_FIXED12_NO_ROUND(step.y, stepFraction);
    step.z = MUL_FIXED12_NO_ROUND(step.z, stepFraction);
    *chain->mPoints = *start;
    zeroedPoints = chain->mVelocities;
    zeroedPoints->x = 0;
    zeroedPoints->y = 0;
    zeroedPoints->z = 0;
    for (index = 1; index < chain->mPointCount; index++) {
        VecFx32_Add(&chain->mPoints[index - 1], &step, &chain->mPoints[index]);
        zeroedPoints = chain->mVelocities;
        zeroedPoints[index].x = 0;
        zeroedPoints[index].y = 0;
        zeroedPoints[index].z = 0;
    }
}

#pragma thumb off
