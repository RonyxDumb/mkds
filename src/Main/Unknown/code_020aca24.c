#include "Main/Unknown/code_020aca24.h"
#include "Main/Unknown/code_020acaa4.h"
#include "Main/Unknown/code_02105e98.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void title_gotoSelectedRender(Unk020aca24 *a) {
    s16 v[5] = {1, 6, 12, 7, 8};

    if (a != NULL) {
        switch (sTitleSceneState->mSelectedIndex) {
            case 0:
            case 3:
            case 4:
            default:
                title_sysdat_setOverlayRelatedNum(0);
                break;
            case 1:
                title_sysdat_setOverlayRelatedNum(2);
                title_struct217B488_setField74(0);
                break;
            case 2:
                title_sysdat_setOverlayRelatedNum(3);
                break;
        }
        a->mNextScene = v[sTitleSceneState->mSelectedIndex];
        sound_2105E98();
    }
}

#pragma thumb off
