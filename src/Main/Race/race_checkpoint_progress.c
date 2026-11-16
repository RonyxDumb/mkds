#include "Main/Race/race_checkpoint_progress.h"
#include "Main/Race/race_end_condition.h"
#include "Main/Race/race_score.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "sound_archive_load_result.h"
#include "fixed_vector_math.h"
#include "Main/Net/wifi_race_sync_finish.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Kart/karts.h"
#include "Main/Sound/sound_system.h"
#include "Main/Sound/sound_mode.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

void UpdateRaceClock(void) {
    RaceProgress *raceProgress;
    s32 frameFractionOrTimeUp;
    RaceProgress *raceProgressForClock;
    u32 elapsedFrames;
    u32 frameLimit;
    u32 timeLimitFrames;
    BOOL hasTimeLimit;
    BOOL flag;
    s8 ownKartIndex;
    u16 kartIndex;
    RandomState64 *random;
    u16 *clock;
    u32 lapFrames;

    frameFractionOrTimeUp = 0;
    raceProgress = gRaceProgress;
    raceProgressForClock = raceProgress;
    if (raceProgress->mHeader.mClockEnabled != 0) {
        timeLimitFrames = raceProgress->mTimeLimitFrameCount;
        frameLimit = 0x57e40;
        hasTimeLimit = FALSE;
        elapsedFrames = raceProgress->mHeader.mElapsedFrames;
        if (timeLimitFrames != 0) {
            frameLimit = timeLimitFrames;
            hasTimeLimit = TRUE;
        }
        if (gRaceSetup->mMode == MODE_WIFI && elapsedFrames > 0x4650) {
            ownKartIndex = gParticipantKartMap->mKartOfParticipant[DWC_GetMyAID()];
            if (ownKartIndex >= 0) {
                flag = FALSE;
                switch (gRaceProgress->mKarts[(u8) ownKartIndex].mStatus) {
                    case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
                    case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
                    case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                        flag = TRUE;
                        break;
                }
                if (flag == FALSE) {
                    FinishRaceProgressKart(&gRaceProgress->mKarts[ownKartIndex], 0);
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
                    SetWiFiRaceSyncFinishRecorded();
                }
            }
        }
        if (elapsedFrames <= frameLimit) {
            elapsedFrames++;
        } else if (hasTimeLimit != FALSE) {
            frameFractionOrTimeUp = 1;
        }
        raceProgress->mHeader.mElapsedFrames = elapsedFrames;
        for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
            lapFrames = gRaceProgress->mKarts[kartIndex].mLapFrames;
            if (lapFrames <= 0x57e40) {
                lapFrames++;
            }
            gRaceProgress->mKarts[kartIndex].mLapFrames = lapFrames;
        }
        if (frameFractionOrTimeUp != 0) {
            switch (gRaceSetup->mMode) {
                case MODE_MISSION_RUN:
                    FinishRaceProgressKartWithEndKind((u16) gRaceSetup->mEntryIndex, RACE_END_KIND_TIME_UP);
                    flag = gSoundModeHolder.mMode == SCENE_SOUND_MODE_PLAYING ||
                           gSoundModeHolder.mMode == SCENE_SOUND_MODE_MAIN_SEQUENCE_ONLY;
                    if (flag) {
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x4a);
                    }
                    break;
                case MODE_BATTLE:
                    if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
                        gRaceProgress->mTimeLimitFrameCount = AdvanceShineBattleTimeLimit() * 0x3c;
                        raceProgress->mHeader.mElapsedFrames = 0;
                    }
                    break;
            }
        }
        raceProgressForClock = gRaceProgress;
        random = &raceProgressForClock->mRandom;
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        frameFractionOrTimeUp = -(s16) (u16) (random->mValue >> 32 >> 20);
    }
    clock = &raceProgressForClock->mHeader.mClockMillisecond;
    ComputeRaceTime((u8 *) clock + 2, (u8 *) clock + 3, clock, frameFractionOrTimeUp, raceProgress->mHeader.mElapsedFrames);
}

