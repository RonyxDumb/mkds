#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_020574a0.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/unk_0217a000.h"

void WriteBackupBuddyRecords(void) {
    WriteBackupBuddyRecordBlock(data_0217aa08->mBuddyRecordBlock);
}

void WriteBuddyRecordsAndFirstBlock(void) {
    WriteBackupBuddyRecordBlock(data_0217aa08->mBuddyRecordBlock);
    StartWriteBackupFirstBlock();
}
