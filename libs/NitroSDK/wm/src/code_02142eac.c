#include "code_02142eac.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "wm_system.h"
#include "os_thread.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "Main/Net/data_0216f000.h"
#include "mb_data.h"

u32 tgid_bak = 0x10000;

// Starts DCF reception into recvBuf (command 17). Needs state 8 and DCF not running; recvBufSize must be at least 0x10.
s32 WM_StartDCF(WirelessMessageCallback callback, void *recvBuf, u16 recvBufSize) {
    WMArm9Buf *work;
    s32 result;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_CHILD_CONNECTED);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&work->mStatusArea->mDcfFlag, 4);
    if (work->mStatusArea->mDcfFlag == 1) {
        return 3;
    }
    if (recvBufSize < 0x10) {
        return 6;
    }
    if (recvBuf == 0) {
        return 6;
    }
    DC_StoreRange(recvBuf, recvBufSize);
    WMi_SetCallbackTable(WIRELESS_REQUEST_BEGIN_FRAME_MODE, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_BEGIN_FRAME_MODE, 2, recvBuf, recvBufSize);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Sends sendDataSize bytes (at most 0x5e4) of sendData to the station destAdr (command 18). Needs state 11 and DCF
// running.
s32 WM_SetDCFData(WirelessMessageCallback callback, const void *destAdr, void *sendData, u16 sendDataSize) {
    WMArm9Buf *work;
    s32 result;
    u32 address[2];

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_CHILD_WITH_DCF);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&work->mStatusArea->mDcfFlag, 4);
    if (work->mStatusArea->mDcfFlag == 0) {
        return 3;
    }
    if (sendDataSize > 0x5e4) {
        return 6;
    }
    DC_StoreRange(sendData, sendDataSize);
    WMi_SetCallbackTable(WIRELESS_REQUEST_QUEUE_FRAME_DATA, callback);
    MI_CpuCopy8(destAdr, address, 6);
    result = WMi_SendCommand(WIRELESS_REQUEST_QUEUE_FRAME_DATA, 4, address[0], address[1], sendData, sendDataSize);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Ends DCF (command 19). Needs state 11 and DCF running.
s32 WM_EndDCF(WirelessMessageCallback callback) {
    WMArm9Buf *work;
    s32 result;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_CHILD_WITH_DCF);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&work->mStatusArea->mDcfFlag, 4);
    if (work->mStatusArea->mDcfFlag == 0) {
        return 3;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_STOP_FRAME_MODE, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_STOP_FRAME_MODE, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Starts the MP protocol (command 14). Needs state 7 or 8 and MP not running; the buffer sizes are checked against
// WM_GetMPReceiveBufferSize and WM_GetMPSendBufferSize.
s32 WM_StartMPEx(WirelessMessageCallback callback, void *recvBuf, u16 recvBufSize, void *sendBuf, u16 sendBufSize,
                 u16 mpFreq, u16 defaultRetryCount, BOOL minPollBmpMode, BOOL singlePacketMode, BOOL fixFreqMode,
                 BOOL ignoreFatalError) {
    WMArm9Buf *work;
    s32 result;
    s32 sendSize;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(2, WIRELESS_UNIT_STATE_PARENT_STARTED, WIRELESS_UNIT_STATE_CHILD_CONNECTED);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&work->mStatusArea->mOwnMemberIndex, 2);
    DC_InvalidateRange(&work->mStatusArea->mPwrMgtMode, 2);
    if (work->mStatusArea->mOwnMemberIndex != 0) {
        if (work->mStatusArea->mPwrMgtMode != 1) {
            return 3;
        }
    }
    DC_InvalidateRange(&work->mStatusArea->mMpFlag, 4);
    if (work->mStatusArea->mMpFlag == 1) {
        return 3;
    }
    if (recvBufSize < WM_GetMPReceiveBufferSize()) {
        return 6;
    }
    if ((recvBufSize & 0x3f) != 0) {
        return 6;
    }
    sendSize = sendBufSize;
    if (sendSize < WM_GetMPSendBufferSize()) {
        return 6;
    }
    if ((sendSize & 0x1f) != 0) {
        return 6;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_BEGIN_EXCHANGE, callback);
    result =
        WMi_SendCommand(WIRELESS_REQUEST_BEGIN_EXCHANGE, 10, recvBuf, (u32) recvBufSize >> 1, sendBuf, sendBufSize,
                        mpFreq, defaultRetryCount, minPollBmpMode, singlePacketMode, fixFreqMode, ignoreFatalError);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Sets the MP frequency (command 35). Needs state 9.
s32 WM_SetMPFrequency(WirelessMessageCallback callback, u32 mpFreq) {
    s32 result;

    WMi_GetSystemWork();
    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_PARENT_WITH_MP);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_SET_EXCHANGE_RATE, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_SET_EXCHANGE_RATE, 1, mpFreq);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Queues sendDataSize bytes of sendData for the stations in destBitmap on port with priority prio (command 15).
