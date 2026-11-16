#pragma once

#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0207a104.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_0210a578.h"

#include "types.h"
#include "Main/Unknown/code_02039774.h"
#include "code_02012b30.h" // MtxFx43
#include "code_02147cd8.h" // Vec3s16
#include "code_02148538.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210b000.h" // SoundDistanceSquaredChange
#include "Main/Unknown/code_02080b1c.h" // KartKillerCursor

struct KartAi;

typedef struct Unk0201ca6c Unk0201ca6c;

// The 0x98-byte record of one kart slot, copied from a row of kartphysicalparam.bin (50 rows: 37 kart rows, then 13
// character rows used in mode 2). Edited in place per race: mBaseSpeedLimit by the engine class, the surface tables by
// the character row. Read by the Kart step and the item objects (Race).
typedef struct KartPhysicalParam {
    // Base radius (0x8000 = 8.0 in 12-bit fixed).
    /* 0 */ s32 mRadius;
    /* 4 */ s32 field4;
    /* 8 */ s32 field8;
    // s16, read only by the kart-kart push (the ratio of the two karts' values); the file column grows with the kart
    // size.
    /* c */ s16 mWeight;
    /* e */ s16 fieldE;
    // Top speed before the factors, scaled by the engine class at creation (x0xb33 / x0xd9a); reached: the length is
    // cut to the limit.
    /* 10 */ s32 mBaseSpeedLimit;
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
    /* 1c */ s32 field1C;
    /* 20 */ s32 field20;
    /* 24 */ s32 field24;
    /* 28 */ s32 field28;
    /* 2c */ s32 field2C;
    /* 30 */ s16 field30;
    /* 32 */ s16 field32;
    /* 34 */ s32 field34;
    /* 38 */ s32 field38[12];
    // 12 factors out of 0x1000, indexed by the surface group; entry 4 is also the floor of the below-the-level path.
    /* 68 */ s32 mSurfaceSpeedLimitFactors[12];
} KartPhysicalParam;

// Event counters of the selected entry's Kart (seven words; the one at 0 is a flag set to 1). Every writer tests that
// the Kart is the selected entry. Read by the rank score of the grand prix and the goal tests of mission run. What each
// counter counts is not named.
typedef struct EntryKartCounters {
    /* 0 */ s32 field0;
    /* 4 */ s32 field4;
    /* 8 */ s32 field8;
    /* c */ s32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
} EntryKartCounters;

struct Kart;

// 16-byte entry of the table at SoundRequestQueue.field4: RunSoundRequests calls field4 with the words at 8 and 0xc.
typedef struct SoundRequest {
    /* 00 */ u32 mSortKey;
    /* 04 */ void (*mFunction)(void *, s32);
    /* 08 */ void *mFirstArgument;
    /* 0c */ s32 mSecondArgument;
} SoundRequest;

typedef struct SoundRequestQueue {
    /* 0 */ s32 mCapacity;
    /* 4 */ SoundRequest *mRequests;
} SoundRequestQueue;

extern SoundRequestQueue data_0217d294;
extern SoundRequestQueue data_0217d29c;

// Frames before the Killer effect may end early because of the kart's rank.
#define KART_KILLER_RANK_END_FRAMES 0xb4
// Frames after which the Killer effect ends.
#define KART_KILLER_MAX_FRAMES 0x1e0
// Frames after which the Teresa effect ends (7.5 seconds).
#define KART_TERESA_MAX_FRAMES 0x1c2
typedef struct KartItemEffectState {
    /* 00 */ s16 field0;
    /* 02 */ s16 field2;
    /* 04 */ s16 field4;
    /* 06 */ s16 field6;
    /* 08 */ s16 field8;
    /* 0a */ s16 fieldA;
    /* 0c */ s16 fieldC;
    /* 0e */ s16 fieldE;
    /* 10 */ s16 mTeresaFrames;
    /* 12 */ s16 field12;
    /* 14 */ s16 field14;
    /* 16 */ s16 field16;
    /* 18 */ s16 field18;
    /* 1a */ s16 field1A;
    /* 1c */ s16 field1C;
    /* 1e */ s16 mKillerFrames;
    /* 20 */ s16 field20;
    /* 22 */ u8 field22[2];
    /* 24 */ BOOL mKillerEnding;
    // The effect may end early after KART_KILLER_RANK_END_FRAMES once the kart's rank is this number or better.
    /* 28 */ s16 mKillerEndRank;
    /* 2a */ u8 field2A[2];
    /* 2c */ KartKillerCursor mKillerCursor;
} KartItemEffectState;

