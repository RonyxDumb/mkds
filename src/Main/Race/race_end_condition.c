#include "Main/Race/race_end_condition.h"
#include "Main/Race/race_progress_rule.h"
#include "Main/Race/race_checkpoint_progress.h"
#include "Main/System/key_recording_read.h"
#include "Main/System/key_recording_finish.h"
#include "Main/Race/race_score.h"
#include "Main/Item/item_data_slots_update.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Race/race_hud_sub_screen_item_box_cells.h"
#include "Main/System/input_slots.h"
#include "Main/System/backup_net_camera_work.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "fixed_vector_math.h"
#include "Main/Race/kart.h"
#include "Main/Kart/karts.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

s32 IsRaceEndConditionMet(void) {
    BOOL endConditionMet;
    u16 kartIndex;
    s32 value;
    BOOL flag;
    s32 participantKart;
    s32 kartCount;
    s32 removedCount;
    RaceSetup *raceSetup;
    RaceProgress *raceProgress;
    raceSetup = g_GlobalCO;
    switch (raceSetup->mMode) {
        case MODE_GRAND_PRIX:
            endConditionMet = TRUE;
            for (kartIndex = 0; kartIndex < (u32) g_GlobalCO->mKartCount; kartIndex++) {
                flag = FALSE;
                value = raceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
                if ((u32) value <= 3 && ((1 << value) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                    flag = TRUE;
                }
                if (flag != FALSE) {
                    value = g_GlobalMV->mKarts[kartIndex].mStatus;
                    flag = FALSE;
                    switch (value) {
                        case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
                        case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
                        case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                            flag = TRUE;
                            break;
                    }
                    if (flag == FALSE) {
                        endConditionMet = FALSE;
                        break;
                    }
                }
            }
            break;
        case MODE_VS:
            endConditionMet = TRUE;
            raceProgress = g_GlobalMV;
            if (raceProgress->mHeader.mFinishedCount <
                (s32) GetCurrentRacerCount() - (raceProgress->mHeader.mRemovedCount + 1)) {
                for (kartIndex = 0; kartIndex < GetCurrentRacerCount(); kartIndex++) {
                    if (IsRacer_Player_Ghost_UnkNet3(kartIndex) != FALSE && IsRacerFinishedRace(kartIndex) == 0) {
                        if (IsRacerFinishStatus4(kartIndex) == FALSE) {
                            endConditionMet = FALSE;
                            break;
                        }
                    }
                }
            }
            if (endConditionMet == FALSE && GetCurrentRaceRules_0() == RULE_KIND_WIN_COUNT) {
                if (IsRacerFinishedRace(GetLeadingKart()) != 0) {
                    endConditionMet = TRUE;
                }
            }
            break;
        case MODE_WIFI:
            participantKart = g_GlobalRE->mKartOfParticipant[DWC_GetMyAID()];
            if (participantKart < 0) {
                endConditionMet = FALSE;
            } else {
                kartCount = g_GlobalCO->mKartCount;
                raceProgress = g_GlobalMV;
                removedCount = raceProgress->mHeader.mRemovedCount;
                if (kartCount - removedCount <= 1) {
                    endConditionMet = FALSE;
                } else {
                    value = GetRaceProgressKart(participantKart)->mStatus;
                    flag = FALSE;
                    switch (value) {
                        case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
                        case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
                        case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                            flag = TRUE;
                            break;
                    }
                    if (flag == FALSE) {
                        endConditionMet = raceProgress->mHeader.mFinishedCount + removedCount >= kartCount - 1;
                    } else {
                        endConditionMet = raceProgress->mHeader.mFinishedCount + removedCount >= kartCount;
                    }
                }
            }
            break;
        case MODE_TIME_ATTACK:
            endConditionMet = FALSE;
            switch (g_GlobalMV->mKarts[0].mStatus) {
                case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
                case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
                case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                    endConditionMet = TRUE;
                    break;
            }
            break;
        case MODE_BATTLE:
            endConditionMet = TRUE;
            for (kartIndex = 0; kartIndex < (u32) raceSetup->mKartCount; kartIndex++) {
                flag = FALSE;
                value = raceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
                if ((u32) value <= 3 && ((1 << value) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                    flag = TRUE;
                }
                if (flag != FALSE) {
                    if (IsKartEliminated(kartIndex) == FALSE) {
                        endConditionMet = FALSE;
                        break;
                    }
                }
                raceSetup = g_GlobalCO;
            }
            break;
        case MODE_MISSION_RUN:
            endConditionMet = FALSE;
            if (raceSetup->mMissionKind == MISSION_KIND_LAPS_FIRST_PLACE &&
                g_GlobalMV->mHeader.mFinishedCount != 0) {
                endConditionMet = TRUE;
            }
            break;
        default:
            endConditionMet = FALSE;
            break;
    }
    return endConditionMet;
}

void RaceModeDefault_SomeFn(void) {
    u16 kartIndex;
    RaceProgressKart *raceProgressKart;
    s32 status;
    BOOL ended;
    BOOL frameFraction;
    BOOL finished;
    MinuteSecondMillisecondTime *finishTime;
    u32 frames;
    frameFraction = FALSE;
    finished = FALSE;
    for (kartIndex = 0; kartIndex < (u32) g_GlobalCO->mKartCount; kartIndex++) {
        status = g_GlobalMV->mKarts[kartIndex].mStatus;
        ended = FALSE;
        switch (status) {
            case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
            case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
            case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                ended = TRUE;
                break;
        }
        if (ended == FALSE && status != RACE_PROGRESS_KART_STATUS_REMOVED) {
            raceProgressKart = &g_GlobalMV->mKarts[kartIndex];
            finishTime = &raceProgressKart->mLapTimes[5];
            frames = g_GlobalMV->mHeader.mElapsedFrames;
            if (g_GlobalCO->mMode == MODE_GRAND_PRIX) {
                if (raceProgressKart->mRaceProgress > 0) {
                    frames = (u32) (frames * FX_Inv(raceProgressKart->mRaceProgress)) >> 12;
                    if (frames > 0x57e40) {
                        frames = 0x57e40;
                    }
                } else {
                    frames = 0x57e40;
                }
            }
            MaybeConvertElapsedTime(&finishTime->mMinute, &finishTime->mSecond, &finishTime->mMillisecond, frameFraction,
                            frames);
            RegisterNewRacer(raceProgressKart, finished);
        }
    }
    g_GlobalMV->mHeader.mFinishedCount = g_GlobalCO->mKartCount;
}

void RaceModeNet_SomeFn(void) {
    u16 kartIndex;
    RaceProgressKart *raceProgressKart;
    s32 status;
    BOOL ended;
    BOOL frameFraction;
    BOOL finished;
    MinuteSecondMillisecondTime *finishTime;
    u32 frames;
    frameFraction = FALSE;
    finished = FALSE;
    for (kartIndex = 0; kartIndex < (u32) g_GlobalCO->mKartCount; kartIndex++) {
        status = g_GlobalMV->mKarts[kartIndex].mStatus;
        ended = FALSE;
        switch (status) {
            case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
            case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
            case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                ended = TRUE;
                break;
        }
        if (ended == FALSE && status != RACE_PROGRESS_KART_STATUS_REMOVED) {
            raceProgressKart = &g_GlobalMV->mKarts[kartIndex];
            finishTime = &raceProgressKart->mLapTimes[5];
            frames = g_GlobalMV->mHeader.mElapsedFrames;
            if (g_GlobalCO->mMode == MODE_GRAND_PRIX) {
                if (raceProgressKart->mRaceProgress > 0) {
                    frames = (u32) (frames * FX_Inv(raceProgressKart->mRaceProgress)) >> 12;
                    if (frames > 0x57e40) {
                        frames = 0x57e40;
                    }
                } else {
                    frames = 0x57e40;
                }
            }
            MaybeConvertElapsedTime(&finishTime->mMinute, &finishTime->mSecond, &finishTime->mMillisecond, frameFraction,
                            frames);
            SubtractDroppedFromRank(kartIndex);
            RegisterNewRacer(raceProgressKart, finished);
        }
    }
    g_GlobalMV->mHeader.mFinishedCount = g_GlobalCO->mKartCount;
}

void RaceModeMissionRun_SomeFn(void) {
    u16 kartIndex;
    RaceProgressKart *raceProgressKart;
    EntryKartCounters *entryKartCounters;
    s32 status;
    BOOL ended;
    u32 succeeded;
    u8 *missionSettings;
    MinuteSecondMillisecondTime *finishTime;
    u32 frames;
    for (kartIndex = 0; kartIndex < (u32) g_GlobalCO->mKartCount; kartIndex++) {
        status = g_GlobalMV->mKarts[kartIndex].mStatus;
        ended = FALSE;
        switch (status) {
            case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
            case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
            case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                ended = TRUE;
                break;
        }
        if (ended == FALSE) {
            raceProgressKart = &g_GlobalMV->mKarts[kartIndex];
            finishTime = &raceProgressKart->mLapTimes[5];
            frames = g_GlobalMV->mHeader.mElapsedFrames;
            if (g_GlobalCO->mMode == MODE_GRAND_PRIX) {
                if (raceProgressKart->mRaceProgress > 0) {
                    frames = (u32) (frames * FX_Inv(raceProgressKart->mRaceProgress)) >> 12;
                    if (frames > 0x57e40) {
                        frames = 0x57e40;
                    }
                } else {
                    frames = 0x57e40;
                }
            }
            MaybeConvertElapsedTime(&finishTime->mMinute, &finishTime->mSecond, &finishTime->mMillisecond, 0, frames);
            succeeded = 1;
            missionSettings = (u8 *) &g_GlobalCO->mMissionTimeLimitFrameCount;
            entryKartCounters = GetGlobalRK();
            switch (missionSettings[7]) {
                case MISSION_KIND_LAPS_MINI_TURBO_COUNT:
                    if (missionSettings[0xf] > (u32) entryKartCounters->mMiniTurboCount) {
                        succeeded = 0;
                    }
                    break;
                case MISSION_KIND_LAPS_FIRST_PLACE:
                    if (((u32) (raceProgressKart->mRankIndexRequestBits << 28) >> 28) != 1) {
                        succeeded = 0;
                    }
                    break;
            }
            if (succeeded != 0) {
                u32 storedKartIndex = (u32) (raceProgressKart->mRankIndexRequestBits << 24) >> 28;
                if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
                    FinishRaceProgressKartWithEndKind(storedKartIndex, RACE_END_KIND_GOAL);
                }
            } else {
                FinishRaceProgressKartWithEndKind((u32) (raceProgressKart->mRankIndexRequestBits << 24) >> 28,
                                                  RACE_END_KIND_FAILED);
            }
        }
    }
    g_GlobalMV->mHeader.mFinishedCount = g_GlobalCO->mKartCount;
}

void RegisterNewRacer(RaceProgressKart *raceProgressKart, s32 finished) {
    MinuteSecondMillisecondTime *finishTime;
    s32 inputSlotIndex;
    s32 mode;
    s16 score;
    inputSlotIndex =
        g_GlobalCO->mCurrentEntries[(u32) (raceProgressKart->mRankIndexRequestBits << 24) >> 28].mPlayer.mIndex;
    if (finished != 0) {
        raceProgressKart->mStatus = RACE_PROGRESS_KART_STATUS_GOAL_REACHED;
    } else {
        raceProgressKart->mStatus = RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL;
    }
    switch (g_GlobalCYT[inputSlotIndex].mSourceKind) {
        case INPUT_SOURCE_PAD_RECORDED:
            FinishKeyRecording(&g_GlobalCYT[inputSlotIndex].mKeyRecording);
            break;
        case INPUT_SOURCE_KEY_RECORDING_PLAYBACK:
            FinishReadingKeyRecording(&g_GlobalCYT[inputSlotIndex].mKeyRecording);
            break;
    }
    raceProgressKart->mFlags |= RACE_PROGRESS_KART_FLAG_FINISH_JUST_HAPPENED;
    if ((raceProgressKart->mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) != 0 &&
        (raceProgressKart->mFlags & RACE_PROGRESS_KART_FLAG_GOAL_WAIT) == 0) {
        RefreshRaceNewRecordTaRecordFlags();
    }
    finishTime = &raceProgressKart->mLapTimes[5];
    if (finished != 0) {
        raceProgressKart->mFinishTimeMs =
            (finishTime->mMinute * 0x3c + finishTime->mSecond) * 1000 + finishTime->mMillisecond;
    } else if (g_GlobalCO->mMode != MODE_WIFI) {
        raceProgressKart->mFinishTimeMs = RACE_FINISH_TIME_NONE_MS;
    }
    mode = g_GlobalCO->mMode;
    if (mode == MODE_GRAND_PRIX || mode == MODE_MISSION_RUN) {
        if ((raceProgressKart->mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) != 0) {
            raceProgressKart->mScore =
                MaybeComputeRacerScore((u32) (raceProgressKart->mRankIndexRequestBits << 24) >> 28);
            score = raceProgressKart->mScore;
            if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
                g_GlobalLU->mScore = score;
            } else {
                g_GlobalLU->mScore += score;
            }
        }
    }
    g_GlobalMV->mHeader.mFinishedCount++;
}