BOOL IsPointBetweenCheckpointLines(const Vec3 *pos, const CourseMapCheckpoint *fromCheckpoint,
                                   const CourseMapCheckpoint *toCheckpoint) {
    volatile IntPair posPair;
    s32 edgeX;

    posPair.mFirst = pos->x;
    posPair.mSecond = pos->z;
    if (MUL_FIXED12_ROUNDED((fromCheckpoint->mPointAZ - toCheckpoint->mPointAZ) >> 4,
                            (pos->x - toCheckpoint->mPointAX) >> 4) -
            MUL_FIXED12_ROUNDED((fromCheckpoint->mPointAX - toCheckpoint->mPointAX) >> 4,
                                (pos->z - toCheckpoint->mPointAZ) >> 4) <
        0) {
        return FALSE;
    }
    edgeX = (toCheckpoint->mPointBX - fromCheckpoint->mPointBX) >> 4;
    if (MUL_FIXED12_ROUNDED((toCheckpoint->mPointBZ - fromCheckpoint->mPointBZ) >> 4,
                            (pos->x - fromCheckpoint->mPointBX) >> 4) -
            MUL_FIXED12_ROUNDED(edgeX, (pos->z - fromCheckpoint->mPointBZ) >> 4) >=
        0) {
        return TRUE;
    }
    return FALSE;
}

s32 ComputeProgressBetweenCheckpoints(const Vec3 *pos, u16 fromIndex, u16 toIndex) {
    CourseMapCheckpoint *fromCheckpoint;
    CourseMapCheckpoint *toCheckpoint;
    IntPair pairs[3];
    s64 numerator;
    s64 denominator;

    fromCheckpoint = &gCourseMap->mCheckpoints[fromIndex];
    toCheckpoint = &gCourseMap->mCheckpoints[toIndex];
    if (IsPointBetweenCheckpointLines(pos, fromCheckpoint, toCheckpoint) == FALSE) {
        return -0x1000;
    }
    pairs[0].mFirst = pos->x - fromCheckpoint->mPointBX;
    pairs[0].mSecond = pos->z - fromCheckpoint->mPointBZ;
    pairs[1].mFirst = pos->x - toCheckpoint->mPointAX;
    pairs[1].mSecond = pos->z - toCheckpoint->mPointAZ;
    pairs[2].mFirst = -toCheckpoint->mDirection.mFirst;
    pairs[2].mSecond = -toCheckpoint->mDirection.mSecond;
    numerator = ComputeDotOfPairsRoundedS64(&pairs[0], &fromCheckpoint->mDirection);
    denominator = numerator + ComputeDotOfPairsRoundedS64(&pairs[1], &pairs[2]);
    if (numerator > 0x7fffffff || denominator > 0x7fffffff || numerator < -0x80000000LL ||
        denominator < -0x80000000LL) {
        numerator >>= 10;
        denominator >>= 10;
    }
    return FX_Div(numerator, denominator);
}

BOOL TryGetKartCheckpointProgress(RaceProgressKart *raceProgressKart, s32 *progressOut, Vec3 *pos, u16 routeIndex,
                                  u16 checkpointIndex) {
    BOOL found;
    u32 testedBit;
    s32 testedWord;
    s16 forwardLink;
    s32 linkIndex;
    s8 nextRoute;
    CourseMapRoute *route;
    s32 testedBits;

    testedWord = checkpointIndex >> 5;
    testedBit = 1 << (checkpointIndex & 0x1f);
    found = FALSE;
    forwardLink = gCourseMap->mCheckpoints[checkpointIndex].mForwardLink;
    testedBits = raceProgressKart->mCheckpointTestedBits[testedWord];
    if ((testedBits & testedBit) != 0) {
        return FALSE;
    }
    if (forwardLink != COURSE_MAP_CHECKPOINT_NO_LINK) {
        route = &gCourseMap->mCheckpointRoutes[routeIndex];
        for (linkIndex = 0; linkIndex < 3; linkIndex++) {
            nextRoute = (route->mNextRoutes)[linkIndex];
            if (nextRoute != COURSE_MAP_ROUTE_NONE_S8) {
                *progressOut =
                    ComputeProgressBetweenCheckpoints(pos, checkpointIndex, GetCheckpointRoute(nextRoute)->mFirstEntry);
                if (*progressOut >= -2 && *progressOut <= 0x1002) {
                    if ((gCourseMap->mCheckpoints[checkpointIndex].mFlags & COURSE_MAP_CHECKPOINT_FLAG_STAGGER) != 0) {
                        if (gRaceSetup->mMode == MODE_WIFI) {
                            *progressOut = 0x1000 - (DWC_GetMyAID() + 1) * 0x190;
                        } else {
                            *progressOut =
                                0x1000 - ((u32) (raceProgressKart->mRankIndexRequestBits << 28) >> 28) * 0x190;
                        }
                    }
                    found = TRUE;
                    break;
                }
            }
        }
    } else {
        *progressOut = ComputeProgressBetweenCheckpoints(pos, checkpointIndex, checkpointIndex + 1);
        if (*progressOut >= -2 && *progressOut <= 0x1002) {
            if ((gCourseMap->mCheckpoints[checkpointIndex].mFlags & COURSE_MAP_CHECKPOINT_FLAG_STAGGER) != 0) {
                *progressOut = 0x1000 - ((u32) (raceProgressKart->mRankIndexRequestBits << 28) >> 28) * 0x190;
            }
            if (*progressOut < 0) {
                *progressOut = 0;
            }
            if (*progressOut > 0x1000) {
                *progressOut = 0x1000;
            }
            found = TRUE;
        }
    }
    raceProgressKart->mCheckpointTestedBits[testedWord] |= testedBit;
    return found;
}

