#include "Main/Unknown/code_02057244.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on
void ClearBuddyRecordBlock(void) {
    MI_CpuFill8(data_0217aa08->mBuddyRecordBlock, 0u, 0xc00u);
}
#pragma thumb off
