#pragma once

#include "types.h"

typedef struct ModelAnimation ModelAnimation;

void func_02087934(u32 color);
void func_020879e8(s32 texWidthFixed, s32 texHeightFixed);
void func_02087ab0(s32 texWidthFixed, s32 texHeightFixed);
void anim_updateAnimator(ModelAnimation *modelAnimation);
void anim_handleLooping(ModelAnimation *modelAnimation);
void anim_initAnimator(ModelAnimation *modelAnimation, s32 frameCountFixed, u16 loopFlag);
