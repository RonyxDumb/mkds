#include "Main/Unknown/code_020a02f8.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02068000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02156000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020a1728.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a2220.h"
#include "Main/Unknown/code_020a223c.h"
#include "Main/Unknown/code_020a228c.h"
#include "Main/Unknown/code_020a22ac.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_0203ca38.h"
#include "Main/Unknown/code_02077bc0.h"

void mgcnt_setBlncntDriverEntries(KartBalloons *kartBalloons) {
    mgcnt_sMinigameController->mKartBalloons = kartBalloons;
}

KartBalloons *mgcnt_getBlncntDriverEntries(void) {
    return mgcnt_sMinigameController->mKartBalloons;
}

void mgcnt_setTryStealBalloonFunc(s32 (*callback)(s32, s32)) {
    mgcnt_sMinigameController->mKartHitByKartCallback = callback;
}

void mgcnt_setField384(void (*callback)(s32, s32)) {
    mgcnt_sMinigameController->mKartsHitEachOtherCallback = callback;
}

void mgcnt_setOnDamageFunc(s32 (*callback)(u16 a, u16 b)) {
    mgcnt_sMinigameController->mKartHitCallback = callback;
}

// Stores the kart-eliminated callback.
void mgcnt_setOnKillFunc(void (*callback)(u16 a)) {
    mgcnt_sMinigameController->mKartEliminatedCallback = callback;
}

// Stores the end callback.
void mgcnt_setOnEndFunc(void (*callback)(void)) {
    mgcnt_sMinigameController->mEndCallback = callback;
}

void mgcnt_setApplyForceToDriverBalloonsFunc(void (*callback)(s32, s32)) {
    mgcnt_sMinigameController->mKartOffsetCallback = callback;
}

void mgcnt_driverInflateBalloonByMic(u16 kartIndex) {
    if (race_getState() != 1) {
        return;
    }
    if (func_01ffc67c(driver_getById(kartIndex)) != FALSE) {
        return;
    }
    mgcnt_sMinigameController->mKarts[kartIndex].field64 = 10;
}

void mgcnt_driverStopInflateBalloonByMic(int kartIndex) {
    mgcnt_sMinigameController->mKarts[kartIndex].field64 = 0xffffffff;
}

s32 mgcnt_getDriverMicInflatingCounter(u16 kartIndex) {
    if (mgcnt_sMinigameController->mWinnerTeamId >= 0) {
        return -1;
    }
    return mgcnt_sMinigameController->mKarts[kartIndex].field64;
}

s32 mgcnt_getDriverKeyInflating(u16 kartIndex) {
    if (mgcnt_sMinigameController->mWinnerTeamId >= 0) {
        return -1;
    }
    return mgcnt_sMinigameController->mKarts[kartIndex].field68;
}

void mgcnt_setDriverIsInflating(u16 kartIndex, u32 inflating) {
    mgcnt_sMinigameController->mKarts[kartIndex].mInflatingBalloon = inflating;
}

u32 mgcnt_getDriverIsInflating(u16 kartIndex) {
    return mgcnt_sMinigameController->mKarts[kartIndex].mInflatingBalloon;
}

void mgcnt_applyForceToDriverBalloons(s32 a, s32 b) {
    if (b == 0) {
        return;
    }
    if (mgcnt_sMinigameController->mKartOffsetCallback != NULL) {
        mgcnt_sMinigameController->mKartOffsetCallback(a, b);
    }
}

