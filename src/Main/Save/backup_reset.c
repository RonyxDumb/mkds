#include "Main/Save/backup_reset.h"
#include "Main/Save/backup_first_block_records.h"
#include "Main/Save/buddy_record_clear.h"
#include "Main/Save/emblem_record.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/backup_busy.h"
#include "Main/Save/backup_buddy_record_block.h"
#include "Main/Save/backup.h"
#include "Main/Save/backup_first_block.h"
#include "Main/Menu/select_race_rule_state.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void OverwriteEmptySaveData_from_thumb(void) {
    ClearAllSaveDataSections_from_thumb(gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT);
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        EnableMKDSSVSomeFlag_from_thumb();
        WorkerInsertTask(Task_WriteNonGhostSaveData_from_thumb);
        g_WorkerContext->mRunRequested = 1;
    }
}

void Task_ReadNonGhostSaveData_from_thumb(void) {
    u16 failedBlockBits;

    failedBlockBits = 0;
    g_SaveDataHolder->mReadStatus = 0;
    ReadSaveDataSection_Header_from_thumb(g_SaveDataHolder->mFirstBlock);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    if (g_SaveDataIoManager->mErrorCode != BACKUP_ERROR_NONE) {
        if (g_SaveDataIoManager->mErrorCode == BACKUP_ERROR_BAD_PREFIX) {
            g_SaveDataHolder->mFailedBlockBits = BACKUP_FAILED_ALL;
            g_SaveDataHolder->mReadStatus = BACKUP_READ_STATUS_BAD_PREFIX;
            ResetSaveDataHolderTaskPendingFlag_from_thumb();
            return;
        }
        failedBlockBits |= BACKUP_FAILED_FIRST_BLOCK;
    }
    ReadSaveDataSection_Emblem_from_thumb(g_SaveDataHolder->mEmblemRecord);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    if (g_SaveDataIoManager->mErrorCode != BACKUP_ERROR_NONE) {
        failedBlockBits |= BACKUP_FAILED_EMBLEM_RECORD;
    }
    ReadSaveDataSection_GrandPrix_from_thumb(g_SaveDataHolder->mGrandPrixRecordBlock);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    if (g_SaveDataIoManager->mErrorCode != BACKUP_ERROR_NONE) {
        failedBlockBits |= BACKUP_FAILED_GRAND_PRIX_RECORD;
    }
    ReadSaveDataSection_TimeTrial_from_thumb(g_SaveDataHolder->mCourseTimeRecordBlock);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    if (g_SaveDataIoManager->mErrorCode != BACKUP_ERROR_NONE) {
        failedBlockBits |= BACKUP_FAILED_COURSE_TIME_RECORD;
    }
    ReadSaveDataSection_MissionRun_from_thumb(g_SaveDataHolder->mMissionRecordBlock);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    if (g_SaveDataIoManager->mErrorCode != BACKUP_ERROR_NONE) {
        failedBlockBits |= BACKUP_FAILED_MISSION_RECORD;
    }
    ReadSaveDataSection_FriendList_from_thumb(g_SaveDataHolder->mBuddyRecordBlock);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    if (g_SaveDataIoManager->mErrorCode != BACKUP_ERROR_NONE) {
        failedBlockBits |= BACKUP_FAILED_BUDDY_RECORD;
    }
    if (g_SaveDataHolder->mReadStatus == 0) {
        if (failedBlockBits != 0) {
            g_SaveDataHolder->mReadStatus = BACKUP_READ_STATUS_BLOCKS_FAILED;
        } else {
            g_SaveDataHolder->mReadStatus = 0;
        }
    }
    g_SaveDataHolder->mFailedBlockBits = failedBlockBits;
    ResetSaveDataHolderTaskPendingFlag_from_thumb();
}

void ReadSaveData_NonGhost_from_thumb(void) {
    g_SaveDataHolder->mUnk_44_0 = 1;
    g_SaveDataHolder->mUnk_3c = 0;
    g_SaveDataHolder->mFailedBlockBits = 0;
    EnableMKDSSVSomeFlag_from_thumb();
    WorkerInsertTask(Task_ReadNonGhostSaveData_from_thumb);
    g_WorkerContext->mRunRequested = 1;
}

