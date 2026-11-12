#pragma once

#include "00/code_02180608.h"
#include "00/Lib/CPS/network.h"
#include "00/Lib/CPS/code_021ad734.h"
#include "00/code_02186d04.h"
#include "00/code_02187484.h"
#include "00/Lib/DWC/code_02188008.h"
#include "00/Lib/DWC/code_02188ec0.h"
#include "00/Lib/DWC/code_021884d8.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/code_021a3a18.h"

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

// Objects whose layout isn't known yet.
extern u32 SOCLiResultCodeInConnecting;
extern SOCLSocketParam SOCLSocketParamTCP;
extern SOCLSocketParam SOCLSocketParamUDPSend;
extern char gMatchingSignature[];
extern char gUnsignedFormat[];
extern char gDwcPidKey[];
extern char gDwcEvalKey[];
extern char gDwcMtypeKey[];
extern char gDwcMresvKey[];
extern char gDwcMverKey[];
extern char gVerKey[];
extern u8 gScmKey[];
extern u8 gScnKey[];
extern u32 gSslLowThreadPriority;
extern char gLocalIpKeyFormat[];
extern char gLocalportKey[];
extern char gNatnegKey[];
extern char gNatnegOnValue[];
extern char gNatnegOffValue[];
extern char gStatechangedKey[];
extern char gGamenamePlainKey[];
extern char gPublicipKey[];
extern char gPublicportKey[];
extern NatnegMagic gNatnegMagicBytes;
extern QueryRecord *gCurrentQr2Rec;
extern char gUnregisteredKeyName[];
extern char data_ov000_021b4400[];
extern char data_ov000_021b4404[];
extern char gPublicAddressFormat[];
extern char gBroadcastAddress[];
extern char gIntFormat[];
extern u8 gNoChallengeErrorMessage[];
extern char gQr2MasterHostnameFormat[];
extern char gFinalQueryidText[];
extern u8 gSrvrText[];
extern u8 gClntText[];
extern u16 gOfferedValues[2];
extern const char *gTaggedItemPrefixes[];
extern u8 gLabelAText[];
extern u8 gLabelBBText[];
extern u8 gLabelCCCText[];
extern u8 gSha1PaddingBytes[];
extern Http *gHttp;
extern DWCNetcheck *gNetcheck;
extern ACWORK *gAcWork;
extern void *gWcmBuffer;
extern void *gSocConfig;
extern DWCNetcheckParam *gNetCheck;
extern ACHOLD *gAcHold;
extern struct Hashtable *gSBRefStrList;
extern struct SbServer *gSBNullServer;
// Objects behind gWiFiSelectCharacterState and gWiFiSelectKartState.
typedef struct WiFiSelectHeapHolder {
    /* 0 */ void *mHeap;
} WiFiSelectHeapHolder;

// Object behind gSortServerList; the 0x5d8 bytes at offset 0x4c of a MatchingServerList.
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
    /* 4bc */ u8 mCryptKey[0x108];
    /* 5c4 */ u32 mQueryOptions;
    /* 5c8 */ s32 mParseState;
    /* 5cc */ s32 mLanAdapterOverride;
    /* 5d0 */ int mDeadList;
} SbServerList;

extern SbServerList *gSortServerList;
extern s32 gGsiAcResult;
extern const char *gSBOverrideMasterServer;
extern char gGsiAcHostname[];

// Object behind gGsiAvailableCheck.
typedef struct GsiAvailableCheck {
    /* 00 */ s32 mSocket;
    /* 04 */ u8 mUnk_04[2];
    /* 06 */ u16 mPort;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u8 mPacketType;
    /* 0d */ u8 mUnk_0d[0x3f];
    /* 4c */ s32 mPacketLength;
    /* 50 */ u32 mSendTime;
    /* 54 */ s32 mRetryCount;
} GsiAvailableCheck;

extern GsiAvailableCheck gGsiAvailableCheck;
extern u8 gGsiAvailableCheckAddress[];
extern u8 gGsiAvailableCheckAddressIp[];
extern u8 gGsiAvailableCheckPacket[];
extern u8 gGsiAvailableCheckPacketGamename[];
extern char gGsiAcGamename[];
extern u8 gInternalInit[];
extern u8 NNMagicData[];
extern u8 gEmptyString[];
extern char gFmeKey[];
extern char gMdfKey[];
extern u8 gInitStateString[];
extern u8 gServerFullString[];
extern u8 gUnexpectedConnectAttemptString[];
extern u8 gYString[];
extern u8 gNString[];
extern char gAndEmptyParensString[];
extern char gGt2HostLengthAssert[];
extern char gGt2UtilityFileName[];
extern char gAddressPortFormat[];
extern char gAddressOnlyFormat[];
extern char gPortOnlyFormat[];
extern char gMatchup1HostnameDefault[];
extern char gMatchup2HostnameDefault[];
extern char gGamenameHostnameFormat[];
extern char data_ov000_021b4054[];
extern char gDwcGpCommandString[];
extern char gDwcGpCommandMatchString[];

extern char gGpMessagePrefixFormat[];
extern char gGpcmPrefix[];
extern char gMatTag[];
extern char gSlashUnsignedFormat[];
extern char gMatchingFilterFormat[];
extern char gAndParenFormat[];
extern char gKeyEqualsUnsignedFormat[];

#include "00/Lib/DWC/dwc_connectinet.h"
