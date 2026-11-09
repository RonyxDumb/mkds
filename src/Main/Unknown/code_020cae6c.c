#include "Main/Unknown/code_020cae6c.h"
#include "Main/Unknown/code_020cadf4.h"

#pragma thumb on
void RequestGhostScene(Unk020cadf4 *sceneNumbers) {
    if (sceneNumbers != NULL) {
        sceneNumbers->mUnk_04 = 0xd;
    }
}
#pragma thumb off
