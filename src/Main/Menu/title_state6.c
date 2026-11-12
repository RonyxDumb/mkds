#include "Main/Menu/title_state6.h"
#include "Main/Unknown/code_02105e98.h"
#include "Main/Scene/run_scene_connection.h"

#pragma thumb on

u32 TitleState6ReturnArgument(u32 value) {
    return value;
}

void UpdateTitleState6(SceneNumbers *sceneNumbers) {
    if (sceneNumbers != 0) {
        sceneNumbers->mNextScene = 0xb;
        StopSceneSeqWithFadeSteps();
    }
}

#pragma thumb off
