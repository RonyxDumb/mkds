#pragma once

#include "types.h"
#include "Main/Net/data_0205b000.h"
#include "Main/Menu/second_menu_scene.h"

void AdvanceWiFiRaceSync(void);

typedef struct WiFiRaceSyncEntry WiFiRaceSyncEntry;

// Values of WiFiRaceSyncPacket.mKind.
typedef enum {
    WIFI_RACE_SYNC_PACKET_PROBE,
    WIFI_RACE_SYNC_PACKET_READY,
    WIFI_RACE_SYNC_PACKET_COUNTDOWN,
    WIFI_RACE_SYNC_PACKET_RECORD
} WiFiRaceSyncPacketKind;

// Body after the 4-byte header. Kind 0: probing participant at 0, its tick at 4. Kind 2: sender countdown at 0. Kind 3:
// 24-bit frame count at 0, then record bytes.
typedef struct WiFiRaceSyncPacketBody {
    /* 00 */ union {
        u16 mProbeOrigin;
        s16 mCountdown;
        u8 mHeaderBytes[4];
        struct {
            u32 mSyncFrames : 24;
        };
    };
    /* 04 */ u64 mProbeTicks[4];
} WiFiRaceSyncPacketBody;

// Message of 0x28 bytes from 0x04.
typedef struct WiFiRaceSyncPacket {
    /* 00 */ union {
        u8 mHeaderByte;
        struct {
            u8 mSender : 2;
            u8 mTarget : 2;
            u8 mKind : 4;
        };
    };
    /* 01 */ u8 mSharedState;
    /* 02 */ union {
        u8 mDroppedMaskByte;
        struct {
            u8 mDroppedParticipantMask : 4;
        };
    };
    /* 03 */ u8 mUnk_03;
    /* 04 */ WiFiRaceSyncPacketBody mBody;
} WiFiRaceSyncPacket;

void RemoveDroppedParticipants(void);
void UpdateParticipantElos(void);
void ReceiveWiFiRaceSyncPacket(u32 fromIndex, WiFiRaceSyncPacket *packet, u32 size, u32 unusedArg1);
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

extern const EloChangeRow gEloChangeTable[9];
extern StateCallbacks gWiFiRaceSyncStateTable[6];
