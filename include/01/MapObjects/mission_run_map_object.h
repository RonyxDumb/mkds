#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject

// The members at the start of every prm table that mean the same in all six objects.
typedef struct MissionRunPrmHead {
    /* 000 */ s32 mCounterLimit;
    /* 004 */ s32 mScale;
    /* 008 */ s32 mCollisionOffsetY;
    /* 00c */ s32 mCollisionExtentXZ;
    /* 010 */ s32 mCourseHitVelocityScale;
    /* 014 */ s32 mFreeVelocityScale;
    /* 018 */ s32 mStopSpeedLimit;
    /* 01c */ s32 mGravity;
    /* 020 */ s32 mBounceScale;
    /* 024 */ s32 mKartPushPosStep;
    /* 028 */ s32 mKartPushVelocity;
    /* 02c */ s32 mItemPushVelocity;
    /* 030 */ s32 mWallPushVelocity;
    /* 034 */ s32 mChainStartupFirstAnimationEntry;
    /* 038 */ s32 mChainStartupFirstFrameStep;
    /* 03c */ s32 mChainStartupFirstFrameCount;
    /* 040 */ s32 mChainStartupSecondAnimationEntry;
    /* 044 */ s32 mChainStartupSecondFrameStep;
    /* 048 */ s32 mUnk_048;
    /* 04c */ s32 mStartupFirstAnimationEntry;
    /* 050 */ s32 mStartupFirstFrameStep;
    /* 054 */ s32 mStartupFirstFrameCount;
    /* 058 */ s32 mStartupSecondAnimationEntry;
    /* 05c */ s32 mStartupSecondFrameStep;
    /* 060 */ s32 mWaitForRaceStartDelayFrames;
    /* 064 */ s32 mWaitForRaceStartAnimationEntry;
    /* 068 */ s32 mWaitForRaceStartFrameStep;
    /* 06c */ s32 mUnk_06c;
} MissionRunPrmHead;

// The parameters of a Bomb King mission run map object: animation entries, speeds, angles and timers for its walk,
// chase, bomb throws, jumps, bounce and stop.
typedef struct BombKingPrm {
    /* 000 */ MissionRunPrmHead mHead;
    /* 070 */ s32 mStoppedAfterHitsAnimationEntry;
    /* 074 */ s32 mStoppedAfterHitsFrameStep;
    /* 078 */ s32 mKartEliminatedAnimationEntry;
    /* 07c */ s32 mKartEliminatedFrameStep;
    /* 080 */ u8 mUnk_080[0x4];
    /* 084 */ s32 mWalkAnimationEntry;
    /* 088 */ s32 mWalkFrameStep;
    /* 08c */ s32 mWalkSpeed;
    /* 090 */ s32 mWalkAnglePerCall;
    /* 094 */ s32 mWalkPointRadius;
    /* 098 */ s32 mWalkPointHalfAngle;
    /* 09c */ s32 mWalkFrameCount;
    /* 0a0 */ u8 mUnk_0a0[0x18];
    /* 0b8 */ s32 mChaseSpeed;
    /* 0bc */ s32 mChaseAnglePerCall;
    /* 0c0 */ s32 mKartRadius;
    /* 0c4 */ s32 mKartHalfAngle;
    /* 0c8 */ s32 mChaseFrameCount;
    /* 0cc */ s32 mKartPointRadius;
    /* 0d0 */ s32 mKartPointHalfAngle;
    /* 0d4 */ s32 mStoredBombThrowAnimationEntry;
    /* 0d8 */ s32 mStoredBombThrowFrameStep;
    /* 0dc */ s32 mStoredBombThrowFrameIndex;
    /* 0e0 */ u8 mUnk_0e0[0xc];
    /* 0ec */ s32 mStoreFoundBombAnimationEntry;
    /* 0f0 */ s32 mStoreFoundBombFrameStep;
    /* 0f4 */ s32 mStoreFoundBombSpeed;
    /* 0f8 */ s32 mStoreFoundBombAnglePerCall;
    /* 0fc */ s32 mBombOffsetX;
    /* 100 */ s32 mBombOffsetY;
    /* 104 */ s32 mChaseAnimationEntry;
    /* 108 */ s32 mChaseFrameStep;
    /* 10c */ s32 mWalkToBombSpeed;
    /* 110 */ s32 mWalkToBombAnglePerCall;
    /* 114 */ s32 mFindBombRadius;
    /* 118 */ s32 mFindBombHalfAngle;
    /* 11c */ s32 mBombPointRadius;
    /* 120 */ s32 mBombPointHalfAngle;
    /* 124 */ s32 mWalkToBombFrameCount;
    /* 128 */ u8 mUnk_128[0xc];
    /* 134 */ s32 mStoredBombThrowSpeed;
    /* 138 */ s32 mStoredBombThrowVelocityY;
    /* 13c */ s32 mStoredBombThrowTimer;
    /* 140 */ s32 mThrowBombsAnimationEntry;
    /* 144 */ s32 mThrowBombsFrameStep;
    /* 148 */ s32 mThrowBombsFrameIndex;
    /* 14c */ s32 mRingRadius;
    /* 150 */ s32 mRingOffsetY;
    /* 154 */ s32 mRingRadiusCounterNonZero;
    /* 158 */ s32 mRingOffsetYCounterNonZero;
    /* 15c */ s32 mRingBombTimer;
    /* 160 */ s32 mRingParkedBombTimer;
    /* 164 */ s32 mBounceAnimationEntry;
    /* 168 */ s32 mBounceFrameStep;
    /* 16c */ s32 mHitPushScale;
    /* 170 */ s32 mHitVelocityY;
    /* 174 */ s32 mStoppedAnimationEntry;
    /* 178 */ s32 mStoppedFrameStep;
    /* 17c */ s32 mJumpCycleAnimationEntry;
    /* 180 */ s32 mJumpCycleFrameStep;
    /* 184 */ s32 mJumpCycleSpeedTarget;
    /* 188 */ s32 mJumpCycleSpeedPerCall;
    /* 18c */ s32 mJumpCycleAnglePerCallTarget;
    /* 190 */ s32 mJumpCycleAnglePerCallIncrement;
    /* 194 */ s32 mJumpCycleFrameCount;
    /* 198 */ s32 mJumpWaitAnimationEntry;
    /* 19c */ s32 mJumpWaitFrameStep;
    /* 1a0 */ s32 mJumpWaitFrameCount;
    /* 1a4 */ u8 mUnk_1a4[0x4];
    /* 1a8 */ s32 mJumpAnimationEntry;
    /* 1ac */ s32 mJumpFrameStep;
    /* 1b0 */ s32 mJumpSpeedTarget;
    /* 1b4 */ s32 mJumpSpeedPerCall;
    /* 1b8 */ s32 mJumpVelocityY;
    /* 1bc */ s32 mJumpFrameCount;
    /* 1c0 */ s32 mJumpToEntryAnimationEntry;
    /* 1c4 */ s32 mJumpToEntryFrameStep;
    /* 1c8 */ s32 mJumpToEntrySpeedTarget;
    /* 1cc */ s32 mJumpToEntrySpeedPerCall;
    /* 1d0 */ s32 mJumpToEntryAnglePerCallTarget;
    /* 1d4 */ s32 mJumpToEntryAnglePerCallIncrement;
    /* 1d8 */ s32 mJumpToEntryFrameCount;
    /* 1dc */ s32 mJumpThrowBombsAnimationEntry;
    /* 1e0 */ s32 mJumpThrowBombsFrameStep;
    /* 1e4 */ s32 mJumpRingRadius;
    /* 1e8 */ s32 mJumpRingBombTimer;
    /* 1ec */ u32 mJumpRingParkedBombTimer;
    /* 1f0 */ s32 mJumpThrowBombsFrameCount;
    /* 1f4 */ s32 mJumpFallAnimationEntry;
    /* 1f8 */ s32 mJumpFallFrameStep;
    /* 1fc */ s32 mJumpFallVelocityY;
    /* 200 */ s32 mJumpLandAnimationEntry;
    /* 204 */ s32 mJumpLandFrameStep;
    /* 208 */ s32 mRandomLimit;
    /* 20c */ s32 mCollisionExtentY;
} BombKingPrm;

