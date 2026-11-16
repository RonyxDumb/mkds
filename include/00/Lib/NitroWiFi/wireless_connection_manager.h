#pragma once

#include "types.h"
#include "wireless_link_control.h"
#include "alarm_timer.h"

// Result of a notification: WcmNotify and WcmNotifyEx take it, WCMNotice.mResult holds it.
typedef enum WifiReportResult {
    WIFI_REPORT_SUCCEEDED = 0,
    WIFI_REPORT_DECLINED = 1,
    WIFI_REPORT_UNRECOVERABLE = 7
} WifiReportResult;

// Values of WCMWork.mNotifyId: the request whose answer is reported next, set by the Async call that starts it
// (WCM_StartupAsync, WCM_CleanupAsync, WCM_BeginSearchAsync, WCM_EndSearchAsync, WCM_ConnectAsync, WCM_DisconnectAsync,
// WCM_TerminateAsync). WcmNotify sends it and clears it. SEARCH_FOUND and SCAN_ROUND are also sent on their own while
// searching (SCAN_ROUND once per round, when the round-scan option is set).
enum {
    WIFI_NOTIFY_NONE = 0,
    WIFI_NOTIFY_STARTUP_REQUEST = 1,
    WIFI_NOTIFY_CLEANUP_REQUEST = 2,
    WIFI_NOTIFY_SCAN_START_REQUEST = 3,
    WIFI_NOTIFY_SCAN_STOP_REQUEST = 4,
    WIFI_NOTIFY_CONNECT_REQUEST = 5,
    WIFI_NOTIFY_DISCONNECT_REQUEST = 6,
    WIFI_NOTIFY_SEARCH_FOUND = 7,
    WIFI_NOTIFY_SCAN_ROUND = 8,
    WIFI_NOTIFY_TERMINATE_REQUEST = 9,
};

// Notice WcmNotifyEx builds and passes to the function at WCMWork.mNotify.
typedef struct WCMNotice {
    /* 00 */ u16 mNotify;
    /* 02 */ u16 mResult;
    /* 04 */ void *mParameter0;
    /* 08 */ u32 mParameter1;
    /* 0c */ u32 mParameter2;
} WCMNotice;

// One access point entry of the list of a WCMWork: state, link level, index, previous and next entries, and data.
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

// Value of the mode member of a WEP key that has no key; the other values are the AP_WEP_MODE_KEY_ lengths.
#define WCM_WEPMODE_NONE 0

// Bits of WCMWork.mOption and of the option argument of WCM_UpdateOption: a TEST bit in the argument replaces that
// setting, the FILTER bit next to it holds its value; channel bit n is channel n (no channel given selects channels 1,
// 7 and 13).
#define WIFI_LINK_OPTION_SETS_CHANNELS 0x00008000
#define WIFI_LINK_OPTION_CHANNEL_1 (WIFI_LINK_OPTION_SETS_CHANNELS | 0x00000002)
#define WIFI_LINK_OPTION_CHANNEL_7 (WIFI_LINK_OPTION_SETS_CHANNELS | 0x00000080)
#define WIFI_LINK_OPTION_CHANNEL_13 (WIFI_LINK_OPTION_SETS_CHANNELS | 0x00002000)
#define WIFI_LINK_OPTION_CHANNELS_1_7_13 (WIFI_LINK_OPTION_CHANNEL_1 | WIFI_LINK_OPTION_CHANNEL_7 | WIFI_LINK_OPTION_CHANNEL_13)
#define WIFI_LINK_OPTION_SETS_POWER 0x00020000
#define WIFI_LINK_OPTION_POWER_SAVE_OFF_BIT 0x00010000
#define WIFI_LINK_OPTION_POWER_SAVE_OFF (WIFI_LINK_OPTION_SETS_POWER | WIFI_LINK_OPTION_POWER_SAVE_OFF_BIT)
#define WIFI_LINK_OPTION_POWER_SAVE_ON (WIFI_LINK_OPTION_SETS_POWER | 0x00000000)
#define WIFI_LINK_OPTION_SETS_AUTH 0x00080000
#define WIFI_LINK_OPTION_AUTH_SHARED_KEY_BIT 0x00040000
#define WIFI_LINK_OPTION_AUTH_SHARED_KEY (WIFI_LINK_OPTION_SETS_AUTH | WIFI_LINK_OPTION_AUTH_SHARED_KEY_BIT)
#define WIFI_LINK_OPTION_AUTH_NOT_SHARED_KEY (WIFI_LINK_OPTION_SETS_AUTH | 0x00000000)
#define WIFI_LINK_OPTION_SETS_SCAN_TYPE 0x00200000
#define WIFI_LINK_OPTION_SCAN_TYPE_0_BIT 0x00100000
#define WIFI_LINK_OPTION_SCAN_TYPE_0 (WIFI_LINK_OPTION_SETS_SCAN_TYPE | WIFI_LINK_OPTION_SCAN_TYPE_0_BIT)
#define WIFI_LINK_OPTION_SCAN_TYPE_1 (WIFI_LINK_OPTION_SETS_SCAN_TYPE | 0x00000000)
#define WIFI_LINK_OPTION_SETS_SCAN_ROUND 0x00800000
#define WIFI_LINK_OPTION_SCAN_ROUND_NO_NOTICE (WIFI_LINK_OPTION_SETS_SCAN_ROUND | 0x00000000)

