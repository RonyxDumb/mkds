#pragma once

#include "00/code_02180608.h"
#include "00/code_021acef8.h"
#include "00/code_021ad734.h"
#include "00/code_02186d04.h"
#include "00/code_02187484.h"
#include "00/code_02188008.h"
#include "00/code_021884d8.h"
#include "00/code_0218e2dc.h"
#include "00/code_021a3a18.h"

#include "types.h"
#include "00/code_021a6fa8.h"

// Settings func_ov000_021a72c4 reads and func_ov000_021a71c0 applies.
typedef struct SOCLSocketParam {
    /* 00 */ s8 mUnk_00;
    /* 01 */ s8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ Unk021a72a4 mUnk_10;
    /* 14 */ Unk021a72a4 mUnk_14;
} SOCLSocketParam;

// Objects whose layout isn't known yet.
extern u32 data_ov000_021b49b4;
extern SOCLSocketParam data_ov000_021b49b8;
extern SOCLSocketParam data_ov000_021b49d0;
extern char gBuddyAuthorizedMessage[];
extern char gDwcGpSstrKeyMatchScMax[];
extern char gDwcGpSstrKeyMatchScNum[];
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
extern char data_ov000_021b41f0[];
extern u8 data_ov000_021b4200[];
extern u8 data_ov000_021b4228[];
extern u8 data_ov000_021b424c[];
extern u32 data_ov000_021b49f4;
extern char data_ov000_021b4388[];
extern char data_ov000_021b4394[];
extern char data_ov000_021b43a0[];
extern char data_ov000_021b43a8[];
extern char data_ov000_021b43ac[];
extern char data_ov000_021b43b0[];
extern char data_ov000_021b43c0[];
extern char data_ov000_021b43cc[];
extern char data_ov000_021b43d8[];
extern char data_ov000_021b41f4[];
extern Unk021a3eb0 data_ov000_021b4270;
extern Unk021a4a08 *data_ov000_021b426c;
extern char data_ov000_021b43f8[];
extern char data_ov000_021b4400[];
extern char data_ov000_021b4404[];
extern char data_ov000_021b440c[];
extern char data_ov000_021b4418[];
extern char data_ov000_021b4428[];
extern u8 data_ov000_021b442c[];
extern char data_ov000_021b4464[];
extern char data_ov000_021b43e4[];
extern u8 gSrvrText[];
extern u8 gClntText[];
extern u16 gOfferedValues[2];
extern const char *data_ov000_021b4a30[];
extern u8 gLabelAText[];
extern u8 gLabelBBText[];
extern u8 gLabelCCCText[];
extern u8 data_ov000_021b4be4[];
extern u8 data_ov000_021b4be5[];
extern u8 gWiFiVSCourseSelectState[];
extern Http *gHttp;
extern DWCNetcheck *gNetcheck;
extern Unk02188408 *gAcWork;
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

extern WiFiSelectHeapHolder *gWiFiSelectCharacterState;
extern WiFiSelectHeapHolder *gWiFiSelectKartState;

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
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[2];
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d[0x3f];
    /* 4c */ s32 mUnk_4c;
    /* 50 */ u32 mUnk_50;
    /* 54 */ s32 mUnk_54;
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
extern char data_ov000_021b3fcc[];
extern char data_ov000_021b3fec[];
extern char data_ov000_021b3ffc[];
extern char data_ov000_021b4004[];
extern char data_ov000_021b4008[];
extern char gMatchup1HostnameDefault[];
extern char gMatchup2HostnameDefault[];
extern char data_ov000_021b404c[];
extern char data_ov000_021b4054[];
extern char gDwcGpCommandString[];
extern char gDwcGpCommandMatchString[];
extern u8 data_ov000_021b4064[];
extern char data_ov000_021b4068[];

extern char gGpMessagePrefixFormat[];
extern char gGpcmPrefix[];
extern char gMatTag[];
extern char gSlashUnsignedFormat[];
extern char gMatchingFilterFormat[];
extern char gAndParenFormat[];
extern char gKeyEqualsUnsignedFormat[];

#include "00/code_021a3760.h"