typedef struct ParticipantKartRecordState {
    /* 00 */ Vec3 field0;
    /* 0c */ u16 fieldC;
    /* 0e */ u16 fieldE;
    /* 10 */ Vec3 field10;
    /* 1c */ s32 field1C;
    /* 20 */ s32 field20;
    /* 24 */ s32 field24;
    /* 28 */ s32 field28;
    /* 2c */ u32 field2C;
    /* 30 */ u32 mAppliedFlags;
    /* 34 */ Vec3 field34;
    /* 40 */ s16 mTargetTurnAngle;
    /* 42 */ u8 field42[2];
    /* 44 */ u32 field44;
    /* 48 */ u32 field48;
    /* 4c */ Vec4 field4C;
    /* 5c */ s16 mEasedTurnAngle;
    /* 5e */ u8 field5E[2];
    /* 60 */ s32 field60;
    /* 64 */ s32 field64;
    /* 68 */ u8 field68[0x18];
    /* 80 */ NNSFndList mPendingRecords;
    /* 8c */ NNSFndList mFreeRecords;
    /* 98 */ Vec3 mPushDirection;
    /* a4 */ s32 fieldA4;
    /* a8 */ Vec3 fieldA8;
    /* b4 */ u16 fieldB4;
} ParticipantKartRecordState;

typedef struct Unk0206c5e4_208 {
    /* 0 */ BOOL field0;
} Unk0206c5e4_208;

// The 0x38 bytes at 0x450 of a Kart: words at 0x08, 0x28, 0x30 and 0x34 and a byte at 0x2c.
typedef struct Unk0206bcb0_A {
    /* 00 */ s32 field0;
    /* 04 */ u8 field4[4];
    /* 08 */ s32 field8;
    /* 0c */ u8 fieldC[0x1c];
    /* 28 */ s32 field28;
    /* 2c */ u8 field2C;
    /* 2d */ u8 field2D[3];
    /* 30 */ u32 field30;
    /* 34 */ u32 field34;
} Unk0206bcb0_A;

// Bits of Kart.field7C.
// Set once at set-up (driver_initField7C) when mIndex == gRaceMultiConfig->mEntryIndex, i.e. the selected entry.
#define KART_7C_INDEX_IS_SELECTED_ENTRY 0x1
// Set at set-up when the entry's mKind is 2. Bit 0x2 and this bit are also tested together as 6 / 0x402004 (left
// literal).
#define KART_7C_ENTRY_KIND_2 0x4
// Set at set-up when mKartModelsEntry->field8 != NULL (a snapshot taken then).
#define KART_7C_MODELS_ENTRY_008_SET 0x10

// Bits of Kart.field44.
// Set from the start of a drift until it ends.
#define KART_44_DRIFTING 0x8
// Set while the Kart is on the ground; the hop clears it and the landing sets it again.
#define KART_44_ON_GROUND 0x10
// Set on both Karts of a pair when the near test passed; cleared at the start of the next step (inside the literal
// 0x57ffffdf).
#define KART_44_NEAR_KART 0x20

