#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43
#include "code_02147cd8.h"

// Linked through mNext/mPrev; on the lists at ParticleEmitter 0x08 and 0x14 and SPLManager 0x1c.
typedef struct ParticleInstance {
    /* 00 */ struct ParticleInstance *mNext;
    /* 04 */ struct ParticleInstance *mPrev;
    /* 08 */ Vec3 mOffset;
    /* 14 */ Vec3 mVelocity;
    /* 20 */ u16 mAngle;
    /* 22 */ s16 mAngleSpeed;
    /* 24 */ u16 mLife;
    /* 26 */ u16 mAge;
    /* 28 */ u16 mSecondTimeScale;
    /* 2a */ u16 mFirstTimeScale;
    /* 2c */ u8 mTextureIndex;
    /* 2d */ u8 mSecondTimeOffset;
    /* 2e */ u16 mBaseAlpha : 5;
    /* 2e */ u16 mAnimAlpha : 5;
    /* 2e */ u16 mPolygonId : 6;
    /* 30 */ s32 mSize;
    /* 34 */ s16 mScale;
    /* 36 */ u16 mColor;
    /* 38 */ Vec3 mEmitterPosition;
} ParticleInstance;

// Used by SPLList_PushFront, SPLList_Erase and SPLList_PopFront.
typedef struct ParticleList {
    /* 00 */ ParticleInstance *mFront;
    /* 04 */ s32 mCount;
    /* 08 */ ParticleInstance *mBack;
} ParticleList;

typedef struct ParticleResourceFlags {
    /* 00 */ u32 mEmitShape : 4;
    /* 00 */ u32 mDrawKind : 2;
    /* 00 */ u32 mAxis : 2;
    /* 00 */ u32 mHasScaleAnim : 1;
    /* 00 */ u32 mHasColorAnim : 1;
    /* 00 */ u32 mHasAlphaAnim : 1;
    /* 00 */ u32 mHasTextureAnim : 1;
    /* 00 */ u32 mRandomAngleSpeed : 1;
    /* 00 */ u32 mRandomAngle : 1;
    /* 00 */ u32 mEndAfterEmit : 1;
    /* 00 */ u32 mFollowEmitter : 1;
    /* 00 */ u32 mHasChildAnim : 1;
    /* 00 */ u32 mRotateKind : 2;
    /* 00 */ u32 mPlaneKind : 1;
    /* 00 */ u32 mRandomSecondTimeOffset : 1;
    /* 00 */ u32 mChildrenFirst : 1;
    /* 00 */ u32 mHideParticles : 1;
    /* 00 */ u32 mTranslateByOffset : 1;
    /* 00 */ u32 mHasGravity : 1;
    /* 00 */ u32 mHasRandom : 1;
    /* 00 */ u32 mHasMagnet : 1;
    /* 00 */ u32 mHasSpin : 1;
    /* 00 */ u32 mHasCollisionPlane : 1;
    /* 00 */ u32 mHasConvergence : 1;
    /* 00 */ u32 mFixedPolygonId : 1;
    /* 00 */ u32 mFixedChildPolygonId : 1;
} ParticleResourceFlags;

// ParticleResourceDrawParams.mScaleMode: which sides of the particle the per-particle scale multiplies.
enum {
    PARTICLE_SCALE_BOTH,
    PARTICLE_SCALE_WIDTH,
    PARTICLE_SCALE_HEIGHT
};

typedef struct ParticleResourceDrawParams {
    /* 00 */ u32 mSecondTimeLength : 8;
    /* 00 */ u32 mStretchFactor : 16;
    /* 00 */ u32 mTexCoordUShift : 2;
    /* 00 */ u32 mTexCoordVShift : 2;
    /* 00 */ u32 mScaleMode : 3;
    /* 00 */ u32 mForwardFromOffset : 1;
} ParticleResourceDrawParams;

