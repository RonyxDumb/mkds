#include "Main/Net/wifi_session.h"
#include "Main/Race/cup_records.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "00/Lib/DWC/code_0219b1f8.h"
#include "00/Lib/DWC/code_021a2ccc.h"
#include "00/Lib/DWC/code_021a3264.h"
#include "code_0214d018.h"
#include "Main/Save/ghost_record.h"
#include "Main/Net/wi_fi_session_step.h"
#include "Main/Menu/menu_screens_work.h"
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
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "Main/System/state_machine_init.h"
#include "Main/Net/player_record.h"
#include "00/Lib/DWC/dwc_friend.h"
#include "00/Lib/DWC/code_0219c384.h"
#include "Main/System/heap_call.h"
#include "code_020176c0.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/backup_net_camera_work.h"

#pragma opt_arithtransformation off

StateCallbacks gWiFiSessionStateTable[7] = {
    {0, 0},
    {EnterWiFiSessionLogin, UpdateWiFiSessionLoginState},
    {0, 0},
    {EnterWiFiSessionSearch, UpdateWiFiSessionSearch},
    {EnterWiFiSessionExchangeNop, UpdateWiFiSessionExchange},
    {EnterWiFiSessionRace, UpdateWiFiSessionRace},
    {0, UpdateWiFiSessionUnusedNop},
};
WiFiSession *gWiFiSession;
char gKartFilterString[0x64];

void PackWiFiSessionIndicesWrapper(void) {
    PackWiFiSessionIndices();
}

// Gives each index in mKartMask the next running number in mPackedIndices (others -1) and tells CopyKartCupRecords the
// old and new number.
void PackWiFiSessionIndices(void) {
    u8 kartIndex;
    s8 nextNumber = 0;
    u8 oldNumber;
    for (kartIndex = 0; kartIndex < WIFI_SESSION_KART_SLOTS; kartIndex++) {
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
        if (step == WIFI_SESSION_STEP_EXCHANGE_RECORDS || step == WIFI_SESSION_STEP_EXCHANGE_SEEDS ||
            step == WIFI_SESSION_STEP_WAIT_BACKUP) {
            gWiFiSession->mEarlyStepTimedOut = TRUE;
            DWC_RegisterMatchingStatus();
            DWC_CloseAllConnectionsHard();
            gWiFiSession->mStep = WIFI_SESSION_STEP_LEAVING;
        } else {
            if (step == WIFI_SESSION_STEP_VERIFY_RESULT || step == WIFI_SESSION_STEP_READY) {
                return TRUE;
            }
            gWiFiSession->mConnectionLost = TRUE;
            DWC_RegisterMatchingStatus();
            DWC_CloseAllConnectionsHard();
            gWiFiSession->mStep = WIFI_SESSION_STEP_LEAVING;
        }
        return TRUE;
    }
    return FALSE;
}

