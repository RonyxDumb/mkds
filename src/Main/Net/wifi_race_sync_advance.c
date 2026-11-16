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
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Race/race_progress_rank.h"
#include "Main/Race/kart.h"
#include "Main/Race/race_clock.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const EloChangeRow gEloChangeTable[9] = {{0x3e8, 8, 0}, {0x1f4, 7, -1}, {0xfa, 6, -2},  {0x64, 5, -3},  {-100, 4, -4},
                                         {-250, 3, -5}, {-500, 2, -6},  {-1000, 1, -7}, {-30000, 0, -8}};
StateCallbacks gWiFiRaceSyncStateTable[WIFI_RACE_SYNC_STATE_COUNT] = {
    {NULL, NULL},
    {EnterWiFiRaceSyncProbe, UpdateWiFiRaceSyncProbe},
    {EnterWiFiRaceSyncReady, UpdateWiFiRaceSyncReady},
    {EnterWiFiRaceSyncCountdown, UpdateWiFiRaceSyncCountdown},
    {EnterWiFiRaceSyncRace, UpdateWiFiRaceSyncRace},
    {EnterWiFiRaceSyncAfterChoice, UpdateWiFiRaceSyncAfterChoice}};

void ResetParticipantKartMap(void) {
    s32 index;

    for (index = 0; index < 4; index++) {
        gParticipantKartMap->mParticipantOfKart[index] = -1;
        gParticipantKartMap->mKartOfParticipant[index] = -1;
    }
    gParticipantKartMap->mUnk_05 = 0;
}

void SetParticipantKartMapFromMask(u32 participantMask) {
    u8 participant;
    u8 kart;

    for (participant = 0, kart = 0; participant < 4; participant++) {
        gParticipantKartMap->mKartOfParticipant[participant] = -1;
        if (BIT_IS_SET(participantMask, participant)) {
            gParticipantKartMap->mParticipantOfKart[kart] = participant;
            gParticipantKartMap->mKartOfParticipant[participant] = kart;
            kart++;
        }
    }
    gParticipantKartMap->mParticipantMask = participantMask;
    while (kart < 4) {
        gParticipantKartMap->mParticipantOfKart[kart] = -1;
        kart++;
    }
}

static inline BOOL ReplyToWiFiRaceSyncProbe(void) {
    u8 participant;
    WiFiRaceSync *sync;
    WiFiRaceSyncRecord *payload;

    sync = gWiFiRaceSync;
    payload = &sync->mSendBuffer->mRecord;
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        if (sync->mPeers[participant].mProbePending != FALSE) {
            MI_CpuCopy8(&sync->mPeers[participant], payload, WIFI_RACE_SYNC_PROBE_SIZE);
            *(u64 *) &payload->mProbeWords[3] = OS_GetTick();
            if (SendWiFiRaceSyncPacket(participant, WIFI_RACE_SYNC_PACKET_PROBE, WIFI_RACE_SYNC_PROBE_SIZE) != 0) {
                gWiFiRaceSync->mPeers[participant].mProbePending = FALSE;
            } else {
                MI_CpuFill8(payload, 0, WIFI_RACE_SYNC_PROBE_SIZE);
            }
            return TRUE;
        }
    }
    return FALSE;
}

