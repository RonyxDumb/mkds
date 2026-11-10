#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_02087d0c.h"

void SetModelAnimationEntryLoopMode(ModelAnimation *animation, u32 entryIndex, u32 loopFlag) {
    u32 *loopFlags = *OFFSET_PTR(u32 *, animation, 32);
    loopFlags[entryIndex] = loopFlag;
    animation->mHead.mLoopMode = loopFlag;
}
