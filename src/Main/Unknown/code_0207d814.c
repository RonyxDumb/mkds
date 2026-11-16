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
#include "Main/Kart/KartTimes.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

void SetupAwardMissionRunKartAi(struct KartAi *kartAi, struct Kart *kart, s32 a) {
    kartAi->mKart = kart;
    kartAi->mIndex = kart->mIndex;
    kartAi->field6 = kartAi->mIndex % 4;
    kartAi->field88 = 0x1000;
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD) {
        kartAi->mDriftChargeRandomLimit = 0;
    } else {
        kartAi->mDriftChargeRandomLimit = 0x1000;
    }
    kartAi->mMinVelocityLength = ((s64) kartAi->mKart->mPhysicalParam->mBaseSpeedLimit * 0x99a + 0x800) >> 12;
    epoi_2080D34(&kartAi->field8, kartAi->mIndex);
    ResetKartAi(kartAi, 0);
    kartAi->fieldCC = 1;
}

void ResetAwardMissionRunKartAi(struct KartAi *kartAi, struct PointLink *pointLink) {
    epoi_2080CD0(&kartAi->field8.mLinkCursor, pointLink);
    ResetKartAi(kartAi, 1);
    ResetKartAi(kartAi, 1);
}

void AdvanceAwardMissionRunKartAi(struct KartAi *kartAi) {
    Vec3 kartPos;
    Vec3 toLinkPos;
    LinkCursor *linkCursor;
    Kart *kart;
    Vec3 *kartForward;
    PointLink *requestedLink;

    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        sub_207E668(kartAi);
    }
    linkCursor = &kartAi->field8.mLinkCursor;
    kart = kartAi->mKart;
    if (kartAi->field90 == 2) {
        kartForward = &kart->mTurnedForward;
    } else {
        kartForward = &kart->field138;
    }
    requestedLink = linkCursor->mRequestedLink;
    driver_getPosition(&kartPos, kartAi->mIndex);
    sub_207F6F0(kartAi, linkCursor, kart, requestedLink, &kartPos, kartForward);
    if (kart->mState == KART_STATE_NORMAL) {
        input_pressVirtualPadKeys(kartAi->mKart->mEntryIndex, PAD_KEY_A);
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kartPos, &toLinkPos);
        AdvanceKartAiHeading(kartAi, &toLinkPos, kartForward);
    }
    enmy_updateDrift1(kartAi);
}

void SetupStaffRollKartAi(struct KartAi *kartAi, struct Kart *kart, s32 a) {
    kartAi->mKart = kart;
    kartAi->mIndex = kart->mIndex;
    kartAi->field6 = kartAi->mIndex % 4;
    kartAi->field88 = 0x1000;
    kartAi->mDriftChargeRandomLimit = 0;
    kartAi->mMinVelocityLength = ((s64) kartAi->mKart->mPhysicalParam->mBaseSpeedLimit * 0x99a + 0x800) >> 12;
    epoi_2080D34(&kartAi->field8, kartAi->mIndex);
    ResetKartAi(kartAi, 0);
    kartAi->fieldCC = 1;
}

void AdvanceStaffRollKartAi(struct KartAi *kartAi) {
    Vec3 kartPos;
    Vec3 toLinkPos;
    LinkCursor *linkCursor = &kartAi->field8.mLinkCursor;
    Kart *kart = kartAi->mKart;
    Vec3 *kartForward;
    PointLink *requestedLink;

    if (kartAi->field90 == 2) {
        kartForward = &kart->mTurnedForward;
    } else {
        kartForward = &kart->field138;
    }
    requestedLink = linkCursor->mRequestedLink;
    driver_getPosition(&kartPos, kartAi->mIndex);
    sub_207F6F0(kartAi, linkCursor, kart, requestedLink, &kartPos, kartForward);
    if (kart->mState == KART_STATE_NORMAL) {
        input_pressVirtualPadKeys(kartAi->mKart->mEntryIndex, PAD_KEY_A);
        VEC_Subtract(&kartAi->mLinkPosWithSideOffset, &kartPos, &toLinkPos);
        AdvanceKartAiHeading(kartAi, &toLinkPos, kartForward);
    }
    enmy_updateDrift1(kartAi);
}

