#include "Main/Unknown/code_0204df90.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02009cc8.h"
#include "Main/Unknown/code_0200aeb4.h"
#include "Main/Unknown/code_0200b1b0.h"
#include "Main/Unknown/code_0200b200.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "Main/Net/ScanConnect.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0204ea14.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200f5ac.h"

#pragma thumb on

void func_0204e928(void *heap, u32 b, void *bmg) {
    u32 workSize;
    gStruct217AA00->mUnk_1664 = heap;
    workSize = MB_FakeGetWorkSize();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2 && workSize < 0xc000) {
        workSize = 0xc000;
    }
    gStruct217AA00->mUnk_1660 = workSize;
    gStruct217AA00->mUnk_165c = heap_allocEx(heap, gStruct217AA00->mUnk_1660, 0x20);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        gStruct217AA00->mUnk_168c = MB_GetSegmentLength(NULL);
        if (gStruct217AA00->mUnk_168c > 0x80000) {
            gStruct217AA00->mUnk_168c = 0x80000;
        }
        gStruct217AA00->mUnk_1658 = heap_allocEx(heap, gStruct217AA00->mUnk_168c, 0x20);
        mbp_loadBannerText(bmg);
        gStruct217AA00->mUnk_1668 = heap_allocEx(heap, 0x4c0, 0x20);
    } else {
        gStruct217AA00->mUnk_168c = 0;
        gStruct217AA00->mUnk_1658 = 0;
        gStruct217AA00->mUnk_1668 = 0;
    }
    func_0204e65c(&gStruct217AA00->mUnk_1658_view);
}

void func_0204e6e8(u32 index, u32 code, Unk0204e4d8 *c) {
    gStruct217AA00->mUnk_1658_view.mUnk_14[index] = code;
    if (gStruct217AA00->mUnk_000c == 0x1b && code != 0xc) {
        return;
    }
    switch (code) {
        case 10: {
            u32 v = 1;
            if (gStruct217AA00->mUnk_1694 & 1) {
                v = 0;
            } else if ((gStruct217AA00->mUnk_008b & 4) && c->mUnk_00_4 == 0) {
                v = 0;
            }
            if (v != 0) {
                func_02007d50(index, 1);
            } else {
                func_02007d50(index, 0);
            }
            return;
        }
        case 7:
            gStruct217AA00->mUnk_1697 |= 1 << index;
            if (gStruct217AA00->mUnk_1696 == (gStruct217AA00->mUnk_1696 & gStruct217AA00->mUnk_1697)) {
                gStruct217AA00->mRequestPending = 0;
            }
            break;
        case 9:
            gStruct217AA00->mUnk_1695 |= 1 << index;
            break;
        case 12:
            gStruct217AA00->mRequestPending = 0;
            break;
        case 1:
            gStruct217AA00->mRequestPending = 0;
            break;
        case 3:
            if (gStruct217AA00->mUnk_1695 & (1 << index)) {
                gStruct217AA00->mUnk_1698 |= 1 << index;
                if (gStruct217AA00->mUnk_1696 == (gStruct217AA00->mUnk_1696 & gStruct217AA00->mUnk_1698)) {
                    gStruct217AA00->mRequestPending = 0;
                }
            }
            if (!(gStruct217AA00->mUnk_1694 & 2)) {
                if (gStruct217AA00->mUnk_1699 != 0) {
                    if (gStruct217AA00->mUnk_1696 & (1 << index)) {
                        gStruct217AA00->mUnk_1696 &= ~(1 << index);
                        gStruct217AA00->mUnk_1699--;
                    }
                    if ((gStruct217AA00->mUnk_1694 & 1) && gStruct217AA00->mUnk_1696 == 0) {
                        func_02050e60(7);
                    }
                } else {
                    gStruct217AA00->mUnk_1696 = 0;
                    gStruct217AA00->mUnk_1698 = 0;
                    gStruct217AA00->mUnk_1695 = 0;
                    gStruct217AA00->mUnk_1699 = 0;
                }
            }
            if ((gStruct217AA00->mUnk_1694 & 2) &&
                gStruct217AA00->mUnk_1696 == (gStruct217AA00->mUnk_1696 & gStruct217AA00->mUnk_1698) &&
                gStruct217AA00->mUnk_000c == 0x19) {
                gStruct217AA00->mRequestPending = 0;
                return;
            }
            if ((gStruct217AA00->mUnk_1694 & 1) &&
                gStruct217AA00->mUnk_1696 == (gStruct217AA00->mUnk_1696 & gStruct217AA00->mUnk_1697) &&
                gStruct217AA00->mUnk_000c == 0x18) {
                gStruct217AA00->mRequestPending = 0;
                return;
            }
            break;
        case 14:
            if (!(gStruct217AA00->mUnk_1696 & (1 << index))) {
                gStruct217AA00->mUnk_1696 |= 1 << index;
                gStruct217AA00->mUnk_1699++;
            }
            break;
    }
}

