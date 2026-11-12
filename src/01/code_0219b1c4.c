#include "01/code_0219b1c4.h"
#include "Main/Unknown/code_02087000.h"
#include "01/code_0219b540.h"
#include "01/code_0219c000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Graphics/model_animation_loop_mode.h"

void StartMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, s32 entryIndex, s32 frameStep, s32 clampLoop) {
    StartModelAnimationBlend(mapObjectModel->mAnimations[0], entryIndex);
    mapObjectModel->mAnimations[0]->mHead.mFrameStep = frameStep;
    SetModelAnimationEntryLoopMode(mapObjectModel->mAnimations[0], ((u16) entryIndex),
                                   (clampLoop != 0 ? MODEL_ANIMATION_LOOP_MODE_CLAMP : MODEL_ANIMATION_LOOP_MODE_WRAP));
}

void AdvanceMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel) {
    AdvanceModelAnimation(mapObjectModel->mAnimations[3]);
}

void StartMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel, s32 entryIndex, s32 frameStep, s32 clampLoop) {
    StartModelAnimationBlend(mapObjectModel->mAnimations[3], entryIndex);
    mapObjectModel->mAnimations[1]->mHead.mFrameStep = frameStep;
    SetModelAnimationEntryLoopMode(mapObjectModel->mAnimations[3], ((u16) entryIndex),
                                   (clampLoop != 0 ? MODEL_ANIMATION_LOOP_MODE_CLAMP : MODEL_ANIMATION_LOOP_MODE_WRAP));
}
