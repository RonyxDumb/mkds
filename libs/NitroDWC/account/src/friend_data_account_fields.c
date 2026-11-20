#include "friend_data_account_fields.h"
#include "wifi_account_init.h"
#include "wifi_id_forward.h"
#include "crc_checksum.h"
#include "Main/Net/block_transfer_and_thread_globals.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "formatted_text_to_buffer.h"
#include "cpu_copy_fill.h"
#include "wifi_id_and_backup_check.h"
#include "Main/Net/friend_data_player_id.h"
#include "tick_counter.h"
#include "startup_entry.h"

#pragma thumb on

u64 DWCi_Acc_GetFriendKey(const DWCAccFriendData *data) {
    return (u64) data->mFriendKeyHi32 << 32 | data->mFriendKeyLo32;
}

u32 GetFriendDataGsProfileId(const DWCAccFriendData *friendData) {
    return friendData->mGsProfileId;
}

void DWCi_Acc_SetUserId(DWCAccFriendData *loginid, u32 useridLo, u32 useridHi) {
    enum { SHIFT_NONE } shift = SHIFT_NONE;
    DWCi_Acc_SetMaskBits(&loginid->mIdData, useridHi, shift, ACCOUNT_USER_ID_HIGH_MASK);
    loginid->mUserIdLo32 = useridLo;
}

void DWCi_Acc_SetPlayerId(DWCAccFriendData *loginid, u32 playerid) {
    loginid->mPlayerId = playerid;
}

void DWCi_Acc_SetFriendKey(DWCAccFriendData *data, u32 friendkeyLo, u32 friendkeyHi) {
    data->mFriendKeyLo32 = friendkeyLo;
    data->mFriendKeyHi32 = friendkeyHi;
}

void DWCi_Acc_SetGsProfileId(DWCAccFriendData *data, u32 gsProfileId) {
    data->mGsProfileId = gsProfileId;
}

u32 GetFriendDataFlags(const DWCAccFriendData *friendData) {
    return (friendData->mIdData >> ACCOUNT_FLAGS_SHIFT) & ACCOUNT_FLAGS_MASK;
}

u32 DWCi_Acc_GetFlag_DataType(const DWCAccFriendData *frienddata) {
    return GetFriendDataFlags(frienddata) & ACCOUNT_DATA_TYPE_MASK;
}

BOOL DWC_IsBuddyFriendData(const DWCAccFriendData *frienddata) {
    if (DWCi_Acc_GetFlag_DataType(frienddata) == ACCOUNT_DATA_TYPE_GS_PROFILE_ID) {
        if ((GetFriendDataFlags(frienddata) & ACCOUNT_FLAG_BUDDY) == ACCOUNT_FLAG_BUDDY) {
            return 1;
        }
        return 0;
    }
    return 0;
}

u32 GetFriendDataType(const DWCAccFriendData *friendData) {
    return DWCi_Acc_GetFlag_DataType(friendData);
}

void SetFriendDataFlags(DWCAccFriendData *friendData, u32 flags) {
    DWCi_Acc_SetMaskBits(&friendData->mIdData, flags, ACCOUNT_FLAGS_SHIFT, ACCOUNT_FLAGS_MASK);
}

void SetFriendDataType(DWCAccFriendData *friendData, u32 dataType) {
    u32 flags;
    u32 value;
    flags = GetFriendDataFlags(friendData);
    value = ACCOUNT_DATA_TYPE_MASK;
    flags = flags & ~value;
    value = flags;
    value = value | dataType;
    SetFriendDataFlags(friendData, value);
}

void DWCi_SetBuddyFriendData(DWCAccFriendData *frienddata) {
    u32 flags;
    if (DWCi_Acc_GetFlag_DataType(frienddata) == ACCOUNT_DATA_TYPE_GS_PROFILE_ID) {
        flags = GetFriendDataFlags(frienddata) | ACCOUNT_FLAG_BUDDY;
        SetFriendDataFlags(frienddata, flags);
    }
}

u64 DWC_Acc_CreateFriendKey(int gsProfileId, u32 gamecode) {
    u32 crcInput[2];
    u8 table[0x100];
    u64 crc;

    crcInput[0] = gsProfileId;
    crcInput[1] = gamecode;
    Crc8InitTable(table, 7);
    crc = Crc8(table, crcInput, 8) & 0x7f;
    crc <<= 32;
    crc |= (u32) gsProfileId;
    return crc;
}

