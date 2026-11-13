#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/bound.h"

#include "Main/System/heap.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Sound/sound_seq.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "Main/System/heap_call.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/data_0217d000.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "code_0212df7c.h"
#include "Main/Race/race_end_condition.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/kart_standing_rank.h"
#include "Main/Kart/karts.h"
#include "Main/Sound/sound_system.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/System/init_after_startup.h"

const u32 gShineBattleTimeLimits[4] = {0xffff, 0x1e, 0x1e, 0x1e};
const s32 gCharacterBalloonOrShineHeights[16] = {0x11000, 0x16000, 0x11000, 0x17000, 0x11800, 0x12000, 0x11000, 0x11000,
                                                 0x10800, 0x11000, 0x13000, 0x15000, 0x10800, 0,       0,       0};
Standings *gStandings;

MapObjectKindDescriptor gDistanceSoundKindDescriptor = {
    0, {0, 0}, 0xcc, InitDistanceSound, CreateEmptyMapObjectKindData, 0, 0, 0, CreateDistanceSoundUpdateList};

void SetStandingsKartBalloons(KartBalloons *kartBalloons) {
    gStandings->mKartBalloons = kartBalloons;
}

KartBalloons *GetStandingsKartBalloons(void) {
    return gStandings->mKartBalloons;
}

void SetStandingsKartHitByKartCallback(s32 (*callback)(s32, s32)) {
    gStandings->mKartHitByKartCallback = callback;
}

void SetStandingsKartsHitEachOtherCallback(void (*callback)(s32, s32)) {
    gStandings->mKartsHitEachOtherCallback = callback;
}

void SetStandingsKartHitCallback(s32 (*callback)(u16 kartIndex, u16 hitByKartIndex)) {
    gStandings->mKartHitCallback = callback;
}

// Stores the kart-eliminated callback.
void SetStandingsKartEliminatedCallback(void (*callback)(u16 kartIndex)) {
    gStandings->mKartEliminatedCallback = callback;
}

// Stores the end callback.
void SetStandingsEndCallback(void (*callback)(void)) {
    gStandings->mEndCallback = callback;
}

void SetStandingsKartOffsetCallback(void (*callback)(u16, Vec3 *)) {
    gStandings->mKartOffsetCallback = callback;
}

void StartKartMicInflate(u16 kartIndex) {
    if (IsRaceStarted() != 1) {
        return;
    }
    if (IsKartNotNormalOrFlagged(GetKart(kartIndex)) != FALSE) {
        return;
    }
    gStandings->mKarts[kartIndex].mMicInflateTimer = 10;
}

void StopKartMicInflate(int kartIndex) {
    gStandings->mKarts[kartIndex].mMicInflateTimer = 0xffffffff;
}

s32 GetKartMicInflateTimer(u16 kartIndex) {
    if (gStandings->mWinnerTeamId >= 0) {
        return -1;
    }
    return gStandings->mKarts[kartIndex].mMicInflateTimer;
}

s32 GetKartSelectKeyInflate(u16 kartIndex) {
    if (gStandings->mWinnerTeamId >= 0) {
        return -1;
    }
    return gStandings->mKarts[kartIndex].mSelectKeyInflate;
}

void SetKartInflatingBalloon(u16 kartIndex, u32 inflating) {
    gStandings->mKarts[kartIndex].mInflatingBalloon = inflating;
}

u32 IsKartInflatingBalloon(u16 kartIndex) {
    return gStandings->mKarts[kartIndex].mInflatingBalloon;
}

void CallStandingsKartOffsetCallback(u16 kartIndex, Vec3 *offset) {
    if (offset == 0) {
        return;
    }
    if (gStandings->mKartOffsetCallback != NULL) {
        gStandings->mKartOffsetCallback(kartIndex, offset);
    }
}

