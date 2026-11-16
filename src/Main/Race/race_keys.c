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
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
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

u16 GetSomeCYId_9(void) {
    return 9;
}

BOOL Struct5624_HasXflag1(void) {
    return (g_Global5624->mFlags & INPUT_STATE_OPEN_DURING_RACE) != 0;
}

void Struct5624_SetXflag2(u32 enable) {
    if (GetCurrentSceneId() == 2 && enable != 0) {
        g_Global5624->mFlags |= INPUT_STATE_READ_RACE_KEYS;
    } else {
        g_Global5624->mFlags &= ~INPUT_STATE_READ_RACE_KEYS;
    }
}

void ResetInputSlotsFromParticipants(void) {
    u16 slotIndex;
    u16 positionIndex;
    ConnectionWork *connectionWork;
    InputSlot *inputSlot;

    for (slotIndex = 0; slotIndex < 8; slotIndex++) {
        inputSlot = &g_GlobalCYT[slotIndex];
        StructCY_SomeFn(inputSlot);
        StructCY_SomeFn_0(inputSlot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
        inputSlot->mSourceKind = INPUT_SOURCE_NONE;
        inputSlot->mRequestedBits = 0;
        inputSlot->mIsBlocked = 0;
        inputSlot->mBitMask = INPUT_SLOT_BIT_MASK_DEFAULT;
        StructCYB_SomeFn(&inputSlot->mKeyRecording);
        StructCYA_SomeFn(&inputSlot->mPair);
    }
    connectionWork = g_GlobalZE;
    if (RaceKeysIsConnectionActive(connectionWork) != 0) {
        for (positionIndex = 0; positionIndex < 8; positionIndex++) {
            if (connectionWork->mParticipantMask & (1 << connectionWork->mParticipantIndexByPos[positionIndex])) {
                g_GlobalCYT[positionIndex].mSourceKind = INPUT_SOURCE_PARTICIPANT;
            }
        }
    }
    g_Global5624->mParticipantPosition = 0;
    g_Global5624->mUnk_0c = FALSE;
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
        StructCY_SomeFn(inputSlot);
        StructCY_SomeFn_0(inputSlot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
        inputSlot->mSourceKind = INPUT_SOURCE_NONE;
        inputSlot->mRequestedBits = 0;
        inputSlot->mIsBlocked = 0;
        inputSlot->mBitMask = INPUT_SLOT_BIT_MASK_DEFAULT;
        StructCYB_SomeFn(&inputSlot->mKeyRecording);
        StructCYA_SomeFn(&inputSlot->mPair);
    }
    g_GlobalCYT[INPUT_SLOT_PAD_OR_PARTICIPANT].mSourceKind = INPUT_SOURCE_PAD_OR_PARTICIPANT;
    g_GlobalCYT[INPUT_SLOT_PAD_AND_TOUCH].mSourceKind = INPUT_SOURCE_PAD_AND_TOUCH;
    g_Global5624->mParticipantPosition = 0;
    g_Global5624->mUnk_0c = FALSE;
    inputSlot = g_GlobalCYT;
    for (resetIndex = 0; resetIndex < 10; resetIndex++) {
        StructCY_SomeFn(inputSlot);
        inputSlot->mRequestedBits = 0;
        StructCY_SomeFn_0(inputSlot, PAD_KEYS_NO_SELECT_OR_START, 0x1e, 0xa);
        inputSlot++;
    }
    raceSetup = g_GlobalCO;
    connectionWork = g_GlobalZE;
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
                    g_GlobalCYT[inputSlotIndex].mSourceKind = INPUT_SOURCE_PARTICIPANT;
                } else if (raceSetup->mRaceKind == RACE_KIND_REPLAY) {
                    g_GlobalCYT[inputSlotIndex].mSourceKind = INPUT_SOURCE_KEY_RECORDING_PLAYBACK;
                } else {
                    g_GlobalCYT[inputSlotIndex].mSourceKind = INPUT_SOURCE_PAD_RECORDED;
                }
            } else if (playerKind == 2) {
                g_GlobalCYT[inputSlotIndex].mSourceKind = INPUT_SOURCE_KEY_RECORDING_PLAYBACK;
            } else if (raceSetup->mMode == MODE_WIFI) {
                g_GlobalCYT[inputSlotIndex].mSourceKind = INPUT_SOURCE_WIFI_REQUESTED_BITS;
            } else {
                g_GlobalCYT[inputSlotIndex].mSourceKind = INPUT_SOURCE_PARTICIPANT;
            }
        } else if (playerKind == 1) {
            g_GlobalCYT[inputSlotIndex].mSourceKind = INPUT_SOURCE_REQUESTED_BITS;
        }
    }
}