BOOL DWC_Acc_CheckFriendKey(u64 friendkey, u32 gamecode) {
    u32 crcInput[2];
    u8 table[0x100];
    s32 crc;

    crcInput[0] = friendkey;
    crcInput[1] = gamecode;
    Crc8InitTable(table, 7);
    crc = Crc8(table, crcInput, 8) & 0x7f;
    return crc == (friendkey >> 32);
}

int DWC_Acc_FriendKeyToGsProfileId(u64 friendkey, u32 gamecode) {
    u32 result;

    if (DWC_Acc_CheckFriendKey(friendkey, gamecode) != 0) {
        result = friendkey & ~0xffffffff00000000ull;
    } else {
        result = 0;
    }
    return result;
}

void FormatFriendKey(u32 low, u32 high, u32 buffer) {
    OS_SNPrintf((char *) buffer, 0xd, "%012llu", low, high);
}

u64 DWC_StringToFriendKey(const char *string) {
    const s8 *chars = (const s8 *) string;
    u64 result;
    u64 placeValue;
    s32 digitIndex;

    result = 0;
    placeValue = 1;
    for (digitIndex = 0; digitIndex < 12; digitIndex++) {
        result += placeValue * (s64) (*(chars + 11 - digitIndex) - 0x30);
        placeValue *= 10;
    }
    return result;
}

void DWCi_Acc_U64ToString32(u64 num, s32 bitnum, char *result) {
    s32 charIndex;
    s32 len;
    const char *table;

    len = (bitnum + 4) / 5;
    table = "0123456789abcdefghijklmnopqrstuv";
    for (charIndex = 0; charIndex < len; charIndex++) {
        *(result + len - 1 - charIndex) = table[num & 0x1f];
        num = num >> 5;
    }
    result[len] = 0;
}

void DWCi_Acc_LoginIdToUserName(const DWCAccFriendData *loginid, u32 gamecode, char *username) {
    char userIdPart[0x15];
    char playerPart[0x15];

    DWCi_Acc_U64ToString32(DWCi_Acc_GetUserId(loginid), 0x2b, userIdPart);
    DWCi_Acc_U64ToString32(GetFriendDataPlayerId(loginid), 0x20, playerPart);
    OS_SNPrintf(username, 0x15, "%s%c%c%c%c%s", userIdPart, (u8) (gamecode >> 24), (u8) (gamecode >> 16),
                (u8) (gamecode >> 8), (u8) gamecode, playerPart);
}

void DWCi_Acc_CreateUserData(DWCAccUserData *userdata, u32 gamecode) {
    u32 crcTable[0x100];

    MI_CpuFill8(userdata, 0, sizeof(*userdata));
    userdata->mSize = sizeof(*userdata);
    userdata->mGsProfileId = 0;
    userdata->mGamecode = gamecode;
    DWCi_Acc_CreateTempLoginId(&userdata->mPseudo);
    SetFriendDataType(&userdata->mAuthentic, ACCOUNT_DATA_TYPE_NONE);
    Crc32InitTable(crcTable, 0xedb88320);
    userdata->mCrc32 = Crc32(crcTable, userdata, 0x3c);
    userdata->mFlag |= 1;
}

void DWCi_Acc_CreateTempLoginId(DWCAccFriendData *loginid) {
    u64 tick;
    u64 rand;
    DWCAuthWiFiId id;

    tick = OS_GetTick();
    DWC_Auth_GetId(&id);
    if (id.mFlag != 0) {
        DWCi_Acc_SetUserId(loginid, ((u32 *) &id)[0], ((u32 *) &id)[1]);
    } else {
        DWCi_Acc_SetUserId(loginid, ((u32 *) &id)[2], ((u32 *) &id)[3]);
    }
    rand = tick * 0x5d588b656c078965ull + 0x269ec3;
    DWCi_Acc_SetPlayerId(loginid, rand >> 32);
    SetFriendDataType(loginid, ACCOUNT_DATA_TYPE_LOGIN_ID);
}

BOOL DWCi_Acc_CheckConsoleUserId(const DWCAccFriendData *loginid) {
    DWCAuthWiFiId id;

    DWC_Auth_GetId(&id);
    if (id.mFlag != 0) {
        if (DWCi_Acc_GetUserId(loginid) == id.mUId) {
            return 1;
        }
        return 0;
    }
    if (DWCi_Acc_GetUserId(loginid) == id.mNotAttestedId) {
        return 1;
    }
    return 0;
}

u32 IsFriendDataLoginId(const DWCAccFriendData *friendData) {
    int dataType;
    dataType = DWCi_Acc_GetFlag_DataType(friendData);
    if (dataType == ACCOUNT_DATA_TYPE_LOGIN_ID) {
        return 1;
    }
    return 0;
}

