#pragma once

#include "types.h"

void UpdateWiFiSessionState6Nop(void *stateObject);

void UpdateWiFiSessionState5(void *stateObject);

void EnterWiFiSessionState5(void *stateObject);
void UpdateWiFiSessionState4(void *stateObject);

void EnterWiFiSessionState4Nop(void *stateObject);

void AdvanceWiFiSessionOnIrq(void);
void EnterWiFiSessionState1(void *stateObject);
void UpdateWiFiSessionState1(void *stateObject);
void EnterWiFiSessionState3(void *stateObject);
void UpdateWiFiSessionState3(void *stateObject);

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
