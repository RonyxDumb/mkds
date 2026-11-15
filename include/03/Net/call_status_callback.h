#pragma once

#include "types.h"
#include "03/Net/exchange_essid.h"
#include "00/Lib/DWC/access_point_wep_key.h"
#include "wireless_power_mp.h"
#include "03/Net/exchange_result_records.h"
#include "00/Lib/NitroWiFi/wireless_connection_config.h"
#include "thread_mutex_types.h"

extern u8 gReceivedTextNonEmpty;
extern u8 *gExchangeSearchAddress;
extern ExchangeAllocFunc gAllocFunction;
extern void *gAlignedBuffer;
extern ExchangeFreeFunc gFreeFunction;
extern s32 gStopRequested;
extern u32 gPacketLength;
extern s32 gExchangeResultCode;
extern s32 gExchangeStatus;
extern u32 gExchangeConnected;
extern u32 gSocketsStarted;
extern struct WCMWepDesc *gExchangeConnectBlock;
extern u32 gExchangeWcmState;
extern void *gThreadStack;
extern u32 gBodyLength;
extern u32 gSelectedEntryIndex;
extern ExchangeEventCallback gExchangeEventCallback;
extern u32 gExchangeState;
extern void *gExchangeWcmWork;
extern u8 *gExchangeSearchEssid;
extern struct WMBssDesc *gExchangeConnectRecord;
extern u32 gReplyIncludesMacAddress;
extern void *gAllocatedBuffer;
extern u32 gExchangeConnectOption;
extern struct RawEntry *gRawEntries;
extern u32 gExchangeSearchOption;
extern s32 gThreadStarted;
extern s32 gEventWriteIndex;
extern s32 gEventReadIndex;
extern s32 gEntryCountMax;
extern s32 gExchangeWiFiInitCalled;
extern struct WCMConfig *gExchangeWcmConfig;
extern ExchangeStatusCallback gStatusCallback;
extern u8 gExchangeSearchAddressBytes[6];
extern MacAddress gSelectedEntryAddress;
extern MacAddress gMacAddress;
extern u8 gFirstKey[0x10];
extern u32 gEvents[4];
extern OSMutex gAllocMutex;
