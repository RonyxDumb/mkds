#include "Main/Save/buddy_record_time.h"
#include "Main/Race/grand_prix_record.h"
#include "Main/Menu/title_scene.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Save/backup_access.h"
#include "Main/Race/cup_records.h"
#include "Main/Save/buddy_records_write.h"
#include "Main/Save/backup_reset.h"
#include "Main/Save/mission_record.h"
#include "Main/Save/buddy_record_reset.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/System/low_byte.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "00/code_021832d8.h"
#include "00/code_0219b580.h"
#include "code_0214d018.h"
#include "Main/Race/race_clock.h"

#pragma opt_rebuildconditionals off

static inline BOOL BuddyRecordIsConnectionActive(void) {
    ConnectionWork *connectionWork;

    connectionWork = gConnectionWork;
    return (connectionWork == NULL ? 0 : connectionWork->mConnectionMode) != 0 && connectionWork->mState != 13;
}

BOOL FormatTimeRecordChars(u8 *charsOut, TimeRecord *timeRecord, s32 courseId) {
    u8 packedBytes[10] = {0};
    u32 value;
    s32 cupCourseIndex;
    u32 characterKartValue;
    u8 bitPosition;
    s32 charIndex;
    u16 charValue;
    u8 bitIndex;
    u32 bitOffset;
    s32 byteIndex;
    u8 startBit;
    s32 xorKey;

    value = timeRecord->mMillisecond + (timeRecord->mSecond * 1000 + timeRecord->mMinute * 60000);
    if (value >= 240000) {
        return 0;
    }
    cupCourseIndex = FindCupCourseIndex(courseId);
    if (cupCourseIndex < 0 || cupCourseIndex >= 32) {
        return 0;
    }
    characterKartValue = timeRecord->mCharacterIndex * 37 + timeRecord->mKartIndex;
    if (characterKartValue >= 0x200) {
        return 0;
    }
    value = ((value & 0x3ffff) << 14) | ((cupCourseIndex & 0x1f) << 9);
    *(u32 *) &packedBytes[0] = value | (characterKartValue & 0x1ff);
    MI_CpuCopy8(&timeRecord->mName, &packedBytes[4], 4);
    *(u16 *) &packedBytes[8] = 0;
    WriteBlockTail(packedBytes, 10, 1);
    xorKey = 0xc3;
    for (byteIndex = 9; byteIndex >= 0; byteIndex--) {
        packedBytes[byteIndex] ^= xorKey;
        xorKey = packedBytes[byteIndex];
    }
    for (charIndex = 0, bitOffset = 0; charIndex < 16; charIndex++) {
        charValue = 0;
        for (bitIndex = 0; bitIndex < 5; bitIndex++) {
            startBit = bitOffset;
            bitPosition = startBit + bitIndex;
            charValue = (u16) (charValue | ((packedBytes[(u8) (bitPosition / 8)] >> (u8) (7 - bitPosition % 8)) & 1))
                        << 1;
        }
        charsOut[charIndex] = GetTimeRecordChar(charValue / 2);
        bitOffset += 5;
    }
    return 1;
}

BOOL FormatFirstCourseTimeRecord(s32 courseId, void *charsOut) {
    TimeRecord timeRecord;
    BOOL hasRecord;

    hasRecord = FALSE;
    if (GetCourseTimeRecord(courseId, 0, &timeRecord) != 0 && timeRecord.mFilled != 0) {
        hasRecord = TRUE;
    }
    if (hasRecord == FALSE) {
        return 0;
    }
    return FormatTimeRecordChars(charsOut, &timeRecord, courseId);
}

BOOL GetMissionRecordValue(s32 row, s32 column, s32 *valueOut) {
    UnpackedMissionRecord missionRecord;
    BOOL isFilled;

    isFilled = FALSE;
    GetMissionRecord(row, column, &missionRecord);
    if (missionRecord.mFilled == 1) {
        isFilled = TRUE;
        *valueOut = missionRecord.mValue;
    }
    return isFilled;
}

BOOL IsKartAppearWithinLimit(KartAppear *kartAppear, u32 characterIndex, u32 kartIndex) {
    u8 limit;
    u8 appearValue;

    limit = GetKartAppearLimit();
    appearValue = kartAppear->mFileData->mValues[kartIndex][characterIndex];
    if (appearValue != 0 && appearValue <= limit) {
        return 1;
    }
    return 0;
}

