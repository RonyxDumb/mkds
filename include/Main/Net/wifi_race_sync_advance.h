#pragma once

#include "types.h"
#include "Main/Net/elo_change_row.h"
#include "Main/Menu/second_menu_scene.h"

void GlobalB_E7Fn_5BImpl(void);

typedef struct WiFiRaceSyncEntry WiFiRaceSyncEntry;

// Values of WiFiRaceSync.mStateMachine.mState, in the order of g_E7FnList4.
typedef enum {
    WIFI_RACE_SYNC_STATE_IDLE,
    WIFI_RACE_SYNC_STATE_PROBE,
    WIFI_RACE_SYNC_STATE_READY,
    WIFI_RACE_SYNC_STATE_COUNTDOWN,
    WIFI_RACE_SYNC_STATE_RACE,
    WIFI_RACE_SYNC_STATE_AFTER_CHOICE,
    WIFI_RACE_SYNC_STATE_COUNT
} WiFiRaceSyncState;

// Values of WiFiRaceSyncPacket.mKind.
typedef enum {
    WIFI_RACE_SYNC_PACKET_PROBE,
    WIFI_RACE_SYNC_PACKET_READY,
    WIFI_RACE_SYNC_PACKET_COUNTDOWN,
    WIFI_RACE_SYNC_PACKET_RECORD,
    // Nothing sends this kind; it has no body.
    WIFI_RACE_SYNC_PACKET_UNSENT,
    // Sent with no body once a peer has enough samples; the receiver ignores it.
    WIFI_RACE_SYNC_PACKET_EMPTY
} WiFiRaceSyncPacketKind;

// The body of a Wi-Fi race sync packet: by kind a probe origin, a countdown or a frame count, and the probe ticks.
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

// A race sync packet: sender, target and kind in the header, the shared state, the dropped mask and mBody.
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
void ReceiveWiFiRaceSyncPacket(u32 fromIndex, WiFiRaceSyncPacket *packet, u32 size, u32 unusedFourth);
void ReceiveWiFiRaceSyncCountdown(u32 fromIndex, WiFiRaceSyncPacket *packet, u32 size);
void ReceiveWiFiRaceSyncRecord(u32 fromIndex, WiFiRaceSyncPacket *packet, u32 size);
void AddWiFiRaceSyncRoundTrip(const u64 *ticks, s32 participant);
s32 GetParticipantSyncFrames(s32 participant);
WiFiRaceSyncEntry *GetParticipantEntryAtSyncFrames(s32 participant, u32 syncFrames);
void E7FnList4_Fn11(void *stateObject);
void UpdateWiFiRaceSyncSharedState(void);
u32 GetWiFiRaceSyncPickedValue(void);
void E7FnList4_Fn10(void *stateObject);
void E7FnList4_Fn9(void *stateObject);
void UpdateWiFiRaceSyncRanks(void);
void SendWiFiRaceSyncRecord(s32 dataSize);
int SendWiFiRaceSyncPacket(u8 participant, u32 kind, int dataSize);
void E7FnList4_Fn8(void *stateObject);
void E7FnList4_Fn7(void *stateObject);
void SendWiFiRaceSyncCountdown(u32 participant);
void E7FnList4_Fn6(void *stateObject);
void E7FnList4_Fn5(void *stateObject);
void SendWiFiRaceSyncReady(u32 participant);
void CallWithNextWiFiRaceSyncParticipant(u16 previousParticipant, void (*callback)(u32));
void E7FnList4_Fn4(void *stateObject);
void E7FnList4_Fn3(void *stateObject);
void E7FnList4_Fn2(void *stateObject);
void AdvanceWiFiRaceSyncFrames(void);
void InitializeGlobalAA(void *heap);
void SetParticipantKartMapFromMask(u32 participantMask);
void CreateGlobalRE(void);

extern const EloChangeRow gEloChangeTable[9];
extern StateCallbacks g_E7FnList4[WIFI_RACE_SYNC_STATE_COUNT];
