#include "Main/Unknown/code_02122b14.h"
#include "00/code_0219b000.h"
#include "00/code_0219b580.h"
#include "00/code_021a2000.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a3000.h"
#include "00/code_021a3264.h"
#include "00/unk_021b5000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02122794.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_021956dc.h"
#include "code_0200f5ac.h"
#include "code_0214d018.h"

// Sets the session up for variant a (0 to 3): case 0 resets masks, records and picks and sets mStep 0, case 1 only
// packs the indices and counts the karts, cases 2 and 3 reset the picks and set mStep 7 and 3.
void SetupWiFiSession(u32 mode) {
    u8 participantIndex;
    u8 ownIndex;
    WriteChangedWiFiBuddies();
    switch (mode) {
        case 0:
            MI_CpuFill8(&gWiFiSession->mStep, 0, 0x60);
            MI_CpuFill8(gWiFiSession->mIndexMessages, 0, 0x110);
            MI_CpuFill8(gWiFiSession->mReceiveBuffers, 0, 0x110);
            for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
                if (participantIndex != GetOwnParticipantIndex()) {
                    SetPeerReceiveBuffer(participantIndex, &gWiFiSession->mPlayerRecords[participantIndex], 0x244);
                    GetRaceSetupCopy()->mEntries[participantIndex].mPlayerKind = 3;
                } else {
                    gWiFiSession->mPlayerRecords[participantIndex].mFirstTotal =
                        gBackupBuffers->mFirstBlock->mTotals[4];
                    gWiFiSession->mPlayerRecords[participantIndex].mSecondTotal =
                        gBackupBuffers->mFirstBlock->mTotals[5];
                    GetRaceSetupCopy()->mEntries[participantIndex].mPlayerKind = 0;
                }
                GetRaceSetupCopy()->mEntries[participantIndex].mCharacterIndex = -1;
                GetRaceSetupCopy()->mEntries[participantIndex].mKartIndex = -1;
                GetRaceSetupCopy()->mCourseId = 0;
                gWiFiSession->mIndexMessages[participantIndex].mCharacterIndex = -1;
                gWiFiSession->mIndexMessages[participantIndex].mKartIndex = -1;
                gWiFiSession->mIndexMessages[participantIndex].mPickedCourseId = 0;
                gWiFiSession->mReceiveBuffers[participantIndex].mCharacterIndex = -1;
                gWiFiSession->mReceiveBuffers[participantIndex].mKartIndex = -1;
                gWiFiSession->mReceiveBuffers[participantIndex].mPickedCourseId = 0;
            }
            gWiFiSession->mStepFrames = 0;
            gWiFiSession->mSendRecordMask = 0;
            gWiFiSession->mReceivedMask = 0;
            DWC_SetUserRecvCallback(ReceiveWiFiSessionMessage);
            ownIndex = GetOwnParticipantIndex();
            gWiFiSession->mPlayerRecords[ownIndex].mSeed = OS_GetTick();
            PackWiFiSessionIndices();
            gWiFiSession->mStep = 0;
            SetRaceSetupCopyEntryIndex((u8) gWiFiSession->mPackedIndices[GetOwnParticipantIndex()]);
            SetSessionKartCount(gWiFiSession->mStartKartCount);
            break;
        case 1:
            PackWiFiSessionIndices();
            gWiFiSession->mKartCount = 0;
            for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
                if ((gWiFiSession->mKartMask & (1 << participantIndex)) != 0) {
                    gWiFiSession->mKartCount++;
                }
            }
            SetRaceSetupCopyEntryIndex((u8) gWiFiSession->mPackedIndices[GetOwnParticipantIndex()]);
            SetSessionKartCount(gWiFiSession->mKartCount);
            break;
        case 2:
            for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
                if (participantIndex != GetOwnParticipantIndex() &&
                    (gWiFiSession->mKartMask & (1 << participantIndex)) != 0) {
                    SetPeerReceiveBuffer(participantIndex, &gWiFiSession->mReceiveBuffers[participantIndex], 0x44);
                }
                GetRaceSetupCopy()->mCourseId = 0;
                gWiFiSession->mIndexMessages[participantIndex].mPickedCourseId = 0;
                gWiFiSession->mReceiveBuffers[participantIndex].mPickedCourseId = 0;
            }
            DWC_SetUserRecvCallback(ReceiveWiFiSessionMessage);
            gWiFiSession->mStep = 7;
            gWiFiSession->mStepFrames = 0;
            gWiFiSession->mSendRecordMask = 0;
            gWiFiSession->mReceivedMask = 0;
            PackWiFiSessionIndices();
            gWiFiSession->mKartCount = 0;
            for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
                if ((gWiFiSession->mKartMask & (1 << participantIndex)) != 0) {
                    gWiFiSession->mKartCount++;
                }
            }
            SetRaceSetupCopyEntryIndex((u8) gWiFiSession->mPackedIndices[GetOwnParticipantIndex()]);
            SetSessionKartCount(gWiFiSession->mKartCount);
            break;
        case 3:
            for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
                if (participantIndex != GetOwnParticipantIndex() &&
                    (gWiFiSession->mKartMask & (1 << participantIndex)) != 0) {
                    SetPeerReceiveBuffer(participantIndex, &gWiFiSession->mReceiveBuffers[participantIndex], 0x44);
                }
                gWiFiSession->mStepFrames = 0;
                gWiFiSession->mSendRecordMask = 0;
                gWiFiSession->mReceivedMask = 0;
                GetRaceSetupCopy()->mEntries[participantIndex].mCharacterIndex = -1;
                GetRaceSetupCopy()->mEntries[participantIndex].mKartIndex = -1;
                GetRaceSetupCopy()->mCourseId = 0;
                gWiFiSession->mIndexMessages[participantIndex].mCharacterIndex = -1;
                gWiFiSession->mIndexMessages[participantIndex].mKartIndex = -1;
                gWiFiSession->mIndexMessages[participantIndex].mPickedCourseId = 0;
                gWiFiSession->mIndexMessages[participantIndex].mContinueChoice = 0;
                gWiFiSession->mReceiveBuffers[participantIndex].mCharacterIndex = -1;
                gWiFiSession->mReceiveBuffers[participantIndex].mKartIndex = -1;
                gWiFiSession->mReceiveBuffers[participantIndex].mPickedCourseId = 0;
                gWiFiSession->mReceiveBuffers[participantIndex].mContinueChoice = 0;
            }
            DWC_SetUserRecvCallback(ReceiveWiFiSessionMessage);
            gWiFiSession->mStep = 3;
            break;
    }
}

