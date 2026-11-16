#include "Main/Net/wifi_race_sync_advance.h"
#include "Main/System/input_slots.h"
#include "Main/Net/slot_result_sync.h"
#include "Main/Net/kart_progress_pack.h"
#include "Main/Net/elo_change_row.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/Net/wifi_session.h"
#include "Main/Net/player_record.h"
#include "Main/Item/item_data_slots_update.h"
#include "Main/System/backup_net_camera_work.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "tick_counter.h"
#include "bit_count.h"
#include "card_rom_backup_access.h"
#include "cpu_copy_fill.h"
#include "thread_scheduler.h"
#include "Main/Race/race_progress_kart.h"
#include "Main/Race/cup_records.h"
#include "Main/Menu/choises_s.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Net/wifi_race_sync_send.h"
#include "Main/Race/race.h"
#include "arena_cache_init.h"
#include "Main/System/heap.h"
#include "Main/Net/slot_result_pending.h"
#include "Main/System/state_machine_init.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Race/race_progress_rank.h"
#include "Main/Race/kart.h"
#include "Main/Race/race_clock.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const EloChangeRow gEloChangeTable[9] = {{0x3e8, 8, 0}, {0x1f4, 7, -1}, {0xfa, 6, -2},  {0x64, 5, -3},  {-100, 4, -4},
                                         {-250, 3, -5}, {-500, 2, -6},  {-1000, 1, -7}, {-30000, 0, -8}};
StateCallbacks g_E7FnList4[WIFI_RACE_SYNC_STATE_COUNT] = {
    {NULL, NULL},
    {E7FnList4_Fn2, E7FnList4_Fn3},
    {E7FnList4_Fn4, E7FnList4_Fn5},
    {E7FnList4_Fn6, E7FnList4_Fn7},
    {E7FnList4_Fn8, E7FnList4_Fn9},
    {E7FnList4_Fn10, E7FnList4_Fn11}};

void CreateGlobalRE(void) {
    s32 index;

    for (index = 0; index < 4; index++) {
        g_GlobalRE->mParticipantOfKart[index] = -1;
        g_GlobalRE->mKartOfParticipant[index] = -1;
    }
    g_GlobalRE->mUnk_05 = 0;
}

void SetParticipantKartMapFromMask(u32 participantMask) {
    u8 participant;
    u8 kart;

    for (participant = 0, kart = 0; participant < 4; participant++) {
        g_GlobalRE->mKartOfParticipant[participant] = -1;
        if (BIT_IS_SET(participantMask, participant)) {
            g_GlobalRE->mParticipantOfKart[kart] = participant;
            g_GlobalRE->mKartOfParticipant[participant] = kart;
            kart++;
        }
    }
    g_GlobalRE->mParticipantMask = participantMask;
    while (kart < 4) {
        g_GlobalRE->mParticipantOfKart[kart] = -1;
        kart++;
    }
}

static inline BOOL ReplyToWiFiRaceSyncProbe(void) {
    u8 participant;
    WiFiRaceSync *sync;
    WiFiRaceSyncRecord *payload;

    sync = g_GlobalAA;
    payload = &sync->mSendBuffer->mRecord;
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        if (sync->mPeers[participant].mProbePending != FALSE) {
            Mem_CpuCopy8(&sync->mPeers[participant], payload, WIFI_RACE_SYNC_PROBE_SIZE);
            *(u64 *) &payload->mProbeWords[3] = Os_GetTick();
            if (SendWiFiRaceSyncPacket(participant, WIFI_RACE_SYNC_PACKET_PROBE, WIFI_RACE_SYNC_PROBE_SIZE) != 0) {
                g_GlobalAA->mPeers[participant].mProbePending = FALSE;
            } else {
                Mem_CpuFill8(payload, 0, WIFI_RACE_SYNC_PROBE_SIZE);
            }
            return TRUE;
        }
    }
    return FALSE;
}

void InitializeGlobalAA(void *heap) {
    s32 slotIndex;
    s32 index;
    u8 participantIndex;
    s32 entryIndex;
    u8 participant;
    WiFiRaceSync *sync;

    if (g_GlobalCO->mMode != MODE_WIFI) {
        return;
    }
    g_GlobalAA = Mem_AllocateHeap(heap, sizeof(*g_GlobalAA));
    g_GlobalAA->mSendBuffer = Mem_AllocateHeapAligned(heap, WIFI_RACE_SYNC_SEND_BUFFER_SIZE, HEAP_ALIGN_CACHE_LINE);
    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        g_GlobalAA->mItemDataSlots[slotIndex].mData = Mem_AllocateHeapAligned(heap, ITEM_DATA_SLOT_BUFFER_SIZE, 32);
        for (index = 0; index < WIFI_RACE_SYNC_PARTICIPANT_COUNT; index++) {
            g_GlobalAA->mReceivedItemDataSlots[slotIndex][index].mData =
                Mem_AllocateHeapAligned(heap, ITEM_DATA_SLOT_BUFFER_SIZE, 32);
        }
    }
    g_GlobalAA->mStartParticipantMask = g_GlobalRE->mParticipantMask;
    Mem_CpuFill8(g_GlobalAA->mSendBuffer, 0, WIFI_RACE_SYNC_SEND_BUFFER_SIZE);
    for (entryIndex = 0; entryIndex < WIFI_RACE_SYNC_PARTICIPANT_COUNT; entryIndex++) {
        // Clears the record part of the entry.
        Mem_CpuFill8(&g_GlobalAA->mEntries[entryIndex], 0, WIFI_RACE_SYNC_RECORD_SIZE);
        g_GlobalAA->mEntries[entryIndex].mRecordReceived = 0;
    }
    participantIndex = g_GlobalAA->mStartParticipantMask;
    g_GlobalAA->mDroppedParticipantMask = 0;
    g_GlobalAA->mParticipantMask = participantIndex;
    for (participantIndex = 0; participantIndex < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participantIndex++) {
        g_GlobalAA->mPeerDroppedMasks[participantIndex] = 0;
        g_GlobalAA->mTimeoutFrames[participantIndex] = 0;
    }
    ResetItemDataSlots();
    InitSlotResultSyncStates();
    g_GlobalAA->mFlags |= WIFI_RACE_SYNC_FLAG_RESET_UNREAD_A;
    g_GlobalAA->mFlags |= WIFI_RACE_SYNC_FLAG_RESET_UNREAD_B;
    sync = g_GlobalAA;
    sync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_IDLE;
    sync->mStateMachine.mNextStateRequested = 1;
    g_GlobalAA->mSharedState = WIFI_RACE_SHARED_STATE_IDLE;
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        index = g_GlobalRE->mKartOfParticipant[participant];
        g_GlobalAA->mEntries[participant].mLastProgressWord = 0;
        if (index >= 0) {
            g_GlobalAA->mEntries[participant].mRank = GetKartStartRank((u8) index);
        } else {
            g_GlobalAA->mEntries[participant].mRank = 0;
        }
    }
    StateDualHandler_Create(&g_GlobalAA->mStateMachine, g_E7FnList4, WIFI_RACE_SYNC_STATE_COUNT, NULL);
}

