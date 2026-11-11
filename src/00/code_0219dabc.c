#include "00/code_0219dabc.h"
#include "00/code_0219a654.h"
#include "00/code_0219f4c4.h"
#include "00/code_021a0958.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_021988e8.h"
#include "00/code_0219a000.h"
#include "00/code_0219e4e8.h"
#include "00/code_0219e134.h"
#include "00/code_0219f000.h"
#include "00/code_0219f9bc.h"
#include "00/code_021a01dc.h"
#include "00/code_021a17bc.h"
#include "os_printf.h"
#include "00/code_0219dd4c.h"
#include "00/code_021a3264.h"

void DWCi_NNCompletedCallback(s32 result, s32 gamesocket, PeerAddress *remoteaddr, void *userdata) {
    s32 index;
    s32 outcome;
    u32 g;
    u32 h;
    char pidText[12];
    if (gWiFiMatching->mState != 6 && gWiFiMatching->mState != 0xb) {
        return;
    }
    if (userdata == NULL) {
        return;
    }
    if (result == 0) {
        ((Unk0219db18 *) userdata)->mUnk_08 = 0;
        gWiFiMatching->mUnk_14++;
        index = gWiFiMatching->mUnk_14;
        if (((Unk0219db18 *) userdata)->mUnk_00 != 0) {
            gWiFiMatching->mParticipantConnectAddresses[index] = remoteaddr->mAddress;
            gWiFiMatching->mParticipantConnectPorts[index] =
                (remoteaddr->mPort >> 8) & 0xff | (remoteaddr->mPort << 8) & 0xff00;
            gWiFiMatching->mUnk_174[0] = 0;
            gWiFiMatching->mUnk_178 = 0;
            gWiFiMatching->mUnk_17c = 0;
            if (gWiFiMatching->mState == 0xb) {
                gWiFiMatching->mState = 0xc;
            } else {
                gWiFiMatching->mState = 7;
            }
            gWiFiMatching->mConnectRetryCount = 0;
            OS_SNPrintf(pidText, 12, gUnsignedFormat, gWiFiMatching->mOwnProfileId);
            if (ReportMatchingConnectResult(
                    gt2Connect(*gWiFiMatching->mConnectionSocket, NULL,
                               gt2AddressToString(gWiFiMatching->mParticipantConnectAddresses[index],
                                                  gWiFiMatching->mParticipantConnectPorts[index], 0),
                               pidText, -1, 0x1388, gWiFiMatching->mConnectionCallbacks, 0)) != 0) {
                return;
            }
            return;
        }
        if (remoteaddr != 0) {
            gWiFiMatching->mParticipantConnectAddresses[index - 1] = remoteaddr->mAddress;
            gWiFiMatching->mParticipantConnectPorts[index - 1] =
                (remoteaddr->mPort >> 8) & 0xff | (remoteaddr->mPort << 8) & 0xff00;
        }
        gWiFiMatching->mIncomingWaitStartTime = MatchingGetTickMilliseconds();
        gWiFiMatching->mState = 7;
        return;
    }
    if (((Unk0219db18 *) userdata)->mUnk_08 == 0) {
        return;
    }
    outcome = DWCi_HandleNNResult(result);
    if (outcome != 2 && outcome != 1) {
        return;
    }
    if (((Unk0219db18 *) userdata)->mUnk_00 == 0) {
        if (outcome == 1 || (outcome == 2 && ((Unk0219db18 *) userdata)->mUnk_01 >= 1)) {
            ((Unk0219db18 *) userdata)->mUnk_08 = 0;
            if (DWCi_ProcessNNFailure() != 0) {
                if (DWCi_CancelPreConnectedClientProcess(
                        gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos]) != 0) {
                    return;
                }
            }
            return;
        }
        ((Unk0219db18 *) userdata)->mUnk_01++;
        if (DWCi_HandleNNError(DWCi_DoNatNegotiationAsync(userdata)) != 0) {
            return;
        }
        return;
    }
    gWiFiMatching->mUnk_17c = MatchingGetTickMilliseconds();
    if (outcome == 1 || (outcome == 2 && gWiFiMatching->mUnk_174[0] >= 1)) {
        ((Unk0219db18 *) userdata)->mUnk_08 = 0;
        if (DWCi_ProcessNNFailure() != 0) {
            gWiFiMatching->mUnk_174[0] = 0;
            gWiFiMatching->mUnk_178 = 0;
            gWiFiMatching->mUnk_17c = 0;
            if (DWCi_CancelPreConnectedServerProcess(
                    gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1]) != 0) {
                return;
            }
        }
    }
}

u32 DWCi_ProcessNNFailure(void) {
    if (gWiFiMatching->mMode == 2) {
        return 1;
    }
    if (gWiFiMatching->mMode != 3) {
        gWiFiMatching->mUnk_174[1]++;
    }
    if (gWiFiMatching->mMode == 3 || gWiFiMatching->mUnk_174[1] >= 5) {
        DWCi_StopMatching(6, -0x15194);
        return 0;
    }
    return 1;
}
