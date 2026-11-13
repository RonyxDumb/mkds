#include "Main/Net/wifi_race_sync_finish.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Save/ghost_record_file.h"

void SetWiFiRaceSyncFinishRecorded(void) {
    gWiFiRaceSync->mFinishRecorded = 1;
}
