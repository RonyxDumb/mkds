#pragma once

#include "Main/Kart/camera.h"
#include "Main/Kart/code_0207a104.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Sound/kart_full_volume_sort.h"
#include "Main/Sound/kart_sound.h" // KartSound

#include "types.h"
#include "Main/System/wvr_state.h"
#include "code_02012b30.h" // MtxFx43
#include "code_02147cd8.h" // Vec3s16
#include "code_02148538.h"
#include "tp.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/data_0210b000.h" // SoundDistanceSquaredChange
#include "Main/Kart/code_02080b1c.h" // KartKillerCursor

struct KartAi;

typedef struct ParticleEmitter ParticleEmitter;

// The 0x98-byte record of one kart slot, copied from a row of kartphysicalparam.bin (50 rows: 37 kart rows, then 13
// character rows used in mode 2). Edited in place per race: mBaseSpeedLimit by the engine class, the surface tables by
// the character row. Read by the Kart step and the item objects (Race).
typedef struct KartPhysicalParam {
    // Base radius (0x8000 = 8.0 in 12-bit fixed).
    /* 0 */ s32 mRadius;
    /* 4 */ s32 mPointAlongUpExtra;
    /* 8 */ s32 mBehindDistance;
    // s16, read only by the kart-kart push (the ratio of the two karts' values); the file column grows with the kart
    // size.
    /* c */ s16 mWeight;
    /* e */ s16 mMiniTurboFrames;
    // Top speed before the factors, scaled by the engine class at creation (x0xb33 / x0xd9a); reached: the length is
    // cut to the limit.
    /* 10 */ s32 mBaseSpeedLimit;
    /* 14 */ s32 mAcceleration;
    /* 18 */ s32 mEndAcceleration;
    /* 1c */ s32 mEndRatio;
    /* 20 */ s32 mDriftAcceleration;
    /* 24 */ s32 mDriftEndAcceleration;
    /* 28 */ s32 mDriftEndRatio;
    /* 2c */ s32 mForwardSpeedFactor;
    /* 30 */ s16 mTurnRate;
    /* 32 */ s16 mDriftTurnRate;
    /* 34 */ s32 mTurnAngleStep;
    /* 38 */ s32 mSurfaceTurnedForwardEaseFactors[12];
    // 12 factors out of 0x1000, indexed by the surface group; entry 4 is also the floor of the below-the-level path.
    /* 68 */ s32 mSurfaceSpeedLimitFactors[12];
} KartPhysicalParam;

// Event counters of the selected entry's Kart (seven words; the one at 0 is a flag set to 1). Every writer tests that
// the Kart is the selected entry. Read by the rank score of the grand prix and the goal tests of mission run.
typedef struct EntryKartCounters {
    /* 0 */ s32 mRaceStartBoosted;
    /* 4 */ s32 mMiniTurboCount;
    /* 8 */ s32 mItemHitCount;
    /* c */ s32 mSurfaceCount;
    /* 10 */ s32 mCourseContactCount;
    /* 14 */ s32 mMapObjectHitCount;
    /* 18 */ s32 mRespawnCount;
} EntryKartCounters;

struct Kart;

// 16-byte entry of the table at SoundRequestQueue.mUnk_04: RunSoundRequests calls mUnk_04 with the words at 8 and 0xc.
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

// Frames before the Killer effect may end early because of the kart's rank.
#define KART_KILLER_RANK_END_FRAMES 0xb4
// Frames after which the Killer effect ends.
#define KART_KILLER_MAX_FRAMES 0x1e0
// Frames after which the Teresa effect ends (7.5 seconds).
#define KART_TERESA_MAX_FRAMES 0x1c2
typedef struct KartItemEffectState {
    /* 00 */ s16 mKinokoBoostTimer;
    /* 02 */ s16 mThunderShrinkTimer;
    /* 04 */ s16 mThunderShrinkFrameIndex;
    /* 06 */ s16 mStarFrames;
    /* 08 */ s16 mAheadCount;
    /* 0a */ s16 mAheadBoostFrames;
    /* 0c */ s16 mScaleTableIndex;
    /* 0e */ s16 mScaleEffectTimer;
    /* 10 */ s16 mTeresaFrames;
    /* 12 */ s16 mTeresaToggleDivisor;
    /* 14 */ s16 mTeresaStepFrames;
    /* 16 */ s16 mTeresaToggleFrames;
    /* 18 */ s16 mTeresaStepLimit;
    /* 1a */ s16 mTeresaDivisorStep;
    /* 1c */ s16 mGessoFrames;
    /* 1e */ s16 mKillerFrames;
    /* 20 */ s16 mUnk_20;
    /* 22 */ u8 mUnk_22[2];
    /* 24 */ BOOL mKillerEnding;
    // The effect may end early after KART_KILLER_RANK_END_FRAMES once the kart's rank is this number or better.
    /* 28 */ s16 mKillerEndRank;
    /* 2a */ u8 mUnk_2a[2];
    /* 2c */ KartKillerCursor mKillerCursor;
} KartItemEffectState;

typedef struct ParticipantKartRecordState {
    /* 00 */ Vec3 mSmoothedPos;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mSmoothedHeadingAngle;
    /* 10 */ Vec3 mSmoothedDrawPos;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mLastSyncCount;
    /* 24 */ s32 mPosBlendFactor;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u32 mEventToggleFlags;
    /* 30 */ u32 mAppliedFlags;
    /* 34 */ Vec3 mUnk_34;
    /* 40 */ s16 mTargetTurnAngle;
    /* 42 */ u8 mUnk_42[2];
    /* 44 */ u32 mRecordBits;
    /* 48 */ u32 mRecordKartBits;
    /* 4c */ Vec4 mSmoothedRotation;
    /* 5c */ s16 mEasedTurnAngle;
    /* 5e */ u8 mUnk_5e[2];
    /* 60 */ s32 mHopHeight;
    /* 64 */ s32 mHopSpeed;
    /* 68 */ u8 mUnk_68[0x18];
    /* 80 */ NNSFndList mPendingRecords;
    /* 8c */ NNSFndList mFreeRecords;
    /* 98 */ Vec3 mPushDirection;
    /* a4 */ s32 mStartedStateKind;
    /* a8 */ Vec3 mPosOffset;
    /* b4 */ u16 mPosOffsetIndex;
} ParticipantKartRecordState;

