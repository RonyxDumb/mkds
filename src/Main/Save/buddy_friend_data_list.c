#include "Main/Save/buddy_friend_data_list.h"
#include "Main/System/backup_net_camera_work.h"
#include "code_0214d018.h"
#include "Main/Save/ghost_record_file.h"

void CopyBuddyFriendDataList(void *destination) {
    MI_CpuCopy8(gBackupBuffers->mBuddyRecordBlock->mFriendData, destination,
                sizeof(gBackupBuffers->mBuddyRecordBlock->mFriendData));
}