// The parameters of a Donketu mission run map object: animation entries, speeds and angles for its walk, chase, jumps,
// kart hits and its water sink, walk and jump.
typedef struct DonketuPrm {
    /* 000 */ MissionRunPrmHead mHead;
    /* 070 */ s32 mKartNotEliminatedAnimationEntry;
    /* 074 */ s32 mKartNotEliminatedFrameStep;
    /* 078 */ s32 mKartEliminatedAnimationEntry;
    /* 07c */ s32 mKartEliminatedFrameStep;
    /* 080 */ s32 mChaseRunAtStartAnimationEntry;
    /* 084 */ s32 mChaseRunAtStartFrameStep;
    /* 088 */ s32 mChaseRunAtStartSpeedTarget;
    /* 08c */ s32 mChaseRunAtStartSpeedPerCall;
    /* 090 */ s32 mChaseRunAtStartFrameCount;
    /* 094 */ u8 mUnk_094[0x8];
    /* 09c */ s32 mWalkToNextEntryAnimationEntry;
    /* 0a0 */ s32 mWalkToNextEntryFrameStep;
    /* 0a4 */ s32 mWalkToNextEntrySpeed;
    /* 0a8 */ s32 mWalkToNextEntryAnglePerCall;
    /* 0ac */ s32 mWalkRangeRadius;
    /* 0b0 */ s32 mWalkRangeHalfAngle;
    /* 0b4 */ u8 mUnk_0b4[0x4];
    /* 0b8 */ s32 mWalkInRangeAnimationEntry;
    /* 0bc */ s32 mWalkInRangeFrameStep;
    /* 0c0 */ s32 mWalkInRangeSpeed;
    /* 0c4 */ s32 mWalkInRangeAnglePerCall;
    /* 0c8 */ s32 mWalkInRangeFrameCount;
    /* 0cc */ s32 mChaseKartAnimationEntry;
    /* 0d0 */ s32 mChaseKartFrameStep;
    /* 0d4 */ s32 mChaseKartSpeed;
    /* 0d8 */ s32 mChaseKartAnglePerCall;
    /* 0dc */ s32 mChaseKartRadius;
    /* 0e0 */ s32 mChaseKartHalfAngle;
    /* 0e4 */ s32 mChaseKartWaitHalfAngle;
    /* 0e8 */ s32 mChaseWaitAnimationEntry;
    /* 0ec */ s32 mChaseWaitFrameStep;
    /* 0f0 */ s32 mChaseWaitFrameCount;
    /* 0f4 */ s32 mChaseRunAnimationEntry;
    /* 0f8 */ s32 mChaseRunFrameStep;
    /* 0fc */ s32 mChaseRunSpeedTarget;
    /* 100 */ s32 mChaseRunSpeedPerCall;
    /* 104 */ s32 mChaseRunFrameCount;
    /* 108 */ s32 mChaseStopCollisionSpeed;
    /* 10c */ s32 mChaseStopAnimationEntry;
    /* 110 */ s32 mChaseStopFrameStep;
    /* 114 */ s32 mChaseStopSpeedPerCall;
    /* 118 */ s32 mChaseStopAnglePerCall;
    /* 11c */ s32 mRepeatJumpAnimationEntry;
    /* 120 */ s32 mRepeatJumpFrameStep;
    /* 124 */ s32 mRepeatJumpVelocityY;
    /* 128 */ s32 mRepeatJumpCount;
    /* 12c */ s32 mJumpWaitAnimationEntry;
    /* 130 */ s32 mJumpWaitFrameStep;
    /* 134 */ s32 mJumpWaitFrameCount;
    /* 138 */ s32 mJumpKartRadius;
    /* 13c */ s32 mJumpKartHalfAngle;
    /* 140 */ s32 mJumpKartFacingRadius;
    /* 144 */ s32 mJumpKartFacingHalfAngle;
    /* 148 */ s32 mJumpMinAbsoluteCounter;
    /* 14c */ s32 mJumpAnimationEntry;
    /* 150 */ s32 mJumpFrameStep;
    /* 154 */ s32 mJumpVelocityY;
    /* 158 */ s32 mJumpAnglePerCall;
    /* 15c */ u8 mUnk_15c[0x4];
    /* 160 */ s32 mJumpLandAnimationEntry;
    /* 164 */ s32 mJumpLandFrameStep;
    /* 168 */ s32 mWalkToCourseMapRowAnimationEntry;
    /* 16c */ s32 mWalkToCourseMapRowFrameStep;
    /* 170 */ s32 mWalkToCourseMapRowSpeedPerCall;
    /* 174 */ s32 mWalkToCourseMapRowSpeedTarget;
    /* 178 */ s32 mWalkToCourseMapRowAnglePerCall;
    /* 17c */ s32 mWalkToCourseMapRowFrameCount;
    /* 180 */ s32 mCourseMapRowRadius;
    /* 184 */ s32 mChaseHitNotBoostedAnimationEntry;
    /* 188 */ s32 mChaseHitNotBoostedFrameStep;
    /* 18c */ s32 mChaseHitNotBoostedVelocityY;
    /* 190 */ s32 mChaseHitNotBoostedHorizontalSpeed;
    /* 194 */ s32 mChaseHitNotBoostedAnglePerCall;
    /* 198 */ u8 mUnk_198[0x4];
    /* 19c */ s32 mChaseHitNotBoostedPosStep;
    /* 1a0 */ s32 mChaseHitBoostedAnimationEntry;
    /* 1a4 */ s32 mChaseHitBoostedFrameStep;
    /* 1a8 */ s32 mChaseHitBoostedVelocityY;
    /* 1ac */ s32 mChaseHitBoostedHorizontalSpeed;
    /* 1b0 */ s32 mChaseHitBoostedAnglePerCall;
    /* 1b4 */ u8 mUnk_1b4[0x4];
    /* 1b8 */ s32 mChaseHitBoostedPosStep;
    /* 1bc */ s32 mHitNotBoostedAnimationEntry;
    /* 1c0 */ s32 mHitNotBoostedFrameStep;
    /* 1c4 */ s32 mHitNotBoostedVelocityY;
    /* 1c8 */ s32 mHitNotBoostedKartVelocityScale;
    /* 1cc */ s32 mHitNotBoostedAnglePerCall;
    /* 1d0 */ u8 mUnk_1d0[0x4];
    /* 1d4 */ s32 mHitBoostedAnimationEntry;
    /* 1d8 */ s32 mHitBoostedFrameStep;
    /* 1dc */ s32 mHitBoostedVelocityY;
    /* 1e0 */ s32 mHitBoostedKartVelocityScale;
    /* 1e4 */ s32 mHitBoostedAnglePerCall;
    /* 1e8 */ u8 mUnk_1e8[0x4];
    /* 1ec */ u32 mHitRepeatJumpAnimationEntry;
    /* 1f0 */ s32 mHitRepeatJumpFrameStep;
    /* 1f4 */ s32 mHitRepeatJumpVelocityY;
    /* 1f8 */ s32 mHitRepeatJumpCount;
    /* 1fc */ s32 mWaterSinkAnimationEntry;
    /* 200 */ s32 mWaterSinkFrameStep;
    /* 204 */ s32 mWaterSinkHorizontalSpeed;
    /* 208 */ s32 mWaterSinkDescentSpeed;
    /* 20c */ s32 mWaterSinkFrameCount;
    /* 210 */ s32 mWaterWalkAnimationEntry;
    /* 214 */ s32 mWaterWalkFrameStep;
    /* 218 */ s32 mWaterWalkSpeed;
    /* 21c */ s32 mWaterWalkAnglePerCall;
    /* 220 */ s32 mWaterWalkFrameCount;
    /* 224 */ s32 mWaterJumpAnimationEntry;
    /* 228 */ s32 mWaterJumpFrameStep;
    /* 22c */ u8 mUnk_22c[0x4];
    /* 230 */ s32 mWaterJumpSpeedTarget;
    /* 234 */ s32 mWaterJumpSpeedPerCall;
    /* 238 */ s32 mWaterJumpVelocityY;
    /* 23c */ s32 mWaterLandAnimationEntry;
    /* 240 */ s32 mWaterLandFrameStep;
} DonketuPrm;

