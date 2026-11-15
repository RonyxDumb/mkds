#include "code_02009928.h"

#include "code_02142eac.h"
#include "code_0200ad00.h"
#include "code_020099d8.h"
#include "mb_parent.h"
#include "code_0214c778.h"
#include "code_0200c0d8.h"
#include "code_0200fc8c.h"
#include "code_0200aeb4.h"
#include "code_020091fc.h"
#include "code_0200eddc.h"
#include "code_0214d5b8.h"
#include "code_0214d018.h"

u16 gWirelessDmaNo;
struct MB_CommPWork *mbc;
ScanParam gScanParams __attribute__((aligned(32)));
struct MBiParam *gWirelessWork;
void *gWMSysBuf;

u16 mbi_life_cam = 0x28;
u16 mbi_life_frame = 0xffff;
u16 mbi_life_mp = 0x28;
u16 mbi_life_table_no = 0xffff;
u32 mbi_power_save_mode = 1;
u16 *gMultibootGameNameCursor = gMultibootGameName;
u16 gMultibootGameName[10] = {0x6d, 0x75, 0x6c, 0x74, 0x69, 0x62, 0x6f, 0x6f, 0x74, 0};

#pragma thumb on

// Stores one block (offset, size, buffer, state) in the first free entry.
void MBi_AttachCacheBuffer(MBiCacheList *table, u32 offset, u32 size, u8 *data, u32 value) {
    u32 savedInterrupts;
    MBiCacheInfo *range;
    savedInterrupts = OS_DisableInterrupts();
    range = table->mList;
    for (;;) {
        if (range >= table->mList + 4) {
            OS_Terminate();
        }
        if (range->mState == MULTIBOOT_CACHE_EMPTY) {
            range->mSrc = offset;
            range->mLen = size;
            range->mPtr = data;
            range->mState = value;
            break;
        }
        range++;
    }
    OS_RestoreInterrupts(savedInterrupts);
}

