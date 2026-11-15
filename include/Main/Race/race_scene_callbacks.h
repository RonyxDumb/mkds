#pragma once
#include "types.h"
#include "Main/Scene/scene_display_archive_work.h" // SceneCallbacks
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"

// Objects whose layout isn't known yet.

extern void *gRaceDisplaySettingsDescs[7];

extern SceneCallbacks gRaceSceneCallbacks;

