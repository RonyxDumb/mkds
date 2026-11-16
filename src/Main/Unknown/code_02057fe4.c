#include "Main/Unknown/code_02057fe4.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_020562b4.h"
#include "Main/Save/GhostTimes.h"
#include "Main/Unknown/code_02058000.h"
#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/code_02058efc.h"
#include "Main/Unknown/code_02059000.h"

#include "Main/Unknown/code_02050000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02051000.h"
#include "Main/Unknown/code_02052000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_0200eddc.h"
#include "code_02142eac.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02059920.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204bca0.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02050034.h"
#include "Main/Unknown/code_0205928c.h"

#pragma thumb on

void func_02058b10(void) {
    MPStateMachine *stateMachine;
    CombineParticipantBits();
    stateMachine = &gStruct217AA00->mUnk_1608;
    stateMachine->mNextState = 0xf;
    stateMachine->mNextStateRequested = 1;
}

#pragma thumb off

#pragma thumb on

static inline u32 func_02058a40_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->mUnk_0000;
}

void UpdateMPState5(void) {
    u8 participantMask;
    u16 waitFrames;

    if (func_02058a40_inline() == 1) {
        participantMask = gStruct217AA00->mParticipantMask;
        if (IsAllMPChildSharedDataCopied() != 0) {
            if (QueueMPDataHalfwordAndWord(1, participantMask, participantMask) != FALSE) {
                SetParticipantMask(participantMask);
            }
        } else {
            waitFrames = gStruct217AA00->mUnk_1608.mUnk_14;
            if (waitFrames > 0xe10) {
                func_02050e60(7);
                return;
            }
            gStruct217AA00->mUnk_1608.mUnk_14 = waitFrames + 1;
        }
    }
}

void UpdateMPState6(void) {
    MPStateMachine *stateMachine;

    if (func_02058a40_inline() == 1 && (gStruct217AA00->mUnk_0454 & 1)) {
        if (QueueMPDataHalfwordAndWord(2, gStruct217AA00->mUnk_0044.mChildMask, gStruct217AA00->mUnk_0457) != FALSE) {
            stateMachine = &gStruct217AA00->mUnk_1608;
            stateMachine->mNextState = 1;
            stateMachine->mNextStateRequested = 1;
        }
    }
}

void EnterMPState3(void) {
    gStruct217AA00->mUnk_1e34 = 0;
    gStruct217AA00->mUnk_1e44 &= ~2;
}

#pragma thumb off

#pragma thumb on

void UpdateMPState3(void) {
    int result;
    MPStateMachine *stateMachine;
    result = func_0205955c();
    if (result == 1) {
        stateMachine = &gStruct217AA00->mUnk_1608;
        stateMachine->mNextState = 4;
        stateMachine->mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

static inline void func_02058910_inline(u16 nextState) {
    MPStateMachine *stateMachine = &gStruct217AA00->mUnk_1608;
    stateMachine->mNextState = nextState;
    stateMachine->mNextStateRequested = 1;
}

void UpdateMPState1(void) {
    BOOL r;
    BOOL a;
    BOOL b;
    s32 v;
    ConnectionWork *p;

    r = TRUE;
    b = FALSE;
    p = gStruct217AA00;
    if (p->mUnk_0454 & 0x40) {
        a = TRUE;
        if (p == NULL) {
            v = 0;
        } else {
            v = p->mUnk_0000;
        }
        if (v != 1 && ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
            a = FALSE;
        }
        if (a != FALSE) {
            b = TRUE;
        }
    }
    if (b != FALSE) {
        if (WFS_GetStatus() == 2) {
            func_0204f8a0(gStruct217AA00->mUnk_0457);
        } else {
            r = FALSE;
        }
    }
    if (r != FALSE) {
        func_02058910_inline(2);
    }
}

void EnterMPState2(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        overlay_beginLoad(2);
    }
}

void UpdateMPState2(void) {
    if (overlay_tryFinishLoad() != 0) {
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            overlay_createFrmHeap();
            func_020474e4();
        }
        func_02058910_inline(3);
    }
}

void EnterMPState4(void) {
    gStruct217AA00->mUnk_1e34 = 0;
    gStruct217AA00->mUnk_1e44 &= ~2;
    gStruct217AA00->mUnk_164f = 0;
}

#pragma thumb off

#pragma thumb on