// Bits of ParticipantKartRecordState.mEventToggleFlags and mAppliedFlags (ParticipantKartRecord.mFlags). The local kart
// flips a bit when the event starts; a peer starts the event when the received bit differs from the applied one.
#define KART_EVENT_HOP 0x1
#define KART_EVENT_SPIN_SINGLE 0x4
#define KART_EVENT_SPIN_DOUBLE 0x8
#define KART_EVENT_FLIP 0x10
#define KART_EVENT_PUSH_FLIP 0x20
#define KART_EVENT_PUSH_DOUBLE_FLIP 0x40
// Flipped on the kart a push flip hits (the peer plays the hit sound).
#define KART_EVENT_HIT_SOUND 0x80
// Flipped on the star kart when it push-flips the kart with kart index 0 to 3.
#define KART_EVENT_PUSH_FLIP_HIT_FIRST 0x200
#define KART_EVENT_PUSH_FLIP_HIT_SECOND 0x400
#define KART_EVENT_PUSH_FLIP_HIT_THIRD 0x800
#define KART_EVENT_PUSH_FLIP_HIT_FOURTH 0x1000
#define KART_EVENT_STAR 0x2000
#define KART_EVENT_THUNDER 0x4000
#define KART_EVENT_THUNDER_SHRINK 0x8000
// Flipped when the kart is respawned.
#define KART_EVENT_RESPAWN 0x10000
#define KART_EVENT_LAUNCH_DOUBLE_FLIP 0x20000
#define KART_EVENT_AHEAD_BOOST 0x40000
#define KART_EVENT_GESSO 0x80000
#define KART_EVENT_KILLER 0x100000
#define KART_EVENT_KILLER_ENDING 0x200000
// Flipped on the killer kart when it push-double-flips the kart with kart index 0 to 3.
#define KART_EVENT_PUSH_DOUBLE_FLIP_HIT_FIRST 0x400000
#define KART_EVENT_PUSH_DOUBLE_FLIP_HIT_SECOND 0x800000
#define KART_EVENT_PUSH_DOUBLE_FLIP_HIT_THIRD 0x1000000
#define KART_EVENT_PUSH_DOUBLE_FLIP_HIT_FOURTH 0x2000000
#define KART_EVENT_TERESA 0x4000000
// Two bits holding the kart index (0 to 3) of the kart that caused the started state; the shift moves them to bit 0.
#define KART_EVENT_SOURCE_KART_MASK 0x60000000
#define KART_EVENT_SOURCE_KART_SHIFT 29

// ParticipantKartRecordState.mRecordKartBits keeps the low byte of Kart.mMotionFlags.
#define KART_RECORD_MOTION_BYTE_MASK 0xff

// Bits of Kart.mMotionFlags.
// Set while R is held in the air with a turn direction latched; lets the landing start a drift.
#define KART_MOTION_DRIFT_ARMED 0x1
// Set in the drift hop and gone at the landing; tilts the Kart while mHopSpeed > 0 and counts as hop for
// a drift start.
#define KART_MOTION_HOPPING 0x2
// Set while the hop runs; AdvanceKartHop clears it when mHopHeight falls below 0.
#define KART_MOTION_HOP_ACTIVE 0x4
// Set from the start of a drift until it ends.
#define KART_MOTION_DRIFTING 0x8
// Set while the Kart is on the ground; the hop clears it and the landing sets it again.
#define KART_MOTION_ON_GROUND 0x10
// Set on both Karts of a pair when the near test passed; cleared at the start of the next step.
#define KART_MOTION_NEAR_KART 0x20
// Set while a map object pushes the Kart (CollideKartWithMapObjects).
#define KART_MOTION_OBJECT_CONTACT 0x40
// Set at the frame the Kart touches a wall and kept while touching; cleared when the contact ends.
#define KART_MOTION_COURSE_CONTACT 0x80
// Set in the step when mForwardSpeed is negative (the Kart is reversing).
#define KART_MOTION_REVERSING 0x100
// Set while mCollisionPushVelocity pushes the Kart away from the course.
#define KART_MOTION_COURSE_PUSH 0x200
// Set while no gas is held on the ground; no drive input changed mForwardSpeed; ScaleKartForwardSpeed
// then decays it.
#define KART_MOTION_COASTING 0x400
// Set at the start of a hop; with HOPPING the heading turns by mTurnDirection until the drift ends.
#define KART_MOTION_HOP_STEER 0x800
// Set while TryHoldKartStill holds the Kart in place on a standing surface.
#define KART_MOTION_STILL_HOLD 0x1000
// Set while mHitVelocity is still large; the AI then refreshes its side offset.
#define KART_MOTION_HIT_VELOCITY 0x2000
// Set while mAirborneFrames is above 5.
#define KART_MOTION_AIRBORNE_LONG 0x4000
// Set when a drift ends in the air; cleared at the next landing.
#define KART_MOTION_DRIFT_ENDED_IN_AIR 0x8000
// Set by ApplyKartLanding at each landing; cleared by ResetKart.
#define KART_MOTION_LANDED 0x10000
// Set while a map object or moving ground carries the Kart.
#define KART_MOTION_MOVED_BY_OBJECT 0x40000
// Copy of NEAR_KART made by AdvanceKartCollision; the forward speed limit test skips Karts that have it.
#define KART_MOTION_NEAR_KART_HELD 0x80000
// Set while the attractor surface pulls the Kart (ApplyKartAttractorPull).
#define KART_MOTION_ATTRACTOR_PULL 0x100000
// Never set in the code; AdvanceKartDrift ends a drift while it is set, like a contact bit.
#define KART_MOTION_DRIFT_BREAK 0x200000
// Set with START_DONE when the race-start boost is given.
#define KART_MOTION_RACE_START_BOOSTED 0x800000
// Set once the race-start rev phase is over (also set at set-up in the award and staff roll).
#define KART_MOTION_START_DONE 0x1000000
// Set on a course contact with hit bit 0x10000; triples the push strength.
#define KART_MOTION_COURSE_PUSH_STRONG 0x4000000
// Set while the Kart turns on the spot at low speed; ApplyKartTurn then keeps the turn goal.
#define KART_MOTION_LOW_SPEED_TURN 0x8000000
// Set when the AI starts a drift turn; AdvanceKartDrift treats it like the R press.
#define KART_MOTION_AI_DRIFT_REQUEST 0x20000000
// Set when a course contact normal is mostly vertical; ApplyKartLanding skips the landing while set.
#define KART_MOTION_VERTICAL_CONTACT 0x40000000
// Set for one step when a special state ends or the motion state is reset; the surface boosts then restart.
#define KART_MOTION_STATE_RESET 0x80000000

