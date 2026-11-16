#include "Main/Unknown/code_020ad268.h"
#include "Main/Unknown/code_020ad2dc.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void title_updateIntro(void) {
    s32 n;
    s32 m;

    n = sTitleSceneState->mBlendFrames++;
    if (n < 30) {
        title_G2_SetBlendAlpha(4, 8, 0, 16);
    } else if (n < 47) {
        m = n - 30;
        title_G2_SetBlendAlpha(4, 8, m, 16 - m);
    } else if (n < 107) {
        title_G2_SetBlendAlpha(0, 0, 0, 0);
    } else {
        title_G2_SetBlendAlpha(0, 0, 0, 0);
        title_struct217B488_setTitleMenuSkipIntro(1);
        sTitleSceneState->mBlendDone = TRUE;
        sTitleSceneState->mBlendFrames--;
    }
}

#pragma thumb off
