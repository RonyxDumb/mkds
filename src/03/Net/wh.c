#include "03/Net/wh.h"

#include "wm_etc.h"
#include "03/Menu/wifi_menu_strings.h"
#include "03/Menu/wifi_menu_shared.h"
#include "wireless_data_sharing.h"
#include "reset_interrupt_enable.h"
#include "wireless_power_mp.h"

char gWhIndicateStateFormat[30] = "unknown indicate, state = %d\n";
char gWhEndParentFailedText[37] = "DWCi_MOV_WH_StateInEndParent failed\n";
char gWhStartKeySharingFailedText[47] = "DWCi_MOV_WH_StateInStartParentKeyShare failed\n";

WhWork *gWhWork;
WhPrintFunction gWhPrintFunction;

void InitWhWork(WhWork *work) {
    gWhWork = work;
    work->mState = WH_STATE_STOP;
    gWhWork->mUnk_13a8 = 0;
    gWhWork->mWepKeyCallback = NULL;
    gWhWork->mUnk_13b0 = 0;
}

void SetWhState(u32 newState) {
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, "%s -> ", gWhStateNames[gWhWork->mState]);
    }
    gWhWork->mState = newState;
    if (gWhPrintFunction != NULL) {
        gWhPrintFunction(0x08000000, "%s\n", gWhStateNames[gWhWork->mState]);
    }
}

void SetWhErrorCode(s32 errorCode) {
    if ((u32) (gWhWork->mState - WH_STATE_ERROR) > WH_STATE_FAILED - WH_STATE_ERROR) {
        gWhWork->mErrorCode = errorCode;
    }
}

BOOL SetWhParentParameter(void) {
    s32 result;

    SetWhState(WH_STATE_BUSY);
    result = WM_SetParentParameter(SetWhParentParameterCallback, &gWhWork->mParentParameter);
    if (result != 2) {
        SetWhErrorCode(result);
        SetWhState(WH_STATE_ERROR);
        return FALSE;
    }
    return TRUE;
}

void SetWhParentParameterCallback(WirelessMessage *event) {
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        SetWhState(WH_STATE_ERROR);
        return;
    }
    if (gWhWork->mWepKeyCallback != NULL) {
        if (SetWhWepKey() == FALSE) {
            SetWhState(WH_STATE_ERROR);
        }
    } else if (StartWhParent() == FALSE) {
        SetWhState(WH_STATE_ERROR);
    }
}

BOOL SetWhWepKey(void) {
    u32 wepMode;
    s32 result;

    SetWhState(WH_STATE_BUSY);
    wepMode = gWhWork->mWepKeyCallback(gWhWork->mWepKey, gWhWork);
    result = WM_SetWEPKey(SetWhWepKeyCallback, wepMode, gWhWork->mWepKey);
    if (result != 2) {
        SetWhErrorCode(result);
        SetWhState(WH_STATE_ERROR);
        return FALSE;
    }
    return TRUE;
}

void SetWhWepKeyCallback(WirelessMessage *event) {
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        SetWhState(WH_STATE_ERROR);
    } else {
        if (StartWhParent() == FALSE) {
            SetWhState(WH_STATE_ERROR);
        }
    }
}

BOOL StartWhParent(void) {
    s32 result;

    if ((u32) (gWhWork->mState - WH_STATE_CONNECTED) <= WH_STATE_KEY_SHARING - WH_STATE_CONNECTED) {
        return TRUE;
    }
    result = WM_StartParent(StartWhParentCallback);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    gWhWork->mUnk_50 = 0;
    gWhWork->mConnectedMask = 1;
    return TRUE;
}

void StartWhParentCallback(WirelessMessage *event) {
    u16 aidBit;
    s32 result;

    aidBit = 1 << event->mLength;
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        SetWhState(WH_STATE_ERROR);
        return;
    }
    switch (event->mReplyState) {
        case WIRELESS_STATE_LINKED:
            if (gWhPrintFunction != NULL) {
                gWhPrintFunction(0x08000000, "StartParent - new child (aid %x) connected\n", event->mLength);
            }
            if (gWhWork->mConnectCallback != NULL && gWhWork->mConnectCallback(event) == 0) {
                result = WM_Disconnect(NULL, event->mLength);
                if (result == 2) {
                    return;
                }
                SetWhErrorCode(result);
                SetWhState(WH_STATE_ERROR);
                return;
            }
            gWhWork->mConnectedMask = gWhWork->mConnectedMask | aidBit;
            return;
        case WIRELESS_STATE_UNLINKED:
            if (gWhPrintFunction != NULL) {
                gWhPrintFunction(0x08000000, "StartParent - child (aid %x) disconnected\n", event->mLength);
            }
            gWhWork->mConnectedMask = gWhWork->mConnectedMask & ~aidBit;
            return;
        case WIRELESS_STATE_SESSION_START:
            if (StartWhMP() == FALSE) {
                SetWhState(WH_STATE_ERROR);
            }
            return;
        case WIRELESS_STATE_FORWARD_UNLESS_RESETTING:
            return;
        default:
            if (gWhPrintFunction != NULL) {
                gWhPrintFunction(0x08000000, gWhIndicateStateFormat, event->mReplyState);
            }
            return;
    }
}

