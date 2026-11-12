#include "Main/Scene/request_ghost_scene.h"
#include "Main/Scene/run_scene_connection.h"

#pragma thumb on
void RequestGhostScene(SceneNumbers *sceneNumbers) {
    if (sceneNumbers != NULL) {
        sceneNumbers->mNextScene = 0xd;
    }
}
#pragma thumb off
