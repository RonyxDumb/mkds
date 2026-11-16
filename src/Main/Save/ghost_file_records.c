#include "Main/Save/ghost_file_records.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Save/ghost_file_path.h"
#include "Main/Race/grand_prix_record.h"
#include "Main/Menu/title_scene.h"
#include "Main/System/archive_slots.h"
#include "Main/Save/backup_busy.h"
#include "Main/Save/buddy_record_reset.h"
#include "Main/Save/backup_first_block.h"
#include "Main/Save/buddy_record_time.h"
#include "friend_data_account_fields.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "cpu_copy_fill.h"
#include "Main/System/backup_net_camera_work.h" // GhostListEntry
#include "friend_user_data.h"
#include "Main/Net/wifi_session.h"
#include "Main/Save/ghost_record_file.h"

u32 g_dec_1000000_0 = 0xf4240;

#pragma opt_loop_invariants off

void Task_ReadGhostBins(void) {
    u8 ghostIndex;
    GhostListEntry *records;
    char path[0x80];

    ghostIndex = 0;
    records = g_SaveDataHolder->mReadDestination;
    for (; ghostIndex < 0x20; ghostIndex++) {
        FormatGhostBinPath(ghostIndex, path, 0x80);
        OpenReadFileBufferSize_from_thumb(path, &records[ghostIndex], 0x230);
    }
    ResetSaveDataHolderTaskPendingFlag_from_thumb();
    g_SaveDataHolder->mReadDestination = NULL;
}

void RunReadGhostBinsFn(void *records) {
    g_SaveDataHolder->mReadDestination = records;
    EnableMKDSSVSomeFlag_from_thumb();
    WorkerInsertTask(Task_ReadGhostBins);
    g_WorkerContext->mRunRequested = 1;
}

// Counts the other karts of a Wi-Fi race on the second total before the race, as the race end takes them off again.
void AddOtherKartCountToSecondTotal(void) {
    BackupFirstBlock *firstBlock;
    u32 total;
    u32 limit;

    g_GlobalB->mKartCountCopy = g_GlobalB->mKartCount;
    firstBlock = g_SaveDataHolder->mFirstBlock;
    total = firstBlock->mTotals[5] + (u8) (g_GlobalB->mKartCountCopy - 1);
    limit = g_dec_1000000_0 + 3;
    if (total > limit) {
        total = limit;
    }
    g_SaveDataHolder->mFirstBlock->mTotals[5] = total;
    WriteSaveDataSection_Header_from_thumb(g_SaveDataHolder->mFirstBlock);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
}

s32 CheckUserDataValidConsole(void) {
    return PlayerProfileInfo_SomeFn_4_from_thumb(&g_SaveDataHolder->mFirstBlock->mUserData);
}

BOOL IsUserDataFriendKeyNonZero(void) {
    u64 friendKey;
    s32 result;

    friendKey = PlayerProfileInfo_GetProfileId_from_thumb(&g_SaveDataHolder->mFirstBlock->mUserData);
    result = 0;
    if (friendKey != result) {
        result = 1;
    }
    return result;
}

void FormatUserDataFriendKey(u32 buffer) {
    u64 friendKey;

    friendKey = PlayerProfileInfo_GetProfileId_from_thumb(&g_SaveDataHolder->mFirstBlock->mUserData);
    PrintfUll_from_thumb(friendKey, friendKey >> 32, buffer);
}

