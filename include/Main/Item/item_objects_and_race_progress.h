#pragma once

#include "types.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Course/course_color_blend.h" // CourseColorBlend
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_drift.h"
#include "matrix_3x3_basic.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/map_object_park.h" // RandomState64
#include "Main/System/backup_net_camera_work.h" // MinuteSecondMillisecondTime

// Item point links with at least this radius (1000.0) are entered in gItemPointLinksByIndex.
#define ITEM_POINT_LINK_INDEXED_RADIUS 0x3e8000

// Frames (60 seconds) that ItemObject.mHitLinkTimer counts from when the hit link has an object.
#define ITEM_OBJECT_HIT_LINK_TIMER_FRAMES 0xe10
// ItemObject.mOwnerKartIndexAndFlags bit 15: the owner is not a kart.
#define ITEM_OBJECT_OWNER_NOT_KART 0x8000
// ItemObject.mFlags: set while the item is on a course hit attribute (the map screen shows it translucent); set when
// the item ends and fades out.
#define ITEM_OBJECT_FLAG_COURSE_HIT_ATTRIBUTE 0x40000
#define ITEM_OBJECT_FLAG_ENDED 0x80000

// One item point: the links that follow it and come before it, and a pointer to its position.
typedef struct ItemPointLink {
    /* 00 */ struct ItemPointLink *mNextLinks[3];
    /* 0c */ struct ItemPointLink *mPreviousLinks[3];
    /* 18 */ Vec3 *mPointPos;
    /* 1c */ s32 mRadius;
    /* 20 */ u8 mLinkIndex;
    /* 21 */ s8 mDirectionX;
    /* 22 */ s8 mDirectionY;
    /* 23 */ s8 mDirectionZ;
    /* 24 */ u16 mNextCount;
    /* 26 */ u16 mPreviousCount;
} ItemPointLink;

// A link and which of its two lists is read.
typedef struct ItemPointLinkRef {
    /* 00 */ ItemPointLink *mLink;
    /* 04 */ s32 mNextLinksUsed;
} ItemPointLinkRef;

// Polygon ids of the item models: the id the models of the pool objects start with, and the id from the object at index
// ItemPool.mActiveCount on (DrawItemPoolModels).
#define ITEM_MODEL_POLYGON_ID 4
#define ITEM_MODEL_POLYGON_ID_BEYOND_ACTIVE 3

// Number of positions in SegmentPoints (a ring).
#define SEGMENT_POINT_COUNT 4

// Four positions and pointers to them.
typedef struct {
    /* 00 */ SegmentProgress mSegmentProgress;
    /* 60 */ s32 mWriteIndex;
    /* 64 */ Vec3 *mPointPointers[SEGMENT_POINT_COUNT];
    /* 74 */ Vec3 mPoints[SEGMENT_POINT_COUNT];
} SegmentPoints;

extern SegmentProgress gJgSegmentProgress;

// ItemObject.mAlpha of a fully opaque item (the polygon alpha has five bits).
#define ITEM_OBJECT_ALPHA_OPAQUE 0x1f

// ItemObject.mRadius and mCourseRadius that ResetItemObject gives every object until its kind sets its own.
#define ITEM_OBJECT_INITIAL_RADIUS 0x7b

// Frames after a course hit (ItemObject.mFramesSinceCourseHit, mFramesSinceReset) that still count as recent; the
// counters start at this value when no hit happened.
#define ITEM_OBJECT_RECENT_HIT_FRAMES 5

// ItemObject.mAlpha below which a fading object gives up its collision slot.
#define ITEM_OBJECT_FADE_ALPHA_NO_COLLISION 0xa

// A resting object re-tests its hit link on the frames whose number modulo 8 equals ItemObject.mCreationNumber & this.
#define ITEM_OBJECT_CREATION_PHASE_MASK 7

// ItemObject.mScaleTargetOrSpeed and the gap of mScale.x and mScale.y below which the scale swing is at rest.
#define ITEM_OBJECT_SCALE_SWING_REST 0x29

// ItemObject.mPendingUpdateCount bit set when the object has frames to catch up.
#define ITEM_OBJECT_PENDING_UPDATE_CATCH_UP 0x8000

// Age (5 seconds) after which a resting object counts as old and may be released.
#define ITEM_OBJECT_OLD_FRAMES 0x12c