void InitWiFiRaceSync(void *heap) {
    s32 slotIndex;
    s32 index;
    u8 participantIndexOrMask;
    s32 entryIndex;
    u8 participant;
    WiFiRaceSync *sync;

    if (gRaceSetup->mMode != MODE_WIFI) {
        return;
    }
    gWiFiRaceSync = HeapAlloc(heap, sizeof(*gWiFiRaceSync));
    gWiFiRaceSync->mSendBuffer = HeapAllocAligned(heap, WIFI_RACE_SYNC_SEND_BUFFER_SIZE, HEAP_ALIGN_CACHE_LINE);
    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        gWiFiRaceSync->mItemDataSlots[slotIndex].mData = HeapAllocAligned(heap, ITEM_DATA_SLOT_BUFFER_SIZE, 32);
        for (index = 0; index < WIFI_RACE_SYNC_PARTICIPANT_COUNT; index++) {
            gWiFiRaceSync->mReceivedItemDataSlots[slotIndex][index].mData =
                HeapAllocAligned(heap, ITEM_DATA_SLOT_BUFFER_SIZE, 32);
        }
    }
    gWiFiRaceSync->mStartParticipantMask = gParticipantKartMap->mParticipantMask;
    MI_CpuFill8(gWiFiRaceSync->mSendBuffer, 0, WIFI_RACE_SYNC_SEND_BUFFER_SIZE);
    for (entryIndex = 0; entryIndex < WIFI_RACE_SYNC_PARTICIPANT_COUNT; entryIndex++) {
        // Clears the record part of the entry.
        MI_CpuFill8(&gWiFiRaceSync->mEntries[entryIndex], 0, WIFI_RACE_SYNC_RECORD_SIZE);
        gWiFiRaceSync->mEntries[entryIndex].mRecordReceived = 0;
    }
    participantIndexOrMask = gWiFiRaceSync->mStartParticipantMask;
    gWiFiRaceSync->mDroppedParticipantMask = 0;
    gWiFiRaceSync->mParticipantMask = participantIndexOrMask;
    for (participantIndexOrMask = 0; participantIndexOrMask < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participantIndexOrMask++) {
        gWiFiRaceSync->mPeerDroppedMasks[participantIndexOrMask] = 0;
        gWiFiRaceSync->mTimeoutFrames[participantIndexOrMask] = 0;
    }
    ResetItemDataSlots();
    InitSlotResultSyncStates();
    gWiFiRaceSync->mFlags |= WIFI_RACE_SYNC_FLAG_RESET_UNREAD_A;
    gWiFiRaceSync->mFlags |= WIFI_RACE_SYNC_FLAG_RESET_UNREAD_B;
    sync = gWiFiRaceSync;
    sync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_IDLE;
    sync->mStateMachine.mNextStateRequested = 1;
    gWiFiRaceSync->mSharedState = WIFI_RACE_SHARED_STATE_IDLE;
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        index = gParticipantKartMap->mKartOfParticipant[participant];
        gWiFiRaceSync->mEntries[participant].mLastProgressWord = 0;
        if (index >= 0) {
            gWiFiRaceSync->mEntries[participant].mRank = GetKartStartRank((u8) index);
        } else {
            gWiFiRaceSync->mEntries[participant].mRank = 0;
        }
    }
    InitStateMachine(&gWiFiRaceSync->mStateMachine, gWiFiRaceSyncStateTable, WIFI_RACE_SYNC_STATE_COUNT, NULL);
}

void AdvanceWiFiRaceSyncFrames(void) {
    WiFiRaceSync *sync;

    sync = gWiFiRaceSync;
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

void EnterWiFiRaceSyncProbe(void *stateObject) {
    u8 participant;
    s32 *tickWords;
    WiFiRaceSync *sync;

    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        tickWords = &gWiFiRaceSync->mPeers[participant].mProbeSentTickLow;
        tickWords[0] = 0;
        tickWords[1] = 0;
        tickWords[2] = 0;
        tickWords[3] = 0;
        tickWords[4] = 0;
        tickWords[5] = 0;
        tickWords[6] = 0;
        tickWords[7] = 0;
        tickWords[8] = 0;
        sync = gWiFiRaceSync;
        sync->mPeers[participant].mRoundTripTotal = 0;
        sync->mPeers[participant].mSampleCount = 0;
        gWiFiRaceSync->mPeers[participant].mRejectedSampleCount = 0;
        gWiFiRaceSync->mPeers[participant].mEmptyPacketPhase = 0;
    }
    gWiFiRaceSync->mSendParticipantIndex = 0;
    gWiFiRaceSync->mSampledMask = 0;
    gWiFiRaceSync->mUnk_0fd = 0;
    gWiFiRaceSync->mCountdownSmoothedDifference = 0;
    gWiFiRaceSync->mCountdownTimer = WIFI_RACE_SYNC_PRE_COUNTDOWN_TIME;
    gWiFiRaceSync->mSharedState = WIFI_RACE_SHARED_STATE_BEFORE_RACE;
    gWiFiRaceSync->mFlags &= ~WIFI_RACE_SYNC_FLAG_IN_RACE;
    gWiFiRaceSync->mFlags |= WIFI_RACE_SYNC_FLAG_REMOVE_DROPPED;
    gWiFiRaceSync->mFlags &= ~WIFI_RACE_SYNC_FLAG_DATA_SHARING_INCOMPLETE;
}

