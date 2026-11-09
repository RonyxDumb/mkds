#include "Main/Unknown/code_020cae6c.h"
#include "Main/Unknown/code_020487fc.h"

#pragma thumb on
void RequestGhostScene(SceneNumbers *sceneNumbers) {
    if (sceneNumbers != NULL) {
        sceneNumbers->mNextScene = 0xd;
    }
}
#pragma thumb off
