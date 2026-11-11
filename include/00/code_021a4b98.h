#pragma once

#include "types.h"
#include "code_02142eac.h"
#include "code_0200f790.h"

// Event the function at mNotify is called with; built by WcmNotifyEx.
typedef struct WCMNotice {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ void *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} WCMNotice;

// 0xd0 bytes. Entry of the list at mPbdBuffer of an WCMWork.
typedef struct WCMApList {
    /* 00 */ u8 mState;
    /* 02 */ u16 mLinkLevel;
    /* 04 */ u32 mIndex;
    /* 08 */ struct WCMApList *mPrevious;
    /* 0c */ struct WCMApList *mNext;
    /* 10 */ u8 mData[0xc0];
} WCMApList;

// Header of the list at mPbdBuffer of an WCMWork: count, first and last entry, then the entries.
typedef struct WCMApListHeader {
    /* 00 */ u32 mCount;
    /* 04 */ WCMApList *mHead;
    /* 08 */ WCMApList *mTail;
    /* 0c */ WCMApList mUnk_0c[1];
} WCMApListHeader;

// 0x2300 bytes; the word gWcmWork points to it.
typedef struct WCMWork {
    /* 0000 */ u8 mWmWork[0xf00];
    /* 0f00 */ u8 mSendBuf[0x600];
    /* 1500 */ u8 mRecvBuf[0xc40];
    /* 2140 */ u8 mBssDesc[4];
    /* 2144 */ u8 mBssid[6];
    /* 214a */ u16 mSsidLength;
    /* 214c */ u8 mSsid[0x22];
    /* 216e */ u16 mBasicRateSet;
    /* 2170 */ u16 mSupportRateSet;
    /* 2172 */ u8 mUnk_2172[0x8e];
    /* 2200 */ u8 mWepKey[0x50];
    /* 2250 */ u8 mWepMode;
    /* 2251 */ u8 mWepKeyId;
    /* 2252 */ u8 mUnk_2252[0xe];
    /* 2260 */ s32 mPhase;
    /* 2264 */ u32 mOption;
    /* 2268 */ u16 mMaxScanTime;
    /* 226a */ u8 mApListLock;
    /* 226b */ u8 mResetting;
    /* 226c */ u32 mDmaNo;
    /* 2270 */ WCMApListHeader *mPbdBuffer;
    /* 2274 */ u32 mNbdBuffer;
    /* 2278 */ u32 mNbdMode;
    /* 227c */ void (*mNotify)(WCMNotice *);
    /* 2280 */ s16 mNotifyId;
    /* 2282 */ u16 mAuthId;
    /* 2284 */ s32 mScanCount;
    /* 2288 */ ScanExParam mScanExParam;
    /* 22c0 */ u8 mUnk_22c0[0xc];
    /* 22cc */ OSAlarm mKeepAliveAlarm;
    /* 22f8 */ u16 mWlStatusOnConnectFail;
    /* 22fa */ u8 mUnk_22fa[6];
} WCMWork;

// Event of the callbacks WcmWmcbConnect and WcmWmcbScanEx take.
typedef struct Unk021a5088 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u8 *mUnk_10[16];
    /* 50 */ u16 mUnk_50[16];
} Unk021a5088;

void WcmWmcbCommon(Unk021425e8 *event);

u32 WcmCountBits(u32 bits);
u32 WcmCountLeadingZero(u32 value);
void WcmWmcbReset(Unk021425e8 *event);
void WcmWmcbEndDCF(Unk021425e8 *event);
void WcmWmcbStartDCF(Unk021425e8 *event);
void WcmWmcbDisconnect(Unk021425e8 *event);
void WcmWmcbConnect(Unk021a5088 *event);
void WcmWmcbEndScan(Unk021425e8 *event);
void WcmWmcbScanEx(Unk021a5088 *event);
u32 WCM_GetPhase(void);
s32 WCM_DisconnectAsync(void);
s32 WCM_EndSearchAsync(void);
s32 WCM_CleanupAsync(void);
