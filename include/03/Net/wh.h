#pragma once

#include "types.h"
#include "wireless_link_control.h"
#include "wireless_key_data_sharing.h"

typedef void (*WhPrintFunction)(u32 flags, const char *format, ...);

// Values of WhWork.mConnectMode, given to StartWhParentConnect: what runs on the link once it is up and what is closed
// first on the way down. MP is plain MP communication, KEY_SHARING and ACTIVE_KEY_SHARING share keys, DATA_SHARING
// starts the data sharing; END_MP_FIRST and its second value also end MP before the disconnect. StartWhParentConnect
// accepts only MP, KEY_SHARING and DATA_SHARING and its only caller passes DATA_SHARING; the other values are only
// cases in FinalizeWh.
enum {
    WIRELESS_CONNECT_MODE_MP = 0,
    WIRELESS_CONNECT_MODE_END_MP_BEFORE_DISCONNECT = 1,
    WIRELESS_CONNECT_MODE_KEY_SHARING = 2,
    WIRELESS_CONNECT_MODE_KEY_SHARING_END_CHECKED = 3,
    WIRELESS_CONNECT_MODE_DATA_SHARING = 4,
    WIRELESS_CONNECT_MODE_END_MP_FIRST_ALSO = 5,
};

// Buffer sizes and the largest parent and child data sizes StartWhParentConnect sets, and the value
// StartWhChannelSearch starts mLowestBusyRatio from.
#define WH_RECEIVE_BUFFER_SIZE 0x180
#define WH_SEND_BUFFER_SIZE 0xe0
#define WH_PARENT_MAX_SIZE 0xd0
#define WH_CHILD_MAX_SIZE 0x44
#define WH_LOWEST_BUSY_RATIO_START 0x65

// Values of WhWork.mState. Names 0 to 9 come from the state name table; 10 has no name and is set when initialize,
// reset start or end fails.
enum {
    WH_STATE_STOP,
    WH_STATE_IDLE,
    WH_STATE_SCANNING,
    WH_STATE_BUSY,
    WH_STATE_CONNECTED,
    WH_STATE_DATA_SHARING,
    WH_STATE_KEY_SHARING,
    WH_STATE_MEASURE_CHANNEL,
    WH_STATE_CONNECT_FAIL,
    WH_STATE_ERROR,
    WH_STATE_INIT_RESET_OR_END_FAILED,
};

// The wireless link work (gWhWork): its parent parameters, state, connect mode and callback, connected mask and channel
// choice.
typedef struct WhWork {
    /* 0000 */ ParentParameter mParentParameter;
    /* 0038 */ u8 pad_38[8];
    /* 0040 */ s32 mState;
    /* 0044 */ u32 mConnectMode;
    /* 0048 */ u32 mUnk_48;
    /* 004c */ u32 (*mConnectCallback)(WirelessMessage *);
    /* 0050 */ u16 mUnk_50;
    /* 0052 */ u16 mConnectedMask;
    /* 0054 */ s32 mErrorCode;
    /* 0058 */ u32 mRandomSeed;
    /* 005c */ u16 mDecidedChannel;
    /* 005e */ u16 mLowestBusyRatio;
    /* 0060 */ u16 mLowestBusyChannelMask;
    /* 0062 */ u8 pad_62[0x1e];
    /* 0080 */ u8 mWmSystemBuffer[0xf00];
    /* 0f80 */ u8 mSendBuffer[WH_SEND_BUFFER_SIZE];
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
void SetWhConnectCallback(u32 (*callback)(WirelessMessage *));
BOOL StartWhParentConnect(u32 mode, u16 tgid, u16 channel);
void StartWhInitializeCallback(WirelessMessage *event);
BOOL StartWhInitialize(void);
void WhIndicationCallback(WirelessMessage *event);
BOOL ClearWhAndInitialize(void);
int PickWhChannel(u16 channelMask);
u16 DecideWhChannel(void);
int StartWhMeasureChannel(WirelessMessageCallback callback, u16 channel);
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