BOOL IsKartAppearWithinParticipantLimit(KartAppear *kartAppear, u32 characterIndex, u32 kartIndex) {
    u8 limit;
    u8 appearValue;

    if (BuddyRecordIsConnectionActive() != FALSE) {
        limit = gBackupBuffers->mParticipantMinValue;
    } else {
        limit = GetKartAppearLimit();
    }
    appearValue = kartAppear->mFileData->mValues[kartIndex][characterIndex];
    if (appearValue != 0 && appearValue <= limit) {
        return TRUE;
    }
    return FALSE;
}

s32 IsBitSetInAllParticipants(s32 bitIndex) {
    if (BuddyRecordIsConnectionActive() == FALSE) {
        return IsBackupFlagSet(bitIndex);
    }
    return IsBitSetInBytes(bitIndex, gBackupBuffers->mParticipantAndBits);
}

s32 IsBitSetInAnyParticipant(s32 bitIndex) {
    if (BuddyRecordIsConnectionActive() == FALSE) {
        return IsBackupFlagSet(bitIndex);
    }
    return IsBitSetInBytes(bitIndex, gBackupBuffers->mParticipantOrBits);
}

void AddBuddyRecordResult(u32 entryIndex, s32 *date, u32 matchKind, u32 resultKind) {
    RaceSetup *raceSetup;
    BuddyRecord buddyRecord;
    u16 *firstCount;
    u16 *secondCount;
    u8 buddyIndex;
    s32 foundIndex;

    raceSetup = gRaceSetup;
    if (entryIndex == raceSetup->mEntryIndex) {
        return;
    }
    if (raceSetup->mCurrentEntries[entryIndex].mPlayer.mFriendData == 0) {
        return;
    }
    foundIndex = FindBuddyIndexByFriendData(raceSetup->mCurrentEntries[entryIndex].mPlayer.mFriendData);
    if (foundIndex == -1) {
        return;
    }
    buddyIndex = foundIndex;
    GetBuddyRecord(buddyIndex, &buddyRecord);
    if (buddyRecord.mFilled == 0) {
        ResetBuddyRecord(&buddyRecord);
    }
    if (gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mName != NULL) {
        MI_CpuCopy8(gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mName, buddyRecord.mName, 0x14);
    }
    switch (matchKind) {
        case 0:
            firstCount = &buddyRecord.mResultCounts[0][0];
            secondCount = &buddyRecord.mResultCounts[0][1];
            break;
        case 1:
            firstCount = &buddyRecord.mResultCounts[1][0];
            secondCount = &buddyRecord.mResultCounts[1][1];
            break;
        case 2:
            firstCount = &buddyRecord.mResultCounts[2][0];
            secondCount = &buddyRecord.mResultCounts[2][1];
            break;
    }
    switch (resultKind) {
        case 0:
            if (*firstCount < 0xffff) {
                *firstCount = *firstCount + 1;
            }
            break;
        case 1:
            if (*secondCount < 0xffff) {
                *secondCount = *secondCount + 1;
            }
            break;
    }
    buddyRecord.mYear = date[0];
    buddyRecord.mMonth = date[1];
    buddyRecord.mDay = date[2];
    buddyRecord.mFilled = 1;
    SetBuddyRecord(buddyIndex, &buddyRecord);
}

static inline u32 IsKartRankAtMost(u16 kartIndex, u32 ownRank) {
    if (GetKartRank(kartIndex) > ownRank) {
        return 0;
    }
    return 1;
}

