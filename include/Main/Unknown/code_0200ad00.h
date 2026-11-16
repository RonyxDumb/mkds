#pragma once

#include "types.h"
#include "code_02142eac.h"

// 0x180-byte entries from 0x600 of WirelessWork.
typedef struct ScanEntry {
    /* 000 */ u8 field0[0xc0];
    /* 0c0 */ Unk021425e8 mMessage;
    /* 178 */ u8 field178[8];
} ScanEntry;

// Object behind gWirelessWork (0x1e00 bytes).
typedef struct WirelessWork {
    /* 000 */ u8 field0[8];
    /* 008 */ u32 mGgid;
    /* 00c */ u16 mTgid;
    /* 00e */ u16 fieldE;
    /* 010 */ u16 mMaxChildren;
    /* 012 */ u16 field12;
    /* 014 */ u16 field14;
    /* 016 */ u16 field16;
    /* 018 */ u16 mBeaconPeriod;
    /* 01a */ u8 field1A[0x32 - 0x1a];
    /* 032 */ u16 mChannel;
    /* 034 */ u16 field34;
    /* 036 */ u16 field36;
    /* 038 */ u8 field38[8];
    /* 040 */ u8 mSendBuffer[0x400];
    /* 440 */ u8 mScanBuffer[0xc0];
    /* 500 */ u16 mSendDataSize;
    /* 502 */ u16 mReceiveDataSize;
    /* 504 */ void *mReceiveBuffer;
    /* 508 */ Unk021425e8Func mCommandCallback;
    /* 50c */ u8 mDataQueued;
    /* 50d */ u8 field50D;
    /* 50e */ u8 field50E[0x518 - 0x50e];
    /* 518 */ u16 mSendBufferSize;
    /* 51a */ u16 mReceiveBufferSize;
    /* 51c */ void (*mCallback)(s32, Unk021425e8 *);
    /* 520 */ u16 *field520;
    /* 524 */ u16 mMode;
    /* 526 */ u16 mResetting;
    /* 528 */ u16 mMPStarted;
    /* 52a */ u16 mConnectedAids;
    /* 52c */ u16 field52C;
    /* 52e */ u8 field52E[2];
    /* 530 */ u16 field530[4];
    /* 538 */ u16 field538[16];
    /* 558 */ u8 field558[0x5e0 - 0x558];
    /* 5e0 */ u16 mScanEntryCount;
    /* 5e2 */ u16 field5E2;
    /* 5e4 */ u32 mRepeatScan;
    /* 5e8 */ u32 field5E8;
    /* 5ec */ u32 mLastScanEntry;
    /* 5f0 */ u8 field5F0[0x10];
    /* 600 */ ScanEntry mScanEntries[16];
} WirelessWork;

// 0x10-byte entries from 0x30 of DataRangeTable.
typedef struct DataRange {
    /* 00 */ u32 mOffset;
    /* 04 */ u32 mSize;
    /* 08 */ u8 *mData;
    /* 0c */ u32 fieldC;
} DataRange;

typedef struct DataRangeTable {
    /* 00 */ u32 field0;
    /* 04 */ u8 field4[0xc];
    /* 10 */ u8 field10[4];
    /* 14 */ s32 field14;
    /* 18 */ u8 field18[0x18];
    /* 30 */ DataRange field30[4];
} DataRangeTable;

void func_0200ad00(void);
u32 IsMPReadyToSendData(void);
u32 AdvanceScanChannel(Unk02143a78 *scanParams);
u32 CopyFromDataRanges(DataRangeTable *table, u32 offset, void *destination, u32 byteCount);
void AddDataRange(DataRangeTable *table, u32 offset, u32 size, u8 *data, u32 value);
