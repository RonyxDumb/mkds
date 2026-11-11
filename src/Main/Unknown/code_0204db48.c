#include "Main/Unknown/code_0204db48.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_0204df5c.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02059878.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0211d4a8.h"

#pragma thumb on

s32 AdvanceScanConnect(u16 entryIndex) {
    s32 result = 0;
    ConnectionWork *connectionWork = gConnectionWork;

    switch (connectionWork->mStep) {
        case 29:
            if (TrySelectScanSlot(entryIndex) == 0) {
                SetRequestErrorCode(5);
            }
            if (TryGetScanSlotName(entryIndex, NULL) != 0) {
                StartRequestEndScan();
            } else {
                SetRequestErrorCode(5);
            }
            break;
        case 10:
            connectionWork->mStepWaitFrames = connectionWork->mStepWaitFrames + 1;
            if (gConnectionWork->mStepWaitFrames > 0x4b0) {
                SetRequestErrorCode(5);
                return 3;
            }
            break;
        case 7:
            connectionWork->mRequestPending = 0;
            break;
        case 30: {
            s32 scanEntryIndex;
            connectionWork->mStepWaitFrames = connectionWork->mStepWaitFrames + 1;
            if (gConnectionWork->mStepWaitFrames > 0x4b0) {
                SetRequestErrorCode(5);
            } else {
                scanEntryIndex = FindScanEntryIndex(entryIndex);
                if (scanEntryIndex != -1) {
                    gConnectionWork->mScanEntryIndex = scanEntryIndex;
                    StartRequestEndScan();
                }
            }
            break;
        }
    }
    connectionWork = gConnectionWork;
    if (connectionWork->mRequestPending != 0) {
        return 0;
    }
    switch (connectionWork->mStep) {
        case 7:
            connectionWork->mFlags |= CONNECTION_FLAG_MULTIBOOT_SETUP;
            EndScan();
            break;
        case 9:
            SetupScanConnect();
            break;
        case 28:
            connectionWork->mStepWaitFrames = 0;
            StartRepeatedScanStep1E();
            break;
        case 30:
            StartRequestEndScan();
            break;
        case 33:
            if (connectionWork->mScanEntryIndex == -1) {
                StartConnectToScanEntry(entryIndex);
            } else {
                StartConnectToScanEntry((u16) connectionWork->mScanEntryIndex);
            }
            break;
        case 34:
            if (connectionWork->mScanConnected != 0) {
                if (connectionWork->mScanEntryIndex == -1) {
                    ReadFakeParentBssDesc(entryIndex);
                } else {
                    ReadFakeParentBssDesc((u16) connectionWork->mScanEntryIndex);
                }
            } else {
                result = 2;
            }
            break;
        case 35:
            StartCloseScanConnect();
            break;
        case 1:
            connectionWork->mStepWaitFrames = 0;
        case 2:
            if (gBootInfo->mUnk_00 == 2) {
                ReadMultiBootParentBssDesc();
            } else {
                StartConnect(NULL, NULL, NULL, ConnectFailedCallback, NULL);
            }
            break;
        case 31:
            if (connectionWork->mStepWaitFrames < 0x3c) {
                connectionWork->mStepWaitFrames = connectionWork->mStepWaitFrames + 1;
            } else {
                connectionWork->mStep = 32;
            }
            break;
        case 26:
        case 32:
            StartRomArchiveTransfer();
            break;
        case 36:
            StartConnect(NULL, NULL, NULL, ConnectFailedCallback, NULL);
            break;
        case 10:
            StartMP();
            break;
        case 11:
            connectionWork->mState = 6;
            InitMPStateMachine();
            result = 1;
            break;
    }
    return result;
}

u8 CompactMaskBits(u8 mask) {
    u8 packed = mask & 1;
    u32 i = 1;
    u32 nextBit = 1;

    for (; i < 8; i++) {
        if (((1 << i) & mask) != 0) {
            packed = packed | (1 << nextBit);
            nextBit++;
        }
    }
    return packed;
}

s32 AdvanceChildMaskCovered(void) {
    BOOL result = FALSE;
    ConnectionWork *connectionWork = gConnectionWork;
    u32 maskCopy = connectionWork->mMultiBootChildMask;
    u8 childMask = connectionWork->mChildren.mChildMask;

    if (maskCopy == (maskCopy & childMask)) {
        result = TRUE;
    } else if (connectionWork->mStepWaitFrames > 0x708) {
        if (childMask == 0) {
            SetRequestErrorCode(5);
        } else {
            gConnectionWork->mMultiBootChildMask = CompactMaskBits(childMask);
            result = TRUE;
        }
    } else {
        connectionWork->mStepWaitFrames = connectionWork->mStepWaitFrames + 1;
    }
    return result;
}

s32 AdvanceMultiBootParent(void) {
    BOOL result = FALSE;
    switch (gConnectionWork->mState) {
        case 2:
            gConnectionWork->mState = 5;
            break;
        case 5:
            break;
        case 10:
            return 1;
        default:
            return 3;
    }
    if (gConnectionWork->mRequestPending != 0) {
        return 0;
    }
    switch (gConnectionWork->mStep) {
        case 22:
            StartSendingToAllChildren();
            break;
        case 24:
            StartBootRequestToAllChildren();
            break;
        case 25:
            StartEndToIdle();
            break;
        case 27:
            StartRomArchiveTransfer();
            break;
        case 36:
            SetLifeTime(0x14);
            break;
        case 3:
            FillParentParameter(1);
            SetParentParameter();
            break;
        case 4:
            SetParentChannelLowestSum();
            FillParentParameter(1);
            SetParentParameter();
            break;
        case 5:
            StartParent(NULL);
            break;
        case 6:
            gConnectionWork->mMultiBootChildMask = CompactMaskBits(gConnectionWork->mMultiBootChildMask);
            gConnectionWork->mStepWaitFrames = 0;
            StartMP();
            break;
        case 11:
        case 15:
            if (AdvanceChildMaskCovered() != 0) {
                InitMPStateMachine();
                result = TRUE;
            }
            break;
    }
    return result;
}

#pragma thumb off

s32 RomArchiveReadCallback(FSArchive *archive, void *dst, u32 src, u32 length) {
    MI_CpuCopy8((const void *) src, dst, length);
    return 0;
}
