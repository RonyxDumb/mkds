#include "03/code_021cfa68.h"

#include "03/code_021d0000.h"
#include "Main/Unknown/code_0200f000.h"
#include "wm_etc.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_021445e0.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"

void InitWhWork(WhWork *work) {
    gWhWork = work;
    work->mUnk_40 = 0;
    gWhWork->mUnk_13a8 = 0;
    gWhWork->mUnk_13ac = NULL;
    gWhWork->mUnk_13b0 = 0;
}

void SetWhState(u32 newState) {
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, gWhStateFromFormat, gWhStateNames[gWhWork->mUnk_40]);
    }
    gWhWork->mUnk_40 = newState;
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, gWhStateToFormat, gWhStateNames[gWhWork->mUnk_40]);
    }
}

void SetWhErrorCode(s32 errorCode) {
    if ((u32) (gWhWork->mUnk_40 - 9) > 1) {
        gWhWork->mUnk_54 = errorCode;
    }
}

BOOL SetWhParentParameter(void) {
    s32 result;

    SetWhState(3);
    result = WM_SetParentParameter(SetWhParentParameterCallback, (ParentParameter *) gWhWork);
    if (result != 2) {
        SetWhErrorCode(result);
        SetWhState(9);
        return FALSE;
    }
    return TRUE;
}

void SetWhParentParameterCallback(Unk021425e8 *event) {
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        SetWhState(9);
        return;
    }
    if (gWhWork->mUnk_13ac != NULL) {
        if (SetWhWepKey() == FALSE) {
            SetWhState(9);
        }
    } else if (StartWhParent() == FALSE) {
        SetWhState(9);
    }
}

BOOL SetWhWepKey(void) {
    u32 wepMode;
    s32 result;

    SetWhState(3);
    wepMode = gWhWork->mUnk_13ac(gWhWork->mUnk_13c0, gWhWork);
    result = WM_SetWEPKey(SetWhWepKeyCallback, wepMode, gWhWork->mUnk_13c0);
    if (result != 2) {
        SetWhErrorCode(result);
        SetWhState(9);
        return FALSE;
    }
    return TRUE;
}

void SetWhWepKeyCallback(Unk021425e8 *event) {
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        SetWhState(9);
    } else {
        if (StartWhParent() == FALSE) {
            SetWhState(9);
        }
    }
}

BOOL StartWhParent(void) {
    s32 result;

    if ((u32) (gWhWork->mUnk_40 - 4) <= 2) {
        return TRUE;
    }
    result = WM_StartParent(StartWhParentCallback);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    gWhWork->mUnk_50 = 0;
    gWhWork->mUnk_52 = 1;
    return TRUE;
}

void StartWhParentCallback(Unk021425e8 *event) {
    u16 aidBit;
    s32 result;

    aidBit = 1 << event->mUnk_10;
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        SetWhState(9);
        return;
    }
    switch (event->mUnk_08_0) {
        case 7:
            if (gWhPrintFunction != NULL) {
                gWhPrintFunction(0x08000000, gWhChildConnectedFormat, event->mUnk_10);
            }
            if (gWhWork->mUnk_4c != NULL && gWhWork->mUnk_4c(event) == 0) {
                result = WM_Disconnect(NULL, event->mUnk_10);
                if (result == 2) {
                    return;
                }
                SetWhErrorCode(result);
                SetWhState(9);
                return;
            }
            gWhWork->mUnk_52 = gWhWork->mUnk_52 | aidBit;
            return;
        case 9:
            if (gWhPrintFunction != NULL) {
                gWhPrintFunction(0x08000000, gWhChildDisconnectedFormat, event->mUnk_10);
            }
            gWhWork->mUnk_52 = gWhWork->mUnk_52 & ~aidBit;
            return;
        case 0:
            if (StartWhMP() == FALSE) {
                SetWhState(9);
            }
            return;
        case 2:
            return;
        default:
            if (gWhPrintFunction != NULL) {
                gWhPrintFunction(0x08000000, gWhIndicateStateFormat, event->mUnk_08_0);
            }
            return;
    }
}