void UpdateMPState4(void) {
    int result;
    MPStateMachine *stateMachine;
    result = func_02058dc0(func_02058efc);
    if (result == 1) {
        stateMachine = &gStruct217AA00->mUnk_1608;
        stateMachine->mNextState = 0xc;
        stateMachine->mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

static inline u32 func_02058820_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->mUnk_0000;
}

static inline void func_020587d8_inline(u16 nextState) {
    MPStateMachine *stateMachine = &gStruct217AA00->mUnk_1608;
    stateMachine->mNextState = nextState;
    stateMachine->mNextStateRequested = 1;
}

// Clears the per-slot flags of received chunks: 0x12 per slot for the parent, 2 for a child.
void EnterMPState7(void) {
    s32 slot;
    u32 flagIndex;
    u32 flagCount;

    WM_SetIndCallback(14, (UnkFunc *) func_02059920, NULL);
    if (func_02058820_inline() == 1) {
        SetMPFrequency(0);
    }
    for (slot = 0; slot < 8; slot++) {
        if (func_02058820_inline() == 1) {
            flagCount = 0x12;
        } else {
            flagCount = 2;
        }
        for (flagIndex = 0; flagIndex < flagCount; flagIndex++) {
            gStruct217AA00->mChunkReceivedFlags[slot][flagIndex] = 0;
        }
    }
    gStruct217AA00->mUnk_162a = 0;
}

void UpdateMPState7(void) {
    if (gStruct217AA00->mRequestPending == 0) {
        switch (gStruct217AA00->mUnk_000c) {
            case 0xc:
                gStruct217AA00->mUnk_000c = 0xb;
                break;
            case 0xb:
                func_020587d8_inline(8);
                break;
            default:
                func_02050e60(2);
                break;
        }
    }
}

void EnterMPState8(void) {
    u16 ownIndex;

    ownIndex = gStruct217AA00->mUnk_0000 == 2 ? gStruct217AA00->mOwnIndex : 0;
    FillPlayerRecord(&gStruct217AA00->mUnk_045c[ownIndex]);
    gStruct217AA00->mUnk_1608.mUnk_1a |= 1;
    gStruct217AA00->mEntryChunkIndex = 0;
    gStruct217AA00->mUnk_1608.mUnk_16 = 0;
}

#pragma thumb off

#pragma thumb on
u32 func_02058754(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value0 = (u32) &gStruct217AA00;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 0x1622u;
    value1 = (value1) + (value0);
    value2 = *(const u8 *) ((value1) + 0u);
    value0 = 1u;
    value2 = (value2) | (value0);
    *(u8 *) ((value1) + 0u) = value2;
    return value0;
}
#pragma thumb off

#pragma thumb on

static inline u32 func_0205821c_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->mUnk_0000;
}

static inline void func_0205821c_inline2(u16 nextState) {
    MPStateMachine *stateMachine = &gStruct217AA00->mUnk_1608;
    stateMachine->mNextState = nextState;
    stateMachine->mNextStateRequested = 1;
}

BOOL QueueMPChunk(u8 chunkNumber, u8 *data, u16 size, u8 playerIndex, u8 destBitmap) {
    u8 *packet;

    if ((gStruct217AA00->mUnk_1608.mUnk_1a & 1) == 0) {
        return FALSE;
    }
    packet = gStruct217AA00->mChunkBuffer;
    packet[1] = chunkNumber;
    *(u16 *) (packet + 2) = size;
    packet[0] = playerIndex;
    if (data != NULL) {
        MI_CpuCopy8(data, packet + 4, size);
    } else {
        size = 0;
    }
    DC_StoreRange(packet, size + 4);
    gStruct217AA00->mUnk_1608.mUnk_1a &= ~1;
    if (QueueMPDataToPort(gStruct217AA00->mChunkBuffer, size + 4, destBitmap, NULL, &data_021652a0) == 0) {
        gStruct217AA00->mUnk_1608.mUnk_1a |= 1;
        return FALSE;
    }
    return TRUE;
}

BOOL GetEntryChunk(u8 *entry, s32 chunkIndex, s32 chunkSize, u8 **outChunk, u16 *outSize) {
    s32 n;

    chunkIndex = chunkIndex * chunkSize;
    n = 0x22c - chunkIndex;
    if (n <= 0) {
        return FALSE;
    }
    if (n > chunkSize) {
        n = chunkSize;
    }
    *outSize = n;
    *outChunk = entry + chunkIndex;
    return TRUE;
}

