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
    stateMachine = &g_GlobalZE->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = MP_STATE_READY;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

#pragma thumb off

#pragma thumb on

static inline u32 MPStatesGetConnectionMode(void) {
    if (g_GlobalZE == NULL) {
        return 0;
    }
    return g_GlobalZE->mConnectionMode;
}

static inline void MPStatesRequestMPState(u16 nextState) {
    MPStateMachine *stateMachine = &g_GlobalZE->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = nextState;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

void UpdateMPSendParticipantMask(void *stateObject) {
    u8 participantMask;
    u16 waitFrames;

    if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT) {
        participantMask = g_GlobalZE->mParticipantMask;
        if (IsAllMPChildSharedDataCopied() != 0) {
            if (QueueMPDataHalfwordAndWord(MP_MESSAGE_PARTICIPANT_MASK, participantMask, participantMask) != FALSE) {
                SetParticipantMask(participantMask);
            }
        } else {
            waitFrames = g_GlobalZE->mMPStateMachine.mChildDataWaitFrames;
            if (waitFrames > 0xe10) {
                SetRequestErrorCode(CONNECTION_ERROR_COMMUNICATION_LOST);
                return;
            }
            g_GlobalZE->mMPStateMachine.mChildDataWaitFrames = waitFrames + 1;
        }
    }
}

void UpdateMPSendGroupSendMask(void *stateObject) {
    MPStateMachine *stateMachine;

    if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT &&
        (g_GlobalZE->mFlags & CONNECTION_FLAG_SEND_READY)) {
        if (QueueMPDataHalfwordAndWord(MP_MESSAGE_GROUP_SEND_MASK, g_GlobalZE->mChildren.mChildMask,
                                       g_GlobalZE->mGroupSendMask) != FALSE) {
            stateMachine = &g_GlobalZE->mMPStateMachine;
            stateMachine->mStateMachine.mNextState = MP_STATE_WAIT_ROM_ARCHIVE;
            stateMachine->mStateMachine.mNextStateRequested = 1;
        }
    }
}

void EnterMPLoadDlArchives(void *stateObject) {
    g_GlobalZE->mSyncState = CONNECTION_SYNC_START;
    g_GlobalZE->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
}

#pragma thumb off

#pragma thumb on

void UpdateMPLoadDlArchives(void *stateObject) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceMainAndMenuDLArchives();
    if (result == 1) {
        stateMachine = &g_GlobalZE->mMPStateMachine;
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
    connectionWork = g_GlobalZE;
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
            SetGroupSendMaskAsParent(g_GlobalZE->mGroupSendMask);
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
        UpdateOverlayStatusWithKind(OVERLAY_SLOT_OV002);
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
    g_GlobalZE->mSyncState = CONNECTION_SYNC_START;
    g_GlobalZE->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    g_GlobalZE->mCallbackFailed = 0;
}

#pragma thumb off

#pragma thumb on

void UpdateMPLoadSoundData(void *stateObject) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceSyncedCallback(LoadSndDataFromFileCallback);
    if (result == 1) {
        stateMachine = &g_GlobalZE->mMPStateMachine;
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
            g_GlobalZE->mChunkReceivedFlags[slot][flagIndex] = 0;
        }
    }
    g_GlobalZE->mRecordReceivedMask = 0;
}