// Bits of Kart.field4C.
// Set while the Kart is small from the Thunder item (driver_startThunderShrinkEffect sets it, driver_updateThunderShrinkEffect clears
// it).
// Set while mHeadingAngleOffset swings (driver_handleStartBoost sets it, AdvanceKartHeadingSwing clears it).
#define KART_4C_HEADING_SWING 0x20000000
// Set each frame on the kart one rank behind the player.
#define KART_4C_ONE_RANK_BEHIND_PLAYER 0x40000
// Set each frame on the player kart and the kart one rank ahead (karts 0 to 2 in an award race); effects and side
// points run only while set.
#define KART_4C_NEAR_PLAYER_RANK 0x8000
// Set each frame on the player kart and the kart one rank ahead (karts 0 to 2 in an award race); effects and side
// points run only while set.
#define KART_4C_NEAR_PLAYER_RANK 0x8000
// Set each frame on the player kart and the kart one rank ahead (karts 0 to 2 in an award race); effects and side
// points run only while set.
#define KART_4C_NEAR_PLAYER_RANK 0x8000
// Set each frame on the player kart and the kart one rank ahead (karts 0 to 2 in an award race); effects and side
// points run only while set.
#define KART_4C_NEAR_PLAYER_RANK 0x8000
// Set each frame on the player kart and the kart one rank ahead (karts 0 to 2 in an award race); effects and side
// points run only while set.
#define KART_4C_NEAR_PLAYER_RANK 0x8000
// Set each frame on the player kart and the kart one rank ahead (karts 0 to 2 in an award race); effects and side
// points run only while set.
#define KART_4C_NEAR_PLAYER_RANK 0x8000
// Set each frame on the player kart and the kart one rank ahead (karts 0 to 2 in an award race); effects and side
// points run only while set.
#define KART_4C_NEAR_PLAYER_RANK 0x8000
// Set each frame on the player kart and the kart one rank ahead (karts 0 to 2 in an award race); effects and side
// points run only while set.
#define KART_4C_NEAR_PLAYER_RANK 0x8000
// Set each frame on the player kart and the kart one rank ahead (karts 0 to 2 in an award race); effects and side
// points run only while set.
#define KART_4C_NEAR_PLAYER_RANK 0x8000
// Set each frame on the player kart and the kart one rank ahead (karts 0 to 2 in an award race); effects and side
// points run only while set.
#define KART_4C_NEAR_PLAYER_RANK 0x8000
// Set each frame on the player kart and the kart one rank ahead (karts 0 to 2 in an award race); effects and side
// points run only while set.
#define KART_4C_NEAR_PLAYER_RANK 0x8000
// Set each frame on the player kart and the kart one rank ahead (karts 0 to 2 in an award race); effects and side
// points run only while set.
#define KART_4C_NEAR_PLAYER_RANK 0x8000
// Set while the kart is behind the camera, outside the view planes or beyond the far distance.
#define KART_4C_OUT_OF_VIEW 0x800000
// Set while the kart is behind the camera, outside the view planes or beyond the far distance.
#define KART_4C_OUT_OF_VIEW 0x800000
// Set while the kart is behind the camera, outside the view planes or beyond the far distance.
#define KART_4C_OUT_OF_VIEW 0x800000
// Set while the kart is behind the camera, outside the view planes or beyond the far distance.
#define KART_4C_OUT_OF_VIEW 0x800000
// Set while the kart is behind the camera, outside the view planes or beyond the far distance.
#define KART_4C_OUT_OF_VIEW 0x800000
#define KART_4C_THUNDER_SHRINK 0x80
// Bits of Kart.field48.
// The Kart steers left in this step (from the input bits or the CPU); driver_1FFCA50 clears both turn bits.
#define KART_48_TURN_LEFT 8
// The Kart steers right in this step.
#define KART_48_TURN_RIGHT 0x10
// Set while a boost runs (driver_addBoost sets it; mBoostTimer counts it down).
#define KART_48_BOOST 0x20
// Set from the release of a fully charged drift until field23C has counted down.
#define KART_48_MINI_TURBO 0x80000

// The values of Kart.mState; each indexes driver_sReactionUpdateFuncs.
typedef enum {
    // Ordinary driving; the handler does nothing.
    KART_STATE_NORMAL,
    // No code starts it; it shares the handler of KART_STATE_SPIN.
    KART_STATE_1,
    // The Kart turns about its vertical axis mYRotationCount times in place.
    KART_STATE_SPIN,
    // The Kart hops and rotates once; started with no direction.
    KART_STATE_FLIP,
    // The Kart is pushed along a direction and rotates once.
    KART_STATE_PUSH_FLIP,
    // The Kart is pushed along a direction and rotates twice.
    KART_STATE_PUSH_DOUBLE_FLIP,
    // The Kart is thrown up and rotates twice with its forward speed cleared.
    KART_STATE_LAUNCH_DOUBLE_FLIP
} KartState;
// The values of Kart.mItemEffect, the item acting on the kart.
typedef enum {
    KART_ITEM_EFFECT_NONE,
    KART_ITEM_EFFECT_STAR,
    // The Boo item (Teresa).
    KART_ITEM_EFFECT_TERESA,
    // The Bullet Bill item (Killer).
    KART_ITEM_EFFECT_KILLER
} KartItemEffect;

