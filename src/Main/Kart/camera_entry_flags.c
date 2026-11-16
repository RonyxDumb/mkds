#include "Main/Kart/camera_entry_flags.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Kart/camera.h"

void ClearCameraEntryFlags(void) {
    gCameraEntryChanged = 0;
    gEntryCameraUpdateRan = 0;
}
