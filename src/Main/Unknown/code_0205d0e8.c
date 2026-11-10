#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

// Zeroes the ten-byte records of the eight karts in the four courses and the team points and win counts.
void ResetCupRecords(void) {
    CupRecords *cupRecords;
    s32 course;
    s32 kart;
    s32 team;
    KartCourseResult *record;
    BOOL x;
    CourseTeamResult *teamRecord;

    cupRecords = gCupRecords;
    for (course = 0; course < 4; course++) {
        for (kart = 0; kart < 8; kart++) {
            record = &cupRecords->mKartResults[course][kart];
            record->mRank = 0;
            record->mPoints = 0;
            record->mTotalPoints = 0;
            record->mWinCount = 0;
            record->mCupRank = 0;
            record->mFinishTime.mMinute = 0;
            record->mFinishTime.mSecond = 0;
            record->mFinishTime.mMillisecond = 0;
        }
        for (team = 0; team < 2; team++) {
            teamRecord = &cupRecords->mTeamResults[course].mTeams[team];
            teamRecord->mTotalPoints = 0;
            teamRecord->mWinCount = 0;
        }
    }
    x = FALSE;
    if ((gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode) != 0 && gConnectionWork->mState != 13) {
        x = TRUE;
    }
    if (x != FALSE) {
        gCupRecords->mUnk_164_0 = 1;
    } else {
        gCupRecords->mUnk_164_0 = 0;
    }
    cupRecords->mScore = 0;
}

u8 GetCourseIndexInCup(void) {
    return (gRaceSetup->mCourseNumber - 1) % 4;
}

// Stores rank and points; the total adds the previous course's (max 9999), rank 1 raises the win count (max 99).
void SetKartCourseResult(u32 kart, s32 rank, u32 points) {
    RaceSetup *raceSetup;
    s8 i, j;
    s32 course, k, mode;
    u16 previousTotal;
    u8 winCount;
    KartCourseResult *record;

    raceSetup = gRaceSetup;
    course = (raceSetup->mCourseNumber - 1) % 4;
    mode = raceSetup->mMode;
    k = (u8) course - 1;
    i = k;
    if (mode == MODE_BATTLE || mode == MODE_VS || mode == 5) {
        if (i < 0) {
            i = i + 4;
        }
    }
    if (i < 0) {
        previousTotal = 0;
    } else {
        previousTotal = gCupRecords->mKartResults[i][(u8) kart].mTotalPoints;
    }
    j = k;
    if (mode == MODE_BATTLE || mode == MODE_VS || mode == 5) {
        if (j < 0) {
            j = j + 4;
        }
    }
    if (j < 0) {
        winCount = 0;
    } else {
        winCount = gCupRecords->mKartResults[j][(u8) kart].mWinCount;
    }
    record = &gCupRecords->mKartResults[(u8) course][(u8) kart];
    record->mRank = rank;
    record->mPoints = points;
    record->mTotalPoints = previousTotal + points;
    if (record->mTotalPoints > 9999) {
        record->mTotalPoints = 9999;
    }
    if (rank == 1) {
        winCount = winCount + 1;
    }
    if (winCount > 99) {
        winCount = 99;
    }
    record->mWinCount = winCount;
}

void ClearKartCourseTotalPoints(u32 kart) {
    gCupRecords->mKartResults[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)][(u8) kart].mTotalPoints = 0;
}

void SetBattleKartCourseResult(u32 kart, s32 isAlive) {
    RaceSetup *raceSetup;
    s8 previousCourse;
    s32 mode, course, courseMinusOne;
    u8 winCount;
    KartCourseResult *record;

    raceSetup = gRaceSetup;
    course = (raceSetup->mCourseNumber - 1) % 4;
    mode = raceSetup->mMode;
    courseMinusOne = (u8) course - 1;
    previousCourse = courseMinusOne;
    if (mode == MODE_BATTLE || mode == MODE_VS || mode == 5) {
        if (previousCourse < 0) {
            previousCourse = previousCourse + 4;
        }
    }
    if (previousCourse < 0) {
        winCount = 0;
    } else {
        winCount = gCupRecords->mKartResults[previousCourse][(u8) kart].mWinCount;
    }
    record = &gCupRecords->mKartResults[(u8) course][(u8) kart];
    record->mPoints = 0;
    record->mRank = 1;
    record->mTotalPoints = 0;
    if (isAlive != 0) {
        winCount = winCount + 1;
    }
    if (winCount > 99) {
        winCount = 99;
    }
    record->mWinCount = winCount;
}

