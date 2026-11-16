#include "Main/Race/kart_standing_rank.h"
#include "Main/Race/race_end_condition.h"
#include "Main/Race/race_progress_rank.h"
#include "Main/Race/kart.h"
#include "Main/Race/race_clock.h"
#include "Main/Race/race_score.h"
#include "Main/Race/race_keys.h"
#include "Main/Race/cup_records.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Kart/shadow_model_draw.h"
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
    RaceSetup *raceSetup = g_GlobalCO;
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
                        g_GlobalAA->mEntries[g_GlobalRE->mParticipantOfKart[kartIndex & 0xff]].mRank;
                } else {
                    rankValue = g_GlobalMV->mKarts[kartIndex].mRank;
                }
                rank = rankValue;
                if (g_GlobalMV->mKarts[kartIndex].mStatus != RACE_PROGRESS_KART_STATUS_REMOVED) {
                    rankPoints = LookupRankPoints(rank);
                }
                SetKartCourseResult(kartIndex, rank, rankPoints);
                SetKartCourseFinishTime(kartIndex, &g_GlobalMV->mKarts[kartIndex].mLapTimes[5]);
                if (g_GlobalCO->mMode == MODE_WIFI) {
                    if (g_GlobalMV->mKarts[kartIndex].mStatus == RACE_PROGRESS_KART_STATUS_REMOVED) {
                        ClearKartCourseTotalPoints(kartIndex);
                    }
                }
                if (usesTeams != FALSE) {
                    if (rank == 1) {
                        winningTeamIndex = g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mTeamIndex;
                    }
                }
                raceSetup = g_GlobalCO;
            }
            break;
        }
        case MODE_BATTLE: {
            s32 isOnWinningTeam;
            if (usesTeams != FALSE) {
                kartIndex = 0;
                if (kartIndex < raceSetup->mKartCount) {
                    raceProgress = g_GlobalMV;
                    do {
                        if (raceProgress->mKarts[kartIndex].mStatus == RACE_PROGRESS_KART_STATUS_GOAL_REACHED) {
                            if (usesTeams != FALSE) {
                                if (winningTeamIndex == -1) {
                                    raceSetup = g_GlobalCO;
                                    winningTeamIndex = raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex;
                                }
                            }
                        }
                        kartIndex = (u16) (kartIndex + 1);
                    } while (kartIndex < raceSetup->mKartCount);
                }
            }
            for (kartIndex = 0; kartIndex < g_GlobalCO->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
                g_GlobalMV->mKarts[kartIndex].mFlags |= RACE_PROGRESS_KART_FLAG_BATTLE_END;
                if (g_GlobalMV->mKarts[kartIndex].mStatus == RACE_PROGRESS_KART_STATUS_GOAL_REACHED) {
                    if (usesTeams != FALSE) {
                        isOnWinningTeam =
                            winningTeamIndex == g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mTeamIndex ? 1 : 0;
                    } else {
                        isOnWinningTeam = 1;
                    }
                    SetBattleKartCourseResult(kartIndex, 1);
                } else {
                    if (usesTeams != FALSE) {
                        isOnWinningTeam =
                            winningTeamIndex == g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mTeamIndex ? 1 : 0;
                    } else {
                        isOnWinningTeam = 0;
                    }
                    SetBattleKartCourseResult(kartIndex, 0);
                    if (g_GlobalMV->mKarts[kartIndex].mStatus == RACE_PROGRESS_KART_STATUS_RACING) {
                        g_GlobalMV->mKarts[kartIndex].mStatus = RACE_PROGRESS_KART_STATUS_BATTLE_LOSER;
                    }
                }
                StructMQRacerEntry_SomeFn_25(GetRacerMQEntry(kartIndex), isOnWinningTeam);
            }
            MaybePlayCrowdAmbientNoise(0);
            break;
        }
    }
    if (usesTeams != FALSE) {
        SetTeamWinCountsAndPoints(winningTeamIndex);
    }
    g_GlobalMV->mRaceDone = 1;
}