s32 mgcnt_handleDriverDriverCollide(s32 firstKartIndex, s32 secondKartIndex) {
    Kart *firstKart;
    Kart *secondKart;
    KartStanding *firstStanding;
    KartStanding *secondStanding;
    BOOL f5;
    s32 f4;
    BOOL f11;
    BOOL t;

    if (mgcnt_sMinigameController->mWinnerTeamId >= 0) {
        return 0;
    }
    firstKart = driver_getById(firstKartIndex);
    secondKart = driver_getById(secondKartIndex);
    secondStanding = &mgcnt_sMinigameController->mKarts[secondKartIndex];
    firstStanding = &mgcnt_sMinigameController->mKarts[firstKartIndex];
    f5 = FALSE;
    if (secondStanding->field24[firstKartIndex] == 0) {
        if ((firstKart->field48 & 0x100000) != 0) {
            f5 = TRUE;
        }
    }
    f4 = 0;
    if (firstStanding->field24[secondKartIndex] == 0) {
        if ((secondKart->field48 & 0x100000) != 0) {
            f4 = 1;
        }
    }
    f11 = TRUE;
    if ((firstKart->field4C & 0x400000) == 0) {
        if (driver_getCollisionMode(firstKartIndex) != 1) {
            f11 = FALSE;
        }
    }
    t = TRUE;
    if ((secondKart->field4C & 0x400000) == 0) {
        if (driver_getCollisionMode(secondKartIndex) != 1) {
            t = FALSE;
        }
    }
    if (f4 != 0) {
        firstStanding->field24[secondKartIndex] = 1;
    }
    if (f5 != FALSE) {
        secondStanding->field24[firstKartIndex] = 1;
    }
    if (f11 == FALSE && t == FALSE && f5 != FALSE && f4 != 0) {
        if (mgcnt_sMinigameController->mKartsHitEachOtherCallback != NULL) {
            mgcnt_sMinigameController->mKartsHitEachOtherCallback(firstKartIndex, secondKartIndex);
            return 1;
        }
    } else if (f11 == FALSE && f4 != 0) {
        f4 = 0;
        if (driver_getCollisionMode(secondKartIndex) == 1) {
            firstStanding->field20 = TRUE;
            if (mgcnt_sMinigameController->mKartHitByKartCallback != NULL) {
                f4 = mgcnt_sMinigameController->mKartHitByKartCallback(firstKartIndex, secondKartIndex);
                if ((firstKart->field4C & 0x400000) == 0) {
                    StructMQRacerEntry_SomeFn_30(firstKart);
                }
            }
        } else if (mgcnt_sMinigameController->mKartHitByKartCallback != NULL) {
            f4 = mgcnt_sMinigameController->mKartHitByKartCallback(firstKartIndex, secondKartIndex);
            if ((firstKart->field4C & 0x400000) == 0) {
                StructMQRacerEntry_SomeFn_30(firstKart);
            }
        }
        return f4;
    } else if (t == FALSE && f5 != FALSE) {
        f4 = 0;
        if (driver_getCollisionMode(firstKartIndex) == 1) {
            secondStanding->field20 = TRUE;
            if (mgcnt_sMinigameController->mKartHitByKartCallback != NULL) {
                f4 = mgcnt_sMinigameController->mKartHitByKartCallback(secondKartIndex, firstKartIndex);
                if ((secondKart->field4C & 0x400000) == 0) {
                    StructMQRacerEntry_SomeFn_30(secondKart);
                }
            }
        } else if (mgcnt_sMinigameController->mKartHitByKartCallback != NULL) {
            f4 = mgcnt_sMinigameController->mKartHitByKartCallback(secondKartIndex, firstKartIndex);
            if ((secondKart->field4C & 0x400000) == 0) {
                StructMQRacerEntry_SomeFn_30(secondKart);
            }
        }
        return f4;
    }
    return 0;
}

void mgcnt_20A1E40(s32 kartIndex, ItemObject *itemObject) {
    u16 v;

    if (mgcnt_sMinigameController->mWinnerTeamId >= 0) {
        return;
    }
    if (driver_getById(kartIndex)->mState == KART_STATE_NORMAL) {
        return;
    }
    if (itemObject->mKind != 0 && itemObject->mKind != 1 && itemObject->mKind != 9) {
        return;
    }
    v = itemObject->field78;
    if ((v & 0x8000) != 0) {
        return;
    }
    mgcnt_sMinigameController->mKarts[kartIndex].mHitByKartIndex = v & ~0xff00;
}

u32 mgcnt_notifyStarInvincibilityStart(u32 value) {
    return value;
}

void mgcnt_20A1DDC(s32 kartIndex) {
    s32 i;
    s32 kartCount;

    kartCount = gRaceMultiConfig->mKartCount;
    for (i = 0; i < kartCount; i++) {
        mgcnt_sMinigameController->mKarts[i].field24[kartIndex] = 0;
    }
}

static inline u16 func_020a1790_inline(Standings *standings, s32 rankIndex) {
    s32 j;

    for (j = 0; j < 8; j++) {
        if ((u16) rankIndex == standings->mKarts[j].mRankIndex) {
            return j;
        }
    }
    return 0;
}

u16 mgcnt_20A1CD8(s32 kartIndex) {
    s32 rank;
    s32 i;
    s32 highestCount;

    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        if (gRaceMultiConfig->mBattleKind == BATTLE_KIND_BALLOON) {
            rank = 3 - mgcnt_sMinigameController->mKarts[kartIndex].mBalloonOrShineCount;
            rank += 1;
        } else if (gRaceMultiConfig->mBattleKind == BATTLE_KIND_SHINE) {
            highestCount = 1;
            for (i = 0; i < gRaceMultiConfig->mKartCount; i++) {
                if (mgcnt_sMinigameController->mKarts[i].mBalloonOrShineCount > highestCount) {
                    highestCount = mgcnt_sMinigameController->mKarts[i].mBalloonOrShineCount;
                }
            }
            rank = (highestCount + 1 - mgcnt_sMinigameController->mKarts[kartIndex].mBalloonOrShineCount) / 2 + 1;
        } else {
            rank = kartIndex;
        }
    } else {
        rank = 3 - mgcnt_sMinigameController->mKarts[kartIndex].mBalloonOrShineCount;
        rank += 1;
    }
    if (rank < 1) {
        rank = 1;
    } else if (rank > 3) {
        rank = 3;
    }
    return rank;
}

