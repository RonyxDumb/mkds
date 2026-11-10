#pragma once

#include "types.h"
#include "Main/Unknown/code_020467d0.h" // StateCallbacks

typedef struct PlayerRecord PlayerRecord;

// Seven pairs of functions passed to InitStateMachine by InitWiFiSession.
extern StateCallbacks gWiFiSessionStateTable[7];

u32 GetWiFiLinkLevel(void);
void InitWiFiSession(void *heap);
void CreateWiFiSessionHeap(void *heap);
void DeleteWiFiSessionHeap(void);
void ResetWiFiSessionToOff(void);
void UpdateBuddyStatuses(void);
void UpdateWiFiSession(void);
s32 SendWiFiPacketToParticipant(u32 participantIndex, void *packet, s32 size, u32 (*finishCallback)(void));
PlayerRecord *GetWiFiSessionPlayerRecordData(u32 index);
