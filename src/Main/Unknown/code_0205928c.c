#include "Main/Unknown/code_0205928c.h"
#include "Main/System/Heap.h"
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
    v3 = heap_allocEx(heap, (0x0000016cu), 0x20);
    v4 = (s32 *) &gStruct217AA00;
    gStruct217AA00->mChunkBuffer = v3;
    slot = 0;
    v2 = 0;
    do {
        v3 = heap_alloc(heap, 0x12);
        gStruct217AA00->mChunkReceivedFlags[slot] = v3;
        v2 = v2 + 4;
        slot = slot + 1;
    } while (slot < 8);
}

#pragma thumb off

#pragma thumb on

static inline u32 func_0205955c_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->mUnk_0000;
}

static inline s32 func_0205955c_inline2(void) {
    BOOL r = FALSE;
    if (func_0205955c_inline() != 0 && gStruct217AA00->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0205955c_inline3(void) {
    BOOL r = FALSE;
    if (func_0205955c_inline2() && !(gStruct217AA00->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0205955c_inline4(void) {
    BOOL r = FALSE;
    if (func_0205955c_inline3() && gStruct217AA00->mUnk_0008 != 9) {
        r = TRUE;
    }
    return r;
}

void func_020597d0(const void *data, s32 b, s32 playerIndex, s32 d) {
    s32 v;
    s32 playerBit;

    v = gStruct217AA00->mUnk_0004;
    if (v != 11) {
        func_020559ec(data, playerIndex, d);
        return;
    }
    playerBit = 1 << playerIndex;
    if (!(gStruct217AA00->mUnk_164c & playerBit)) {
        MI_CpuCopy8(data, &gStruct217AA00->mUnk_045c[playerIndex], 0x14);
        gStruct217AA00->mUnk_164c |= playerBit;
    }
}

s32 IsAllMPChildSharedDataCopied(void) {
    s32 allCopied;
    u16 childIndex;
    u8 childMask;

    allCopied = 1;
    childIndex = allCopied;
    childMask = gStruct217AA00->mUnk_0044.mChildMask;
    for (; childIndex < 8; childIndex++) {
        if ((childMask & (allCopied << childIndex)) &&
            gStruct217AA00->mUnk_15bc_view.mSharedDataCopied[childIndex] == 0) {
            allCopied = 0;
            break;
        }
    }
    return allCopied;
}

s32 func_02059700(void) {
    BOOL done;

    done = FALSE;
    switch (gStruct217AA00->mUnk_1e34) {
        case 0:
            gStruct217AA00->mUnk_1e34 = 6;
            break;
        case 6:
            if (gStruct217AA00->mUnk_0044.mChildMask ==
                (gStruct217AA00->mUnk_0044.mChildMask & gStruct217AA00->mUnk_1d54)) {
                gStruct217AA00->mUnk_1e34 = 7;
            }
            break;
        case 7:
            if (QueueMPDataHalfword(5, 0xff) != FALSE) {
                gStruct217AA00->mUnk_1d54 = done;
                gStruct217AA00->mUnk_1e34 = 1;
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
    switch (gStruct217AA00->mUnk_1e34) {
        case 0:
            if (gStruct217AA00->mUnk_0454 & 1) {
                gStruct217AA00->mUnk_1e34 = 2;
            }
            break;
        case 2:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
                switch (a) {
                    case 0:
                        func_020473e4();
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
                gStruct217AA00->mUnk_000c = 0x27;
                gStruct217AA00->mRequestPending = 1;
                gStruct217AA00->mNextLoadIndex = 0;
                FS_InitFile(&gStruct217AA00->mFile);
                gStruct217AA00->mUnk_1e34 = 3;
            } else {
                gStruct217AA00->mUnk_1e34 = 5;
            }
            QueueMPDataHalfword(3, 1);
            break;
        case 3:
            if (LoadPendingFiles() != FALSE) {
                gStruct217AA00->mUnk_1e34 = 5;
            }
            break;
        case 5:
            if (QueueMPDataHalfword(4, 1) != FALSE) {
                gStruct217AA00->mUnk_1e34 = 1;
            }
            break;
        case 1:
            if (gStruct217AA00->mUnk_1e44 & 2) {
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
    gStruct217AA00->mUnk_1e34 = 0;
    gStruct217AA00->mUnk_1e44 &= ~2;
    stateMachine = &gStruct217AA00->mUnk_1608;
    stateMachine->mNextState = 0x10;
    stateMachine->mNextStateRequested = 1;
    gStruct217AA00->mCourseId = courseId;
    gStruct217AA00->mMode = mode;
}

#pragma thumb off

#pragma thumb on

static inline u32 func_020593dc_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->mUnk_0000;
}

static inline s32 func_020593dc_inline2(void) {
    BOOL r = FALSE;
    if (func_020593dc_inline() != 0 && gStruct217AA00->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020593dc_inline3(void) {
    BOOL r = FALSE;
    if (func_020593dc_inline2() && !(gStruct217AA00->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020593dc_inline4(void) {
    BOOL r = FALSE;
    if (func_020593dc_inline3() && gStruct217AA00->mUnk_0008 != 9) {
        r = TRUE;
    }
    return r;
}

void RequestMPState18(void) {
    MPStateMachine *stateMachine;

    gStruct217AA00->mUnk_1e34 = 0;
    gStruct217AA00->mUnk_1e44 &= ~2;
    stateMachine = &gStruct217AA00->mUnk_1608;
    stateMachine->mNextState = 0x12;
    stateMachine->mNextStateRequested = 1;
}

void RequestMPState21(void) {
    MPStateMachine *stateMachine;

    gStruct217AA00->mUnk_1e34 = 0;
    gStruct217AA00->mUnk_1e44 &= ~2;
    stateMachine = &gStruct217AA00->mUnk_1608;
    stateMachine->mNextState = 0x15;
    stateMachine->mNextStateRequested = 1;
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
            return func_020595e8(1, gStruct217AA00->mCourseId, gStruct217AA00->mMode);
        default:
            return 3;
    }
}

#pragma thumb off

#pragma thumb on

void EnterMPState16(void) {
    int v1;
    if (gStruct217AA00 == NULL) {
        v1 = 0;
    } else {
        v1 = gStruct217AA00->mUnk_0000;
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
        stateMachine = &gStruct217AA00->mUnk_1608;
        stateMachine->mNextState = 0x11;
        stateMachine->mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

void func_0205933c(void) {
    u32 loaded;

    loaded = LoadCourseSoundSet((u32) gStruct217AA00->mMode, (u32) gStruct217AA00->mCourseId);
    if (*(u16 *) 0x027ffc40 == 2) {
        rconf_loadCharacterSounds(0);
    }
    if (loaded == 0) {
        gStruct217AA00->mUnk_164f = 1;
    }
}

void func_02059304(void) {
    gStruct217AA00->mUnk_1e34 = 0;
    gStruct217AA00->mUnk_1e44 &= ~2;
    gStruct217AA00->mUnk_164f = 0;
}

#pragma thumb off

#pragma thumb on

void UpdateMPState17(void) {
    int result;
    MPStateMachine *stateMachine;
    result = func_02058dc0(func_0205933c);
    if (result == 1) {
        stateMachine = &gStruct217AA00->mUnk_1608;
        stateMachine->mNextState = 0x14;
        stateMachine->mNextStateRequested = 1;
    }
}

void EnterMPState20(void) {
    int v1;
    if (gStruct217AA00 == NULL) {
        v1 = 0;
    } else {
        v1 = gStruct217AA00->mUnk_0000;
    }
    if (v1 == 1) {
        SetMPFrequency(1);
    }
}

void UpdateMPState20(void) {
    MPStateMachine *stateMachine;
    if (gStruct217AA00->mRequestPending == 0) {
        stateMachine = &gStruct217AA00->mUnk_1608;
        stateMachine->mNextState = 0xf;
        stateMachine->mNextStateRequested = 1;
    }
}

#pragma thumb off
