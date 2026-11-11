#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_020800f4.h"
#include "Main/Unknown/code_02080cd0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/code_0207d000.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"
#include "Main/Unknown/code_02080000.h"
#include "Main/Unknown/code_020808d4.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_021000c8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a228c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02077bc0.h"

static inline s32 BattleKartAiXzIntDistanceSquared(const Vec3 *firstPos, const Vec3 *secondPos) {
    s32 xDifference = FROM_FIXED12(firstPos->x - secondPos->x);
    s32 zDifference = FROM_FIXED12(firstPos->z - secondPos->z);

    return xDifference * xDifference + zDifference * zDifference;
}

// Recomputes the CPU kart's speed limit on its own turn of eight frames and sets the kart's limit from it.
void AdvanceBattleKartAiSpeedLimit(KartAiSpeedLimit *kartAiSpeedLimit, KartAi *kartAi) {
    s32 speedLimit;
    Kart *kart;

    if (kartAi->mIndex == GetRaceUpdateFramesMod8()) {
        kartAiSpeedLimit->mUnk_0c = FALSE;
        speedLimit = kartAi->mKart->mSpeedLimitGoal;
        if (speedLimit > 0xa000) {
            speedLimit = 0xa000;
        }
        SetBattleKartAiTurnSpeedLimit(kartAiSpeedLimit, kartAi, speedLimit);
        if (kartAiSpeedLimit->mTurnSpeedLimit < speedLimit) {
            speedLimit = kartAiSpeedLimit->mTurnSpeedLimit;
        }
        if (speedLimit > 0xa000) {
            speedLimit = 0xa000;
        }
        kartAiSpeedLimit->mSpeedLimit = speedLimit;
        if (kartAi->mLinkSpeedLimit != 0) {
            if (kartAiSpeedLimit->mSpeedLimit > kartAi->mLinkSpeedLimit) {
                kartAiSpeedLimit->mSpeedLimit = kartAi->mLinkSpeedLimit;
            }
        }
    }
    kart = kartAi->mKart;
    if (kart->mState != KART_STATE_NORMAL) {
        return;
    }
    if ((kart->mDriveFlags & (KART_DRIVE_BOOST | KART_DRIVE_JUMP_PAD)) == 0) {
        kart->mSpeedLimitGoal = kartAiSpeedLimit->mSpeedLimit;
    }
}

void SetBattleKartAiTurnSpeedLimit(KartAiSpeedLimit *kartAiSpeedLimit, KartAi *kartAi, s32 speedLimit) {
    s32 turnRatio;

    kartAiSpeedLimit->mTurnSpeedLimit = speedLimit;
    if (kartAi->mTurnAngleDegrees <= 0x5000) {
        return;
    }
    turnRatio = MUL_FIXED12_ROUNDED(kartAi->mTurnAngleDegrees - 0x5000, 0x5b);
    if (turnRatio > 0x1000) {
        turnRatio = 0x1000;
    }
    kartAiSpeedLimit->mTurnSpeedLimit = MUL_FIXED12_ROUNDED(0x1000 - MUL_FIXED12_ROUNDED(turnRatio, 0x99c), 0x6000);
    if (kartAi->mTargetShine == NULL) {
        return;
    }
    if (kartAi->mEntryForwardDot > 0xb33) {
        kartAiSpeedLimit->mTurnSpeedLimit = kartAiSpeedLimit->mTurnSpeedLimit >> 1;
    }
}

