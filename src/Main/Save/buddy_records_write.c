#include "Main/Save/buddy_records_write.h"
#include "Main/Save/backup_first_block_start_write.h"
#include "Main/Save/backup_buddy_record_block.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

void WriteBackupBuddyRecords(void) {
    WriteBackupBuddyRecordBlock(gBackupBuffers->mBuddyRecordBlock);
}

void WriteBuddyRecordsAndFirstBlock(void) {
    WriteBackupBuddyRecordBlock(gBackupBuffers->mBuddyRecordBlock);
    StartWriteBackupFirstBlock();
}