// The parameters of a Hanachan mission run map object: animation entries, its move speed and angle steps, speed
// reductions by balloon count, its four followers and its two kart ranges.
typedef struct HanachanPrm {
    /* 000 */ MissionRunPrmHead mHead;
    /* 070 */ s32 mKartNotEliminatedAnimationEntry;
    /* 074 */ s32 mKartNotEliminatedFrameStep;
    /* 078 */ s32 mKartEliminatedAnimationEntry;
    /* 07c */ s32 mKartEliminatedFrameStep;
    /* 080 */ u8 mUnk_080[0x8];
    /* 088 */ s32 mMoveAnimationEntry;
    /* 08c */ s32 mMoveFrameStep;
    /* 090 */ s32 mMoveSpeedTarget;
    /* 094 */ s32 mMoveSpeedPerCall;
    /* 098 */ s32 mMoveAnglePerCallTarget;
    /* 09c */ s32 mMoveAnglePerCallIncrement;
    /* 0a0 */ s32 mMoveRangeRadius;
    /* 0a4 */ u8 mUnk_0a4[0x4];
    /* 0a8 */ s32 mTwoBalloonSpeedReduction;
    /* 0ac */ s32 mOneBalloonSpeedReduction;
    /* 0b0 */ u8 mUnk_0b0[0x10];
    /* 0c0 */ s32 mFollowerFirstDistance;
    /* 0c4 */ s32 mFollowerSecondDistance;
    /* 0c8 */ s32 mFollowerThirdDistance;
    /* 0cc */ s32 mFollowerFourthDistance;
    /* 0d0 */ s32 mFollowerAnimationFrameOffset;
    /* 0d4 */ s32 mFollowerAnglePerCall;
    /* 0d8 */ s32 mFollowerTurnDelay;
    /* 0dc */ s32 mFollowerFirstCollisionOffsetY;
    /* 0e0 */ u8 mUnk_0e0[0x4];
    /* 0e4 */ s32 mFollowerSecondCollisionOffsetY;
    /* 0e8 */ u8 mUnk_0e8[0x4];
    /* 0ec */ s32 mFollowerThirdCollisionOffsetY;
    /* 0f0 */ u8 mUnk_0f0[0x4];
    /* 0f4 */ s32 mFollowerFourthCollisionOffsetY;
    /* 0f8 */ u8 mUnk_0f8[0x4];
    /* 0fc */ s32 mStarHitSideSpeed;
    /* 100 */ s32 mCollisionRadius;
    /* 104 */ s32 mSecondKartRangeAnimationEntry;
    /* 108 */ s32 mSecondKartRangeFrameStep;
    /* 10c */ s32 mSecondKartRangeAngleOffset;
    /* 110 */ s32 mSecondKartRangeRadius;
    /* 114 */ s32 mSecondKartRangeHalfAngle;
    /* 118 */ s32 mFirstKartRangeAnimationEntry;
    /* 11c */ s32 mFirstKartRangeFrameStep;
    /* 120 */ s32 mFirstKartRangeAngleOffset;
    /* 124 */ s32 mFirstKartRangeRadius;
    /* 128 */ s32 mFirstKartRangeHalfAngle;
    /* 12c */ s32 mKartRangeCooldown;
    /* 130 */ s32 mKartRangeSpeedPercentReduction;
} HanachanPrm;