void PickBattleKartAiRaceStart(KartAi *kartAi, KartAiRaceSpeedLimit *raceSpeedLimit) {
    BOOL isHumanGhostOrPeer = FALSE;
    s32 value;
    s32 boostChanceLimit;
    RandomState64 *kartAiRandom;

    raceSpeedLimit->mHeadingSwingAtRaceStart = 0;
    raceSpeedLimit->mBoostsAtRaceStart = 0;
    raceSpeedLimit->mRaceStartBoostChoice = 0;
    value = gRaceSetup->mCurrentEntries[kartAi->mIndex].mPlayer.mKind;
    if ((u32) value <= 3) {
        if ((1 << value) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
    }
    if (isHumanGhostOrPeer != FALSE) {
        return;
    }
    if (gRaceSetup->mBattleKind != BATTLE_KIND_SHINE) {
        return;
    }
    kartAiRandom = GetKartAiRandom();
    kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
    value = (s16) (u16) (kartAiRandom->mValue >> 52);
    boostChanceLimit = 0x333;
    switch (gRaceSetup->mCpuDifficulty) {
        case CPU_DIFFICULTY_NORMAL:
            boostChanceLimit = 0x666;
            break;
        case CPU_DIFFICULTY_HARD:
            boostChanceLimit = 0x99a;
            break;
    }
    if (value > boostChanceLimit) {
        return;
    }
    raceSpeedLimit->mBoostsAtRaceStart = 1;
    raceSpeedLimit->mRaceStartBoostChoice = PickKartAiRaceStartBoost(0);
}

void SetupBattleKartAiParams(void) {
    RaceSetup *raceSetup;

    gSearchStartIndex = 0;
    data_0217b030 = &data_0216600c;
    raceSetup = gRaceSetup;
    if (raceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        switch (raceSetup->mCpuDifficulty) {
            case CPU_DIFFICULTY_NORMAL:
                data_0217b030 = &data_02166028;
                break;
            case CPU_DIFFICULTY_HARD:
                data_0217b030 = &data_02165ff0;
                break;
        }
    } else {
        gEntryYDifferenceLimit = 0x190000;
        if (raceSetup->mCourseId == COURSE_ID_MINI_DOKAN_GC) {
            gEntryYDifferenceLimit = 0x28000;
        }
    }
}

void ResetBattleKartAi(KartAi *kartAi) {
    Vec3 zeroVector = data_02155ebc;

    kartAi->mSideOffset = zeroVector;
    kartAi->mSideOffsetFrames = 0;
    kartAi->mSideOffsetFrameLimit = 0;
    kartAi->mTurnAngleDegrees = 0;
    kartAi->mSideOffsetRatio = 0;
    kartAi->mContactStageFrames = 0;
    kartAi->mContactStageFrameLimit = 0;
    kartAi->mLinkSpeedLimit = 0;
    kartAi->mContactStage = 0;
    kartAi->mContactTimer = 0;
    kartAi->mTargetKart = NULL;
    kartAi->mTargetAhead = 0;
    kartAi->mTargetDistanceSquared = 0;
    kartAi->mTargetDistanceSquared = -0x1000;
    kartAi->mTargetKartPos = zeroVector;
    kartAi->mHeadingPos = &kartAi->mLinkPosWithSideOffset;
    kartAi->mInflateWaitFrames = 0;
    kartAi->mInflatePending = FALSE;
    kartAi->mHeadingSwingPhase = 0;
    kartAi->mHeadingSwingOffset = 0;
    kartAi->mHeadingSwingSign = 0;
    kartAi->mTargetShine = NULL;
    kartAi->mEntrySearchStartIndex = 0;
    kartAi->mEntryForwardDot = 0;
    kartAi->mTargetShinePos = zeroVector;
}

void SetupBattleKartAi(KartAi *kartAi, Kart *kart) {
    BattleKartAiParams *kartAiParams;
    RandomState64 *kartAiRandom;
    s16 goalIndex;
    s32 randomValue;
    s16 balloonCountGoal;

    kartAi->mKart = kart;
    kartAi->mIndex = kart->mIndex;
    kartAi->mUnk_06 = kartAi->mIndex % 4;
    ResetBattlePointLinkCursorNear(&kartAi->mBattleLinkCursor, &kart->mPos, &kart->mUnk_138, kart->mIndex);
    kartAi->mLinkPosWithSideOffset = *kartAi->mBattleLinkCursor.mLink->mPoint;
    ResetBattleKartAi(kartAi);
    if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        kartAiParams = data_0217b030;
        balloonCountGoal = 0;
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
        for (goalIndex = 0; goalIndex < 3; goalIndex++) {
            if (kartAiParams->mUnk_00[goalIndex] > 0 && randomValue <= kartAiParams->mUnk_00[goalIndex]) {
                balloonCountGoal = goalIndex + 1;
                break;
            }
        }
        kartAi->mBalloonCountGoal = balloonCountGoal;
    } else {
        kartAi->mBalloonCountGoal = 0;
    }
}

