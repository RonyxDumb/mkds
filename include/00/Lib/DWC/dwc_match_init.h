#pragma once

#include "types.h"
#include "os_printf.h"
#include "os_tick.h"
#include "string.h"
#include "print_memory_functions.h"
#include "text_to_number.h"
#include "cpu_copy_fill.h"
#include "00/Lib/GameSpy/sb_serverlist.h"
#include "00/Lib/GameSpy/socket_accessors.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "00/Lib/DWC/error_state.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/DWC/dwc_match_qr2_callbacks.h"
#include "00/Lib/DWC/dwc_match_closing.h"
#include "00/Lib/DWC/dwc_match_resend.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/query_reporting.h"
#include "00/Lib/GameSpy/socket_calls.h"

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
u32 DWCi_GT2UnrecognizedMessageCallback(Gt2Socket *socket, s32 address, s32 port, void *message, s32 size);
void DWCi_MatchProcess(s32 runStateMachine);
void DWCi_ConnectToFriendsAsync(const void *friendIdxList, s32 friendIdxListLen, s32 numEntry, s32 distantFriend,
                                DWCMatchedCallback matchedCallback, u32 matchedParam, MatchEvalFunc *evalCallback,
                                u32 evalParam);
void DWCi_ConnectToAnybodyAsync(u32 numEntry, const void *addFilter, DWCMatchedCallback matchedCallback,
                                u32 matchedParam, MatchEvalFunc *evalCallback, u32 evalParam);
u32 DWCi_QR2Startup(u32 profileId);
void DWCi_MatchInit(WiFiMatching *wiFiMatching, GpConnection *gpConnection, Gt2Socket **connectionSocket,
                    void *connectionCallbacks, void *gameName, void *secretKey, void *buddies, u32 buddyEntryCount);

#include "00/Lib/DWC/dwc_connectinet.h"