static inline BOOL IsWiFiSessionMessageMatching(const WiFiSessionMessage *message, u32 fromIndex, u32 size,
                                                u8 toIndex) {
    if (message->mKind < WIFI_SESSION_MESSAGE_KIND_COUNT) {
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
    if (gWiFiSession->mStep >= WIFI_SESSION_STEP_EXCHANGE_PICKS && (gWiFiSession->mKartMask & (1 << fromIndex)) == 0) {
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
        case WIFI_SESSION_MESSAGE_RECORD_REQUEST:
            BIT_SET(gWiFiSession->mSendRecordMask, fromIndex);
            break;
        case WIFI_SESSION_MESSAGE_RECORD:
            BIT_SET(gWiFiSession->mReceivedMask, fromIndex);
            DWC_SetRecvBuffer(fromIndex, &gWiFiSession->mReceiveBuffers[fromIndex], sizeof(WiFiSessionMessage));
            break;
        case WIFI_SESSION_MESSAGE_RECORDS_SENT:
            if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_SEEDS) {
                BIT_SET(gWiFiSession->mReceivedMask, fromIndex);
            }
            break;
        case WIFI_SESSION_MESSAGE_CONTINUE_CHOICE:
            if (gWiFiSession->mStep != WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) {
                return;
            }
            if (message->mContinueChoice == WIFI_CONTINUE_CHOICE_NONE) {
                return;
            }
            MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                        sizeof(WiFiSessionMessage));
            BIT_SET(gWiFiSession->mReceivedMask, fromIndex);
            break;
        case WIFI_SESSION_MESSAGE_CONTINUE_CONFIRM:
            if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(gWiFiSession->mReceivedMask, fromIndex);
            } else if (gWiFiSession->mStep == WIFI_SESSION_STEP_CONFIRM_CONTINUE) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(gWiFiSession->mReceivedMask, fromIndex);
            }
            break;
        case WIFI_SESSION_MESSAGE_PICKS:
            if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_SEEDS) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                gWiFiSession->mReceivedMask = WIFI_SESSION_ALL_RECEIVED;
            } else if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_PICKS) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                if (message->mCharacterIndex == -1) {
                    return;
                }
                if (message->mKartIndex == -1) {
                    return;
                }
                BIT_SET(gWiFiSession->mReceivedMask, fromIndex);
            } else if (gWiFiSession->mStep == WIFI_SESSION_STEP_CONFIRM_CONTINUE) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                gWiFiSession->mReceivedMask = WIFI_SESSION_ALL_RECEIVED;
            }
            break;
        case WIFI_SESSION_MESSAGE_PICK_MASK:
            if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_PICKS) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(gWiFiSession->mReceivedMask, fromIndex);
            } else if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(gWiFiSession->mReceivedMask, fromIndex);
            }
            break;
        case WIFI_SESSION_MESSAGE_COURSE_PICK:
            if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                gWiFiSession->mReceivedMask = WIFI_SESSION_ALL_RECEIVED;
            } else if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS) {
                if (message->mPickedCourseId == 0) {
                    return;
                }
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(gWiFiSession->mReceivedMask, fromIndex);
            }
            break;
        case WIFI_SESSION_MESSAGE_COURSE_MASK:
            if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(gWiFiSession->mReceivedMask, fromIndex);
            } else if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(gWiFiSession->mReceivedMask, fromIndex);
            }
            break;
        case WIFI_SESSION_MESSAGE_RESULT:
            if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(gWiFiSession->mReceivedMask, fromIndex);
            } else if (gWiFiSession->mStep == WIFI_SESSION_STEP_VERIFY_RESULT) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[fromIndex], &gWiFiSession->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                EndWiFiSessionOnPicksMismatch(fromIndex);
                BIT_SET(gWiFiSession->mReceivedMask, fromIndex);
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

u32 GetWiFiSessionCharacterIndex(u8 index) {
    return gWiFiSession->mIndexMessages[index].mCharacterIndex;
}

u32 GetWiFiSessionKartIndex(u8 index) {
    return gWiFiSession->mIndexMessages[index].mKartIndex;
}

u32 GetWiFiSessionPickedCourseId(u8 index) {
    return gWiFiSession->mIndexMessages[index].mPickedCourseId;
}

#pragma opt_arithtransformation off

// Own answer on the battle results screen: nonzero is CONTINUE (stored 1), zero is QUIT (stored 2).
void SetWiFiSessionOwnContinueChoice(u32 wantsContinue) {
    gWiFiSession->mIndexMessages[DWC_GetMyAID()].mContinueChoice =
        wantsContinue != 0 ? WIFI_CONTINUE_CHOICE_CONTINUE : WIFI_CONTINUE_CHOICE_QUIT;
}

s32 GetWiFiSessionCourseId(void) {
    if (GetRaceSetupCopy()->mCourseId == 0) {
        return gWiFiSession->mIndexMessages[DWC_GetMyAID()].mPickedCourseId;
    }
    return GetRaceSetupCopy()->mCourseId;
}