// Needs state 9 or 10; returns 7 when a parent has no child connected. callback is called with arg when it is sent.
s32 WM_SetMPDataToPortEx(UnkFunc *callback, void *arg, void *sendData, s32 sendDataSize, u16 destBitmap, u16 port,
                         u16 prio) {
    u16 limit;
    u32 children;
    WMStatus *status;
    s32 result;
    s32 parent;

    children = 1;
    status = WMi_GetSystemWork()->mStatusArea;
    result = WMi_CheckStateEx(2, WIRELESS_UNIT_STATE_PARENT_WITH_MP, WIRELESS_UNIT_STATE_CHILD_WITH_MP);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&status->mMpMaxSendSize, 2);
    limit = status->mMpMaxSendSize;
    DC_InvalidateRange(&status->mOwnMemberIndex, 2);
    parent = status->mOwnMemberIndex == 0 ? children : 0;
    if (parent == 1) {
        DC_InvalidateRange(&status->mConnectedChildren, 2);
        children = status->mConnectedChildren;
        DC_InvalidateRange(&status->mMpReadyBitmap, 2);
    }
    if (sendData == 0) {
        return 6;
    }
    if (children == 0) {
        return 7;
    }
    DC_InvalidateRange(&status->mMpSendBuf, 2);
    if (sendData == status->mMpSendBuf) {
        return 6;
    }
    if (sendDataSize + (parent != 0 ? 4 : 2) > limit) {
        return 6;
    }
    if (sendDataSize == 0) {
        return 6;
    }
    DC_StoreRange(sendData, sendDataSize);
    result = WMi_SendCommand(WIRELESS_REQUEST_QUEUE_EXCHANGE_DATA, 7, sendData, sendDataSize, destBitmap, port, prio,
                             callback, arg);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Ends the MP protocol (command 16). Needs state 9 or 10 and MP running.
s32 WM_EndMP(WirelessMessageCallback callback) {
    WMArm9Buf *work;
    s32 result;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(2, WIRELESS_UNIT_STATE_PARENT_WITH_MP, WIRELESS_UNIT_STATE_CHILD_WITH_MP);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&work->mStatusArea->mMpFlag, 4);
    if (work->mStatusArea->mMpFlag == 0) {
        return 3;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_STOP_EXCHANGE, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_STOP_EXCHANGE, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Enables the wireless hardware (command 3). Needs state 0.
s32 WM_Enable(WirelessMessageCallback callback) {
    WMArm9Buf *work;
    s32 result;

    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_DISABLED);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_ACTIVATE, callback);
    work = WMi_GetSystemWork();
    result = WMi_SendCommand(WIRELESS_REQUEST_ACTIVATE, 3, work->mWM7, work->mStatusArea, work->mMessageArea);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Disables the wireless hardware (command 4). Needs state 1.