void AdvanceWiFiRaceSyncFrames(void) {
    WiFiRaceSync *sync;

    sync = g_GlobalAA;
    if (sync == NULL) {
        return;
    }
    switch (sync->mStateMachine.mState) {
        case WIFI_RACE_SYNC_STATE_RACE:
        case WIFI_RACE_SYNC_STATE_AFTER_CHOICE:
            sync->mSyncFrames++;
            break;
    }
}

void E7FnList4_Fn2(void *stateObject) {
    u8 participant;
    s32 *probeCopy;
    WiFiRaceSync *sync;

    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        probeCopy = &g_GlobalAA->mPeers[participant].mProbeSentTickLow;
        probeCopy[0] = 0;
        probeCopy[1] = 0;
        probeCopy[2] = 0;
        probeCopy[3] = 0;
        probeCopy[4] = 0;
        probeCopy[5] = 0;
        probeCopy[6] = 0;
        probeCopy[7] = 0;
        probeCopy[8] = 0;
        sync = g_GlobalAA;
        sync->mPeers[participant].mRoundTripTotal = 0;
        sync->mPeers[participant].mSampleCount = 0;
        g_GlobalAA->mPeers[participant].mRejectedSampleCount = 0;
        g_GlobalAA->mPeers[participant].mEmptyPacketPhase = 0;
    }
    g_GlobalAA->mSendParticipantIndex = 0;
    g_GlobalAA->mSampledMask = 0;
    g_GlobalAA->mUnk_0fd = 0;
    g_GlobalAA->mCountdownDrift = 0;
    g_GlobalAA->mCountdownTimer = WIFI_RACE_SYNC_PRE_COUNTDOWN_TIME;
    g_GlobalAA->mSharedState = WIFI_RACE_SHARED_STATE_PROBING;
    g_GlobalAA->mFlags &= ~WIFI_RACE_SYNC_FLAG_IN_RACE;
    g_GlobalAA->mFlags |= WIFI_RACE_SYNC_FLAG_REMOVE_DROPPED;
    g_GlobalAA->mFlags &= ~WIFI_RACE_SYNC_FLAG_DATA_SHARING_INCOMPLETE;
}

void E7FnList4_Fn3(void *stateObject) {
    u16 participant;
    u8 mask;
    u16 sendParticipantIndex;
    u8 targetParticipant;
    WiFiRaceSync *sync;
    WiFiRaceSyncRecord *payload;
    WiFiRaceSyncSendBuffer *sendBuffer;

    mask = 0;
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        if (participant == DWC_GetMyAID() ||
            g_GlobalAA->mPeers[participant].mSampleCount >= WIFI_RACE_SYNC_SAMPLE_COUNT) {
            mask = mask | (1 << participant);
        }
    }
    sync = g_GlobalAA;
    if (sync->mParticipantMask == (sync->mParticipantMask & mask)) {
        sync->mSampledMask = mask;
        sync = g_GlobalAA;
        sync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_READY;
        sync->mStateMachine.mNextStateRequested = 1;
    }
    if (ReplyToWiFiRaceSyncProbe() != FALSE) {
        return;
    }
    sync = g_GlobalAA;
    sendParticipantIndex = sync->mSendParticipantIndex;
    if (sendParticipantIndex < WIFI_RACE_SYNC_PARTICIPANT_COUNT) {
        targetParticipant = sendParticipantIndex;
        if (BIT_IS_SET(sync->mParticipantMask, targetParticipant) && targetParticipant != DWC_GetMyAID()) {
            sync = g_GlobalAA;
            if (sync->mPeers[targetParticipant].mSampleCount < WIFI_RACE_SYNC_SAMPLE_COUNT) {
                sendBuffer = sync->mSendBuffer;
                payload = &sendBuffer->mRecord;
                sendBuffer->mRecord.mLeadHalfword = DWC_GetMyAID();
                *(u64 *) &payload->mProgressWord = Os_GetTick();
                payload->mProbeWords[1] = 0;
                payload->mProbeWords[2] = 0;
                payload->mProbeWords[3] = 0;
                payload->mProbeWords[4] = 0;
                payload->mProbeWords[5] = 0;
                *(u32 *) &payload->mSlotResultSyncs[0] = 0;
                SendWiFiRaceSyncPacket(targetParticipant, WIFI_RACE_SYNC_PACKET_PROBE, WIFI_RACE_SYNC_PROBE_SIZE);
            } else {
                if (sync->mPeers[targetParticipant].mEmptyPacketPhase == 0) {
                    SendWiFiRaceSyncPacket(targetParticipant, WIFI_RACE_SYNC_PACKET_EMPTY, 0);
                }
                g_GlobalAA->mPeers[targetParticipant].mEmptyPacketPhase++;
                if (g_GlobalAA->mPeers[targetParticipant].mEmptyPacketPhase > WIFI_RACE_SYNC_EMPTY_PHASE_LAST) {
                    g_GlobalAA->mPeers[targetParticipant].mEmptyPacketPhase = 0;
                }
            }
        }
        g_GlobalAA->mSendParticipantIndex++;
    } else {
        sync->mSendParticipantIndex = 0;
    }
}

