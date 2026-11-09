#include "Main/Unknown/code_0205b0f4.h"

#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_0205afa8.h"
#include "Main/Unknown/code_0205b000.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_0205c000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/code_0205a908.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "00/code_021832d8.h"
#include "01/code_021956dc.h"
#include "code_0200f5ac.h"
#include "code_0202056c.h"
#include "code_021458c4.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0203d568.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020b2e34.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0211ff74.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02061654.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/code_0203c25c.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"

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
        if ((participantMask & (1 << participant)) != 0) {
            gParticipantKartMap->mParticipantOfKart[kart] = participant;
            gParticipantKartMap->mKartOfParticipant[participant] = kart;
            kart++;
        }
    }
    gParticipantKartMap->mUnk_04 = participantMask;
    while (kart < 4) {
        gParticipantKartMap->mParticipantOfKart[kart] = -1;
        kart++;
    }
}

static inline BOOL ReplyToWiFiRaceSyncProbe(void) {
    u8 participant;
    WiFiRaceSync *sync;
    Unk0217aa14_754_04 *payload;

    sync = gWiFiRaceSync;
    payload = &sync->mSendBuffer->mUnk_04;
    for (participant = 0; participant < 4; participant++) {
        if (sync->mPeers[participant].mProbePending != FALSE) {
            MI_CpuCopy8(&sync->mPeers[participant], payload, 0x28);
            *(u64 *) &payload->mUnk_0c[2] = OS_GetTick();
            if (SendWiFiRaceSyncPacket(participant, WIFI_RACE_SYNC_PACKET_PROBE, 0x28) != 0) {
                gWiFiRaceSync->mPeers[participant].mProbePending = FALSE;
            } else {
                MI_CpuFill8(payload, 0, 0x28);
            }
            return TRUE;
        }
    }
    return FALSE;
}

void InitWiFiRaceSync(void *heap) {
    s32 i;
    s32 j;
    u8 k;
    s32 entryIndex;
    u8 participant;
    WiFiRaceSync *sync;

    if (gRaceSetup->mMode != 5) {
        return;
    }
    gWiFiRaceSync = HeapAlloc(heap, 0x760);
    gWiFiRaceSync->mSendBuffer = HeapAllocAligned(heap, 0x6c, 0x20);
    for (i = 0; i < 16; i++) {
        gWiFiRaceSync->mUnk_324[i].mData = HeapAllocAligned(heap, 20, 32);
        for (j = 0; j < 4; j++) {
            gWiFiRaceSync->mUnk_3e4[i][j].mData = HeapAllocAligned(heap, 20, 32);
        }
    }
    gWiFiRaceSync->mStartParticipantMask = gParticipantKartMap->mUnk_04;
    MI_CpuFill8(gWiFiRaceSync->mSendBuffer, 0, 0x6c);
    for (entryIndex = 0; entryIndex < 4; entryIndex++) {
        MI_CpuFill8(&gWiFiRaceSync->mEntries[entryIndex], 0, 0x68);
        gWiFiRaceSync->mEntries[entryIndex].mUnk_86_0 = 0;
    }
    k = gWiFiRaceSync->mStartParticipantMask;
    gWiFiRaceSync->mDroppedParticipantMask = 0;
    gWiFiRaceSync->mParticipantMask = k;
    for (k = 0; k < 4; k++) {
        gWiFiRaceSync->mPeerDroppedMasks[k] = 0;
        gWiFiRaceSync->mTimeoutFrames[k] = 0;
    }
    ResetItemDataSlots();
    func_0205a6b4();
    gWiFiRaceSync->mFlags |= 1;
    gWiFiRaceSync->mFlags |= 0x40;
    sync = gWiFiRaceSync;
    sync->mStateMachine.mNextState = 0;
    sync->mStateMachine.mNextStateRequested = 1;
    gWiFiRaceSync->mSharedState = 0;
    for (participant = 0; participant < 4; participant++) {
        j = gParticipantKartMap->mKartOfParticipant[participant];
        gWiFiRaceSync->mEntries[participant].mUnk_80 = 0;
        if (j >= 0) {
            gWiFiRaceSync->mEntries[participant].mRank = GetKartStartRank((u8) j);
        } else {
            gWiFiRaceSync->mEntries[participant].mRank = 0;
        }
    }
    InitStateMachine(&gWiFiRaceSync->mStateMachine, gWiFiRaceSyncStateTable, 6, NULL);
}

