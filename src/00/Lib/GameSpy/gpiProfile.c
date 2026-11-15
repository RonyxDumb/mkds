#include "00/Lib/GameSpy/gpiProfile.h"
#include "code_02139f70.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/Lib/GameSpy/code_0218dd8c.h"
#include "00/code_02192d64.h"

s32 gpiCheckProfileForUser(GpConnection *connection, GpiProfile *profile, void *userData) {
    GPIFindProfileByUserData *data = userData;
    int difference;
    GPIInfoCache *cache;
    cache = profile->mCache;
    if (((cache != NULL) && (difference = strcmp(data->mNick, cache->mUnk_00[0]), difference == 0)) &&
        (difference = strcmp(data->mEmail, cache->mUnk_00[2]), difference == 0)) {
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
