#include "Main/Unknown/code_0205905c.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_0205928c.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma opt_rebuildconditionals off

static inline u32 func_0205905c_inline(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 func_0205905c_inline2(void) {
    BOOL r = FALSE;
    if (func_0205905c_inline() != 0 && gConnectionWork->mState != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0205905c_inline3(void) {
    BOOL r = FALSE;
    if (func_0205905c_inline2() && !(gConnectionWork->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0205905c_inline4(void) {
    BOOL r = FALSE;
    if (func_0205905c_inline3() && gConnectionWork->mErrorCode != 9) {
        r = TRUE;
    }
    return r;
}

#pragma thumb on

BOOL AdvanceMPStateMachine(void) {
    BOOL finished;

    finished = FALSE;
    if (!func_0205905c_inline2()) {
        return TRUE;
    }
    AdvanceStateMachine(&gConnectionWork->mUnk_1608.mStateMachine);
    if (!func_0205905c_inline4()) {
        if (func_0205905c_inline() == 1 && gConnectionWork->mUnk_0044.mChildCount == 0) {
            SetRequestErrorCode(7);
        }
    }
    if (gConnectionWork->mUnk_1608.mStateMachine.mState == 0xf) {
        finished = TRUE;
    }
    return finished;
}

s32 WLMenuToRaceAdvanceMPStateMachineWrapper(void) {
    return AdvanceMPStateMachine();
}

s32 WLMenuToMenuAdvanceMPStateMachineWrapper(void) {
    return AdvanceMPStateMachine();
}

u32 AdvanceMenuDLArchives(void) {
    if (func_0205905c_inline4()) {
        return 3;
    }
    if (!func_0205905c_inline2()) {
        return 1;
    }
    switch (func_0205905c_inline()) {
        case 1:
            return AdvanceParentSync();
        case 2:
            return AdvanceChildArchiveSync(3, NULL, NULL);
        default:
            return 3;
    }
}

u32 AdvanceResultDLArchives(void) {
    if (func_0205905c_inline4()) {
        return 3;
    }
    if (!func_0205905c_inline2()) {
        return 1;
    }
    switch (func_0205905c_inline()) {
        case 1:
            return AdvanceParentSync();
        case 2:
            return AdvanceChildArchiveSync(2, NULL, NULL);
        default:
            return 3;
    }
}

#pragma thumb off