// Bits of ItemObject.mFlags. The low 12 bits are events of the current frame: UpdateItemObject clears them first.
// Frames of ItemObject.mFramesSinceCourseHit and mFramesSinceReset that count as recent; the frames
// ItemObject.mCourseReleaseTimer runs for after a course hit on a resting object and on any other object; the bits of
// ItemObject.mDistanceSquaredAndFlags the view test sets when the object is outside the view; the object age after
// which an excluded owner is free again (once it has a course hit, and without waiting for one).
#define ITEM_OBJECT_RECENT_HIT_FRAMES 5
#define ITEM_OBJECT_RESTING_RELEASE_FRAMES 0xb4
#define ITEM_OBJECT_COURSE_RELEASE_FRAMES 2
#define ITEM_OBJECT_VIEW_TEST_OUTSIDE_BITS 3
#define ITEM_OBJECT_EXCLUDED_AFTER_HIT_AGE_FRAMES 4
#define ITEM_OBJECT_EXCLUDED_AGE_FRAMES 0x1e
// Fade-out (ITEM_OBJECT_FLAG_FADING_OUT) began this frame.
#define ITEM_OBJECT_FLAG_FADE_OUT_STARTED 0x1
// The release timer (ITEM_OBJECT_FLAG_RELEASING) began this frame.
#define ITEM_OBJECT_FLAG_RELEASE_STARTED 0x2
// The object was returned to its pool; UpdateItemObject then stops.
#define ITEM_OBJECT_FLAG_RELEASED 0x4
// A falling object touched the ground this frame.
#define ITEM_OBJECT_FLAG_LANDED 0x8
// A bouncing object bounced off the ground this frame.
#define ITEM_OBJECT_FLAG_BOUNCED 0x10
// A thrown or falling object hit a wall this frame.
#define ITEM_OBJECT_FLAG_HIT_WALL 0x20
// The scale (and with it the radii) was changed this frame.
#define ITEM_OBJECT_FLAG_SCALE_CHANGED 0x40
// The normal was set by code; UpdateItemObject then does not blend it back toward up.
#define ITEM_OBJECT_FLAG_KEEP_NORMAL 0x80
// A ground hit replaced the normal this frame.
#define ITEM_OBJECT_FLAG_NORMAL_CHANGED 0x100
// The object is held in a kart's ItemInUse.
#define ITEM_OBJECT_FLAG_IN_USE 0x1000
// The object was taken from its pool and is running.
#define ITEM_OBJECT_FLAG_ACTIVE 0x2000
// Set when the object is launched or starts falling; stays set while it rests.
#define ITEM_OBJECT_FLAG_LAUNCHED 0x4000
// The object rests on the course.
#define ITEM_OBJECT_FLAG_RESTING 0x8000
// The view test of the object failed.
#define ITEM_OBJECT_FLAG_OUT_OF_VIEW 0x10000
// No ground hit in the last 5 frames (ItemObject.mFramesSinceCourseHit).
#define ITEM_OBJECT_FLAG_NO_RECENT_COURSE_HIT 0x20000
// Set while ItemObject.mFramesSinceReset is below 5; a held object takes it from the kart course hit attribute bit.
#define ITEM_OBJECT_FLAG_COURSE_HIT_ATTRIBUTE 0x40000
// Fade-out is running.
#define ITEM_OBJECT_FLAG_FADING_OUT 0x80000
// The release timer is running.
#define ITEM_OBJECT_FLAG_RELEASING 0x100000
// Fade-out or release has begun.
#define ITEM_OBJECT_FLAGS_ENDING 0x180000
// The object is hit-tested even when the entry kart is far from the tested kart.
#define ITEM_OBJECT_FLAG_HITS_FAR_KARTS 0x200000
// The object owns a sound source (ItemObject.mSoundSource).
#define ITEM_OBJECT_FLAG_HAS_SOUND_SOURCE 0x400000
// The scale is not grown or swung by UpdateItemObject.
#define ITEM_OBJECT_FLAG_FIXED_SCALE 0x800000
// A hit bounced the object once; the next hit deflects it in a random direction.
#define ITEM_OBJECT_FLAG_BOUNCED_BEFORE 0x1000000
// The object was deflected in a random direction.
#define ITEM_OBJECT_FLAG_DEFLECTED 0x2000000
// The object was hit during the current step.
#define ITEM_OBJECT_FLAG_HIT_THIS_STEP 0x4000000
// The object was created in a Wi-Fi race (ResetItemObject, MODE_WIFI): its changes are sent as item events.
#define ITEM_OBJECT_FLAG_WIFI_RACE 0x8000000
// The object was created from received data (ResetItemObjectFromData).
#define ITEM_OBJECT_FLAG_FROM_DATA 0x10000000
// The object was set up from data (RoundTripItemObjectData, StartItemObjectFromData).
#define ITEM_OBJECT_FLAG_DATA_SET_UP 0x20000000
// The object is on a boost surface (COURSE_HIT_BOOST_SURFACE).
#define ITEM_OBJECT_FLAG_ON_BOOST_SURFACE 0x40000000