// One frame of the exchange: counts the frames since each kart last called back, marks silent karts and drops them,
// then runs the handler of the current mStep (steps 2, 6, 7, 11 and 12 inline). Always returns 0.
s32 UpdateWiFiSessionStep(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    s32 waitFlag;
    WiFiSessionMessage *ownRecord;
    BackupAccess *backup;
    UpdateWiFiSessionKartTimeouts();
    RemoveWiFiSessionKarts();
    switch (gWiFiSession->mStep) {
        case 0:
            AdvanceWiFiSessionStep0();
            break;
        case 1:
            AdvanceWiFiSessionStep1();
            break;
        case 2:
            UpdateWiFiSessionStepTimeout(0x1c20);
            if (gBackupBuffers->mBusy == 0) {
                backup = gBackupAccess;
                if (backup->mBackupEnabled != 0) {
                    waitFlag = backup->mCommandRunning;
                } else {
                    waitFlag = 0;
                }
            } else {
                waitFlag = 1;
            }
            if (waitFlag == 0) {
                gWiFiSession->mStepFrames = 0;
                gWiFiSession->mStep = 5;
            }
            break;
        case 3:
            AdvanceWiFiSessionStep3();
            break;
        case 4:
            AdvanceWiFiSessionStep4();
            break;
        case 5:
            AdvanceWiFiSessionStep5();
            break;
        case 6:
            UpdateWiFiSessionStepTimeout(0x1c20);
            toIndex = PickNextToIndex();
            if (toIndex < gWiFiSession->mStartKartCount) {
                fromIndex = GetOwnParticipantIndex();
                ownIndex = GetOwnParticipantIndex();
                ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
                ownRecord->mKind = 4;
                ownRecord->mSize = 0x44;
                ownRecord->mFromIndex = fromIndex;
                ownRecord->mToIndex = toIndex;
                ownRecord->mKartMask = gWiFiSession->mKartMask;
                DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[GetOwnParticipantIndex()], 0x44);
            }
            if (AreAllStepMessagesReceived() != FALSE) {
                gWiFiSession->mSendRecordMask = 0;
                gWiFiSession->mReceivedMask = 0;
                CombineKartRemoveMask();
                gWiFiSession->mStep = 7;
                gWiFiSession->mStepFrames = 0;
            }
            break;
        case 7:
            UpdateWiFiSessionStepTimeout(0x1c20);
            toIndex = PickNextToIndex();
            if (toIndex < gWiFiSession->mStartKartCount) {
                fromIndex = GetOwnParticipantIndex();
                ownIndex = GetOwnParticipantIndex();
                ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
                ownRecord->mKind = 5;
                ownRecord->mSize = 0x44;
                ownRecord->mFromIndex = fromIndex;
                ownRecord->mToIndex = toIndex;
                ownRecord->mKartMask = gWiFiSession->mKartMask;
                DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[GetOwnParticipantIndex()], 0x44);
            }
            if (AreAllStepMessagesReceived() != FALSE) {
                ownIndex = GetOwnParticipantIndex();
                if (gWiFiSession->mIndexMessages[ownIndex].mPickedCourseId != 0) {
                    gWiFiSession->mSendRecordMask = 0;
                    gWiFiSession->mReceivedMask = 0;
                    gWiFiSession->mStep = 8;
                    gWiFiSession->mStepFrames = 0;
                }
            }
            break;
        case 8:
            AdvanceWiFiSessionStep8();
            break;
        case 9:
            AdvanceWiFiSessionStep9();
            break;
        case 11:
            UpdateWiFiSessionStepTimeout(0x1c20);
            if (DWC_GetNumConnectionHost() <= 1) {
                gWiFiSession->mStepFrames = 0;
                gWiFiSession->mStep = 12;
            }
            break;
        case 12:
            break;
    }
    return 0;
}

