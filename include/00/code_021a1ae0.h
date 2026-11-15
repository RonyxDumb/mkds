#pragma once

#include "types.h"
#include "os_printf.h"
#include "os_tick.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0213a460.h"
#include "code_0214d018.h"
#include "00/code_0218a000.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/Lib/GameSpy/sb_serverlist.h"
#include "00/Lib/GameSpy/code_0219887c.h"
#include "00/code_0219a000.h"
#include "00/Lib/DWC/code_0219b1f8.h"
#include "00/Lib/DWC/code_0219c384.h"
#include "00/unk_021b5000.h"
#include "00/code_0219d000.h"
#include "00/code_0219de5c.h"
#include "00/code_0219e000.h"
#include "00/code_0219f000.h"
#include "00/code_0219f9bc.h"
#include "00/code_021a0000.h"
#include "00/code_021a1000.h"
#include "00/code_021a17bc.h"
#include "00/code_021a1ac0.h"
#include "00/code_021a4000.h"
#include "00/unk_021b4000.h"
#include "00/Lib/GameSpy/code_021a3a18.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"

// Address and byte-swapped port built by DWCi_GT2UnrecognizedMessageCallback and handed on with the data.
typedef struct UnmatchedDataAddress {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mFamily;
    /* 02 */ u16 mPort;
    /* 04 */ u32 mAddress;
} UnmatchedDataAddress;

void DWCi_MatchGPRecvBuddyMsgCallback(GpConnection *gpConnection, u32 profileId, const char *message);
void DWCi_GT2ConnectedCallback(Gt2Connection *connection, s32 result);
void DWCi_GT2ConnectAttemptCallback(u32 socket, Gt2Connection *connection, u32 address, u32 port, s32 latency,
                                    char *message);
u32 DWCi_GT2UnrecognizedMessageCallback(u32 socket, u32 address, u16 port, u8 *data, u32 size);
void DWCi_MatchProcess(s32 param_1);
void DWCi_ConnectToFriendsAsync(const void *friendIdxList, s32 friendIdxListLen, s32 numEntry, s32 distantFriend,
                                void *matchedCallback, u32 matchedParam, u32 evalCallback, u32 evalParam);
void DWCi_ConnectToAnybodyAsync(u32 numEntry, const void *addFilter, u32 matchedCallback, u32 matchedParam,
                                u32 evalCallback, u32 evalParam);
u32 DWCi_QR2Startup(u32 profileId);
void DWCi_MatchInit(WiFiMatching *wiFiMatching, GpConnection *gpConnection, void **connectionSocket,
                    void *connectionCallbacks, void *gameName, void *secretKey, void *buddies, u32 buddyEntryCount);

#include "00/Lib/DWC/dwc_connectinet.h"