// The parameters of an Iwante mission run map object: animation entries, speeds and frame counts for its moves, falls
// and landings, the chain camera offset, its hands and item hit reactions.
typedef struct IwantePrm {
    /* 000 */ MissionRunPrmHead mHead;
    /* 070 */ s32 mHideAtEndReachedAnimationEntry;
    /* 074 */ s32 mHideAtEndReachedFrameStep;
    /* 078 */ s32 mKartEliminatedHoldAnimationEntry;
    /* 07c */ s32 mKartEliminatedHoldFrameStep;
    /* 080 */ s32 mChainCameraPosYOffset;
    /* 084 */ u8 mUnk_084[0x4];
    /* 088 */ s32 mItemHitHalfAngle;
    /* 08c */ s32 mTurnToKartAnimationEntry;
    /* 090 */ s32 mTurnToKartFrameStep;
    /* 094 */ s32 mTurnToKartSpeedTarget;
    /* 098 */ s32 mTurnToKartSpeedPerCall;
    /* 09c */ u8 mUnk_09c[0x8];
    /* 0a4 */ s32 mTurnToKartVelocityY;
    /* 0a8 */ s32 mTurnToKartFrameCount;
    /* 0ac */ u8 mUnk_0ac[0x24];
    /* 0d0 */ s32 mMoveToKartAnimationEntry;
    /* 0d4 */ s32 mMoveToKartFrameStep;
    /* 0d8 */ s32 mMoveToKartSpeedTarget;
    /* 0dc */ s32 mMoveToKartSpeedPerCall;
    /* 0e0 */ u8 mUnk_0e0[0x8];
    /* 0e8 */ s32 mMoveToKartPointRadius;
    /* 0ec */ s32 mFallDelayFrameCount;
    /* 0f0 */ s32 mFallOnKartAnimationEntry;
    /* 0f4 */ s32 mFallOnKartFrameStep;
    /* 0f8 */ s32 mFallOnKartSpeedTarget;
    /* 0fc */ s32 mFallOnKartSpeedPerCall;
    /* 100 */ u8 mUnk_100[0x8];
    /* 108 */ s32 mFallOnKartVelocityY;
    /* 10c */ s32 mLandOnKartAnimationEntry;
    /* 110 */ s32 mLandOnKartFrameStep;
    /* 114 */ s32 mLandOnKartFrameCount;
    /* 118 */ s32 mLandBeforeSidewaysAnimationEntry;
    /* 11c */ s32 mLandBeforeSidewaysFrameStep;
    /* 120 */ s32 mLandBeforeSidewaysFrameCount;
    /* 124 */ u8 mUnk_124[0x4];
    /* 128 */ s32 mMoveSidewaysAnimationEntry;
    /* 12c */ s32 mMoveSidewaysFrameStep;
    /* 130 */ s32 mMoveSidewaysSpeedTarget;
    /* 134 */ s32 mMoveSidewaysSpeedPerCall;
    /* 138 */ u8 mUnk_138[0x8];
    /* 140 */ s32 mMoveSidewaysFrameCount;
    /* 144 */ s32 mKartHitCarryVelocity;
    /* 148 */ s32 mSidewaysStopAnimationEntry;
    /* 14c */ s32 mSidewaysStopFrameStep;
    /* 150 */ s32 mSidewaysStopSpeedTarget;
    /* 154 */ s32 mSidewaysStopSpeedPerCall;
    /* 158 */ u8 mUnk_158[0x8];
    /* 160 */ s32 mSidewaysStopFrameCount;
    /* 164 */ s32 mMoveToPointsAnimationEntry;
    /* 168 */ s32 mMoveToPointsFrameStep;
    /* 16c */ s32 mMoveToPointsSpeedTarget;
    /* 170 */ s32 mMoveToPointsSpeedPerCall;
    /* 174 */ s32 mMoveToPointsMoveAnglePerCallTarget;
    /* 178 */ s32 mMoveToPointsMoveAnglePerCallIncrement;
    /* 17c */ s32 mMoveToPointsVelocityY;
    /* 180 */ s32 mMoveToPointsFrameCount;
    /* 184 */ s32 mReachAnimationEntry;
    /* 188 */ s32 mReachFrameStep;
    /* 18c */ s32 mReachSpeedTarget;
    /* 190 */ s32 mReachSpeedPerCall;
    /* 194 */ s32 mReachMoveAnglePerCallTarget;
    /* 198 */ s32 mReachMoveAnglePerCallIncrement;
    /* 19c */ s32 mReachPointRadius;
    /* 1a0 */ u8 mUnk_1a0[0x4];
    /* 1a4 */ s32 mFallAnimationEntry;
    /* 1a8 */ s32 mFallFrameStep;
    /* 1ac */ s32 mFallSpeedTarget;
    /* 1b0 */ s32 mFallSpeedPerCall;
    /* 1b4 */ s32 mFallMoveAnglePerCallTarget;
    /* 1b8 */ s32 mFallMoveAnglePerCallIncrement;
    /* 1bc */ s32 mFallVelocityY;
    /* 1c0 */ s32 mLandAnimationEntry;
    /* 1c4 */ s32 mLandFrameStep;
    /* 1c8 */ s32 mLandFrameCount;
    /* 1cc */ s32 mDirectFallOnKartAnimationEntry;
    /* 1d0 */ s32 mDirectFallOnKartFrameStep;
    /* 1d4 */ s32 mDirectFallOnKartSpeedTarget;
    /* 1d8 */ s32 mDirectFallOnKartSpeedPerCall;
    /* 1dc */ u8 mUnk_1dc[0x8];
    /* 1e4 */ s32 mDirectFallOnKartVelocityY;
    /* 1e8 */ u8 mUnk_1e8[0x4];
    /* 1ec */ u32 mHandsRepeatCount;
    /* 1f0 */ u8 mUnk_1f0[0x20];
    /* 210 */ s32 mLandOnKartAndStopAnimationEntry;
    /* 214 */ s32 mLandOnKartAndStopFrameStep;
    /* 218 */ s32 mLandOnKartAndStopFrameCount;
    /* 21c */ s32 mHitReactionAnimationEntry;
    /* 220 */ s32 mHitReactionFrameStep;
    /* 224 */ s32 mItemHitVelocity;
    /* 228 */ s32 mItemHitVelocityY;
    /* 22c */ s32 mHitSecondAnimationEntry;
    /* 230 */ s32 mHitSecondFrameStep;
    /* 234 */ s32 mHitThirdAnimationEntry;
    /* 238 */ s32 mHitThirdFrameStep;
    /* 23c */ s32 mHitReactionHoldAnimationEntry;
    /* 240 */ s32 mHitReactionHoldFrameStep;
    /* 244 */ u8 mUnk_244[0x8];
    /* 24c */ s32 mHitHoldAnimationEntry;
    /* 250 */ s32 mHitHoldFrameStep;
    /* 254 */ s32 mWalkWithEffectsAnimationEntry;
    /* 258 */ s32 mWalkWithEffectsFrameStep;
    /* 25c */ u8 mUnk_25c[0x10];
    /* 26c */ s32 mApproachAngleOffset;
    /* 270 */ s32 mApproachPointRadius;
    /* 274 */ s32 mHandsAnglePointDistance;
    /* 278 */ s32 mHandsMovePointDistance;
    /* 27c */ s32 mWalkAnimationEntry;
    /* 280 */ s32 mWalkFrameStep;
    /* 284 */ u8 mUnk_284[0x8];
    /* 28c */ s32 mWalkBAnimationEntry;
    /* 290 */ s32 mWalkBFrameStep;
    /* 294 */ s32 mWalkAAnimationEntry;
    /* 298 */ s32 mWalkAFrameStep;
    /* 29c */ s32 mMoveVerticalAnimationEntry;
    /* 2a0 */ s32 mMoveVerticalFrameStep;
    /* 2a4 */ s32 mMoveVerticalVelocityY;
    /* 2a8 */ s32 mMoveVerticalFrameCount;
    /* 2ac */ s32 mChangeToWalkBAnimationEntry;
    /* 2b0 */ s32 mChangeToWalkBFrameStep;
    /* 2b4 */ s32 mChangeToWalkAAnimationEntry;
    /* 2b8 */ s32 mChangeToWalkAFrameStep;
    /* 2bc */ u32 mApproachKartObjectRadius;
    /* 2c0 */ u32 mApproachKartHandRadius;
    /* 2c4 */ u32 mHandsTurnPerCallTarget;
    /* 2c8 */ s32 mWalkTurnPerCallTarget;
    /* 2cc */ s32 mWalkSpeedTarget;
} IwantePrm;

