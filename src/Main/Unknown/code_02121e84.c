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

void func_02122728(void) {
    PackWiFiSessionIndices();
}

// Gives each index in mKartMask the next running number in mPackedIndices (others -1) and tells rres_205D0E8 the
// old and new number.
void PackWiFiSessionIndices(void) {
    u8 i;
    s8 nextNumber = 0;
    u8 oldNumber;
    for (i = 0; i < 4; i++) {
        if (i < gStruct217D384->mStartKartCount) {
            if ((gStruct217D384->mKartMask & (1 << i)) == 0) {
                gStruct217D384->mPackedIndices[i] = -1;
            } else {
                oldNumber = gStruct217D384->mPackedIndices[i];
                gStruct217D384->mPackedIndices[i] = nextNumber;
                nextNumber++;
                rres_205D0E8(oldNumber, gStruct217D384->mPackedIndices[i]);
            }
        } else {
            gStruct217D384->mPackedIndices[i] = -1;
        }
    }
}

BOOL UpdateWiFiSessionStepTimeout(u32 limit) {
    s32 frames;
    s32 step;
    frames = gStruct217D384->mStepFrames;
    gStruct217D384->mStepFrames = frames + 1;
    if (frames > limit) {
        gStruct217D384->mStepFrames = 0;
        step = gStruct217D384->mStep;
        if (step == 0 || step == 1 || step == 2) {
            gStruct217D384->field194E = 1;
            func_ov000_021a2ccc();
            func_ov000_0219bbfc();
            gStruct217D384->mStep = 11;
        } else {
            if (step == 9 || step == 10) {
                return TRUE;
            }
            gStruct217D384->field19AD = 1;
            func_ov000_021a2ccc();
            func_ov000_0219bbfc();
            gStruct217D384->mStep = 11;
        }
        return TRUE;
    }
    return FALSE;
}

static inline BOOL func_02121f4c_inline(const Unk0217d384_1d00 *message, u32 fromIndex, u32 size, u8 toIndex) {
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
    Unk0217d384_1d00 *message;
    u8 ownIndex;
    message = buffer;
    if (gStruct217D384->mStep >= 5 && (gStruct217D384->mKartMask & (1 << fromIndex)) == 0) {
        return;
    }
    gStruct217D384->mSinceCallbackFrames[fromIndex] = 0;
    ownIndex = func_ov000_0219bb50();
    if (func_02121f4c_inline(message, fromIndex, size, ownIndex) == FALSE) {
        return;
    }
    if (IsWiFiSessionMessageKindAllowed(message->mKind) == FALSE) {
        return;
    }
    switch (message->mKind) {
        case 0:
            gStruct217D384->mSendRecordMask |= 1 << fromIndex;
            break;
        case 1:
            gStruct217D384->mReceivedMask |= 1 << fromIndex;
            SetPeerReceiveBuffer(fromIndex, &gStruct217D384->mReceiveBuffers[fromIndex], 0x44);
            break;
        case 2:
            if (gStruct217D384->mStep == 1) {
                gStruct217D384->mReceivedMask |= 1 << fromIndex;
            }
            break;
        case 8:
            if (gStruct217D384->mStep != 3) {
                return;
            }
            if (message->field40 == 0) {
                return;
            }
            MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
            gStruct217D384->mReceivedMask |= 1 << fromIndex;
            break;
        case 9:
            if (gStruct217D384->mStep == 3) {
                MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
                gStruct217D384->mReceivedMask |= 1 << fromIndex;
            } else if (gStruct217D384->mStep == 4) {
                MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
                gStruct217D384->mReceivedMask |= 1 << fromIndex;
            }
            break;
        case 3:
            if (gStruct217D384->mStep == 1) {
                MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
                gStruct217D384->mReceivedMask = 0xff;
            } else if (gStruct217D384->mStep == 5) {
                MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
                if (message->mCharacterIndex == -1) {
                    return;
                }
                if (message->mKartIndex == -1) {
                    return;
                }
                gStruct217D384->mReceivedMask |= 1 << fromIndex;
            } else if (gStruct217D384->mStep == 4) {
                MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
                gStruct217D384->mReceivedMask = 0xff;
            }
            break;
        case 4:
            if (gStruct217D384->mStep == 5) {
                MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
                gStruct217D384->mReceivedMask |= 1 << fromIndex;
            } else if (gStruct217D384->mStep == 6) {
                MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
                gStruct217D384->mReceivedMask |= 1 << fromIndex;
            }
            break;
        case 5:
            if (gStruct217D384->mStep == 6) {
                MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
                gStruct217D384->mReceivedMask = 0xff;
            } else if (gStruct217D384->mStep == 7) {
                if (message->mPickedCourseId == 0) {
                    return;
                }
                MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
                gStruct217D384->mReceivedMask |= 1 << fromIndex;
            }
            break;
        case 6:
            if (gStruct217D384->mStep == 7) {
                MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
                gStruct217D384->mReceivedMask |= 1 << fromIndex;
            } else if (gStruct217D384->mStep == 8) {
                MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
                gStruct217D384->mReceivedMask |= 1 << fromIndex;
            }
            break;
        case 7:
            if (gStruct217D384->mStep == 8) {
                MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
                gStruct217D384->mReceivedMask |= 1 << fromIndex;
            } else if (gStruct217D384->mStep == 9) {
                MI_CpuCopy8(&gStruct217D384->mReceiveBuffers[fromIndex], &gStruct217D384->mIndexMessages[fromIndex], 0x44);
                EndWiFiSessionOnPicksMismatch(fromIndex);
                gStruct217D384->mReceivedMask |= 1 << fromIndex;
            }
            break;
    }
}

void SetWiFiSessionOwnCharacterIndex(s32 characterIndex) {
    gStruct217D384->mIndexMessages[func_ov000_0219bb50()].mCharacterIndex = characterIndex;
}

void SetWiFiSessionOwnCharacterIndexNone(void) {
    gStruct217D384->mIndexMessages[func_ov000_0219bb50()].mCharacterIndex = -1;
}

void SetWiFiSessionOwnKartIndex(s32 kartIndex) {
    gStruct217D384->mIndexMessages[func_ov000_0219bb50()].mKartIndex = kartIndex;
}

void SetWiFiSessionOwnPickedCourseId(s32 pickedCourseId) {
    gStruct217D384->mIndexMessages[func_ov000_0219bb50()].mPickedCourseId = pickedCourseId;
}
