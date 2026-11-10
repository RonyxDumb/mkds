#include "Main/Unknown/code_0205928c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_0204f644.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/code_02051000.h"
#include "Main/Unknown/code_02058000.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"

#include "Main/Unknown/code_0210e33c.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "fs_file.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"

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

static inline u32 func_0205955c_inline(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 func_0205955c_inline2(void) {
    BOOL r = FALSE;
    if (func_0205955c_inline() != 0 && gConnectionWork->mState != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0205955c_inline3(void) {
    BOOL r = FALSE;
    if (func_0205955c_inline2() && !(gConnectionWork->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0205955c_inline4(void) {
    BOOL r = FALSE;
    if (func_0205955c_inline3() && gConnectionWork->mErrorCode != 9) {
        r = TRUE;
    }
    return r;
}

void func_020597d0(const void *data, s32 b, s32 playerIndex, s32 d) {
    s32 v;
    s32 playerBit;

    v = gConnectionWork->mState;
    if (v != 11) {
        StoreReceivedPlayerName(data, playerIndex, d);
        return;
    }
    playerBit = 1 << playerIndex;
    if (!(gConnectionWork->mUnk_164c & playerBit)) {
        MI_CpuCopy8(data, &gConnectionWork->mUnk_045c[playerIndex], 0x14);
        gConnectionWork->mUnk_164c |= playerBit;
    }
}

s32 IsAllMPChildSharedDataCopied(void) {
    s32 allCopied;
    u16 childIndex;
    u8 childMask;

    allCopied = 1;
    childIndex = allCopied;
    childMask = gConnectionWork->mUnk_0044.mChildMask;
    for (; childIndex < 8; childIndex++) {
        if ((childMask & (allCopied << childIndex)) &&
            gConnectionWork->mUnk_15bc_view.mSharedDataCopied[childIndex] == 0) {
            allCopied = 0;
            break;
        }
    }
    return allCopied;
}

s32 func_02059700(void) {
    BOOL done;

    done = FALSE;
    switch (gConnectionWork->mSyncState) {
        case 0:
            gConnectionWork->mSyncState = 6;
            break;
        case 6:
            if (gConnectionWork->mUnk_0044.mChildMask ==
                (gConnectionWork->mUnk_0044.mChildMask & gConnectionWork->mSyncDoneChildMask)) {
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

s32 func_020595e8(s32 a, void *b, void *c) {
    BOOL done;

    done = FALSE;
    switch (gConnectionWork->mSyncState) {
        case 0:
            if (gConnectionWork->mUnk_0454 & 1) {
                gConnectionWork->mSyncState = 2;
            }
            break;
        case 2:
            if (gBootInfo->mUnk_00 == 2) {
                switch (a) {
                    case 0:
                        RequestMainAndMenuDLArchives();
                        break;
                    case 1:
                        RequestRaceArchives(b, c);
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
            if (gConnectionWork->mUnk_1e44 & 2) {
                done = TRUE;
            }
            break;
    }
    return done;
}

u32 func_0205955c(void) {
    if (func_0205955c_inline4()) {
        return 3;
    }
    switch (func_0205955c_inline()) {
        case 1:
            return func_02059700();
        case 2:
            return func_020595e8(0, NULL, NULL);
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
    gConnectionWork->mUnk_1e44 &= ~2;
    stateMachine = &gConnectionWork->mUnk_1608;
    stateMachine->mStateMachine.mNextState = 0x10;
    stateMachine->mStateMachine.mNextStateRequested = 1;
    gConnectionWork->mCourseId = courseId;
    gConnectionWork->mMode = mode;
}

#pragma thumb off

#pragma thumb on

static inline u32 func_020593dc_inline(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 func_020593dc_inline2(void) {
    BOOL r = FALSE;
    if (func_020593dc_inline() != 0 && gConnectionWork->mState != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020593dc_inline3(void) {
    BOOL r = FALSE;
    if (func_020593dc_inline2() && !(gConnectionWork->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020593dc_inline4(void) {
    BOOL r = FALSE;
    if (func_020593dc_inline3() && gConnectionWork->mErrorCode != 9) {
        r = TRUE;
    }
    return r;
}

void RequestMPState18(void) {
    MPStateMachine *stateMachine;

    gConnectionWork->mSyncState = 0;
    gConnectionWork->mUnk_1e44 &= ~2;
    stateMachine = &gConnectionWork->mUnk_1608;
    stateMachine->mStateMachine.mNextState = 0x12;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

void RequestMPState21(void) {
    MPStateMachine *stateMachine;

    gConnectionWork->mSyncState = 0;
    gConnectionWork->mUnk_1e44 &= ~2;
    stateMachine = &gConnectionWork->mUnk_1608;
    stateMachine->mStateMachine.mNextState = 0x15;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

u32 func_020593dc(void) {
    if (func_020593dc_inline4()) {
        return 3;
    }
    if (!func_020593dc_inline2()) {
        return 1;
    }
    switch (func_020593dc_inline()) {
        case 1:
            return func_02059700();
        case 2:
            return func_020595e8(1, gConnectionWork->mCourseId, gConnectionWork->mMode);
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
    result = func_020593dc();
    if (result == 1) {
        stateMachine = &gConnectionWork->mUnk_1608;
        stateMachine->mStateMachine.mNextState = 0x11;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

void func_0205933c(void) {
    u32 loaded;

    loaded = LoadCourseSoundSet((u32) gConnectionWork->mMode, (u32) gConnectionWork->mCourseId);
    if (gBootInfo->mUnk_00 == 2) {
        LoadSndBanksForCharacters(0);
    }
    if (loaded == 0) {
        gConnectionWork->mCallbackFailed = 1;
    }
}

void func_02059304(void) {
    gConnectionWork->mSyncState = 0;
    gConnectionWork->mUnk_1e44 &= ~2;
    gConnectionWork->mCallbackFailed = 0;
}

#pragma thumb off

#pragma thumb on

void UpdateMPState17(void) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceSyncedCallback(func_0205933c);
    if (result == 1) {
        stateMachine = &gConnectionWork->mUnk_1608;
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
        stateMachine = &gConnectionWork->mUnk_1608;
        stateMachine->mStateMachine.mNextState = 0xf;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off
