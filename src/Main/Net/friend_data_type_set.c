#include "Main/Net/friend_data_type_set.h"
#include "Main/Net/friend_data_flags_set.h"
#include "Main/Net/friend_data_flags_get.h"

#pragma thumb on
void SetFriendDataType(DWCAccFriendData *friendData, u32 dataType) {
    u32 flags;
    u32 value;
    flags = GetFriendDataFlags(friendData);
    value = 3;
    flags = flags & ~value;
    value = flags;
    value = value | dataType;
    SetFriendDataFlags(friendData, value);
}
#pragma thumb off
