#include "Main/Unknown/code_02152918.h"
#include "Main/Unknown/unk_0216f000.h"
#include "os_printf.h"

#pragma thumb on

void DWC_Acc_FriendKeyToNumericKey(u32 low, u32 high, u32 buffer) {
    OS_SNPrintf((char *) buffer, 0xd, a012llu, low, high);
}

#pragma thumb off
