#pragma once

#include "types.h"
#include "code_02152490.h" // DWCAccFriendData

extern u32 data_021653e4;

s32 AddBuddyFromFriendKey(const void *keyString, void *name);
s32 AddOrUpdateBuddyRecord(DWCAccFriendData *friendDataList, void *name, DWCAccFriendData *friendData, s32 notYetBuddy,
                           s32 e, s32 allowAdd);
s32 FindBuddyIndexByFriendData(const void *friendData);
s32 CheckFriendKeyString(const void *keyString);
void FormatUserDataFriendKey(u32 buffer);
BOOL IsUserDataFriendKeyNonZero(void);
s32 CheckUserDataValidConsole(void);
void AddOtherKartCountToSecondTotal(void);
void StartReadGhostFileRecords(void *records);
void ReadGhostFileRecords(void);
