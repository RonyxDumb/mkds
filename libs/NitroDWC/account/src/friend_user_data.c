#include "friend_user_data.h"
#include "friend_data_account_fields.h"
#include "dwc_account_init.h"
#include "Main/Net/friend_data_player_id.h"
#include "digest_hmac_overlay_hash.h"

#pragma thumb on

void DWC_LoginIdToUserName(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata, char *username) {
    DWCi_Acc_LoginIdToUserName(frienddata, userdata->mGamecode, username);
}

BOOL DWC_IsEqualFriendData(const DWCAccFriendData *frienddata1, const DWCAccFriendData *frienddata2) {
    u32 type;
    type = DWCi_Acc_GetFlag_DataType(frienddata1);
    if (type != DWCi_Acc_GetFlag_DataType(frienddata2)) {
        return 0;
    }
    if (type == 3) {
        if (GetFriendDataGsProfileId(frienddata1) == GetFriendDataGsProfileId(frienddata2)) {
            return 1;
        }
        return 0;
    }
    if (type == 1) {
        if (DWCi_Acc_GetUserId(frienddata1) == DWCi_Acc_GetUserId(frienddata2) &&
            GetFriendDataPlayerId(frienddata1) == GetFriendDataPlayerId(frienddata2)) {
            return 1;
        }
        return 0;
    }
    if (type == 2) {
        if (DWCi_Acc_GetFriendKey(frienddata1) == DWCi_Acc_GetFriendKey(frienddata2)) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void DWC_ReportFriendData(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata) {
    u8 name[0x24];
    u64 friendKey;
    if (DWCi_Acc_GetFlag_DataType(frienddata) != 3) {
        if (DWCi_Acc_GetFlag_DataType(frienddata) == 2) {
            friendKey = DWCi_Acc_GetFriendKey(frienddata);
            FormatFriendKey(friendKey, friendKey >> 32, (u32) name);
            return;
        }
        if (DWCi_Acc_GetFlag_DataType(frienddata) == 1) {
            DWCi_Acc_LoginIdToUserName(frienddata, userdata->mGamecode, (char *) &name[0xd]);
        }
    }
}

void DWC_ReportUserData(const DWCAccUserData *userdata) {
    DWC_ReportFriendData(userdata, &userdata->mPseudo);
    DWC_ReportFriendData(userdata, &userdata->mAuthentic);
}

u32 IsLeapYearTwoDigit(u32 year) {
    if ((year & 3) == 0) {
        return 1;
    }
    return 0;
}

s32 DateToDayCount(const RTCDate *date) {
    s32 dayNum;
    if (date->mYear >= 100 || date->mMonth < 1 || date->mMonth > 12 || date->mDay < 1 || date->mDay > 31 ||
        (s32) date->mWeek >= 7 || date->mMonth < 1 || date->mMonth > 12) {
        return -1;
    }
    dayNum = date->mDay - 1 + (sMonthStartDay - 1)[date->mMonth];
    if (date->mMonth >= ACCOUNT_MARCH && IsLeapYearTwoDigit(date->mYear) != 0) {
        dayNum++;
    }
    dayNum = dayNum + date->mYear * 365;
    return dayNum + ((date->mYear + 3) >> 2);
}

#pragma thumb off
