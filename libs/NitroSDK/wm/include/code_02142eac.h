#pragma once

#include "types.h"

typedef struct WMDataSharingInfo WMDataSharingInfo;

typedef struct WirelessMessage WirelessMessage;

// Values of WirelessMessage.mCommand: the request the message answers, or one of the messages the other processor sends
// on its own (the last three). Bit 15 of the member marks a ring message as free (WIRELESS_FREE_FLAG).
typedef enum WirelessRequest {
    WIRELESS_REQUEST_POWER_UP_STACK = 0,
    WIRELESS_REQUEST_RESTART = 1,
    WIRELESS_REQUEST_CLOSE_STACK = 2,
    WIRELESS_REQUEST_ACTIVATE = 3,
    WIRELESS_REQUEST_DEACTIVATE = 4,
    WIRELESS_REQUEST_RADIO_ON = 5,
    WIRELESS_REQUEST_RADIO_OFF = 6,
    WIRELESS_REQUEST_CONFIGURE_HOST = 7,
    WIRELESS_REQUEST_OPEN_HOST = 8,
    WIRELESS_REQUEST_CLOSE_HOST = 9,
    WIRELESS_REQUEST_BEGIN_SEARCH = 10,
    WIRELESS_REQUEST_STOP_SEARCH = 11,
    WIRELESS_REQUEST_ENTER_HOST = 12,
    WIRELESS_REQUEST_LEAVE = 13,
    WIRELESS_REQUEST_BEGIN_EXCHANGE = 14,
    WIRELESS_REQUEST_QUEUE_EXCHANGE_DATA = 15,
    WIRELESS_REQUEST_STOP_EXCHANGE = 16,
    WIRELESS_REQUEST_BEGIN_FRAME_MODE = 17,
    WIRELESS_REQUEST_QUEUE_FRAME_DATA = 18,
    WIRELESS_REQUEST_STOP_FRAME_MODE = 19,
    WIRELESS_REQUEST_SET_BASIC_CIPHER_KEY = 20,
    WIRELESS_REQUEST_BEGIN_KEY_SHARE = 21,
    WIRELESS_REQUEST_STOP_KEY_SHARE = 22,
    WIRELESS_REQUEST_SET_HOST_ADVERT = 24,
    WIRELESS_REQUEST_WATCH_BEACONS = 25,
    WIRELESS_REQUEST_SET_TIMEOUT = 29,
    WIRELESS_REQUEST_MEASURE_CHANNEL = 30,
    WIRELESS_REQUEST_SET_JOIN_ALLOWED = 33,
    WIRELESS_REQUEST_SET_EXCHANGE_RATE = 35,
    WIRELESS_REQUEST_BEGIN_SEARCH_CHANNELS = 38,
    WIRELESS_REQUEST_SET_CIPHER_KEY = 39,
    WIRELESS_REQUEST_KIND_COUNT = 42,
    WIRELESS_REQUEST_EVENT_REPORT = 0x80,
    WIRELESS_REQUEST_PORT_SENT = 0x81,
    WIRELESS_REQUEST_PORT_DATA = 0x82
} WirelessRequest;

#define WIRELESS_FREE_FLAG 0x8000

// Values of WirelessMessage.mResultCode, the answer of the other processor to a command.
typedef enum WirelessResult {
    WIRELESS_RESULT_SUCCEEDED = 0,
    WIRELESS_RESULT_REFUSED = 1,
    WIRELESS_RESULT_OCCUPIED = 2,
    WIRELESS_RESULT_BAD_PHASE = 3,
    WIRELESS_RESULT_SWITCHED_OFF = 4,
    WIRELESS_RESULT_NOT_SET_UP = 5,
    WIRELESS_RESULT_BAD_INPUT = 6,
    WIRELESS_RESULT_NO_REMOTE = 7,
    WIRELESS_RESULT_PIPE_ERROR = 8,
    WIRELESS_RESULT_NO_ANSWER = 9,
    WIRELESS_RESULT_SEND_BACKLOG = 10,
    WIRELESS_RESULT_EMPTY_STATION_MASK = 13,
    WIRELESS_RESULT_NOT_LISTED = 11,
    WIRELESS_RESULT_LIST_FULL = 12,
    WIRELESS_RESULT_TRANSMIT_ERROR = 15,
    WIRELESS_RESULT_STORAGE_ERROR = 19
} WirelessResult;

