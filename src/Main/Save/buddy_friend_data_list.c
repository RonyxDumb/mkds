#include "Main/Save/buddy_friend_data_list.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0214d018.h"
#include "Main/Save/ghost_record_file.h"

void CopyBuddyFriendDataList(void *destination) {
    MI_CpuCopy8(gBackupBuffers->mBuddyRecordBlock->mFriendData, destination,
                sizeof(gBackupBuffers->mBuddyRecordBlock->mFriendData));
}