void E7FnList4_Fn4(void *stateObject) {
    s32 participant;
    WiFiRaceSync *sync;
    u8 sampleCount;
    u64 roundTripTotal;

    g_GlobalAA->mReadyMask = 1 << DWC_GetMyAID();
    g_GlobalAA->mCountdownTimer = WIFI_RACE_SYNC_PRE_COUNTDOWN_TIME;
    g_GlobalAA->mSendParticipantIndex = 0;
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        sync = g_GlobalAA;
        sampleCount = sync->mPeers[participant].mSampleCount;
        roundTripTotal = sync->mPeers[participant].mRoundTripTotal;
        if (sampleCount == 0) {
            sync->mEntries[participant].mRoundTripAverage = 0;
        } else {
            sync->mEntries[participant].mRoundTripAverage = (roundTripTotal / sampleCount * 64 / 0x82ea + 32) / 33;
        }
    }
}

void CallWithNextWiFiRaceSyncParticipant(u16 previousParticipant, void (*callback)(u32)) {
    u16 participantOffset;
    s32 nextParticipant;
    u16 participant;

    nextParticipant = -1;
    for (participantOffset = 1; participantOffset <= 4; participantOffset++) {
        participant = previousParticipant + participantOffset;
        if (participant >= 4) {
            participant = participant - 4;
        }
        if (participant != DWC_GetMyAID() && (g_GlobalAA->mParticipantMask & (1 << (u8) participant)) != 0) {
            nextParticipant = participant;
            break;
        }
    }
    if (nextParticipant == -1) {
        return;
    }
    callback(nextParticipant);
}

void SendWiFiRaceSyncReady(u32 participant) {
    u8 index;
    if (participant == 0xffffffff) {
        return;
    }
    index = participant;
    if (g_GlobalAA->mParticipantMask & (1 << index)) {
        if (SendWiFiRaceSyncPacket(index, WIFI_RACE_SYNC_PACKET_READY, 8) != 0) {
            g_GlobalAA->mSendParticipantIndex = index;
        }
    }
}

void E7FnList4_Fn5(void *stateObject) {
    WiFiRaceSync *sync;
    u8 participant;
    WiFiRaceSyncRecord *payload;

    sync = g_GlobalAA;
    payload = &sync->mSendBuffer->mRecord;
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        if (sync->mPeers[participant].mProbePending != FALSE) {
            Mem_CpuCopy8(&sync->mPeers[participant], payload, WIFI_RACE_SYNC_PROBE_SIZE);
            *(u64 *) &payload->mProbeWords[3] = Os_GetTick();
            if (SendWiFiRaceSyncPacket(participant, WIFI_RACE_SYNC_PACKET_PROBE, WIFI_RACE_SYNC_PROBE_SIZE) != 0) {
                g_GlobalAA->mPeers[participant].mProbePending = FALSE;
            } else {
                Mem_CpuFill8(payload, 0, WIFI_RACE_SYNC_PROBE_SIZE);
            }
            break;
        }
    }
    sync = g_GlobalAA;
    if (sync->mParticipantMask == (sync->mParticipantMask & sync->mReadyMask)) {
        sync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_COUNTDOWN;
        sync->mStateMachine.mNextStateRequested = 1;
        return;
    }
    CallWithNextWiFiRaceSyncParticipant(sync->mSendParticipantIndex, SendWiFiRaceSyncReady);
}

void E7FnList4_Fn6(void *stateObject) {
    g_GlobalAA->mCountdownTimer = WIFI_RACE_SYNC_COUNTDOWN_TIME;
    g_GlobalAA->mCountdownSendIndex = 0;
}

void SendWiFiRaceSyncCountdown(u32 participant) {
    WiFiRaceSyncSendBuffer *sendBuffer;
    WiFiRaceSyncRecord *payload;

    sendBuffer = g_GlobalAA->mSendBuffer;
    payload = &sendBuffer->mRecord;
    payload->mLeadHalfword = g_GlobalAA->mCountdownTimer - g_GlobalAA->mEntries[participant].mRoundTripAverage;
    payload->mCountdownBytes[0] = g_GlobalAA->mSampledMask;
    if (SendWiFiRaceSyncPacket(participant, WIFI_RACE_SYNC_PACKET_COUNTDOWN, 8) != 0) {
        g_GlobalAA->mCountdownSendIndex = participant;
    }
}

void E7FnList4_Fn7(void *stateObject) {
    WiFiRaceSync *sync;

    g_GlobalAA->mCountdownTimer = g_GlobalAA->mCountdownTimer - 1;
    if (g_GlobalAA->mCountdownTimer <= 0) {
        g_GlobalAA->mCountdownTimer = -1;
        sync = g_GlobalAA;
        sync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_RACE;
        sync->mStateMachine.mNextStateRequested = 1;
        return;
    }
    CallWithNextWiFiRaceSyncParticipant(g_GlobalAA->mCountdownSendIndex, SendWiFiRaceSyncCountdown);
}

void E7FnList4_Fn8(void *stateObject) {
    u8 participant;

    g_GlobalAA->mFlags = g_GlobalAA->mFlags | WIFI_RACE_SYNC_FLAG_IN_RACE;
    g_GlobalAA->mFlags = g_GlobalAA->mFlags & ~WIFI_RACE_SYNC_FLAG_CLEARED_UNREAD;
    g_GlobalAA->mFlags = g_GlobalAA->mFlags & ~WIFI_RACE_SYNC_FLAG_IDLE_DISCONNECT_SENT;
    g_GlobalAA->mSyncFrames = 0;
    g_GlobalAA->mRecordSendCursor = 0;
    g_GlobalAA->mUnk_73d = 0;
    g_GlobalAA->mUnk_73b = 0;
    g_GlobalAA->mFinishedMask = 0;
    g_GlobalAA->mFinishRecorded = FALSE;
    g_GlobalAA->mIdleFrames = 0;
    g_GlobalAA->mSharedState = WIFI_RACE_SHARED_STATE_RACING;
    Mem_CpuFill8(g_GlobalAA->mSendBuffer, 0, WIFI_RACE_SYNC_SEND_BUFFER_SIZE);
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        if (BIT_IS_SET(g_GlobalAA->mStartParticipantMask, participant) &&
            (g_GlobalAA->mParticipantMask & (1 << participant)) == 0) {
            if (g_GlobalRE->mKartOfParticipant[participant] >= 0) {
                g_GlobalAA->mEntries[participant].mLastProgressWord =
                    (GetKartStartRank((u8) g_GlobalRE->mKartOfParticipant[participant]) - 1) |
                    WIFI_RACE_SYNC_PROGRESS_DROPPED;
            }
        }
    }
}

