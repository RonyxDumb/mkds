#include "Main/Unknown/code_0207d814.h"

#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203c5ac.h"
#include "Main/Unknown/code_020b1dbc.h"
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
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020435c4.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

void SetupAwardMissionRunKartAi(struct KartAi *kartAi, struct Kart *kart, s32 unusedValue) {
    kartAi->mKart = kart;
    kartAi->mIndex = kart->mIndex;
    kartAi->mUnk_06 = kartAi->mIndex % 4;
    kartAi->mDriftStartRandomLimit = 0x1000;
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        kartAi->mDriftChargeRandomLimit = 0;
    } else {
        kartAi->mDriftChargeRandomLimit = 0x1000;
    }
    kartAi->mMinVelocityLength = MUL_FIXED12_ROUNDED(kartAi->mKart->mPhysicalParam->mBaseSpeedLimit, 0x99a);
    InitRacePointLinkCursor(&kartAi->mPointLinkCursor, kartAi->mIndex);
    ResetKartAi(kartAi, 0);
    kartAi->mHeadingSwingSign = 1;
}

void ResetAwardMissionRunKartAi(struct KartAi *kartAi, struct RacePointLink *pointLink) {
    ResetPointLinkCursor(&kartAi->mPointLinkCursor, pointLink);
    ResetKartAi(kartAi, 1);
    ResetKartAi(kartAi, 1);
}

void AdvanceAwardMissionRunKartAi(struct KartAi *kartAi) {
    Vec3 kartPos;
    Vec3 toLinkPos;
    PointLinkCursor *linkCursor;
    Kart *kart;
    Vec3 *kartForward;
    RacePointLink *requestedLink;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AdvanceKartAiContactStages(kartAi);
    }
    linkCursor = &kartAi->mPointLinkCursor;
    kart = kartAi->mKart;
    if (kartAi->mDriftState == 2) {
        kartForward = &kart->mTurnedForward;
    } else {
        kartForward = &kart->mUnk_138;
    }
    requestedLink = linkCursor->mRequestedLink;
    GetKartPos(&kartPos, kartAi->mIndex);
    AdvanceKartAiAlongLinks(kartAi, linkCursor, kart, requestedLink, &kartPos, kartForward);
    if (kart->mState == KART_STATE_NORMAL) {
        RequestBits(kartAi->mKart->mEntryIndex, PAD_KEY_A);
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kartPos, &toLinkPos);
        AdvanceKartAiHeading(kartAi, &toLinkPos, kartForward);
    }
    AdvanceKartAiDrift(kartAi);
}

void SetupStaffRollKartAi(struct KartAi *kartAi, struct Kart *kart, s32 unusedValue) {
    kartAi->mKart = kart;
    kartAi->mIndex = kart->mIndex;
    kartAi->mUnk_06 = kartAi->mIndex % 4;
    kartAi->mDriftStartRandomLimit = 0x1000;
    kartAi->mDriftChargeRandomLimit = 0;
    kartAi->mMinVelocityLength = MUL_FIXED12_ROUNDED(kartAi->mKart->mPhysicalParam->mBaseSpeedLimit, 0x99a);
    InitRacePointLinkCursor(&kartAi->mPointLinkCursor, kartAi->mIndex);
    ResetKartAi(kartAi, 0);
    kartAi->mHeadingSwingSign = 1;
}

void AdvanceStaffRollKartAi(struct KartAi *kartAi) {
    Vec3 kartPos;
    Vec3 toLinkPos;
    PointLinkCursor *linkCursor = &kartAi->mPointLinkCursor;
    Kart *kart = kartAi->mKart;
    Vec3 *kartForward;
    RacePointLink *requestedLink;

    if (kartAi->mDriftState == 2) {
        kartForward = &kart->mTurnedForward;
    } else {
        kartForward = &kart->mUnk_138;
    }
    requestedLink = linkCursor->mRequestedLink;
    GetKartPos(&kartPos, kartAi->mIndex);
    AdvanceKartAiAlongLinks(kartAi, linkCursor, kart, requestedLink, &kartPos, kartForward);
    if (kart->mState == KART_STATE_NORMAL) {
        RequestBits(kartAi->mKart->mEntryIndex, PAD_KEY_A);
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kartPos, &toLinkPos);
        AdvanceKartAiHeading(kartAi, &toLinkPos, kartForward);
    }
    AdvanceKartAiDrift(kartAi);
}

