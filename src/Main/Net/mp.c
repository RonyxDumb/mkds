#include "Main/Net/mp.h"
#include "Main/System/heap.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Net/pending_files.h"
#include "Main/Net/scan.h"
#include "Main/Net/mp_states_connection.h"

#include "Main/Sound/sound_set_load.h"
#include "Main/MapObjects/data_0217a000.h"
#include "fs_file.h"
#include "code_0214d018.h"
#include "Main/System/result_archive_path.h"
#include "Main/Net/disconnect.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Menu/select_race_rule_state.h"

#pragma thumb on

void InitMPChunkBuffers(void *heap) {
    int slot;
    int v2;
    void *v3;
    int *v4;
    v3 = HeapAllocAligned(heap, (0x0000016cu), 0x20);
    v4 = (s32 *) &gConnectionWork;
    gConnectionWork->mChunkBuffer = v3;
    slot = 0;
    v2 = 0;
    do {
        v3 = HeapAlloc(heap, 0x12);
        gConnectionWork->mChunkReceivedFlags[slot] = v3;
        v2 = v2 + 4;
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
    if (MPStatesGetConnectionMode() != 0 && gConnectionWork->mState != 13) {
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
    if (MPStatesIsConnectionActiveNotEnding() && gConnectionWork->mErrorCode != 9) {
        result = TRUE;
    }
    return result;
}

void StoreReceivedPlayerNameByState(const void *data, s32 aid, s32 playerIndex, s32 keepMask) {
    s32 state;
    s32 playerBit;

    state = gConnectionWork->mState;
    if (state != 11) {
        StoreReceivedPlayerName(data, playerIndex, keepMask);
        return;
    }
    playerBit = 1 << playerIndex;
    if (!(gConnectionWork->mNamesStoredMask & playerBit)) {
        MI_CpuCopy8(data, &gConnectionWork->mPlayerRecords[playerIndex], 0x14);
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
            gConnectionWork->mUnk_15bc_view.mSharedDataCopied[childIndex] == 0) {
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
        case 0:
            gConnectionWork->mSyncState = 6;
            break;
        case 6:
            if (gConnectionWork->mChildren.mChildMask ==
                (gConnectionWork->mChildren.mChildMask & gConnectionWork->mSyncDoneChildMask)) {
                gConnectionWork->mSyncState = 7;
            }
            break;
        case 7:
            if (QueueMPDataHalfword(5, 0xff) != FALSE) {
                gConnectionWork->mSyncDoneChildMask = done;
                gConnectionWork->mSyncState = 1;
            }
            break;
        case 1:
            done = TRUE;
            break;
    }
    return done;
}

s32 AdvanceChildArchiveSync(s32 archiveKind, void *courseId, void *mode) {
    BOOL done;

    done = FALSE;
    switch (gConnectionWork->mSyncState) {
        case 0:
            if (gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY) {
                gConnectionWork->mSyncState = 2;
            }
            break;
        case 2:
            if (gBootInfo->mBootType == 2) {
                switch (archiveKind) {
                    case 0:
                        RequestMainAndMenuDLArchives();
                        break;
                    case 1:
                        RequestRaceArchives(courseId, mode);
                        break;
                    case 2:
                        RequestResultDLArchives();
                        break;
                    case 3:
                        RequestMenuDLArchives();
                        break;
                }
                gConnectionWork->mStep = 0x27;
                gConnectionWork->mRequestPending = 1;
                gConnectionWork->mNextLoadIndex = 0;
                FS_InitFile(&gConnectionWork->mFile);
                gConnectionWork->mSyncState = 3;
            } else {
                gConnectionWork->mSyncState = 5;
            }
            QueueMPDataHalfword(3, 1);
            break;
        case 3:
            if (LoadPendingFiles() != FALSE) {
                gConnectionWork->mSyncState = 5;
            }
            break;
        case 5:
            if (QueueMPDataHalfword(4, 1) != FALSE) {
                gConnectionWork->mSyncState = 1;
            }
            break;
        case 1:
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
        case 1:
            return AdvanceParentSync();
        case 2:
            return AdvanceChildArchiveSync(0, NULL, NULL);
        default:
            return 3;
    }
}

#pragma thumb off

#pragma thumb on

// Asks for state 16 with the next race's course and mode.
void RequestMPState16(void *courseId, void *mode) {
    MPStateMachine *stateMachine;
    gConnectionWork->mSyncState = 0;
    gConnectionWork->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    stateMachine = &gConnectionWork->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = 0x10;
    stateMachine->mStateMachine.mNextStateRequested = 1;
    gConnectionWork->mCourseId = courseId;
    gConnectionWork->mMode = mode;
}

#pragma thumb off

#pragma thumb on

void RequestMPState18(void) {
    MPStateMachine *stateMachine;

    gConnectionWork->mSyncState = 0;
    gConnectionWork->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    stateMachine = &gConnectionWork->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = 0x12;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

void RequestMPState21(void) {
    MPStateMachine *stateMachine;

    gConnectionWork->mSyncState = 0;
    gConnectionWork->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    stateMachine = &gConnectionWork->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = 0x15;
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
        case 1:
            return AdvanceParentSync();
        case 2:
            return AdvanceChildArchiveSync(1, gConnectionWork->mCourseId, gConnectionWork->mMode);
        default:
            return 3;
    }
}

#pragma thumb off

#pragma thumb on

void EnterMPState16(void) {
    int v1;
    if (gConnectionWork == NULL) {
        v1 = 0;
    } else {
        v1 = gConnectionWork->mConnectionMode;
    }
    if (v1 == 1) {
        SetMPFrequency(0);
    }
}

void UpdateMPState16(void) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceRaceArchives();
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = 0x11;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

void LoadCourseSoundSetCallback(void) {
    u32 loaded;

    loaded = LoadCourseSoundSet((u32) gConnectionWork->mMode, (u32) gConnectionWork->mCourseId);
    if (gBootInfo->mBootType == 2) {
        LoadSndBanksForCharacters(0);
    }
    if (loaded == 0) {
        gConnectionWork->mCallbackFailed = 1;
    }
}

void EnterMPState17(void) {
    gConnectionWork->mSyncState = 0;
    gConnectionWork->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    gConnectionWork->mCallbackFailed = 0;
}

#pragma thumb off

#pragma thumb on

void UpdateMPState17(void) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceSyncedCallback(LoadCourseSoundSetCallback);
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = 0x14;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

void EnterMPState20(void) {
    int v1;
    if (gConnectionWork == NULL) {
        v1 = 0;
    } else {
        v1 = gConnectionWork->mConnectionMode;
    }
    if (v1 == 1) {
        SetMPFrequency(1);
    }
}

void UpdateMPState20(void) {
    MPStateMachine *stateMachine;
    if (gConnectionWork->mRequestPending == 0) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = 0xf;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off
