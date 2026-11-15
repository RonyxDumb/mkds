#include "Main/Scene/scene_frames.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
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