s16 FindKartCheckpointForward(RaceProgressKart *raceProgressKart, s32 *progressOut, Vec3 *pos, u16 routeIndex,
                              u16 checkpointIndex, s32 depth) {
    s16 forwardLink;
    s8 nextRoute;
    s32 linkIndex;
    s16 found;
    CourseMapRoute *route;

    forwardLink = gCourseMap->mCheckpoints[checkpointIndex].mForwardLink;
    if (TryGetKartCheckpointProgress(raceProgressKart, progressOut, pos, routeIndex, checkpointIndex) != 0) {
        return checkpointIndex;
    }
    if (depth == 0) {
        return -1;
    }
    if (forwardLink != COURSE_MAP_CHECKPOINT_NO_LINK) {
        route = &gCourseMap->mCheckpointRoutes[routeIndex];
        found = -1;
        for (linkIndex = 0; linkIndex < 3; linkIndex++) {
            nextRoute = (route->mNextRoutes)[linkIndex];
            if (nextRoute != COURSE_MAP_ROUTE_NONE_S8) {
                found = FindKartCheckpointForward(raceProgressKart, progressOut, pos, nextRoute,
                                                  GetCheckpointRoute(nextRoute)->mFirstEntry, depth - 1);
                if (found != -1) {
                    return found;
                }
            }
        }
        return found;
    }
    return FindKartCheckpointForward(raceProgressKart, progressOut, pos, routeIndex, checkpointIndex + 1, depth - 1);
}

s16 FindKartCheckpointBackward(RaceProgressKart *raceProgressKart, s32 *progressOut, Vec3 *pos, u16 routeIndex,
                               u16 checkpointIndex, s32 depth) {
    s16 backwardLink;
    s8 previousRoute;
    s32 linkIndex;
    s16 found;
    CourseMapRoute *route;

    backwardLink = gCourseMap->mCheckpoints[checkpointIndex].mBackwardLink;
    if (TryGetKartCheckpointProgress(raceProgressKart, progressOut, pos, routeIndex, checkpointIndex) != 0) {
        return checkpointIndex;
    }
    if (depth == 0) {
        return -1;
    }
    if (backwardLink != COURSE_MAP_CHECKPOINT_NO_LINK) {
        route = &gCourseMap->mCheckpointRoutes[routeIndex];
        found = -1;
        for (linkIndex = 0; linkIndex < 3; linkIndex++) {
            previousRoute = route->mPreviousRoutes[linkIndex];
            if (previousRoute != COURSE_MAP_ROUTE_NONE_S8) {
                found = FindKartCheckpointBackward(raceProgressKart, progressOut, pos, previousRoute,
                                                   GetCheckpointRoute(previousRoute)->mFirstEntry +
                                                       GetCheckpointRoute(previousRoute)->mEntryCount - 1,
                                                   depth - 1);
                if (found != -1) {
                    return found;
                }
            }
        }
        return found;
    }
    return FindKartCheckpointBackward(raceProgressKart, progressOut, pos, routeIndex, checkpointIndex - 1, depth - 1);
}