u32 MBi_ReadFromCache(MBiCacheList *table, u32 offset, void *destination, u32 byteCount) {
    u32 savedInterrupts;
    u32 found;
    MBiCacheInfo *range;
    s32 offsetInRange;
    found = 0;
    savedInterrupts = OS_DisableInterrupts();
    for (range = table->mList; range < table->mList + 4; range++) {
        if (range->mState >= MULTIBOOT_CACHE_LOADED) {
            offsetInRange = offset - range->mSrc;
            if (offsetInRange >= 0 && offsetInRange + byteCount <= range->mLen) {
                MI_CpuCopy8(range->mPtr + offsetInRange, destination, byteCount);
                found = 1;
                table->mLifetime = found;
                break;
            }
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return found;
}

// Moves the scan to the next allowed channel; returns 0 when no channel is allowed.
u32 changeScanChannel(ScanParam *scanParams) {
    u16 candidate;
    u16 channelIndex;
    u16 currentChannel;
    u32 allowedMask;
    allowedMask = WM_GetAllowedChannel();
    if (allowedMask == 0) {
        return 0;
    }
    channelIndex = 0;
    currentChannel = scanParams->mChannel;
    candidate = currentChannel;
    for (; channelIndex < 16;) {
        if ((allowedMask & (1 << (candidate - 1))) != 0 && currentChannel != candidate) {
            scanParams->mChannel = candidate;
            break;
        }
        channelIndex++;
        candidate = candidate == 16 ? 1 : candidate + 1;
    }
    return 1;
}

u32 MBi_IsSendEnabled(void) {
    u32 result;
    u32 secondCheck;
    u32 firstCheck;
    MBiParam *work;
    result = 0;
    secondCheck = 0;
    firstCheck = 0;
    work = gWirelessWork;
    if (work->mMPStarted == 1) {
        if (work->mDataQueued == 0) {
            firstCheck = 1;
        }
    }
    if (firstCheck != 0) {
        if (work->mResetting == 0) {
            secondCheck = 1;
        }
    }
    if (secondCheck != 0) {
        if (work->mConnectedAids != 0) {
            result = 1;
        }
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void MBi_OnInitializeDone(void) {
    u32 result;
    result = WM_SetIndCallback(MBi_ParentCallback);
    MBi_CheckWmErrcode(WIRELESS_REQUEST_EVENT_REPORT, result);
    result = WM_SetLifeTime(MBi_ParentCallback, mbi_life_table_no, mbi_life_cam, mbi_life_frame, mbi_life_mp);
    MBi_CheckWmErrcode(WIRELESS_REQUEST_SET_TIMEOUT, result);
}

#pragma thumb off

#pragma thumb on

// Handles the results of the parent start-up steps, then child connects, disconnects and sent data.
void MBi_ParentCallback(WirelessMessage *result) {
    u32 nonZeroCount;
    u32 childIndex;
    MB_CommPWork *parentWork;
    u32 flag;
    switch (result->mCommand) {
        case WIRELESS_REQUEST_POWER_UP_STACK:
            if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
                gWirelessWork->mCallback(0x100, result);
                return;
            }
            MBi_OnInitializeDone();
            return;
        case WIRELESS_REQUEST_SET_TIMEOUT:
            if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
                gWirelessWork->mCallback(0x100, result);
                return;
            }
            MBi_CheckWmErrcode(WIRELESS_REQUEST_CONFIGURE_HOST,
                               WM_SetParentParameter(MBi_ParentCallback, (ParentParameter *) gWirelessWork));
            return;
        case WIRELESS_REQUEST_CONFIGURE_HOST:
            gWirelessWork->mCallback(0x15, result);
            MBi_CheckWmErrcode(WIRELESS_REQUEST_WATCH_BEACONS, WM_SetBeaconIndication(MBi_ParentCallback, 1));
            return;
        case WIRELESS_REQUEST_WATCH_BEACONS:
            if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
                gWirelessWork->mCallback(0x100, result);
                return;
            }
            MBi_CheckWmErrcode(WIRELESS_REQUEST_OPEN_HOST, WMi_StartParentEx(MBi_ParentCallback, mbi_power_save_mode));
            return;
        case WIRELESS_REQUEST_OPEN_HOST:
            if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
                gWirelessWork->mCallback(0x100, result);
                return;
            }
            switch (result->mReplyState) {
                case WIRELESS_STATE_SESSION_START:
                    gWirelessWork->mConnectedAids = 0;
                    gWirelessWork->mMPStarted = 0;
                    return;
                case WIRELESS_STATE_LINKED:
                    if (gWirelessWork->mResetting == 1) {
                        return;
                    }
                    gWirelessWork->mConnectedAids |= 1 << result->mLength;
                    gWirelessWork->mCallback(0, result);
                    if (gWirelessWork->mMPStarted == 0 && mbc->mStartMpBusy == 0) {
                        mbc->mStartMpBusy = 1;
                        flag = 1;
                        if (gWirelessWork->mContSend != 0) {
                            flag = 0;
                        }
                        MBi_CheckWmErrcode(WIRELESS_REQUEST_BEGIN_EXCHANGE,
                                           WM_StartMPEx(MBi_ParentCallback, gWirelessWork->mReceiveBuffer,
                                                        gWirelessWork->mReceiveBufferSize, gWirelessWork->mSendBuffer,
                                                        gWirelessWork->mSendBufferSize, flag, 0, 0, 0, 1, 1));
                        return;
                    }
                    if (MBi_IsSendEnabled() == 0) {
                        return;
                    }
                    gWirelessWork->mCallback(0x19, NULL);
                    return;
                case WIRELESS_STATE_UNLINKED:
                    gWirelessWork->mConnectedAids &= ~(1 << result->mLength);
                    gWirelessWork->mCallback(1, result);
                    return;
                case WIRELESS_STATE_FORWARD_UNLESS_RESETTING:
                    if (gWirelessWork->mResetting == 1) {
                        return;
                    }
                    gWirelessWork->mCallback(0x1c, result);
                    return;
                default:
                    gWirelessWork->mCallback(0x100, result);
                    return;
            }
        case WIRELESS_REQUEST_BEGIN_EXCHANGE:
            mbc->mStartMpBusy = 0;
            switch (result->mState) {
                case WIRELESS_STATE_EXCHANGE_BEGUN:
                    gWirelessWork->mMPStarted = 1;
                    gWirelessWork->mCallback(0x19, NULL);
                    return;
                case WIRELESS_STATE_EXCHANGE_PASS_RECV_BUFFER:
                    gWirelessWork->mCallback(3, result->mRecvBuf);
                    return;
                default:
                    gWirelessWork->mCallback(0x100, result);
                    return;
            }
        case WIRELESS_REQUEST_QUEUE_EXCHANGE_DATA:
            parentWork = mbc;
            if (parentWork->mUseWvrFlag != 0) {
                nonZeroCount = 0;
                for (childIndex = 0; childIndex < 15; childIndex++) {
                    if (parentWork->mPCommState[childIndex] != 0) {
                        nonZeroCount++;
                        if (nonZeroCount >= 2) {
                            break;
                        }
                    }
                }
                if (nonZeroCount == 1) {
                    OS_SpinWait(0x32c8);
                }
            }
            gWirelessWork->mDataQueued = 0;
            if (result->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
                gWirelessWork->mCallback(2, result);
                gWirelessWork->mCallback(0x19, NULL);
                return;
            }
            if (result->mResultCode == WIRELESS_RESULT_SEND_BACKLOG) {
                gWirelessWork->mCallback(0x2a, result);
                return;
            }
            gWirelessWork->mCallback(0x13, result);
            gWirelessWork->mCallback(0x19, NULL);
            return;
        case WIRELESS_REQUEST_RESTART:
            if (mbc->mIsStartedEx == 0) {
                if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
                    gWirelessWork->mResetting = 0;
                    gWirelessWork->mCallback(0x100, result);
                    return;
                }
                gWirelessWork->mConnectedAids = 0;
                gWirelessWork->mMPStarted = 0;
                MBi_CheckWmErrcode(WIRELESS_REQUEST_CLOSE_STACK, WM_End(MBi_ParentCallback));
                return;
            }
            WM_SetPortCallback(1, NULL, NULL);
            WM_SetIndCallback(NULL);
        case WIRELESS_REQUEST_CLOSE_STACK:
            if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
                gWirelessWork->mResetting = 0;
                gWirelessWork->mCallback(0x100, result);
                return;
            }
            gWirelessWork->mMbIsStarted = 0;
            mbc->mIsMbInitialized = 0;
            gWirelessWork->mCallback(0x11, result);
            return;
        case WIRELESS_REQUEST_LEAVE:
            if (result->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
                gWirelessWork->mConnectedAids &= ~result->mAidBitmap;
            }
            return;
        case WIRELESS_REQUEST_EVENT_REPORT:
            switch (result->mState) {
                case WIRELESS_STATE_EVENT_FORWARD_FIRST:
                    gWirelessWork->mCallback(0x1d, result);
                    return;
                case WIRELESS_STATE_EVENT_FORWARD_SECOND:
                    gWirelessWork->mCallback(0x1f, result);
                    return;
                case WIRELESS_STATE_EVENT_FORWARD_THIRD:
                    gWirelessWork->mCallback(0x20, result);
                    return;
                case WIRELESS_STATE_EVENT_FORWARD_FOURTH:
                    gWirelessWork->mCallback(0x21, result);
                    return;
                case WIRELESS_STATE_EVENT_FATAL:
                    OS_Terminate();
                    break;
                case WIRELESS_STATE_EVENT_IGNORED:
                    break;
            }
            break;
        default:
            gWirelessWork->mCallback(0x100, result);
            return;
    }
}

