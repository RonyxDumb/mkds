#pragma once

#include "types.h"
#include "Main/Scene/display_settings.h" // KeyRecording
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"

void ResetKeyRecording(KeyRecording *record);
void ClearKeyRecordingBufferPointer(KeyRecording *record);
