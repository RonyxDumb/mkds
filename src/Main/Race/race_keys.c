#include "Main/Race/race_keys.h"
#include "Main/System/input_slot_repeat.h"
#include "Main/System/key_recording_reset.h"
#include "Main/System/input_slot_pair_reset.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "Main/Menu/data_02175628.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/System/init_after_startup.h"

#pragma opt_rebuildconditionals off

static inline s32 RaceKeysIsConnectionActive(ConnectionWork *connectionWork) {
    BOOL result = FALSE;
    if ((connectionWork == NULL ? 0 : connectionWork->mConnectionMode) != 0 && connectionWork->mState != 13) {
        result = TRUE;
    }
    return result;
}

u16 GetPadInputSlot(void) {
    return 9;
}

BOOL IsInputOpenDuringRace(void) {
    return (gInputState->mFlags & INPUT_STATE_OPEN_DURING_RACE) != 0;
}

void SetReadRaceKeys(u32 enable) {
    if (GetCurrentSceneNumber() == 2 && enable != 0) {
        gInputState->mFlags |= INPUT_STATE_READ_RACE_KEYS;
    } else {
        gInputState->mFlags &= ~INPUT_STATE_READ_RACE_KEYS;
    }
}

void ResetInputSlotsFromParticipants(void) {
    u16 slotIndex;
    u16 positionIndex;
    ConnectionWork *connectionWork;
    InputSlot *inputSlot;

    for (slotIndex = 0; slotIndex < 8; slotIndex++) {
        inputSlot = &gInputSlots[slotIndex];
        ResetInputSlot(inputSlot);
        SetInputSlotRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot->mSourceKind = 0;
        inputSlot->mRequestedBits = 0;
        inputSlot->mUnk_44 = 0;
        inputSlot->mBitMask = 0x2fff;
        ResetKeyRecording(&inputSlot->mUnk_28);
        ResetInputSlotPair(&inputSlot->mPair);
    }
    connectionWork = gConnectionWork;
    if (RaceKeysIsConnectionActive(connectionWork) != 0) {
        for (positionIndex = 0; positionIndex < 8; positionIndex++) {
            if (connectionWork->mParticipantMask & (1 << connectionWork->mParticipantIndexByPos[positionIndex])) {
                gInputSlots[positionIndex].mSourceKind = 4;
            }
        }
    }
    gInputState->mParticipantPosition = 0;
    gInputState->mUnk_0c = FALSE;
}

void ResetInputSlotsFromRaceSetup(void) {
    s32 slotIndex;
    s32 resetIndex;
    u16 entryIndex;
    s32 inputSlotIndex;
    BOOL isNonCpu;
    InputSlot *inputSlot;
    RaceSetup *raceSetup;
    ConnectionWork *connectionWork;
    s32 playerKind;

    for (slotIndex = 0; slotIndex < 10; slotIndex++) {
        inputSlot = GetInputSlot(slotIndex);
        ResetInputSlot(inputSlot);
        SetInputSlotRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot->mSourceKind = 0;
        inputSlot->mRequestedBits = 0;
        inputSlot->mUnk_44 = 0;
        inputSlot->mBitMask = 0x2fff;
        ResetKeyRecording(&inputSlot->mUnk_28);
        ResetInputSlotPair(&inputSlot->mPair);
    }
    gInputSlots[8].mSourceKind = 5;
    gInputSlots[9].mSourceKind = 6;
    gInputState->mParticipantPosition = 0;
    gInputState->mUnk_0c = FALSE;
    inputSlot = gInputSlots;
    for (resetIndex = 0; resetIndex < 10; resetIndex++) {
        ResetInputSlot(inputSlot);
        inputSlot->mRequestedBits = 0;
        SetInputSlotRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot++;
    }
    raceSetup = gRaceSetup;
    connectionWork = gConnectionWork;
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        playerKind = raceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
        isNonCpu = FALSE;
        inputSlotIndex = raceSetup->mCurrentEntries[entryIndex].mPlayer.mIndex;
        if ((u32) playerKind <= 3 && ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            isNonCpu = TRUE;
        }
        if (isNonCpu != FALSE) {
            if (entryIndex == raceSetup->mEntryIndex) {
                if (RaceKeysIsConnectionActive(connectionWork) != 0) {
                    gInputSlots[inputSlotIndex].mSourceKind = 4;
                } else if (raceSetup->mRaceKind == RACE_KIND_REPLAY) {
                    gInputSlots[inputSlotIndex].mSourceKind = 1;
                } else {
                    gInputSlots[inputSlotIndex].mSourceKind = 2;
                }
            } else if (playerKind == 2) {
                gInputSlots[inputSlotIndex].mSourceKind = 1;
            } else if (raceSetup->mMode == MODE_WIFI) {
                gInputSlots[inputSlotIndex].mSourceKind = 7;
            } else {
                gInputSlots[inputSlotIndex].mSourceKind = 4;
            }
        } else if (playerKind == 1) {
            gInputSlots[inputSlotIndex].mSourceKind = 3;
        }
    }
}
