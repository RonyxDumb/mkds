#pragma once

#include "types.h"

// Values of GpBuddyStatus.mStatus: what a player's profile status says; set with DWCi_SetGPStatus and read from friends
// by DWC_GetFriendStatusSC.
enum {
    DWC_STATUS_OFFLINE,
    DWC_STATUS_ONLINE,
    DWC_STATUS_PLAYING,
    DWC_STATUS_MATCH_ANYBODY,
    DWC_STATUS_MATCH_FRIEND,
    DWC_STATUS_MATCH_SC_CL,
    DWC_STATUS_MATCH_SC_SV,
};

void DWC_DeleteBuddyFriendData(void *friendData);
s32 DWC_GetNumFriend(void *friendList, s32 friendListLength);
u8 DWC_GetFriendStatusSC(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString);

u8 DWC_GetFriendStatus(void *friendData, char *statusString);
