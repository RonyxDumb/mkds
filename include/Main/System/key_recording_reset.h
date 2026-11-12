#pragma once

#include "types.h"
#include "Main/Scene/display_settings.h" // KeyRecording
#include "code_020182c0.h"
#include "Main/Menu/data_02175628.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"

void ResetKeyRecording(KeyRecording *record);
void ClearKeyRecordingBufferPointer(KeyRecording *record);