void InitKartAiTables(void) {
    s32 cpuAndGhostKartCount;

    switch (GetKartAiEngineOrDifficultyIndex()) {
        case 0:
            gKartAiRaceStartBoostRandomLimits = data_usa_02155630;
            data_usa_0217ae2c = data_usa_0215569c;
            break;
        case 1:
            gKartAiRaceStartBoostRandomLimits = data_usa_02155654;
            data_usa_0217ae2c = data_usa_021556c0;
            break;
        case 2:
        default:
            gKartAiRaceStartBoostRandomLimits = data_usa_02155678;
            data_usa_0217ae2c = data_usa_0215560c;
            break;
    }
    data_usa_021658f0 = 3;
    cpuAndGhostKartCount = gRaceSetup->mKartCount - gRaceSetup->mHumanAndPeerKartCount;
    if (cpuAndGhostKartCount > 1) {
        if (cpuAndGhostKartCount <= 3) {
            data_usa_021658f0 = cpuAndGhostKartCount - 1;
        }
    }
    data_usa_0217ae34 = data_usa_02165910[cpuAndGhostKartCount];
}

u32 SetupRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    raceSpeedLimit->mBaseSpeedLimit = kartAi->mKart->mPhysicalParam->mBaseSpeedLimit;
    raceSpeedLimit->mSpeedLimitBeforeTurn = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mTableIndex = GetKartAiTableIndex(kartAi->mIndex);
    raceSpeedLimit->mUnk_20 = raceSpeedLimit->mTableIndex;
    raceSpeedLimit->mUnk_24 = 0;
    raceSpeedLimit->mSpeedLimit = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mSpeedLimitAddition = 0;
    raceSpeedLimit->mTurnSpeedLimit = 0;
    raceSpeedLimit->mSpeedLimitBeforeTurn = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mRank = -1;
    raceSpeedLimit->mSpeedLimitReduced = 0;
    return -1;
}

void ResetRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    raceSpeedLimit->mSpeedLimit = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mSpeedLimitAddition = 0x0u;
    raceSpeedLimit->mTurnSpeedLimit = 0x0u;
    raceSpeedLimit->mSpeedLimitBeforeTurn = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mRank = -1;
    raceSpeedLimit->mSpeedLimitReduced = 0x0u;
}

// Rolls the race start of a CPU kart: a race start boost with its choice, or the flag in mUnk_28.
void PickKartAiRaceStart(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    BOOL isHumanGhostOrPeer = FALSE;
    u32 playerKind;
    BOOL boostChosen;
    s32 tableIndex;
    s32 randomValue;
    s32 randomLimit;
    RandomState64 *kartAiRandom;
    KartAi *kartAiOfKart;

    playerKind = gRaceSetup->mCurrentEntries[kartAi->mIndex].mPlayer.mKind;
    if (playerKind <= 3) {
        if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
    }
    if (isHumanGhostOrPeer != FALSE) {
        return;
    }
    boostChosen = FALSE;
    kartAiRandom = GetKartAiRandom();
    kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
    randomValue = (s16) (u16) (kartAiRandom->mValue >> 52);
    tableIndex = GetKartAiTableIndex(kartAi->mIndex);
    kartAiOfKart = GetKart(kartAi->mIndex)->mAi;
    if (kartAiOfKart->mListedCpu != 0) {
        tableIndex = boostChosen;
    }
    randomLimit = gKartAiRaceStartBoostRandomLimits[tableIndex];
    if (randomValue < randomLimit || randomLimit >= 0x1000) {
        raceSpeedLimit->mBoostsAtRaceStart = 1;
        raceSpeedLimit->mRaceStartBoostChoice = PickKartAiRaceStartBoost(kartAiOfKart->mListedCpu);
        boostChosen = TRUE;
    }
    if (boostChosen != FALSE) {
        return;
    }
    randomLimit = data_usa_0217ae2c[tableIndex];
    if (randomValue >= randomLimit) {
        if (!(randomLimit >= 1.0f)) {
            return;
        }
    }
    raceSpeedLimit->mHeadingSwingAtRaceStart = 1;
}

