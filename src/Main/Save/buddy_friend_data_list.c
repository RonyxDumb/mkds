#include "Main/Save/buddy_friend_data_list.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record_file.h"

void GlobalZ_CopyNKFLOther1(void *destination) {
    Mem_CpuCopy8(g_SaveDataHolder->mBuddyRecordBlock->mFriendData, destination,
                sizeof(g_SaveDataHolder->mBuddyRecordBlock->mFriendData));
}