int SendWiFiRaceSyncPacket(u8 participant, u32 kind, int dataSize) {
    WiFiRaceSyncPacket *packet;
    int result;

    result = 1;
    if ((g_GlobalAA->mFlags & WIFI_RACE_SYNC_FLAG_SENDING) != 0) {
        return 0;
    }
    if (participant != DWC_GetMyAID()) {
        result = dataSize + 4;
        packet = &g_GlobalAA->mSendBuffer->mPacket;
        g_GlobalAA->mFlags = g_GlobalAA->mFlags | WIFI_RACE_SYNC_FLAG_SENDING;
        packet->mSender = DWC_GetMyAID();
        packet->mTarget = participant;
        packet->mKind = kind;
        packet->mSharedState = g_GlobalAA->mSharedState;
        packet->mDroppedParticipantMask = g_GlobalAA->mDroppedParticipantMask;
        DC_SomeClean(packet, result);
        result = SendWiFiPacketToParticipant(participant, packet, result, FinishWiFiRaceSyncSend);
        if (result == 0) {
            g_GlobalAA->mFlags = g_GlobalAA->mFlags & ~WIFI_RACE_SYNC_FLAG_SENDING;
        }
    }
    return result;
}

void SendWiFiRaceSyncRecord(s32 dataSize) {
    u8 participant;
    s8 lastParticipant;
    s32 sentCount;
    u8 sendCursor;

    sentCount = 0;
    sendCursor = g_GlobalAA->mRecordSendCursor;
    if ((sendCursor & 1) == 0) {
        g_GlobalAA->mRecordSendCursor = sendCursor + 1;
        return;
    }
    participant = sendCursor >> 1;
    lastParticipant = participant - 1;
    if (lastParticipant < 0) {
        lastParticipant = lastParticipant + 4;
    }
    while (sentCount < 1 && participant != lastParticipant) {
        if (participant != DWC_GetMyAID() && BIT_IS_SET(g_GlobalAA->mParticipantMask, participant)) {
            if (SendWiFiRaceSyncPacket(participant, WIFI_RACE_SYNC_PACKET_RECORD, dataSize) != 0) {
                participant = participant + 1;
                if (participant >= 4) {
                    participant = 0;
                }
                sentCount = sentCount + 1;
            } else {
                participant = participant + 1;
                if (participant >= 4) {
                    participant = 0;
                }
            }
        } else {
            participant = participant + 1;
            if (participant >= 4) {
                participant = 0;
            }
        }
    }
    g_GlobalAA->mRecordSendCursor = participant << 1;
}