// Result of a WM_ call that only queues the request: the result then arrives in the callback.
#define WIRELESS_CALL_QUEUED 2

typedef void (*WirelessMessageCallback)(WirelessMessage *);

// Called with the message of the port; each user reads it through its own view (data sharing, ROM archive, MP link).
typedef void (*WirelessPortCallback)(void *portMessage);
// Callback of a port send, unprototyped for the same reason.
typedef void (*WirelessSendCallback)();

// 0x2c bytes from 0x36 of UserGameDetails.
typedef struct UserGameNameBlock {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u8 mName[0x14];
    /* 16 */ u8 mUnk_16[0x16];
} UserGameNameBlock;

// 0x62 bytes from 0xe of UserGameInfo.
typedef struct UserGameDetails {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ union {
        u8 mUnk_06;
        struct {
            u8 mChildCount : 4;
            u8 mLanguageIndex : 4;
        };
    };
    /* 07 */ union {
        u8 mUnk_07;
        struct {
            u8 mHasGhost : 1;
            u8 mKartIndex : 6;
        };
    };
    /* 08 */ u8 mUnk_08[2];
    /* 0a */ u8 mUnk_0a[4];
    /* 0e */ u8 mUnk_0e[0x28];
    /* 36 */ UserGameNameBlock mNameInfo;
} UserGameDetails;

// 0x70 bytes at 0x50 of WMBssDesc; the word at 0x38 of ChildList points to one.
typedef struct UserGameInfo {
    union {
        struct {
            /* 00 */ u8 mUnk_00[7];
            /* 07 */ u8 mKind;
            /* 08 */ u8 mUnk_08[2];
            /* 0a */ u8 mMemberCount;
            /* 0b */ u8 mUnk_0b[3];
            /* 0e */ UserGameDetails mGameInfoPart;
        };
        struct {
            /* 00 */ u8 mUnk_00_pad[0x18];
            /* 18 */ union {
                u32 mUnk_18;
                struct {
                    u32 mCharacterIndex : 4;
                    u32 mCupCourseIndex : 5;
                    u32 mMinute : 7;
                    u32 mSecond : 6;
                    u32 mMillisecond : 10;
                };
            };
            /* 1c */ u8 mUnk_1c[0x54];
        };
    };
} UserGameInfo;

typedef struct WMGameInfo {
    /* 00 */ u16 mMagicNumber;
    /* 02 */ u8 mVer;
    /* 03 */ u8 mPlatform;
    /* 04 */ u32 mGgid;
    /* 08 */ u16 mTgid;
    /* 0a */ u8 mUserGameInfoLength;
    /* 0b */ u8 mAttribute;
    /* 0c */ u16 mParentMaxSize;
    /* 0e */ u16 mChildMaxSize;
    /* 10 */ UserGameInfo mUserGameInfo;
} WMGameInfo;

// 0xc0 bytes. MB_ReadMultiBootParentBssDesc and MB_FakeReadParentBssDesc fill it. Also the buffer behind member 0x24
// of ConnectionWork and the first 0xc0 bytes of each ScanSlot.
typedef struct WMBssDesc {
    /* 00 */ u16 mLength;
    /* 02 */ u16 mRssi;
    /* 04 */ u8 mBssid[6];
    /* 0a */ u16 mSsidLength;
    /* 0c */ union {
        u8 mSsid[32];
        u16 mSsidHalfwords[16];
    };
    /* 2c */ u16 mCapaInfo;
    /* 2e */ struct {
        u16 mBasic;
        u16 mSupport;
    } mRateSet;
    /* 32 */ u16 mBeaconPeriod;
    /* 34 */ u16 mDtimPeriod;
    /* 36 */ u16 mChannel;
    /* 38 */ u16 mCfpPeriod;
    /* 3a */ u16 mCfpMaxDuration;
    /* 3c */ u16 mGameInfoLength;
    /* 3e */ u16 mOtherElementCount;
    /* 40 */ WMGameInfo mGameInfo;
} WMBssDesc;

