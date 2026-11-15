#pragma once

#include "types.h"

void UpdateWiFiSessionUnusedNop(void *stateObject);

void UpdateWiFiSessionRace(void *stateObject);

void EnterWiFiSessionRace(void *stateObject);
void UpdateWiFiSessionExchange(void *stateObject);

void EnterWiFiSessionExchangeNop(void *stateObject);

void AdvanceWiFiSessionOnIrq(void);
void EnterWiFiSessionLogin(void *stateObject);
void UpdateWiFiSessionState1(void *stateObject);
void EnterWiFiSessionSearch(void *stateObject);
void UpdateWiFiSessionSearch(void *stateObject);

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
