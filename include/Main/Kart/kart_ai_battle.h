#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/kart_effects_ahead.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Kart/kart_point_link_effects.h"
#include "Main/Kart/kart_effect_param_tables.h"

typedef struct MapObject MapObject;

enum {
    KART_AI_DRIFT_NONE,
    KART_AI_DRIFT_HOP_PENDING,
    KART_AI_DRIFT_HOLDING,
    KART_AI_DRIFT_RELEASE_PENDING,
    KART_AI_DRIFT_COUNTER_STEER,
};

enum {
    KART_AI_TURN_NONE,
    KART_AI_TURN_LEFT,
    KART_AI_TURN_RIGHT,
};

enum {
    KART_AI_CONTACT_NONE,
    KART_AI_CONTACT_STEER_FLAT,
    KART_AI_CONTACT_SLOW,
    KART_AI_CONTACT_REQUEST_LINK,
    KART_AI_CONTACT_KART_CALLED,
};

#define KART_AI_CONTACT_FRAMES_NONE 0x14
#define KART_AI_CONTACT_FRAMES_STEER_FLAT 0x78
#define KART_AI_CONTACT_FRAMES_SLOW 0xb4
#define KART_AI_CONTACT_FRAMES_REQUEST_LINK 0xb4

// The speed limit of a race kart AI: base, current and turn limits, rank, table index and the race start boosts.
typedef struct KartAiRaceSpeedLimit {
    /* 00 */ s32 mBaseSpeedLimit;
    /* 04 */ s32 mSpeedLimit;
    /* 08 */ s32 mSpeedLimitAddition;
    /* 0c */ s32 mTurnSpeedLimit;
    /* 10 */ s32 mSpeedLimitBeforeTurn;
    /* 14 */ s32 mRank;
    /* 18 */ s32 mSpeedLimitReduced;
    /* 1c */ s32 mTableIndex;
    /* 20 */ s32 mTableIndexCopy;
    /* 24 */ s32 mProgressGapLimit;
    /* 28 */ s32 mHeadingSwingAtRaceStart;
    /* 2c */ s32 mBoostsAtRaceStart;
    /* 30 */ u16 mRaceStartBoostChoice;
    /* 32 */ u8 mUnk_32[2];
} KartAiRaceSpeedLimit;

// The speed limit of a battle kart AI: base, current and turn limits.
typedef struct KartAiSpeedLimit {
    /* 00 */ s32 mBaseSpeedLimit;
    /* 04 */ s32 mSpeedLimit;
    /* 08 */ s32 mUnk_08;
    /* 0c */ BOOL mUnk_0c;
    /* 10 */ s32 mTurnSpeedLimit;
} KartAiSpeedLimit;

// One per Kart: follows the kart (mKart), steers it and requests its bits and items.
typedef struct KartAi {
    /* 00 */ Kart *mKart;
    /* 04 */ u16 mIndex;
    /* 06 */ u16 mIndexModFour;
    /* 08 */ PointLinkCursor mPointLinkCursor;
    /* 28 */ LinkCursor mBattleLinkCursor;
    /* 44 */ Vec3 mLinkPosWithSideOffset;
    /* 50 */ Vec3 mTargetKartPos;
    // Points at the position the CPU kart heads to: mLinkPosWithSideOffset, mTargetKartPos or mTargetShinePos.
    /* 5c */ Vec3 *mHeadingPos;
    /* 60 */ Vec3 mSideOffset;
    /* 6c */ u16 mSideOffsetFrames;
    /* 6e */ u16 mSideOffsetFrameLimit;
    /* 70 */ s32 mTurnAngleDegrees;
    /* 74 */ s32 mSideOffsetRatio;
    /* 78 */ u16 mContactStageFrames;
    /* 7a */ u16 mContactStageFrameLimit;
    /* 7c */ s32 mUnk_7c;
    /* 80 */ u16 mUnk_80;
    /* 82 */ u8 mUnk_82[2];
    /* 84 */ s32 mResetAtPointLink;
    /* 88 */ s32 mDriftStartRandomLimit;
    /* 8c */ s32 mDriftChargeRandomLimit;
    /* 90 */ s32 mDriftState;
    /* 94 */ s32 mTurnSide;
    /* 98 */ s32 mDriftFrames;
    /* 9c */ s32 mMinVelocityLength;
    /* a0 */ BOOL mDriftChargeRollAllowed;
    /* a4 */ s32 mLinkSpeedLimit;
    /* a8 */ s32 mContactStage;
    /* ac */ s16 mContactTimer;
    /* ae */ u8 mUnk_ae[2];
    /* b0 */ Kart *mTargetKart;
    /* b4 */ s32 mTargetAhead;
    /* b8 */ s32 mTargetDistanceSquared;
    /* bc */ s32 mTargetForwardDot;
    /* c0 */ s16 mBalloonCountGoal;
    /* c2 */ s16 mInflateWaitFrames;
    /* c4 */ BOOL mInflatePending;
    /* c8 */ u16 mHeadingSwingPhase;
    /* ca */ u16 mHeadingSwingOffset;
    /* cc */ s32 mHeadingSwingSign;
    /* d0 */ MapObject *mTargetShine;
    /* d4 */ s16 mEntrySearchStartIndex;
    /* d6 */ u8 mUnk_d6[2];
    /* d8 */ s32 mEntryForwardDot;
    /* dc */ Vec3 mTargetShinePos;
    /* e8 */ KartAiRaceSpeedLimit mRaceSpeedLimit;
    /* 11c */ KartAiItemUse mItemUse;
    /* 140 */ KartAiSpeedLimit mAiSpeedLimit;
    /* 154 */ s32 mListedCpu;
} KartAi;

