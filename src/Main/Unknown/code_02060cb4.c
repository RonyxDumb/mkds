#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_0203b070.h"
#include "Main/Unknown/code_0203b0a0.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/System/ArchiveFiles.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057624.h"
#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_021524d8.h"
#include "Main/Unknown/code_02152698.h"
#include "Main/Unknown/code_02152918.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"
#include "code_021522a0.h"
#include "code_02152500.h"
#include "code_021526e4.h"
#include "code_02152934.h"

#pragma opt_loop_invariants off

void ghdat_loadStaffGhostsTask(void) {
    u8 i;
    u8 *records;
    char path[0x80];

    i = 0;
    records = gSaveData->mReadDestination;
    for (; i < 0x20; i++) {
        race_getGhostFileName(i, path, 0x80);
        arc_readFile(path, records + i * 0x230, 0x230);
    }
    savd_endOperation();
    gSaveData->mReadDestination = NULL;
}

void ghdat_loadStaffGhostsAsync(void *records) {
    gSaveData->mReadDestination = records;
    savd_beginOperation();
    bgwkr_enqueueTask((void (*)(void)) ghdat_loadStaffGhostsTask);
    gBgWkrState->mRunRequested = 1;
}

void func_020612b0(void) {
    BackupFirstBlock *firstBlock;
    u32 total;
    u32 limit;

    gStruct217D384->mKartCountCopy = gStruct217D384->mKartCount;
    firstBlock = gSaveData->mFirstBlock;
    total = firstBlock->field34[5] + (u8) (gStruct217D384->mKartCountCopy - 1);
    limit = data_021653e4 + 3;
    if (total > limit) {
        total = limit;
    }
    gSaveData->mFirstBlock->field34[5] = total;
    savd_writeNksy(gSaveData->mFirstBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
}

s32 CheckUserDataValidConsole(void) {
    return DWC_CheckValidConsole((DWCAccUserData *) gSaveData->mFirstBlock->mUserData);
}

s32 func_02061250(void) {
    u64 friendKey;
    s32 result;

    friendKey = DWC_CreateFriendKey((DWCAccUserData *) gSaveData->mFirstBlock->mUserData);
    result = 0;
    if (friendKey != result) {
        result = 1;
    }
    return result;
}

void FormatUserDataFriendKey(u32 buffer) {
    u64 friendKey;

    friendKey = DWC_CreateFriendKey((DWCAccUserData *) gSaveData->mFirstBlock->mUserData);
    DWC_Acc_FriendKeyToNumericKey(friendKey, friendKey >> 32, buffer);
}

s32 CheckFriendKeyString(const void *keyString) {
    u8 friendData[12];
    BuddyRecord buddyRecord;
    u64 friendKey;
    s32 foundIndex;
    u8 i;
    u8 *friendDataList;

    friendKey = DWC_Acc_NumericKeyToFriendKey(keyString);
    if (DWC_Acc_CheckFriendKey(friendKey, 0x414d434a) == 0) {
        return 1;
    }
    if (friendKey == DWC_CreateFriendKey((DWCAccUserData *) gSaveData->mFirstBlock->mUserData)) {
        return 1;
    }
    DWC_CreateFriendKeyToken(friendData, friendKey, friendKey >> 32);
    friendDataList = (u8 *) gSaveData->mBuddyRecordBlock + 0x874;
    foundIndex = -1;
    for (i = 0; i < 60; i++) {
        u8 *entry;

        GetBuddyRecord(i, &buddyRecord);
        if (buddyRecord.mFilled == 1) {
            entry = friendDataList + i * 12;
            if (DWCi_Acc_IsValidFriendData(entry) != 0 &&
                DWC_IsEqualFriendData((DWCAccFriendData *) entry, (DWCAccFriendData *) friendData) != 0) {
                foundIndex = (s8) i;
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
    u8 i;
    u8 *friendDataList;

    friendDataList = (u8 *) gSaveData->mBuddyRecordBlock + 0x874;
    foundIndex = -1;
    for (i = 0; i < 60; i++) {
        u8 *entry;

        GetBuddyRecord(i, &buddyRecord);
        if (buddyRecord.mFilled == 1) {
            entry = friendDataList + i * 12;
            if (DWCi_Acc_IsValidFriendData(entry) != 0 && DWC_IsEqualFriendData((DWCAccFriendData *) entry, friendData) != 0) {
                foundIndex = (s8) i;
                break;
            }
        }
    }
    return foundIndex;
}

s32 AddOrUpdateBuddyRecord(u8 *friendDataList, void *name, u8 *friendData, s32 notYetBuddy, s32 e, s32 allowAdd) {
    DateBytes oldestDate;
    DateBytes recordDate;
    BuddyRecord buddyRecord;
    s32 today[3];
    s32 slotIndex;
    BOOL found;
    s32 oldestIndex;
    s32 i;
    u8 *entry;
    u8 year;
    u8 month;
    u8 day;
    u8 slot;

    slotIndex = -1;
    found = FALSE;
    GetDate(today);
    year = today[0];
    month = today[1];
    day = today[2];
    entry = friendDataList;
    for (i = 0; i < 60; i = (s8) (i + 1), entry += 12) {
        GetBuddyRecord((u8) i, &buddyRecord);
        if (buddyRecord.mFilled == 1 && DWCi_Acc_IsValidFriendData(friendData) != 0 && DWCi_Acc_IsValidFriendData(entry) != 0 &&
            DWC_IsEqualFriendData((DWCAccFriendData *) entry, (DWCAccFriendData *) friendData) != 0) {
            slotIndex = i;
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
        for (i = 0; i < 60; i = (s8) (i + 1)) {
            GetBuddyRecord((u8) i, &buddyRecord);
            if (buddyRecord.mFilled == 0) {
                slotIndex = i;
                break;
            }
        }
    }
    oldestIndex = -1;
    if (slotIndex == -1) {
        oldestDate.mYear = 100;
        oldestDate.mMonth = 12;
        oldestDate.mDay = 31;
        for (i = 0; i < 60; i = (s8) (i + 1)) {
            GetBuddyRecord((u8) i, &buddyRecord);
            recordDate.mYear = buddyRecord.mYear;
            recordDate.mMonth = buddyRecord.mMonth;
            recordDate.mDay = buddyRecord.mDay;
            if (buddyRecord.mFilled == 1 && buddyRecord.mFlagged == 0 &&
                IsDateEarlier(&recordDate, &oldestDate) != FALSE) {
                oldestDate = recordDate;
                oldestIndex = i;
            }
        }
        if (oldestIndex != -1) {
            slotIndex = oldestIndex;
        }
    }
    if (slotIndex == -1) {
        return -1;
    }
    MI_CpuCopy8(friendData, friendDataList + slotIndex * 12, 12);
    slot = slotIndex;
    GetBuddyRecord(slot, &buddyRecord);
    if (found == FALSE) {
        ResetBuddyRecord((u32) &buddyRecord);
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
    buddyRecord.field22_2 = e != 0;
    buddyRecord.mFilled = 1;
    SetBuddyRecord(slot, &buddyRecord);
    return slotIndex;
}

s32 AddBuddyFromFriendKey(const void *keyString, void *name) {
    u8 friendData[12];
    u64 friendKey;

    friendKey = DWC_Acc_NumericKeyToFriendKey(keyString);
    DWC_CreateFriendKeyToken(friendData, friendKey, friendKey >> 32);
    return AddOrUpdateBuddyRecord((u8 *) gSaveData->mBuddyRecordBlock + 0x874, name, friendData, 1, 0, 1);
}