typedef struct ParticleResourceHeader {
    /* 00 */ ParticleResourceFlags mFlags;
    /* 04 */ Vec3 mPositionOffset;
    /* 10 */ s32 mEmitRate;
    /* 14 */ s32 mRadius;
    /* 18 */ s32 mHalfLength;
    /* 1c */ Vec3s16 mDirection;
    /* 22 */ u16 mColor;
    /* 24 */ s32 mDirectionSpeed;
    /* 28 */ s32 mAxisSpeed;
    /* 2c */ s32 mSizeScale;
    /* 30 */ s16 mBaseScale;
    /* 32 */ u16 mDelayFrameCount;
    /* 34 */ s16 mAngleSpeedMin;
    /* 36 */ s16 mAngleSpeedMax;
    /* 38 */ u16 mAngle;
    /* 3a */ u8 mUnk_3a[2];
    /* 3c */ u16 mEmitFrameCount;
    /* 3e */ u16 mLife;
    /* 40 */ u8 mSizeRandom;
    /* 41 */ u8 mLifeRandom;
    /* 42 */ u8 mSpeedRandom;
    /* 43 */ u8 mUnk_43;
    /* 44 */ u8 mEmitInterval;
    /* 45 */ u8 mAlpha;
    /* 46 */ u8 mDragFactor;
    /* 47 */ u8 mTextureIndex;
    /* 48 */ ParticleResourceDrawParams mDrawParams;
    /* 4c */ u32 mFlipU : 1;
    /* 4c */ u32 mFlipV : 1;
    /* 4c */ u32 mUnk_4c_2 : 30;
    /* 50 */ s16 mPlaneCenterX;
    /* 52 */ s16 mPlaneCenterY;
    /* 54 */ u8 mUpdateCycleBits;
} ParticleResourceHeader;

typedef struct ParticleScaleAnim {
    /* 00 */ s16 mStartScale;
    /* 02 */ s16 mMidScale;
    /* 04 */ s16 mEndScale;
    /* 06 */ u8 mMidStart;
    /* 07 */ u8 mMidEnd;
    /* 08 */ u16 mTimeIndex : 1;
    /* 08 */ u16 mUnk_08_1 : 15;
} ParticleScaleAnim;

typedef struct ParticleColorAnim {
    /* 00 */ u16 mStartColor;
    /* 02 */ u16 mEndColor;
    /* 04 */ u8 mFirstBlendStart;
    /* 05 */ u8 mFirstBlendEnd;
    /* 06 */ u8 mSecondBlendEnd;
    /* 07 */ u8 mUnk_07;
    /* 08 */ u16 mRandomColor : 1;
    /* 08 */ u16 mTimeIndex : 1;
    /* 08 */ u16 mBlend : 1;
    /* 08 */ u16 mUnk_08_3 : 13;
} ParticleColorAnim;

typedef struct ParticleAlphaAnim {
    /* 00 */ u16 mStartAlpha : 5;
    /* 00 */ u16 mMidAlpha : 5;
    /* 00 */ u16 mEndAlpha : 5;
    /* 00 */ u16 mUnk_00_15 : 1;
    /* 02 */ u16 mAlphaRandom : 8;
    /* 02 */ u16 mTimeIndex : 1;
    /* 02 */ u16 mUnk_02_9 : 7;
    /* 04 */ u8 mMidStartRate;
    /* 05 */ u8 mMidEndRate;
    /* 06 */ u8 mUnk_06[2];
} ParticleAlphaAnim;

typedef struct ParticleTextureAnim {
    /* 00 */ u8 mTextureIndices[8];
    /* 08 */ u32 mFrameCount : 8;
    /* 08 */ u32 mFrameLength : 8;
    /* 08 */ u32 mRandomTexture : 1;
    /* 08 */ u32 mTimeIndex : 1;
    /* 08 */ u32 mUnk_08_18 : 14;
} ParticleTextureAnim;

typedef struct ParticleChildTexParams {
    /* 00 */ u32 mTexCoordUShift : 2;
    /* 00 */ u32 mTexCoordVShift : 2;
    /* 00 */ u32 mFlipU : 1;
    /* 00 */ u32 mFlipV : 1;
    /* 00 */ u32 mForwardFromOffset : 1;
    /* 00 */ u32 mUnk_00_7 : 25;
} ParticleChildTexParams;

