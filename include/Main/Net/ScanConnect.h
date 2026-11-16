#pragma once

#include "types.h"
#include "Main/Unknown/code_02008934.h"

// Block the callback behind mScanCallback receives from MBFi_ScanCallback.
typedef struct ScanEntryArgs {
    /* 00 */ u16 mEntryIndex;
    /* 04 */ EntryRecord *mEntry;
    /* 08 */ u8 *mScanBuffer;
    /* 0c */ u32 fieldC;
} ScanEntryArgs;

// Block the callback behind mScanCallback receives from MBFi_ScanErrorCallback.
typedef struct ScanErrorArgs {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
} ScanErrorArgs;

#include "code_02142eac.h"

typedef struct ScanConnectWork {
    /* 0000 */ u8 field0[0x20];
    /* 0020 */ u8 mReceiveBuffer[0x480];
    /* 04a0 */ u8 mMessageBuffer[0x20];
    /* 04c0 */ u8 mScanBuffer[0xc0];
    /* 0580 */ Unk02143a78 mScanParams;
    /* 0590 */ u8 field590[0x10];
    /* 05a0 */ u8 mMPLink[0x24];
    /* 05c4 */ u8 field5C4[0x18];
    /* 05dc */ void (*mScanCallback)(u32, void *);
    /* 05e0 */ void (*mStateCallback)(u32, void *);
    /* 05e4 */ u32 field5E4;
    /* 05e8 */ u8 field5E8[0x5ee - 0x5e8];
    /* 05ee */ u16 field5EE;
    /* 05f0 */ u8 field5F0[0x5ef8 - 0x5f0];
    /* 5ef8 */ u32 mRepeatScan;
    /* 5efc */ u32 mEndScanRequested;
    /* 5f00 */ u32 mUseScanBssid;
    /* 5f04 */ u32 mEndRequested;
    /* 5f08 */ u32 field5F08;
    /* 5f0c */ u16 field5F0C;
    /* 5f0e */ u16 mState;
} ScanConnectWork;

typedef struct MPLink {
    /* 00 */ UnkFunc *mCallback;
    /* 04 */ void *mSendBuffer;
    /* 08 */ u8 *mReceiveBuffer;
    /* 0c */ u8 fieldC[4];
    /* 10 */ u16 mSendBufferSize;
    /* 12 */ u16 mReceiveBufferSize;
    /* 14 */ u16 field14;
    /* 16 */ u16 field16;
    /* 18 */ u16 field18;
    /* 1a */ u16 mMPStarted;
    /* 1c */ u16 mResetting;
    /* 1e */ u16 field1E;
    /* 20 */ u16 mDataQueued;
} MPLink;

// Two halfwords that are passed on to the function at field0 of an MPLink.
typedef struct CommandResult {
    /* 00 */ u16 mCommand;
    /* 02 */ u16 mResultCode;
} CommandResult;

extern u8 gDefaultScanBssid[6];

// Declared here until the code that defines it is decompiled.
void MBFi_StateInEndScan(void);
void RequestEndScan(void);
u32 RotateChannel(void);
void MBFi_CommBeaconRecvCallback(u32 a, void *entry, u32 entryIndex);
u32 MBFi_ScanUnlock(void);
void MBFi_ScanLock(const u8 *a);
void MBFi_ScanErrorCallback(u16 a, u16 b);
void MBFi_ScanCallback(u32 a, EntryRecord *entry, u32 entryIndex);
void MBFi_StateOutStartScanParent(Unk021425e8 *a);
void MBFi_StateInStartScan(void);
void MB_FakeStartScanParent(UnkFunc *callback, u32 b);
void MBFi_CommChangeChildState(u32 state, void *b);
void MB_FakeSetCStateCallback(UnkFunc *callback);
unsigned int MB_FakeGetWorkSize(void);
void MBFi_EndComplete(void);
void MB_FakeEnd(void);
void MB_FakeInit(ScanConnectWork *a, void *b);
void MBi_WMClearCallback(void);
void QueueMPDataCallback(Unk021425e8 *a);
s32 QueueMPDataIfReady(u32 a, u16 b, u8 *c);
void PortCallback(Unk021425e8 *a);
u32 IsMPReadyToQueueData(void);
void StartResetCallback(Unk021425e8 *a);
void StartReset(void);
void StartResetWithFlagCallback(Unk021425e8 *a);
void StartResetWithFlag(void);
void ScanConnectStartMPCallback(Unk021425e8 *a);
void SetPortCallbackAndStartMP(void *sendBuffer, u8 *receiveBuffer);
void ScanConnectStartConnectCallback(Unk021425e8 *a);
void MBi_WMStartConnect(u8 *scanBuffer);
void MBi_WMSetCallback(unsigned int callback);
u32 MBi_WMSetBuffer(u32 arg0);