void AddVSBuddyRecordResults(void) {
    BOOL countsChanged;
    u32 outcome;
    u16 entryIndex;
    u32 ownRank;
    u32 firstTotal;
    u32 secondTotal;
    s32 teamIndex;
    s32 playerKind;
    s32 date[3];

    countsChanged = FALSE;
    teamIndex = -1;
    if (BuddyRecordIsConnectionActive() == FALSE) {
        return;
    }
    if (gRaceSetup->mEntryIndex == -1) {
        return;
    }
    if (GetRaceProgressKart(gRaceSetup->mEntryIndex)->mStatus == RACE_PROGRESS_KART_STATUS_REMOVED) {
        return;
    }
    if (gRaceProgress->mRaceDone == 0) {
        return;
    }
    GetClockDateOrDefault(date);
    ownRank = GetKartRank((u16) gRaceSetup->mEntryIndex);
    if (gRaceSetup->mUseTeams != 0) {
        teamIndex = GetCurrentEntry(gRaceSetup->mEntryIndex)->mPlayer.mTeamIndex;
    }
    firstTotal = gBackupBuffers->mFirstBlock->mTotals[0];
    secondTotal = gBackupBuffers->mFirstBlock->mTotals[1];
    for (entryIndex = 0; entryIndex < (u32) gRaceSetup->mKartCount; entryIndex++) {
        if (entryIndex == gRaceSetup->mEntryIndex) {
            continue;
        }
        playerKind = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
        if (playerKind == PLAYER_KIND_CPU || playerKind == PLAYER_KIND_NONE || playerKind == PLAYER_KIND_GHOST) {
            continue;
        }
        if (gRaceSetup->mUseTeams != 0) {
            if (teamIndex == gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mTeamIndex) {
                outcome = 2;
            } else {
                switch (gRaceSetup->mRuleKind) {
                    case 0:
                    case 2:
                        outcome = IsKartRankAtMost(entryIndex, ownRank);
                        break;
                    case 1:
                        if (teamIndex == GetCupWinningTeam()) {
                            outcome = 0;
                        } else if (gRaceProgress->mKarts[entryIndex].mStatus == RACE_PROGRESS_KART_STATUS_REMOVED) {
                            outcome = 2;
                        } else {
                            outcome = 1;
                        }
                        break;
                }
            }
        } else {
            outcome = IsKartRankAtMost(entryIndex, ownRank);
        }
        if ((gConnectionWork->mGroupSendMask &
             (1 << gConnectionWork->mParticipantIndexByPos[gConnectionWork->mParticipantIndexByPos[entryIndex]])) ==
            0) {
            AddBuddyRecordResult(entryIndex, date, 0, outcome);
        }
        if (outcome == 0) {
            if (firstTotal < gResultTotalMax) {
                firstTotal++;
                countsChanged = TRUE;
            }
        } else if (outcome == 1) {
            if (secondTotal < gResultTotalMax) {
                secondTotal++;
                countsChanged = TRUE;
            }
        }
    }
    if (countsChanged != FALSE) {
        gBackupBuffers->mFirstBlock->mTotals[0] = firstTotal;
        gBackupBuffers->mFirstBlock->mTotals[1] = secondTotal;
        WriteBuddyRecordsAndFirstBlock();
    } else {
        WriteBackupBuddyRecords();
    }
}

void AddBattleBuddyRecordResults(void) {
    u16 entryIndex;
    u32 firstTotal;
    u32 secondTotal;
    BOOL countsChanged;
    u32 outcome;
    s32 playerKind;
    s32 date[5];

    countsChanged = FALSE;
    if (BuddyRecordIsConnectionActive() == FALSE) {
        return;
    }
    if (gRaceSetup->mEntryIndex == -1) {
        return;
    }
    if (GetRaceProgressKart(gRaceSetup->mEntryIndex)->mStatus == RACE_PROGRESS_KART_STATUS_REMOVED) {
        return;
    }
    if (IsWinnerDecidedAndEndReached() == 0) {
        return;
    }
    GetClockDateOrDefault(date);
    firstTotal = gBackupBuffers->mFirstBlock->mTotals[2];
    secondTotal = gBackupBuffers->mFirstBlock->mTotals[3];
    for (entryIndex = 0; entryIndex < (u32) gRaceSetup->mKartCount; entryIndex++) {
        if (entryIndex == gRaceSetup->mEntryIndex) {
            continue;
        }
        playerKind = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
        if (playerKind == PLAYER_KIND_CPU || playerKind == PLAYER_KIND_NONE || playerKind == PLAYER_KIND_GHOST) {
            continue;
        }
        outcome = 2;
        if (IsKartOnWinningTeamAtEnd((u16) gRaceSetup->mEntryIndex) != 0) {
            if (IsKartOnWinningTeamAtEnd(entryIndex) == 0) {
                outcome = 0;
            }
        } else if (IsKartOnWinningTeamAtEnd(entryIndex) != 0) {
            if (gRaceProgress->mKarts[entryIndex].mStatus != RACE_PROGRESS_KART_STATUS_REMOVED) {
                outcome = 1;
            }
        }
        if ((gConnectionWork->mGroupSendMask &
             (1 << gConnectionWork->mParticipantIndexByPos[gConnectionWork->mParticipantIndexByPos[entryIndex]])) ==
            0) {
            AddBuddyRecordResult(entryIndex, date, 1, outcome);
        }
        if (outcome == 0) {
            if (firstTotal < gResultTotalMax) {
                countsChanged = TRUE;
                firstTotal++;
            }
        } else if (outcome == 1) {
            if (secondTotal < gResultTotalMax) {
                countsChanged = TRUE;
                secondTotal++;
            }
        }
    }
    if (countsChanged != FALSE) {
        gBackupBuffers->mFirstBlock->mTotals[2] = firstTotal;
        gBackupBuffers->mFirstBlock->mTotals[3] = secondTotal;
        WriteBuddyRecordsAndFirstBlock();
    } else {
        WriteBackupBuddyRecords();
    }
}

