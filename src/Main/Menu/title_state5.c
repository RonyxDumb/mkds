#include "Main/Menu/title_state5.h"
#include "Main/Menu/title_state4.h"
#include "Main/Sound/sound_seq.h"
#include "Main/MapObjects/data_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void UpdateTitleState5(SceneNumbers *sceneNumbers) {
    s16 nextScenes[5] = {1, 6, 12, 7, 8};

    if (sceneNumbers != NULL) {
        switch (gTitleScene->mSelectedIndex) {
            case 0:
            case 3:
            case 4:
            default:
                SetConnectionKind(0);
                break;
            case 1:
                SetConnectionKind(2);
                TitleSetWLMenuKind(0);
                break;
            case 2:
                SetConnectionKind(3);
                break;
        }
        sceneNumbers->mNextScene = nextScenes[gTitleScene->mSelectedIndex];
        StopSceneSeqWithFadeSteps();
    }
}

#pragma thumb off