void UpdateWiFiRaceSyncProbe(void *stateObject) {
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
            gWiFiRaceSync->mPeers[participant].mSampleCount >= WIFI_RACE_SYNC_SAMPLE_COUNT) {
            mask = mask | (1 << participant);
        }
    }
    sync = gWiFiRaceSync;
    if (sync->mParticipantMask == (sync->mParticipantMask & mask)) {
        sync->mSampledMask = mask;
        sync = gWiFiRaceSync;
        sync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_READY;
        sync->mStateMachine.mNextStateRequested = 1;
    }
    if (ReplyToWiFiRaceSyncProbe() != FALSE) {
        return;
    }
    sync = gWiFiRaceSync;
    sendParticipantIndex = sync->mSendParticipantIndex;
    if (sendParticipantIndex < WIFI_RACE_SYNC_PARTICIPANT_COUNT) {
        targetParticipant = sendParticipantIndex;
        if (BIT_IS_SET(sync->mParticipantMask, targetParticipant) && targetParticipant != DWC_GetMyAID()) {
            sync = gWiFiRaceSync;
            if (sync->mPeers[targetParticipant].mSampleCount < WIFI_RACE_SYNC_SAMPLE_COUNT) {
                sendBuffer = sync->mSendBuffer;
                payload = &sendBuffer->mRecord;
                sendBuffer->mRecord.mLeadHalfword = DWC_GetMyAID();
                *(u64 *) &payload->mProgressWord = OS_GetTick();
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
                gWiFiRaceSync->mPeers[targetParticipant].mEmptyPacketPhase++;
                if (gWiFiRaceSync->mPeers[targetParticipant].mEmptyPacketPhase > WIFI_RACE_SYNC_EMPTY_PHASE_LAST) {
                    gWiFiRaceSync->mPeers[targetParticipant].mEmptyPacketPhase = 0;
                }
            }
        }
        gWiFiRaceSync->mSendParticipantIndex++;
    } else {
        sync->mSendParticipantIndex = 0;
    }
}

void EnterWiFiRaceSyncReady(void *stateObject) {
    s32 participant;
    WiFiRaceSync *sync;
    u8 sampleCount;
    u64 roundTripTotal;

    gWiFiRaceSync->mReadyMask = 1 << DWC_GetMyAID();
    gWiFiRaceSync->mCountdownTimer = WIFI_RACE_SYNC_PRE_COUNTDOWN_TIME;
    gWiFiRaceSync->mSendParticipantIndex = 0;
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        sync = gWiFiRaceSync;
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
        if (participant != DWC_GetMyAID() && (gWiFiRaceSync->mParticipantMask & (1 << (u8) participant)) != 0) {
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
    if (gWiFiRaceSync->mParticipantMask & (1 << index)) {
        if (SendWiFiRaceSyncPacket(index, WIFI_RACE_SYNC_PACKET_READY, 8) != 0) {
            gWiFiRaceSync->mSendParticipantIndex = index;
        }
    }
}

void UpdateWiFiRaceSyncReady(void *stateObject) {
    WiFiRaceSync *sync;
    u8 participant;
    WiFiRaceSyncRecord *payload;

    sync = gWiFiRaceSync;
    payload = &sync->mSendBuffer->mRecord;
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        if (sync->mPeers[participant].mProbePending != FALSE) {
            MI_CpuCopy8(&sync->mPeers[participant], payload, WIFI_RACE_SYNC_PROBE_SIZE);
            *(u64 *) &payload->mProbeWords[3] = OS_GetTick();
            if (SendWiFiRaceSyncPacket(participant, WIFI_RACE_SYNC_PACKET_PROBE, WIFI_RACE_SYNC_PROBE_SIZE) != 0) {
                gWiFiRaceSync->mPeers[participant].mProbePending = FALSE;
            } else {
                MI_CpuFill8(payload, 0, WIFI_RACE_SYNC_PROBE_SIZE);
            }
            break;
        }
    }
    sync = gWiFiRaceSync;
    if (sync->mParticipantMask == (sync->mParticipantMask & sync->mReadyMask)) {
        sync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_COUNTDOWN;
        sync->mStateMachine.mNextStateRequested = 1;
        return;
    }
    CallWithNextWiFiRaceSyncParticipant(sync->mSendParticipantIndex, SendWiFiRaceSyncReady);
}

void EnterWiFiRaceSyncCountdown(void *stateObject) {
    gWiFiRaceSync->mCountdownTimer = WIFI_RACE_SYNC_COUNTDOWN_TIME;
    gWiFiRaceSync->mCountdownSendParticipantIndex = 0;
}

void SendWiFiRaceSyncCountdown(u32 participant) {
    WiFiRaceSyncSendBuffer *sendBuffer;
    WiFiRaceSyncRecord *payload;

    sendBuffer = gWiFiRaceSync->mSendBuffer;
    payload = &sendBuffer->mRecord;
    payload->mLeadHalfword = gWiFiRaceSync->mCountdownTimer - gWiFiRaceSync->mEntries[participant].mRoundTripAverage;
    payload->mCountdownBytes[0] = gWiFiRaceSync->mSampledMask;
    if (SendWiFiRaceSyncPacket(participant, WIFI_RACE_SYNC_PACKET_COUNTDOWN, 8) != 0) {
        gWiFiRaceSync->mCountdownSendParticipantIndex = participant;
    }
}

