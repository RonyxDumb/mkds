#pragma once

#include "types.h"
#include "03/System/tasks.h"

// One brightness fade: its task, frame counts, kind and whether it is enabled.
typedef struct BlendBrightnessFadeSlot {
    /* 00 */ TaskEntry *mTask;
    /* 04 */ s16 mFrames;
    /* 06 */ u16 mFrameCount;
    /* 08 */ u8 mKind;
    /* 09 */ u8 mEnabled;
} BlendBrightnessFadeSlot;

void AdvanceBlendBrightnessFadeWait(TaskEntry *task, void *arg);

extern BlendBrightnessFadeSlot *gBlendBrightnessFadeSlots;