void FinishRaceProgressKartWithEndKind(s32 kartIndex, s32 endKind) {
    Kart *kart;
    MinuteSecondMillisecondTime finishTime;
    s32 status;
    BOOL ended;
    RaceProgressKart *raceProgressKart;
    raceProgressKart = &g_GlobalMV->mKarts[kartIndex];
    status = raceProgressKart->mStatus;
    ended = FALSE;
    switch (status) {
        case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
        case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
        case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
            ended = TRUE;
            break;
    }
    if (ended != FALSE) {
        return;
    }
    if ((raceProgressKart->mFlags & RACE_PROGRESS_KART_FLAG_GOAL_WAIT) != 0) {
        return;
    }
    if ((raceProgressKart->mFlags & RACE_PROGRESS_KART_FLAG_FAILURE_WAIT) != 0) {
        return;
    }
    kart = GetRacerMQEntry(kartIndex);
    raceProgressKart = &g_GlobalMV->mKarts[kartIndex];
    g_GlobalMV->mHeader.mClockEnabled = 0;
    MaybeConvertElapsedTime(&finishTime.mMinute, &finishTime.mSecond, &finishTime.mMillisecond, 0,
                    g_GlobalMV->mHeader.mElapsedFrames);
    raceProgressKart->mLapTimes[5] = finishTime;
    if ((raceProgressKart->mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) != 0) {
        g_GlobalMV->mEntryEndKind = endKind;
        kart->mEntryFlags |= KART_ENTRY_OUT_OF_ROUND;
        kart->mDriveFlags &= ~KART_DRIVE_RESPAWN_LANDING;
        if (endKind == RACE_END_KIND_GOAL) {
            raceProgressKart->mFlags |= RACE_PROGRESS_KART_FLAG_GOAL_WAIT;
            g_GlobalMV->mFramesSinceFinish = 0;
            if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
                RaceModeBattle_OrMissionRun_SomeFn();
            }
        } else {
            raceProgressKart->mFlags |= RACE_PROGRESS_KART_FLAG_FAILURE_WAIT;
            g_GlobalMV->mFramesSinceFailure = 0;
            if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
                ((void (*)(s32)) EliminateKartAndCheckWinner)(kartIndex);
            }
        }
    }
    RegisterNewRacer(raceProgressKart, endKind == RACE_END_KIND_GOAL);
    if (IsRaceEndConditionMet() == 0) {
        return;
    }
    switch (g_GlobalCO->mMode) {
        case MODE_BATTLE:
            RaceModeBattle_OrMissionRun_SomeFn();
            return;
        case MODE_MISSION_RUN:
            RaceModeMissionRun_SomeFn();
            return;
        case MODE_WIFI:
            RaceModeNet_SomeFn();
            return;
        default:
            RaceModeDefault_SomeFn();
            return;
        case MODE_TIME_ATTACK:
            return;
    }
}

void FinishMissionRunKartAtGoal(u16 kartIndex) {
    if (g_GlobalCO->mMode != MODE_MISSION_RUN) {
        return;
    }
    FinishRaceProgressKartWithEndKind(kartIndex, RACE_END_KIND_GOAL);
}
