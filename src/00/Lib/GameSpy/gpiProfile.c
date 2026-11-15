#include "00/Lib/GameSpy/gpiProfile.h"
#include "code_02139f70.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/Lib/GameSpy/code_0218dd8c.h"

u32 gpiCheckProfileForUser(u32 connection, int profile, GPIFindProfileByUserData *data) {
    int difference;
    u32 *cache;
    cache = *(u32 **) (profile + 0xc);
    if (((cache != NULL) && (difference = strcmp(data->mNick, (const char *) (*cache)), difference == 0)) &&
        (difference = strcmp(data->mEmail, (const char *) (cache[2])), difference == 0)) {
        *data->mProfile = (GpiProfile *) profile;
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

void gpiProfileMapCallback(u32 profile, u32 *mapData) {
    ((GpiProfileMapFunc) mapData[1])(*mapData, profile, mapData[2]);
}

BOOL GpiForEachProfileWhileNonZero(GpConnection *gpConnection, void *callback, void *userData) {
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

BOOL gpiCheckForBuddy(void *unused, GpiProfile *entry, GpiProfileSearch *search) {
    if (entry->mBuddyStatus != NULL && search->mKey == entry->mBuddyStatus->mIndex) {
        search->mEntry = entry;
        return FALSE;
    }
    return TRUE;
}
