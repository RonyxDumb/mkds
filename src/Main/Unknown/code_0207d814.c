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

void SetupAwardMissionRunKartAi(struct KartAi *kartAi, struct Kart *kart, s32 a) {
    kartAi->mKart = kart;
    kartAi->mIndex = kart->mIndex;
    kartAi->mUnk_06 = kartAi->mIndex % 4;
    kartAi->mUnk_88 = 0x1000;
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        kartAi->mDriftChargeRandomLimit = 0;
    } else {
        kartAi->mDriftChargeRandomLimit = 0x1000;
    }
    kartAi->mMinVelocityLength = MUL_FIXED12_ROUNDED(kartAi->mKart->mPhysicalParam->mBaseSpeedLimit, 0x99a);
    InitRacePointLinkCursor(&kartAi->mUnk_08, kartAi->mIndex);
    ResetKartAi(kartAi, 0);
    kartAi->mUnk_cc = 1;
}

void ResetAwardMissionRunKartAi(struct KartAi *kartAi, struct RacePointLink *pointLink) {
    ResetPointLinkCursor(&kartAi->mUnk_08, pointLink);
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
    linkCursor = &kartAi->mUnk_08;
    kart = kartAi->mKart;
    if (kartAi->mUnk_90 == 2) {
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

void SetupStaffRollKartAi(struct KartAi *kartAi, struct Kart *kart, s32 a) {
    kartAi->mKart = kart;
    kartAi->mIndex = kart->mIndex;
    kartAi->mUnk_06 = kartAi->mIndex % 4;
    kartAi->mUnk_88 = 0x1000;
    kartAi->mDriftChargeRandomLimit = 0;
    kartAi->mMinVelocityLength = MUL_FIXED12_ROUNDED(kartAi->mKart->mPhysicalParam->mBaseSpeedLimit, 0x99a);
    InitRacePointLinkCursor(&kartAi->mUnk_08, kartAi->mIndex);
    ResetKartAi(kartAi, 0);
    kartAi->mUnk_cc = 1;
}

void AdvanceStaffRollKartAi(struct KartAi *kartAi) {
    Vec3 kartPos;
    Vec3 toLinkPos;
    PointLinkCursor *linkCursor = &kartAi->mUnk_08;
    Kart *kart = kartAi->mKart;
    Vec3 *kartForward;
    RacePointLink *requestedLink;

    if (kartAi->mUnk_90 == 2) {
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
    raceSpeedLimit->mUnk_1c = GetKartAiTableIndex(kartAi->mIndex);
    raceSpeedLimit->mUnk_20 = raceSpeedLimit->mUnk_1c;
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
    if (kartAiOfKart->mUnk_154 != 0) {
        tableIndex = boostChosen;
    }
    randomLimit = gKartAiRaceStartBoostRandomLimits[tableIndex];
    if (randomValue < randomLimit || randomLimit >= 0x1000) {
        raceSpeedLimit->mBoostsAtRaceStart = 1;
        raceSpeedLimit->mRaceStartBoostChoice = PickKartAiRaceStartBoost(kartAiOfKart->mUnk_154);
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
    s32 t;
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
        t = raceSpeedLimit->mSpeedLimitAddition + kart->mSpeedLimitGoal;
        if (kartAi->mUnk_a8 == 2) {
            t = 0x3000;
        }
        if (t > 0xa000) {
            t = 0xa000;
        }
        if (kart->mUnk_4c & 0x8000000) {
            t = MUL_FIXED12_ROUNDED(t, 0xb33);
        }
        if (kartAi->mUnk_90 == 0) {
            raceSpeedLimit->mTurnSpeedLimit = t;
            if (kartAi->mTurnAngleDegrees > 0x5000) {
                turnExcessRatio = MUL_FIXED12_NO_ROUND(kartAi->mTurnAngleDegrees - 0x5000, 0x5b);
                if (turnExcessRatio > 0x1000) {
                    turnExcessRatio = 0x1000;
                }
                raceSpeedLimit->mTurnSpeedLimit =
                    MUL_FIXED12_NO_ROUND(0x1000 - MUL_FIXED12_NO_ROUND(turnExcessRatio, 0x668), 0xa000);
            }
            AdvanceKartAiSpeedLimitByRank(raceSpeedLimit, kartAi, t);
            t = raceSpeedLimit->mSpeedLimitBeforeTurn;
        }
        if (raceSpeedLimit->mTurnSpeedLimit < t) {
            t = raceSpeedLimit->mTurnSpeedLimit;
        }
        if (t > 0xa000) {
            t = 0xa000;
        }
        raceSpeedLimit->mSpeedLimit = t;
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
    s32 n = raceSpeedLimit->mRank;
    u16 kartIndex = kartAi->mIndex;
    u16 i;
    BOOL isHumanGhostOrPeer;
    s32 v;
    s32 d;
    s32 *k = &raceSpeedLimit->mUnk_1c;
    KartAiParamRow *kartAiParamRow = GetKartAiParamRow();
    s32 e;
    s32 g;
    const s32 *t;

    raceSpeedLimit->mSpeedLimitReduced = 0;
    isHumanGhostOrPeer = FALSE;
    v = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
    if ((u32) v <= 3) {
        if ((1 << v) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
    }
    if (isHumanGhostOrPeer != FALSE) {
        return;
    }
    if (k[0] > 2) {
        if (n > 2) {
            k[1] = n;
        }
    }
    if (k[0] == 1) {
        if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
            if (GetKartRaceProgressScaled(kartIndex) >= 0x28f) {
                if (GetKartRank(kartIndex) >= 4) {
                    for (i = 1; i < 4; i++) {
                        d = GetKartIndexAtRank(i);
                        if (d >= 0) {
                            KartAi *otherKartAi = GetKart(d)->mAi;
                            KartAiRaceSpeedLimit *otherRaceSpeedLimit = &otherKartAi->mUnk_e8;

                            if (otherKartAi->mUnk_154 != 0) {
                                if (otherRaceSpeedLimit->mUnk_1c == 2) {
                                    k[0] = 2;
                                    k[1] = k[0];
                                    otherRaceSpeedLimit->mUnk_20 = 1;
                                    otherRaceSpeedLimit->mUnk_1c = otherRaceSpeedLimit->mUnk_20;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    e = k[1];
    if (IsKartEnded(kartIndex) != 0) {
        t = data_usa_021658f4;
    } else {
        t = data_usa_0217ae34;
    }
    v = t[n - 1];
    k[2] = MUL_FIXED12_NO_ROUND(v, kartAiParamRow->mUnk_04);
    if (IsOneKartNotHumanOrPeer() != 0) {
        n = kartAiParamRow->mUnk_04;
        d = GetKartAtNonCpuRank();
        if (d >= 0) {
            e = GetKartRaceProgressScaled(kartAi->mIndex);
            e -= GetKartRaceProgressScaled((u16) d);
            if (IsKartEnded(kartAi->mIndex) != 0) {
                t = data_usa_021658f4;
            } else {
                t = data_usa_0217ae34;
            }
            v = t[GetKartRank((s32) (u16) d)];
            if (e > MUL_FIXED12_NO_ROUND(v, n)) {
                raceSpeedLimit->mSpeedLimitBeforeTurn =
                    MUL_FIXED12_NO_ROUND(raceSpeedLimit->mSpeedLimitBeforeTurn, 0xf85);
                raceSpeedLimit->mSpeedLimitReduced = 1;
            }
        }
    } else if (n < e) {
        raceSpeedLimit->mSpeedLimitBeforeTurn = MUL_FIXED12_NO_ROUND(raceSpeedLimit->mSpeedLimitBeforeTurn, 0xe66);
        raceSpeedLimit->mSpeedLimitReduced = 1;
    } else if (n == e) {
        if (n == 1) {
            d = GetKind1KartByRankPlusOffset((u16) n, data_usa_021658f0);
            if (d >= 0) {
                g = GetKartRaceProgressScaled(kartIndex);
                g -= GetKartRaceProgressScaled((u16) d);
                if (g > GetKart(d)->mAi->mUnk_e8.mUnk_24) {
                    raceSpeedLimit->mSpeedLimitBeforeTurn =
                        MUL_FIXED12_NO_ROUND(raceSpeedLimit->mSpeedLimitBeforeTurn, 0xf85);
                    raceSpeedLimit->mSpeedLimitReduced = 1;
                }
            }
        } else {
            g = GetKartRaceProgressScaled(kartIndex);
            d = GetFirstKind1KartByRank();
            if (d >= 0) {
                e = GetKartRaceProgressScaled((u16) d) - g;
                e -= MUL_FIXED12_NO_ROUND(k[2], GetFirstRankProgressRatio());
                if (e > 0) {
                    raceSpeedLimit->mSpeedLimitBeforeTurn =
                        raceSpeedLimit->mSpeedLimitBeforeTurn + MUL_FIXED12_NO_ROUND(e, 0x3000);
                } else {
                    d = GetKind1KartAheadOfRank(n);
                    if (d >= 0) {
                        Kart *otherKart = GetKart(d);
                        s32 w = kartAiParamRow->mUnk_08;

                        if (otherKart->mAi->mUnk_e8.mSpeedLimit > MUL_FIXED12_NO_ROUND(w, 0xcd0)) {
                            e = GetKartRaceProgressScaled((u16) d) - g;
                            if (e < MUL_FIXED12_NO_ROUND(k[2], GetFirstRankProgressRatio())) {
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
        speedRatio = GetPointLinkSpeedRatio(&kartAi->mUnk_08);
        kartAi->mKart->mForwardSpeed = MUL_FIXED12_ROUNDED(kartAi->mKart->mPhysicalParam->mBaseSpeedLimit, speedRatio);
        kartAi->mKart->mSpeedLimitGoal = kartAi->mKart->mForwardSpeed;
        kartAi->mKart->mSpeedLimit = kartAi->mKart->mSpeedLimitGoal;
        return;
    }
    PickKartAiRaceStart(raceSpeedLimit, kartAi);
}