BOOL DWCi_Acc_IsAuthentic(const DWCAccUserData *userdata) {
    return IsFriendDataLoginId(&userdata->mAuthentic);
}

u32 IsFriendDataTypeNonZero(const void *friendData) {
    int dataType;
    dataType = DWCi_Acc_GetFlag_DataType(friendData);
    if (dataType != ACCOUNT_DATA_TYPE_NONE) {
        return 1;
    }
    return 0;
}

u32 IsFriendDataTypeNonZeroWrapper(const void *friendData) {
    return IsFriendDataTypeNonZero(friendData);
}

void DWC_CreateUserData(DWCAccUserData *userdata, u32 gamecode) {
    DWCi_Acc_CreateUserData(userdata, gamecode);
}

BOOL DWC_CheckValidConsole(const DWCAccUserData *userdata) {
    DWCAuthWiFiId id;

    if (DWCi_Acc_GetFlag_DataType(&userdata->mAuthentic) == ACCOUNT_DATA_TYPE_NONE) {
        return 1;
    }
    DWC_Auth_GetId(&id);
    if (id.mFlag == 0) {
        return 0;
    }
    if (id.mUId == DWCi_Acc_GetUserId(&userdata->mAuthentic)) {
        return 1;
    }
    return 0;
}

void DWCi_Acc_SetLoginIdToUserData(DWCAccUserData *userdata, const DWCAccFriendData *loginid, int gsProfileId) {
    u32 crcTable[0x100];

    userdata->mAuthentic = *loginid;
    userdata->mGsProfileId = gsProfileId;
    Crc32InitTable(crcTable, 0xedb88320);
    userdata->mCrc32 = Crc32(crcTable, userdata, 0x3c);
    userdata->mFlag |= 1;
}

BOOL DWCi_Acc_IsDirty(const DWCAccUserData *userdata) {
    if ((userdata->mFlag & 1) == 1) {
        return 1;
    }
    return 0;
}

void DWCi_Acc_ClearDirty(DWCAccUserData *userdata) {
    u32 crcTable[0x100];

    userdata->mFlag &= ~1;
    Crc32InitTable(crcTable, 0xedb88320);
    userdata->mCrc32 = Crc32(crcTable, userdata, 0x3c);
}

u64 DWC_GetFriendKey(const DWCAccFriendData *frienddata) {
    if (DWCi_Acc_GetFlag_DataType(frienddata) == ACCOUNT_DATA_TYPE_FRIEND_KEY) {
        return DWCi_Acc_GetFriendKey(frienddata);
    }
    return 0;
}

int DWC_GetGsProfileId(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata) {
    u64 friendKey;

    switch (DWCi_Acc_GetFlag_DataType(frienddata)) {
        case ACCOUNT_DATA_TYPE_FRIEND_KEY:
            friendKey = DWCi_Acc_GetFriendKey(frienddata);
            if (DWC_Acc_CheckFriendKey(friendKey, userdata->mGamecode) != 0) {
                return DWC_Acc_FriendKeyToGsProfileId(friendKey, userdata->mGamecode);
            }
            return 0;
        case ACCOUNT_DATA_TYPE_GS_PROFILE_ID:
            return GetFriendDataGsProfileId(frienddata);
        case ACCOUNT_DATA_TYPE_LOGIN_ID:
            return -1;
        default:
            return 0;
    }
}

u64 DWC_CreateFriendKey(const DWCAccUserData *userdata) {
    u64 friendKey;

    friendKey = 0;
    if (userdata->mGsProfileId != 0) {
        friendKey = DWC_Acc_CreateFriendKey(userdata->mGsProfileId, userdata->mGamecode);
    }
    return friendKey;
}

void InitFriendDataFromFriendKey(void *friendData, u32 friendKeyLow, u32 friendKeyHigh) {
    MI_CpuFill8(friendData, 0, 0xc);
    DWCi_Acc_SetFriendKey(friendData, friendKeyLow, friendKeyHigh);
    SetFriendDataType(friendData, ACCOUNT_DATA_TYPE_FRIEND_KEY);
}

void DWC_CreateExchangeToken(const DWCAccUserData *userdata, DWCAccFriendData *token) {
    MI_CpuFill8(token, 0, 12);
    if (DWCi_Acc_IsAuthentic(userdata) != 0) {
        DWCi_Acc_SetGsProfileId(token, userdata->mGsProfileId);
        SetFriendDataType(token, ACCOUNT_DATA_TYPE_GS_PROFILE_ID);
    } else {
        *token = userdata->mPseudo;
    }
}

#pragma thumb off