BOOL StartWhMP(void) {
    s32 result;

    if ((u32) (gWhWork->mUnk_40 - 4) <= 2) {
        return TRUE;
    }
    SetWhState(4);
    result = WM_StartMPEx(StartWhMPCallback, gWhWork->mUnk_1060, gWhWork->mUnk_12a4, gWhWork->mUnk_f80,
                          gWhWork->mUnk_12a0, 1, 0, 0, 0, 0, 0);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

void StartWhMPCallback(Unk021425e8 *event) {
    s32 result;

    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        SetWhState(9);
        return;
    }
    switch (event->mUnk_04) {
        case 0xa:
            if (gWhWork->mUnk_44 == 2) {
                if (gWhWork->mUnk_40 == 4) {
                    if (StartWhKeySharing() != FALSE) {
                        return;
                    }
                    if (gWhPrintFunction != NULL) {
                        gWhPrintFunction(0x08000000, gWhStartKeySharingFailedText);
                    }
                    SetWhState(9);
                    return;
                }
                if (gWhWork->mUnk_40 == 6) {
                    return;
                }
            } else if (gWhWork->mUnk_44 == 4) {
                result = WM_StartDataSharing(&gWhWork->mUnk_13e0, 0xd, 7, 0x44, 1);
                if (result != 0) {
                    SetWhErrorCode(result);
                    SetWhState(9);
                    return;
                }
                SetWhState(5);
                return;
            }
            SetWhState(4);
            return;
        case 0xb:
            break;
        case 0xc:
        case 0xd:
        default:
            if (gWhPrintFunction != NULL) {
                gWhPrintFunction(0x08000000, gWhIndicateStateFormat, event->mUnk_04);
            }
            break;
    }
}

BOOL StartWhKeySharing(void) {
    s32 result;

    SetWhState(6);
    result = WM_StartKeySharing(&gWhWork->mUnk_1e00, 0xd);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

BOOL EndWhKeySharing(void) {
    s32 result = WM_EndKeySharing(&gWhWork->mUnk_1e00);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

BOOL EndWhMP(void) {
    s32 result;
    SetWhState(3);
    result = WM_EndMP(EndWhMPCallback);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

void EndWhMPCallback(Unk021425e8 *event) {
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        StartWhResetOrFail();
    } else if (EndWhParent() == FALSE) {
        if (gWhPrintFunction != NULL) {
            gWhPrintFunction(0x08000000, gWhEndParentFailedText);
        }
        StartWhResetOrFail();
    }
}

BOOL EndWhParent(void) {
    s32 result = WM_EndParent(EndWhParentCallback);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

void EndWhParentCallback(Unk021425e8 *event) {
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
    } else {
        SetWhState(1);
    }
}

BOOL EndActiveWhKeySharing(void) {
    s32 result;

    if (gWhWork->mUnk_40 != 6) {
        return FALSE;
    }
    SetWhState(3);
    result = WM_EndKeySharing(&gWhWork->mUnk_1e00);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

BOOL EndWhMPBeforeDisconnect(void) {
    s32 result;
    SetWhState(3);
    result = WM_EndMP(EndWhMPBeforeDisconnectCallback);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

void EndWhMPBeforeDisconnectCallback(Unk021425e8 *event) {
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        FinalizeWh();
    } else {
        if (DisconnectWh() == FALSE) {
            SetWhState(9);
        }
    }
}

BOOL DisconnectWh(void) {
    s32 result;

    SetWhState(3);
    result = WM_Disconnect(DisconnectWhCallback, 0);
    if (result != 2) {
        SetWhErrorCode(result);
        StartWhResetOrFail();
        return FALSE;
    }
    return TRUE;
}

void DisconnectWhCallback(Unk021425e8 *event) {
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
    } else {
        SetWhState(1);
    }
}

BOOL StartWhReset(void) {
    s32 result;
    SetWhState(3);
    result = WM_Reset(StartWhResetCallback);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

void StartWhResetCallback(Unk021425e8 *event) {
    if (event->mResultCode != 0) {
        SetWhState(9);
        SetWhErrorCode(event->mResultCode);
    } else {
        SetWhState(1);
    }
}

void EndWhCallback(Unk021425e8 *event) {
    if (event->mResultCode != 0) {
        SetWhState(10);
        return;
    }
    SetWhState(0);
}

void SetWhGgid(u32 ggid) {
    gWhWork->mUnk_08 = ggid;
}

u16 GetWhConnectedMask(void) {
    return gWhWork->mUnk_52;
}

u32 GetWhState(void) {
    return gWhWork->mUnk_40;
}

BOOL StartWhChannelSearch(void) {
    u16 macAddress[3];
    u32 result;
    u32 seed;

    OS_GetMacAddress(macAddress);
    seed = *(u32 *) 0x27ffc3c;
    seed = macAddress[0] + seed + macAddress[1] + macAddress[2];
    gWhWork->mUnk_58 = seed;
    gWhWork->mUnk_58 = gWhWork->mUnk_58 * 0x10dcd + 0x3039;
    gWhWork->mUnk_5c = 0;
    gWhWork->mUnk_5e = 0x65;
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

void StartWhMeasureChannelCallback(Unk021425e8 *event) {
    u16 channel;
    u16 busyRatio;
    u32 result;

    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        SetWhState(9);
        return;
    }
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, gWhChannelBusyRatioFormat, event->mUnk_08_0, event->mUnk_08_2);
    }
    channel = event->mUnk_08_0;
    busyRatio = event->mUnk_08_2;
    if (gWhWork->mUnk_5e > busyRatio) {
        gWhWork->mUnk_5e = busyRatio;
        gWhWork->mUnk_60 = 1 << (channel - 1);
    } else if (gWhWork->mUnk_5e == busyRatio) {
        gWhWork->mUnk_60 = gWhWork->mUnk_60 | (1 << (channel - 1));
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
    if (gWhWork->mUnk_40 != 7) {
        OS_Terminate();
    }
    SetWhState(1);
    channel = PickWhChannel((u32) (gWhWork->mUnk_60));
    workAddress = &gWhWork;
    gWhWork->mUnk_5c = channel;
    if ((UnkFunc *) (*(u32 *) &gWhPrintFunction) != NULL) {
        (*(UnkFunc *) (*(u32 *) &gWhPrintFunction))((0x08000000u), (u32) &gWhDecidedChannelFormat,
                                                    (*workAddress)->mUnk_5c);
    }
    return gWhWork->mUnk_5c;
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
        gWhWork->mUnk_58 = gWhWork->mUnk_58 * 0x10dcd + 0x3039;
        skipCount = (bitCount * (gWhWork->mUnk_58 & 0xff)) >> 8;
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
    gWhWork->mUnk_12a4 = 0;
    gWhWork->mUnk_12a0 = 0;
    gWhWork->mUnk_48 = 0;
    gWhWork->mUnk_50 = 0;
    gWhWork->mUnk_52 = 1;
    gWhWork->mUnk_54 = 0;
    gWhWork->mUnk_00 = NULL;
    gWhWork->mUnk_04 = 0;
    gWhWork->mUnk_4c = NULL;
    if (StartWhInitialize() != FALSE) {
        return TRUE;
    }
    return FALSE;
}

void WhIndicationCallback(Unk021425e8 *event) {
    if (event->mResultCode == 8) {
        SetWhState(9);
        OS_Terminate();
    }
}

BOOL StartWhInitialize(void) {
    s32 result;
    SetWhState(3);
    result = WM_Initialize(gWhWork->mUnk_80, StartWhInitializeCallback, 2);
    if (result != 2) {
        SetWhErrorCode(result);
        SetWhState(10);
        return FALSE;
    }
    return TRUE;
}

void StartWhInitializeCallback(Unk021425e8 *event) {
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
    if (gWhWork->mUnk_40 != 1) {
        OS_Terminate();
    }
    gWhWork->mUnk_12a4 = 0x180;
    gWhWork->mUnk_12a0 = 0xe0;
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, gWhRecvBufferSizeFormat, gWhWork->mUnk_12a4);
    }
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, gWhSendBufferSizeFormat, gWhWork->mUnk_12a0);
    }
    gWhWork->mUnk_44 = mode;
    SetWhState(3);
    gWhWork->mUnk_0c = tgid;
    gWhWork->mUnk_32 = channel;
    gWhWork->mUnk_18 = WM_GetDispersionBeaconPeriod();
    gWhWork->mUnk_34 = 0xd0;
    gWhWork->mUnk_36 = 0x44;
    gWhWork->mUnk_10 = 2;
    gWhWork->mUnk_16 = 0;
    gWhWork->mUnk_12 = 0;
    gWhWork->mUnk_0e = 1;
    gWhWork->mUnk_14 = mode == 2 ? 1 : 0;
    if (mode == 0 || mode == 2 || mode == 4) {
        return SetWhParentParameter();
    }
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, gWhConnectModeFormat, mode);
    }
    return FALSE;
}

