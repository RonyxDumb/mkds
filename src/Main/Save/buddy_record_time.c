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
#include "Main/Net/wifi_race_sync_advance.h"
#include "Main/System/low_byte.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Net/player_record.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Menu/select_race_rule_state.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "cpu_copy_fill.h"
#include "Main/Race/race_clock.h"
#include "Main/Net/wifi_session.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const u8 g_TimeTrialBase32Table[33] = {0x53, 0x37, 0x4c, 0x43, 0x58, 0x33, 0x4a, 0x5a, 0x45, 0x38, 0x46,
                                     0x47, 0x34, 0x48, 0x42, 0x4b, 0x57, 0x4e, 0x35, 0x32, 0x59, 0x50,
                                     0x41, 0x36, 0x52, 0x54, 0x55, 0x39, 0x56, 0x4d, 0x44, 0x51};
u32 g_dec_1000000 = 0xf4240;

#pragma opt_rebuildconditionals off

static inline BOOL BuddyRecordIsConnectionActive(void) {
    ConnectionWork *connectionWork;

    connectionWork = g_GlobalZE;
    return (connectionWork == NULL ? CONNECTION_MODE_NONE : connectionWork->mConnectionMode) != CONNECTION_MODE_NONE &&
           connectionWork->mState != CONNECTION_STATE_ENDED;
}

BOOL GenerateTimeTrialCodeImpl(u8 *charsOut, TimeRecord *timeRecord, s32 courseId) {
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
    cupCourseIndex = GetCourseIdFromInternalId(courseId);
    if (cupCourseIndex < 0 || cupCourseIndex >= 32) {
        return 0;
    }
    characterKartValue = timeRecord->mCharacterIndex * 37 + timeRecord->mKartIndex;
    if (characterKartValue >= 0x200) {
        return 0;
    }
    value = ((value & 0x3ffff) << 14) | ((cupCourseIndex & 0x1f) << 9);
    *(u32 *) &packedBytes[0] = value | (characterKartValue & 0x1ff);
    Mem_CpuCopy8(&timeRecord->mName, &packedBytes[4], 4);
    *(u16 *) &packedBytes[8] = 0;
    CalculateCRCChecksum_from_thumb(packedBytes, 10, 1);
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

BOOL GenerateTimeTrialCode(s32 courseId, void *charsOut) {
    TimeRecord timeRecord;
    BOOL hasRecord;

    hasRecord = FALSE;
    if (TimeTrialRecord_CopyFrom_from_thumb(courseId, 0, &timeRecord) != 0 && timeRecord.mFilled != 0) {
        hasRecord = TRUE;
    }
    if (hasRecord == FALSE) {
        return 0;
    }
    return GenerateTimeTrialCodeImpl(charsOut, &timeRecord, courseId);
}

BOOL IsMissionStageBeaten(s32 row, s32 column, s32 *valueOut) {
    UnpackedMissionRecord missionRecord;
    BOOL isFilled;

    isFilled = FALSE;
    GetMissionLevelStageInfoByIds_from_thumb(row, column, &missionRecord);
    if (missionRecord.mFilled == 1) {
        isFilled = TRUE;
        *valueOut = missionRecord.mValue;
    }
    return isFilled;
}

BOOL IsKartAppearWithinLimit(KartAppear *kartAppear, u32 characterIndex, u32 kartIndex) {
    u8 limit;
    u8 appearValue;

    limit = CheckExtraKartUnlockFlags_from_thumb();
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
        limit = g_SaveDataHolder->mParticipantMinValue;
    } else {
        limit = CheckExtraKartUnlockFlags_from_thumb();
    }
    appearValue = kartAppear->mFileData->mValues[kartIndex][characterIndex];
    if (appearValue != 0 && appearValue <= limit) {
        return TRUE;
    }
    return FALSE;
}

s32 IsBitSetInAllParticipants(s32 bitIndex) {
    if (BuddyRecordIsConnectionActive() == FALSE) {
        return CheckSavedSecretFlag_from_thumb(bitIndex);
    }
    return CheckSecretFlagWith_from_thumb(bitIndex, g_SaveDataHolder->mParticipantAndBits);
}

s32 CheckSecretFlag(s32 bitIndex) {
    if (BuddyRecordIsConnectionActive() == FALSE) {
        return CheckSavedSecretFlag_from_thumb(bitIndex);
    }
    return CheckSecretFlagWith_from_thumb(bitIndex, g_SaveDataHolder->mParticipantOrBits);
}

