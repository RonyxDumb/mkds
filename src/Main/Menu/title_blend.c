#include "Main/Menu/title_blend.h"
#include "Main/Menu/title_bg.h"
#include "Main/MapObjects/data_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void AdvanceTitleBlend(void) {
    s32 blendFrame;
    s32 fadeFrame;

    blendFrame = gTitleScene->mBlendFrames++;
    if (blendFrame < 30) {
        TitleWriteMainBlendAlpha(4, 8, 0, 16);
    } else if (blendFrame < 47) {
        fadeFrame = blendFrame - 30;
        TitleWriteMainBlendAlpha(4, 8, fadeFrame, 16 - fadeFrame);
    } else if (blendFrame < 107) {
        TitleWriteMainBlendAlpha(0, 0, 0, 0);
    } else {
        TitleWriteMainBlendAlpha(0, 0, 0, 0);
        SetTitleBlendDone(1);
        gTitleScene->mBlendDone = TRUE;
        gTitleScene->mBlendFrames--;
    }
}

#pragma thumb off