// Bits of Kart.mDriveFlags.
// Set by ApplyKartSurfaceBoostHeld (the boost surface) and read as "the Kart is on a boost surface".
#define KART_DRIVE_ON_BOOST_SURFACE 0x1
// Set while the accelerate button (A) is held.
#define KART_DRIVE_ACCEL_HELD 0x2
// Set while the brake button (B) is held.
#define KART_DRIVE_BRAKE_HELD 0x4
// The Kart steers left in this step (from the input bits or the CPU); ResetKartTurnAndRadius clears both turn bits.
#define KART_DRIVE_TURN_LEFT 0x8
// The Kart steers right in this step.
#define KART_DRIVE_TURN_RIGHT 0x10
// Set while a boost runs (StartKartBoost sets it; mBoostTimer counts it down).
#define KART_DRIVE_BOOST 0x20
// Set while the kart sinks after being placed (ResetKartAndSetPos).
#define KART_DRIVE_SINKING 0x40
// Set when A and B are held together on the ground; the Kart slows and can turn on the spot at low speed.
#define KART_DRIVE_BRAKING 0x80
// Set on the ground while the Kart turns on the spot at low speed.
#define KART_DRIVE_LOW_SPEED_TURN 0x100
// Set while the kart is placed after a fall; mission gates, coins and entry-kart object checks skip it.
#define KART_DRIVE_OBJECTS_SKIP 0x200
// Set when a contact effect was placed for the Kart; the effect fades with COURSE_CONTACT.
#define KART_DRIVE_CONTACT_EFFECT 0x400
// Respawn wait: the kart has fallen off the course and waits to be put back (IsKartInRespawnWait).
#define KART_DRIVE_RESPAWN_WAIT 0x800
// Set when the Kart fell out of the course; no boost, state or push flip can start while set.
#define KART_DRIVE_RESPAWN_FALL 0x1000
// Set at the end of a race or an elimination; ScaleKartForwardSpeed then shrinks mForwardSpeed every step.
#define KART_DRIVE_SLOWING_STOP 0x2000
// Set when a special state hands back to normal driving; AdvanceKartInputAndTurn counts mStateEndTimer down.
#define KART_DRIVE_STATE_END_TIMER 0x4000
// Set when the race-start boost starts (picks the boost sound); cleared by the next boost or when it ends.
#define KART_DRIVE_RACE_START_BOOST 0x8000
// Set while the Kart is moved to a keyed placement point (AdvanceKartToKeyedPlacement).
#define KART_DRIVE_KEYED_PLACEMENT 0x10000
// Set when a hit puts the Kart into a hit state; cleared when the state ends.
#define KART_DRIVE_HIT_STATE 0x20000
// Set by ResetKartMotionState(kart, 0); narrows the input mask IsKartNotNormalOrFlagged tests.
#define KART_DRIVE_INPUT_LOCKED 0x40000
// Set from the release of a fully charged drift until mMiniTurboTimer has counted down.
#define KART_DRIVE_MINI_TURBO 0x80000
// Set while the mushroom boost runs (mKinokoBoostTimer counts it down).
#define KART_DRIVE_KINOKO_BOOST 0x100000
// Set after the course sound table entry of a 0x10 course hit was played once.
#define KART_DRIVE_COURSE_SOUND_PLAYED 0x200000
// Set by ApplyKartSurfaceBoostWithSpeedFloor; a boost then keeps the speed limit goal at 0x8800 or more.
#define KART_DRIVE_BOOST_SPEED_FLOOR 0x400000
// Set with the fall sound 0xce, and by a course hit 0x400 with value 4.
#define KART_DRIVE_FALL_SOUND_A 0x800000
// Set with the fall sound 0x15d.
#define KART_DRIVE_FALL_SOUND_B 0x1000000
// Set by ResetKartToRespawnPoint until the Kart lands; limits the input mask meanwhile.
#define KART_DRIVE_RESPAWN_LANDING 0x2000000
// Set while the scale-table effect holds the Kart still (TryStartKartScaleTableEffect).
#define KART_DRIVE_SCALE_TABLE_EFFECT 0x4000000
// Set in a grand prix while the Kart is far from the entry Kart.
#define KART_DRIVE_FAR_FROM_ENTRY 0x8000000
// Set by the jump-pad surface until the Kart touches the course again; the speed limit goal comes from the surface.
#define KART_DRIVE_JUMP_PAD 0x10000000
// Set by a boost that is not a mini turbo or a respawn boost; cleared with the mushroom boost.
#define KART_DRIVE_ITEM_BOOST 0x20000000
// Set by ApplyKartSurfaceBoostHeld; cleared once the Kart is on the ground off that surface; the camera and AI use the
// Kart's own up vector while set.
#define KART_DRIVE_BOOST_SURFACE_HELD 0x40000000
// Set while AdvanceKartQuaternionFromVector had to flip the sign of the target quaternion.
#define KART_DRIVE_QUATERNION_FLIPPED 0x80000000
// Respawn wait or fall.
#define KART_DRIVE_RESPAWNING (KART_DRIVE_RESPAWN_WAIT | KART_DRIVE_RESPAWN_FALL)
// Any drive state in which the Kart is not driving normally (scale table, respawn landing, input lock, slowing stop,
// respawn wait, sinking).
#define KART_DRIVE_NOT_NORMAL                                                                                          \
    (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT | KART_DRIVE_SLOWING_STOP | KART_DRIVE_KEYED_PLACEMENT |             \
     KART_DRIVE_INPUT_LOCKED | KART_DRIVE_RESPAWN_LANDING | KART_DRIVE_SCALE_TABLE_EFFECT)

// Bits of Kart.mEffectFlags.
// Set in the push flip and push double flip states.
#define KART_EFFECT_PUSH_FLIP_STATE 0x1
// Set in a step when the Kart ran on the ground; StopKartStillHold then skips the surface sound request.
#define KART_EFFECT_GROUND_SOUND_STEP 0x2
// Set while the model scale animation runs (StartKartModelScaleAnimation).
#define KART_EFFECT_MODEL_SCALE_ANIM 0x8
// Set in the flip and spin states; the draw matrix then comes from mRotationQuaternion.
#define KART_EFFECT_TUMBLING 0x10
// Set in the spin state; the draw matrix gets the extra y rotation.
#define KART_EFFECT_Y_SPIN 0x20
// Set while the Kart is a star (StartKartStar).
#define KART_EFFECT_STAR 0x40
// Set while the Kart is small from the Thunder item (StartKartThunderShrink sets it, AdvanceKartThunderShrink clears
// it).
#define KART_EFFECT_THUNDER_SHRINK 0x80
// Set in a step while a shrink animation scales the Kart; TryHoldKartStill refuses then.
#define KART_EFFECT_SHRINK_ANIMATING 0x100
// Set with RESPAWN_DROP; AdvanceKartBoosts times the A press against the landing for a respawn boost.
#define KART_EFFECT_RESPAWN_BOOST_WINDOW 0x400
// Set by ResetKartToRespawnPoint (with 0x400) while the Kart drops onto the track; the landing clears it.
#define KART_EFFECT_RESPAWN_DROP 0x800
// Set on the Kart that started a state for another Kart; the motion slot then plays its sound and character animation.
#define KART_EFFECT_START_SOUND_PENDING 0x1000
// Set while the timed ahead boost runs (StartKartAheadBoost sets it).
#define KART_EFFECT_AHEAD_BOOST 0x2000
// Set while a kart is ahead and the ahead speed limit factor builds up.
#define KART_EFFECT_AHEAD_BUILD_UP 0x4000
// Set each frame on the player kart and the kart one rank ahead (karts 0 to 2 in an award race); effects and side
// points run only while set.
#define KART_EFFECT_NEAR_PLAYER_RANK 0x8000
// Set while the scale-table effect runs (TryStartKartScaleTableEffect).
#define KART_EFFECT_SCALE_TABLE 0x10000
// Set while the model colour blend toward the course colours runs (gesso ink, Teresa).
#define KART_EFFECT_COURSE_COLORED 0x20000
// Set each frame on the kart one rank behind the player.
#define KART_EFFECT_ONE_RANK_BEHIND_PLAYER 0x40000
// Set in a step on both Karts of a pair that overlap deeply.
#define KART_EFFECT_KART_OVERLAP 0x100000
// Set when a respawn wait is started by a course hit 0x800.
#define KART_EFFECT_RESPAWN_WAIT_SET 0x200000
// Set from StartKartBlink for the 90 steps of the blink; the push flips refuse while set.
#define KART_EFFECT_BLINK_GUARD 0x400000
// Set while the kart is behind the camera, outside the view planes or beyond the far distance.
#define KART_EFFECT_OUT_OF_VIEW 0x800000
// Set for the part of the blink cycle where the kart is not drawn.
#define KART_EFFECT_BLINK_HIDDEN 0x1000000
// Set while the Kart wobbles after a push (AdvanceKartWobble draws mWobbleMatrix).
#define KART_EFFECT_WOBBLE 0x2000000
// Set when the Kart fell into water; the water depth effects skip it.
#define KART_EFFECT_WATER_FALL 0x4000000
// Set while the Kart is covered in gesso ink (StartKartGesso).
#define KART_EFFECT_GESSO 0x8000000
// Set while the Kart is a bullet bill (StartKartKiller).
#define KART_EFFECT_KILLER 0x10000000
// Set while mHeadingAngleOffset swings (AdvanceKartRaceStartBoost sets it, AdvanceKartHeadingSwing clears it).
#define KART_EFFECT_HEADING_SWING 0x20000000
// Set while the Kart is on an attractor surface (course hit bit 0x20000); the attractor pull runs.
#define KART_EFFECT_ATTRACTOR 0x40000000
// Set in the launch double flip state once the Kart has landed; the state ends 30 steps later.
#define KART_EFFECT_LAUNCH_ENDING 0x80000000
// Either invincible item runs (star or bullet bill).
#define KART_EFFECT_STAR_OR_KILLER (KART_EFFECT_STAR | KART_EFFECT_KILLER)

