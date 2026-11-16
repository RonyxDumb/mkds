#include "Main/Menu/title_registers.h"

#include "Main/Graphics/oam_upload.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

#pragma thumb on

void Scene_Title_VBlankImpl_from_thumb(void) {
    g_SceneTitleContext->mStateHandlers[g_SceneTitleContext->mState].mWriteRegisters();
    g_SceneTitleContext->mStateChanged = FALSE;
    NavigationContext_OnSceneVblank_from_thumb();
    CopyOamBuffersToMemory_from_thumb(&g_SceneTitleContext->mMainOam, &g_SceneTitleContext->mSubOam);
}

#pragma thumb off

void StructHU_IncrementSomeCounter(int *counter) {
    u32 value;
    value = *(u32 *) counter;
    if ((s32) value < 0x7fffffff) {
        *counter = value + 1;
    }
}