void MBi_ChildPortCallback(void *portMessage) {
    WirelessMessage *result = portMessage;
    if (result->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
        if (result->mState == WIRELESS_STATE_LINKED) {
        } else if (result->mState == WIRELESS_STATE_UNLINKED) {
        } else if (result->mState == WIRELESS_STATE_PORT_DATA_ARRIVED) {
            gWirelessWork->mCallback(9, result);
        }
    }
}

// Child side (scan, connect, MP data); mMode is only ever 1, so this does not run in this build.
void MBi_ChildCallback(WirelessMessage *result) {
    ScanEntry *entry;
    u8 firstByte;
    MBiParam *work;
    s32 entryIndex;
    s32 entryCount;
    ScanEntry *entries;
    work = gWirelessWork;
    switch (result->mCommand) {
        case WIRELESS_REQUEST_POWER_UP_STACK:
            if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
                work->mCallback(0x100, result);
                return;
            }
            work->mCallback(0x15, result);
            MBi_CheckWmErrcode(WIRELESS_REQUEST_SET_TIMEOUT, WM_SetLifeTime(MBi_ChildCallback, mbi_life_table_no,
                                                                        mbi_life_cam, mbi_life_frame, mbi_life_mp));
            return;
        case WIRELESS_REQUEST_SET_TIMEOUT:
            if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
                work->mCallback(0x100, result);
                return;
            }
            gScanParams.mScanBuf = work->mScanBuffer;
            if (gScanParams.mChannel == 0) {
                gScanParams.mChannel = 1;
            }
            if (gScanParams.mMaxChannelTime == 0) {
                gScanParams.mMaxChannelTime = 0xc8;
            }
            gScanParams.mBssid[0] = 0xff;
            gScanParams.mBssid[1] = 0xff;
            gScanParams.mBssid[2] = 0xff;
            gScanParams.mBssid[3] = 0xff;
            gScanParams.mBssid[4] = 0xff;
            gScanParams.mBssid[5] = 0xff;
            work->mRepeatScan = 1;
            work->mScanChannelFlag = 1;
            MBi_CheckWmErrcode(WIRELESS_REQUEST_BEGIN_SEARCH, WM_StartScan(MBi_ChildCallback, &gScanParams));
            return;
        case WIRELESS_REQUEST_BEGIN_SEARCH:
            if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
                work->mCallback(0x100, result);
                return;
            }
            switch (result->mReplyState) {
                case WIRELESS_STATE_SEARCH_NO_ACTION:
                    return;
                case WIRELESS_STATE_HOST_SIGHTED:
                    entries = work->mScanEntries;
                    entryIndex = 0;
                    entryCount = work->mScanEntryCount;
                    if (entryCount > 0) {
                        entry = entries;
                        firstByte = result->mMacAddress[0];
                        do {
                            if (firstByte == entry->mMessage.mMacAddress[0] &&
                                result->mMacAddress[1] == entry->mMessage.mMacAddress[1] &&
                                result->mMacAddress[2] == entry->mMessage.mMacAddress[2] &&
                                result->mMacAddress[3] == entry->mMessage.mMacAddress[3] &&
                                result->mMacAddress[4] == entry->mMessage.mMacAddress[4] &&
                                result->mMacAddress[5] == entry->mMessage.mMacAddress[5]) {
                                entries[entryIndex].mMessage.mGameInfoLength = result->mGameInfoLength;
                                entries[entryIndex].mMessage.mGameInfo = result->mGameInfo;
                                DC_InvalidateRange(&work->mScanEntries[entryIndex], 0xc0);
                                MI_DmaCopy16(gWirelessDmaNo, work->mScanBuffer, &work->mScanEntries[entryIndex], 0xc0);
                                work->mLastScanEntry = entryIndex;
                                goto done;
                            }
                            entry++;
                            entryIndex++;
                        } while (entryIndex < entryCount);
                    }
                    if (entryIndex < 16) {
                        work->mScanEntryCount = entryIndex + 1;
                        MIi_CpuCopy16(result, &entries[entryIndex].mMessage, 0xb8);
                        entry = &work->mScanEntries[entryIndex];
                        DC_InvalidateRange(entry, 0xc0);
                        MI_DmaCopy16(gWirelessDmaNo, work->mScanBuffer, entry, 0xc0);
                        work->mLastScanEntry = entryIndex;
                    }
                done:
                    work->mCallback(4, result);
                    if (work->mRepeatScan == 0) {
                        return;
                    }
                    if (work->mScanChannelFlag != 0) {
                        if (changeScanChannel(&gScanParams) == 0) {
                            MBi_CommEnd();
                        }
                    }
                    MBi_CheckWmErrcode(WIRELESS_REQUEST_BEGIN_SEARCH, WM_StartScan(MBi_ChildCallback, &gScanParams));
                    return;
                case WIRELESS_STATE_SEARCH_EMPTY:
                    work->mCallback(5, result);
                    if (work->mRepeatScan == 0) {
                        return;
                    }
                    if (work->mScanChannelFlag != 0) {
                        if (changeScanChannel(&gScanParams) == 0) {
                            MBi_CommEnd();
                        }
                    }
                    MBi_CheckWmErrcode(WIRELESS_REQUEST_BEGIN_SEARCH, WM_StartScan(MBi_ChildCallback, &gScanParams));
                    return;
                default:
                    work->mCallback(0x100, result);
                    return;
            }
        case WIRELESS_REQUEST_STOP_SEARCH:
            if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
                work->mCallback(0x100, result);
                return;
            }
            MBi_CheckWmErrcode(WIRELESS_REQUEST_ENTER_HOST,
                               WM_StartConnectEx(MBi_ChildCallback, work->mPInfo, NULL, 1, 0));
            return;
        case WIRELESS_REQUEST_ENTER_HOST:
            if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
                work->mScanEntryCount = 0;
                work->mCallback(0xb, result);
                return;
            }
            switch (result->mReplyState) {
                case WIRELESS_STATE_CHILD_SESSION_START:
                    work->mConnectedAids = 0;
                    work->mMPStarted = 1;
                    return;
                case WIRELESS_STATE_LINKED:
                    work->mMyAid = result->mOwnAid;
                    work->mCallback(6, result);
                    work->mConnectedAids = 1;
                    if (WM_SetPortCallback(1, MBi_ChildPortCallback, NULL) != 0) {
                        return;
                    }
                    MBi_CheckWmErrcode(WIRELESS_REQUEST_BEGIN_EXCHANGE,
                                       WM_StartMPEx(MBi_ChildCallback, work->mReceiveBuffer, work->mReceiveBufferSize,
                                                    work->mSendBuffer, work->mSendBufferSize,
                                                    work->mContSend == 0 ? 1 : 0, 0, 0, 0, 1, 1));
                    return;
                case WIRELESS_STATE_UNLINKED:
                    work->mCallback(10, result);
                    work->mConnectedAids = 0;
                    work->mMPStarted = 0;
                    return;
                default:
                    work->mCallback(0x100, result);
                    return;
            }
        case WIRELESS_REQUEST_BEGIN_EXCHANGE:
            switch (result->mState) {
                case WIRELESS_STATE_EXCHANGE_BEGUN:
                    work->mMPStarted = 1;
                    if (MBi_IsSendEnabled() == 0) {
                        return;
                    }
                    work->mCallback(0x19, NULL);
                    return;
                case WIRELESS_STATE_EXCHANGE_IGNORED_FIRST:
                case WIRELESS_STATE_EXCHANGE_IGNORED_SECOND:
                    return;
                default:
                    work->mCallback(0x100, result);
                    return;
            }
        case WIRELESS_REQUEST_QUEUE_EXCHANGE_DATA:
            work->mDataQueued = 0;
            if (result->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
                work->mCallback(8, result);
            } else if (result->mResultCode == WIRELESS_RESULT_NO_ANSWER) {
                work->mCallback(0x29, result);
            } else {
                work->mCallback(0x12, result);
            }
            work->mCallback(0x19, NULL);
            return;
        case WIRELESS_REQUEST_RESTART:
            if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
                work->mResetting = 0;
                work->mCallback(0x100, result);
                return;
            }
            work->mConnectedAids = 0;
            gWirelessWork->mMPStarted = 0;
            MBi_CheckWmErrcode(WIRELESS_REQUEST_CLOSE_STACK, WM_End(MBi_ChildCallback));
            return;
        case WIRELESS_REQUEST_CLOSE_STACK:
            if (result->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
                work->mResetting = 0;
                work->mCallback(0x100, result);
                return;
            }
            work->mMbIsStarted = 0;
            mbc->mIsMbInitialized = 0;
            work->mCallback(0x11, result);
            return;
        case WIRELESS_REQUEST_BEGIN_KEY_SHARE:
            if (MBi_IsSendEnabled() == 0) {
                return;
            }
            work->mCallback(0x19, NULL);
            return;
        case WIRELESS_REQUEST_EVENT_REPORT:
            switch (result->mState) {
                case WIRELESS_STATE_EVENT_FATAL:
                    OS_Terminate();
                    break;
                case WIRELESS_STATE_EVENT_IGNORED:
                    break;
            }
            return;
        default:
            work->mCallback(0x100, result);
            return;
    }
}

