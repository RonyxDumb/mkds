#include "Main/Save/backup_read_copy.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "cpu_copy_fill.h"

#pragma thumb on
void CopyToSXSomePtr_from_thumb(u32 *buffer, u32 length) {
    Mem_CpuCopy8(buffer, g_SaveDataIoManager->mReadTarget, length);
}
#pragma thumb off
