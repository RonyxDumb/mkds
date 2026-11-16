#include "Main/Scene/scene_frames.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"

u32 SceneReturnTerminateForPulledOut(void) {
    return 0x1u;
}

u32 ReturnNoTerminateForPulledOut(void) {
    return 0x0u;
}

u32 GetSceneFrames(void) {
    return (gSceneRunState->mSceneFrames);
}
