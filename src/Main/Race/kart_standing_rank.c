#include "Main/Race/kart_standing_rank.h"
#include "Main/Race/race_progress_rank.h"
#include "Main/Race/kart.h"
#include "Main/Race/race_clock.h"
#include "Main/Race/race_score.h"
#include "Main/Race/race_keys.h"
#include "Main/Race/cup_records.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Kart/code_0207a000.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Race/race_end.h"
#include "Main/Sound/race_end_seq.h"
#include "Main/Race/race_progress_kart.h"
#include "Main/Race/race_checkpoint_progress.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Kart/karts.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

static inline s32 GetKartStandingRankIndexPlusOne(u32 kartIndex) {
    return GetKartStandingRankIndex(kartIndex) + 1;
}

void FinishRaceProgress(void) {
    RaceProgress *raceProgress;
    s32 winningTeamIndex = -1;
    RaceSetup *raceSetup = gRaceSetup;
    s32 mode = raceSetup->mMode;
    u32 kartIndex;
    BOOL usesTeams = FALSE;
    switch (mode) {
        case MODE_BATTLE:
        case MODE_VS:
            if (raceSetup->mUseTeams != 0) {
                usesTeams = TRUE;
            }
            break;
    }
    switch (mode) {
        case MODE_GRAND_PRIX:
        case MODE_VS:
        case MODE_WIFI: {
            for (kartIndex = 0; kartIndex < raceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
                u32 rankValue;
                u8 rank;
                u32 rankPoints = 0;
                if (raceSetup->mMode == MODE_WIFI) {
                    rankValue =
                        gWiFiRaceSync->mEntries[gParticipantKartMap->mParticipantOfKart[kartIndex & 0xff]].mRank;
                } else {
                    rankValue = gRaceProgress->mKarts[kartIndex].mRank;
                }
                rank = rankValue;
                if (gRaceProgress->mKarts[kartIndex].mStatus != RACE_PROGRESS_KART_STATUS_REMOVED) {
                    rankPoints = LookupRankPoints(rank);
                }
                SetKartCourseResult(kartIndex, rank, rankPoints);
                SetKartCourseFinishTime(kartIndex, &gRaceProgress->mKarts[kartIndex].mLapTimes[5]);
                if (gRaceSetup->mMode == MODE_WIFI) {
                    if (gRaceProgress->mKarts[kartIndex].mStatus == RACE_PROGRESS_KART_STATUS_REMOVED) {
                        ClearKartCourseTotalPoints(kartIndex);
                    }
                }
                if (usesTeams != FALSE) {
                    if (rank == 1) {
                        winningTeamIndex = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex;
                    }
                }
                raceSetup = gRaceSetup;
            }
            break;
        }
        case MODE_BATTLE: {
            s32 isOnWinningTeam;
            if (usesTeams != FALSE) {
                kartIndex = 0;
                if (kartIndex < raceSetup->mKartCount) {
                    raceProgress = gRaceProgress;
                    do {
                        if (raceProgress->mKarts[kartIndex].mStatus == RACE_PROGRESS_KART_STATUS_GOAL_REACHED) {
                            if (usesTeams != FALSE) {
                                if (winningTeamIndex == -1) {
                                    raceSetup = gRaceSetup;
                                    winningTeamIndex = raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex;
                                }
                            }
                        }
                        kartIndex = (u16) (kartIndex + 1);
                    } while (kartIndex < raceSetup->mKartCount);
                }
            }
            for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
                gRaceProgress->mKarts[kartIndex].mFlags |= RACE_PROGRESS_KART_FLAG_BATTLE_END;
                if (gRaceProgress->mKarts[kartIndex].mStatus == RACE_PROGRESS_KART_STATUS_GOAL_REACHED) {
                    if (usesTeams != FALSE) {
                        isOnWinningTeam =
                            winningTeamIndex == gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex ? 1 : 0;
                    } else {
                        isOnWinningTeam = 1;
                    }
                    SetBattleKartCourseResult(kartIndex, 1);
                } else {
                    if (usesTeams != FALSE) {
                        isOnWinningTeam =
                            winningTeamIndex == gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex ? 1 : 0;
                    } else {
                        isOnWinningTeam = 0;
                    }
                    SetBattleKartCourseResult(kartIndex, 0);
                    if (gRaceProgress->mKarts[kartIndex].mStatus == RACE_PROGRESS_KART_STATUS_RACING) {
                        gRaceProgress->mKarts[kartIndex].mStatus = RACE_PROGRESS_KART_STATUS_BATTLE_LOSER;
                    }
                }
                FinishKartAtBattleEnd(GetKart(kartIndex), isOnWinningTeam);
            }
            StartRaceEndSeq(0);
            break;
        }
    }
    if (usesTeams != FALSE) {
        SetTeamWinCountsAndPoints(winningTeamIndex);
    }
    gRaceProgress->mRaceDone = 1;
}