// System work area set up by WmInitCore. The callback tables are indexed by the command number of the message that
// WmReceiveFifo takes.
// Bytes of the system buffer that the WMArm9Buf occupies; the arm7 area follows.
#define WM_ARM9_BUF_SIZE 0x200

typedef struct WMArm9Buf {
    /* 000 */ void *mWM7;
    /* 004 */ struct WMStatus *mStatusArea;
    /* 008 */ u32 mIndBuf;
    // Command request area; the command functions fill it in and WMi_SendCommand copies it for a command with no words.
    /* 00c */ void *mRequestArea;
    // Message area for replies; WmReceiveFifo does not mark it free after handling.
    /* 010 */ WirelessMessage *mMessageArea;
    /* 014 */ u16 mDmaNo;
    /* 016 */ u16 mScanOnlyFlag;
    /* 018 */ WirelessMessageCallback mCommandCallbacks[0x2a];
    /* 0c0 */ WirelessMessageCallback mIndicationCallback;
    /* 0c4 */ WirelessPortCallback mPortCallbacks[16];
    /* 104 */ void *mPortCallbackArgs[16];
} WMArm9Buf;

// Values of WMStatus.mState, which WMi_CheckStateEx compares: the wireless unit is off, enabled, powered on, scanning,
// running as a parent or child, and as a parent or child exchanging MP data or (child) DCF data. SCAN_START_EXTRA is
// only an extra state in which a scan may start.
enum {
    WIRELESS_UNIT_STATE_DISABLED = 0,
    WIRELESS_UNIT_STATE_ENABLED = 1,
    WIRELESS_UNIT_STATE_POWERED_ON = 2,
    WIRELESS_UNIT_STATE_SCAN_START_EXTRA = 3,
    WIRELESS_UNIT_STATE_SCANNING = 5,
    WIRELESS_UNIT_STATE_PARENT_STARTED = 7,
    WIRELESS_UNIT_STATE_CHILD_CONNECTED = 8,
    WIRELESS_UNIT_STATE_PARENT_WITH_MP = 9,
    WIRELESS_UNIT_STATE_CHILD_WITH_MP = 10,
    WIRELESS_UNIT_STATE_CHILD_WITH_DCF = 11,
};

// Wireless status area written by the other processor; WM_ReadStatus copies 0x7bc bytes of it.
typedef struct WMStatus {
    /* 000 */ u16 mState;
    /* 002 */ u8 mBusyApiid[2];
    /* 004 */ void *mUnk_004;
    /* 008 */ u8 mScanContinue[4];
    /* 00c */ u32 mMpFlag;
    /* 010 */ u32 mDcfFlag;
    /* 014 */ u8 mUnk_014[0x32];
    /* 046 */ u16 mMpRecvBufSize;
    /* 048 */ u8 mMpRecvBuf[8];
    /* 050 */ void *mMpSendBuf;
    /* 054 */ u8 mUnk_054[0x32];
    /* 086 */ u16 mMpReadyBitmap;
    /* 088 */ u8 mUnk_088[0x30];
    /* 0b8 */ u16 mLinkLevel;
    /* 0ba */ u8 mUnk_0ba[8];
    /* 0c2 */ u16 mPwrMgtMode;
    /* 0c4 */ u8 mUnk_0c4[0x30];
    /* 0f4 */ u16 mMaxEntry;
    /* 0f6 */ u8 mUnk_0f6[0x88];
    // Bit n is set while child n is connected.
    /* 17e */ u16 mConnectedChildren;
    /* 180 */ u8 mUnk_180[4];
    // This station's number: 0 for the parent.
    /* 184 */ u16 mOwnMemberIndex;
    /* 186 */ u8 mUnk_186[8];
    /* 18e */ u16 mMpMaxSendSize;
    /* 190 */ u16 mMpMaxRecvSize;
    /* 192 */ u8 mUnk_192[0x62a];
} WMStatus;

