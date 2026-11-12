#pragma once

#include "types.h"
#include "Main/Unknown/code_02152000.h"

typedef struct DWCAccFriendData {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
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

void DWC_CreateExchangeToken(const DWCAccUserData *userdata, DWCAccFriendData *token);

void InitFriendDataFromFriendKey(void *friendData, u32 friendKeyLow, u32 friendKeyHigh);

typedef struct DWCAccFriendData DWCAccFriendData;
typedef struct DWCAccUserData DWCAccUserData;

u64 DWC_CreateFriendKey(const DWCAccUserData *userdata);
int DWC_GetGsProfileId(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata);
u64 DWC_GetFriendKey(const DWCAccFriendData *frienddata);
void DWCi_Acc_ClearDirty(DWCAccUserData *userdata);
BOOL DWCi_Acc_IsDirty(const DWCAccUserData *userdata);
void DWCi_Acc_SetLoginIdToUserData(DWCAccUserData *userdata, const DWCAccFriendData *loginid, int gsProfileId);
BOOL DWC_CheckValidConsole(const DWCAccUserData *userdata);
void DWC_CreateUserData(DWCAccUserData *userdata, u32 gamecode);

u32 IsFriendDataTypeNonZeroWrapper(const void *friendData);

u32 IsFriendDataTypeNonZero(const void *friendData);

typedef struct DWCAccUserData DWCAccUserData;

BOOL DWCi_Acc_IsAuthentic(const DWCAccUserData *userdata);

u32 IsFriendDataLoginId(const DWCAccFriendData *friendData);

typedef struct DWCAccFriendData DWCAccFriendData;
typedef struct DWCAccUserData DWCAccUserData;

BOOL DWCi_Acc_CheckConsoleUserId(const DWCAccFriendData *loginid);
void DWCi_Acc_CreateTempLoginId(DWCAccFriendData *loginid);
void DWCi_Acc_CreateUserData(DWCAccUserData *userdata, u32 gamecode);
void DWCi_Acc_LoginIdToUserName(const DWCAccFriendData *loginid, u32 gamecode, char *username);
void DWCi_Acc_U64ToString32(u64 num, s32 bitnum, char *result);
u64 DWC_StringToFriendKey(const char *string);

void FormatFriendKey(u32 low, u32 high, u32 buffer);

typedef struct DWCAccFriendData DWCAccFriendData;

int DWC_Acc_FriendKeyToGsProfileId(u64 friendkey, u32 gamecode);
BOOL DWC_Acc_CheckFriendKey(u64 friendkey, u32 gamecode);
u64 DWC_Acc_CreateFriendKey(int gsProfileId, u32 gamecode);
void DWCi_SetBuddyFriendData(DWCAccFriendData *frienddata);

typedef struct DWCAccFriendData DWCAccFriendData;

void SetFriendDataType(DWCAccFriendData *friendData, u32 dataType);

typedef struct DWCAccFriendData DWCAccFriendData;

void SetFriendDataFlags(DWCAccFriendData *friendData, u32 flags);

u32 GetFriendDataType(const DWCAccFriendData *friendData);

typedef struct DWCAccFriendData DWCAccFriendData;

BOOL DWC_IsBuddyFriendData(const DWCAccFriendData *frienddata);
u32 DWCi_Acc_GetFlag_DataType(const DWCAccFriendData *frienddata);

typedef struct DWCAccFriendData DWCAccFriendData;

u32 GetFriendDataFlags(const DWCAccFriendData *friendData);

typedef struct DWCAccFriendData DWCAccFriendData;

void DWCi_Acc_SetGsProfileId(DWCAccFriendData *data, u32 gsProfileId);
void DWCi_Acc_SetFriendKey(DWCAccFriendData *data, u32 friendkeyLo, u32 friendkeyHi);
void DWCi_Acc_SetPlayerId(DWCAccFriendData *loginid, u32 playerid);
void DWCi_Acc_SetUserId(DWCAccFriendData *loginid, u32 useridLo, u32 useridHi);

typedef struct DWCAccFriendData DWCAccFriendData;

u32 GetFriendDataGsProfileId(const DWCAccFriendData *friendData);

typedef struct DWCAccFriendData DWCAccFriendData;

u64 DWCi_Acc_GetFriendKey(const DWCAccFriendData *data);
