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

void ResetBackupAndStartWrite(void) {
    ResetBackupFirstBlockAndRecords(gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT);
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        SetBackupBusy();
        QueueThreadFunction(WriteBackupFirstBlockAndRecords);
        gThreadFunctionQueue->mRunRequested = 1;
    }
}

void ReadBackupFirstBlockAndRecords(void) {
    u16 failedBlockBits;

    failedBlockBits = 0;
    gBackupBuffers->mReadStatus = BACKUP_READ_STATUS_OK;
    ReadBackupFirstBlock(gBackupBuffers->mFirstBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != BACKUP_ERROR_NONE) {
        if (gBackupAccess->mErrorCode == BACKUP_ERROR_BAD_PREFIX) {
            gBackupBuffers->mFailedBlockBits = BACKUP_FAILED_ALL;
            gBackupBuffers->mReadStatus = BACKUP_READ_STATUS_BAD_PREFIX;
            ClearBackupBusy();
            return;
        }
        failedBlockBits |= BACKUP_FAILED_FIRST_BLOCK;
    }
    ReadBackupEmblemRecord(gBackupBuffers->mEmblemRecord);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != BACKUP_ERROR_NONE) {
        failedBlockBits |= BACKUP_FAILED_EMBLEM_RECORD;
    }
    ReadBackupGrandPrixRecordBlock(gBackupBuffers->mGrandPrixRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != BACKUP_ERROR_NONE) {
        failedBlockBits |= BACKUP_FAILED_GRAND_PRIX_RECORD;
    }
    ReadBackupCourseTimeRecordBlock(gBackupBuffers->mCourseTimeRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != BACKUP_ERROR_NONE) {
        failedBlockBits |= BACKUP_FAILED_COURSE_TIME_RECORD;
    }
    ReadBackupMissionRecordBlock(gBackupBuffers->mMissionRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != BACKUP_ERROR_NONE) {
        failedBlockBits |= BACKUP_FAILED_MISSION_RECORD;
    }
    ReadBackupBuddyRecordBlock(gBackupBuffers->mBuddyRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != BACKUP_ERROR_NONE) {
        failedBlockBits |= BACKUP_FAILED_BUDDY_RECORD;
    }
    if (gBackupBuffers->mReadStatus == BACKUP_READ_STATUS_OK) {
        if (failedBlockBits != 0) {
            gBackupBuffers->mReadStatus = BACKUP_READ_STATUS_BLOCKS_FAILED;
        } else {
            gBackupBuffers->mReadStatus = BACKUP_READ_STATUS_OK;
        }
    }
    gBackupBuffers->mFailedBlockBits = failedBlockBits;
    ClearBackupBusy();
}

void StartReadBackupFirstBlockAndRecords(void) {
    gBackupBuffers->mUnk_44_0 = 1;
    gBackupBuffers->mUnk_3c = 0;
    gBackupBuffers->mFailedBlockBits = 0;
    SetBackupBusy();
    QueueThreadFunction(ReadBackupFirstBlockAndRecords);
    gThreadFunctionQueue->mRunRequested = 1;
}

void ResetFailedBackupBlocks(void) {
    if (gBackupBuffers->mFailedBlockBits & BACKUP_FAILED_EMBLEM_RECORD) {
        ClearEmblemRecord();
        WriteBackupEmblemRecord(gBackupBuffers->mEmblemRecord);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gBackupBuffers->mFailedBlockBits & BACKUP_FAILED_GRAND_PRIX_RECORD) {
        ClearGrandPrixRecordBlock();
        WriteBackupGrandPrixRecordBlock(gBackupBuffers->mGrandPrixRecordBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gBackupBuffers->mFailedBlockBits & BACKUP_FAILED_COURSE_TIME_RECORD) {
        ClearCourseTimeRecordBlock();
        WriteBackupCourseTimeRecordBlock(gBackupBuffers->mCourseTimeRecordBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gBackupBuffers->mFailedBlockBits & BACKUP_FAILED_MISSION_RECORD) {
        ClearMissionRecordBlock();
        WriteBackupMissionRecordBlock(gBackupBuffers->mMissionRecordBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gBackupBuffers->mFailedBlockBits & BACKUP_FAILED_BUDDY_RECORD) {
        ClearBuddyRecordBlock();
        WriteBackupBuddyRecordBlock(gBackupBuffers->mBuddyRecordBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (gBackupBuffers->mFailedBlockBits & BACKUP_FAILED_FIRST_BLOCK) {
        ResetBackupFirstBlock(gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT);
        WriteBackupFirstBlock(gBackupBuffers->mFirstBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    gBackupBuffers->mFailedBlockBits = 0;
    ClearBackupBusy();
}

void StartResetFailedBackupBlocks(void) {
    SetBackupBusy();
    QueueThreadFunction(ResetFailedBackupBlocks);
    gThreadFunctionQueue->mRunRequested = 1;
}

void SetBackupFlag(s32 flagIndex) {
    u8 *flagBytes;

    flagBytes = gBackupBuffers->mFirstBlock->mFlags;
    flagBytes[flagIndex >> 3] |= 1 << (flagIndex & 7);
}

BOOL IsBitSetInBytes(s32 bitIndex, u8 *bytes) {
    u32 isSet;

    isSet = 1;
    if (((1 << (bitIndex & 7)) & bytes[bitIndex >> 3]) == 0) {
        isSet = 0;
    }
    return isSet;
}

BOOL IsBackupFlagSet(u32 flagIndex) {
    return IsBitSetInBytes(flagIndex, gBackupBuffers->mFirstBlock->mFlags);
}

u8 GetKartAppearLimitFromBits(u8 *bytes) {
    u8 result;

    result = 1;
    if (IsBitSetInBytes(0x13, bytes)) {
        result = 4;
    } else if (IsBitSetInBytes(0x12, bytes)) {
        result = 3;
    } else if (IsBitSetInBytes(0x11, bytes)) {
        result = 2;
    }
    return result;
}

u8 GetKartAppearLimit(void) {
    return GetKartAppearLimitFromBits(gBackupBuffers->mFirstBlock->mFlags);
}

void RaiseKartAppearLimit(u32 value) {
    u8 *flagBytes;

    if (value > 3) {
        flagBytes = gBackupBuffers->mFirstBlock->mFlags;
        flagBytes[2] |= 8;
    }
    if (value > 2) {
        flagBytes = gBackupBuffers->mFirstBlock->mFlags;
        flagBytes[2] |= 4;
    }
    if (value > 1) {
        flagBytes = gBackupBuffers->mFirstBlock->mFlags;
        flagBytes[2] |= 2;
    }
}

#pragma thumb off
