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
    /* 04 */ void *mParameter0;
    /* 08 */ u32 mParameter1;
    /* 0c */ u32 mParameter2;
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

// Values of the mode member of a WEP key: the key length in bits.
#define WCM_WEPMODE_NONE 0
#define WCM_WEPMODE_40 1
#define WCM_WEPMODE_104 2
#define WCM_WEPMODE_128 3

// Bits of WCMWork.mOption: TEST bits say a setting is made, the FILTER bit next to it gives its value (channel bits
// are numbered from channel 1).
#define WCM_OPTION_TEST_CHANNEL 0x00008000
#define WCM_OPTION_CHANNEL_1 (WCM_OPTION_TEST_CHANNEL | 0x00000002)
#define WCM_OPTION_CHANNEL_7 (WCM_OPTION_TEST_CHANNEL | 0x00000080)
#define WCM_OPTION_CHANNEL_13 (WCM_OPTION_TEST_CHANNEL | 0x00002000)
#define WCM_OPTION_CHANNEL_RDC (WCM_OPTION_CHANNEL_1 | WCM_OPTION_CHANNEL_7 | WCM_OPTION_CHANNEL_13)
#define WCM_OPTION_TEST_POWER 0x00020000
#define WCM_OPTION_FILTER_POWER 0x00010000
#define WCM_OPTION_MASK_POWER (WCM_OPTION_TEST_POWER | WCM_OPTION_FILTER_POWER)
#define WCM_OPTION_POWER_SAVE (WCM_OPTION_TEST_POWER | 0x00000000)
#define WCM_OPTION_TEST_AUTH 0x00080000
#define WCM_OPTION_FILTER_AUTH 0x00040000
#define WCM_OPTION_MASK_AUTH (WCM_OPTION_TEST_AUTH | WCM_OPTION_FILTER_AUTH)
#define WCM_OPTION_AUTH_OPENSYSTEM (WCM_OPTION_TEST_AUTH | 0x00000000)
#define WCM_OPTION_TEST_SCANTYPE 0x00200000
#define WCM_OPTION_FILTER_SCANTYPE 0x00100000
#define WCM_OPTION_MASK_SCANTYPE (WCM_OPTION_TEST_SCANTYPE | WCM_OPTION_FILTER_SCANTYPE)
#define WCM_OPTION_SCANTYPE_PASSIVE (WCM_OPTION_TEST_SCANTYPE | 0x00000000)
#define WCM_OPTION_TEST_ROUNDSCAN 0x00800000
#define WCM_OPTION_ROUNDSCAN_IGNORE (WCM_OPTION_TEST_ROUNDSCAN | 0x00000000)

// Rates that the connect adds to the support set of an access point it could not join.
#define WCM_CAMOUFLAGE_RATESET 0x0024

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
