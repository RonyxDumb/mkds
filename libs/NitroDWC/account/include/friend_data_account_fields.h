#pragma once

#include "types.h"

// Data types of a friend data record (the low two bits of its flags): empty, login id, friend key, or a profile id
// of the game server.
#define ACCOUNT_DATA_TYPE_NONE 0
#define ACCOUNT_DATA_TYPE_LOGIN_ID 1
#define ACCOUNT_DATA_TYPE_FRIEND_KEY 2
#define ACCOUNT_DATA_TYPE_GS_PROFILE_ID 3
#define ACCOUNT_DATA_TYPE_MASK 0x3

// Flag bit of a record of the profile id type: the friend is a buddy.
#define ACCOUNT_FLAG_BUDDY 0x4

// mIdData holds the flags in bits 11 and up, and the top bits of the user id below them.
#define DWC_ACC_FLAGS_SHIFT 11
#define DWC_ACC_FLAGS_MASK 0x1fffff
#define ACCOUNT_USER_ID_HIGH_MASK 0x7ff

typedef struct DWCAccFriendData {
    /* 00 */ u32 mIdData;
    union {
        struct {
            /* 04 */ u32 mUserIdLo;
            /* 08 */ u32 mPlayerId;
        };
        struct {
            /* 04 */ u32 mFriendKeyLo;
            /* 08 */ u32 mFriendKeyHi;
        };
        /* 04 */ u32 mGsProfileId;
    };
} DWCAccFriendData;

typedef struct DWCAccUserData {
    /* 00 */ u32 mSize;
    /* 04 */ DWCAccFriendData mPseudo;
    /* 10 */ DWCAccFriendData mAuthentic;
    /* 1c */ u32 mGsProfileId;
    /* 20 */ u32 mFlag;
    /* 24 */ u32 mGamecode;
    /* 28 */ u8 mReserved[0x14];
    /* 3c */ u32 mCrc32;
} DWCAccUserData;

void PlayerProfileInfo_CopyFriendCode_from_thumb(const DWCAccUserData *userdata, DWCAccFriendData *token);

void FriendCode_SetProfileIdAndChecksum_from_thumb(void *friendData, u32 friendKeyLow, u32 friendKeyHigh);

typedef struct DWCAccFriendData DWCAccFriendData;
typedef struct DWCAccUserData DWCAccUserData;

u64 PlayerProfileInfo_GetProfileId_from_thumb(const DWCAccUserData *userdata);
int DWC_GetGsProfileId(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata);
u64 FriendCode_GetFriendCodePacked_0_from_thumb(const DWCAccFriendData *frienddata);
void PlayerProfileInfo_PrepareForSave_from_thumb(DWCAccUserData *userdata);
BOOL PlayerProfileInfo_NeedsSaving_from_thumb(const DWCAccUserData *userdata);
void DWCi_Acc_SetLoginIdToUserData(DWCAccUserData *userdata, const DWCAccFriendData *loginid, int gsProfileId);
BOOL PlayerProfileInfo_SomeFn_4_from_thumb(const DWCAccUserData *userdata);
void j_PlayerProfileInfo_Create_from_thumb(DWCAccUserData *userdata, u32 gamecode);

u32 FriendCode_HasNonzeroState_0_from_thumb(const void *friendData);

u32 FriendCode_HasNonzeroState_from_thumb(const void *friendData);

typedef struct DWCAccUserData DWCAccUserData;

BOOL PlayerProfileInfo_FriendCode2_HasState1_from_thumb(const DWCAccUserData *userdata);

u32 FriendCode_IsState1_from_thumb(const DWCAccFriendData *friendData);

typedef struct DWCAccFriendData DWCAccFriendData;
typedef struct DWCAccUserData DWCAccUserData;

BOOL DWCi_Acc_CheckConsoleUserId(const DWCAccFriendData *loginid);
void FriendCode_CreateFrom_from_thumb(DWCAccFriendData *loginid);
void PlayerProfileInfo_Create_from_thumb(DWCAccUserData *userdata, u32 gamecode);
void FriendCode_SomeFn_7_from_thumb(const DWCAccFriendData *loginid, u32 gamecode, char *username);
void DWCi_Acc_U64ToString32(u64 num, s32 bitnum, char *result);
u64 ConvertFriendCodeTo64_from_thumb(const char *string);

void PrintfUll_from_thumb(u32 low, u32 high, u32 buffer);

typedef struct DWCAccFriendData DWCAccFriendData;

int DWC_Acc_FriendKeyToGsProfileId(u64 friendkey, u32 gamecode);
BOOL Friend_VerifyChecksum_from_thumb(u64 friendkey, u32 gamecode);
u64 VerifyChecksumGetProfileId_from_thumb(int gsProfileId, u32 gamecode);
void DWCi_SetBuddyFriendData(DWCAccFriendData *frienddata);

typedef struct DWCAccFriendData DWCAccFriendData;

void FriendCode_SetState_from_thumb(DWCAccFriendData *friendData, u32 dataType);

typedef struct DWCAccFriendData DWCAccFriendData;

void FriendCode_SetFlags_from_thumb(DWCAccFriendData *friendData, u32 flags);

u32 GetFriendDataType(const DWCAccFriendData *friendData);

typedef struct DWCAccFriendData DWCAccFriendData;

BOOL FriendCode_SomeFn_from_thumb(const DWCAccFriendData *frienddata);
u32 FriendCode_GetState_from_thumb(const DWCAccFriendData *frienddata);

typedef struct DWCAccFriendData DWCAccFriendData;

u32 FriendCode_GetFlags_from_thumb(const DWCAccFriendData *friendData);

typedef struct DWCAccFriendData DWCAccFriendData;

void FriendCode_SetProfileId_from_thumb(DWCAccFriendData *data, u32 gsProfileId);
void FriendCode_SetFriendCodeValues_from_thumb(DWCAccFriendData *data, u32 friendkeyLo, u32 friendkeyHi);
void FriendCode_SetCrcChecksum_from_thumb(DWCAccFriendData *loginid, u32 playerid);
void FriendCode_SetProfileIdAndFlags_from_thumb(DWCAccFriendData *loginid, u32 useridLo, u32 useridHi);

typedef struct DWCAccFriendData DWCAccFriendData;

u32 FriendCode_GetProfileId_from_thumb(const DWCAccFriendData *friendData);

typedef struct DWCAccFriendData DWCAccFriendData;

u64 FriendCode_GetFriendCodePacked_from_thumb(const DWCAccFriendData *data);