// Bits of ItemObject.mOwnerKartIndexAndFlags; the low byte is the owner kart index.
// Release is waiting to be replayed after setup from data.
#define ITEM_OWNER_RELEASE_PENDING 0x100
// Release timer is waiting to be replayed.
#define ITEM_OWNER_RELEASE_TIMER_PENDING 0x200
// Fade-out without callback is waiting to be replayed.
#define ITEM_OWNER_NO_CALLBACK_FADE_OUT_PENDING 0x400
// Fade-out is waiting to be replayed.
#define ITEM_OWNER_FADE_OUT_PENDING 0x800
// Any of the four pending bits.
#define ITEM_OWNER_PENDING_MASK 0xf00
// A red shell has this object as its target.
#define ITEM_OWNER_KOURA_R_TARGETED 0x1000
// Together with ITEM_OWNER_EXCLUDED: the owner stays excluded until the object hits the course.
#define ITEM_OWNER_EXCLUDED_UNTIL_COURSE_HIT 0x2000
// The owner kart is not hit by the object; cleared after 30 frames or at the first course hit.
#define ITEM_OWNER_EXCLUDED 0x4000
// The owner index is not valid (the owner reads as kart 8).
#define ITEM_OWNER_NO_OWNER 0x8000
// All the flag bits above; clearing them leaves the owner kart index.
#define ITEM_OWNER_FLAGS_MASK 0xff00
// Kart index that stands for no kart (one past the last kart): an item without an owner reads as this kart.
#define ITEM_NO_KART_INDEX 8

// The part every item object shares; the per-kind objects embed it as their first member.
typedef struct ItemObject {
    // Sound source of the item object (the sounds started on it).
    /* 00 */ SoundSource mSoundSource;
    // Kind number of the object's pool; ResetItemObject writes it each time the object is set up or handed out.
    /* 44 */ s32 mKind;
    /* 48 */ s32 mCreationNumber;
    // Index the object was allocated at in its pool; mObjects is reordered later, so this is not its position now.
    /* 4c */ s16 mPoolIndex;
    // Id used by the mode 5 event calls; only written in mode 5 (flag 0x8000000).
    /* 4e */ s16 mId;
    /* 050 */ Vec3 mPos;
    /* 5c */ Vec3 mVelocity;
    /* 68 */ Vec3 mScale;
    // Bit flags used by item code in 22 units; UpdateItemObject clears the low 12 bits on each call.
    /* 74 */ u32 mFlags;
    /* 78 */ u16 mOwnerKartIndexAndFlags;
    /* 7a */ u16 mPendingUpdateCount;
    /* 7c */ CourseColorBlend mColorBlend;
    /* 090 */ u16 *mKartLightColor;
    /* 094 */ MtxFx43 mTransformMtx;
    /* 0c4 */ Vec3 mDrawPos;
    /* d0 */ Vec3 *mPosPointer;
    /* 0d4 */ s32 mDistanceSquaredAndFlags;
    /* 0d8 */ s16 mAlpha;
    /* 0da */ s16 mCollisionSlotIndex;
    /* 0dc */ s32 mCourseRadius;
    /* e0 */ s32 mRadius;
    /* 0e4 */ Vec3 mPrevPos;
    /* 0f0 */ Vec3 mNormal;
    /* fc */ u32 mCollisionBits;
    /* 100 */ s32 mScaleTargetOrSpeed;
    /* 104 */ struct CollisionHitLink *mCollisionHitLink;
    /* 108 */ Vec3 mCoursePointOrParams;
    /* 114 */ s16 mFramesSinceCourseHit;
    /* 116 */ s16 mFramesSinceReset;
    /* 118 */ s16 mCourseReleaseTimer;
    /* 11a */ s16 mHitLinkTimer;
    // Frames since the object was taken by a kart or started, counted per UpdateItemObject call (several per frame in
    // mode 5); held objects count too.
    /* 11c */ s32 mAgeFrames;
    /* 120 */ void (*mAdvance)(struct ItemObject *);
    /* 124 */ void (*mBounce)(struct ItemObject *, Vec3 *, Vec3 *);
    /* 128 */ u8 mKartSoundMask;
    /* 129 */ u8 mUnk_129[3];
} ItemObject;

// Values of RaceProgressKart.mStatus. Racing, goal reached (battle: still alive at the end), battle loser, ended
// without the goal (time up, or the race is over), removed.
#define RACE_PROGRESS_KART_STATUS_RACING 0
#define RACE_PROGRESS_KART_STATUS_GOAL_REACHED 1
#define RACE_PROGRESS_KART_STATUS_BATTLE_LOSER 2
#define RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL 3
#define RACE_PROGRESS_KART_STATUS_REMOVED 4

// Bits of RaceProgressKart.mFlags.
#define RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY 0x1
#define RACE_PROGRESS_KART_FLAG_BATTLE_END 0x2
#define RACE_PROGRESS_KART_FLAG_AGAINST_CHECKPOINT 0x4
#define RACE_PROGRESS_KART_FLAG_FINISH_JUST_HAPPENED 0x8
#define RACE_PROGRESS_KART_FLAG_GOAL_WAIT 0x10
#define RACE_PROGRESS_KART_FLAG_FAILURE_WAIT 0x20
#define RACE_PROGRESS_KART_FLAG_FINISH_PENDING 0x40

