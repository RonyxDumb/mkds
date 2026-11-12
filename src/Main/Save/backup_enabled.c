#include "Main/Save/backup_enabled.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"

u32 IsBackupEnabled(void) {
    u32 backupEnabled;
    backupEnabled = gBackupAccess->mBackupEnabled;
    return backupEnabled;
}
