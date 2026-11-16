#include "Main/Menu/title_blend.h"
#include "Main/Menu/title_bg.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

#pragma optimize_for_size on
#pragma thumb on

void Title_SomeBldalphaConfig_from_thumb(void) {
    s32 blendFrame;
    s32 fadeFrame;

    blendFrame = g_SceneTitleContext->mBlendFrames++;
    if (blendFrame < 30) {
        EnableAlphaSetTopBldcntBldalpha(4, 8, 0, 16);
    } else if (blendFrame < 47) {
        fadeFrame = blendFrame - 30;
        EnableAlphaSetTopBldcntBldalpha(4, 8, fadeFrame, 16 - fadeFrame);
    } else if (blendFrame < 107) {
        EnableAlphaSetTopBldcntBldalpha(0, 0, 0, 0);
    } else {
        EnableAlphaSetTopBldcntBldalpha(0, 0, 0, 0);
        SetB488TitleMenuSkipIntro(1);
        g_SceneTitleContext->mBlendDone = TRUE;
        g_SceneTitleContext->mBlendFrames--;
    }
}

#pragma thumb off
