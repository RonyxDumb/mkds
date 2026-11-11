#include "Main/Unknown/code_0204df90.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02009cc8.h"
#include "code_0200aeb4.h"
#include "code_0200b1b0.h"
#include "Main/Unknown/code_0200b200.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200b6e8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204ea14.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200f5ac.h"

#pragma thumb on

void AllocConnectionBuffers(void *heap, u32 unused, void *bmg) {
    u32 workSize;
    gConnectionWork->mAllocHeap = heap;
    workSize = GetScanConnectWorkSize();
    if (gBootInfo->mUnk_00 != 2 && workSize < 0xc000) {
        workSize = 0xc000;
    }
    gConnectionWork->mMultiBootWorkSize = workSize;
    gConnectionWork->mMultiBootWork = HeapAllocAligned(heap, gConnectionWork->mMultiBootWorkSize, 0x20);
    if (gBootInfo->mUnk_00 != 2) {
        gConnectionWork->mMultiBootSegmentSize = MB_GetSegmentLength(NULL);
        if (gConnectionWork->mMultiBootSegmentSize > 0x80000) {
            gConnectionWork->mMultiBootSegmentSize = 0x80000;
        }
        gConnectionWork->mMultiBootSegment = HeapAllocAligned(heap, gConnectionWork->mMultiBootSegmentSize, 0x20);
        SetGameRegistryTexts(bmg);
        gConnectionWork->mUnk_1668 = HeapAllocAligned(heap, 0x4c0, 0x20);
    } else {
        gConnectionWork->mMultiBootSegmentSize = 0;
        gConnectionWork->mMultiBootSegment = 0;
        gConnectionWork->mUnk_1668 = 0;
    }
    ResetConnectionBuffers(&gConnectionWork->mUnk_1658_view);
}

void ParentStateCallback(u32 index, u32 code, Unk0204e4d8 *childInfo) {
    gConnectionWork->mUnk_1658_view.mChildStateCodes[index] = code;
    if (gConnectionWork->mStep == 0x1b && code != 0xc) {
        return;
    }
    switch (code) {
        case 10: {
            u32 accept = 1;
            if (gConnectionWork->mMultiBootRequestFlags & 1) {
                accept = 0;
            } else if ((gConnectionWork->mStatusFlags & 4) && childInfo->mUnk_00_4 == 0) {
                accept = 0;
            }
            if (accept != 0) {
                MB_CommResponseRequest(index, 1);
            } else {
                MB_CommResponseRequest(index, 0);
            }
            return;
        }
        case 7:
            gConnectionWork->mSendCompleteMask |= 1 << index;
            if (gConnectionWork->mWaitToSendMask ==
                (gConnectionWork->mWaitToSendMask & gConnectionWork->mSendCompleteMask)) {
                gConnectionWork->mRequestPending = 0;
            }
            break;
        case 9:
            gConnectionWork->mMultiBootChildMask |= 1 << index;
            break;
        case 12:
            gConnectionWork->mRequestPending = 0;
            break;
        case 1:
            gConnectionWork->mRequestPending = 0;
            break;
        case 3:
            if (gConnectionWork->mMultiBootChildMask & (1 << index)) {
                gConnectionWork->mBootRequestDoneMask |= 1 << index;
                if (gConnectionWork->mWaitToSendMask ==
                    (gConnectionWork->mWaitToSendMask & gConnectionWork->mBootRequestDoneMask)) {
                    gConnectionWork->mRequestPending = 0;
                }
            }
            if (!(gConnectionWork->mMultiBootRequestFlags & 2)) {
                if (gConnectionWork->mWaitToSendCount != 0) {
                    if (gConnectionWork->mWaitToSendMask & (1 << index)) {
                        gConnectionWork->mWaitToSendMask &= ~(1 << index);
                        gConnectionWork->mWaitToSendCount--;
                    }
                    if ((gConnectionWork->mMultiBootRequestFlags & 1) && gConnectionWork->mWaitToSendMask == 0) {
                        SetRequestErrorCode(7);
                    }
                } else {
                    gConnectionWork->mWaitToSendMask = 0;
                    gConnectionWork->mBootRequestDoneMask = 0;
                    gConnectionWork->mMultiBootChildMask = 0;
                    gConnectionWork->mWaitToSendCount = 0;
                }
            }
            if ((gConnectionWork->mMultiBootRequestFlags & 2) &&
                gConnectionWork->mWaitToSendMask ==
                    (gConnectionWork->mWaitToSendMask & gConnectionWork->mBootRequestDoneMask) &&
                gConnectionWork->mStep == 0x19) {
                gConnectionWork->mRequestPending = 0;
                return;
            }
            if ((gConnectionWork->mMultiBootRequestFlags & 1) &&
                gConnectionWork->mWaitToSendMask ==
                    (gConnectionWork->mWaitToSendMask & gConnectionWork->mSendCompleteMask) &&
                gConnectionWork->mStep == 0x18) {
                gConnectionWork->mRequestPending = 0;
                return;
            }
            break;
        case 14:
            if (!(gConnectionWork->mWaitToSendMask & (1 << index))) {
                gConnectionWork->mWaitToSendMask |= 1 << index;
                gConnectionWork->mWaitToSendCount++;
            }
            break;
    }
}

