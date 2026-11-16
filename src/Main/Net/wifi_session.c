#include "Main/Net/wifi_session.h"
#include "Main/Race/cup_records.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "00/Lib/DWC/data_transport.h"
#include "00/Lib/DWC/match_send_and_key_value_strings.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record.h"
#include "Main/Net/wi_fi_session_step.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_seq.h"
#include "00/Lib/DWC/matchmaking.h"
#include "Main/Race/race_setup.h"
#include "print_memory_multibyte_write.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Net/wifi_session_login.h"
#include "Main/Net/wifi_session_heap.h"
#include "00/Lib/DWC/internet_connection.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "Main/System/state_machine_init.h"
#include "Main/Net/player_record.h"
#include "00/Lib/DWC/friend_status.h"
#include "00/Lib/DWC/error_state.h"
#include "Main/System/heap_call.h"
#include "expanded_heap_head.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/backup_net_camera_work.h"

#pragma opt_arithtransformation off

StateCallbacks g_GlobalB_E7FnList[7] = {
    {0, 0},
    {GlobalB_E7Fn_1A, GlobalB_E7Fn_1B},
    {0, 0},
    {GlobalB_E7Fn_3A, GlobalB_E7Fn_3B},
    {GlobalB_E7Fn_4A, GlobalB_E7Fn_4B},
    {GlobalB_E7Fn_5A, GlobalB_E7Fn_5B},
    {0, GlobalB_E7Fn_6B},
};
WiFiSession *g_GlobalB;
char g_SomeFormatBuffer[0x64];

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
        if (kartIndex < g_GlobalB->mStartKartCount) {
            if ((g_GlobalB->mKartMask & (1 << kartIndex)) == 0) {
                g_GlobalB->mPackedIndices[kartIndex] = -1;
            } else {
                oldNumber = g_GlobalB->mPackedIndices[kartIndex];
                g_GlobalB->mPackedIndices[kartIndex] = nextNumber;
                nextNumber++;
                CopyKartCupRecords(oldNumber, g_GlobalB->mPackedIndices[kartIndex]);
            }
        } else {
            g_GlobalB->mPackedIndices[kartIndex] = -1;
        }
    }
}

