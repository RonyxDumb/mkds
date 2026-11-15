#pragma once

#include "types.h"
#include "code_02142eac.h"
#include "code_0200aea8.h"

// 0x180-byte entries from 0x600 of MBiParam.
typedef struct ScanEntry {
    /* 000 */ u8 mUnk_000[0xc0];
    /* 0c0 */ WirelessMessage mMessage;
    /* 178 */ u8 mUnk_178[8];
} ScanEntry;

// Object behind gWirelessWork (0x1e00 bytes).
typedef struct MBiParam {
    /* 000 */ u8 mUnk_000[8];
    /* 008 */ u32 mGgid;
    /* 00c */ u16 mTgid;
    /* 00e */ u16 mEntryFlag;
    /* 010 */ u16 mMaxChildren;
    /* 012 */ u16 mMultiBootFlag;
    /* 014 */ u16 mKsFlag;
    /* 016 */ u16 mCsFlag;
    /* 018 */ u16 mBeaconPeriod;
    /* 01a */ u8 mUnk_01a[0x32 - 0x1a];
    /* 032 */ u16 mChannel;
    /* 034 */ u16 mParentMaxSize;
    /* 036 */ u16 mChildMaxSize;
    /* 038 */ u8 mReserved[8];
    /* 040 */ u8 mSendBuffer[0x400];
    /* 440 */ u8 mScanBuffer[0xc0];
    /* 500 */ u16 mSendDataSize;
    /* 502 */ u16 mReceiveDataSize;
    /* 504 */ void *mReceiveBuffer;
    /* 508 */ WirelessMessageCallback mCommandCallback;
    /* 50c */ u8 mDataQueued;
    /* 50d */ u8 mMbIsStarted;
    /* 50e */ u8 mReserved0[0x518 - 0x50e];
    /* 518 */ u16 mSendBufferSize;
    /* 51a */ u16 mReceiveBufferSize;
    /* 51c */ void (*mCallback)(s32, WirelessMessage *);
    /* 520 */ u16 *mPInfo;
    /* 524 */ u16 mMode;
    /* 526 */ u16 mResetting;
    /* 528 */ u16 mMPStarted;
    /* 52a */ u16 mConnectedAids;
    /* 52c */ u16 mContSend;
    /* 52e */ u8 mReserved1[2];
    /* 530 */ u16 mUname[4];
    /* 538 */ u16 mGname[16];
    /* 558 */ u8 mUnk_558[0x5e0 - 0x558];
    /* 5e0 */ u16 mScanEntryCount;
    /* 5e2 */ u16 mMyAid;
    /* 5e4 */ u32 mRepeatScan;
    /* 5e8 */ u32 mScanChannelFlag;
    /* 5ec */ u32 mLastScanEntry;
    /* 5f0 */ u8 mReserved8[0x10];
    /* 600 */ ScanEntry mScanEntries[16];
} MBiParam;

void MBi_OnInitializeDone(void);
u32 MBi_IsSendEnabled(void);
u32 changeScanChannel(ScanParam *scanParams);