void mgcnt_handleDriverBalloonShineCountIncrease(u16 kartIndex) {
    s32 i;
    s32 j;
    s32 kartCount;
    s32 count;
    KartStanding *ownStanding;
    u16 otherRankIndex;
    u16 ownRankIndex;
    KartStanding *otherStanding;

    for (i = mgcnt_sMinigameController->mKarts[kartIndex].mRankIndex - 1; i >= 0; i--) {
        otherStanding = &mgcnt_sMinigameController->mKarts[func_020a1790_inline(mgcnt_sMinigameController, i)];
        otherRankIndex = otherStanding->mRankIndex;
        ownRankIndex = mgcnt_sMinigameController->mKarts[kartIndex].mRankIndex;
        ownStanding = &mgcnt_sMinigameController->mKarts[kartIndex];
        if (ownRankIndex > otherRankIndex) {
            if (ownStanding->mBalloonOrShineCount > otherStanding->mBalloonOrShineCount ||
                (ownStanding->mEliminationStatus == 0 && otherStanding->mEliminationStatus != 0)) {
                otherStanding->mRankIndex = ownRankIndex;
                mgcnt_sMinigameController->mKarts[kartIndex].mRankIndex = otherRankIndex;
            }
        }
    }
    kartCount = gRaceMultiConfig->mKartCount;
    mgcnt_sMinigameController->mLowestBalloonOrShineCount = 0xffff;
    mgcnt_sMinigameController->mHighestBalloonOrShineCount = 0;
    for (j = 0; j < kartCount; j++) {
        count = mgcnt_sMinigameController->mKarts[j].mBalloonOrShineCount;
        mgcnt_sMinigameController->mLowestBalloonOrShineCount = (count < mgcnt_sMinigameController->mLowestBalloonOrShineCount && count >= 0)
                                                     ? count
                                                     : mgcnt_sMinigameController->mLowestBalloonOrShineCount;
        count = mgcnt_sMinigameController->mKarts[j].mBalloonOrShineCount;
        mgcnt_sMinigameController->mHighestBalloonOrShineCount =
            (count > mgcnt_sMinigameController->mHighestBalloonOrShineCount) ? count : mgcnt_sMinigameController->mHighestBalloonOrShineCount;
    }
}

void mgcnt_handleDriverBalloonShineCountDecrease(u16 kartIndex) {
    s32 i;
    s32 j;
    s32 kartCount;
    s32 count;
    KartStanding *ownStanding;
    u16 otherRankIndex;
    u16 ownRankIndex;
    KartStanding *otherStanding;

    for (i = mgcnt_sMinigameController->mKarts[kartIndex].mRankIndex + 1; i < 8; i++) {
        otherStanding = &mgcnt_sMinigameController->mKarts[func_020a1790_inline(mgcnt_sMinigameController, i)];
        otherRankIndex = otherStanding->mRankIndex;
        ownRankIndex = mgcnt_sMinigameController->mKarts[kartIndex].mRankIndex;
        ownStanding = &mgcnt_sMinigameController->mKarts[kartIndex];
        if (ownRankIndex < otherRankIndex) {
            if (ownStanding->mBalloonOrShineCount < otherStanding->mBalloonOrShineCount ||
                (ownStanding->mEliminationStatus != 0 && otherStanding->mEliminationStatus == 0)) {
                otherStanding->mRankIndex = ownRankIndex;
                mgcnt_sMinigameController->mKarts[kartIndex].mRankIndex = otherRankIndex;
            }
        }
    }
    kartCount = gRaceMultiConfig->mKartCount;
    mgcnt_sMinigameController->mLowestBalloonOrShineCount = 0xffff;
    mgcnt_sMinigameController->mHighestBalloonOrShineCount = 0;
    for (j = 0; j < kartCount; j++) {
        count = mgcnt_sMinigameController->mKarts[j].mBalloonOrShineCount;
        mgcnt_sMinigameController->mLowestBalloonOrShineCount = (count < mgcnt_sMinigameController->mLowestBalloonOrShineCount && count >= 0)
                                                     ? count
                                                     : mgcnt_sMinigameController->mLowestBalloonOrShineCount;
        count = mgcnt_sMinigameController->mKarts[j].mBalloonOrShineCount;
        mgcnt_sMinigameController->mHighestBalloonOrShineCount =
            (count > mgcnt_sMinigameController->mHighestBalloonOrShineCount) ? count : mgcnt_sMinigameController->mHighestBalloonOrShineCount;
    }
}

// Takes one kart out of play: runs the kart-eliminated callback, sets its status to 1, in mode 2 sets its count to -1,
// re-sorts the ranks and starts the mode's out handling of the kart (mode 2: a kart handler call; mode 4: two bits in
// the kart's words).
void mgcnt_killDriverDirect(u16 kartIndex) {
    Kart *kart;

    if (mgcnt_sMinigameController->mKartEliminatedCallback != NULL) {
        mgcnt_sMinigameController->mKartEliminatedCallback(kartIndex);
    }
    mgcnt_sMinigameController->mKarts[kartIndex].mEliminationStatus = 1;
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        mgcnt_sMinigameController->mKarts[kartIndex].mBalloonOrShineCount = -1;
        mgcnt_sMinigameController->mKarts[kartIndex].mBalloonsLeftToMake = 0;
    }
    if ((u32) kartIndex >= gRaceMultiConfig->mKartCount) {
        return;
    }
    mgcnt_handleDriverBalloonShineCountDecrease(kartIndex);
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        driver_killForMg(driver_getById(kartIndex));
    } else if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        kart = driver_getById(kartIndex);
        kart->field48 |= 0x2000;
        kart->field7C |= 8;
    }
}

