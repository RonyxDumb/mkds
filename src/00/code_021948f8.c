#include "00/code_021948f8.h"
#include "00/code_02193634.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_021965a0.h"
#include "00/code_02196594.h"
#include "00/code_02194b9c.h"
#include "00/code_02194ba4.h"
#include "code_0213a460.h"
#include "00/code_02196590.h"
#include "00/code_021a3690.h"
#include "code_02134398.h"
#include "00/code_02196000.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "00/code_0218dd8c.h"
#include "00/code_021a3668.h"
#include "00/code_02190cd4.h"

void GpiReleaseProfile(GpiProfile *profile) {
    if (profile->mBuddyStatus != NULL) {
        DWCi_GsFree(profile->mBuddyStatus->mStatusString);
        profile->mBuddyStatus->mStatusString = NULL;
        DWCi_GsFree(profile->mBuddyStatus->mLocationString);
        profile->mBuddyStatus->mLocationString = NULL;
        DWCi_GsFree(profile->mBuddyStatus);
        profile->mBuddyStatus = NULL;
    }
    gpiFreeInfoCache(profile);
    DWCi_GsFree(profile->mAuthSig);
    profile->mAuthSig = NULL;
    DWCi_GsFree(profile->mPeerSig);
    profile->mPeerSig = NULL;
}

BOOL GpiInitProfileList(GpConnection *connection) {
    GpiConnection *gpState;

    gpState = connection->mGpiConnection;
    gpState->mBuddyCount = 0;
    gpState->mProfileList.mUnk_04 = 0;
    gpState->mProfileList.mTable = TableNew(0x1c, 4, GpiHashProfile, GpiCompareProfiles, GpiReleaseProfile);
    if (gpState->mProfileList.mTable != NULL) {
        return TRUE;
    }
    return FALSE;
}

s32 gpiProcessNewProfile(GpConnection *connection, GpiOperation *operation, const char *input) {
    GpiCallback callback;
    u32 *arg;
    s32 profileNumber;
    s32 result;
    char intValue[0x10];

    if (GpiReadError(connection, input, 1) != FALSE) {
        return 4;
    }
    if (strncmp(input, gNprKey, 5) != 0) {
        GpiSetError(connection, 1, data_ov000_021b356c);
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    if (GpiGetValue(input, data_ov000_021b359c, intValue, 0x10) == FALSE) {
        GpiSetError(connection, 1, data_ov000_021b356c);
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    profileNumber = StrtolBase10(intValue);
    callback = operation->mCallback;
    if (callback.mCallback != NULL) {
        arg = DWCi_GsMalloc(8);
        if (arg == NULL) {
            GpiSetErrorMessage(connection, data_ov000_021b35a8);
            return 1;
        }
        arg[1] = profileNumber;
        arg[0] = 0;
        result = GpiQueueCallback(connection, callback, arg, operation, 0);
        if (result != 0) {
            return result;
        }
    }
    GpiRemoveOperation(connection, operation);
    return 0;
}

GpiProfile *GpiFindOrAddProfile(GpConnection *connection, s32 id) {
    GPIProfileList *profileStore;
    GpiProfile *profileEntry;

    profileStore = &connection->mGpiConnection->mProfileList;
    if (id <= 0) {
        AssertionFailed(gIdPositiveAssertion, gGpiProfileFileName, NULL, 0x2b5);
    }
    if (id <= 0) {
        return NULL;
    }
    if (GpiFindProfile(connection, id, &profileEntry) != 0) {
        return profileEntry;
    }
    {
        GpiProfile newProfile = {0};

        newProfile.mProfileId = id;
        newProfile.mUserId = 0;
        newProfile.mCache = 0;
        newProfile.mAuthSig = NULL;
        newProfile.mPeerSig = NULL;
        newProfile.mRequestCount = 0;
        HashtableSet(profileStore->mTable, &newProfile);
    }
    profileStore->mUnk_04 = profileStore->mUnk_04 + 1;
    if (GpiFindProfile(connection, id, &profileEntry) != 0) {
        return profileEntry;
    }
    return NULL;
}

u32 GpiFindProfile(GpConnection *connection, u32 profileid, GpiProfile **profile) {
    GpiConnection *gpState;
    GpiProfile lookup;
    GpiProfile *foundProfile;

    gpState = connection->mGpiConnection;
    lookup.mProfileId = profileid;
    foundProfile = HashtableFind(gpState->mProfileList.mTable, &lookup);
    if (profile != NULL) {
        *profile = foundProfile;
    }
    if (foundProfile != NULL) {
        return 1;
    }
    return 0;
}

void GpiRemoveProfileById(GpConnection *connection, u32 profileid) {
    GpiConnection *gpState;
    GpiProfile *pProfile;

    gpState = connection->mGpiConnection;
    if (GpiFindProfile(connection, profileid, &pProfile) != 0) {
        HashtableRemove(gpState->mProfileList.mTable, pProfile);
    }
}

void GpiRemoveProfile(GpConnection *connection, GpiProfile *profile) {
    HashtableRemove(connection->mGpiConnection->mProfileList.mTable, profile);
}
