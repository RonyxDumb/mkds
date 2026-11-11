#include "00/code_0219b1f8.h"
#include "00/code_0218d818.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e2dc.h"
#include "00/code_0219887c.h"
#include "00/code_0219a654.h"
#include "00/code_0219b580.h"
#include "00/code_0219c384.h"
#include "00/code_0219d000.h"
#include "00/code_0219c000.h"
#include "00/unk_021b5000.h"
#include "code_02139f70.h"
#include "00/code_0219d128.h"
#include "os_printf.h"
#include "00/code_021a10b0.h"
#include "00/code_021a17bc.h"
#include "00/code_021a1ae0.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a3a18.h"
#include "code_0213a460.h"

// GP callback slot 3 (message). The first branch hands the text to DWCi_GPRecvBuddyAuthCallback (the "I have authorized
// ..." sentence); the second takes GPCM-prefixed text with a MAT tag and forwards it to the matching code only in state
// 5 or matching mode 2 and 3.
void WiFiGpMessageCallback(GpConnection *connection, BuddyMessageData *arg, u32 param) {
    char *message;
    char versionText[12] = {0};
    u32 versionLength;
    WiFiConnection *wiFiConnection;

    message = arg->mUnk_08;
    if (DWCi_GPRecvBuddyAuthCallback(connection, (u32 *) arg, param) == 0) {
        if (memcmp(message, gDwcGpCommandString, strlen(gDwcGpCommandString)) == 0) {
            message += strlen(gDwcGpCommandString);
            versionLength = strchr(message, 0x76) - message;
            strncpy(versionText, message, versionLength);
            if (versionLength <= 10) {
                if (strtoul(versionText, NULL, 10) == 3) {
                    message += versionLength + 1;
                    if (memcmp(message, gDwcGpCommandMatchString, strlen(gDwcGpCommandMatchString)) == 0) {
                        wiFiConnection = gWiFiConnection;
                        if (wiFiConnection->mState == 5 || wiFiConnection->mMatching.mMode == 2 ||
                            wiFiConnection->mMatching.mMode == 3) {
                            message += strlen(gDwcGpCommandMatchString);
                            ParseMatchingGpMessage(connection, arg->mProfile, message);
                        }
                    }
                }
            }
        }
    }
}

// Slot 1 of the Gt2ConnectionCallbacks record (the library's Gt2CallDataCallback, code_02197e58.c:152): the body
// only forwards (connection, data, size, flag) to DWCi_RecvCallback, the receive side of the message layer.
void WiFiGt2DataCallback(Unk0219887c *connection, void *message, s32 length, u32 reliable) {
    DWCi_RecvCallback(connection, message, length, reliable);
}

void DWCi_GT2ClosedCallback(Unk0219887c *connection, u32 reason) {
    u32 profileId;
    s32 detail;
    BOOL hostSide;
    u8 *connectionInfo;
    u32 aid;
    s32 kind;
    u32 inMask;
    WiFiConnection *wiFiConnection;
    u32 friendListIndex;
    void **closedCallbackArg;

    profileId = 0;
    hostSide = FALSE;
    if (IsMatchingPointerNull() != 0) {
        return;
    }
    switch (reason) {
        case 0:
        case 1:
            kind = 0;
            break;
        case 2:
        case 3:
            kind = 6;
            detail = -0x1db0;
            break;
        case 4:
            kind = 0xb;
            detail = -0x1db1;
            break;
    }
    if (kind == 0) {
        connectionInfo = gt2GetConnectionData(connection);
        if (connectionInfo == NULL) {
            return;
        }
        aid = connectionInfo[1];
        inMask = (gWiFiConnection->mMatching.mParticipantMask & (1 << aid)) != 0;
        DWCi_ClearTransConnection(aid);
        wiFiConnection = gWiFiConnection;
        if ((wiFiConnection->mMatching.mMode == 2 && reason == 0) ||
            (wiFiConnection->mMatching.mMode == 3 && aid == 0)) {
            hostSide = TRUE;
        }
        profileId = DWCi_DeleteAID(aid);
        stGt2ConnectionList[connectionInfo[0]] = NULL;
        gWiFiConnection->mMatching.mLastParticipantPos--;
        gWiFiConnection->mMatching.mUnk_14--;
    }
    if (gWiFiConnection->mUnk_2d == 0 && gWiFiConnection->mState == 6 && inMask == 0) {
        if (gWiFiConnection->mMatching.mMode == 2 && kind == 0) {
            DWCi_GPSetServerStatus();
            DWCi_ProcessMatchSCClosing(profileId);
        }
        return;
    }
    if (DWCi_ProcessMatchClosing(kind, detail, profileId) != 0) {
        return;
    }
    if (kind != 0) {
        DWCi_SetError(kind, detail);
        return;
    }
    if (gWiFiConnection->mMatching.mMode == 2) {
        if (gWiFiConnection->mUnk_2d == 0) {
            DWCi_GPSetServerStatus();
        } else if (gWiFiConnection->mMatching.mLastParticipantPos == 0) {
            DWCi_SetGPStatus(1, data_ov000_021b4054, NULL);
        }
    } else if (gWiFiConnection->mMatching.mLastParticipantPos == 0) {
        DWCi_SetGPStatus(1, data_ov000_021b4054, NULL);
    }
    if (gWiFiConnection->mMatching.mMode == 0 || gWiFiConnection->mMatching.mMode == 1) {
        gWiFiConnection->mMatching.mUnk_16 = gWiFiConnection->mMatching.mUnk_14;
        qr2_send_statechanged(gWiFiConnection->mMatching.mUnk_10);
    }
    wiFiConnection = gWiFiConnection;
    if (wiFiConnection->mUnk_7c != NULL && inMask != 0) {
        if (reason == 0) {
            reason = 1;
        } else {
            reason = 0;
        }
        friendListIndex = FindBuddyEntryIndex(profileId);
        closedCallbackArg = &wiFiConnection->mUnk_80;
        gWiFiConnection->mUnk_7c(kind, reason, hostSide, aid, friendListIndex, *closedCallbackArg);
    }
    if (gWiFiConnection->mUnk_2d != 0 || gWiFiConnection->mMatching.mMode != 2) {
        if (gWiFiConnection->mMatching.mLastParticipantPos == 0) {
            NNFreeNegotiateList();
            DWCi_ClearQR2Key();
            SetWiFiConnectionState(3);
        }
    }
}

// Slot 3 of the record (Gt2CallElapsedTimeCallback, code_02197e58.c:196): the body only forwards (connection,
// elapsed time) to DWCi_PingCallback, which calls the layer's mUnk_60c with the time and the peer index.
void WiFiGt2ElapsedTimeCallback(Unk0219887c *connection, u32 latency) {
    DWCi_PingCallback(connection, latency);
}

void DWCi_GT2SocketErrorCallback(u32 *socket) {
    stLastSocketError = GOAGetLastError(GetSocketDescriptor(socket));
    DWCi_SetError(0xb, -0x17aeb);
    gWiFiConnection->mSocket = NULL;
}

NatTraversalEntry *FindNegotiatorForCookie(u32 cookie) {
    s32 index;
    NatTraversalEntry *negotiator;

    if (negotiateList == NULL) {
        return NULL;
    }
    for (index = 0; index < DarrayGetCount((u32 *) negotiateList); index++) {
        negotiator = DarrayGetElement(negotiateList, index);
        if (negotiator->mCookie == cookie) {
            return negotiator;
        }
    }
    return NULL;
}