void mgcnt_checkMgEnd(void) {
    s32 kartCount;
    s32 teamId;
    s32 i;
    s32 j;
    s32 entryIndex;
    s32 k;
    u16 firstRankKartIndex;
    Standings *standings;
    KartStanding *kartStanding;
    Kart *kart;

    kartCount = gRaceMultiConfig->mKartCount;
    standings = mgcnt_sMinigameController;
    for (k = 0; k < 8; k++) {
        if (standings->mKarts[k].mRankIndex == 0) {
            firstRankKartIndex = k;
            goto found;
        }
    }
    firstRankKartIndex = 0;
found:
    teamId = standings->mKarts[firstRankKartIndex].mTeamId;
    kartStanding = standings->mKarts;
    for (j = 0; j < 8; j++, kartStanding++) {
        if (kartStanding->mEliminationStatus == 0) {
            if (teamId != kartStanding->mTeamId) {
                return;
            }
        }
    }
    for (i = 0; i < kartCount; i++) {
        kart = driver_getById((u16) i);
        kart->field48 |= 0x2000;
        kart->field7C |= 8;
    }
    mgcnt_sMinigameController->mWinnerTeamId = teamId;
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        if (gRaceMultiConfig->mBattleKind == BATTLE_KIND_SHINE) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4a);
        }
        mgcnt_sMinigameController->mEndTimer = 0x5a;
    } else if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        entryIndex = gRaceMultiConfig->mEntryIndex;
        if (mgcnt_sMinigameController->mWinnerTeamId == entryIndex) {
            rstat_winMission(entryIndex);
        } else {
            rstat_loseMission(entryIndex);
        }
        mgcnt_sMinigameController->mEndTimer = 0;
    }
}

void mgcnt_20A1748(u16 kartIndex) {
    KartStanding *kartStanding;

    kartStanding = &mgcnt_sMinigameController->mKarts[kartIndex];
    kartStanding->field1C = -2;
    kartStanding->field18 = -2;
    kartStanding->mHitByKartIndex = kartIndex;
    mgcnt_sMinigameController->mKartHitCallback(kartIndex, kartIndex);
}

void mgcnt_resetDriverState(int kartIndex) {
    mgcnt_sMinigameController->mKarts[kartIndex].mEliminationStatus = 0;
}

static inline u16 func_020a12b8_inline(s32 rankIndex) {
    s32 j;

    for (j = 0; j < 8; j++) {
        if ((u16) rankIndex == mgcnt_sMinigameController->mKarts[j].mRankIndex) {
            return j;
        }
    }
    return 0;
}

void mgcnt_killDriver(u16 kartIndex) {
    if (mgcnt_sMinigameController->mWinnerTeamId >= 0) {
        return;
    }
    if (mgcnt_sMinigameController->mKarts[kartIndex].mEliminationStatus != 0) {
        return;
    }
    mgcnt_killDriverDirect(kartIndex);
    mgcnt_checkMgEnd();
}