s32 CallKartCollisionCallbacks(s32 firstKartIndex, s32 secondKartIndex) {
    Kart *firstKart;
    Kart *secondKart;
    KartStanding *firstStanding;
    KartStanding *secondStanding;
    BOOL firstHitsSecond;
    s32 result;
    BOOL firstGuarded;
    BOOL secondGuarded;

    if (gStandings->mWinnerTeamId >= 0) {
        return 0;
    }
    firstKart = GetKart(firstKartIndex);
    secondKart = GetKart(secondKartIndex);
    secondStanding = &gStandings->mKarts[secondKartIndex];
    firstStanding = &gStandings->mKarts[firstKartIndex];
    firstHitsSecond = FALSE;
    if (secondStanding->mHitSeenFromKart[firstKartIndex] == 0) {
        if ((firstKart->mDriveFlags & KART_DRIVE_KINOKO_BOOST) != 0) {
            firstHitsSecond = TRUE;
        }
    }
    result = 0;
    if (firstStanding->mHitSeenFromKart[secondKartIndex] == 0) {
        if ((secondKart->mDriveFlags & KART_DRIVE_KINOKO_BOOST) != 0) {
            result = 1;
        }
    }
    firstGuarded = TRUE;
    if ((firstKart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
        if (GetKartItemEffect(firstKartIndex) != 1) {
            firstGuarded = FALSE;
        }
    }
    secondGuarded = TRUE;
    if ((secondKart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
        if (GetKartItemEffect(secondKartIndex) != 1) {
            secondGuarded = FALSE;
        }
    }
    if (result != 0) {
        firstStanding->mHitSeenFromKart[secondKartIndex] = 1;
    }
    if (firstHitsSecond != FALSE) {
        secondStanding->mHitSeenFromKart[firstKartIndex] = 1;
    }
    if (firstGuarded == FALSE && secondGuarded == FALSE && firstHitsSecond != FALSE && result != 0) {
        if (gStandings->mKartsHitEachOtherCallback != NULL) {
            gStandings->mKartsHitEachOtherCallback(firstKartIndex, secondKartIndex);
            return 1;
        }
    } else if (firstGuarded == FALSE && result != 0) {
        result = 0;
        if (GetKartItemEffect(secondKartIndex) == 1) {
            firstStanding->mSkipNotNormalEnd = TRUE;
            if (gStandings->mKartHitByKartCallback != NULL) {
                result = gStandings->mKartHitByKartCallback(firstKartIndex, secondKartIndex);
                if ((firstKart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                    StartKartBlink(firstKart);
                }
            }
        } else if (gStandings->mKartHitByKartCallback != NULL) {
            result = gStandings->mKartHitByKartCallback(firstKartIndex, secondKartIndex);
            if ((firstKart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                StartKartBlink(firstKart);
            }
        }
        return result;
    } else if (secondGuarded == FALSE && firstHitsSecond != FALSE) {
        result = 0;
        if (GetKartItemEffect(firstKartIndex) == 1) {
            secondStanding->mSkipNotNormalEnd = TRUE;
            if (gStandings->mKartHitByKartCallback != NULL) {
                result = gStandings->mKartHitByKartCallback(secondKartIndex, firstKartIndex);
                if ((secondKart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                    StartKartBlink(secondKart);
                }
            }
        } else if (gStandings->mKartHitByKartCallback != NULL) {
            result = gStandings->mKartHitByKartCallback(secondKartIndex, firstKartIndex);
            if ((secondKart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                StartKartBlink(secondKart);
            }
        }
        return result;
    }
    return 0;
}

void SetKartHitByKartIndexFromItem(s32 kartIndex, ItemObject *itemObject) {
    u16 ownerKartIndexAndFlags;

    if (gStandings->mWinnerTeamId >= 0) {
        return;
    }
    if (GetKart(kartIndex)->mState == KART_STATE_NORMAL) {
        return;
    }
    if (itemObject->mKind != ITEM_OBJECT_KIND_KOURA_G && itemObject->mKind != ITEM_OBJECT_KIND_KOURA_R &&
        itemObject->mKind != ITEM_OBJECT_KIND_BOMB) {
        return;
    }
    ownerKartIndexAndFlags = itemObject->mOwnerKartIndexAndFlags;
    if ((ownerKartIndexAndFlags & 0x8000) != 0) {
        return;
    }
    gStandings->mKarts[kartIndex].mHitByKartIndex = ownerKartIndexAndFlags & ~0xff00;
}

u32 StandingsReturnArgument(u32 value) {
    return value;
}

void ClearStandingsHitSeenFromKart(s32 kartIndex) {
    s32 otherKartIndex;
    s32 kartCount;

    kartCount = gRaceSetup->mKartCount;
    for (otherKartIndex = 0; otherKartIndex < kartCount; otherKartIndex++) {
        gStandings->mKarts[otherKartIndex].mHitSeenFromKart[kartIndex] = 0;
    }
}

static inline u16 FindStandingsKartIndexByRankIndex(Standings *standings, s32 rankIndex) {
    s32 kartIndex;

    for (kartIndex = 0; kartIndex < 8; kartIndex++) {
        if ((u16) rankIndex == standings->mKarts[kartIndex].mRankIndex) {
            return kartIndex;
        }
    }
    return 0;
}

u16 GetBattleItemRank(s32 kartIndex) {
    s32 rank;
    s32 otherKartIndex;
    s32 highestCount;

    if (gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            rank = 3 - gStandings->mKarts[kartIndex].mBalloonOrShineCount;
            rank += 1;
        } else if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            highestCount = 1;
            for (otherKartIndex = 0; otherKartIndex < gRaceSetup->mKartCount; otherKartIndex++) {
                if (gStandings->mKarts[otherKartIndex].mBalloonOrShineCount > highestCount) {
                    highestCount = gStandings->mKarts[otherKartIndex].mBalloonOrShineCount;
                }
            }
            rank = (highestCount + 1 - gStandings->mKarts[kartIndex].mBalloonOrShineCount) / 2 + 1;
        } else {
            rank = kartIndex;
        }
    } else {
        rank = 3 - gStandings->mKarts[kartIndex].mBalloonOrShineCount;
        rank += 1;
    }
    if (rank < 1) {
        rank = 1;
    } else if (rank > 3) {
        rank = 3;
    }
    return rank;
}

void MoveKartTowardFirstRank(u16 kartIndex) {
    s32 rankIndex;
    s32 otherKartIndex;
    s32 kartCount;
    s32 count;
    KartStanding *ownStanding;
    u16 otherRankIndex;
    u16 ownRankIndex;
    KartStanding *otherStanding;

    for (rankIndex = gStandings->mKarts[kartIndex].mRankIndex - 1; rankIndex >= 0; rankIndex--) {
        otherStanding = &gStandings->mKarts[FindStandingsKartIndexByRankIndex(gStandings, rankIndex)];
        otherRankIndex = otherStanding->mRankIndex;
        ownRankIndex = gStandings->mKarts[kartIndex].mRankIndex;
        ownStanding = &gStandings->mKarts[kartIndex];
        if (ownRankIndex > otherRankIndex) {
            if (ownStanding->mBalloonOrShineCount > otherStanding->mBalloonOrShineCount ||
                (ownStanding->mEliminationStatus == 0 && otherStanding->mEliminationStatus != 0)) {
                otherStanding->mRankIndex = ownRankIndex;
                gStandings->mKarts[kartIndex].mRankIndex = otherRankIndex;
            }
        }
    }
    kartCount = gRaceSetup->mKartCount;
    gStandings->mLowestBalloonOrShineCount = 0xffff;
    gStandings->mHighestBalloonOrShineCount = 0;
    for (otherKartIndex = 0; otherKartIndex < kartCount; otherKartIndex++) {
        count = gStandings->mKarts[otherKartIndex].mBalloonOrShineCount;
        gStandings->mLowestBalloonOrShineCount = (count < gStandings->mLowestBalloonOrShineCount && count >= 0)
                                                     ? count
                                                     : gStandings->mLowestBalloonOrShineCount;
        count = gStandings->mKarts[otherKartIndex].mBalloonOrShineCount;
        gStandings->mHighestBalloonOrShineCount =
            (count > gStandings->mHighestBalloonOrShineCount) ? count : gStandings->mHighestBalloonOrShineCount;
    }
}

void MoveKartTowardLastRank(u16 kartIndex) {
    s32 rankIndex;
    s32 otherKartIndex;
    s32 kartCount;
    s32 count;
    KartStanding *ownStanding;
    u16 otherRankIndex;
    u16 ownRankIndex;
    KartStanding *otherStanding;

    for (rankIndex = gStandings->mKarts[kartIndex].mRankIndex + 1; rankIndex < 8; rankIndex++) {
        otherStanding = &gStandings->mKarts[FindStandingsKartIndexByRankIndex(gStandings, rankIndex)];
        otherRankIndex = otherStanding->mRankIndex;
        ownRankIndex = gStandings->mKarts[kartIndex].mRankIndex;
        ownStanding = &gStandings->mKarts[kartIndex];
        if (ownRankIndex < otherRankIndex) {
            if (ownStanding->mBalloonOrShineCount < otherStanding->mBalloonOrShineCount ||
                (ownStanding->mEliminationStatus != 0 && otherStanding->mEliminationStatus == 0)) {
                otherStanding->mRankIndex = ownRankIndex;
                gStandings->mKarts[kartIndex].mRankIndex = otherRankIndex;
            }
        }
    }
    kartCount = gRaceSetup->mKartCount;
    gStandings->mLowestBalloonOrShineCount = 0xffff;
    gStandings->mHighestBalloonOrShineCount = 0;
    for (otherKartIndex = 0; otherKartIndex < kartCount; otherKartIndex++) {
        count = gStandings->mKarts[otherKartIndex].mBalloonOrShineCount;
        gStandings->mLowestBalloonOrShineCount = (count < gStandings->mLowestBalloonOrShineCount && count >= 0)
                                                     ? count
                                                     : gStandings->mLowestBalloonOrShineCount;
        count = gStandings->mKarts[otherKartIndex].mBalloonOrShineCount;
        gStandings->mHighestBalloonOrShineCount =
            (count > gStandings->mHighestBalloonOrShineCount) ? count : gStandings->mHighestBalloonOrShineCount;
    }
}

// Takes one kart out of play: runs the kart-eliminated callback, sets its status to 1, in mode 2 sets its count to -1,
// re-sorts the ranks and starts the mode's out handling of the kart (mode 2: a kart handler call; mode 4: two bits in
// the kart's words).
void EliminateKart(u16 kartIndex) {
    Kart *kart;

    if (gStandings->mKartEliminatedCallback != NULL) {
        gStandings->mKartEliminatedCallback(kartIndex);
    }
    gStandings->mKarts[kartIndex].mEliminationStatus = 1;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        gStandings->mKarts[kartIndex].mBalloonOrShineCount = -1;
        gStandings->mKarts[kartIndex].mBalloonsLeftToMake = 0;
    }
    if ((u32) kartIndex >= gRaceSetup->mKartCount) {
        return;
    }
    MoveKartTowardLastRank(kartIndex);
    if (gRaceSetup->mMode == MODE_BATTLE) {
        StartBattleKartRemoval(GetKart(kartIndex));
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        kart = GetKart(kartIndex);
        kart->mDriveFlags |= KART_DRIVE_SLOWING_STOP;
        kart->mEntryFlags |= KART_ENTRY_ENDED;
    }
}

void SetWinnerIfOneTeamLeft(void) {
    s32 kartCount;
    s32 teamId;
    s32 kartIndex;
    s32 standingIndex;
    s32 entryIndex;
    s32 scanIndex;
    u16 firstRankKartIndex;
    Standings *standings;
    KartStanding *kartStanding;
    Kart *kart;

    kartCount = gRaceSetup->mKartCount;
    standings = gStandings;
    for (scanIndex = 0; scanIndex < 8; scanIndex++) {
        if (standings->mKarts[scanIndex].mRankIndex == 0) {
            firstRankKartIndex = scanIndex;
            goto found;
        }
    }
    firstRankKartIndex = 0;
found:
    teamId = standings->mKarts[firstRankKartIndex].mTeamId;
    kartStanding = standings->mKarts;
    for (standingIndex = 0; standingIndex < 8; standingIndex++, kartStanding++) {
        if (kartStanding->mEliminationStatus == 0) {
            if (teamId != kartStanding->mTeamId) {
                return;
            }
        }
    }
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        kart = GetKart((u16) kartIndex);
        kart->mDriveFlags |= KART_DRIVE_SLOWING_STOP;
        kart->mEntryFlags |= KART_ENTRY_ENDED;
    }
    gStandings->mWinnerTeamId = teamId;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x4a);
        }
        gStandings->mEndTimer = 0x5a;
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        entryIndex = gRaceSetup->mEntryIndex;
        if (gStandings->mWinnerTeamId == entryIndex) {
            FinishMissionRunKartWithEndKind0(entryIndex);
        } else {
            FinishRaceProgressKartWithEndKind4(entryIndex);
        }
        gStandings->mEndTimer = 0;
    }
}

