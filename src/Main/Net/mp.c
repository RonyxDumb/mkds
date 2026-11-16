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

void InitMPChunkBuffers(void *heap) {
    int slot;
    int byteOffset;
    void *allocation;
    ConnectionWork **workAddress;
    allocation = HeapAllocAligned(heap, MP_CHUNK_PACKET_BYTES, HEAP_ALIGN_CACHE_LINE);
    workAddress = &gConnectionWork;
    gConnectionWork->mChunkBuffer = allocation;
    slot = 0;
    byteOffset = 0;
    do {
        allocation = HeapAlloc(heap, MP_CHUNK_FLAGS_PER_SLOT);
        gConnectionWork->mChunkReceivedFlags[slot] = allocation;
        byteOffset = byteOffset + 4;
        slot = slot + 1;
    } while (slot < 8);
}

#pragma thumb off

#pragma thumb on

static inline u32 MPStatesGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 MPStatesIsConnectionActive(void) {
    BOOL result = FALSE;
    if (MPStatesGetConnectionMode() != CONNECTION_MODE_NONE && gConnectionWork->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

static inline s32 MPStatesIsConnectionActiveNotEnding(void) {
    BOOL result = FALSE;
    if (MPStatesIsConnectionActive() && !(gConnectionWork->mFlags & CONNECTION_FLAG_ENDING)) {
        result = TRUE;
    }
    return result;
}

static inline s32 MPStatesIsConnectionActiveNotEndingWithError(void) {
    BOOL result = FALSE;
    if (MPStatesIsConnectionActiveNotEnding() && gConnectionWork->mErrorCode != CONNECTION_ERROR_NONE) {
        result = TRUE;
    }
    return result;
}

void StoreReceivedPlayerNameByState(const void *data, u8 aid, s32 playerIndex, s32 keepMask) {
    s32 state;
    s32 playerBit;

    state = gConnectionWork->mState;
    if (state != CONNECTION_STATE_GATHERING) {
        StoreReceivedPlayerName(data, playerIndex, keepMask);
        return;
    }
    playerBit = 1 << playerIndex;
    if (!(gConnectionWork->mNamesStoredMask & playerBit)) {
        MI_CpuCopy8(data, &gConnectionWork->mPlayerRecords[playerIndex], PLAYER_NAME_BYTES);
        gConnectionWork->mNamesStoredMask |= playerBit;
    }
}

s32 IsAllMPChildSharedDataCopied(void) {
    s32 allCopied;
    u16 childIndex;
    u8 childMask;

    allCopied = 1;
    childIndex = allCopied;
    childMask = gConnectionWork->mChildren.mChildMask;
    for (; childIndex < 8; childIndex++) {
        if ((childMask & (allCopied << childIndex)) &&
            gConnectionWork->mDataSharing.mSharedDataCopied[childIndex] == 0) {
            allCopied = 0;
            break;
        }
    }
    return allCopied;
}

s32 AdvanceParentSync(void) {
    BOOL done;

    done = FALSE;
    switch (gConnectionWork->mSyncState) {
        case CONNECTION_SYNC_START:
            gConnectionWork->mSyncState = CONNECTION_SYNC_PARENT_WAIT_CHILDREN;
            break;
        case CONNECTION_SYNC_PARENT_WAIT_CHILDREN:
            if (gConnectionWork->mChildren.mChildMask ==
                (gConnectionWork->mChildren.mChildMask & gConnectionWork->mSyncDoneChildMask)) {
                gConnectionWork->mSyncState = CONNECTION_SYNC_PARENT_ANNOUNCE;
            }
            break;
        case CONNECTION_SYNC_PARENT_ANNOUNCE:
            if (QueueMPDataHalfword(MP_MESSAGE_TRANSFER_SYNC_DONE, 0xff) != FALSE) {
                gConnectionWork->mSyncDoneChildMask = done;
                gConnectionWork->mSyncState = CONNECTION_SYNC_DONE;
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
    switch (gConnectionWork->mSyncState) {
        case CONNECTION_SYNC_START:
            if (gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY) {
                gConnectionWork->mSyncState = CONNECTION_SYNC_CHILD_LOAD;
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
                gConnectionWork->mStep = CONNECTION_STEP_CHILD_ARCHIVE_SYNC;
                gConnectionWork->mRequestPending = 1;
                gConnectionWork->mNextLoadIndex = 0;
                FS_InitFile(&gConnectionWork->mFile);
                gConnectionWork->mSyncState = CONNECTION_SYNC_CHILD_LOAD_WAIT;
            } else {
                gConnectionWork->mSyncState = CONNECTION_SYNC_CHILD_REPORT;
            }
            QueueMPDataHalfword(MP_MESSAGE_SYNC_NOT_DONE, 1);
            break;
        case CONNECTION_SYNC_CHILD_LOAD_WAIT:
            if (LoadPendingFiles() != FALSE) {
                gConnectionWork->mSyncState = CONNECTION_SYNC_CHILD_REPORT;
            }
            break;
        case CONNECTION_SYNC_CHILD_REPORT:
            if (QueueMPDataHalfword(MP_MESSAGE_SYNC_DONE, 1) != FALSE) {
                gConnectionWork->mSyncState = CONNECTION_SYNC_DONE;
            }
            break;
        case CONNECTION_SYNC_DONE:
            if (gConnectionWork->mTransferFlags & CONNECTION_TRANSFER_SYNC_DONE) {
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
    gConnectionWork->mSyncState = CONNECTION_SYNC_START;
    gConnectionWork->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    stateMachine = &gConnectionWork->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = MP_STATE_WAIT_RACE_ARCHIVES;
    stateMachine->mStateMachine.mNextStateRequested = 1;
    gConnectionWork->mCourseId = courseId;
    gConnectionWork->mMode = mode;
}

#pragma thumb off

#pragma thumb on

void RequestMPWaitResultArchives(void) {
    MPStateMachine *stateMachine;

    gConnectionWork->mSyncState = CONNECTION_SYNC_START;
    gConnectionWork->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    stateMachine = &gConnectionWork->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = MP_STATE_WAIT_RESULT_ARCHIVES;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

void RequestMPWaitMenuArchives(void) {
    MPStateMachine *stateMachine;

    gConnectionWork->mSyncState = CONNECTION_SYNC_START;
    gConnectionWork->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    stateMachine = &gConnectionWork->mMPStateMachine;
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
            return AdvanceChildArchiveSync(MP_ARCHIVE_KIND_RACE, gConnectionWork->mCourseId, gConnectionWork->mMode);
        default:
            return 3;
    }
}

#pragma thumb off

#pragma thumb on

void EnterMPWaitRaceArchives(void *stateObject) {
    int connectionMode;
    if (gConnectionWork == NULL) {
        connectionMode = CONNECTION_MODE_NONE;
    } else {
        connectionMode = gConnectionWork->mConnectionMode;
    }
    if (connectionMode == CONNECTION_MODE_PARENT) {
        SetMPFrequency(0);
    }
}

void UpdateMPWaitRaceArchives(void *stateObject) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceRaceArchives();
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = MP_STATE_LOAD_COURSE_SOUND;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

void LoadCourseSoundSetCallback(void) {
    u32 loaded;

    loaded = LoadCourseSoundSet((u32) gConnectionWork->mMode, (u32) gConnectionWork->mCourseId);
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        LoadSndBanksForCharacters(0);
    }
    if (loaded == 0) {
        gConnectionWork->mCallbackFailed = 1;
    }
}

void EnterMPLoadCourseSound(void *stateObject) {
    gConnectionWork->mSyncState = CONNECTION_SYNC_START;
    gConnectionWork->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    gConnectionWork->mCallbackFailed = 0;
}

#pragma thumb off

#pragma thumb on

void UpdateMPLoadCourseSound(void *stateObject) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceSyncedCallback(LoadCourseSoundSetCallback);
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = MP_STATE_WAIT_REQUEST_DONE;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

void EnterMPWaitRequestDone(void *stateObject) {
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

void UpdateMPWaitRequestDone(void *stateObject) {
    MPStateMachine *stateMachine;
    if (gConnectionWork->mRequestPending == 0) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = MP_STATE_READY;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off
