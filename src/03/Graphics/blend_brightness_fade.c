#include "03/Graphics/blend_brightness_fade.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "registers.h"
#include "03/System/exp_heap.h"
#include "03/Menu/wifi_menu_shared.h"
#include "display_blend_affine_setup.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/System/tasks.h"
#include "fixed_vector_math.h"

BlendBrightnessFadeSlot *gBlendBrightnessFadeSlots;

void InitBlendBrightnessFadeSlotsFaded(void) {
    gBlendBrightnessFadeSlots = AllocZeroedExpHeapBlock(0x18, 4);
    G2x_SetBlendBrightness_(&reg_G2_BLDCNT, 0x3f, 0x10);
    G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3f, 0x10);
}

void FreeBlendBrightnessFadeSlots(void) {
    FreeExpHeapBlockAndClearPointer(&gBlendBrightnessFadeSlots);
}

u8 IsBlendBrightnessFadeSlotBusy(int screen) {
    BlendBrightnessFadeSlot *slot;
    if (screen == 1) {
        slot = gBlendBrightnessFadeSlots;
    } else {
        slot = gBlendBrightnessFadeSlots + 1;
    }
    return slot->mEnabled;
}

// Fade kinds: 0 from black, 1 to black, 2 from white, 3 to white.
u32 StartBlendBrightnessFade(s32 kind, s32 screen, u32 plane, u16 frameCount) {
    s8 startLevels[4] = {-0x10, 0x00, 0x10, 0x00};
    BlendBrightnessFadeSlot *slot;

    if (screen == 1) {
        slot = gBlendBrightnessFadeSlots;
    } else {
        slot = gBlendBrightnessFadeSlots + 1;
    }
    if (slot->mEnabled != 0) {
        return 0;
    }
    if (screen == 1) {
        G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, plane, startLevels[kind]);
    } else {
        G2x_SetBlendBrightness_(&reg_G2_BLDCNT, plane, startLevels[kind]);
    }
    slot->mTask = AddTask(1, AdvanceBlendBrightnessFade, slot, 200);
    slot->mFrames = 0;
    slot->mKind = kind;
    slot->mFrameCount = frameCount;
    slot->mEnabled = 1;
    return 1;
}

u8 gBlendBrightnessFadeGapByte[1];
u8 gBlendBrightnessFadeGapBytes[8];

void AdvanceBlendBrightnessFade(TaskEntry *task, void *arg) {
    BlendBrightnessFadeSlot *slot = arg;
    u8 bitsByKind[4] = {0x11, 0x10, 0x01, 0x00};
    s8 finalLevels[4] = {0x00, -0x10, 0x00, 0x10};
    s32 level;
    u8 bits;

    slot->mFrames++;
    level = FX_DivS32(slot->mFrames << 4, slot->mFrameCount);
    bits = bitsByKind[slot->mKind];
    if (bits & 1) {
        level = 0x10 - level;
    }
    if (bits & 0x10) {
        level = -level;
    }
    if (slot == gBlendBrightnessFadeSlots) {
        G2x_ChangeBlendBrightness_(&reg_G2S_DB_BLDCNT, level);
    } else {
        G2x_ChangeBlendBrightness_(&reg_G2_BLDCNT, level);
    }
    if (slot->mFrames >= slot->mFrameCount) {
        if (slot == gBlendBrightnessFadeSlots) {
            G2x_ChangeBlendBrightness_(&reg_G2S_DB_BLDCNT, finalLevels[slot->mKind]);
        } else {
            G2x_ChangeBlendBrightness_(&reg_G2_BLDCNT, finalLevels[slot->mKind]);
        }
        slot->mEnabled = 0;
        RequestTaskRemoval(1, task);
    }
}

u32 StartBlendBrightnessFadeWait(u16 frameCount) {
    BlendBrightnessFadeSlot *slot = gBlendBrightnessFadeSlots;

    if (slot->mEnabled != 0) {
        return 0;
    }
    slot->mTask = AddTask(1, AdvanceBlendBrightnessFadeWait, slot, 200);
    slot->mFrames = 0;
    slot->mFrameCount = frameCount;
    slot->mEnabled = 1;
    return 1;
}

void AdvanceBlendBrightnessFadeWait(TaskEntry *task, void *arg) {
    BlendBrightnessFadeSlot *state = arg;
    state->mFrames++;
    if (state->mFrames >= state->mFrameCount) {
        state->mEnabled = 0;
        RequestTaskRemoval(1, task);
    }
}
