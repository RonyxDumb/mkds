#include "code_02152a7c.h"
#include "code_02152490.h"
#include "code_02152ac8.h"

#pragma thumb on

void DWCi_Acc_SetUserId(DWCAccFriendData *loginid, u32 useridLo, u32 useridHi) {
    enum { K0 } shift = K0;
    DWCi_Acc_SetMaskBits(&loginid->field0, useridHi, shift, 0x7ff);
    loginid->field4 = useridLo;
}

void DWCi_Acc_SetPlayerId(DWCAccFriendData *loginid, u32 playerid) {
    loginid->field8 = playerid;
}

void DWCi_Acc_SetFriendKey(DWCAccFriendData *data, u32 friendkeyLo, u32 friendkeyHi) {
    data->field4 = friendkeyLo;
    data->field8 = friendkeyHi;
}

void DWCi_Acc_SetGsProfileId(DWCAccFriendData *data, u32 gsProfileId) {
    data->field4 = gsProfileId;
}

#pragma thumb off
