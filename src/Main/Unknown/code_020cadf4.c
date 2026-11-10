#include "Main/Unknown/code_020cadf4.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_020cae24.h"
#include "Main/Unknown/code_020cae38.h"
#include "Main/Unknown/code_020cae54.h"

#pragma thumb on
#pragma optimize_for_size on
void RequestRaceOrWLMenuScene(SceneNumbers *sceneNumbers) {
    if (sceneNumbers != NULL) {
        if (MenuGetConnectionKind() != 0 && GetMultiSimple() != 0) {
            sceneNumbers->mNextScene = 6;
            SetWLMenuKind(1);
        } else {
            sceneNumbers->mNextScene = 2;
        }
    }
}
#pragma thumb off