typedef struct Kart {
    // Sound source of the Kart (the sounds started on it).
    /* 00 */ SoundSource mSoundSource;
    /* 44 */ vu32 field44;
    /* 48 */ vu32 field48;
    /* 4c */ vu32 field4C;
    /* 50 */ Vec3 mTurnedForward;
    /* 05c */ Vec3 mSignedTurnedForward;
    /* 68 */ Vec3 mEasedTurnedForward;
    /* 74 */ u16 mIndex;
    /* 76 */ u8 field76[0x2];
    /* 78 */ s32 mEntryIndex;
    /* 7c */ vu32 field7C;
    /* 80 */ Vec3 mPos;
    /* 8c */ Vec3 mPrevPos;
    // Copy of the kart position made when the draw matrix is built; until then it holds the position of one step
    // earlier.
    /* 98 */ Vec3 mDrawMatrixPos;
    /* a4 */ Vec3 mVelocity;
    /* b0 */ Vec3 mVelocityDirection;
    // Size scale of the kart (x, y, z; 0x1000 = 1.0): mScaleBase times mScaleFactor per axis, y also times
    // mScaleYFactor. Zero at the start placement (ResetKartToStartPlacement) and where the kart is moved to a far
    // corner (StructMQRacerEntry_SomeFn_53, StructMQRacerEntry_SomeFn_25).
    /* bc */ Vec3 mScale;
    // Negative step added by driver_1FFB9CC to mVerticalSpeed, by AdvanceKartHop to mHopSpeed while hopping and to a
    // speed of the mode-5 record; -0x2b9 at reset, 0 after the water-height branch of driver_handleOobFallCannonPipe.
    /* c8 */ s32 mGravity;
    // The value mSpeedLimit follows: it falls by x0xf37/0x1000 per step but never below it and rises to it at once.
    // Written by the step, by the companion objects (their own choice) and at set-up; read by the companion objects as
    // the kart's limit.
    /* cc */ s32 mSpeedLimitGoal;
    /* d0 */ s32 mSpeedLimit;
    /* d4 */ u32 fieldD4;
    /* d8 */ s32 fieldD8;
    /* dc */ s32 mSpeedLimitFactor;
    /* e0 */ union {
        struct {
            s32 fieldE0;
            Vec3 fieldE4;
            Vec3 fieldF0;
            u32 fieldFC;
            s32 field100;
            struct Unk020e04b0 *field104;
            Vec3 field108;
            u8 field114[6];
            s16 field11A;
            s32 field11C;
        };
        struct {
            Vec4 mUnk_e0_m;
            Vec4 mUnk_f0_q;
            Vec4 mUnk_100_q;
            Vec4 mUnk_110_q;
        };
    };
    /* 120 */ union {
        struct {
            Vec3 field120;
            Vec3 field12C;
            Vec3 field138;
            Vec3 field144;
        };
        MtxFx43 mUnk_120_m;
    };
    /* 150 */ union {
        struct {
            Vec3 field150;
            Vec3 field15C;
            Vec3 field168;
            Vec3 field174;
        };
        MtxFx43 mUnk_150_m;
    };
    /* 180 */ volatile KartState mState;
    /* 184 */ MtxFx43 mWobbleMatrix;
    /* 1b4 */ MtxFx43 *mDrawMatrix;
    // Collision center of the Kart: the position moved up by mRadius plus 0x400 along the up vector. The
    // collision sweep ends here; Kart.mPrevCollisionCenter is where it starts.
    /* 1b8 */ Vec3 mCollisionCenter;
    // Collision center of the previous step, set from the previous position by slot 5 of Kart.mSlotFunctions: the start
    // of the collision sweep that ends at Kart.mCollisionCenter.
    /* 1c4 */ Vec3 mPrevCollisionCenter;
    // Current radius: the record's radius times two scales (code_01ffba68.c:208), set from the record at creation.
    /* 1d0 */ s32 mRadius;
    /* 1d4 */ s32 field1D4;
    /* 1d8 */ Vec3 mPointAlongUp;
    /* 1e4 */ Vec3 mPrevPointAlongUp;
    /* 1f0 */ Vec3 field1F0;
    /* 1fc */ Vec3 field1FC;
    /* 208 */ Unk0206c5e4_208 *field208;
    // The functions of one Kart, one per slot index: 0 set-up at creation, 1 reset to the starting values, 2 stores the
    // squared distance in the sound source, 3 and 4 the two steps UpdateKarts runs for every Kart, 5 stores the
    // previous collision center, 6 respawn, 7 start placement, 8 does nothing. 7 and 8 are never called. InitKart fills
    // it from gKartDefaultSlotFunctions and replaces slots 2 to 5; it also replaces slots 3 and 4 with an empty
    // function when race_sState.mUseChainCameras is set and RaceSetup.fieldC is not 5.
    /* 20c */ void (*mSlotFunctions[9])(struct Kart *);
    /* 230 */ void (*field230)(struct Kart *);
    /* 234 */ s16 mAirTiltAngle;
    // Angle about world up that orients the kart (0x10000 per turn): set from a direction vector or a start rotation,
    // turned by the step functions and by mHeadingAnglePerFrame; mHeadingAngleOffset is added on top when the
    // orientation is built.
    /* 236 */ u16 mHeadingAngle;
    /* 238 */ s16 mBoostTimer;
    /* 23a */ s16 field23A;
    /* 23c */ s16 mMiniTurboTimer;
    /* 23e */ u8 field23E[2];
    /* 240 */ u32 mTurnedForwardEaseFactor;
    /* 244 */ Vec3 mGroundNormal;
    /* 250 */ Vec3 field250;
    /* 25c */ s32 field25C;
    // Vertical speed added to mVelocity.y after mVelocity is rebuilt each step, so it persists; mGravity is added to
    // it, it is reset to -0x2b9 or -0xd9d on a ground hit while negative, and a hop start adds a kick.
    /* 260 */ s32 mVerticalSpeed;
    /* 264 */ u8 field264[4];
    /* 268 */ Vec3 field268;
    /* 274 */ s32 field274;
    /* 278 */ Vec3 mForward;
    /* 284 */ Vec3 mHopStartUp;
    /* 290 */ Vec3 mHopStartForward;
    // The item acting on the kart (KartItemEffect); NONE when no star, Teresa or Killer runs.
    /* 29c */ s32 mItemEffect;
    /* 2a0 */ s32 mVelocityLengthRatio;
    /* 2a4 */ s32 mVelocityLength;
    /* 2a8 */ s32 mForwardSpeed;
    // mPos.y while the floor-hit bit is set; read once (the fall height of a landing).
    /* 2ac */ s32 mLastGroundY;
    /* 2b0 */ u16 mTestedKartMask;
    /* 2b2 */ u16 mNearKartMask;
    /* 2b4 */ u16 mPrevNearKartMask;
    /* 2b6 */ u8 field2B6[2];
    // Vertical speed of the hop arc: 0x1405 at the start (driver_handleJumpAndDrift), mGravity added each step by
    // AdvanceKartHop, integrated into mHopHeight, 0 once the height is below 0.
    /* 2b8 */ s32 mHopSpeed;
    // Height of the hop arc, integrated from mHopSpeed; 0 at the start and when it would go below 0. The camera, its
    // look-at and the replay record subtract it from mPos.y.
    /* 2bc */ s32 mHopHeight;
    // Angle about the x axis that tilts the kart while mHopSpeed > 0 and bit 2 of field44 is set (0x9c4 minus
    // mHopHeight * 500 / 0x1000, 0x352 when that exceeds 0x6a4); 0 otherwise. 0x10000 per turn.
    /* 2c0 */ u16 mHopTiltAngle;
    /* 2c2 */ u8 field2C2[2];
    // Sign 1 / -1 / 0 of a turn, latched when it starts (from field48 bits 0x10 / 8, or from the entry's input bits
    // 0x10 / 0x20) and cleared when it ends; read only as a sign.
    /* 2c4 */ s32 mTurnDirection;
    /* 2c8 */ s16 mCollisionSlot;
    /* 2ca */ s16 field2CA;
    // Pointer to this slot's KartPhysicalParam; set once in driver_initPhysicalParams. The record is shared by nothing
    // else.
    /* 2cc */ KartPhysicalParam *mPhysicalParam;
    // Two words of charphysicalparam.bin for the entry's character: [0] scales the surface factors below 0x1000, [1] is
    // added to mWeight.
    /* 2d0 */ s32 *mCharPhysicalParam;
    /* 2d4 */ s32 mTurnRatio;
    /* 2d8 */ Vec3 mHitVelocity;
    /* 2e4 */ Vec3 mPrevHitVelocity;
    /* 2f0 */ Vec3 field2F0;
    /* 2fc */ s32 mDriftCharge;
    /* 300 */ u16 mLeftTurnCount;
    /* 302 */ u16 mRightTurnCount;
    /* 304 */ u16 *mAwayTurnCounter;
    /* 308 */ u16 *mTowardTurnCounter;
    /* 30c */ s32 mTurnCountTimer;
    /* 310 */ struct KartAi *mAi;
    /* 314 */ u16 mRotationAngle;
    /* 316 */ u8 field316[2];
    /* 318 */ s32 mRotationAngleSum;
    /* 31c */ Vec3 mRotationAxis;
    /* 328 */ Vec3 mLaunchForward;
    /* 334 */ s32 field334;
    /* 338 */ u16 field338;
    /* 33a */ u8 field33A[2];
    /* 33c */ s32 field33C;
    /* 340 */ s32 mLaunchStartY;
    /* 344 */ s32 field344;
    /* 348 */ s32 mLaunchFrames;
    /* 34c */ Vec4 mRotationQuaternion;
    /* 35c */ s16 mRotationEndFrames;
    /* 35e */ u8 field35E[2];
    /* 360 */ s32 mRotationAnglePerFrame;
    /* 364 */ u16 mYRotationAngle;
    /* 366 */ u16 mYRotationCount;
    /* 368 */ s32 mYRotationAngleSum;
    /* 36c */ s32 mYRotationAnglePerFrame;
    /* 370 */ u16 field370;
    /* 372 */ u8 field372[2];
    /* 374 */ Vec3 field374;
    // Calls of UpdateKartAirborne since KART_44_ON_GROUND was last set; not every step (skipped below
    // y = 0).
    /* 380 */ u32 mAirborneFrames;
    // Draw gate of the kart: 0xffff while it is drawn, 0 when driver_render skips it (hidden states, or the off phase of
    // the blink); other draw code skips its drawing while it is 0; 0 at reset for an entry of kind 2.
    /* 384 */ u16 mVisible;
    // Angle added to mHeadingAngle each step, first multiplied by 0xe66 / 0x1000 and cut to 0 below 0x14; set in
    // HandleWalls, 0 at reset.
    /* 386 */ s16 mHeadingAnglePerFrame;
    // Angle that follows mTurnDirection: eased toward 11000 or -11000, changed by the turn input and cut back to 0 on
    // the ground; it is the angle of the rotation of field278 about field244 in driver_handleRegularDriving.
    /* 388 */ s16 mTurnAngle;
    /* 38a */ s16 field38A;
    /* 38c */ s32 mSpeedLimitHitFactor;
    /* 390 */ u8 field390[4];
    /* 394 */ s32 field394;
    /* 398 */ s32 field398;
    /* 39c */ s32 mMapObjectVectorLength;
    /* 3a0 */ s32 mMapObjectVectorForwardDot;
    // Angle of the tire object about the x axis (0x10000 per turn), advanced each step in sub_20641F0 from the speed
    // ratio and used by driver_render; 0 at reset.
    /* 3a4 */ u16 mTireSpinAngle;
    /* 3a6 */ u8 field3A6[2];
    /* 3a8 */ s32 mQuaternionBlendFactor;
    /* 3ac */ u16 mSinkFrames;
    /* 3ae */ u8 field3AE[2];
    // mVelocity, minus mVerticalSpeed on a floor hit, shifted right by 4 each step (driver_updateDriftEffects); copied or
    // scaled into the velocity (field40) of effect objects.
    /* 3b0 */ Vec3 mEffectVelocity;
    /* 3bc */ u16 field3BC;
    /* 3be */ u16 mRaceStartFrameCount;
    /* 3c0 */ s16 mRespawnFrames;
    /* 3c2 */ u8 field3C2[2];
    // Number of the course respawn slot this Kart goes back to, set when it falls or when it respawns with none chosen;
    // -1 means none chosen (ResetKart writes -1).
    /* 3c4 */ s32 mRespawnSlot;
    /* 3c8 */ s16 field3C8;
    /* 3ca */ u8 field3CA[2];
    /* 3cc */ s32 mSoundIndex;
    /* 3d0 */ s16 field3D0;
    // Countdown of 0x14 set on the slower kart of a kart-kart contact in driver_handleDriverCollision and counted down by
    // AdvanceKartCollisionTimer, which calls sfx_210B12C at 0 (what that call does is unknown).
    /* 3d2 */ s16 mKartCollisionTimer;
    /* 3d4 */ s16 mKartCollisionDelayTimer;
    /* 3d6 */ u8 field3D6[2];
    /* 3d8 */ s32 mRank;
    // Result of the handler: index into the two 12-entry tables of the record; -1 when the floor is left; compared with
    // 8 and 0xb. Group meanings unknown.
    /* 3dc */ s32 mSurfaceGroup;
    // Bits 8..12 of the attribute of the strongest ground hit (mask 0x1e34ef); indexes driver_sHandleFloorCollisionFuncs; 0 after
    // reset.
    /* 3e0 */ s32 mSurfaceKind;
    // Bits 5..7 of the same attribute: second selector (effect tables).
    /* 3e4 */ s32 mSurfaceVariant;
    /* 3e8 */ s16 field3E8;
    /* 3ea */ u8 field3EA[2];
    /* 3ec */ s32 mTurnHeadingAnglePerFrameGoal;
    /* 3f0 */ s32 mTurnHeadingAnglePerFrame;
    /* 3f4 */ s32 mSpeedLimitFactorPerDepth;
    /* 3f8 */ s32 field3F8;
    /* 3fc */ u16 mModelScaleKind;
    /* 3fe */ u16 mModelScaleFrameIndex;
    /* 400 */ u16 mModelScaleFrameCount;
    /* 402 */ u8 field402[2];
    /* 404 */ s32 mModelScaleY;
    /* 408 */ s32 mModelOffsetY;
    /* 40c */ s32 field40C;
    /* 410 */ s32 field410;
    /* 414 */ s32 mModelScaleX;
    /* 418 */ s32 mModelScaleZ;
    // Part of mScale looked up in three tables (x, y, z) of 25 entries (0x800 up to 0x1000) by a step counter, forwards
    // or backwards; 0x1000 when no step runs.
    /* 41c */ Vec3 mScaleFactor;
    // Part of mScale held at 0x1000, eased down to 0x800 while the countdown of driver_updateThunderShrinkEffect runs and set
    // back to 0x1000 at its end; mScaleFactor is the table-driven part.
    /* 428 */ Vec3 mScaleBase;
    // Factor of mScale.y only: 0x1000 normally, lowered by 0x4cd per call to a floor of 0x4cd in driver_updateDossunFlatEffect.
    /* 434 */ s32 mScaleYFactor;
    /* 438 */ struct MapObject *mPrevTouchingMapObjects[2];
    /* 440 */ u16 field440[2];
    /* 444 */ s32 field444[2];
    /* 44c */ struct MapObject *field44C;
    /* 450 */ Unk0206bcb0_A field450;
    /* 488 */ u32 field488;
    /* 48c */ s32 (*field48C)(void *);
    /* 490 */ u32 field490;
    /* 494 */ u8 field494[0x24];
    /* 4b8 */ s32 field4B8;
    /* 4bc */ s32 field4BC;
    /* 4c0 */ s32 field4C0;
    /* 4c4 */ s32 field4C4;
    /* 4c8 */ s32 mRadiusFactor;
    /* 4cc */ s32 field4CC;
    /* 4d0 */ u32 field4D0;
    /* 4d4 */ s32 field4D4;
    /* 4d8 */ s16 field4D8;
    /* 4da */ s16 field4DA;
    /* 4dc */ s16 mLandingTimer;
    // Angle added to mHeadingAngle when the orientation is built, never to mHeadingAngle itself;
    // AdvanceKartHeadingSwing swings it back and forth and sets it to 0 at the end.
    /* 4de */ s16 mHeadingAngleOffset;
    // Angle added to mHeadingAngleOffset each step by AdvanceKartHeadingSwing; changed by 0x3c per call toward the
    // swing direction and clamped to 0x17c, later 0xd2; 0 at reset.
    /* 4e0 */ s16 mHeadingAngleOffsetPerFrame;
    /* 4e2 */ s16 mHeadingAngleOffsetDirection;
    /* 4e4 */ u16 mHeadingAngleOffsetCount;
    /* 4e6 */ u8 field4E6[2];
    /* 4e8 */ s32 field4E8;
    /* 4ec */ s32 field4EC;
    /* 4f0 */ Vec3 field4F0;
    /* 4fc */ u16 field4FC;
    /* 4fe */ u8 field4FE[2];
    /* 500 */ u32 mWaterDepth;
    /* 504 */ u16 field504;
    /* 506 */ u16 field506;
    // Points to mPos, or for a kind-3 entry in mode 5 to a Vec3 of the received record (field514); set in InitKart.
    // Draw, culling, effect placement and the position getter read the position through it.
    /* 508 */ Vec3 *mPosSource;
    /* 50c */ Vec4 *field50C;
    /* 510 */ Vec3 *field510;
    /* 514 */ ParticipantKartRecordState *field514;
    /* 518 */ SoundDistanceSquaredChange field518;
    /* 528 */ u8 field528[0xc];
    /* 534 */ Vec3 *mPosSourceCopy;
    /* 538 */ KartItemEffectState field538;
    /* 590 */ struct KartModelsEntry *mKartModelsEntry;
    /* 594 */ s32 mWobbleAmplitude;
    /* 598 */ s16 mWobbleDirection;
    /* 59a */ u8 field59A[2];
    /* 59c */ s32 mWobbleEasedAmplitude;
    /* 5a0 */ u16 mWobbleAngle;
    /* 5a2 */ u8 field5A2[2];
    /* 5a4 */ s32 mWobbleSine;
} Kart;

