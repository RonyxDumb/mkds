#include "Main/Unknown/code_0204a52c.h"
#include "Main/Unknown/unk_02175000.h"

u32 SceneReturnTerminateForPulledOut(void) {
    return 0x1u;
}

u32 ReturnNoTerminateForPulledOut(void) {
    return 0x0u;
}

u32 GetSceneFrames(void) {
    return (gSceneRunState->mSceneFrames);
}
