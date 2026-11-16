#pragma once

#include "types.h"

// Stores 0 in gCameraEntryChanged and gEntryCameraUpdateRan. UpdateRace calls it once per call before the camera steps.
void ClearCameraEntryFlags(void);
