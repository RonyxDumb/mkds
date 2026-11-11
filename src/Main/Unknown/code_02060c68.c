#include "Main/Unknown/code_02060c68.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/unk_0217a000.h"

// Stores the session player in the buddy records; the second argument allows adding a new record.
s32 SetBuddyRecordFromPlayer(PlayerRecord *player, u32 addIfMissing) {
    u32 flag = player->mHasEmblem;
    DWCAccFriendData *friendData = &player->mFriendData;
    u32 slot = AddOrUpdateBuddyRecord(gBackupBuffers->mBuddyRecordBlock->mFriendData, player, friendData, 0x0u, flag,
                                      addIfMissing);
    return slot;
}
