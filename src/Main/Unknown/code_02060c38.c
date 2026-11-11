#include "Main/Unknown/code_02060c38.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

void CopyBuddyFriendDataList(void *destination) {
    MI_CpuCopy8(&gBackupBuffers->mBuddyRecordBlock->mRecords[60], destination, 0x2d0);
}
