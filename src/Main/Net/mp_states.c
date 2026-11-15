#include "Main/Net/mp_states.h"
#include "Main/Net/participant_get_connection.h"
#include "Main/Net/connection.h"
#include "Main/Net/participant_bits.h"
#include "Main/Save/ghost_record.h"
#include "Main/Net/mp_states_connection.h"
#include "Main/Net/mp_state.h"

#include "Main/System/backup_net_camera_work.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/scan.h"
#include "thread_scheduler.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "arena_cache_init.h"
#include "wireless_link_control.h"
#include "cpu_copy_fill.h"
#include "Main/Net/mp_chunk_state_machine.h"
#include "Main/System/result_archive_path.h"
#include "Main/Net/rom_archive.h"
#include "Main/Net/slot_result_sync.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Net/participant_index.h"
#include "Main/Net/mp.h"
#include "Main/Save/ghost_record_file.h"

QueueMPDataToPortParams gQueueMPChunkParams = {QueueMPChunkCallback, 0x16c, {0, 0}, 0xe, 2, {0, 0}};

#pragma thumb on

void RequestMPReadyAfterCombine(void) {
    MPStateMachine *stateMachine;
    CombineParticipantBits();
    stateMachine = &gConnectionWork->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = MP_STATE_READY;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

#pragma thumb off

#pragma thumb on

static inline u32 MPStatesGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline void MPStatesRequestMPState(u16 nextState) {
    MPStateMachine *stateMachine = &gConnectionWork->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = nextState;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

void UpdateMPSendParticipantMask(void *stateObject) {
    u8 participantMask;
    u16 waitFrames;

    if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT) {
        participantMask = gConnectionWork->mParticipantMask;
        if (IsAllMPChildSharedDataCopied() != 0) {
            if (QueueMPDataHalfwordAndWord(MP_MESSAGE_PARTICIPANT_MASK, participantMask, participantMask) != FALSE) {
                SetParticipantMask(participantMask);
            }
        } else {
            waitFrames = gConnectionWork->mMPStateMachine.mChildDataWaitFrames;
            if (waitFrames > 0xe10) {
                SetRequestErrorCode(CONNECTION_ERROR_COMMUNICATION_LOST);
                return;
            }
            gConnectionWork->mMPStateMachine.mChildDataWaitFrames = waitFrames + 1;
        }
    }
}

void UpdateMPSendGroupSendMask(void *stateObject) {
    MPStateMachine *stateMachine;

    if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT &&
        (gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY)) {
        if (QueueMPDataHalfwordAndWord(MP_MESSAGE_GROUP_SEND_MASK, gConnectionWork->mChildren.mChildMask,
                                       gConnectionWork->mGroupSendMask) != FALSE) {
            stateMachine = &gConnectionWork->mMPStateMachine;
            stateMachine->mStateMachine.mNextState = MP_STATE_WAIT_ROM_ARCHIVE;
            stateMachine->mStateMachine.mNextStateRequested = 1;
        }
    }
}

void EnterMPLoadDlArchives(void *stateObject) {
    gConnectionWork->mSyncState = CONNECTION_SYNC_START;
    gConnectionWork->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
}

#pragma thumb off

#pragma thumb on

void UpdateMPLoadDlArchives(void *stateObject) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceMainAndMenuDLArchives();
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = MP_STATE_LOAD_SOUND_DATA;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

void UpdateMPWaitRomArchive(void *stateObject) {
    BOOL shouldRequestState;
    BOOL isModeAllowed;
    BOOL isMultiBootSetup;
    s32 connectionMode;
    ConnectionWork *connectionWork;

    shouldRequestState = TRUE;
    isMultiBootSetup = FALSE;
    connectionWork = gConnectionWork;
    if (connectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) {
        isModeAllowed = TRUE;
        if (connectionWork == NULL) {
            connectionMode = CONNECTION_MODE_NONE;
        } else {
            connectionMode = connectionWork->mConnectionMode;
        }
        if (connectionMode != CONNECTION_MODE_PARENT && gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
            isModeAllowed = FALSE;
        }
        if (isModeAllowed != FALSE) {
            isMultiBootSetup = TRUE;
        }
    }
    if (isMultiBootSetup != FALSE) {
        if (GetRomArchiveState() == ROM_ARCHIVE_READY) {
            SetGroupSendMaskAsParent(gConnectionWork->mGroupSendMask);
        } else {
            shouldRequestState = FALSE;
        }
    }
    if (shouldRequestState != FALSE) {
        MPStatesRequestMPState(MP_STATE_LOAD_OVERLAY);
    }
}

