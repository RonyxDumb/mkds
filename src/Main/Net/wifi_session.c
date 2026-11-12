#include "Main/Net/wifi_session.h"
#include "Main/Race/cup_records.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "00/code_0219b000.h"
#include "00/Lib/DWC/code_0219b580.h"
#include "00/code_021a2000.h"
#include "00/Lib/DWC/code_021a2ccc.h"
#include "00/code_021a3000.h"
#include "00/Lib/DWC/code_021a3264.h"
#include "code_0214d018.h"
#include "Main/Save/ghost_record.h"
#include "Main/Net/wi_fi_session_step.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
#include "00/Lib/DWC/dwc_match.h"
#include "Main/Race/race_setup.h"
#include "code_02134398.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Net/wifi_session_login.h"
#include "Main/Net/wifi_session_heap.h"
#include "00/Lib/DWC/dwc_connectinet.h"
#include "00/unk_021b5000.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "Main/System/state_machine_init.h"
#include "Main/Net/player_record.h"
#include "00/Lib/DWC/dwc_friend.h"
#include "00/Lib/DWC/code_0219c384.h"
#include "Main/System/heap_call.h"
#include "code_020176c0.h"

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
    ownIndex = DWC_GetMyAID();
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
            DWC_SetRecvBuffer(fromIndex, &gWiFiSession->mReceiveBuffers[fromIndex], 0x44);
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
    gWiFiSession->mIndexMessages[DWC_GetMyAID()].mCharacterIndex = characterIndex;
}

void SetWiFiSessionOwnCharacterIndexNone(void) {
    gWiFiSession->mIndexMessages[DWC_GetMyAID()].mCharacterIndex = -1;
}

void SetWiFiSessionOwnKartIndex(s32 kartIndex) {
    gWiFiSession->mIndexMessages[DWC_GetMyAID()].mKartIndex = kartIndex;
}

void SetWiFiSessionOwnPickedCourseId(s32 pickedCourseId) {
    gWiFiSession->mIndexMessages[DWC_GetMyAID()].mPickedCourseId = pickedCourseId;
}

u32 GetWiFiSessionCharacterIndex(u32 index) {
    return gWiFiSession->mIndexMessages[index].mCharacterIndex;
}

u32 GetWiFiSessionKartIndex(u32 index) {
    return gWiFiSession->mIndexMessages[index].mKartIndex;
}

u32 GetWiFiSessionPickedCourseId(u32 index) {
    return gWiFiSession->mIndexMessages[index].mPickedCourseId;
}

#pragma opt_arithtransformation off

// Own answer on the battle results screen: nonzero is CONTINUE (stored 1), zero is QUIT (stored 2).
void SetWiFiSessionOwnContinueChoice(u32 wantsContinue) {
    gWiFiSession->mIndexMessages[DWC_GetMyAID()].mContinueChoice = wantsContinue != 0 ? 1 : 2;
}

s32 GetWiFiSessionCourseId(void) {
    if (GetRaceSetupCopy()->mCourseId == 0) {
        return gWiFiSession->mIndexMessages[DWC_GetMyAID()].mPickedCourseId;
    }
    return GetRaceSetupCopy()->mCourseId;
}

