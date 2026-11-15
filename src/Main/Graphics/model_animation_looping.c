#include "Main/Graphics/model_animation_looping.h"
#include "Main/Graphics/model_animation.h"
#include "Main/Graphics/data_02087000.h"

const Vec3 gKartNameTagInitialPos = {0, 0, 0};

void ResetModelAnimationLooping(ModelAnimationFrameLoop *animation, u32 frameCountFixed) {
    animation->mLoopMode = MODEL_ANIMATION_LOOP_MODE_WRAP;
    animation->mDone = 0;
    animation->mFrameStep = FIXED12_UNIT;
    animation->mFrameCountFixed = frameCountFixed;
    animation->mFrameIndex = 0;
    animation->mLoopsDone = 0;
    animation->mLoopCount = 0;
}