// The race progress of one kart (mKarts[kart index]): status, lap times, checkpoints, rank and score.
typedef struct RaceProgressKart {
    // See RACE_PROGRESS_KART_STATUS_*.
    /* 00 */ s32 mStatus;
    // Frames of the current lap, counted while the clock gate is on (about 0x57e40 at most); read and reset at each lap
    // pass.
    /* 04 */ s32 mLapFrames;
    /* 08 */ s32 mPrismDataOffset;
    // Slot k-1 holds lap k, slot 5 the finish time. Laps not yet run still hold the value written at StructDC_SomeFn_from_thumb, so
    // GetLeastTimeLap is only meaningful after all laps.
    /* 0c */ MinuteSecondMillisecondTime mLapTimes[6];
    /* 24 */ s32 mLap;
    // Counted for the leader at each ranking step (kart 0 in a one-kart race); read by MaybeComputeGPScore.
    /* 28 */ s32 mFirstPlaceFrames;
    /* 2c */ s32 mFinishTimeMs;
    // 0x1 local entry, 0x2 ended by the mode 2 end, 0x4 facing against the checkpoint, 0x8 finish just happened, 0x10
    // local entry ended by the goal and the post-goal wait runs, 0x20 same for a failure kind, 0x40 finish pending.
    /* 30 */ u16 mFlags;
    /* 32 */ u16 mCheckpoint;
    // Number of the last numbered checkpoint the kart has passed in sequence in this lap: set to the entered number
    // while that is at most one more than the value (so it also falls back when the kart drives back), -1 when the lap
    // count advances, the last number at set-up and when the kart crosses the line backwards; the lap completes when it
    // is the last number and the kart reaches checkpoint 0.
    /* 34 */ s16 mInOrderCheckpointNumber;
    // Number of the last numbered checkpoint the kart entered (not required to be in sequence), -1 when the lap count
    // advances, the last number at set-up. Written only.
    /* 36 */ s16 mCheckpointNumber;
    /* 38 */ u16 mRoute;
    /* 3a */ u16 mHighestLap;
    /* 3c */ union {
        u16 mRankIndexRequestBits;
        struct {
            u16 mRank : 4;
            u16 mIndex : 4;
            u16 mFinishRequest : 2;
        };
    };
    // Set by RegisterNewRacer for the local entry in modes 0 and 4; 0 otherwise.
    /* 3e */ s16 mScore;
    // Position between the kart's checkpoint and the next one as of the last update, fixed point about 0 to 0x1000 (the
    // tests accept -2 to 0x1002); it is used again as the position when the checkpoint search found no new one.
    /* 40 */ s32 mCheckpointProgress;
    // ((mLap - 1) << 12 + mLapProgress) scaled by 1/laps, fixed point; the rank sort uses it after mLap.
    /* 44 */ s32 mRaceProgress;
    // Position within the lap, fixed point, scaled by 1/(g_GlobalPE.mLapProgressBaseMax + 1).
    /* 48 */ s32 mLapProgress;
    // One bit per checkpoint index over 16 words: set when the checkpoint was already tested in this update's search,
    // tested to skip it, cleared for all words before each update.
    /* 4c */ s32 mCheckpointTestedBits[0x10];
} RaceProgressKart;

// The race clock and the finish counters at the start of RaceProgress.
typedef struct RaceProgressHeader {
    /* 00 */ s32 mElapsedFrames;
    // Gate of the clock; cleared by FinishRaceProgressKartWithEndKind (finish request for ANY entry: mission goal,
    // forced finish, kind 6), not by the normal goal crossing; set only by StartRaceClock.
    /* 04 */ s32 mClockEnabled;
    /* 08 */ union {
        struct {
            /* 08 */ u16 mClockMillisecond;
            /* 0a */ u8 mClockMinute;
            /* 0b */ u8 mClockSecond;
        };
        MinuteSecondMillisecondTime mClockTime;
    };
    // Frames from the file, 0 = course absent. Compared with mElapsedFrames.
    /* 0c */ u16 mRankTime;
    // Calls of RegisterNewRacer; set to the kart count when the race is over.
    /* 0e */ u16 mFinishedCount;
    // Only karts removed while not ended.
    /* 10 */ u16 mRemovedCount;
    /* 12 */ u8 mId[0x2];
} RaceProgressHeader;

// Nine words.
typedef struct RaceProgressScoreTerms {
    /* 00 */ s32 mTimeRemainingScore;
    /* 04 */ s32 mFirstPlaceScore;
    /* 08 */ s32 mRaceStartBoostScore;
    /* 0c */ s32 mMiniTurboScore;
    /* 10 */ s32 mItemHitScore;
    /* 14 */ s32 mSurfaceScore;
    /* 18 */ s32 mCourseContactScore;
    /* 1c */ s32 mMapObjectHitScore;
    /* 20 */ s32 mRespawnScore;
} RaceProgressScoreTerms;

