#include "Main/Save/buddy_record_clear.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on
void ClearSaveDataSection_FriendList_from_thumb(void) {
    Mem_CpuFill8(g_SaveDataHolder->mBuddyRecordBlock, 0u, sizeof(BuddyRecordBlock));
}
#pragma thumb off
