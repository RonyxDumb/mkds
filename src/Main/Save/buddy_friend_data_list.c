#include "Main/Save/buddy_friend_data_list.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0214d018.h"

void CopyBuddyFriendDataList(void *destination) {
    MI_CpuCopy8(&gBackupBuffers->mBuddyRecordBlock->mRecords[60], destination, 0x2d0);
}
