#pragma once

#include "types.h"
#include "Main/Scene/display_settings.h" // KeyRecording
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"

void FinishKeyRecording(KeyRecording *record);
