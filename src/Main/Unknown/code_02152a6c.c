#include "Main/Unknown/code_02152a6c.h"
#include "code_02152490.h"

#pragma thumb on
u32 DWCi_Acc_GetFlags(const DWCAccFriendData *friendData) {
    return (friendData->field0 >> 11) & 0x1fffff;
}
#pragma thumb off
