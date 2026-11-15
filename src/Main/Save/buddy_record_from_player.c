#include "Main/Save/buddy_record_from_player.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

// Stores the session player in the buddy records; the second argument allows adding a new record.
s32 SetBuddyRecordFromPlayer(PlayerRecord *player, u32 addIfMissing) {
    u32 flag = player->mHasEmblem;
    DWCAccFriendData *friendData = &player->mFriendData;
    u32 slot = AddOrUpdateBuddyRecord(gBackupBuffers->mBuddyRecordBlock->mFriendData, player, friendData, 0x0u, flag,
                                      addIfMissing);
    return slot;
}
