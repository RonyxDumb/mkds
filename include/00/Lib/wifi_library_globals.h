#pragma once

#include "00/Menu/wi_fi_state_machine.h"
#include "00/Lib/CPS/tcp_ip_stack.h"
#include "00/Lib/DWC/http_transfer.h"
#include "00/Lib/DWC/network_check_status.h"
#include "00/Lib/DWC/network_check_control.h"
#include "00/Lib/DWC/access_point_power_mode.h"
#include "00/Lib/DWC/access_point_state.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/query_reporting.h"
#include "00/Lib/GameSpy/stream_cipher.h"

#include "types.h"
#include "00/Lib/NitroWiFi/socket_objects.h"

// Settings SOCLi_GetSizeSocket reads and SOCLi_InitSocket applies.
typedef struct SOCLSocketParam {
    /* 00 */ s8 mFlagMode;
    /* 01 */ s8 mFlagBlock;
    /* 02 */ u16 mRcvbufSize;
    /* 04 */ u16 mRcvbufConsumeMin;
    /* 06 */ u16 mSndbufSize;
    /* 08 */ u16 mLinbufSize;
    /* 0a */ u16 mOutbufSize;
    /* 0c */ u16 mWrtbufSize;
    /* 0e */ u16 mUdpbufSize;
    /* 10 */ SOCLSocketCommandPipeParam mRecvPipe;
    /* 14 */ SOCLSocketCommandPipeParam mSendPipe;
} SOCLSocketParam;

extern u32 gSslLowThreadPriority;
extern NatnegMagic gNatnegMagicBytes;
extern QueryRecord *gCurrentQr2Rec;
extern u8 gSha1PaddingBytes[];
extern ACWORK *gAcWork;
extern void *gWcmBuffer;
extern void *gSocConfig;
extern DWCNetcheckParam *gNetCheck;
extern ACHOLD *gAcHold;
// The heap of a Wi-Fi character or kart select screen.
typedef struct WiFiSelectHeapHolder {
    /* 0 */ void *mHeap;
} WiFiSelectHeapHolder;

// Object behind gSortServerList; the 0x5d8 bytes at offset 0x4c of a MatchingServerList.
// Values of SbServerList.mState: browsing the local network, not connected, taking in the data that follows the list
// (ad hoc), and receiving the NtrMain list.
enum {
    SERVER_LIST_STATE_LOCAL_SCAN = 0,
    SERVER_LIST_STATE_NO_SOCKET = 1,
    SERVER_LIST_STATE_AD_HOC = 2,
    SERVER_LIST_STATE_RECEIVING_LIST = 3,
};

// Values of SbServerList.mParseState, the parts of the NtrMain list in the order they arrive: the cipher key, the own
// address, the field names, the popular values, the entries; DONE once the list is complete.
enum {
    SERVER_LIST_PARSE_CIPHER_KEY = 0,
    SERVER_LIST_PARSE_ADDRESS = 1,
    SERVER_LIST_PARSE_FIELD_NAMES = 2,
    SERVER_LIST_PARSE_POPULAR_VALUES = 3,
    SERVER_LIST_PARSE_ENTRIES = 4,
    SERVER_LIST_PARSE_DONE = 5,
};

typedef struct SbServer SbServer;
typedef struct SbServerList SbServerList;

typedef void (*SbServerListCallback)(SbServerList *list, s32 reason, SbServer *server, void *instance);
typedef void (*SbMaploopCallback)(SbServerList *list, SbServer *server, u32 rotationTime, s32 mapCount, u8 **mapNames,
                                  void *instance);
typedef void (*SbPlayerSearchCallback)(SbServerList *list, u8 *name, u32 ipAddress, u16 netPort, u32 lastSeenTime,
                                       u8 *gameName, void *instance);

typedef struct SbServerList {
    /* 000 */ s32 mState;
    /* 004 */ struct Darray *mServers;
    /* 008 */ struct Darray *mKeyList;
    /* 00c */ char mQueryForGameName[0x24];
    /* 030 */ char mQueryFromGameName[0x24];
    /* 054 */ char mQueryFromKey[0x20];
    /* 074 */ s8 mChallenge[8];
    /* 07c */ u8 *mInBuffer;
    /* 080 */ s32 mInBufferLength;
    /* 084 */ char *mPopularValues[0xff];
    /* 480 */ s32 mNumPopularValues;
    /* 484 */ s32 mExpectedElements;
    /* 488 */ SbServerListCallback mCallback;
    /* 48c */ SbMaploopCallback mMaploopCallback;
    /* 490 */ SbPlayerSearchCallback mPlayerSearchCallback;
    /* 494 */ void *mInstance;
    /* 498 */ const char *mSortKey;
    /* 49c */ s32 mSortAscending;
    /* 4a0 */ s32 mMyPublicIp;
    /* 4a4 */ u32 mSrcIp;
    /* 4a8 */ u16 mDefaultPort;
    /* 4aa */ u8 mUnk_4aa[2];
    /* 4ac */ char *mLastError;
    /* 4b0 */ s32 mSocket;
    /* 4b4 */ u32 mLanStartTime;
    /* 4b8 */ u32 mFromGameVersion;
    /* 4bc */ GOACryptState mCryptKey;
    /* 5c1 */ u8 mUnk_5c1[3];
    /* 5c4 */ u32 mQueryOptions;
    /* 5c8 */ s32 mParseState;
    /* 5cc */ s32 mLanAdapterOverride;
    /* 5d0 */ struct SbServer *mDeadList;
} SbServerList;

// The availability check request: its socket, server address, packet, send time and retry count.
typedef struct GsiAvailableCheck {
    /* 00 */ s32 mSocket;
    /* 04 */ SOCSockAddrIn mAddress;
    /* 0c */ u8 mPacketType;
    /* 0d */ u8 mUnk_0d[4];
    /* 11 */ u8 mPacketGamename[0x3b];
    /* 4c */ s32 mPacketLength;
    /* 50 */ u32 mSendTime;
    /* 54 */ s32 mRetryCount;
} GsiAvailableCheck;

extern u8 NNMagicData[];

#include "00/Lib/DWC/internet_connection.h"
