#include "Main/Graphics/model_animation_loop_mode.h"
#include "Main/Graphics/model_animation.h"

void SetModelAnimationEntryLoopMode(ModelAnimation *animation, u32 entryIndex, u32 loopFlag) {
    u32 *loopFlags = *OFFSET_PTR(u32 *, animation, 32);
    loopFlags[entryIndex] = loopFlag;
    animation->mHead.mLoopMode = loopFlag;
}
