#pragma once

#include "00/code_0219b580.h"
#include "00/code_0219c384.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"
#include "00/code_0219de4c.h"
#include "types.h"
#include "00/code_021a4b98.h"
#include "00/code_021a2ccc.h"
#include "00/dwc_connectinet.h"
#include "code_02142eac.h" // ScanExParam
#include "code_0200f790.h"
#include "00/code_021a6fa8.h"
#include "code_0200e77c.h"

// One element of the table at gLocalIpList.
typedef struct SOCInAddr {
    /* 0 */ u32 addr;
} SOCInAddr;

typedef void (*Unk021b5f54Func)(void *param_1, void *param_2, void *param_3, u16 param_4);

typedef struct WCMCpsifWork {
    /* 00 */ u8 mInitialized;
    /* 04 */ OSThreadQueue mSendQ;
    /* 0c */ OSMutex mSendMutex;
    /* 24 */ s32 mSendResult;
    /* 28 */ Unk021b5f54Func mRecvCallback;
} WCMCpsifWork;

typedef struct SOCLConfig {
    /* 00 */ s32 mUseDhcp;
    /* 04 */ u32 mMyIp;
    /* 08 */ u32 mNetMask;
    /* 0c */ u32 mGatewayIp;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ void *(*mAlloc)(u32 param_1);
    /* 1c */ void (*mFree)(void *param_1);
    /* 20 */ s32 mCmdPacketMax;
    /* 24 */ s32 mLanBufLen;
    /* 28 */ void *mLanBuf;
    /* 2c */ s32 mCpsThreadPriority;
    /* 30 */ s32 mMtu;
    /* 34 */ s32 mRwin;
} SOCLConfig;

typedef struct CPSConfig {
    /* 00 */ s32 mMode;
    /* 04 */ void *(*mAlloc)(u32 param_1);
    /* 08 */ void (*mFree)(void *param_1);
    /* 0c */ void (*mDhcpCallback)(void);
    /* 10 */ u32 (*mLinkIsOn)(void);
    /* 14 */ s32 mRandomSeedLow;
    /* 18 */ s32 mRandomSeedHigh;
    /* 1c */ void *mLanBuf;
    /* 20 */ s32 mLanBufLen;
    /* 24 */ s32 mMyMss;
    /* 28 */ u32 mRequestedIp;
    /* 2c */ u32 mYieldWait;
} CPSConfig;

// Objects whose layout isn't known yet.
extern u8 gFreeFunc[];
extern u8 gAllocFunc[];
extern WCMWork *gWcmWork;
extern u8 SOCLiYieldWait[];

extern u8 gMatchingMaskedParticipantIndices[0x20];

// Four bytes at gOptSCBlock.
typedef struct DWCMatchOptSCBlock {
    /* 00 */ u8 mValid;
    /* 01 */ u8 mLock;
    /* 02 */ u16 mPad;
} DWCMatchOptSCBlock;

extern DWCMatchOptSCBlock gOptSCBlock;

typedef struct DWCMatchOptMinCompleteIn {
    /* 00 */ u8 mValid;
    /* 01 */ u8 mMinEntry;
    /* 02 */ u8 mRetry;
    /* 03 */ u8 mPad;
    /* 04 */ u32 mTimeout;
    /* 08 */ u32 mRecvBit;
    /* 0c */ u32 mTimeoutBit;
    /* 10 */ u64 mStartTime;
    /* 18 */ u64 mLastPollTime;
} DWCMatchOptMinCompleteIn;

extern DWCMatchOptMinCompleteIn *gOptMinComp;
extern void *gMatchingFilterText;
extern WCMCpsifWork gWcmCpsifWork;
extern u8 gWcmRssiIndex;
extern u8 gWcmRssi[16];
extern SOCLConfig *SOCLiConfigPtr;
extern u32 SOCLiRequestedIP;
extern SOCLSocket *SOCLiUDPSendSocket;
extern CPSConfig SOCLiCPSConfig;
extern void *SOCLiCommandPackets;
extern OSMessageQueue SOCLiCommandPacketQueue;

extern s32 nIndex;
extern char strAddressArray[2][0x16];
extern char *Matchup2Hostname;
extern char *Matchup1Hostname;
extern u32 matchup2ip;
extern u32 matchup1ip;
extern void *negotiateList;
extern u8 gNatNegReceiveBuffer[];
extern s32 stLastSocketError;
extern void *pStRemoteAuthParam;
extern void (*stRemoteAuthCallback)();
