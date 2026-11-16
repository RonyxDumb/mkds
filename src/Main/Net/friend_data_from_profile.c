#include "Main/Net/friend_data_from_profile.h"
#include "friend_data_account_fields.h"
#include "cpu_copy_fill.h"

#pragma thumb on

void InitFriendDataFromGsProfileId(DWCAccFriendData *friendData, u32 gsProfileId) {
    Mem_CpuFill8(friendData, 0, 0xc);
    FriendCode_SetProfileId_from_thumb(friendData, gsProfileId);
    FriendCode_SetState_from_thumb(friendData, 3);
}

#pragma thumb off