// Rates added to the support set of the access point when a connect fails with status 0x12; the connect is then tried
// once more.
#define WIFI_LINK_RETRY_RATE_SET 0x0024

// Values of WCMWork.mPhase, which WCM_GetPhase returns (NONE before the work area is set up). Each Async call moves the
// phase to the pending one (STARTING, STOPPING, SEARCH_STARTING, SEARCH_STOPPING, CONNECTING, DISCONNECTING,
// TERMINATING) and its callback settles it. FAILED is final: WcmSetPhase no longer changes it. A request the unit
// refuses in the common callback, a call that fails with the pipe error, or a fatal pipe event while connecting or
// disconnecting leaves ABORT_PENDING; the next callback of the running step then resets.
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

// The wireless connection manager state: WM work, buffers, BSS description, WEP key, phase, scan parameters and alarm.
typedef struct WCMWork {
    /* 0000 */ u8 mWmWork[0xf00];
    /* 0f00 */ u8 mSendBuf[0x600];
    /* 1500 */ u8 mRecvBuf[0xc40];
    /* 2140 */ WMBssDesc mBssDesc;
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
    /* 22cc */ OSAlarm mKeepAliveAlarm;
    /* 22f8 */ u16 mWlStatusOnConnectFail;
    /* 22fa */ u8 mUnk_22fa[6];
} WCMWork;

typedef struct WMStartConnectCallback {
    /* 00 */ u16 mApiId;
    /* 02 */ u16 mErrCode;
    /* 04 */ u16 mWlCmdID;
    /* 06 */ u16 mWlResult;
    /* 08 */ u16 mState;
    /* 0a */ u16 mAid;
    /* 0c */ u16 mReason;
    /* 0e */ u16 mWlStatus;
    /* 10 */ u8 mMacAddress[6];
    /* 16 */ u16 mParentSize;
    /* 18 */ u16 mChildSize;
} WMStartConnectCallback;

typedef struct WMStartScanExCallback WMStartScanExCallback;

void WcmWmcbCommon(WirelessMessage *event);

u32 WcmCountBits(u32 bits);
u32 WcmCountLeadingZero(u32 value);
void WcmWmcbReset(WirelessMessage *event);
void WcmWmcbEndDCF(WirelessMessage *event);
void WcmWmcbStartDCF(WirelessMessage *event);
void WcmWmcbDisconnect(WirelessMessage *event);
void WcmWmcbConnect(WMStartConnectCallback *event);
void WcmWmcbEndScan(WirelessMessage *event);
void WcmWmcbScanEx(WMStartScanExCallback *event);
u32 WCM_GetPhase(void);
s32 WCM_DisconnectAsync(void);
s32 WCM_EndSearchAsync(void);
s32 WCM_CleanupAsync(void);

extern WCMWork *gWcmWork;
