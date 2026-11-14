#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/kart_effects_ahead.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/Kart/code_02080cd0.h"
#include "Main/MapObjects/data_02165000.h"

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

// Object of 0x34 bytes at 0xe8 of the object KartAi starts: PickBattleKartAiRaceStart writes the words at 0x28 and 0x2c
// and the halfword at 0x30.
typedef struct KartAiRaceSpeedLimit {
    /* 00 */ s32 mBaseSpeedLimit;
    /* 04 */ s32 mSpeedLimit;
    /* 08 */ s32 mSpeedLimitAddition;
    /* 0c */ s32 mTurnSpeedLimit;
    /* 10 */ s32 mSpeedLimitBeforeTurn;
    /* 14 */ s32 mRank;
    /* 18 */ s32 mSpeedLimitReduced;
    /* 1c */ s32 mTableIndex;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mProgressGapLimit;
    /* 28 */ s32 mHeadingSwingAtRaceStart;
    /* 2c */ s32 mBoostsAtRaceStart;
    /* 30 */ u16 mRaceStartBoostChoice;
    /* 32 */ u8 mUnk_32[2];
} KartAiRaceSpeedLimit;

// Object at 0x140 of the object KartAi starts: AdvanceBattleKartAiSpeedLimit and SetBattleKartAiTurnSpeedLimit write
// the words at 0x04, 0x0c and 0x10.
typedef struct KartAiSpeedLimit {
    /* 00 */ s32 mBaseSpeedLimit;
    /* 04 */ s32 mSpeedLimit;
    /* 08 */ s32 mUnk_08;
    /* 0c */ BOOL mUnk_0c;
    /* 10 */ s32 mTurnSpeedLimit;
} KartAiSpeedLimit;

// One per Kart: follows the kart (mKart), steers it and requests its bits and items.
// Object of 0x158 bytes (FindKartAiTargetShine to PickBattleKartAiRaceStart take it first): the Kart it follows at
// 0x00, a LinkCursor at 0x28, vectors at 0x44, 0x50, 0x60 and 0xdc, a KartAiRaceSpeedLimit at 0xe8, a KartAiItemUse at
// 0x11c, a KartAiSpeedLimit at 0x140 and a word at 0x154.
typedef struct KartAi {
    /* 00 */ Kart *mKart;
    /* 04 */ u16 mIndex;
    /* 06 */ u16 mUnk_06;
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
    /* 84 */ s32 mUnk_84;
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