typedef struct ParticleChildAnim {
    /* 00 */ u16 mUseBehaviors : 1;
    /* 00 */ u16 mHasScaleAnim : 1;
    /* 00 */ u16 mHasAlphaAnim : 1;
    /* 00 */ u16 mInheritAngle : 2;
    /* 00 */ u16 mFollowEmitter : 1;
    /* 00 */ u16 mOwnColor : 1;
    /* 00 */ u16 mDrawKind : 2;
    /* 00 */ u16 mRotateKind : 2;
    /* 00 */ u16 mPlaneKind : 1;
    /* 00 */ u16 mUnk_00_12 : 4;
    /* 02 */ s16 mVelocityRandom;
    /* 04 */ s16 mEndScale;
    /* 06 */ u16 mLife;
    /* 08 */ u8 mVelocityScale;
    /* 09 */ u8 mSizeScale;
    /* 0a */ u16 mColor;
    /* 0c */ u8 mChildCount;
    /* 0d */ u8 mStartLifeRate;
    /* 0e */ u8 mInterval;
    /* 0f */ u8 mTextureIndex;
    /* 10 */ ParticleChildTexParams mTexParams;
} ParticleChildAnim;

typedef struct ParticleEmitterFlags {
    /* 00 */ u32 mEnding : 1;
    /* 00 */ u32 mEmissionStopped : 1;
    /* 00 */ u32 mPaused : 1;
    /* 00 */ u32 mHidden : 1;
    /* 00 */ u32 mStarted : 1;
    /* 00 */ u32 mUnk_00_5 : 27;
} ParticleEmitterFlags;

typedef struct ParticleEmitter ParticleEmitter;
typedef struct ParticleResource ParticleResource;

// Entries of the table at ParticleResource 0x18 (count at 0x1c).
typedef struct ParticleBehaviorEntry {
    /* 00 */ void (*mApply)(); // called with four arguments; the type of the first differs per entry
    /* 04 */ void *mData;
} ParticleBehaviorEntry;

struct ParticleResource {
    /* 00 */ ParticleResourceHeader *mHeader;
    /* 04 */ ParticleScaleAnim *mScaleAnim;
    /* 08 */ ParticleColorAnim *mColorAnim;
    /* 0c */ ParticleAlphaAnim *mAlphaAnim;
    /* 10 */ ParticleTextureAnim *mTextureAnim;
    /* 14 */ ParticleChildAnim *mChildAnim;
    /* 18 */ ParticleBehaviorEntry *mBehaviors;
    /* 1c */ u16 mBehaviorCount;
};

// The four bytes at ParticleEmitter 0x98.
typedef struct Unk0201ca6c_98 {
    /* 00 */ u8 mVelocityFactorIndex;
    /* 01 */ u8 mCounting;
    /* 02 */ u8 mStepCount;
    /* 03 */ u8 mSideIndex;
} Unk0201ca6c_98;

struct ParticleEmitter {
    /* 00 */ struct ParticleEmitter *mNext;
    /* 04 */ struct ParticleEmitter *mPrev;
    /* 08 */ ParticleList mParticles;
    /* 14 */ ParticleList mChildParticles;
    /* 20 */ ParticleResource *mResource;
    /* 24 */ ParticleEmitterFlags mFlags;
    /* 28 */ Vec3 mPosition;
    /* 34 */ Vec3 mParticleShift;
    /* 40 */ Vec3 mVelocity;
    /* 4c */ u16 mAge;
    /* 4e */ s16 mEmitFraction;
    /* 50 */ Vec3s16 mDirection;
    /* 56 */ u16 mAngle;
    /* 58 */ s32 mEmitRate;
    /* 5c */ s32 mRadius;
    /* 60 */ s32 mHalfLength;
    /* 64 */ s32 mDirectionSpeed;
    /* 68 */ s32 mAxisSpeed;
    /* 6c */ s32 mSizeScale;
    /* 70 */ u16 mLife;
    /* 72 */ u16 mColor;
    /* 74 */ s32 mPlaneY;
    /* 78 */ s16 mTexCoordU;
    /* 7a */ s16 mTexCoordV;
    /* 7c */ s16 mChildTexCoordU;
    /* 7e */ s16 mChildTexCoordV;
    /* 80 */ u32 mEmitInterval : 8;
    /* 80 */ u32 mAlpha : 8;
    /* 80 */ u32 mUpdateCycle : 3;
    /* 80 */ u32 mUnk_80_19 : 13;
    /* 84 */ Vec3s16 mAxisX;
    /* 8a */ Vec3s16 mAxisY;
    /* 90 */ void (*mCallback)(ParticleEmitter *p, s32 a);
    /* 94 */ union {
        void *mCallbackData;
        u32 mUnk_94_u;
    };
    /* 98 */ union {
        u32 mCallbackState;
        Unk0201ca6c_98 mCallbackBytes;
        struct {
            u8 mVelocityFactorIndex;
            u8 mUnk_98_8;
            u8 mStepCount;
            u8 mUnk_98_24;
        };
    };
};

