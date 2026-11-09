#include "Main/Unknown/code_0209b60c.h"
#include "Main/Unknown/code_0209bc74.h"

// Current frame of the .nsbca animation in slot 0: the whole-frame part of its 20.12 position.
u32 GetMapObjectModelNsbcaFrameIndex(MapObjectModel *model) {
    u32 value0 = model->mAnimations[0]->mHead.mFrameIndex;
    value0 = (value0 << 4);
    value0 = (value0 >> 16);
    return value0;
}

u32 GetMapObjectModelNsbtpFrameIndex(MapObjectModel *model) {
    u32 value0 = model->mAnimations[1]->mHead.mFrameIndex;
    value0 = (value0 << 4);
    value0 = (value0 >> 16);
    return value0;
}
