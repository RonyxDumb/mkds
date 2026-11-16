#pragma once

#include "types.h"

// Stores 0 in gCameraEntryChanged and gEntryCameraUpdateRan. race_update calls it once per call before the camera steps.
u32 cam_2073E98(void);
