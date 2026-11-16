#include "Main/Unknown/code_021529e0.h"
#include "Main/Unknown/code_02152a04.h"
#include "Main/Unknown/code_02152a6c.h"

#pragma thumb on
void DWCi_Acc_SetFlag_DataType(DWCAccFriendData *friendData, u32 dataType) {
    u32 flags;
    u32 d;
    flags = DWCi_Acc_GetFlags(friendData);
    d = 3;
    flags = flags & ~d;
    d = flags;
    d = d | dataType;
    DWCi_Acc_SetFlags(friendData, d);
}
#pragma thumb off