void EnterMPLoadOverlay(void *stateObject) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        StartLoadOverlay(OVERLAY_SLOT_OV002);
    }
}

void UpdateMPLoadOverlay(void *stateObject) {
    if (TryFinishOverlayLoad() != 0) {
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            CreateOverlayFrmHeap();
            InitArchiveBuffersOnOverlayHeap();
        }
        MPStatesRequestMPState(MP_STATE_LOAD_DL_ARCHIVES);
    }
}

void EnterMPLoadSoundData(void *stateObject) {
    gConnectionWork->mSyncState = CONNECTION_SYNC_START;
    gConnectionWork->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    gConnectionWork->mCallbackFailed = 0;
}

#pragma thumb off

#pragma thumb on

void UpdateMPLoadSoundData(void *stateObject) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceSyncedCallback(LoadSndDataFromFileCallback);
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = MP_STATE_START_DATA_SHARING;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

// Clears the per-slot flags of received chunks: 0x12 per slot for the parent, 2 for a child.
void EnterMPStartExchange(void *stateObject) {
    s32 slot;
    u32 flagIndex;
    u32 flagCount;

    WM_SetPortCallback(14, MPChunkPortCallback, NULL);
    if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT) {
        SetMPFrequency(0);
    }
    for (slot = 0; slot < 8; slot++) {
        if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT) {
            flagCount = MP_CHUNK_FLAGS_PER_SLOT;
        } else {
            flagCount = 2;
        }
        for (flagIndex = 0; flagIndex < flagCount; flagIndex++) {
            gConnectionWork->mChunkReceivedFlags[slot][flagIndex] = 0;
        }
    }
    gConnectionWork->mRecordReceivedMask = 0;
}

void UpdateMPStartExchange(void *stateObject) {
    if (gConnectionWork->mRequestPending == 0) {
        switch (gConnectionWork->mStep) {
            case CONNECTION_STEP_SETTING_EXCHANGE_RATE:
                gConnectionWork->mStep = CONNECTION_STEP_STARTING_EXCHANGE;
                break;
            case CONNECTION_STEP_STARTING_EXCHANGE:
                MPStatesRequestMPState(MP_STATE_EXCHANGE_OWN_RECORDS);
                break;
            default:
                SetRequestErrorCode(CONNECTION_ERROR_MP_FAILED);
                break;
        }
    }
}

void EnterMPExchangeOwnRecords(void *stateObject) {
    u16 ownIndex;

    ownIndex = gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD ? gConnectionWork->mOwnIndex : 0;
    FillPlayerRecord(&gConnectionWork->mPlayerRecords[ownIndex]);
    gConnectionWork->mMPStateMachine.mChunkSendFlags |= 1;
    gConnectionWork->mEntryChunkIndex = 0;
    gConnectionWork->mMPStateMachine.mEntryWaitFrames = 0;
}

#pragma thumb off

#pragma thumb on
void QueueMPChunkCallback(void) {
    gConnectionWork->mMPStateMachine.mChunkSendFlags |= 1;
}
#pragma thumb off

#pragma thumb on