void UpdateWiFiRaceSyncCountdown(void *stateObject) {
    WiFiRaceSync *sync;

    gWiFiRaceSync->mCountdownTimer = gWiFiRaceSync->mCountdownTimer - 1;
    if (gWiFiRaceSync->mCountdownTimer <= 0) {
        gWiFiRaceSync->mCountdownTimer = -1;
        sync = gWiFiRaceSync;
        sync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_RACE;
        sync->mStateMachine.mNextStateRequested = 1;
        return;
    }
    CallWithNextWiFiRaceSyncParticipant(gWiFiRaceSync->mCountdownSendParticipantIndex, SendWiFiRaceSyncCountdown);
}

void EnterWiFiRaceSyncRace(void *stateObject) {
    u8 participant;

    gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags | WIFI_RACE_SYNC_FLAG_IN_RACE;
    gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags & ~WIFI_RACE_SYNC_FLAG_CLEARED_UNREAD;
    gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags & ~WIFI_RACE_SYNC_FLAG_IDLE_DISCONNECT_SENT;
    gWiFiRaceSync->mSyncFrames = 0;
    gWiFiRaceSync->mRecordSendCursor = 0;
    gWiFiRaceSync->mUnk_73d = 0;
    gWiFiRaceSync->mUnk_73b = 0;
    gWiFiRaceSync->mFinishedMask = 0;
    gWiFiRaceSync->mFinishRecorded = FALSE;
    gWiFiRaceSync->mIdleFrames = 0;
    gWiFiRaceSync->mSharedState = WIFI_RACE_SHARED_STATE_RACING;
    MI_CpuFill8(gWiFiRaceSync->mSendBuffer, 0, WIFI_RACE_SYNC_SEND_BUFFER_SIZE);
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        if (BIT_IS_SET(gWiFiRaceSync->mStartParticipantMask, participant) &&
            (gWiFiRaceSync->mParticipantMask & (1 << participant)) == 0) {
            if (gParticipantKartMap->mKartOfParticipant[participant] >= 0) {
                gWiFiRaceSync->mEntries[participant].mLastProgressWord =
                    (GetKartStartRank((u8) gParticipantKartMap->mKartOfParticipant[participant]) - 1) |
                    WIFI_RACE_SYNC_PROGRESS_DROPPED;
            }
        }
    }
}