// Bits of Kart.mEntryFlags.
// Set once at set-up (InitKartFlags) when mIndex == gRaceSetup.mEntryIndex, i.e. the selected entry.
#define KART_ENTRY_SELECTED 0x1
// Set at set-up when the entry is PLAYER_KIND_CPU (the Kart AI drives it); also set at a race end that hands the Kart
// to the AI.
#define KART_ENTRY_CPU 0x2
// Set at set-up when the entry is PLAYER_KIND_GHOST.
#define KART_ENTRY_GHOST 0x4
// Set when the Kart's race or battle is over (finish, elimination, mission end).
#define KART_ENTRY_ENDED 0x8
// Set at set-up when mKartModelsEntry->mCharacterAnimation != NULL.
#define KART_ENTRY_HAS_CHARACTER_ANIMATION 0x10
// Set by the removal step (battle elimination, a removed race entry, a finished entry-kind-2 Kart). Cleared when the
// Kart is put back at its start.
#define KART_ENTRY_REMOVED 0x20
// Kart is hidden: AdvanceKartRemovalShrink sets it once the removal shrink has finished (25 steps after REMOVED). The
// staff roll sets it on every Kart but the entry Kart and clears it as each one comes into view.
#define KART_ENTRY_HIDDEN 0x40
// Set while the Kart grows back after being put at its start; AdvanceKartMotion then only advances the scale.
#define KART_ENTRY_SCALING_IN 0x80
// Set with BATTLE_END_DONE; never tested alone.
#define KART_ENTRY_BATTLE_END_MARK 0x100
// Set in a wifi race on the selected entry until its race ended; its state changes are sent to the other players.
#define KART_ENTRY_WIFI_LOCAL 0x200
// Set in a wifi race on every Kart that another player (or the ended entry) drives; it follows
// ParticipantKartRecordState.
#define KART_ENTRY_WIFI_PEER 0x400
// Set when StartKartRaceEnd has run for the Kart.
#define KART_ENTRY_RACE_END_STARTED 0x1000
// Set while the Kart is a Teresa (the Boo item, mItemEffect 2); item objects with mHurtsKart pass through it.
#define KART_ENTRY_TERESA 0x2000
// The Kart is drawn translucent (set on the selected entry when its Teresa starts, and when a removal ends).
#define KART_ENTRY_TRANSLUCENT 0x4000
// The Kart is not drawn (the Teresa blink phase of the other Karts, and when a removal ends).
#define KART_ENTRY_NOT_DRAWN 0x8000
// Set when the Kart's result animation is the win one.
#define KART_ENTRY_RESULT_WON 0x10000
// Set when the Kart's result animation is the lose one.
#define KART_ENTRY_RESULT_LOST 0x20000
// Set by StartBattleKartRemoval; the removal shrink only brings the Kart back to its start while it is set.
#define KART_ENTRY_BATTLE_REMOVAL 0x40000
// Set when the removal shrink has brought the Kart back to its start (after 0xb9 steps).
#define KART_ENTRY_BATTLE_RESPAWNED 0x80000
// Set when FinishKartAtBattleEnd has run for the Kart.
#define KART_ENTRY_BATTLE_END_DONE 0x100000
// Set at the race end for a Kart that did not reach the goal in a rule kind 1 race, or in a mission run.
#define KART_ENTRY_DID_NOT_FINISH 0x200000
// Set when the removal has finished and the Kart waits at its start place out of play; item boxes ignore it.
#define KART_ENTRY_PARKED 0x400000
// Set when the race progress removed the Kart (StartKartRemovalFromProgress).
#define KART_ENTRY_REMOVED_BY_PROGRESS 0x800000
// Set with PARKED on every Kart but the selected entry; the Kart is not drawn.
#define KART_ENTRY_NOT_DRAWN_PARKED 0x1000000
// Set when the Kart won (battle winner or rule kind 1 winner); the end screen picks its music from it.
#define KART_ENTRY_WINNER 0x2000000
// Set once the removal has taken the Kart out of the AI non-CPU count.
#define KART_ENTRY_REMOVAL_COUNTED 0x4000000
// Set in time attack and in the award and staff roll; item object hits and Kart collisions are skipped.
#define KART_ENTRY_SKIP_KART_HITS 0x8000000
// Set when FinishKartAtMissionRunEnd has run for the Kart.
#define KART_ENTRY_MISSION_END_DONE 0x10000000
// Set when the entry Kart's race ended or its last balloon was lost; counts as not normal.
#define KART_ENTRY_OUT_OF_ROUND 0x20000000
// A wifi race Kart, local or peer.
#define KART_ENTRY_WIFI_ANY (KART_ENTRY_WIFI_LOCAL | KART_ENTRY_WIFI_PEER)
// Removed or parked.
#define KART_ENTRY_REMOVED_OR_PARKED (KART_ENTRY_REMOVED | KART_ENTRY_PARKED)
// Teresa or parked.
#define KART_ENTRY_TERESA_OR_PARKED (KART_ENTRY_TERESA | KART_ENTRY_PARKED)
// Removed, parked or Teresa.
#define KART_ENTRY_REMOVED_PARKED_OR_TERESA (KART_ENTRY_REMOVED | KART_ENTRY_TERESA | KART_ENTRY_PARKED)

// The values of Kart.mState; each indexes gKartStateFunctions.
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

// The values of Kart.mDriftCharge: the charge level of a drift. LEVEL_2 and LEVEL_3 start their effects; the drift
// gives a mini-turbo boost when it ends at MINI_TURBO_READY.
enum {
    KART_DRIFT_CHARGE_NONE,
    KART_DRIFT_CHARGE_STARTED,
    KART_DRIFT_CHARGE_LEVEL_2,
    KART_DRIFT_CHARGE_LEVEL_3,
    KART_DRIFT_CHARGE_MINI_TURBO_READY
};

// Frames until another turn press counts for the drift charge (Kart.mTurnCountTimer).
#define KART_TURN_COUNT_INTERVAL_FRAMES 10

// Surface groups (Kart.mSurfaceGroup) of the two surface kind sets that give a boost of KART_SURFACE_BOOST_FRAMES; the
// kart on the same group the next frame only keeps the boost timer instead of starting a boost.
#define KART_SURFACE_GROUP_BOOST_A 8
#define KART_SURFACE_GROUP_BOOST_B 0xb
#define KART_SURFACE_BOOST_FRAMES 60
// Kart.mBoostTimer of a kart that replays a recorded boost bit.
#define KART_RECORDED_BOOST_FRAMES 3

// Kart.mRotationAnglePerFrame at the start of the launch double flip (it falls by the decay factor each frame down to
// the minimum) and at the start of the flip.
#define KART_LAUNCH_FLIP_ANGLE_PER_FRAME 0xfa0
#define KART_LAUNCH_FLIP_ANGLE_PER_FRAME_MIN 0xc8
#define KART_LAUNCH_FLIP_ANGLE_DECAY FIXED12_RATIO(97, 100)
#define KART_FLIP_ANGLE_PER_FRAME 0x666
// Values of Kart.mItemEffectData.mGessoFrames at which the course colors are in and at which the Gesso ends.
#define KART_GESSO_COLORED_FRAME 400
#define KART_GESSO_END_FRAME 450
// Kart.mRespawnFrames at which the respawn sets the fade flag, starts the fade to faded, sets the follow-kart state
// and ends.
#define KART_RESPAWN_FADE_FLAG_FRAME 22
#define KART_RESPAWN_FADE_OUT_FRAME 25
#define KART_RESPAWN_FOLLOW_KART_FRAME 85
#define KART_RESPAWN_END_FRAME 120