// A value from 0 to 19 made from the MAC address; the caller adds 200 for the beacon period.
u32 MBi_GetBeaconPeriodDispersion(void) {
    u8 macAddress[6];
    u32 byteSum;
    s32 byteIndex;
    OS_GetMacAddress(macAddress);
    byteIndex = 0;
    byteSum = 0;
    for (; byteIndex < 6; byteIndex++) {
        byteSum += macAddress[byteIndex];
    }
    return (byteSum + SYSTEM_WORK->mVblankCount) * 7 % 0x14;
}

s32 MB_Init(void *buffer, MBUserInfo *user, u32 ggid, u32 tgid, u32 dmaNo) {
    MBiParam *wirelessWork;
    MB_CommPWork *parentWork;
    u32 savedInterrupts;
    vu16 clearValue16;
    vu32 clearValue32;
    s32 index;
    u16 *cursor;
    if (mbc != NULL && mbc->mIsMbInitialized != 0) {
        return 2;
    }
    wirelessWork = (MBiParam *) (((u32) buffer + 0x1f) & ~0x1f);
    parentWork = (MB_CommPWork *) (((u32) wirelessWork + 0x1e1f) & ~0x1f);
    if (tgid == 0x10000) {
        tgid = WM_GetNextTgid();
    }
    savedInterrupts = OS_DisableInterrupts();
    gWirelessDmaNo = dmaNo;
    gWirelessWork = wirelessWork;
    mbc = parentWork;
    clearValue32 = 0;
    MIi_CpuClear32(clearValue32, wirelessWork, 0x1e00);
    clearValue16 = 0;
    MIi_CpuClear16(clearValue16, parentWork, 0x1340);
    cursor = wirelessWork->mUname;
    for (index = 0; index < user->mNameLength; index++) {
        *cursor = user->mName[index];
        cursor++;
    }
    cursor = wirelessWork->mGname;
    for (index = 0; index < 16; index++) {
        if (*gMultibootGameNameCursor == 0) {
            break;
        }
        *cursor = *gMultibootGameNameCursor++;
        cursor++;
    }
    MI_CpuCopy8(user, &parentWork->mUser, sizeof(MBUserInfo));
    if (user->mNameLength < 10) {
        parentWork->mUser.mName[user->mNameLength] = 0;
    }
    wirelessWork->mSendDataSize = 0x100;
    wirelessWork->mReceiveDataSize = 8;
    wirelessWork->mSendBufferSize = 0;
    wirelessWork->mReceiveBufferSize = 0;
    wirelessWork->mContSend = 1;
    wirelessWork->mReceiveBuffer = parentWork->mRecvBuffer;
    wirelessWork->mEntryFlag = 1;
    wirelessWork->mMultiBootFlag = 0;
    wirelessWork->mCsFlag = 1;
    wirelessWork->mKsFlag = 0;
    wirelessWork->mGgid = ggid;
    wirelessWork->mTgid = tgid;
    wirelessWork->mBeaconPeriod = MBi_GetBeaconPeriodDispersion() + 0xc8;
    wirelessWork->mMaxChildren = 0xf;
    wirelessWork->mDataQueued = 0;
    wirelessWork->mMbIsStarted = 0;
    parentWork->mIsMbInitialized = 1;
    parentWork->mStartMpBusy = 0;
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

u32 MBi_IsCommSizeValid(u32 sendDataSize, u32 receiveDataSize, u32 maxChildren) {
    s32 totalSize;
    if (sendDataSize > 0x1fe || sendDataSize < 0xe4) {
        return 0;
    }
    if (receiveDataSize > 0x10 || receiveDataSize < 8) {
        return 0;
    }
    totalSize = (sendDataSize + 0x26) * 4 + 0x14a + maxChildren * ((receiveDataSize + 0x20) * 4 + 0x70);
    if (totalSize < 0x15e0) {
        return 1;
    }
    return 0;
}

// Sets the send size and child limit before the parent starts; returns 0 when the start-up already ran or they do not
// fit.
u32 MB_SetParentCommParam(u32 sendDataSize, u32 maxChildren) {
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    if (gWirelessWork->mMbIsStarted != 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    if (MBi_IsCommSizeValid(sendDataSize, 8, maxChildren) == 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    gWirelessWork->mMaxChildren = maxChildren;
    gWirelessWork->mSendDataSize = sendDataSize;
    gWirelessWork->mReceiveDataSize = 8;
    OS_RestoreInterrupts(savedInterrupts);
    return 1;
}

s32 MBi_StartCommon(void) {
    gWirelessWork->mMPStarted = 0;
    gWirelessWork->mConnectedAids = 0;
    gWirelessWork->mResetting = 0;
    gWirelessWork->mGname[8] = 0;
    MBi_SetMaxScanTime(10);
    if (mbc->mIsStartedEx == 0) {
        s32 result;
        do {
            result = WM_Initialize(gWMSysBuf, gWirelessWork->mCommandCallback, gWirelessDmaNo);
        } while (result == 4);
        if (result != 2) {
            return 8;
        }
        WM_SetIndCallback(gWirelessWork->mCommandCallback);
        gWirelessWork->mMbIsStarted = 1;
        return 0;
    }
    WM_SetIndCallback(gWirelessWork->mCommandCallback);
    gWirelessWork->mMbIsStarted = 1;
    MBi_OnInitializeDone();
    return 0;
}

// Starts the parent on channel a: sets up the buffers and callbacks, then the callbacks bring the parent up.
s32 MBi_StartParentCore(u16 channel) {
    u32 savedInterrupts;
    vu16 clearValues[2];
    s32 value;
    MBParentStateCallback callback;
    s32 childIndex;
    MB_CommPWork *parentWork;
    MBiParam *wirelessWork;
    savedInterrupts = OS_DisableInterrupts();
    gWirelessWork->mChannel = channel;
    parentWork = mbc;
    gWMSysBuf = (void *) (((u32) parentWork + 0x7d1f) & ~0x1f);
    callback = parentWork->mCallback;
    clearValues[0] = 0;
    MIi_CpuClear16(clearValues[0], parentWork->mChildUser, 0x69c0);
    MB_CommSetParentStateCallback(callback);
    mbc->mBlockSizeMax = gWirelessWork->mSendDataSize - 6;
    MBi_SetChildMPMaxSize(gWirelessWork->mReceiveDataSize);
    MBi_SetParentPieceBuffer(&mbc->mReqDataBuf);
    for (childIndex = 0; childIndex < 15; childIndex++) {
        mbc->mPCommState[childIndex] = 0;
        mbc->mChildEntryIndex[childIndex] = -1;
    }
    mbc->mEntryCount = 0;
    clearValues[1] = 0;
    MIi_CpuClear16(clearValues[1], mbc->mFileInfo, 0x5d40);
    MI_CpuFill8(mbc->mReq2child, 0, 0x1e);
    gWirelessWork->mMode = 1;
    gWirelessWork->mCallback = MBi_CommParentCallback;
    gWirelessWork->mCommandCallback = MBi_ParentCallback;
    gWirelessWork->mParentMaxSize = gWirelessWork->mSendDataSize;
    wirelessWork = gWirelessWork;
    wirelessWork->mSendBufferSize = (wirelessWork->mParentMaxSize + 0x23) & ~0x1f;
    gWirelessWork->mChildMaxSize = gWirelessWork->mReceiveDataSize;
    wirelessWork = gWirelessWork;
    wirelessWork->mReceiveBufferSize = (((wirelessWork->mChildMaxSize + 0xe) * 0xf + 0x29) & ~0x1f) << 1;
    MB_InitSendGameInfoStatus();
    value = MBi_StartCommon();
    OS_RestoreInterrupts(savedInterrupts);
    mbc->mUseWvrFlag = PXI_IsCallbackReady(0xf, 1);
    return value;
}

s32 MB_StartParentFromIdle(u16 channel) {
    mbc->mIsStartedEx = 1;
    return MBi_StartParentCore(channel);
}

#pragma thumb off

#pragma thumb on

int MBi_CallReset(void) {
    int result;
    result = WM_Reset(gWirelessWork->mCommandCallback);
    MBi_CheckWmErrcode(WIRELESS_REQUEST_RESTART, result);
    if (result == 2) {
        result = 0;
    }
    return result;
}

#pragma thumb off

#pragma thumb on
u32 MBi_OnReset(void) {
    return MBi_CallReset();
}
#pragma thumb off

#pragma thumb on

// Starts a reset, on the worker when there is one; returns 1 when a reset is already under way.
u32 MBi_CommEnd(void) {
    u32 result;
    u32 savedInterrupts;
    result = 1;
    savedInterrupts = OS_DisableInterrupts();
    if (gWirelessWork->mResetting == 0) {
        result = 0;
        *(u32 *) ((u32) gWirelessWork + 0x5e4LL) = result;
        gWirelessWork->mResetting = 1;
        if (MBi_IsTaskAvailable() != 0) {
            MBi_EndTaskThread(MBi_OnReset);
        } else {
            result = MBi_CallReset();
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return result;
}

#pragma thumb off

#pragma thumb on

void MB_EndToIdle(void) {
    u32 savedInterrupts;
    savedInterrupts = ((s64) OS_DisableInterrupts());
    if (mbc->mIsStartedEx == 0) {
        OS_Terminate();
    }
    MBi_CommEnd();
    OS_RestoreInterrupts(savedInterrupts);
}

#pragma thumb off

#pragma thumb on

void MB_DisconnectChild(u32 childIndex) {
    u32 slot;
    u32 value;
    s32 entryIndex;
    u32 childBit;
    WM_Disconnect(MBi_ParentCallback, childIndex);
    if (childIndex != 0 && childIndex < 16) {
        slot = childIndex - 1;
        mbc->mChildversion[slot] = 0;
        MI_CpuFill8(mbc->mChildggid + slot, 0, 4);
        MI_CpuFill8(OFFSET_PTR(MBUserInfo, mbc->mChildUser, slot * 0x16), 0, sizeof(MBUserInfo));
        MBi_ClearParentPieceBuffer(childIndex);
        value = 0;
        mbc->mReq2child[slot] = value;
        entryIndex = mbc->mChildEntryIndex[slot];
        value = ~value;
        if (entryIndex != value) {
            childBit = 1 << childIndex;
            entryIndex = (u8) entryIndex;
            OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4)->mGameinfoChildBmp &= ~childBit;
            OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4)->mGameinfoChangedBmp |= childBit;
            mbc->mChildEntryIndex[childIndex - 1] = value;
            OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4)->mPollbmp &= ~childBit;
        }
        if (BIT_IS_SET(mbc->mChildEntryBmp, childIndex)) {
            mbc->mChildNum--;
            BIT_CLEAR(mbc->mChildEntryBmp, childIndex);
        }
        mbc->mPCommState[slot] = 0;
    }
}

#pragma thumb off

#pragma thumb on
void MBi_SetMaxScanTime(u32 maxChannelTime) {
    u32 maxChannelTimeCopy = maxChannelTime;
    u32 unusedValue;
    gScanParams.mMaxChannelTime = maxChannelTimeCopy;
}
#pragma thumb off

#pragma thumb on

s32 MBi_SetMPData(WirelessMessageCallback callback, void *data, s32 dataSize, u16 unusedValue, u16 childMask) {
    s32 result;
    result = WM_SetMPDataToPortEx(callback, NULL, data, dataSize, childMask, 1, 3);
    MBi_CheckWmErrcode(WIRELESS_REQUEST_QUEUE_EXCHANGE_DATA, result);
    return result;
}

int MBi_SendMP(void *data, u32 size, u32 childMask) {
    MBiParam *work;
    u32 value;
    s32 result;
    u16 sizeHalfword;
    u16 childMaskHalfword;
    sizeHalfword = size;
    childMaskHalfword = childMask;
    work = gWirelessWork;
    if (work->mMPStarted == 0 || work->mResetting == 1) {
        return 1;
    }
    switch (work->mMode) {
        case 1:
            if (work->mContSend == 0) {
                value = 0x3e8;
            } else {
                value = 0;
            }
            result = MBi_SetMPData(work->mCommandCallback, data, sizeHalfword, value, childMaskHalfword);
            if (result == 2) {
                gWirelessWork->mDataQueued = 1;
            }
            if (result == 2) {
                result = 0;
            }
            return result;
        case 2:
            result = MBi_SetMPData(MBi_ChildCallback, data, sizeHalfword, 0, childMaskHalfword);
            if (result == 2) {
                gWirelessWork->mDataQueued = 1;
            }
            if (result == 2) {
                result = 0;
            }
            return result;
        default:
            return 1;
    }
}

#pragma thumb off

#pragma thumb on

u32 MBi_GetGgid(void) {
    return gWirelessWork->mGgid;
}

u16 MBi_GetTgid(void) {
    return gWirelessWork->mTgid;
}

#pragma thumb off

#pragma thumb on

u8 MBi_GetAttribute(void) {
    MBiParam *work;
    u32 bit2;
    u32 bit1;
    u32 bit4;
    u32 bit8;
    work = gWirelessWork;
    if (work->mMultiBootFlag != 0) {
        bit2 = 2;
    } else {
        bit2 = 0;
    }
    if (work->mEntryFlag != 0) {
        bit1 = 1;
    } else {
        bit1 = 0;
    }
    if (work->mKsFlag != 0) {
        bit4 = 4;
    } else {
        bit4 = 0;
    }
    if (work->mCsFlag != 0) {
        bit8 = 8;
    } else {
        bit8 = 0;
    }
    return bit8 | (bit4 | (bit1 | bit2));
}

#pragma thumb off

#pragma thumb on

u32 MBi_IsStarted(void) {
    if (gWirelessWork->mMbIsStarted == 1) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void MBi_CheckWmErrcode(u16 command, s32 resultCode) {
    u16 report[2];
    if (resultCode != 2 && resultCode != 0) {
        report[0] = command;
        report[1] = resultCode;
        gWirelessWork->mCallback(0xff, (WirelessMessage *) report);
    }
}

#pragma thumb off