// Every eighth frame, on this kart's turn, recomputes the CPU speed limit; every call sets the kart's limit from it.
void AdvanceRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    BOOL isHumanGhostOrPeer;
    u32 playerKind;
    s32 speedLimit;
    s32 turnExcessRatio;
    Kart *kart;

    if (kartAi->mIndex == GetRaceUpdateFramesMod8()) {
        raceSpeedLimit->mSpeedLimitAddition = 0;
        raceSpeedLimit->mSpeedLimitReduced = 0;
        isHumanGhostOrPeer = FALSE;
        playerKind = gRaceSetup->mCurrentEntries[kartAi->mIndex].mPlayer.mKind;
        if (playerKind <= 3) {
            if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                isHumanGhostOrPeer = TRUE;
            }
        }
        if (isHumanGhostOrPeer != FALSE) {
            raceSpeedLimit->mRank = GetKartRank(kartAi->mIndex);
        } else {
            raceSpeedLimit->mRank = GetKartRankAmongKind1(kartAi->mIndex);
        }
        raceSpeedLimit->mSpeedLimitAddition = GetKartAiParamRow()->mSpeedLimitAddition;
        if (IsOneKartNotHumanOrPeer() != 0) {
            raceSpeedLimit->mSpeedLimitAddition = raceSpeedLimit->mSpeedLimitAddition >> 1;
        }
        kart = kartAi->mKart;
        speedLimit = raceSpeedLimit->mSpeedLimitAddition + kart->mSpeedLimitGoal;
        if (kartAi->mContactStage == 2) {
            speedLimit = 0x3000;
        }
        if (speedLimit > 0xa000) {
            speedLimit = 0xa000;
        }
        if (kart->mUnk_4c & 0x8000000) {
            speedLimit = MUL_FIXED12_ROUNDED(speedLimit, 0xb33);
        }
        if (kartAi->mDriftState == 0) {
            raceSpeedLimit->mTurnSpeedLimit = speedLimit;
            if (kartAi->mTurnAngleDegrees > 0x5000) {
                turnExcessRatio = MUL_FIXED12_NO_ROUND(kartAi->mTurnAngleDegrees - 0x5000, 0x5b);
                if (turnExcessRatio > 0x1000) {
                    turnExcessRatio = 0x1000;
                }
                raceSpeedLimit->mTurnSpeedLimit =
                    MUL_FIXED12_NO_ROUND(0x1000 - MUL_FIXED12_NO_ROUND(turnExcessRatio, 0x668), 0xa000);
            }
            AdvanceKartAiSpeedLimitByRank(raceSpeedLimit, kartAi, speedLimit);
            speedLimit = raceSpeedLimit->mSpeedLimitBeforeTurn;
        }
        if (raceSpeedLimit->mTurnSpeedLimit < speedLimit) {
            speedLimit = raceSpeedLimit->mTurnSpeedLimit;
        }
        if (speedLimit > 0xa000) {
            speedLimit = 0xa000;
        }
        raceSpeedLimit->mSpeedLimit = speedLimit;
    }
    kart = kartAi->mKart;
    if (kart->mState != KART_STATE_NORMAL) {
        return;
    }
    if (kart->mUnk_4c & 0x10000000) {
        return;
    }
    if ((kart->mUnk_48 & 0x10000020) == 0) {
        kart->mSpeedLimitGoal = raceSpeedLimit->mSpeedLimit;
    }
}

