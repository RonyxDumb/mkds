#pragma once

#include "types.h"
#include "friend_data_account_fields.h" // DWCAccFriendData


s32 AddBuddyFromFriendKey(const void *keyString, void *name);
s32 AddOrUpdateBuddyRecord(DWCAccFriendData *friendDataList, void *name, DWCAccFriendData *friendData, s32 notYetBuddy,
                           s32 hasEmblem, s32 allowAdd);
s32 FindSomeOI_FriendCode_Index(const void *friendData);
s32 CheckFriendCode(const void *keyString);
void FormatUserDataFriendKey(u32 buffer);
BOOL IsUserDataFriendKeyNonZero(void);
s32 CheckUserDataValidConsole(void);
void AddOtherKartCountToSecondTotal(void);
void RunReadGhostBinsFn(void *records);
void Task_ReadGhostBins(void);

extern u32 g_dec_1000000_0;
