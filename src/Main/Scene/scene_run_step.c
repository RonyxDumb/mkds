#include "Main/Scene/scene_run_step.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"

#include "fixed_point_graphics_setup.h"
#include "registers.h"

u32 GetSceneRunStep(void) {
    return (gSceneRunState->mRunStep);
}

u32 SceneRunPAD_DetectFold(void) {
    u32 foldState;
    foldState = 0x27fffa8u;
    foldState = *(const u16 *) ((foldState) + (0));
    foldState = (foldState) & (0x8000u);
    foldState = ((s32) foldState >> 15);
    return foldState;
}

void SetMainMasterBrightness(s32 brightness) {
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, brightness);
}

void SetSubMasterBrightness(s32 brightness) {
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, brightness);
}