void AddBuddyRecordResult(u32 entryIndex, s32 *date, u32 matchKind, u32 resultKind) {
    RaceSetup *raceSetup;
    BuddyRecord buddyRecord;
    u16 *firstCount;
    u16 *secondCount;
    u8 buddyIndex;
    s32 foundIndex;

    raceSetup = g_GlobalCO;
    if (entryIndex == raceSetup->mEntryIndex) {
        return;
    }
    if (raceSetup->mCurrentEntries[entryIndex].mPlayer.mFriendData == 0) {
        return;
    }
    foundIndex = FindSomeOI_FriendCode_Index(raceSetup->mCurrentEntries[entryIndex].mPlayer.mFriendData);
    if (foundIndex == -1) {
        return;
    }
    buddyIndex = foundIndex;
    GlobalZ_GetOI(buddyIndex, &buddyRecord);
    if (buddyRecord.mFilled == 0) {
        StructOI_Initialize_from_thumb(&buddyRecord);
    }
    if (g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mName != NULL) {
        Mem_CpuCopy8(g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mName, buddyRecord.mName,
                    sizeof(buddyRecord.mName));
    }
    switch (matchKind) {
        case BUDDY_RECORD_MATCH_VS:
            firstCount = &buddyRecord.mResultCounts[0][0];
            secondCount = &buddyRecord.mResultCounts[0][1];
            break;
        case BUDDY_RECORD_MATCH_BATTLE:
            firstCount = &buddyRecord.mResultCounts[1][0];
            secondCount = &buddyRecord.mResultCounts[1][1];
            break;
        case BUDDY_RECORD_MATCH_WIFI_RACE:
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
    GlobalZ_SetOI(buddyIndex, &buddyRecord);
}

static inline u32 IsKartRankAtMost(u16 kartIndex, u32 ownRank) {
    if (GetSomeRacerFlags(kartIndex) > ownRank) {
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
    if (g_GlobalCO->mEntryIndex == -1) {
        return;
    }
    if (GetRaceProgressKart(g_GlobalCO->mEntryIndex)->mStatus == RACE_PROGRESS_KART_STATUS_REMOVED) {
        return;
    }
    if (g_GlobalMV->mRaceDone == 0) {
        return;
    }
    GetCurrentDate(date);
    ownRank = GetSomeRacerFlags((u16) g_GlobalCO->mEntryIndex);
    if (g_GlobalCO->mUseTeams != 0) {
        teamIndex = GetCurrentEntry(g_GlobalCO->mEntryIndex)->mPlayer.mTeamIndex;
    }
    firstTotal = g_SaveDataHolder->mFirstBlock->mTotals[0];
    secondTotal = g_SaveDataHolder->mFirstBlock->mTotals[1];
    for (entryIndex = 0; entryIndex < (u32) g_GlobalCO->mKartCount; entryIndex++) {
        if (entryIndex == g_GlobalCO->mEntryIndex) {
            continue;
        }
        playerKind = g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mKind;
        if (playerKind == PLAYER_KIND_CPU || playerKind == PLAYER_KIND_NONE || playerKind == PLAYER_KIND_GHOST) {
            continue;
        }
        if (g_GlobalCO->mUseTeams != 0) {
            if (teamIndex == g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mTeamIndex) {
                outcome = 2;
            } else {
                switch (g_GlobalCO->mRuleKind) {
                    case RULE_KIND_FREE:
                    case RULE_KIND_RACE_COUNT:
                        outcome = IsKartRankAtMost(entryIndex, ownRank);
                        break;
                    case RULE_KIND_WIN_COUNT:
                        if (teamIndex == GetCupWinningTeam()) {
                            outcome = 0;
                        } else if (g_GlobalMV->mKarts[entryIndex].mStatus == RACE_PROGRESS_KART_STATUS_REMOVED) {
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
        if ((g_GlobalZE->mGroupSendMask &
             (1 << g_GlobalZE->mParticipantIndexByPos[g_GlobalZE->mParticipantIndexByPos[entryIndex]])) ==
            0) {
            AddBuddyRecordResult(entryIndex, date, BUDDY_RECORD_MATCH_VS, outcome);
        }
        if (outcome == 0) {
            if (firstTotal < g_dec_1000000) {
                firstTotal++;
                countsChanged = TRUE;
            }
        } else if (outcome == 1) {
            if (secondTotal < g_dec_1000000) {
                secondTotal++;
                countsChanged = TRUE;
            }
        }
    }
    if (countsChanged != FALSE) {
        g_SaveDataHolder->mFirstBlock->mTotals[0] = firstTotal;
        g_SaveDataHolder->mFirstBlock->mTotals[1] = secondTotal;
        SaveFriendList();
    } else {
        WriteFriendListSaveDataSection();
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
    if (g_GlobalCO->mEntryIndex == -1) {
        return;
    }
    if (GetRaceProgressKart(g_GlobalCO->mEntryIndex)->mStatus == RACE_PROGRESS_KART_STATUS_REMOVED) {
        return;
    }
    if (IsWinnerDecidedAndEndReached() == 0) {
        return;
    }
    GetCurrentDate(date);
    firstTotal = g_SaveDataHolder->mFirstBlock->mTotals[2];
    secondTotal = g_SaveDataHolder->mFirstBlock->mTotals[3];
    for (entryIndex = 0; entryIndex < (u32) g_GlobalCO->mKartCount; entryIndex++) {
        if (entryIndex == g_GlobalCO->mEntryIndex) {
            continue;
        }
        playerKind = g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mKind;
        if (playerKind == PLAYER_KIND_CPU || playerKind == PLAYER_KIND_NONE || playerKind == PLAYER_KIND_GHOST) {
            continue;
        }
        outcome = 2;
        if (IsKartOnWinningTeamAtEnd((u16) g_GlobalCO->mEntryIndex) != 0) {
            if (IsKartOnWinningTeamAtEnd(entryIndex) == 0) {
                outcome = 0;
            }
        } else if (IsKartOnWinningTeamAtEnd(entryIndex) != 0) {
            if (g_GlobalMV->mKarts[entryIndex].mStatus != RACE_PROGRESS_KART_STATUS_REMOVED) {
                outcome = 1;
            }
        }
        if ((g_GlobalZE->mGroupSendMask &
             (1 << g_GlobalZE->mParticipantIndexByPos[g_GlobalZE->mParticipantIndexByPos[entryIndex]])) ==
            0) {
            AddBuddyRecordResult(entryIndex, date, BUDDY_RECORD_MATCH_BATTLE, outcome);
        }
        if (outcome == 0) {
            if (firstTotal < g_dec_1000000) {
                countsChanged = TRUE;
                firstTotal++;
            }
        } else if (outcome == 1) {
            if (secondTotal < g_dec_1000000) {
                countsChanged = TRUE;
                secondTotal++;
            }
        }
    }
    if (countsChanged != FALSE) {
        g_SaveDataHolder->mFirstBlock->mTotals[2] = firstTotal;
        g_SaveDataHolder->mFirstBlock->mTotals[3] = secondTotal;
        SaveFriendList();
    } else {
        WriteFriendListSaveDataSection();
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
    if (g_GlobalCO->mEntryIndex == -1) {
        return;
    }
    if (GetRaceProgressKart(g_GlobalCO->mEntryIndex)->mStatus == RACE_PROGRESS_KART_STATUS_REMOVED) {
        return;
    }
    if (IsWinnerDecidedAndEndReached() == 0) {
        return;
    }
    GetCurrentDate(date);
    GetSomeRacerFlags((u16) g_GlobalCO->mEntryIndex);
    firstTotal = g_SaveDataHolder->mFirstBlock->mTotals[2];
    secondTotal = g_SaveDataHolder->mFirstBlock->mTotals[3];
    for (entryIndex = 0; entryIndex < (u32) g_GlobalCO->mKartCount; entryIndex++) {
        if (entryIndex == g_GlobalCO->mEntryIndex) {
            continue;
        }
        playerKind = g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mKind;
        if (playerKind == PLAYER_KIND_CPU || playerKind == PLAYER_KIND_NONE || playerKind == PLAYER_KIND_GHOST) {
            continue;
        }
        outcome = 2;
        if (IsKartOnWinningTeamAtEnd((u16) g_GlobalCO->mEntryIndex) != 0) {
            if (IsKartOnWinningTeamAtEnd(entryIndex) == 0) {
                outcome = 0;
            }
        } else if (IsKartOnWinningTeamAtEnd(entryIndex) != 0) {
            if (g_GlobalMV->mKarts[entryIndex].mStatus != RACE_PROGRESS_KART_STATUS_REMOVED) {
                outcome = 1;
            }
        }
        if ((g_GlobalZE->mGroupSendMask &
             (1 << g_GlobalZE->mParticipantIndexByPos[g_GlobalZE->mParticipantIndexByPos[entryIndex]])) ==
            0) {
            AddBuddyRecordResult(entryIndex, date, BUDDY_RECORD_MATCH_BATTLE, outcome);
        }
        if (outcome == 0) {
            if (firstTotal < g_dec_1000000) {
                countsChanged = TRUE;
                firstTotal++;
            }
        } else if (outcome == 1) {
            if (secondTotal < g_dec_1000000) {
                countsChanged = TRUE;
                secondTotal++;
            }
        }
    }
    if (countsChanged != FALSE) {
        g_SaveDataHolder->mFirstBlock->mTotals[2] = firstTotal;
        g_SaveDataHolder->mFirstBlock->mTotals[3] = secondTotal;
        SaveFriendList();
    } else {
        WriteFriendListSaveDataSection();
    }
}

static inline u16 GetCupKartTotalPoints(u16 entryIndex) {
    s32 lowByte;
    s32 courseIndexInCup;
    s32 lowByteAgain;
    KartCourseResult *courseResult;

    lowByte = Int32ToInt8(entryIndex);
    courseIndexInCup = GetSomeLUMaxIndex();
    lowByteAgain = Int32ToInt8(lowByte);
    courseResult = &g_GlobalLU->mKartResults[courseIndexInCup][0];
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

    firstTotal = g_SaveDataHolder->mFirstBlock->mTotals[4];
    secondTotal = g_SaveDataHolder->mFirstBlock->mTotals[5];
    UpdateParticipantElos();
    if (g_GlobalCO->mCourseNumber <= WIFI_BUDDY_RECORD_SKIPPED_COURSE_COUNT) {
        return;
    }
    if (g_GlobalMV->mRaceDone == 0) {
        return;
    }
    if (GetRaceProgressKart(g_GlobalCO->mEntryIndex)->mStatus == RACE_PROGRESS_KART_STATUS_REMOVED) {
        return;
    }
    GetCurrentDate(date);
    ownCupRank = GetSomeRacerPosition(g_GlobalCO->mEntryIndex);
    ownPoints = GetCupKartTotalPoints(g_GlobalCO->mEntryIndex);
    otherKartCount = g_GlobalB->mKartCountCopy - 1;
    kartCountCopy = g_GlobalB->mKartCountCopy;
    if (otherKartCount > 0) {
        if (secondTotal < otherKartCount) {
            secondTotal = 0;
        } else {
            secondTotal -= otherKartCount;
        }
    }
    if ((s16) (kartCountCopy - g_GlobalCO->mKartCount) > 0) {
        firstTotal += (s16) (kartCountCopy - g_GlobalCO->mKartCount);
        if (firstTotal > g_dec_1000000) {
            firstTotal = g_dec_1000000;
        }
    }
    for (entryIndex = 0; entryIndex < (u32) g_GlobalCO->mKartCount; entryIndex++) {
        outcome = 2;
        if (entryIndex != g_GlobalCO->mEntryIndex) {
            if (ownCupRank < GetSomeRacerPosition(entryIndex)) {
                outcome = 0;
            } else if (ownCupRank > GetSomeRacerPosition(entryIndex)) {
                outcome = 1;
            }
            if (ownPoints == GetCupKartTotalPoints(entryIndex)) {
                outcome = 2;
            }
            AddBuddyRecordResult(entryIndex, date, BUDDY_RECORD_MATCH_WIFI_RACE, outcome);
            if (outcome == 0) {
                if (firstTotal < g_dec_1000000) {
                    firstTotal++;
                }
            } else if (outcome == 1) {
                if (secondTotal < g_dec_1000000) {
                    secondTotal++;
                }
            }
        }
    }
    g_SaveDataHolder->mFirstBlock->mElo = GetTKSomeSize(DWC_GetMyAID());
    g_SaveDataHolder->mFirstBlock->mTotals[4] = firstTotal;
    g_SaveDataHolder->mFirstBlock->mTotals[5] = secondTotal;
    SaveFriendList();
}

void SetRaceResultRecords(void) {
    if (g_GlobalCO->mRaceKind == RACE_KIND_NORMAL) {
        switch (g_GlobalCO->mMode) {
            case MODE_VS:
                AddVSBuddyRecordResults();
                break;
            case MODE_MISSION_RUN:
                SomeMissionLevelStageChecking();
                break;
            case MODE_BATTLE:
                switch (g_GlobalCO->mBattleKind) {
                    case BATTLE_KIND_BALLOON:
                        AddBattleBuddyRecordResults();
                        break;
                    case BATTLE_KIND_SHINE:
                        AddShineBattleBuddyRecordResults();
                        break;
                }
                break;
            case MODE_WIFI:
                AddWiFiRaceBuddyRecordResults();
                break;
        }
    }
}

void GlobalZ_SetOI(u32 recordIndex, BuddyRecord *buddyRecord) {
    Mem_CpuCopy8(buddyRecord, &g_SaveDataHolder->mBuddyRecordBlock->mRecords[recordIndex], sizeof(BuddyRecord));
}

u32 GlobalZ_GetOI(u32 recordIndex, BuddyRecord *buddyRecordOut) {
    if (buddyRecordOut != NULL) {
        Mem_CpuCopy8(&g_SaveDataHolder->mBuddyRecordBlock->mRecords[recordIndex], buddyRecordOut, sizeof(BuddyRecord));
    }
    return g_SaveDataHolder->mBuddyRecordBlock->mRecords[recordIndex].mFilled != 0;
}
