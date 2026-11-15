#pragma once

#include "types.h"
#include "code_0214d93c.h" // RTCDate

typedef struct DWCAccFriendData DWCAccFriendData;

typedef struct DWCAccUserData DWCAccUserData;

// Month from which a leap year has its extra day already behind it.
#define DWC_ACC_MARCH 3

s32 DateToDayCount(const RTCDate *date);
u32 IsLeapYearTwoDigit(u32 year);
void DWC_ReportUserData(const DWCAccUserData *userdata);
void DWC_ReportFriendData(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata);
BOOL DWC_IsEqualFriendData(const DWCAccFriendData *frienddata1, const DWCAccFriendData *frienddata2);
void DWC_LoginIdToUserName(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata, char *username);
