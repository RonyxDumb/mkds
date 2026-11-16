#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_0203b0a0.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0204b03c.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_02057624.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_02060cb4.h"
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
#include "Main/Unknown/code_0203c8dc.h"

#pragma opt_rebuildconditionals off

static inline BOOL func_0205f218_inline(void) {
    ConnectionWork *connectionWork;

    connectionWork = gStruct217AA00;
    return (connectionWork == NULL ? 0 : connectionWork->field0) != 0 && connectionWork->field4 != 13;
}

BOOL FormatTimeRecordChars(u8 *charsOut, TimeRecord *timeRecord, s32 courseId) {
    u8 packedBytes[10] = {0};
    u32 e;
    s32 cupCourseIndex;
    u32 characterKartValue;
    u8 bitPosition;
    s32 charIndex;
    u16 charValue;
    u8 bitIndex;
    u32 bitOffset;
    s32 byteIndex;
    u8 q;
    s32 xorKey;

    e = timeRecord->mMillisecond + (timeRecord->mSecond * 1000 + timeRecord->mMinute * 60000);
    if (e >= 240000) {
        return 0;
    }
    cupCourseIndex = rconf_getCourseNumber(courseId);
    if (cupCourseIndex < 0 || cupCourseIndex >= 32) {
        return 0;
    }
    characterKartValue = timeRecord->mCharacterIndex * 37 + timeRecord->mKartIndex;
    if (characterKartValue >= 0x200) {
        return 0;
    }
    e = ((e & 0x3ffff) << 14) | ((cupCourseIndex & 0x1f) << 9);
    *(u32 *) &packedBytes[0] = e | (characterKartValue & 0x1ff);
    MI_CpuCopy8(&timeRecord->mName, &packedBytes[4], 4);
    *(u16 *) &packedBytes[8] = 0;
    savc_generateBlockFooter(packedBytes, 10, 1);
    xorKey = 0xc3;
    for (byteIndex = 9; byteIndex >= 0; byteIndex--) {
        packedBytes[byteIndex] ^= xorKey;
        xorKey = packedBytes[byteIndex];
    }
    for (charIndex = 0, bitOffset = 0; charIndex < 16; charIndex++) {
        charValue = 0;
        for (bitIndex = 0; bitIndex < 5; bitIndex++) {
            q = bitOffset;
            bitPosition = q + bitIndex;
            charValue = (u16) (charValue | ((packedBytes[(u8) (bitPosition / 8)] >> (u8) (7 - bitPosition % 8)) & 1))
                        << 1;
        }
        charsOut[charIndex] = aS7lcx3jze8fg4h[(u8) (charValue / 2)];
        bitOffset += 5;
    }
    return 1;
}

