#include "Main/Scene/request_title_scene.h"
#include "Main/Scene/run_scene_connection.h"

#pragma thumb on
void RequestTitleScene(SceneNumbers *sceneNumbers) {
    if (sceneNumbers != NULL) {
        sceneNumbers->mNextScene = 0;
    }
}
#pragma thumb off
