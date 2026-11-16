#pragma once

#include "types.h"

// Seven pairs of functions passed to sm_init by InitWiFiSession.
extern UnkFunc *g_GlobalB_E7FnList[14];

u32 sub_21205E8(void);
void InitWiFiSession(void *heap);
void CreateWiFiSessionHeap(void *heap);
void DeleteWiFiSessionHeap(void);
void func_021204d0(void);
void UpdateBuddyStatuses(void);
void UpdateWiFiSession(void);
s32 sub_2120340(u32 a, void *b, s32 c, u32 (*d)(void));
void *GetWiFiSessionPlayerRecordData(u32 index);