// Jg: the object built from the jg_* files plus lap_count and lap_final; this is the kart it follows.
extern Kart *jg_sTargetDriver;

extern int data_02154f10[];

void driver_beginColReaction(Kart *kart, KartState mode);
BOOL StructMQRacerEntry_SomeFn_83(Kart *kart);
int StructMQRacerEntry_SomeFn_71(Kart *kart);
BOOL StructMQRacerEntry_SomeFn_64(Kart *kart);
BOOL StructMQRacerEntry_SomeFn_86(Kart *kart);
void driver_notifyDragItemChanged(Kart *kart);
void driver_notifySlotItemChanged(Kart *kart);
void StructMQRacerEntry_SomeFn_30(Kart *kart);
void func_0206c1ac(Unk0201ca6c *emitter, Kart *kart);
void func_0206c2b4(Unk0201ca6c *emitter, Kart *kart);
BOOL driver_206C354(Kart *kart, const Vec3 *overlapDirection, int flag);
void func_0206c450(Unk0201ca6c *emitter, Kart *kart);
void func_0206c488(Unk0201ca6c *emitter, Kart *kart);

void ptcm_createEmitterNoUpdateSkip(u32 idx, const Vec3 *pos, void *splManager, void (*cb)());
int driver_handleWheelSpin(Kart *kart);
void driver_handleDrifting(Kart *kart, int fromLowSpeedTurn);
#include "Main/Unknown/code_0210ab48.h"
void driver_endDrift(Kart *kart);
void driver_handleBoost(s32 *acceleration, Kart *kart);
extern SoundRequestQueue data_0217d26c[7];
extern SoundRequestQueue data_0217d274;
extern SoundRequestQueue data_0217d284;
extern SoundRequestQueue data_0217d28c;
#include "Main/Unknown/code_0210dc7c.h"
void func_020718c8(void *kart, int arg);
void driver_emitSfx3(void *soundSource, int arg);
#include "Main/Unknown/code_021035ac.h"
BOOL driver_tryStartSpinOut(Kart *kart, int rotationCount, int b);
BOOL TryStartKartState(Kart *kart, KartState newState);
void driver_handleJumpAndDrift(Kart *kart);
void driver_getShadowZDirection(const Kart *p, Vec3 *out);
void driver_getShadowYDirection(const Kart *p, Vec3 *out);

#include "Main/Unknown/code_0207ae58.h"
#include "Main/Unknown/code_02079c0c.h"
