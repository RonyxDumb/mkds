#include "00/Lib/GameSpy/profile_for_each.h"
#include "narrow_string_functions.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "print_memory_functions.h"
#include "00/Lib/GameSpy/hash_table.h"
#include "00/Lib/GameSpy/profile_info.h"

s32 gpiCheckProfileForUser(GpConnection *connection, GpiProfile *profile, void *userData) {
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

s32 gpiFindProfileByUser(GpConnection *connection, const char *nick, const char *email, GpiProfile **profile) {
    GPIFindProfileByUserData data;

    data.mNick = nick;
    data.mEmail = email;
    data.mProfile = profile;
    data.mFound = FALSE;
    GpiForEachProfileWhileNonZero(connection, gpiCheckProfileForUser, &data);
    if (data.mFound == FALSE) {
        *profile = NULL;
    }
    return 0;
}

void gpiProfileMapCallback(GpiProfile *profile, GPIProfileMapData *mapData) {
    mapData->mFunc(mapData->mConnection, profile, mapData->mData);
}

BOOL GpiForEachProfileWhileNonZero(GpConnection *gpConnection, GpiProfileMapFunc callback, void *userData) {
    GpiConnection *gpiConnection;
    GPIProfileMapData mapData;

    gpiConnection = gpConnection->mGpiConnection;
    mapData.mConnection = gpConnection;
    mapData.mFunc = callback;
    mapData.mData = userData;
    if (HashtableFindByFn(gpiConnection->mProfileList.mTable, (s32) gpiProfileMapCallback, &mapData) == NULL) {
        return TRUE;
    }
    return FALSE;
}

BOOL gpiCheckForBuddy(GpConnection *unused, GpiProfile *entry, void *data) {
    GpiProfileSearch *search = data;
    if (entry->mBuddyStatus != NULL && search->mKey == entry->mBuddyStatus->mIndex) {
        search->mEntry = entry;
        return FALSE;
    }
    return TRUE;
}