// Child: queues its own entry chunk by chunk, again and again. Parent: waits for the children's entries.
void UpdateMPState8(void) {
    ConnectionWork *work;
    u32 expectedMask;
    u8 receivedMask;
    u8 chunkIndex;
    u8 *chunkData;
    u16 chunkSize;
    u16 v;

    if (func_0205821c_inline() == 1) {
        work = gStruct217AA00;
        expectedMask = work->mUnk_0044.mUnk_42;
        receivedMask = work->mUnk_162a;
        if (expectedMask == (expectedMask & receivedMask)) {
            if (QueueMPChunk(0xfe, NULL, (u8) (receivedMask | 1), 0, receivedMask) != FALSE) {
                func_0205821c_inline2(9);
            }
        } else {
            if ((gStruct217AA00->mUnk_0454 & 0x40) != 0) {
                v = 0x708;
            } else {
                v = 0x258;
            }
            gStruct217AA00->mUnk_1608.mUnk_16++;
            if (gStruct217AA00->mUnk_1608.mUnk_16 > v) {
                gStruct217AA00->mUnk_0044.mUnk_42 = gStruct217AA00->mUnk_0044.mChildMask;
            }
        }
    } else {
        if ((gStruct217AA00->mUnk_1608.mUnk_1a & 1) != 0) {
            chunkIndex = gStruct217AA00->mEntryChunkIndex;
            v = gStruct217AA00->mUnk_0000 == 2 ? gStruct217AA00->mOwnIndex : 0;
            if (GetEntryChunk((u8 *) &gStruct217AA00->mUnk_045c[v], chunkIndex, 0x20, &chunkData, &chunkSize) != FALSE) {
                v = gStruct217AA00->mUnk_0000 == 2 ? gStruct217AA00->mOwnIndex : 0;
                QueueMPChunk(chunkIndex, chunkData, chunkSize, v, 1);
                gStruct217AA00->mEntryChunkIndex = chunkIndex + 1;
            } else {
                gStruct217AA00->mEntryChunkIndex = 0;
            }
        }
    }
}

void EnterMPState9(void) {
    gStruct217AA00->mUnk_0004 = 10;
    gStruct217AA00->mUnk_1608.mUnk_16 = 0;
    gStruct217AA00->mUnk_162a = 0;
    gStruct217AA00->mEntryChunkIndex = 0;
    gStruct217AA00->mEntryChunkSlot = 0;
}

// Parent: queues the entries of all slots to the children, chunk by chunk, until the wait ends.
void UpdateMPState9(void) {
    u32 slotDone;
    u8 chunkIndex;
    u8 slot;
    u8 *chunkData;
    u16 chunkSize;
    u16 waitLimit;

    if (func_0205821c_inline() == 1) {
        if ((gStruct217AA00->mUnk_1608.mUnk_1a & 1) != 0) {
            slotDone = 1;
            slot = gStruct217AA00->mEntryChunkSlot;
            if (((u8) (gStruct217AA00->mUnk_0044.mChildMask | 1) & (1 << slot)) != 0) {
                chunkIndex = gStruct217AA00->mEntryChunkIndex;
                if (GetEntryChunk((u8 *) &gStruct217AA00->mUnk_045c[slot], chunkIndex, 0x168, &chunkData, &chunkSize) !=
                    FALSE) {
                    QueueMPChunk(chunkIndex, chunkData, chunkSize, slot, gStruct217AA00->mUnk_0044.mChildMask);
                    gStruct217AA00->mEntryChunkIndex = chunkIndex + 1;
                    slotDone = 0;
                }
            }
            if (slotDone != 0) {
                gStruct217AA00->mEntryChunkSlot++;
                gStruct217AA00->mEntryChunkIndex = 0;
                if (gStruct217AA00->mEntryChunkSlot >= 8) {
                    gStruct217AA00->mEntryChunkSlot = 0;
                }
            }
        }
        if ((gStruct217AA00->mUnk_0454 & 0x40) != 0) {
            waitLimit = 0x708;
        } else {
            waitLimit = 0x258;
        }
        gStruct217AA00->mUnk_1608.mUnk_16++;
        if (gStruct217AA00->mUnk_1608.mUnk_16 > waitLimit) {
            gStruct217AA00->mUnk_162a = gStruct217AA00->mUnk_0044.mChildMask;
            func_0205821c_inline2(10);
        }
    }
}

void EnterMPState10(void) {
    u8 slot;

    WM_SetIndCallback(14, NULL, NULL);
    gStruct217AA00->mUnk_043c = gStruct217AA00->mUnk_045c[0].mUnk_228_4;
    if (*(u16 *) 0x027ffc40 == 2) {
        gSystemData->mLanguageIndex = gStruct217AA00->mUnk_043c;
    }
    for (slot = 1; slot < 8; slot++) {
        if ((gStruct217AA00->mUnk_162a & (1 << slot)) == 0) {
            MI_CpuFill8(&gStruct217AA00->mUnk_045c[slot], 0, 0x22c);
        }
    }
}

void UpdateMPState10(void) {
    if (gStruct217AA00->mRequestPending == 0) {
        switch (gStruct217AA00->mUnk_000c) {
            case 0xb:
                func_02052da4();
                break;
            case 0x25:
                func_0205821c_inline2(6);
                break;
        }
    }
}

