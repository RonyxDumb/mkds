#pragma once

#include "types.h"
#include "mb_gameinfo.h"
#include "Main/MapObjects/data_0217a000.h"

// Block the callback behind mScanCallback receives from CallScanCallbackWithEntry.
typedef struct ScanEntryArgs {
    /* 00 */ u16 mEntryIndex;
    /* 04 */ MBGameInfoRecvList *mEntry;
    /* 08 */ u8 *mScanBuffer;
    /* 0c */ u32 mUnk_0c;
} ScanEntryArgs;

// Block the callback behind mScanCallback receives from ReportScanError.
typedef struct ScanErrorArgs {
    /* 00 */ u16 mErrorCode;
    /* 02 */ u16 mResultCode;
} ScanErrorArgs;

#include "code_02142eac.h"

typedef struct MPLink {
    /* 00 */ UnkFunc *mCallback;
    /* 04 */ void *mSendBuffer;
    /* 08 */ u8 *mReceiveBuffer;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u16 mSendBufferSize;
    /* 12 */ u16 mReceiveBufferSize;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mMPStarted;
    /* 1c */ u16 mResetting;
    /* 1e */ u16 mUnk_1e;
    /* 20 */ u16 mDataQueued;
} MPLink;

typedef struct ScanConnectWork {
    /* 0000 */ u8 mUnk_0000[0x20];
    /* 0020 */ u8 mReceiveBuffer[0x480];
    /* 04a0 */ u8 mMessageBuffer[0x20];
    /* 04c0 */ WMBssDesc mScanBuffer;
    /* 0580 */ ScanParam mScanParams;
    /* 05a0 */ MPLink mMPLink;
    /* 05c4 */ u8 mUnk_05c4[0x18];
    /* 05dc */ void (*mScanCallback)(u32, void *);
    /* 05e0 */ void (*mStateCallback)(u32, void *);
    /* 05e4 */ u32 mUnk_05e4;
    /* 05e8 */ u8 mUnk_05e8[0x5ee - 0x5e8];
    /* 05ee */ u16 mUnk_05ee;
    /* 05f0 */ u8 mUnk_05f0[0x5ef8 - 0x5f0];
    /* 5ef8 */ u32 mRepeatScan;
    /* 5efc */ u32 mEndScanRequested;
    /* 5f00 */ u32 mUseScanBssid;
    /* 5f04 */ u32 mEndRequested;
    /* 5f08 */ u32 mUnk_5f08;
    /* 5f0c */ u16 mUnk_5f0c;
    /* 5f0e */ u16 mState;
} ScanConnectWork;

// Two halfwords that are passed on to the function at mUnk_00 of an MPLink.
typedef struct CommandResult {
    /* 00 */ u16 mCommand;
    /* 02 */ u16 mResultCode;
} CommandResult;


void ScanConnectEndScan(void);
void RequestEndScan(void);
u32 PickScanChannel(void);
void EntryCallback(u32 event, void *entry, u32 entryIndex);
void ClearUseScanBssid(void);
void SetScanBssid(const u8 *bssid);
void ReportScanError(u16 errorCode, u16 resultCode);
void CallScanCallbackWithEntry(u32 event, MBGameInfoRecvList *entry, u32 entryIndex);
void ScanConnectStartScanCallback(Unk021425e8 *result);
void ScanConnectStartScan(void);
void StartRepeatedScan(UnkFunc *callback, u32 param);
void SetScanConnectStateAndNotify(u32 state, void *info);
void SetScanConnectStateCallback(UnkFunc *callback);
unsigned int GetScanConnectWorkSize(void);
void FinishScanConnect(void);
void CloseScanConnect(void);
void InitScanConnectWork(ScanConnectWork *work, void *initData);
void ClearPortCallback(void);
void QueueMPDataCallback(Unk021425e8 *result);
s32 QueueMPDataIfReady(u32 dataSize, u16 destBitmap, u8 *data);
void PortCallback(Unk021425e8 *result);
u32 IsMPReadyToQueueData(void);
void StartResetCallback(Unk021425e8 *result);
void StartReset(void);
void StartResetWithFlagCallback(Unk021425e8 *result);
void StartResetWithFlag(void);
void ScanConnectStartMPCallback(Unk021425e8 *result);
void SetPortCallbackAndStartMP(void *sendBuffer, u8 *receiveBuffer);
void ScanConnectStartConnectCallback(Unk021425e8 *result);
void ScanConnectStartConnect(WMBssDesc *scanBuffer);
void SetMPLinkCallback(UnkFunc *callback);
void SetupMPLink(MPLink *link);

extern const u8 gDefaultScanBssid[6];
extern u16 gScanConnectInitialized;
extern struct MPLink *gMPLink;
extern struct ScanConnectWork *gScanConnectWork;
