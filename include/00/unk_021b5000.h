#pragma once

#include "00/Lib/DWC/code_0219b1f8.h"
#include "00/Lib/DWC/code_0219c384.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"
#include "00/code_0219de4c.h"
#include "types.h"
#include "00/Lib/NitroWiFi/code_021a4b98.h"
#include "00/Lib/DWC/code_021a2ccc.h"
#include "00/Lib/DWC/dwc_connectinet.h"
#include "code_02142eac.h" // ScanExParam
#include "code_0200f790.h"
#include "00/code_021a6fa8.h"
#include "code_0200e77c.h"

// One element of the table at gLocalIpList.
typedef struct SOCInAddr {
    /* 0 */ u32 addr;
} SOCInAddr;

typedef void (*WCMRecvInd)(void *srcAddr, void *dstAddr, void *buffer, u16 size);

typedef struct WCMCpsifWork {
    /* 00 */ u8 mInitialized;
    /* 04 */ OSThreadQueue mSendQ;
    /* 0c */ OSMutex mSendMutex;
    /* 24 */ s32 mSendResult;
    /* 28 */ WCMRecvInd mRecvCallback;
} WCMCpsifWork;

typedef struct SOCLConfig {
    /* 00 */ s32 mUseDhcp;
    /* 04 */ u32 mMyIp;
    /* 08 */ u32 mNetMask;
    /* 0c */ u32 mGatewayIp;
    /* 10 */ u32 mDnsFirstIp;
    /* 14 */ u32 mDnsSecondIp;
    /* 18 */ void *(*mAlloc)(u32 size);
    /* 1c */ void (*mFree)(void *block);
    /* 20 */ s32 mCmdPacketMax;
    /* 24 */ s32 mLanBufLen;
    /* 28 */ void *mLanBuf;
    /* 2c */ s32 mCpsThreadPriority;
    /* 30 */ s32 mMtu;
    /* 34 */ s32 mRwin;
} SOCLConfig;

typedef struct CPSConfig {
    /* 00 */ s32 mMode;
    /* 04 */ void *(*mAlloc)(u32 size);
    /* 08 */ void (*mFree)(void *block);
    /* 0c */ void (*mDhcpCallback)(void);
    /* 10 */ u32 (*mLinkIsOn)(void);
    /* 14 */ u64 mRandomSeed;
    /* 1c */ void *mLanBuf;
    /* 20 */ s32 mLanBufLen;
    /* 24 */ s32 mMyMss;
    /* 28 */ u32 mRequestedIp;
    /* 2c */ u32 mYieldWait;
} CPSConfig;

// Four bytes at gOptSCBlock.
typedef struct DWCMatchOptSCBlock {
    /* 00 */ u8 mValid;
    /* 01 */ u8 mLock;
    /* 02 */ u16 mPad;
} DWCMatchOptSCBlock;

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

extern WCMCpsifWork gWcmCpsifWork;

extern char *Matchup2Hostname;
extern char *Matchup1Hostname;
extern u32 matchup2ip;
extern u32 matchup1ip;
extern void *negotiateList;
