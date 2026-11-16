#pragma once

#include "types.h"
#include "03/System/tasks.h"
#include "03/Menu/wifi_menu_shared.h"

u32 StartBlendBrightnessFadeWait(u16 frameCount);
void AdvanceBlendBrightnessFade(TaskEntry *task, void *arg);
u32 StartBlendBrightnessFade(s32 kind, s32 screen, u32 plane, u16 frameCount);
