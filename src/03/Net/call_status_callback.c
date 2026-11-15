#include "03/Menu/exchange_status_record.h"
#include "03/Net/exchange_essid.h"
#include "03/Menu/wifi_menu_tables.h"
#include "03/Net/exchange_result_records.h"
#include "os_thread.h"
#include "code_02134398.h"

u8 gReceivedTextNonEmpty;
u8 *gExchangeSearchAddress;
ExchangeAllocFunc gAllocFunction;
void *gAlignedBuffer;
ExchangeFreeFunc gFreeFunction;
s32 gStopRequested;
u32 gPacketLength;
s32 gExchangeResultCode;
s32 gExchangeStatus;
u32 gExchangeConnected;
u32 gSocketsStarted;
WCMWepDesc *gExchangeConnectBlock;
u32 gExchangeWcmState;
void *gThreadStack;
u32 gBodyLength;
u32 gSelectedEntryIndex;
ExchangeEventCallback gExchangeEventCallback;
u32 gExchangeState;
void *gExchangeWcmWork;
u8 *gExchangeSearchEssid;
WMBssDesc *gExchangeConnectRecord;
u32 gReplyIncludesMacAddress;
void *gAllocatedBuffer;
u32 gExchangeConnectOption;
RawEntry *gRawEntries;
u32 gExchangeSearchOption;
s32 gThreadStarted;
s32 gEventWriteIndex;
s32 gEventReadIndex;
s32 gEntryCountMax;
s32 gExchangeWiFiInitCalled;
WCMConfig *gExchangeWcmConfig;
ExchangeStatusCallback gStatusCallback;
u8 gExchangeSearchAddressBytes[6];
MacAddress gSelectedEntryAddress;
MacAddress gMacAddress;
u8 gFirstKey[0x10];
u32 gEvents[4];
OSMutex gAllocMutex;

// Asks the thread to stop, waits for it to end, frees its stack and shuts the lower layer down.
s32 StopExchange(void) {
    s32 oldStatus;
    if (gThreadStarted != 0) {
        oldStatus = gExchangeStatus;
        gStopRequested = 1;
        while (gExchangeStatus >= EXCHANGE_STATUS_STARTED && gExchangeStatus <= EXCHANGE_STATUS_SECOND_KEY_RECEIVED) {
            OS_Sleep(100);
        }
        OS_Sleep(500);
        if (OS_IsThreadTerminated(&gExchangeThread) == 0) {
            do {
                OS_WakeupThreadDirect(&gExchangeThread);
                OS_JoinThread(&gExchangeThread);
            } while (OS_IsThreadTerminated(&gExchangeThread) == 0);
        }
        if (gThreadStack != NULL) {
            gFreeFunction(gThreadStack);
            gThreadStack = NULL;
        }
        gThreadStarted = 0;
        if (oldStatus != gExchangeStatus) {
            CallStatusCallback();
        }
    }
    if (gExchangeWiFiInitCalled > 0) {
        s32 result = ReleaseExchangeWiFi();
        gExchangeWiFiInitCalled = 0;
        return result;
    }
    return -10;
}

u32 GetExchangeStatus(u32 *output) {
    int now;
    *output = gExchangeStatus;
    if ((gTimeoutAtMs) == -1) {
        output[1] = 0xffffffff;
    } else {
        now = GetTickMilliseconds();
        output[1] = (gTimeoutAtMs) -now;
    }
    output[2] = gExchangeResultCode;
    return 1;
}

u32 CopyExchangeResult(ExchangeResult *output) {
    memcpy(((u32 *) (u32) output), &gExchangeResult, sizeof(ExchangeResult));
    return 1;
}

// Reports the status, the time left and the result code to the stored callback.
void CallStatusCallback(void) {
    u8 status[8];
    GetExchangeStatus(((void *) status));
    gStatusCallback((const ExchangeStatus *) status);
}
