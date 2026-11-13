#include "03/Net/wh.h"

#include "03/code_021d0000.h"
#include "wm_etc.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_021445e0.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"

char *gWhStateNames[10] = {
    gWhStateStopName,         gWhStateIdleName,          gWhStateScanningName,      gWhStateBusyName,
    gWhStateConnectedName,    gWhStateDataSharingName,   gWhStateKeySharingName,    gWhStateMeasureChannelName,
    gWhStateConnectFailName,  gWhStateErrorName,
};
char gWhStateMeasureChannelName[36] = "DWCi_MOV_WH_SYSSTATE_MEASURECHANNEL";
char gWhStateConnectFailName[34] = "DWCi_MOV_WH_SYSSTATE_CONNECT_FAIL";
char gWhStateDataSharingName[33] = "DWCi_MOV_WH_SYSSTATE_DATASHARING";
char gWhStateKeySharingName[32] = "DWCi_MOV_WH_SYSSTATE_KEYSHARING";
char gWhStateConnectedName[31] = "DWCi_MOV_WH_SYSSTATE_CONNECTED";
char gWhStateScanningName[30] = "DWCi_MOV_WH_SYSSTATE_SCANNING";
char gWhStateErrorName[27] = "DWCi_MOV_WH_SYSSTATE_ERROR";
char gWhStateIdleName[26] = "DWCi_MOV_WH_SYSSTATE_IDLE";
char gWhStateStopName[26] = "DWCi_MOV_WH_SYSSTATE_STOP";
char gWhStateBusyName[26] = "DWCi_MOV_WH_SYSSTATE_BUSY";

BOOL StartWhChannelSearch(void) {
    u16 macAddress[3];
    u32 result;
    u32 seed;

    OS_GetMacAddress(macAddress);
    seed = *(u32 *) 0x27ffc3c;
    seed = macAddress[0] + seed + macAddress[1] + macAddress[2];
    gWhWork->mRandomSeed = seed;
    gWhWork->mRandomSeed = gWhWork->mRandomSeed * 0x10dcd + 0x3039;
    gWhWork->mDecidedChannel = 0;
    gWhWork->mLowestBusyRatio = 0x65;
    SetWhState(3);
    result = MeasureNextWhChannel(1);
    if (result == 0x18) {
        SetWhErrorCode(0x18);
        SetWhState(9);
        return FALSE;
    }
    if (result != 2) {
        SetWhErrorCode(result);
        SetWhState(9);
        return FALSE;
    }
    return TRUE;
}

u32 MeasureNextWhChannel(u16 channel) {
    u16 allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0x8000) {
        SetWhErrorCode(3);
        SetWhState(9);
        return 3;
    }
    if (allowedChannels == 0) {
        SetWhErrorCode(0x16);
        SetWhState(9);
        return 0x18;
    }
    while (((1 << (channel - 1)) & allowedChannels) == 0) {
        channel++;
        if (channel > 0x10) {
            return 0x18;
        }
    }
    return (u16) StartWhMeasureChannel(StartWhMeasureChannelCallback, channel);
}

void StartWhMeasureChannelCallback(WirelessMessage *event) {
    u16 channel;
    u16 busyRatio;
    u32 result;

    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        SetWhState(9);
        return;
    }
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, "channel %d bratio = %x\n", event->mReplyState, event->mUnk_08_2);
    }
    channel = event->mReplyState;
    busyRatio = event->mUnk_08_2;
    if (gWhWork->mLowestBusyRatio > busyRatio) {
        gWhWork->mLowestBusyRatio = busyRatio;
        gWhWork->mLowestBusyChannelMask = 1 << (channel - 1);
    } else if (gWhWork->mLowestBusyRatio == busyRatio) {
        gWhWork->mLowestBusyChannelMask = gWhWork->mLowestBusyChannelMask | (1 << (channel - 1));
    }
    result = MeasureNextWhChannel(channel + 1);
    if (result == 0x18) {
        SetWhState(7);
        return;
    }
    if (result != 2) {
        SetWhState(9);
    }
}

int StartWhMeasureChannel(Unk021425e8Func callback, u16 channel) {
    return WM_MeasureChannel(callback, 3, 0x11, channel, 0x1e);
}

u16 DecideWhChannel(void) {
    WhWork **workAddress;
    u16 channel;
    if (gWhWork->mState != 7) {
        OS_Terminate();
    }
    SetWhState(1);
    channel = PickWhChannel((u32) (gWhWork->mLowestBusyChannelMask));
    workAddress = &gWhWork;
    gWhWork->mDecidedChannel = channel;
    if ((UnkFunc *) (*(u32 *) &gWhPrintFunction) != NULL) {
        (*(UnkFunc *) (*(u32 *) &gWhPrintFunction))((0x08000000u), (u32) "decided channel = %d\n",
                                                    (*workAddress)->mDecidedChannel);
    }
    return gWhWork->mDecidedChannel;
}

int PickWhChannel(u16 channelMask) {
    s16 lastChannel;
    s16 bitIndex;
    u16 bitCount;
    u16 skipCount;
    s16 channelIndex;

    lastChannel = 0;
    bitCount = 0;
    for (bitIndex = 0; bitIndex < 16; bitIndex++) {
        if ((channelMask & (1 << bitIndex)) != 0) {
            lastChannel = bitIndex + 1;
            bitCount++;
        }
    }
    if (bitCount > 1) {
        gWhWork->mRandomSeed = gWhWork->mRandomSeed * 0x10dcd + 0x3039;
        skipCount = (bitCount * (gWhWork->mRandomSeed & 0xff)) >> 8;
        for (channelIndex = 0; channelIndex < 16; channelIndex++) {
            if ((channelMask & 1) != 0) {
                if (skipCount == 0) {
                    return (s16) (channelIndex + 1);
                }
                skipCount--;
            }
            channelMask = channelMask >> 1;
        }
        return 0;
    }
    return lastChannel;
}