// Values of WirelessMessage.mReplyState / mState that the scan, connect, MP and multiboot callbacks tell apart.
typedef enum WirelessState {
    WIRELESS_STATE_SESSION_START = 0x0,
    WIRELESS_STATE_NEVER_HANDLED = 0x1,
    WIRELESS_STATE_FORWARD_UNLESS_RESETTING = 0x2,
    WIRELESS_STATE_SEARCH_NO_ACTION = 0x3,
    WIRELESS_STATE_SEARCH_EMPTY = 0x4,
    WIRELESS_STATE_HOST_SIGHTED = 0x5,
    WIRELESS_STATE_CHILD_SESSION_START = 0x6,
    WIRELESS_STATE_LINKED = 0x7,
    WIRELESS_STATE_CHILD_NO_ACTION = 0x8,
    WIRELESS_STATE_UNLINKED = 0x9,
    WIRELESS_STATE_EXCHANGE_BEGUN = 0xa,
    WIRELESS_STATE_EXCHANGE_PASS_RECV_BUFFER = 0xb,
    WIRELESS_STATE_EXCHANGE_IGNORED_FIRST = 0xc,
    WIRELESS_STATE_EXCHANGE_IGNORED_SECOND = 0xd,
    WIRELESS_STATE_DCF_RUNNING = 0xe,
    WIRELESS_STATE_DCF_FRAME_RECEIVED = 0xf,
    // Event report states the multiboot parent passes on as callback kinds 0x1d, 0x1f, 0x20 and 0x21.
    WIRELESS_STATE_EVENT_FORWARD_FIRST = 0x10,
    WIRELESS_STATE_EVENT_FORWARD_SECOND = 0x11,
    WIRELESS_STATE_EVENT_FORWARD_THIRD = 0x12,
    WIRELESS_STATE_EVENT_FORWARD_FOURTH = 0x13,
    WIRELESS_STATE_PORT_DATA_ARRIVED = 0x15,
    WIRELESS_STATE_EVENT_FATAL = 0x16, // the multiboot callbacks end the program
    WIRELESS_STATE_EVENT_IGNORED = 0x17,
} WirelessState;

// Message the other processor passes to WmReceiveFifo and to the callbacks. Several layouts overlay it: port and
// indication messages hold the state at 0x04, command replies at 0x08 (mReplyState); names with Or cover both.
struct WirelessMessage {
    // Command number; 0x80, 0x81 and 0x82 are indications and port messages. Bit 15 marks a ring message as free.
    /* 00 */ u16 mCommand;
    // 0 on success, otherwise an error number.
    /* 02 */ u16 mResultCode;
    /* 04 */ u16 mState;
    /* 06 */ u16 mPort;
    /* 08 */ union {
        struct {
            void *mRecvBuf;
            void *mData;
        };
        struct {
            u16 mReplyState;
            union {
                u16 mBusyRatio;
                u16 mOwnAid;
                u16 mAidBitmap;
            };
        };
        struct {
            u8 mUnk_08_b[2];
            u8 mMacAddress[6];
        };
    };
    /* 10 */ u16 mLength;
    /* 12 */ u16 mAid;
    /* 14 */ u8 mPeerBytes[6];
    /* 1a */ u16 mSeqNo;
    /* 1c */ void *mArg;
    /* 20 */ u16 mOwnIndex;
    /* 22 */ u8 mUnk_22[2];
    /* 24 */ u8 mSsid[0x12];
    /* 36 */ u16 mGameInfoLength;
    /* 38 */ WMGameInfo mGameInfo;
};