void AdvanceWiFiRaceSyncFrames(void) {
    WiFiRaceSync *sync;

    sync = gWiFiRaceSync;
    if (sync == NULL) {
        return;
    }
    switch (sync->mStateMachine.mState) {
        case 4:
        case 5:
            sync->mSyncFrames++;
            break;
    }
}

void EnterWiFiRaceSyncState1(void) {
    u8 participant;
    s32 *probeCopy;
    WiFiRaceSync *sync;

    for (participant = 0; participant < 4; participant++) {
        probeCopy = &gWiFiRaceSync->mPeers[participant].mUnk_04;
        probeCopy[0] = 0;
        probeCopy[1] = 0;
        probeCopy[2] = 0;
        probeCopy[3] = 0;
        probeCopy[4] = 0;
        probeCopy[5] = 0;
        probeCopy[6] = 0;
        probeCopy[7] = 0;
        probeCopy[8] = 0;
        sync = gWiFiRaceSync;
        sync->mPeers[participant].mUnk_28 = 0;
        sync->mPeers[participant].mUnk_2c = 0;
        sync->mPeers[participant].mSampleCount = 0;
        gWiFiRaceSync->mPeers[participant].mRejectedSampleCount = 0;
        gWiFiRaceSync->mPeers[participant].mUnk_36 = 0;
    }
    gWiFiRaceSync->mSendParticipantIndex = 0;
    gWiFiRaceSync->mUnk_0fb = 0;
    gWiFiRaceSync->mUnk_0fd = 0;
    gWiFiRaceSync->mUnk_0f4 = 0;
    gWiFiRaceSync->mCountdownTimer = 0x7f;
    gWiFiRaceSync->mSharedState = 1;
    gWiFiRaceSync->mFlags &= ~2;
    gWiFiRaceSync->mFlags |= 0x80;
    gWiFiRaceSync->mFlags &= ~0x10;
}

void UpdateWiFiRaceSyncState1(void) {
    u16 participant;
    u8 mask;
    u16 sendParticipantIndex;
    u8 targetParticipant;
    WiFiRaceSync *sync;
    Unk0217aa14_754_04 *payload;
    Unk0217aa14_754 *sendBuffer;

    mask = 0;
    for (participant = 0; participant < 4; participant++) {
        if (participant == GetOwnParticipantIndex() || gWiFiRaceSync->mPeers[participant].mSampleCount >= 12) {
            mask = mask | (1 << participant);
        }
    }
    sync = gWiFiRaceSync;
    if (sync->mParticipantMask == (sync->mParticipantMask & mask)) {
        sync->mUnk_0fb = mask;
        sync = gWiFiRaceSync;
        sync->mStateMachine.mNextState = 2;
        sync->mStateMachine.mNextStateRequested = 1;
    }
    if (ReplyToWiFiRaceSyncProbe() != FALSE) {
        return;
    }
    sync = gWiFiRaceSync;
    sendParticipantIndex = sync->mSendParticipantIndex;
    if (sendParticipantIndex < 4) {
        targetParticipant = sendParticipantIndex;
        if ((sync->mParticipantMask & (1 << targetParticipant)) != 0 && targetParticipant != GetOwnParticipantIndex()) {
            sync = gWiFiRaceSync;
            if (sync->mPeers[targetParticipant].mSampleCount < 12) {
                sendBuffer = sync->mSendBuffer;
                payload = &sendBuffer->mUnk_04;
                sendBuffer->mUnk_04.mUnk_00_h = GetOwnParticipantIndex();
                *(u64 *) &payload->mUnk_04 = OS_GetTick();
                payload->mUnk_0c[0] = 0;
                payload->mUnk_0c[1] = 0;
                payload->mUnk_0c[2] = 0;
                payload->mUnk_0c[3] = 0;
                payload->mUnk_0c[4] = 0;
                *(u32 *) &payload->mUnk_20[0] = 0;
                SendWiFiRaceSyncPacket(targetParticipant, WIFI_RACE_SYNC_PACKET_PROBE, 0x28);
            } else {
                if (sync->mPeers[targetParticipant].mUnk_36 == 0) {
                    SendWiFiRaceSyncPacket(targetParticipant, 5, 0);
                }
                gWiFiRaceSync->mPeers[targetParticipant].mUnk_36++;
                if (gWiFiRaceSync->mPeers[targetParticipant].mUnk_36 > 4) {
                    gWiFiRaceSync->mPeers[targetParticipant].mUnk_36 = 0;
                }
            }
        }
        gWiFiRaceSync->mSendParticipantIndex++;
    } else {
        sync->mSendParticipantIndex = 0;
    }
}

