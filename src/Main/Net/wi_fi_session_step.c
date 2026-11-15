#include "Main/Net/wi_fi_session_step.h"
#include "00/code_0219b000.h"
#include "00/Lib/DWC/code_0219b1f8.h"
#include "00/code_021a2000.h"
#include "00/Lib/DWC/code_021a2ccc.h"
#include "00/code_021a3000.h"
#include "00/Lib/DWC/code_021a3264.h"
#include "00/unk_021b5000.h"
#include "Main/Net/wifi_session.h"
#include "Main/Net/wifi_session_karts.h"
#include "Main/Race/race_setup.h"
#include "Main/Net/wifi_session_login.h"
#include "Main/MapObjects/data_0217a000.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "os_tick.h"
#include "code_0214d018.h"
#include "Main/Save/ghost_record_file.h"

// Sets the session up for a WiFiSessionSetup mode: the first resets masks, records and picks and starts at the first
// step, the second only packs the indices and counts the karts, the last two reset the picks and restart at the course
// picks or the continue choices.
void SetupWiFiSession(u32 mode) {
    u8 participantIndex;
    u8 ownIndex;
    WriteChangedWiFiBuddies();
    switch (mode) {
        case WIFI_SESSION_SETUP_FIRST:
            MI_CpuFill8(&gWiFiSession->mStep, 0, 0x60);
            MI_CpuFill8(gWiFiSession->mIndexMessages, 0, sizeof(gWiFiSession->mIndexMessages));
            MI_CpuFill8(gWiFiSession->mReceiveBuffers, 0, sizeof(gWiFiSession->mReceiveBuffers));
            for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
                if (participantIndex != DWC_GetMyAID()) {
                    DWC_SetRecvBuffer(participantIndex, &gWiFiSession->mPlayerRecords[participantIndex],
                                      sizeof(WiFiPlayerRecord));
                    GetRaceSetupCopy()->mEntries[participantIndex].mPlayerKind = PLAYER_KIND_PEER;
                } else {
                    gWiFiSession->mPlayerRecords[participantIndex].mFirstTotal =
                        gBackupBuffers->mFirstBlock->mTotals[4];
                    gWiFiSession->mPlayerRecords[participantIndex].mSecondTotal =
                        gBackupBuffers->mFirstBlock->mTotals[5];
                    GetRaceSetupCopy()->mEntries[participantIndex].mPlayerKind = PLAYER_KIND_HUMAN;
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
            ownIndex = DWC_GetMyAID();
            gWiFiSession->mPlayerRecords[ownIndex].mSeed = OS_GetTick();
            PackWiFiSessionIndices();
            gWiFiSession->mStep = WIFI_SESSION_STEP_EXCHANGE_RECORDS;
            SetRaceSetupCopyEntryIndex((u8) gWiFiSession->mPackedIndices[DWC_GetMyAID()]);
            SetSessionKartCount(gWiFiSession->mStartKartCount);
            break;
        case WIFI_SESSION_SETUP_PACK:
            PackWiFiSessionIndices();
            gWiFiSession->mKartCount = 0;
            for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
                if (BIT_IS_SET(gWiFiSession->mKartMask, participantIndex)) {
                    gWiFiSession->mKartCount++;
                }
            }
            SetRaceSetupCopyEntryIndex((u8) gWiFiSession->mPackedIndices[DWC_GetMyAID()]);
            SetSessionKartCount(gWiFiSession->mKartCount);
            break;
        case WIFI_SESSION_SETUP_COURSE_PICKS:
            for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
                if (participantIndex != DWC_GetMyAID() && BIT_IS_SET(gWiFiSession->mKartMask, participantIndex)) {
                    DWC_SetRecvBuffer(participantIndex, &gWiFiSession->mReceiveBuffers[participantIndex],
                                      sizeof(WiFiSessionMessage));
                }
                GetRaceSetupCopy()->mCourseId = 0;
                gWiFiSession->mIndexMessages[participantIndex].mPickedCourseId = 0;
                gWiFiSession->mReceiveBuffers[participantIndex].mPickedCourseId = 0;
            }
            DWC_SetUserRecvCallback(ReceiveWiFiSessionMessage);
            gWiFiSession->mStep = WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS;
            gWiFiSession->mStepFrames = 0;
            gWiFiSession->mSendRecordMask = 0;
            gWiFiSession->mReceivedMask = 0;
            PackWiFiSessionIndices();
            gWiFiSession->mKartCount = 0;
            for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
                if (BIT_IS_SET(gWiFiSession->mKartMask, participantIndex)) {
                    gWiFiSession->mKartCount++;
                }
            }
            SetRaceSetupCopyEntryIndex((u8) gWiFiSession->mPackedIndices[DWC_GetMyAID()]);
            SetSessionKartCount(gWiFiSession->mKartCount);
            break;
        case WIFI_SESSION_SETUP_CONTINUE_CHOICES:
            for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
                if (participantIndex != DWC_GetMyAID() && BIT_IS_SET(gWiFiSession->mKartMask, participantIndex)) {
                    DWC_SetRecvBuffer(participantIndex, &gWiFiSession->mReceiveBuffers[participantIndex],
                                      sizeof(WiFiSessionMessage));
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
                gWiFiSession->mIndexMessages[participantIndex].mContinueChoice = WIFI_CONTINUE_CHOICE_NONE;
                gWiFiSession->mReceiveBuffers[participantIndex].mCharacterIndex = -1;
                gWiFiSession->mReceiveBuffers[participantIndex].mKartIndex = -1;
                gWiFiSession->mReceiveBuffers[participantIndex].mPickedCourseId = 0;
                gWiFiSession->mReceiveBuffers[participantIndex].mContinueChoice = WIFI_CONTINUE_CHOICE_NONE;
            }
            DWC_SetUserRecvCallback(ReceiveWiFiSessionMessage);
            gWiFiSession->mStep = WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES;
            break;
    }
}

