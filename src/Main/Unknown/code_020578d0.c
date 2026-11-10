#include "Main/Unknown/code_020578d0.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on
void CopyBackupReadToGhostRecordHead(u32 *buffer, u32 length) {
    MI_CpuCopy8(buffer, gBackupAccess->mReadTarget, 48u);
}
#pragma thumb off

#pragma thumb on
void CopyBackupReadToGhostListEntry(u32 *buffer, u32 length) {
    MI_CpuCopy8(buffer, gBackupAccess->mReadTarget, 0x230u);
}
#pragma thumb off
