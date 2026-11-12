#include "Main/MapObjects/wanwan_chain_init.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "code_02147cd8.h"

#pragma thumb on

const Vec3 data_021583c8 = {0x100, 0x400, 0x100};

void InitWanwanChain(WanwanChain *chain, Vec3 *start, Vec3 *end, s32 length, s32 pointCount, s32 value,
                     Vec3 *modelScale) {
    s32 segmentCount;
    void *heap;

    chain->mLength = length;
    chain->mPointCount = pointCount;
    heap = GetHeap(GetCurrentHeapCall());
    chain->mPoints = HeapAlloc(heap, pointCount * 12);
    heap = GetHeap(GetCurrentHeapCall());
    chain->mVelocities = HeapAlloc(heap, pointCount * 12);
    chain->mModelScale = *modelScale;
    chain->mUnk_40 = MUL_FIXED12_NO_ROUND(value, modelScale->y);
    segmentCount = pointCount - 1;
    chain->mStepFraction = 0x1000 / segmentCount;
    chain->mLinkLength = MUL_FIXED12_NO_ROUND(length, 0x119a) / segmentCount;
    chain->mLinkLengthSquared = (s64) chain->mLinkLength * chain->mLinkLength;
    SetWanwanChainPointsEvenly(chain, start, end);
    chain->mMinY = start->y + chain->mUnk_40;
    chain->mDownwardStep = 0x599;
    chain->mDamping = 0x51;
    chain->mPullScale = data_021583c8;
    chain->mFirstLinkConstrained = 1;
}

void SetWanwanChainPointsEvenly(WanwanChain *chain, Vec3 *start, Vec3 *end) {
    Vec3 step;
    Vec3 *zeroedPoints;
    s32 index;
    s32 stepFraction;

    VEC_Subtract(end, start, &step);
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
        VEC_Add(&chain->mPoints[index - 1], &step, &chain->mPoints[index]);
        zeroedPoints = chain->mVelocities;
        zeroedPoints[index].x = 0;
        zeroedPoints[index].y = 0;
        zeroedPoints[index].z = 0;
    }
}

#pragma thumb off
