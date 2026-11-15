#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_021947e4.h"

typedef struct GpiProfileSearch {
    /* 00 */ u32 mKey;
    /* 04 */ GpiProfile *mEntry;
} GpiProfileSearch;

typedef struct GpConnection GpConnection;

BOOL gpiCheckForBuddy(GpConnection *unused, GpiProfile *entry, void *data);

// Argument block of the walk over the list at 0x428: the object, the function to call and its argument.
// Called with the connection, the profile and the user data.
typedef s32 (*GpiProfileMapFunc)(GpConnection *connection, GpiProfile *profile, void *data);

typedef struct GPIProfileMapData {
    /* 00 */ GpConnection *mConnection;
    /* 04 */ GpiProfileMapFunc mFunc;
    /* 08 */ void *mData;
} GPIProfileMapData;

BOOL GpiForEachProfileWhileNonZero(GpConnection *gpConnection, GpiProfileMapFunc callback, void *userData);

void gpiProfileMapCallback(GpiProfile *profile, GPIProfileMapData *mapData);

typedef struct GpConnection GpConnection;

// Argument block of the search of gpiCheckProfileForUser.
typedef struct GPIFindProfileByUserData {
    /* 00 */ const char *mNick;
    /* 04 */ const char *mEmail;
    /* 08 */ GpiProfile **mProfile;
    /* 0c */ BOOL mFound;
} GPIFindProfileByUserData;

s32 gpiFindProfileByUser(GpConnection *connection, const char *nick, const char *email, GpiProfile **profile);

s32 gpiCheckProfileForUser(GpConnection *connection, GpiProfile *profile, void *data);
