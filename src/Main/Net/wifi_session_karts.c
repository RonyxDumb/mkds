#include "Main/Net/wifi_session_karts.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "00/Lib/DWC/data_transport.h"
#include "Main/Net/wifi_session.h"

void ResetWiFiConnectionLost(void) {
    StateMachine *stateMachine;
    gWiFiSession->mConnectionLost = FALSE;
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_IDLE;
    stateMachine->mNextStateRequested = 1;
}

// Unless the step is already leaving or ended, drops the indices set in both mKartMask and mKartRemoveMask from
// mKartMask and mKartCount; sets the leaving step (connection lost) as soon as the own index is in that set, or when
// one kart or none is left.
void RemoveWiFiSessionKarts(void) {
    u8 participantIndex;
    u32 bit;
    if (gWiFiSession->mStep == WIFI_SESSION_STEP_LEAVING || gWiFiSession->mStep == WIFI_SESSION_STEP_ENDED) {
        return;
    }
    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        bit = 1 << participantIndex;
        if ((gWiFiSession->mKartMask & bit) != 0 && (gWiFiSession->mKartRemoveMask & bit) != 0) {
            if (participantIndex == DWC_GetMyAID()) {
                gWiFiSession->mConnectionLost = TRUE;
                DWC_RegisterMatchingStatus();
                DWC_CloseAllConnectionsHard();
                gWiFiSession->mStep = WIFI_SESSION_STEP_LEAVING;
                return;
            }
            gWiFiSession->mKartMask &= ~bit;
            gWiFiSession->mKartRemoveMask &= ~bit;
            gWiFiSession->mKartCount--;
        }
    }
    if (gWiFiSession->mKartCount <= 1) {
        gWiFiSession->mConnectionLost = TRUE;
        DWC_RegisterMatchingStatus();
        DWC_CloseAllConnectionsHard();
        gWiFiSession->mStep = WIFI_SESSION_STEP_LEAVING;
    }
}

void UpdateWiFiSessionKartTimeouts(void) {
    u8 participantIndex;
    u8 ownIndex;
    if (gWiFiSession->mStep > WIFI_SESSION_STEP_WAIT_BACKUP && gWiFiSession->mStep < WIFI_SESSION_STEP_VERIFY_RESULT) {
        if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) {
            ownIndex = DWC_GetMyAID();
            if (gWiFiSession->mIndexMessages[ownIndex].mContinueChoice != WIFI_CONTINUE_CHOICE_CONTINUE) {
                return;
            }
        }
        for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
            if (participantIndex != DWC_GetMyAID() && BIT_IS_SET(gWiFiSession->mKartMask, participantIndex)) {
                if (gWiFiSession->mSinceCallbackFrames[participantIndex] > WIFI_SESSION_KART_TIMEOUT_FRAMES) {
                    BIT_SET(gWiFiSession->mKartRemoveMask, participantIndex);
                }
            }
        }
    }
    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        if (participantIndex != DWC_GetMyAID() && BIT_IS_SET(gWiFiSession->mKartMask, participantIndex)) {
            gWiFiSession->mSinceCallbackFrames[participantIndex]++;
        }
    }
}

u32 GetKartMaskBit(u32 index) {
    return gWiFiSession->mKartMask & (1 << index);
}

u32 GetKartMaskBitOfPackedIndex(u8 packedIndex) {
    s8 slotIndex;
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        if (packedIndex == gWiFiSession->mPackedIndices[slotIndex]) {
            goto found;
        }
    }
    slotIndex = -1;
found:
    if (slotIndex == -1) {
        return 0;
    }
    return gWiFiSession->mKartMask & (1 << (u8) slotIndex);
}
