#include "Main/Net/wi_fi_session_step.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "00/Lib/DWC/data_transport.h"
#include "00/Lib/DWC/match_send_and_key_value_strings.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "Main/Net/wifi_session.h"
#include "Main/Net/wifi_session_karts.h"
#include "Main/Race/race_setup.h"
#include "Main/Net/wifi_session_login.h"
#include "Main/System/backup_net_camera_work.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "tick_counter.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record_file.h"

// Sets the session up for a WiFiSessionSetup mode: the first resets masks, records and picks and starts at the first
// step, the second only packs the indices and counts the karts, the last two reset the picks and restart at the course
// picks or the continue choices.
void SetupWiFiSession(u32 mode) {
    u8 participantIndex;
    u8 ownIndex;
    WriteSaveFriendCodes();
    switch (mode) {
        case WIFI_SESSION_SETUP_FIRST:
            Mem_CpuFill8(&g_GlobalB->mStep, 0, 0x60);
            Mem_CpuFill8(g_GlobalB->mIndexMessages, 0, sizeof(g_GlobalB->mIndexMessages));
            Mem_CpuFill8(g_GlobalB->mReceiveBuffers, 0, sizeof(g_GlobalB->mReceiveBuffers));
            for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
                if (participantIndex != DWC_GetMyAID()) {
                    DWC_SetRecvBuffer(participantIndex, &g_GlobalB->mPlayerRecords[participantIndex],
                                      sizeof(WiFiPlayerRecord));
                    GetGlobalCA_from_thumb()->mEntries[participantIndex].mPlayerKind = PLAYER_KIND_PEER;
                } else {
                    g_GlobalB->mPlayerRecords[participantIndex].mFirstTotal =
                        g_SaveDataHolder->mFirstBlock->mTotals[4];
                    g_GlobalB->mPlayerRecords[participantIndex].mSecondTotal =
                        g_SaveDataHolder->mFirstBlock->mTotals[5];
                    GetGlobalCA_from_thumb()->mEntries[participantIndex].mPlayerKind = PLAYER_KIND_HUMAN;
                }
                GetGlobalCA_from_thumb()->mEntries[participantIndex].mCharacterIndex = -1;
                GetGlobalCA_from_thumb()->mEntries[participantIndex].mKartIndex = -1;
                GetGlobalCA_from_thumb()->mCourseId = 0;
                g_GlobalB->mIndexMessages[participantIndex].mCharacterIndex = -1;
                g_GlobalB->mIndexMessages[participantIndex].mKartIndex = -1;
                g_GlobalB->mIndexMessages[participantIndex].mPickedCourseId = 0;
                g_GlobalB->mReceiveBuffers[participantIndex].mCharacterIndex = -1;
                g_GlobalB->mReceiveBuffers[participantIndex].mKartIndex = -1;
                g_GlobalB->mReceiveBuffers[participantIndex].mPickedCourseId = 0;
            }
            g_GlobalB->mStepFrames = 0;
            g_GlobalB->mSendRecordMask = 0;
            g_GlobalB->mReceivedMask = 0;
            DWC_SetUserRecvCallback(ReceiveWiFiSessionMessage);
            ownIndex = DWC_GetMyAID();
            g_GlobalB->mPlayerRecords[ownIndex].mSeed = Os_GetTick();
            PackWiFiSessionIndices();
            g_GlobalB->mStep = WIFI_SESSION_STEP_EXCHANGE_RECORDS;
            SetRaceSetupCopyEntryIndex((u8) g_GlobalB->mPackedIndices[DWC_GetMyAID()]);
            SetSessionKartCount(g_GlobalB->mStartKartCount);
            break;
        case WIFI_SESSION_SETUP_PACK:
            PackWiFiSessionIndices();
            g_GlobalB->mKartCount = 0;
            for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
                if (BIT_IS_SET(g_GlobalB->mKartMask, participantIndex)) {
                    g_GlobalB->mKartCount++;
                }
            }
            SetRaceSetupCopyEntryIndex((u8) g_GlobalB->mPackedIndices[DWC_GetMyAID()]);
            SetSessionKartCount(g_GlobalB->mKartCount);
            break;
        case WIFI_SESSION_SETUP_COURSE_PICKS:
            for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
                if (participantIndex != DWC_GetMyAID() && BIT_IS_SET(g_GlobalB->mKartMask, participantIndex)) {
                    DWC_SetRecvBuffer(participantIndex, &g_GlobalB->mReceiveBuffers[participantIndex],
                                      sizeof(WiFiSessionMessage));
                }
                GetGlobalCA_from_thumb()->mCourseId = 0;
                g_GlobalB->mIndexMessages[participantIndex].mPickedCourseId = 0;
                g_GlobalB->mReceiveBuffers[participantIndex].mPickedCourseId = 0;
            }
            DWC_SetUserRecvCallback(ReceiveWiFiSessionMessage);
            g_GlobalB->mStep = WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS;
            g_GlobalB->mStepFrames = 0;
            g_GlobalB->mSendRecordMask = 0;
            g_GlobalB->mReceivedMask = 0;
            PackWiFiSessionIndices();
            g_GlobalB->mKartCount = 0;
            for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
                if (BIT_IS_SET(g_GlobalB->mKartMask, participantIndex)) {
                    g_GlobalB->mKartCount++;
                }
            }
            SetRaceSetupCopyEntryIndex((u8) g_GlobalB->mPackedIndices[DWC_GetMyAID()]);
            SetSessionKartCount(g_GlobalB->mKartCount);
            break;
        case WIFI_SESSION_SETUP_CONTINUE_CHOICES:
            for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
                if (participantIndex != DWC_GetMyAID() && BIT_IS_SET(g_GlobalB->mKartMask, participantIndex)) {
                    DWC_SetRecvBuffer(participantIndex, &g_GlobalB->mReceiveBuffers[participantIndex],
                                      sizeof(WiFiSessionMessage));
                }
                g_GlobalB->mStepFrames = 0;
                g_GlobalB->mSendRecordMask = 0;
                g_GlobalB->mReceivedMask = 0;
                GetGlobalCA_from_thumb()->mEntries[participantIndex].mCharacterIndex = -1;
                GetGlobalCA_from_thumb()->mEntries[participantIndex].mKartIndex = -1;
                GetGlobalCA_from_thumb()->mCourseId = 0;
                g_GlobalB->mIndexMessages[participantIndex].mCharacterIndex = -1;
                g_GlobalB->mIndexMessages[participantIndex].mKartIndex = -1;
                g_GlobalB->mIndexMessages[participantIndex].mPickedCourseId = 0;
                g_GlobalB->mIndexMessages[participantIndex].mContinueChoice = WIFI_CONTINUE_CHOICE_NONE;
                g_GlobalB->mReceiveBuffers[participantIndex].mCharacterIndex = -1;
                g_GlobalB->mReceiveBuffers[participantIndex].mKartIndex = -1;
                g_GlobalB->mReceiveBuffers[participantIndex].mPickedCourseId = 0;
                g_GlobalB->mReceiveBuffers[participantIndex].mContinueChoice = WIFI_CONTINUE_CHOICE_NONE;
            }
            DWC_SetUserRecvCallback(ReceiveWiFiSessionMessage);
            g_GlobalB->mStep = WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES;
            break;
    }
}

