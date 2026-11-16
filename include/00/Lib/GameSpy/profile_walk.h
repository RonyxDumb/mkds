#pragma once

#include "types.h"
#include "00/Lib/GameSpy/profile_empty_check.h"

typedef struct GpiProfileSearch {
    /* 00 */ u32 mKey;
    /* 04 */ GPIProfile *mEntry;
} GpiProfileSearch;

typedef struct GPConnection GPConnection;

BOOL gpiCheckForBuddy(GPConnection *unused, GPIProfile *entry, void *data);

// Argument block of the walk over the list at 0x428: the object, the function to call and its argument.
// Called with the connection, the profile and the user data.
typedef s32 (*gpiProfileMapFunc)(GPConnection *connection, GPIProfile *profile, void *data);

typedef struct GPIProfileMapData {
    /* 00 */ GPConnection *mConnection;
    /* 04 */ gpiProfileMapFunc mFunc;
    /* 08 */ void *mData;
} GPIProfileMapData;

BOOL gpiProfileMap(GPConnection *gpConnection, gpiProfileMapFunc callback, void *userData);

void gpiProfileMapCallback(GPIProfile *profile, GPIProfileMapData *mapData);

typedef struct GPConnection GPConnection;

// Argument block of the search of gpiCheckProfileForUser.
typedef struct GPIFindProfileByUserData {
    /* 00 */ const char *mNick;
    /* 04 */ const char *mEmail;
    /* 08 */ GPIProfile **mProfile;
    /* 0c */ BOOL mFound;
} GPIFindProfileByUserData;

s32 gpiFindProfileByUser(GPConnection *connection, const char *nick, const char *email, GPIProfile **profile);

s32 gpiCheckProfileForUser(GPConnection *connection, GPIProfile *profile, void *data);