void SetKartCourseFinishTime(u32 kart, MinuteSecondMillisecondTime *finishTime) {
    KartCourseResult *record;
    MinuteSecondMillisecondTime *recordTime;

    record = &gCupRecords->mKartResults[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)][(u8) kart];
    recordTime = &record->mFinishTime;
    recordTime->mMinute = finishTime->mMinute;
    recordTime->mSecond = finishTime->mSecond;
    recordTime->mMillisecond = finishTime->mMillisecond;
}

void GetKartCourseFinishTime(MinuteSecondMillisecondTime *finishTime, u32 kart, u32 course) {
    KartCourseResult *record;
    MinuteSecondMillisecondTime *recordTime;

    record = &gCupRecords->mKartResults[course][(u8) kart];
    recordTime = &record->mFinishTime;
    finishTime->mMinute = recordTime->mMinute;
    finishTime->mSecond = recordTime->mSecond;
    finishTime->mMillisecond = recordTime->mMillisecond;
}

void SetKartCupRank(s32 kart, u8 rank) {
    gCupRecords->mKartResults[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)][(u8) kart].mCupRank = rank;
}

// Flags the team as winning this course and clears the flag of the other team.
void SetCupWinningTeam(s32 team) {
    s32 otherTeam;
    CourseTeamResult *p, *q;

    otherTeam = 0;
    if (team == 0) {
        otherTeam = 1;
    }
    p = gCupRecords->mTeamResults[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)].mTeams;
    p[team].mUnk_03_0 = 1;
    q = gCupRecords->mTeamResults[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)].mTeams;
    q[otherTeam].mUnk_03_0 = 0;
}

// Stores each team's win count (the winning team gains one, max 99) and its karts' total points (max 9999).
void SetTeamWinCountsAndPoints(s32 winningTeam) {
    s32 team;
    u16 kart, points;
    u32 winCount;
    s8 previousCourse;
    CourseTeamResults *courseTeams;
    CourseTeamResult *teamRecord;

    for (team = 0; team < 2; team++) {
        points = 0;
        courseTeams = &gCupRecords->mTeamResults[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)];
        teamRecord = &courseTeams->mTeams[(s32) team];
        previousCourse = (u8) ((gRaceSetup->mCourseNumber - 1) % 4) - 1;
        if (gRaceSetup->mMode == MODE_BATTLE || gRaceSetup->mMode == MODE_VS || gRaceSetup->mMode == 5) {
            if (previousCourse < 0) {
                previousCourse = previousCourse + 4;
            }
        }
        if (previousCourse < 0) {
            winCount = 0;
        } else {
            winCount = gCupRecords->mTeamResults[previousCourse].mTeams[team].mWinCount;
        }
        if (team == winningTeam) {
            winCount = (u8) (winCount + 1);
        }
        if (winCount > 99) {
            winCount = 99;
        }
        teamRecord->mWinCount = winCount;
        for (kart = 0; kart < (u32) gRaceSetup->mKartCount; kart++) {
            if (team == gRaceSetup->mCurrentEntries[kart].mPlayer.mTeamIndex) {
                points =
                    points + gCupRecords->mKartResults[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)][(u8) (s32) (u8) kart]
                                 .mTotalPoints;
            }
        }
        if (points > 9999) {
            points = 9999;
        }
        teamRecord->mTotalPoints = points;
    }
}

// Zero outside Grand Prix, VS and mode 5.
s32 GetKartCupRank(u32 kart) {
    s32 mode;
    KartCourseResult *courseRecords;
    KartCourseResult *record;

    mode = gRaceSetup->mMode;
    if (mode == MODE_GRAND_PRIX || mode == MODE_VS || mode == 5) {
        courseRecords = gCupRecords->mKartResults[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)];
        record = &courseRecords[(u8) kart];
        return record->mCupRank;
    }
    return 0;
}

s32 GetCupWinningTeam(void) {
    s32 team, winningTeam;
    CourseTeamResults *courseTeams;

    winningTeam = -1;
    courseTeams = &gCupRecords->mTeamResults[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)];
    for (team = 0; team < 2; team++) {
        if (courseTeams->mTeams[(u32) team].mUnk_03_0) {
            winningTeam = team;
            break;
        }
    }
    return winningTeam;
}