// One frame of the exchange: counts the frames since each kart last called back, marks silent karts and drops them,
// then runs the handler of the current mStep (WAIT_BACKUP, EXCHANGE_PICK_MASKS, EXCHANGE_COURSE_PICKS, LEAVING and
// ENDED inline). Always returns 0.
s32 GlobalB_E7Fn_4BImpl(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    s32 waitFlag;
    WiFiSessionMessage *ownRecord;
    BackupAccess *backup;
    UpdateWiFiSessionKartTimeouts();
    RemoveWiFiSessionKarts();
    switch (g_GlobalB->mStep) {
        case WIFI_SESSION_STEP_EXCHANGE_RECORDS:
            AdvanceWiFiSessionStep0();
            break;
        case WIFI_SESSION_STEP_EXCHANGE_SEEDS:
            AdvanceWiFiSessionStep1();
            break;
        case WIFI_SESSION_STEP_WAIT_BACKUP:
            UpdateWiFiSessionStepTimeout(0x1c20);
            if (g_SaveDataHolder->mBusy == 0) {
                backup = g_SaveDataIoManager;
                if (backup->mBackupEnabled != 0) {
                    waitFlag = backup->mCommandRunning;
                } else {
                    waitFlag = 0;
                }
            } else {
                waitFlag = 1;
            }
            if (waitFlag == 0) {
                g_GlobalB->mStepFrames = 0;
                g_GlobalB->mStep = WIFI_SESSION_STEP_EXCHANGE_PICKS;
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
            toIndex = GetSomeRacerIndex();
            if (toIndex < g_GlobalB->mStartKartCount) {
                fromIndex = DWC_GetMyAID();
                ownIndex = DWC_GetMyAID();
                ownRecord = &g_GlobalB->mIndexMessages[ownIndex];
                ownRecord->mKind = WIFI_SESSION_MESSAGE_PICK_MASK;
                ownRecord->mSize = sizeof(WiFiSessionMessage);
                ownRecord->mFromIndex = fromIndex;
                ownRecord->mToIndex = toIndex;
                ownRecord->mKartMask = g_GlobalB->mKartMask;
                DWC_SendUnreliable(toIndex, &g_GlobalB->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
            }
            if (AreAllStepMessagesReceived() != FALSE) {
                g_GlobalB->mSendRecordMask = 0;
                g_GlobalB->mReceivedMask = 0;
                CombineKartRemoveMask();
                g_GlobalB->mStep = WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS;
                g_GlobalB->mStepFrames = 0;
            }
            break;
        case WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS:
            UpdateWiFiSessionStepTimeout(0x1c20);
            toIndex = GetSomeRacerIndex();
            if (toIndex < g_GlobalB->mStartKartCount) {
                fromIndex = DWC_GetMyAID();
                ownIndex = DWC_GetMyAID();
                ownRecord = &g_GlobalB->mIndexMessages[ownIndex];
                ownRecord->mKind = WIFI_SESSION_MESSAGE_COURSE_PICK;
                ownRecord->mSize = sizeof(WiFiSessionMessage);
                ownRecord->mFromIndex = fromIndex;
                ownRecord->mToIndex = toIndex;
                ownRecord->mKartMask = g_GlobalB->mKartMask;
                DWC_SendUnreliable(toIndex, &g_GlobalB->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
            }
            if (AreAllStepMessagesReceived() != FALSE) {
                ownIndex = DWC_GetMyAID();
                if (g_GlobalB->mIndexMessages[ownIndex].mPickedCourseId != 0) {
                    g_GlobalB->mSendRecordMask = 0;
                    g_GlobalB->mReceivedMask = 0;
                    g_GlobalB->mStep = WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS;
                    g_GlobalB->mStepFrames = 0;
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
                g_GlobalB->mStepFrames = 0;
                g_GlobalB->mStep = WIFI_SESSION_STEP_ENDED;
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
    toIndex = GetSomeRacerIndex();
    if (toIndex < g_GlobalB->mStartKartCount) {
        toBit = 1 << toIndex;
        if ((g_GlobalB->mSendRecordMask & toBit) != 0) {
            fromIndex = DWC_GetMyAID();
            ownIndex = DWC_GetMyAID();
            ownPlayerRecord = &g_GlobalB->mPlayerRecords[ownIndex];
            ownPlayerRecord->mKind = WIFI_SESSION_MESSAGE_RECORD;
            ownPlayerRecord->mSize = sizeof(WiFiPlayerRecord);
            ownPlayerRecord->mFromIndex = fromIndex;
            ownPlayerRecord->mToIndex = toIndex;
            ownPlayerRecord->mKartMask = g_GlobalB->mKartMask;
            ownIndex = DWC_GetMyAID();
            DWC_SendUnreliable(toIndex, &g_GlobalB->mPlayerRecords[ownIndex], sizeof(WiFiPlayerRecord));
            g_GlobalB->mSendRecordMask &= ~toBit;
        } else if ((g_GlobalB->mReceivedMask & toBit) == 0) {
            header.mFromIndex = DWC_GetMyAID();
            header.mSize = sizeof(WiFiSessionMessageHeader);
            header.mToIndex = toIndex;
            header.mKind = WIFI_SESSION_MESSAGE_RECORD_REQUEST;
            header.mKartMask = g_GlobalB->mKartMask;
            DWC_SendUnreliable(toIndex, &header, sizeof(WiFiSessionMessageHeader));
        }
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    g_GlobalB->mSendRecordMask = 0;
    g_GlobalB->mReceivedMask = 0;
    g_GlobalB->mStepFrames = 0;
    g_GlobalB->mStep = WIFI_SESSION_STEP_EXCHANGE_SEEDS;
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
    toIndex = GetSomeRacerIndex();
    if (toIndex < g_GlobalB->mStartKartCount) {
        toBit = 1 << toIndex;
        if ((g_GlobalB->mSendRecordMask & toBit) != 0) {
            fromIndex = DWC_GetMyAID();
            ownIndex = DWC_GetMyAID();
            ownPlayerRecord = &g_GlobalB->mPlayerRecords[ownIndex];
            ownPlayerRecord->mKind = WIFI_SESSION_MESSAGE_RECORD;
            ownPlayerRecord->mSize = sizeof(WiFiPlayerRecord);
            ownPlayerRecord->mFromIndex = fromIndex;
            ownPlayerRecord->mToIndex = toIndex;
            ownPlayerRecord->mKartMask = g_GlobalB->mKartMask;
            ownIndex = DWC_GetMyAID();
            DWC_SendUnreliable(toIndex, &g_GlobalB->mPlayerRecords[ownIndex], sizeof(WiFiPlayerRecord));
            g_GlobalB->mSendRecordMask &= ~toBit;
        } else {
            header.mFromIndex = DWC_GetMyAID();
            header.mSize = sizeof(WiFiSessionMessageHeader);
            header.mToIndex = toIndex;
            header.mKind = WIFI_SESSION_MESSAGE_RECORDS_SENT;
            header.mKartMask = g_GlobalB->mKartMask;
            DWC_SendUnreliable(toIndex, &header, sizeof(WiFiSessionMessageHeader));
        }
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    session = g_GlobalB;
    seedSum = 0;
    for (participantIndex = 0; participantIndex < session->mStartKartCount; participantIndex++) {
        seedSum += session->mPlayerRecords[participantIndex].mSeed;
    }
    generator = &session->mRandom;
    generator->mValue = seedSum;
    generator->mMultiplier = RANDOM_STATE64_MULTIPLIER;
    generator->mIncrement = RANDOM_STATE64_INCREMENT;
    StartCopyOtherEmblems(0);
    g_GlobalB->mSendRecordMask = 0;
    g_GlobalB->mReceivedMask = 0;
    g_GlobalB->mStepFrames = 0;
    g_GlobalB->mStep = WIFI_SESSION_STEP_WAIT_BACKUP;
}

void AdvanceWiFiSessionStep3(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    WiFiSessionMessage *ownRecord;
    UpdateWiFiSessionStepTimeout(0x1c20);
    ownIndex = DWC_GetMyAID();
    if (g_GlobalB->mIndexMessages[ownIndex].mContinueChoice == WIFI_CONTINUE_CHOICE_QUIT) {
        DWC_RegisterMatchingStatus();
        DWC_CloseAllConnectionsHard();
        g_GlobalB->mStep = WIFI_SESSION_STEP_LEAVING;
        return;
    }
    toIndex = GetSomeRacerIndex();
    if (toIndex < g_GlobalB->mStartKartCount) {
        fromIndex = DWC_GetMyAID();
        ownIndex = DWC_GetMyAID();
        ownRecord = &g_GlobalB->mIndexMessages[ownIndex];
        ownRecord->mKind = WIFI_SESSION_MESSAGE_CONTINUE_CHOICE;
        ownRecord->mSize = sizeof(WiFiSessionMessage);
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = g_GlobalB->mKartMask;
        DWC_SendUnreliable(toIndex, &g_GlobalB->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    ownIndex = DWC_GetMyAID();
    if (g_GlobalB->mIndexMessages[ownIndex].mContinueChoice == WIFI_CONTINUE_CHOICE_NONE) {
        return;
    }
    g_GlobalB->mSendRecordMask = 0;
    g_GlobalB->mReceivedMask = 0;
    g_GlobalB->mStep = WIFI_SESSION_STEP_CONFIRM_CONTINUE;
    g_GlobalB->mStepFrames = 0;
}

void AdvanceWiFiSessionStep4(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    WiFiSessionMessage *ownRecord;
    StateMachine *stateMachine;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = GetSomeRacerIndex();
    if (toIndex < g_GlobalB->mStartKartCount) {
        fromIndex = DWC_GetMyAID();
        ownIndex = DWC_GetMyAID();
        ownRecord = &g_GlobalB->mIndexMessages[ownIndex];
        ownRecord->mKind = WIFI_SESSION_MESSAGE_CONTINUE_CONFIRM;
        ownRecord->mSize = sizeof(WiFiSessionMessage);
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = g_GlobalB->mKartMask;
        DWC_SendUnreliable(toIndex, &g_GlobalB->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    if (g_GlobalB->mKartCount == 1) {
        DWC_RegisterMatchingStatus();
        DWC_CloseAllConnectionsHard();
        stateMachine = &g_GlobalB->mStateMachine;
        stateMachine->mNextState = WIFI_SESSION_STATE_IDLE;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    g_GlobalB->mSendRecordMask = 0;
    g_GlobalB->mReceivedMask = 0;
    g_GlobalB->mStep = WIFI_SESSION_STEP_EXCHANGE_PICKS;
    g_GlobalB->mStepFrames = 0;
    ownIndex = DWC_GetMyAID();
    SetRaceSetupCopyEntryIndex((u8) g_GlobalB->mPackedIndices[ownIndex]);
    SetSessionKartCount(g_GlobalB->mKartCount);
}

void AdvanceWiFiSessionStep5(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    WiFiSessionMessage *ownRecord;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = GetSomeRacerIndex();
    if (toIndex < g_GlobalB->mStartKartCount) {
        fromIndex = DWC_GetMyAID();
        ownIndex = DWC_GetMyAID();
        ownRecord = &g_GlobalB->mIndexMessages[ownIndex];
        ownRecord->mKind = WIFI_SESSION_MESSAGE_PICKS;
        ownRecord->mSize = sizeof(WiFiSessionMessage);
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = g_GlobalB->mKartMask;
        DWC_SendUnreliable(toIndex, &g_GlobalB->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    ownIndex = DWC_GetMyAID();
    if (g_GlobalB->mIndexMessages[ownIndex].mCharacterIndex == -1) {
        return;
    }
    ownIndex = DWC_GetMyAID();
    if (g_GlobalB->mIndexMessages[ownIndex].mKartIndex == -1) {
        return;
    }
    g_GlobalB->mSendRecordMask = 0;
    g_GlobalB->mReceivedMask = 0;
    g_GlobalB->mStep = WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS;
    g_GlobalB->mStepFrames = 0;
}

void AdvanceWiFiSessionStep8(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u8 participantIndex;
    WiFiSessionMessage *ownRecord;
    UpdateWiFiSessionStepTimeout(0x1c20);
    toIndex = GetSomeRacerIndex();
    if (toIndex < g_GlobalB->mStartKartCount) {
        fromIndex = DWC_GetMyAID();
        ownIndex = DWC_GetMyAID();
        ownRecord = &g_GlobalB->mIndexMessages[ownIndex];
        ownRecord->mKind = WIFI_SESSION_MESSAGE_COURSE_MASK;
        ownRecord->mSize = sizeof(WiFiSessionMessage);
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = g_GlobalB->mKartMask;
        DWC_SendUnreliable(toIndex, &g_GlobalB->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
    }
    if (AreAllStepMessagesReceived() == FALSE) {
        return;
    }
    g_GlobalB->mSendRecordMask = 0;
    g_GlobalB->mReceivedMask = 0;
    CombineKartRemoveMask();
    MaybeVSSelectRandomCourseId();
    for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
        ownIndex = DWC_GetMyAID();
        g_GlobalB->mIndexMessages[ownIndex].mKartIndices[participantIndex] =
            g_GlobalB->mIndexMessages[participantIndex].mKartIndex;
        ownIndex = DWC_GetMyAID();
        g_GlobalB->mIndexMessages[ownIndex].mCharacterIndices[participantIndex] =
            g_GlobalB->mIndexMessages[participantIndex].mCharacterIndex;
    }
    ownIndex = DWC_GetMyAID();
    g_GlobalB->mIndexMessages[ownIndex].mTalliedCourseId = GetGlobalCA_from_thumb()->mCourseId;
    g_GlobalB->mStep = WIFI_SESSION_STEP_VERIFY_RESULT;
    g_GlobalB->mStepFrames = 0;
}

void AdvanceWiFiSessionStep9(void) {
    u8 toIndex;
    u8 fromIndex;
    u8 ownIndex;
    u8 participantIndex;
    WiFiSessionMessage *ownRecord;
    toIndex = GetSomeRacerIndex();
    if (toIndex < g_GlobalB->mStartKartCount) {
        fromIndex = DWC_GetMyAID();
        ownIndex = DWC_GetMyAID();
        ownRecord = &g_GlobalB->mIndexMessages[ownIndex];
        ownRecord->mKind = WIFI_SESSION_MESSAGE_RESULT;
        ownRecord->mSize = sizeof(WiFiSessionMessage);
        ownRecord->mFromIndex = fromIndex;
        ownRecord->mToIndex = toIndex;
        ownRecord->mKartMask = g_GlobalB->mKartMask;
        DWC_SendUnreliable(toIndex, &g_GlobalB->mIndexMessages[DWC_GetMyAID()], sizeof(WiFiSessionMessage));
    }
    if (UpdateWiFiSessionStepTimeout(0x78) == FALSE) {
        return;
    }
    for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
        if (participantIndex != DWC_GetMyAID() && BIT_IS_SET(g_GlobalB->mKartMask, participantIndex)) {
            if (DWC_SetRecvBuffer(participantIndex, g_GlobalB->mRecvBuffers[participantIndex], 0x80) == FALSE) {
                return;
            }
        }
    }
    g_GlobalB->mSendRecordMask = 0;
    g_GlobalB->mReceivedMask = 0;
    g_GlobalB->mStep = WIFI_SESSION_STEP_READY;
    g_GlobalB->mStepFrames = 0;
}

// Only from EXCHANGE_PICKS up to before VERIFY_RESULT: ORs into mKartRemoveMask every kart in mKartMask that some
// stored mask (own included) does not list.
void CombineKartRemoveMask(void) {
    u8 participantIndex;
    u8 commonMask = 0xff;
    if (g_GlobalB->mStep < WIFI_SESSION_STEP_EXCHANGE_PICKS) {
        return;
    }
    if (g_GlobalB->mStep >= WIFI_SESSION_STEP_VERIFY_RESULT) {
        return;
    }
    for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
        if (BIT_IS_SET(g_GlobalB->mKartMask, participantIndex)) {
            commonMask &= g_GlobalB->mIndexMessages[participantIndex].mKartMask;
        }
    }
    for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
        if (BIT_IS_SET(g_GlobalB->mKartMask, participantIndex)) {
            if ((commonMask & (1 << participantIndex)) == 0) {
                BIT_SET(g_GlobalB->mKartRemoveMask, participantIndex);
            }
        }
    }
}
