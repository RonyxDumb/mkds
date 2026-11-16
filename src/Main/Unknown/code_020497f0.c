#include "Main/Unknown/code_020497f0.h"
#include "Main/Unknown/unk_02175000.h"

#include "gx.h"
#include "registers.h"

u32 scene_getState(void) {
    return (scene_sSceneState->mUnk_10c);
}

u32 scene_PAD_DetectFold(void) {
    u32 value0;
    value0 = 0x27fffa8u;
    value0 = *(const u16 *) ((value0) + (0));
    value0 = (value0) & (0x8000u);
    value0 = ((s32) value0 >> 15);
    return value0;
}

void scene_GX_SetMasterBrightness(s32 brightness) {
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, brightness);
}

void scene_GXS_SetMasterBrightness(s32 brightness) {
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, brightness);
}
