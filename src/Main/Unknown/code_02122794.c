#include "Main/Unknown/code_02122794.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "00/code_0219b000.h"
#include "00/code_0219b580.h"
#include "00/code_021a2000.h"
#include "00/code_021a2ccc.h"

void ResetWiFiConnectionLost(void) {
    StateMachine *stateMachine;
    gWiFiSession->mConnectionLost = 0;
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = 2;
    stateMachine->mNextStateRequested = 1;
}

// Drops the indices set in mKartRemoveMask from the roster; ends the run (step 11) if the own index is removed or one
// kart or none remains.
void RemoveWiFiSessionKarts(void) {
    u8 participantIndex;
    u32 bit;
    if (gWiFiSession->mStep == 11 || gWiFiSession->mStep == 12) {
        return;
    }
    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        bit = 1 << participantIndex;
        if ((gWiFiSession->mKartMask & bit) != 0 && (gWiFiSession->mKartRemoveMask & bit) != 0) {
            if (participantIndex == GetOwnParticipantIndex()) {
                gWiFiSession->mConnectionLost = 1;
                DWC_RegisterMatchingStatus();
                DWC_CloseAllConnectionsHard();
                gWiFiSession->mStep = 11;
                return;
            }
            gWiFiSession->mKartMask &= ~bit;
            gWiFiSession->mKartRemoveMask &= ~bit;
            gWiFiSession->mKartCount--;
        }
    }
    if (gWiFiSession->mKartCount <= 1) {
        gWiFiSession->mConnectionLost = 1;
        DWC_RegisterMatchingStatus();
        DWC_CloseAllConnectionsHard();
        gWiFiSession->mStep = 11;
    }
}

void UpdateWiFiSessionKartTimeouts(void) {
    u8 participantIndex;
    u8 ownIndex;
    if (gWiFiSession->mStep > 2 && gWiFiSession->mStep < 9) {
        if (gWiFiSession->mStep == 3) {
            ownIndex = GetOwnParticipantIndex();
            if (gWiFiSession->mIndexMessages[ownIndex].mContinueChoice != 1) {
                return;
            }
        }
        for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
            if (participantIndex != GetOwnParticipantIndex() &&
                (gWiFiSession->mKartMask & (1 << participantIndex)) != 0) {
                if (gWiFiSession->mSinceCallbackFrames[participantIndex] > 300) {
                    gWiFiSession->mKartRemoveMask |= 1 << participantIndex;
                }
            }
        }
    }
    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        if (participantIndex != GetOwnParticipantIndex() && (gWiFiSession->mKartMask & (1 << participantIndex)) != 0) {
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
