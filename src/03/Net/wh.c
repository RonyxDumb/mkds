#include "03/Net/wh.h"

#include "03/code_021d0000.h"
#include "wm_etc.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_021445e0.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"

char gWhIndicateStateFormat[30] = "unknown indicate, state = %d\n";
char gWhEndParentFailedText[37] = "DWCi_MOV_WH_StateInEndParent failed\n";
char gWhStartKeySharingFailedText[47] = "DWCi_MOV_WH_StateInStartParentKeyShare failed\n";

WhWork *gWhWork;
UnkFunc *gWhPrintFunction;

void InitWhWork(WhWork *work) {
    gWhWork = work;
    work->mState = 0;
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
    if ((u32) (gWhWork->mState - 9) > 1) {
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
    if (gWhWork->mWepKeyCallback != NULL) {
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
    wepMode = gWhWork->mWepKeyCallback(gWhWork->mWepKey, gWhWork);
    result = WM_SetWEPKey(SetWhWepKeyCallback, wepMode, gWhWork->mWepKey);
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

    if ((u32) (gWhWork->mState - 4) <= 2) {
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

void StartWhParentCallback(Unk021425e8 *event) {
    u16 aidBit;
    s32 result;

    aidBit = 1 << event->mLength;
    if (event->mResultCode != 0) {
        SetWhErrorCode(event->mResultCode);
        SetWhState(9);
        return;
    }
    switch (event->mReplyState) {
        case 7:
            if (gWhPrintFunction != NULL) {
                gWhPrintFunction(0x08000000, "StartParent - new child (aid %x) connected\n", event->mLength);
            }
            if (gWhWork->mConnectCallback != NULL && gWhWork->mConnectCallback(event) == 0) {
                result = WM_Disconnect(NULL, event->mLength);
                if (result == 2) {
                    return;
                }
                SetWhErrorCode(result);
                SetWhState(9);
                return;
            }
            gWhWork->mConnectedMask = gWhWork->mConnectedMask | aidBit;
            return;
        case 9:
            if (gWhPrintFunction != NULL) {
                gWhPrintFunction(0x08000000, "StartParent - child (aid %x) disconnected\n", event->mLength);
            }
            gWhWork->mConnectedMask = gWhWork->mConnectedMask & ~aidBit;
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
                gWhPrintFunction(0x08000000, gWhIndicateStateFormat, event->mReplyState);
            }
            return;
    }
}

BOOL StartWhMP(void) {
    s32 result;

    if ((u32) (gWhWork->mState - 4) <= 2) {
        return TRUE;
    }
    SetWhState(4);
    result = WM_StartMPEx(StartWhMPCallback, gWhWork->mReceiveBuffer, gWhWork->mReceiveBufferSize, gWhWork->mSendBuffer,
                          gWhWork->mSendBufferSize, 1, 0, 0, 0, 0, 0);
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
    switch (event->mState) {
        case 0xa:
            if (gWhWork->mConnectMode == 2) {
                if (gWhWork->mState == 4) {
                    if (StartWhKeySharing() != FALSE) {
                        return;
                    }
                    if (gWhPrintFunction != NULL) {
                        gWhPrintFunction(0x08000000, gWhStartKeySharingFailedText);
                    }
                    SetWhState(9);
                    return;
                }
                if (gWhWork->mState == 6) {
                    return;
                }
            } else if (gWhWork->mConnectMode == 4) {
                result = WM_StartDataSharing(&gWhWork->mDataSharingInfo, 0xd, 7, 0x44, 1);
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
                gWhPrintFunction(0x08000000, gWhIndicateStateFormat, event->mState);
            }
            break;
    }
}

BOOL StartWhKeySharing(void) {
    s32 result;

    SetWhState(6);
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

    if (gWhWork->mState != 6) {
        return FALSE;
    }
    SetWhState(3);
    result = WM_EndKeySharing(&gWhWork->mKeySharingBuf);
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
    return gWhWork->mConnectedMask;
}

u32 GetWhState(void) {
    return gWhWork->mState;
}
