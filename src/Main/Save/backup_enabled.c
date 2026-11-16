#include "Main/Save/backup_enabled.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"

u32 SaveDataIoManager_IsBusy(void) {
    u32 backupEnabled;
    backupEnabled = g_SaveDataIoManager->mBackupEnabled;
    return backupEnabled;
}
