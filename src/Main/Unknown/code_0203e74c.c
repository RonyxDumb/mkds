#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203f2b4.h"
#include "Main/Unknown/code_0203f280.h"
#include "Main/Unknown/code_0203f320.h"
#include "Main/Unknown/code_0203f334.h"
#include "Main/Unknown/code_0204a904.h"
#include "Main/Unknown/code_0204a928.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_02077bc0.h"

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
    raceSetup = gRaceSetup;
    switch (raceSetup->mMode) {
        case MODE_GRAND_PRIX:
            endConditionMet = TRUE;
            for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
                flag = FALSE;
                value = raceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
                if ((u32) value <= 3 && ((1 << value) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                    flag = TRUE;
                }
                if (flag != FALSE) {
                    value = gRaceProgress->mKarts[kartIndex].mStatus;
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
            raceProgress = gRaceProgress;
            if (raceProgress->mHeader.mFinishedCount <
                (s32) RaceProgressGetCurrentKartCount() - (raceProgress->mHeader.mRemovedCount + 1)) {
                for (kartIndex = 0; kartIndex < RaceProgressGetCurrentKartCount(); kartIndex++) {
                    if (IsKartNonCpu(kartIndex) != FALSE && IsKartEnded(kartIndex) == 0) {
                        if (IsRaceProgressKartRemoved(kartIndex) == FALSE) {
                            endConditionMet = FALSE;
                            break;
                        }
                    }
                }
            }
            if (endConditionMet == FALSE && RaceProgressGetCurrentRuleKind() == 1) {
                if (IsKartEnded(GetLeadingKart()) != 0) {
                    endConditionMet = TRUE;
                }
            }
            break;
        case 5:
            participantKart = gParticipantKartMap->mKartOfParticipant[GetOwnParticipantIndex()];
            if (participantKart < 0) {
                endConditionMet = FALSE;
            } else {
                kartCount = gRaceSetup->mKartCount;
                raceProgress = gRaceProgress;
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
            switch (gRaceProgress->mKarts[0].mStatus) {
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
                raceSetup = gRaceSetup;
            }
            break;
        case MODE_MISSION_RUN:
            endConditionMet = FALSE;
            if (raceSetup->mMissionKind == 6 && gRaceProgress->mHeader.mFinishedCount != 0) {
                endConditionMet = TRUE;
            }
            break;
        default:
            endConditionMet = FALSE;
            break;
    }
    return endConditionMet;
}

void FinishRemainingRaceProgressKarts(void) {
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
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        status = gRaceProgress->mKarts[kartIndex].mStatus;
        ended = FALSE;
        switch (status) {
            case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
            case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
            case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                ended = TRUE;
                break;
        }
        if (ended == FALSE && status != RACE_PROGRESS_KART_STATUS_REMOVED) {
            raceProgressKart = &gRaceProgress->mKarts[kartIndex];
            finishTime = &raceProgressKart->mLapTimes[5];
            frames = gRaceProgress->mHeader.mElapsedFrames;
            if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
                if (raceProgressKart->mRaceProgress > 0) {
                    frames = (u32) (frames * FX_Inv(raceProgressKart->mRaceProgress)) >> 12;
                    if (frames > 0x57e40) {
                        frames = 0x57e40;
                    }
                } else {
                    frames = 0x57e40;
                }
            }
            ComputeRaceTime(&finishTime->mMinute, &finishTime->mSecond, &finishTime->mMillisecond, frameFraction,
                            frames);
            FinishRaceProgressKart(raceProgressKart, finished);
        }
    }
    gRaceProgress->mHeader.mFinishedCount = gRaceSetup->mKartCount;
}

void FinishRemainingWiFiRaceKarts(void) {
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
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        status = gRaceProgress->mKarts[kartIndex].mStatus;
        ended = FALSE;
        switch (status) {
            case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
            case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
            case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                ended = TRUE;
                break;
        }
        if (ended == FALSE && status != RACE_PROGRESS_KART_STATUS_REMOVED) {
            raceProgressKart = &gRaceProgress->mKarts[kartIndex];
            finishTime = &raceProgressKart->mLapTimes[5];
            frames = gRaceProgress->mHeader.mElapsedFrames;
            if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
                if (raceProgressKart->mRaceProgress > 0) {
                    frames = (u32) (frames * FX_Inv(raceProgressKart->mRaceProgress)) >> 12;
                    if (frames > 0x57e40) {
                        frames = 0x57e40;
                    }
                } else {
                    frames = 0x57e40;
                }
            }
            ComputeRaceTime(&finishTime->mMinute, &finishTime->mSecond, &finishTime->mMillisecond, frameFraction,
                            frames);
            SubtractDroppedFromRank(kartIndex);
            FinishRaceProgressKart(raceProgressKart, finished);
        }
    }
    gRaceProgress->mHeader.mFinishedCount = gRaceSetup->mKartCount;
}

