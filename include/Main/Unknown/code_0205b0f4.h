#pragma once

#include "types.h"

typedef struct WiFiRaceSyncEntry WiFiRaceSyncEntry;

// 0x24 bytes from 0x04 of WiFiRaceSyncPacket, followed by four 8-byte values.
typedef struct WiFiRaceSyncPacketBody {
    /* 00 */ union {
        u16 mUnk_00;
        s16 mUnk_00_s;
        u8 mUnk_00_b[4];
        struct {
            u32 mUnk_00_0 : 24;
        };
    };
    /* 04 */ u64 mUnk_04[4];
} WiFiRaceSyncPacketBody;

// Message of 0x28 bytes from 0x04.
typedef struct WiFiRaceSyncPacket {
    /* 00 */ union {
        u8 mUnk_00;
        struct {
            u8 mSender : 2;
            u8 mTarget : 2;
            u8 mKind : 4;
        };
    };
    /* 01 */ u8 mSharedState;
    /* 02 */ union {
        u8 mUnk_02;
        struct {
            u8 mDroppedParticipantMask : 4;
        };
    };
    /* 03 */ u8 mUnk_03;
    /* 04 */ WiFiRaceSyncPacketBody mUnk_04;
} WiFiRaceSyncPacket;

void RemoveDroppedParticipants(void);
void UpdateParticipantElos(void);
void ReceiveWiFiRaceSyncPacket(u32 fromIndex, WiFiRaceSyncPacket *packet, u32 size, u32 d);
void ReceiveWiFiRaceSyncCountdown(u32 fromIndex, WiFiRaceSyncPacket *packet, u32 size);
void ReceiveWiFiRaceSyncRecord(u32 fromIndex, WiFiRaceSyncPacket *packet, u32 size);
void AddWiFiRaceSyncRoundTrip(const u64 *ticks, s32 participant);
s32 GetParticipantSyncFrames(s32 participant);
WiFiRaceSyncEntry *GetParticipantEntryAtSyncFrames(s32 participant, u32 syncFrames);
void UpdateWiFiRaceSyncState5(void);
void UpdateWiFiRaceSyncSharedState(void);
u32 GetWiFiRaceSyncPickedValue(void);
void EnterWiFiRaceSyncState5(void);
void UpdateWiFiRaceSyncState4(void);
void UpdateWiFiRaceSyncRanks(void);
void SendWiFiRaceSyncRecord(s32 dataSize);
int SendWiFiRaceSyncPacket(u8 participant, u32 kind, int dataSize);
void EnterWiFiRaceSyncState4(void);
void UpdateWiFiRaceSyncState3(void);
void SendWiFiRaceSyncCountdown(u32 participant);
void EnterWiFiRaceSyncState3(void);
void UpdateWiFiRaceSyncState2(void);
void SendWiFiRaceSyncReady(u32 participant);
void CallWithNextWiFiRaceSyncParticipant(u16 previousParticipant, void (*callback)(u32));
void EnterWiFiRaceSyncState2(void);
void UpdateWiFiRaceSyncState1(void);
void EnterWiFiRaceSyncState1(void);
void AdvanceWiFiRaceSyncFrames(void);
void InitWiFiRaceSync(void *heap);
void SetParticipantKartMapFromMask(u32 participantMask);
void ResetParticipantKartMap(void);
