#include "Main/Save/ghost_file_records.h"
#include "Main/Save/ghost_file_path.h"
#include "Main/Race/grand_prix_record.h"
#include "Main/Menu/title_scene.h"
#include "Main/System/archive_slots.h"
#include "Main/Save/backup_busy.h"
#include "Main/Save/buddy_record_reset.h"
#include "Main/Save/backup_first_block.h"
#include "Main/Save/buddy_record_time.h"
#include "dwc_account.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "code_0214d018.h"
#include "Main/MapObjects/data_0217a000.h" // GhostListEntry
#include "code_021522a0.h"
#include "Main/Net/wifi_session.h"
#include "Main/Save/ghost_record_file.h"

u32 gSecondTotalLimitBase = 0xf4240;

#pragma opt_loop_invariants off

void ReadGhostFileRecords(void) {
    u8 ghostIndex;
    GhostListEntry *records;
    char path[0x80];

    ghostIndex = 0;
    records = gBackupBuffers->mReadDestination;
    for (; ghostIndex < 0x20; ghostIndex++) {
        FormatGhostFilePath(ghostIndex, path, 0x80);
        ReadFileBytes(path, &records[ghostIndex], 0x230);
    }
    ClearBackupBusy();
    gBackupBuffers->mReadDestination = NULL;
}

void StartReadGhostFileRecords(void *records) {
    gBackupBuffers->mReadDestination = records;
    SetBackupBusy();
    QueueThreadFunction(ReadGhostFileRecords);
    gThreadFunctionQueue->mRunRequested = 1;
}

