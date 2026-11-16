#include "code_02152ab4.h"
#include "code_02152490.h"

#pragma thumb on

u64 DWCi_Acc_GetFriendKey(const DWCAccFriendData *data) {
    return (u64) data->field8 << 32 | data->field4;
}

#pragma thumb off