// A Grand Prix rank time entry: the course and the rank time for each engine class.
typedef struct RankTimeGpEntry {
    /* 00 */ u8 mCourseId;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mRankTimeEngine0;
    /* 04 */ u16 mRankTimeEngine1;
    /* 06 */ u16 mRankTimeEngine2;
} RankTimeGpEntry;

// The Grand Prix rank time file: the score weights MaybeComputeGPScore reads, then mEntryCount entries.
typedef struct RankTimeGp {
    /* 00 */ u8 mUnk_00[0x8];
    /* 08 */ u16 mEntryCount;
    /* 0a */ u16 mTimeRemainingWeight;
    /* 0c */ u16 mFirstPlaceWeight;
    /* 0e */ u16 mRaceStartBoostPoints;
    /* 10 */ u16 mMiniTurboPoints;
    /* 12 */ u16 mItemHitPoints;
    /* 14 */ u16 mSurfaceDivisor;
    /* 16 */ u16 mCourseContactPoints;
    /* 18 */ u16 mMapObjectHitPoints;
    /* 1a */ u16 mRespawnPoints;
    /* 1c */ RankTimeGpEntry mEntries[1];
} RankTimeGp;

// A row of RaceProgress.mRankPointFile: the points for rank 1 to 8; the first row of the file is skipped.
typedef struct RankPointRow {
    /* 00 */ u8 mPoints[8];
} RankPointRow;

// The race progress (g_GlobalMV): per-kart progress and status, the rank order, the race clock and the generators.
typedef struct RaceProgress {
    /* 000 */ RaceProgressHeader mHeader;
    /* 014 */ RaceProgressKart mKarts[8];
    /* 474 */ s8 mKartAtRank[8];
    // Synced random generator; also stepped at each clock update while the clock gate is on, for the jitter that
    // GetSomeMVTime shows.
    /* 47c */ RandomState64 mRandom;
    // Written once, never read; mNextHeader.mSeed holds the same value.
    /* 494 */ s32 mSeed;
    // Random generator seeded from three Os_GetTick calls, not from mSeed. Local means this console, not the local
    // player (mFlags bit 1 is the local entry). Mode 1 uses it where the other modes use mRandom.
    /* 498 */ RandomState64 mLocalRandom;
    // Random generator seeded with the constant 0xa094a2f; the map objects draw from it in mode 5 (from mRandom
    // otherwise).
    /* 4b0 */ RandomState64 mFixedSeedRandom;
    /* 4c8 */ RankTimeGp *mRankTimeGpFile;
    // Set once per race in every mode; read by HUD and net code.
    /* 4cc */ s32 mRaceDone;
    /* 4d0 */ s32 mCameraChainEnded;
    // Entry i is the fraction of the lap at numbered checkpoint i, fixed point; compared with a kart's mLapProgress.
    /* 4d4 */ s32 *mCheckpointLapProgress;
    /* 4d8 */ u8 mUnk_4d8[0x4];
    /* 4dc */ RankPointRow *mRankPointFile;
    // How the race of the entry flagged local in RaceProgressKart.mFlags ended: the second argument of
    // FinishRaceProgressKartWithEndKind (0 goal reached, other values the other ends), 6 until it has ended.
    /* 4e0 */ s32 mEntryEndKind;
    // Reciprocal of one more than g_GlobalPE's mLapProgressBaseMax, as a fixed-point factor: multiplied with a position
    // in the route to get RaceProgressKart.mLapProgress and mCheckpointLapProgress.
    /* 4e4 */ s32 mLapProgressScale;
    // Reciprocal of the lap count as a fixed-point factor: multiplied with (mLap - 1, mLapProgress) to get
    // RaceProgressKart.mRaceProgress.
    /* 4e8 */ s32 mRaceProgressScale;
    // Read only by MaybeConvertElapsedTime: when set, the clock counts down from mTimeLimitFrameCount. Set at StructDC_SomeFn_from_thumb in mode 4
    // (unless mUnk_2f is 6) and in mode 2 when mUnk_18 is 1.
    /* 4ec */ BOOL mTimeCountsDown;
    /* 4f0 */ s32 mEntryRaceEnded;
    // In frames; 0 = none, clock cap 0x57e40. Compared with the frame clock; mode 2 value is mSettings.mUnk_02 * 0x3c.
    /* 4f4 */ u32 mTimeLimitFrameCount;
    /* 4f8 */ u8 mStartPlacementOffset;
    /* 4f9 */ u8 mUnk_4f9;
    // Mode 4 only: counted while the local entry ended with flag 0x10, zeroed by FinishRaceProgressKartWithEndKind. No
    // StructDC_SomeFn_from_thumb write (zero from the allocation).
    /* 4fa */ u16 mFramesSinceFinish;
    // Calls of the end step, counted while IsEntryKartNormalOrNotMissionRun returns non-zero, since the selected entry
    // ended without the goal; the step waits for 0x3c and then takes the entry out.
    /* 4fc */ u16 mFramesSinceFailure;
    /* 4fe */ u16 mUnk_4fe;
    /* 500 */ RaceProgressScoreTerms mScoreTerms;
} RaceProgress;