void Task_EraseNonGhostSaveDataSections_from_thumb(void) {
    if (g_SaveDataHolder->mFailedBlockBits & BACKUP_FAILED_EMBLEM_RECORD) {
        ClearSaveDataSection_Emblem_from_thumb();
        WriteSaveDataSection_Emblem_from_thumb(g_SaveDataHolder->mEmblemRecord);
        if (g_SaveDataIoManager->mBackupEnabled != 0) {
            j_WaitForPendingCardOperation();
        }
    }
    if (g_SaveDataHolder->mFailedBlockBits & BACKUP_FAILED_GRAND_PRIX_RECORD) {
        ClearSaveDataSection_GrandPrix_from_thumb();
        WriteSaveDataSection_GrandPrix_from_thumb(g_SaveDataHolder->mGrandPrixRecordBlock);
        if (g_SaveDataIoManager->mBackupEnabled != 0) {
            j_WaitForPendingCardOperation();
        }
    }
    if (g_SaveDataHolder->mFailedBlockBits & BACKUP_FAILED_COURSE_TIME_RECORD) {
        ClearSaveDataSection_TimeTrials_from_thumb();
        WriteSaveDataSection_TimeTrials_from_thumb(g_SaveDataHolder->mCourseTimeRecordBlock);
        if (g_SaveDataIoManager->mBackupEnabled != 0) {
            j_WaitForPendingCardOperation();
        }
    }
    if (g_SaveDataHolder->mFailedBlockBits & BACKUP_FAILED_MISSION_RECORD) {
        ClearSaveDataSection_MissionRun_from_thumb();
        WriteSaveDataSection_MissionRun_from_thumb(g_SaveDataHolder->mMissionRecordBlock);
        if (g_SaveDataIoManager->mBackupEnabled != 0) {
            j_WaitForPendingCardOperation();
        }
    }
    if (g_SaveDataHolder->mFailedBlockBits & BACKUP_FAILED_BUDDY_RECORD) {
        ClearSaveDataSection_FriendList_from_thumb();
        WriteSaveDataSection_FriendList_from_thumb(g_SaveDataHolder->mBuddyRecordBlock);
        if (g_SaveDataIoManager->mBackupEnabled != 0) {
            j_WaitForPendingCardOperation();
        }
    }
    if (g_SaveDataHolder->mFailedBlockBits & 1) {
        ClearSaveDataSection_Header_from_thumb(gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT);
        WriteSaveDataSection_Header_from_thumb(g_SaveDataHolder->mFirstBlock);
        if (g_SaveDataIoManager->mBackupEnabled != 0) {
            j_WaitForPendingCardOperation();
        }
    }
    g_SaveDataHolder->mFailedBlockBits = 0;
    ResetSaveDataHolderTaskPendingFlag_from_thumb();
}

void EraseNonGhostSaveDataSections_from_thumb(void) {
    EnableMKDSSVSomeFlag_from_thumb();
    WorkerInsertTask(Task_EraseNonGhostSaveDataSections_from_thumb);
    g_WorkerContext->mRunRequested = 1;
}

void SetSavedSecretFlag_from_thumb(s32 flagIndex) {
    u8 *flagBytes;

    flagBytes = g_SaveDataHolder->mFirstBlock->mFlags;
    flagBytes[flagIndex >> 3] |= 1 << (flagIndex & 7);
}

BOOL CheckSecretFlagWith_from_thumb(s32 bitIndex, u8 *bytes) {
    u32 isSet;

    isSet = 1;
    if (((1 << (bitIndex & 7)) & bytes[bitIndex >> 3]) == 0) {
        isSet = 0;
    }
    return isSet;
}

BOOL CheckSavedSecretFlag_from_thumb(u32 flagIndex) {
    return CheckSecretFlagWith_from_thumb(flagIndex, g_SaveDataHolder->mFirstBlock->mFlags);
}

u8 CheckExtraKartUnlockFlagsWith_from_thumb(u8 *bytes) {
    u8 result;

    result = 1;
    if (CheckSecretFlagWith_from_thumb(0x13, bytes)) {
        result = 4;
    } else if (CheckSecretFlagWith_from_thumb(0x12, bytes)) {
        result = 3;
    } else if (CheckSecretFlagWith_from_thumb(0x11, bytes)) {
        result = 2;
    }
    return result;
}

u8 CheckExtraKartUnlockFlags_from_thumb(void) {
    return CheckExtraKartUnlockFlagsWith_from_thumb(g_SaveDataHolder->mFirstBlock->mFlags);
}

void SetMKDSSVExtraKartUnlockFlagsByState_from_thumb(u32 value) {
    u8 *flagBytes;

    if (value > 3) {
        flagBytes = g_SaveDataHolder->mFirstBlock->mFlags;
        flagBytes[2] |= 8;
    }
    if (value > 2) {
        flagBytes = g_SaveDataHolder->mFirstBlock->mFlags;
        flagBytes[2] |= 4;
    }
    if (value > 1) {
        flagBytes = g_SaveDataHolder->mFirstBlock->mFlags;
        flagBytes[2] |= 2;
    }
}

#pragma thumb off
