#include "Main/Race/race_keys.h"
#include "Main/System/input_slot_repeat.h"
#include "Main/System/key_recording_reset.h"
#include "Main/System/input_slot_pair_reset.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/System/init_after_startup.h"

#pragma opt_rebuildconditionals off

static inline s32 RaceKeysIsConnectionActive(ConnectionWork *connectionWork) {
    BOOL result = FALSE;
    if ((connectionWork == NULL ? CONNECTION_MODE_NONE : connectionWork->mConnectionMode) != CONNECTION_MODE_NONE &&
        connectionWork->mState != CONNECTION_STATE_ENDED) {
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
        SetInputSlotRepeat(inputSlot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
        inputSlot->mSourceKind = INPUT_SOURCE_NONE;
        inputSlot->mRequestedBits = 0;
        inputSlot->mIsBlocked = 0;
        inputSlot->mBitMask = INPUT_SLOT_BIT_MASK_DEFAULT;
        ResetKeyRecording(&inputSlot->mKeyRecording);
        ResetInputSlotPair(&inputSlot->mPair);
    }
    connectionWork = gConnectionWork;
    if (RaceKeysIsConnectionActive(connectionWork) != 0) {
        for (positionIndex = 0; positionIndex < 8; positionIndex++) {
            if (connectionWork->mParticipantMask & (1 << connectionWork->mParticipantIndexByPos[positionIndex])) {
                gInputSlots[positionIndex].mSourceKind = INPUT_SOURCE_PARTICIPANT;
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
        SetInputSlotRepeat(inputSlot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
        inputSlot->mSourceKind = INPUT_SOURCE_NONE;
        inputSlot->mRequestedBits = 0;
        inputSlot->mIsBlocked = 0;
        inputSlot->mBitMask = INPUT_SLOT_BIT_MASK_DEFAULT;
        ResetKeyRecording(&inputSlot->mKeyRecording);
        ResetInputSlotPair(&inputSlot->mPair);
    }
    gInputSlots[INPUT_SLOT_PAD_OR_PARTICIPANT].mSourceKind = INPUT_SOURCE_PAD_OR_PARTICIPANT;
    gInputSlots[INPUT_SLOT_PAD_AND_TOUCH].mSourceKind = INPUT_SOURCE_PAD_AND_TOUCH;
    gInputState->mParticipantPosition = 0;
    gInputState->mUnk_0c = FALSE;
    inputSlot = gInputSlots;
    for (resetIndex = 0; resetIndex < 10; resetIndex++) {
        ResetInputSlot(inputSlot);
        inputSlot->mRequestedBits = 0;
        SetInputSlotRepeat(inputSlot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
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
                    gInputSlots[inputSlotIndex].mSourceKind = INPUT_SOURCE_PARTICIPANT;
                } else if (raceSetup->mRaceKind == RACE_KIND_REPLAY) {
                    gInputSlots[inputSlotIndex].mSourceKind = INPUT_SOURCE_KEY_RECORDING_PLAYBACK;
                } else {
                    gInputSlots[inputSlotIndex].mSourceKind = INPUT_SOURCE_PAD_RECORDED;
                }
            } else if (playerKind == 2) {
                gInputSlots[inputSlotIndex].mSourceKind = INPUT_SOURCE_KEY_RECORDING_PLAYBACK;
            } else if (raceSetup->mMode == MODE_WIFI) {
                gInputSlots[inputSlotIndex].mSourceKind = INPUT_SOURCE_WIFI_REQUESTED_BITS;
            } else {
                gInputSlots[inputSlotIndex].mSourceKind = INPUT_SOURCE_PARTICIPANT;
            }
        } else if (playerKind == 1) {
            gInputSlots[inputSlotIndex].mSourceKind = INPUT_SOURCE_REQUESTED_BITS;
        }
    }
}
