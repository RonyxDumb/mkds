#pragma once

#include "types.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0208ab98.h" // CourseColorBlend
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "code_02146d78.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020d22c0.h" // RandomState64
#include "Main/Unknown/unk_0217a000.h" // MinuteSecondMillisecondTime

// Item point links with at least this radius (1000.0) are entered in gItemPointLinksByIndex.
#define ITEM_POINT_LINK_INDEXED_RADIUS 0x3e8000

// Frames (60 seconds) that ItemObject.mHitLinkTimer counts from when the hit link has an object.
#define ITEM_OBJECT_HIT_LINK_TIMER_FRAMES 0xe10

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

// Four positions and pointers to them.
typedef struct {
    /* 00 */ SegmentProgress mSegmentProgress;
    /* 60 */ s32 mWriteIndex;
    /* 64 */ Vec3 *mPointPointers[4];
    /* 74 */ Vec3 mPoints[4];
} SegmentPoints;

extern SegmentPoints data_0217bb88;

// Element returned through gItemPools: the first 0x12c bytes that every pool object shares; the per-kind objects
// embed it as their first member and run from 0x12c (kinds 4, 6 and 13) to 0x31c bytes. One is also embedded in
// MapObjects at 0x18c.
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
    /* 08e */ u8 mUnk_08e[2];
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

// One 0x8c entry per kart (mKarts[kart index]).
typedef struct RaceProgressKart {
    // See RACE_PROGRESS_KART_STATUS_*.
    /* 00 */ s32 mStatus;
    // Frames of the current lap, counted while the clock gate is on (about 0x57e40 at most); read and reset at each lap
    // pass.
    /* 04 */ s32 mLapFrames;
    /* 08 */ s32 mUnk_08;
    // Slot k-1 holds lap k, slot 5 the finish time. Laps not yet run still hold the value written at init, so
    // GetKartBestLapTime is only meaningful after all laps.
    /* 0c */ MinuteSecondMillisecondTime mLapTimes[6];
    /* 24 */ s32 mLap;
    // Counted for the leader at each ranking step (kart 0 in a one-kart race); read by ComputeGrandPrixScoreTerms.
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
    // Set by FinishRaceProgressKart for the local entry in modes 0 and 4; 0 otherwise.
    /* 3e */ s16 mScore;
    // Position between the kart's checkpoint and the next one as of the last update, fixed point about 0 to 0x1000 (the
    // tests accept -2 to 0x1002); it is used again as the position when the checkpoint search found no new one.
    /* 40 */ s32 mCheckpointProgress;
    // ((mLap - 1) << 12 + mLapProgress) scaled by 1/laps, fixed point; the rank sort uses it after mLap.
    /* 44 */ s32 mRaceProgress;
    // Position within the lap, fixed point, scaled by 1/(gCourseMap->mLapProgressBaseMax + 1).
    /* 48 */ s32 mLapProgress;
    // One bit per checkpoint index over 16 words: set when the checkpoint was already tested in this update's search,
    // tested to skip it, cleared for all words before each update.
    /* 4c */ s32 mCheckpointTestedBits[0x10];
} RaceProgressKart;

// The 0x14 bytes before RaceProgress.mKarts: the race clock and the finish counters.
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
    // Calls of FinishRaceProgressKart; set to the kart count when the race is over.
    /* 0e */ u16 mFinishedCount;
    // Only karts removed while not ended.
    /* 10 */ u16 mRemovedCount;
    /* 12 */ u8 mUnk_12[0x2];
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

// 8-byte entries from 0x1c of the object behind RaceProgress.mUnk_4c8.
typedef struct RankTimeGpEntry {
    /* 00 */ u8 mCourseId;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mRankTimeEngine0;
    /* 04 */ u16 mRankTimeEngine1;
    /* 06 */ u16 mRankTimeEngine2;
} RankTimeGpEntry;

// Object behind RaceProgress.mRankTimeGpFile: header 0x1c bytes (score weights read by ComputeGrandPrixScoreTerms:
// halfwords 0x0a..0x1a), then mEntryCount entries of 8 bytes.
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

// A row of the file behind RaceProgress.mRankPointFile: points for rank 1..8, first row of the file skipped.
typedef struct RankPointRow {
    /* 00 */ u8 mPoints[8];
} RankPointRow;

