#pragma once

#include "types.h"
#include "multiboot_game_info_beacon.h"
#include "Main/System/backup_net_camera_work.h"

// What the scan callback gets for an entry event: the entry index, and the entry and the scan buffer (both NULL when an
// entry timed out).
typedef struct ScanEntryArgs {
    /* 00 */ u16 mEntryIndex;
    /* 04 */ MBGameInfoRecvList *mEntry;
    /* 08 */ WMBssDesc *mScanBuffer;
    /* 0c */ u32 mUnk_0c;
} ScanEntryArgs;

// What the scan callback gets for a scan error: the error code and the result code.
typedef struct ScanErrorArgs {
    /* 00 */ u16 mErrorCode;
    /* 02 */ u16 mResultCode;
} ScanErrorArgs;

#include "wireless_link_control.h"

// ScanConnectWork.mState; the child steps through the parent's messages.
typedef enum ScanConnectState {
    SCAN_CONNECT_STATE_IDLE = 0,
    SCAN_CONNECT_STATE_CONNECTING = 1,
    SCAN_CONNECT_STATE_LINK_UP = 2,
    SCAN_CONNECT_STATE_CONNECT_FAILED = 3,
    SCAN_CONNECT_STATE_LINK_LOST = 4,
    SCAN_CONNECT_STATE_SEND_REQUEST = 5,
    SCAN_CONNECT_STATE_REQUEST_REJECTED = 6,
    SCAN_CONNECT_STATE_ACCEPTED = 7,
    SCAN_CONNECT_STATE_WAIT_START = 8, // the START message moves ACCEPTED on to SEND_START in the same call
    SCAN_CONNECT_STATE_SEND_START = 9,
    SCAN_CONNECT_STATE_SEND_DONE = 10,
    SCAN_CONNECT_STATE_RESET_DONE = 11,
    SCAN_CONNECT_STATE_RESET_ABORTED = 12,
    SCAN_CONNECT_STATE_REQUEST_FAILED = 14,
    SCAN_CONNECT_STATE_ERROR = 19, // only passed to the state callback with an error kind
    SCAN_CONNECT_STATE_FINISHED = 20, // the scan connection was closed
} ScanConnectState;

// Kind that the state callback gets with SCAN_CONNECT_STATE_ERROR.
typedef enum ScanConnectError {
    SCAN_CONNECT_ERROR_OTHER = 8,
    SCAN_CONNECT_ERROR_WM_REJECTED = 9,
} ScanConnectError;

// Port of the MP link, and the result QueueMPDataIfReady returns when no data was queued.
#define MP_LINK_PORT 1
#define MP_LINK_QUEUE_NOT_READY 1

// Size of the object behind gScanConnectWork.
#define SCAN_CONNECT_WORK_SIZE 0x5f20

// Scan timing and channels: the most time in milliseconds spent on a channel (a locked bssid waits longer) and the
// channel range PickScanChannel walks.
#define SCAN_CHANNEL_TIME_ANY 10
#define SCAN_CHANNEL_TIME_LOCKED 0xdc
#define SCAN_CHANNEL_FIRST 1
#define SCAN_CHANNEL_LAST 0x10

// First argument of the MPLink callback.
typedef enum MPLinkEvent {
    MP_LINK_EVENT_CONNECTED = 6,
    MP_LINK_EVENT_UNUSED = 7, // never raised
    MP_LINK_EVENT_SENT = 8,
    MP_LINK_EVENT_RECEIVED = 9,
    MP_LINK_EVENT_DISCONNECTED = 10,
    MP_LINK_EVENT_CONNECT_FAILED = 11,
    MP_LINK_EVENT_RESET_DONE = 15,
    MP_LINK_EVENT_SEND_FAILED = 18,
    MP_LINK_EVENT_MP_STARTED = 20,
    MP_LINK_EVENT_SEND_READY = 25,
    MP_LINK_EVENT_SEND_BUSY = 0x29,
    MP_LINK_EVENT_CALL_FAILED = 0xff, // a WM call failed
    MP_LINK_EVENT_REPLY_FAILED = 0x100, // a WM reply failed
} MPLinkEvent;

// First argument of ScanConnectWork.mScanCallback.
typedef enum ScanEvent {
    SCAN_EVENT_ENTRY_NEW = 0,
    SCAN_EVENT_ENTRY_UPDATED = 1,
    SCAN_EVENT_ERROR = 2,
    SCAN_EVENT_END = 3,
} ScanEvent;

// ScanErrorArgs.mErrorCode.
typedef enum ScanError {
    SCAN_ERROR_START = 10,
    SCAN_ERROR_END = 11,
    SCAN_ERROR_NO_CHANNEL = 30,
} ScanError;

// Called with the event kind and what goes with it: the wireless message, a command and result code pair, or 0 when
// nothing goes with it.
typedef void (*MPLinkEventCallback)(s32 eventKind, void *info);