BOOL FormatFirstCourseTimeRecord(s32 courseId, void *charsOut) {
    TimeRecord timeRecord;
    BOOL hasRecord;

    hasRecord = FALSE;
    if (savd_getNktaEntry(courseId, 0, &timeRecord) != 0 && timeRecord.mFilled != 0) {
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
    savd_getNkmrEntry(row, column, &missionRecord);
    if (missionRecord.mFilled == 1) {
        isFilled = TRUE;
        *valueOut = missionRecord.mValue;
    }
    return isFilled;
}

BOOL IsKartAppearWithinLimit(KartAppear *kartAppear, u32 characterIndex, u32 kartIndex) {
    u8 limit;
    u8 appearValue;

    limit = savd_getKartUnlockLevel();
    appearValue = kartAppear->mFileData->mValues[kartIndex][characterIndex];
    if (appearValue != 0 && appearValue <= limit) {
        return 1;
    }
    return 0;
}

BOOL func_0205fc98(KartAppear *kartAppear, u32 characterIndex, u32 kartIndex) {
    u8 limit;
    u8 appearValue;

    if (func_0205f218_inline() != FALSE) {
        limit = gSaveData->mParticipantMinValue;
    } else {
        limit = savd_getKartUnlockLevel();
    }
    appearValue = kartAppear->mFileData->mValues[kartIndex][characterIndex];
    if (appearValue != 0 && appearValue <= limit) {
        return TRUE;
    }
    return FALSE;
}

s32 IsBitSetInAllParticipants(s32 bitIndex) {
    if (func_0205f218_inline() == FALSE) {
        return savd_isUnlockBitSet(bitIndex);
    }
    return savd_isBitSet2(bitIndex, gSaveData->mParticipantAndBits);
}

s32 IsBitSetInAnyParticipant(s32 bitIndex) {
    if (func_0205f218_inline() == FALSE) {
        return savd_isUnlockBitSet(bitIndex);
    }
    return savd_isBitSet2(bitIndex, gSaveData->mParticipantOrBits);
}

void AddBuddyRecordResult(u32 entryIndex, s32 *date, u32 matchKind, u32 resultKind) {
    RaceSetup *raceSetup;
    BuddyRecord buddyRecord;
    u16 *firstCount;
    u16 *secondCount;
    u8 buddyIndex;
    s32 foundIndex;

    raceSetup = gRaceMultiConfig;
    if (entryIndex == raceSetup->mEntryIndex) {
        return;
    }
    if (raceSetup->mCurrentEntries[entryIndex].mPlayer.field20 == 0) {
        return;
    }
    foundIndex = FindBuddyIndexByFriendData((const void *) raceSetup->mCurrentEntries[entryIndex].mPlayer.field20);
    if (foundIndex == -1) {
        return;
    }
    buddyIndex = foundIndex;
    GetBuddyRecord(buddyIndex, &buddyRecord);
    if (buddyRecord.mFilled == 0) {
        ResetBuddyRecord((u32) &buddyRecord);
    }
    if (gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mName != NULL) {
        MI_CpuCopy8(gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mName, buddyRecord.mName, 0x14);
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

static inline u32 func_0205f700_inline(u16 kartIndex, u32 ownRank) {
    if (rstat_getPlace(kartIndex) > ownRank) {
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
    if (func_0205f218_inline() == FALSE) {
        return;
    }
    if (gRaceMultiConfig->mEntryIndex == -1) {
        return;
    }
    if (gRaceStatus->field0[(u16) gRaceMultiConfig->mEntryIndex].mStatus == 4) {
        return;
    }
    if (gRaceStatus->mRaceDone == 0) {
        return;
    }
    GetDate(date);
    ownRank = rstat_getPlace((u16) gRaceMultiConfig->mEntryIndex);
    if (gRaceMultiConfig->mUseTeams != 0) {
        teamIndex = gRaceMultiConfig->mCurrentEntries[(u16) gRaceMultiConfig->mEntryIndex].mPlayer.mTeamIndex;
    }
    firstTotal = gSaveData->mFirstBlock->field34[0];
    secondTotal = gSaveData->mFirstBlock->field34[1];
    for (entryIndex = 0; entryIndex < (u32) gRaceMultiConfig->mKartCount; entryIndex++) {
        if (entryIndex == gRaceMultiConfig->mEntryIndex) {
            continue;
        }
        playerKind = gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mKind;
        if (playerKind == PLAYER_KIND_CPU || playerKind == PLAYER_KIND_NONE || playerKind == PLAYER_KIND_GHOST) {
            continue;
        }
        if (gRaceMultiConfig->mUseTeams != 0) {
            if (teamIndex == gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mTeamIndex) {
                outcome = 2;
            } else {
                switch (gRaceMultiConfig->mRuleKind) {
                    case 0:
                    case 2:
                        outcome = func_0205f700_inline(entryIndex, ownRank);
                        break;
                    case 1:
                        if (teamIndex == rres_205D480()) {
                            outcome = 0;
                        } else if (gRaceStatus->field0[entryIndex].mStatus == 4) {
                            outcome = 2;
                        } else {
                            outcome = 1;
                        }
                        break;
                }
            }
        } else {
            outcome = func_0205f700_inline(entryIndex, ownRank);
        }
        if ((gStruct217AA00->field457 & (1 << gStruct217AA00->field1E8C[gStruct217AA00->field1E8C[entryIndex]])) == 0) {
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
        gSaveData->mFirstBlock->field34[0] = firstTotal;
        gSaveData->mFirstBlock->field34[1] = secondTotal;
        SaveFriendList();
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
    if (func_0205f218_inline() == FALSE) {
        return;
    }
    if (gRaceMultiConfig->mEntryIndex == -1) {
        return;
    }
    if (gRaceStatus->field0[(u16) gRaceMultiConfig->mEntryIndex].mStatus == 4) {
        return;
    }
    if (mgcnt_hasMgEnded() == 0) {
        return;
    }
    GetDate(date);
    firstTotal = gSaveData->mFirstBlock->field34[2];
    secondTotal = gSaveData->mFirstBlock->field34[3];
    for (entryIndex = 0; entryIndex < (u32) gRaceMultiConfig->mKartCount; entryIndex++) {
        if (entryIndex == gRaceMultiConfig->mEntryIndex) {
            continue;
        }
        playerKind = gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mKind;
        if (playerKind == PLAYER_KIND_CPU || playerKind == PLAYER_KIND_NONE || playerKind == PLAYER_KIND_GHOST) {
            continue;
        }
        outcome = 2;
        if (mgcnt_hasDriverWon((u16) gRaceMultiConfig->mEntryIndex) != 0) {
            if (mgcnt_hasDriverWon(entryIndex) == 0) {
                outcome = 0;
            }
        } else if (mgcnt_hasDriverWon(entryIndex) != 0) {
            if (gRaceStatus->field0[entryIndex].mStatus != 4) {
                outcome = 1;
            }
        }
        if ((gStruct217AA00->field457 & (1 << gStruct217AA00->field1E8C[gStruct217AA00->field1E8C[entryIndex]])) == 0) {
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
        gSaveData->mFirstBlock->field34[2] = firstTotal;
        gSaveData->mFirstBlock->field34[3] = secondTotal;
        SaveFriendList();
    } else {
        WriteBackupBuddyRecords();
    }
}

void sub_205F218(void) {
    u16 entryIndex;
    u32 firstTotal;
    u32 secondTotal;
    BOOL countsChanged;
    u32 outcome;
    s32 playerKind;
    s32 date[5];

    countsChanged = FALSE;
    if (func_0205f218_inline() == FALSE) {
        return;
    }
    if (gRaceMultiConfig->mEntryIndex == -1) {
        return;
    }
    if (gRaceStatus->field0[(u16) gRaceMultiConfig->mEntryIndex].mStatus == 4) {
        return;
    }
    if (mgcnt_hasMgEnded() == 0) {
        return;
    }
    GetDate(date);
    rstat_getPlace((u16) gRaceMultiConfig->mEntryIndex);
    firstTotal = gSaveData->mFirstBlock->field34[2];
    secondTotal = gSaveData->mFirstBlock->field34[3];
    for (entryIndex = 0; entryIndex < (u32) gRaceMultiConfig->mKartCount; entryIndex++) {
        if (entryIndex == gRaceMultiConfig->mEntryIndex) {
            continue;
        }
        playerKind = gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mKind;
        if (playerKind == PLAYER_KIND_CPU || playerKind == PLAYER_KIND_NONE || playerKind == PLAYER_KIND_GHOST) {
            continue;
        }
        outcome = 2;
        if (mgcnt_hasDriverWon((u16) gRaceMultiConfig->mEntryIndex) != 0) {
            if (mgcnt_hasDriverWon(entryIndex) == 0) {
                outcome = 0;
            }
        } else if (mgcnt_hasDriverWon(entryIndex) != 0) {
            if (gRaceStatus->field0[entryIndex].mStatus != 4) {
                outcome = 1;
            }
        }
        if ((gStruct217AA00->field457 & (1 << gStruct217AA00->field1E8C[gStruct217AA00->field1E8C[entryIndex]])) == 0) {
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
        gSaveData->mFirstBlock->field34[2] = firstTotal;
        gSaveData->mFirstBlock->field34[3] = secondTotal;
        SaveFriendList();
    } else {
        WriteBackupBuddyRecords();
    }
}

static inline u16 func_0205ef70_inline(u16 entryIndex) {
    s32 lowByte;
    s32 courseIndexInCup;
    s32 lowByteAgain;
    KartCourseResult *courseResult;

    lowByte = rres_205DC7C(entryIndex);
    courseIndexInCup = rres_205DB28();
    lowByteAgain = rres_205DC7C(lowByte);
    courseResult = &rres_sRaceResults->mKartResults[courseIndexInCup][0];
    courseResult += lowByteAgain;
    return courseResult->mTotalPoints;
}

void sub_205EF70(void) {
    u16 entryIndex;
    s32 ownCupRank;
    u32 firstTotal;
    u32 secondTotal;
    u32 kartCountCopy;
    u16 ownPoints;
    u32 outcome;
    s8 otherKartCount;
    s32 date[3];

    firstTotal = gSaveData->mFirstBlock->field34[4];
    secondTotal = gSaveData->mFirstBlock->field34[5];
    sub_205B32C();
    if (gRaceMultiConfig->mCourseNumber <= 3) {
        return;
    }
    if (gRaceStatus->mRaceDone == 0) {
        return;
    }
    if (gRaceStatus->field0[(u16) gRaceMultiConfig->mEntryIndex].mStatus == 4) {
        return;
    }
    GetDate(date);
    ownCupRank = rres_getGlobalRank((u16) gRaceMultiConfig->mEntryIndex);
    ownPoints = func_0205ef70_inline(gRaceMultiConfig->mEntryIndex);
    otherKartCount = gStruct217D384->mKartCountCopy - 1;
    kartCountCopy = gStruct217D384->mKartCountCopy;
    if (otherKartCount > 0) {
        if (secondTotal < otherKartCount) {
            secondTotal = 0;
        } else {
            secondTotal -= otherKartCount;
        }
    }
    if ((s16) (kartCountCopy - gRaceMultiConfig->mKartCount) > 0) {
        firstTotal += (s16) (kartCountCopy - gRaceMultiConfig->mKartCount);
        if (firstTotal > gResultTotalMax) {
            firstTotal = gResultTotalMax;
        }
    }
    for (entryIndex = 0; entryIndex < (u32) gRaceMultiConfig->mKartCount; entryIndex++) {
        outcome = 2;
        if (entryIndex != gRaceMultiConfig->mEntryIndex) {
            if (ownCupRank < rres_getGlobalRank(entryIndex)) {
                outcome = 0;
            } else if (ownCupRank > rres_getGlobalRank(entryIndex)) {
                outcome = 1;
            }
            if (ownPoints == func_0205ef70_inline(entryIndex)) {
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
    gSaveData->mFirstBlock->mElo = GetPlayerRecordElo(func_ov000_0219bb50());
    gSaveData->mFirstBlock->field34[4] = firstTotal;
    gSaveData->mFirstBlock->field34[5] = secondTotal;
    SaveFriendList();
}

void SetRaceResultRecords(void) {
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
        switch (gRaceMultiConfig->mMode) {
            case MODE_VS:
                AddVSBuddyRecordResults();
                break;
            case MODE_MISSION_RUN:
                race_saveMrResult();
                break;
            case MODE_BATTLE:
                switch (gRaceMultiConfig->mBattleKind) {
                    case BATTLE_KIND_BALLOON:
                        AddBattleBuddyRecordResults();
                        break;
                    case BATTLE_KIND_SHINE:
                        sub_205F218();
                        break;
                }
                break;
            case 5:
                sub_205EF70();
                break;
        }
    }
}

void SetBuddyRecord(u32 recordIndex, BuddyRecord *buddyRecord) {
    MI_CpuCopy8(buddyRecord, &gSaveData->mBuddyRecordBlock->mRecords[recordIndex], 0x24);
}

u32 GetBuddyRecord(u32 recordIndex, BuddyRecord *buddyRecordOut) {
    if (buddyRecordOut != NULL) {
        MI_CpuCopy8(&gSaveData->mBuddyRecordBlock->mRecords[recordIndex], buddyRecordOut, 0x24);
    }
    return gSaveData->mBuddyRecordBlock->mRecords[recordIndex].mFilled != 0;
}
