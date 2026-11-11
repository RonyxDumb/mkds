#pragma once

#include "types.h"

void RemoveBuddyEntry(void *friendData);
s32 DWC_GetNumFriend(void *friendList, s32 friendListLength);
u8 DWC_GetFriendStatusSC(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString);
