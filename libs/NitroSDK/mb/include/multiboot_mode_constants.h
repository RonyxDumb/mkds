#pragma once

#include "types.h"
#include "wireless_link_control.h"
#include "multiboot_cache_init.h"

// Values of MBiParam.mMode: the parent side is set up here, the child side is never entered in this build.
enum {
    MULTIBOOT_MODE_PARENT = 1,
    MULTIBOOT_MODE_CHILD = 2,
};

// Parent set-up values: data bytes sent and received per MP exchange, children allowed and the beacon period base; and
// the longest time per channel a scan falls back on when none is set (child scan only, not run in this build).
#define MULTIBOOT_PARENT_SEND_DATA_SIZE 0x100
#define MULTIBOOT_PARENT_RECEIVE_DATA_SIZE 8
#define MULTIBOOT_MAX_CHILDREN 0xf
#define MULTIBOOT_BEACON_PERIOD_BASE 0xc8
#define MULTIBOOT_SCAN_DEFAULT_MAX_CHANNEL_TIME 0xc8

// Bytes of the game info the beacon of a multiboot parent carries.
#define MULTIBOOT_BEACON_GAME_INFO_LENGTH 0x10

// One scan result of the multiboot parent list; mMessage holds the received message.
typedef struct ScanEntry {
    /* 000 */ u8 mUnk_000[0xc0];
    /* 0c0 */ WirelessMessage mMessage;
    /* 178 */ u8 mUnk_178[8];
} ScanEntry;

// The multiboot wireless work: the game group id, mEntryFlag, mMultiBootFlag, mMaxChildren, mKsFlag and mCsFlag.
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
    /* 520 */ WMBssDesc *mPInfo;
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
