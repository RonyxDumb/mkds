#include "Main/Save/buddy_friend_data_list.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record_file.h"

void CopyBuddyFriendDataList(void *destination) {
    MI_CpuCopy8(gBackupBuffers->mBuddyRecordBlock->mFriendData, destination,
                sizeof(gBackupBuffers->mBuddyRecordBlock->mFriendData));
}