// 0x40 bytes. The port callback message WmReceiveFifo builds for gPortCallbackEvent: the first 0x3c bytes have the
// members of the same offsets in WirelessMessage.
typedef struct WMPortRecvCallback {
    /* 00 */ u16 mCommand;
    /* 02 */ u16 mResultCode;
    /* 04 */ u16 mState;
    /* 06 */ u16 mPort;
    /* 08 */ void *mRecvBuf;
    /* 0c */ void *mData;
    /* 10 */ u16 mLength;
    /* 12 */ u16 mAid;
    /* 14 */ u8 mPeerBytes[6];
    /* 1a */ u16 mSeqNo;
    /* 1c */ void *mArg;
    /* 20 */ u16 mOwnIndex;
    /* 22 */ u8 mUnk_22[2];
    /* 24 */ u8 mSsid[0x18];
    /* 3c */ u8 mUnk_3c[4];
} WMPortRecvCallback;

// Result of WM_GetOtherElements: mCount counts the filled entries of mElement.
typedef struct WMOtherElements {
    /* 00 */ u8 mCount;
    /* 04 */ struct {
        /* 00 */ u8 mId;
        /* 01 */ u8 mLength;
        /* 04 */ const u8 *mBody;
    } mElement[16];
} WMOtherElements;

// Header of the MP receive buffer: mCount is the number of records, mLength the size of each, and the records start at
// mData.
typedef struct WMMpRecvHeader {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mCount;
    /* 06 */ u16 mLength;
    /* 08 */ u8 mUnk_08[2];
    /* 0a */ u8 mData[1];
} WMMpRecvHeader;

// One station's record in the MP receive buffer; the payload starts at 0x0a.
typedef struct WMMpRecvData {
    /* 00 */ u16 mLength;
    /* 02 */ u16 mRateRssi;
    /* 04 */ u16 mAid;
    /* 06 */ u16 mNoResponse;
    /* 08 */ u16 mWmHeader;
    /* 0a */ u8 mPayload[1];
} WMMpRecvData;

// Request WM_StartConnectEx writes into the request area.
typedef struct StartConnectExRequest {
    /* 00 */ u16 mApiid;
    /* 02 */ u8 mReserved[2];
    /* 04 */ WMBssDesc *mPInfo;
    /* 08 */ u8 mSsid[0x18];
    /* 20 */ u32 mPowerSave;
    /* 24 */ u8 mReserved2[2];
    /* 26 */ u16 mAuthMode;
} StartConnectExRequest;

// Scan parameters of WM_StartScanEx.
typedef struct ScanExParam {
    /* 00 */ void *mScanBuf;
    /* 04 */ u16 mScanBufSize;
    /* 06 */ u16 mChannelList;
    /* 08 */ u16 mMaxChannelTime;
    /* 0a */ u8 mBssid[6];
    /* 10 */ u16 mScanType;
    /* 12 */ u16 mSsidLength;
    /* 14 */ u8 mSsid[0x20];
    /* 34 */ u16 mSsidMatchLength;
    /* 36 */ u8 mUnk_36[0xe];
} ScanExParam;

// Request WM_StartScanEx writes into the request area.
typedef struct StartScanExRequest {
    /* 00 */ u16 mApiid;
    /* 02 */ u16 mChannelList;
    /* 04 */ void *mScanBuf;
    /* 08 */ u16 mScanBufSize;
    /* 0a */ u16 mMaxChannelTime;
    /* 0c */ u8 mBssid[6];
    /* 12 */ u16 mScanType;
    /* 14 */ u16 mSsidLength;
    /* 16 */ u8 mSsid[0x20];
    /* 36 */ u16 mSsidMatchLength;
} StartScanExRequest;

// 0x20 bytes. Scan parameters of WM_StartScan.
typedef struct ScanParam {
    /* 00 */ void *mScanBuf;
    /* 04 */ u16 mChannel;
    /* 06 */ u16 mMaxChannelTime;
    /* 08 */ u8 mBssid[6];
    /* 0e */ u16 mReserved[9];
} ScanParam;

// Request WM_StartScan writes into the request area.
typedef struct StartScanRequest {
    /* 00 */ u16 mApiid;
    /* 02 */ u16 mChannel;
    /* 04 */ void *mScanBuf;
    /* 08 */ u16 mMaxChannelTime;
    /* 0a */ u8 mBssid[6];
} StartScanRequest;