// 0 for the first course; battle, VS and mode 5 wrap to the fourth course.
u16 GetKartPreviousTotalPoints(u32 kart) {
    s32 mode;
    s8 previousCourse;

    mode = gRaceSetup->mMode;
    previousCourse = (u8) ((gRaceSetup->mCourseNumber - 1) % 4) - 1;
    if (mode == MODE_BATTLE || mode == MODE_VS || mode == 5) {
        if (previousCourse < 0) {
            previousCourse = previousCourse + 4;
        }
    }
    if (previousCourse < 0) {
        return 0;
    }
    return gCupRecords->mKartResults[previousCourse][(u8) kart].mTotalPoints;
}

// 0 for the first course; battle, VS and mode 5 wrap to the fourth course.
u8 GetKartPreviousWinCount(u32 kart) {
    s32 mode;
    s8 previousCourse;

    mode = gRaceSetup->mMode;
    previousCourse = (u8) ((gRaceSetup->mCourseNumber - 1) % 4) - 1;
    if (mode == MODE_BATTLE || mode == MODE_VS || mode == 5) {
        if (previousCourse < 0) {
            previousCourse = previousCourse + 4;
        }
    }
    if (previousCourse < 0) {
        return 0;
    }
    return gCupRecords->mKartResults[previousCourse][(u8) kart].mWinCount;
}

// The previous course's rank in Grand Prix, VS and mode 5 (VS and mode 5 wrap); else the kart count minus the index.
u8 GetKartStartRank(u32 kart) {
    RaceSetup *raceSetup;
    s32 mode;
    s8 previousCourse;
    u8 rank;

    raceSetup = gRaceSetup;
    mode = raceSetup->mMode;
    previousCourse = (u8) ((raceSetup->mCourseNumber - 1) % 4) - 1;
    if (mode == MODE_BATTLE || mode == MODE_VS || mode == 5) {
        if (previousCourse < 0) {
            previousCourse = previousCourse + 4;
        }
    }
    if (mode == MODE_GRAND_PRIX || mode == MODE_VS || mode == 5) {
        if (previousCourse < 0) {
            rank = raceSetup->mKartCount - kart;
        } else {
            rank = gCupRecords->mKartResults[previousCourse][(u8) kart].mRank;
        }
    } else {
        rank = raceSetup->mKartCount - kart;
    }
    if (rank == 0) {
        rank = raceSetup->mKartCount - kart;
    }
    return rank;
}

// 0 to 7 from the Grand Prix score and the entry kart's total points; stored in the Grand Prix record.
s32 ComputeGrandPrixRecordValue(void) {
    RaceSetup *raceSetup;
    CupRecords *cupRecords;
    s32 score, scoreBucket, pointsBucket, bucketSum;
    u16 totalPoints, entryIndex;
    u32 entryKartIndex;

    raceSetup = gRaceSetup;
    cupRecords = gCupRecords;
    entryIndex = raceSetup->mEntryIndex;
    score = cupRecords->mScore;
    entryKartIndex = (u8) entryIndex;
    totalPoints = cupRecords->mKartResults[(u8) ((raceSetup->mCourseNumber - 1) % 4)][(u8) entryKartIndex].mTotalPoints;
    if (score >= 1000) {
        scoreBucket = 0;
    } else if (score >= 700) {
        scoreBucket = 1;
    } else if (score >= 400) {
        scoreBucket = 2;
    } else if (score >= 200) {
        scoreBucket = 3;
    } else if (score >= 0) {
        scoreBucket = 4;
    } else {
        scoreBucket = 5;
    }
    if (totalPoints >= 40) {
        pointsBucket = 0;
    } else if (totalPoints >= 36) {
        pointsBucket = 1;
    } else if (totalPoints >= 30) {
        pointsBucket = 2;
    } else if (totalPoints >= 20) {
        pointsBucket = 3;
    } else {
        pointsBucket = 4;
    }
    bucketSum = scoreBucket + pointsBucket;
    if (bucketSum >= 8) {
        bucketSum = 7;
    }
    return 7 - bucketSum;
}

// 2 to 7 from the Mission Run score; stored in the Mission Run record.
s32 ComputeMissionRecordValue(void) {
    s32 score;

    score = gCupRecords->mScore;
    if (score >= 100) {
        return 7;
    }
    if (score >= 90) {
        return 6;
    }
    if (score >= 70) {
        return 5;
    }
    if (score >= 50) {
        return 4;
    }
    if (score >= 0) {
        return 3;
    }
    return 2;
}

// Copies the records of kart from over those of kart to in all four courses.
void CopyKartCupRecords(u8 from, u8 to) {
    s32 course;

    for (course = 0; course < 4; course++) {
        MI_CpuCopy8(&gCupRecords->mKartResults[course][from], &gCupRecords->mKartResults[course][to], 10);
    }
}
