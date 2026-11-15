#include "Main/Save/backup_first_block_records.h"
#include "Main/Save/buddy_record_clear.h"
#include "Main/Save/ghost_clear.h"
#include "Main/Save/emblem_record.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/backup_busy.h"
#include "Main/Save/backup_buddy_record_block.h"
#include "Main/Save/backup.h"
#include "Main/Save/backup_first_block.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void ResetBackupFirstBlockAndRecords(u32 copyOwnerName) {
    ClearEmblemRecord();
    ClearGrandPrixRecordBlock();
    ClearCourseTimeRecordBlock();
    ClearMissionRecordBlock();
    ClearCourseAndFirstSlotGhost();
    ClearBuddyRecordBlock();
    ResetBackupFirstBlock(copyOwnerName);
}

void WriteBackupFirstBlockAndRecords(void) {
    WriteBackupEmblemRecord(gBackupBuffers->mEmblemRecord);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupGrandPrixRecordBlock(gBackupBuffers->mGrandPrixRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupCourseTimeRecordBlock(gBackupBuffers->mCourseTimeRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupMissionRecordBlock(gBackupBuffers->mMissionRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupBuddyRecordBlock(gBackupBuffers->mBuddyRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupFirstBlock(gBackupBuffers->mFirstBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    ClearBackupBusy();
}

#pragma thumb off