void ComputeRaceTime(u8 *minuteOut, u8 *secondOut, u16 *millisecondOut, s32 frameFraction, u32 frames) {
    RaceProgress *raceProgress;
    s8 minutes;
    s8 seconds;
    s16 milliseconds;
    s32 frameScaled;
    s32 secondsScaled;
    s32 totalSeconds;
    s32 fractionSecondsScaled;

    raceProgress = gRaceProgress;
    if (raceProgress->mTimeCountsDown != FALSE) {
        if (raceProgress->mTimeLimitFrameCount > frames) {
            frames = raceProgress->mTimeLimitFrameCount - frames;
        } else {
            frames = 0;
        }
    }
    if (frames >= 0x57e40) {
        frames = 0x57e3f;
        frameFraction = 0x1000;
    }
    frameScaled = TO_FIXED12(frames);
    secondsScaled = frameScaled / 60;
    totalSeconds = FROM_FIXED12(secondsScaled);
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
    milliseconds = (secondsScaled & FIXED12_FRACTION_MASK) * 1000 >> 12;
    if (frameFraction != 0) {
        fractionSecondsScaled = MUL_FIXED12_ROUNDED(0x44, frameFraction);
        milliseconds += fractionSecondsScaled * 1000 >> 12;
        if (milliseconds < 0) {
            milliseconds += 1000;
            seconds--;
        } else if (milliseconds >= 1000) {
            milliseconds -= 1000;
            seconds++;
        }
        if (seconds < 0) {
            seconds += 60;
            minutes--;
        } else if (seconds >= 60) {
            seconds -= 60;
            minutes++;
        }
        if (minutes < 0) {
            minutes = 0;
            seconds = 0;
            milliseconds = 0;
        } else if (minutes > 99) {
            milliseconds = 999;
            minutes = 99;
            seconds = 59;
        }
    }
    *minuteOut = minutes;
    *secondOut = seconds;
    *millisecondOut = milliseconds;
}

void AddLapTimes(const MinuteSecondMillisecondTime *augend, const MinuteSecondMillisecondTime *addend,
                 MinuteSecondMillisecondTime *result) {
    s16 minutes;
    s16 milliseconds;
    s16 seconds;

    minutes = augend->mMinute + addend->mMinute;
    milliseconds = augend->mMillisecond + addend->mMillisecond;
    seconds = augend->mSecond + addend->mSecond;
    if (milliseconds > 999) {
        milliseconds -= 1000;
        seconds++;
    }
    if (seconds > 59) {
        seconds -= 60;
        minutes++;
    }
    if (minutes >= 100) {
        minutes = 99;
        milliseconds = 999;
        seconds = 59;
    }
    result->mMinute = minutes;
    result->mSecond = seconds;
    result->mMillisecond = milliseconds;
}

void StoreRaceProgressKartLapTime(RaceProgressKart *raceProgressKart, s32 pastFinalLap) {
    Vec3 kartPos;
    Vec3 kartPrevPos;
    Vec3 probePos;
    Vec3 step;
    MinuteSecondMillisecondTime *totalTime;
    u8 lapIndex;
    s32 stepCount;
    MinuteSecondMillisecondTime *lapTimes;
    s32 progress;
    u16 checkpointIndex;
    s16 forwardLink;

    forwardLink = gCourseMap->mCheckpoints->mForwardLink;
    lapTimes = raceProgressKart->mLapTimes;
    stepCount = 0;
    if (raceProgressKart->mLap <= 1) {
        return;
    }
    GetKartPos(&kartPos, (u32) (raceProgressKart->mRankIndexRequestBits << 24) >> 28);
    GetKartPrevPos(&kartPrevPos, (u32) (raceProgressKart->mRankIndexRequestBits << 24) >> 28);
    VEC_Subtract(&kartPos, &kartPrevPos, &step);
    step.x = MUL_FIXED12_NO_ROUND(step.x, -240);
    step.y = MUL_FIXED12_NO_ROUND(step.y, -240);
    step.z = MUL_FIXED12_NO_ROUND(step.z, -240);
    probePos = kartPos;
    if (forwardLink == COURSE_MAP_CHECKPOINT_NO_LINK) {
        forwardLink = 1;
    }
    checkpointIndex = forwardLink;
    do {
        progress = ComputeProgressBetweenCheckpoints(&probePos, 0, checkpointIndex);
        VEC_Add(&probePos, &step, &probePos);
        stepCount++;
    } while (progress > 0 && stepCount < 0x11);
    ComputeRaceTime(&lapTimes[raceProgressKart->mLap - 2].mMinute, &lapTimes[raceProgressKart->mLap - 2].mSecond,
                    &lapTimes[raceProgressKart->mLap - 2].mMillisecond, -stepCount * 0xf0,
                    raceProgressKart->mLapFrames);
    raceProgressKart->mLapFrames = 0;
    totalTime = &lapTimes[5];
    totalTime->mMinute = 0;
    totalTime->mSecond = 0;
    lapTimes[5].mMillisecond = 0;
    for (lapIndex = 0; lapIndex < raceProgressKart->mLap - 1; lapIndex++) {
        AddLapTimes(&lapTimes[lapIndex], totalTime, totalTime);
    }
    if (pastFinalLap != 0) {
        return;
    }
    raceProgressKart->mFinishTimeMs = (totalTime->mMinute * 60 + totalTime->mSecond) * 1000 + totalTime->mMillisecond;
}
