#pragma once

#include "types.h"

// Values of WanwanChain.mDownwardStep: the initial one, and the one the lunge and hit states set.
#define WANWAN_CHAIN_DOWNWARD_STEP_INITIAL 0x599
#define WANWAN_CHAIN_DOWNWARD_STEP_HIT 0x219

// Object of InitWanwanChain: words at 0x00 to 0x10, a vector at 0x14, a word at 0x20, a vector at 0x34, and two
// arrays of vectors at 0x44 and 0x48 with one element per unit of the word at 0x20.
typedef struct WanwanChain {
    /* 00 */ s32 mLength;
    /* 04 */ s32 mDownwardStep;
    /* 08 */ s32 mFirstLinkConstrained;
    /* 0c */ s32 mMinY;
    /* 10 */ s32 mDamping;
    /* 14 */ Vec3 mPullScale;
    /* 20 */ s32 mPointCount;
    /* 24 */ s32 mStepFraction;
    /* 28 */ s32 mLinkLength;
    /* 2c */ s64 mLinkLengthSquared;
    /* 34 */ Vec3 mModelScale;
    /* 40 */ s32 mMinYOffset;
    /* 44 */ Vec3 *mPoints;
    /* 48 */ Vec3 *mVelocities;
} WanwanChain;

extern const Vec3 gWanwanChainInitialPullScale;

void InitWanwanChain(WanwanChain *chain, Vec3 *start, Vec3 *end, s32 length, s32 pointCount, s32 value,
                     Vec3 *modelScale);
void SetWanwanChainPointsEvenly(WanwanChain *chain, Vec3 *start, Vec3 *end);
