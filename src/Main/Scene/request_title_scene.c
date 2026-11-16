#include "Main/Scene/request_title_scene.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/System/scene_numbers.h"

#pragma thumb on
void RequestTitleScene(SceneNumbers *sceneNumbers) {
    if (sceneNumbers != NULL) {
        sceneNumbers->mNextScene = SCENE_TITLE;
    }
}
#pragma thumb off
