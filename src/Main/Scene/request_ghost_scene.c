#include "Main/Scene/request_ghost_scene.h"
#include "Main/System/scene_numbers.h"
#include "Main/Scene/run_scene_connection.h"

#pragma thumb on
void RequestGhostScene(SceneNumbers *sceneNumbers) {
    if (sceneNumbers != NULL) {
        sceneNumbers->mNextScene = SCENE_GHOST;
    }
}
#pragma thumb off
