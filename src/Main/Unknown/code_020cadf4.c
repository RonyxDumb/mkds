#include "Main/Unknown/code_020cadf4.h"
#include "Main/Unknown/code_020cae24.h"
#include "Main/Unknown/code_020cae38.h"
#include "Main/Unknown/code_020cae54.h"

#pragma thumb on
#pragma optimize_for_size on
void RequestRaceOrWLMenuScene(Unk020cadf4 *sceneNumbers) {
    if (sceneNumbers != NULL) {
        if (MenuGetConnectionKind() != 0 && func_020cae38() != 0) {
            sceneNumbers->mUnk_04 = 6;
            func_020cae24(1);
        } else {
            sceneNumbers->mUnk_04 = 2;
        }
    }
}
#pragma thumb off