BOOL QueueMPChunk(u8 chunkNumber, u8 *data, u16 size, u8 playerIndex, u8 destBitmap) {
    u8 *packet;

    if ((gConnectionWork->mMPStateMachine.mChunkSendFlags & 1) == 0) {
        return FALSE;
    }
    packet = gConnectionWork->mChunkBuffer;
    packet[1] = chunkNumber;
    *(u16 *) (packet + 2) = size;
    packet[0] = playerIndex;
    if (data != NULL) {
        MI_CpuCopy8(data, packet + 4, size);
    } else {
        size = 0;
    }
    DC_StoreRange(packet, size + 4);
    gConnectionWork->mMPStateMachine.mChunkSendFlags &= ~1;
    if (QueueMPDataToPort(gConnectionWork->mChunkBuffer, size + 4, destBitmap, NULL, &gQueueMPChunkParams) == 0) {
        gConnectionWork->mMPStateMachine.mChunkSendFlags |= 1;
        return FALSE;
    }
    return TRUE;
}

BOOL GetEntryChunk(u8 *entry, s32 chunkIndex, s32 chunkSize, u8 **outChunk, u16 *outSize) {
    s32 remaining;

    chunkIndex = chunkIndex * chunkSize;
    remaining = 0x22c - chunkIndex;
    if (remaining <= 0) {
        return FALSE;
    }
    if (remaining > chunkSize) {
        remaining = chunkSize;
    }
    *outSize = remaining;
    *outChunk = entry + chunkIndex;
    return TRUE;
}

// Child: queues its own entry chunk by chunk, again and again. Parent: waits for the children's entries.
void UpdateMPExchangeOwnRecords(void *stateObject) {
    ConnectionWork *work;
    u32 expectedMask;
    u8 receivedMask;
    u8 chunkIndex;
    u8 *chunkData;
    u16 chunkSize;
    u16 value;

    if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT) {
        work = gConnectionWork;
        expectedMask = work->mChildren.mExpectedRecordMask;
        receivedMask = work->mRecordReceivedMask;
        if (expectedMask == (expectedMask & receivedMask)) {
            if (QueueMPChunk(MP_CHUNK_HELD_RECORDS_MASK, NULL, (u8) (receivedMask | 1), 0, receivedMask) != FALSE) {
                MPStatesRequestMPState(MP_STATE_SEND_ALL_RECORDS);
            }
        } else {
            if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
                value = 0x708;
            } else {
                value = 0x258;
            }
            gConnectionWork->mMPStateMachine.mEntryWaitFrames++;
            if (gConnectionWork->mMPStateMachine.mEntryWaitFrames > value) {
                gConnectionWork->mChildren.mExpectedRecordMask = gConnectionWork->mChildren.mChildMask;
            }
        }
    } else {
        if ((gConnectionWork->mMPStateMachine.mChunkSendFlags & 1) != 0) {
            chunkIndex = gConnectionWork->mEntryChunkIndex;
            value = gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD ? gConnectionWork->mOwnIndex : 0;
            if (GetEntryChunk((u8 *) &gConnectionWork->mPlayerRecords[value], chunkIndex, 0x20, &chunkData,
                              &chunkSize) != FALSE) {
                value = gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD ? gConnectionWork->mOwnIndex : 0;
                QueueMPChunk(chunkIndex, chunkData, chunkSize, value, 1);
                gConnectionWork->mEntryChunkIndex = chunkIndex + 1;
            } else {
                gConnectionWork->mEntryChunkIndex = 0;
            }
        }
    }
}

void EnterMPSendAllRecords(void *stateObject) {
    gConnectionWork->mState = CONNECTION_STATE_ENTRY_EXCHANGE;
    gConnectionWork->mMPStateMachine.mEntryWaitFrames = 0;
    gConnectionWork->mRecordReceivedMask = 0;
    gConnectionWork->mEntryChunkIndex = 0;
    gConnectionWork->mEntryChunkSlot = 0;
}

