#include "Main/Menu/title_state6.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Scene/run_scene_connection.h"

#pragma thumb on

void TitleRequestNicknameSceneNop(void) {}

void UpdateTitleRequestNicknameScene(SceneNumbers *sceneNumbers) {
    if (sceneNumbers != 0) {
        sceneNumbers->mNextScene = 0xb;
        StopSceneSeqWithFadeSteps();
    }
}

#pragma thumb off
