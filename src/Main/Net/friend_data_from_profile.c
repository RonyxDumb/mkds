#include "Main/Net/friend_data_from_profile.h"
#include "friend_data_account_fields.h"
#include "cpu_copy_fill.h"

#pragma thumb on

void InitFriendDataFromGsProfileId(DWCAccFriendData *friendData, u32 gsProfileId) {
    MI_CpuFill8(friendData, 0, 0xc);
    DWCi_Acc_SetGsProfileId(friendData, gsProfileId);
    SetFriendDataType(friendData, ACCOUNT_DATA_TYPE_GS_PROFILE_ID);
}

#pragma thumb off