typedef struct Kart {
    // Sound source of the Kart (the sounds started on it).
    /* 00 */ SoundSource mSoundSource;
    /* 44 */ vu32 mMotionFlags;
    /* 48 */ vu32 mDriveFlags;
    /* 4c */ vu32 mEffectFlags;
    /* 50 */ Vec3 mTurnedForward;
    /* 05c */ Vec3 mSignedTurnedForward;
    /* 68 */ Vec3 mEasedTurnedForward;
    /* 74 */ u16 mIndex;
    /* 76 */ u8 mUnk_76[0x2];
    /* 78 */ s32 mEntryIndex;
    /* 7c */ vu32 mEntryFlags;
    /* 80 */ Vec3 mPos;
    /* 8c */ Vec3 mPrevPos;
    // Copy of the kart position made when the draw matrix is built; until then it holds the position of one step
    // earlier.
    /* 98 */ Vec3 mDrawMatrixPos;
    /* a4 */ Vec3 mVelocity;
    /* b0 */ Vec3 mVelocityDirection;
    // Size scale of the kart (x, y, z; 0x1000 = 1.0): mScaleBase times mScaleFactor per axis, y also times
    // mScaleYFactor. Zero at the start placement (ResetKartToStartPlacement) and where the kart is moved to a far
    // corner (AdvanceKartRemovalShrink, FinishKartAtBattleEnd).
    /* bc */ Vec3 mScale;
    // Negative step added by ApplyKartGravity to mVerticalSpeed, by AdvanceKartHop to mHopSpeed while hopping and to a
    // speed of the mode-5 record; -0x2b9 at reset, 0 after the water-height branch of StartKartRespawnWait.
    /* c8 */ s32 mGravity;
    // The value mSpeedLimit follows: it falls by x0xf37/0x1000 per step but never below it and rises to it at once.
    // Written by the step, by the companion objects (their own choice) and at set-up; read by the companion objects as
    // the kart's limit.
    /* cc */ s32 mSpeedLimitGoal;
    /* d0 */ s32 mSpeedLimit;
    /* d4 */ u32 mSpeedLimitGroundFactor;
    /* d8 */ s32 mAheadSpeedLimitFactor;
    /* dc */ s32 mSpeedLimitFactor;
    /* e0 */ union {
        struct {
            s32 mUnk_e0;
            Vec3 mUnk_e4;
            Vec3 mUnk_f0;
            u32 mUnk_fc;
            s32 mUnk_100;
            struct CollisionHitLink *mUnk_104;
            Vec3 mUnk_108;
            u8 mUnk_114[6];
            s16 mUnk_11a;
            s32 mUnk_11c;
        };
        struct {
            Vec4 mHeadingQuaternion;
            Vec4 mTiltQuaternion;
            Vec4 mAirTiltQuaternion;
            Vec4 mCombinedQuaternion;
        };
    };
    /* 120 */ union {
        struct {
            Vec3 mRotationRow0;
            Vec3 mRotationRow1;
            Vec3 mRotationRow2;
            Vec3 mRotationRow3;
        };
        MtxFx43 mRotationMatrix;
    };
    /* 150 */ union {
        struct {
            Vec3 mDrawBaseRow0;
            Vec3 mDrawBaseRow1;
            Vec3 mDrawBaseRow2;
            Vec3 mDrawBaseRow3;
        };
        MtxFx43 mDrawBaseMatrix;
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
    // Current radius: the record's radius times two scales, set from the record at creation.
    /* 1d0 */ s32 mRadius;
    /* 1d4 */ s32 mScaledPointAlongUpExtra;
    /* 1d8 */ Vec3 mPointAlongUp;
    /* 1e4 */ Vec3 mPrevPointAlongUp;
    /* 1f0 */ Vec3 mSecondCollisionCenter;
    /* 1fc */ Vec3 mPointMotion;
    /* 208 */ struct CollisionHitLink *mCollisionHitLink;
    // The functions of one Kart, one per slot index: 0 set-up at creation, 1 reset to the starting values, 2 stores the
    // squared distance in the sound source, 3 and 4 the two steps UpdateKarts runs for every Kart, 5 stores the
    // previous collision center, 6 respawn, 7 start placement, 8 does nothing. 7 and 8 are never called. InitKart fills
    // it from gKartDefaultSlotFunctions and replaces slots 2 to 5; it also replaces slots 3 and 4 with an empty
    // function when gRace.mUseChainCameras is set and RaceSetup.mRaceKind is not 5.
    /* 20c */ void (*mSlotFunctions[9])(struct Kart *);
    /* 230 */ void (*mAdvanceOffsetCycle)(struct Kart *);
    /* 234 */ s16 mAirTiltAngle;
    // Angle about world up that orients the kart (0x10000 per turn): set from a direction vector or a start rotation,
    // turned by the step functions and by mHeadingAnglePerFrame; mHeadingAngleOffset is added on top when the
    // orientation is built.
    /* 236 */ u16 mHeadingAngle;
    /* 238 */ s16 mBoostTimer;
    /* 23a */ s16 mStateEndTimer;
    /* 23c */ s16 mMiniTurboTimer;
    /* 23e */ u8 mUnk_23e[2];
    /* 240 */ u32 mTurnedForwardEaseFactor;
    /* 244 */ Vec3 mGroundNormal;
    /* 250 */ Vec3 mCourseContactNormal;
    /* 25c */ union {
        Vec3 mUnk_25c;
        struct {
            /* 25c */ s32 mUnk_25c_x;
            // Vertical speed added to mVelocity.y after mVelocity is rebuilt each step, so it persists; mGravity is
            // added to it, it is reset to -0x2b9 or -0xd9d on a ground hit while negative, and a hop start adds a kick.
            /* 260 */ s32 mVerticalSpeed;
            /* 264 */ u8 mUnk_264[4];
        };
    };
    /* 268 */ Vec3 mAttractorPullDirection;
    /* 274 */ s32 mAttractorPullSpeed;
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
    /* 2b6 */ u8 mUnk_2b6[2];
    // Vertical speed of the hop arc: 0x1405 at the start (AdvanceKartDrift), mGravity added each step by
    // AdvanceKartHop, integrated into mHopHeight, 0 once the height is below 0.
    /* 2b8 */ s32 mHopSpeed;
    // Height of the hop arc, integrated from mHopSpeed; 0 at the start and when it would go below 0. The camera, its
    // look-at and the replay record subtract it from mPos.y.
    /* 2bc */ s32 mHopHeight;
    // Angle about the x axis that tilts the kart while mHopSpeed > 0 and KART_MOTION_HOPPING is set (0x9c4 minus
    // mHopHeight * 500 / 0x1000, 0x352 when that exceeds 0x6a4); 0 otherwise. 0x10000 per turn.
    /* 2c0 */ u16 mHopTiltAngle;
    /* 2c2 */ u8 mUnk_2c2[2];
    // Sign 1 / -1 / 0 of a turn, latched when it starts (from KART_DRIVE_TURN_RIGHT / KART_DRIVE_TURN_LEFT, or from the
    // entry's input bits 0x10 / 0x20) and cleared when it ends; read only as a sign.
    /* 2c4 */ s32 mTurnDirection;
    /* 2c8 */ s16 mCollisionSlot;
    /* 2ca */ s16 mSecondCollisionSlot;
    // Pointer to this slot's KartPhysicalParam; set once in InitKartPhysicalParams. The record is shared by nothing
    // else.
    /* 2cc */ KartPhysicalParam *mPhysicalParam;
    // Two words of charphysicalparam.bin for the entry's character: [0] scales the surface factors below 0x1000, [1] is
    // added to mWeight.
    /* 2d0 */ s32 *mCharPhysicalParam;
    /* 2d4 */ s32 mTurnRatio;
    /* 2d8 */ Vec3 mHitVelocity;
    /* 2e4 */ Vec3 mPrevHitVelocity;
    /* 2f0 */ Vec3 mPrevPrevHitVelocity;
    /* 2fc */ s32 mDriftCharge;
    /* 300 */ u16 mLeftTurnCount;
    /* 302 */ u16 mRightTurnCount;
    /* 304 */ u16 *mAwayTurnCounter;
    /* 308 */ u16 *mTowardTurnCounter;
    /* 30c */ s32 mTurnCountTimer;
    /* 310 */ struct KartAi *mAi;
    /* 314 */ u16 mRotationAngle;
    /* 316 */ u8 mUnk_316[2];
    /* 318 */ s32 mRotationAngleSum;
    /* 31c */ Vec3 mRotationAxis;
    /* 328 */ Vec3 mLaunchForward;
    /* 334 */ s32 mLaunchAxisSwing;
    /* 338 */ u16 mLaunchAxisSwingAngle;
    /* 33a */ u8 mUnk_33a[2];
    /* 33c */ s32 mLaunchAxisSwingAngleSum;
    /* 340 */ s32 mLaunchStartY;
    /* 344 */ s32 mUnk_344;
    /* 348 */ s32 mLaunchFrames;
    /* 34c */ Vec4 mRotationQuaternion;
    /* 35c */ s16 mRotationEndFrames;
    /* 35e */ u8 mUnk_35e[2];
    /* 360 */ s32 mRotationAnglePerFrame;
    /* 364 */ u16 mYRotationAngle;
    /* 366 */ u16 mYRotationCount;
    /* 368 */ s32 mYRotationAngleSum;
    /* 36c */ s32 mYRotationAnglePerFrame;
    /* 370 */ u16 mVerticalSpeedStepCount;
    /* 372 */ u8 mUnk_372[2];
    /* 374 */ Vec3 mCollisionPushVelocity;
    // Calls of UpdateKartAirborne since KART_MOTION_ON_GROUND was last set; not every step (skipped below
    // y = 0).
    /* 380 */ u32 mAirborneFrames;
    // Draw gate of the kart: 0xffff while it is drawn, 0 when DrawKart skips it (hidden states, or the off phase of
    // the blink); other draw code skips its drawing while it is 0; 0 at reset for an entry of kind 2.
    /* 384 */ u16 mVisible;
    // Angle added to mHeadingAngle each step, first multiplied by 0xe66 / 0x1000 and cut to 0 below 0x14; set in
    // ApplyKartContact, 0 at reset.
    /* 386 */ s16 mHeadingAnglePerFrame;
    // Angle that follows mTurnDirection: eased toward 11000 or -11000, changed by the turn input and cut back to 0 on
    // the ground; it is the angle of the rotation of mUnk_278 about mUnk_244 in AdvanceKartByVelocity.
    /* 388 */ s16 mTurnAngle;
    /* 38a */ s16 mDriftHeadingAnglePerFrame;
    /* 38c */ s32 mSpeedLimitHitFactor;
    /* 390 */ u8 mUnk_390[4];
    /* 394 */ s32 mShrinkFactor;
    /* 398 */ s32 mUnk_398;
    /* 39c */ s32 mMapObjectVectorLength;
    /* 3a0 */ s32 mMapObjectVectorForwardDot;
    // Angle of the tire object about the x axis (0x10000 per turn), advanced each step in AdvanceKartDrawState from the
    // speed ratio and used by DrawKart; 0 at reset.
    /* 3a4 */ u16 mTireSpinAngle;
    /* 3a6 */ u8 mUnk_3a6[2];
    /* 3a8 */ s32 mQuaternionBlendFactor;
    /* 3ac */ u16 mSinkFrames;
    /* 3ae */ u8 mUnk_3ae[2];
    // mVelocity, minus mVerticalSpeed on a floor hit, shifted right by 4 each step (AdvanceKartEffects); copied or
    // scaled into the velocity (mUnk_40) of effect objects.
    /* 3b0 */ Vec3 mEffectVelocity;
    /* 3bc */ u16 mUnk_3bc;
    /* 3be */ u16 mRaceStartFrameCount;
    /* 3c0 */ s16 mRespawnFrames;
    /* 3c2 */ u8 mUnk_3c2[2];
    // Number of the course respawn slot this Kart goes back to, set when it falls or when it respawns with none chosen;
    // -1 means none chosen (ResetKart writes -1).
    /* 3c4 */ s32 mRespawnSlot;
    /* 3c8 */ s16 mFramesSinceRemovalOrReset;
    /* 3ca */ u8 mUnk_3ca[2];
    /* 3cc */ s32 mSoundIndex;
    /* 3d0 */ s16 mKartIndexModThree;
    // Countdown of 0x14 set on the slower kart of a kart-kart contact in CollideKartWithKarts and counted down by
    // AdvanceKartCollisionTimer, which calls StartKartCollisionSound at 0 (what that call does is unknown).
    /* 3d2 */ s16 mKartCollisionTimer;
    /* 3d4 */ s16 mKartCollisionDelayTimer;
    /* 3d6 */ u8 mUnk_3d6[2];
    /* 3d8 */ s32 mRank;
    // Result of the handler: index into the two 12-entry tables of the record; -1 when the floor is left; compared with
    // 8 and 0xb. Group meanings unknown.
    /* 3dc */ s32 mSurfaceGroup;
    // Bits 8..12 of the attribute of the strongest ground hit (mask 0x1e34ef); indexes gKartSurfaceFunctions; 0 after
    // reset.
    /* 3e0 */ s32 mSurfaceKind;
    // Bits 5..7 of the same attribute: second selector (effect tables).
    /* 3e4 */ s32 mSurfaceVariant;
    /* 3e8 */ s16 mAirTiltAngleOffset;
    /* 3ea */ u8 mUnk_3ea[2];
    /* 3ec */ s32 mTurnHeadingAnglePerFrameGoal;
    /* 3f0 */ s32 mTurnHeadingAnglePerFrame;
    /* 3f4 */ s32 mSpeedLimitFactorPerDepth;
    /* 3f8 */ s32 mVelocityScaleFactor;
    /* 3fc */ u16 mModelScaleKind;
    /* 3fe */ u16 mModelScaleFrameIndex;
    /* 400 */ u16 mModelScaleFrameCount;
    /* 402 */ u8 mUnk_402[2];
    /* 404 */ s32 mModelScaleY;
    /* 408 */ s32 mModelOffsetY;
    /* 40c */ s32 mRespawnLandRaceFrame;
    /* 410 */ s32 mRespawnPressRaceFrame;
    /* 414 */ s32 mModelScaleX;
    /* 418 */ s32 mModelScaleZ;
    // Part of mScale looked up in three tables (x, y, z) of 25 entries (0x800 up to 0x1000) by a step counter, forwards
    // or backwards; 0x1000 when no step runs.
    /* 41c */ Vec3 mScaleFactor;
    // Part of mScale held at 0x1000, eased down to 0x800 while the countdown of AdvanceKartThunderShrink runs and set
    // back to 0x1000 at its end; mScaleFactor is the table-driven part.
    /* 428 */ Vec3 mScaleBase;
    // Factor of mScale.y only: 0x1000 normally, lowered by 0x4cd per call to a floor of 0x4cd in
    // AdvanceKartScaleTableEffect.
    /* 434 */ s32 mScaleYFactor;
    /* 438 */ struct MapObject *mPrevTouchingMapObjects[2];
    /* 440 */ u16 mMapObjectSoundFrames[2];
    /* 444 */ s32 mMapObjectSoundPlayed[2];
    /* 44c */ struct MapObject *mScaleEffectMapObject;
    /* 450 */ KartSound mSound;
    /* 4bc */ s32 mRespawnWaitVelocityScale;
    /* 4c0 */ s32 mCourseHitAttributeBit;
    /* 4c4 */ s32 mSurfaceSpeedLimitGoal;
    /* 4c8 */ s32 mRadiusFactor;
    /* 4cc */ s32 mTireTurnAngle;
    /* 4d0 */ u32 mCollisionStepFrames;
    /* 4d4 */ s32 mRevLevel;
    /* 4d8 */ s16 mAttractorIndex;
    /* 4da */ s16 mCourseHitTimer;
    /* 4dc */ s16 mLandingTimer;
    // Angle added to mHeadingAngle when the orientation is built, never to mHeadingAngle itself;
    // AdvanceKartHeadingSwing swings it back and forth and sets it to 0 at the end.
    /* 4de */ s16 mHeadingAngleOffset;
    // Angle added to mHeadingAngleOffset each step by AdvanceKartHeadingSwing; changed by 0x3c per call toward the
    // swing direction and clamped to 0x17c, later 0xd2; 0 at reset.
    /* 4e0 */ s16 mHeadingAngleOffsetPerFrame;
    /* 4e2 */ s16 mHeadingAngleOffsetDirection;
    /* 4e4 */ u16 mHeadingAngleOffsetCount;
    /* 4e6 */ u8 mUnk_4e6[2];
    /* 4e8 */ s32 mOffsetCyclePhaseStep;
    /* 4ec */ s32 mOffsetCyclePhase;
    /* 4f0 */ Vec3 mOffsetCycleAmount;
    /* 4fc */ u16 mOffsetCycleIndex;
    /* 4fe */ u8 mUnk_4fe[2];
    /* 500 */ u32 mWaterDepth;
    /* 504 */ u16 mBlinkFrames;
    /* 506 */ u16 mBlinkCycleFrames;
    // Points to mPos, or in mode 5 to a Vec3 of the received record; set in InitKart.
    /* 508 */ Vec3 *mPosSource;
    /* 50c */ Vec4 *mRotationSource;
    /* 510 */ Vec3 *mCollisionPosSource;
    /* 514 */ ParticipantKartRecordState *mParticipantRecordData;
    /* 518 */ SoundDistanceSquaredChange mSoundDistanceSquaredChange;
    /* 534 */ Vec3 *mPosSourceCopy;
    /* 538 */ KartItemEffectState mItemEffectData;
    /* 590 */ struct KartModelsEntry *mKartModelsEntry;
    /* 594 */ s32 mWobbleAmplitude;
    /* 598 */ s16 mWobbleDirection;
    /* 59a */ u8 mUnk_59a[2];
    /* 59c */ s32 mWobbleEasedAmplitude;
    /* 5a0 */ u16 mWobbleAngle;
    /* 5a2 */ u8 mUnk_5a2[2];
    /* 5a4 */ s32 mWobbleSine;
} Kart;

// Jg: the object built from the jg_* files plus lap_count and lap_final; this is the kart it follows.
extern Kart *gJgKart;

void StartKartState(Kart *kart, KartState mode);
BOOL IsKartOutOfView(Kart *kart);
int GetKartCourseHitAttributeBit(Kart *kart);
BOOL IsKartRemovedOrRespawning(Kart *kart);
BOOL IsKartNotNormal(Kart *kart);
void SetupKartAiItemInUseEntry(Kart *kart);
void SetupKartAiHeldItemEntry(Kart *kart);
void StartKartBlink(Kart *kart);
void PlaceEffectBehindKart(ParticleEmitter *emitter, Kart *kart);
void SetEffectFlatVelocityFromKart(ParticleEmitter *emitter, Kart *kart);
BOOL TryStartKartCollisionEffects(Kart *kart, const Vec3 *overlapDirection, int flag);
void SetEffectVelocityFromKart(ParticleEmitter *emitter, Kart *kart);
void SetEffectScaleFromKart(ParticleEmitter *emitter, Kart *kart);

void StartEffectWithCallback(u32 idx, const Vec3 *pos, void *splManager, void (*cb)());
int TryTurnKartAtLowSpeed(Kart *kart);
void AdvanceKartDriftTurnAngle(Kart *kart, int fromLowSpeedTurn);
#include "Main/Sound/code_0210ab48.h"
void EndKartDrift(Kart *kart);
void AdvanceKartBoost(s32 *acceleration, Kart *kart);
extern SoundRequestQueue gSoundRequestQueues[7];
#include "Main/Sound/sound_request_queue.h"
void RequestKartSound(void *kart, int arg);
void KartStartSoundFullVolume(void *soundSource, int arg);
#include "Main/Item/code_021035ac.h"
BOOL TrySpinKart(Kart *kart, int rotationCount, int skipSound);
BOOL TryStartKartState(Kart *kart, KartState newState);
void AdvanceKartDrift(Kart *kart);
void GetKartForward(const Kart *kart, Vec3 *forward);
void GetKartUp(const Kart *kart, Vec3 *upDirection);

#include "Main/Kart/character_animation.h"
#include "Main/Kart/code_02079c0c.h"
#include "Main/MapObjects/data_02165000.h"

typedef struct Kart Kart;

// The kind passed to StartKartBoost.
typedef enum {
    // The mushroom and the boost surfaces.
    KART_BOOST_ITEM_OR_SURFACE,
    // The release of a fully charged drift.
    KART_BOOST_MINI_TURBO,
    // At the end of the race start sequence.
    KART_BOOST_RACE_START,
    // On landing after a respawn.
    KART_BOOST_RESPAWN
} KartBoostKind;

void StartKartBoost(Kart *kart, KartBoostKind boostKind, s16 boostFrames);
void StartKartSoundAndCharacterAnimation(Kart *kart);
void ApplyItemObjectHitToKart(Kart *kart);
void UpdateKartAheadEffect(Kart *kart);
void ApplyKartPush(Kart *pushingKart, Kart *pushedKart, const Vec3 *contactDirection, s32 storeDirection, Vec3 *out);
BOOL TryStartKartPushDoubleFlip(Kart *killerKart, Kart *hitKart);
BOOL TryStartKartPushFlip(Kart *starKart, Kart *hitKart, const Vec3 *pushDirection);

void CollideKartWithKarts(Kart *kart);

void CollideKartWithMapObjects(Kart *kart);
void ApplyKartLanding(Kart *kart, Vec3 *groundNormal);

extern const Vec4 gKartResetHeadingQuaternion;
extern const Vec4 gKartResetSecondQuaternion;
extern const int gKartCollisionSingleEffectIds[1];
extern const Vec4 gKartResetRotationQuaternion;
extern const Vec4 gKartResetThirdQuaternion;
extern const Vec4 gKartResetFourthQuaternion;

extern s32 gFirstBaseSpeedLimitReciprocal;
extern Vec3 gKartPlacementHeadingAxis;
extern Vec4 gKartLaunchDoubleFlipTargetQuaternion;
extern Vec3 gFixedPositionSelectedEffectIds;
extern KartKillerEndRankOffsets gKartKillerEndRankOffsets;
extern s16 gKartFlipEndFrameCount;
extern s32 gKartAheadSpeedLimitStartFactor;
extern s16 gTurnHeadingReductionAtSpeedLimit;
extern s32 gKartWobbleAmplitudeDecay;
// The functions every Kart starts with, copied into Kart.mSlotFunctions by InitKart. Slots 0, 1, 6, 7 and 8 keep these;
// slots 2 to 5 are zero here and always replaced by InitKart.
extern void (*gKartDefaultSlotFunctions[9])(Kart *kart);
extern Vec3 gFixedPositionEffectPos;
extern void (*gKartStateFunctions[8])(struct Kart *);
extern s32 gKartFlipStartVerticalSpeed;
extern s32 gKartWobbleAngleFactor;
extern s32 gKartFlipSecondLandVerticalSpeed;
extern s32 gKartPushFlipStartVerticalSpeed;
extern Vec3 gKartPointMotionDecayFactors;
extern s32 gKartRespawnOffsetScale;
extern s32 gKartJumpPadVerticalSpeeds[5];
extern s32 gKartFlipFirstLandVerticalSpeed;
extern s32 gKartWobbleEaseFactor;
extern s32 gKartJumpPadSpeedLimitGoals[5];
extern s32 gKartPushFlipStartAnglePerFrame;
extern Vec3 gParticipantRecordHeadingAxis;
extern s32 gKartOverlapLengthLimit;
extern s32 gKartPushDoubleFlipLandVerticalSpeed;
extern KartEffectScales gKartRaceStartEffectOffsets;
extern s32 gTurnHeadingEaseFactor;
extern KartFollowEffectIds gKartFollowEffectIds;
typedef struct KartSurfaceSoundIds {
    /* 00 */ u32 mSoundIds[3];
} KartSurfaceSoundIds;

extern KartSurfaceSoundIds gKartSurfaceSoundIds;
extern u16 gKartWobbleAnglePerCall;
extern s32 gKartPushDoubleFlipStartAnglePerFrame;
extern s32 gFixedPositionOtherEffectIds[2];
extern s32 gKartPushFlipAngleDecay;
extern s32 gSpeedReductionAtFullTurnRatio;

// Frames Kart.mLandingTimer is set to at a landing.
#define KART_LANDING_FRAMES 7
// A fall that lasted longer than this many frames makes the landing bounce.
#define KART_BOUNCE_LANDING_AIRBORNE_FRAMES 0x19
// A landing after more airborne frames than this, with the kart nose down by more than the tilt, slows the kart.
#define KART_LANDING_SLOWDOWN_AIRBORNE_FRAMES 0x14
#define KART_LANDING_SLOWDOWN_MIN_TILT 0x3e8
// A map object pushes the kart only when the vector to it is longer than this.
#define KART_MAP_OBJECT_PUSH_MIN_LENGTH 0x1000
// Frames after which a map object sound played for a touched object may play again.
#define KART_MAP_OBJECT_SOUND_FRAMES 10
// Kart.mVelocityLength a kart needs before a kart-to-kart contact bumps it, and the frames that bump timers run.
#define KART_COLLISION_BUMP_MIN_SPEED 0x1000
#define KART_COLLISION_TIMER_FRAMES 0x14
#define KART_COLLISION_DELAY_FRAMES 0xf
// The ahead build-up starts above this speed of the kart and counts karts that go at least the second speed.
#define KART_AHEAD_BUILD_UP_MIN_SPEED 0x4000
#define KART_AHEAD_OTHER_MIN_SPEED 0x2000
// The ahead boost starts once KartItemEffectState.mAheadCount is above this.
#define KART_AHEAD_BOOST_MIN_COUNT 0xf
// Frames a mushroom boost lasts.
#define KART_KINOKO_BOOST_FRAMES 0x5a
// Largest absolute Kart.mTurnAngle while steering or drifting.
#define KART_MAX_TURN_ANGLE 11000
// Smallest Kart.mDriftHeadingAnglePerFrame during a drift.
#define KART_DRIFT_HEADING_MIN 50
// The air drift can arm only after the kart was airborne for at least this many frames.
#define KART_DRIFT_ARM_MIN_AIRBORNE_FRAMES 5
// Kart.mHopSpeed and the vertical speed added when a hop starts.
#define KART_HOP_SPEED 0x1405
#define KART_HOP_VERTICAL_SPEED 0x21a2
// The low speed turn on the spot is possible below this Kart.mVelocityLength.
#define KART_LOW_SPEED_TURN_MAX_SPEED 0x1800
// A map object spins the kart when it is hit above this Kart.mVelocityLength (or the object has
// MAP_OBJECT_FLAG_HIT_AT_ANY_SPEED).
#define KART_MAP_OBJECT_SPIN_MIN_SPEED 0x3000

// Values of Kart.mModelScaleKind: which scale tables the model scale animation plays (a normal landing, a landing after
// a hop or a long fall, a bump), and the frames it runs.
#define KART_MODEL_SCALE_LAND 0
#define KART_MODEL_SCALE_HARD_LAND 1
#define KART_MODEL_SCALE_BUMP 2
#define KART_MODEL_SCALE_FRAMES 0xf
// More airborne frames than this make the landing scale a hard landing.
#define KART_HARD_LAND_AIRBORNE_FRAMES 0xa
// Floors of Kart.mRespawnWaitVelocityScale below which the wait stops shrinking it: after a fall into water, and for
// the other respawn waits.
#define KART_WATER_FALL_WAIT_MIN_SCALE 0x19a
#define KART_RESPAWN_WAIT_MIN_SCALE 0x666
// Kart.mSpeedLimit a reset kart starts with.
#define KART_START_SPEED_LIMIT 0xd000
// Kart.mVisible with every bit set: visible to every camera.
#define KART_VISIBLE_ALL 0xffff
// Kart.mOffsetCyclePhaseStep a reset kart starts with.
#define KART_OFFSET_CYCLE_START_PHASE_STEP 0x1000
// The sound a kart starts with (Kart.mSound.mSoundId and mVolume) after a reset.
#define KART_START_SOUND_ID 0xa5
#define KART_START_SOUND_VOLUME 0x64
// Heading swing at the race start: swings counted before it settles, and the largest heading change per frame while it
// swings and while it settles.
#define KART_HEADING_SWING_LAST_COUNT 2
#define KART_HEADING_SWING_MAX_PER_FRAME 0x17c
#define KART_HEADING_SWING_SETTLE_MAX_PER_FRAME 0xd2
// Kart.mForwardSpeed and mVerticalSpeed given by the keyed placement and by the placement that ends a respawn.
#define KART_RESPAWN_PLACEMENT_FORWARD_SPEED 0x1e000
#define KART_KEYED_PLACEMENT_FORWARD_SPEED 0x5000
#define KART_KEYED_PLACEMENT_VERTICAL_SPEED 0x3000
// The air tilt starts at this Kart.mVelocityLength.
#define KART_AIR_TILT_MIN_SPEED 0x1000
// Kart.mCollisionStepFrames at the start, and the frames after which a kart held still is placed back.
#define KART_COLLISION_STEP_FRAMES_FULL 0x64