// One frame of the exchange: counts the frames since each kart last called back, marks silent karts and drops them,
// then runs the handler of the current mStep (WAIT_BACKUP, EXCHANGE_PICK_MASKS, EXCHANGE_COURSE_PICKS, LEAVING and
// ENDED inline). Always returns 0.
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
        case WIFI_SESSION_STEP_EXCHANGE_RECORDS:
            AdvanceWiFiSessionStep0();
            break;
        case WIFI_SESSION_STEP_EXCHANGE_SEEDS:
            AdvanceWiFiSessionStep1();
            break;
        case WIFI_SESSION_STEP_WAIT_BACKUP:
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
                gWiFiSession->mStep = WIFI_SESSION_STEP_EXCHANGE_PICKS;
            }
            break;
        case WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES:
            AdvanceWiFiSessionStep3();
            break;
        case WIFI_SESSION_STEP_CONFIRM_CONTINUE:
            AdvanceWiFiSessionStep4();
            break;
        case WIFI_SESSION_STEP_EXCHANGE_PICKS:
            AdvanceWiFiSessionStep5();
            break;
        case WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS:
            UpdateWiFiSessionStepTimeout(0x1c20);
            toIndex = PickNextToIndex();
            if (toIndex < gWiFiSession->mStartKartCount) {
                fromIndex = DWC_GetMyAID();
                ownIndex = DWC_GetMyAID();
                ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
                ownRecord->mKind = WIFI_SESSION_MESSAGE_PICK_MASK;
                ownRecord->mSize = sizeof(WiFiSessionMessage);
                ownRecord->mFromIndex = fromIndex;
                ownRecord->mToIndex = toIndex;
                ownRecord->mKartMask = gWiFiSession->mKartMask;
                DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
            }
            if (AreAllStepMessagesReceived() != FALSE) {
                gWiFiSession->mSendRecordMask = 0;
                gWiFiSession->mReceivedMask = 0;
                CombineKartRemoveMask();
                gWiFiSession->mStep = WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS;
                gWiFiSession->mStepFrames = 0;
            }
            break;
        case WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS:
            UpdateWiFiSessionStepTimeout(0x1c20);
            toIndex = PickNextToIndex();
            if (toIndex < gWiFiSession->mStartKartCount) {
                fromIndex = DWC_GetMyAID();
                ownIndex = DWC_GetMyAID();
                ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
                ownRecord->mKind = WIFI_SESSION_MESSAGE_COURSE_PICK;
                ownRecord->mSize = sizeof(WiFiSessionMessage);
                ownRecord->mFromIndex = fromIndex;
                ownRecord->mToIndex = toIndex;
                ownRecord->mKartMask = gWiFiSession->mKartMask;
                DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
            }
            if (AreAllStepMessagesReceived() != FALSE) {
                ownIndex = DWC_GetMyAID();
                if (gWiFiSession->mIndexMessages[ownIndex].mPickedCourseId != 0) {
                    gWiFiSession->mSendRecordMask = 0;
                    gWiFiSession->mReceivedMask = 0;
                    gWiFiSession->mStep = WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS;
                    gWiFiSession->mStepFrames = 0;
                }
            }
            break;
        case WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS:
            AdvanceWiFiSessionStep8();
            break;
        case WIFI_SESSION_STEP_VERIFY_RESULT:
            AdvanceWiFiSessionStep9();
            break;
        case WIFI_SESSION_STEP_LEAVING:
            UpdateWiFiSessionStepTimeout(0x1c20);
            if (DWC_GetNumConnectionHost() <= 1) {
                gWiFiSession->mStepFrames = 0;
                gWiFiSession->mStep = WIFI_SESSION_STEP_ENDED;
            }
            break;
        case WIFI_SESSION_STEP_ENDED:
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
            fromIndex = DWC_GetMyAID();
            ownIndex = DWC_GetMyAID();
            ownPlayerRecord = &gWiFiSession->mPlayerRecords[ownIndex];
            ownPlayerRecord->mKind = WIFI_SESSION_MESSAGE_RECORD;
            ownPlayerRecord->mSize = sizeof(WiFiPlayerRecord);
            ownPlayerRecord->mFromIndex = fromIndex;
            ownPlayerRecord->mToIndex = toIndex;
            ownPlayerRecord->mKartMask = gWiFiSession->mKartMask;
            ownIndex = DWC_GetMyAID();
            DWC_SendUnreliable(toIndex, &gWiFiSession->mPlayerRecords[ownIndex], sizeof(WiFiPlayerRecord));
            gWiFiSession->mSendRecordMask &= ~toBit;
        } else if ((gWiFiSession->mReceivedMask & toBit) == 0) {
            header.mFromIndex = DWC_GetMyAID();
            header.mSize = sizeof(WiFiSessionMessageHeader);
            header.mToIndex = toIndex;
            header.mKind = WIFI_SESSION_MESSAGE_RECORD_REQUEST;
            header.mKartMask = gWiFiSession->mKartMask;
            DWC_SendUnreliable(toIndex, &header, sizeof(WiFiSessionMessageHeader));
        }
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStepFrames = 0;
    gWiFiSession->mStep = WIFI_SESSION_STEP_EXCHANGE_SEEDS;
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
            fromIndex = DWC_GetMyAID();
            ownIndex = DWC_GetMyAID();
            ownPlayerRecord = &gWiFiSession->mPlayerRecords[ownIndex];
            ownPlayerRecord->mKind = WIFI_SESSION_MESSAGE_RECORD;
            ownPlayerRecord->mSize = sizeof(WiFiPlayerRecord);
            ownPlayerRecord->mFromIndex = fromIndex;
            ownPlayerRecord->mToIndex = toIndex;
            ownPlayerRecord->mKartMask = gWiFiSession->mKartMask;
            ownIndex = DWC_GetMyAID();
            DWC_SendUnreliable(toIndex, &gWiFiSession->mPlayerRecords[ownIndex], sizeof(WiFiPlayerRecord));
            gWiFiSession->mSendRecordMask &= ~toBit;
        } else {
            header.mFromIndex = DWC_GetMyAID();
            header.mSize = sizeof(WiFiSessionMessageHeader);
            header.mToIndex = toIndex;
            header.mKind = WIFI_SESSION_MESSAGE_RECORDS_SENT;
            header.mKartMask = gWiFiSession->mKartMask;
            DWC_SendUnreliable(toIndex, &header, sizeof(WiFiSessionMessageHeader));
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
    generator->mMultiplier = RANDOM_STATE64_MULTIPLIER;
    generator->mIncrement = RANDOM_STATE64_INCREMENT;
    StartCopyOtherEmblems(0);
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStepFrames = 0;
    gWiFiSession->mStep = WIFI_SESSION_STEP_WAIT_BACKUP;
}

