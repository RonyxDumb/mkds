#include "Main/Unknown/code_02060c68.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/unk_0217a000.h"

// Stores the session player in the buddy records; the second argument allows adding a new record.
s32 SetBuddyRecordFromPlayer(Unk0217aa00_45c *player, u32 addIfMissing) {
    u32 flag = player->mUnk_214;
    DWCAccFriendData *friendData = &player->mUnk_218;
    u32 slot = AddOrUpdateBuddyRecord(data_0217aa08->mBuddyRecordBlock->mUnk_874, player, friendData, 0x0u, flag,
                                      addIfMissing);
    return slot;
}
