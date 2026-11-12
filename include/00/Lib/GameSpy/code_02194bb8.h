#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_0218f960.h"

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
    /* 000 */ s32 mProfile;
    /* 004 */ char mNick[0x20];
    /* 024 */ s32 mStatus;
    /* 028 */ char mStatusString[0x100];
} PlayerMatch;

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
    /* 00 */ s32 mResult;
    /* 04 */ char mEmail[0x34];
    /* 38 */ BOOL mIsValid;
} EmailCheckReply;

typedef struct UserNicksReply {
    /* 00 */ s32 mResult;
    /* 04 */ char mEmail[0x34];
    /* 38 */ s32 mNumNicks;
    /* 3c */ char **mNicks;
    /* 40 */ char **mUniquenicks;
} UserNicksReply;

BOOL GpiUpdateSearches(GpConnection *connection);
s32 GpiUpdateSearch(GpConnection *connection, GpiOperation *operation);
int gpiProfileSearch(GpConnection *connection, s8 *nick, s8 *uniquenick, s8 *email, s8 *firstname, s8 *lastname,
                         int icquin, int skip, u32 blocking, u32 callback, u32 param);
int GpiStartSearchOperation(GpConnection *connection, u32 data, u32 blocking, u32 callback, u32 param);
BOOL GpiCreateSearch(GpConnection *connection, GPISearchData **searchData, u32 kind);
s32 GpiOpenSearchSocket(GpConnection *connection, GpiOperation *operation);
void gpiHandleTransferMessage(GpConnection *connection, GpiPeer *peer, s32 type, const char *headers, s32 buffer,
                              s32 len);