u16 mgcnt_handleShineRunnersTimeUp(void) {
    NNSSndSeqPlayer **seqPlayerHandle;
    s32 v;
    u16 kartIndex;
    s32 i;
    s32 m;
    s32 kartCount;
    s32 lowestCount;

    if (mgcnt_sMinigameController->mWinnerTeamId >= 0) {
        return 0;
    }
    v = mgcnt_sMinigameController->field3A4 + 1;
    if (v >= 3) {
        v = 3;
    }
    mgcnt_sMinigameController->field3A4 = v;
    mgcnt_sMinigameController->field3A2 = mgcnt_sShineRunnersRoundDuration[mgcnt_sMinigameController->field3A4];
    lowestCount = mgcnt_sMinigameController->mLowestBalloonOrShineCount;
    if (lowestCount != mgcnt_sMinigameController->mHighestBalloonOrShineCount) {
        kartCount = gRaceMultiConfig->mKartCount;
        for (m = 0; m <= lowestCount; m++) {
            for (i = kartCount - 1; i >= 0; i--) {
                kartIndex = func_020a12b8_inline(i);
                if (m == mgcnt_sMinigameController->mKarts[kartIndex].mBalloonOrShineCount) {
                    mgcnt_killDriverDirect(kartIndex);
                }
            }
            mgcnt_checkMgEnd();
            if (mgcnt_sMinigameController->mWinnerTeamId >= 0) {
                return 0;
            }
        }
    }
    if (data_0217c780 & 1) {
        seqPlayerHandle = sp_acquireElement(sound_getPoolById(0));
        if (SoundHandle_217D084.fieldC != 0) {
            if (seqPlayerHandle[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
            }
            if (seqPlayerHandle[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(seqPlayerHandle, 0, 0x4b);
        }
    }
    return mgcnt_sMinigameController->field3A2;
}

void mgcnt_tryFinish(void) {
    s32 kartCount;
    s32 i;
    u16 kartIndex;
    s32 randomKartIndex;
    u16 randomLimit;
    RandomState64 *randomState;

    if (mgcnt_sMinigameController->mWinnerTeamId >= 0) {
        return;
    }
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        kartCount = gRaceMultiConfig->mKartCount;
        if (gRaceMultiConfig->mBattleKind == BATTLE_KIND_BALLOON) {
            if (mgcnt_sMinigameController->mWinnerTeamId >= 0) {
                return;
            }
            randomLimit = kartCount;
            do {
                randomState = &gRaceStatus->mRandom;
                if ((u16) kartCount == 0) {
                    randomKartIndex = 0;
                } else {
                    randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
                    if (randomLimit == 0) {
                        randomKartIndex = (u32) (randomState->mValue >> 32);
                    } else {
                        randomKartIndex = (u32) (((u64) (u32) (randomState->mValue >> 32) * (u64) randomLimit) >> 32);
                    }
                }
                kartIndex = randomKartIndex;
                if (mgcnt_sMinigameController->mKarts[kartIndex].mEliminationStatus == 0) {
                    mgcnt_killDriver(kartIndex);
                    mgcnt_sMinigameController->mKarts[kartIndex].mEliminationStatus = 2;
                }
            } while (mgcnt_sMinigameController->mWinnerTeamId < 0);
        } else if (gRaceMultiConfig->mBattleKind == BATTLE_KIND_SHINE) {
            for (i = kartCount - 1; i >= 0; i--) {
                if (mgcnt_sMinigameController->mWinnerTeamId < 0) {
                    kartIndex = func_020a12b8_inline(i);
                    if (mgcnt_sMinigameController->mKarts[kartIndex].mEliminationStatus == 0) {
                        mgcnt_killDriver(kartIndex);
                        mgcnt_sMinigameController->mKarts[kartIndex].mEliminationStatus = 2;
                    }
                }
            }
        }
    } else if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        for (i = 7; i >= 0; i--) {
            kartIndex = func_020a12b8_inline(i);
            if (kartIndex != gRaceMultiConfig->mEntryIndex && mgcnt_sMinigameController->mWinnerTeamId < 0) {
                mgcnt_killDriver(kartIndex);
            }
        }
    }
}

u32 mgcnt_hasMgEnded(void) {
    u32 result = 0u;
    if (mgcnt_sMinigameController->mWinnerTeamId < 0) {
        return result;
    }
    if (mgcnt_sMinigameController->mEndTimer < 0) {
        result = 1u;
    }
    return result;
}

// TRUE when mWinnerTeamId is not negative.
BOOL mgcnt_hasWinnerBeenDecided(void) {
    if (mgcnt_sMinigameController->mWinnerTeamId >= 0) {
        return TRUE;
    }
    return FALSE;
}

// Returns the kart's mRankIndex.
u16 mgcnt_getDriverPlace(int kartIndex) {
    return mgcnt_sMinigameController->mKarts[kartIndex].mRankIndex;
}

// Returns mShineCount.
u32 mgcnt_getCollectableShineCount(void) {
    return (mgcnt_sMinigameController->mShineCount);
}

// Adds its argument to mShineCount (+1 when a shine is placed, -1 when one is finished).
void mgcnt_updateCollectableShineCount(short amount) {
    Standings *standings;
    standings = mgcnt_sMinigameController;
    standings->mShineCount = standings->mShineCount + amount;
}

u16 mgcnt_getTotalOwnedShineCount(void) {
    s32 i;
    s32 total;
    s32 kartCount;
    s32 count;

    total = 0;
    kartCount = gRaceMultiConfig->mKartCount;
    for (i = 0; i < kartCount; i++) {
        count = mgcnt_sMinigameController->mKarts[(u16) i].mBalloonOrShineCount;
        if (count <= 0) {
            count = 0;
        }
        total += (u16) count;
    }
    return total;
}

u16 mgcnt_getMaxOwnedShineCount(void) {
    return mgcnt_sMinigameController->mHighestBalloonOrShineCount;
}

// Returns the kart's count, 0 when it is negative.
u16 mgcnt_getDriverBalloonShineCount(u16 kartIndex) {
    s32 count;

    count = mgcnt_sMinigameController->mKarts[kartIndex].mBalloonOrShineCount;
    if (count <= 0) {
        count = 0;
    }
    return count;
}

void mgcnt_updateDriverBalloonShineCount(u16 kartIndex, s32 amount) {
    mgcnt_sMinigameController->mKarts[kartIndex].mBalloonOrShineCount += amount;
    if (amount > 0) {
        mgcnt_handleDriverBalloonShineCountIncrease(kartIndex);
    } else if (amount < 0) {
        mgcnt_handleDriverBalloonShineCountDecrease(kartIndex);
    }
}

u16 mgcnt_getDriverBalloonShineInventoryCount(u16 kartIndex) {
    return mgcnt_sMinigameController->mKarts[kartIndex].mBalloonsLeftToMake;
}

void mgcnt_updateDriverBalloonShineInventoryCount(u16 kartIndex, s32 amount) {
    mgcnt_sMinigameController->mKarts[kartIndex].mBalloonsLeftToMake += amount;
}

// TRUE when the kart's elimination status is not 0.
BOOL mgcnt_isDriverDead(int kartIndex) {
    if (mgcnt_sMinigameController->mKarts[kartIndex].mEliminationStatus != 0) {
        return TRUE;
    }
    return FALSE;
}

// TRUE when the kart has the lowest balloon or shine count (ties count) and not every kart has it.
BOOL mgcnt_isDriverShineCountLow(u16 kartIndex) {
    Standings *standings;
    BOOL result;
    s32 count;

    standings = mgcnt_sMinigameController;
    result = FALSE;
    count = standings->mKarts[kartIndex].mBalloonOrShineCount;
    if (standings->mLowestBalloonOrShineCount == count) {
        if (standings->mHighestBalloonOrShineCount != count) {
            result = TRUE;
        }
    }
    return result;
}

BOOL mgcnt_hasDriverWon(s32 kartIndex) {
    KartStanding *kartStanding;
    BOOL result;

    kartStanding = &mgcnt_sMinigameController->mKarts[kartIndex];
    result = FALSE;
    if (mgcnt_sMinigameController->mWinnerTeamId == kartStanding->mTeamId) {
        if (mgcnt_sMinigameController->mEndTimer < 0) {
            result = TRUE;
        }
    }
    return result;
}

// Returns the address of the kart's saved position (mKarts[i].mPos), not its rank.
Vec3 *mgcnt_getDriverPosition(int kartIndex) {
    return &mgcnt_sMinigameController->mKarts[kartIndex].mPos;
}

CourseMapPoint *mgcnt_getRandomShineMepo(void) {
    RandomState64 *randomState;
    u16 pointStep;
    s32 pointIndex;

    randomState = &gRaceStatus->mRandom;
    randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
    pointStep = (u16) (((u64) (u32) (randomState->mValue >> 32) * 5) >> 32) + 1;
    pointIndex = mgcnt_sMinigameController->field3B8 + pointStep;
    if (pointIndex >= gMapData->mBattlePointCount) {
        pointIndex = 0;
    }
    mgcnt_sMinigameController->field3B8 = pointIndex;
    return &gMapData->mBattlePoints[mgcnt_sMinigameController->field3B8];
}

// Allocates the Standings object and fills every entry (rank = own index, side id, status, count; the real karts first,
// then the unused slots) and sets the winner to -1. Called from race_init in modes 2 and 4.
void mgcnt_init(void) {
    s32 i;
    KartStanding *kartStanding;

    mgcnt_sMinigameController = heap_alloc(proc_getHeap(proc_getCurrent()), 0x3c0);
    for (i = 0; i < 8; i++) {
        kartStanding = &mgcnt_sMinigameController->mKarts[i];
        kartStanding->field1C = -2;
        kartStanding->field18 = -2;
        kartStanding->mHitByKartIndex = i;
        kartStanding->mRankIndex = i;
        if (i < gRaceMultiConfig->mKartCount) {
            switch (gRaceMultiConfig->mCurrentEntries[(u16) i].mPlayer.mTeamIndex) {
                case 0:
                    kartStanding->mTeamId = 1;
                    break;
                case 1:
                    kartStanding->mTeamId = 3;
                    break;
                default:
                    kartStanding->mTeamId = i;
                    break;
            }
            kartStanding->mEliminationStatus = 0;
            kartStanding->mBalloonOrShineCount = 0;
            kartStanding->mBalloonsLeftToMake = 0;
        } else {
            kartStanding->mEliminationStatus = 2;
            kartStanding->mBalloonOrShineCount = -1;
            kartStanding->mBalloonsLeftToMake = 0;
            kartStanding->mTeamId = gRaceMultiConfig->mKartCount;
        }
    }
    mgcnt_sMinigameController->mWinnerTeamId = -1;
}

void mgcnt_forceEnd(void) {
    mgcnt_sMinigameController->mEndTimer = -1;
    if (mgcnt_sMinigameController->mEndCallback != NULL) {
        mgcnt_sMinigameController->mEndCallback();
    }
}

void mgcnt_update(void) {
    Kart *kart;
    BOOL a;
    BOOL b;
    s32 v;
    u32 f;
    s32 i;
    s32 kartCount;
    KartStanding *kartStanding = mgcnt_sMinigameController->mKarts;

    kartCount = gRaceMultiConfig->mKartCount;
    if (mgcnt_sMinigameController->mWinnerTeamId >= 0) {
        if (mgcnt_sMinigameController->mEndTimer > 0) {
            mgcnt_sMinigameController->mEndTimer = mgcnt_sMinigameController->mEndTimer - 1;
            if (mgcnt_sMinigameController->mEndTimer <= 0) {
                mgcnt_sMinigameController->mEndTimer = -1;
                if (mgcnt_sMinigameController->mEndCallback != NULL) {
                    mgcnt_sMinigameController->mEndCallback();
                }
            }
        }
        for (i = 0; i < kartCount; i++) {
            if (mgcnt_sMinigameController->mKarts[i].mEliminationStatus == 1) {
                if (i != gRaceMultiConfig->mEntryIndex) {
                    driver_emitKillVoice(driver_getById((u16) i));
                }
                mgcnt_sMinigameController->mKarts[i].mEliminationStatus = 2;
            }
        }
        return;
    }
    for (i = kartCount - 1; i >= 0; i--) {
        kartStanding = &mgcnt_sMinigameController->mKarts[i];
        if (kartStanding->mEliminationStatus == 1) {
            driver_emitKillVoice(driver_getById((u16) i));
            mgcnt_sMinigameController->mKarts[i].mEliminationStatus = 2;
        } else if (mgcnt_sMinigameController->mWinnerTeamId < 0 && kartStanding->mBalloonOrShineCount > 0) {
            kart = driver_getById((u16) i);
            kartStanding = &mgcnt_sMinigameController->mKarts[i];
            v = kartStanding->field64 - 1;
            if (v <= 0) {
                v = 0;
            }
            kartStanding->field64 = v;
            mgcnt_sMinigameController->mKarts[i].field68 = -(mgcnt_sMinigameController->mKarts[i].field68 <= 0);
            if (func_01ffc67c(kart) != FALSE ||
                (u16) (gInputUnits[kart->mEntryIndex].mBits & (PAD_KEY_A | PAD_KEY_B)) != 0) {
                mgcnt_sMinigameController->mKarts[i].field68 = -1;
                mgcnt_sMinigameController->mKarts[i].field64 = -1;
            } else if (race_getState() == 1) {
                if ((u16) (gInputUnits[(u32) kart->mEntryIndex].mBits & 4) != 0) {
                    mgcnt_sMinigameController->mKarts[i].field68 = 1;
                } else if (gInputUnits[kart->mEntryIndex].field5A != 0) {
                    mgcnt_sMinigameController->mKarts[i].field64 = 10;
                }
            }
            if (mgcnt_sMinigameController->mKartHitCallback != NULL) {
                b = TRUE;
                f = kart->field48;
                a = (f & 0x200) != 0;
                if (kart->mState == KART_STATE_NORMAL && (f & 0x4000000) == 0) {
                    b = FALSE;
                }
                if (kartStanding->field4 == FALSE && a != FALSE && (kart->field4C & 0x400000) == 0) {
                    kartStanding->field4 = TRUE;
                    kartStanding->field0 = FALSE;
                    kartStanding->field18 = -2;
                    kartStanding->mHitByKartIndex = i;
                    kartStanding->field20 = FALSE;
                    if (kartStanding->mBalloonOrShineCount <= 1) {
                        if ((gRaceMultiConfig->mMode == MODE_BATTLE && gRaceMultiConfig->mBattleKind == BATTLE_KIND_BALLOON) ||
                            gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                            kart->field7C |= 0x20000000;
                            kart->field48 &= ~0x2000000;
                        }
                    }
                } else if (kartStanding->field4 == TRUE && (kart->field44 & 0x10000) != 0) {
                    kartStanding->field4 = FALSE;
                    kartStanding->field1C = 0;
                    if ((kart->field4C & 0x400000) == 0) {
                        StructMQRacerEntry_SomeFn_30(kart);
                    }
                }
                if (kartStanding->field1C == 0) {
                    kartStanding->field1C = -2;
                    mgcnt_sMinigameController->mKartHitCallback(i, 8);
                    kartStanding->mHitByKartIndex = i;
                } else if (kartStanding->field1C >= 0) {
                    kartStanding->field1C = kartStanding->field1C + 1;
                }
                if (kartStanding->field0 == FALSE && b != FALSE && (kart->field4C & 0x400000) == 0) {
                    kartStanding->field0 = TRUE;
                    if (kartStanding->mBalloonOrShineCount <= 1) {
                        if ((gRaceMultiConfig->mMode == MODE_BATTLE && gRaceMultiConfig->mBattleKind == BATTLE_KIND_BALLOON) ||
                            gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                            kart->field7C |= 0x20000000;
                        }
                    }
                } else if (kartStanding->field0 == TRUE && b == FALSE && (kart->field48 & 0x6052840) == 0) {
                    kartStanding->field0 = FALSE;
                    if (kartStanding->field20 == FALSE) {
                        kartStanding->field18 = 0;
                        if ((kart->field4C & 0x400000) == 0) {
                            StructMQRacerEntry_SomeFn_30(kart);
                        }
                    } else {
                        kartStanding->field20 = FALSE;
                    }
                }
                if (kartStanding->field18 == 0) {
                    kartStanding->field18 = -2;
                    mgcnt_sMinigameController->mKartHitCallback(i, kartStanding->mHitByKartIndex);
                    kartStanding->mHitByKartIndex = i;
                } else if (kartStanding->field18 >= 0) {
                    kartStanding->field18 = kartStanding->field18 + 1;
                }
            }
            kartStanding->mPos = kart->mPos;
        }
    }
}

void bsfx_init(Unk020a0318 *mapObject) {
    s32 courseId;

    courseId = gRaceMultiConfig->mCourseId;
    if (courseId == COURSE_ID_MANSION) {
        mapObject->mSoundId = 0x121;
    } else if (courseId == COURSE_ID_BEACH) {
        mapObject->mSoundId = 0x111;
        mapObject->mSecondSoundId = 0x10a;
    } else {
        mapObject->mSoundId = 0x20d;
    }
}

void bsfx_globalLogicInit(MapObjectList *mapObjectList) {
    s32 i;
    Unk020a0318 *mapObject;
    RandomState64 *randomState;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (gRaceMultiConfig->mCourseId == COURSE_ID_MANSION) {
            mapObject->mRadius = 0xa28;
            mapObject->mCenterX = mapObject->field0.mPos.x + 0x73a000;
            mapObject->mCenterY = mapObject->field0.mPos.y;
            mapObject->mCenterZ = mapObject->field0.mPos.z - 0x1400000;
            mapObject->mDistanceLevelInverted = TRUE;
        } else if (gRaceMultiConfig->mCourseId == COURSE_ID_BEACH) {
            mapObject->mRadius = 0x546;
            mapObject->mCenterX = mapObject->field0.mPos.x + 0x28a000;
            mapObject->mCenterY = mapObject->field0.mPos.y;
            mapObject->mCenterZ = mapObject->field0.mPos.z - 0x32000;
            mapObject->mDistanceLevelInverted = FALSE;
        } else {
            mapObject->mRadius = 0xa28;
            mapObject->mCenterX = mapObject->field0.mPos.x;
            mapObject->mCenterY = mapObject->field0.mPos.y;
            mapObject->mCenterZ = mapObject->field0.mPos.z;
            mapObject->mDistanceLevelInverted = FALSE;
        }
        randomState = &gRaceStatus->mLocalRandom;
        randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
        mapObject->mSoundTimer = (u16) (((u64) (u32) (randomState->mValue >> 32) * 0x3c) >> 32) + 0x258;
        mapObject->mDistanceVolumeFixed12 = 0x7f000;
        randomState = &gRaceStatus->mLocalRandom;
        randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
        mapObject->mDistanceLevelTimer = (u16) (((u64) (u32) (randomState->mValue >> 32) * 0xf) >> 32);
    }
}