s32 CheckFriendCode(const void *keyString) {
    DWCAccFriendData friendData;
    BuddyRecord buddyRecord;
    u64 friendKey;
    s32 foundIndex;
    u8 buddyIndex;
    DWCAccFriendData *friendDataList;

    friendKey = ConvertFriendCodeTo64_from_thumb(keyString);
    if (Friend_VerifyChecksum_from_thumb(friendKey, 0x414d434a) == 0) {
        return 1;
    }
    if (friendKey == PlayerProfileInfo_GetProfileId_from_thumb(&g_SaveDataHolder->mFirstBlock->mUserData)) {
        return 1;
    }
    FriendCode_SetProfileIdAndChecksum_from_thumb(&friendData, friendKey, friendKey >> 32);
    friendDataList = g_SaveDataHolder->mBuddyRecordBlock->mFriendData;
    foundIndex = -1;
    for (buddyIndex = 0; buddyIndex < 60; buddyIndex++) {
        DWCAccFriendData *entry;

        GlobalZ_GetOI(buddyIndex, &buddyRecord);
        if (buddyRecord.mFilled == 1) {
            entry = friendDataList + buddyIndex;
            if (FriendCode_HasNonzeroState_0_from_thumb(entry) != 0 && FriendCode_SameAs_from_thumb(entry, &friendData) != 0) {
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

s32 FindSomeOI_FriendCode_Index(const void *friendData) {
    BuddyRecord buddyRecord;
    s32 foundIndex;
    u8 buddyIndex;
    DWCAccFriendData *friendDataList;

    friendDataList = g_SaveDataHolder->mBuddyRecordBlock->mFriendData;
    foundIndex = -1;
    for (buddyIndex = 0; buddyIndex < 60; buddyIndex++) {
        DWCAccFriendData *entry;

        GlobalZ_GetOI(buddyIndex, &buddyRecord);
        if (buddyRecord.mFilled == 1) {
            entry = friendDataList + buddyIndex;
            if (FriendCode_HasNonzeroState_0_from_thumb(entry) != 0 && FriendCode_SameAs_from_thumb(entry, friendData) != 0) {
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
    GetCurrentDate(today);
    year = today[0];
    month = today[1];
    day = today[2];
    entry = friendDataList;
    for (buddyIndex = 0; buddyIndex < 60; buddyIndex++, entry++) {
        GlobalZ_GetOI((u8) buddyIndex, &buddyRecord);
        if (buddyRecord.mFilled == 1 && FriendCode_HasNonzeroState_0_from_thumb(friendData) != 0 &&
            FriendCode_HasNonzeroState_0_from_thumb(entry) != 0 && FriendCode_SameAs_from_thumb(entry, friendData) != 0) {
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
            GlobalZ_GetOI((u8) buddyIndex, &buddyRecord);
            if (buddyRecord.mFilled == 0) {
                slotIndex = buddyIndex;
                break;
            }
        }
    }
    oldestIndex = -1;
    if (slotIndex == -1) {
        oldestDate.mYear = BUDDY_RECORD_LATEST_YEAR;
        oldestDate.mMonth = BUDDY_RECORD_LATEST_MONTH;
        oldestDate.mDay = BUDDY_RECORD_LATEST_DAY;
        for (buddyIndex = 0; buddyIndex < 60; buddyIndex++) {
            GlobalZ_GetOI((u8) buddyIndex, &buddyRecord);
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
    Mem_CpuCopy8(friendData, friendDataList + slotIndex, sizeof(DWCAccFriendData));
    slot = slotIndex;
    GlobalZ_GetOI(slot, &buddyRecord);
    if (found == FALSE) {
        StructOI_Initialize_from_thumb(&buddyRecord);
    }
    buddyRecord.mYear = year;
    buddyRecord.mMonth = month;
    buddyRecord.mDay = day;
    if (notYetBuddy != 0) {
        buddyRecord.mNotYetBuddy = 1;
    } else {
        buddyRecord.mNotYetBuddy = 0;
    }
    Mem_CpuCopy8(name, buddyRecord.mName, sizeof(buddyRecord.mName));
    buddyRecord.mHasEmblem = hasEmblem != 0;
    buddyRecord.mFilled = 1;
    GlobalZ_SetOI(slot, &buddyRecord);
    return slotIndex;
}

s32 AddBuddyFromFriendKey(const void *keyString, void *name) {
    DWCAccFriendData friendData;
    u64 friendKey;

    friendKey = ConvertFriendCodeTo64_from_thumb(keyString);
    FriendCode_SetProfileIdAndChecksum_from_thumb(&friendData, friendKey, friendKey >> 32);
    return AddOrUpdateBuddyRecord(g_SaveDataHolder->mBuddyRecordBlock->mFriendData, name, &friendData, 1, 0, 1);
}