s32 WM_Disable(WirelessMessageCallback callback) {
    s32 result;

    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_ENABLED);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_DEACTIVATE, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_DEACTIVATE, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Powers the wireless hardware on (command 5). Needs state 1.
s32 WM_PowerOn(WirelessMessageCallback callback) {
    s32 result;

    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_ENABLED);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_RADIO_ON, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_RADIO_ON, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Powers the wireless hardware off (command 6). Needs state 2.
s32 WM_PowerOff(WirelessMessageCallback callback) {
    s32 result;

    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_POWERED_ON);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_RADIO_OFF, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_RADIO_OFF, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Sets up the system buffer with WM_Init, then starts the wireless hardware (command 0).
s32 WM_Initialize(void *wmSysBuf, WirelessMessageCallback callback, u16 dmaNo) {
    WMArm9Buf *work;
    s32 result;

    result = WM_Init(wmSysBuf, dmaNo);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_POWER_UP_STACK, callback);
    work = WMi_GetSystemWork();
    result = WMi_SendCommand(WIRELESS_REQUEST_POWER_UP_STACK, 3, work->mWM7, work->mStatusArea, work->mMessageArea);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Resets the wireless state back to idle (command 1). Needs state 2 or later.
s32 WM_Reset(WirelessMessageCallback callback) {
    s32 result;

    result = WMi_CheckIdle();
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_RESTART, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_RESTART, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Shuts the wireless hardware down (command 2). Needs state 2.
s32 WM_End(WirelessMessageCallback callback) {
    s32 result;

    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_POWERED_ON);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_CLOSE_STACK, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_CLOSE_STACK, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Sets the parent parameters (command 7). Needs state 2; game info and beacon data sizes are limited to 0x200 bytes.
s32 WM_SetParentParameter(WirelessMessageCallback callback, ParentParameter *pparaBuf) {
    s32 result;

    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_POWERED_ON);
    if (result != 0) {
        return result;
    }
    if (pparaBuf == 0) {
        return 6;
    }
    if (pparaBuf->mUserGameInfoLength != 0) {
        if (pparaBuf->mUserGameInfo == 0) {
            return 6;
        }
    }
    if (pparaBuf->mParentMaxSize + (pparaBuf->mKsFlag != 0 ? 0x2a : 0) > 0x200 ||
        pparaBuf->mChildMaxSize + (pparaBuf->mKsFlag != 0 ? 6 : 0) > 0x200) {
        return 6;
    }
    WmCheckParentParameter(pparaBuf);
    WMi_SetCallbackTable(WIRELESS_REQUEST_CONFIGURE_HOST, callback);
    DC_StoreRange(pparaBuf, 0x40);
    if (pparaBuf->mUserGameInfoLength != 0) {
        DC_StoreRange(pparaBuf->mUserGameInfo, pparaBuf->mUserGameInfoLength);
    }
    result = WMi_SendCommand(WIRELESS_REQUEST_CONFIGURE_HOST, 1, pparaBuf);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Returns 1 when the game info length, beacon period and channel of param are in range, otherwise 0.
u32 WmCheckParentParameter(const ParentParameter *param) {
    if (param->mUserGameInfoLength > 0x70) {
        return 0;
    }
    if (param->mBeaconPeriod < 10 || param->mBeaconPeriod > 0x3e8) {
        return 0;
    }
    if (param->mChannel < 1 || param->mChannel > 0xe) {
        return 0;
    }
    return 1;
}

// Starts the parent (command 8). Needs state 2.
s32 WMi_StartParentEx(WirelessMessageCallback callback, BOOL powerSave) {
    s32 result;

    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_POWERED_ON);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_OPEN_HOST, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_OPEN_HOST, 1, powerSave);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Starts the parent with power save on.
s32 WM_StartParent(WirelessMessageCallback callback) {
    return WMi_StartParentEx(callback, 1);
}