void CallKartHitCallbackForSelf(u16 kartIndex) {
    KartStanding *kartStanding;

    kartStanding = &gStandings->mKarts[kartIndex];
    kartStanding->mObjectsSkipEndPending = KART_STANDING_HIT_END_NONE;
    kartStanding->mNotNormalEndPending = KART_STANDING_HIT_END_NONE;
    kartStanding->mHitByKartIndex = kartIndex;
    gStandings->mKartHitCallback(kartIndex, kartIndex);
}

void ClearStandingEliminationStatus(int kartIndex) {
    gStandings->mKarts[kartIndex].mEliminationStatus = 0;
}

static inline u16 FindKartIndexByRankIndex(s32 rankIndex) {
    s32 kartIndex;

    for (kartIndex = 0; kartIndex < 8; kartIndex++) {
        if ((u16) rankIndex == gStandings->mKarts[kartIndex].mRankIndex) {
            return kartIndex;
        }
    }
    return 0;
}

void EliminateKartAndCheckWinner(u16 kartIndex) {
    if (gStandings->mWinnerTeamId >= 0) {
        return;
    }
    if (gStandings->mKarts[kartIndex].mEliminationStatus != 0) {
        return;
    }
    EliminateKart(kartIndex);
    SetWinnerIfOneTeamLeft();
}

