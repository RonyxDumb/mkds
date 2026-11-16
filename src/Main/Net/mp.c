#include "Main/Net/mp.h"
#include "Main/System/heap.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Net/pending_files.h"
#include "Main/Net/scan.h"
#include "Main/Net/mp_states_connection.h"

#include "Main/Sound/sound_set_load.h"
#include "Main/System/backup_net_camera_work.h"
#include "file_handle_setup.h"
#include "cpu_copy_fill.h"
#include "Main/System/result_archive_path.h"
#include "Main/Net/disconnect.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Net/mp_chunk_state_machine.h"

#pragma thumb on

void AllocateSomeZEStuff_from_thumb(void *heap) {
    int slot;
    int byteOffset;
    void *allocation;
    ConnectionWork **workAddress;
    allocation = Mem_AllocateHeapAligned(heap, MP_CHUNK_PACKET_BYTES, HEAP_ALIGN_CACHE_LINE);
    workAddress = &g_GlobalZE;
    g_GlobalZE->mChunkBuffer = allocation;
    slot = 0;
    byteOffset = 0;
    do {
        allocation = Mem_AllocateHeap(heap, MP_CHUNK_FLAGS_PER_SLOT);
        g_GlobalZE->mChunkReceivedFlags[slot] = allocation;
        byteOffset = byteOffset + 4;
        slot = slot + 1;
    } while (slot < 8);
}

#pragma thumb off

#pragma thumb on

static inline u32 MPStatesGetConnectionMode(void) {
    if (g_GlobalZE == NULL) {
        return 0;
    }
    return g_GlobalZE->mConnectionMode;
}

