#include "01/Menu/emblem_input.h"

#include "Main/System/heap.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/camera.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "Main/System/input_slots.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "01/MapObjects/mission_run_range_and_collision_callbacks.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
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
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_LEFT;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mLeftHeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mLeftHeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_RIGHT;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mRightHeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mRightHeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_UP;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mUpHeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mUpHeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_DOWN;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mDownHeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mDownHeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_A;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mAHeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mAHeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_B;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mBHeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mBHeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_X;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mXHeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mXHeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_Y;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mYHeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mYHeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_L;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mLHeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mLHeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_R;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mRHeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mRHeldCount = heldCount;
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
        case PAD_KEY_LEFT:
            return gEmblemInput->mLeftHeldCount == 1 || gEmblemInput->mLeftHeldCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_RIGHT:
            return gEmblemInput->mRightHeldCount == 1 || gEmblemInput->mRightHeldCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_UP:
            return gEmblemInput->mUpHeldCount == 1 || gEmblemInput->mUpHeldCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_DOWN:
            return gEmblemInput->mDownHeldCount == 1 || gEmblemInput->mDownHeldCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_A:
            return gEmblemInput->mAHeldCount == 1 || gEmblemInput->mAHeldCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_B:
            return gEmblemInput->mBHeldCount == 1 || gEmblemInput->mBHeldCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_X:
            return gEmblemInput->mXHeldCount == 1 || gEmblemInput->mXHeldCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_Y:
            return gEmblemInput->mYHeldCount == 1 || gEmblemInput->mYHeldCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_L:
            return gEmblemInput->mLHeldCount == 1 || gEmblemInput->mLHeldCount == EMBLEM_INPUT_REPEAT_CALLS;
        case PAD_KEY_R:
            return gEmblemInput->mRHeldCount == 1 || gEmblemInput->mRHeldCount == EMBLEM_INPUT_REPEAT_CALLS;
    }
    return FALSE;
}
