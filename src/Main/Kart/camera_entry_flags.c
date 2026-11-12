#include "Main/Kart/camera_entry_flags.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Kart/camera.h"

void ClearCameraEntryFlags(void) {
    gCameraEntryChanged = 0;
    gEntryCameraUpdateRan = 0;
}