void UpdateWiFiRaceSyncRanks(void) {
    u32 sortKeys[4];
    u8 participantOrder[4];
    u8 participant;
    u8 orderIndex;
    u8 insertIndex;
    u8 shiftIndex;
    s16 earlierIndex;
    u32 finishedMask;
    u32 key;
    u8 movedParticipant;
    u8 rank;
    u32 inMaskBit;
    u32 recordWord;
    u32 participantFinishedMask;
    u32 kart;
    u32 entryRecord;
    u32 skipFlag;
    WiFiRaceSync *sync;
    u32 participantBit;
    u8 otherParticipant;
    u32 kartRank;
    u32 startMask;

    finishedMask = 0xf;
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        sortKeys[participant] = -1;
        participantOrder[participant] = participant;
        sync = g_GlobalAA;
        participantBit = 1 << participant;
        inMaskBit = sync->mParticipantMask & participantBit;
        if (inMaskBit != 0) {
            skipFlag = 0;
            if ((sync->mStartParticipantMask & participantBit) != 0) {
                skipFlag = inMaskBit == 0;
            }
            if (skipFlag != 0) {
                sortKeys[participant] =
                    sync->mEntries[participant].mLastProgressWord & WIFI_RACE_SYNC_PROGRESS_SORT_KEY_MASK;
            } else {
                if (participant == DWC_GetMyAID()) {
                    recordWord = PackOwnKartProgress();
                    participantFinishedMask = g_GlobalAA->mFinishedMask;
                } else {
                    recordWord = g_GlobalAA->mEntries[participant].mProgressWord;
                    participantFinishedMask = (u8) ((recordWord & WIFI_RACE_SYNC_PROGRESS_FINISHED_MASK) >>
                                                    WIFI_RACE_SYNC_PROGRESS_FINISHED_SHIFT);
                }
                finishedMask = finishedMask & participantFinishedMask;
                if (recordWord == 0 && IsAwardOrStaffRoll() == 0) {
                    if (g_GlobalRE->mKartOfParticipant[participant] != -1) {
                        recordWord =
                            (GetKartStartRank((u16) g_GlobalRE->mKartOfParticipant[participant]) - 1) |
                            WIFI_RACE_SYNC_PROGRESS_DROPPED;
                    }
                }
                if (recordWord != 0) {
                    if ((u8) ((recordWord & WIFI_RACE_SYNC_PROGRESS_RACING_MASK) >>
                              WIFI_RACE_SYNC_PROGRESS_RACING_SHIFT) == 0) {
                        g_GlobalAA->mFinishedMask = g_GlobalAA->mFinishedMask | participantBit;
                    }
                    g_GlobalAA->mEntries[participant].mLastProgressWord = recordWord;
                    sortKeys[participant] =
                        g_GlobalAA->mEntries[participant].mLastProgressWord & WIFI_RACE_SYNC_PROGRESS_SORT_KEY_MASK;
                }
            }
        }
    }
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        sync = g_GlobalAA;
        participantBit = 1 << participant;
        kart = *(u8 *) &g_GlobalRE->mKartOfParticipant[participant];
        entryRecord = sync->mEntries[participant].mLastProgressWord;
        inMaskBit = sync->mParticipantMask & participantBit;
        if (inMaskBit != 0) {
            skipFlag = 0;
            if ((sync->mStartParticipantMask & participantBit) != 0) {
                skipFlag = inMaskBit == 0;
            }
            if (skipFlag == 0 && (finishedMask & participantBit) != 0 && IsRacerFinishedRace(kart) == 0) {
                SetRaceProgressKartFinishRequest(kart, (entryRecord & WIFI_RACE_SYNC_PROGRESS_TIME_MASK) !=
                                                           WIFI_RACE_SYNC_PROGRESS_DID_NOT_FINISH);
            }
        }
    }
    for (insertIndex = 1; insertIndex < WIFI_RACE_SYNC_PARTICIPANT_COUNT; insertIndex++) {
        shiftIndex = insertIndex;
        key = sortKeys[insertIndex];
        movedParticipant = participantOrder[insertIndex];
        while (shiftIndex != 0 && sortKeys[shiftIndex - 1] > key) {
            sortKeys[shiftIndex] = sortKeys[shiftIndex - 1];
            participantOrder[shiftIndex] = participantOrder[shiftIndex - 1];
            shiftIndex--;
        }
        sortKeys[shiftIndex] = key;
        participantOrder[shiftIndex] = movedParticipant;
    }
    for (orderIndex = 0; orderIndex < WIFI_RACE_SYNC_PARTICIPANT_COUNT; orderIndex++) {
        participant = participantOrder[orderIndex];
        rank = 0;
        sync = g_GlobalAA;
        startMask = sync->mStartParticipantMask;
        if (BIT_IS_SET(startMask, participant)) {
            if ((u8) (((u32) sync->mEntries[participant].mLastProgressWord & WIFI_RACE_SYNC_PROGRESS_RACING_MASK) >>
                      WIFI_RACE_SYNC_PROGRESS_RACING_SHIFT) == 0) {
                rank = orderIndex + 1;
                for (earlierIndex = orderIndex; earlierIndex >= 0; earlierIndex--) {
                    if ((u8) (((u32) sync->mEntries[participantOrder[earlierIndex]].mLastProgressWord &
                               WIFI_RACE_SYNC_PROGRESS_RACING_MASK) >>
                              WIFI_RACE_SYNC_PROGRESS_RACING_SHIFT) != 0) {
                        rank = rank - 1;
                    }
                }
            } else {
                u16 ownKartIndex;

                ownKartIndex = g_GlobalRE->mKartOfParticipant[participant];
                kartRank = g_GlobalMV->mKarts[ownKartIndex].mRank;
                rank = kartRank;
                for (otherParticipant = 0; otherParticipant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; otherParticipant++) {
                    u32 isRacing;

                    if ((u8) (((u32) sync->mEntries[otherParticipant].mLastProgressWord &
                               WIFI_RACE_SYNC_PROGRESS_RACING_MASK) >>
                              WIFI_RACE_SYNC_PROGRESS_RACING_SHIFT) == 0) {
                        isRacing = 1;
                    } else {
                        isRacing = 0;
                    }
                    if (BIT_IS_SET(startMask, otherParticipant)) {
                        u16 otherKartIndex;
                        u32 otherRank;

                        otherKartIndex = g_GlobalRE->mKartOfParticipant[otherParticipant];
                        otherKartIndex = (u16) otherKartIndex;
                        otherRank = g_GlobalMV->mKarts[otherKartIndex].mRank;
                        if (g_GlobalMV->mKarts[otherKartIndex].mStatus != RACE_PROGRESS_KART_STATUS_REMOVED &&
                            isRacing != 0 && otherRank > kartRank) {
                            rank = rank + 1;
                        }
                    }
                }
            }
        }
        sync->mEntries[participant].mRank = rank;
    }
}

void E7FnList4_Fn9(void *stateObject) {
    u16 recordSize;
    u32 progressWord;
    WiFiRaceSync *sync;
    WiFiRaceSyncSendBuffer *sendBuffer;
    WiFiRaceSyncRecord *payload;

    UpdateItemDataSlots();
    UpdateSlotResultSyncs();
    sync = g_GlobalAA;
    sendBuffer = sync->mSendBuffer;
    payload = &sendBuffer->mRecord;
    recordSize = WIFI_RACE_SYNC_RECORD_SIZE - sync->mUnusedItemDataBytes;
    sendBuffer->mRecord.mSyncFrames = sync->mSyncFrames;
    payload->mHeaderBytes[3] = recordSize;
    if (g_GlobalRE->mKartOfParticipant[DWC_GetMyAID()] < 0) {
        payload->mProgressWord = 0;
    } else {
        progressWord = PackOwnKartProgress();
        payload->mProgressWord =
            progressWord | ((g_GlobalAA->mFinishedMask << WIFI_RACE_SYNC_PROGRESS_FINISHED_SHIFT) &
                            WIFI_RACE_SYNC_PROGRESS_FINISHED_MASK);
    }
    SendWiFiRaceSyncRecord(recordSize);
    UpdateWiFiRaceSyncRanks();
    if (IsRacerFinishedRace(*(u8 *) &g_GlobalRE->mKartOfParticipant[DWC_GetMyAID()]) == 0 &&
        (g_GlobalAA->mFlags & WIFI_RACE_SYNC_FLAG_IDLE_DISCONNECT_SENT) == 0) {
        if (g_GlobalCYT[GetSomeCYId_9()].mBits == 0) {
            g_GlobalAA->mIdleFrames = g_GlobalAA->mIdleFrames + 1;
            if (g_GlobalAA->mIdleFrames > WIFI_RACE_SYNC_IDLE_FRAMES) {
                g_GlobalAA->mFlags = g_GlobalAA->mFlags | WIFI_RACE_SYNC_FLAG_IDLE_DISCONNECT_SENT;
                SetWiFiDisconnectKind(WIFI_DISCONNECT_NO_INPUT);
            }
        } else {
            g_GlobalAA->mIdleFrames = 0;
        }
    }
    if (g_GlobalAA->mSharedState == WIFI_RACE_SHARED_STATE_RACING) {
        switch (GetChoisesSPickedValue()) {
            case CHOISES_S_PICK_NEXT:
            case CHOISES_S_PICK_NEXT_LAST:
                g_GlobalAA->mSharedState = WIFI_RACE_SHARED_STATE_PICKED_NEXT;
                sync = g_GlobalAA;
                sync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_AFTER_CHOICE;
                sync->mStateMachine.mNextStateRequested = 1;
                break;
            case CHOISES_S_PICK_QUIT:
                g_GlobalAA->mSharedState = WIFI_RACE_SHARED_STATE_PICKED_QUIT;
                sync = g_GlobalAA;
                sync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_AFTER_CHOICE;
                sync->mStateMachine.mNextStateRequested = 1;
                break;
        }
    }
}