// KartAi.mTargetDistanceSquared at or past this (a distance of 300) is too far to use an item on the target.
#define KART_AI_ITEM_RANGE_SQUARED 0x15f90
// KartAi.mTargetForwardDot and mEntryForwardDot above this mean the target lies ahead of the kart.
#define KART_AI_AHEAD_DOT 0xb33
// The same dot above this is the looser test used when the target is in range and ahead.
#define KART_AI_AHEAD_DOT_LOOSE 0x666
// KartAi.mTurnAngleDegrees above this lowers the turn speed limit in proportion.
#define KART_AI_TURN_SLOWDOWN_START_ANGLE 0x5000
// A held item is used only while KartAi.mTurnAngleDegrees is below this.
#define KART_AI_ITEM_TURN_ANGLE_LIMIT 0xa000
// The same limit for the items that tolerate a wider turn.
#define KART_AI_ITEM_TURN_ANGLE_LIMIT_WIDE 0x14000
// Frames of the CPU drift before it may roll for the charge; frames its contact timer runs; the speed below which a
// contact starts it; and the frames the item throw timers run.
#define KART_AI_DRIFT_CHARGE_ROLL_FRAMES 0x28
#define KART_AI_CONTACT_FRAMES 10
#define KART_AI_CONTACT_MAX_SPEED 0x3000
#define KART_AI_THROW_TIMER_FRAMES 2
// Point link values that start a CPU drift: the turn side (left or right) and whether the charge roll is allowed.
#define KART_AI_DRIFT_LINK_LEFT_ROLL 1
#define KART_AI_DRIFT_LINK_LEFT_NO_ROLL 2
#define KART_AI_DRIFT_LINK_RIGHT_ROLL 3
#define KART_AI_DRIFT_LINK_RIGHT_NO_ROLL 4

void AdvanceBattleKartAiSpeedLimit(KartAiSpeedLimit *kartAiSpeedLimit, KartAi *kartAi);
void SetBattleKartAiTurnSpeedLimit(KartAiSpeedLimit *kartAiSpeedLimit, KartAi *kartAi, s32 speedLimit);
void PickBattleKartAiRaceStart(KartAi *kartAi, KartAiRaceSpeedLimit *raceSpeedLimit);
void SetupBattleKartAiParams(void);
void ResetBattleKartAi(KartAi *kartAi);
void SetupBattleKartAi(KartAi *kartAi, Kart *kart);
void ResetBattleKartAiAtPointLink(KartAi *kartAi, PointLink *pointLink);
void AdvanceBattleKartAi(KartAi *kartAi);
void AdvanceBattleKartAiAlongPointLinks(KartAi *kartAi);
void AdvanceBattleKartAiSideOffset(KartAi *kartAi);
void AdvanceBattleKartAiTargetKart(KartAi *kartAi);
void AdvanceBattleKartAiMicInflate(KartAi *kartAi);
void PickKartAiBalloonCountGoal(KartAi *kartAi);
void AdvanceBattleKartAiTargetShine(KartAi *kartAi);
BOOL FindKartAiTargetShine(KartAi *kartAi, s32 distanceSquaredLimit, s32 yDifferenceLimit);

typedef struct KartAiSpeedLimit KartAiSpeedLimit;
typedef struct KartAi KartAi;

void SetupBattleKartAiSpeedLimit(KartAiSpeedLimit *speedLimit, KartAi *kartAi);

extern const Vec3 gBattleKartAiZeroVector;
extern const Vec3 gVec3UnitY;
extern BattleKartAiParams gBattleKartAiParamsHard;
extern BattleKartAiParams gBattleKartAiParamsDefault;
extern BattleKartAiParams gBattleKartAiParamsNormal;
extern u16 gSearchStartIndex;
extern struct BattleKartAiParams *gBattleKartAiParams;
extern s32 gEntryYDifferenceLimit;

extern char gKartModelSlashPrefix[2];
