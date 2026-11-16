#include "Main/Menu/title_request_nickname_scene.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/System/scene_numbers.h"
#include "Main/Scene/run_scene_connection.h"

#pragma thumb on

void TitleRequestNicknameSceneNop(void) {}

void UpdateTitleRequestNicknameScene(SceneNumbers *sceneNumbers) {
    if (sceneNumbers != 0) {
        sceneNumbers->mNextScene = SCENE_NICKNAME;
        StopSceneSeqWithFadeSteps();
    }
}

#pragma thumb off
