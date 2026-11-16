#pragma once

#include "types.h"
#include "03/System/tasks.h"

typedef void (*ExchangeEventCallback)(u32 event, u32 arg);

typedef struct RawEntry RawEntry;

// Values of gExchangeWcmState and gEssidWcmState: where the WCM layer is in starting up, searching, connecting and
// cleaning up.
#define EXCHANGE_WCM_STATE_STOPPED 0
#define EXCHANGE_WCM_STATE_INITIALIZED 1
#define EXCHANGE_WCM_STATE_CLEANING_UP 2
#define EXCHANGE_WCM_STATE_IDLE 3
#define EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING 4
#define EXCHANGE_WCM_STATE_SEARCHING 5
#define EXCHANGE_WCM_STATE_SEARCH_PENDING 6
#define EXCHANGE_WCM_STATE_CONNECTED 7
#define EXCHANGE_WCM_STATE_CONNECT_PENDING 8

// Event numbers passed to ExchangeEventCallback: the WCM notice callback passes most of them; CONNECT_TIMEOUT and
// SEARCH_TIMEOUT are queued by alarms.
#define EXCHANGE_EVENT_UNEXPECTED_NOTICE 1
#define EXCHANGE_EVENT_CHAINED_REQUEST_FAILED 2
#define EXCHANGE_EVENT_LINK_TERMINATED 3
#define EXCHANGE_EVENT_SCAN_ROUND 4
#define EXCHANGE_EVENT_SEARCH_FOUND 5
#define EXCHANGE_EVENT_STARTUP_DONE 6
#define EXCHANGE_EVENT_UNUSED_AFTER_STARTUP_DONE 7
#define EXCHANGE_EVENT_SEARCH_STARTED 8
#define EXCHANGE_EVENT_SEARCH_START_FAILED 9
#define EXCHANGE_EVENT_SEARCH_STOPPED 10
#define EXCHANGE_EVENT_SEARCH_STOP_FAILED 11
#define EXCHANGE_EVENT_CONNECTED 12
#define EXCHANGE_EVENT_CONNECT_FAILED 13
#define EXCHANGE_EVENT_DISCONNECTED 14
#define EXCHANGE_EVENT_DISCONNECT_FAILED 15
#define EXCHANGE_EVENT_UNUSED_AFTER_DISCONNECT_FAILED 16
#define EXCHANGE_EVENT_UNUSED_BEFORE_CONNECT_TIMEOUT 17
#define EXCHANGE_EVENT_CONNECT_TIMEOUT 18
#define EXCHANGE_EVENT_SEARCH_TIMEOUT 19
#define EXCHANGE_EVENT_CLEANUP_DONE 20

// WCMConfig.mDmaNo of the exchange WCM layer.
#define EXCHANGE_WCM_DMA_NO 3

typedef struct OamEntry OamEntry;

// An animated icon: its task, OAM entry, palette index and step frames.
typedef struct AnimatedIcon {
    /* 00 */ TaskEntry *mTask;
    /* 04 */ OamEntry *mOamEntry;
    /* 08 */ u8 mPaletteIndex;
    /* 09 */ u8 mStepFrames;
} AnimatedIcon;

// Message passed to ExchangeWcmNotifyCallback.
typedef struct WcmNoticeHead {
    /* 00 */ s16 mNotify;
    /* 02 */ s16 mResult;
} WcmNoticeHead;

BOOL InitExchangeWcm(ExchangeEventCallback callback, void *buffer, u32 size);
BOOL ConnectExchangeToEntry(void *entry, void *optionalBytes, u32 option);
BOOL CleanupExchangeWcm(void);
BOOL DisconnectExchange(void);
BOOL StartExchangeSearch(u8 *address, u8 *name, s32 nameLength, u32 option);
s32 CopyExchangeScanRecords(RawEntry *output, s32 maxCount);
BOOL StartExchangeReturnToIdle(void);
void ExchangeWcmNotifyCallback(WcmNoticeHead *message);
void AdvanceAnimatedIcon(TaskEntry *task, void *arg);
void ReleaseAnimatedIcon(void);
void CreateAnimatedIcon(int index);
void AdvanceButtonReset(TaskEntry *task, void *arg);
void ReleaseSlideButtons(TaskEntry *task, void *arg);
