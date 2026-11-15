#pragma once

#include "types.h"
#include "code_02142eac.h"
#include "code_0200f790.h"

// Result of a notification: WcmNotify and WcmNotifyEx take it, WCMNotice.mResult holds it.
typedef enum WifiReportResult {
    WIFI_REPORT_SUCCEEDED = 0,
    WIFI_REPORT_DECLINED = 1,
    WIFI_REPORT_UNRECOVERABLE = 7
} WifiReportResult;

// Values of WCMWork.mNotifyId: the request whose answer is reported next (named by the wireless call that starts it).
// WcmNotify sends it and clears it.
// SEARCH_FOUND and SCAN_ROUND are also sent on their own while searching.
enum {
    WIFI_NOTIFY_NONE = 0,
    WIFI_NOTIFY_ENABLE_REQUEST = 1,
    WIFI_NOTIFY_POWER_OFF_REQUEST = 2,
    WIFI_NOTIFY_SCAN_START_REQUEST = 3,
    WIFI_NOTIFY_SCAN_STOP_REQUEST = 4,
    WIFI_NOTIFY_CONNECT_REQUEST = 5,
    WIFI_NOTIFY_DISCONNECT_REQUEST = 6,
    WIFI_NOTIFY_SEARCH_FOUND = 7,
    WIFI_NOTIFY_SCAN_ROUND = 8,
    WIFI_NOTIFY_LINK_TERMINATING = 9,
};

// Event the function at mNotify is called with; built by WcmNotifyEx.
typedef struct WCMNotice {
    /* 00 */ u16 mNotify;
    /* 02 */ u16 mResult;
    /* 04 */ void *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} WCMNotice;

// 0xd0 bytes. Entry of the list at mPbdBuffer of an WCMWork.
typedef struct WCMApList {
    /* 00 */ u8 mState;
    /* 02 */ u16 mLinkLevel;
    /* 04 */ u32 mIndex;
    /* 08 */ struct WCMApList *mPrevious;
    /* 0c */ struct WCMApList *mNext;
    /* 10 */ u8 mData[0xc0];
} WCMApList;

// Header of the list at mPbdBuffer of an WCMWork: count, first and last entry, then the entries.
typedef struct WCMApListHeader {
    /* 00 */ u32 mCount;
    /* 04 */ WCMApList *mHead;
    /* 08 */ WCMApList *mTail;
    /* 0c */ WCMApList mBlocks[1];
} WCMApListHeader;

// Values of WCMWork.mPhase, which WCM_GetPhase returns (NONE before the work area is set up). Each Async call moves the
// phase to the pending one (STARTING, STOPPING, SEARCH_STARTING, SEARCH_STOPPING, CONNECTING, DISCONNECTING,
// TERMINATING) and its callback settles it. FAILED is final: WcmSetPhase no longer changes it. A refused request leaves
// ABORT_PENDING, where the running step ends by resetting.
enum {
    WIFI_LINK_PHASE_NONE = 0,
    WIFI_LINK_PHASE_STOPPED = 1,
    WIFI_LINK_PHASE_STARTING = 2,
    WIFI_LINK_PHASE_READY = 3,
    WIFI_LINK_PHASE_STOPPING = 4,
    WIFI_LINK_PHASE_SEARCH_STARTING = 5,
    WIFI_LINK_PHASE_SEARCHING = 6,
    WIFI_LINK_PHASE_SEARCH_STOPPING = 7,
    WIFI_LINK_PHASE_CONNECTING = 8,
    WIFI_LINK_PHASE_CONNECTED = 9,
    WIFI_LINK_PHASE_DISCONNECTING = 10,
    WIFI_LINK_PHASE_FAILED = 11,
    WIFI_LINK_PHASE_ABORT_PENDING = 12,
    WIFI_LINK_PHASE_TERMINATING = 13,
};

// 0x2300 bytes; the word gWcmWork points to it.
typedef struct WCMWork {
    /* 0000 */ u8 mWmWork[0xf00];
    /* 0f00 */ u8 mSendBuf[0x600];
    /* 1500 */ u8 mRecvBuf[0xc40];
    /* 2140 */ u8 mBssDesc[4];
    /* 2144 */ u8 mBssid[6];
    /* 214a */ u16 mSsidLength;
    /* 214c */ u8 mSsid[0x22];
    /* 216e */ u16 mBasicRateSet;
    /* 2170 */ u16 mSupportRateSet;
    /* 2172 */ u8 mUnk_2172[0x8e];
    /* 2200 */ u8 mWepKey[0x50];
    /* 2250 */ u8 mWepMode;
    /* 2251 */ u8 mWepKeyId;
    /* 2252 */ u8 mUnk_2252[0xe];
    // WIFI_LINK_PHASE_*
    /* 2260 */ s32 mPhase;
    /* 2264 */ u32 mOption;
    /* 2268 */ u16 mMaxScanTime;
    /* 226a */ u8 mApListLock;
    /* 226b */ u8 mResetting;
    /* 226c */ u32 mDmaNo;
    /* 2270 */ WCMApListHeader *mPbdBuffer;
    /* 2274 */ u32 mNbdBuffer;
    /* 2278 */ u32 mNbdMode;
    /* 227c */ void (*mNotify)(WCMNotice *);
    // WIFI_NOTIFY_*
    /* 2280 */ s16 mNotifyId;
    /* 2282 */ u16 mAuthId;
    /* 2284 */ s32 mScanCount;
    /* 2288 */ ScanExParam mScanExParam;
    /* 22c0 */ u8 mUnk_22c0[0xc];
    /* 22cc */ OSAlarm mKeepAliveAlarm;
    /* 22f8 */ u16 mWlStatusOnConnectFail;
    /* 22fa */ u8 mUnk_22fa[6];
} WCMWork;

typedef struct WMStartScanExCallback WMStartScanExCallback;

void WcmWmcbCommon(WirelessMessage *event);

u32 WcmCountBits(u32 bits);
u32 WcmCountLeadingZero(u32 value);
void WcmWmcbReset(WirelessMessage *event);
void WcmWmcbEndDCF(WirelessMessage *event);
void WcmWmcbStartDCF(WirelessMessage *event);
void WcmWmcbDisconnect(WirelessMessage *event);
void WcmWmcbConnect(WMStartScanExCallback *event);
void WcmWmcbEndScan(WirelessMessage *event);
void WcmWmcbScanEx(WMStartScanExCallback *event);
u32 WCM_GetPhase(void);
s32 WCM_DisconnectAsync(void);
s32 WCM_EndSearchAsync(void);
s32 WCM_CleanupAsync(void);

extern WCMWork *gWcmWork;