// Ends the parent (command 9). Needs state 7.
s32 WM_EndParent(WirelessMessageCallback callback) {
    s32 result;

    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_PARENT_STARTED);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_CLOSE_HOST, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_CLOSE_HOST, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Starts a scan (command 10). Needs state 2, 3 or 5; the channel must be 1 to 14.
s32 WM_StartScan(WirelessMessageCallback callback, ScanParam *param) {
    StartScanRequest *request;
    s32 result;

    result = WMi_CheckStateEx(3, WIRELESS_UNIT_STATE_POWERED_ON, WIRELESS_UNIT_STATE_SCAN_START_EXTRA,
                              WIRELESS_UNIT_STATE_SCANNING);
    if (result != 0) {
        return result;
    }
    if (param == 0) {
        return 6;
    }
    if (param->mScanBuf == 0) {
        return 6;
    }
    if (param->mChannel < 1 || param->mChannel > 0xe) {
        return 6;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_BEGIN_SEARCH, callback);
    request = WMi_GetSystemWork()->mRequestArea;
    request->mApiid = WIRELESS_REQUEST_BEGIN_SEARCH;
    request->mChannel = param->mChannel;
    request->mScanBuf = param->mScanBuf;
    request->mMaxChannelTime = param->mMaxChannelTime;
    request->mBssid[0] = param->mBssid[0];
    request->mBssid[1] = param->mBssid[1];
    request->mBssid[2] = param->mBssid[2];
    request->mBssid[3] = param->mBssid[3];
    request->mBssid[4] = param->mBssid[4];
    request->mBssid[5] = param->mBssid[5];
    result = WMi_SendCommand(WIRELESS_REQUEST_BEGIN_SEARCH, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Starts a scan with a scan type and SSID (command 38). Needs state 2, 3 or 5.
s32 WM_StartScanEx(WirelessMessageCallback callback, ScanExParam *param) {
    StartScanExRequest *request;
    s32 result;
    u16 scanType;

    result = WMi_CheckStateEx(3, WIRELESS_UNIT_STATE_POWERED_ON, WIRELESS_UNIT_STATE_SCAN_START_EXTRA,
                              WIRELESS_UNIT_STATE_SCANNING);
    if (result != 0) {
        return result;
    }
    if (param == 0) {
        return 6;
    }
    if (param->mScanBuf == 0) {
        return 6;
    }
    if (param->mScanBufSize > 0x400) {
        return 6;
    }
    if (param->mSsidLength > 0x20) {
        return 6;
    }
    scanType = param->mScanType;
    if (scanType != 0 && scanType != 1 && scanType != 2 && scanType != 3) {
        return 6;
    }
    if ((u16) (scanType + 0xfffe) <= 1) {
        if (param->mSsidMatchLength > 0x20) {
            return 6;
        }
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_BEGIN_SEARCH_CHANNELS, callback);
    request = WMi_GetSystemWork()->mRequestArea;
    request->mApiid = WIRELESS_REQUEST_BEGIN_SEARCH_CHANNELS;
    request->mChannelList = param->mChannelList;
    request->mScanBuf = param->mScanBuf;
    request->mScanBufSize = param->mScanBufSize;
    request->mMaxChannelTime = param->mMaxChannelTime;
    MI_CpuCopy8(param->mBssid, request->mBssid, 6);
    request->mScanType = param->mScanType;
    request->mSsidMatchLength = param->mSsidMatchLength;
    request->mSsidLength = param->mSsidLength;
    MI_CpuCopy8(param->mSsid, request->mSsid, 0x20);
    result = WMi_SendCommand(WIRELESS_REQUEST_BEGIN_SEARCH_CHANNELS, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Ends the scan (command 11). Needs state 5.
s32 WM_EndScan(WirelessMessageCallback callback) {
    s32 result;

    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_SCANNING);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_STOP_SEARCH, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_STOP_SEARCH, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Connects to the parent described by pInfo (command 12). Needs state 2.
s32 WM_StartConnectEx(WirelessMessageCallback callback, u16 *pInfo, void *ssid, BOOL powerSave, u16 authMode) {
    StartConnectExRequest *request;
    s32 result;

    result = WMi_CheckStateEx(1, WIRELESS_UNIT_STATE_POWERED_ON);
    if (result != 0) {
        return result;
    }
    if (pInfo == 0) {
        return 6;
    }
    DC_StoreRange(pInfo, pInfo[0] * 2);
    WMi_SetCallbackTable(WIRELESS_REQUEST_ENTER_HOST, callback);
    request = WMi_GetSystemWork()->mRequestArea;
    request->mApiid = WIRELESS_REQUEST_ENTER_HOST;
    request->mPInfo = pInfo;
    if (ssid != 0) {
        MI_CpuCopy8(ssid, request->mSsid, 0x18);
    } else {
        MI_CpuFill8(request->mSsid, 0, 0x18);
    }
    request->mPowerSave = powerSave;
    request->mAuthMode = authMode;
    result = WMi_SendCommand(WIRELESS_REQUEST_ENTER_HOST, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Disconnects the station aid (command 13): a child from a parent, or the parent itself when aid is 0 on a child.
s32 WM_Disconnect(WirelessMessageCallback callback, u32 aid) {
    WMArm9Buf *work;
    s32 result;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(5, WIRELESS_UNIT_STATE_PARENT_STARTED, WIRELESS_UNIT_STATE_PARENT_WITH_MP,
                              WIRELESS_UNIT_STATE_CHILD_CONNECTED, WIRELESS_UNIT_STATE_CHILD_WITH_MP,
                              WIRELESS_UNIT_STATE_CHILD_WITH_DCF);
    if (result != 0) {
        return result;
    }
    if (work->mStatusArea->mState == WIRELESS_UNIT_STATE_PARENT_STARTED ||
        work->mStatusArea->mState == WIRELESS_UNIT_STATE_PARENT_WITH_MP) {
        if (aid < 1 || aid > 0xf) {
            return 6;
        }
        DC_InvalidateRange(&work->mStatusArea->mConnectedChildren, 2);
        if ((work->mStatusArea->mConnectedChildren & (1 << aid)) == 0) {
            return 7;
        }
    } else if (aid != 0) {
        return 6;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_LEAVE, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_LEAVE, 1, 1 << aid);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Disconnects the children in aidBitmap (command 13). Needs state 7 or 9; returns 7 when none of them is connected.
s32 WM_DisconnectChildren(WirelessMessageCallback callback, u32 aidBitmap) {
    WMArm9Buf *work;
    s32 result;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(2, WIRELESS_UNIT_STATE_PARENT_STARTED, WIRELESS_UNIT_STATE_PARENT_WITH_MP);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&work->mStatusArea->mConnectedChildren, 2);
    if ((work->mStatusArea->mConnectedChildren & aidBitmap & 0xfffe) == 0) {
        return 7;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_LEAVE, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_LEAVE, 1, aidBitmap);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Sets the callback for indications.
s32 WM_SetIndCallback(WirelessMessageCallback callback) {
    u32 enabled;
    s32 result;

    enabled = OS_DisableInterrupts();
    result = WMi_CheckInitialized();
    if (result != 0) {
        OS_RestoreInterrupts(enabled);
        return result;
    }
    WMi_GetSystemWork()->mIndicationCallback = callback;
    OS_RestoreInterrupts(enabled);
    return 0;
}

// Sets the callback and argument for data received on port (stored in WMArm9Buf.mPortCallbacks and
// WMArm9Buf.mPortCallbackArgs).
s32 WM_SetPortCallback(u16 port, UnkFunc *callback, void *arg) {
    u32 enabled;
    s32 result;
    WMArm9Buf *work;

    enabled = OS_DisableInterrupts();
    result = WMi_CheckInitialized();
    if (result != 0) {
        OS_RestoreInterrupts(enabled);
        return result;
    }
    work = WMi_GetSystemWork();
    work->mPortCallbacks[port] = callback;
    work->mPortCallbackArgs[port] = arg;
    OS_RestoreInterrupts(enabled);
    return 0;
}

// Copies the status area into statusBuf.
s32 WM_ReadStatus(void *statusBuf) {
    WMArm9Buf *work;
    s32 result;

    work = WMi_GetSystemWork();
    result = WMi_CheckInitialized();
    if (result != 0) {
        return result;
    }
    if (statusBuf == 0) {
        return 6;
    }
    DC_InvalidateRange(work->mStatusArea, 0x7bc);
    MIi_CpuCopyFast(work->mStatusArea, statusBuf, 0x7bc);
    return 0;
}

// Returns the send buffer size WM_StartMPEx needs, or 0 when the state does not allow it.
s32 WM_GetMPSendBufferSize(void) {
    WMArm9Buf *work;

    work = WMi_GetSystemWork();
    if (WMi_CheckStateEx(2, WIRELESS_UNIT_STATE_PARENT_STARTED, WIRELESS_UNIT_STATE_CHILD_CONNECTED) != 0) {
        return 0;
    }
    DC_InvalidateRange(&work->mStatusArea->mMpFlag, 4);
    if (work->mStatusArea->mMpFlag == 1) {
        return 0;
    }
    DC_InvalidateRange(&work->mStatusArea->mMpMaxSendSize, 4);
    return (work->mStatusArea->mMpMaxSendSize + 0x1f) & ~0x1f;
}

// Returns the receive buffer size WM_StartMPEx needs, or 0 when the state does not allow it.
s32 WM_GetMPReceiveBufferSize(void) {
    WMArm9Buf *work;
    s32 isHost;
    u16 maxRecvSize;

    work = WMi_GetSystemWork();
    if (WMi_CheckStateEx(2, WIRELESS_UNIT_STATE_PARENT_STARTED, WIRELESS_UNIT_STATE_CHILD_CONNECTED) != 0) {
        return 0;
    }
    DC_InvalidateRange(&work->mStatusArea->mMpFlag, 4);
    if (work->mStatusArea->mMpFlag == 1) {
        return 0;
    }
    DC_InvalidateRange(&work->mStatusArea->mOwnMemberIndex, 2);
    if (work->mStatusArea->mOwnMemberIndex == 0) {
        isHost = 1;
    } else {
        isHost = 0;
    }
    DC_InvalidateRange(&work->mStatusArea->mMpMaxRecvSize, 2);
    maxRecvSize = work->mStatusArea->mMpMaxRecvSize;
    if (isHost != 1) {
        return ((maxRecvSize + 0x51) & ~0x1f) << 1;
    }
    DC_InvalidateRange(&work->mStatusArea->mMaxEntry, 2);
    return (((maxRecvSize + 0xc) * work->mStatusArea->mMaxEntry + 0x29) & ~0x1f) << 1;
}

// Returns the record of station aid in the MP receive data header, or NULL when there is none.
void *WM_ReadMPData(const WMMpRecvHeader *header, u16 aid) {
    WMArm9Buf *work;
    u32 records[16];
    s32 recordIndex;

    work = WMi_GetSystemWork();
    if (WMi_CheckInitialized() != 0) {
        return 0;
    }
    if (aid < 1 || aid > 0xf) {
        return 0;
    }
    DC_InvalidateRange(&work->mStatusArea->mConnectedChildren, 2);
    if ((work->mStatusArea->mConnectedChildren & (1 << aid)) == 0) {
        return 0;
    }
    if (header->mCount == 0) {
        return 0;
    }
    records[0] = (u32) header->mData;
    recordIndex = 0;
    do {
        if (aid == *(u16 *) (records[recordIndex] + 4)) {
            return (void *) records[recordIndex];
        }
        recordIndex++;
        records[recordIndex] = header->mLength + records[recordIndex - 1];
    } while (recordIndex < header->mCount);
    return 0;
}

// Returns the bitmap of allowed channels, or 0x8000 when the library is not set up.
u16 WM_GetAllowedChannel(void) {
    if (WMi_CheckInitialized() != 0) {
        return 0x8000;
    }
    return SYSTEM_WORK->mNvramUserInfo.mAllowedChannel;
}

// Returns the signal strength of the link, 0 when there is no link.
u16 WM_GetLinkLevel(void) {
    WMArm9Buf *work;

    work = WMi_GetSystemWork();
    if (WMi_CheckInitialized() != 0) {
        return 0;
    }
    DC_InvalidateRange(work->mStatusArea, 2);
    switch (work->mStatusArea->mState) {
        case WIRELESS_UNIT_STATE_PARENT_WITH_MP:
            DC_InvalidateRange(&work->mStatusArea->mConnectedChildren, 2);
            if (work->mStatusArea->mConnectedChildren == 0) {
                return 0;
            }
        case WIRELESS_UNIT_STATE_CHILD_WITH_MP:
        case WIRELESS_UNIT_STATE_CHILD_WITH_DCF:
            DC_InvalidateRange(&work->mStatusArea->mLinkLevel, 2);
            return work->mStatusArea->mLinkLevel;
        default:
            return 0;
    }
}

// Returns a beacon period from 200 that depends on the MAC address and the system work value at 0x027ffc3c.
u16 WM_GetDispersionBeaconPeriod(void) {
    u8 address[6];
    s32 index;
    u16 sum;

    OS_GetMacAddress(address);
    for (index = 0, sum = 0; index < 6; index++) {
        sum = sum + address[index];
    }
    sum = sum + SYSTEM_WORK->mVblankCount;
    sum = sum * 7;
    return sum % 20 + 200;
}

// Returns a scan period from 30 that depends on the MAC address and the system work value at 0x027ffc3c.
u16 WM_GetDispersionScanPeriod(void) {
    u8 address[6];
    s32 index;
    u16 sum;

    OS_GetMacAddress(address);
    for (index = 0, sum = 0; index < 6; index++) {
        sum = sum + address[index];
    }
    sum = sum + SYSTEM_WORK->mVblankCount;
    sum = sum * 13;
    return sum % 10 + 30;
}

// Collects the extra information elements that follow the game info of a scanned parent.
WMOtherElements WM_GetOtherElements(const u16 *bssDesc) {
    WMOtherElements elements;
    const u8 *body;
    s32 elementIndex;
    u8 bodyLength;
    u8 total;
    u8 size;

    if (bssDesc[0x1e] != 0) {
        elements.mCount = 0;
        return elements;
    }
    elements.mCount = bssDesc[0x1f];
    if (elements.mCount == 0) {
        return elements;
    }
    if (elements.mCount > 0x10) {
        elements.mCount = 0x10;
    }
    body = (const u8 *) bssDesc + 0x40;
    bodyLength = bssDesc[0] * 2 - 0x40;
    total = 0;
    for (elementIndex = 0; elementIndex < elements.mCount; elementIndex++) {
        elements.mElement[elementIndex].mId = body[0];
        elements.mElement[elementIndex].mLength = body[1];
        elements.mElement[elementIndex].mBody = body + 2;
        size = elements.mElement[elementIndex].mLength + 2;
        total = total + size;
        if (total > bodyLength) {
            elements.mCount = 0;
            return elements;
        }
        body = body + size;
    }
    return elements;
}

// Returns the next TGID, starting from the RTC time the first time.
u16 WM_GetNextTgid(void) {
    RTCTime time;

    if (tgid_bak == 0x10000) {
        RTC_Init();
        if (RTC_GetTime(&time) == 0) {
            tgid_bak = (u16) (time.mSecond + (time.mMinute << 8));
        }
    }
    tgid_bak = (u16) (tgid_bak + 1);
    return tgid_bak;
}
