#include "Main/Net/friend_data_type_wrapper.h"
#include "Main/Net/friend_data_type_non_zero.h"

#pragma thumb on
u32 IsFriendDataTypeNonZeroWrapper(const void *friendData) {
    return IsFriendDataTypeNonZero(friendData);
}
#pragma thumb off