int SendWiFiRaceSyncPacket(u8 participant, u32 kind, int dataSize) {
    WiFiRaceSyncPacket *packet;
    int result;

    result = 1;
    if ((gWiFiRaceSync->mFlags & WIFI_RACE_SYNC_FLAG_SENDING) != 0) {
        return 0;
    }
    if (participant != DWC_GetMyAID()) {
        result = dataSize + 4;
        packet = &gWiFiRaceSync->mSendBuffer->mPacket;
        gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags | WIFI_RACE_SYNC_FLAG_SENDING;
        packet->mSender = DWC_GetMyAID();
        packet->mTarget = participant;
        packet->mKind = kind;
        packet->mSharedState = gWiFiRaceSync->mSharedState;
        packet->mDroppedParticipantMask = gWiFiRaceSync->mDroppedParticipantMask;
        DC_StoreRange(packet, result);
        result = SendWiFiPacketToParticipant(participant, packet, result, FinishWiFiRaceSyncSend);
        if (result == 0) {
            gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags & ~WIFI_RACE_SYNC_FLAG_SENDING;
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
    sendCursor = gWiFiRaceSync->mRecordSendCursor;
    if ((sendCursor & 1) == 0) {
        gWiFiRaceSync->mRecordSendCursor = sendCursor + 1;
        return;
    }
    participant = sendCursor >> 1;
    lastParticipant = participant - 1;
    if (lastParticipant < 0) {
        lastParticipant = lastParticipant + 4;
    }
    while (sentCount < 1 && participant != lastParticipant) {
        if (participant != DWC_GetMyAID() && BIT_IS_SET(gWiFiRaceSync->mParticipantMask, participant)) {
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
    gWiFiRaceSync->mRecordSendCursor = participant << 1;
}

void UpdateWiFiRaceSyncRanks(void) {
    u32 sortKeys[4];
    u8 participantOrder[4];
    u8 participant;
    u8 orderIndex;
    u8 insertIndex;
    u8 shiftIndex;
    s16 earlierIndex;
    u32 agreedFinishedMask;
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

    agreedFinishedMask = 0xf;
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        sortKeys[participant] = -1;
        participantOrder[participant] = participant;
        sync = gWiFiRaceSync;
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
                    participantFinishedMask = gWiFiRaceSync->mFinishedMask;
                } else {
                    recordWord = gWiFiRaceSync->mEntries[participant].mProgressWord;
                    participantFinishedMask = (u8) ((recordWord & WIFI_RACE_SYNC_PROGRESS_FINISHED_MASK) >>
                                                    WIFI_RACE_SYNC_PROGRESS_FINISHED_SHIFT);
                }
                agreedFinishedMask = agreedFinishedMask & participantFinishedMask;
                if (recordWord == 0 && IsRaceStarted() == 0) {
                    if (gParticipantKartMap->mKartOfParticipant[participant] != -1) {
                        recordWord =
                            (GetKartStartRank((u16) gParticipantKartMap->mKartOfParticipant[participant]) - 1) |
                            WIFI_RACE_SYNC_PROGRESS_DROPPED;
                    }
                }
                if (recordWord != 0) {
                    if ((u8) ((recordWord & WIFI_RACE_SYNC_PROGRESS_RACING_MASK) >>
                              WIFI_RACE_SYNC_PROGRESS_RACING_SHIFT) == 0) {
                        gWiFiRaceSync->mFinishedMask = gWiFiRaceSync->mFinishedMask | participantBit;
                    }
                    gWiFiRaceSync->mEntries[participant].mLastProgressWord = recordWord;
                    sortKeys[participant] =
                        gWiFiRaceSync->mEntries[participant].mLastProgressWord & WIFI_RACE_SYNC_PROGRESS_SORT_KEY_MASK;
                }
            }
        }
    }
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        sync = gWiFiRaceSync;
        participantBit = 1 << participant;
        kart = *(u8 *) &gParticipantKartMap->mKartOfParticipant[participant];
        entryRecord = sync->mEntries[participant].mLastProgressWord;
        inMaskBit = sync->mParticipantMask & participantBit;
        if (inMaskBit != 0) {
            skipFlag = 0;
            if ((sync->mStartParticipantMask & participantBit) != 0) {
                skipFlag = inMaskBit == 0;
            }
            if (skipFlag == 0 && (agreedFinishedMask & participantBit) != 0 && IsKartEnded(kart) == 0) {
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
        sync = gWiFiRaceSync;
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
                u16 participantKartIndex;

                participantKartIndex = gParticipantKartMap->mKartOfParticipant[participant];
                kartRank = gRaceProgress->mKarts[participantKartIndex].mRank;
                rank = kartRank;
                for (otherParticipant = 0; otherParticipant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; otherParticipant++) {
                    u32 otherFinished;

                    if ((u8) (((u32) sync->mEntries[otherParticipant].mLastProgressWord &
                               WIFI_RACE_SYNC_PROGRESS_RACING_MASK) >>
                              WIFI_RACE_SYNC_PROGRESS_RACING_SHIFT) == 0) {
                        otherFinished = 1;
                    } else {
                        otherFinished = 0;
                    }
                    if (BIT_IS_SET(startMask, otherParticipant)) {
                        u16 otherKartIndex;
                        u32 otherRank;

                        otherKartIndex = gParticipantKartMap->mKartOfParticipant[otherParticipant];
                        otherKartIndex = (u16) otherKartIndex;
                        otherRank = gRaceProgress->mKarts[otherKartIndex].mRank;
                        if (gRaceProgress->mKarts[otherKartIndex].mStatus != RACE_PROGRESS_KART_STATUS_REMOVED &&
                            otherFinished != 0 && otherRank > kartRank) {
                            rank = rank + 1;
                        }
                    }
                }
            }
        }
        sync->mEntries[participant].mRank = rank;
    }
}

void UpdateWiFiRaceSyncRace(void *stateObject) {
    u16 recordSize;
    u32 progressWord;
    WiFiRaceSync *sync;
    WiFiRaceSyncSendBuffer *sendBuffer;
    WiFiRaceSyncRecord *payload;

    UpdateItemDataSlots();
    UpdateSlotResultSyncs();
    sync = gWiFiRaceSync;
    sendBuffer = sync->mSendBuffer;
    payload = &sendBuffer->mRecord;
    recordSize = WIFI_RACE_SYNC_RECORD_SIZE - sync->mUnusedItemDataBytes;
    sendBuffer->mRecord.mSyncFrames = sync->mSyncFrames;
    payload->mHeaderBytes[3] = recordSize;
    if (gParticipantKartMap->mKartOfParticipant[DWC_GetMyAID()] < 0) {
        payload->mProgressWord = 0;
    } else {
        progressWord = PackOwnKartProgress();
        payload->mProgressWord =
            progressWord | ((gWiFiRaceSync->mFinishedMask << WIFI_RACE_SYNC_PROGRESS_FINISHED_SHIFT) &
                            WIFI_RACE_SYNC_PROGRESS_FINISHED_MASK);
    }
    SendWiFiRaceSyncRecord(recordSize);
    UpdateWiFiRaceSyncRanks();
    if (IsKartEnded(*(u8 *) &gParticipantKartMap->mKartOfParticipant[DWC_GetMyAID()]) == 0 &&
        (gWiFiRaceSync->mFlags & WIFI_RACE_SYNC_FLAG_IDLE_DISCONNECT_SENT) == 0) {
        if (gInputSlots[GetPadInputSlot()].mBits == 0) {
            gWiFiRaceSync->mIdleFrames = gWiFiRaceSync->mIdleFrames + 1;
            if (gWiFiRaceSync->mIdleFrames > WIFI_RACE_SYNC_IDLE_FRAMES) {
                gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags | WIFI_RACE_SYNC_FLAG_IDLE_DISCONNECT_SENT;
                SetWiFiDisconnectKind(WIFI_DISCONNECT_NO_INPUT);
            }
        } else {
            gWiFiRaceSync->mIdleFrames = 0;
        }
    }
    if (gWiFiRaceSync->mSharedState == WIFI_RACE_SHARED_STATE_RACING) {
        switch (GetChoisesSPickedValue()) {
            case CHOISES_S_PICK_NEXT:
            case CHOISES_S_PICK_NEXT_LAST:
                gWiFiRaceSync->mSharedState = WIFI_RACE_SHARED_STATE_PICKED_NEXT;
                sync = gWiFiRaceSync;
                sync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_AFTER_CHOICE;
                sync->mStateMachine.mNextStateRequested = 1;
                break;
            case CHOISES_S_PICK_QUIT:
                gWiFiRaceSync->mSharedState = WIFI_RACE_SHARED_STATE_PICKED_QUIT;
                sync = gWiFiRaceSync;
                sync->mStateMachine.mNextState = WIFI_RACE_SYNC_STATE_AFTER_CHOICE;
                sync->mStateMachine.mNextStateRequested = 1;
                break;
        }
    }
}

