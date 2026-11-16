#include "Main/Save/buddy_records_write.h"
#include "Main/Save/backup_first_block_start_write.h"
#include "Main/Save/backup_buddy_record_block.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

void WriteFriendListSaveDataSection(void) {
    WriteSaveDataSection_FriendList_from_thumb(g_SaveDataHolder->mBuddyRecordBlock);
}

void SaveFriendList(void) {
    WriteSaveDataSection_FriendList_from_thumb(g_SaveDataHolder->mBuddyRecordBlock);
    WriteSaveDataHeader_from_thumb();
}
