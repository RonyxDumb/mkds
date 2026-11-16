#include "Main/Unknown/code_021524d8.h"
#include "Main/Unknown/code_021529e0.h"
#include "code_0214d018.h"
#include "code_02152a7c.h"

#pragma thumb on

void DWC_CreateFriendKeyToken(void *friendData, u32 friendKeyLow, u32 friendKeyHigh) {
    MI_CpuFill8(friendData, 0, 0xc);
    DWCi_Acc_SetFriendKey(friendData, friendKeyLow, friendKeyHigh);
    DWCi_Acc_SetFlag_DataType(friendData, 2);
}

#pragma thumb off
