#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Save/GhostTimes.h"
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
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->field0;
}

static inline void func_02058b74_inline(u16 nextState) {
    MPStateMachine *stateMachine = &gStruct217AA00->field1608;
    stateMachine->mNextState = nextState;
    stateMachine->mNextStateRequested = 1;
}

static inline s32 func_02058cac_inline2(void) {
    BOOL r = FALSE;
    if (func_02058b38_inline() != 0 && gStruct217AA00->field4 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02058cac_inline3(void) {
    BOOL r = FALSE;
    if (func_02058cac_inline2() && !(gStruct217AA00->field454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02058cac_inline4(void) {
    BOOL r = FALSE;
    if (func_02058cac_inline3() && gStruct217AA00->field8 != 9) {
        r = TRUE;
    }
    return r;
}

#pragma thumb on

s32 func_02058dc0(void (*callback)(void)) {
    BOOL done;

    done = FALSE;
    switch (gStruct217AA00->field1E34) {
        case 0:
            if (gStruct217AA00->field454 & 1) {
                switch (func_02058b38_inline()) {
                    case 1:
                        gStruct217AA00->field1E34 = 6;
                        break;
                    case 2:
                        gStruct217AA00->field1E34 = 2;
                        break;
                }
            }
            break;
        case 7:
            QueueMPDataHalfword(5, 0xff);
            gStruct217AA00->field1E44 |= 2;
            gStruct217AA00->field1D54 = done;
            gStruct217AA00->field1E34 = 1;
            break;
        case 6:
            if (gStruct217AA00->field44.mChildMask ==
                (gStruct217AA00->field44.mChildMask & gStruct217AA00->field1D54)) {
                gStruct217AA00->field1E34 = 7;
            }
            break;
        case 2:
            if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
                bgwkr_enqueueTask(callback);
                gBgWkrState->mRunRequested = 1;
            }
            gStruct217AA00->field1E34 = 3;
            QueueMPDataHalfword(3, 1);
            break;
        case 3:
            if (gBgWkrState->mRunRequested == 0) {
                if (gStruct217AA00->field164F != 0) {
                    sub_2050E60(7);
                } else {
                    gStruct217AA00->field1E34 = 5;
                }
            }
            break;
        case 5:
            if (QueueMPDataHalfword(4, 1) != FALSE) {
                gStruct217AA00->field1E34 = 1;
            }
            break;
        case 1:
            if (gStruct217AA00->field1E44 & 2) {
                done = TRUE;
            }
            break;
    }
    return done;
}

s32 func_02058cac(void) {
    BOOL finished;
    u16 ownIndex;

    finished = FALSE;
    if (!func_02058cac_inline2()) {
        return 1;
    }
    ownIndex = ((const ConnectionWork *) gStruct217AA00)->field0 == 2 ? gStruct217AA00->mOwnIndex : 0;
    if (ownIndex == 0xffff && func_02058b38_inline() == 2) {
        if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
            sub_2050E60(0);
            return 3;
        }
        return 2;
    }
    sm_execute(&gStruct217AA00->field1608);
    if (!func_02058cac_inline4()) {
        if (func_02058b38_inline() == 1 && gStruct217AA00->field44.mChildCount == 0) {
            sub_2050E60(7);
        }
    }
    if (gStruct217AA00->field1608.mState == 0xf) {
        finished = TRUE;
    }
    return finished;
}

void func_02058c74(void) {
    u16 ownIndex;

    ownIndex = gStruct217AA00->field0 == 2 ? gStruct217AA00->mOwnIndex : 0;
    FillPlayerRecord(&gStruct217AA00->field45C[ownIndex]);
}

void func_02058c10(void) {
    if (gStruct217AA00->mRequestPending != 0) {
        return;
    }
    if (func_02058b38_inline() != 1) {
        func_02058b74_inline(0x16);
        return;
    }
    switch (gStruct217AA00->fieldC) {
        case 11:
        case 15:
            SetEntry(0);
            return;
        case 13:
            func_02058b74_inline(7);
            break;
    }
}

void func_02058ba4(void) {
    u64 v;

    v = (u32) OS_GetTick() << 8;
    v = (u32) v & ~(u32) (v >> 32);
    if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
        v = v * 0x5d588b656c078965ull + 0x269ec3;
        gStruct217AA00->field1608.field18 = (u16) (((v >> 32) * 0xb4) >> 32) + 0x78;
    } else {
        gStruct217AA00->field1608.field18 = 0xb4;
    }
}

void func_02058b74(void) {
    gStruct217AA00->field1608.field18 = gStruct217AA00->field1608.field18 - 1;
    if (gStruct217AA00->field1608.field18 < 0) {
        func_02058b74_inline(7);
    }
}

void func_02058b38(void) {
    if (func_02058b38_inline() == 1) {
        gStruct217AA00->mParticipantMask = gStruct217AA00->field44.mChildMask | 1;
    }
    gStruct217AA00->field1608.field14 = 0;
}

#pragma thumb off
