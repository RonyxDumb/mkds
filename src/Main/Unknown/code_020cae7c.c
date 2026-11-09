#include "Main/Unknown/code_020cae7c.h"
#include "Main/Unknown/code_020487fc.h"

#pragma thumb on
void RequestTitleScene(SceneNumbers *sceneNumbers) {
    if (sceneNumbers != NULL) {
        sceneNumbers->mNextScene = 0;
    }
}
#pragma thumb off
