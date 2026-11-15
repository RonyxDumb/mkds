#include "Main/Scene/scene_run_step.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"

#include "gx.h"
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
