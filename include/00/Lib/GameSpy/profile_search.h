#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"

// One profile found by a search: profile, nicks, names and email.
typedef struct ProfileMatch {
    /* 00 */ s32 mProfile;
    /* 04 */ char mNick[0x1f];
    /* 23 */ char mUniquenick[0x15];
    /* 38 */ char mFirstname[0x1f];
    /* 57 */ char mLastname[0x1f];
    /* 76 */ char mEmail[0x36];
} ProfileMatch;

// One player found by a search: profile, nick, status and status string.
typedef struct PlayerMatch {
    /* 000 */ s32 mProfile;
    /* 004 */ char mNick[0x20];
    /* 024 */ s32 mStatus;
    /* 028 */ char mStatusString[0x100];
} PlayerMatch;

// Objects gpiProcessSearch allocates and passes to gpiAddCallback.
typedef struct GpCheckNewUserResponseArg {
    /* 00 */ s32 mResult;
    /* 04 */ s32 mProfile;
} GpCheckNewUserResponseArg;

typedef struct OthersReply {
    /* 00 */ s32 mResult;
    /* 04 */ s32 mNumProfiles;
    /* 08 */ ProfileMatch *mProfiles;
} OthersReply;

typedef struct SuggestNickReply {
    /* 00 */ s32 mResult;
    /* 04 */ s32 mNumSuggestedNicks;
    /* 08 */ char **mSuggestedNicks;
} SuggestNickReply;

typedef struct PlayerMatchReply {
    /* 00 */ s32 mResult;
    /* 04 */ s32 mProductId;
    /* 08 */ s32 mNumMatches;
    /* 0c */ PlayerMatch *mMatches;
} PlayerMatchReply;

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

BOOL gpiProcessSearches(GPConnection *connection);
s32 gpiProcessSearch(GPConnection *connection, GPIOperation *operation);
int gpiProfileSearch(GPConnection *connection, s8 *nick, s8 *uniquenick, s8 *email, s8 *firstname, s8 *lastname,
                         int icquin, int skip, u32 blocking, GPCallback callback, u32 param);
int gpiStartSearch(GPConnection *connection, GPISearchData *data, u32 blocking, GPCallback callback,
                            u32 param);
BOOL gpiInitSearchData(GPConnection *connection, GPISearchData **searchData, u32 kind);
s32 gpiStartProfileSearch(GPConnection *connection, GPIOperation *operation);
void gpiHandleTransferMessage(GPConnection *connection, GPIPeer *peer, s32 type, const char *headers, s32 buffer,
                              s32 len);