// The record of one item object kind: its pool sizes and the callbacks for setup, reset, start, advance, draw, release.
typedef struct ItemKind {
    /* 00 */ s32 mObjectSize;
    // Most objects of the kind that may be in use, copied to the pool; CreateItemKinds changes it in modes 2, 4 and 5.
    /* 04 */ s32 mLimit;
    /* 08 */ s32 mMissionRunLimit;
    // Number of objects the kind's pool preallocates: mLimit - 1 plus the largest object count of an enabled ItemInfo,
    // plus 3 in mode 5, or 0x10 for kind 2 in the other modes.
    /* 0c */ s32 mObjectCount;
    /* 10 */ s32 mObjectBudget;
    /* 14 */ void (*mSetup)(void);
    // Called with the object by ResetItemObject after it has reset the common fields.
    /* 18 */ void (*mReset)(void *);
    // Called with the object when StartItemObject moves it into the started part of its pool.
    /* 1c */ void (*mStart)(void *);
    // Called by AdvanceItemInUseOneWithOrientation with the item-in-use record and its first object, which is not
    // started yet.
    /* 20 */ void (*mAdvanceInUse)(void *, void *);
    // Called with the item-in-use record and the object by StartLastItemInUseObjectAndInit after it takes the object
    // out of the record and starts it.
    /* 24 */ s32 (*mInit)(void *, void *);
    // Copied into the object's per-call callback (ItemObject.mUnk_120) when the object is started, unless flags
    // 0x180000 are set.
    /* 28 */ void (*mAdvance)(struct ItemObject *);
    // Draw callback of the objects of the kind's pool.
    /* 2c */ void (*mDraw)(void *, void *, void *);
    // View test, the same function type the map objects use: position, radius, draw distance, far distance squared,
    // alpha.
    /* 30 */ s32 (*mViewTest)(Vec3 *, s32, s32, s32, u16);
    // Called with the object by StartItemObjectFadeOut when its second argument is 0; returns 0 to end the call with 2,
    // 1 to end it with 0, anything else lets it continue.
    /* 34 */ s32 (*mFadeOutCallback)(void *item);
    // Called with the object after StartItemObject and LaunchItemObjectFromPos have set it up from a kart; the entries
    // that exist set the object's mUnk_120 to the kind's mAdvance unless flags 0x180000 are set.
    /* 38 */ void (*mAfterLaunchCallback)(void *);
    // Called with the object at the end of ReleaseItemObject.
    /* 3c */ void (*mRelease)(void *);
    /* 40 */ s32 mKeepsAdvanceAtEnd;
    /* 44 */ s32 mKeepsAdvanceWhenResting;
    // Copies the object's fields into the byte buffer (third argument non-zero) or back from it (zero); after a write
    // it also stamps the frame count and hands the buffer on (AddItemDataSizedByKind); with no object and no buffer it
    // returns the byte count.
    /* 48 */ void *(*mCopyData)(void *, void *, s32);
    // Byte count that mCopyData copies after the first byte of its record.
    /* 4c */ s32 mDataSize;
    // Called with the object right after a buffer was read into it (see mCopyData); every entry starts with
    // SetupItemObjectFromData.
    /* 50 */ void (*mInitFromData)(void *);
    /* 54 */ s32 mSkipsStartCollisionSlot;
    // Returns the kind's far distance squared; when NULL the value of gSoundFalloffs[1].mUnk_20 is used.
    /* 58 */ u32 (*mGetFarDistanceSquared)(void);
    /* 5c */ s32 mDrawDistance;
    /* 60 */ s32 mViewRadiusScale;
    /* 64 */ s32 mCourseRadius;
    /* 68 */ s32 mSetupRadius;
    /* 6c */ s32 mRadius;
    /* 70 */ s32 mScaleLimit;
    /* 74 */ s32 mTargetScale;
    /* 78 */ s32 mScaleStep;
    /* 7c */ s32 mBounceFactor;
    /* 80 */ s32 mStartsFalling;
    /* 84 */ s32 mHurtsKart;
    /* 88 */ s32 mEndsOnKartHit;
    /* 8c */ u8 mUnk_8c[4];
    /* 90 */ s32 mObjectCapCost;
    /* 94 */ s32 mUsedUpSoundId;
    /* 98 */ s32 mKartHitSoundId;
    /* 9c */ s32 mRestSoundId;
    /* a0 */ s32 mFalloffIndex;
    /* a4 */ s32 mFarDistanceSquared;
} ItemKind;

