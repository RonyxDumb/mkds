#include "Main/Net/wifi_session_karts.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "00/Lib/DWC/data_transport.h"
#include "Main/Net/wifi_session.h"

void ResetWiFiConnectionLost(void) {
    StateMachine *stateMachine;
    g_GlobalB->mConnectionLost = FALSE;
    stateMachine = &g_GlobalB->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_IDLE;
    stateMachine->mNextStateRequested = 1;
}

// Drops the indices set in mKartRemoveMask from the roster; ends the run (the leaving step) if the own index is removed
// or one kart or none remains.
void RemoveWiFiSessionKarts(void) {
    u8 participantIndex;
    u32 bit;
    if (g_GlobalB->mStep == WIFI_SESSION_STEP_LEAVING || g_GlobalB->mStep == WIFI_SESSION_STEP_ENDED) {
        return;
    }
    for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
        bit = 1 << participantIndex;
        if ((g_GlobalB->mKartMask & bit) != 0 && (g_GlobalB->mKartRemoveMask & bit) != 0) {
            if (participantIndex == DWC_GetMyAID()) {
                g_GlobalB->mConnectionLost = TRUE;
                DWC_RegisterMatchingStatus();
                DWC_CloseAllConnectionsHard();
                g_GlobalB->mStep = WIFI_SESSION_STEP_LEAVING;
                return;
            }
            g_GlobalB->mKartMask &= ~bit;
            g_GlobalB->mKartRemoveMask &= ~bit;
            g_GlobalB->mKartCount--;
        }
    }
    if (g_GlobalB->mKartCount <= 1) {
        g_GlobalB->mConnectionLost = TRUE;
        DWC_RegisterMatchingStatus();
        DWC_CloseAllConnectionsHard();
        g_GlobalB->mStep = WIFI_SESSION_STEP_LEAVING;
    }
}

void UpdateWiFiSessionKartTimeouts(void) {
    u8 participantIndex;
    u8 ownIndex;
    if (g_GlobalB->mStep > WIFI_SESSION_STEP_WAIT_BACKUP && g_GlobalB->mStep < WIFI_SESSION_STEP_VERIFY_RESULT) {
        if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) {
            ownIndex = DWC_GetMyAID();
            if (g_GlobalB->mIndexMessages[ownIndex].mContinueChoice != WIFI_CONTINUE_CHOICE_CONTINUE) {
                return;
            }
        }
        for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
            if (participantIndex != DWC_GetMyAID() && BIT_IS_SET(g_GlobalB->mKartMask, participantIndex)) {
                if (g_GlobalB->mSinceCallbackFrames[participantIndex] > WIFI_SESSION_KART_TIMEOUT_FRAMES) {
                    BIT_SET(g_GlobalB->mKartRemoveMask, participantIndex);
                }
            }
        }
    }
    for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
        if (participantIndex != DWC_GetMyAID() && BIT_IS_SET(g_GlobalB->mKartMask, participantIndex)) {
            g_GlobalB->mSinceCallbackFrames[participantIndex]++;
        }
    }
}

u32 GetKartMaskBit(u32 index) {
    return g_GlobalB->mKartMask & (1 << index);
}

u32 GetKartMaskBitOfPackedIndex(u8 packedIndex) {
    s8 slotIndex;
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        if (packedIndex == g_GlobalB->mPackedIndices[slotIndex]) {
            goto found;
        }
    }
    slotIndex = -1;
found:
    if (slotIndex == -1) {
        return 0;
    }
    return g_GlobalB->mKartMask & (1 << (u8) slotIndex);
}