void EnterWiFiRaceSyncAfterChoice(void *stateObject) {
    gWiFiRaceSync->mFlags &= ~WIFI_RACE_SYNC_FLAG_ALL_PEERS_PICKED_SEEN;
}

u32 GetWiFiRaceSyncPickedValue(void) {
    u32 result;
    WiFiRaceSync *wiFiRaceSync;

    wiFiRaceSync = gWiFiRaceSync;
    result = 0;
    if (wiFiRaceSync->mSharedState != WIFI_RACE_SHARED_STATE_PICKED_QUIT) {
        if (wiFiRaceSync->mSharedState != WIFI_RACE_SHARED_STATE_ALL_PEERS_PICKED) {
            return result;
        }
        if ((wiFiRaceSync->mFlags & WIFI_RACE_SYNC_FLAG_ALL_PEERS_PICKED_SEEN) != 0) {
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
    sync = gWiFiRaceSync;
    switch (sync->mSharedState) {
        case WIFI_RACE_SHARED_STATE_PICKED_QUIT:
        case WIFI_RACE_SHARED_STATE_PICKED_NEXT:
            for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
                participantBit = 1 << participant;
                if ((gWiFiRaceSync->mParticipantMask & participantBit) != 0 && participant != DWC_GetMyAID()) {
                    if (gWiFiRaceSync->mPeerSharedStates[participant] != WIFI_RACE_SHARED_STATE_PICKED_NEXT &&
                        gWiFiRaceSync->mPeerSharedStates[participant] != WIFI_RACE_SHARED_STATE_ALL_PEERS_PICKED) {
                        value = value | participantBit;
                    }
                }
            }
            if (value == 0) {
                gWiFiRaceSync->mSharedState = WIFI_RACE_SHARED_STATE_ALL_PEERS_PICKED;
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
                sync->mFlags = sync->mFlags | WIFI_RACE_SYNC_FLAG_ALL_PEERS_PICKED_SEEN;
            }
            if ((gWiFiRaceSync->mParticipantMask | ~allPeersPickedMask) != 0) {
                gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags | WIFI_RACE_SYNC_FLAG_ALL_PEERS_PICKED_SEEN;
            }
            break;
    }
    if ((gWiFiRaceSync->mParticipantMask & ~allPeersPickedMask) == 0) {
        gWiFiRaceSync->mSharedState = WIFI_RACE_SHARED_STATE_ALL_PEERS_PICKED;
    }
}

void UpdateWiFiRaceSyncAfterChoice(void *stateObject) {
    u16 recordSize;
    WiFiRaceSync *sync;
    WiFiRaceSyncSendBuffer *sendBuffer;
    WiFiRaceSyncRecord *payload;
    s32 progressWord;

    UpdateItemDataSlots();
    UpdateSlotResultSyncs();
    sync = gWiFiRaceSync;
    sendBuffer = sync->mSendBuffer;
    payload = &sendBuffer->mRecord;
    recordSize = WIFI_RACE_SYNC_RECORD_SIZE - sync->mUnusedItemDataBytes;
    sendBuffer->mRecord.mSyncFrames = sync->mSyncFrames;
    payload->mHeaderBytes[3] = recordSize;
    if (gParticipantKartMap->mKartOfParticipant[DWC_GetMyAID()] < 0) {
        payload->mProgressWord = 0;
    } else {
        progressWord = PackOwnKartProgress();
        payload->mProgressWord =
            progressWord | ((gWiFiRaceSync->mFinishedMask << WIFI_RACE_SYNC_PROGRESS_FINISHED_SHIFT) &
                            WIFI_RACE_SYNC_PROGRESS_FINISHED_MASK);
    }
    SendWiFiRaceSyncRecord(recordSize);
    UpdateWiFiRaceSyncRanks();
    UpdateWiFiRaceSyncSharedState();
}

WiFiRaceSyncEntry *GetParticipantEntryAtSyncFrames(s32 participant, u32 syncFrames) {
    WiFiRaceSyncEntry *entry;

    entry = &gWiFiRaceSync->mEntries[participant];
    if (syncFrames != entry->mSyncFrames) {
        return NULL;
    }
    return entry;
}

s32 GetParticipantSyncFrames(s32 participant) {
    return gWiFiRaceSync->mEntries[participant].mSyncFrames;
}

void AddWiFiRaceSyncRoundTrip(const u64 *ticks, s32 participant) {
    u8 sampleCount;
    u64 roundTrip;
    WiFiRaceSync *sync;
    BOOL accepted;

    sync = gWiFiRaceSync;
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
            gWiFiRaceSync->mPeers[participant].mRejectedSampleCount++;
            if (gWiFiRaceSync->mPeers[participant].mRejectedSampleCount > WIFI_RACE_SYNC_MAX_REJECTED_SAMPLES) {
                BIT_SET(gWiFiRaceSync->mDroppedParticipantMask, participant);
            }
        }
    } else {
        accepted = TRUE;
    }
    if (accepted != FALSE) {
        sampleCount = sampleCount + 1;
    }
    gWiFiRaceSync->mPeers[participant].mSampleCount = sampleCount;
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
    sync = gWiFiRaceSync;
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
    MI_CpuCopy8(bodyBytes, entry, recordSize);
}