void E7FnList4_Fn10(void *stateObject) {
    g_GlobalAA->mFlags &= ~WIFI_RACE_SYNC_FLAG_PEERS_SYNCED;
}

u32 GetWiFiRaceSyncPickedValue(void) {
    u32 result;
    WiFiRaceSync *wiFiRaceSync;

    wiFiRaceSync = g_GlobalAA;
    result = 0;
    if (wiFiRaceSync->mSharedState != WIFI_RACE_SHARED_STATE_PICKED_QUIT) {
        if (wiFiRaceSync->mSharedState != WIFI_RACE_SHARED_STATE_ALL_PEERS_PICKED) {
            return result;
        }
        if ((wiFiRaceSync->mFlags & WIFI_RACE_SYNC_FLAG_PEERS_SYNCED) != 0) {
            result = 2;
        }
        return result;
    }
    return 9;
}

void UpdateWiFiRaceSyncSharedState(void) {
    WiFiRaceSync *sync;
    u8 value;
    u8 allPeersPickedMask;
    u8 participant;
    enum { PARTICIPANT_BIT_NONE } participantBit;

    value = 0;
    allPeersPickedMask = 0;
    sync = g_GlobalAA;
    switch (sync->mSharedState) {
        case WIFI_RACE_SHARED_STATE_PICKED_QUIT:
        case WIFI_RACE_SHARED_STATE_PICKED_NEXT:
            for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
                participantBit = 1 << participant;
                if ((g_GlobalAA->mParticipantMask & participantBit) != 0 && participant != DWC_GetMyAID()) {
                    if (g_GlobalAA->mPeerSharedStates[participant] != WIFI_RACE_SHARED_STATE_PICKED_NEXT &&
                        g_GlobalAA->mPeerSharedStates[participant] != WIFI_RACE_SHARED_STATE_ALL_PEERS_PICKED) {
                        value = value | participantBit;
                    }
                }
            }
            if (value == 0) {
                g_GlobalAA->mSharedState = WIFI_RACE_SHARED_STATE_ALL_PEERS_PICKED;
            }
            break;
        case WIFI_RACE_SHARED_STATE_ALL_PEERS_PICKED:
            for (value = 0; value < WIFI_RACE_SYNC_PARTICIPANT_COUNT; value++) {
                participantBit = 1 << value;
                if ((sync->mParticipantMask & participantBit) != 0 &&
                    sync->mPeerSharedStates[value] == WIFI_RACE_SHARED_STATE_ALL_PEERS_PICKED) {
                    allPeersPickedMask = allPeersPickedMask | participantBit;
                }
            }
            if ((sync->mParticipantMask & ~allPeersPickedMask) == 0) {
                sync->mFlags = sync->mFlags | WIFI_RACE_SYNC_FLAG_PEERS_SYNCED;
            }
            if ((g_GlobalAA->mParticipantMask | ~allPeersPickedMask) != 0) {
                g_GlobalAA->mFlags = g_GlobalAA->mFlags | WIFI_RACE_SYNC_FLAG_PEERS_SYNCED;
            }
            break;
    }
    if ((g_GlobalAA->mParticipantMask & ~allPeersPickedMask) == 0) {
        g_GlobalAA->mSharedState = WIFI_RACE_SHARED_STATE_ALL_PEERS_PICKED;
    }
}

void E7FnList4_Fn11(void *stateObject) {
    u16 recordSize;
    WiFiRaceSync *sync;
    WiFiRaceSyncSendBuffer *sendBuffer;
    WiFiRaceSyncRecord *payload;
    s32 progressWord;

    UpdateItemDataSlots();
    UpdateSlotResultSyncs();
    sync = g_GlobalAA;
    sendBuffer = sync->mSendBuffer;
    payload = &sendBuffer->mRecord;
    recordSize = WIFI_RACE_SYNC_RECORD_SIZE - sync->mUnusedItemDataBytes;
    sendBuffer->mRecord.mSyncFrames = sync->mSyncFrames;
    payload->mHeaderBytes[3] = recordSize;
    if (g_GlobalRE->mKartOfParticipant[DWC_GetMyAID()] < 0) {
        payload->mProgressWord = 0;
    } else {
        progressWord = PackOwnKartProgress();
        payload->mProgressWord =
            progressWord | ((g_GlobalAA->mFinishedMask << WIFI_RACE_SYNC_PROGRESS_FINISHED_SHIFT) &
                            WIFI_RACE_SYNC_PROGRESS_FINISHED_MASK);
    }
    SendWiFiRaceSyncRecord(recordSize);
    UpdateWiFiRaceSyncRanks();
    UpdateWiFiRaceSyncSharedState();
}

WiFiRaceSyncEntry *GetParticipantEntryAtSyncFrames(s32 participant, u32 syncFrames) {
    WiFiRaceSyncEntry *entry;

    entry = &g_GlobalAA->mEntries[participant];
    if (syncFrames != entry->mSyncFrames) {
        return NULL;
    }
    return entry;
}

s32 GetParticipantSyncFrames(s32 participant) {
    return g_GlobalAA->mEntries[participant].mSyncFrames;
}