// Read by SPLBehavior_ApplyMagnet and SPLBehavior_ApplyConvergence.
typedef struct ParticleBehaviorPoint {
    /* 00 */ Vec3 mPoint;
    /* 0c */ s16 mFactor;
} ParticleBehaviorPoint;

// Read by SPLBehavior_ApplyRandom.
typedef struct ParticleBehaviorRandom {
    /* 00 */ s16 mRangeX;
    /* 02 */ s16 mRangeY;
    /* 04 */ s16 mRangeZ;
    /* 06 */ u16 mInterval;
} ParticleBehaviorRandom;

// Read by SPLBehavior_ApplyCollisionPlane.
typedef struct ParticleBehaviorCollisionPlane {
    /* 00 */ s32 mPlaneY;
    /* 04 */ s16 mBounceFactor;
    /* 06 */ u16 mMode : 2;
    /* 06 */ u16 mUnk_06_2 : 14;
} ParticleBehaviorCollisionPlane;

// Read by SPLBehavior_ApplySpin.
typedef struct ParticleBehaviorSpin {
    /* 00 */ u16 mAngle;
    /* 02 */ u16 mAxis;
} ParticleBehaviorSpin;

void SPLUtil_RotateXYZ(s32 sinValue, s32 cosValue, MtxFx43 *mtx);
void SPLUtil_DrawXZPlane(u32 texCoordU, u32 texCoordV, s32 centerX, s32 centerZ);
void SPLUtil_DrawXYPlane(u32 texCoordU, u32 texCoordV, s32 centerX, s32 centerY);
void SPLEmitter_EmitChildren(ParticleInstance *emtr, ParticleEmitter *q, ParticleList *r);
void SPLEmitter_EmitParticles(ParticleEmitter *emtr, ParticleList *r);
void SPLUtil_TiltCoordinates(Vec3 *ptclPos, const Vec3 *pos, ParticleEmitter *emtr);
void SPLEmitter_ComputeOrthogonalAxes(ParticleEmitter *emtr);
void SPLAnim_ChildAlpha(ParticleInstance *ptcl, ParticleResource *res, s32 lifeRate);
void SPLAnim_ChildScale(ParticleInstance *ptcl, ParticleResource *res, s32 lifeRate);
void SPLAnim_Texture(ParticleInstance *ptcl, ParticleResource *res, s32 lifeRate);
void SPLAnim_Alpha(ParticleInstance *ptcl, ParticleResource *res, s32 lifeRate);
void SPLAnim_Color(ParticleInstance *ptcl, ParticleResource *res, s32 lifeRate);
void SPLAnim_Scale(ParticleInstance *ptcl, ParticleResource *res, s32 lifeRate);
void SPLBehavior_ApplyConvergence(const ParticleBehaviorPoint *conv, ParticleInstance *ptcl, Vec3 *acc,
                                  ParticleEmitter *emtr);
void SPLBehavior_ApplyCollisionPlane(const ParticleBehaviorCollisionPlane *plane, ParticleInstance *ptcl, Vec3 *acc,
                                     ParticleEmitter *emtr);
void SPLBehavior_ApplySpin(const ParticleBehaviorSpin *spin, ParticleInstance *ptcl, Vec3 *acc, ParticleEmitter *emtr);
void SPLBehavior_ApplyMagnet(const ParticleBehaviorPoint *magnet, ParticleInstance *ptcl, Vec3 *acc,
                             ParticleEmitter *emtr);
void SPLBehavior_ApplyRandom(const ParticleBehaviorRandom *rng, ParticleInstance *ptcl, Vec3 *acc,
                             ParticleEmitter *emtr);
void SPLBehavior_ApplyGravity(const Vec3s16 *gravity, ParticleInstance *ptcl, Vec3 *acc, ParticleEmitter *emtr);
ParticleInstance *SPLList_Erase(ParticleList *list, ParticleInstance *node);
ParticleInstance *SPLList_PopFront(ParticleList *list);
void SPLList_PushFront(ParticleList *list, ParticleInstance *node);
void SPLRandom_VecFx32_XY(Vec3 *vec);
void SPLRandom_VecFx32(Vec3 *vec);