// Parent: queues the entries of all slots to the children, chunk by chunk, until the wait ends.
void UpdateMPSendAllRecords(void *stateObject) {
    u32 slotDone;
    u8 chunkIndex;
    u8 slot;
    u8 *chunkData;
    u16 chunkSize;
    u16 waitLimit;

    if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT) {
        if ((gConnectionWork->mMPStateMachine.mChunkSendFlags & 1) != 0) {
            slotDone = 1;
            slot = gConnectionWork->mEntryChunkSlot;
            if (((u8) (gConnectionWork->mChildren.mChildMask | 1) & (1 << slot)) != 0) {
                chunkIndex = gConnectionWork->mEntryChunkIndex;
                if (GetEntryChunk((u8 *) &gConnectionWork->mPlayerRecords[slot], chunkIndex, 0x168, &chunkData,
                                  &chunkSize) != FALSE) {
                    QueueMPChunk(chunkIndex, chunkData, chunkSize, slot, gConnectionWork->mChildren.mChildMask);
                    gConnectionWork->mEntryChunkIndex = chunkIndex + 1;
                    slotDone = 0;
                }
            }
            if (slotDone != 0) {
                gConnectionWork->mEntryChunkSlot++;
                gConnectionWork->mEntryChunkIndex = 0;
                if (gConnectionWork->mEntryChunkSlot >= MP_PARTICIPANT_SLOT_COUNT) {
                    gConnectionWork->mEntryChunkSlot = 0;
                }
            }
        }
        if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
            waitLimit = 0x708;
        } else {
            waitLimit = 0x258;
        }
        gConnectionWork->mMPStateMachine.mEntryWaitFrames++;
        if (gConnectionWork->mMPStateMachine.mEntryWaitFrames > waitLimit) {
            gConnectionWork->mRecordReceivedMask = gConnectionWork->mChildren.mChildMask;
            MPStatesRequestMPState(MP_STATE_SEND_ROM_ARCHIVE);
        }
    }
}

void EnterMPSendRomArchive(void *stateObject) {
    u8 slot;

    WM_SetPortCallback(14, NULL, NULL);
    gConnectionWork->mLanguageIndex = gConnectionWork->mPlayerRecords[0].mLanguageIndex;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        gStartupWork->mLanguageIndex = gConnectionWork->mLanguageIndex;
    }
    for (slot = 1; slot < 8; slot++) {
        if ((gConnectionWork->mRecordReceivedMask & (1 << slot)) == 0) {
            MI_CpuFill8(&gConnectionWork->mPlayerRecords[slot], 0, sizeof(PlayerRecord));
        }
    }
}

void UpdateMPSendRomArchive(void *stateObject) {
    if (gConnectionWork->mRequestPending == 0) {
        switch (gConnectionWork->mStep) {
            case CONNECTION_STEP_STARTING_EXCHANGE:
                StartRomArchiveSend();
                break;
            case CONNECTION_STEP_ROM_ARCHIVE_SEND:
                MPStatesRequestMPState(MP_STATE_SEND_GROUP_SEND_MASK);
                break;
        }
    }
}

void EnterMPSendPlayerNames(void *stateObject) {
    gConnectionWork->mPlayerSendIndex = 0;
    gConnectionWork->mNamesStoredMask = 0;
}

void UpdateMPSendPlayerNames(void *stateObject) {
    u8 playerIndex;
    u8 receivedMask;
    u32 receivedBit;

    switch (MPStatesGetConnectionMode()) {
        case CONNECTION_MODE_PARENT:
            playerIndex = gConnectionWork->mPlayerSendIndex;
            receivedMask = gConnectionWork->mRecordReceivedMask;
            receivedBit = receivedMask & (1 << playerIndex);
            if (receivedBit != 0) {
                if (QueueMPDataPlayerName(playerIndex, receivedMask) != FALSE) {
                    gConnectionWork->mPlayerSendIndex++;
                }
            } else {
                gConnectionWork->mPlayerSendIndex++;
            }
            if (gConnectionWork->mPlayerSendIndex >= MP_PARTICIPANT_SLOT_COUNT) {
                MPStatesRequestMPState(MP_STATE_SEND_GROUP_SEND_MASK);
            }
            break;
        case CONNECTION_MODE_CHILD:
            playerIndex = gConnectionWork->mRecordReceivedMask;
            receivedMask = gConnectionWork->mNamesStoredMask;
            if (playerIndex == (playerIndex & receivedMask)) {
                MPStatesRequestMPState(MP_STATE_SEND_GROUP_SEND_MASK);
            }
            break;
    }
}

