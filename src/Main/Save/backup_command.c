#include "Main/Save/backup_command.h"
#include "Main/Save/backup_enabled.h"
#include "Main/MapObjects/data_0217a000.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"

#pragma optimize_for_size on

u32 IsBackupCommandRunning(void) {
    if (IsBackupEnabled() != 0) {
        return gBackupAccess->mCommandRunning;
    }
    return 0;
}

u32 IsBackupBusy(void) {
    return gBackupBuffers->mBusy != 0 ? 1 : IsBackupCommandRunning();
}
