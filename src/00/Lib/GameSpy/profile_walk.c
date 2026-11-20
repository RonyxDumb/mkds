#include "00/Lib/GameSpy/profile_walk.h"
#include "narrow_string_functions.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/GameSpy/hash_table.h"
#include "00/Lib/GameSpy/profile_info.h"

s32 gpiCheckProfileForUser(GPConnection *connection, GPIProfile *profile, void *userData) {
    GPIFindProfileByUserData *data = userData;
    int difference;
    GPIInfoCache *cache;
    cache = profile->mCache;
    if (((cache != NULL) && (difference = strcmp(data->mNick, cache->mNick), difference == 0)) &&
        (difference = strcmp(data->mEmail, cache->mEmail), difference == 0)) {
        *data->mProfile = profile;
        data->mFound = TRUE;
        return 0;
    }
    return 1;
}

s32 gpiFindProfileByUser(GPConnection *connection, const char *nick, const char *email, GPIProfile **profile) {
    GPIFindProfileByUserData data;

    data.mNick = nick;
    data.mEmail = email;
    data.mProfile = profile;
    data.mFound = FALSE;
    gpiProfileMap(connection, gpiCheckProfileForUser, &data);
    if (data.mFound == FALSE) {
        *profile = NULL;
    }
    return 0;
}

void gpiProfileMapCallback(GPIProfile *profile, GPIProfileMapData *mapData) {
    mapData->mFunc(mapData->mConnection, profile, mapData->mData);
}

BOOL gpiProfileMap(GPConnection *gpConnection, gpiProfileMapFunc callback, void *userData) {
    GPIConnection *gpiConnection;
    GPIProfileMapData mapData;

    gpiConnection = gpConnection->mGpiConnection;
    mapData.mConnection = gpConnection;
    mapData.mFunc = callback;
    mapData.mData = userData;
    if (TableMapSafe2(gpiConnection->mProfileList.mTable, (s32) gpiProfileMapCallback, &mapData) == NULL) {
        return TRUE;
    }
    return FALSE;
}

BOOL gpiCheckForBuddy(GPConnection *unused, GPIProfile *entry, void *data) {
    GpiProfileSearch *search = data;
    if (entry->mBuddyStatus != NULL && search->mKey == entry->mBuddyStatus->mIndex) {
        search->mEntry = entry;
        return FALSE;
    }
    return TRUE;
}
