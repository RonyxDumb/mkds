#include "Main/Kart/camera_entry_flags.h"
#include "Main/Unknown/unk_0217a000.h"

void ClearCameraEntryFlags(void) {
    gCameraEntryChanged = 0;
    gEntryCameraUpdateRan = 0;
}
