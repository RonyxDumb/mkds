#pragma once

#include "types.h"
#include "clock_chip_access.h" // RTCDate

typedef struct DWCAccFriendData DWCAccFriendData;

typedef struct DWCAccUserData DWCAccUserData;

// Month from which a leap year has its extra day already behind it.
#define ACCOUNT_MARCH 3

s32 DateToDayCount(const RTCDate *date);
u32 IsLeapYear_from_thumb(u32 year);
void PlayerProfileInfo_SomeFn_2_from_thumb(const DWCAccUserData *userdata);
void PlayerProfileInfo_SomeFn_3_from_thumb(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata);
BOOL FriendCode_SameAs_from_thumb(const DWCAccFriendData *frienddata1, const DWCAccFriendData *frienddata2);
void DWC_LoginIdToUserName(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata, char *username);