void ResetConnectionBuffers(MultiBootStateView *view) {
    s32 index;
    if (gConnectionWork->mMultiBootWork != 0) {
        MI_CpuFill8(gConnectionWork->mMultiBootWork, 0, gConnectionWork->mMultiBootWorkSize);
    }
    if (gConnectionWork->mUnk_1668 != 0) {
        MI_CpuFill8(gConnectionWork->mUnk_1668, 0, 0x4c0);
    }
    for (index = 0; index < 8; index++) {
        view->mChildStateCodes[index] = 0;
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

void StartMultiBootParent(void) {
    Unk0204e4d8 user;
    gConnectionWork->mStep = 0x16;
    gConnectionWork->mRequestPending = 1;
    ResetConnectionBuffers(&gConnectionWork->mUnk_1658_view);
    user.mUnk_01 = 10;
    user.mUnk_00_0 = gStartupWork->mUnk_40;
    user.mUnk_00_4 = 8;
    MI_CpuCopy8(data_0217aa08->mFirstBlock->mPlayerName, user.mUnk_02, 0x14);
    gConnectionWork->mParentTgid = ComputeParentTgid(1);
    if (MB_Init(gConnectionWork->mMultiBootWork, (Unk02009ff4 *) &user, 0x25, gConnectionWork->mParentTgid, 2) != 0) {
        SetRequestErrorCode(5);
    }
    MB_SetParentCommParam(0x1fe, 7);
    MB_CommSetParentStateCallback(ParentStateCallback);
    if (((s32(*)(u32)) MB_StartParentFromIdle)(gConnectionWork->mParentChannel) != 0) {
        SetRequestErrorCode(5);
    }
    if (RegisterMultiBootSegment() == 0) {
        SetRequestErrorCode(5);
    }
    gConnectionWork->mStatusFlags &= ~4;
    gConnectionWork->mRequestPending = 0;
}

void SetupScanConnect(void) {
    Unk0204e4d8 userInfo;
    gConnectionWork->mStep = 0x1c;
    gConnectionWork->mRequestPending = 1;
    userInfo.mUnk_00_0 = gStartupWork->mUnk_40;
    userInfo.mUnk_01 = 10;
    userInfo.mUnk_00_4 = 9;
    MI_CpuCopy8(data_0217aa08->mFirstBlock->mPlayerName, userInfo.mUnk_02, 0x14);
    gConnectionWork->mScanEntryIndex = -1;
    InitScanConnectWork(gConnectionWork->mMultiBootWork, &userInfo);
    SetScanConnectStateCallback(ScanConnectStateCallback);
    gConnectionWork->mRequestPending = 0;
}

void StartCloseScanConnect(void) {
    gConnectionWork->mStep = 0x1f;
    gConnectionWork->mRequestPending = 1;
    CloseScanConnect();
}

void StartRepeatedScanStep1D(void) {
    gConnectionWork->mStep = 0x1d;
    gConnectionWork->mRequestPending = 1;
    StartRepeatedScan(RepeatedScanCallback, 0x25);
}

static inline u32 MultiBootGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

void StartRepeatedScanStep1E(void) {
    gConnectionWork->mStep = 0x1e;
    gConnectionWork->mRequestPending = 1;
    StartRepeatedScan(RepeatedScanCallback, 0x25);
}

// Returns the scan entry index with bytes 4..9 matching the first six of element a of mScanSlots[0].mUnk_c0, or -1.
s32 FindScanEntryIndex(u32 entryIndex) {
    s32 result;
    u16 index;
    WMBssDesc scanBlock;
    result = -1;
    if (gConnectionWork->mStep == 0x1e) {
        for (index = 0; index < 16; index++) {
            if (MB_FakeGetParentBssDesc(index, &scanBlock) != 0) {
                u8 *tableBytes = gConnectionWork->mScanSlots[0].mKey.mUnk_00;
                u8 *entryBytes = tableBytes + entryIndex * 0xe0;
                if (scanBlock.mBssid[0] == tableBytes[entryIndex * 0xe0] && scanBlock.mBssid[1] == entryBytes[1] &&
                    scanBlock.mBssid[2] == entryBytes[2] && scanBlock.mBssid[3] == entryBytes[3] &&
                    scanBlock.mBssid[4] == entryBytes[4] && scanBlock.mBssid[5] == entryBytes[5]) {
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
            SetRequestErrorCode(5);
            break;
        case 3:
            gConnectionWork->mRequestPending = 0;
            break;
    }
}

void ScanConnectStateCallback(u32 state) {
    switch (state) {
        case 11:
            gConnectionWork->mRequestPending = 0;
            break;
        case 20:
            gConnectionWork->mStepWaitFrames = (OS_GetTick() >> 10) % 40;
            gConnectionWork->mRequestPending = 0;
            break;
        case 7:
            gConnectionWork->mScanConnected = 1;
            gConnectionWork->mState = 6;
            break;
        case 4:
            SetRequestErrorCode(5);
            break;
        case 3:
        case 6:
            gConnectionWork->mScanConnected = 0;
            gConnectionWork->mRequestPending = 0;
            break;
    }
}

s32 AdvanceMultiBootParentSetup(void) {
    BOOL result = FALSE;
    switch (gConnectionWork->mStep) {
        case 0:
            gConnectionWork->mFlags |= CONNECTION_FLAG_MULTIBOOT_SETUP;
            gConnectionWork->mState = 1;
            Initialize();
            break;
        case 1:
            MeasureChannel(result);
            break;
        case 4:
            SetParentChannelLowestSum();
            StartMultiBootParent();
            break;
        case 0x16:
            FinishMultiBootParentSetup();
            result = TRUE;
            break;
    }
    return result;
}

s32 AdvanceMultiBootScanSetup(void) {
    BOOL stepDone = FALSE;
    BOOL result = FALSE;
    if (gBootInfo->mUnk_00 == 2) {
        switch (gConnectionWork->mStep) {
            case 0:
                gConnectionWork->mFlags |= CONNECTION_FLAG_MULTIBOOT_SETUP;
                gConnectionWork->mState = 1;
                Initialize();
                break;
            case 1:
                stepDone = TRUE;
                break;
        }
    } else {
        switch (gConnectionWork->mStep) {
            case 0:
                gConnectionWork->mFlags |= CONNECTION_FLAG_MULTIBOOT_SETUP;
                gConnectionWork->mState = 1;
                Initialize();
                break;
            case 1:
                SetupScanConnect();
                break;
            case 0x1c:
                StartRepeatedScanStep1D();
                stepDone = TRUE;
                break;
        }
    }
    if (stepDone != FALSE) {
        gConnectionWork->mState = 3;
        result = TRUE;
    }
    return result;
}

s32 AdvanceMultiBootSetup(s32 a) {
    s32 result = 0;
    if (gConnectionWork->mRequestPending != 0) {
        return 0;
    }
    switch (MultiBootGetConnectionMode()) {
        case 1:
            result = AdvanceMultiBootParentSetup();
            break;
        case 2:
            result = AdvanceMultiBootScanSetup();
            break;
        case 0:
            if (a != 0) {
                gConnectionWork->mConnectionMode = 1;
            } else {
                gConnectionWork->mConnectionMode = 2;
            }
            break;
    }
    return result;
}

void StartSendingToAllChildren(void) {
    u8 index;
    u8 count;
    if (gConnectionWork->mWaitToSendMask == 0) {
        SetRequestErrorCode(5);
        return;
    }
    gConnectionWork->mStep = 0x18;
    index = 1;
    gConnectionWork->mRequestPending = index;
    count = 0;
    gConnectionWork->mSendCompleteMask = count;
    gConnectionWork->mMultiBootRequestFlags |= index;
    for (; index <= 15; index++) {
        if (MB_CommResponseRequest(index, 2) == 1) {
            count++;
        }
    }
    if (count == 0) {
        gConnectionWork->mMultiBootRequestFlags &= ~1;
    }
}

void StartBootRequestToAllChildren(void) {
    u8 index;
    u8 count;
    gConnectionWork->mStep = 0x19;
    index = 1;
    gConnectionWork->mRequestPending = index;
    gConnectionWork->mMultiBootRequestFlags |= 2;
    count = 0;
    gConnectionWork->mMultiBootChildMask = count;
    for (; index <= 15; index++) {
        if (MB_CommResponseRequest(index, 3) == 1) {
            count++;
        }
    }
    if (count == 0) {
        gConnectionWork->mMultiBootRequestFlags &= ~2;
    }
}

void StartEndToIdle(void) {
    gConnectionWork->mStep = 0x1b;
    gConnectionWork->mRequestPending = 1;
    gConnectionWork->mMultiBootRequestFlags &= ~2;
    MB_EndToIdle();
}

void StartRequestEndScan(void) {
    gConnectionWork->mStep = 0x21;
    gConnectionWork->mRequestPending = 1;
    RequestEndScan();
}

void StartConnectToScanEntry(u32 entryIndex) {
    gConnectionWork->mStep = 0x22;
    gConnectionWork->mRequestPending = 1;
    gConnectionWork->mScanConnected = 0;
    if (StartConnectToEntry(entryIndex) == 0) {
        SetRequestErrorCode(5);
    }
}

void ReadFakeParentBssDesc(u32 entryIndex) {
    u32 result;
    gConnectionWork->mStep = 0x23;
    gConnectionWork->mRequestPending = 1;
    result = MB_FakeReadParentBssDesc(entryIndex, gConnectionWork->mParentBssDesc, 0x1bc, 0x36, 0, 0);
    gConnectionWork->mRequestPending = 0;
    gConnectionWork->mParentBssDesc->mGameInfo.mTgid = (gConnectionWork->mParentBssDesc->mGameInfo.mTgid + 7) & 0x7fff;
    if (result == 0) {
        SetRequestErrorCode(5);
    }
}

void ReadMultiBootParentBssDesc(void) {
    gConnectionWork->mStep = 0x1a;
    gConnectionWork->mRequestPending = 1;
    MB_ReadMultiBootParentBssDesc(gConnectionWork->mParentBssDesc, 0x1bc, 0x36, 0, 0);
    gConnectionWork->mParentBssDesc->mGameInfo.mTgid = (gConnectionWork->mParentBssDesc->mGameInfo.mTgid + 7) & 0x7fff;
    gConnectionWork->mRequestPending = 0;
}

#pragma thumb off