void AddShineBattleBuddyRecordResults(void) {
    u16 entryIndex;
    u32 firstTotal;
    u32 secondTotal;
    BOOL countsChanged;
    u32 outcome;
    s32 playerKind;
    s32 date[5];

    countsChanged = FALSE;
    if (BuddyRecordIsConnectionActive() == FALSE) {
        return;
    }
    if (gRaceSetup->mEntryIndex == -1) {
        return;
    }
    if (GetRaceProgressKart(gRaceSetup->mEntryIndex)->mStatus == RACE_PROGRESS_KART_STATUS_REMOVED) {
        return;
    }
    if (IsWinnerDecidedAndEndReached() == 0) {
        return;
    }
    GetClockDateOrDefault(date);
    GetKartRank((u16) gRaceSetup->mEntryIndex);
    firstTotal = gBackupBuffers->mFirstBlock->mTotals[2];
    secondTotal = gBackupBuffers->mFirstBlock->mTotals[3];
    for (entryIndex = 0; entryIndex < (u32) gRaceSetup->mKartCount; entryIndex++) {
        if (entryIndex == gRaceSetup->mEntryIndex) {
            continue;
        }
        playerKind = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
        if (playerKind == PLAYER_KIND_CPU || playerKind == PLAYER_KIND_NONE || playerKind == PLAYER_KIND_GHOST) {
            continue;
        }
        outcome = 2;
        if (IsKartOnWinningTeamAtEnd((u16) gRaceSetup->mEntryIndex) != 0) {
            if (IsKartOnWinningTeamAtEnd(entryIndex) == 0) {
                outcome = 0;
            }
        } else if (IsKartOnWinningTeamAtEnd(entryIndex) != 0) {
            if (gRaceProgress->mKarts[entryIndex].mStatus != RACE_PROGRESS_KART_STATUS_REMOVED) {
                outcome = 1;
            }
        }
        if ((gConnectionWork->mGroupSendMask &
             (1 << gConnectionWork->mParticipantIndexByPos[gConnectionWork->mParticipantIndexByPos[entryIndex]])) ==
            0) {
            AddBuddyRecordResult(entryIndex, date, 1, outcome);
        }
        if (outcome == 0) {
            if (firstTotal < gResultTotalMax) {
                countsChanged = TRUE;
                firstTotal++;
            }
        } else if (outcome == 1) {
            if (secondTotal < gResultTotalMax) {
                countsChanged = TRUE;
                secondTotal++;
            }
        }
    }
    if (countsChanged != FALSE) {
        gBackupBuffers->mFirstBlock->mTotals[2] = firstTotal;
        gBackupBuffers->mFirstBlock->mTotals[3] = secondTotal;
        WriteBuddyRecordsAndFirstBlock();
    } else {
        WriteBackupBuddyRecords();
    }
}

static inline u16 GetCupKartTotalPoints(u16 entryIndex) {
    s32 lowByte;
    s32 courseIndexInCup;
    s32 lowByteAgain;
    KartCourseResult *courseResult;

    lowByte = GetLowByte(entryIndex);
    courseIndexInCup = GetCourseIndexInCup();
    lowByteAgain = GetLowByte(lowByte);
    courseResult = &gCupRecords->mKartResults[courseIndexInCup][0];
    courseResult += lowByteAgain;
    return courseResult->mTotalPoints;
}

