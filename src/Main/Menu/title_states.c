#include "Main/Menu/title_states.h"
#include "Main/Menu/title_registers.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

#pragma optimize_for_size on
#pragma thumb on

void StructHU_InvokeFunc_from_thumb(s32 flag) {
    enum { STATE_INDEX_FIRST } stateIndex;
    OamBuffer_ResetValues16_from_thumb(&g_SceneTitleContext->mMainOam, &g_SceneTitleContext->mSubOam);
    stateIndex = g_SceneTitleContext->mState;
    g_SceneTitleContext->mStateHandlers[stateIndex].mUpdate(flag);
    StructHU_IncrementSomeCounter(&g_SceneTitleContext->mStateFrames);
    NavigationContext_OnSceneUpdate_from_thumb();
    OamBuffer_SomeFn2_from_thumb(&g_SceneTitleContext->mMainOam, &g_SceneTitleContext->mSubOam);
}

#pragma thumb off
