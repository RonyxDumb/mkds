#pragma once

#include "types.h"

typedef struct Unk0217aa00_45c Unk0217aa00_45c;

// Seven pairs of functions passed to InitStateMachine by InitWiFiSession.
extern UnkFunc *data_0216e21c[14];

u32 func_021205e8(void);
void InitWiFiSession(void *heap);
void CreateWiFiSessionHeap(void *heap);
void DeleteWiFiSessionHeap(void);
void func_021204d0(void);
void UpdateBuddyStatuses(void);
void UpdateWiFiSession(void);
s32 SendWiFiPacketToParticipant(u32 a, void *b, s32 c, u32 (*d)(void));
Unk0217aa00_45c *GetWiFiSessionPlayerRecordData(u32 index);