void AddWiFiRaceBuddyRecordResults(void) {
    u16 entryIndex;
    s32 ownCupRank;
    u32 firstTotal;
    u32 secondTotal;
    u32 kartCountCopy;
    u16 ownPoints;
    u32 outcome;
    s8 otherKartCount;
    s32 date[3];

    firstTotal = gBackupBuffers->mFirstBlock->mTotals[4];
    secondTotal = gBackupBuffers->mFirstBlock->mTotals[5];
    UpdateParticipantElos();
    if (gRaceSetup->mCourseNumber <= 3) {
        return;
    }
    if (gRaceProgress->mRaceDone == 0) {
        return;
    }
    if (GetRaceProgressKart(gRaceSetup->mEntryIndex)->mStatus == RACE_PROGRESS_KART_STATUS_REMOVED) {
        return;
    }
    GetClockDateOrDefault(date);
    ownCupRank = GetKartCupRank((u16) gRaceSetup->mEntryIndex);
    ownPoints = GetCupKartTotalPoints(gRaceSetup->mEntryIndex);
    otherKartCount = gWiFiSession->mKartCountCopy - 1;
    kartCountCopy = gWiFiSession->mKartCountCopy;
    if (otherKartCount > 0) {
        if (secondTotal < otherKartCount) {
            secondTotal = 0;
        } else {
            secondTotal -= otherKartCount;
        }
    }
    if ((s16) (kartCountCopy - gRaceSetup->mKartCount) > 0) {
        firstTotal += (s16) (kartCountCopy - gRaceSetup->mKartCount);
        if (firstTotal > gResultTotalMax) {
            firstTotal = gResultTotalMax;
        }
    }
    for (entryIndex = 0; entryIndex < (u32) gRaceSetup->mKartCount; entryIndex++) {
        outcome = 2;
        if (entryIndex != gRaceSetup->mEntryIndex) {
            if (ownCupRank < GetKartCupRank(entryIndex)) {
                outcome = 0;
            } else if (ownCupRank > GetKartCupRank(entryIndex)) {
                outcome = 1;
            }
            if (ownPoints == GetCupKartTotalPoints(entryIndex)) {
                outcome = 2;
            }
            AddBuddyRecordResult(entryIndex, date, 2, outcome);
            if (outcome == 0) {
                if (firstTotal < gResultTotalMax) {
                    firstTotal++;
                }
            } else if (outcome == 1) {
                if (secondTotal < gResultTotalMax) {
                    secondTotal++;
                }
            }
        }
    }
    gBackupBuffers->mFirstBlock->mElo = GetPlayerRecordElo(DWC_GetMyAID());
    gBackupBuffers->mFirstBlock->mTotals[4] = firstTotal;
    gBackupBuffers->mFirstBlock->mTotals[5] = secondTotal;
    WriteBuddyRecordsAndFirstBlock();
}

void SetRaceResultRecords(void) {
    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
        switch (gRaceSetup->mMode) {
            case MODE_VS:
                AddVSBuddyRecordResults();
                break;
            case MODE_MISSION_RUN:
                TrySetMissionRecord();
                break;
            case MODE_BATTLE:
                switch (gRaceSetup->mBattleKind) {
                    case BATTLE_KIND_BALLOON:
                        AddBattleBuddyRecordResults();
                        break;
                    case BATTLE_KIND_SHINE:
                        AddShineBattleBuddyRecordResults();
                        break;
                }
                break;
            case 5:
                AddWiFiRaceBuddyRecordResults();
                break;
        }
    }
}

void SetBuddyRecord(u32 recordIndex, BuddyRecord *buddyRecord) {
    MI_CpuCopy8(buddyRecord, &gBackupBuffers->mBuddyRecordBlock->mRecords[recordIndex], 0x24);
}

u32 GetBuddyRecord(u32 recordIndex, BuddyRecord *buddyRecordOut) {
    if (buddyRecordOut != NULL) {
        MI_CpuCopy8(&gBackupBuffers->mBuddyRecordBlock->mRecords[recordIndex], buddyRecordOut, 0x24);
    }
    return gBackupBuffers->mBuddyRecordBlock->mRecords[recordIndex].mFilled != 0;
}