BOOL ClearWhAndInitialize(void) {
    gWhWork->mReceiveBufferSize = 0;
    gWhWork->mSendBufferSize = 0;
    gWhWork->mUnk_48 = 0;
    gWhWork->mUnk_50 = 0;
    gWhWork->mConnectedMask = 1;
    gWhWork->mUnk_54 = 0;
    gWhWork->mUserGameInfo = NULL;
    gWhWork->mUserGameInfoLength = 0;
    gWhWork->mConnectCallback = NULL;
    if (StartWhInitialize() != FALSE) {
        return TRUE;
    }
    return FALSE;
}

void WhIndicationCallback(WirelessMessage *event) {
    if (event->mResultCode == 8) {
        SetWhState(9);
        OS_Terminate();
    }
}

BOOL StartWhInitialize(void) {
    s32 result;
    SetWhState(3);
    result = WM_Initialize(gWhWork->mWmSystemBuffer, StartWhInitializeCallback, 2);
    if (result != 2) {
        SetWhErrorCode(result);
        SetWhState(10);
        return FALSE;
    }
    return TRUE;
}

void StartWhInitializeCallback(WirelessMessage *event) {
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        SetWhState(10);
    } else {
        s32 result = WM_SetIndCallback(WhIndicationCallback);
        if (result != 0) {
            SetWhErrorCode(result);
            SetWhState(10);
        } else {
            SetWhState(1);
        }
    }
}

BOOL StartWhParentConnect(u32 mode, u16 tgid, u16 channel) {
    if (gWhWork->mState != 1) {
        OS_Terminate();
    }
    gWhWork->mReceiveBufferSize = 0x180;
    gWhWork->mSendBufferSize = 0xe0;
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, "recv buffer size = %d\n", gWhWork->mReceiveBufferSize);
    }
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, "send buffer size = %d\n", gWhWork->mSendBufferSize);
    }
    gWhWork->mConnectMode = mode;
    SetWhState(3);
    gWhWork->mTgid = tgid;
    gWhWork->mChannel = channel;
    gWhWork->mBeaconPeriod = WM_GetDispersionBeaconPeriod();
    gWhWork->mParentMaxSize = 0xd0;
    gWhWork->mChildMaxSize = 0x44;
    gWhWork->mMaxEntry = 2;
    gWhWork->mUnk_16 = 0;
    gWhWork->mUnk_12 = 0;
    gWhWork->mEntryFlag = 1;
    gWhWork->mKsFlag = mode == 2 ? 1 : 0;
    if (mode == 0 || mode == 2 || mode == 4) {
        return SetWhParentParameter();
    }
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, "unknown connect mode %d\n", mode);
    }
    return FALSE;
}

void SetWhConnectCallback(u32 callback) {
    gWhWork->mConnectCallback = (s32(*)(WirelessMessage *)) callback;
}

u8 *GetWhSharedDataAddress(u32 aid) {
    return WM_GetSharedDataAddress(&gWhWork->mDataSharingInfo, &gWhWork->mReceiveData, aid);
}

BOOL StepWhDataSharing(void *sendData) {
    s32 result = WM_StepDataSharing(&gWhWork->mDataSharingInfo, sendData, &gWhWork->mReceiveData);
    if (result == 7) {
        if (gWhPrintFunction != NULL) {
            gWhPrintFunction(0x08000000, "DWCi_MOV_WH_StepDataSharing - Warning No Child\n");
        }
        return FALSE;
    }
    if (result == 5) {
        if (gWhPrintFunction != NULL) {
            gWhPrintFunction(0x08000000, "DWCi_MOV_WH_StepDataSharing - Warning No DataSet\n");
        }
        SetWhErrorCode(result);
        return FALSE;
    }
    if (result != 0) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

void StartWhResetOrFail(void) {
    int result;
    result = StartWhReset();
    if (result == 0) {
        SetWhState(10);
    }
}

void FinalizeWh(void) {
    s32 state = gWhWork->mState;
    if (state == 1) {
        if (gWhPrintFunction != NULL) {
            gWhPrintFunction(0x08000000, "already DWCi_MOV_WH_SYSSTATE_IDLE\n");
        }
        return;
    }
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, "DWCi_MOV_WH_Finalize, state = %d\n", state);
    }
    if (gWhWork->mState != 6 && gWhWork->mState != 5 && gWhWork->mState != 4) {
        SetWhState(3);
        StartWhResetOrFail();
        return;
    }
    SetWhState(3);
    switch (gWhWork->mConnectMode) {
        case 3:
            if (EndActiveWhKeySharing() == FALSE) {
                StartWhResetOrFail();
            }
            break;
        case 1:
        case 5:
            if (EndWhMPBeforeDisconnect() == FALSE) {
                StartWhResetOrFail();
            }
            break;
        case 2:
            if (EndWhKeySharing() == FALSE) {
                StartWhResetOrFail();
            }
            break;
        case 0:
        case 4:
            if (EndWhMP() == FALSE) {
                StartWhResetOrFail();
            }
            break;
    }
}

BOOL EndWh(void) {
    int result;
    if (gWhWork->mState != 1) {
        OS_Terminate();
    }
    SetWhState(3);
    result = WM_End(EndWhCallback);
    if (result != 2) {
        SetWhState(9);
        return 0;
    }
    return 1;
}
