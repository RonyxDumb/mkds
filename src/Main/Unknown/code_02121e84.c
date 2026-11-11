#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "00/code_0219b000.h"
#include "00/code_0219b580.h"
#include "00/code_021a2000.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a3000.h"
#include "00/code_021a3264.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

#pragma opt_arithtransformation off

void PackWiFiSessionIndicesWrapper(void) {
    PackWiFiSessionIndices();
}

// Gives each index in mKartMask the next running number in mPackedIndices (others -1) and tells CopyKartCupRecords the
// old and new number.
void PackWiFiSessionIndices(void) {
    u8 kartIndex;
    s8 nextNumber = 0;
    u8 oldNumber;
    for (kartIndex = 0; kartIndex < 4; kartIndex++) {
        if (kartIndex < gWiFiSession->mStartKartCount) {
            if ((gWiFiSession->mKartMask & (1 << kartIndex)) == 0) {
                gWiFiSession->mPackedIndices[kartIndex] = -1;
            } else {
                oldNumber = gWiFiSession->mPackedIndices[kartIndex];
                gWiFiSession->mPackedIndices[kartIndex] = nextNumber;
                nextNumber++;
                CopyKartCupRecords(oldNumber, gWiFiSession->mPackedIndices[kartIndex]);
            }
        } else {
            gWiFiSession->mPackedIndices[kartIndex] = -1;
        }
    }
}

BOOL UpdateWiFiSessionStepTimeout(u32 limit) {
    s32 frames;
    s32 step;
    frames = gWiFiSession->mStepFrames;
    gWiFiSession->mStepFrames = frames + 1;
    if (frames > limit) {
        gWiFiSession->mStepFrames = 0;
        step = gWiFiSession->mStep;
        if (step == 0 || step == 1 || step == 2) {
            gWiFiSession->mEarlyStepTimedOut = 1;
            DWC_RegisterMatchingStatus();
            DWC_CloseAllConnectionsHard();
            gWiFiSession->mStep = 11;
        } else {
            if (step == 9 || step == 10) {
                return TRUE;
            }
            gWiFiSession->mConnectionLost = 1;
            DWC_RegisterMatchingStatus();
            DWC_CloseAllConnectionsHard();
            gWiFiSession->mStep = 11;
        }
        return TRUE;
    }
    return FALSE;
}

static inline BOOL IsWiFiSessionMessageMatching(const WiFiSessionMessage *message, u32 fromIndex, u32 size,
                                                u8 toIndex) {
    if (message->mKind < 10) {
        if (message->mSize == size) {
            if (message->mFromIndex == fromIndex) {
                if (message->mToIndex == toIndex) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

// Receive callback of the net layer: validates the header, checks the kind against the step, copies the message into
// the own array and sets mReceivedMask.
void ReceiveWiFiSessionMessage(u32 fromIndex, void *buffer, u32 size) {
    WiFiSessionMessage *message;
    u8 ownIndex;
    message = buffer;
    if (gWiFiSession->mStep >= 5 && (gWiFiSession->mKartMask & (1 << fromIndex)) == 0) {
        return;
    }
    gWiFiSession->mSinceCallbackFrames[fromIndex] = 0;
    ownIndex = GetOwnParticipantIndex();
    if (IsWiFiSessionMessageMatching(message, fromIndex, size, ownIndex) == FALSE) {
        return;
    }
    if (IsWiFiSessionMessageKindAllowed(message->mKind) == FALSE) {
        return;
    }
    switch (message->mKind) {
        case 0:
            gWiFiSession->mSendRecordMask |= 1 << fromIndex;
            break;
        case 1:
            gWiFiSession->mReceivedMask |= 1 << fromIndex;
            SetPeerReceiveBuffer(fromIndex, &gWiFiSession->mReceiveBuffers[fromIndex], 0x44);
            break;
        case 2:
            if (gWiFiSession->mStep == 1) {
                gWiFiSession->mReceivedMask |= 1 << fromIndex;
            }
            break;
        case 8:
            if (gWiFiSession->mStep != 3) {
                return;
            }
            if (message->mContinueChoice == 0) {
                return;
            }
            MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
            gWiFiSession->mReceivedMask |= 1 << fromIndex;
            break;
        case 9:
            if (gWiFiSession->mStep == 3) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
                gWiFiSession->mReceivedMask |= 1 << fromIndex;
            } else if (gWiFiSession->mStep == 4) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
                gWiFiSession->mReceivedMask |= 1 << fromIndex;
            }
            break;
        case 3:
            if (gWiFiSession->mStep == 1) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
                gWiFiSession->mReceivedMask = 0xff;
            } else if (gWiFiSession->mStep == 5) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
                if (message->mCharacterIndex == -1) {
                    return;
                }
                if (message->mKartIndex == -1) {
                    return;
                }
                gWiFiSession->mReceivedMask |= 1 << fromIndex;
            } else if (gWiFiSession->mStep == 4) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
                gWiFiSession->mReceivedMask = 0xff;
            }
            break;
        case 4:
            if (gWiFiSession->mStep == 5) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
                gWiFiSession->mReceivedMask |= 1 << fromIndex;
            } else if (gWiFiSession->mStep == 6) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
                gWiFiSession->mReceivedMask |= 1 << fromIndex;
            }
            break;
        case 5:
            if (gWiFiSession->mStep == 6) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
                gWiFiSession->mReceivedMask = 0xff;
            } else if (gWiFiSession->mStep == 7) {
                if (message->mPickedCourseId == 0) {
                    return;
                }
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
                gWiFiSession->mReceivedMask |= 1 << fromIndex;
            }
            break;
        case 6:
            if (gWiFiSession->mStep == 7) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
                gWiFiSession->mReceivedMask |= 1 << fromIndex;
            } else if (gWiFiSession->mStep == 8) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
                gWiFiSession->mReceivedMask |= 1 << fromIndex;
            }
            break;
        case 7:
            if (gWiFiSession->mStep == 8) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
                gWiFiSession->mReceivedMask |= 1 << fromIndex;
            } else if (gWiFiSession->mStep == 9) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex], 0x44);
                EndWiFiSessionOnPicksMismatch(fromIndex);
                gWiFiSession->mReceivedMask |= 1 << fromIndex;
            }
            break;
    }
}

void SetWiFiSessionOwnCharacterIndex(s32 characterIndex) {
    gWiFiSession->mIndexMessages[GetOwnParticipantIndex()].mCharacterIndex = characterIndex;
}

void SetWiFiSessionOwnCharacterIndexNone(void) {
    gWiFiSession->mIndexMessages[GetOwnParticipantIndex()].mCharacterIndex = -1;
}

void SetWiFiSessionOwnKartIndex(s32 kartIndex) {
    gWiFiSession->mIndexMessages[GetOwnParticipantIndex()].mKartIndex = kartIndex;
}

void SetWiFiSessionOwnPickedCourseId(s32 pickedCourseId) {
    gWiFiSession->mIndexMessages[GetOwnParticipantIndex()].mPickedCourseId = pickedCourseId;
}
