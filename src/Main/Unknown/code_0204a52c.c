#include "Main/Unknown/code_0204a52c.h"
#include "Main/Unknown/unk_02175000.h"

u32 scene_cardPulledOutCallbackDoStop(void) {
    return 0x1u;
}

u32 scene_cardPulledOutCallbackDontStop(void) {
    return 0x0u;
}

u32 scene_getSceneFrameCounter(void) {
    return (scene_sSceneState->mSceneFrames);
}