void func_0204e65c(Unk0217aa00_1658 *view) {
    s32 index;
    if (gStruct217AA00->mUnk_165c != 0) {
        MI_CpuFill8(gStruct217AA00->mUnk_165c, 0, gStruct217AA00->mUnk_1660);
    }
    if (gStruct217AA00->mUnk_1668 != 0) {
        MI_CpuFill8(gStruct217AA00->mUnk_1668, 0, 0x4c0);
    }
    for (index = 0; index < 8; index++) {
        view->mUnk_14[index] = 0;
    }
    view->mUnk_3c = 0;
    view->mUnk_3d = 0;
    view->mUnk_3e = 0;
    view->mUnk_3f = 0;
    view->mUnk_40 = 0;
    view->mUnk_41 = 0;
    view->mUnk_38 = 0;
    view->mUnk_3a = 0;
    view->mUnk_42 = -1;
    view->mUnk_44 = 0;
}

void func_0204e568(void) {
    Unk0204e4d8 b;
    gStruct217AA00->mUnk_000c = 0x16;
    gStruct217AA00->mRequestPending = 1;
    func_0204e65c(&gStruct217AA00->mUnk_1658_view);
    b.mUnk_01 = 10;
    b.mUnk_00_0 = gSystemData->mUnk_40;
    b.mUnk_00_4 = 8;
    MI_CpuCopy8(gSaveData->mFirstBlock->mPlayerName, b.mUnk_02, 0x14);
    gStruct217AA00->mUnk_1690 = func_02052c5c(1);
    if (InitWirelessWork(gStruct217AA00->mUnk_165c, (Unk02009ff4 *) &b, 0x25, gStruct217AA00->mUnk_1690, 2) != 0) {
        func_02050e60(5);
    }
    SetMPLimits(0x1fe, 7);
    SetCallback(func_0204e6e8);
    if (((s32(*)(u32)) func_02009cc8)(gStruct217AA00->mUnk_0088) != 0) {
        func_02050e60(5);
    }
    if (mbp_204EA3C() == 0) {
        func_02050e60(5);
    }
    gStruct217AA00->mUnk_008b &= ~4;
    gStruct217AA00->mRequestPending = 0;
}

void SetupScanConnect(void) {
    Unk0204e4d8 b;
    gStruct217AA00->mUnk_000c = 0x1c;
    gStruct217AA00->mRequestPending = 1;
    b.mUnk_00_0 = gSystemData->mUnk_40;
    b.mUnk_01 = 10;
    b.mUnk_00_4 = 9;
    MI_CpuCopy8(gSaveData->mFirstBlock->mPlayerName, b.mUnk_02, 0x14);
    gStruct217AA00->mScanEntryIndex = -1;
    MB_FakeInit(gStruct217AA00->mUnk_165c, &b);
    MB_FakeSetCStateCallback(ScanConnectStateCallback);
    gStruct217AA00->mRequestPending = 0;
}

