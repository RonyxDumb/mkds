#pragma once

#include "types.h"
#include "code_02142eac.h"
#include "code_021445e0.h"

// Values of WhWork.mConnectMode, given to StartWhParentConnect: what runs on the link once it is up and what is closed
// first on the way down. MP is plain MP communication, KEY_SHARING and ACTIVE_KEY_SHARING share keys, DATA_SHARING
// starts the data sharing; values 1 and 5 also end MP before the
// disconnect; no caller passes them (bare case labels).
enum {
    WIRELESS_CONNECT_MODE_MP = 0,
    WIRELESS_CONNECT_MODE_KEY_SHARING = 2,
    WIRELESS_CONNECT_MODE_ACTIVE_KEY_SHARING = 3,
    WIRELESS_CONNECT_MODE_DATA_SHARING = 4,
};

typedef struct WhWork {
    /* 0000 */ void *mUserGameInfo;
    /* 0004 */ u16 mUserGameInfoLength;
    /* 0006 */ u8 pad_06[2];
    /* 0008 */ u32 mUnk_08;
    /* 000c */ u16 mTgid;
    /* 000e */ u16 mEntryFlag;
    /* 0010 */ u16 mMaxEntry;
    /* 0012 */ u16 mUnk_12;
    /* 0014 */ u16 mKsFlag;
    /* 0016 */ u16 mUnk_16;
    /* 0018 */ u16 mBeaconPeriod;
    /* 001a */ u8 pad_1a[0x18];
    /* 0032 */ u16 mChannel;
    /* 0034 */ u16 mParentMaxSize;
    /* 0036 */ u16 mChildMaxSize;
    /* 0038 */ u8 pad_38[8];
    /* 0040 */ s32 mState;
    /* 0044 */ u32 mConnectMode;
    /* 0048 */ u32 mUnk_48;
    /* 004c */ s32 (*mConnectCallback)(WirelessMessage *);
    /* 0050 */ u16 mUnk_50;
    /* 0052 */ u16 mConnectedMask;
    /* 0054 */ s32 mUnk_54;
    /* 0058 */ u32 mRandomSeed;
    /* 005c */ u16 mDecidedChannel;
    /* 005e */ u16 mLowestBusyRatio;
    /* 0060 */ u16 mLowestBusyChannelMask;
    /* 0062 */ u8 pad_62[0x1e];
    /* 0080 */ u8 mWmSystemBuffer[0xf00];
    /* 0f80 */ u8 mSendBuffer[0xe0];
    /* 1060 */ u8 mReceiveBuffer[0x240];
    /* 12a0 */ u32 mSendBufferSize;
    /* 12a4 */ u32 mReceiveBufferSize;
    /* 12a8 */ u8 pad_12a8[0x100];
    /* 13a8 */ u32 mUnk_13a8;
    /* 13ac */ u32 (*mWepKeyCallback)(void *, struct WhWork *);
    /* 13b0 */ u32 mUnk_13b0;
    /* 13b4 */ u8 pad_13b4[0xc];
    /* 13c0 */ u8 mWepKey[0x20];
    /* 13e0 */ WMDataSharingInfo mDataSharingInfo;
    /* 1c00 */ WMDataSet mReceiveData;
    /* 1e00 */ WMDataSharingInfo mKeySharingBuf;
} WhWork;

extern WhWork *gWhWork;

BOOL EndWh(void);
void FinalizeWh(void);
void StartWhResetOrFail(void);
BOOL StepWhDataSharing(void *sendData);
u8 *GetWhSharedDataAddress(u32 aid);
void SetWhConnectCallback(u32 callback);
BOOL StartWhParentConnect(u32 mode, u16 tgid, u16 channel);
void StartWhInitializeCallback(WirelessMessage *event);
BOOL StartWhInitialize(void);
void WhIndicationCallback(WirelessMessage *event);
BOOL ClearWhAndInitialize(void);
int PickWhChannel(u16 channelMask);
u16 DecideWhChannel(void);
int StartWhMeasureChannel(Unk021425e8Func callback, u16 channel);
void StartWhMeasureChannelCallback(WirelessMessage *event);
u32 MeasureNextWhChannel(u16 channel);
BOOL StartWhChannelSearch(void);
u32 GetWhState(void);
u16 GetWhConnectedMask(void);
void SetWhGgid(u32 ggid);
void EndWhCallback(WirelessMessage *event);
void StartWhResetCallback(WirelessMessage *event);
BOOL StartWhReset(void);
void DisconnectWhCallback(WirelessMessage *event);
BOOL DisconnectWh(void);
void EndWhMPBeforeDisconnectCallback(WirelessMessage *event);
BOOL EndWhMPBeforeDisconnect(void);
BOOL EndActiveWhKeySharing(void);
void EndWhParentCallback(WirelessMessage *event);
BOOL EndWhParent(void);
void EndWhMPCallback(WirelessMessage *event);
BOOL EndWhMP(void);
BOOL EndWhKeySharing(void);
BOOL StartWhKeySharing(void);
void StartWhMPCallback(WirelessMessage *event);
BOOL StartWhMP(void);
void StartWhParentCallback(WirelessMessage *event);
BOOL StartWhParent(void);
void SetWhWepKeyCallback(WirelessMessage *event);
BOOL SetWhWepKey(void);
void SetWhParentParameterCallback(WirelessMessage *event);
BOOL SetWhParentParameter(void);
void SetWhErrorCode(s32 errorCode);
void SetWhState(u32 value);
void InitWhWork(WhWork *work);
