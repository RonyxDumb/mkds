#include "01/Menu/emblem_input.h"

#include "Main/System/heap.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/camera.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "01/MapObjects/mission_run_range_and_collision_callbacks.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Race/race_setup_input.h"

EmblemInput *gEmblemInput;

void CreateEmblemInput(void) {
    gEmblemInput = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(EmblemInput));
}

void AdvanceEmblemInput(void) {
    InputSlotIndex slotIndex;
    BOOL pairUsable;
    int pairRecentlyLost;
    u16 value;
    u16 bitHeld;
    s32 heldCount;

    gEmblemInput->mPrevX = gEmblemInput->mX;
    gEmblemInput->mPrevY = gEmblemInput->mY;
    gEmblemInput->mPrevPressed = gEmblemInput->mPressed;
    gEmblemInput->mPrevDown = gEmblemInput->mDown;
    gEmblemInput->mPrevReleased = gEmblemInput->mReleased;
    if (gEmblemInput->mDown == 0 && gPadOrParticipantSlotPairView->mPair.mPairX != 0 &&
        gPadOrParticipantSlotPairView->mPair.mPairY != 0) {
        gEmblemInput->mPressed = 1;
    } else {
        gEmblemInput->mPressed = 0;
    }
    if (gEmblemInput->mDown != 0 && gPadOrParticipantSlotPairView->mPair.mPairX == 0 &&
        gPadOrParticipantSlotPairView->mPair.mPairY == 0) {
        gEmblemInput->mReleased = 1;
    } else {
        gEmblemInput->mReleased = 0;
    }
    slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    pairUsable = TRUE;
    pairRecentlyLost = 0;
    value = gInputSlots[slotIndex].mPair.mHasPair;
    if (value == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        pairRecentlyLost = pairUsable;
    }
    if (pairRecentlyLost == 0 && value == 0) {
        pairUsable = FALSE;
    }
    if (pairUsable != FALSE && (value = gPadOrParticipantSlotPairView->mPair.mPairX) != 0 &&
        gPadOrParticipantSlotPairView->mPair.mPairY != 0) {
        gEmblemInput->mX = value;
        gEmblemInput->mY = gPadOrParticipantSlotPairView->mPair.mPairY;
        gEmblemInput->mDown = 1;
    } else {
        gEmblemInput->mDown = 0;
    }
    if (gEmblemInput->mDown != 0 && gEmblemInput->mX <= gEmblemInput->mPrevX + 1 &&
        gEmblemInput->mX >= gEmblemInput->mPrevX - 1 && gEmblemInput->mY <= gEmblemInput->mPrevY + 1 &&
        gEmblemInput->mY >= gEmblemInput->mPrevY - 1) {
        gEmblemInput->mStillCallCount++;
        if (gEmblemInput->mStillCallCount > EMBLEM_INPUT_STILL_PRESS_CALLS) {
            gEmblemInput->mStillCallCount = 0;
            gEmblemInput->mPressed = 1;
            gEmblemInput->mReleased = 1;
        }
    } else {
        gEmblemInput->mStillCallCount = 0;
    }
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_DIRECTION_LEFT;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mLeftKeyRepeatCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mLeftKeyRepeatCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_DIRECTION_RIGHT;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mRightKeyRepeatCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mRightKeyRepeatCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_DIRECTION_UP;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mUpKeyRepeatCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mUpKeyRepeatCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_DIRECTION_DOWN;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mDownKeyRepeatCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mDownKeyRepeatCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_A;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mAKeyRepeatCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mAKeyRepeatCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_B;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mBKeyRepeatCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mBKeyRepeatCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_X;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mXKeyRepeatCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mXKeyRepeatCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_Y;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mYKeyRepeatCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mYKeyRepeatCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_L;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mLKeyRepeatCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mLKeyRepeatCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_R;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mRKeyRepeatCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mRKeyRepeatCount = heldCount;
}

s32 GetEmblemInputX(void) {
    return gEmblemInput->mX;
}

u32 GetEmblemInputY(void) {
    return gEmblemInput->mY;
}

u32 GetEmblemInputPressed(void) {
    return gEmblemInput->mPressed;
}

u32 GetEmblemInputDown(void) {
    return gEmblemInput->mDown;
}

u32 GetEmblemInputPrevX(void) {
    return gEmblemInput->mPrevX;
}

u32 GetEmblemInputPrevY(void) {
    return gEmblemInput->mPrevY;
}

u32 GetEmblemInputPrevDown(void) {
    return gEmblemInput->mPrevDown;
}

u16 GetEmblemInputNewBits(u16 mask) {
    return gInputSlots[INPUT_SLOT_PAD_OR_PARTICIPANT].mPressedBits & mask;
}

u16 GetEmblemInputBits(u16 mask) {
    return gInputSlots[INPUT_SLOT_PAD_OR_PARTICIPANT].mBits & mask;
}

BOOL IsEmblemInputRepeat(int mask) {
    switch (mask) {
        case PAD_KEY_DIRECTION_LEFT:
            return gEmblemInput->mLeftKeyRepeatCount == 1 || gEmblemInput->mLeftKeyRepeatCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_DIRECTION_RIGHT:
            return gEmblemInput->mRightKeyRepeatCount == 1 || gEmblemInput->mRightKeyRepeatCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_DIRECTION_UP:
            return gEmblemInput->mUpKeyRepeatCount == 1 || gEmblemInput->mUpKeyRepeatCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_DIRECTION_DOWN:
            return gEmblemInput->mDownKeyRepeatCount == 1 || gEmblemInput->mDownKeyRepeatCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_A:
            return gEmblemInput->mAKeyRepeatCount == 1 || gEmblemInput->mAKeyRepeatCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_B:
            return gEmblemInput->mBKeyRepeatCount == 1 || gEmblemInput->mBKeyRepeatCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_X:
            return gEmblemInput->mXKeyRepeatCount == 1 || gEmblemInput->mXKeyRepeatCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_Y:
            return gEmblemInput->mYKeyRepeatCount == 1 || gEmblemInput->mYKeyRepeatCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_L:
            return gEmblemInput->mLKeyRepeatCount == 1 || gEmblemInput->mLKeyRepeatCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_R:
            return gEmblemInput->mRKeyRepeatCount == 1 || gEmblemInput->mRKeyRepeatCount == EMBLEM_INPUT_REPEAT_CALLS;
    }
    return FALSE;
}