void ResetBattleKartAiAtPointLink(KartAi *kartAi, PointLink *pointLink) {
    ResetBattlePointLinkCursorTo(&kartAi->mBattleLinkCursor, pointLink);
    kartAi->mLinkPosWithSideOffset = *kartAi->mBattleLinkCursor.mLink->mPoint;
    ResetBattleKartAi(kartAi);
}

void AdvanceBattleKartAi(KartAi *kartAi) {
    AdvanceBattleKartAiMicInflate(kartAi);
    if (kartAi->mInflatePending == FALSE) {
        AdvanceKartAiContactStages(kartAi);
    }
    AdvanceBattleKartAiAlongPointLinks(kartAi);
    if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        AdvanceBattleKartAiTargetKart(kartAi);
        return;
    }
    if (kartAi->mTargetShine != NULL) {
        AdvanceBattleKartAiTargetKart(kartAi);
    }
    AdvanceBattleKartAiTargetShine(kartAi);
}

void AdvanceBattleKartAiAlongPointLinks(KartAi *kartAi) {
    LinkCursor *linkCursor;
    Kart *kart;
    PointLink *requestedLink;
    Vec3 *kartForward;
    Vec3 *headingPos;
    Vec3 kartPos;
    Vec3 headingOffset;
    Vec3 headingOffsetFlat;
    Vec3 kartForwardFlat;
    Vec3 crossProduct;
    s32 crossLength;
    BOOL hasTargetAhead;
    s32 targetKartIndex;

    kart = kartAi->mKart;
    linkCursor = &kartAi->mBattleLinkCursor;
    kartForward = &kart->mUnk_138;
    requestedLink = linkCursor->mRequestedLink;
    GetKartPos(&kartPos, kartAi->mIndex);
    if (kart->mDriveFlags &
        (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT | KART_DRIVE_RESPAWN_FALL | KART_DRIVE_SLOWING_STOP)) {
        return;
    }
    if (requestedLink != NULL && linkCursor->mLink != requestedLink) {
        AdvanceBattlePointLinkCursorTo(linkCursor, requestedLink);
        kartAi->mLinkSpeedLimit = GetBattlePointLinkSpeedLimit(linkCursor);
        AdvanceBattleKartAiSideOffset(kartAi);
        kartAi->mLinkPosWithSideOffset = *linkCursor->mLink->mPoint;
        VEC_Add(&kartAi->mLinkPosWithSideOffset, &kartAi->mSideOffset, &kartAi->mLinkPosWithSideOffset);
    } else {
        if (kartAi->mIndex == GetRaceUpdateFramesMod8()) {
            headingPos = kartAi->mHeadingPos;
            kartForwardFlat = *kartForward;
            VEC_Subtract(headingPos, &kart->mPos, &headingOffsetFlat);
            kartForwardFlat.y = 0;
            headingOffsetFlat.y = 0;
            VEC_CrossProduct(&kartForwardFlat, &headingOffsetFlat, &crossProduct);
            crossLength = VEC_Mag(&crossProduct);
            kartAi->mTurnAngleDegrees =
                ((s64) FX_Atan2(crossLength, VEC_DotProduct(&kartForwardFlat, &headingOffsetFlat)) * 0x394bb834c8LL +
                 0x80000000LL) >>
                32;
        }
        if (IsWithinBattlePointLinkDistance(linkCursor, &kartPos) != 0 ||
            IsPastBattlePointLink(linkCursor, &kartPos) != 0) {
            hasTargetAhead = FALSE;
            if (kartAi->mTargetKart != NULL && kartAi->mTargetAhead != 0) {
                hasTargetAhead = TRUE;
            }
            if (hasTargetAhead != FALSE) {
                targetKartIndex = kartAi->mTargetKart->mIndex;
            } else {
                targetKartIndex = -1;
            }
            AdvanceBattlePointLinkCursor(linkCursor, &kartPos, &kart->mUnk_138, kartAi->mIndex, kartAi->mTargetShine,
                                         targetKartIndex);
            kartAi->mLinkSpeedLimit = GetBattlePointLinkSpeedLimit(linkCursor);
            AdvanceBattleKartAiSideOffset(kartAi);
            kartAi->mLinkPosWithSideOffset = *linkCursor->mLink->mPoint;
            VEC_Add(&kartAi->mLinkPosWithSideOffset, &kartAi->mSideOffset, &kartAi->mLinkPosWithSideOffset);
            linkCursor->mRequestedLink = NULL;
            linkCursor->mUnk_18 = FALSE;
        }
    }
    if (kart->mState != KART_STATE_NORMAL) {
        return;
    }
    if (kartAi->mInflatePending != FALSE) {
        return;
    }
    RequestBits(kartAi->mKart->mEntryIndex, PAD_KEY_A);
    VEC_Subtract(kartAi->mHeadingPos, &kartPos, &headingOffset);
    AdvanceKartAiHeading(kartAi, &headingOffset, kartForward);
}

