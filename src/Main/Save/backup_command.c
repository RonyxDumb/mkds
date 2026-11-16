#include "Main/Save/backup_command.h"
#include "Main/Save/backup_enabled.h"
#include "Main/System/backup_net_camera_work.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Save/ghost_record_file.h"

#pragma optimize_for_size on

u32 IsBackupCommandRunning(void) {
    if (SaveDataIoManager_IsBusy() != 0) {
        return g_SaveDataIoManager->mCommandRunning;
    }
    return 0;
}

u32 IsBackupBusy(void) {
    return g_SaveDataHolder->mBusy != 0 ? 1 : IsBackupCommandRunning();
}
