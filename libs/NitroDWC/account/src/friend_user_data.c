#include "friend_user_data.h"
#include "friend_data_account_fields.h"
#include "wifi_account_init.h"
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
    if (type == ACCOUNT_DATA_TYPE_GS_PROFILE_ID) {
        if (GetFriendDataGsProfileId(frienddata1) == GetFriendDataGsProfileId(frienddata2)) {
            return 1;
        }
        return 0;
    }
    if (type == ACCOUNT_DATA_TYPE_LOGIN_ID) {
        if (DWCi_Acc_GetUserId(frienddata1) == DWCi_Acc_GetUserId(frienddata2) &&
            GetFriendDataPlayerId(frienddata1) == GetFriendDataPlayerId(frienddata2)) {
            return 1;
        }
        return 0;
    }
    if (type == ACCOUNT_DATA_TYPE_FRIEND_KEY) {
        if (DWCi_Acc_GetFriendKey(frienddata1) == DWCi_Acc_GetFriendKey(frienddata2)) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void DWC_ReportFriendData(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata) {
    u8 text[0x24];
    u64 friendKey;
    if (DWCi_Acc_GetFlag_DataType(frienddata) != ACCOUNT_DATA_TYPE_GS_PROFILE_ID) {
        if (DWCi_Acc_GetFlag_DataType(frienddata) == ACCOUNT_DATA_TYPE_FRIEND_KEY) {
            friendKey = DWCi_Acc_GetFriendKey(frienddata);
            FormatFriendKey(friendKey, friendKey >> 32, (u32) text);
            return;
        }
        if (DWCi_Acc_GetFlag_DataType(frienddata) == ACCOUNT_DATA_TYPE_LOGIN_ID) {
            DWCi_Acc_LoginIdToUserName(frienddata, userdata->mGamecode, (char *) &text[0xd]);
        }
    }
}

void DWC_ReportUserData(const DWCAccUserData *userdata) {
    DWC_ReportFriendData(userdata, &userdata->mPseudo);
    DWC_ReportFriendData(userdata, &userdata->mAuthentic);
}

u32 IsLeapYear(u32 year) {
    if ((year & 3) == 0) {
        return 1;
    }
    return 0;
}

s32 ConvertDateToDays(const RTCDate *date) {
    s32 days;
    if (date->mYear >= 100 || date->mMonth < 1 || date->mMonth > 12 || date->mDay < 1 || date->mDay > 31 ||
        (s32) date->mWeek >= 7 || date->mMonth < 1 || date->mMonth > 12) {
        return -1;
    }
    days = date->mDay - 1 + (sMonthStartDay - 1)[date->mMonth];
    if (date->mMonth >= ACCOUNT_MARCH && IsLeapYear(date->mYear) != 0) {
        days++;
    }
    days = days + date->mYear * 365;
    return days + ((date->mYear + 3) >> 2);
}

#pragma thumb off