void AdvanceBattleKartAiSideOffset(KartAi *kartAi) {
    Vec3 vec3UnitY = gVec3UnitY;
    RandomState64 *kartAiRandom;
    s32 randomValue;
    s32 centeredRandom;
    s32 ratioChange;
    s32 newSideOffsetRatio;
    s32 sideOffsetScale;

    VEC_CrossProduct(&kartAi->mBattleLinkCursor.mDirection, &vec3UnitY, &kartAi->mSideOffset);
    kartAi->mSideOffsetFrames++;
    if (kartAi->mSideOffsetFrames > kartAi->mSideOffsetFrameLimit) {
        kartAi->mSideOffsetFrames = 0;
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        kartAi->mSideOffsetFrameLimit = 0;
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
        centeredRandom = MUL_FIXED12_ROUNDED(randomValue, 0x2000) - 0x1000;
        ratioChange = MUL_FIXED12_ROUNDED(centeredRandom, 0x4ce);
        newSideOffsetRatio = kartAi->mSideOffsetRatio + ratioChange;
        if (GetAbsoluteValue(newSideOffsetRatio) > 0xb36) {
            if (newSideOffsetRatio > 0) {
                newSideOffsetRatio = 0xb36;
            } else {
                newSideOffsetRatio = -0xb36;
            }
        }
        kartAi->mSideOffsetRatio = newSideOffsetRatio;
    }
    sideOffsetScale = MUL_FIXED12_ROUNDED(kartAi->mSideOffsetRatio, kartAi->mBattleLinkCursor.mLink->mRadius);
    kartAi->mSideOffset.x = MUL_FIXED12_NO_ROUND(kartAi->mSideOffset.x, sideOffsetScale);
    kartAi->mSideOffset.y = MUL_FIXED12_NO_ROUND(kartAi->mSideOffset.y, sideOffsetScale);
    kartAi->mSideOffset.z = MUL_FIXED12_NO_ROUND(kartAi->mSideOffset.z, sideOffsetScale);
}

