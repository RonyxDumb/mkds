#pragma once

#include "types.h"

typedef struct BuddyRecordBlock BuddyRecordBlock;

void ReadSaveDataSection_FriendList_from_thumb(void *block);
void WriteSaveDataSection_FriendList_from_thumb(BuddyRecordBlock *block);