BOOL UpdateWiFiSessionStepTimeout(u32 limit) {
    s32 frames;
    s32 step;
    frames = g_GlobalB->mStepFrames;
    g_GlobalB->mStepFrames = frames + 1;
    if (frames > limit) {
        g_GlobalB->mStepFrames = 0;
        step = g_GlobalB->mStep;
        if (step == WIFI_SESSION_STEP_EXCHANGE_RECORDS || step == WIFI_SESSION_STEP_EXCHANGE_SEEDS ||
            step == WIFI_SESSION_STEP_WAIT_BACKUP) {
            g_GlobalB->mEarlyStepTimedOut = TRUE;
            DWC_RegisterMatchingStatus();
            DWC_CloseAllConnectionsHard();
            g_GlobalB->mStep = WIFI_SESSION_STEP_LEAVING;
        } else {
            if (step == WIFI_SESSION_STEP_VERIFY_RESULT || step == WIFI_SESSION_STEP_READY) {
                return TRUE;
            }
            g_GlobalB->mConnectionLost = TRUE;
            DWC_RegisterMatchingStatus();
            DWC_CloseAllConnectionsHard();
            g_GlobalB->mStep = WIFI_SESSION_STEP_LEAVING;
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
    if (g_GlobalB->mStep >= WIFI_SESSION_STEP_EXCHANGE_PICKS && (g_GlobalB->mKartMask & (1 << fromIndex)) == 0) {
        return;
    }
    g_GlobalB->mSinceCallbackFrames[fromIndex] = 0;
    ownIndex = DWC_GetMyAID();
    if (IsWiFiSessionMessageMatching(message, fromIndex, size, ownIndex) == FALSE) {
        return;
    }
    if (IsWiFiSessionMessageKindAllowed(message->mKind) == FALSE) {
        return;
    }
    switch (message->mKind) {
        case WIFI_SESSION_MESSAGE_RECORD_REQUEST:
            BIT_SET(g_GlobalB->mSendRecordMask, fromIndex);
            break;
        case WIFI_SESSION_MESSAGE_RECORD:
            BIT_SET(g_GlobalB->mReceivedMask, fromIndex);
            DWC_SetRecvBuffer(fromIndex, &g_GlobalB->mReceiveBuffers[fromIndex], sizeof(WiFiSessionMessage));
            break;
        case WIFI_SESSION_MESSAGE_RECORDS_SENT:
            if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_SEEDS) {
                BIT_SET(g_GlobalB->mReceivedMask, fromIndex);
            }
            break;
        case WIFI_SESSION_MESSAGE_CONTINUE_CHOICE:
            if (g_GlobalB->mStep != WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) {
                return;
            }
            if (message->mContinueChoice == WIFI_CONTINUE_CHOICE_NONE) {
                return;
            }
            Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                        sizeof(WiFiSessionMessage));
            BIT_SET(g_GlobalB->mReceivedMask, fromIndex);
            break;
        case WIFI_SESSION_MESSAGE_CONTINUE_CONFIRM:
            if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) {
                Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(g_GlobalB->mReceivedMask, fromIndex);
            } else if (g_GlobalB->mStep == WIFI_SESSION_STEP_CONFIRM_CONTINUE) {
                Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(g_GlobalB->mReceivedMask, fromIndex);
            }
            break;
        case WIFI_SESSION_MESSAGE_PICKS:
            if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_SEEDS) {
                Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                g_GlobalB->mReceivedMask = WIFI_SESSION_ALL_RECEIVED;
            } else if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_PICKS) {
                Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                if (message->mCharacterIndex == -1) {
                    return;
                }
                if (message->mKartIndex == -1) {
                    return;
                }
                BIT_SET(g_GlobalB->mReceivedMask, fromIndex);
            } else if (g_GlobalB->mStep == WIFI_SESSION_STEP_CONFIRM_CONTINUE) {
                Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                g_GlobalB->mReceivedMask = WIFI_SESSION_ALL_RECEIVED;
            }
            break;
        case WIFI_SESSION_MESSAGE_PICK_MASK:
            if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_PICKS) {
                Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(g_GlobalB->mReceivedMask, fromIndex);
            } else if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS) {
                Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(g_GlobalB->mReceivedMask, fromIndex);
            }
            break;
        case WIFI_SESSION_MESSAGE_COURSE_PICK:
            if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS) {
                Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                g_GlobalB->mReceivedMask = WIFI_SESSION_ALL_RECEIVED;
            } else if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS) {
                if (message->mPickedCourseId == 0) {
                    return;
                }
                Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(g_GlobalB->mReceivedMask, fromIndex);
            }
            break;
        case WIFI_SESSION_MESSAGE_COURSE_MASK:
            if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS) {
                Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(g_GlobalB->mReceivedMask, fromIndex);
            } else if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS) {
                Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(g_GlobalB->mReceivedMask, fromIndex);
            }
            break;
        case WIFI_SESSION_MESSAGE_RESULT:
            if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS) {
                Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                BIT_SET(g_GlobalB->mReceivedMask, fromIndex);
            } else if (g_GlobalB->mStep == WIFI_SESSION_STEP_VERIFY_RESULT) {
                Mem_CpuCopy8(&g_GlobalB->mReceiveBuffers[fromIndex], &g_GlobalB->mIndexMessages[fromIndex],
                            sizeof(WiFiSessionMessage));
                EndWiFiSessionOnPicksMismatch(fromIndex);
                BIT_SET(g_GlobalB->mReceivedMask, fromIndex);
            }
            break;
    }
}

void SetWiFiSessionOwnCharacterIndex(s32 characterIndex) {
    g_GlobalB->mIndexMessages[DWC_GetMyAID()].mCharacterIndex = characterIndex;
}

void SetWiFiSessionOwnCharacterIndexNone(void) {
    g_GlobalB->mIndexMessages[DWC_GetMyAID()].mCharacterIndex = -1;
}

void SetWiFiSessionOwnKartIndex(s32 kartIndex) {
    g_GlobalB->mIndexMessages[DWC_GetMyAID()].mKartIndex = kartIndex;
}

void SetWiFiSessionOwnPickedCourseId(s32 pickedCourseId) {
    g_GlobalB->mIndexMessages[DWC_GetMyAID()].mPickedCourseId = pickedCourseId;
}

u32 GetWiFiSessionCharacterIndex(u8 index) {
    return g_GlobalB->mIndexMessages[index].mCharacterIndex;
}

u32 GetWiFiSessionKartIndex(u8 index) {
    return g_GlobalB->mIndexMessages[index].mKartIndex;
}

u32 GetWiFiSessionPickedCourseId(u8 index) {
    return g_GlobalB->mIndexMessages[index].mPickedCourseId;
}

#pragma opt_arithtransformation off

// Own answer on the battle results screen: nonzero is CONTINUE (stored 1), zero is QUIT (stored 2).
void SetWiFiSessionOwnContinueChoice(u32 wantsContinue) {
    g_GlobalB->mIndexMessages[DWC_GetMyAID()].mContinueChoice =
        wantsContinue != 0 ? WIFI_CONTINUE_CHOICE_CONTINUE : WIFI_CONTINUE_CHOICE_QUIT;
}

