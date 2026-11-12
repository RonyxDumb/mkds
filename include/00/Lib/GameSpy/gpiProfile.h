#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_021947e4.h"

typedef struct GpiProfileSearch {
    /* 00 */ u32 mKey;
    /* 04 */ GpiProfile *mEntry;
} GpiProfileSearch;

BOOL gpiCheckForBuddy(void *unused, GpiProfile *entry, GpiProfileSearch *search);

typedef struct GpConnection GpConnection;

// Argument block of the walk over the list at 0x428: the object, the function to call and its argument.
typedef struct GPIProfileMapData {
    /* 00 */ GpConnection *mConnection;
    /* 04 */ void *mFunc;
    /* 08 */ void *mData;
} GPIProfileMapData;

BOOL GpiForEachProfileWhileNonZero(GpConnection *a, void *b, void *c);

void gpiProfileMapCallback(u32 profile, u32 *mapData);

typedef struct GpConnection GpConnection;

// Argument block of the search of gpiCheckProfileForUser.
typedef struct GPIFindProfileByUserData {
    /* 00 */ const char *mNick;
    /* 04 */ const char *mEmail;
    /* 08 */ void **mProfile;
    /* 0c */ BOOL mFound;
} GPIFindProfileByUserData;

s32 gpiFindProfileByUser(GpConnection *connection, const char *nick, const char *email, void **profile);

u32 gpiCheckProfileForUser(u32 connection, int profile, GPIFindProfileByUserData *data);