// Steps to the next time limit, eliminates the karts with the lowest shine count (none when all counts are equal) and
// returns the new limit in seconds; 0 when a winner is decided.
u16 AdvanceShineBattleTimeLimit(void) {
    NNSSndSeqPlayer **seqPlayerHandle;
    s32 timeLimitIndex;
    u16 kartIndex;
    s32 rankIndex;
    s32 targetCount;
    s32 kartCount;
    s32 lowestCount;

    if (gStandings->mWinnerTeamId >= 0) {
        return 0;
    }
    timeLimitIndex = gStandings->mTimeLimitIndex + 1;
    if (timeLimitIndex >= 3) {
        timeLimitIndex = 3;
    }
    gStandings->mTimeLimitIndex = timeLimitIndex;
    gStandings->mTimeLimitSeconds = gShineBattleTimeLimits[gStandings->mTimeLimitIndex];
    lowestCount = gStandings->mLowestBalloonOrShineCount;
    if (lowestCount != gStandings->mHighestBalloonOrShineCount) {
        kartCount = gRaceSetup->mKartCount;
        for (targetCount = 0; targetCount <= lowestCount; targetCount++) {
            for (rankIndex = kartCount - 1; rankIndex >= 0; rankIndex--) {
                kartIndex = FindKartIndexByRankIndex(rankIndex);
                if (targetCount == gStandings->mKarts[kartIndex].mBalloonOrShineCount) {
                    EliminateKart(kartIndex);
                }
            }
            SetWinnerIfOneTeamLeft();
            if (gStandings->mWinnerTeamId >= 0) {
                return 0;
            }
        }
    }
    if (gRaceSoundKind & 1) {
        seqPlayerHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
        if (gSoundModeHolder.mSeqStartEnabled != 0) {
            if (seqPlayerHandle[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
            }
            if (seqPlayerHandle[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(seqPlayerHandle, 0, 0x4b);
        }
    }
    return gStandings->mTimeLimitSeconds;
}

void EliminateKartsUntilWinnerDecided(void) {
    s32 kartCount;
    s32 rankIndex;
    u16 kartIndex;
    s32 randomKartIndex;
    u16 randomLimit;
    RandomState64 *randomState;

    if (gStandings->mWinnerTeamId >= 0) {
        return;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        kartCount = gRaceSetup->mKartCount;
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            if (gStandings->mWinnerTeamId >= 0) {
                return;
            }
            randomLimit = kartCount;
            do {
                randomState = &gRaceProgress->mRandom;
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
                if (gStandings->mKarts[kartIndex].mEliminationStatus == 0) {
                    EliminateKartAndCheckWinner(kartIndex);
                    gStandings->mKarts[kartIndex].mEliminationStatus = 2;
                }
            } while (gStandings->mWinnerTeamId < 0);
        } else if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            for (rankIndex = kartCount - 1; rankIndex >= 0; rankIndex--) {
                if (gStandings->mWinnerTeamId < 0) {
                    kartIndex = FindKartIndexByRankIndex(rankIndex);
                    if (gStandings->mKarts[kartIndex].mEliminationStatus == 0) {
                        EliminateKartAndCheckWinner(kartIndex);
                        gStandings->mKarts[kartIndex].mEliminationStatus = 2;
                    }
                }
            }
        }
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        for (rankIndex = 7; rankIndex >= 0; rankIndex--) {
            kartIndex = FindKartIndexByRankIndex(rankIndex);
            if (kartIndex != gRaceSetup->mEntryIndex && gStandings->mWinnerTeamId < 0) {
                EliminateKartAndCheckWinner(kartIndex);
            }
        }
    }
}

u32 IsWinnerDecidedAndEndReached(void) {
    u32 result = 0u;
    if (gStandings->mWinnerTeamId < 0) {
        return result;
    }
    if (gStandings->mEndTimer < 0) {
        result = 1u;
    }
    return result;
}

// TRUE when mWinnerTeamId is not negative.
BOOL IsWinnerDecided(void) {
    if (gStandings->mWinnerTeamId >= 0) {
        return TRUE;
    }
    return FALSE;
}

// Returns the kart's mRankIndex.
u16 GetKartStandingRankIndex(int kartIndex) {
    return gStandings->mKarts[kartIndex].mRankIndex;
}

// Returns mShineCount.
u32 GetShineCount(void) {
    return (gStandings->mShineCount);
}

// Adds its argument to mShineCount (+1 when a shine is placed, -1 when one is finished).
void AddShineCount(short amount) {
    Standings *standings;
    standings = gStandings;
    standings->mShineCount = standings->mShineCount + amount;
}

u16 GetTotalBalloonOrShineCount(void) {
    s32 kartIndex;
    s32 total;
    s32 kartCount;
    s32 count;

    total = 0;
    kartCount = gRaceSetup->mKartCount;
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        count = GetStandingsKart(kartIndex)->mBalloonOrShineCount;
        if (count <= 0) {
            count = 0;
        }
        total += (u16) count;
    }
    return total;
}