// Race object behind gRaceProgress (0x524 bytes, made by CreateRaceProgress from InitRace, stepped every frame by
// UpdateRaceProgress). Per-kart progress and status (mKarts, 8 entries), the rank order (mKartAtRank), the race clock
// in the header (mUnk_00_header), two loaded files (rankpoint.rpt,
// ranktimeGP.rtt), three random generators (mRandom synced, mLocalRandom per console, a third with a fixed seed used in
// mode 5) and race-done / time-limit flags. 17 files use only the generators.
typedef struct RaceProgress {
    /* 000 */ RaceProgressHeader mHeader;
    /* 014 */ RaceProgressKart mKarts[8];
    /* 474 */ s8 mKartAtRank[8];
    // Synced random generator; also stepped at each clock update while the clock gate is on, for the jitter that
    // GetRaceClockTime shows.
    /* 47c */ RandomState64 mRandom;
    // Written once, never read; mNextHeader.mUnk_5c holds the same value.
    /* 494 */ s32 mSeed;
    // Random generator seeded from three OS_GetTick calls, not from mSeed. Local means this console, not the local
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
    // Reciprocal of one more than gCourseMap's mLapProgressBaseMax, as a fixed-point factor: multiplied with a position
    // in the route to get RaceProgressKart.mLapProgress and mCheckpointLapProgress.
    /* 4e4 */ s32 mLapProgressScale;
    // Reciprocal of the lap count as a fixed-point factor: multiplied with (mLap - 1, mLapProgress) to get
    // RaceProgressKart.mRaceProgress.
    /* 4e8 */ s32 mRaceProgressScale;
    // Read only by ComputeRaceTime: when set, the clock counts down from mTimeLimitFrameCount. Set at init in mode 4
    // (unless mUnk_2f is 6) and in mode 2 when mUnk_18 is 1.
    /* 4ec */ BOOL mTimeCountsDown;
    /* 4f0 */ s32 mEntryRaceEnded;
    // In frames; 0 = none, clock cap 0x57e40. Compared with the frame clock; mode 2 value is mSettings->mUnk_02 * 0x3c.
    /* 4f4 */ u32 mTimeLimitFrameCount;
    /* 4f8 */ u8 mStartPlacementOffset;
    /* 4f9 */ u8 mUnk_4f9;
    // Mode 4 only: counted while the local entry ended with flag 0x10, zeroed by FinishRaceProgressKartWithEndKind. No
    // init write (zero from the allocation).
    /* 4fa */ u16 mFramesSinceFinish;
    // Calls of the end step, counted while IsEntryKartNormalOrNotMissionRun returns non-zero, since the selected entry
    // ended without the goal; the step waits for 0x3c and then takes the entry out.
    /* 4fc */ u16 mFramesSinceFailure;
    /* 4fe */ u16 mUnk_4fe;
    /* 500 */ RaceProgressScoreTerms mScoreTerms;
} RaceProgress;

// Entry of the table behind gItemKinds: one record per object kind (14, 0xa8 bytes each), a heap copy of the static
// gItemKind records, indexed by the kind number.
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
    /* 34 */ UnkWordFunc *mFadeOutCallback;
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
    /* 58 */ u32 mGetFarDistanceSquared;
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

// Default record: its only function pointer is the shared ComputeViewTest hook.
extern ItemKind gItemKindKinokoP;

extern ItemKind gItemKindTeresa;

extern ItemKind gItemKindGesso;

extern ItemKind gItemKindBomb;

extern ItemKind data_0215a4dc;

extern ItemKind gItemKindFBox;

// Default record: its only function pointer is the shared ComputeViewTest hook.
extern ItemKind gItemKindThunder;

extern ItemKind gItemKindKouraW;

// Default record: its only function pointer is the shared ComputeViewTest hook.
extern ItemKind gItemKindStar;

extern ItemKind gItemKindKinoko;

extern ItemKind gItemKindBanana;

extern ItemKind gItemKindKouraR;

extern ItemKind gItemKindKouraG;

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
    ITEM_USE_KIND_CIRCLE
} ItemUseKind;

struct ItemInUse;
struct HeldItem;

// One of the 18 items: the object kind and the number of objects it takes from the pool, the use kind and the hook
// called after its use. gItemInfos holds the heap copy of 18 static records of this type; the roulette may roll an item
// only while mEnabled is set.
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

extern ItemInfo data_0215a4c0;

extern ItemInfo data_0215a174;

extern ItemInfo data_0215a2ec;

extern ItemInfo data_02159d90;

extern ItemInfo data_021599dc;

extern ItemInfo data_021598fc;

extern ItemInfo data_02159680;

extern ItemInfo data_02159f4c;

extern ItemInfo data_02159aa0;

extern ItemInfo data_02159cc0;

extern ItemInfo data_02159e54;

extern ItemInfo data_02159664;

extern ItemInfo data_021596a0;

extern ItemInfo data_02159f68;

extern ItemInfo data_02159770;

extern ItemInfo data_02159838;

extern ItemInfo data_02159918;

// Entry of the table behind gItemPools: one pool per object kind (14), indexed by the kind number. The pool's objects
// sit in one array: the first mActiveCount are started, up to mTakenCount are handed out, the rest are free. Item,
// roulette, per-kind and HUD map code use it.
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

// Value of the first word of HeldItem.
typedef enum { UNK_020F40DC_KIND_0 } Unk020f40dc_Kind;

// The item a kart holds: its item index, how many are left and the objects it holds.
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

#include "Main/Unknown/code_020d6dc0.h"

extern s32 gItemPointLinksByIndex[];
extern ItemKind *gItemKinds;
extern RaceProgress *gRaceProgress;

static inline RaceProgressKart *GetRaceProgressKart(u16 kartIndex) {
    return &gRaceProgress->mKarts[kartIndex];
}

static inline s8 GetKartAtRank(u8 rank) {
    return gRaceProgress->mKartAtRank[rank - 1];
}
extern ItemSpreadRow gItemSpreadRows[];
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
s32 PushSegmentPoint(SegmentPoints *segmentPoints, Vec3 *point);
void InitSegmentPoints(SegmentPoints *segmentPoints, Vec3 *points, s32 scale);
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
