#include "code_021526bc.h"
#include "Main/Net/friend_data_login_id.h"

#pragma thumb on

BOOL DWCi_Acc_IsAuthentic(const DWCAccUserData *userdata) {
    return IsFriendDataLoginId(&userdata->mAuthentic);
}

#pragma thumb off
