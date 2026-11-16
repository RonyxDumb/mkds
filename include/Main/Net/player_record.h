#pragma once

#include "types.h"

void GlobalB_E7Fn_6B(void *stateObject);

void GlobalB_E7Fn_5B(void *stateObject);

void GlobalB_E7Fn_5A(void *stateObject);
void GlobalB_E7Fn_4B(void *stateObject);

void GlobalB_E7Fn_4A(void *stateObject);

void DisplayConfig_VblankFnImpl(void);
void GlobalB_E7Fn_1A(void *stateObject);
void GlobalB_E7Fn_1B(void *stateObject);
void GlobalB_E7Fn_3A(void *stateObject);
void GlobalB_E7Fn_3B(void *stateObject);

u8 GetWorstRankStarValue(int index);
void SetTKSomeSize(int index, s16 elo);
int GetTKSomeSize(int index);

u32 GetPlayerRecordSecondTotal(u32 index);
u32 GetPlayerRecordFirstTotal(u32 index);
u8 GetSomeBTKUseCustomEmblemFlag(u32 index);

u32 GetMaybeSomeWifiIdx(u32 index);
void *GetSomeBTKNickname(u32 index);
void *GetSomeBTKEmblemData(u32 index);

typedef struct DWCAccFriendData DWCAccFriendData;

DWCAccFriendData *GetSomeBTKFriendCode(u32 index);
