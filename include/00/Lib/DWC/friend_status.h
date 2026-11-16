#pragma once

#include "types.h"

// Values of GpBuddyStatus.mStatus: what a player's profile status says; set with DWCi_SetGPStatus and read from friends
// by DWC_GetFriendStatusSC.
enum {
    FRIEND_STATUS_OFFLINE,
    FRIEND_STATUS_ONLINE,
    FRIEND_STATUS_PLAYING,
    FRIEND_STATUS_MATCH_ANYBODY,
    FRIEND_STATUS_MATCH_FRIEND,
    FRIEND_STATUS_MATCH_SERVER = 6,
};

void DWC_DeleteBuddyFriendData(void *friendData);
s32 DWC_GetNumFriend(void *friendList, s32 friendListLength);
u8 DWC_GetFriendStatusSC(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString);

u8 DWC_GetFriendStatus(void *friendData, char *statusString);
