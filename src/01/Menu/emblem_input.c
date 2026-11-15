#include "01/Menu/emblem_input.h"

#include "Main/System/heap.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/camera.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "Main/Menu/data_02175628.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "01/code_02188158.h"
#include "Main/System/heap_call.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "01/code_02192000.h"
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
    if (value == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
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
        if (gEmblemInput->mStillCallCount > 0x3c) {
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
        heldCount = gEmblemInput->mBit5HeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mBit5HeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_RIGHT;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mBit4HeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mBit4HeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_UP;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mBit6HeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mBit6HeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_DOWN;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mBit7HeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mBit7HeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_A;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mBit0HeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mBit0HeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_B;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mBit1HeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mBit1HeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_X;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mBit10HeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mBit10HeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_Y;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mBit11HeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mBit11HeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_L;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mBit9HeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mBit9HeldCount = heldCount;
    bitHeld = gEmblemInputSlotView->mNextBits & PAD_KEY_R;
    if (bitHeld == 0) {
        heldCount = 0;
    } else {
        heldCount = gEmblemInput->mBit8HeldCount + 1;
        if (heldCount >= 0x11) {
            heldCount = 0xf;
        }
    }
    gEmblemInput->mBit8HeldCount = heldCount;
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
        case 0x20:
            return gEmblemInput->mBit5HeldCount == 1 || gEmblemInput->mBit5HeldCount == 0xf;
        case 0x10:
            return gEmblemInput->mBit4HeldCount == 1 || gEmblemInput->mBit4HeldCount == 0xf;
        case 0x40:
            return gEmblemInput->mBit6HeldCount == 1 || gEmblemInput->mBit6HeldCount == 0xf;
        case 0x80:
            return gEmblemInput->mBit7HeldCount == 1 || gEmblemInput->mBit7HeldCount == 0xf;
        case 1:
            return gEmblemInput->mBit0HeldCount == 1 || gEmblemInput->mBit0HeldCount == 0xf;
        case 2:
            return gEmblemInput->mBit1HeldCount == 1 || gEmblemInput->mBit1HeldCount == 0xf;
        case 0x400:
            return gEmblemInput->mBit10HeldCount == 1 || gEmblemInput->mBit10HeldCount == 0xf;
        case 0x800:
            return gEmblemInput->mBit11HeldCount == 1 || gEmblemInput->mBit11HeldCount == 0xf;
        case 0x200:
            return gEmblemInput->mBit9HeldCount == 1 || gEmblemInput->mBit9HeldCount == 0xf;
        case 0x100:
            return gEmblemInput->mBit8HeldCount == 1 || gEmblemInput->mBit8HeldCount == 0xf;
    }
    return FALSE;
}
