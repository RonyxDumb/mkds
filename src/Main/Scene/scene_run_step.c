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
    u32 value0;
    value0 = 0x27fffa8u;
    value0 = *(const u16 *) ((value0) + (0));
    value0 = (value0) & (0x8000u);
    value0 = ((s32) value0 >> 15);
    return value0;
}

void SetMainMasterBrightness(s32 brightness) {
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, brightness);
}

void SetSubMasterBrightness(s32 brightness) {
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, brightness);
}
