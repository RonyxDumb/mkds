#pragma once

#include "00/code_02180608.h"
#include "00/Lib/CPS/network.h"
#include "00/code_02186d04.h"
#include "00/code_02187484.h"
#include "00/Lib/DWC/code_02188008.h"
#include "00/Lib/DWC/code_02188ec0.h"
#include "00/Lib/DWC/code_021884d8.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/code_021a3a18.h"
#include "00/Lib/GameSpy/code_0218a71c.h"

#include "types.h"
#include "00/code_021a6fa8.h"

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
// Objects behind gWiFiSelectCharacterState and gWiFiSelectKartState.
typedef struct WiFiSelectHeapHolder {
    /* 0 */ void *mHeap;
} WiFiSelectHeapHolder;

// Object behind gSortServerList; the 0x5d8 bytes at offset 0x4c of a MatchingServerList.
// Values of SbServerList.mState: browsing the local network, not connected, taking in the data that follows the list
// (ad hoc), and receiving the main list.
enum {
    SERVER_LIST_STATE_LOCAL_SCAN = 0,
    SERVER_LIST_STATE_NO_SOCKET = 1,
    SERVER_LIST_STATE_AD_HOC = 2,
    SERVER_LIST_STATE_RECEIVING_LIST = 3,
};

// Values of SbServerList.mParseState, the parts of the main list in the order they arrive: the cipher key, the own
// address, the field names, the popular values, the entries; DONE once the list is complete.
enum {
    SERVER_LIST_PARSE_CIPHER_KEY = 0,
    SERVER_LIST_PARSE_ADDRESS = 1,
    SERVER_LIST_PARSE_FIELD_NAMES = 2,
    SERVER_LIST_PARSE_POPULAR_VALUES = 3,
    SERVER_LIST_PARSE_ENTRIES = 4,
    SERVER_LIST_PARSE_DONE = 5,
};

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
    /* 488 */ UnkFunc *mCallback;
    /* 48c */ UnkFunc *mMaploopCallback;
    /* 490 */ UnkFunc *mPlayerSearchCallback;
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
    /* 5d0 */ int mDeadList;
} SbServerList;

// Object behind gGsiAvailableCheck.
typedef struct GsiAvailableCheck {
    /* 00 */ s32 mSocket;
    /* 04 */ u8 mAddress[2];
    /* 06 */ u16 mPort;
    /* 08 */ u8 mAddressIp[4];
    /* 0c */ u8 mPacketType;
    /* 0d */ u8 mUnk_0d[4];
    /* 11 */ u8 mPacketGamename[0x3b];
    /* 4c */ s32 mPacketLength;
    /* 50 */ u32 mSendTime;
    /* 54 */ s32 mRetryCount;
} GsiAvailableCheck;

extern u8 NNMagicData[];

#include "00/Lib/DWC/dwc_connectinet.h"