void ReceiveWiFiRaceSyncCountdown(u32 fromIndex, WiFiRaceSyncPacket *packet, u32 size) {
    s32 smoothed;
    WiFiRaceSync *sync;
    s16 senderCountdown;
    s16 ownCountdown;
    s16 difference;
    u32 participantBit;

    senderCountdown = packet->mBody.mCountdown;
    sync = gWiFiRaceSync;
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
    smoothed = (difference << 11) + (gWiFiRaceSync->mCountdownSmoothedDifference >> 1);
    gWiFiRaceSync->mCountdownSmoothedDifference = smoothed;
    gWiFiRaceSync->mCountdownTimer += (s16) FROM_FIXED12(smoothed + 0x800);
}

void ReceiveWiFiRaceSyncPacket(u32 fromIndex, WiFiRaceSyncPacket *packet, u32 size, u32 unusedFourth) {
    u32 participant;
    WiFiRaceSync *sync;
    WiFiRaceSyncPacketBody *body;
    WiFiRaceSyncPeer *peer;
    u32 sender;
    u64 tick;
    u8 ownParticipant;

    sync = gWiFiRaceSync;
    if (sync == NULL) {
        return;
    }
    participant = packet->mSender;
    if ((sync->mParticipantMask & (1 << participant)) == 0) {
        return;
    }
    sync->mTimeoutFrames[participant] = 0;
    gWiFiRaceSync->mPeerDroppedMasks[packet->mSender] = packet->mDroppedParticipantMask;
    gWiFiRaceSync->mPeerSharedStates[packet->mSender] = packet->mSharedState;
    switch (((volatile WiFiRaceSyncPacket *) packet)->mKind) {
        case WIFI_RACE_SYNC_PACKET_PROBE:
            body = &packet->mBody;
            sender = packet->mSender;
            ownParticipant = DWC_GetMyAID();
            if (body->mProbeOrigin == ownParticipant) {
                body->mProbeTicks[3] = OS_GetTick();
                AddWiFiRaceSyncRoundTrip(body->mProbeTicks, sender);
                return;
            }
            if (body->mProbeOrigin >= WIFI_RACE_SYNC_PARTICIPANT_COUNT) {
                return;
            }
            peer = &gWiFiRaceSync->mPeers[sender];
            MI_CpuCopy8(body, peer, WIFI_RACE_SYNC_PROBE_SIZE);
            tick = OS_GetTick();
            peer->mProbeReceivedTickLow = tick;
            peer->mProbeReceivedTickHigh = tick >> 32;
            gWiFiRaceSync->mPeers[sender].mProbePending = TRUE;
            break;
        case WIFI_RACE_SYNC_PACKET_READY:
            gWiFiRaceSync->mReadyMask = gWiFiRaceSync->mReadyMask | (1 << packet->mSender);
            break;
        case WIFI_RACE_SYNC_PACKET_COUNTDOWN:
            ReceiveWiFiRaceSyncCountdown(fromIndex, packet, size);
            break;
        case WIFI_RACE_SYNC_PACKET_RECORD:
            ReceiveWiFiRaceSyncRecord(fromIndex, packet, size);
            break;
// UNSENT is never sent. EMPTY is sent with no body by UpdateWiFiRaceSyncProbe to a peer that has 12 samples, on every
// fifth visit to that peer; neither does anything here.
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
        if (gParticipantKartMap->mKartOfParticipant[participant] == -1) {
            elos[participant] = 5000;
        } else {
            elos[participant] = GetPlayerRecordElo(participant);
        }
    }
    for (participant = 0; participant < 4; participant++) {
        kart = gParticipantKartMap->mKartOfParticipant[participant];
        if (kart == -1) {
            continue;
        }
        newElos[participant] = elos[participant];
        for (otherParticipant = 0; otherParticipant < 4; otherParticipant++) {
            rankedNotWorse = 1;
            otherKart = gParticipantKartMap->mKartOfParticipant[otherParticipant];
            if (otherKart == -1 || kart == otherKart) {
                continue;
            }
            kartRank = GetKartRank((u16) kart);
            otherKartRank = GetKartRank((u16) otherKart);
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
        SetPlayerRecordElo(participant, newElos[participant]);
    }
}

// Marks a peer dropped after more than 300 silent calls (more than 600 before its first sample); a peer dropped here
// and also reported dropped by every other live peer is removed with its kart. With one participant or none left, calls
// SetWiFiDisconnectKind(WIFI_DISCONNECT_OPPONENT_LEFT), first lowering a backup counter by the other kart count unless
// the session state is off.
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
        if ((gWiFiRaceSync->mParticipantMask & participantBit) != 0 && participant != DWC_GetMyAID() &&
            (gWiFiRaceSync->mDroppedParticipantMask & participantBit) == 0) {
            timeoutLimit = WIFI_RACE_SYNC_TIMEOUT_FRAMES;
            if (gWiFiRaceSync->mPeers[participant].mSampleCount == 0) {
                timeoutLimit = WIFI_RACE_SYNC_FIRST_TIMEOUT_FRAMES;
            }
            gWiFiRaceSync->mTimeoutFrames[participant]++;
            if (gWiFiRaceSync->mTimeoutFrames[participant] > timeoutLimit) {
                gWiFiRaceSync->mDroppedParticipantMask |= participantBit;
            }
        }
    }
    agreedDroppedMask = gWiFiRaceSync->mDroppedParticipantMask;
    for (participant = 0; participant < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participant++) {
        if (BIT_IS_SET(gWiFiRaceSync->mParticipantMask, participant)) {
            if (participant != DWC_GetMyAID()) {
                if ((gWiFiRaceSync->mDroppedParticipantMask & (1 << participant)) == 0) {
                    peerMask = gWiFiRaceSync->mPeerDroppedMasks[participant] | (1u << participant);
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
        if ((agreedDroppedMask & participantBit) != 0 && (gWiFiRaceSync->mParticipantMask & participantBit) != 0 &&
            gParticipantKartMap->mKartOfParticipant[participant] != -1) {
            RemoveRaceProgressKart(gParticipantKartMap->mKartOfParticipant[participant]);
            gWiFiRaceSync->mParticipantMask = gWiFiRaceSync->mParticipantMask & ~participantBit;
        }
    }
    if (CountSetBits(gWiFiRaceSync->mParticipantMask) > 1) {
        return;
    }
    sessionState = gWiFiSession->mStateMachine.mState;
    firstBlock = gBackupBuffers->mFirstBlock;
    firstBlockCount = firstBlock->mTotals[5];
    if (sessionState != WIFI_SESSION_STATE_OFF) {
        s8 otherKartCount = gWiFiSession->mKartCountCopy - 1;
        if (otherKartCount > 0) {
            if (firstBlockCount < otherKartCount) {
                firstBlockCount = 0;
            } else {
                firstBlockCount = firstBlockCount - otherKartCount;
            }
        }
        firstBlock->mTotals[5] = firstBlockCount;
        WriteBackupFirstBlockWrapper();
        WaitThreadFunctionsDone();
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    SetWiFiDisconnectKind(WIFI_DISCONNECT_OPPONENT_LEFT);
}

void AdvanceWiFiRaceSync(void) {
    if ((gWiFiRaceSync->mFlags & WIFI_RACE_SYNC_FLAG_REMOVE_DROPPED) != 0) {
        RemoveDroppedParticipants();
    }
    AdvanceStateMachine(&gWiFiRaceSync->mStateMachine);
}