// The multiplayer link: its callback, send and receive buffers with their sizes, the parent and child max sizes, and
// the mMPStarted, mResetting and mDataQueued flags.
typedef struct MPLink {
    /* 00 */ MPLinkEventCallback mCallback;
    /* 04 */ void *mSendBuffer;
    /* 08 */ u8 *mReceiveBuffer;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u16 mSendBufferSize;
    /* 12 */ u16 mReceiveBufferSize;
    /* 14 */ u16 mParentMaxSize;
    /* 16 */ u16 mChildMaxSize;
    /* 18 */ u16 mParentPayloadSize;
    /* 1a */ u16 mMPStarted;
    /* 1c */ u16 mResetting;
    /* 1e */ u16 mUnk_1e;
    /* 20 */ u16 mDataQueued;
} MPLink;

typedef void (*ScanEventCallback)(u32 event, void *args);
typedef void (*ScanConnectStateFunc)(u32 state, void *info);

// The scan and connect work: buffers, mScanParams, the mMPLink, the scan and state callbacks, the repeat and end
// request flags and mState.
typedef struct ScanConnectWork {
    /* 0000 */ u8 mUnk_0000[0x20];
    /* 0020 */ u8 mReceiveBuffer[0x480];
    /* 04a0 */ u8 mMessageBuffer[0x20];
    /* 04c0 */ WMBssDesc mScanBuffer;
    /* 0580 */ ScanParam mScanParams;
    /* 05a0 */ MPLink mMPLink;
    /* 05c4 */ u8 mUserInfo[0x18];
    /* 05dc */ ScanEventCallback mScanCallback;
    /* 05e0 */ ScanConnectStateFunc mStateCallback;
    /* 05e4 */ u32 mScanGgid;
    /* 05e8 */ u8 mBeaconRecvStatus[0x5ee - 0x5e8];
    /* 05ee */ u16 mUnk_05ee;
    /* 05f0 */ u8 mUnk_05f0[0x5ef8 - 0x5f0];
    /* 5ef8 */ u32 mRepeatScan;
    /* 5efc */ u32 mEndScanRequested;
    /* 5f00 */ u32 mUseScanBssid;
    /* 5f04 */ u32 mEndRequested;
    /* 5f08 */ u32 mGgid;
    /* 5f0c */ u16 mFileId;
    /* 5f0e */ u16 mState;
} ScanConnectWork;

// A command and result code pair that MPLink.mCallback gets with MP_LINK_EVENT_CALL_FAILED and
// MP_LINK_EVENT_REPLY_FAILED.
typedef struct CommandResult {
    /* 00 */ u16 mCommand;
    /* 02 */ u16 mResultCode;
} CommandResult;


void ScanConnectEndScan(void);
void RequestEndScan(void);
u32 PickScanChannel(void);
// First argument of EntryCallback, as the multiboot game info receiver (MB_RecvGameInfoBeacon,
// MB_CountGameInfoLifetime) calls it: a complete entry got all its game info fragments, a complete entry lost them, a
// complete entry timed out, or no entry slot was free.
enum {
    BEACON_ENTRY_EVENT_COMPLETE = 1,
    BEACON_ENTRY_EVENT_INCOMPLETE = 2,
    BEACON_ENTRY_EVENT_TIMED_OUT = 3,
    BEACON_ENTRY_EVENT_NO_FREE_SLOT = 4,
};
void EntryCallback(u32 event, void *entry, u32 entryIndex);
void ClearUseScanBssid(void);
void SetScanBssid(const u8 *bssid);
void ReportScanError(u16 errorCode, u16 resultCode);
void CallScanCallbackWithEntry(u32 event, MBGameInfoRecvList *entry, u32 entryIndex);
void ScanConnectStartScanCallback(WirelessMessage *result);
void ScanConnectStartScan(void);
void StartRepeatedScan(ScanEventCallback callback, u32 param);
void SetScanConnectStateAndNotify(u32 state, void *info);
void SetScanConnectStateCallback(ScanConnectStateFunc callback);
unsigned int GetScanConnectWorkSize(void);
void FinishScanConnect(void);
void CloseScanConnect(void);
void InitScanConnectWork(ScanConnectWork *work, void *initData);
void ClearPortCallback(void);
void QueueMPDataCallback(WirelessMessage *result);
s32 QueueMPDataIfReady(u32 dataSize, u16 destBitmap, u8 *data);
void PortCallback(void *portMessage);
u32 IsMPReadyToQueueData(void);
void StartResetCallback(WirelessMessage *result);
void StartReset(void);
void StartResetWithFlagCallback(WirelessMessage *result);
void StartResetWithFlag(void);
void ScanConnectStartMPCallback(WirelessMessage *result);
void SetPortCallbackAndStartMP(void *sendBuffer, u8 *receiveBuffer);
void ScanConnectStartConnectCallback(WirelessMessage *result);
void ScanConnectStartConnect(WMBssDesc *scanBuffer);
void SetMPLinkCallback(MPLinkEventCallback callback);
void SetupMPLink(MPLink *link);

extern const u8 gDefaultScanBssid[6];
extern u16 gScanConnectInitialized;
extern struct MPLink *gMPLink;
extern struct ScanConnectWork *gScanConnectWork;