void AdvanceKartAiSpeedLimitByRank(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi,
                                   s32 speedLimitCap) {
    s32 rank = raceSpeedLimit->mRank;
    u16 kartIndex = kartAi->mIndex;
    u16 rankIndex;
    BOOL isHumanGhostOrPeer;
    s32 value;
    s32 otherKartIndex;
    s32 *tableIndices = &raceSpeedLimit->mTableIndex;
    KartAiParamRow *kartAiParamRow = GetKartAiParamRow();
    s32 gap;
    s32 progress;
    const s32 *limitTable;

    raceSpeedLimit->mSpeedLimitReduced = 0;
    isHumanGhostOrPeer = FALSE;
    value = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
    if ((u32) value <= 3) {
        if ((1 << value) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
    }
    if (isHumanGhostOrPeer != FALSE) {
        return;
    }
    if (tableIndices[0] > 2) {
        if (rank > 2) {
            tableIndices[1] = rank;
        }
    }
    if (tableIndices[0] == 1) {
        if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
            if (GetKartRaceProgressScaled(kartIndex) >= 0x28f) {
                if (GetKartRank(kartIndex) >= 4) {
                    for (rankIndex = 1; rankIndex < 4; rankIndex++) {
                        otherKartIndex = GetKartIndexAtRank(rankIndex);
                        if (otherKartIndex >= 0) {
                            KartAi *otherKartAi = GetKart(otherKartIndex)->mAi;
                            KartAiRaceSpeedLimit *otherRaceSpeedLimit = &otherKartAi->mRaceSpeedLimit;

                            if (otherKartAi->mListedCpu != 0) {
                                if (otherRaceSpeedLimit->mTableIndex == 2) {
                                    tableIndices[0] = 2;
                                    tableIndices[1] = tableIndices[0];
                                    otherRaceSpeedLimit->mUnk_20 = 1;
                                    otherRaceSpeedLimit->mTableIndex = otherRaceSpeedLimit->mUnk_20;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    gap = tableIndices[1];
    if (IsKartEnded(kartIndex) != 0) {
        limitTable = data_usa_021658f4;
    } else {
        limitTable = data_usa_0217ae34;
    }
    value = limitTable[rank - 1];
    tableIndices[2] = MUL_FIXED12_NO_ROUND(value, kartAiParamRow->mUnk_04);
    if (IsOneKartNotHumanOrPeer() != 0) {
        rank = kartAiParamRow->mUnk_04;
        otherKartIndex = GetKartAtNonCpuRank();
        if (otherKartIndex >= 0) {
            gap = GetKartRaceProgressScaled(kartAi->mIndex);
            gap -= GetKartRaceProgressScaled((u16) otherKartIndex);
            if (IsKartEnded(kartAi->mIndex) != 0) {
                limitTable = data_usa_021658f4;
            } else {
                limitTable = data_usa_0217ae34;
            }
            value = limitTable[GetKartRank((s32) (u16) otherKartIndex)];
            if (gap > MUL_FIXED12_NO_ROUND(value, rank)) {
                raceSpeedLimit->mSpeedLimitBeforeTurn =
                    MUL_FIXED12_NO_ROUND(raceSpeedLimit->mSpeedLimitBeforeTurn, 0xf85);
                raceSpeedLimit->mSpeedLimitReduced = 1;
            }
        }
    } else if (rank < gap) {
        raceSpeedLimit->mSpeedLimitBeforeTurn = MUL_FIXED12_NO_ROUND(raceSpeedLimit->mSpeedLimitBeforeTurn, 0xe66);
        raceSpeedLimit->mSpeedLimitReduced = 1;
    } else if (rank == gap) {
        if (rank == 1) {
            otherKartIndex = GetKind1KartByRankPlusOffset((u16) rank, data_usa_021658f0);
            if (otherKartIndex >= 0) {
                progress = GetKartRaceProgressScaled(kartIndex);
                progress -= GetKartRaceProgressScaled((u16) otherKartIndex);
                if (progress > GetKart(otherKartIndex)->mAi->mRaceSpeedLimit.mUnk_24) {
                    raceSpeedLimit->mSpeedLimitBeforeTurn =
                        MUL_FIXED12_NO_ROUND(raceSpeedLimit->mSpeedLimitBeforeTurn, 0xf85);
                    raceSpeedLimit->mSpeedLimitReduced = 1;
                }
            }
        } else {
            progress = GetKartRaceProgressScaled(kartIndex);
            otherKartIndex = GetFirstKind1KartByRank();
            if (otherKartIndex >= 0) {
                gap = GetKartRaceProgressScaled((u16) otherKartIndex) - progress;
                gap -= MUL_FIXED12_NO_ROUND(tableIndices[2], GetFirstRankProgressRatio());
                if (gap > 0) {
                    raceSpeedLimit->mSpeedLimitBeforeTurn =
                        raceSpeedLimit->mSpeedLimitBeforeTurn + MUL_FIXED12_NO_ROUND(gap, 0x3000);
                } else {
                    otherKartIndex = GetKind1KartAheadOfRank(rank);
                    if (otherKartIndex >= 0) {
                        Kart *otherKart = GetKart(otherKartIndex);
                        s32 rowValue = kartAiParamRow->mUnk_08;

                        if (otherKart->mAi->mRaceSpeedLimit.mSpeedLimit > MUL_FIXED12_NO_ROUND(rowValue, 0xcd0)) {
                            gap = GetKartRaceProgressScaled((u16) otherKartIndex) - progress;
                            if (gap < MUL_FIXED12_NO_ROUND(tableIndices[2], GetFirstRankProgressRatio())) {
                                raceSpeedLimit->mSpeedLimitBeforeTurn =
                                    MUL_FIXED12_NO_ROUND(raceSpeedLimit->mSpeedLimitBeforeTurn, 0xfae);
                                raceSpeedLimit->mSpeedLimitReduced = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (raceSpeedLimit->mSpeedLimitReduced == 0) {
        raceSpeedLimit->mSpeedLimitBeforeTurn = MUL_FIXED12_NO_ROUND(raceSpeedLimit->mSpeedLimitBeforeTurn, 0x10cd);
        if (raceSpeedLimit->mSpeedLimitBeforeTurn >= speedLimitCap) {
            raceSpeedLimit->mSpeedLimitBeforeTurn = speedLimitCap;
        }
    } else {
        if (raceSpeedLimit->mSpeedLimitBeforeTurn < kartAiParamRow->mUnk_08) {
            raceSpeedLimit->mSpeedLimitBeforeTurn = kartAiParamRow->mUnk_08;
        }
    }
}

// Returns the race start boost choice (1 to 5) of a CPU kart: three candidates by difficulty, picked at random, or the
// last one when a is non-zero.
u16 PickKartAiRaceStartBoost(s32 pickLast) {
    u16 choices[9];
    u16 *difficultyChoices;
    s32 choiceIndex;
    RandomState64 *kartAiRandom;

    choices[0] = data_usa_021658f8[0];
    choices[1] = data_usa_021658f8[1];
    choices[2] = data_usa_021658f8[2];
    choices[3] = data_usa_02165908[0];
    choices[4] = data_usa_02165908[1];
    choices[5] = data_usa_02165908[2];
    choices[6] = data_usa_02165900[0];
    choices[7] = data_usa_02165900[1];
    choices[8] = data_usa_02165900[2];
    difficultyChoices = &choices[6];
    if (pickLast != 0) {
        choiceIndex = 2;
    } else {
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        choiceIndex = (u16) (((kartAiRandom->mValue >> 32) * 3) >> 32);
    }
    switch (gRaceSetup->mCpuDifficulty) {
        case CPU_DIFFICULTY_EASY:
            difficultyChoices = &choices[0];
            break;
        case CPU_DIFFICULTY_NORMAL:
            difficultyChoices = &choices[3];
            break;
    }
    return difficultyChoices[choiceIndex];
}

void InitKartAiRaceSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    s32 speedRatio;

    raceSpeedLimit->mBaseSpeedLimit = kartAi->mKart->mPhysicalParam->mBaseSpeedLimit;
    raceSpeedLimit->mSpeedLimit = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mSpeedLimitAddition = 0;
    raceSpeedLimit->mTurnSpeedLimit = 0;
    raceSpeedLimit->mSpeedLimitBeforeTurn = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mRank = -1;
    raceSpeedLimit->mSpeedLimitReduced = 0;
    raceSpeedLimit->mSpeedLimitBeforeTurn = 0;
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        kartAi->mKart->mForwardSpeed = raceSpeedLimit->mBaseSpeedLimit;
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        speedRatio = GetPointLinkSpeedRatio(&kartAi->mPointLinkCursor);
        kartAi->mKart->mForwardSpeed = MUL_FIXED12_ROUNDED(kartAi->mKart->mPhysicalParam->mBaseSpeedLimit, speedRatio);
        kartAi->mKart->mSpeedLimitGoal = kartAi->mKart->mForwardSpeed;
        kartAi->mKart->mSpeedLimit = kartAi->mKart->mSpeedLimitGoal;
        return;
    }
    PickKartAiRaceStart(raceSpeedLimit, kartAi);
}