// The parameters of a King Teresa mission run map object: animation entries, speeds and alpha limits for waiting,
// approaching, moving to a forward point and group entry, hit reaction, boss coins, show and hide, and its mission run
// timer values.
typedef struct KingTeresaPrm {
    /* 000 */ MissionRunPrmHead mHead;
    /* 070 */ s32 mWinnerDecidedAnimationEntry;
    /* 074 */ s32 mWinnerDecidedFrameStep;
    /* 078 */ s32 mKartEliminatedAnimationEntry;
    /* 07c */ s32 mKartEliminatedFrameStep;
    /* 080 */ s32 mPosOffsetY;
    /* 084 */ s32 mSinkMinOffsetY;
    /* 088 */ s32 mSinkStepY;
    /* 08c */ u8 mUnk_08c[0x4];
    /* 090 */ s32 mWaitToApproachAnimationEntry;
    /* 094 */ s32 mWaitToApproachFrameStep;
    /* 098 */ u8 mUnk_098[0x4];
    /* 09c */ s32 mWaitToApproachAlphaLimitPerCall;
    /* 0a0 */ s32 mWaitToApproachSpeed;
    /* 0a4 */ u8 mUnk_0a4[0x4];
    /* 0a8 */ s32 mWaitToApproachMoveAnglePerCallTarget;
    /* 0ac */ u8 mUnk_0ac[0x4];
    /* 0b0 */ s32 mWaitToApproachAnglePerCallTarget;
    /* 0b4 */ u8 mUnk_0b4[0x4];
    /* 0b8 */ s32 mWaitToApproachKartRadius;
    /* 0bc */ s32 mApproachFacingHalfAngle;
    /* 0c0 */ s32 mWaitToApproachMoveAngleOffset;
    /* 0c4 */ s32 mApproachAnimationEntry;
    /* 0c8 */ s32 mApproachFrameStep;
    /* 0cc */ s32 mApproachAlphaLimitTarget;
    /* 0d0 */ s32 mApproachAlphaLimitPerCall;
    /* 0d4 */ s32 mApproachSpeedTarget;
    /* 0d8 */ s32 mApproachSpeedPerCall;
    /* 0dc */ s32 mApproachAnglePerCallTarget;
    /* 0e0 */ s32 mApproachAnglePerCallIncrement;
    /* 0e4 */ s32 mApproachPointRadius;
    /* 0e8 */ s32 mApproachKartDistance;
    /* 0ec */ s32 mMoveToForwardPointAnimationEntry;
    /* 0f0 */ s32 mMoveToForwardPointFrameStep;
    /* 0f4 */ s32 mMoveToForwardPointAlphaLimitTarget;
    /* 0f8 */ s32 mMoveToForwardPointAlphaLimitPerCall;
    /* 0fc */ s32 mMoveToForwardPointSpeedTarget;
    /* 100 */ s32 mMoveToForwardPointSpeedPerCall;
    /* 104 */ s32 mMoveToForwardPointAnglePerCallTarget;
    /* 108 */ s32 mMoveToForwardPointAnglePerCallIncrement;
    /* 10c */ u8 mUnk_10c[0x4];
    /* 110 */ s32 mBossTransferAmount;
    /* 114 */ s32 mBossTransferPosStepY;
    /* 118 */ s32 mMoveToGroupEntryAnimationEntry;
    /* 11c */ s32 mMoveToGroupEntryFrameStep;
    /* 120 */ s32 mMoveToGroupEntryAlphaLimitTarget;
    /* 124 */ s32 mMoveToGroupEntryAlphaLimitPerCall;
    /* 128 */ s32 mMoveToGroupEntryStage1SpeedTarget;
    /* 12c */ s32 mMoveToGroupEntryStage1SpeedPerCall;
    /* 130 */ s32 mMoveToGroupEntryStage1AnglePerCallTarget;
    /* 134 */ s32 mMoveToGroupEntryStage1AnglePerCallIncrement;
    /* 138 */ s32 mMoveToGroupEntryPointRadius;
    /* 13c */ s32 mMoveToGroupEntryPointHalfAngle;
    /* 140 */ s32 mNextGroupSpan;
    /* 144 */ s32 mHitReactionAnimationEntry;
    /* 148 */ s32 mHitReactionFrameStep;
    /* 14c */ s32 mHitReactionAlphaLimitTarget;
    /* 150 */ s32 mHitReactionAlphaLimitPerCall;
    /* 154 */ s32 mHitReactionSpeedTarget;
    /* 158 */ s32 mHitReactionSpeedPerCall;
    /* 15c */ s32 mHitReactionAnglePerCallTarget;
    /* 160 */ s32 mHitReactionAnglePerCallIncrement;
    /* 164 */ s32 mHitReactionFrameCount;
    /* 168 */ s32 mStopForBossCoinsAnimationEntry;
    /* 16c */ s32 mStopForBossCoinsFrameStep;
    /* 170 */ s32 mShowBossCoinsAnimationEntry;
    /* 174 */ s32 mShowBossCoinsFrameStep;
    /* 178 */ s32 mShowBossCoinsAlphaLimitTarget;
    /* 17c */ s32 mShowBossCoinsAlphaLimitPerCall;
    /* 180 */ s32 mStopKartFacingHalfAngle;
    /* 184 */ s32 mStopKartInRangeHalfAngle;
    /* 188 */ s32 mStopKartInRangeRadius;
    /* 18c */ s32 mShowBossCoinsShownCountMax;
    /* 190 */ s32 mParkBossCoinCount;
    /* 194 */ s32 mShowBossCoinsFrameCount;
    /* 198 */ s32 mShowHideAnimationEntry;
    /* 19c */ s32 mShowHideFrameStep;
    /* 1a0 */ s32 mHideAlphaLimitTarget;
    /* 1a4 */ s32 mHideAlphaLimitPerCall;
    /* 1a8 */ s32 mHideFrameCount;
    /* 1ac */ s32 mShowAlphaLimitTarget;
    /* 1b0 */ s32 mShowAlphaLimitPerCall;
    /* 1b4 */ s32 mShowFrameCount;
    /* 1b8 */ s32 mTimerStart;
    /* 1bc */ s32 mTimerMax;
    /* 1c0 */ s32 mTimerCountUpAdd;
    /* 1c4 */ s32 mTimerBossTransferAdd;
    /* 1c8 */ s32 mShowNearKartTimerLimit;
    /* 1cc */ s32 mWaitToApproachEndTimer;
    /* 1d0 */ s32 mApproachTimerLimit;
    /* 1d4 */ s32 mWaitToApproachAlphaLimitDivisor;
    /* 1d8 */ s32 mTurnTowardKartAnimationEntry;
    /* 1dc */ s32 mTurnTowardKartFrameStep;
    /* 1e0 */ s32 mTurnTowardKartSpeedTarget;
    /* 1e4 */ s32 mTurnTowardKartSpeedPerCall;
    /* 1e8 */ s32 mTurnTowardKartAnglePerCallTarget;
    /* 1ec */ s32 mTurnTowardKartAnglePerCallIncrement;
    /* 1f0 */ s32 mTurnTowardKartFrameCount;
    /* 1f4 */ s32 mCoinsFadeOutAnimationEntry;
    /* 1f8 */ s32 mCoinsFadeOutFrameStep;
    /* 1fc */ s32 mTurnAwayAnimationEntry;
    /* 200 */ s32 mTurnAwayFrameStep;
    /* 204 */ s32 mTurnAwaySpeedTarget;
    /* 208 */ s32 mTurnAwaySpeedPerCall;
    /* 20c */ s32 mTurnAwayAnglePerCallTarget;
    /* 210 */ s32 mTurnAwayAnglePerCallIncrement;
    /* 214 */ s32 mTurnAwayFrameCount;
    /* 218 */ s32 mMoveToForwardPointPointRadius;
    /* 21c */ s32 mForwardPointDistance;
    /* 220 */ s32 mMoveToGroupEntryStage2SpeedTarget;
    /* 224 */ s32 mMoveToGroupEntryStage2SpeedPerCall;
    /* 228 */ s32 mMoveToGroupEntryStage2AnglePerCallTarget;
    /* 22c */ s32 mMoveToGroupEntryStage2AnglePerCallIncrement;
    /* 230 */ s32 mMoveToGroupEntryStage3SpeedTarget;
    /* 234 */ s32 mMoveToGroupEntryStage3SpeedPerCall;
    /* 238 */ s32 mMoveToGroupEntryStage3AnglePerCallTarget;
    /* 23c */ s32 mMoveToGroupEntryStage3AnglePerCallIncrement;
    /* 240 */ s32 mCollisionExtentY;
} KingTeresaPrm;