void EnterMPState11(void) {
    gStruct217AA00->mUnk_164e = 0;
    gStruct217AA00->mUnk_164c = 0;
}

void UpdateMPState11(void) {
    u8 a;
    u8 b;
    u32 c;

    switch (func_0205821c_inline()) {
        case 1:
            a = gStruct217AA00->mUnk_164e;
            b = gStruct217AA00->mUnk_162a;
            c = b & (1 << a);
            if (c != 0) {
                if (func_020504a4(a, b) != FALSE) {
                    gStruct217AA00->mUnk_164e++;
                }
            } else {
                gStruct217AA00->mUnk_164e++;
            }
            if (gStruct217AA00->mUnk_164e >= 8) {
                func_0205821c_inline2(6);
            }
            break;
        case 2:
            a = gStruct217AA00->mUnk_162a;
            b = gStruct217AA00->mUnk_164c;
            if (a == (a & b)) {
                func_0205821c_inline2(6);
            }
            break;
    }
}

#pragma thumb off

#pragma thumb on

void EnterMPState12(void) {
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

#pragma thumb off

#pragma thumb on

static inline u32 func_020580a4_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->mUnk_0000;
}

static inline void func_020580a4_inline2(u16 v) {
    MPStateMachine *p = &gStruct217AA00->mUnk_1608;
    p->mNextState = v;
    p->mNextStateRequested = 1;
}

void UpdateMPState12(void) {
    if (gStruct217AA00->mRequestPending != 0) {
        return;
    }
    switch (gStruct217AA00->mUnk_000c) {
        case 0xc:
        case 0x25:
        case 0x27:
            StartDataSharing();
            break;
        case 0xe:
            gStruct217AA00->mUnk_0004 = 7;
            func_020580a4_inline2(5);
            break;
    }
}

void EnterMPState13(void) {
    s32 ownIndex;

    gStruct217AA00->mUnk_164d = 0;
    ownIndex = 0;
    if (gStruct217AA00->mUnk_0000 == 2) {
        ownIndex = gStruct217AA00->mOwnIndex;
    }
    MI_CpuCopy8(gSaveData->mFirstBlock->mFlags, gStruct217AA00->mUnk_045c[(u16) ownIndex].mBits, 4);
    gStruct217AA00->mUnk_162a |= 1;
}

void UpdateMPState13(void) {
    s32 ownIndex;

    if (func_020580a4_inline() == 1) {
        if (gStruct217AA00->mUnk_0044.mChildMask == (gStruct217AA00->mUnk_0044.mChildMask & gStruct217AA00->mUnk_164d)) {
            func_020580a4_inline2(0xe);
        }
    } else if (gStruct217AA00->mUnk_164d != 0) {
        func_020580a4_inline2(0xe);
    } else {
        if (gStruct217AA00->mUnk_0000 == 2) {
            ownIndex = gStruct217AA00->mOwnIndex;
        } else {
            ownIndex = 0;
        }
        func_020503cc((u8) (u16) ownIndex, 1);
    }
}
#pragma thumb off

#pragma thumb on
u32 EnterMPState14(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &gStruct217AA00;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 0x164eu;
    *(u8 *) ((value1) + (value0)) = value2;
    return value0;
}
#pragma thumb off

#pragma thumb on

static inline u32 func_02057fe8_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->mUnk_0000;
}

static inline void func_02057fe8_inline2(u16 nextState) {
    MPStateMachine *stateMachine = &gStruct217AA00->mUnk_1608;
    stateMachine->mNextState = nextState;
    stateMachine->mNextStateRequested = 1;
}

void UpdateMPState14(void) {
    if (func_02057fe8_inline() == 1) {
        if ((gStruct217AA00->mUnk_162a & (1 << gStruct217AA00->mUnk_164e)) != 0) {
            if (func_020503cc(gStruct217AA00->mUnk_164e, gStruct217AA00->mUnk_0044.mChildMask) != FALSE) {
                gStruct217AA00->mUnk_164e += 1;
            }
        } else {
            gStruct217AA00->mUnk_164e += 1;
        }
        if (gStruct217AA00->mUnk_164e > 8) {
            func_02057fe8_inline2(0xb);
        }
    } else if (gStruct217AA00->mUnk_162a == (gStruct217AA00->mUnk_162a & gStruct217AA00->mUnk_164d)) {
        func_02057fe8_inline2(0xb);
    }
}
#pragma thumb off

#pragma thumb on

u32 func_02057fe4(u32 value) {
    return value;
}

#pragma thumb off