void AdvanceBattleKartAiTargetKart(KartAi *kartAi) {
    Kart *kart;
    Kart *targetKart;
    KartItems *kartItems;
    Vec3 targetPos;
    Vec3 toTarget;
    Vec3 linkPos;
    Vec3 sideDirection;
    Vec3 linkToTarget;
    Vec3 vec3UnitY;
    s32 distanceSquared;
    s32 kartFlag;
    s32 targetFlag;
    u16 searchIndex;
    u16 candidateKartIndex;
    u32 kartIndex;
    u32 kartCount;
    s32 value;
    Vec3 *kartPos;

    kartIndex = kartAi->mIndex;
    if (kartIndex != GetRaceUpdateFramesMod8()) {
        return;
    }
    if (gRaceSetup->mCpuDifficulty == CPU_DIFFICULTY_EASY) {
        return;
    }
    if (kartAi->mTargetKart == NULL) {
        kartAi->mHeadingPos = &kartAi->mLinkPosWithSideOffset;
        candidateKartIndex = gSearchStartIndex;
        for (searchIndex = 0; searchIndex < (u32) gRaceSetup->mKartCount; searchIndex++) {
            if (ShouldKartAiTargetKart(kartAi->mIndex, candidateKartIndex) != 0) {
                targetKart = GetKart(candidateKartIndex);
                kartPos = &kartAi->mKart->mPos;
                distanceSquared = BattleKartAiXzIntDistanceSquared(kartPos, &targetKart->mPos);
                value = 0;
                if (distanceSquared < 0x895440) {
                    if (GetAbsoluteValue(kartAi->mKart->mPos.y - targetKart->mPos.y) < 0x3c000) {
                        value = 1;
                        kartAi->mTargetDistanceSquared = distanceSquared;
                    }
                }
                if (value != 0) {
                    kartCount = gRaceSetup->mKartCount;
                    gSearchStartIndex++;
                    if (gSearchStartIndex >= kartCount) {
                        gSearchStartIndex = 0;
                    }
                    goto store;
                }
            }
            candidateKartIndex++;
            if (candidateKartIndex >= (u32) gRaceSetup->mKartCount) {
                candidateKartIndex = 0;
            }
        }
        targetKart = NULL;
    store:
        kartAi->mTargetKart = targetKart;
        return;
    }
    kartItems = &gKartItems[kartIndex];
    if (kartItems->mItemInUse.mObjectKind == 0xf && kartItems->mHeldItem.mItemInfoIndex == 0x13 &&
        (kartAi->mKart->mEffectFlags & KART_EFFECT_STAR) == 0) {
        goto clear;
    }
    if (IsKartTargetable(kartAi->mTargetKart->mIndex) == FALSE) {
        goto clear;
    }
    kart = kartAi->mKart;
    targetKart = kartAi->mTargetKart;
    kartPos = &kart->mPos;
    distanceSquared = BattleKartAiXzIntDistanceSquared(kartPos, &targetKart->mPos);
    value = 0;
    if (distanceSquared < 0xf42400) {
        if (GetAbsoluteValue(kartAi->mKart->mPos.y - kartAi->mTargetKart->mPos.y) < 0x3c000) {
            kartAi->mTargetDistanceSquared = distanceSquared;
            value = 1;
        }
    }
    if (value == 0) {
        goto clear;
    }
    if (GetAbsoluteValue(kartAi->mKart->mPos.y - kartAi->mTargetKart->mPos.y) >= 0x3c000) {
        goto clear;
    }
    value = 0;
    VEC_Subtract(&kartAi->mTargetKart->mPos, &kartAi->mKart->mPos, &toTarget);
    if (VEC_DotProduct(&toTarget, &kartAi->mKart->mUnk_138) > 0) {
        if (LENGTH_SQUARED(toTarget) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&toTarget, &toTarget);
        }
        kartAi->mTargetForwardDot = VEC_DotProduct(&toTarget, &kartAi->mKart->mUnk_138);
        value = 1;
    }
    kartAi->mTargetAhead = value != 0;
    if (kartAi->mTargetAhead != 0) {
        kartItems = &gKartItems[kartAi->mIndex];
        value = 1;
        if (kartItems->mItemInUse.mObjectKind == 0xf && kartItems->mHeldItem.mItemInfoIndex == 0x13) {
            if ((GetKart(kartAi->mIndex)->mEffectFlags & KART_EFFECT_STAR) == 0) {
                value = 0;
            }
        }
        kartFlag = value != 0 ? 1 : 0;
        targetFlag = (kartAi->mTargetKart->mEffectFlags & KART_EFFECT_STAR) != 0 ? 1 : 0;
        if (kartFlag != 0 && targetFlag == 0 && kartAi->mTargetForwardDot > 0xb33) {
            targetPos = kartAi->mTargetKart->mPos;
            targetPos.y = kartAi->mLinkPosWithSideOffset.y;
            linkPos = *kartAi->mBattleLinkCursor.mLink->mPoint;
            vec3UnitY = gVec3UnitY;
            VEC_CrossProduct(&kartAi->mBattleLinkCursor.mDirection, &vec3UnitY, &sideDirection);
            VEC_Subtract(&targetPos, &linkPos, &linkToTarget);
            distanceSquared = Vec3DotUnrounded(&linkToTarget, &sideDirection);
            value = kartAi->mBattleLinkCursor.mLink->mRadius;
            if (GetAbsoluteValue(distanceSquared) >= value) {
                kartAi->mHeadingPos = &kartAi->mLinkPosWithSideOffset;
            } else {
                kartAi->mTargetKartPos = targetPos;
                kartAi->mHeadingPos = &kartAi->mTargetKartPos;
            }
        } else {
            kartAi->mHeadingPos = &kartAi->mLinkPosWithSideOffset;
        }
    } else {
        kartAi->mHeadingPos = &kartAi->mLinkPosWithSideOffset;
    }
    return;
