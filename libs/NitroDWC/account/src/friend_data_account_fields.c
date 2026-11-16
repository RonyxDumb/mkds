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

u64 FriendCode_GetFriendCodePacked_from_thumb(const DWCAccFriendData *data) {
    return (u64) data->mFriendKeyHi << 32 | data->mFriendKeyLo;
}

#pragma thumb off

#pragma thumb on

u32 FriendCode_GetProfileId_from_thumb(const DWCAccFriendData *friendData) {
    return friendData->mGsProfileId;
}

#pragma thumb off

#pragma thumb on

void FriendCode_SetProfileIdAndFlags_from_thumb(DWCAccFriendData *loginid, u32 useridLo, u32 useridHi) {
    enum { SHIFT_NONE } shift = SHIFT_NONE;
    FriendCode_SetFlagsImpl_from_thumb(&loginid->mIdData, useridHi, shift, 0x7ff);
    loginid->mUserIdLo = useridLo;
}

void FriendCode_SetCrcChecksum_from_thumb(DWCAccFriendData *loginid, u32 playerid) {
    loginid->mPlayerId = playerid;
}

void FriendCode_SetFriendCodeValues_from_thumb(DWCAccFriendData *data, u32 friendkeyLo, u32 friendkeyHi) {
    data->mFriendKeyLo = friendkeyLo;
    data->mFriendKeyHi = friendkeyHi;
}

void FriendCode_SetProfileId_from_thumb(DWCAccFriendData *data, u32 gsProfileId) {
    data->mGsProfileId = gsProfileId;
}

#pragma thumb off

#pragma thumb on
u32 FriendCode_GetFlags_from_thumb(const DWCAccFriendData *friendData) {
    return (friendData->mIdData >> DWC_ACC_FLAGS_SHIFT) & DWC_ACC_FLAGS_MASK;
}
#pragma thumb off

#pragma thumb on

u32 FriendCode_GetState_from_thumb(const DWCAccFriendData *frienddata) {
    return FriendCode_GetFlags_from_thumb(frienddata) & ACCOUNT_DATA_TYPE_MASK;
}