void StartCloseScanConnect(void) {
    gStruct217AA00->mUnk_000c = 0x1f;
    gStruct217AA00->mRequestPending = 1;
    MB_FakeEnd();
}

void func_0204e498(void) {
    gStruct217AA00->mUnk_000c = 0x1d;
    gStruct217AA00->mRequestPending = 1;
    MB_FakeStartScanParent(RepeatedScanCallback, 0x25);
}

static inline u32 func_0204e1a8_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->mUnk_0000;
}

void func_0204e474(void) {
    gStruct217AA00->mUnk_000c = 0x1e;
    gStruct217AA00->mRequestPending = 1;
    MB_FakeStartScanParent(RepeatedScanCallback, 0x25);
}

// Returns the scan entry index with bytes 4..9 matching the first six of element a of mUnk_00ac[0].mUnk_c0, or -1.
s32 FindScanEntryIndex(u32 entryIndex) {
    s32 result;
    u16 index;
    ScanBlockView scanBlock;
    result = -1;
    if (gStruct217AA00->mUnk_000c == 0x1e) {
        for (index = 0; index < 16; index++) {
            if (MB_FakeGetParentBssDesc(index, &scanBlock) != 0) {
                u8 *tableBytes = gStruct217AA00->mUnk_00ac[0].mUnk_c0;
                u8 *entryBytes = tableBytes + entryIndex * 0xe0;
                if (scanBlock.mUnk_02[2] == tableBytes[entryIndex * 0xe0] && scanBlock.mUnk_02[3] == entryBytes[1] &&
                    scanBlock.mUnk_02[4] == entryBytes[2] && scanBlock.mUnk_02[5] == entryBytes[3] &&
                    scanBlock.mUnk_02[6] == entryBytes[4] && scanBlock.mUnk_02[7] == entryBytes[5]) {
                    result = (s8) index;
                    break;
                }
            }
        }
    }
    return result;
}

// Codes: 2 is an error, 3 the end of the scan; 0 and 1 carry a table entry and are ignored.
void RepeatedScanCallback(u32 code) {
    switch (code) {
        case 0:
        case 1:
            break;
        case 2:
            func_02050e60(5);
            break;
        case 3:
            gStruct217AA00->mRequestPending = 0;
            break;
    }
}

void ScanConnectStateCallback(u32 state) {
    switch (state) {
        case 11:
            gStruct217AA00->mRequestPending = 0;
            break;
        case 20:
            gStruct217AA00->mUnk_1692 = (OS_GetTick() >> 10) % 40;
            gStruct217AA00->mRequestPending = 0;
            break;
        case 7:
            gStruct217AA00->mUnk_169c = 1;
            gStruct217AA00->mUnk_0004 = 6;
            break;
        case 4:
            func_02050e60(5);
            break;
        case 3:
        case 6:
            gStruct217AA00->mUnk_169c = 0;
            gStruct217AA00->mRequestPending = 0;
            break;
    }
}

s32 func_0204e29c(void) {
    BOOL r = FALSE;
    switch (gStruct217AA00->mUnk_000c) {
        case 0:
            gStruct217AA00->mUnk_0454 |= 0x40;
            gStruct217AA00->mUnk_0004 = 1;
            Initialize();
            break;
        case 1:
            MeasureChannel(r);
            break;
        case 4:
            func_0204f814();
            func_0204e568();
            break;
        case 0x16:
            func_0200104c();
            r = TRUE;
            break;
    }
    return r;
}

s32 func_0204e204(void) {
    BOOL stepDone = FALSE;
    BOOL result = FALSE;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        switch (gStruct217AA00->mUnk_000c) {
            case 0:
                gStruct217AA00->mUnk_0454 |= 0x40;
                gStruct217AA00->mUnk_0004 = 1;
                Initialize();
                break;
            case 1:
                stepDone = TRUE;
                break;
        }
    } else {
        switch (gStruct217AA00->mUnk_000c) {
            case 0:
                gStruct217AA00->mUnk_0454 |= 0x40;
                gStruct217AA00->mUnk_0004 = 1;
                Initialize();
                break;
            case 1:
                SetupScanConnect();
                break;
            case 0x1c:
                func_0204e498();
                stepDone = TRUE;
                break;
        }
    }
    if (stepDone != FALSE) {
        gStruct217AA00->mUnk_0004 = 3;
        result = TRUE;
    }
    return result;
}