clear:
    kartAi->mTargetKart = NULL;
    kartAi->mHeadingPos = &kartAi->mLinkPosWithSideOffset;
}

void AdvanceBattleKartAiMicInflate(KartAi *kartAi) {
    s32 balloonOrShineCount;
    u16 balloonsLeftToMake;
    BOOL balloonsLeftTestPassed;

    kartAi->mInflatePending = FALSE;
    if (gRaceSetup->mBattleKind != BATTLE_KIND_BALLOON) {
        return;
    }
    if (IsKartNotNormalOrFlagged(kartAi->mKart) != FALSE) {
        StopKartMicInflate(kartAi->mIndex);
        return;
    }
    balloonOrShineCount = GetBalloonOrShineCount(kartAi->mIndex);
    balloonsLeftToMake = GetBalloonsLeftToMake(kartAi->mIndex);
    if (balloonOrShineCount >= kartAi->mBalloonCountGoal) {
        return;
    }
    balloonsLeftTestPassed = FALSE;
    if (balloonsLeftToMake > data_0217b030->mInflateBalloonsLeftLimit ||
        (balloonsLeftToMake == data_0217b030->mInflateBalloonsLeftLimit &&
         IsKartInflatingBalloon(kartAi->mIndex) != 0)) {
        balloonsLeftTestPassed = TRUE;
    }
    if (balloonsLeftTestPassed == FALSE) {
        return;
    }
    kartAi->mInflateWaitFrames++;
    if (kartAi->mInflateWaitFrames > data_0217b030->mInflateWaitFrameCount) {
        StartKartMicInflate(kartAi->mIndex);
        kartAi->mInflateWaitFrames = 0;
    }
    kartAi->mInflatePending = TRUE;
}

void PickKartAiBalloonCountGoal(KartAi *kartAi) {
    s32 *randomLimits = data_0217b030->mUnk_0c;
    RandomState64 *kartAiRandom;
    s16 goalIndex;
    s32 randomValue;
    s16 balloonCountGoal = 0;

    kartAiRandom = GetKartAiRandom();
    kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
    randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
    for (goalIndex = 0; goalIndex < 3; goalIndex++) {
        if (randomLimits[goalIndex] > 0 && randomValue <= randomLimits[goalIndex]) {
            balloonCountGoal = goalIndex + 1;
            break;
        }
    }
    kartAi->mBalloonCountGoal = balloonCountGoal;
}

