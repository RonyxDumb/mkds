#include "Main/Net/mp_chunk_state_machine.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Net/mp_states.h"
#include "Main/Net/mp_states_connection.h"
#include "Main/Net/mp_state.h"
#include "Main/Net/mp.h"
#include "Main/Net/slot_result_sync.h"
#include "thread_scheduler.h"
#include "Main/System/state_machine_init.h"
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
#include "Main/System/backup_net_camera_work.h"
#include "arena_cache_init.h"
#include "cpu_copy_fill.h"
#include "Main/Net/mp_link.h"

StateCallbacks g_E7FnList1[MP_STATE_COUNT] = {{E7Fn1_0_from_thumb, UpdateMPFillOwnRecord},
                                                {NULL, UpdateMPWaitRomArchive},
                                                {EnterMPLoadOverlay, UpdateMPLoadOverlay},
                                                {EnterMPLoadDlArchives, UpdateMPLoadDlArchives},
                                                {EnterMPLoadSoundData, UpdateMPLoadSoundData},
                                                {EnterMPSendParticipantMask, UpdateMPSendParticipantMask},
                                                {NULL, UpdateMPSendGroupSendMask},
                                                {EnterMPStartExchange, UpdateMPStartExchange},
                                                {EnterMPExchangeOwnRecords, UpdateMPExchangeOwnRecords},
                                                {EnterMPSendAllRecords, UpdateMPSendAllRecords},
                                                {EnterMPSendRomArchive, UpdateMPSendRomArchive},
                                                {EnterMPSendPlayerNames, UpdateMPSendPlayerNames},
                                                {EnterMPStartDataSharing, UpdateMPStartDataSharing},
                                                {EnterMPExchangePlayerBits, UpdateMPExchangePlayerBits},
                                                {EnterMPSendPlayerBits, UpdateMPSendPlayerBits},
                                                {EnterMPReadyNop, NULL},
                                                {StructZE_E7Fn_16_1_from_thumb, StructZE_E7Fn_16_2_from_thumb},
                                                {StructZE_E7Fn_17_1_from_thumb, StructZE_E7Fn_17_2_from_thumb},
                                                {StructZE_E7Fn_18_1_from_thumb, StructZE_E7Fn_18_2_from_thumb},
                                                {StructZE_E7Fn_19_1_from_thumb, StructZE_E7Fn_19_2_from_thumb},
                                                {StructZE_E7Fn_20_1_from_thumb, StructZE_E7Fn_20_2_from_thumb},
                                                {StructZE_E7Fn_21_1_from_thumb, StructZE_E7Fn_21_2_from_thumb},
                                                {StructZE_E7Fn_22_1_from_thumb, StructZE_E7Fn_22_2_from_thumb}};

#pragma opt_rebuildconditionals off

s32 SceneFn_Result(SceneNumbers *sceneNumbers) {
    SceneCallbacks resultSceneCallbacks = g_Scene_Result;

    OnSceneLoop(sceneNumbers, &resultSceneCallbacks);
    return 0;
}

#pragma thumb on

static inline u32 MPChunkGetConnectionMode(void) {
    if (g_GlobalZE == NULL) {
        return 0;
    }
    return g_GlobalZE->mConnectionMode;
}

