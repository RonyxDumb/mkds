#include "Main/Save/backup_enabled.h"
#include "01/Menu/record_time_attack.h"

u32 IsBackupEnabled(void) {
    u32 backupEnabled;
    backupEnabled = gBackupAccess->mBackupEnabled;
    return backupEnabled;
}