void UpdateBattleKartStatuses(void) {
    u32 kartIndex;
    if (IsWinnerDecidedAndEndReached() != 0) {
        for (kartIndex = 0; kartIndex < g_GlobalCO->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            RaceProgressKart *kart = &g_GlobalMV->mKarts[kartIndex];
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
    for (kartIndex = 0; kartIndex < g_GlobalCO->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
        if (IsKartEliminated(kartIndex) != FALSE) {
            RaceProgressKart *kart = &g_GlobalMV->mKarts[kartIndex];
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
        switch (g_GlobalCO->mMode) {
            case MODE_TIME_ATTACK:
                break;
            case MODE_BATTLE:
                RaceModeBattle_OrMissionRun_SomeFn();
                break;
            case MODE_MISSION_RUN:
                RaceModeMissionRun_SomeFn();
                break;
            case MODE_WIFI:
                RaceModeNet_SomeFn();
                break;
            default:
                RaceModeDefault_SomeFn();
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
    RaceProgress *raceProgress = g_GlobalMV;
    if (raceProgress->mRaceDone != 0) {
        return FALSE;
    }
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        racingCount = 0;
        for (kartIndex = 0; kartIndex < g_GlobalCO->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
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
    s32 endKind = RACE_END_KIND_KART_STATE;
    RaceSetup *raceSetup = g_GlobalCO;
    s32 entryIndex = raceSetup->mEntryIndex;
    u16 kartIndex;
    RaceProgressKart *kart;
    BOOL hasEnded;
    if (entryIndex < 0) {
        return;
    }
    kartIndex = entryIndex;
    kart = &g_GlobalMV->mKarts[kartIndex];
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
            g_GlobalMV->mFramesSinceFinish++;
            if (g_GlobalMV->mFramesSinceFinish <= g_GlobalCO->mFinishWaitFrameCount) {
                return;
            }
            StructMQRacerEntry_SomeFn_15(GetRacerMQEntry((u16) entryIndex));
            StructMQRacerEntry_SomeFn_21_ById(KartStandingReturnArgumentAsU16(entryIndex));
            RequestRaceEndStemSet();
            MaybePlayCrowdAmbientNoise(0);
            if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
                FinishStandings();
            }
            kart = &g_GlobalMV->mKarts[kartIndex];
            kart->mFlags &= ~RACE_PROGRESS_KART_FLAG_GOAL_WAIT;
        } else if ((kart->mFlags & RACE_PROGRESS_KART_FLAG_FAILURE_WAIT) != 0) {
            if (IsEntryKartNormalOrNotMissionRun() != 0) {
                g_GlobalMV->mFramesSinceFailure++;
            }
            if (g_GlobalMV->mFramesSinceFailure <= RACE_FAILURE_WAIT_FRAMES) {
                return;
            }
            StructMQRacerEntry_SomeFn_15(GetRacerMQEntry(entryIndex));
            StructMQRacerEntry_SomeFn_21_ById(entryIndex);
            MaybePlayCrowdAmbientNoise(0);
            if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
                FinishStandings();
            }
            kart = &g_GlobalMV->mKarts[kartIndex];
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
        if ((g_GlobalCO->mMissionRunBits & MISSION_RUN_BIT_END_IN_CONTACT) != 0) {
            if (IsEntryKartInContact() != 0) {
                endKind = RACE_END_KIND_CONTACT;
                endFound = TRUE;
            }
        }
    }
    if (endFound == FALSE) {
        if ((g_GlobalCO->mMissionRunBits & MISSION_RUN_BIT_END_KART_FLAG_1000) != 0) {
            if (IsEntryKartRespawnFalling() != 0) {
                endFound = TRUE;
            }
        }
    }
    if (endFound == FALSE) {
        if (UpdateShapeMapObjectCounts() != 0) {
            endKind = RACE_END_KIND_FAILED;
            endFound = TRUE;
        }
    }
    if (endFound == FALSE) {
        return;
    }
    FinishRaceProgressKartWithEndKind((u16) g_GlobalCO->mEntryIndex, endKind);
}

void FinishRaceProgressKartMissionFailed(u16 kartIndex) {
    FinishRaceProgressKartWithEndKind(kartIndex, RACE_END_KIND_FAILED);
}

void UpdateRaceProgress(void) {
    u32 kartIndex;
    UpdateRaceClock();
    if (g_GlobalCO->mMode == MODE_WIFI) {
        for (kartIndex = 0; kartIndex < g_GlobalCO->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            RaceProgressKart *kart = &g_GlobalMV->mKarts[kartIndex];
            if (kart->mFinishRequest != 0) {
                RegisterNewRacer(kart, kart->mFinishRequest == 1 ? 1 : 0);
                if (IsRaceEndConditionMet() != 0) {
                    switch (g_GlobalCO->mMode) {
                        case MODE_TIME_ATTACK:
                            break;
                        case MODE_BATTLE:
                            RaceModeBattle_OrMissionRun_SomeFn();
                            break;
                        case MODE_MISSION_RUN:
                            RaceModeMissionRun_SomeFn();
                            break;
                        case MODE_WIFI:
                            RaceModeNet_SomeFn();
                            break;
                        default:
                            RaceModeDefault_SomeFn();
                            break;
                    }
                }
                kart->mFinishRequest = 0;
            }
        }
    }
    if (g_GlobalPE->mCheckpoints != NULL) {
        UpdateRaceProgressKarts();
    } else {
        BOOL entryRaceEnded = FALSE;
        switch (g_GlobalCO->mRaceKind) {
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
        g_GlobalMV->mEntryRaceEnded = entryRaceEnded;
    }
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        for (kartIndex = 0; kartIndex < g_GlobalCO->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            u16 *rankBits;
            u8 standingRank = GetKartStandingRankIndexPlusOne(kartIndex);
            rankBits = &g_GlobalMV->mKarts[kartIndex].mRankIndexRequestBits;
            *rankBits = (*rankBits & ~0xf) | (standingRank & 0xf);
        }
        for (kartIndex = 0; kartIndex < 8; kartIndex = (u16) (kartIndex + 1)) {
            g_GlobalMV->mKartAtRank[kartIndex] = -1;
        }
        UpdateBattleKartStatuses();
        if (ShouldFinishBattle() != 0) {
            FinishRaceProgress();
        }
    }
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        AdvanceMissionRunEnd();
    }
    if (g_GlobalCO->mMode == MODE_TIME_ATTACK) {
        BOOL raceEnded = FALSE;
        switch (g_GlobalMV->mKarts[0].mStatus) {
            case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
            case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
            case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                raceEnded = TRUE;
                break;
        }
        if (raceEnded == FALSE) {
            return;
        }
        if (g_GlobalMV->mRaceDone == 0) {
            g_GlobalMV->mRaceDone = 1;
        }
        return;
    }
    if ((u32) g_GlobalMV->mHeader.mFinishedCount < g_GlobalCO->mKartCount) {
        return;
    }
    if (g_GlobalMV->mRaceDone != 0) {
        return;
    }
    FinishRaceProgress();
}