void SetWhConnectCallback(u32 callback) {
    gWhWork->mUnk_4c = (s32(*)(Unk021425e8 *)) callback;
}

u8 *GetWhSharedDataAddress(u32 aid) {
    return WM_GetSharedDataAddress(&gWhWork->mUnk_13e0, &gWhWork->mUnk_1c00, aid);
}

BOOL StepWhDataSharing(void *sendData) {
    s32 result = WM_StepDataSharing(&gWhWork->mUnk_13e0, sendData, &gWhWork->mUnk_1c00);
    if (result == 7) {
        if (gWhPrintFunction != NULL) {
            gWhPrintFunction(0x08000000, gWhNoChildText);
        }
        return FALSE;
    }
    if (result == 5) {
        if (gWhPrintFunction != NULL) {
            gWhPrintFunction(0x08000000, gWhNoDataSetText);
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
    s32 state = gWhWork->mUnk_40;
    if (state == 1) {
        if (gWhPrintFunction != NULL) {
            gWhPrintFunction(0x08000000, gWhAlreadyIdleText);
        }
        return;
    }
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, gWhFinalizeStateFormat, state);
    }
    if (gWhWork->mUnk_40 != 6 && gWhWork->mUnk_40 != 5 && gWhWork->mUnk_40 != 4) {
        SetWhState(3);
        StartWhResetOrFail();
        return;
    }
    SetWhState(3);
    switch (gWhWork->mUnk_44) {
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
    if (gWhWork->mUnk_40 != 1) {
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