// The parameters of a Kuriking mission run map object: animation entries, speeds and angles for its walk, grow, chase,
// face kart, turn to entry and row, bomb and kinoko throws, and jump.
typedef struct KurikingPrm {
    /* 000 */ MissionRunPrmHead mHead;
    /* 070 */ s32 mKartNotEliminatedAnimationEntry;
    /* 074 */ s32 mKartNotEliminatedFrameStep;
    /* 078 */ s32 mChaseKartAnimationEntry;
    /* 07c */ s32 mChaseKartFrameStep;
    /* 080 */ s32 mStartupNsbtaEntryIndex;
    /* 084 */ u8 mUnk_084[0x14];
    /* 098 */ s32 mWalkAnimationEntry;
    /* 09c */ s32 mWalkFrameStep;
    /* 0a0 */ s32 mWalkNsbtaEntryIndex;
    /* 0a4 */ s32 mWalkCounterZeroSpeedTarget;
    /* 0a8 */ s32 mWalkCounterZeroSpeedPerCall;
    /* 0ac */ s32 mWalkCounterZeroAnglePerCallTarget;
    /* 0b0 */ s32 mWalkCounterZeroAnglePerCallIncrement;
    /* 0b4 */ s32 mWalkPointRadius;
    /* 0b8 */ s32 mWalkFrameCount;
    /* 0bc */ s32 mWalkCounterOneSpeedTarget;
    /* 0c0 */ s32 mWalkCounterOneSpeedPerCall;
    /* 0c4 */ s32 mWalkCounterOneAnglePerCallTarget;
    /* 0c8 */ s32 mWalkCounterOneAnglePerCallIncrement;
    /* 0cc */ s32 mWalkCounterOtherSpeedTarget;
    /* 0d0 */ s32 mWalkCounterOtherSpeedPerCall;
    /* 0d4 */ s32 mWalkCounterOtherAnglePerCallTarget;
    /* 0d8 */ s32 mWalkCounterOtherAnglePerCallIncrement;
    /* 0dc */ s32 mGrowAnimationEntry;
    /* 0e0 */ s32 mGrowFrameStep;
    /* 0e4 */ s32 mGrowNsbtaEntryIndex;
    /* 0e8 */ s32 mGrowSpeedTarget;
    /* 0ec */ s32 mGrowSpeedPerCall;
    /* 0f0 */ s32 mGrowAnglePerCallTarget;
    /* 0f4 */ s32 mGrowAnglePerCallIncrement;
    /* 0f8 */ s32 mGrowScaleIncrease;
    /* 0fc */ s32 mGrowScalePerCall;
    /* 100 */ s32 mGrowFrameCount;
    /* 104 */ s32 mKartInRangeAnimationEntry;
    /* 108 */ s32 mKartInRangeFrameStep;
    /* 10c */ s32 mKartInRangeNsbtaEntryIndex;
    /* 110 */ s32 mKartInRangeSpeedTarget;
    /* 114 */ s32 mKartInRangeSpeedPerCall;
    /* 118 */ s32 mKartInRangeAnglePerCallTarget;
    /* 11c */ s32 mKartInRangeAnglePerCallIncrement;
    /* 120 */ u8 mUnk_120[0x4];
    /* 124 */ s32 mKartRadius;
    /* 128 */ s32 mKartHalfAngle;
    /* 12c */ s32 mKartInRangeFrameCount;
    /* 130 */ s32 mKartHitSpeed;
    /* 134 */ s32 mFaceKartAnimationEntry;
    /* 138 */ s32 mFaceKartFrameStep;
    /* 13c */ s32 mFaceKartNsbtaEntryIndex;
    /* 140 */ s32 mFaceKartSpeedTarget;
    /* 144 */ s32 mFaceKartSpeedPerCall;
    /* 148 */ s32 mFaceKartMoveAnglePerCallTarget;
    /* 14c */ s32 mFaceKartMoveAnglePerCallIncrement;
    /* 150 */ s32 mFaceKartAnglePerCallTarget;
    /* 154 */ s32 mFaceKartAnglePerCallIncrement;
    /* 158 */ s32 mFaceKartFrameCount;
    /* 15c */ s32 mTurnToEntryAnimationEntry;
    /* 160 */ s32 mTurnToEntryFrameStep;
    /* 164 */ s32 mTurnToEntryNsbtaEntryIndex;
    /* 168 */ s32 mTurnToEntrySpeedTarget;
    /* 16c */ s32 mTurnToEntrySpeedPerCall;
    /* 170 */ s32 mTurnToEntryMoveAnglePerCallTarget;
    /* 174 */ s32 mTurnToEntryMoveAnglePerCallIncrement;
    /* 178 */ s32 mTurnToEntryAnglePerCallTarget;
    /* 17c */ s32 mTurnToEntryAnglePerCallIncrement;
    /* 180 */ s32 mTurnToEntryFrameCount;
    /* 184 */ s32 mThrowBombsAnimationEntry;
    /* 188 */ s32 mThrowBombsFrameStep;
    /* 18c */ s32 mThrowBombsNsbtaEntryIndex;
    /* 190 */ s32 mThrowBombsFrameIndex;
    /* 194 */ s32 mThrowOffsetY;
    /* 198 */ s32 mThrowRadius;
    /* 19c */ s32 mThrowVelocityY;
    /* 1a0 */ s32 mThrowSpeed;
    /* 1a4 */ s32 mThrowAngleStep;
    /* 1a8 */ s32 mKinokoRandomLimit;
    /* 1ac */ s32 mThrowKinokoTimer;
    /* 1b0 */ s32 mThrowBombTimer;
    /* 1b4 */ s32 mTurnToRowAnimationEntry;
    /* 1b8 */ s32 mTurnToRowFrameStep;
    /* 1bc */ s32 mTurnToRowNsbtaEntryIndex;
    /* 1c0 */ s32 mTurnToRowSpeedTarget;
    /* 1c4 */ s32 mTurnToRowSpeedPerCall;
    /* 1c8 */ s32 mTurnToRowAnglePerCallTarget;
    /* 1cc */ s32 mTurnToRowAnglePerCallIncrement;
    /* 1d0 */ s32 mTurnToRowFrameCount;
    /* 1d4 */ s32 mJumpAnimationStateAnimationEntry;
    /* 1d8 */ s32 mJumpAnimationStateFrameStep;
    /* 1dc */ s32 mJumpAnimationStateNsbtaEntryIndex;
    /* 1e0 */ s32 mJumpAnimationEntry;
    /* 1e4 */ s32 mJumpFrameStep;
    /* 1e8 */ s32 mJumpNsbtaEntryIndex;
    /* 1ec */ u32 mJumpSpeedTarget;
    /* 1f0 */ s32 mJumpSpeedPerCall;
    /* 1f4 */ s32 mJumpVelocityY;
    /* 1f8 */ s32 mJumpLandAnimationEntry;
    /* 1fc */ s32 mJumpLandFrameStep;
    /* 200 */ s32 mJumpLandNsbtaEntryIndex;
    /* 204 */ s32 mChaseKartSpeedTarget;
    /* 208 */ s32 mChaseKartSpeedPerCall;
    /* 20c */ s32 mChaseKartAnglePerCallTarget;
    /* 210 */ s32 mChaseKartAnglePerCallIncrement;
    /* 214 */ s32 mCollisionExtentY;
} KurikingPrm;