void EnterWiFiRaceSyncState2(void) {
    s32 participant;
    WiFiRaceSync *sync;
    u8 sampleCount;
    u64 roundTripTotal;

    gWiFiRaceSync->mReadyMask = 1 << GetOwnParticipantIndex();
    gWiFiRaceSync->mCountdownTimer = 0x7f;
    gWiFiRaceSync->mSendParticipantIndex = 0;
    for (participant = 0; participant < 4; participant++) {
        sync = gWiFiRaceSync;
        sampleCount = sync->mPeers[participant].mSampleCount;
        roundTripTotal = *(u64 *) &sync->mPeers[participant].mUnk_28;
        if (sampleCount == 0) {
            sync->mEntries[participant].mRoundTripAverage = 0;
        } else {
            sync->mEntries[participant].mRoundTripAverage = (roundTripTotal / sampleCount * 64 / 0x82ea + 32) / 33;
        }
    }
}

void CallWithNextWiFiRaceSyncParticipant(u16 previousParticipant, void (*callback)(u32)) {
    u16 i;
    s32 nextParticipant;
    u16 participant;

    nextParticipant = -1;
    for (i = 1; i <= 4; i++) {
        participant = previousParticipant + i;
        if (participant >= 4) {
            participant = participant - 4;
        }
        if (participant != GetOwnParticipantIndex() &&
            (gWiFiRaceSync->mParticipantMask & (1 << (u8) participant)) != 0) {
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

void UpdateWiFiRaceSyncState2(void) {
    WiFiRaceSync *sync;
    u8 participant;
    Unk0217aa14_754_04 *payload;

    sync = gWiFiRaceSync;
    payload = &sync->mSendBuffer->mUnk_04;
    for (participant = 0; participant < 4; participant++) {
        if (sync->mPeers[participant].mProbePending != FALSE) {
            MI_CpuCopy8(&sync->mPeers[participant], payload, 0x28);
            *(u64 *) &payload->mUnk_0c[2] = OS_GetTick();
            if (SendWiFiRaceSyncPacket(participant, WIFI_RACE_SYNC_PACKET_PROBE, 0x28) != 0) {
                gWiFiRaceSync->mPeers[participant].mProbePending = FALSE;
            } else {
                MI_CpuFill8(payload, 0, 0x28);
            }
            break;
        }
    }
    sync = gWiFiRaceSync;
    if (sync->mParticipantMask == (sync->mParticipantMask & sync->mReadyMask)) {
        sync->mStateMachine.mNextState = 3;
        sync->mStateMachine.mNextStateRequested = 1;
        return;
    }
    CallWithNextWiFiRaceSyncParticipant(sync->mSendParticipantIndex, SendWiFiRaceSyncReady);
}

void EnterWiFiRaceSyncState3(void) {
    gWiFiRaceSync->mCountdownTimer = 0xf0;
    gWiFiRaceSync->mUnk_734 = 0;
}

void SendWiFiRaceSyncCountdown(u32 participant) {
    Unk0217aa14_754 *sendBuffer;
    Unk0217aa14_754_04 *payload;

    sendBuffer = gWiFiRaceSync->mSendBuffer;
    payload = &sendBuffer->mUnk_04;
    payload->mUnk_00_h = gWiFiRaceSync->mCountdownTimer - gWiFiRaceSync->mEntries[participant].mRoundTripAverage;
    payload->mUnk_04_b[0] = gWiFiRaceSync->mUnk_0fb;
    if (SendWiFiRaceSyncPacket(participant, WIFI_RACE_SYNC_PACKET_COUNTDOWN, 8) != 0) {
        gWiFiRaceSync->mUnk_734 = participant;
    }
}

void UpdateWiFiRaceSyncState3(void) {
    WiFiRaceSync *sync;

    gWiFiRaceSync->mCountdownTimer = gWiFiRaceSync->mCountdownTimer - 1;
    if (gWiFiRaceSync->mCountdownTimer <= 0) {
        gWiFiRaceSync->mCountdownTimer = -1;
        sync = gWiFiRaceSync;
        sync->mStateMachine.mNextState = 4;
        sync->mStateMachine.mNextStateRequested = 1;
        return;
    }
    CallWithNextWiFiRaceSyncParticipant(gWiFiRaceSync->mUnk_734, SendWiFiRaceSyncCountdown);
}

void EnterWiFiRaceSyncState4(void) {
    u8 participant;

    gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags | 2;
    gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags & ~0x20;
    gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags & ~0x200;
    gWiFiRaceSync->mSyncFrames = 0;
    gWiFiRaceSync->mUnk_73a = 0;
    gWiFiRaceSync->mUnk_73d = 0;
    gWiFiRaceSync->mUnk_73b = 0;
    gWiFiRaceSync->mUnk_73e = 0;
    gWiFiRaceSync->mUnk_72c = FALSE;
    gWiFiRaceSync->mUnk_738 = 0;
    gWiFiRaceSync->mSharedState = 2;
    MI_CpuFill8(gWiFiRaceSync->mSendBuffer, 0, 0x6c);
    for (participant = 0; participant < 4; participant++) {
        if ((gWiFiRaceSync->mStartParticipantMask & (1 << participant)) != 0 &&
            (gWiFiRaceSync->mParticipantMask & (1 << participant)) == 0) {
            if (gParticipantKartMap->mKartOfParticipant[participant] >= 0) {
                gWiFiRaceSync->mEntries[participant].mUnk_80 =
                    (GetKartStartRank((u8) gParticipantKartMap->mKartOfParticipant[participant]) - 1) | 0x700000;
            }
        }
    }
}

int SendWiFiRaceSyncPacket(u8 participant, u32 kind, int dataSize) {
    WiFiRaceSyncPacket *packet;
    int r;

    r = 1;
    if ((gWiFiRaceSync->mFlags & 4) != 0) {
        return 0;
    }
    if (participant != GetOwnParticipantIndex()) {
        r = dataSize + 4;
        packet = &gWiFiRaceSync->mSendBuffer->mPacket;
        gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags | 4;
        packet->mSender = GetOwnParticipantIndex();
        packet->mTarget = participant;
        packet->mKind = kind;
        packet->mSharedState = gWiFiRaceSync->mSharedState;
        packet->mDroppedParticipantMask = gWiFiRaceSync->mDroppedParticipantMask;
        DC_StoreRange(packet, r);
        r = SendWiFiPacketToParticipant(participant, packet, r, FinishWiFiRaceSyncSend);
        if (r == 0) {
            gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags & ~4;
        }
    }
    return r;
}

void SendWiFiRaceSyncRecord(s32 dataSize) {
    u8 participant;
    s8 lastParticipant;
    s32 sentCount;
    u8 sendCursor;

    sentCount = 0;
    sendCursor = gWiFiRaceSync->mUnk_73a;
    if ((sendCursor & 1) == 0) {
        gWiFiRaceSync->mUnk_73a = sendCursor + 1;
        return;
    }
    participant = sendCursor >> 1;
    lastParticipant = participant - 1;
    if (lastParticipant < 0) {
        lastParticipant = lastParticipant + 4;
    }
    while (sentCount < 1 && participant != lastParticipant) {
        if (participant != GetOwnParticipantIndex() && (gWiFiRaceSync->mParticipantMask & (1 << participant)) != 0) {
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
    gWiFiRaceSync->mUnk_73a = participant << 1;
}

void UpdateWiFiRaceSyncRanks(void) {
    u32 sortKeys[4];
    u8 participantOrder[4];
    u8 participant;
    u8 j;
    u8 l;
    u8 n;
    s16 m;
    u32 x;
    u32 key;
    u8 k;
    u8 rank;
    u32 inMaskBit;
    u32 recordWord;
    u32 g;
    u32 kart;
    u32 entryRecord;
    u32 q;
    WiFiRaceSync *sync;
    u32 participantBit;
    u8 p;
    u32 c;
    u32 startMask;

    x = 0xf;
    for (participant = 0; participant < 4; participant++) {
        sortKeys[participant] = -1;
        participantOrder[participant] = participant;
        sync = gWiFiRaceSync;
        participantBit = 1 << participant;
        inMaskBit = sync->mParticipantMask & participantBit;
        if (inMaskBit != 0) {
            q = 0;
            if ((sync->mStartParticipantMask & participantBit) != 0) {
                q = inMaskBit == 0;
            }
            if (q != 0) {
                sortKeys[participant] = sync->mEntries[participant].mUnk_80 & 0x3fffff;
            } else {
                if (participant == GetOwnParticipantIndex()) {
                    recordWord = PackOwnKartProgress();
                    g = gWiFiRaceSync->mUnk_73e;
                } else {
                    recordWord = gWiFiRaceSync->mEntries[participant].mUnk_04;
                    g = (u8) ((recordWord & 0x7800000) >> 23);
                }
                x = x & g;
                if (recordWord == 0 && IsRaceStarted() == 0) {
                    if (gParticipantKartMap->mKartOfParticipant[participant] != -1) {
                        recordWord =
                            (GetKartStartRank((u16) gParticipantKartMap->mKartOfParticipant[participant]) - 1) |
                            0x700000;
                    }
                }
                if (recordWord != 0) {
                    if ((u8) ((recordWord & 0x400000) >> 22) == 0) {
                        gWiFiRaceSync->mUnk_73e = gWiFiRaceSync->mUnk_73e | participantBit;
                    }
                    gWiFiRaceSync->mEntries[participant].mUnk_80 = recordWord;
                    sortKeys[participant] = gWiFiRaceSync->mEntries[participant].mUnk_80 & 0x3fffff;
                }
            }
        }
    }
    for (participant = 0; participant < 4; participant++) {
        sync = gWiFiRaceSync;
        participantBit = 1 << participant;
        kart = *(u8 *) &gParticipantKartMap->mKartOfParticipant[participant];
        entryRecord = sync->mEntries[participant].mUnk_80;
        inMaskBit = sync->mParticipantMask & participantBit;
        if (inMaskBit != 0) {
            q = 0;
            if ((sync->mStartParticipantMask & participantBit) != 0) {
                q = inMaskBit == 0;
            }
            if (q == 0 && (x & participantBit) != 0 && IsKartEnded(kart) == 0) {
                SetRaceProgressKartFinishRequest(kart, (entryRecord & 0x7ffff) != 0x7ffff);
            }
        }
    }
    for (l = 1; l < 4; l++) {
        n = l;
        key = sortKeys[l];
        k = participantOrder[l];
        while (n != 0 && sortKeys[n - 1] > key) {
            sortKeys[n] = sortKeys[n - 1];
            participantOrder[n] = participantOrder[n - 1];
            n--;
        }
        sortKeys[n] = key;
        participantOrder[n] = k;
    }
    for (j = 0; j < 4; j++) {
        participant = participantOrder[j];
        rank = 0;
        sync = gWiFiRaceSync;
        startMask = sync->mStartParticipantMask;
        if ((startMask & (1 << participant)) != 0) {
            if ((u8) (((u32) sync->mEntries[participant].mUnk_80 & 0x400000) >> 22) == 0) {
                rank = j + 1;
                for (m = j; m >= 0; m--) {
                    if ((u8) (((u32) sync->mEntries[participantOrder[m]].mUnk_80 & 0x400000) >> 22) != 0) {
                        rank = rank - 1;
                    }
                }
            } else {
                u16 w;

                w = gParticipantKartMap->mKartOfParticipant[participant];
                c = gRaceProgress->mUnk_000[w].mUnk_50_0;
                rank = c;
                for (p = 0; p < 4; p++) {
                    u32 e;

                    if ((u8) (((u32) sync->mEntries[p].mUnk_80 & 0x400000) >> 22) == 0) {
                        e = 1;
                    } else {
                        e = 0;
                    }
                    if ((startMask & (1 << p)) != 0) {
                        u16 o;
                        u32 v;

                        o = gParticipantKartMap->mKartOfParticipant[p];
                        o = (u16) o;
                        v = gRaceProgress->mUnk_000[o].mUnk_50_0;
                        if (gRaceProgress->mUnk_000[o].mStatus != 4 && e != 0 && v > c) {
                            rank = rank + 1;
                        }
                    }
                }
            }
        }
        sync->mEntries[participant].mRank = rank;
    }
}

void UpdateWiFiRaceSyncState4(void) {
    u16 recordSize;
    u32 progressWord;
    WiFiRaceSync *sync;
    Unk0217aa14_754 *sendBuffer;
    Unk0217aa14_754_04 *payload;

    UpdateItemDataSlots();
    func_0205a350();
    sync = gWiFiRaceSync;
    sendBuffer = sync->mSendBuffer;
    payload = &sendBuffer->mUnk_04;
    recordSize = 0x68 - sync->mUnk_724;
    sendBuffer->mUnk_04.mUnk_00_0 = sync->mSyncFrames;
    payload->mUnk_00_b[3] = recordSize;
    if (gParticipantKartMap->mKartOfParticipant[GetOwnParticipantIndex()] < 0) {
        payload->mUnk_04 = 0;
    } else {
        progressWord = PackOwnKartProgress();
        payload->mUnk_04 = progressWord | ((gWiFiRaceSync->mUnk_73e << 23) & 0x7800000);
    }
    SendWiFiRaceSyncRecord(recordSize);
    UpdateWiFiRaceSyncRanks();
    if (IsKartEnded(*(u8 *) &gParticipantKartMap->mKartOfParticipant[GetOwnParticipantIndex()]) == 0 &&
        (gWiFiRaceSync->mFlags & 0x200) == 0) {
        if (data_0217562a[func_020435bc()].mBits == 0) {
            gWiFiRaceSync->mUnk_738 = gWiFiRaceSync->mUnk_738 + 1;
            if (gWiFiRaceSync->mUnk_738 > 0x708) {
                gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags | 0x200;
                func_021208e8(1);
            }
        } else {
            gWiFiRaceSync->mUnk_738 = 0;
        }
    }
    if (gWiFiRaceSync->mSharedState == 2) {
        switch (GetChoisesSPickedValue()) {
            case 2:
            case 7:
                gWiFiRaceSync->mSharedState = 4;
                sync = gWiFiRaceSync;
                sync->mStateMachine.mNextState = 5;
                sync->mStateMachine.mNextStateRequested = 1;
                break;
            case 9:
                gWiFiRaceSync->mSharedState = 3;
                sync = gWiFiRaceSync;
                sync->mStateMachine.mNextState = 5;
                sync->mStateMachine.mNextStateRequested = 1;
                break;
        }
    }
}

void EnterWiFiRaceSyncState5(void) {
    gWiFiRaceSync->mFlags &= ~0x100;
}

u32 GetWiFiRaceSyncPickedValue(void) {
    u32 result;
    WiFiRaceSync *p;

    p = gWiFiRaceSync;
    result = 0;
    if (p->mSharedState != 3) {
        if (p->mSharedState != 5) {
            return result;
        }
        if ((p->mFlags & 0x100) != 0) {
            result = 2;
        }
        return result;
    }
    return 9;
}

void UpdateWiFiRaceSyncSharedState(void) {
    WiFiRaceSync *sync;
    u8 a;
    u8 sharedState5Mask;
    u8 participant;
    enum { K0 } participantBit;

    a = 0;
    sharedState5Mask = 0;
    sync = gWiFiRaceSync;
    switch (sync->mSharedState) {
        case 3:
        case 4:
            for (participant = 0; participant < 4; participant++) {
                participantBit = 1 << participant;
                if ((gWiFiRaceSync->mParticipantMask & participantBit) != 0 &&
                    participant != GetOwnParticipantIndex()) {
                    if (gWiFiRaceSync->mPeerSharedStates[participant] != 4 &&
                        gWiFiRaceSync->mPeerSharedStates[participant] != 5) {
                        a = a | participantBit;
                    }
                }
            }
            if (a == 0) {
                gWiFiRaceSync->mSharedState = 5;
            }
            break;
        case 5:
            for (a = 0; a < 4; a++) {
                participantBit = 1 << a;
                if ((sync->mParticipantMask & participantBit) != 0 && sync->mPeerSharedStates[a] == 5) {
                    sharedState5Mask = sharedState5Mask | participantBit;
                }
            }
            if ((sync->mParticipantMask & ~sharedState5Mask) == 0) {
                sync->mFlags = sync->mFlags | 0x100;
            }
            if ((gWiFiRaceSync->mParticipantMask | ~sharedState5Mask) != 0) {
                gWiFiRaceSync->mFlags = gWiFiRaceSync->mFlags | 0x100;
            }
            break;
    }
    if ((gWiFiRaceSync->mParticipantMask & ~sharedState5Mask) == 0) {
        gWiFiRaceSync->mSharedState = 5;
    }
}

void UpdateWiFiRaceSyncState5(void) {
    u16 recordSize;
    WiFiRaceSync *sync;
    Unk0217aa14_754 *sendBuffer;
    Unk0217aa14_754_04 *payload;
    s32 progressWord;

    UpdateItemDataSlots();
    func_0205a350();
    sync = gWiFiRaceSync;
    sendBuffer = sync->mSendBuffer;
    payload = &sendBuffer->mUnk_04;
    recordSize = 0x68 - sync->mUnk_724;
    sendBuffer->mUnk_04.mUnk_00_0 = sync->mSyncFrames;
    payload->mUnk_00_b[3] = recordSize;
    if (gParticipantKartMap->mKartOfParticipant[GetOwnParticipantIndex()] < 0) {
        payload->mUnk_04 = 0;
    } else {
        progressWord = PackOwnKartProgress();
        payload->mUnk_04 = progressWord | ((gWiFiRaceSync->mUnk_73e << 23) & 0x7800000);
    }
    SendWiFiRaceSyncRecord(recordSize);
    UpdateWiFiRaceSyncRanks();
    UpdateWiFiRaceSyncSharedState();
}

WiFiRaceSyncEntry *GetParticipantEntryAtSyncFrames(s32 participant, u32 syncFrames) {
    WiFiRaceSyncEntry *entry;

    entry = &gWiFiRaceSync->mEntries[participant];
    if (syncFrames != entry->mUnk_00_0) {
        return NULL;
    }
    return entry;
}

s32 GetParticipantSyncFrames(s32 participant) {
    return gWiFiRaceSync->mEntries[participant].mUnk_00_0;
}

void AddWiFiRaceSyncRoundTrip(const u64 *ticks, s32 participant) {
    u8 sampleCount;
    u64 roundTrip;
    WiFiRaceSync *sync;
    BOOL accepted;

    sync = gWiFiRaceSync;
    sampleCount = sync->mPeers[participant].mSampleCount;
    if (sampleCount >= 12) {
        return;
    }
    if (sampleCount != 0) {
        roundTrip = (ticks[3] - ticks[0]) - (ticks[2] - ticks[1]);
        if (roundTrip * 64 / 0x82ea < 1000) {
            *(u64 *) &sync->mPeers[participant].mUnk_28 += roundTrip;
            accepted = TRUE;
        } else {
            accepted = FALSE;
            gWiFiRaceSync->mPeers[participant].mRejectedSampleCount++;
            if (gWiFiRaceSync->mPeers[participant].mRejectedSampleCount > 0x40) {
                gWiFiRaceSync->mDroppedParticipantMask |= 1 << participant;
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
    bodyBytes = packet->mUnk_04.mUnk_00_b;
    packetFrames = packet->mUnk_04.mUnk_00_0;
    entryFrames = sync->mEntries[participant].mUnk_00_0;
    entry = &sync->mEntries[participant];
    recordSize = bodyBytes[3];
    if (sync->mStateMachine.mState != 4 && sync->mStateMachine.mState != 5) {
        return;
    }
    if (entryFrames != 0 && entryFrames >= packetFrames) {
        return;
    }
    if (sync->mEntries[participant].mUnk_86_0 == 0) {
        sync->mEntries[participant].mUnk_86_0 = 1;
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

    senderCountdown = packet->mUnk_04.mUnk_00_s;
    sync = gWiFiRaceSync;
    ownCountdown = sync->mCountdownTimer;
    if (sync->mStateMachine.mState == 2) {
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
    smoothed = (difference << 11) + (gWiFiRaceSync->mUnk_0f4 >> 1);
    gWiFiRaceSync->mUnk_0f4 = smoothed;
    gWiFiRaceSync->mCountdownTimer += (s16) ((smoothed + 0x800) >> 12);
}

void ReceiveWiFiRaceSyncPacket(u32 fromIndex, WiFiRaceSyncPacket *packet, u32 size, u32 d) {
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
            body = &packet->mUnk_04;
            sender = packet->mSender;
            ownParticipant = GetOwnParticipantIndex();
            if (body->mUnk_00 == ownParticipant) {
                body->mUnk_04[3] = OS_GetTick();
                AddWiFiRaceSyncRoundTrip(body->mUnk_04, sender);
                return;
            }
            if (body->mUnk_00 >= 4) {
                return;
            }
            peer = &gWiFiRaceSync->mPeers[sender];
            MI_CpuCopy8(body, peer, 0x28);
            tick = OS_GetTick();
            peer->mUnk_0c = tick;
            peer->mUnk_10 = tick >> 32;
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
// Kinds 4 and 5 have no body; only kind 5 is sent (state 1, once a peer has 12 samples), nothing sends
// kind 4.
        case 4:
        case 5:
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

// Marks a peer dropped after 300 silent calls (600 before its first sample); a peer every live peer also reports
// dropped is removed with its kart. With one participant or none left, lowers a backup counter by the other kart count
// (session state non-zero) and calls func_021208e8(2).
void RemoveDroppedParticipants(void) {
    u8 participant;
    u32 agreedDroppedMask;
    u32 participantBit;
    u32 timeoutLimit;
    u8 peerMask;
    u16 sessionState;
    u32 firstBlockCount;
    BackupFirstBlock *firstBlock;

    for (participant = 0; participant < 4; participant++) {
        participantBit = 1 << participant;
        if ((gWiFiRaceSync->mParticipantMask & participantBit) != 0 && participant != GetOwnParticipantIndex() &&
            (gWiFiRaceSync->mDroppedParticipantMask & participantBit) == 0) {
            timeoutLimit = 300;
            if (gWiFiRaceSync->mPeers[participant].mSampleCount == 0) {
                timeoutLimit = 600;
            }
            gWiFiRaceSync->mTimeoutFrames[participant]++;
            if (gWiFiRaceSync->mTimeoutFrames[participant] > timeoutLimit) {
                gWiFiRaceSync->mDroppedParticipantMask |= participantBit;
            }
        }
    }
    agreedDroppedMask = gWiFiRaceSync->mDroppedParticipantMask;
    for (participant = 0; participant < 4; participant++) {
        if ((gWiFiRaceSync->mParticipantMask & (1 << participant)) != 0) {
            if (participant != GetOwnParticipantIndex()) {
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
    for (participant = 0; participant < 4; participant++) {
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
    sessionState = gWiFiSession->mUnk_0008.mState;
    firstBlock = data_0217aa08->mFirstBlock;
    firstBlockCount = firstBlock->mUnk_34[5];
    if (sessionState != 0) {
        s8 otherKartCount = gWiFiSession->mKartCountCopy - 1;
        if (otherKartCount > 0) {
            if (firstBlockCount < otherKartCount) {
                firstBlockCount = 0;
            } else {
                firstBlockCount = firstBlockCount - otherKartCount;
            }
        }
        firstBlock->mUnk_34[5] = firstBlockCount;
        WriteBackupFirstBlockWrapper();
        WaitThreadFunctionsDone();
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    func_021208e8(2);
}
