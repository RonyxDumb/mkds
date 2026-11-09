#include "Main/Unknown/code_02057cfc.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on
void CopyBackupReadToBlock(u32 *buffer, u32 length) {
    MI_CpuCopy8(buffer, gBackupAccess->mReadTarget, length);
}
#pragma thumb off
