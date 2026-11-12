#pragma once

#include "types.h"

void UpdateWiFiSessionState6Nop(void);

void UpdateWiFiSessionState5(void);

void EnterWiFiSessionState5(void);
void UpdateWiFiSessionState4(void);

void EnterWiFiSessionState4Nop(void);

void AdvanceWiFiSessionOnIrq(void);
void EnterWiFiSessionState1(void);
void UpdateWiFiSessionState1(void);
void EnterWiFiSessionState3(void);
void UpdateWiFiSessionState3(void);

u8 GetPlayerRecordLowestGrandPrixValue(int index);
void SetPlayerRecordElo(int index, s16 elo);
int GetPlayerRecordElo(int index);

u32 GetPlayerRecordSecondTotal(u32 index);
u32 GetPlayerRecordFirstTotal(u32 index);
u8 HasPlayerRecordEmblem(u32 index);

u32 GetPlayerRecordRegion(u32 index);
void *GetPlayerRecordName(u32 index);
void *GetPlayerRecordEmblem(u32 index);

typedef struct DWCAccFriendData DWCAccFriendData;

DWCAccFriendData *GetPlayerRecordFriendData(u32 index);