#pragma thumb off

#pragma thumb on

void EnterMPStartDataSharing(void *stateObject) {
    int connectionMode;
    if (gConnectionWork == NULL) {
        connectionMode = CONNECTION_MODE_NONE;
    } else {
        connectionMode = gConnectionWork->mConnectionMode;
    }
    if (connectionMode == CONNECTION_MODE_PARENT) {
        SetMPFrequency(1);
    }
}

#pragma thumb off

#pragma thumb on

void UpdateMPStartDataSharing(void *stateObject) {
    if (gConnectionWork->mRequestPending != 0) {
        return;
    }
    switch (gConnectionWork->mStep) {
        case CONNECTION_STEP_SETTING_EXCHANGE_RATE:
        case CONNECTION_STEP_ROM_ARCHIVE_SEND:
        case CONNECTION_STEP_CHILD_ARCHIVE_SYNC:
            StartDataSharing();
            break;
        case CONNECTION_STEP_STARTING_SHARING:
            gConnectionWork->mState = CONNECTION_STATE_SYNC_WAIT;
            MPStatesRequestMPState(MP_STATE_SEND_PARTICIPANT_MASK);
            break;
    }
}

void EnterMPExchangePlayerBits(void *stateObject) {
    s32 ownIndex;

    gConnectionWork->mBitsReceivedMask = 0;
    ownIndex = 0;
    if (gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD) {
        ownIndex = gConnectionWork->mOwnIndex;
    }
    MI_CpuCopy8(gBackupBuffers->mFirstBlock->mFlags, gConnectionWork->mPlayerRecords[(u16) ownIndex].mBits,
                sizeof(gConnectionWork->mPlayerRecords[(u16) ownIndex].mBits));
    gConnectionWork->mRecordReceivedMask |= 1;
}

void UpdateMPExchangePlayerBits(void *stateObject) {
    s32 ownIndex;

    if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT) {
        if (gConnectionWork->mChildren.mChildMask ==
            (gConnectionWork->mChildren.mChildMask & gConnectionWork->mBitsReceivedMask)) {
            MPStatesRequestMPState(MP_STATE_SEND_PLAYER_BITS);
        }
    } else if (gConnectionWork->mBitsReceivedMask != 0) {
        MPStatesRequestMPState(MP_STATE_SEND_PLAYER_BITS);
    } else {
        if (gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD) {
            ownIndex = gConnectionWork->mOwnIndex;
        } else {
            ownIndex = 0;
        }
        QueueMPDataPlayerBits((u16) ownIndex, 1);
    }
}
#pragma thumb off

#pragma thumb on
void EnterMPSendPlayerBits(void *stateObject) {
    gConnectionWork->mPlayerSendIndex = 0;
}
#pragma thumb off

#pragma thumb on

void UpdateMPSendPlayerBits(void *stateObject) {
    if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT) {
        if ((gConnectionWork->mRecordReceivedMask & (1 << gConnectionWork->mPlayerSendIndex)) != 0) {
            if (QueueMPDataPlayerBits(gConnectionWork->mPlayerSendIndex, gConnectionWork->mChildren.mChildMask) !=
                FALSE) {
                gConnectionWork->mPlayerSendIndex += 1;
            }
        } else {
            gConnectionWork->mPlayerSendIndex += 1;
        }
        if (gConnectionWork->mPlayerSendIndex > MP_PARTICIPANT_SLOT_COUNT) {
            MPStatesRequestMPState(MP_STATE_SEND_PLAYER_NAMES);
        }
    } else if (gConnectionWork->mRecordReceivedMask ==
               (gConnectionWork->mRecordReceivedMask & gConnectionWork->mBitsReceivedMask)) {
        MPStatesRequestMPState(MP_STATE_SEND_PLAYER_NAMES);
    }
}
#pragma thumb off

#pragma thumb on

void EnterMPReadyNop(void *stateObject) {}

#pragma thumb off
