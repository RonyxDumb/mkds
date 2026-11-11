#pragma once

#include "types.h"
#include "00/code_0218f960.h"

// 0xac-byte array element GpiUpdateSearch fills.
typedef struct ProfileMatch {
    /* 00 */ s32 mProfile;
    /* 04 */ char mNick[0x1f];
    /* 23 */ char mUniquenick[0x15];
    /* 38 */ char mFirstname[0x1f];
    /* 57 */ char mLastname[0x1f];
    /* 76 */ char mEmail[0x36];
} ProfileMatch;

// 0x128-byte array element GpiUpdateSearch fills.
typedef struct PlayerMatch {
    /* 000 */ s32 mUnk_000;
    /* 004 */ char mUnk_004[0x20];
    /* 024 */ s32 mUnk_024;
    /* 028 */ char mUnk_028[0x100];
} PlayerMatch;

// 0x10-byte local of GpiUpdateSearch passed to GpiCallback.mCallback.
typedef struct Unk02194cac_10 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ ProfileMatch *mUnk_0c;
} Unk02194cac_10;

// Objects GpiUpdateSearch allocates and passes to GpiQueueCallback.
typedef struct GpCheckNewUserResponseArg {
    /* 00 */ s32 mResult;
    /* 04 */ s32 mProfile;
} GpCheckNewUserResponseArg;

typedef struct ReverseBuddiesReply {
    /* 00 */ s32 mResult;
    /* 04 */ s32 mNumProfiles;
    /* 08 */ ProfileMatch *mProfiles;
} ReverseBuddiesReply;

typedef struct SuggestNickReply {
    /* 00 */ s32 mResult;
    /* 04 */ s32 mNumSuggestedNicks;
    /* 08 */ char **mSuggestedNicks;
} SuggestNickReply;

typedef struct FindPlayersReply {
    /* 00 */ s32 mResult;
    /* 04 */ s32 mProductId;
    /* 08 */ s32 mNumMatches;
    /* 0c */ PlayerMatch *mMatches;
} FindPlayersReply;

typedef struct EmailCheckReply {
    /* 00 */ s32 mUnk_00;
    /* 04 */ char mUnk_04[0x34];
    /* 38 */ BOOL mUnk_38;
} EmailCheckReply;

typedef struct UserNicksReply {
    /* 00 */ s32 mResult;
    /* 04 */ char mEmail[0x34];
    /* 38 */ s32 mNumNicks;
    /* 3c */ char **mNicks;
    /* 40 */ char **mUniquenicks;
} UserNicksReply;

extern char gSearchManagerName[];
extern u8 data_ov000_021b35f8[];
extern char gSearchIndexAssertion[];
extern char gGpiSearchFileName[];
extern s8 gSmString[];
extern char gSearchManagerConnectErrorString[];
extern u8 gSearchKey[];
extern u8 data_ov000_021b3670[];
extern u8 data_ov000_021b367c[];
extern u8 data_ov000_021b3688[];
extern u8 data_ov000_021b3698[];
extern u8 data_ov000_021b36a0[];
extern u8 data_ov000_021b36b0[];
extern u8 data_ov000_021b36b8[];
extern u8 data_ov000_021b36c4[];
extern u8 data_ov000_021b36d0[];
extern u8 gSkipKey[];
extern u8 gValidKey[];
extern u8 gNicksKey[];
extern u8 gPassKey[];
extern u8 gPmatchKey[];
extern u8 data_ov000_021b3708[];
extern u8 gCheckKey[];
extern u8 data_ov000_021b371c[];
extern u8 gProductIDKey[];
extern u8 gCdkeyKey[];
extern u8 gOthersKey[];
extern u8 gUniquesearchKey[];
extern u8 gPreferrednickKey[];
extern char data_ov000_021b3768[];
extern u8 data_ov000_021b376c[];
extern char data_ov000_021b3778[];
extern char data_ov000_021b3780[];
extern char gBsrdoneKey[];
extern char gMoreKey[];
extern char gBsrKey[];
extern char gNickResultKey[];
extern char gUniquenickResultKey[];
extern char gSearchFirstnameKey[];
extern char gSearchLastnameKey[];
extern char gSearchEmailKey[];
extern char gSearchServerReadErrorString[];
extern char gVrKey[];
extern char gNrKey[];
extern char gNdoneKey[];
extern char gPsrdoneKey[];
extern char gPsrKey[];
extern char gStatusResultKey[];
extern char gStatuscodeKey[];
extern char gCurKey[];
extern char data_ov000_021b3850[];
extern char gNurResultKey[];
extern char gOthersResultKey[];
extern char gOdoneKey[];
extern char gOKey[];
extern char gOthersFirstKey[];
extern char gOthersLastKey[];
extern char gUsKey[];
extern char gUsdoneKey[];
extern char gSuggestedNickCountAssertion[];
extern char data_ov000_021b38c0[];
extern char data_ov000_021b38e8[];
extern char gResolveSearchHostErrorString[];
extern char data_ov000_021b394c[];
extern char data_ov000_021b396c[];
extern char gXferKey[];
extern char gTransferIdFormat[];

BOOL GpiUpdateSearches(GpConnection *connection);
s32 GpiUpdateSearch(GpConnection *connection, GpiOperation *operation);
int gpiProfileSearch(GpConnection *connection, s8 *nick, s8 *uniquenick, s8 *email, s8 *firstname, s8 *lastname,
                         int icquin, int skip, u32 blocking, u32 callback, u32 param);
int GpiStartSearchOperation(GpConnection *connection, u32 data, u32 blocking, u32 callback, u32 param);
BOOL GpiCreateSearch(GpConnection *connection, GPISearchData **searchData, u32 kind);
s32 GpiOpenSearchSocket(GpConnection *connection, GpiOperation *operation);
void gpiHandleTransferMessage(GpConnection *connection, GpiPeer *peer, s32 type, const char *headers, s32 buffer,
                              s32 len);
