#pragma once

#include "types.h"
#include "Main/Unknown/code_020467d0.h" // StateCallbacks

typedef struct Unk0217aa00_45c Unk0217aa00_45c;

// Seven pairs of functions passed to InitStateMachine by InitWiFiSession.
extern StateCallbacks data_0216e21c[7];

u32 func_021205e8(void);
void InitWiFiSession(void *heap);
void CreateWiFiSessionHeap(void *heap);
void DeleteWiFiSessionHeap(void);
void func_021204d0(void);
void UpdateBuddyStatuses(void);
void UpdateWiFiSession(void);
s32 SendWiFiPacketToParticipant(u32 a, void *b, s32 c, u32 (*d)(void));
Unk0217aa00_45c *GetWiFiSessionPlayerRecordData(u32 index);