void bsfx_update(void *mapObjectList, Unk020a0318 *mapObject) {
    Kart *kart;
    NNSSndSeqPlayer **sndHandleSlot;
    RandomState64 *randomState;
    Unk0210b7a8 slot8Request;
    Unk0210b7a8 slot9Request;
    s32 v;
    s32 halfRadius;
    s32 radius;
    s32 deltaZ;
    s32 deltaX;
    s64 distanceSquared;

    if (mapObject->mDistanceLevelTimer-- <= 0) {
        mapObject->mDistanceLevelTimer = 0xf;
        radius = mapObject->mRadius;
        halfRadius = radius / 2;
        kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
        deltaX = kart->mPos.x - mapObject->mCenterX;
        deltaZ = kart->mPos.z - mapObject->mCenterZ;
        distanceSquared = (s64) deltaX * deltaX + (s64) deltaZ * deltaZ;
        if (distanceSquared < (s64) halfRadius * halfRadius) {
            v = 2;
        } else if (distanceSquared < (s64) (radius << 12) * (radius << 12)) {
            v = 1;
        } else {
            v = 0;
        }
        mapObject->mDistanceLevel = v;
        if (mapObject->mDistanceLevelInverted != FALSE) {
            mapObject->mDistanceLevel = mapObject->mDistanceLevel == 0;
        }
    }
    if (mapObject->mDistanceLevel > 1) {
        mapObject->mDistanceVolumeFixed12 = 0x7f001;
    } else if (mapObject->mDistanceLevel > 0) {
        mapObject->mDistanceVolumeFixed12 = mapObject->mDistanceVolumeFixed12 + 0x4000;
        if (mapObject->mDistanceVolumeFixed12 > 0x7f000) {
            mapObject->mDistanceVolumeFixed12 = 0x7f000;
        }
    } else {
        mapObject->mDistanceVolumeFixed12 = mapObject->mDistanceVolumeFixed12 - 0x4000;
        if (mapObject->mDistanceVolumeFixed12 < 0) {
            mapObject->mDistanceVolumeFixed12 = 0;
        }
    }
    if (mapObject->mSoundId != 0) {
        if (mapObject->mDistanceLevel != 0) {
            if (*GetSndHandleSlot(8) != NULL) {
                kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
                mapObject->fieldA0 = mapObject->fieldA0 - (s32) (((s64) kart->mVelocityLengthRatio * 0x1000) >> 12);
                if (mapObject->fieldA0 < 0xc000) {
                    mapObject->fieldA0 = 0xc000;
                }
            } else if (mapObject->mSoundTimer-- <= 0) {
                sndHandleSlot = GetSndHandleSlot(8);
                slot8Request.mSoundId = mapObject->mSoundId;
                slot8Request.mPositionSource = NULL;
                slot8Request.field8 = 4;
                slot8Request.mDistanceSquared = mobj_calcXZCamDist(NULL);
                sub_210B760(&slot8Request, sndHandleSlot);
                randomState = &gRaceStatus->mLocalRandom;
                randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
                mapObject->mSoundTimer = (u16) (((u64) (u32) (randomState->mValue >> 32) * 0x3c) >> 32) + 0x78;
                mapObject->fieldA0 = 0x7f000;
            }
        } else if (mapObject->mSoundTimer > 0) {
            mapObject->mSoundTimer = mapObject->mSoundTimer - 1;
        }
        if (*GetSndHandleSlot(8) != NULL) {
            v = mapObject->mDistanceVolumeFixed12 < mapObject->fieldA0 ? mapObject->mDistanceVolumeFixed12
                                                                       : mapObject->fieldA0;
            SetSndHandleTrackVolume(GetSndHandleSlot(8), v >> 12);
        }
    }
    if (mapObject->mSecondSoundId == 0) {
        return;
    }
    if (mapObject->mDistanceLevel != 0) {
        if (*GetSndHandleSlot(9) == NULL) {
            sndHandleSlot = GetSndHandleSlot(9);
            slot9Request.mSoundId = mapObject->mSecondSoundId;
            slot9Request.mPositionSource = NULL;
            slot9Request.field8 = 4;
            slot9Request.mDistanceSquared = mobj_calcXZCamDist(NULL);
            sub_210B760(&slot9Request, sndHandleSlot);
        }
    }
    if (*GetSndHandleSlot(9) == NULL) {
        return;
    }
    SetSndHandleTrackVolume(GetSndHandleSlot(9), mapObject->mDistanceVolumeFixed12 >> 12);
}

void *bsfx_setupLogicPart(void) {
    return mobj_createLogicPart(bsfx_globalLogicInit, bsfx_update, NULL);
}
