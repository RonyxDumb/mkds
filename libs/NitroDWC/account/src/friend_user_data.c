#include "friend_user_data.h"
#include "friend_data_account_fields.h"
#include "wifi_account_init.h"
#include "Main/Net/friend_data_player_id.h"
#include "digest_hmac_overlay_hash.h"

#pragma thumb on

void DWC_LoginIdToUserName(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata, char *username) {
    FriendCode_SomeFn_7_from_thumb(frienddata, userdata->mGamecode, username);
}

BOOL FriendCode_SameAs_from_thumb(const DWCAccFriendData *frienddata1, const DWCAccFriendData *frienddata2) {
    u32 type;
    type = FriendCode_GetState_from_thumb(frienddata1);
    if (type != FriendCode_GetState_from_thumb(frienddata2)) {
        return 0;
    }
    if (type == 3) {
        if (FriendCode_GetProfileId_from_thumb(frienddata1) == FriendCode_GetProfileId_from_thumb(frienddata2)) {
            return 1;
        }
        return 0;
    }
    if (type == 1) {
        if (FriendCode_GetSomePackedValue_from_thumb(frienddata1) == FriendCode_GetSomePackedValue_from_thumb(frienddata2) &&
            FriendCode_GetCrcChecksum_from_thumb(frienddata1) == FriendCode_GetCrcChecksum_from_thumb(frienddata2)) {
            return 1;
        }
        return 0;
    }
    if (type == 2) {
        if (FriendCode_GetFriendCodePacked_from_thumb(frienddata1) == FriendCode_GetFriendCodePacked_from_thumb(frienddata2)) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void PlayerProfileInfo_SomeFn_3_from_thumb(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata) {
    u8 name[0x24];
    u64 friendKey;
    if (FriendCode_GetState_from_thumb(frienddata) != 3) {
        if (FriendCode_GetState_from_thumb(frienddata) == 2) {
            friendKey = FriendCode_GetFriendCodePacked_from_thumb(frienddata);
            PrintfUll_from_thumb(friendKey, friendKey >> 32, (u32) name);
            return;
        }
        if (FriendCode_GetState_from_thumb(frienddata) == 1) {
            FriendCode_SomeFn_7_from_thumb(frienddata, userdata->mGamecode, (char *) &name[0xd]);
        }
    }
}

void PlayerProfileInfo_SomeFn_2_from_thumb(const DWCAccUserData *userdata) {
    PlayerProfileInfo_SomeFn_3_from_thumb(userdata, &userdata->mPseudo);
    PlayerProfileInfo_SomeFn_3_from_thumb(userdata, &userdata->mAuthentic);
}

u32 IsLeapYear_from_thumb(u32 year) {
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
    if (date->mMonth >= ACCOUNT_MARCH && IsLeapYear_from_thumb(date->mYear) != 0) {
        dayNum++;
    }
    dayNum = dayNum + date->mYear * 365;
    return dayNum + ((date->mYear + 3) >> 2);
}

#pragma thumb off