// Parameter table of a map object (the .prm file): mPrm of MissionRunMapObject points to it and each object reads its
// own member. Object behind StopTurningMoveFollowsAngle and the per-state functions around StartIwanteHandsHitReaction.
typedef union MissionRunPrm {
    MissionRunPrmHead mHead;
    BombKingPrm mBombKing;
    DonketuPrm mDonketu;
    HanachanPrm mHanachan;
    IwantePrm mIwante;
    KingTeresaPrm mKingTeresa;
    KurikingPrm mKuriking;
} MissionRunPrm;

// Values of MissionRunMapObjectEffect.mKind: where ComputeEffectPosition puts the effect. Offsets are turned by the
// angle of the object; MODEL is the effect of a model started at the water height; the camera position is added in
// ROTATED_OFFSET_CAMERA (never set).
enum {
    MAP_OBJECT_EFFECT_MODEL,
    MAP_OBJECT_EFFECT_ROTATED_OFFSET,
    MAP_OBJECT_EFFECT_SCALED_OFFSET,
    MAP_OBJECT_EFFECT_ROTATED_OFFSET_CAMERA,
    MAP_OBJECT_EFFECT_ROW_HEIGHT,
    MAP_OBJECT_EFFECT_WATER_HEIGHT,
};

// One effect attached to a mission run map object: its kind, timer, offset and effect handle.
typedef struct MissionRunMapObjectEffect {
    /* 00 */ s32 mKind;
    /* 04 */ s32 mTimer;
    /* 08 */ Vec3 mOffset;
    /* 14 */ void *mEffect;
} MissionRunMapObjectEffect;

enum {
    MAP_OBJECT_ANGLE_NONE,
    MAP_OBJECT_ANGLE_FOLLOW_MOVE_ANGLE,
    MAP_OBJECT_ANGLE_TURN_TO_POINT,
    MAP_OBJECT_ANGLE_TURN_FROM_POINT,
    MAP_OBJECT_ANGLE_TURN_SIDEWAYS,
    MAP_OBJECT_ANGLE_SPIN,
    MAP_OBJECT_ANGLE_SPIN_CHOOSE_DIRECTION,
    MAP_OBJECT_ANGLE_SPIN_NEGATIVE,
    MAP_OBJECT_ANGLE_SPIN_POSITIVE,
};

// Values of mMoveAngleMode: how mMoveAngle changes. It stays, copies mAngle, or turns toward or away from
// mMoveAnglePoint (or sideways to it) by mMoveAnglePerCall.
enum {
    MAP_OBJECT_MOVE_ANGLE_KEEP,
    MAP_OBJECT_MOVE_ANGLE_FOLLOW_ANGLE,
    MAP_OBJECT_MOVE_ANGLE_TURN_TO_POINT,
    MAP_OBJECT_MOVE_ANGLE_TURN_FROM_POINT,
    MAP_OBJECT_MOVE_ANGLE_TURN_SIDEWAYS,
};

// Values of MissionRunMapObject.mShadowMode: where the shadow is drawn. The first two put it on the course map row of
// the object (the second when no height offset was given), AT_OBJECT at the position of the object, AT_NODE under the
// node position.
enum {
    MAP_OBJECT_SHADOW_COURSE_OFFSET,
    MAP_OBJECT_SHADOW_COURSE,
    MAP_OBJECT_SHADOW_AT_OBJECT,
    MAP_OBJECT_SHADOW_AT_NODE,
};

// Values of MissionRunMapObject.mCollisionShape: the body the kart and item hit tests use.
enum {
    MAP_OBJECT_COLLISION_SPHERE,
    MAP_OBJECT_COLLISION_BOX,
    MAP_OBJECT_COLLISION_CYLINDER,
};

// Values of MissionRunMapObject.mCourseCollisionMode: how the object is moved out of the course. ALT_FILTER uses the
// other course collision filter; PUSH_Y_ONLY moves it only up or down and PUSH_Y_ONLY_NO_BITS also skips the checks of
// the collision bits.
enum {
    MAP_OBJECT_COURSE_COLLISION_PUSH_OUT,
    MAP_OBJECT_COURSE_COLLISION_ALT_FILTER,
    MAP_OBJECT_COURSE_COLLISION_PUSH_Y_ONLY_NO_BITS,
    MAP_OBJECT_COURSE_COLLISION_PUSH_Y_ONLY,
};

// Values of mKartResponse: the index into the kart's collision response table (gCollideKartWithMapObjectResponses).
enum {
    KART_MAP_OBJECT_RESPONSE_NONE = 0,
    KART_MAP_OBJECT_RESPONSE_BUMP = 2,
    KART_MAP_OBJECT_RESPONSE_FLIP_DOUBLE = 10,
    KART_MAP_OBJECT_RESPONSE_SCALE_EFFECT = 11,
    KART_MAP_OBJECT_RESPONSE_CARRY = 12,
    KART_MAP_OBJECT_RESPONSE_CARRY_HALT = 13,
    KART_MAP_OBJECT_RESPONSE_CARRY_SPIN = 14,
};

// Values of mItemResponse, which CollideItemWithMissionRunMapObject returns as the hit type of ApplyItemObjectHitType:
// the item bounces off the object, or is pushed away and fades out.
enum {
    ITEM_MAP_OBJECT_RESPONSE_BOUNCE = 1,
    ITEM_MAP_OBJECT_RESPONSE_PUSH_FADE_OUT = 2,
};

// Layout provisional: functions on objects that share this prefix use different types at 0xa0 and 0xa8.
typedef struct MissionRunMapObject MissionRunMapObject;
#include "01/MapObjects/mission_run_motion_setters.h"
typedef struct Kart Kart;
typedef struct ItemObject ItemObject;

typedef void (*MapObjectKartCollisionCallback)(MissionRunMapObject *mapObject, Kart *kart);
typedef void (*MapObjectItemCollisionCallback)(MissionRunMapObject *mapObject, ItemObject *itemObject);

// The bit of mCollisionBits the update sets when mPos.y is below 0; IsNotRisingWithBelowZeroBit tests it with a
// velocity that is not upward.
#define COURSE_HIT_GROUND 0x1e34ef
#define COURSE_HIT_WALL 0x214300
#define COURSE_HIT_NOT_RISING_BIT 0x800