// Two words of a row of gItemSpreadRows.
typedef struct {
    /* 00 */ s32 mX;
    /* 04 */ s32 mY;
} ItemSpreadOffset;

// Row of gItemSpreadRows.
typedef struct {
    /* 00 */ ItemSpreadOffset mOffsets[3];
} ItemSpreadRow;

typedef enum {
    ITEM_USE_KIND_HOOK_ONLY,
    ITEM_USE_KIND_ONE,
    ITEM_USE_KIND_ONE_WITH_ORIENTATION,
    ITEM_USE_KIND_TRAIL,
    ITEM_USE_KIND_CIRCLE,
    ITEM_USE_KIND_NONE // ItemInUse.mUseKind while nothing is in use (ResetItemInUse)
} ItemUseKind;

struct ItemInUse;
struct HeldItem;

// One of the 18 items: its object kind and count, use kind and the hook called after its use.
typedef struct ItemInfo {
    // Gate of the roll and of the hand-over of the rolled item; set per mode by CreateItemInfos
    /* 00 */ BOOL mEnabled;
    /* 04 */ s32 mEnabledInWiFi;
    /* 08 */ s32 mObjectKind;
    /* 0c */ s32 mObjectCount;
    /* 10 */ s32 mUsesTimer;
    // ItemUseKind: how the objects are carried; 0 carries none. (above mUseKind)
    /* 14 */ s32 mUseKind;
    /* 18 */ void (*mUseHook)(struct ItemInUse *itemInUse, struct HeldItem *heldItem);
} ItemInfo;

// One pool of item objects of a kind (gItemPools): the first mActiveCount are started, up to mTakenCount handed out.
typedef struct ItemPool {
    /* 00 */ s32 mKind;
    /* 04 */ ItemObject **mObjects;
    // Length of mObjects: the number of preallocated objects.
    /* 08 */ s32 mObjectCount;
    /* 0c */ s32 mObjectBudget;
    // Objects handed out, the front part of mObjects: the first mActiveCount of them are started, the rest are held
    // by a kart.
    /* 10 */ s32 mTakenCount;
    // Objects that were started, the first part of mObjects; UpdateItemPool runs over these.
    /* 14 */ s32 mActiveCount;
    /* 18 */ s32 mRestingCount;
    // Taken objects plus the uses promised to a kart before they are taken (a gained held item adds its object
    // count).
    /* 1c */ s32 mReservedCount;
    // The most objects of the kind that may be in use; the pool is full when mLimit - mReservedCount <= 0, and a
    // held-item gain can push mReservedCount past mLimit.
    /* 20 */ s32 mLimit;
    /* 24 */ void (*mDraw)(void *, void *, void *);
    /* 28 */ s32 (*mViewTest)(Vec3 *, s32, s32, s32, u16);
    /* 2c */ s32 mScaleLimit;
    /* 30 */ s32 mTargetScale;
    /* 34 */ s32 mScaleStep;
    /* 38 */ s32 mDrawDistance;
    /* 3c */ s32 mFarDistanceSquared;
    /* 40 */ s32 mDrawnByMapObjects;
} ItemPool;

// Index into gItemInfos (the first word of HeldItem, KartItems.mActiveItem, the roulette's shown and result items).
// Names follow the gItemInfo records that CreateItemInfos copies in; ITEM_INFO_COUNT is one past the last record and
// ITEM_INFO_NONE is the value for no item.
typedef enum {
    ITEM_INFO_KOURA_G,
    ITEM_INFO_KOURA_R,
    ITEM_INFO_BANANA,
    ITEM_INFO_F_BOX,
    ITEM_INFO_KINOKO,
    ITEM_INFO_KINOKO_THREE,
    ITEM_INFO_BOMB,
    ITEM_INFO_KOURA_W,
    ITEM_INFO_THUNDER,
    ITEM_INFO_KOURA_G_THREE,
    ITEM_INFO_BANANA_THREE,
    ITEM_INFO_KOURA_R_THREE,
    ITEM_INFO_STAR,
    ITEM_INFO_KINOKO_P,
    ITEM_INFO_KILLER,
    ITEM_INFO_GESSO,
    ITEM_INFO_TERESA,
    ITEM_INFO_BOUNCING_ITEM_BOX,
    ITEM_INFO_COUNT,
    ITEM_INFO_NONE = 0x13
} ItemInfoIndex;

