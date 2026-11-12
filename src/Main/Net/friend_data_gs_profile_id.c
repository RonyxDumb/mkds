#include "Main/Net/friend_data_gs_profile_id.h"
#include "code_02152490.h"

#pragma thumb on

u32 GetFriendDataGsProfileId(const DWCAccFriendData *friendData) {
    return friendData->mUnk_04;
}

#pragma thumb off
