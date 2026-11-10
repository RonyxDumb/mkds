#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200f5ac.h"

#pragma opt_rebuildconditionals off

static inline u32 func_02058b38_inline(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline void func_02058b74_inline(u16 nextState) {
    MPStateMachine *stateMachine = &gConnectionWork->mUnk_1608;
    stateMachine->mStateMachine.mNextState = nextState;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

static inline s32 func_02058cac_inline2(void) {
    BOOL r = FALSE;
    if (func_02058b38_inline() != 0 && gConnectionWork->mState != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02058cac_inline3(void) {
    BOOL r = FALSE;
    if (func_02058cac_inline2() && !(gConnectionWork->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02058cac_inline4(void) {
    BOOL r = FALSE;
    if (func_02058cac_inline3() && gConnectionWork->mErrorCode != 9) {
        r = TRUE;
    }
    return r;
}

#pragma thumb on

s32 AdvanceSyncedCallback(void (*callback)(void)) {
    BOOL done;

    done = FALSE;
    switch (gConnectionWork->mSyncState) {
        case 0:
            if (gConnectionWork->mUnk_0454 & 1) {
                switch (func_02058b38_inline()) {
                    case 1:
                        gConnectionWork->mSyncState = 6;
                        break;
                    case 2:
                        gConnectionWork->mSyncState = 2;
                        break;
                }
            }
            break;
        case 7:
            QueueMPDataHalfword(5, 0xff);
            gConnectionWork->mUnk_1e44 |= 2;
            gConnectionWork->mSyncDoneChildMask = done;
            gConnectionWork->mSyncState = 1;
            break;
        case 6:
            if (gConnectionWork->mUnk_0044.mChildMask ==
                (gConnectionWork->mUnk_0044.mChildMask & gConnectionWork->mSyncDoneChildMask)) {
                gConnectionWork->mSyncState = 7;
            }
            break;
        case 2:
            if (gBootInfo->mUnk_00 == 2) {
                QueueThreadFunction(callback);
                gThreadFunctionQueue->mRunRequested = 1;
            }
            gConnectionWork->mSyncState = 3;
            QueueMPDataHalfword(3, 1);
            break;
        case 3:
            if (gThreadFunctionQueue->mRunRequested == 0) {
                if (gConnectionWork->mCallbackFailed != 0) {
                    SetRequestErrorCode(7);
                } else {
                    gConnectionWork->mSyncState = 5;
                }
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

s32 AdvanceMPStateMachineWithOwnIndex(void) {
    BOOL finished;
    u16 ownIndex;

    finished = FALSE;
    if (!func_02058cac_inline2()) {
        return 1;
    }
    ownIndex = ((const ConnectionWork *) gConnectionWork)->mConnectionMode == 2 ? gConnectionWork->mOwnIndex : 0;
    if (ownIndex == 0xffff && func_02058b38_inline() == 2) {
        if (gBootInfo->mUnk_00 == 2) {
            SetRequestErrorCode(0);
            return 3;
        }
        return 2;
    }
    AdvanceStateMachine(&gConnectionWork->mUnk_1608.mStateMachine);
    if (!func_02058cac_inline4()) {
        if (func_02058b38_inline() == 1 && gConnectionWork->mUnk_0044.mChildCount == 0) {
            SetRequestErrorCode(7);
        }
    }
    if (gConnectionWork->mUnk_1608.mStateMachine.mState == 0xf) {
        finished = TRUE;
    }
    return finished;
}

void EnterMPState0(void) {
    u16 ownIndex;

    ownIndex = gConnectionWork->mConnectionMode == 2 ? gConnectionWork->mOwnIndex : 0;
    FillPlayerRecord(&gConnectionWork->mUnk_045c[ownIndex]);
}

void UpdateMPState0(void) {
    if (gConnectionWork->mRequestPending != 0) {
        return;
    }
    if (func_02058b38_inline() != 1) {
        func_02058b74_inline(0x16);
        return;
    }
    switch (gConnectionWork->mStep) {
        case 11:
        case 15:
            SetEntry(0);
            return;
        case 13:
            func_02058b74_inline(7);
            break;
    }
}

void EnterMPState22(void) {
    u64 v;

    v = (u32) OS_GetTick() << 8;
    v = (u32) v & ~(u32) (v >> 32);
    if (gBootInfo->mUnk_00 == 2) {
        v = v * 0x5d588b656c078965ull + 0x269ec3;
        gConnectionWork->mUnk_1608.mDelayTimer = (u16) (((v >> 32) * 0xb4) >> 32) + 0x78;
    } else {
        gConnectionWork->mUnk_1608.mDelayTimer = 0xb4;
    }
}

void UpdateMPState22(void) {
    gConnectionWork->mUnk_1608.mDelayTimer = gConnectionWork->mUnk_1608.mDelayTimer - 1;
    if (gConnectionWork->mUnk_1608.mDelayTimer < 0) {
        func_02058b74_inline(7);
    }
}

void EnterMPState5(void) {
    if (func_02058b38_inline() == 1) {
        gConnectionWork->mParticipantMask = gConnectionWork->mUnk_0044.mChildMask | 1;
    }
    gConnectionWork->mUnk_1608.mChildDataWaitFrames = 0;
}

#pragma thumb off