s32 func_0204e1a8(s32 a) {
    s32 result = 0;
    if (gStruct217AA00->mRequestPending != 0) {
        return 0;
    }
    switch (func_0204e1a8_inline()) {
        case 1:
            result = func_0204e29c();
            break;
        case 2:
            result = func_0204e204();
            break;
        case 0:
            if (a != 0) {
                gStruct217AA00->mUnk_0000 = 1;
            } else {
                gStruct217AA00->mUnk_0000 = 2;
            }
            break;
    }
    return result;
}

void func_0204e128(void) {
    u8 index;
    u8 count;
    if (gStruct217AA00->mUnk_1696 == 0) {
        func_02050e60(5);
        return;
    }
    gStruct217AA00->mUnk_000c = 0x18;
    index = 1;
    gStruct217AA00->mRequestPending = index;
    count = 0;
    gStruct217AA00->mUnk_1697 = count;
    gStruct217AA00->mUnk_1694 |= index;
    for (; index <= 15; index++) {
        if (func_02007d50(index, 2) == 1) {
            count++;
        }
    }
    if (count == 0) {
        gStruct217AA00->mUnk_1694 &= ~1;
    }
}

void func_0204e0bc(void) {
    u8 index;
    u8 count;
    gStruct217AA00->mUnk_000c = 0x19;
    index = 1;
    gStruct217AA00->mRequestPending = index;
    gStruct217AA00->mUnk_1694 |= 2;
    count = 0;
    gStruct217AA00->mUnk_1695 = count;
    for (; index <= 15; index++) {
        if (func_02007d50(index, 3) == 1) {
            count++;
        }
    }
    if (count == 0) {
        gStruct217AA00->mUnk_1694 &= ~2;
    }
}

void func_0204e090(void) {
    gStruct217AA00->mUnk_000c = 0x1b;
    gStruct217AA00->mRequestPending = 1;
    gStruct217AA00->mUnk_1694 &= ~2;
    func_02009c04();
}

void StartRequestEndScan(void) {
    gStruct217AA00->mUnk_000c = 0x21;
    gStruct217AA00->mRequestPending = 1;
    RequestEndScan();
}

void func_0204e03c(u32 entryIndex) {
    gStruct217AA00->mUnk_000c = 0x22;
    gStruct217AA00->mRequestPending = 1;
    gStruct217AA00->mUnk_169c = 0;
    if (MB_FakeEntryToParent(entryIndex) == 0) {
        func_02050e60(5);
    }
}

void func_0204dfe0(u32 a) {
    u32 result;
    gStruct217AA00->mUnk_000c = 0x23;
    gStruct217AA00->mRequestPending = 1;
    result = MB_FakeReadParentBssDesc(a, (ScanBlock *) gStruct217AA00->mUnk_0024, 0x1bc, 0x36, 0, 0);
    gStruct217AA00->mRequestPending = 0;
    gStruct217AA00->mUnk_0024->mUnk_48 = (gStruct217AA00->mUnk_0024->mUnk_48 + 7) & 0x7fff;
    if (result == 0) {
        func_02050e60(5);
    }
}

void func_0204df90(void) {
    gStruct217AA00->mUnk_000c = 0x1a;
    gStruct217AA00->mRequestPending = 1;
    func_02007ec4((ScanBlock *) gStruct217AA00->mUnk_0024, 0x1bc, 0x36, 0, 0);
    gStruct217AA00->mUnk_0024->mUnk_48 = (gStruct217AA00->mUnk_0024->mUnk_48 + 7) & 0x7fff;
    gStruct217AA00->mRequestPending = 0;
}

#pragma thumb off