// Parent parameters of WM_SetParentParameter.
typedef struct ParentParameter {
    /* 00 */ struct UserGameInfo *mUserGameInfo;
    /* 04 */ u16 mUserGameInfoLength;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ u32 mGgid;
    /* 0c */ u16 mTgid;
    /* 0e */ u16 mEntryFlag;
    /* 10 */ u16 mMaxEntry;
    /* 12 */ u16 mMultiBootFlag;
    /* 14 */ u16 mKsFlag;
    /* 16 */ u16 mCsFlag;
    /* 18 */ u16 mBeaconPeriod;
    /* 1a */ u8 mUnk_1a[0x18];
    /* 32 */ u16 mChannel;
    /* 34 */ u16 mParentMaxSize;
    /* 36 */ u16 mChildMaxSize;
} ParentParameter;

s32 WM_StartDCF(WirelessMessageCallback callback, void *recvBuf, u16 recvBufSize);
s32 WM_SetDCFData(WirelessMessageCallback callback, const void *destAdr, void *sendData, u16 sendDataSize);
s32 WM_EndDCF(WirelessMessageCallback callback);
s32 WM_StartMPEx(WirelessMessageCallback callback, void *recvBuf, u16 recvBufSize, void *sendBuf, u16 sendBufSize,
                 u16 mpFreq, u16 defaultRetryCount, BOOL minPollBmpMode, BOOL singlePacketMode, BOOL fixFreqMode,
                 BOOL ignoreFatalError);
s32 WM_SetMPFrequency(WirelessMessageCallback callback, u32 mpFreq);
s32 WM_SetMPDataToPortEx(WirelessSendCallback callback, void *arg, void *sendData, s32 sendDataSize, u16 destBitmap,
                         u16 port, u16 prio);
s32 WM_EndMP(WirelessMessageCallback callback);
s32 WM_Enable(WirelessMessageCallback callback);
s32 WM_Disable(WirelessMessageCallback callback);
s32 WM_PowerOn(WirelessMessageCallback callback);
s32 WM_PowerOff(WirelessMessageCallback callback);
s32 WM_Initialize(void *wmSysBuf, WirelessMessageCallback callback, u16 dmaNo);
s32 WM_Reset(WirelessMessageCallback callback);
s32 WM_End(WirelessMessageCallback callback);
s32 WM_SetParentParameter(WirelessMessageCallback callback, ParentParameter *pparaBuf);
u32 WmCheckParentParameter(const ParentParameter *param);
s32 WMi_StartParentEx(WirelessMessageCallback callback, BOOL powerSave);
s32 WM_StartParent(WirelessMessageCallback callback);
s32 WM_EndParent(WirelessMessageCallback callback);
s32 WM_StartScan(WirelessMessageCallback callback, ScanParam *param);
s32 WM_StartScanEx(WirelessMessageCallback callback, ScanExParam *param);
s32 WM_EndScan(WirelessMessageCallback callback);
s32 WM_StartConnectEx(WirelessMessageCallback callback, WMBssDesc *pInfo, void *ssid, BOOL powerSave, u16 authMode);
s32 WM_Disconnect(WirelessMessageCallback callback, u32 aid);
s32 WM_DisconnectChildren(WirelessMessageCallback callback, u32 aidBitmap);
s32 WM_SetIndCallback(WirelessMessageCallback callback);
s32 WM_SetPortCallback(u16 port, WirelessPortCallback callback, void *arg);
s32 WM_ReadStatus(void *statusBuf);
s32 WM_GetMPSendBufferSize(void);
s32 WM_GetMPReceiveBufferSize(void);
void *WM_ReadMPData(const WMMpRecvHeader *header, u16 aid);
u16 WM_GetAllowedChannel(void);
u16 WM_GetLinkLevel(void);
u16 WM_GetDispersionBeaconPeriod(void);
u16 WM_GetDispersionScanPeriod(void);
WMOtherElements WM_GetOtherElements(const u16 *bssDesc);
u16 WM_GetNextTgid(void);

extern u32 tgid_bak;