s32 GetWiFiSessionCourseId(void) {
    if (GetGlobalCA_from_thumb()->mCourseId == 0) {
        return g_GlobalB->mIndexMessages[DWC_GetMyAID()].mPickedCourseId;
    }
    return GetGlobalCA_from_thumb()->mCourseId;
}

BOOL IsWiFiStep5ReachedNoDisconnect(void) {
    if (g_GlobalB->mStep >= WIFI_SESSION_STEP_EXCHANGE_PICKS) {
        if (CheckWiFiSessionDisconnect() == WIFI_DISCONNECT_NONE) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL IsWiFiSessionStep7Reached(void) {
    BOOL result = TRUE;
    WiFiSession *session = g_GlobalB;
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
    WiFiSession *session = g_GlobalB;
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

    step = g_GlobalB->mStep;
    if (step >= WIFI_SESSION_STEP_EXCHANGE_PICKS) {
        if (g_GlobalB->mKartCount > 1) {
            return WIFI_CONTINUE_RESULT_KARTS_LEFT;
        }
        return WIFI_CONTINUE_RESULT_ENDED;
    }
    if (g_GlobalB->mConnectionLost == TRUE) {
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
void MaybeVSSelectRandomCourseId(void) {
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

    session = g_GlobalB;
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
    GetGlobalCA_from_thumb()->mCourseId = talliedCourseId;
}

void WriteWiFiSessionToRaceSetupCopy(void) {
    BOOL ownKind = FALSE;
    u8 participantIndex;

    for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
        if (g_GlobalB->mKartMask & (1 << participantIndex)) {
            if (participantIndex == DWC_GetMyAID()) {
                s8 entryIndex;

                entryIndex = g_GlobalB->mPackedIndices[participantIndex];
                GetGlobalCA_from_thumb()->mEntries[entryIndex].mPlayerKind = ownKind;
            } else {
                s8 entryIndex;

                entryIndex = g_GlobalB->mPackedIndices[participantIndex];
                GetGlobalCA_from_thumb()->mEntries[entryIndex].mPlayerKind = PLAYER_KIND_PEER;
            }
            {
                WiFiSession *wiFiSession;
                s8 entryIndex;

                wiFiSession = g_GlobalB;
                entryIndex = wiFiSession->mPackedIndices[participantIndex];
                GetGlobalCA_from_thumb()->mEntries[entryIndex].mCharacterIndex =
                    wiFiSession->mIndexMessages[participantIndex].mCharacterIndex;
            }
            {
                WiFiSession *wiFiSession;
                s8 entryIndex;

                wiFiSession = g_GlobalB;
                entryIndex = wiFiSession->mPackedIndices[participantIndex];
                GetGlobalCA_from_thumb()->mEntries[entryIndex].mKartIndex =
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
            if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_RECORDS ||
                g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_SEEDS) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_RECORD:
            if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_RECORDS) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_RECORDS_SENT:
            if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_RECORDS ||
                g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_SEEDS) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_CONTINUE_CHOICE:
            if ((u32) (g_GlobalB->mStep - WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) <=
                WIFI_SESSION_STEP_CONFIRM_CONTINUE - WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_CONTINUE_CONFIRM:
            if ((u32) (g_GlobalB->mStep - WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) <=
                WIFI_SESSION_STEP_EXCHANGE_PICKS - WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_PICKS:
            if (g_GlobalB->mStep == WIFI_SESSION_STEP_EXCHANGE_SEEDS ||
                (u32) (g_GlobalB->mStep - WIFI_SESSION_STEP_CONFIRM_CONTINUE) <=
                    WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS - WIFI_SESSION_STEP_CONFIRM_CONTINUE) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_PICK_MASK:
            if ((u32) (g_GlobalB->mStep - WIFI_SESSION_STEP_EXCHANGE_PICKS) <=
                WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS - WIFI_SESSION_STEP_EXCHANGE_PICKS) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_COURSE_PICK:
            if ((u32) (g_GlobalB->mStep - WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS) <=
                WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS - WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_COURSE_MASK:
            if ((u32) (g_GlobalB->mStep - WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS) <=
                WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS - WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS) {
                return TRUE;
            }
            break;
        case WIFI_SESSION_MESSAGE_RESULT:
            if ((u32) (g_GlobalB->mStep - WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS) <=
                WIFI_SESSION_STEP_VERIFY_RESULT - WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

// Index the next message goes to; mStartKartCount means none (the two calls after a pick, or no index left).
u8 GetSomeRacerIndex(void) {
    u8 participantIndex;
    u8 callCount;

    callCount = g_GlobalB->mCallsSincePick;
    if (callCount < WIFI_SESSION_CALLS_AFTER_PICK) {
        g_GlobalB->mCallsSincePick = callCount + 1;
        return g_GlobalB->mStartKartCount;
    }
    for (participantIndex = g_GlobalB->mPickStartIndex; participantIndex < g_GlobalB->mStartKartCount;
         participantIndex++) {
        if (participantIndex != DWC_GetMyAID()) {
            if (g_GlobalB->mKartMask & (1 << participantIndex)) {
                break;
            }
        }
    }
    if (g_GlobalB->mPickStartIndex >= g_GlobalB->mStartKartCount) {
        for (participantIndex = 0; participantIndex < g_GlobalB->mPickStartIndex; participantIndex++) {
            if (participantIndex != DWC_GetMyAID()) {
                if (g_GlobalB->mKartMask & (1 << participantIndex)) {
                    break;
                }
            }
        }
        if (participantIndex >= g_GlobalB->mPickStartIndex) {
            return g_GlobalB->mStartKartCount;
        }
    }
    g_GlobalB->mPickStartIndex = participantIndex + 1;
    g_GlobalB->mCallsSincePick = 0;
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

    for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
        if (participantIndex != DWC_GetMyAID()) {
            if (g_GlobalB->mKartMask & (1 << participantIndex)) {
                checkedCount++;
                if ((g_GlobalB->mReceivedMask & (1 << participantIndex)) == 0) {
                    break;
                }
                receivedCount++;
            }
        }
    }
    if (checkedCount == 0) {
        g_GlobalB->mConnectionLost = TRUE;
        DWC_RegisterMatchingStatus();
        DWC_CloseAllConnectionsHard();
        g_GlobalB->mStep = WIFI_SESSION_STEP_LEAVING;
        return FALSE;
    }
    rosterCount = 0;
    startKartCount = g_GlobalB->mStartKartCount;
    kartMask = g_GlobalB->mKartMask;
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

    for (participantIndex = 0; participantIndex < g_GlobalB->mStartKartCount; participantIndex++) {
        if ((ownIndex = DWC_GetMyAID(), g_GlobalB->mIndexMessages[ownIndex].mKartIndices[participantIndex]) !=
                g_GlobalB->mReceiveBuffers[index].mKartIndices[participantIndex] ||
            (ownIndex = DWC_GetMyAID(), g_GlobalB->mIndexMessages[ownIndex].mCharacterIndices[participantIndex]) !=
                g_GlobalB->mReceiveBuffers[index].mCharacterIndices[participantIndex]) {
            differs = TRUE;
        }
    }
    ownIndex = DWC_GetMyAID();
    if (g_GlobalB->mReceiveBuffers[index].mTalliedCourseId !=
        g_GlobalB->mIndexMessages[ownIndex].mTalliedCourseId) {
        differs = TRUE;
    }
    if (differs == FALSE) {
        return;
    }
    g_GlobalB->mConnectionLost = TRUE;
    DWC_RegisterMatchingStatus();
    DWC_CloseAllConnectionsHard();
    g_GlobalB->mStep = WIFI_SESSION_STEP_LEAVING;
}

BOOL IsWiFiMatchingBeforeTimeLimit(void) {
    return DWC_GetMOMinCompState(NULL) == 0;
}

u8 GetWiFiMatchingParticipantCount(void) {
    return DWC_GetNumConnectionHost();
}

BOOL HasWiFiBuddyStatus4(void) {
    return g_GlobalB->mStatus4BuddyCount != 0;
}

u32 StopWiFiSessionMatching(void) {
    return DWC_CancelMatching();
}

BOOL IsWiFiSessionMatchingActive(void) {
    if (DWC_IsValidCancelMatching() != 0) {
        if (g_GlobalB->mStateMachine.mState == WIFI_SESSION_STATE_SEARCH) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL IsKartKeysStartStatus2(void) {
    return g_GlobalB->mStartStatus == WIFI_START_STATUS_CANCELED;
}

void RequestWiFiSessionMatching(u32 kartType, s32 useTimeLimit, s32 unused) {
    StateMachine *stateMachine;

    DWC_CloseAllConnectionsHard();
    Mem_CpuFill8(&g_GlobalB->mKeys[WIFI_MATCH_KEY_REGION], 0, sizeof(KartKey));
    Mem_CpuFill8(&g_GlobalB->mKeys[WIFI_MATCH_KEY_TYPE], 0, sizeof(KartKey));
    Mem_CpuFill8(&g_GlobalB->mKeys[WIFI_MATCH_KEY_FILTER], 0, sizeof(KartKey));
    Mem_CpuFill8(&g_GlobalB->mKeys[WIFI_MATCH_KEY_ELO], 0, sizeof(KartKey));
    g_GlobalB->mEarlyStepTimedOut = FALSE;
    g_GlobalB->mNumEntry = 0;
    g_GlobalB->mStatus4BuddyCount = 0;
    g_GlobalB->mKartCount = 0;
    g_GlobalB->mStartKartCount = 0;
    g_GlobalB->mKartCountCopy = 0;
    g_GlobalB->mKartMask = 0;
    g_GlobalB->mKartRemoveMask = 0;
    Mem_CpuFill8(&g_GlobalB->mStep, 0, 0x60);
    g_GlobalB->mKeys[WIFI_MATCH_KEY_TYPE].mValue = kartType;
    g_GlobalB->mNumEntry = WIFI_SESSION_KART_SLOTS;
    if (useTimeLimit == 0) {
        g_GlobalB->mMinCompleteOption.mValid = TRUE;
        g_GlobalB->mMinCompleteOption.mMinEntry = WIFI_MATCH_MIN_ENTRIES;
        g_GlobalB->mMinCompleteOption.mTimeLimit = WIFI_MATCH_NO_WAIT;
    } else {
        g_GlobalB->mMinCompleteOption.mValid = TRUE;
        g_GlobalB->mMinCompleteOption.mMinEntry = WIFI_MATCH_MIN_ENTRIES;
        g_GlobalB->mMinCompleteOption.mTimeLimit = WIFI_MATCH_WAIT_LIMIT;
    }
    DWC_SetMatchingOption(0, &g_GlobalB->mMinCompleteOption, 0);
    stateMachine = &g_GlobalB->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_SEARCH;
    stateMachine->mNextStateRequested = 1;
}

s32 CheckWiFiMatchingResult(void) {
    if ((g_GlobalB->mEarlyStepTimedOut != 0 && DWC_GetNumConnectionHost() <= 1) ||
        g_GlobalB->mErrorKind == WIFI_ERROR_KIND_UNRECOVERABLE) {
        return -1;
    }
    return IsWiFiStep5ReachedNoDisconnect() != FALSE;
}

void GlobalB_E7Fn_3AImpl(void) {
    s32 eloHigh;
    s32 eloLow;

    ClearWiFiDisconnectStatus();
    Mem_CpuFill8(g_GlobalB->mPlayerRecords, 0, sizeof(g_GlobalB->mPlayerRecords));
    StructTK_SomeFn_from_thumb(&g_GlobalB->mPlayerRecords[0].mPlayer);
    g_GlobalB->mKeys[WIFI_MATCH_KEY_REGION].mValue = g_GlobalB->mPlayerRecords[0].mPlayer.mRegion;
    g_GlobalB->mKeys[WIFI_MATCH_KEY_ELO].mValue = g_GlobalB->mPlayerRecords[0].mPlayer.mElo;
    __memcpy(g_GlobalB->mKeys[WIFI_MATCH_KEY_FILTER].mName, "kart_filter", 12);
    g_GlobalB->mKeys[WIFI_MATCH_KEY_FILTER].mId =
        DWC_AddMatchKeyString(g_GlobalB->mKeys[WIFI_MATCH_KEY_FILTER].mId,
                              g_GlobalB->mKeys[WIFI_MATCH_KEY_FILTER].mName, "ds_mario_kart_product");
    __memcpy(g_GlobalB->mKeys[WIFI_MATCH_KEY_TYPE].mName, "kart_type", 10);
    g_GlobalB->mKeys[WIFI_MATCH_KEY_TYPE].mId =
        DWC_AddMatchKeyInt(g_GlobalB->mKeys[WIFI_MATCH_KEY_TYPE].mId, g_GlobalB->mKeys[WIFI_MATCH_KEY_TYPE].mName,
                           &g_GlobalB->mKeys[WIFI_MATCH_KEY_TYPE]);
    __memcpy(g_GlobalB->mKeys[WIFI_MATCH_KEY_ELO].mName, "kart_elo", 9);
    g_GlobalB->mKeys[WIFI_MATCH_KEY_ELO].mId =
        DWC_AddMatchKeyInt(g_GlobalB->mKeys[WIFI_MATCH_KEY_ELO].mId, g_GlobalB->mKeys[WIFI_MATCH_KEY_ELO].mName,
                           &g_GlobalB->mKeys[WIFI_MATCH_KEY_ELO]);
    __memcpy(g_GlobalB->mKeys[WIFI_MATCH_KEY_REGION].mName, "kart_region", 12);
    g_GlobalB->mKeys[WIFI_MATCH_KEY_REGION].mId = DWC_AddMatchKeyInt(
        g_GlobalB->mKeys[WIFI_MATCH_KEY_REGION].mId, g_GlobalB->mKeys[WIFI_MATCH_KEY_REGION].mName,
        &g_GlobalB->mKeys[WIFI_MATCH_KEY_REGION]);
    eloLow = g_GlobalB->mPlayerRecords[0].mPlayer.mElo - WIFI_ELO_WINDOW;
    if (eloLow <= 0) {
        eloLow = 0;
    }
    eloHigh = g_GlobalB->mPlayerRecords[0].mPlayer.mElo + WIFI_ELO_WINDOW;
    if (eloHigh > WIFI_ELO_MAX) {
        eloHigh = WIFI_ELO_MAX;
    }
    Mem_CpuFill8(g_SomeFormatBuffer, 0, sizeof(g_SomeFormatBuffer));
    if (g_GlobalB->mKeys[WIFI_MATCH_KEY_TYPE].mValue == WIFI_MATCH_TYPE_ELO) {
        MaybeStrcpy(g_SomeFormatBuffer, "%s = '%s' and %s > %d and %s < %d", "kart_filter", "ds_mario_kart_product",
                "kart_elo", eloLow, "kart_elo", eloHigh);
    } else {
        MaybeStrcpy(g_SomeFormatBuffer, "%s = '%s'", "kart_filter", "ds_mario_kart_product");
    }
    switch (g_GlobalB->mKeys[WIFI_MATCH_KEY_TYPE].mValue) {
        case WIFI_MATCH_TYPE_REGION:
            DWC_ConnectToAnybodyAsync(g_GlobalB->mNumEntry, g_SomeFormatBuffer, KartKeysStartCallback, NULL,
                                      ComputeRegionEval, 0);
            break;
        case WIFI_MATCH_TYPE_REGION_ELO:
            DWC_ConnectToAnybodyAsync(g_GlobalB->mNumEntry, g_SomeFormatBuffer, KartKeysStartCallback, NULL,
                                      ComputeRegionEloEval, 0);
            break;
        case WIFI_MATCH_TYPE_FRIENDS:
            DWC_ConnectToFriendsAsync(NULL, 0, g_GlobalB->mNumEntry, 1, KartKeysStartCallback, NULL, 0, 0);
            break;
        case WIFI_MATCH_TYPE_ELO:
            DWC_ConnectToAnybodyAsync(g_GlobalB->mNumEntry, g_SomeFormatBuffer, KartKeysStartCallback, NULL,
                                      ComputeEloEval, 0);
            break;
    }
    g_GlobalB->mStartStatus = WIFI_START_STATUS_PENDING;
}

BOOL IsKartKeysStartStatus3(void) {
    s32 status;

    status = g_GlobalB->mStartStatus;
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
        DWC_GetMatchIntValue(serverIndex, g_GlobalB->mKeys[WIFI_MATCH_KEY_TYPE].mName, WIFI_MATCH_TYPE_MISSING);
    kartRegion =
        DWC_GetMatchIntValue(serverIndex, g_GlobalB->mKeys[WIFI_MATCH_KEY_REGION].mName, WIFI_MATCH_REGION_MISSING);
    value = DWC_GetMatchIntValue(serverIndex, g_GlobalB->mKeys[WIFI_MATCH_KEY_ELO].mName, WIFI_MATCH_ELO_MISSING);
    if (kartType == WIFI_MATCH_TYPE_MISSING || kartRegion == WIFI_MATCH_REGION_MISSING || value < 0) {
        return 0;
    }
    session = g_GlobalB;
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
        DWC_GetMatchIntValue(serverIndex, g_GlobalB->mKeys[WIFI_MATCH_KEY_TYPE].mName, WIFI_MATCH_TYPE_MISSING);
    kartRegion =
        DWC_GetMatchIntValue(serverIndex, g_GlobalB->mKeys[WIFI_MATCH_KEY_REGION].mName, WIFI_MATCH_REGION_MISSING);
    if (kartType == WIFI_MATCH_TYPE_MISSING || kartRegion == WIFI_MATCH_REGION_MISSING) {
        return FALSE;
    }
    if (kartType == WIFI_MATCH_TYPE_REGION) {
        if (g_GlobalB->mPlayerRecords[0].mPlayer.mRegion == kartRegion) {
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
        DWC_GetMatchIntValue(serverIndex, g_GlobalB->mKeys[WIFI_MATCH_KEY_TYPE].mName, WIFI_MATCH_TYPE_MISSING);
    kartRegion =
        DWC_GetMatchIntValue(serverIndex, g_GlobalB->mKeys[WIFI_MATCH_KEY_REGION].mName, WIFI_MATCH_REGION_MISSING);
    value = DWC_GetMatchIntValue(serverIndex, g_GlobalB->mKeys[WIFI_MATCH_KEY_ELO].mName, WIFI_MATCH_ELO_MISSING);
    if (kartType == WIFI_MATCH_TYPE_MISSING || kartRegion == WIFI_MATCH_REGION_MISSING || value < 0) {
        return 0;
    }
    if (kartType == WIFI_MATCH_TYPE_REGION_ELO) {
        return (kartRegion != g_GlobalB->mPlayerRecords[0].mPlayer.mRegion ? 2 : 1) * WIFI_MATCH_SCORE_HIGH;
    }
    if (kartType == WIFI_MATCH_TYPE_ELO) {
        session = g_GlobalB;
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
            g_GlobalB->mStartStatus = WIFI_START_STATUS_CANCELED;
            return;
        }
        g_GlobalB->mKartMask = 0;
        g_GlobalB->mKartCount = DWC_GetNumConnectionHost();
        g_GlobalB->mStartKartCount = g_GlobalB->mKartCount;
        session = g_GlobalB;
        participantIndex = 0;
        while (participantIndex < session->mStartKartCount) {
            BIT_SET(session->mKartMask, participantIndex);
            session = g_GlobalB;
            participantIndex++;
        }
        Mem_CpuFill8(session->mPlayerRecords, 0, sizeof(session->mPlayerRecords));
        StructTK_SomeFn_from_thumb(&g_GlobalB->mPlayerRecords[DWC_GetMyAID()].mPlayer);
        SetupWiFiSession(WIFI_SESSION_SETUP_FIRST);
        g_GlobalB->mStartStatus = WIFI_START_STATUS_CONNECTED;
    } else {
        g_GlobalB->mStartStatus = WIFI_START_STATUS_FAILED;
    }
}

void SetWiFiDisconnectKind(s32 kind) {
    g_GlobalB->mDisconnectKind = kind;
    if (g_GlobalB->mDisconnectKind != WIFI_DISCONNECT_OPPONENT_LEFT) {
        return;
    }
    DWC_RegisterMatchingStatus();
    DWC_CloseAllConnectionsHard();
}

void ResetWiFiSession(void) {
    Mem_CpuFill8(g_GlobalB->mRecvBuffers, 0, sizeof(g_GlobalB->mRecvBuffers));
    Mem_CpuFill8(g_GlobalB->mPlayerRecords, 0, sizeof(g_GlobalB->mPlayerRecords));
    Mem_CpuFill8(g_GlobalB->mConnection, 0, 0xe24);
    Mem_CpuFill8(&g_GlobalB->mStep, 0, 0x60);
    Mem_CpuFill8(&g_GlobalB->mUserData, 0, 0x350);
    Mem_CpuFill8(g_GlobalB->mReceiveBuffers, 0, sizeof(g_GlobalB->mReceiveBuffers));
    Mem_CpuFill8(g_GlobalB->mIndexMessages, 0, sizeof(g_GlobalB->mIndexMessages));
    Mem_CpuFill8(&g_GlobalB->mLogin, 0, sizeof(g_GlobalB->mLogin));
    g_GlobalB->mResetToOff = FALSE;
    g_GlobalB->mRaceSyncEnabled = FALSE;
    g_GlobalB->mIrqCallbackCount = 0;
    g_GlobalB->mDisconnectKind = WIFI_DISCONNECT_NONE;
    g_GlobalB->mErrorKind = 0;
    g_GlobalB->mErrorCode = 0;
    g_GlobalB->mUnk_1f4c = 0;
    g_GlobalB->mUnk_1f4d = 0;
    Mem_CpuFill8(g_GlobalB->mPackedIndices, 0, 4);
    g_GlobalB->mKartCount = 0;
    g_GlobalB->mStartKartCount = 0;
    g_GlobalB->mKartCountCopy = 0;
    g_GlobalB->mKartMask = 0;
    g_GlobalB->mKartRemoveMask = 0;
    g_GlobalB->mBuddyPollIndex = 0;
}

// 0 none, 1 no input for 30 seconds, 2 the opponent left, 3 error; for 1 and 2 it also requests state 2.
u32 CheckWiFiSessionDisconnect(void) {
    WiFiSession *session;
    StateMachine *stateMachine;
    s32 errorKind;

    session = g_GlobalB;
    if (session->mStateMachine.mState != WIFI_SESSION_STATE_OFF) {
        errorKind = session->mErrorKind;
        if (errorKind == WIFI_ERROR_KIND_LINK_DROPPED || errorKind == WIFI_ERROR_KIND_MATCHING_CLOSED ||
            errorKind == WIFI_ERROR_KIND_HTTP_CLOSED || errorKind == 0xb) {
            return WIFI_DISCONNECT_ERROR;
        }
        if (session->mDisconnectKind == WIFI_DISCONNECT_OPPONENT_LEFT) {
            if (DWC_GetNumConnectionHost() <= 1) {
                stateMachine = &g_GlobalB->mStateMachine;
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
    g_GlobalB->mErrorKind = 0;
    g_GlobalB->mDisconnectKind = WIFI_DISCONNECT_NONE;
    g_GlobalB->mErrorCode = 0;
}

u32 GetMaybeNetErrorCode(void) {
    return ((0x0u) - ((g_GlobalB->mErrorCode)));
}

u32 GetWiFiLinkLevel(void) {
    return DWC_GetLinkLevel();
}

#pragma thumb on
void InitializeGlobalB_from_thumb(void *heap) {
    StateMachine *stateMachine;

    g_GlobalB = Mem_AllocateHeapAligned(heap, 0x1f58, HEAP_ALIGN_CACHE_LINE);
    StateDualHandler_Create(&g_GlobalB->mStateMachine, g_GlobalB_E7FnList, 8, NULL);
    stateMachine = &g_GlobalB->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_OFF;
    stateMachine->mNextStateRequested = 1;
}

// Creates the 0x3e800-byte exp heap and registers WiFiSessionHeapAlloc / Free with the net layer (the heap is used only
// through them).
void CreateStructBHeap_from_thumb(void *heap) {
    g_GlobalB->mHeapBuffer = Mem_AllocateHeapAligned(heap, 0x3e800, HEAP_ALIGN_CACHE_LINE);
    g_GlobalB->mHeap = Mem_Exp_Create(g_GlobalB->mHeapBuffer, 0x3e800, 1);
    g_GlobalB->mHeapCreated = TRUE;
    DWC_SetMemFunc(WiFiSessionHeapAlloc, WiFiSessionHeapFree);
}

// Destroys the heap and frees its buffer (mHeap is left set), clears mHeapCreated and requests state 0.
void DeleteWiFiSessionHeap(void) {
    StateMachine *stateMachine;

    if (g_GlobalB->mHeap != NULL) {
        Mem_Exp_Finalize(g_GlobalB->mHeap);
        Mem_FreeHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), g_GlobalB->mHeapBuffer);
    }
    g_GlobalB->mHeapCreated = FALSE;
    stateMachine = &g_GlobalB->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_OFF;
    stateMachine->mNextStateRequested = 1;
}
#pragma thumb off

void ResetWiFiSessionToOff(void) {
    StateMachine *stateMachine;

    ResetWiFiSession();
    g_GlobalB->mResetToOff = TRUE;
    stateMachine = &g_GlobalB->mStateMachine;
    stateMachine->mNextState = WIFI_SESSION_STATE_OFF;
    stateMachine->mNextStateRequested = 1;
}

// Polls one buddy entry's status per call and counts the entries with status 4 into mStatus4BuddyCount.
void UpdateBuddyStatuses(void) {
    u8 status4Count = 0;
    WiFiSession *session;
    WiFiSession *countSession;
    u8 buddyIndex;

    if (g_GlobalB->mBuddyPollIndex >= WIFI_BUDDY_COUNT) {
        g_GlobalB->mBuddyPollIndex = 0;
    }
    session = g_GlobalB;
    session->mBuddyStatuses[session->mBuddyPollIndex] =
        DWC_GetFriendStatus(&session->mBuddies[session->mBuddyPollIndex], NULL);
    g_GlobalB->mBuddyPollIndex++;
    countSession = g_GlobalB;
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
    if (g_GlobalB == NULL) {
        return;
    }
    if (g_OverlayManager->mCurrentOverlay != OVERLAY_SLOT_OV000) {
        return;
    }
    DWC_ProcessFriendsMatch();
    if (DWC_GetLastError(NULL) != 0) {
        g_GlobalB->mErrorKind = DWC_GetLastError(&g_GlobalB->mErrorCode);
        DWC_ClearError();
    }
    if (g_GlobalB->mStateMachine.mState != WIFI_SESSION_STATE_OFF) {
        UpdateBuddyStatuses();
    }
    StateDualHandler_Execute(&g_GlobalB->mStateMachine);
}

s32 SendWiFiPacketToParticipant(u32 participantIndex, void *packet, s32 size, u32 (*finishCallback)(void)) {
    return DWC_SendUnreliable(participantIndex, packet, size);
}

// Returns the name+emblem part of the index's record, or NULL if the index is not in mKartMask.
PlayerRecord *GetTKByIndex(u32 index) {
    WiFiSession *session = g_GlobalB;

    if (session->mKartMask & (1 << index)) {
        return &session->mPlayerRecords[index].mPlayer;
    }
    return NULL;
}