static inline s32 MPStatesIsConnectionActive(void) {
    BOOL result = FALSE;
    if (MPStatesGetConnectionMode() != CONNECTION_MODE_NONE && g_GlobalZE->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

static inline s32 MPStatesIsConnectionActiveNotEnding(void) {
    BOOL result = FALSE;
    if (MPStatesIsConnectionActive() && !(g_GlobalZE->mFlags & CONNECTION_FLAG_ENDING)) {
        result = TRUE;
    }
    return result;
}

static inline s32 MPStatesIsConnectionActiveNotEndingWithError(void) {
    BOOL result = FALSE;
    if (MPStatesIsConnectionActiveNotEnding() && g_GlobalZE->mErrorCode != CONNECTION_ERROR_NONE) {
        result = TRUE;
    }
    return result;
}

void StoreReceivedPlayerNameByState(const void *data, u8 aid, s32 playerIndex, s32 keepMask) {
    s32 state;
    s32 playerBit;

    state = g_GlobalZE->mState;
    if (state != CONNECTION_STATE_GATHERING) {
        StoreReceivedPlayerName(data, playerIndex, keepMask);
        return;
    }
    playerBit = 1 << playerIndex;
    if (!(g_GlobalZE->mNamesStoredMask & playerBit)) {
        Mem_CpuCopy8(data, &g_GlobalZE->mPlayerRecords[playerIndex], PLAYER_NAME_BYTES);
        g_GlobalZE->mNamesStoredMask |= playerBit;
    }
}

s32 IsAllMPChildSharedDataCopied(void) {
    s32 allCopied;
    u16 childIndex;
    u8 childMask;

    allCopied = 1;
    childIndex = allCopied;
    childMask = g_GlobalZE->mChildren.mChildMask;
    for (; childIndex < 8; childIndex++) {
        if ((childMask & (allCopied << childIndex)) &&
            g_GlobalZE->mDataSharing.mSharedDataCopied[childIndex] == 0) {
            allCopied = 0;
            break;
        }
    }
    return allCopied;
}

s32 AdvanceParentSync(void) {
    BOOL done;

    done = FALSE;
    switch (g_GlobalZE->mSyncState) {
        case CONNECTION_SYNC_START:
            g_GlobalZE->mSyncState = CONNECTION_SYNC_PARENT_WAIT_CHILDREN;
            break;
        case CONNECTION_SYNC_PARENT_WAIT_CHILDREN:
            if (g_GlobalZE->mChildren.mChildMask ==
                (g_GlobalZE->mChildren.mChildMask & g_GlobalZE->mSyncDoneChildMask)) {
                g_GlobalZE->mSyncState = CONNECTION_SYNC_PARENT_ANNOUNCE;
            }
            break;
        case CONNECTION_SYNC_PARENT_ANNOUNCE:
            if (QueueMPDataHalfword(MP_MESSAGE_TRANSFER_SYNC_DONE, 0xff) != FALSE) {
                g_GlobalZE->mSyncDoneChildMask = done;
                g_GlobalZE->mSyncState = CONNECTION_SYNC_DONE;
            }
            break;
        case CONNECTION_SYNC_DONE:
            done = TRUE;
            break;
    }
    return done;
}

s32 AdvanceChildArchiveSync(s32 archiveKind, void *courseId, void *mode) {
    BOOL done;

    done = FALSE;
    switch (g_GlobalZE->mSyncState) {
        case CONNECTION_SYNC_START:
            if (g_GlobalZE->mFlags & CONNECTION_FLAG_SEND_READY) {
                g_GlobalZE->mSyncState = CONNECTION_SYNC_CHILD_LOAD;
            }
            break;
        case CONNECTION_SYNC_CHILD_LOAD:
            if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                switch (archiveKind) {
                    case MP_ARCHIVE_KIND_MAIN_AND_MENU:
                        RequestMainAndMenuDLArchives();
                        break;
                    case MP_ARCHIVE_KIND_RACE:
                        RequestRaceArchives(courseId, mode);
                        break;
                    case MP_ARCHIVE_KIND_RESULT:
                        RequestResultDLArchives();
                        break;
                    case MP_ARCHIVE_KIND_MENU:
                        RequestMenuDLArchives();
                        break;
                }
                g_GlobalZE->mStep = CONNECTION_STEP_CHILD_ARCHIVE_SYNC;
                g_GlobalZE->mRequestPending = 1;
                g_GlobalZE->mNextLoadIndex = 0;
                Fs_File_Initialize(&g_GlobalZE->mFile);
                g_GlobalZE->mSyncState = CONNECTION_SYNC_CHILD_LOAD_WAIT;
            } else {
                g_GlobalZE->mSyncState = CONNECTION_SYNC_CHILD_REPORT;
            }
            QueueMPDataHalfword(MP_MESSAGE_SYNC_NOT_DONE, 1);
            break;
        case CONNECTION_SYNC_CHILD_LOAD_WAIT:
            if (LoadPendingFiles() != FALSE) {
                g_GlobalZE->mSyncState = CONNECTION_SYNC_CHILD_REPORT;
            }
            break;
        case CONNECTION_SYNC_CHILD_REPORT:
            if (QueueMPDataHalfword(MP_MESSAGE_SYNC_DONE, 1) != FALSE) {
                g_GlobalZE->mSyncState = CONNECTION_SYNC_DONE;
            }
            break;
        case CONNECTION_SYNC_DONE:
            if (g_GlobalZE->mTransferFlags & CONNECTION_TRANSFER_SYNC_DONE) {
                done = TRUE;
            }
            break;
    }
    return done;
}

u32 AdvanceMainAndMenuDLArchives(void) {
    if (MPStatesIsConnectionActiveNotEndingWithError()) {
        return 3;
    }
    switch (MPStatesGetConnectionMode()) {
        case CONNECTION_MODE_PARENT:
            return AdvanceParentSync();
        case CONNECTION_MODE_CHILD:
            return AdvanceChildArchiveSync(MP_ARCHIVE_KIND_MAIN_AND_MENU, NULL, NULL);
        default:
            return 3;
    }
}

#pragma thumb off

#pragma thumb on

// Asks for state 16 with the next race's course and mode.
void RequestMPWaitRaceArchives(void *courseId, void *mode) {
    MPStateMachine *stateMachine;
    g_GlobalZE->mSyncState = CONNECTION_SYNC_START;
    g_GlobalZE->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    stateMachine = &g_GlobalZE->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = MP_STATE_WAIT_RACE_ARCHIVES;
    stateMachine->mStateMachine.mNextStateRequested = 1;
    g_GlobalZE->mCourseId = courseId;
    g_GlobalZE->mMode = mode;
}

#pragma thumb off

#pragma thumb on

void RequestMPWaitResultArchives(void) {
    MPStateMachine *stateMachine;

    g_GlobalZE->mSyncState = CONNECTION_SYNC_START;
    g_GlobalZE->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    stateMachine = &g_GlobalZE->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = MP_STATE_WAIT_RESULT_ARCHIVES;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

void RequestMPWaitMenuArchives(void) {
    MPStateMachine *stateMachine;

    g_GlobalZE->mSyncState = CONNECTION_SYNC_START;
    g_GlobalZE->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    stateMachine = &g_GlobalZE->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = MP_STATE_WAIT_MENU_ARCHIVES;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

u32 AdvanceRaceArchives(void) {
    if (MPStatesIsConnectionActiveNotEndingWithError()) {
        return 3;
    }
    if (!MPStatesIsConnectionActive()) {
        return 1;
    }
    switch (MPStatesGetConnectionMode()) {
        case CONNECTION_MODE_PARENT:
            return AdvanceParentSync();
        case CONNECTION_MODE_CHILD:
            return AdvanceChildArchiveSync(MP_ARCHIVE_KIND_RACE, g_GlobalZE->mCourseId, g_GlobalZE->mMode);
        default:
            return 3;
    }
}

#pragma thumb off

#pragma thumb on

void StructZE_E7Fn_16_1_from_thumb(void *stateObject) {
    int connectionMode;
    if (g_GlobalZE == NULL) {
        connectionMode = CONNECTION_MODE_NONE;
    } else {
        connectionMode = g_GlobalZE->mConnectionMode;
    }
    if (connectionMode == CONNECTION_MODE_PARENT) {
        SetMPFrequency(0);
    }
}

void StructZE_E7Fn_16_2_from_thumb(void *stateObject) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceRaceArchives();
    if (result == 1) {
        stateMachine = &g_GlobalZE->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = MP_STATE_LOAD_COURSE_SOUND;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

void LoadCourseSoundSetCallback(void) {
    u32 loaded;

    loaded = LoadCourseSoundSet((u32) g_GlobalZE->mMode, (u32) g_GlobalZE->mCourseId);
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        MaybeReloadRacersSfx(0);
    }
    if (loaded == 0) {
        g_GlobalZE->mCallbackFailed = 1;
    }
}

void StructZE_E7Fn_17_1_from_thumb(void *stateObject) {
    g_GlobalZE->mSyncState = CONNECTION_SYNC_START;
    g_GlobalZE->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    g_GlobalZE->mCallbackFailed = 0;
}

#pragma thumb off

#pragma thumb on

void StructZE_E7Fn_17_2_from_thumb(void *stateObject) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceSyncedCallback(LoadCourseSoundSetCallback);
    if (result == 1) {
        stateMachine = &g_GlobalZE->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = MP_STATE_WAIT_REQUEST_DONE;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

void StructZE_E7Fn_20_1_from_thumb(void *stateObject) {
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

void StructZE_E7Fn_20_2_from_thumb(void *stateObject) {
    MPStateMachine *stateMachine;
    if (g_GlobalZE->mRequestPending == 0) {
        stateMachine = &g_GlobalZE->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = MP_STATE_READY;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off