void FinishRemainingMissionRunKarts(void) {
    u16 kartIndex;
    RaceProgressKart *raceProgressKart;
    EntryKartCounters *entryKartCounters;
    s32 status;
    BOOL ended;
    u32 succeeded;
    u8 *missionSettings;
    MinuteSecondMillisecondTime *finishTime;
    u32 frames;
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        status = gRaceProgress->mKarts[kartIndex].mStatus;
        ended = FALSE;
        switch (status) {
            case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
            case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
            case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                ended = TRUE;
                break;
        }
        if (ended == FALSE) {
            raceProgressKart = &gRaceProgress->mKarts[kartIndex];
            finishTime = &raceProgressKart->mLapTimes[5];
            frames = gRaceProgress->mHeader.mElapsedFrames;
            if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
                if (raceProgressKart->mRaceProgress > 0) {
                    frames = (u32) (frames * FX_Inv(raceProgressKart->mRaceProgress)) >> 12;
                    if (frames > 0x57e40) {
                        frames = 0x57e40;
                    }
                } else {
                    frames = 0x57e40;
                }
            }
            ComputeRaceTime(&finishTime->mMinute, &finishTime->mSecond, &finishTime->mMillisecond, 0, frames);
            succeeded = 1;
            missionSettings = (u8 *) &gRaceSetup->mMissionTimeLimitFrameCount;
            entryKartCounters = GetEntryKartCounters();
            switch (missionSettings[7]) {
                case 4:
                    if (missionSettings[0xf] > (u32) entryKartCounters->mMiniTurboCount) {
                        succeeded = 0;
                    }
                    break;
                case 6:
                    if (((u32) (raceProgressKart->mRankIndexRequestBits << 28) >> 28) != 1) {
                        succeeded = 0;
                    }
                    break;
            }
            if (succeeded != 0) {
                u32 storedKartIndex = (u32) (raceProgressKart->mRankIndexRequestBits << 24) >> 28;
                if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                    FinishRaceProgressKartWithEndKind(storedKartIndex, 0);
                }
            } else {
                FinishRaceProgressKartWithEndKind((u32) (raceProgressKart->mRankIndexRequestBits << 24) >> 28, 4);
            }
        }
    }
    gRaceProgress->mHeader.mFinishedCount = gRaceSetup->mKartCount;
}

void FinishRaceProgressKart(RaceProgressKart *raceProgressKart, s32 finished) {
    MinuteSecondMillisecondTime *finishTime;
    s32 inputSlotIndex;
    s32 mode;
    s16 score;
    inputSlotIndex =
        gRaceSetup->mCurrentEntries[(u32) (raceProgressKart->mRankIndexRequestBits << 24) >> 28].mPlayer.mIndex;
    if (finished != 0) {
        raceProgressKart->mStatus = RACE_PROGRESS_KART_STATUS_GOAL_REACHED;
    } else {
        raceProgressKart->mStatus = RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL;
    }
    switch (gInputSlots[inputSlotIndex].mSourceKind) {
        case 2:
            FinishKeyRecording(&gInputSlots[inputSlotIndex].mUnk_28);
            break;
        case 1:
            FinishReadingKeyRecording(&gInputSlots[inputSlotIndex].mUnk_28);
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
    } else if (gRaceSetup->mMode != MODE_WIFI) {
        raceProgressKart->mFinishTimeMs = 0x5b8d80;
    }
    mode = gRaceSetup->mMode;
    if (mode == MODE_GRAND_PRIX || mode == MODE_MISSION_RUN) {
        if ((raceProgressKart->mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) != 0) {
            raceProgressKart->mScore =
                ComputeRaceProgressKartScore((u32) (raceProgressKart->mRankIndexRequestBits << 24) >> 28);
            score = raceProgressKart->mScore;
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                gCupRecords->mScore = score;
            } else {
                gCupRecords->mScore += score;
            }
        }
    }
    gRaceProgress->mHeader.mFinishedCount++;
}

void FinishRaceProgressKartWithEndKind(s32 kartIndex, s32 endKind) {
    Kart *kart;
    MinuteSecondMillisecondTime finishTime;
    s32 status;
    BOOL ended;
    RaceProgressKart *raceProgressKart;
    raceProgressKart = &gRaceProgress->mKarts[kartIndex];
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
    kart = GetKart(kartIndex);
    raceProgressKart = &gRaceProgress->mKarts[kartIndex];
    gRaceProgress->mHeader.mClockEnabled = 0;
    ComputeRaceTime(&finishTime.mMinute, &finishTime.mSecond, &finishTime.mMillisecond, 0,
                    gRaceProgress->mHeader.mElapsedFrames);
    raceProgressKart->mLapTimes[5] = finishTime;
    if ((raceProgressKart->mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) != 0) {
        gRaceProgress->mEntryEndKind = endKind;
        kart->mUnk_7c |= 0x20000000;
        kart->mUnk_48 &= ~0x2000000;
        if (endKind == 0) {
            raceProgressKart->mFlags |= RACE_PROGRESS_KART_FLAG_GOAL_WAIT;
            gRaceProgress->mFramesSinceFinish = 0;
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                EliminateKartsUntilWinnerDecided();
            }
        } else {
            raceProgressKart->mFlags |= RACE_PROGRESS_KART_FLAG_FAILURE_WAIT;
            gRaceProgress->mFramesSinceFailure = 0;
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                ((void (*)(s32)) EliminateKartAndCheckWinner)(kartIndex);
            }
        }
    }
    FinishRaceProgressKart(raceProgressKart, endKind == 0);
    if (IsRaceEndConditionMet() == 0) {
        return;
    }
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            EliminateKartsUntilWinnerDecided();
            return;
        case MODE_MISSION_RUN:
            FinishRemainingMissionRunKarts();
            return;
        case MODE_WIFI:
            FinishRemainingWiFiRaceKarts();
            return;
        default:
            FinishRemainingRaceProgressKarts();
            return;
        case MODE_TIME_ATTACK:
            return;
    }
}

void FinishMissionRunKartWithEndKind0(u16 kartIndex) {
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        return;
    }
    FinishRaceProgressKartWithEndKind(kartIndex, 0);
}
