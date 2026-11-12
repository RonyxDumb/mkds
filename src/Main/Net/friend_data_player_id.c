#include "Main/Net/friend_data_player_id.h"
#include "code_02152490.h"

#pragma thumb on

u32 GetFriendDataPlayerId(const DWCAccFriendData *friendData) {
    return friendData->mUnk_08;
}

#pragma thumb off