// A mission run map object: the shared map object, its parameter block, state, speed, angle, callback, collision,
// shadow and timer members and five effects.
typedef struct MissionRunMapObject {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ MissionRunPrm *mPrm;
    /* 0a4 */ struct MissionRunMapObject *mPreviousObject;
    /* 0a8 */ union {
        s32 mHandShape;
        s32 mHandOrder;
        s32 mKartRangeCooldown;
        s32 mFollowerIndex;
        s32 mMoveStage;
    };
    /* 0ac */ s32 mCounter;
    /* 0b0 */ s32 mStateFrames;
    /* 0b4 */ s32 mRepeatsRemaining;
    /* 0b8 */ s32 mUnk_0b8;
    /* 0bc */ MissionRunMapObjectEffect mEffects[5];
    /* 134 */ s32 mModelAnimationFrameIndex;
    /* 138 */ s32 mThrowCount;
    /* 13c */ s32 mTurnDelayFrames;
    /* 140 */ s32 mEffectStepCounter;
    /* 144 */ s32 mSoundStepCounter;
    /* 148 */ s32 mEntryGroupIndex;
    /* 14c */ s32 mEntryIndex;
    /* 150 */ s32 mStateNumber;
    /* 154 */ s32 mUnk_154;
    /* 158 */ s32 (*mStateFunction)(struct MissionRunMapObject *);
    /* 15c */ s32 (*mNextStateFunction)(struct MissionRunMapObject *);
    /* 160 */ s32 mScaleTarget;
    /* 164 */ s32 mScalePerCall;
    /* 168 */ s32 mAlphaLimit;
    /* 16c */ s32 mAlphaLimitTarget;
    /* 170 */ s32 mAlphaLimitPerCall;
    /* 174 */ s32 mSpeed;
    /* 178 */ s32 mSpeedTarget;
    /* 17c */ s32 mSpeedPerCall;
    /* 180 */ s32 mAngleState;
    /* 184 */ s32 mAngle;
    /* 188 */ Vec3 mAnglePoint;
    /* 194 */ s32 mAnglePerCall;
    /* 198 */ s32 mAnglePerCallTarget;
    /* 19c */ s32 mAnglePerCallIncrement;
    /* 1a0 */ s32 mSidewaysAngleOffset;
    /* 1a4 */ s32 mMoveAngleMode;
    /* 1a8 */ s32 mMoveAngle;
    /* 1ac */ Vec3 mMoveAnglePoint;
    /* 1b8 */ s32 mMoveAnglePerCall;
    /* 1bc */ s32 mMoveAnglePerCallTarget;
    /* 1c0 */ s32 mMoveAnglePerCallIncrement;
    /* 1c4 */ s32 mMoveAngleOffset;
    /* 1c8 */ Vec3 mVelocity;
    /* 1d4 */ MapObjectCallback mAnimationEndCallback;
    /* 1d8 */ s32 mAnimationFrameCallbackFrameIndex;
    /* 1dc */ MapObjectCallback mAnimationFrameCallback;
    /* 1e0 */ s32 mFirstCallbackFrameIndex;
    /* 1e4 */ void (*mFirstFrameCallback)(struct MissionRunMapObject *);
    /* 1e8 */ s32 mSecondCallbackFrameIndex;
    /* 1ec */ void (*mSecondFrameCallback)(struct MissionRunMapObject *);
    /* 1f0 */ s32 mStateFrameCount;
    /* 1f4 */ MapObjectCallback mStateFrameCountCallback;
    /* 1f8 */ s32 mPointRadius;
    /* 1fc */ s32 mPointHalfAngle;
    /* 200 */ Vec3 mPoint;
    /* 20c */ MapObjectCallback mPointInRangeCallback;
    /* 210 */ s32 mOutOfRangeRadius;
    /* 214 */ s32 mOutOfRangeHalfAngle;
    /* 218 */ Vec3 mOutOfRangePoint;
    /* 224 */ MapObjectCallback mOutOfRangeCallback;
    /* 228 */ MapObjectCallback mStoppedCallback;
    /* 22c */ MapObjectCallback mCourseCollisionCallback;
    /* 230 */ MapObjectCallback mUnusedCallback;
    /* 234 */ s32 mCollisionShape;
    /* 238 */ Vec3 mPosWithOffset;
    /* 244 */ Vec3 mOffset;
    /* 250 */ s32 mOffsetTargetX;
    /* 254 */ s32 mOffsetTargetY;
    /* 258 */ s32 mOffsetTargetZ;
    /* 25c */ Vec3 mCollisionExtent;
    /* 268 */ s32 mCollisionExtentTargetX;
    /* 26c */ s32 mCollisionExtentTargetY;
    /* 270 */ s32 mCollisionExtentTargetZ;
    /* 274 */ s32 mOffsetPerCall;
    /* 278 */ s32 mCollisionExtentPerCall;
    /* 27c */ u32 mShadowMode;
    /* 280 */ s32 mShadowOffsetX;
    /* 284 */ s32 mShadowOffsetY;
    /* 288 */ s32 mShadowOffsetZ;
    /* 28c */ s32 mShadowOffsetTargetX;
    /* 290 */ s32 mShadowOffsetTargetY;
    /* 294 */ s32 mShadowOffsetTargetZ;
    /* 298 */ s32 mShadowScaleX;
    /* 29c */ s32 mShadowScaleY;
    /* 2a0 */ s32 mShadowScaleZ;
    /* 2a4 */ s32 mShadowScaleTargetX;
    /* 2a8 */ s32 mShadowScaleTargetY;
    /* 2ac */ s32 mShadowScaleTargetZ;
    /* 2b0 */ s32 mShadowOffsetPerCall;
    /* 2b4 */ s32 mShadowScalePerCall;
    /* 2b8 */ s32 mCourseCollisionMode;
    /* 2bc */ BOOL mBounceEnabled;
    /* 2c0 */ BOOL mGravityEnabled;
    /* 2c4 */ BOOL mKeepCallbacks;
    /* 2c8 */ u32 mCollisionBits;
    /* 2cc */ u8 mUnk_2cc[0x4];
    /* 2d0 */ s32 mTimer;
    /* 2d4 */ MapObjectKartCollisionCallback mKartCollisionCallback;
    /* 2d8 */ s32 mKartResponse;
    /* 2dc */ MapObjectItemCollisionCallback mItemCollisionCallback;
    /* 2e0 */ s32 mItemResponse;
    /* 2e4 */ s32 mNodeMatchValue;
    /* 2e8 */ Vec3 mNodePosition;
    /* 2f4 */ Vec3 mBombOffset;
    /* 300 */ void *mItemBomb;
    /* 304 */ struct MapObjectModel *mNsbmd;
    /* 308 */ struct MapObjectModel *mShadowNsbmd;
} MissionRunMapObject;

void SetVelocity(MissionRunMapObject *mapObject, Vec3 *velocity);
void SetAnglePoint(MissionRunMapObject *mapObject, Vec3 *point);
void SetMoveAnglePoint(MissionRunMapObject *mapObject, Vec3 *point);
void SetAnglePointAndMoveAnglePoint(MissionRunMapObject *mapObject, Vec3 *point);
void StopMoveAngleTurning(MissionRunMapObject *mapObject);
void TurnAndMoveToPointOwnRates(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                                s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement);
void SpinTowardPointMoveToPoint(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                                s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement);
void SpinAngleStopMoveAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement);
void TurnToPointMoveSideways(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                             s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement, s32 moveAngleOffset);
void TurnSidewaysMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                                  s32 angleOffset);
void StopTurningMoveFromPoint(MissionRunMapObject *mapObject, s32 moveAnglePerCallTarget,
                              s32 moveAnglePerCallIncrement);
void TurnFromPointMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement);
void TurnAndMoveToPointSameRate(MissionRunMapObject *mapObject, s32 perCallTarget, s32 perCallIncrement);
void TurnToPointMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement);
void StopTurningMoveFollowsAngle(MissionRunMapObject *mapObject);