BOOL IsWiFiStep5ReachedNoDisconnect(void) {
    if (gWiFiSession->mStep >= 5) {
        if (CheckWiFiSessionDisconnect() == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL IsWiFiSessionStep7Reached(void) {
    BOOL result = TRUE;
    WiFiSession *session = gWiFiSession;
    s32 step = session->mStep;

    if (step < 7) {
        if (session->mConnectionLost != 1 || step != 0xc) {
            result = FALSE;
        }
    }
    return result;
}

BOOL IsWiFiSessionStep10Reached(void) {
    BOOL result = TRUE;
    WiFiSession *session = gWiFiSession;
    s32 step = session->mStep;

    if (step < 10) {
        if (session->mConnectionLost != 1 || step != 0xc) {
            result = FALSE;
        }
    }
    return result;
}

// Result of the CONTINUE/QUIT answers: 0 not settled, 1 more than one kart is left, 2 one kart left or the run ended.
s32 GetWiFiSessionContinueResult(void) {
    s32 step;

    step = gWiFiSession->mStep;
    if (step >= 5) {
        if (gWiFiSession->mKartCount > 1) {
            return 1;
        }
        return 2;
    }
    if (gWiFiSession->mConnectionLost == 1) {
        if (step == 0xc) {
            return 2;
        }
    }
    if (step == 0xc) {
        return 2;
    }
    return 0;
}

// Counts the course picks of the indices in mKartMask and stores the most picked in the race setup's mCourseId; ties
// are settled with the object's own LCG (mRandom).
void TallyPickedCourse(void) {
    u8 participantIndex;
    u8 highestCount = 0;
    u8 tiedCount = 0;
    u32 tiedCourses[4] = {0, 0, 0, 0};
    u8 pickCounts[0x37] = {0};
    u8 courseIndex;
    WiFiSession *session;
    RandomState64 *randomState;
    u32 tieIndex;
    u32 talliedCourseId;

    session = gWiFiSession;
    for (participantIndex = 0; participantIndex < session->mStartKartCount; participantIndex++) {
        if (session->mKartMask & (1 << participantIndex)) {
            pickCounts[session->mIndexMessages[participantIndex].mPickedCourseId]++;
            if (highestCount < pickCounts[session->mIndexMessages[participantIndex].mPickedCourseId]) {
                highestCount = pickCounts[session->mIndexMessages[participantIndex].mPickedCourseId];
            }
        }
    }
    for (courseIndex = 0; courseIndex < 0x37; courseIndex++) {
        if (highestCount == pickCounts[courseIndex]) {
            tiedCourses[tiedCount++] = courseIndex;
        }
    }
    randomState = &session->mRandom;
    if (tiedCount == 0) {
        tieIndex = 0;
    } else {
        randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
        if (tiedCount == 0) {
            tieIndex = randomState->mValue >> 32;
        } else {
            tieIndex = ((randomState->mValue >> 32) * (u32) tiedCount) >> 32;
        }
    }
    talliedCourseId = tiedCourses[(u16) tieIndex];
    GetRaceSetupCopy()->mCourseId = talliedCourseId;
}

void WriteWiFiSessionToRaceSetupCopy(void) {
    BOOL ownKind = FALSE;
    u8 participantIndex;

    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        if (gWiFiSession->mKartMask & (1 << participantIndex)) {
            if (participantIndex == DWC_GetMyAID()) {
                s8 entryIndex;

                entryIndex = gWiFiSession->mPackedIndices[participantIndex];
                GetRaceSetupCopy()->mEntries[entryIndex].mPlayerKind = ownKind;
            } else {
                s8 entryIndex;

                entryIndex = gWiFiSession->mPackedIndices[participantIndex];
                GetRaceSetupCopy()->mEntries[entryIndex].mPlayerKind = PLAYER_KIND_PEER;
            }
            {
                WiFiSession *wiFiSession;
                s8 entryIndex;

                wiFiSession = gWiFiSession;
                entryIndex = wiFiSession->mPackedIndices[participantIndex];
                GetRaceSetupCopy()->mEntries[entryIndex].mCharacterIndex =
                    wiFiSession->mIndexMessages[participantIndex].mCharacterIndex;
            }
            {
                WiFiSession *wiFiSession;
                s8 entryIndex;

                wiFiSession = gWiFiSession;
                entryIndex = wiFiSession->mPackedIndices[participantIndex];
                GetRaceSetupCopy()->mEntries[entryIndex].mKartIndex =
                    wiFiSession->mIndexMessages[participantIndex].mKartIndex;
            }
        }
    }
}

BOOL DoesMessageHeaderMatch(WiFiSessionMessageHeader *header, u32 size, u32 fromIndex, u32 toIndex) {
    if (header->mKind < 10) {
        if (header->mSize == size) {
            if (header->mFromIndex == fromIndex) {
                if (header->mToIndex == toIndex) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

BOOL IsWiFiSessionMessageKindAllowed(u32 kind) {
    switch (kind) {
        case 0:
            if (gWiFiSession->mStep == 0 || gWiFiSession->mStep == 1) {
                return TRUE;
            }
            break;
        case 1:
            if (gWiFiSession->mStep == 0) {
                return TRUE;
            }
            break;
        case 2:
            if (gWiFiSession->mStep == 0 || gWiFiSession->mStep == 1) {
                return TRUE;
            }
            break;
        case 8:
            if ((u32) (gWiFiSession->mStep - 3) <= 1) {
                return TRUE;
            }
            break;
        case 9:
            if ((u32) (gWiFiSession->mStep - 3) <= 2) {
                return TRUE;
            }
            break;
        case 3:
            if (gWiFiSession->mStep == 1 || (u32) (gWiFiSession->mStep - 4) <= 2) {
                return TRUE;
            }
            break;
        case 4:
            if ((u32) (gWiFiSession->mStep - 5) <= 1) {
                return TRUE;
            }
            break;
        case 5:
            if ((u32) (gWiFiSession->mStep - 6) <= 1) {
                return TRUE;
            }
            break;
        case 6:
            if ((u32) (gWiFiSession->mStep - 7) <= 1) {
                return TRUE;
            }
            break;
        case 7:
            if ((u32) (gWiFiSession->mStep - 8) <= 1) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

// Index the next message goes to; mStartKartCount means none (the two calls after a pick, or no index left).
u8 PickNextToIndex(void) {
    u8 participantIndex;
    u8 callCount;

    callCount = gWiFiSession->mCallsSincePick;
    if (callCount < 2) {
        gWiFiSession->mCallsSincePick = callCount + 1;
        return gWiFiSession->mStartKartCount;
    }
    for (participantIndex = gWiFiSession->mPickStartIndex; participantIndex < gWiFiSession->mStartKartCount;
         participantIndex++) {
        if (participantIndex != DWC_GetMyAID()) {
            if (gWiFiSession->mKartMask & (1 << participantIndex)) {
                break;
            }
        }
    }
    if (gWiFiSession->mPickStartIndex >= gWiFiSession->mStartKartCount) {
        for (participantIndex = 0; participantIndex < gWiFiSession->mPickStartIndex; participantIndex++) {
            if (participantIndex != DWC_GetMyAID()) {
                if (gWiFiSession->mKartMask & (1 << participantIndex)) {
                    break;
                }
            }
        }
        if (participantIndex >= gWiFiSession->mPickStartIndex) {
            return gWiFiSession->mStartKartCount;
        }
    }
    gWiFiSession->mPickStartIndex = participantIndex + 1;
    gWiFiSession->mCallsSincePick = 0;
    return participantIndex;
}

// TRUE once every other counted index has sent the message of this step; with no other index left it ends the run.
BOOL AreAllStepMessagesReceived(void) {
    u8 participantIndex;
    u8 receivedCount = 0;
    u8 checkedCount = 0;
    u8 startKartCount;
    u8 secondParticipantIndex;
    u8 rosterCount;
    u8 kartMask;

    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        if (participantIndex != DWC_GetMyAID()) {
            if (gWiFiSession->mKartMask & (1 << participantIndex)) {
                checkedCount++;
                if ((gWiFiSession->mReceivedMask & (1 << participantIndex)) == 0) {
                    break;
                }
                receivedCount++;
            }
        }
    }
    if (checkedCount == 0) {
        gWiFiSession->mConnectionLost = 1;
        DWC_RegisterMatchingStatus();
        DWC_CloseAllConnectionsHard();
        gWiFiSession->mStep = 0xb;
        return FALSE;
    }
    rosterCount = 0;
    startKartCount = gWiFiSession->mStartKartCount;
    kartMask = gWiFiSession->mKartMask;
    for (secondParticipantIndex = 0; secondParticipantIndex < startKartCount; secondParticipantIndex++) {
        if (kartMask & (1 << secondParticipantIndex)) {
            rosterCount++;
        }
    }
    return receivedCount == rosterCount - 1;
}

void EndWiFiSessionOnPicksMismatch(u32 index) {
    u8 participantIndex;
    u8 differs = 0;
    u8 ownIndex;

    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        if ((ownIndex = DWC_GetMyAID(), gWiFiSession->mIndexMessages[ownIndex].mKartIndices[participantIndex]) !=
                gWiFiSession->mReceiveBuffers[index].mKartIndices[participantIndex] ||
            (ownIndex = DWC_GetMyAID(), gWiFiSession->mIndexMessages[ownIndex].mCharacterIndices[participantIndex]) !=
                gWiFiSession->mReceiveBuffers[index].mCharacterIndices[participantIndex]) {
            differs = 1;
        }
    }
    ownIndex = DWC_GetMyAID();
    if (gWiFiSession->mReceiveBuffers[index].mTalliedCourseId !=
        gWiFiSession->mIndexMessages[ownIndex].mTalliedCourseId) {
        differs = 1;
    }
    if (differs == 0) {
        return;
    }
    gWiFiSession->mConnectionLost = 1;
    DWC_RegisterMatchingStatus();
    DWC_CloseAllConnectionsHard();
    gWiFiSession->mStep = 0xb;
}

BOOL IsWiFiMatchingBeforeTimeLimit(void) {
    return DWC_GetMOMinCompState(NULL) == 0;
}

u8 GetWiFiMatchingParticipantCount(void) {
    return DWC_GetNumConnectionHost();
}

BOOL HasWiFiBuddyStatus4(void) {
    return gWiFiSession->mStatus4BuddyCount != 0;
}

u32 StopWiFiSessionMatching(void) {
    return DWC_CancelMatching();
}

BOOL IsWiFiSessionMatchingActive(void) {
    if (DWC_IsValidCancelMatching() != 0) {
        if (gWiFiSession->mStateMachine.mState == 3) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL IsKartKeysStartStatus2(void) {
    return gWiFiSession->mStartStatus == 2;
}

void RequestWiFiSessionMatching(u32 kartType, s32 useTimeLimit, s32 unused) {
    StateMachine *stateMachine;

    DWC_CloseAllConnectionsHard();
    MI_CpuFill8(&gWiFiSession->mKeys[0], 0, 0x18);
    MI_CpuFill8(&gWiFiSession->mKeys[1], 0, 0x18);
    MI_CpuFill8(&gWiFiSession->mKeys[2], 0, 0x18);
    MI_CpuFill8(&gWiFiSession->mKeys[3], 0, 0x18);
    gWiFiSession->mEarlyStepTimedOut = 0;
    gWiFiSession->mNumEntry = 0;
    gWiFiSession->mStatus4BuddyCount = 0;
    gWiFiSession->mKartCount = 0;
    gWiFiSession->mStartKartCount = 0;
    gWiFiSession->mKartCountCopy = 0;
    gWiFiSession->mKartMask = 0;
    gWiFiSession->mKartRemoveMask = 0;
    MI_CpuFill8(&gWiFiSession->mStep, 0, 0x60);
    gWiFiSession->mKeys[1].mValue = kartType;
    gWiFiSession->mNumEntry = 4;
    if (useTimeLimit == 0) {
        gWiFiSession->mMinCompleteOption.mValid = 1;
        gWiFiSession->mMinCompleteOption.mMinEntry = 2;
        gWiFiSession->mMinCompleteOption.mTimeLimit = 1;
    } else {
        gWiFiSession->mMinCompleteOption.mValid = 1;
        gWiFiSession->mMinCompleteOption.mMinEntry = 2;
        gWiFiSession->mMinCompleteOption.mTimeLimit = 0xea60;
    }
    DWC_SetMatchingOption(0, &gWiFiSession->mMinCompleteOption, 0);
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = 3;
    stateMachine->mNextStateRequested = 1;
}

s32 CheckWiFiMatchingResult(void) {
    if ((gWiFiSession->mEarlyStepTimedOut != 0 && DWC_GetNumConnectionHost() <= 1) || gWiFiSession->mErrorKind == 7) {
        return -1;
    }
    return IsWiFiStep5ReachedNoDisconnect() != FALSE;
}

void RegisterKartKeysAndStart(void) {
    s32 eloHigh;
    s32 eloLow;

    ClearWiFiDisconnectStatus();
    MI_CpuFill8(gWiFiSession->mPlayerRecords, 0, 0x910);
    FillPlayerRecord(&gWiFiSession->mPlayerRecords[0].mPlayer);
    gWiFiSession->mKeys[0].mValue = gWiFiSession->mPlayerRecords[0].mPlayer.mRegion;
    gWiFiSession->mKeys[3].mValue = gWiFiSession->mPlayerRecords[0].mPlayer.mElo;
    __memcpy(gWiFiSession->mKeys[2].mName, "kart_filter", 12);
    gWiFiSession->mKeys[2].mId =
        DWC_AddMatchKeyString(gWiFiSession->mKeys[2].mId, gWiFiSession->mKeys[2].mName, "ds_mario_kart_product");
    __memcpy(gWiFiSession->mKeys[1].mName, "kart_type", 10);
    gWiFiSession->mKeys[1].mId =
        DWC_AddMatchKeyInt(gWiFiSession->mKeys[1].mId, gWiFiSession->mKeys[1].mName, &gWiFiSession->mKeys[1]);
    __memcpy(gWiFiSession->mKeys[3].mName, "kart_elo", 9);
    gWiFiSession->mKeys[3].mId =
        DWC_AddMatchKeyInt(gWiFiSession->mKeys[3].mId, gWiFiSession->mKeys[3].mName, &gWiFiSession->mKeys[3]);
    __memcpy(gWiFiSession->mKeys[0].mName, "kart_region", 12);
    gWiFiSession->mKeys[0].mId =
        DWC_AddMatchKeyInt(gWiFiSession->mKeys[0].mId, gWiFiSession->mKeys[0].mName, &gWiFiSession->mKeys[0]);
    eloLow = gWiFiSession->mPlayerRecords[0].mPlayer.mElo - 0x3e8;
    if (eloLow <= 0) {
        eloLow = 0;
    }
    eloHigh = gWiFiSession->mPlayerRecords[0].mPlayer.mElo + 0x3e8;
    if (eloHigh > 0x2710) {
        eloHigh = 0x2710;
    }
    MI_CpuFill8(gKartFilterString, 0, 0x64);
    if (gWiFiSession->mKeys[1].mValue == 1) {
        sprintf(gKartFilterString, "%s = '%s' and %s > %d and %s < %d", "kart_filter", "ds_mario_kart_product",
                "kart_elo", eloLow, "kart_elo", eloHigh);
    } else {
        sprintf(gKartFilterString, "%s = '%s'", "kart_filter", "ds_mario_kart_product");
    }
    switch (gWiFiSession->mKeys[1].mValue) {
        case 3:
            DWC_ConnectToAnybodyAsync(gWiFiSession->mNumEntry, gKartFilterString, KartKeysStartCallback, NULL,
                                      ComputeRegionEval, 0);
            break;
        case 4:
            DWC_ConnectToAnybodyAsync(gWiFiSession->mNumEntry, gKartFilterString, KartKeysStartCallback, NULL,
                                      ComputeRegionEloEval, 0);
            break;
        case 0:
            DWC_ConnectToFriendsAsync(NULL, 0, gWiFiSession->mNumEntry, 1, KartKeysStartCallback, NULL, 0, 0);
            break;
        case 1:
            DWC_ConnectToAnybodyAsync(gWiFiSession->mNumEntry, gKartFilterString, KartKeysStartCallback, NULL,
                                      ComputeEloEval, 0);
            break;
    }
    gWiFiSession->mStartStatus = 1;
}

BOOL IsKartKeysStartStatus3(void) {
    s32 status;

    status = gWiFiSession->mStartStatus;
    switch (status) {
        case 1:
            break;
        case 3:
            return TRUE;
        case 4:
            break;
    }
    return FALSE;
}

s32 ComputeEloEval(u32 serverIndex) {
    s32 kartType;
    s32 kartRegion;
    s32 value;
    WiFiSession *session;

    kartType = DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[1].mName, 5);
    kartRegion = DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[0].mName, 3);
    value = DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[3].mName, -1);
    if (kartType == 5 || kartRegion == 3 || value < 0) {
        return 0;
    }
    session = gWiFiSession;
    if (session->mPlayerRecords[0].mPlayer.mElo > value) {
        value = session->mPlayerRecords[0].mPlayer.mElo - value;
    } else {
        value = value - session->mPlayerRecords[0].mPlayer.mElo;
    }
    if (value < 0x3e8) {
        if (kartType == 1) {
            return 0x7d0 - value;
        }
        if (kartType == 4) {
            return 0x3e8 - value;
        }
    }
    return 0;
}

BOOL ComputeRegionEval(u32 serverIndex) {
    s32 kartType;
    s32 kartRegion;

    kartType = DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[1].mName, 5);
    kartRegion = DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[0].mName, 3);
    if (kartType == 5 || kartRegion == 3) {
        return FALSE;
    }
    if (kartType == 3) {
        if (gWiFiSession->mPlayerRecords[0].mPlayer.mRegion == kartRegion) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 ComputeRegionEloEval(u32 serverIndex) {
    s32 kartType;
    s32 kartRegion;
    s32 value;
    WiFiSession *session;

    kartType = DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[1].mName, 5);
    kartRegion = DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[0].mName, 3);
    value = DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[3].mName, -1);
    if (kartType == 5 || kartRegion == 3 || value < 0) {
        return 0;
    }
    if (kartType == 4) {
        return (kartRegion != gWiFiSession->mPlayerRecords[0].mPlayer.mRegion ? 2 : 1) * 0x7d0;
    }
    if (kartType == 1) {
        session = gWiFiSession;
        if (session->mPlayerRecords[0].mPlayer.mElo > value) {
            value = session->mPlayerRecords[0].mPlayer.mElo - value;
        } else {
            value = value - session->mPlayerRecords[0].mPlayer.mElo;
        }
        if (value < 0x3e8) {
            if (kartRegion != session->mPlayerRecords[0].mPlayer.mRegion) {
                return 0x7d0 - value;
            }
            return 0x3e8 - value;
        }
    }
    return 0;
}

void KartKeysStartCallback(u32 result, s32 flag) {
    WiFiSession *session;
    u8 participantIndex;

    if (result == 0) {
        if (flag != 0) {
            gWiFiSession->mStartStatus = 2;
            return;
        }
        gWiFiSession->mKartMask = 0;
        gWiFiSession->mKartCount = DWC_GetNumConnectionHost();
        gWiFiSession->mStartKartCount = gWiFiSession->mKartCount;
        session = gWiFiSession;
        participantIndex = 0;
        while (participantIndex < session->mStartKartCount) {
            session->mKartMask |= 1 << participantIndex;
            session = gWiFiSession;
            participantIndex++;
        }
        MI_CpuFill8(session->mPlayerRecords, 0, 0x910);
        FillPlayerRecord(&gWiFiSession->mPlayerRecords[DWC_GetMyAID()].mPlayer);
        SetupWiFiSession(0);
        gWiFiSession->mStartStatus = 3;
    } else {
        gWiFiSession->mStartStatus = 4;
    }
}

void SetWiFiDisconnectKind(s32 kind) {
    gWiFiSession->mDisconnectKind = kind;
    if (gWiFiSession->mDisconnectKind != 2) {
        return;
    }
    DWC_RegisterMatchingStatus();
    DWC_CloseAllConnectionsHard();
}

void ResetWiFiSession(void) {
    MI_CpuFill8(gWiFiSession->mRecvBuffers, 0, 0x200);
    MI_CpuFill8(gWiFiSession->mPlayerRecords, 0, 0x910);
    MI_CpuFill8(gWiFiSession->mConnection, 0, 0xe24);
    MI_CpuFill8(&gWiFiSession->mStep, 0, 0x60);
    MI_CpuFill8(&gWiFiSession->mUserData, 0, 0x350);
    MI_CpuFill8(gWiFiSession->mReceiveBuffers, 0, 0x110);
    MI_CpuFill8(gWiFiSession->mIndexMessages, 0, 0x110);
    MI_CpuFill8(&gWiFiSession->mLogin, 0, 0x10);
    gWiFiSession->mUnk_1f34 = FALSE;
    gWiFiSession->mRaceSyncEnabled = FALSE;
    gWiFiSession->mIrqCallbackCount = 0;
    gWiFiSession->mDisconnectKind = 0;
    gWiFiSession->mErrorKind = 0;
    gWiFiSession->mErrorCode = 0;
    gWiFiSession->mUnk_1f4c = 0;
    gWiFiSession->mUnk_1f4d = 0;
    MI_CpuFill8(gWiFiSession->mPackedIndices, 0, 4);
    gWiFiSession->mKartCount = 0;
    gWiFiSession->mStartKartCount = 0;
    gWiFiSession->mKartCountCopy = 0;
    gWiFiSession->mKartMask = 0;
    gWiFiSession->mKartRemoveMask = 0;
    gWiFiSession->mBuddyPollIndex = 0;
}

// 0 none, 1 no input for 30 seconds, 2 the opponent left, 3 error; for 1 and 2 it also requests state 2.
u32 CheckWiFiSessionDisconnect(void) {
    WiFiSession *session;
    StateMachine *stateMachine;
    s32 errorKind;

    session = gWiFiSession;
    if (session->mStateMachine.mState != 0) {
        errorKind = session->mErrorKind;
        if (errorKind == 6 || errorKind == 3 || errorKind == 4 || errorKind == 0xb) {
            return 3;
        }
        if (session->mDisconnectKind == 2) {
            if (DWC_GetNumConnectionHost() <= 1) {
                stateMachine = &gWiFiSession->mStateMachine;
                stateMachine->mNextState = 2;
                stateMachine->mNextStateRequested = 1;
                return 2;
            }
        } else if (session->mDisconnectKind == 1) {
            stateMachine = &session->mStateMachine;
            stateMachine->mNextState = 2;
            stateMachine->mNextStateRequested = 1;
            return 1;
        }
    }
    return 0;
}

void ClearWiFiDisconnectStatus(void) {
    gWiFiSession->mErrorKind = 0;
    gWiFiSession->mDisconnectKind = 0;
    gWiFiSession->mErrorCode = 0;
}

u32 GetWiFiSessionErrorCodeNegated(void) {
    return ((0x0u) - ((gWiFiSession->mErrorCode)));
}

StateCallbacks gWiFiSessionStateTable[7] = {
    {0, 0},
    {EnterWiFiSessionState1, UpdateWiFiSessionState1},
    {0, 0},
    {EnterWiFiSessionState3, UpdateWiFiSessionState3},
    {EnterWiFiSessionState4Nop, UpdateWiFiSessionState4},
    {EnterWiFiSessionState5, UpdateWiFiSessionState5},
    {0, UpdateWiFiSessionState6Nop},
};

u32 GetWiFiLinkLevel(void) {
    return DWC_GetLinkLevel();
}

#pragma thumb on
void InitWiFiSession(void *heap) {
    StateMachine *stateMachine;

    gWiFiSession = HeapAllocAligned(heap, 0x1f58, 0x20);
    InitStateMachine(&gWiFiSession->mStateMachine, gWiFiSessionStateTable, 8, NULL);
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
}

// Creates the 0x3e800-byte exp heap and registers WiFiSessionHeapAlloc / Free with the net layer (the heap is used only
// through them).
void CreateWiFiSessionHeap(void *heap) {
    gWiFiSession->mHeapBuffer = HeapAllocAligned(heap, 0x3e800, 0x20);
    gWiFiSession->mHeap = NNS_FndCreateExpHeapEx(gWiFiSession->mHeapBuffer, 0x3e800, 1);
    gWiFiSession->mHeapCreated = TRUE;
    DWC_SetMemFunc(WiFiSessionHeapAlloc, WiFiSessionHeapFree);
}

// Destroys the heap and frees its buffer (mHeap is left set), clears mHeapCreated and requests state 0.
void DeleteWiFiSessionHeap(void) {
    StateMachine *stateMachine;

    if (gWiFiSession->mHeap != NULL) {
        NNS_FndDestroyExpHeap(gWiFiSession->mHeap);
        HeapFree(GetHeap(GetCurrentHeapCall()), gWiFiSession->mHeapBuffer);
    }
    gWiFiSession->mHeapCreated = FALSE;
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
}
#pragma thumb off

void ResetWiFiSessionToOff(void) {
    StateMachine *stateMachine;

    ResetWiFiSession();
    gWiFiSession->mUnk_1f34 = TRUE;
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = 0;
    stateMachine->mNextStateRequested = 1;
}

// Polls one buddy entry's status per call and counts the entries with status 4 into mStatus4BuddyCount.
void UpdateBuddyStatuses(void) {
    u8 status4Count = 0;
    WiFiSession *session;
    WiFiSession *countSession;
    u8 buddyIndex;

    if (gWiFiSession->mBuddyPollIndex >= 0x3c) {
        gWiFiSession->mBuddyPollIndex = 0;
    }
    session = gWiFiSession;
    session->mBuddyStatuses[session->mBuddyPollIndex] =
        DWC_GetFriendStatus(&session->mBuddies[session->mBuddyPollIndex], NULL);
    gWiFiSession->mBuddyPollIndex++;
    countSession = gWiFiSession;
    buddyIndex = 0;
    do {
        switch (countSession->mBuddyStatuses[buddyIndex]) {
            case 2:
                break;
            case 4:
                status4Count++;
                break;
        }
        buddyIndex++;
    } while (buddyIndex < 0x3c);
    countSession->mStatus4BuddyCount = status4Count;
}

void UpdateWiFiSession(void) {
    if (gWiFiSession == NULL) {
        return;
    }
    if (gOverlayLoader->mCurrentOverlay != 0) {
        return;
    }
    DWC_ProcessFriendsMatch();
    if (DWC_GetLastError(NULL) != 0) {
        gWiFiSession->mErrorKind = DWC_GetLastError(&gWiFiSession->mErrorCode);
        DWC_ClearError();
    }
    if (gWiFiSession->mStateMachine.mState != 0) {
        UpdateBuddyStatuses();
    }
    AdvanceStateMachine(&gWiFiSession->mStateMachine);
}

s32 SendWiFiPacketToParticipant(u32 participantIndex, void *packet, s32 size, u32 (*finishCallback)(void)) {
    return DWC_SendUnreliable(participantIndex, packet, size);
}

// Returns the name+emblem part of the index's record, or NULL if the index is not in mKartMask.
PlayerRecord *GetWiFiSessionPlayerRecordData(u32 index) {
    WiFiSession *session = gWiFiSession;

    if (session->mKartMask & (1 << index)) {
        return &session->mPlayerRecords[index].mPlayer;
    }
    return NULL;
}