u16 GetHighestBalloonOrShineCount(void) {
    return gStandings->mHighestBalloonOrShineCount;
}

// Returns the kart's count, 0 when it is negative.
u16 GetBalloonOrShineCount(u16 kartIndex) {
    s32 count;

    count = gStandings->mKarts[kartIndex].mBalloonOrShineCount;
    if (count <= 0) {
        count = 0;
    }
    return count;
}

void AddBalloonOrShineCountAndMoveRank(u16 kartIndex, s32 amount) {
    gStandings->mKarts[kartIndex].mBalloonOrShineCount += amount;
    if (amount > 0) {
        MoveKartTowardFirstRank(kartIndex);
    } else if (amount < 0) {
        MoveKartTowardLastRank(kartIndex);
    }
}

u16 GetBalloonsLeftToMake(u16 kartIndex) {
    return gStandings->mKarts[kartIndex].mBalloonsLeftToMake;
}

void AddBalloonsLeftToMake(u16 kartIndex, s32 amount) {
    gStandings->mKarts[kartIndex].mBalloonsLeftToMake += amount;
}

// TRUE when the kart's elimination status is not 0.
BOOL IsKartEliminated(int kartIndex) {
    if (gStandings->mKarts[kartIndex].mEliminationStatus != 0) {
        return TRUE;
    }
    return FALSE;
}

// TRUE when the kart has the lowest balloon or shine count (ties count) and not every kart has it.
BOOL IsKartLastByBalloonOrShineCount(u16 kartIndex) {
    Standings *standings;
    BOOL result;
    s32 count;

    standings = gStandings;
    result = FALSE;
    count = standings->mKarts[kartIndex].mBalloonOrShineCount;
    if (standings->mLowestBalloonOrShineCount == count) {
        if (standings->mHighestBalloonOrShineCount != count) {
            result = TRUE;
        }
    }
    return result;
}

BOOL IsKartOnWinningTeamAtEnd(s32 kartIndex) {
    KartStanding *kartStanding;
    BOOL result;

    kartStanding = &gStandings->mKarts[kartIndex];
    result = FALSE;
    if (gStandings->mWinnerTeamId == kartStanding->mTeamId) {
        if (gStandings->mEndTimer < 0) {
            result = TRUE;
        }
    }
    return result;
}

