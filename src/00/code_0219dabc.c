#include "00/code_0219dabc.h"
#include "00/GameSpy/gt2Utility.h"
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

void func_ov000_0219db18(s32 a, s32 b, PeerAddress *c, void *d) {
    s32 e;
    s32 f;
    u32 g;
    u32 h;
    char i[12];
    if (gWiFiMatching->mState != 6 && gWiFiMatching->mState != 0xb) {
        return;
    }
    if (d == NULL) {
        return;
    }
    if (a == 0) {
        ((Unk0219db18 *) d)->field8 = 0;
        gWiFiMatching->field14++;
        e = gWiFiMatching->field14;
        if (((Unk0219db18 *) d)->field0 != 0) {
            gWiFiMatching->mParticipantConnectAddresses[e] = c->mAddress;
            gWiFiMatching->mParticipantConnectPorts[e] = (c->mPort >> 8) & 0xff | (c->mPort << 8) & 0xff00;
            gWiFiMatching->field174[0] = 0;
            gWiFiMatching->field178 = 0;
            gWiFiMatching->field17C = 0;
            if (gWiFiMatching->mState == 0xb) {
                gWiFiMatching->mState = 0xc;
            } else {
                gWiFiMatching->mState = 7;
            }
            gWiFiMatching->mConnectRetryCount = 0;
            OS_SNPrintf(i, 12, gUnsignedFormat, gWiFiMatching->mOwnProfileId);
            if (ReportMatchingConnectResult(
                    func_ov000_02198968(*gWiFiMatching->mConnectionSocket, NULL,
                                        Gt2FormatAddress(gWiFiMatching->mParticipantConnectAddresses[e],
                                                         gWiFiMatching->mParticipantConnectPorts[e], 0),
                                        i, -1, 0x1388, gWiFiMatching->mConnectionCallbacks, 0)) != 0) {
                return;
            }
            return;
        }
        if (c != 0) {
            gWiFiMatching->mParticipantConnectAddresses[e - 1] = c->mAddress;
            gWiFiMatching->mParticipantConnectPorts[e - 1] = (c->mPort >> 8) & 0xff | (c->mPort << 8) & 0xff00;
        }
        gWiFiMatching->mIncomingWaitStartTime = func_ov000_021a350c();
        gWiFiMatching->mState = 7;
        return;
    }
    if (((Unk0219db18 *) d)->field8 == 0) {
        return;
    }
    f = func_ov000_0219e45c(a);
    if (f != 2 && f != 1) {
        return;
    }
    if (((Unk0219db18 *) d)->field0 == 0) {
        if (f == 1 || (f == 2 && ((Unk0219db18 *) d)->field1 >= 1)) {
            ((Unk0219db18 *) d)->field8 = 0;
            if (func_ov000_0219dabc() != 0) {
                if (func_ov000_0219f938(gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos]) !=
                    0) {
                    return;
                }
            }
            return;
        }
        ((Unk0219db18 *) d)->field1++;
        if (func_ov000_0219e4a0(func_ov000_021a0c30(d)) != 0) {
            return;
        }
        return;
    }
    gWiFiMatching->field17C = func_ov000_021a350c();
    if (f == 1 || (f == 2 && gWiFiMatching->field174[0] >= 1)) {
        ((Unk0219db18 *) d)->field8 = 0;
        if (func_ov000_0219dabc() != 0) {
            gWiFiMatching->field174[0] = 0;
            gWiFiMatching->field178 = 0;
            gWiFiMatching->field17C = 0;
            if (func_ov000_0219f9bc(gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1]) !=
                0) {
                return;
            }
        }
    }
}

u32 func_ov000_0219dabc(void) {
    if (gWiFiMatching->mMode == 2) {
        return 1;
    }
    if (gWiFiMatching->mMode != 3) {
        gWiFiMatching->field174[1]++;
    }
    if (gWiFiMatching->mMode == 3 || gWiFiMatching->field174[1] >= 5) {
        ReportMatchingError(6, -0x15194);
        return 0;
    }
    return 1;
}