void UpdateBattleKartStatuses(void) {
    u32 kartIndex;
    if (IsWinnerDecidedAndEndReached() != 0) {
        for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            RaceProgressKart *kart = &gRaceProgress->mKarts[kartIndex];
            if (kart->mStatus == RACE_PROGRESS_KART_STATUS_RACING) {
                if (IsKartOnWinningTeamAtEnd(kartIndex) != 0) {
                    kart->mStatus = RACE_PROGRESS_KART_STATUS_GOAL_REACHED;
                } else {
                    kart->mStatus = RACE_PROGRESS_KART_STATUS_BATTLE_LOSER;
                }
                kart->mFlags |= RACE_PROGRESS_KART_FLAG_BATTLE_END;
            }
        }
        return;
    }
    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
        if (IsKartEliminated(kartIndex) != FALSE) {
            RaceProgressKart *kart = &gRaceProgress->mKarts[kartIndex];
            if (kart->mStatus == RACE_PROGRESS_KART_STATUS_RACING) {
                if (IsKartOnWinningTeamAtEnd(kartIndex) != 0) {
                    kart->mStatus = RACE_PROGRESS_KART_STATUS_GOAL_REACHED;
                } else {
                    kart->mStatus = RACE_PROGRESS_KART_STATUS_BATTLE_LOSER;
                }
                kart->mFlags |= RACE_PROGRESS_KART_FLAG_BATTLE_END;
            }
        }
    }
    if (IsRaceEndConditionMet() != 0) {
        switch (gRaceSetup->mMode) {
            case MODE_TIME_ATTACK:
                break;
            case MODE_BATTLE:
                EliminateKartsUntilWinnerDecided();
                break;
            case MODE_MISSION_RUN:
                FinishRemainingMissionRunKarts();
                break;
            case MODE_WIFI:
                FinishRemainingWiFiRaceKarts();
                break;
            default:
                FinishRemainingRaceProgressKarts();
                break;
        }
    }
}

static inline u16 KartStandingReturnArgumentAsU16(s32 entryIndex) {
    return (u16) entryIndex;
}

// TRUE once no kart is still racing in battle, until the race is marked done.
BOOL ShouldFinishBattle(void) {
    u32 kartIndex;
    s32 racingCount;
    BOOL noneRacing = TRUE;
    RaceProgress *raceProgress = gRaceProgress;
    if (raceProgress->mRaceDone != 0) {
        return FALSE;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        racingCount = 0;
        for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            if (raceProgress->mKarts[kartIndex].mStatus == RACE_PROGRESS_KART_STATUS_RACING) {
                racingCount++;
                if (racingCount > 0) {
                    noneRacing = FALSE;
                    break;
                }
            }
        }
        return noneRacing;
    }
    return FALSE;
}

void AdvanceMissionRunEnd(void) {
    BOOL endFound = FALSE;
    s32 endKind = 2;
    RaceSetup *raceSetup = gRaceSetup;
    s32 entryIndex = raceSetup->mEntryIndex;
    u16 kartIndex;
    u32 kartOffset;
    RaceProgressKart *kart;
    BOOL hasEnded;
    if (entryIndex < 0) {
        return;
    }
    kartIndex = entryIndex;
    kartOffset = kartIndex * 0x8c;
    kart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], kartOffset);
    hasEnded = FALSE;
    switch (kart->mStatus) {
        case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
        case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
        case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
            hasEnded = TRUE;
            break;
    }
    if (hasEnded != FALSE) {
        if ((kart->mFlags & RACE_PROGRESS_KART_FLAG_GOAL_WAIT) != 0) {
            gRaceProgress->mFramesSinceFinish++;
            if (gRaceProgress->mFramesSinceFinish <= gRaceSetup->mFinishWaitFrameCount) {
                return;
            }
            FinishKartAtMissionRunEnd(GetKart((u16) entryIndex));
            StartKartRaceEndWrapper(KartStandingReturnArgumentAsU16(entryIndex));
            RequestRaceEndStemSet();
            StartRaceEndSeq(0);
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                FinishStandings();
            }
            kart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], kartOffset);
            kart->mFlags &= ~RACE_PROGRESS_KART_FLAG_GOAL_WAIT;
        } else if ((kart->mFlags & RACE_PROGRESS_KART_FLAG_FAILURE_WAIT) != 0) {
            if (IsEntryKartNormalOrNotMissionRun() != 0) {
                gRaceProgress->mFramesSinceFailure++;
            }
            if (gRaceProgress->mFramesSinceFailure <= 0x3c) {
                return;
            }
            FinishKartAtMissionRunEnd(GetKart(entryIndex));
            StartKartRaceEndWrapper((u16) entryIndex);
            StartRaceEndSeq(0);
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                FinishStandings();
            }
            kart = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], kartOffset);
            kart->mFlags &= ~RACE_PROGRESS_KART_FLAG_FAILURE_WAIT;
        }
        return;
    }
    if ((raceSetup->mMissionRunBits & MISSION_RUN_BIT_END_NOT_NORMAL) != 0) {
        if (IsEntryKartNotNormalOrScaleTableBit() != FALSE) {
            endFound = TRUE;
        }
    }
    if (endFound == FALSE) {
        if ((gRaceSetup->mMissionRunBits & MISSION_RUN_BIT_END_IN_CONTACT) != 0) {
            if (IsEntryKartInContact() != 0) {
                endKind = 3;
                endFound = TRUE;
            }
        }
    }
    if (endFound == FALSE) {
        if ((gRaceSetup->mMissionRunBits & MISSION_RUN_BIT_END_KART_FLAG_1000) != 0) {
            if (IsEntryKartFlag1000Set() != 0) {
                endFound = TRUE;
            }
        }
    }
    if (endFound == FALSE) {
        if (UpdateShapeMapObjectCounts() != 0) {
            endKind = 4;
            endFound = TRUE;
        }
    }
    if (endFound == FALSE) {
        return;
    }
    FinishRaceProgressKartWithEndKind((u16) gRaceSetup->mEntryIndex, endKind);
}

