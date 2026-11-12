#include "Main/Graphics/model_animation_looping.h"
#include "Main/Graphics/model_animation.h"
#include "Main/Unknown/code_02087000.h"

void ResetModelAnimationLooping(ModelAnimationFrameLoop *animation, u32 frameCountFixed) {
    animation->mLoopMode = MODEL_ANIMATION_LOOP_MODE_WRAP;
    animation->mDone = 0;
    animation->mFrameStep = 0x1000;
    animation->mFrameCountFixed = frameCountFixed;
    animation->mFrameIndex = 0;
    animation->mLoopsDone = 0;
    animation->mLoopCount = 0;
}
