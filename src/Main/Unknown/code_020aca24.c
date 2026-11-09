#include "Main/Unknown/code_020aca24.h"
#include "Main/Unknown/code_020acaa4.h"
#include "Main/Unknown/code_02105e98.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void UpdateTitleState5(SceneNumbers *a) {
    s16 v[5] = {1, 6, 12, 7, 8};

    if (a != NULL) {
        switch (gTitleScene->mSelectedIndex) {
            case 0:
            case 3:
            case 4:
            default:
                SetConnectionKind(0);
                break;
            case 1:
                SetConnectionKind(2);
                func_020acaa4(0);
                break;
            case 2:
                SetConnectionKind(3);
                break;
        }
        a->mNextScene = v[gTitleScene->mSelectedIndex];
        StopSceneSeqWithFadeSteps();
    }
}

#pragma thumb off
