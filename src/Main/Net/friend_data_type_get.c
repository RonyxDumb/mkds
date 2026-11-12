#include "Main/Net/friend_data_type_get.h"
#include "code_02152a24.h"

#pragma thumb on
u32 GetFriendDataType(const DWCAccFriendData *friendData) {
    return DWCi_Acc_GetFlag_DataType(friendData);
}
#pragma thumb off