void AddWiFiRaceSyncRoundTrip(const u64 *ticks, s32 participant) {
    u8 sampleCount;
    u64 roundTrip;
    WiFiRaceSync *sync;
    BOOL accepted;

    sync = g_GlobalAA;
    sampleCount = sync->mPeers[participant].mSampleCount;
    if (sampleCount >= WIFI_RACE_SYNC_SAMPLE_COUNT) {
        return;
    }
    if (sampleCount != 0) {
        roundTrip = (ticks[3] - ticks[0]) - (ticks[2] - ticks[1]);
        if (roundTrip * 64 / 0x82ea < 1000) {
            sync->mPeers[participant].mRoundTripTotal += roundTrip;
            accepted = TRUE;
        } else {
            accepted = FALSE;
            g_GlobalAA->mPeers[participant].mRejectedSampleCount++;
            if (g_GlobalAA->mPeers[participant].mRejectedSampleCount > WIFI_RACE_SYNC_MAX_REJECTED_SAMPLES) {
                BIT_SET(g_GlobalAA->mDroppedParticipantMask, participant);
            }
        }
    } else {
        accepted = TRUE;
    }
    if (accepted != FALSE) {
        sampleCount = sampleCount + 1;
    }
    g_GlobalAA->mPeers[participant].mSampleCount = sampleCount;
}

void ReceiveWiFiRaceSyncRecord(u32 fromIndex, WiFiRaceSyncPacket *packet, u32 size) {
    WiFiRaceSync *sync;
    WiFiRaceSyncEntry *entry;
    u8 *bodyBytes;
    u32 packetFrames;
    u32 participant;
    u8 recordSize;
    u32 entryFrames;

    participant = packet->mSender;
    sync = g_GlobalAA;
    bodyBytes = packet->mBody.mHeaderBytes;
    packetFrames = packet->mBody.mSyncFrames;
    entryFrames = sync->mEntries[participant].mSyncFrames;
    entry = &sync->mEntries[participant];
    recordSize = bodyBytes[3];
    if (sync->mStateMachine.mState != WIFI_RACE_SYNC_STATE_RACE &&
        sync->mStateMachine.mState != WIFI_RACE_SYNC_STATE_AFTER_CHOICE) {
        return;
    }
    if (entryFrames != 0 && entryFrames >= packetFrames) {
        return;
    }
    if (sync->mEntries[participant].mRecordReceived == 0) {
        sync->mEntries[participant].mRecordReceived = 1;
    }
    Mem_CpuCopy8(bodyBytes, entry, recordSize);
}

void ReceiveWiFiRaceSyncCountdown(u32 fromIndex, WiFiRaceSyncPacket *packet, u32 size) {
    s32 smoothed;
    WiFiRaceSync *sync;
    s16 senderCountdown;
    s16 ownCountdown;
    s16 difference;
    u32 participantBit;

    senderCountdown = packet->mBody.mCountdown;
    sync = g_GlobalAA;
    ownCountdown = sync->mCountdownTimer;
    if (sync->mStateMachine.mState == WIFI_RACE_SYNC_STATE_READY) {
        participantBit = 1 << packet->mSender;
        if ((sync->mReadyMask & participantBit) == 0) {
            sync->mReadyMask |= participantBit;
        }
        return;
    }
    if (ownCountdown < 0) {
        return;
    }
    difference = senderCountdown - ownCountdown;
    if (difference > 0) {
        difference = (difference + 1) >> 1;
    } else if (difference < 0) {
        difference = (difference - 1) >> 1;
    }
    smoothed = (difference << 11) + (g_GlobalAA->mCountdownDrift >> 1);
    g_GlobalAA->mCountdownDrift = smoothed;
    g_GlobalAA->mCountdownTimer += (s16) FROM_FIXED12(smoothed + 0x800);
}

void ReceiveWiFiRaceSyncPacket(u32 fromIndex, WiFiRaceSyncPacket *packet, u32 size, u32 unusedFourth) {
    u32 participant;
    WiFiRaceSync *sync;
    WiFiRaceSyncPacketBody *body;
    WiFiRaceSyncPeer *peer;
    u32 sender;
    u64 tick;
    u8 ownParticipant;

    sync = g_GlobalAA;
    if (sync == NULL) {
        return;
    }
    participant = packet->mSender;
    if ((sync->mParticipantMask & (1 << participant)) == 0) {
        return;
    }
    sync->mTimeoutFrames[participant] = 0;
    g_GlobalAA->mPeerDroppedMasks[packet->mSender] = packet->mDroppedParticipantMask;
    g_GlobalAA->mPeerSharedStates[packet->mSender] = packet->mSharedState;
    switch (((volatile WiFiRaceSyncPacket *) packet)->mKind) {
        case WIFI_RACE_SYNC_PACKET_PROBE:
            body = &packet->mBody;
            sender = packet->mSender;
            ownParticipant = DWC_GetMyAID();
            if (body->mProbeOrigin == ownParticipant) {
                body->mProbeTicks[3] = Os_GetTick();
                AddWiFiRaceSyncRoundTrip(body->mProbeTicks, sender);
                return;
            }
            if (body->mProbeOrigin >= WIFI_RACE_SYNC_PARTICIPANT_COUNT) {
                return;
            }
            peer = &g_GlobalAA->mPeers[sender];
            Mem_CpuCopy8(body, peer, WIFI_RACE_SYNC_PROBE_SIZE);
            tick = Os_GetTick();
            peer->mProbeReceivedTickLow = tick;
            peer->mProbeReceivedTickHigh = tick >> 32;
            g_GlobalAA->mPeers[sender].mProbePending = TRUE;
            break;
        case WIFI_RACE_SYNC_PACKET_READY:
            g_GlobalAA->mReadyMask = g_GlobalAA->mReadyMask | (1 << packet->mSender);
            break;
        case WIFI_RACE_SYNC_PACKET_COUNTDOWN:
            ReceiveWiFiRaceSyncCountdown(fromIndex, packet, size);
            break;
        case WIFI_RACE_SYNC_PACKET_RECORD:
            ReceiveWiFiRaceSyncRecord(fromIndex, packet, size);
            break;
// Kinds 4 and 5 have no body; only kind 5 is sent (state 1, once a peer has 12 samples), nothing sends
// kind 4.
        case WIFI_RACE_SYNC_PACKET_UNSENT:
        case WIFI_RACE_SYNC_PACKET_EMPTY:
            break;
    }
}

