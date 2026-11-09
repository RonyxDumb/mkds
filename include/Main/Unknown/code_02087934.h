#pragma once

#include "types.h"

typedef struct Unk02087b78 Unk02087b78;

void func_02087934(u32 color);
void func_020879e8(s32 texWidthFixed, s32 texHeightFixed);
void func_02087ab0(s32 texWidthFixed, s32 texHeightFixed);
void AdvanceModelAnimationFrame(Unk02087b78 *modelAnimation);
void func_02087b9c(Unk02087b78 *modelAnimation);
void ResetModelAnimationWithLoopFlag(Unk02087b78 *modelAnimation, s32 frameCountFixed, u16 loopFlag);