BOOL IsWiFiStep5ReachedNoDisconnect(void) {
    if (gWiFiSession->mStep >= WIFI_SESSION_STEP_EXCHANGE_PICKS) {
        if (CheckWiFiSessionDisconnect() == WIFI_DISCONNECT_NONE) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL IsWiFiSessionStep7Reached(void) {
    BOOL result = TRUE;
    WiFiSession *session = gWiFiSession;
    s32 step = session->mStep;

    if (step < WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS) {
        if (session->mConnectionLost != TRUE || step != WIFI_SESSION_STEP_ENDED) {
            result = FALSE;
        }
    }
    return result;
}

BOOL IsWiFiSessionStep10Reached(void) {
    BOOL result = TRUE;
    WiFiSession *session = gWiFiSession;
    s32 step = session->mStep;

    if (step < WIFI_SESSION_STEP_READY) {
        if (session->mConnectionLost != TRUE || step != WIFI_SESSION_STEP_ENDED) {
            result = FALSE;
        }
    }
    return result;
}

// Result of the CONTINUE/QUIT answers: 0 not settled, 1 more than one kart is left, 2 one kart left or the run ended.
s32 GetWiFiSessionContinueResult(void) {
    s32 step;

    step = gWiFiSession->mStep;
    if (step >= WIFI_SESSION_STEP_EXCHANGE_PICKS) {
        if (gWiFiSession->mKartCount > 1) {
            return WIFI_CONTINUE_RESULT_KARTS_LEFT;
        }
        return WIFI_CONTINUE_RESULT_ENDED;
    }
    if (gWiFiSession->mConnectionLost == TRUE) {
        if (step == WIFI_SESSION_STEP_ENDED) {
            return WIFI_CONTINUE_RESULT_ENDED;
        }
    }
    if (step == WIFI_SESSION_STEP_ENDED) {
        return WIFI_CONTINUE_RESULT_ENDED;
    }
    return WIFI_CONTINUE_RESULT_NOT_SETTLED;
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
    if (header->mKind < WIFI_SESSION_MESSAGE_KIND_COUNT) {
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
        case WIFI_SESSION_MESSAGE_RECORD_REQUEST:
            if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_RECORDS ||
                gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_SEEDS) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_RECORD:
            if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_RECORDS) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_RECORDS_SENT:
            if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_RECORDS ||
                gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_SEEDS) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_CONTINUE_CHOICE:
            if ((u32) (gWiFiSession->mStep - WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) <=
                WIFI_SESSION_STEP_CONFIRM_CONTINUE - WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_CONTINUE_CONFIRM:
            if ((u32) (gWiFiSession->mStep - WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) <=
                WIFI_SESSION_STEP_EXCHANGE_PICKS - WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_PICKS:
            if (gWiFiSession->mStep == WIFI_SESSION_STEP_EXCHANGE_SEEDS ||
                (u32) (gWiFiSession->mStep - WIFI_SESSION_STEP_CONFIRM_CONTINUE) <=
                    WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS - WIFI_SESSION_STEP_CONFIRM_CONTINUE) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_PICK_MASK:
            if ((u32) (gWiFiSession->mStep - WIFI_SESSION_STEP_EXCHANGE_PICKS) <=
                WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS - WIFI_SESSION_STEP_EXCHANGE_PICKS) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_COURSE_PICK:
            if ((u32) (gWiFiSession->mStep - WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS) <=
                WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS - WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_COURSE_MASK:
            if ((u32) (gWiFiSession->mStep - WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS) <=
                WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS - WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_RESULT:
            if ((u32) (gWiFiSession->mStep - WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS) <=
                WIFI_SESSION_STEP_VERIFY_RESULT - WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS) {
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
    if (callCount < WIFI_SESSION_CALLS_AFTER_PICK) {
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
        gWiFiSession->mConnectionLost = TRUE;
        DWC_RegisterMatchingStatus();
        DWC_CloseAllConnectionsHard();
        gWiFiSession->mStep = WIFI_SESSION_STEP_LEAVING;
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
    u8 differs = FALSE;
    u8 ownIndex;

    for (participantIndex = 0; participantIndex < gWiFiSession->mStartKartCount; participantIndex++) {
        if ((ownIndex = DWC_GetMyAID(), gWiFiSession->mIndexMessages[ownIndex].mKartIndices[participantIndex]) !=
                gWiFiSession->mReceiveBuffers[index].mKartIndices[participantIndex] ||
            (ownIndex = DWC_GetMyAID(), gWiFiSession->mIndexMessages[ownIndex].mCharacterIndices[participantIndex]) !=
                gWiFiSession->mReceiveBuffers[index].mCharacterIndices[participantIndex]) {
            differs = TRUE;
        }
    }
    ownIndex = DWC_GetMyAID();
    if (gWiFiSession->mReceiveBuffers[index].mTalliedCourseId !=
        gWiFiSession->mIndexMessages[ownIndex].mTalliedCourseId) {
        differs = TRUE;
    }
    if (differs == FALSE) {
        return;
    }
    gWiFiSession->mConnectionLost = TRUE;
    DWC_RegisterMatchingStatus();
    DWC_CloseAllConnectionsHard();
    gWiFiSession->mStep = WIFI_SESSION_STEP_LEAVING;
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
        if (gWiFiSession->mStateMachine.mState == WIFI_SESSION_STATE_SEARCH) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL IsKartKeysStartStatus2(void) {
    return gWiFiSession->mStartStatus == WIFI_START_STATUS_CANCELED;
}

void RequestWiFiSessionMatching(u32 kartType, s32 useTimeLimit, s32 unused) {
    StateMachine *stateMachine;

    DWC_CloseAllConnectionsHard();
    MI_CpuFill8(&gWiFiSession->mKeys[WIFI_MATCH_KEY_REGION], 0, sizeof(KartKey));
    MI_CpuFill8(&gWiFiSession->mKeys[WIFI_MATCH_KEY_TYPE], 0, sizeof(KartKey));
    MI_CpuFill8(&gWiFiSession->mKeys[WIFI_MATCH_KEY_FILTER], 0, sizeof(KartKey));
    MI_CpuFill8(&gWiFiSession->mKeys[WIFI_MATCH_KEY_ELO], 0, sizeof(KartKey));
    gWiFiSession->mEarlyStepTimedOut = FALSE;
    gWiFiSession->mNumEntry = 0;
    gWiFiSession->mStatus4BuddyCount = 0;
    gWiFiSession->mKartCount = 0;
    gWiFiSession->mStartKartCount = 0;
    gWiFiSession->mKartCountCopy = 0;
    gWiFiSession->mKartMask = 0;
    gWiFiSession->mKartRemoveMask = 0;
    MI_CpuFill8(&gWiFiSession->mStep, 0, 0x60);
    gWiFiSession->mKeys[WIFI_MATCH_KEY_TYPE].mValue = kartType;
    gWiFiSession->mNumEntry = WIFI_SESSION_KART_SLOTS;
    if (useTimeLimit == 0) {
        gWiFiSession->mMinCompleteOption.mValid = TRUE;
        gWiFiSession->mMinCompleteOption.mMinEntry = WIFI_MATCH_MIN_ENTRIES;
        gWiFiSession->mMinCompleteOption.mTimeLimit = WIFI_MATCH_NO_WAIT;
    } else {
        gWiFiSession->mMinCompleteOption.mValid = TRUE;
        gWiFiSession->mMinCompleteOption.mMinEntry = WIFI_MATCH_MIN_ENTRIES;
        gWiFiSession->mMinCompleteOption.mTimeLimit = WIFI_MATCH_WAIT_LIMIT;
    }
    DWC_SetMatchingOption(0, &gWiFiSession->mMinCompleteOption, 0);
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_SEARCH;
    stateMachine->mNextStateRequested = 1;
}

s32 CheckWiFiMatchingResult(void) {
    if ((gWiFiSession->mEarlyStepTimedOut != 0 && DWC_GetNumConnectionHost() <= 1) ||
        gWiFiSession->mErrorKind == WIFI_ERROR_KIND_UNRECOVERABLE) {
        return -1;
    }
    return IsWiFiStep5ReachedNoDisconnect() != FALSE;
}

void RegisterKartKeysAndStart(void) {
    s32 eloHigh;
    s32 eloLow;

    ClearWiFiDisconnectStatus();
    MI_CpuFill8(gWiFiSession->mPlayerRecords, 0, sizeof(gWiFiSession->mPlayerRecords));
    FillPlayerRecord(&gWiFiSession->mPlayerRecords[0].mPlayer);
    gWiFiSession->mKeys[WIFI_MATCH_KEY_REGION].mValue = gWiFiSession->mPlayerRecords[0].mPlayer.mRegion;
    gWiFiSession->mKeys[WIFI_MATCH_KEY_ELO].mValue = gWiFiSession->mPlayerRecords[0].mPlayer.mElo;
    __memcpy(gWiFiSession->mKeys[WIFI_MATCH_KEY_FILTER].mName, "kart_filter", 12);
    gWiFiSession->mKeys[WIFI_MATCH_KEY_FILTER].mId =
        DWC_AddMatchKeyString(gWiFiSession->mKeys[WIFI_MATCH_KEY_FILTER].mId,
                              gWiFiSession->mKeys[WIFI_MATCH_KEY_FILTER].mName, "ds_mario_kart_product");
    __memcpy(gWiFiSession->mKeys[WIFI_MATCH_KEY_TYPE].mName, "kart_type", 10);
    gWiFiSession->mKeys[WIFI_MATCH_KEY_TYPE].mId =
        DWC_AddMatchKeyInt(gWiFiSession->mKeys[WIFI_MATCH_KEY_TYPE].mId, gWiFiSession->mKeys[WIFI_MATCH_KEY_TYPE].mName,
                           &gWiFiSession->mKeys[WIFI_MATCH_KEY_TYPE]);
    __memcpy(gWiFiSession->mKeys[WIFI_MATCH_KEY_ELO].mName, "kart_elo", 9);
    gWiFiSession->mKeys[WIFI_MATCH_KEY_ELO].mId =
        DWC_AddMatchKeyInt(gWiFiSession->mKeys[WIFI_MATCH_KEY_ELO].mId, gWiFiSession->mKeys[WIFI_MATCH_KEY_ELO].mName,
                           &gWiFiSession->mKeys[WIFI_MATCH_KEY_ELO]);
    __memcpy(gWiFiSession->mKeys[WIFI_MATCH_KEY_REGION].mName, "kart_region", 12);
    gWiFiSession->mKeys[WIFI_MATCH_KEY_REGION].mId = DWC_AddMatchKeyInt(
        gWiFiSession->mKeys[WIFI_MATCH_KEY_REGION].mId, gWiFiSession->mKeys[WIFI_MATCH_KEY_REGION].mName,
        &gWiFiSession->mKeys[WIFI_MATCH_KEY_REGION]);
    eloLow = gWiFiSession->mPlayerRecords[0].mPlayer.mElo - WIFI_ELO_WINDOW;
    if (eloLow <= 0) {
        eloLow = 0;
    }
    eloHigh = gWiFiSession->mPlayerRecords[0].mPlayer.mElo + WIFI_ELO_WINDOW;
    if (eloHigh > WIFI_ELO_MAX) {
        eloHigh = WIFI_ELO_MAX;
    }
    MI_CpuFill8(gKartFilterString, 0, sizeof(gKartFilterString));
    if (gWiFiSession->mKeys[WIFI_MATCH_KEY_TYPE].mValue == WIFI_MATCH_TYPE_ELO) {
        sprintf(gKartFilterString, "%s = '%s' and %s > %d and %s < %d", "kart_filter", "ds_mario_kart_product",
                "kart_elo", eloLow, "kart_elo", eloHigh);
    } else {
        sprintf(gKartFilterString, "%s = '%s'", "kart_filter", "ds_mario_kart_product");
    }
    switch (gWiFiSession->mKeys[WIFI_MATCH_KEY_TYPE].mValue) {
        case WIFI_MATCH_TYPE_REGION:
            DWC_ConnectToAnybodyAsync(gWiFiSession->mNumEntry, gKartFilterString, KartKeysStartCallback, NULL,
                                      ComputeRegionEval, 0);
            break;
        case WIFI_MATCH_TYPE_REGION_ELO:
            DWC_ConnectToAnybodyAsync(gWiFiSession->mNumEntry, gKartFilterString, KartKeysStartCallback, NULL,
                                      ComputeRegionEloEval, 0);
            break;
        case WIFI_MATCH_TYPE_FRIENDS:
            DWC_ConnectToFriendsAsync(NULL, 0, gWiFiSession->mNumEntry, 1, KartKeysStartCallback, NULL, 0, 0);
            break;
        case WIFI_MATCH_TYPE_ELO:
            DWC_ConnectToAnybodyAsync(gWiFiSession->mNumEntry, gKartFilterString, KartKeysStartCallback, NULL,
                                      ComputeEloEval, 0);
            break;
    }
    gWiFiSession->mStartStatus = WIFI_START_STATUS_PENDING;
}

BOOL IsKartKeysStartStatus3(void) {
    s32 status;

    status = gWiFiSession->mStartStatus;
    switch (status) {
        case WIFI_START_STATUS_PENDING:
            break;
        case WIFI_START_STATUS_CONNECTED:
            return TRUE;
        case WIFI_START_STATUS_FAILED:
            break;
    }
    return FALSE;
}

s32 ComputeEloEval(u32 serverIndex) {
    s32 kartType;
    s32 kartRegion;
    s32 value;
    WiFiSession *session;

    kartType =
        DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[WIFI_MATCH_KEY_TYPE].mName, WIFI_MATCH_TYPE_MISSING);
    kartRegion =
        DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[WIFI_MATCH_KEY_REGION].mName, WIFI_MATCH_REGION_MISSING);
    value = DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[WIFI_MATCH_KEY_ELO].mName, WIFI_MATCH_ELO_MISSING);
    if (kartType == WIFI_MATCH_TYPE_MISSING || kartRegion == WIFI_MATCH_REGION_MISSING || value < 0) {
        return 0;
    }
    session = gWiFiSession;
    if (session->mPlayerRecords[0].mPlayer.mElo > value) {
        value = session->mPlayerRecords[0].mPlayer.mElo - value;
    } else {
        value = value - session->mPlayerRecords[0].mPlayer.mElo;
    }
    if (value < WIFI_ELO_WINDOW) {
        if (kartType == WIFI_MATCH_TYPE_ELO) {
            return WIFI_MATCH_SCORE_HIGH - value;
        }
        if (kartType == WIFI_MATCH_TYPE_REGION_ELO) {
            return WIFI_MATCH_SCORE_LOW - value;
        }
    }
    return 0;
}

BOOL ComputeRegionEval(u32 serverIndex) {
    s32 kartType;
    s32 kartRegion;

    kartType =
        DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[WIFI_MATCH_KEY_TYPE].mName, WIFI_MATCH_TYPE_MISSING);
    kartRegion =
        DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[WIFI_MATCH_KEY_REGION].mName, WIFI_MATCH_REGION_MISSING);
    if (kartType == WIFI_MATCH_TYPE_MISSING || kartRegion == WIFI_MATCH_REGION_MISSING) {
        return FALSE;
    }
    if (kartType == WIFI_MATCH_TYPE_REGION) {
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

    kartType =
        DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[WIFI_MATCH_KEY_TYPE].mName, WIFI_MATCH_TYPE_MISSING);
    kartRegion =
        DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[WIFI_MATCH_KEY_REGION].mName, WIFI_MATCH_REGION_MISSING);
    value = DWC_GetMatchIntValue(serverIndex, gWiFiSession->mKeys[WIFI_MATCH_KEY_ELO].mName, WIFI_MATCH_ELO_MISSING);
    if (kartType == WIFI_MATCH_TYPE_MISSING || kartRegion == WIFI_MATCH_REGION_MISSING || value < 0) {
        return 0;
    }
    if (kartType == WIFI_MATCH_TYPE_REGION_ELO) {
        return (kartRegion != gWiFiSession->mPlayerRecords[0].mPlayer.mRegion ? 2 : 1) * WIFI_MATCH_SCORE_HIGH;
    }
    if (kartType == WIFI_MATCH_TYPE_ELO) {
        session = gWiFiSession;
        if (session->mPlayerRecords[0].mPlayer.mElo > value) {
            value = session->mPlayerRecords[0].mPlayer.mElo - value;
        } else {
            value = value - session->mPlayerRecords[0].mPlayer.mElo;
        }
        if (value < WIFI_ELO_WINDOW) {
            if (kartRegion != session->mPlayerRecords[0].mPlayer.mRegion) {
                return WIFI_MATCH_SCORE_HIGH - value;
            }
            return WIFI_MATCH_SCORE_LOW - value;
        }
    }
    return 0;
}

void KartKeysStartCallback(u32 result, s32 flag) {
    WiFiSession *session;
    u8 participantIndex;

    if (result == 0) {
        if (flag != 0) {
            gWiFiSession->mStartStatus = WIFI_START_STATUS_CANCELED;
            return;
        }
        gWiFiSession->mKartMask = 0;
        gWiFiSession->mKartCount = DWC_GetNumConnectionHost();
        gWiFiSession->mStartKartCount = gWiFiSession->mKartCount;
        session = gWiFiSession;
        participantIndex = 0;
        while (participantIndex < session->mStartKartCount) {
            BIT_SET(session->mKartMask, participantIndex);
            session = gWiFiSession;
            participantIndex++;
        }
        MI_CpuFill8(session->mPlayerRecords, 0, sizeof(session->mPlayerRecords));
        FillPlayerRecord(&gWiFiSession->mPlayerRecords[DWC_GetMyAID()].mPlayer);
        SetupWiFiSession(WIFI_SESSION_SETUP_FIRST);
        gWiFiSession->mStartStatus = WIFI_START_STATUS_CONNECTED;
    } else {
        gWiFiSession->mStartStatus = WIFI_START_STATUS_FAILED;
    }
}

void SetWiFiDisconnectKind(s32 kind) {
    gWiFiSession->mDisconnectKind = kind;
    if (gWiFiSession->mDisconnectKind != WIFI_DISCONNECT_OPPONENT_LEFT) {
        return;
    }
    DWC_RegisterMatchingStatus();
    DWC_CloseAllConnectionsHard();
}

void ResetWiFiSession(void) {
    MI_CpuFill8(gWiFiSession->mRecvBuffers, 0, sizeof(gWiFiSession->mRecvBuffers));
    MI_CpuFill8(gWiFiSession->mPlayerRecords, 0, sizeof(gWiFiSession->mPlayerRecords));
    MI_CpuFill8(gWiFiSession->mConnection, 0, 0xe24);
    MI_CpuFill8(&gWiFiSession->mStep, 0, 0x60);
    MI_CpuFill8(&gWiFiSession->mUserData, 0, 0x350);
    MI_CpuFill8(gWiFiSession->mReceiveBuffers, 0, sizeof(gWiFiSession->mReceiveBuffers));
    MI_CpuFill8(gWiFiSession->mIndexMessages, 0, sizeof(gWiFiSession->mIndexMessages));
    MI_CpuFill8(&gWiFiSession->mLogin, 0, sizeof(gWiFiSession->mLogin));
    gWiFiSession->mResetToOff = FALSE;
    gWiFiSession->mRaceSyncEnabled = FALSE;
    gWiFiSession->mIrqCallbackCount = 0;
    gWiFiSession->mDisconnectKind = WIFI_DISCONNECT_NONE;
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
    if (session->mStateMachine.mState != WIFI_SESSION_STATE_OFF) {
        errorKind = session->mErrorKind;
        if (errorKind == WIFI_ERROR_KIND_LINK_DROPPED || errorKind == WIFI_ERROR_KIND_MATCHING_CLOSED ||
            errorKind == WIFI_ERROR_KIND_HTTP_CLOSED || errorKind == 0xb) {
            return WIFI_DISCONNECT_ERROR;
        }
        if (session->mDisconnectKind == WIFI_DISCONNECT_OPPONENT_LEFT) {
            if (DWC_GetNumConnectionHost() <= 1) {
                stateMachine = &gWiFiSession->mStateMachine;
                stateMachine->mNextState = WIFI_SESSION_STATE_IDLE;
                stateMachine->mNextStateRequested = 1;
                return WIFI_DISCONNECT_OPPONENT_LEFT;
            }
        } else if (session->mDisconnectKind == WIFI_DISCONNECT_NO_INPUT) {
            stateMachine = &session->mStateMachine;
            stateMachine->mNextState = WIFI_SESSION_STATE_IDLE;
            stateMachine->mNextStateRequested = 1;
            return WIFI_DISCONNECT_NO_INPUT;
        }
    }
    return WIFI_DISCONNECT_NONE;
}

void ClearWiFiDisconnectStatus(void) {
    gWiFiSession->mErrorKind = 0;
    gWiFiSession->mDisconnectKind = WIFI_DISCONNECT_NONE;
    gWiFiSession->mErrorCode = 0;
}

u32 GetWiFiSessionErrorCodeNegated(void) {
    return ((0x0u) - ((gWiFiSession->mErrorCode)));
}

u32 GetWiFiLinkLevel(void) {
    return DWC_GetLinkLevel();
}

#pragma thumb on
void InitWiFiSession(void *heap) {
    StateMachine *stateMachine;

    gWiFiSession = HeapAllocAligned(heap, 0x1f58, HEAP_ALIGN_CACHE_LINE);
    InitStateMachine(&gWiFiSession->mStateMachine, gWiFiSessionStateTable, 8, NULL);
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_OFF;
    stateMachine->mNextStateRequested = 1;
}

// Creates the 0x3e800-byte exp heap and registers WiFiSessionHeapAlloc / Free with the net layer (the heap is used only
// through them).
void CreateWiFiSessionHeap(void *heap) {
    gWiFiSession->mHeapBuffer = HeapAllocAligned(heap, 0x3e800, HEAP_ALIGN_CACHE_LINE);
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
    stateMachine->mNextState = WIFI_SESSION_STATE_OFF;
    stateMachine->mNextStateRequested = 1;
}
#pragma thumb off

void ResetWiFiSessionToOff(void) {
    StateMachine *stateMachine;

    ResetWiFiSession();
    gWiFiSession->mResetToOff = TRUE;
    stateMachine = &gWiFiSession->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_OFF;
    stateMachine->mNextStateRequested = 1;
}

// Polls one buddy entry's status per call and counts the entries with status 4 into mStatus4BuddyCount.
void UpdateBuddyStatuses(void) {
    u8 status4Count = 0;
    WiFiSession *session;
    WiFiSession *countSession;
    u8 buddyIndex;

    if (gWiFiSession->mBuddyPollIndex >= WIFI_BUDDY_COUNT) {
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
            case WIFI_BUDDY_STATUS_NOT_COUNTED:
                break;
            case WIFI_BUDDY_STATUS_COUNTED:
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
    if (gOverlayLoader->mCurrentOverlay != OVERLAY_SLOT_OV000) {
        return;
    }
    DWC_ProcessFriendsMatch();
    if (DWC_GetLastError(NULL) != 0) {
        gWiFiSession->mErrorKind = DWC_GetLastError(&gWiFiSession->mErrorCode);
        DWC_ClearError();
    }
    if (gWiFiSession->mStateMachine.mState != WIFI_SESSION_STATE_OFF) {
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