void UpdateMPStartExchange(void *stateObject) {
    if (g_GlobalZE->mRequestPending == 0) {
        switch (g_GlobalZE->mStep) {
            case CONNECTION_STEP_SETTING_EXCHANGE_RATE:
                g_GlobalZE->mStep = CONNECTION_STEP_STARTING_EXCHANGE;
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

    ownIndex = g_GlobalZE->mConnectionMode == CONNECTION_MODE_CHILD ? g_GlobalZE->mOwnIndex : 0;
    StructTK_SomeFn_from_thumb(&g_GlobalZE->mPlayerRecords[ownIndex]);
    g_GlobalZE->mMPStateMachine.mChunkSendFlags |= 1;
    g_GlobalZE->mEntryChunkIndex = 0;
    g_GlobalZE->mMPStateMachine.mEntryWaitFrames = 0;
}

#pragma thumb off

#pragma thumb on
void QueueMPChunkCallback(void) {
    g_GlobalZE->mMPStateMachine.mChunkSendFlags |= 1;
}
#pragma thumb off

#pragma thumb on

BOOL QueueMPChunk(u8 chunkNumber, u8 *data, u16 size, u8 playerIndex, u8 destBitmap) {
    u8 *packet;

    if ((g_GlobalZE->mMPStateMachine.mChunkSendFlags & 1) == 0) {
        return FALSE;
    }
    packet = g_GlobalZE->mChunkBuffer;
    packet[1] = chunkNumber;
    *(u16 *) (packet + 2) = size;
    packet[0] = playerIndex;
    if (data != NULL) {
        Mem_CpuCopy8(data, packet + 4, size);
    } else {
        size = 0;
    }
    DC_SomeClean(packet, size + 4);
    g_GlobalZE->mMPStateMachine.mChunkSendFlags &= ~1;
    if (QueueMPDataToPort(g_GlobalZE->mChunkBuffer, size + 4, destBitmap, NULL, &gQueueMPChunkParams) == 0) {
        g_GlobalZE->mMPStateMachine.mChunkSendFlags |= 1;
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
        work = g_GlobalZE;
        expectedMask = work->mChildren.mExpectedRecordMask;
        receivedMask = work->mRecordReceivedMask;
        if (expectedMask == (expectedMask & receivedMask)) {
            if (QueueMPChunk(MP_CHUNK_HELD_RECORDS_MASK, NULL, (u8) (receivedMask | 1), 0, receivedMask) != FALSE) {
                MPStatesRequestMPState(MP_STATE_SEND_ALL_RECORDS);
            }
        } else {
            if ((g_GlobalZE->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
                value = 0x708;
            } else {
                value = 0x258;
            }
            g_GlobalZE->mMPStateMachine.mEntryWaitFrames++;
            if (g_GlobalZE->mMPStateMachine.mEntryWaitFrames > value) {
                g_GlobalZE->mChildren.mExpectedRecordMask = g_GlobalZE->mChildren.mChildMask;
            }
        }
    } else {
        if ((g_GlobalZE->mMPStateMachine.mChunkSendFlags & 1) != 0) {
            chunkIndex = g_GlobalZE->mEntryChunkIndex;
            value = g_GlobalZE->mConnectionMode == CONNECTION_MODE_CHILD ? g_GlobalZE->mOwnIndex : 0;
            if (GetEntryChunk((u8 *) &g_GlobalZE->mPlayerRecords[value], chunkIndex, 0x20, &chunkData,
                              &chunkSize) != FALSE) {
                value = g_GlobalZE->mConnectionMode == CONNECTION_MODE_CHILD ? g_GlobalZE->mOwnIndex : 0;
                QueueMPChunk(chunkIndex, chunkData, chunkSize, value, 1);
                g_GlobalZE->mEntryChunkIndex = chunkIndex + 1;
            } else {
                g_GlobalZE->mEntryChunkIndex = 0;
            }
        }
    }
}

void EnterMPSendAllRecords(void *stateObject) {
    g_GlobalZE->mState = CONNECTION_STATE_ENTRY_EXCHANGE;
    g_GlobalZE->mMPStateMachine.mEntryWaitFrames = 0;
    g_GlobalZE->mRecordReceivedMask = 0;
    g_GlobalZE->mEntryChunkIndex = 0;
    g_GlobalZE->mEntryChunkSlot = 0;
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
        if ((g_GlobalZE->mMPStateMachine.mChunkSendFlags & 1) != 0) {
            slotDone = 1;
            slot = g_GlobalZE->mEntryChunkSlot;
            if (((u8) (g_GlobalZE->mChildren.mChildMask | 1) & (1 << slot)) != 0) {
                chunkIndex = g_GlobalZE->mEntryChunkIndex;
                if (GetEntryChunk((u8 *) &g_GlobalZE->mPlayerRecords[slot], chunkIndex, 0x168, &chunkData,
                                  &chunkSize) != FALSE) {
                    QueueMPChunk(chunkIndex, chunkData, chunkSize, slot, g_GlobalZE->mChildren.mChildMask);
                    g_GlobalZE->mEntryChunkIndex = chunkIndex + 1;
                    slotDone = 0;
                }
            }
            if (slotDone != 0) {
                g_GlobalZE->mEntryChunkSlot++;
                g_GlobalZE->mEntryChunkIndex = 0;
                if (g_GlobalZE->mEntryChunkSlot >= MP_PARTICIPANT_SLOT_COUNT) {
                    g_GlobalZE->mEntryChunkSlot = 0;
                }
            }
        }
        if ((g_GlobalZE->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
            waitLimit = 0x708;
        } else {
            waitLimit = 0x258;
        }
        g_GlobalZE->mMPStateMachine.mEntryWaitFrames++;
        if (g_GlobalZE->mMPStateMachine.mEntryWaitFrames > waitLimit) {
            g_GlobalZE->mRecordReceivedMask = g_GlobalZE->mChildren.mChildMask;
            MPStatesRequestMPState(MP_STATE_SEND_ROM_ARCHIVE);
        }
    }
}

void EnterMPSendRomArchive(void *stateObject) {
    u8 slot;

    WM_SetPortCallback(14, NULL, NULL);
    g_GlobalZE->mLanguageIndex = g_GlobalZE->mPlayerRecords[0].mLanguageIndex;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        g_GlobalP->mLanguageIndex = g_GlobalZE->mLanguageIndex;
    }
    for (slot = 1; slot < 8; slot++) {
        if ((g_GlobalZE->mRecordReceivedMask & (1 << slot)) == 0) {
            Mem_CpuFill8(&g_GlobalZE->mPlayerRecords[slot], 0, sizeof(PlayerRecord));
        }
    }
}

void UpdateMPSendRomArchive(void *stateObject) {
    if (g_GlobalZE->mRequestPending == 0) {
        switch (g_GlobalZE->mStep) {
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
    g_GlobalZE->mPlayerSendIndex = 0;
    g_GlobalZE->mNamesStoredMask = 0;
}

void UpdateMPSendPlayerNames(void *stateObject) {
    u8 playerIndex;
    u8 receivedMask;
    u32 receivedBit;

    switch (MPStatesGetConnectionMode()) {
        case CONNECTION_MODE_PARENT:
            playerIndex = g_GlobalZE->mPlayerSendIndex;
            receivedMask = g_GlobalZE->mRecordReceivedMask;
            receivedBit = receivedMask & (1 << playerIndex);
            if (receivedBit != 0) {
                if (QueueMPDataPlayerName(playerIndex, receivedMask) != FALSE) {
                    g_GlobalZE->mPlayerSendIndex++;
                }
            } else {
                g_GlobalZE->mPlayerSendIndex++;
            }
            if (g_GlobalZE->mPlayerSendIndex >= MP_PARTICIPANT_SLOT_COUNT) {
                MPStatesRequestMPState(MP_STATE_SEND_GROUP_SEND_MASK);
            }
            break;
        case CONNECTION_MODE_CHILD:
            playerIndex = g_GlobalZE->mRecordReceivedMask;
            receivedMask = g_GlobalZE->mNamesStoredMask;
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
    if (g_GlobalZE == NULL) {
        connectionMode = CONNECTION_MODE_NONE;
    } else {
        connectionMode = g_GlobalZE->mConnectionMode;
    }
    if (connectionMode == CONNECTION_MODE_PARENT) {
        SetMPFrequency(1);
    }
}

#pragma thumb off

#pragma thumb on

void UpdateMPStartDataSharing(void *stateObject) {
    if (g_GlobalZE->mRequestPending != 0) {
        return;
    }
    switch (g_GlobalZE->mStep) {
        case CONNECTION_STEP_SETTING_EXCHANGE_RATE:
        case CONNECTION_STEP_ROM_ARCHIVE_SEND:
        case CONNECTION_STEP_CHILD_ARCHIVE_SYNC:
            StartDataSharing();
            break;
        case CONNECTION_STEP_STARTING_SHARING:
            g_GlobalZE->mState = CONNECTION_STATE_SYNC_WAIT;
            MPStatesRequestMPState(MP_STATE_SEND_PARTICIPANT_MASK);
            break;
    }
}

void EnterMPExchangePlayerBits(void *stateObject) {
    s32 ownIndex;

    g_GlobalZE->mBitsReceivedMask = 0;
    ownIndex = 0;
    if (g_GlobalZE->mConnectionMode == CONNECTION_MODE_CHILD) {
        ownIndex = g_GlobalZE->mOwnIndex;
    }
    Mem_CpuCopy8(g_SaveDataHolder->mFirstBlock->mFlags, g_GlobalZE->mPlayerRecords[(u16) ownIndex].mBits,
                sizeof(g_GlobalZE->mPlayerRecords[(u16) ownIndex].mBits));
    g_GlobalZE->mRecordReceivedMask |= 1;
}

void UpdateMPExchangePlayerBits(void *stateObject) {
    s32 ownIndex;

    if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT) {
        if (g_GlobalZE->mChildren.mChildMask ==
            (g_GlobalZE->mChildren.mChildMask & g_GlobalZE->mBitsReceivedMask)) {
            MPStatesRequestMPState(MP_STATE_SEND_PLAYER_BITS);
        }
    } else if (g_GlobalZE->mBitsReceivedMask != 0) {
        MPStatesRequestMPState(MP_STATE_SEND_PLAYER_BITS);
    } else {
        if (g_GlobalZE->mConnectionMode == CONNECTION_MODE_CHILD) {
            ownIndex = g_GlobalZE->mOwnIndex;
        } else {
            ownIndex = 0;
        }
        QueueMPDataPlayerBits((u16) ownIndex, 1);
    }
}
#pragma thumb off

#pragma thumb on
void EnterMPSendPlayerBits(void *stateObject) {
    g_GlobalZE->mPlayerSendIndex = 0;
}
#pragma thumb off

#pragma thumb on

void UpdateMPSendPlayerBits(void *stateObject) {
    if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT) {
        if ((g_GlobalZE->mRecordReceivedMask & (1 << g_GlobalZE->mPlayerSendIndex)) != 0) {
            if (QueueMPDataPlayerBits(g_GlobalZE->mPlayerSendIndex, g_GlobalZE->mChildren.mChildMask) !=
                FALSE) {
                g_GlobalZE->mPlayerSendIndex += 1;
            }
        } else {
            g_GlobalZE->mPlayerSendIndex += 1;
        }
        if (g_GlobalZE->mPlayerSendIndex > MP_PARTICIPANT_SLOT_COUNT) {
            MPStatesRequestMPState(MP_STATE_SEND_PLAYER_NAMES);
        }
    } else if (g_GlobalZE->mRecordReceivedMask ==
               (g_GlobalZE->mRecordReceivedMask & g_GlobalZE->mBitsReceivedMask)) {
        MPStatesRequestMPState(MP_STATE_SEND_PLAYER_NAMES);
    }
}
#pragma thumb off

#pragma thumb on

void EnterMPReadyNop(void *stateObject) {}

#pragma thumb off