void AdvanceBattleKartAiTargetShine(KartAi *kartAi) {
    MapObject *targetShine;
    Vec3 shinePos;
    Vec3 toShine;
    Vec3 linkPos;
    Vec3 sideDirection;
    Vec3 linkToShine;
    Vec3 vec3UnitY;
    s32 value;
    s32 distanceSquared;
    BOOL isInRange;
    BOOL isAhead;
    s32 linkRadius;
    Vec3 *mapObjectPos;
    Vec3 *kartPos;

    targetShine = kartAi->mTargetShine;
    if (targetShine != NULL) {
        if (!(targetShine->mFlags & 1)) {
            mapObjectPos = &targetShine->mPos;
            kartPos = &kartAi->mKart->mPos;
            distanceSquared = BattleKartAiXzIntDistanceSquared(kartPos, mapObjectPos);
            value = gEntryYDifferenceLimit;
            if (distanceSquared < 0x15f900 && GetAbsoluteValue(kartAi->mKart->mPos.y - targetShine->mPos.y) < value) {
                isInRange = TRUE;
            } else {
                isInRange = FALSE;
            }
            if (isInRange != FALSE) {
                isAhead = FALSE;
                VEC_Subtract(&targetShine->mPos, &kartAi->mKart->mPos, &toShine);
                if (VEC_DotProduct(&toShine, &kartAi->mKart->mUnk_138) > 0) {
                    if (LENGTH_SQUARED(toShine) >= 0x10) {
                        Vec3NormalizeAndGetLengthUnchecked(&toShine, &toShine);
                    }
                    kartAi->mEntryForwardDot = VEC_DotProduct(&toShine, &kartAi->mKart->mUnk_138);
                    isAhead = TRUE;
                }
                if (isAhead != FALSE && kartAi->mEntryForwardDot > 0xb33) {
                    shinePos = targetShine->mPos;
                    shinePos.y = kartAi->mLinkPosWithSideOffset.y;
                    linkPos = *kartAi->mBattleLinkCursor.mLink->mPoint;
                    vec3UnitY = gVec3UnitY;
                    VEC_CrossProduct(&kartAi->mBattleLinkCursor.mDirection, &vec3UnitY, &sideDirection);
                    VEC_Subtract(&shinePos, &linkPos, &linkToShine);
                    value = Vec3DotUnrounded(&linkToShine, &sideDirection);
                    linkRadius = kartAi->mBattleLinkCursor.mLink->mRadius;
                    if (GetAbsoluteValue(value) >= linkRadius) {
                        kartAi->mHeadingPos = &kartAi->mLinkPosWithSideOffset;
                    } else {
                        kartAi->mTargetShinePos = shinePos;
                        kartAi->mHeadingPos = &kartAi->mTargetShinePos;
                    }
                } else {
                    kartAi->mHeadingPos = &kartAi->mLinkPosWithSideOffset;
                }
            } else {
                kartAi->mTargetShine = NULL;
                kartAi->mHeadingPos = &kartAi->mLinkPosWithSideOffset;
            }
        } else {
            kartAi->mTargetShine = NULL;
            kartAi->mHeadingPos = &kartAi->mLinkPosWithSideOffset;
        }
    } else {
        if (kartAi->mIndex == GetRaceUpdateFramesMod8()) {
            FindKartAiTargetShine(kartAi, 0x17d7840, gEntryYDifferenceLimit);
        }
    }
}

// Picks a Shine16 object within the given x/z and y ranges as the CPU kart's target; TRUE if one was found.
BOOL FindKartAiTargetShine(KartAi *kartAi, s32 distanceSquaredLimit, s32 yDifferenceLimit) {
    MapObjectList *shineList;
    s16 stepIndex;
    s32 listCount;
    s16 checkedCount;
    s16 listIndex;
    s32 longestDistanceSquared;
    MapObject *farthestShine;
    MapObject *shine;
    Vec3 *shinePos;
    Vec3 *kartPos;
    s32 distanceSquared;
    BOOL isInRange;

    shineList = FindMapObjectKindUpdateList(MAP_OBJECT_KIND_SHINE16);
    listCount = GetMapObjectListCount(shineList);
    longestDistanceSquared = 0;
    farthestShine = NULL;
    stepIndex = 0;
    checkedCount = 0;
    listIndex = kartAi->mEntrySearchStartIndex;
    for (; stepIndex < listCount; stepIndex++) {
        shine = GetMapObjects(shineList)[listIndex];
        listIndex++;
        if (listIndex >= listCount) {
            listIndex = 0;
        }
        if (!(shine->mFlags & 1)) {
            checkedCount++;
            shinePos = &shine->mPos;
            kartPos = &kartAi->mKart->mPos;
            distanceSquared = BattleKartAiXzIntDistanceSquared(kartPos, shinePos);
            if (distanceSquared < distanceSquaredLimit &&
                GetAbsoluteValue(kartAi->mKart->mPos.y - shine->mPos.y) < yDifferenceLimit) {
                isInRange = TRUE;
            } else {
                isInRange = FALSE;
            }
            if (isInRange != FALSE) {
                if (farthestShine == NULL || longestDistanceSquared < distanceSquared) {
                    farthestShine = shine;
                    longestDistanceSquared = distanceSquared;
                }
            }
            if (checkedCount >= 5) {
                break;
            }
        }
    }
    kartAi->mEntrySearchStartIndex = listIndex;
    if (farthestShine != NULL) {
        kartAi->mTargetShine = farthestShine;
        return TRUE;
    }
    return FALSE;
}
