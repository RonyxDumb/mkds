#include "Main/Save/buddy_records_write.h"
#include "Main/Save/backup_first_block_start_write.h"
#include "Main/Save/backup_buddy_record_block.h"
#include "Main/MapObjects/data_0217a000.h"

void WriteBackupBuddyRecords(void) {
    WriteBackupBuddyRecordBlock(gBackupBuffers->mBuddyRecordBlock);
}

void WriteBuddyRecordsAndFirstBlock(void) {
    WriteBackupBuddyRecordBlock(gBackupBuffers->mBuddyRecordBlock);
    StartWriteBackupFirstBlock();
}