// Counts the other karts of a Wi-Fi race on the second total before the race, as the race end takes them off again.
void AddOtherKartCountToSecondTotal(void) {
    BackupFirstBlock *firstBlock;
    u32 total;
    u32 limit;

    gWiFiSession->mKartCountCopy = gWiFiSession->mKartCount;
    firstBlock = gBackupBuffers->mFirstBlock;
    total = firstBlock->mTotals[5] + (u8) (gWiFiSession->mKartCountCopy - 1);
    limit = gSecondTotalLimitBase + 3;
    if (total > limit) {
        total = limit;
    }
    gBackupBuffers->mFirstBlock->mTotals[5] = total;
    WriteBackupFirstBlock(gBackupBuffers->mFirstBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
}

s32 CheckUserDataValidConsole(void) {
    return DWC_CheckValidConsole(&gBackupBuffers->mFirstBlock->mUserData);
}

BOOL IsUserDataFriendKeyNonZero(void) {
    u64 friendKey;
    s32 result;

    friendKey = DWC_CreateFriendKey(&gBackupBuffers->mFirstBlock->mUserData);
    result = 0;
    if (friendKey != result) {
        result = 1;
    }
    return result;
}

void FormatUserDataFriendKey(u32 buffer) {
    u64 friendKey;

    friendKey = DWC_CreateFriendKey(&gBackupBuffers->mFirstBlock->mUserData);
    FormatFriendKey(friendKey, friendKey >> 32, buffer);
}

s32 CheckFriendKeyString(const void *keyString) {
    DWCAccFriendData friendData;
    BuddyRecord buddyRecord;
    u64 friendKey;
    s32 foundIndex;
    u8 buddyIndex;
    DWCAccFriendData *friendDataList;

    friendKey = DWC_StringToFriendKey(keyString);
    if (DWC_Acc_CheckFriendKey(friendKey, 0x414d434a) == 0) {
        return 1;
    }
    if (friendKey == DWC_CreateFriendKey(&gBackupBuffers->mFirstBlock->mUserData)) {
        return 1;
    }
    InitFriendDataFromFriendKey(&friendData, friendKey, friendKey >> 32);
    friendDataList = gBackupBuffers->mBuddyRecordBlock->mFriendData;
    foundIndex = -1;
    for (buddyIndex = 0; buddyIndex < 60; buddyIndex++) {
        DWCAccFriendData *entry;

        GetBuddyRecord(buddyIndex, &buddyRecord);
        if (buddyRecord.mFilled == 1) {
            entry = friendDataList + buddyIndex;
            if (IsFriendDataTypeNonZeroWrapper(entry) != 0 && DWC_IsEqualFriendData(entry, &friendData) != 0) {
                foundIndex = (s8) buddyIndex;
                break;
            }
        }
    }
    if (foundIndex != -1) {
        return 2;
    }
    return 0;
}

s32 FindBuddyIndexByFriendData(const void *friendData) {
    BuddyRecord buddyRecord;
    s32 foundIndex;
    u8 buddyIndex;
    DWCAccFriendData *friendDataList;

    friendDataList = gBackupBuffers->mBuddyRecordBlock->mFriendData;
    foundIndex = -1;
    for (buddyIndex = 0; buddyIndex < 60; buddyIndex++) {
        DWCAccFriendData *entry;

        GetBuddyRecord(buddyIndex, &buddyRecord);
        if (buddyRecord.mFilled == 1) {
            entry = friendDataList + buddyIndex;
            if (IsFriendDataTypeNonZeroWrapper(entry) != 0 && DWC_IsEqualFriendData(entry, friendData) != 0) {
                foundIndex = (s8) buddyIndex;
                break;
            }
        }
    }
    return foundIndex;
}

s32 AddOrUpdateBuddyRecord(DWCAccFriendData *friendDataList, void *name, DWCAccFriendData *friendData, s32 notYetBuddy,
                           s32 hasEmblem, s32 allowAdd) {
    DateBytes oldestDate;
    DateBytes recordDate;
    BuddyRecord buddyRecord;
    s32 today[3];
    s32 slotIndex;
    BOOL found;
    s32 oldestIndex;
    s8 buddyIndex;
    DWCAccFriendData *entry;
    u8 year;
    u8 month;
    u8 day;
    u8 slot;

    slotIndex = -1;
    found = FALSE;
    GetClockDateOrDefault(today);
    year = today[0];
    month = today[1];
    day = today[2];
    entry = friendDataList;
    for (buddyIndex = 0; buddyIndex < 60; buddyIndex++, entry++) {
        GetBuddyRecord((u8) buddyIndex, &buddyRecord);
        if (buddyRecord.mFilled == 1 && IsFriendDataTypeNonZeroWrapper(friendData) != 0 &&
            IsFriendDataTypeNonZeroWrapper(entry) != 0 && DWC_IsEqualFriendData(entry, friendData) != 0) {
            slotIndex = buddyIndex;
            found = TRUE;
            break;
        }
    }
    if (notYetBuddy != 0 && found != FALSE) {
        return -1;
    }
    if (allowAdd == 0 && slotIndex == -1) {
        return -1;
    }
    if (slotIndex == -1) {
        for (buddyIndex = 0; buddyIndex < 60; buddyIndex++) {
            GetBuddyRecord((u8) buddyIndex, &buddyRecord);
            if (buddyRecord.mFilled == 0) {
                slotIndex = buddyIndex;
                break;
            }
        }
    }
    oldestIndex = -1;
    if (slotIndex == -1) {
        oldestDate.mYear = 100;
        oldestDate.mMonth = 12;
        oldestDate.mDay = 31;
        for (buddyIndex = 0; buddyIndex < 60; buddyIndex++) {
            GetBuddyRecord((u8) buddyIndex, &buddyRecord);
            recordDate.mYear = buddyRecord.mYear;
            recordDate.mMonth = buddyRecord.mMonth;
            recordDate.mDay = buddyRecord.mDay;
            if (buddyRecord.mFilled == 1 && buddyRecord.mFlagged == 0 &&
                IsDateEarlier(&recordDate, &oldestDate) != FALSE) {
                oldestDate = recordDate;
                oldestIndex = buddyIndex;
            }
        }
        if (oldestIndex != -1) {
            slotIndex = oldestIndex;
        }
    }
    if (slotIndex == -1) {
        return -1;
    }
    MI_CpuCopy8(friendData, friendDataList + slotIndex, sizeof(DWCAccFriendData));
    slot = slotIndex;
    GetBuddyRecord(slot, &buddyRecord);
    if (found == FALSE) {
        ResetBuddyRecord(&buddyRecord);
    }
    buddyRecord.mYear = year;
    buddyRecord.mMonth = month;
    buddyRecord.mDay = day;
    if (notYetBuddy != 0) {
        buddyRecord.mNotYetBuddy = 1;
    } else {
        buddyRecord.mNotYetBuddy = 0;
    }
    MI_CpuCopy8(name, buddyRecord.mName, 0x14);
    buddyRecord.mHasEmblem = hasEmblem != 0;
    buddyRecord.mFilled = 1;
    SetBuddyRecord(slot, &buddyRecord);
    return slotIndex;
}

s32 AddBuddyFromFriendKey(const void *keyString, void *name) {
    DWCAccFriendData friendData;
    u64 friendKey;

    friendKey = DWC_StringToFriendKey(keyString);
    InitFriendDataFromFriendKey(&friendData, friendKey, friendKey >> 32);
    return AddOrUpdateBuddyRecord(gBackupBuffers->mBuddyRecordBlock->mFriendData, name, &friendData, 1, 0, 1);
}