// Returns the address of the kart's saved position (mKarts[i].mPos), not its rank.
Vec3 *GetKartStandingPos(int kartIndex) {
    return &gStandings->mKarts[kartIndex].mPos;
}

CourseMapPoint *MoveToRandomForwardBattlePoint(void) {
    RandomState64 *randomState;
    u16 pointStep;
    s32 pointIndex;

    randomState = &gRaceProgress->mRandom;
    randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
    pointStep = (u16) (((u64) (u32) (randomState->mValue >> 32) * 5) >> 32) + 1;
    pointIndex = gStandings->mBattlePointIndex + pointStep;
    if (pointIndex >= gCourseMap->mBattlePointCount) {
        pointIndex = 0;
    }
    gStandings->mBattlePointIndex = pointIndex;
    return &gCourseMap->mBattlePoints[gStandings->mBattlePointIndex];
}

// Allocates the Standings object and fills every entry (rank = own index, side id, status, count; the real karts first,
// then the unused slots) and sets the winner to -1. Called from InitRace in modes 2 and 4.
void InitStandings(void) {
    s32 kartIndex;
    KartStanding *kartStanding;

    gStandings = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x3c0);
    for (kartIndex = 0; kartIndex < 8; kartIndex++) {
        kartStanding = &gStandings->mKarts[kartIndex];
        kartStanding->mObjectsSkipEndPending = KART_STANDING_HIT_END_NONE;
        kartStanding->mNotNormalEndPending = KART_STANDING_HIT_END_NONE;
        kartStanding->mHitByKartIndex = kartIndex;
        kartStanding->mRankIndex = kartIndex;
        if (kartIndex < gRaceSetup->mKartCount) {
            switch (GetCurrentEntry(kartIndex)->mPlayer.mTeamIndex) {
                case 0:
                    kartStanding->mTeamId = 1;
                    break;
                case 1:
                    kartStanding->mTeamId = 3;
                    break;
                default:
                    kartStanding->mTeamId = kartIndex;
                    break;
            }
            kartStanding->mEliminationStatus = 0;
            kartStanding->mBalloonOrShineCount = 0;
            kartStanding->mBalloonsLeftToMake = 0;
        } else {
            kartStanding->mEliminationStatus = 2;
            kartStanding->mBalloonOrShineCount = -1;
            kartStanding->mBalloonsLeftToMake = 0;
            kartStanding->mTeamId = gRaceSetup->mKartCount;
        }
    }
    gStandings->mWinnerTeamId = -1;
}

void FinishStandings(void) {
    gStandings->mEndTimer = -1;
    if (gStandings->mEndCallback != NULL) {
        gStandings->mEndCallback();
    }
}