void AdvanceWiFiSessionStep3(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    WiFiSessionMessage *ownRecord;
    UpdateWiFiSessionStepTimeout(0x1c20);
    ownIndex = DWC_GetMyAID();
    if (gWiFiSession->mIndexMessages[ownIndex].mContinueChoice == WIFI_CONTINUE_CHOICE_QUIT) {
        DWC_RegisterMatchingStatus();
        DWC_CloseAllConnectionsHard();
        gWiFiSession->mStep = WIFI_SESSION_STEP_LEAVING;
        return;
    }
    toIndex = PickNextToIndex();
    if (toIndex < gWiFiSession->mStartKartCount) {
        fromIndex = DWC_GetMyAID();
        ownIndex = DWC_GetMyAID();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = WIFI_SESSION_MESSAGE_CONTINUE_CHOICE;
        ownRecord->mSize = sizeof(WiFiSessionMessage);
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    ownIndex = DWC_GetMyAID();
    if (gWiFiSession->mIndexMessages[ownIndex].mContinueChoice == WIFI_CONTINUE_CHOICE_NONE) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = WIFI_SESSION_STEP_CONFIRM_CONTINUE;
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
        fromIndex = DWC_GetMyAID();
        ownIndex = DWC_GetMyAID();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = WIFI_SESSION_MESSAGE_CONTINUE_CONFIRM;
        ownRecord->mSize = sizeof(WiFiSessionMessage);
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    if (gWiFiSession->mKartCount == 1) {
        DWC_RegisterMatchingStatus();
        DWC_CloseAllConnectionsHard();
        stateMachine = &gWiFiSession->mStateMachine;
        stateMachine->mNextState = WIFI_SESSION_STATE_IDLE;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = WIFI_SESSION_STEP_EXCHANGE_PICKS;
    gWiFiSession->mStepFrames = 0;
    ownIndex = DWC_GetMyAID();
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
        fromIndex = DWC_GetMyAID();
        ownIndex = DWC_GetMyAID();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = WIFI_SESSION_MESSAGE_PICKS;
        ownRecord->mSize = sizeof(WiFiSessionMessage);
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    ownIndex = DWC_GetMyAID();
    if (gWiFiSession->mIndexMessages[ownIndex].mCharacterIndex == -1) {
        return;
    }
    ownIndex = DWC_GetMyAID();
    if (gWiFiSession->mIndexMessages[ownIndex].mKartIndex == -1) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS;
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
        fromIndex = DWC_GetMyAID();
        ownIndex = DWC_GetMyAID();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = WIFI_SESSION_MESSAGE_COURSE_MASK;
        ownRecord->mSize = sizeof(WiFiSessionMessage);
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    CombineKartRemoveMask();
    TallyPickedCourse();
    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        ownIndex = DWC_GetMyAID();
        gWiFiSession->mIndexMessages[ownIndex].mKartIndices[participantIndex] =
            gWiFiSession->mIndexMessages[participantIndex].mKartIndex;
        ownIndex = DWC_GetMyAID();
        gWiFiSession->mIndexMessages[ownIndex].mCharacterIndices[participantIndex] =
            gWiFiSession->mIndexMessages[participantIndex].mCharacterIndex;
    }
    ownIndex = DWC_GetMyAID();
    gWiFiSession->mIndexMessages[ownIndex].mTalliedCourseId = GetRaceSetupCopy()->mCourseId;
    gWiFiSession->mStep = WIFI_SESSION_STEP_VERIFY_RESULT;
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
        fromIndex = DWC_GetMyAID();
        ownIndex = DWC_GetMyAID();
        ownRecord = &gWiFiSession->mIndexMessages[ownIndex];
        ownRecord->mKind = WIFI_SESSION_MESSAGE_RESULT;
        ownRecord->mSize = sizeof(WiFiSessionMessage);
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = gWiFiSession->mKartMask;
        DWC_SendUnreliable(toIndex, &gWiFiSession->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
    }
    if (UpdateWiFiSessionStepTimeout(0x78) == FALSE) {
        return;
    }
    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        if (participantIndex != DWC_GetMyAID() && BIT_IS_SET(gWiFiSession->mKartMask, participantIndex)) {
            if (DWC_SetRecvBuffer(participantIndex, gWiFiSession->mRecvBuffers[participantIndex], 0x80) == FALSE) {
                return;
            }
        }
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = WIFI_SESSION_STEP_READY;
    gWiFiSession->mStepFrames = 0;
}

// Only from EXCHANGE_PICKS up to before VERIFY_RESULT: ORs into mKartRemoveMask every kart in mKartMask that some
// stored mask (own included) does not list.
void CombineKartRemoveMask(void) {
    u8 participantIndex;
    u8 commonMask = 0xff;
    if (gWiFiSession->mStep < WIFI_SESSION_STEP_EXCHANGE_PICKS) {
        return;
    }
    if (gWiFiSession->mStep >= WIFI_SESSION_STEP_VERIFY_RESULT) {
        return;
    }
    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        if (BIT_IS_SET(gWiFiSession->mKartMask, participantIndex)) {
            commonMask &= gWiFiSession->mIndexMessages[participantIndex].mKartMask;
        }
    }
    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        if (BIT_IS_SET(gWiFiSession->mKartMask, participantIndex)) {
            if ((commonMask & (1 << participantIndex)) == 0) {
                BIT_SET(gWiFiSession->mKartRemoveMask, participantIndex);
            }
        }
    }
}