BOOL StartWhMP(void) {
    s32 result;

    if ((u32) (gWhWork->mState - WH_STATE_CONNECTED) <= WH_STATE_KEY_SHARING - WH_STATE_CONNECTED) {
        return TRUE;
    }
    SetWhState(WH_STATE_CONNECTED);
    result = WM_StartMPEx(StartWhMPCallback, gWhWork->mReceiveBuffer, gWhWork->mReceiveBufferSize, gWhWork->mSendBuffer,
                          gWhWork->mSendBufferSize, 1, 0, 0, 0, 0, 0);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

void StartWhMPCallback(WirelessMessage *event) {
    s32 result;

    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        SetWhState(WH_STATE_ERROR);
        return;
    }
    switch (event->mState) {
        case WIRELESS_STATE_EXCHANGE_BEGUN:
            if (gWhWork->mConnectMode == WIRELESS_CONNECT_MODE_KEY_SHARING) {
                if (gWhWork->mState == WH_STATE_CONNECTED) {
                    if (StartWhKeySharing() != FALSE) {
                        return;
                    }
                    if (gWhPrintFunction != NULL) {
                        gWhPrintFunction(0x08000000, gWhStartKeySharingFailedText);
                    }
                    SetWhState(WH_STATE_ERROR);
                    return;
                }
                if (gWhWork->mState == WH_STATE_KEY_SHARING) {
                    return;
                }
            } else if (gWhWork->mConnectMode == WIRELESS_CONNECT_MODE_DATA_SHARING) {
                result = WM_StartDataSharing(&gWhWork->mDataSharingInfo, 0xd, 7, 0x44, 1);
                if (result != 0) {
                    SetWhErrorCode(result);
                    SetWhState(WH_STATE_ERROR);
                    return;
                }
                SetWhState(WH_STATE_DATA_SHARING);
                return;
            }
            SetWhState(WH_STATE_CONNECTED);
            return;
        case WIRELESS_STATE_EXCHANGE_PASS_RECV_BUFFER:
            break;
        case WIRELESS_STATE_EXCHANGE_IGNORED_FIRST:
        case WIRELESS_STATE_EXCHANGE_IGNORED_SECOND:
        default:
            if (gWhPrintFunction != NULL) {
                gWhPrintFunction(0x08000000, gWhIndicateStateFormat, event->mState);
            }
            break;
    }
}

BOOL StartWhKeySharing(void) {
    s32 result;

    SetWhState(WH_STATE_KEY_SHARING);
    result = WM_StartKeySharing(&gWhWork->mKeySharingBuf, 0xd);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

BOOL EndWhKeySharing(void) {
    s32 result = WM_EndKeySharing(&gWhWork->mKeySharingBuf);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

BOOL EndWhMP(void) {
    s32 result;
    SetWhState(WH_STATE_BUSY);
    result = WM_EndMP(EndWhMPCallback);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

void EndWhMPCallback(WirelessMessage *event) {
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

void EndWhParentCallback(WirelessMessage *event) {
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
    } else {
        SetWhState(WH_STATE_IDLE);
    }
}

BOOL EndActiveWhKeySharing(void) {
    s32 result;

    if (gWhWork->mState != WH_STATE_KEY_SHARING) {
        return FALSE;
    }
    SetWhState(WH_STATE_BUSY);
    result = WM_EndKeySharing(&gWhWork->mKeySharingBuf);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

BOOL EndWhMPBeforeDisconnect(void) {
    s32 result;
    SetWhState(WH_STATE_BUSY);
    result = WM_EndMP(EndWhMPBeforeDisconnectCallback);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

void EndWhMPBeforeDisconnectCallback(WirelessMessage *event) {
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        FinalizeWh();
    } else {
        if (DisconnectWh() == FALSE) {
            SetWhState(WH_STATE_ERROR);
        }
    }
}

BOOL DisconnectWh(void) {
    s32 result;

    SetWhState(WH_STATE_BUSY);
    result = WM_Disconnect(DisconnectWhCallback, 0);
    if (result != 2) {
        SetWhErrorCode(result);
        StartWhResetOrFail();
        return FALSE;
    }
    return TRUE;
}

void DisconnectWhCallback(WirelessMessage *event) {
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
    } else {
        SetWhState(WH_STATE_IDLE);
    }
}

BOOL StartWhReset(void) {
    s32 result;
    SetWhState(WH_STATE_BUSY);
    result = WM_Reset(StartWhResetCallback);
    if (result != 2) {
        SetWhErrorCode(result);
        return FALSE;
    }
    return TRUE;
}

void StartWhResetCallback(WirelessMessage *event) {
    if (event->mResultCode != 0) {
        SetWhState(WH_STATE_ERROR);
        SetWhErrorCode(event->mResultCode);
    } else {
        SetWhState(WH_STATE_IDLE);
    }
}

void EndWhCallback(WirelessMessage *event) {
    if (event->mResultCode != 0) {
        SetWhState(WH_STATE_FAILED);
        return;
    }
    SetWhState(WH_STATE_STOP);
}

void SetWhGgid(u32 ggid) {
    gWhWork->mParentParameter.mGgid = ggid;
}

u16 GetWhConnectedMask(void) {
    return gWhWork->mConnectedMask;
}

u32 GetWhState(void) {
    return gWhWork->mState;
}