static inline void MPChunkRequestMPState(u16 nextState) {
    MPStateMachine *stateMachine = &g_GlobalZE->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = nextState;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

u32 IsAllMPChunksReceived(u32 slot) {
    u32 chunkCount;
    u8 *receivedFlags;
    u32 allReceived;
    u32 chunkIndex;

    receivedFlags = g_GlobalZE->mChunkReceivedFlags[slot];
    allReceived = 1;
    if (MPChunkGetConnectionMode() == CONNECTION_MODE_PARENT) {
        chunkCount = MP_CHUNK_FLAGS_PER_SLOT;
    } else {
        chunkCount = 2;
    }
    for (chunkIndex = 0; chunkIndex < chunkCount; chunkIndex++) {
        if (receivedFlags[chunkIndex] == 0) {
            allReceived = 0;
            break;
        }
    }
    return allReceived;
}

void ProcessMPChunk(u8 *chunk) {
    u32 playerIndex;
    PlayerRecord *entry;
    u32 finished;
    u32 byteOffset;
    u16 ownIndex;
    u8 playerBit;

    playerIndex = chunk[0];
    entry = &g_GlobalZE->mPlayerRecords[playerIndex];
    finished = 0;
    if (MPChunkGetConnectionMode() == CONNECTION_MODE_PARENT) {
        byteOffset = chunk[1] << 5;
    } else {
        byteOffset = chunk[1] * 0x168;
    }
    switch (chunk[1]) {
        case MP_CHUNK_RECORD_ARRIVED:
            if (MPChunkGetConnectionMode() == CONNECTION_MODE_CHILD) {
                MPChunkRequestMPState(MP_STATE_SEND_ALL_RECORDS);
            }
            break;
        case MP_CHUNK_HELD_RECORDS_MASK:
            if (MPChunkGetConnectionMode() == CONNECTION_MODE_CHILD) {
                g_GlobalZE->mExpectedRecordMask = *(u16 *) (chunk + 2);
            }
            break;
        case MP_CHUNK_ALL_RECORDS_HELD:
            if (MPChunkGetConnectionMode() == CONNECTION_MODE_PARENT) {
                BIT_SET(g_GlobalZE->mRecordReceivedMask, playerIndex);
                if (g_GlobalZE->mChildren.mChildMask ==
                    (g_GlobalZE->mChildren.mChildMask & g_GlobalZE->mRecordReceivedMask)) {
                    MPChunkRequestMPState(MP_STATE_SEND_ROM_ARCHIVE);
                }
            }
            break;
        case MP_CHUNK_NO_EMBLEM:
            g_GlobalZE->mPlayerRecords[playerIndex].mHasEmblem = 0;
            finished = 1;
            break;
        default:
            Mem_CpuCopy8(chunk + 4, entry->mName + byteOffset, *(u16 *) (chunk + 2));
            g_GlobalZE->mChunkReceivedFlags[chunk[0]][chunk[1]] = 1;
            if (IsAllMPChunksReceived(chunk[0]) != 0) {
                finished = 1;
            }
            break;
    }
    if (finished != 0) {
        playerBit = 1U << chunk[0];
        if (MPChunkGetConnectionMode() == CONNECTION_MODE_PARENT) {
            if (QueueMPChunk(MP_CHUNK_RECORD_ARRIVED, NULL, 0, 0, playerBit) != FALSE) {
                g_GlobalZE->mRecordReceivedMask |= 1 << chunk[0];
                return;
            }
        } else {
            g_GlobalZE->mRecordReceivedMask |= 1 << chunk[0];
            if (g_GlobalZE->mExpectedRecordMask ==
                (g_GlobalZE->mExpectedRecordMask & g_GlobalZE->mRecordReceivedMask)) {
                ownIndex = g_GlobalZE->mConnectionMode == CONNECTION_MODE_CHILD ? g_GlobalZE->mOwnIndex : 0;
                if (QueueMPChunk(MP_CHUNK_ALL_RECORDS_HELD, NULL, 0, ownIndex, 1) != FALSE) {
                    MPChunkRequestMPState(MP_STATE_SEND_ROM_ARCHIVE);
                }
            }
        }
    }
}

void MPChunkPortCallback(void *portMessage) {
    WirelessMessage *event = portMessage;
    if (event->mResultCode == WIRELESS_RESULT_SUCCEEDED && event->mData != NULL &&
        event->mLength >= MP_CHUNK_HEADER_SIZE) {
        DC_SomeClean(event->mData, event->mLength);
        switch (event->mState) {
            case WIRELESS_STATE_LINKED:
            case WIRELESS_STATE_UNLINKED:
                break;
            case WIRELESS_STATE_PORT_DATA_ARRIVED:
                ProcessMPChunk(event->mData);
                break;
        }
    }
}

void InitMPStateMachine(void) {
    ConnectionWork *connectionWork;
    u32 connectionMode;

    StateDualHandler_Create(&g_GlobalZE->mMPStateMachine.mStateMachine, g_E7FnList1, MP_STATE_COUNT, NULL);
    g_GlobalZE->mPlayerSendIndex = 0;
    g_GlobalZE->mMPStateMachine.mChildDataWaitFrames = 0;
    g_GlobalZE->mMPStateMachine.mChunkSendFlags = 0;
    g_GlobalZE->mEntryChunkIndex = 0;
    g_GlobalZE->mRecordReceivedMask = 0;
    g_GlobalZE->mNamesStoredMask = 0;
    connectionWork = g_GlobalZE;
    connectionMode = CONNECTION_MODE_NONE;
    if (connectionWork != NULL) {
        connectionMode = connectionWork->mConnectionMode;
    }
    if (connectionMode == CONNECTION_MODE_PARENT) {
        connectionWork->mChildren.mExpectedRecordMask = (connectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0
                                                            ? connectionWork->mMultiBootChildMask
                                                            : connectionWork->mChildren.mChildMask;
    }
    g_GlobalZE->mRaceSeed = 0;
}

#pragma thumb off
