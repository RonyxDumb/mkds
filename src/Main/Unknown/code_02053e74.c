#include "Main/Unknown/code_02053e74.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0204f240.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_02052000.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_02054f38.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_020562b4.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_020176c0.h"
#include "code_0214d018.h"

#pragma opt_rebuildconditionals off

static inline u32 func_02053e74_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->field0;
}

static inline s32 func_02053e74_inline2(void) {
    BOOL r = FALSE;
    if (func_02053e74_inline() != 0 && gStruct217AA00->field4 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02053e74_inline3(void) {
    BOOL r = FALSE;
    if (func_02053e74_inline2() && !(gStruct217AA00->field454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02053e74_inline4(void) {
    BOOL r = FALSE;
    if (func_02053e74_inline3() && gStruct217AA00->field8 != 9) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02054754_inline(Unk0217aa00_15c8 *e) {
    BOOL r = FALSE;
    u8 f = e->field6_0;
    if (gStruct217AA00->field15EC == 0) {
        if (f & 1) {
            r = TRUE;
        }
    } else {
        if (f & 2) {
            r = TRUE;
        }
    }
    return r;
}

static inline s32 func_02054754_inline2(DataSharing *dataSharing, Unk0217aa00_15c8 *e) {
    u8 mask = gStruct217AA00->field44.mChildMask;
    u8 i;
    BOOL ok = FALSE;
    u16 m;

    for (i = 1; i < 8; i++) {
        if (mask & (1 << i)) {
            if (dataSharing->mSharedDataCopied[i] == 0) {
                ok = FALSE;
                i = 8;
            } else {
                m = gStruct217AA00->field15EC == 0 ? 1 : 2;
                if ((m & e[i].field6_0) == 0) {
                    ok = FALSE;
                    i = 8;
                } else {
                    ok = TRUE;
                }
            }
        }
    }
    return ok;
}

static inline u32 func_0205465c_inline(ConnectionWork *p) {
    if (p == NULL) {
        return 0;
    }
    return p->field0;
}

// Returns 1 once the last step is issued, 2 on failure, 3 when an error has been recorded, 0 otherwise.
s32 AdvanceConnectionSetup(s32 isParent, void *b) {
    BOOL finished;

    finished = FALSE;
    if (gStruct217AA00->field1E3C != 0) {
        u16 ownIndex;

        ownIndex = gStruct217AA00->field0 == 2 ? gStruct217AA00->mOwnIndex : 0;
        if (ownIndex == 0xffff) {
            return 2;
        }
    }
    if (func_02053e74_inline4()) {
        return 3;
    }
    if (gStruct217AA00->mRequestPending != 0) {
        return 0;
    }
    switch (gStruct217AA00->fieldC) {
        case 0:
        case 21:
            gStruct217AA00->field454 &= ~0x40;
            gStruct217AA00->field4 = 1;
            Initialize();
            break;
        case 1:
            gStruct217AA00->field4 = 11;
            if (isParent != 0) {
                SetLifeTime(0x28);
            } else {
                StartScan(0, NULL, NULL);
            }
            break;
        case 2:
            if (isParent != 0) {
                SetLifeTime(0x28);
            } else {
                StartScan(0, NULL, NULL);
            }
            break;
        case 3:
            MeasureChannel(0);
            break;
        case 4:
            sub_204F814();
            FillGhostParentParameter(b);
            SetParentParameter();
            break;
        case 5:
            StartParent(NULL);
            break;
        case 6:
            func_0204ef1c();
            break;
        case 7:
            if (gStruct217AA00->field1E45 == -1) {
                StartScan(0, NULL, NULL);
            } else {
                EndScan();
            }
            break;
        case 9:
            StartConnect(NULL, NULL, NULL, NULL, ResetOwnIndex);
            break;
        case 10:
            gStruct217AA00->field1E3C = 1;
            func_0204ef1c();
            break;
        case 11:
            if (isParent != 0) {
                StartParentSideBlockTransfer();
            } else {
                StartChildSideBlockTransfer();
                SetOwnIndexFromConnection();
            }
            finished = TRUE;
            break;
        default:
            sub_20533A0();
            break;
    }
    return finished;
}

// Child side; returns 1 when done, 2 on failure, 3 when an error has been recorded, 0 otherwise (the parent returns 1
// at once).
s32 AdvanceBlockCountRequest(void) {
    BOOL finished;

    finished = FALSE;
    if (func_02053e74_inline4()) {
        return 3;
    }
    if (gStruct217AA00->field1E3C != 0) {
        u16 ownIndex;

        ownIndex = gStruct217AA00->field0 == 2 ? gStruct217AA00->mOwnIndex : 0;
        if (ownIndex == 0xffff) {
            return 2;
        }
    }
    if (gStruct217AA00->mRequestPending != 0) {
        return 0;
    }
    if (func_02053e74_inline() == 1) {
        return 1;
    }
    switch (gStruct217AA00->fieldC) {
        case 0x28:
        case 0x29:
            StartBlockCountRequest();
            break;
        case 0x2a:
            switch (func_02053e74_inline()) {
                case 1:
                    gStruct217AA00->fieldC = 0x28;
                    break;
                case 2:
                    gStruct217AA00->fieldC = 0x29;
                    break;
            }
            finished = TRUE;
            break;
    }
    return finished;
}

void func_02054aa0(void) {
    s32 c0;
    s32 c1;

    if (gStruct217AA00->field4 != 11) {
        return;
    }
    if (gStruct217AA00->fieldC == 0x2c) {
        TryGetBlockReceiveProgress(gStruct217AA00->mBlockInfos[0]->mBlockId, 0, &c0, &c1);
    }
    if (gStruct217AA00->mSendTimer != 0) {
        gStruct217AA00->mSendTimer = gStruct217AA00->mSendTimer - 1;
        return;
    }
    if (func_02053e74_inline() == 0) {
        return;
    }
    func_0204ed84();
}

// Child side; returns 1 when done, 2 on failure, 3 when an error has been recorded, 0 otherwise (the parent returns 1
// at once).
s32 AdvanceBlockReceive(void) {
    BOOL finished;

    finished = FALSE;
    if (func_02053e74_inline4()) {
        return 3;
    }
    if (gStruct217AA00->field1E3C != 0) {
        u16 ownIndex;

        ownIndex = gStruct217AA00->field0 == 2 ? gStruct217AA00->mOwnIndex : 0;
        if (ownIndex == 0xffff) {
            return 2;
        }
    }
    if (gStruct217AA00->mRequestPending != 0) {
        return 0;
    }
    if (func_02053e74_inline() == 1) {
        return 1;
    }
    switch (gStruct217AA00->fieldC) {
        case 0x28:
        case 0x29:
        case 0x2a:
            gStruct217AA00->mBlockIndex = 0;
            StartBlockNodeRequest();
            break;
        case 0x2b:
            StartBlockDataRequest();
            break;
        case 0x2c:
            func_0204ead0(1, 0);
            break;
        case 0x2e:
            gStruct217AA00->field1E3C = 0;
            finished = TRUE;
            break;
    }
    return finished;
}

// Polled until it returns TRUE.
BOOL FinishDataSharingSync(void) {
    BOOL finished;
    DataSharing *dataSharing;

    finished = FALSE;
    dataSharing = &gStruct217AA00->mUnk_15bc_view;
    if (!func_02053e74_inline2()) {
        return TRUE;
    }
    if (!(gStruct217AA00->field454 & 4)) {
        return TRUE;
    }
    if (sub_204FFBC() != 0) {
        return TRUE;
    }
    if (dataSharing->mSharedDataCopied[0] != 0) {
        ConnectionWork *connection;

        connection = gStruct217AA00;
        if (func_02054754_inline(dataSharing->fieldC) != 0) {
            if ((connection->field454 & 8) != 0) {
                connection->field4 = 9;
            } else {
                connection->field4 = 8;
            }
            finished = TRUE;
            gStruct217AA00->field15F4 = 0;
        } else if (func_02053e74_inline() == 1) {
            if (func_02054754_inline2(dataSharing, dataSharing->fieldC) != 0) {
                connection->field8B |= 1;
            }
        }
    }
    return finished;
}

// Starts the wait that FinishDataSharingSync completes; always returns 1.
s32 StartDataSharingSync(void) {
    if (func_02053e74_inline2()) {
        gStruct217AA00->field4 = 7;
        gStruct217AA00->field8B &= ~1;
        if (gStruct217AA00->field15EC == 0) {
            gStruct217AA00->field15EC = 1;
        } else {
            gStruct217AA00->field15EC = 0;
        }
    }
    return 1;
}

s32 func_0205465c(void) {
    ConnectionWork *connection;
    s32 r;
    s32 count;

    r = 0;
    connection = gStruct217AA00;
    if (func_0205465c_inline(connection) != 1) {
        r = 2;
    } else {
        if (func_0205465c_inline(connection) == 1) {
            if ((connection->field454 & 0x40) != 0) {
                count = connection->field1699;
            } else {
                count = connection->field44.mChildCount;
            }
        } else {
            count = 0;
        }
        if (count == 0) {
            if (connection->field1E38 != 0) {
                r = 1;
            } else {
                r = 2;
            }
        }
    }
    return r;
}

void InitConnection(void *heap) {
    gStruct217AA00 = heap_allocEx(heap, 0x1f00, 0x20);
    gStruct217AA00->field0 = 0;
    gStruct217AA00->field4 = 0;
    gStruct217AA00->field8 = 9;
    gStruct217AA00->fieldC = 0;
    gStruct217AA00->mRequestPending = 0;
    gStruct217AA00->field454 = 0;
    gStruct217AA00->field456_0 = 0;
}

void InitConnectionBuffers(void *heap) {
    gStruct217AA00->field14 = heap_allocEx(heap, 0xf00, 0x20);
    gStruct217AA00->mParentParameter = heap_allocEx(heap, 0x40, 0x20);
    gStruct217AA00->field1C = heap_allocEx(heap, 0x20, 0x20);
    gStruct217AA00->field24 = heap_allocEx(heap, 0xc0, 0x20);
    gStruct217AA00->field28 = heap_allocEx(heap, 0xc0, 0x20);
    gStruct217AA00->field20 = heap_allocEx(heap, 0x44, 0x20);
    gStruct217AA00->field2C = heap_allocEx(heap, 0x400, 0x20);
    gStruct217AA00->field30 = 0x1c0;
    gStruct217AA00->field34 = heap_allocEx(heap, gStruct217AA00->field30, 0x20);
    gStruct217AA00->field38 = 0x400;
    gStruct217AA00->field3C = heap_allocEx(heap, gStruct217AA00->field38, 0x20);
    gStruct217AA00->field15BC = heap_allocEx(heap, 0x820, 0x20);
    gStruct217AA00->field15C0 = heap_allocEx(heap, 0x200, 0x20);
    gStruct217AA00->field15C4 = heap_allocEx(heap, 8, 0x20);
    gStruct217AA00->field15C8 = heap_allocEx(heap, 0x40, 0x20);
    gStruct217AA00->field40 = heap_allocEx(heap, 0x18, 0x20);
    gStruct217AA00->field1664 = 0;
    gStruct217AA00->field165C = 0;
    gStruct217AA00->field1658 = 0;
    gStruct217AA00->field44.field38 = heap_allocEx(heap, 0x1c, 0x20);
    gStruct217AA00->mHeap = NNS_FndCreateExpHeapEx(heap_alloc(heap, 0x7800), 0x7800, 1);
    gStruct217AA00->mMPReceiveBuffer = 0;
    gStruct217AA00->mMPReceiveBufferSize = 0;
    gStruct217AA00->mMPSendBuffer = 0;
    gStruct217AA00->mMPSendBufferSize = 0;
    gStruct217AA00->field456_0 = 1;
    sub_2053D00();
}

void sub_2054330(void) {
    while (sub_2054F58() != 1) {
    }
    gStruct217AA00->field456_0 = 0;
}

void ResetDataSharing(DataSharing *dataSharing) {
    Unk0217aa00_1e4c *q;
    s32 i;
    s32 j;

    dataSharing->mParticipantMask = 0;
    MI_CpuFill8(gStruct217AA00->field15C4, 0, 8);
    for (i = 0; i < 8; i++) {
        dataSharing->mSharedDataCopied[i] = 0;
        MI_CpuFill8(&dataSharing->fieldC[i], 0, 8);
    }
    dataSharing->field3C[0] = 0;
    for (i = 0; i < 7; i++) {
        dataSharing->field3C[i] = 0;
    }
    dataSharing->field4A = 0;
    dataSharing->field34 = 5;
    dataSharing->field38 = 0;
    dataSharing->field30 = 0;
    gStruct217AA00->field454 &= ~0x10;
    gStruct217AA00->field8B &= ~1;
    q = &gStruct217AA00->mUnk_1e4c_view;
    q->field60 = 0;
    q->field68 = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            q->field0[i].field0[j] = 0;
        }
    }
    gStruct217AA00->field454 &= ~0x10;
}

void ResetConnectionData(void) {
    u8 *q;
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    for (i = 0; i < 7; i++) {
        gStruct217AA00->field44.mEntries[i].mAid = 0xffff;
        q = gStruct217AA00->field44.mEntries[i].field0;
        for (j = 0; j < 6; j++) {
            q[j] = 0;
        }
    }
    gStruct217AA00->field44.field42 = 0;
    gStruct217AA00->field44.mChildMask = 0;
    gStruct217AA00->field44.mChildCount = 0;
    gStruct217AA00->field44.field3C = 0;
    gStruct217AA00->field44.mDisconnectingIndex = -1;
    gStruct217AA00->field88 = -1;
    gStruct217AA00->field8A = 0;
    gStruct217AA00->field8B = 0;
    gStruct217AA00->field44.field3E = 0;
    MI_CpuCopy8(gSaveData->mFirstBlock->mPlayerName, gStruct217AA00->field44.field38, 0x14);
    gStruct217AA00->field44.field38->fieldE.field6_4 = gSystemData->mLanguageIndex;
    gStruct217AA00->field44.field38->fieldE.field6_0 = 0;
    for (j = 0; j < 4; j++) {
        gStruct217AA00->fieldAC[j].fieldDC_0 = 0;
        gStruct217AA00->fieldAC[j].fieldDB = 0;
        q = gStruct217AA00->fieldAC[j].fieldC0;
        for (k = 0; k < 6; k++) {
            q[k] = 0;
        }
    }
    gStruct217AA00->mOwnIndex = 0xffff;
    gStruct217AA00->field438 = 0;
    gStruct217AA00->field434 = 0;
    gStruct217AA00->field439 = 1;
    gStruct217AA00->field43A = 0;
    gStruct217AA00->field436 = 0;
    gStruct217AA00->field43C = 0;
    gStruct217AA00->field43D = 0;
    gStruct217AA00->field43B = 0;
    q = gStruct217AA00->mUnk_00ac_view.field380;
    for (l = 0; l < 6; l++) {
        q[l] = 0;
    }
    gStruct217AA00->field457 = 0;
    gStruct217AA00->field458 = 0;
    gStruct217AA00->field1699 = 0;
    gStruct217AA00->field454 &= ~1;
    ClearParticipantBits();
    ResetDataSharing(&gStruct217AA00->mUnk_15bc_view);
}

void sub_2053E74(void) {
    Unk0217aa00_1e4c *q;
    ConnectionWork *connection;
    RandomState *random;
    s32 i;
    s32 j;
    s32 a;
    s32 b;

    q = &gStruct217AA00->mUnk_1e4c_view;
    q->field60 = 0;
    q->field68 = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            q->field0[i].field0[j] = 0;
        }
    }
    gStruct217AA00->field454 &= ~0x10;
    gStruct217AA00->field454 |= 8;
    connection = gStruct217AA00;
    a = 0;
    switch (func_02053e74_inline()) {
        case 1:
            a = connection->mParentParameter->fieldC;
            break;
        case 2:
            a = connection->field24->field48;
            break;
    }
    b = 0;
    switch (func_02053e74_inline()) {
        case 1:
            b = connection->mParentParameter->fieldC;
            break;
        case 2:
            b = connection->field24->field48;
            break;
    }
    connection->mRandom.mStateLow = b + (a << 10);
    random = &connection->mRandom;
    random->mStateHigh = 0;
    random->mMultiplierLow = 0x6c078965;
    random->mMultiplierHigh = 0x5d588b65;
    random->mIncrementLow = 0x269ec3;
    random->mIncrementHigh = 0;
}
