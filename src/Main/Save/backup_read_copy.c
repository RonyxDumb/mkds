#include "Main/Save/backup_read_copy.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "cpu_copy_fill.h"

#pragma thumb on
void CopyBackupReadToBlock(u32 *buffer, u32 length) {
    MI_CpuCopy8(buffer, gBackupAccess->mReadTarget, length);
}
#pragma thumb off