void InitKartAiTables(void) {
    s32 cpuAndGhostKartCount;

    switch (sub_20853DC()) {
        case 0:
            gKartAiRaceStartBoostRandomLimits = data_02155630;
            data_0217ae4c = data_0215569c;
            break;
        case 1:
            gKartAiRaceStartBoostRandomLimits = data_02155654;
            data_0217ae4c = data_021556c0;
            break;
        case 2:
        default:
            gKartAiRaceStartBoostRandomLimits = data_02155678;
            data_0217ae4c = data_0215560c;
            break;
    }
    data_021658f0 = 3;
    cpuAndGhostKartCount = gRaceMultiConfig->mKartCount - gRaceMultiConfig->mHumanAndPeerKartCount;
    if (cpuAndGhostKartCount > 1) {
        if (cpuAndGhostKartCount <= 3) {
            data_021658f0 = cpuAndGhostKartCount - 1;
        }
    }
    data_0217ae54 = data_02165910[cpuAndGhostKartCount];
}

u32 enrb_initForRace(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    u32 value0 = (u32) raceSpeedLimit;
    u32 value1 = (u32) kartAi;
    u32 zero;
    u32 raceSpeedLimitAddress;
    raceSpeedLimitAddress = value0;
    value0 = kartAi->mKart->mPhysicalParam->mBaseSpeedLimit;
    *(u32 *) ((raceSpeedLimitAddress) + (0)) = value0;
    value0 = *(const u32 *) ((raceSpeedLimitAddress) + (0));
    *(u32 *) ((raceSpeedLimitAddress) + (16)) = value0;
    value0 = kartAi->mIndex;
    value0 = GetKartAiTableIndex(value0);
    *(u32 *) ((raceSpeedLimitAddress) + (28)) = value0;
    value0 = *(const u32 *) ((raceSpeedLimitAddress) + (28));
    zero = 0u;
    *(u32 *) ((raceSpeedLimitAddress) + (32)) = value0;
    *(u32 *) ((raceSpeedLimitAddress) + (36)) = zero;
    value1 = *(const u32 *) ((raceSpeedLimitAddress) + (0));
    value0 = ~(0u);
    *(u32 *) ((raceSpeedLimitAddress) + (4)) = value1;
    *(u32 *) ((raceSpeedLimitAddress) + (8)) = zero;
    *(u32 *) ((raceSpeedLimitAddress) + (12)) = zero;
    value1 = *(const u32 *) ((raceSpeedLimitAddress) + (0));
    *(u32 *) ((raceSpeedLimitAddress) + (16)) = value1;
    *(u32 *) ((raceSpeedLimitAddress) + (20)) = value0;
    *(u32 *) ((raceSpeedLimitAddress) + (24)) = zero;
    return value0;
}

void ResetRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    raceSpeedLimit->mSpeedLimit = (u32) (((u32) raceSpeedLimit->mBaseSpeedLimit));
    raceSpeedLimit->mSpeedLimitAddition = 0x0u;
    raceSpeedLimit->mTurnSpeedLimit = 0x0u;
    raceSpeedLimit->mSpeedLimitBeforeTurn = (u32) (((u32) raceSpeedLimit->mBaseSpeedLimit));
    raceSpeedLimit->mRank = (u32) ((~(0x0u)));
    raceSpeedLimit->mSpeedLimitReduced = 0x0u;
}

