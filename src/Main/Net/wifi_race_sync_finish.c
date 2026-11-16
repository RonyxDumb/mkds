#include "Main/Net/wifi_race_sync_finish.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

void SetWiFiRaceSyncFinishRecorded(void) {
    g_GlobalAA->mFinishRecorded = 1;
}