void FinishRaceProgressKartWithEndKind4(u16 kartIndex) {
    FinishRaceProgressKartWithEndKind(kartIndex, 4);
}

void UpdateRaceProgress(void) {
    u32 kartIndex;
    UpdateRaceClock();
    if (gRaceSetup->mMode == MODE_WIFI) {
        for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            RaceProgressKart *kart = &gRaceProgress->mKarts[kartIndex];
            if (kart->mFinishRequest != 0) {
                FinishRaceProgressKart(kart, kart->mFinishRequest == 1 ? 1 : 0);
                if (IsRaceEndConditionMet() != 0) {
                    switch (gRaceSetup->mMode) {
                        case MODE_TIME_ATTACK:
                            break;
                        case MODE_BATTLE:
                            EliminateKartsUntilWinnerDecided();
                            break;
                        case MODE_MISSION_RUN:
                            FinishRemainingMissionRunKarts();
                            break;
                        case MODE_WIFI:
                            FinishRemainingWiFiRaceKarts();
                            break;
                        default:
                            FinishRemainingRaceProgressKarts();
                            break;
                    }
                }
                kart->mFinishRequest = 0;
            }
        }
    }
    if (gCourseMap->mCheckpoints != NULL) {
        UpdateRaceProgressKarts();
    } else {
        BOOL entryRaceEnded = FALSE;
        switch (gRaceSetup->mRaceKind) {
            case RACE_KIND_DEMO:
            case RACE_KIND_REPLAY:
            case RACE_KIND_STAFF_ROLL:
                entryRaceEnded = TRUE;
                break;
            case RACE_KIND_NORMAL:
                if (IsEntryRaceEnded() != 0) {
                    entryRaceEnded = TRUE;
                }
                break;
        }
        gRaceProgress->mEntryRaceEnded = entryRaceEnded;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            u16 *rankBits;
            u8 standingRank = GetKartStandingRankIndexPlusOne(kartIndex);
            rankBits = &gRaceProgress->mKarts[kartIndex].mRankIndexRequestBits;
            *rankBits = (*rankBits & ~0xf) | (standingRank & 0xf);
        }
        for (kartIndex = 0; kartIndex < 8; kartIndex = (u16) (kartIndex + 1)) {
            gRaceProgress->mKartAtRank[kartIndex] = -1;
        }
        UpdateBattleKartStatuses();
        if (ShouldFinishBattle() != 0) {
            FinishRaceProgress();
        }
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AdvanceMissionRunEnd();
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        BOOL raceEnded = FALSE;
        switch (gRaceProgress->mKarts[0].mStatus) {
            case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
            case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
            case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                raceEnded = TRUE;
                break;
        }
        if (raceEnded == FALSE) {
            return;
        }
        if (gRaceProgress->mRaceDone == 0) {
            gRaceProgress->mRaceDone = 1;
        }
        return;
    }
    if ((u32) gRaceProgress->mHeader.mFinishedCount < gRaceSetup->mKartCount) {
        return;
    }
    if (gRaceProgress->mRaceDone != 0) {
        return;
    }
    FinishRaceProgress();
}