void AdvanceWiFiSessionStep0(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u32 toBit;
    WiFiPlayerRecord *ownPlayerRecord;
    WiFiSessionMessageHeader header;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = PickNextToIndex();
    if (toIndex < gWiFiSession->mStartKartCount) {
        toBit = 1 << toIndex;
        if ((gWiFiSession->mSendRecordMask & toBit) != 0) {
            fromIndex = GetOwnParticipantIndex();
            ownIndex = GetOwnParticipantIndex();
            ownPlayerRecord = &gWiFiSession->mPlayerRecords[ownIndex];
            ownPlayerRecord->mKind = 1;
            ownPlayerRecord->mSize = 0x244;
            ownPlayerRecord->mFromIndex = fromIndex;
            ownPlayerRecord->mToIndex = toIndex;
            ownPlayerRecord->mKartMask = gWiFiSession->mKartMask;
            ownIndex = GetOwnParticipantIndex();
            DWC_SendUnreliable(toIndex, &gWiFiSession->mPlayerRecords[ownIndex], 0x244);
            gWiFiSession->mSendRecordMask &= ~toBit;
        } else if ((gWiFiSession->mReceivedMask & toBit) == 0) {
            header.mFromIndex = GetOwnParticipantIndex();
            header.mSize = 0xc;
            header.mToIndex = toIndex;
            header.mKind = 0;
            header.mKartMask = gWiFiSession->mKartMask;
            DWC_SendUnreliable(toIndex, &header, 0xc);
        }
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStepFrames = 0;
    gWiFiSession->mStep = 1;
}

void AdvanceWiFiSessionStep1(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u8 participantIndex;
    u32 toBit;
    u32 seedSum;
    WiFiSession *session;
    WiFiPlayerRecord *ownPlayerRecord;
    RandomState64 *generator;
    WiFiSessionMessageHeader header;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = PickNextToIndex();
    if (toIndex < gWiFiSession->mStartKartCount) {
        toBit = 1 << toIndex;
        if ((gWiFiSession->mSendRecordMask & toBit) != 0) {
            fromIndex = GetOwnParticipantIndex();
            ownIndex = GetOwnParticipantIndex();
            ownPlayerRecord = &gWiFiSession->mPlayerRecords[ownIndex];
            ownPlayerRecord->mKind = 1;
            ownPlayerRecord->mSize = 0x244;
            ownPlayerRecord->mFromIndex = fromIndex;
            ownPlayerRecord->mToIndex = toIndex;
            ownPlayerRecord->mKartMask = gWiFiSession->mKartMask;
            ownIndex = GetOwnParticipantIndex();
            DWC_SendUnreliable(toIndex, &gWiFiSession->mPlayerRecords[ownIndex], 0x244);
            gWiFiSession->mSendRecordMask &= ~toBit;
        } else {
            header.mFromIndex = GetOwnParticipantIndex();
            header.mSize = 0xc;
            header.mToIndex = toIndex;
            header.mKind = 2;
            header.mKartMask = gWiFiSession->mKartMask;
            DWC_SendUnreliable(toIndex, &header, 0xc);
        }
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    session = gWiFiSession;
    seedSum = 0;
    for (participantIndex = 0; participantIndex < session->mStartKartCount; participantIndex++) {
        seedSum += session->mPlayerRecords[participantIndex].mSeed;
    }
    generator = &session->mRandom;
    generator->mValue = seedSum;
    generator->mMultiplier = 0x5d588b656c078965;
    generator->mIncrement = 0x269ec3;
    StartCopyOtherEmblems(0);
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStepFrames = 0;
    gWiFiSession->mStep = 2;
}

void AdvanceWiFiSessionStep3(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    WiFiSessionMessage *ownRecord;
    UpdateWiFiSessionStepTimeout(0x1c20);
    ownIndex = GetOwnParticipantIndex();
    if (gWiFiSession->mIndexMessages[ownIndex].mContinueChoice == 2) {
        DWC_RegisterMatchingStatus();
        DWC_CloseAllConnectionsHard();
        gWiFiSession->mStep = 11;
        return;
    }
    toIndex = PickNextToIndex();
    if (toIndex < gWiFiSession->mStartKartCount) {
        fromIndex = GetOwnParticipantIndex();
        ownIndex = GetOwnParticipantIndex();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = 8;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[GetOwnParticipantIndex()], 0x44);
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    ownIndex = GetOwnParticipantIndex();
    if (gWiFiSession->mIndexMessages[ownIndex].mContinueChoice == 0) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = 4;
    gWiFiSession->mStepFrames = 0;
}

void AdvanceWiFiSessionStep4(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    WiFiSessionMessage *ownRecord;
    StateMachine *stateMachine;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = PickNextToIndex();
    if (toIndex < gWiFiSession->mStartKartCount) {
        fromIndex = GetOwnParticipantIndex();
        ownIndex = GetOwnParticipantIndex();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = 9;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[GetOwnParticipantIndex()], 0x44);
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    if (gWiFiSession->mKartCount == 1) {
        DWC_RegisterMatchingStatus();
        DWC_CloseAllConnectionsHard();
        stateMachine = &gWiFiSession->mStateMachine;
        stateMachine->mNextState = 2;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = 5;
    gWiFiSession->mStepFrames = 0;
    ownIndex = GetOwnParticipantIndex();
    SetRaceSetupCopyEntryIndex((u8) gWiFiSession->mPackedIndices[ownIndex]);
    SetSessionKartCount(gWiFiSession->mKartCount);
}

void AdvanceWiFiSessionStep5(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    WiFiSessionMessage *ownRecord;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = PickNextToIndex();
    if (toIndex < gWiFiSession->mStartKartCount) {
        fromIndex = GetOwnParticipantIndex();
        ownIndex = GetOwnParticipantIndex();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = 3;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[GetOwnParticipantIndex()], 0x44);
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    ownIndex = GetOwnParticipantIndex();
    if (gWiFiSession->mIndexMessages[ownIndex].mCharacterIndex == -1) {
        return;
    }
    ownIndex = GetOwnParticipantIndex();
    if (gWiFiSession->mIndexMessages[ownIndex].mKartIndex == -1) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = 6;
    gWiFiSession->mStepFrames = 0;
}

void AdvanceWiFiSessionStep8(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u8 participantIndex;
    WiFiSessionMessage *ownRecord;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = PickNextToIndex();
    if (toIndex < gWiFiSession->mStartKartCount) {
        fromIndex = GetOwnParticipantIndex();
        ownIndex = GetOwnParticipantIndex();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = 6;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[GetOwnParticipantIndex()], 0x44);
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    CombineKartRemoveMask();
    TallyPickedCourse();
    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        ownIndex = GetOwnParticipantIndex();
        gWiFiSession->mIndexMessages[ownIndex].mKartIndices[participantIndex] =
            gWiFiSession->mIndexMessages[participantIndex].mKartIndex;
        ownIndex = GetOwnParticipantIndex();
        gWiFiSession->mIndexMessages[ownIndex].mCharacterIndices[participantIndex] =
            gWiFiSession->mIndexMessages[participantIndex].mCharacterIndex;
    }
    ownIndex = GetOwnParticipantIndex();
    gWiFiSession->mIndexMessages[ownIndex].mTalliedCourseId = GetRaceSetupCopy()->mCourseId;
    gWiFiSession->mStep = 9;
    gWiFiSession->mStepFrames = 0;
}

void AdvanceWiFiSessionStep9(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u8 participantIndex;
    WiFiSessionMessage *ownRecord;
    toIndex = PickNextToIndex();
    if (toIndex < gWiFiSession->mStartKartCount) {
        fromIndex = GetOwnParticipantIndex();
        ownIndex = GetOwnParticipantIndex();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = 7;
        ownRecord->mSize = 0x44;
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[GetOwnParticipantIndex()], 0x44);
    }
    if (UpdateWiFiSessionStepTimeout(0x78) == FALSE) {
        return;
    }
    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        if (participantIndex != GetOwnParticipantIndex() && (gWiFiSession->mKartMask & (1 << participantIndex)) != 0) {
            if (SetPeerReceiveBuffer(participantIndex, gWiFiSession->mUnk_001c[participantIndex], 0x80) == FALSE) {
                return;
            }
        }
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = 10;
    gWiFiSession->mStepFrames = 0;
}

// Only while 5 <= mStep < 9: ORs into mKartRemoveMask every kart in mKartMask that some stored mask (own included) does
// not list.
void CombineKartRemoveMask(void) {
    u8 participantIndex;
    u8 commonMask = 0xff;
    if (gWiFiSession->mStep < 5) {
        return;
    }
    if (gWiFiSession->mStep >= 9) {
        return;
    }
    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        if ((gWiFiSession->mKartMask & (1 << participantIndex)) != 0) {
            commonMask &= gWiFiSession->mIndexMessages[participantIndex].mKartMask;
        }
    }
    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        if ((gWiFiSession->mKartMask & (1 << participantIndex)) != 0) {
            if ((commonMask & (1 << participantIndex)) == 0) {
                gWiFiSession->mKartRemoveMask |= 1 << participantIndex;
            }
        }
    }
}