void UpdateParticipantElos(void) {
    s16 elos[4];
    s16 newElos[4];
    s32 eloChange;
    u8 participant;
    u8 otherParticipant;
    u8 rankedNotWorse;
    u8 row;
    s32 kart;
    s8 otherKart;
    u32 kartRank;
    u32 otherKartRank;
    s16 eloDifference;

    for (participant = 0; participant < 4; participant++) {
        if (g_GlobalRE->mKartOfParticipant[participant] == -1) {
            elos[participant] = 5000;
        } else {
            elos[participant] = GetTKSomeSize(participant);
        }
    }
    for (participant = 0; participant < 4; participant++) {
        kart = g_GlobalRE->mKartOfParticipant[participant];
        if (kart == -1) {
            continue;
        }
        newElos[participant] = elos[participant];
        for (otherParticipant = 0; otherParticipant < 4; otherParticipant++) {
            rankedNotWorse = 1;
            otherKart = g_GlobalRE->mKartOfParticipant[otherParticipant];
            if (otherKart == -1 || kart == otherKart) {
                continue;
            }
            kartRank = GetSomeRacerFlags((u16) kart);
            otherKartRank = GetSomeRacerFlags((u16) otherKart);
            if (kartRank > otherKartRank) {
                rankedNotWorse = 0;
            }
            eloDifference = elos[otherParticipant] - elos[participant];
            for (row = 0; row < 9; row++) {
                if (eloDifference > gEloChangeTable[row].mDifferenceAbove) {
                    if (rankedNotWorse != 0) {
                        eloChange = gEloChangeTable[row].mWinChange;
                    } else {
                        eloChange = gEloChangeTable[row].mLossChange;
                    }
                    break;
                }
            }
            newElos[participant] += eloChange;
            if (newElos[participant] < 0) {
                newElos[participant] = 0;
                continue;
            }
            if (newElos[participant] > 10000) {
                newElos[participant] = 10000;
            }
        }
        SetTKSomeSize(participant, newElos[participant]);
    }
}

// Marks a peer dropped after 300 silent calls (600 before its first sample); a peer every live peer also reports
// dropped is removed with its kart. With one participant or none left, lowers a backup counter by the other kart count
// (session state non-zero) and calls SetWiFiDisconnectKind(2).
void RemoveDroppedParticipants(void) {
    u8 participant;
    u32 agreedDroppedMask;
    u32 participantBit;
    u32 timeoutLimit;
    u8 peerMask;
    u16 sessionState;
    u32 firstBlockCount;
    BackupFirstBlock *firstBlock;

    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        participantBit = 1 << participant;
        if ((g_GlobalAA->mParticipantMask & participantBit) != 0 && participant != DWC_GetMyAID() &&
            (g_GlobalAA->mDroppedParticipantMask & participantBit) == 0) {
            timeoutLimit = WIFI_RACE_SYNC_TIMEOUT_FRAMES;
            if (g_GlobalAA->mPeers[participant].mSampleCount == 0) {
                timeoutLimit = WIFI_RACE_SYNC_FIRST_TIMEOUT_FRAMES;
            }
            g_GlobalAA->mTimeoutFrames[participant]++;
            if (g_GlobalAA->mTimeoutFrames[participant] > timeoutLimit) {
                g_GlobalAA->mDroppedParticipantMask |= participantBit;
            }
        }
    }
    agreedDroppedMask = g_GlobalAA->mDroppedParticipantMask;
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        if (BIT_IS_SET(g_GlobalAA->mParticipantMask, participant)) {
            if (participant != DWC_GetMyAID()) {
                if ((g_GlobalAA->mDroppedParticipantMask & (1 << participant)) == 0) {
                    peerMask = g_GlobalAA->mPeerDroppedMasks[participant] | (1u << participant);
                    agreedDroppedMask = agreedDroppedMask & peerMask;
                }
            }
        }
    }
    if (agreedDroppedMask == 0) {
        return;
    }
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        participantBit = 1 << participant;
        if ((agreedDroppedMask & participantBit) != 0 && (g_GlobalAA->mParticipantMask & participantBit) != 0 &&
            g_GlobalRE->mKartOfParticipant[participant] != -1) {
            RemoveRaceProgressKart(g_GlobalRE->mKartOfParticipant[participant]);
            g_GlobalAA->mParticipantMask = g_GlobalAA->mParticipantMask & ~participantBit;
        }
    }
    if (Math_CountPopulation(g_GlobalAA->mParticipantMask) > 1) {
        return;
    }
    sessionState = g_GlobalB->mStateMachine.mState;
    firstBlock = g_SaveDataHolder->mFirstBlock;
    firstBlockCount = firstBlock->mTotals[5];
    if (sessionState != WIFI_SESSION_STATE_OFF) {
        s8 otherKartCount = g_GlobalB->mKartCountCopy - 1;
        if (otherKartCount > 0) {
            if (firstBlockCount < otherKartCount) {
                firstBlockCount = 0;
            } else {
                firstBlockCount = firstBlockCount - otherKartCount;
            }
        }
        firstBlock->mTotals[5] = firstBlockCount;
        WriteSaveDataSectionHeaderToSaveData_from_thumb();
        WaitForWorkerTask();
        if (g_SaveDataIoManager->mBackupEnabled != 0) {
            j_WaitForPendingCardOperation();
        }
    }
    SetWiFiDisconnectKind(WIFI_DISCONNECT_OPPONENT_LEFT);
}

void GlobalB_E7Fn_5BImpl(void) {
    if ((g_GlobalAA->mFlags & WIFI_RACE_SYNC_FLAG_REMOVE_DROPPED) != 0) {
        RemoveDroppedParticipants();
    }
    StateDualHandler_Execute(&g_GlobalAA->mStateMachine);
}
