#include "Main/Net/friend_data_from_profile.h"
#include "dwc_account.h"
#include "code_0214d018.h"

#pragma thumb on

void InitFriendDataFromGsProfileId(DWCAccFriendData *friendData, u32 gsProfileId) {
    MI_CpuFill8(friendData, 0, 0xc);
    DWCi_Acc_SetGsProfileId(friendData, gsProfileId);
    SetFriendDataType(friendData, 3);
}

#pragma thumb off