// Rolls the race start of a CPU kart: a race start boost with its choice, or the flag in field28.
void PickKartAiRaceStart(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    BOOL isHumanGhostOrPeer = FALSE;
    s32 playerKind;
    BOOL boostChosen;
    s32 tableIndex;
    s32 randomValue;
    s32 randomLimit;
    RandomState64 *kartAiRandom;
    KartAi *kartAiOfKart;

    playerKind = gRaceMultiConfig->mCurrentEntries[kartAi->mIndex].mPlayer.mKind;
    if ((u32) playerKind <= 3) {
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
    kartAiOfKart = driver_getById(kartAi->mIndex)->mAi;
    if (kartAiOfKart->field154 != 0) {
        tableIndex = boostChosen;
    }
    randomLimit = gKartAiRaceStartBoostRandomLimits[tableIndex];
    if (randomValue < randomLimit || randomLimit >= 0x1000) {
        raceSpeedLimit->mBoostsAtRaceStart = 1;
        raceSpeedLimit->mRaceStartBoostChoice = PickKartAiRaceStartBoost(kartAiOfKart->field154);
        boostChosen = TRUE;
    }
    if (boostChosen != FALSE) {
        return;
    }
    randomLimit = data_0217ae4c[tableIndex];
    if (randomValue >= randomLimit) {
        if (!(randomLimit >= 1.0f)) {
            return;
        }
    }
    raceSpeedLimit->field28 = 1;
}

// Every eighth frame, on this kart's turn, recomputes the CPU speed limit; every call sets the kart's limit from it.
void enrb_updateForRace(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    BOOL isHumanGhostOrPeer;
    s32 playerKind;
    s32 t;
    s32 turnExcessRatio;
    Kart *kart;

    if (kartAi->mIndex == race_getFrameCounterModulo8()) {
        raceSpeedLimit->mSpeedLimitAddition = 0;
        raceSpeedLimit->mSpeedLimitReduced = 0;
        isHumanGhostOrPeer = FALSE;
        playerKind = gRaceMultiConfig->mCurrentEntries[kartAi->mIndex].mPlayer.mKind;
        if ((u32) playerKind <= 3) {
            if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                isHumanGhostOrPeer = TRUE;
            }
        }
        if (isHumanGhostOrPeer != FALSE) {
            raceSpeedLimit->mRank = rstat_getPlace(kartAi->mIndex);
        } else {
            raceSpeedLimit->mRank = GetKartRankAmongKind1(kartAi->mIndex);
        }
        raceSpeedLimit->mSpeedLimitAddition = GetKartAiParamRow()->field0;
        if (sub_2085390() != 0) {
            raceSpeedLimit->mSpeedLimitAddition = raceSpeedLimit->mSpeedLimitAddition >> 1;
        }
        kart = kartAi->mKart;
        t = raceSpeedLimit->mSpeedLimitAddition + kart->mSpeedLimitGoal;
        if (kartAi->fieldA8 == 2) {
            t = 0x3000;
        }
        if (t > 0xa000) {
            t = 0xa000;
        }
        if (kart->field4C & 0x8000000) {
            t = ((s64) t * 0xb33 + 0x800) >> 12;
        }
        if (kartAi->field90 == 0) {
            raceSpeedLimit->mTurnSpeedLimit = t;
            if (kartAi->mTurnAngleDegrees > 0x5000) {
                turnExcessRatio = ((s64) (kartAi->mTurnAngleDegrees - 0x5000) * 0x5b) >> 12;
                if (turnExcessRatio > 0x1000) {
                    turnExcessRatio = 0x1000;
                }
                raceSpeedLimit->mTurnSpeedLimit =
                    ((s64) (0x1000 - (s32) (((s64) turnExcessRatio * 0x668) >> 12)) * 0xa000) >> 12;
            }
            enrb_updateRubberBanding(raceSpeedLimit, kartAi, t);
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
    if (kart->field4C & 0x10000000) {
        return;
    }
    if ((kart->field48 & 0x10000020) == 0) {
        kart->mSpeedLimitGoal = raceSpeedLimit->mSpeedLimit;
    }
}

void enrb_updateRubberBanding(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi, s32 speedLimitCap) {
    s32 n = raceSpeedLimit->mRank;
    u16 kartIndex = kartAi->mIndex;
    u16 i;
    BOOL isHumanGhostOrPeer;
    s32 v;
    s32 d;
    s32 *k = &raceSpeedLimit->field1C;
    KartAiParamRow *kartAiParamRow = GetKartAiParamRow();
    s32 e;
    s32 g;
    const s32 *t;

    raceSpeedLimit->mSpeedLimitReduced = 0;
    isHumanGhostOrPeer = FALSE;
    v = gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.mKind;
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
        if (gRaceMultiConfig->mMode == MODE_GRAND_PRIX) {
            if (GetKartRaceProgressScaled(kartIndex) >= 0x28f) {
                if (rstat_getPlace(kartIndex) >= 4) {
                    for (i = 1; i < 4; i++) {
                        d = GetKartIndexAtRank(i);
                        if (d >= 0) {
                            KartAi *otherKartAi = driver_getById(d)->mAi;
                            KartAiRaceSpeedLimit *otherRaceSpeedLimit = &otherKartAi->fieldE8;

                            if (otherKartAi->field154 != 0) {
                                if (otherRaceSpeedLimit->field1C == 2) {
                                    k[0] = 2;
                                    k[1] = k[0];
                                    otherRaceSpeedLimit->field20 = 1;
                                    otherRaceSpeedLimit->field1C = otherRaceSpeedLimit->field20;
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
    if (rstat_hasDriverFinished(kartIndex) != 0) {
        t = data_021658f4;
    } else {
        t = data_0217ae54;
    }
    v = t[n - 1];
    k[2] = ((s64) v * kartAiParamRow->field4) >> 12;
    if (sub_2085390() != 0) {
        n = kartAiParamRow->field4;
        d = sub_2085434();
        if (d >= 0) {
            e = GetKartRaceProgressScaled(kartAi->mIndex);
            e -= GetKartRaceProgressScaled((u16) d);
            if (rstat_hasDriverFinished(kartAi->mIndex) != 0) {
                t = data_021658f4;
            } else {
                t = data_0217ae54;
            }
            v = t[rstat_getPlace((s32) (u16) d)];
            if (e > (s32) (((s64) v * n) >> 12)) {
                raceSpeedLimit->mSpeedLimitBeforeTurn = ((s64) raceSpeedLimit->mSpeedLimitBeforeTurn * 0xf85) >> 12;
                raceSpeedLimit->mSpeedLimitReduced = 1;
            }
        }
    } else if (n < e) {
        raceSpeedLimit->mSpeedLimitBeforeTurn = ((s64) raceSpeedLimit->mSpeedLimitBeforeTurn * 0xe66) >> 12;
        raceSpeedLimit->mSpeedLimitReduced = 1;
    } else if (n == e) {
        if (n == 1) {
            d = sub_20854A0((u16) n, data_021658f0);
            if (d >= 0) {
                g = GetKartRaceProgressScaled(kartIndex);
                g -= GetKartRaceProgressScaled((u16) d);
                if (g > driver_getById(d)->mAi->fieldE8.field24) {
                    raceSpeedLimit->mSpeedLimitBeforeTurn = ((s64) raceSpeedLimit->mSpeedLimitBeforeTurn * 0xf85) >> 12;
                    raceSpeedLimit->mSpeedLimitReduced = 1;
                }
            }
        } else {
            g = GetKartRaceProgressScaled(kartIndex);
            d = GetFirstKind1KartByRank();
            if (d >= 0) {
                e = GetKartRaceProgressScaled((u16) d) - g;
                e -= (s32) (((s64) k[2] * sub_208548C()) >> 12);
                if (e > 0) {
                    raceSpeedLimit->mSpeedLimitBeforeTurn =
                        raceSpeedLimit->mSpeedLimitBeforeTurn + (s32) (((s64) e * 0x3000) >> 12);
                } else {
                    d = sub_2085458(n);
                    if (d >= 0) {
                        Kart *otherKart = driver_getById(d);
                        s32 w = kartAiParamRow->field8;

                        if (otherKart->mAi->fieldE8.mSpeedLimit > (s32) (((s64) w * 0xcd0) >> 12)) {
                            e = GetKartRaceProgressScaled((u16) d) - g;
                            if (e < (s32) (((s64) k[2] * sub_208548C()) >> 12)) {
                                raceSpeedLimit->mSpeedLimitBeforeTurn =
                                    ((s64) raceSpeedLimit->mSpeedLimitBeforeTurn * 0xfae) >> 12;
                                raceSpeedLimit->mSpeedLimitReduced = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (raceSpeedLimit->mSpeedLimitReduced == 0) {
        raceSpeedLimit->mSpeedLimitBeforeTurn = ((s64) raceSpeedLimit->mSpeedLimitBeforeTurn * 0x10cd) >> 12;
        if (raceSpeedLimit->mSpeedLimitBeforeTurn >= speedLimitCap) {
            raceSpeedLimit->mSpeedLimitBeforeTurn = speedLimitCap;
        }
    } else {
        if (raceSpeedLimit->mSpeedLimitBeforeTurn < kartAiParamRow->field8) {
            raceSpeedLimit->mSpeedLimitBeforeTurn = kartAiParamRow->field8;
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

    choices[0] = g_CpuMode1SomeArray[0];
    choices[1] = g_CpuMode1SomeArray[1];
    choices[2] = g_CpuMode1SomeArray[2];
    choices[3] = g_CpuMode2SomeArray[0];
    choices[4] = g_CpuMode2SomeArray[1];
    choices[5] = g_CpuMode2SomeArray[2];
    choices[6] = data_02165900[0];
    choices[7] = data_02165900[1];
    choices[8] = data_02165900[2];
    difficultyChoices = &choices[6];
    if (pickLast != 0) {
        choiceIndex = 2;
    } else {
        kartAiRandom = GetKartAiRandom();
        kartAiRandom->mValue = kartAiRandom->mMultiplier * kartAiRandom->mValue + kartAiRandom->mIncrement;
        choiceIndex = (u16) (((kartAiRandom->mValue >> 32) * 3) >> 32);
    }
    switch (gRaceMultiConfig->mCpuDifficulty) {
        case CPU_DIFFICULTY_EASY:
            difficultyChoices = &choices[0];
            break;
        case CPU_DIFFICULTY_NORMAL:
            difficultyChoices = &choices[3];
            break;
    }
    return difficultyChoices[choiceIndex];
}

void enrb_initForAwardStaffRoll(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    s32 speedRatio;

    raceSpeedLimit->mBaseSpeedLimit = kartAi->mKart->mPhysicalParam->mBaseSpeedLimit;
    raceSpeedLimit->mSpeedLimit = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mSpeedLimitAddition = 0;
    raceSpeedLimit->mTurnSpeedLimit = 0;
    raceSpeedLimit->mSpeedLimitBeforeTurn = raceSpeedLimit->mBaseSpeedLimit;
    raceSpeedLimit->mRank = -1;
    raceSpeedLimit->mSpeedLimitReduced = 0;
    raceSpeedLimit->mSpeedLimitBeforeTurn = 0;
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD) {
        kartAi->mKart->mForwardSpeed = raceSpeedLimit->mBaseSpeedLimit;
        return;
    }
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
        speedRatio = GetPointLinkSpeedRatio((PointLinkCursor *) &kartAi->field8.mLinkCursor);
        kartAi->mKart->mForwardSpeed =
            ((s64) kartAi->mKart->mPhysicalParam->mBaseSpeedLimit * speedRatio + 0x800) >> 12;
        kartAi->mKart->mSpeedLimitGoal = kartAi->mKart->mForwardSpeed;
        kartAi->mKart->mSpeedLimit = kartAi->mKart->mSpeedLimitGoal;
        return;
    }
    PickKartAiRaceStart(raceSpeedLimit, kartAi);
}
