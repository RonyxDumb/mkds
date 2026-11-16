#include "Main/Net/race_connection_flag.h"
#include "Main/System/backup_net_camera_work.h"

void ClearRaceConnectionFlag(void) {
    g_GlobalZE->mFlags &= ~CONNECTION_FLAG_RACE;
}