void UpdateStandings(void) {
    Kart *kart;
    BOOL objectsSkipSet;
    BOOL notNormalOrFlagged;
    s32 nextMicInflateTimer;
    u32 kartFlags;
    s32 kartIndex;
    s32 kartCount;
    KartStanding *kartStanding = gStandings->mKarts;

    kartCount = gRaceSetup->mKartCount;
    if (gStandings->mWinnerTeamId >= 0) {
        if (gStandings->mEndTimer > 0) {
            gStandings->mEndTimer = gStandings->mEndTimer - 1;
            if (gStandings->mEndTimer <= 0) {
                gStandings->mEndTimer = -1;
                if (gStandings->mEndCallback != NULL) {
                    gStandings->mEndCallback();
                }
            }
        }
        for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
            if (gStandings->mKarts[kartIndex].mEliminationStatus == 1) {
                if (kartIndex != gRaceSetup->mEntryIndex) {
                    QueueKartOwnSoundIndex(GetKart((u16) kartIndex));
                }
                gStandings->mKarts[kartIndex].mEliminationStatus = 2;
            }
        }
        return;
    }
    for (kartIndex = kartCount - 1; kartIndex >= 0; kartIndex--) {
        kartStanding = &gStandings->mKarts[kartIndex];
        if (kartStanding->mEliminationStatus == 1) {
            QueueKartOwnSoundIndex(GetKart((u16) kartIndex));
            gStandings->mKarts[kartIndex].mEliminationStatus = 2;
        } else if (gStandings->mWinnerTeamId < 0 && kartStanding->mBalloonOrShineCount > 0) {
            kart = GetKart((u16) kartIndex);
            kartStanding = &gStandings->mKarts[kartIndex];
            nextMicInflateTimer = kartStanding->mMicInflateTimer - 1;
            if (nextMicInflateTimer <= 0) {
                nextMicInflateTimer = 0;
            }
            kartStanding->mMicInflateTimer = nextMicInflateTimer;
            gStandings->mKarts[kartIndex].mSelectKeyInflate = -(gStandings->mKarts[kartIndex].mSelectKeyInflate <= 0);
            if (IsKartNotNormalOrFlagged(kart) != FALSE ||
                (u16) (gInputSlots[kart->mEntryIndex].mBits & (PAD_KEY_A | PAD_KEY_B)) != 0) {
                gStandings->mKarts[kartIndex].mSelectKeyInflate = -1;
                gStandings->mKarts[kartIndex].mMicInflateTimer = -1;
            } else if (IsRaceStarted() == 1) {
                if ((u16) (GetInputSlot(kart->mEntryIndex)->mBits & PAD_KEY_SELECT) != 0) {
                    gStandings->mKarts[kartIndex].mSelectKeyInflate = 1;
                } else if (gInputSlots[kart->mEntryIndex].mPair.mMicOverThreshold[0] != 0) {
                    gStandings->mKarts[kartIndex].mMicInflateTimer = 10;
                }
            }
            if (gStandings->mKartHitCallback != NULL) {
                notNormalOrFlagged = TRUE;
                kartFlags = kart->mDriveFlags;
                objectsSkipSet = (kartFlags & KART_DRIVE_OBJECTS_SKIP) != 0;
                if (kart->mState == KART_STATE_NORMAL && (kartFlags & KART_DRIVE_SCALE_TABLE_EFFECT) == 0) {
                    notNormalOrFlagged = FALSE;
                }
                if (kartStanding->mObjectsSkipSeen == FALSE && objectsSkipSet != FALSE &&
                    (kart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                    kartStanding->mObjectsSkipSeen = TRUE;
                    kartStanding->mNotNormalOrFlaggedSeen = FALSE;
                    kartStanding->mNotNormalEndPending = KART_STANDING_HIT_END_NONE;
                    kartStanding->mHitByKartIndex = kartIndex;
                    kartStanding->mSkipNotNormalEnd = FALSE;
                    if (kartStanding->mBalloonOrShineCount <= 1) {
                        if ((gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) ||
                            gRaceSetup->mMode == MODE_MISSION_RUN) {
                            kart->mEntryFlags |= KART_ENTRY_OUT_OF_ROUND;
                            kart->mDriveFlags &= ~KART_DRIVE_RESPAWN_LANDING;
                        }
                    }
                } else if (kartStanding->mObjectsSkipSeen == TRUE && (kart->mMotionFlags & KART_MOTION_LANDED) != 0) {
                    kartStanding->mObjectsSkipSeen = FALSE;
                    kartStanding->mObjectsSkipEndPending = 0;
                    if ((kart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                        StartKartBlink(kart);
                    }
                }
                if (kartStanding->mObjectsSkipEndPending == 0) {
                    kartStanding->mObjectsSkipEndPending = KART_STANDING_HIT_END_NONE;
                    gStandings->mKartHitCallback(kartIndex, 8);
                    kartStanding->mHitByKartIndex = kartIndex;
                } else if (kartStanding->mObjectsSkipEndPending >= 0) {
                    kartStanding->mObjectsSkipEndPending = kartStanding->mObjectsSkipEndPending + 1;
                }
                if (kartStanding->mNotNormalOrFlaggedSeen == FALSE && notNormalOrFlagged != FALSE &&
                    (kart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                    kartStanding->mNotNormalOrFlaggedSeen = TRUE;
                    if (kartStanding->mBalloonOrShineCount <= 1) {
                        if ((gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) ||
                            gRaceSetup->mMode == MODE_MISSION_RUN) {
                            kart->mEntryFlags |= KART_ENTRY_OUT_OF_ROUND;
                        }
                    }
                } else if (kartStanding->mNotNormalOrFlaggedSeen == TRUE && notNormalOrFlagged == FALSE &&
                           (kart->mDriveFlags & KART_DRIVE_NOT_NORMAL) == 0) {
                    kartStanding->mNotNormalOrFlaggedSeen = FALSE;
                    if (kartStanding->mSkipNotNormalEnd == FALSE) {
                        kartStanding->mNotNormalEndPending = 0;
                        if ((kart->mEffectFlags & KART_EFFECT_BLINK_GUARD) == 0) {
                            StartKartBlink(kart);
                        }
                    } else {
                        kartStanding->mSkipNotNormalEnd = FALSE;
                    }
                }
                if (kartStanding->mNotNormalEndPending == 0) {
                    kartStanding->mNotNormalEndPending = KART_STANDING_HIT_END_NONE;
                    gStandings->mKartHitCallback(kartIndex, kartStanding->mHitByKartIndex);
                    kartStanding->mHitByKartIndex = kartIndex;
                } else if (kartStanding->mNotNormalEndPending >= 0) {
                    kartStanding->mNotNormalEndPending = kartStanding->mNotNormalEndPending + 1;
                }
            }
            kartStanding->mPos = kart->mPos;
        }
    }
}

void InitDistanceSound(DistanceSound *mapObject) {
    s32 courseId;

    courseId = gRaceSetup->mCourseId;
    if (courseId == COURSE_ID_MANSION) {
        mapObject->mSoundId = 0x121;
    } else if (courseId == COURSE_ID_BEACH) {
        mapObject->mSoundId = 0x111;
        mapObject->mSecondSoundId = 0x10a;
    } else {
        mapObject->mSoundId = 0x20d;
    }
}

void InitDistanceSoundObjects(MapObjectList *mapObjectList) {
    s32 objectIndex;
    DistanceSound *mapObject;
    RandomState64 *randomState;

    if (mapObjectList == NULL) {
        return;
    }
    for (objectIndex = 0;
         objectIndex < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[objectIndex]) != NULL;
         objectIndex++) {
        if (gRaceSetup->mCourseId == COURSE_ID_MANSION) {
            mapObject->mRadius = 0xa28;
            mapObject->mCenterX = mapObject->mMapObject.mPos.x + 0x73a000;
            mapObject->mCenterY = mapObject->mMapObject.mPos.y;
            mapObject->mCenterZ = mapObject->mMapObject.mPos.z - 0x1400000;
            mapObject->mDistanceLevelInverted = TRUE;
        } else if (gRaceSetup->mCourseId == COURSE_ID_BEACH) {
            mapObject->mRadius = 0x546;
            mapObject->mCenterX = mapObject->mMapObject.mPos.x + 0x28a000;
            mapObject->mCenterY = mapObject->mMapObject.mPos.y;
            mapObject->mCenterZ = mapObject->mMapObject.mPos.z - 0x32000;
            mapObject->mDistanceLevelInverted = FALSE;
        } else {
            mapObject->mRadius = 0xa28;
            mapObject->mCenterX = mapObject->mMapObject.mPos.x;
            mapObject->mCenterY = mapObject->mMapObject.mPos.y;
            mapObject->mCenterZ = mapObject->mMapObject.mPos.z;
            mapObject->mDistanceLevelInverted = FALSE;
        }
        randomState = &gRaceProgress->mLocalRandom;
        randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
        mapObject->mSoundTimer = (u16) (((u64) (u32) (randomState->mValue >> 32) * 0x3c) >> 32) + 0x258;
        mapObject->mDistanceVolumeFixed12 = 0x7f000;
        randomState = &gRaceProgress->mLocalRandom;
        randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
        mapObject->mDistanceLevelTimer = (u16) (((u64) (u32) (randomState->mValue >> 32) * 0xf) >> 32);
    }
}

void UpdateDistanceSound(void *mapObjectList, DistanceSound *mapObject) {
    Kart *kart;
    NNSSndSeqPlayer **sndHandleSlot;
    RandomState64 *randomState;
    SoundStartParams slot8Request;
    SoundStartParams slot9Request;
    s32 value;
    s32 halfRadius;
    s32 radius;
    s32 deltaZ;
    s32 deltaX;
    s64 distanceSquared;

    if (mapObject->mDistanceLevelTimer-- <= 0) {
        mapObject->mDistanceLevelTimer = 0xf;
        radius = mapObject->mRadius;
        halfRadius = radius / 2;
        kart = GetKart((u16) gRaceSetup->mEntryIndex);
        deltaX = kart->mPos.x - mapObject->mCenterX;
        deltaZ = kart->mPos.z - mapObject->mCenterZ;
        distanceSquared = (s64) deltaX * deltaX + (s64) deltaZ * deltaZ;
        if (distanceSquared < (s64) halfRadius * halfRadius) {
            value = 2;
        } else if (distanceSquared < (s64) TO_FIXED12(radius) * TO_FIXED12(radius)) {
            value = 1;
        } else {
            value = 0;
        }
        mapObject->mDistanceLevel = value;
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
                kart = GetKart((u16) gRaceSetup->mEntryIndex);
                mapObject->mSoundVolumeFixed12 =
                    mapObject->mSoundVolumeFixed12 - MUL_FIXED12_NO_ROUND(kart->mVelocityLengthRatio, 0x1000);
                if (mapObject->mSoundVolumeFixed12 < 0xc000) {
                    mapObject->mSoundVolumeFixed12 = 0xc000;
                }
            } else if (mapObject->mSoundTimer-- <= 0) {
                sndHandleSlot = GetSndHandleSlot(8);
                slot8Request.mSoundId = mapObject->mSoundId;
                slot8Request.mPositionSource = NULL;
                slot8Request.mFalloffIndex = 4;
                slot8Request.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
                StartSndHandleSound(&slot8Request, sndHandleSlot);
                randomState = &gRaceProgress->mLocalRandom;
                randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
                mapObject->mSoundTimer = (u16) (((u64) (u32) (randomState->mValue >> 32) * 0x3c) >> 32) + 0x78;
                mapObject->mSoundVolumeFixed12 = 0x7f000;
            }
        } else if (mapObject->mSoundTimer > 0) {
            mapObject->mSoundTimer = mapObject->mSoundTimer - 1;
        }
        if (*GetSndHandleSlot(8) != NULL) {
            value = mapObject->mDistanceVolumeFixed12 < mapObject->mSoundVolumeFixed12
                        ? mapObject->mDistanceVolumeFixed12
                        : mapObject->mSoundVolumeFixed12;
            SetSndHandleTrackVolume(GetSndHandleSlot(8), FROM_FIXED12(value));
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
            slot9Request.mFalloffIndex = 4;
            slot9Request.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
            StartSndHandleSound(&slot9Request, sndHandleSlot);
        }
    }
    if (*GetSndHandleSlot(9) == NULL) {
        return;
    }
    SetSndHandleTrackVolume(GetSndHandleSlot(9), FROM_FIXED12(mapObject->mDistanceVolumeFixed12));
}

MapObjectList *CreateDistanceSoundUpdateList(void) {
    return CreateMapObjectUpdateList(InitDistanceSoundObjects, UpdateDistanceSound, NULL);
}