// ItemInfo.mObjectKind and the index of ItemPool: the kind of object an item hands out. ITEM_OBJECT_KIND_COUNT pools
// exist; ITEM_OBJECT_KIND_NONE is the value of ItemInUse.mObjectKind when no item is in use.
typedef enum {
    ITEM_OBJECT_KIND_KOURA_G,
    ITEM_OBJECT_KIND_KOURA_R,
    ITEM_OBJECT_KIND_BANANA,
    ITEM_OBJECT_KIND_KINOKO,
    ITEM_OBJECT_KIND_STAR,
    ITEM_OBJECT_KIND_KOURA_W,
    ITEM_OBJECT_KIND_THUNDER,
    ITEM_OBJECT_KIND_F_BOX,
    ITEM_OBJECT_KIND_BOUNCING_ITEM_BOX,
    ITEM_OBJECT_KIND_BOMB,
    ITEM_OBJECT_KIND_GESSO,
    ITEM_OBJECT_KIND_TERESA,
    ITEM_OBJECT_KIND_KINOKO_P,
    ITEM_OBJECT_KIND_KILLER,
    ITEM_OBJECT_KIND_COUNT,
    ITEM_OBJECT_KIND_NONE
} ItemObjectKind;

// ItemKind.mLimit (objects the pool holds) of the bouncing item box in a battle and of the mushroom in a Wi-Fi race.
#define ITEM_BATTLE_BOUNCING_ITEM_BOX_LIMIT 8
#define ITEM_WIFI_KINOKO_LIMIT 0x20

// The item a kart holds: its item index, how many are left and the objects it holds.
// HeldItem.mObjectStartFramesLeft starts at HELD_ITEM_OBJECT_START_FRAMES and counts down; one held object leaves
// on each launch frame.
#define HELD_ITEM_OBJECT_START_FRAMES 10
#define HELD_ITEM_FIRST_LAUNCH_FRAME 7
#define HELD_ITEM_SECOND_LAUNCH_FRAME 5
#define HELD_ITEM_THIRD_LAUNCH_FRAME 3

// The item a kart holds: its item info, objects, use timers and launch state.
typedef struct HeldItem {
    /* 00 */ s32 mItemInfoIndex;
    /* 04 */ struct KartItems *mKartItems;
    /* 08 */ s32 mObjectCount;
    /* 0c */ s32 mUsesTimer;
    /* 10 */ s16 mTimer;
    /* 12 */ s16 mUseTimerLimit;
    /* 14 */ ItemObject *mObjects[3];
    /* 20 */ s32 mObjectStartFramesLeft;
    /* 24 */ BOOL mIsPeerEntry;
} HeldItem;

#include "Main/MapObjects/map_object_response_and_quaternion_math.h"

extern struct RaceProgress *g_GlobalMV;

static inline RaceProgressKart *GetRaceProgressKart(u16 kartIndex) {
    return &g_GlobalMV->mKarts[kartIndex];
}

static inline s8 GetKartAtRank(u8 rank) {
    return g_GlobalMV->mKartAtRank[rank - 1];
}
extern ItemInfo *gItemInfos;

static inline ItemInfo *GetItemInfo(u32 itemInfoIndex) {
    return &gItemInfos[itemInfoIndex];
}
extern ItemPool *gItemPools;

static inline ItemPool *GetItemPool(s32 objectKind) {
    return &gItemPools[objectKind];
}

u8 GetItemPointLinkIndex(ItemPointLinkRef *ref);
void PickNextItemPointLink(ItemPointLinkRef *in, ItemPointLinkRef *out, u32 idx, s32 flag);
BOOL FollowItemPointLinksToPos(ItemPointLinkRef *in, ItemPointLinkRef *out, Vec3 *pos);
BOOL CopyCloserItemPointLinkRef(ItemPointLinkRef *current, ItemPointLinkRef *candidate, ItemPointLinkRef *out,
                                Vec3 *pos);
BOOL PickNearestNearbyItemPointLink(ItemPointLinkRef *in, ItemPointLinkRef *out, Vec3 *pos);
s32 PushSegmentPoint(SegmentPoints *segmentPoints, const Vec3 *point);
void InitSegmentPoints(SegmentPoints *segmentPoints, const Vec3 *points, s32 scale);
s32 GetItemPointLinkByIndex(s32 idx);
void RemoveReservedItemObjects(s32 itemInfoIndex, s32 amount);
void SetHeldItemWithCount(HeldItem *rec, s32 kind, s32 count);
void RemoveHeldItem(HeldItem *rec, s32 *kind, s32 *count);
void SetHeldItemUseDelay(HeldItem *rec, s32 frames);
BOOL StartHeldItemTimer(HeldItem *rec, s32 frames);
void StartHeldItemObjects(HeldItem *rec);
void TakeHeldItemObjects(HeldItem *rec);
void ReleaseHeldItem(HeldItem *rec, s32 keep);
void ResetHeldItem(HeldItem *rec);
void RemoveHeldItemObjects(HeldItem *rec, s32 amount);
void SetHeldItem(HeldItem *rec, s32 kind);
void UpdateHeldItem(HeldItem *rec);