BOOL FriendCode_SomeFn_from_thumb(const DWCAccFriendData *frienddata) {
    if (FriendCode_GetState_from_thumb(frienddata) == ACCOUNT_DATA_TYPE_GS_PROFILE_ID) {
        if ((FriendCode_GetFlags_from_thumb(frienddata) & ACCOUNT_FLAG_BUDDY) == ACCOUNT_FLAG_BUDDY) {
            return 1;
        }
        return 0;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
u32 GetFriendDataType(const DWCAccFriendData *friendData) {
    return FriendCode_GetState_from_thumb(friendData);
}
#pragma thumb off

#pragma thumb on

void FriendCode_SetFlags_from_thumb(DWCAccFriendData *friendData, u32 flags) {
    FriendCode_SetFlagsImpl_from_thumb(&friendData->mIdData, flags, DWC_ACC_FLAGS_SHIFT, DWC_ACC_FLAGS_MASK);
}

#pragma thumb off

#pragma thumb on
void FriendCode_SetState_from_thumb(DWCAccFriendData *friendData, u32 dataType) {
    u32 flags;
    u32 value;
    flags = FriendCode_GetFlags_from_thumb(friendData);
    value = ACCOUNT_DATA_TYPE_MASK;
    flags = flags & ~value;
    value = flags;
    value = value | dataType;
    FriendCode_SetFlags_from_thumb(friendData, value);
}
#pragma thumb off

#pragma thumb on

void DWCi_SetBuddyFriendData(DWCAccFriendData *frienddata) {
    u32 flags;
    if (FriendCode_GetState_from_thumb(frienddata) == ACCOUNT_DATA_TYPE_GS_PROFILE_ID) {
        flags = FriendCode_GetFlags_from_thumb(frienddata) | ACCOUNT_FLAG_BUDDY;
        FriendCode_SetFlags_from_thumb(frienddata, flags);
    }
}

u64 VerifyChecksumGetProfileId_from_thumb(int gsProfileId, u32 gamecode) {
    u32 code[2];
    u8 table[0x100];
    u64 crc;

    code[0] = gsProfileId;
    code[1] = gamecode;
    GenerateFriendCrcLookupTable(table, 7);
    crc = ComputeFriendCrc(table, code, 8) & 0x7f;
    crc <<= 32;
    crc |= (u32) gsProfileId;
    return crc;
}

BOOL Friend_VerifyChecksum_from_thumb(u64 friendkey, u32 gamecode) {
    u32 code[2];
    u8 table[0x100];
    s32 crc;

    code[0] = friendkey;
    code[1] = gamecode;
    GenerateFriendCrcLookupTable(table, 7);
    crc = ComputeFriendCrc(table, code, 8) & 0x7f;
    return crc == (friendkey >> 32);
}

int DWC_Acc_FriendKeyToGsProfileId(u64 friendkey, u32 gamecode) {
    u32 result;

    if (Friend_VerifyChecksum_from_thumb(friendkey, gamecode) != 0) {
        result = friendkey & ~0xffffffff00000000ull;
    } else {
        result = 0;
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void PrintfUll_from_thumb(u32 low, u32 high, u32 buffer) {
    Util_SNPrintF((char *) buffer, 0xd, "%012llu", low, high);
}

#pragma thumb off

#pragma thumb on

u64 ConvertFriendCodeTo64_from_thumb(const char *string) {
    const s8 *chars = (const s8 *) string;
    u64 result;
    u64 dec;
    s32 digitIndex;

    result = 0;
    dec = 1;
    for (digitIndex = 0; digitIndex < 12; digitIndex++) {
        result += dec * (s64) (*(chars + 11 - digitIndex) - 0x30);
        dec *= 10;
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

void FriendCode_SomeFn_7_from_thumb(const DWCAccFriendData *loginid, u32 gamecode, char *username) {
    char idPart[0x15];
    char playerPart[0x15];

    DWCi_Acc_U64ToString32(FriendCode_GetSomePackedValue_from_thumb(loginid), 0x2b, idPart);
    DWCi_Acc_U64ToString32(FriendCode_GetCrcChecksum_from_thumb(loginid), 0x20, playerPart);
    Util_SNPrintF(username, 0x15, "%s%c%c%c%c%s", idPart, (u8) (gamecode >> 24), (u8) (gamecode >> 16),
                (u8) (gamecode >> 8), (u8) gamecode, playerPart);
}

void PlayerProfileInfo_Create_from_thumb(DWCAccUserData *userdata, u32 gamecode) {
    u32 crcTable[0x100];

    Mem_CpuFill8(userdata, 0, sizeof(*userdata));
    userdata->mSize = sizeof(*userdata);
    userdata->mGsProfileId = 0;
    userdata->mGamecode = gamecode;
    FriendCode_CreateFrom_from_thumb(&userdata->mPseudo);
    FriendCode_SetState_from_thumb(&userdata->mAuthentic, 0);
    GenerateProfileInfoCrcLookupTable(crcTable, 0xedb88320);
    userdata->mCrc32 = ComputeProfileInfoCrc(crcTable, userdata, 0x3c);
    userdata->mFlag |= 1;
}

void FriendCode_CreateFrom_from_thumb(DWCAccFriendData *loginid) {
    u64 tick;
    u64 rand;
    DWCAuthWiFiId id;

    tick = Os_GetTick();
    StructDW_SomeFn_GetSomething_from_thumb(&id);
    if (id.mFlag != 0) {
        FriendCode_SetProfileIdAndFlags_from_thumb(loginid, ((u32 *) &id)[0], ((u32 *) &id)[1]);
    } else {
        FriendCode_SetProfileIdAndFlags_from_thumb(loginid, ((u32 *) &id)[2], ((u32 *) &id)[3]);
    }
    rand = tick * 0x5d588b656c078965ull + 0x269ec3;
    FriendCode_SetCrcChecksum_from_thumb(loginid, rand >> 32);
    FriendCode_SetState_from_thumb(loginid, 1);
}

BOOL DWCi_Acc_CheckConsoleUserId(const DWCAccFriendData *loginid) {
    DWCAuthWiFiId id;

    StructDW_SomeFn_GetSomething_from_thumb(&id);
    if (id.mFlag != 0) {
        if (FriendCode_GetSomePackedValue_from_thumb(loginid) == id.mUId) {
            return 1;
        }
        return 0;
    }
    if (FriendCode_GetSomePackedValue_from_thumb(loginid) == id.mNotAttestedId) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

u32 FriendCode_IsState1_from_thumb(const DWCAccFriendData *friendData) {
    int dataType;
    dataType = FriendCode_GetState_from_thumb(friendData);
    if (dataType == ACCOUNT_DATA_TYPE_LOGIN_ID) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

BOOL PlayerProfileInfo_FriendCode2_HasState1_from_thumb(const DWCAccUserData *userdata) {
    return FriendCode_IsState1_from_thumb(&userdata->mAuthentic);
}

#pragma thumb off

#pragma thumb on

u32 FriendCode_HasNonzeroState_from_thumb(const void *friendData) {
    int dataType;
    dataType = FriendCode_GetState_from_thumb(friendData);
    if (dataType != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
u32 FriendCode_HasNonzeroState_0_from_thumb(const void *friendData) {
    return FriendCode_HasNonzeroState_from_thumb(friendData);
}
#pragma thumb off

#pragma thumb on

void j_PlayerProfileInfo_Create_from_thumb(DWCAccUserData *userdata, u32 gamecode) {
    PlayerProfileInfo_Create_from_thumb(userdata, gamecode);
}

BOOL PlayerProfileInfo_SomeFn_4_from_thumb(const DWCAccUserData *userdata) {
    DWCAuthWiFiId id;

    if (FriendCode_GetState_from_thumb(&userdata->mAuthentic) == 0) {
        return 1;
    }
    StructDW_SomeFn_GetSomething_from_thumb(&id);
    if (id.mFlag == 0) {
        return 0;
    }
    if (id.mUId == FriendCode_GetSomePackedValue_from_thumb(&userdata->mAuthentic)) {
        return 1;
    }
    return 0;
}

void DWCi_Acc_SetLoginIdToUserData(DWCAccUserData *userdata, const DWCAccFriendData *loginid, int gsProfileId) {
    u32 crcTable[0x100];

    userdata->mAuthentic = *loginid;
    userdata->mGsProfileId = gsProfileId;
    GenerateProfileInfoCrcLookupTable(crcTable, 0xedb88320);
    userdata->mCrc32 = ComputeProfileInfoCrc(crcTable, userdata, 0x3c);
    userdata->mFlag |= 1;
}

BOOL PlayerProfileInfo_NeedsSaving_from_thumb(const DWCAccUserData *userdata) {
    if ((userdata->mFlag & 1) == 1) {
        return 1;
    }
    return 0;
}

void PlayerProfileInfo_PrepareForSave_from_thumb(DWCAccUserData *userdata) {
    u32 crcTable[0x100];

    userdata->mFlag &= ~1;
    GenerateProfileInfoCrcLookupTable(crcTable, 0xedb88320);
    userdata->mCrc32 = ComputeProfileInfoCrc(crcTable, userdata, 0x3c);
}

u64 FriendCode_GetFriendCodePacked_0_from_thumb(const DWCAccFriendData *frienddata) {
    if (FriendCode_GetState_from_thumb(frienddata) == ACCOUNT_DATA_TYPE_FRIEND_KEY) {
        return FriendCode_GetFriendCodePacked_from_thumb(frienddata);
    }
    return 0;
}

int DWC_GetGsProfileId(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata) {
    u64 friendKey;

    switch (FriendCode_GetState_from_thumb(frienddata)) {
        case ACCOUNT_DATA_TYPE_FRIEND_KEY:
            friendKey = FriendCode_GetFriendCodePacked_from_thumb(frienddata);
            if (Friend_VerifyChecksum_from_thumb(friendKey, userdata->mGamecode) != 0) {
                return DWC_Acc_FriendKeyToGsProfileId(friendKey, userdata->mGamecode);
            }
            return 0;
        case ACCOUNT_DATA_TYPE_GS_PROFILE_ID:
            return FriendCode_GetProfileId_from_thumb(frienddata);
        case ACCOUNT_DATA_TYPE_LOGIN_ID:
            return -1;
        default:
            return 0;
    }
}

u64 PlayerProfileInfo_GetProfileId_from_thumb(const DWCAccUserData *userdata) {
    u64 friendKey;

    friendKey = 0;
    if (userdata->mGsProfileId != 0) {
        friendKey = VerifyChecksumGetProfileId_from_thumb(userdata->mGsProfileId, userdata->mGamecode);
    }
    return friendKey;
}

#pragma thumb off

#pragma thumb on

void FriendCode_SetProfileIdAndChecksum_from_thumb(void *friendData, u32 friendKeyLow, u32 friendKeyHigh) {
    Mem_CpuFill8(friendData, 0, 0xc);
    FriendCode_SetFriendCodeValues_from_thumb(friendData, friendKeyLow, friendKeyHigh);
    FriendCode_SetState_from_thumb(friendData, 2);
}

#pragma thumb off

#pragma thumb on

void PlayerProfileInfo_CopyFriendCode_from_thumb(const DWCAccUserData *userdata, DWCAccFriendData *token) {
    Mem_CpuFill8(token, 0, 12);
    if (PlayerProfileInfo_FriendCode2_HasState1_from_thumb(userdata) != 0) {
        FriendCode_SetProfileId_from_thumb(token, userdata->mGsProfileId);
        FriendCode_SetState_from_thumb(token, 3);
    } else {
        *token = userdata->mPseudo;
    }
}

#pragma thumb off
