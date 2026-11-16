#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/DWC/matching_result_codes.h"
#include "00/Lib/GameSpy/operation_queue.h"
#include "narrow_string_functions.h"
#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/GameSpy/profile_compare.h"
#include "00/Lib/GameSpy/profile_hash.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "00/Lib/GameSpy/hash_table.h"
#include "00/Lib/GameSpy/callback_queue.h"

void gpiProfilesTableFree(GPIProfile *profile) {
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

BOOL gpiInitProfiles(GPConnection *connection) {
    GPIConnection *gpState;

    gpState = connection->mGpiConnection;
    gpState->mBuddyCount = 0;
    gpState->mProfileList.mNum = 0;
    gpState->mProfileList.mTable = TableNew(0x1c, 4, gpiProfilesTableHash, gpiProfilesTableCompare, gpiProfilesTableFree);
    if (gpState->mProfileList.mTable != NULL) {
        return TRUE;
    }
    return FALSE;
}

s32 gpiProcessNewProfile(GPConnection *connection, GPIOperation *operation, const char *input) {
    GPICallback callback;
    u32 *arg;
    s32 profileNumber;
    s32 result;
    char profileIdText[0x10];

    if (gpiCheckForError(connection, input, 1) != FALSE) {
        return 4;
    }
    if (strncmp(input, "\\npr\\", 5) != 0) {
        gpiSetError(connection, 1, "Unexpected data was received from the server.");
        gpiCallErrorCallback(connection, PROFILE_RESULT_NETWORK_ERROR, 1);
        return PROFILE_RESULT_NETWORK_ERROR;
    }
    if (gpiValueForKey(input, "\\profileid\\", profileIdText, 0x10) == FALSE) {
        gpiSetError(connection, 1, "Unexpected data was received from the server.");
        gpiCallErrorCallback(connection, PROFILE_RESULT_NETWORK_ERROR, 1);
        return PROFILE_RESULT_NETWORK_ERROR;
    }
    profileNumber = StrtolBase10(profileIdText);
    callback = operation->mCallback;
    if (callback.mCallback != NULL) {
        arg = DWCi_GsMalloc(8);
        if (arg == NULL) {
            gpiSetErrorString(connection, "Out of memory.");
            return PROFILE_RESULT_OUT_OF_MEMORY;
        }
        arg[1] = profileNumber;
        arg[0] = 0;
        result = gpiAddCallback(connection, callback, arg, operation, PROFILE_CALLBACK_TYPE_PLAIN);
        if (result != 0) {
            return result;
        }
    }
    gpiRemoveOperation(connection, operation);
    return 0;
}

GPIProfile *gpiProfileListAdd(GPConnection *connection, s32 id) {
    GPIProfileList *profileList;
    GPIProfile *profileEntry;

    profileList = &connection->mGpiConnection->mProfileList;
    if (id <= 0) {
        AssertionFailed("id > 0", "gpiProfile.c", NULL, 0x2b5);
    }
    if (id <= 0) {
        return NULL;
    }
    if (gpiGetProfile(connection, id, &profileEntry) != 0) {
        return profileEntry;
    }
    {
        GPIProfile newProfile = {0};

        newProfile.mProfileId = id;
        newProfile.mUserId = 0;
        newProfile.mCache = 0;
        newProfile.mAuthSig = NULL;
        newProfile.mPeerSig = NULL;
        newProfile.mRequestCount = 0;
        TableEnter(profileList->mTable, &newProfile);
    }
    profileList->mNum = profileList->mNum + 1;
    if (gpiGetProfile(connection, id, &profileEntry) != 0) {
        return profileEntry;
    }
    return NULL;
}

u32 gpiGetProfile(GPConnection *connection, u32 profileid, GPIProfile **profile) {
    GPIConnection *gpState;
    GPIProfile lookup;
    GPIProfile *foundProfile;

    gpState = connection->mGpiConnection;
    lookup.mProfileId = profileid;
    foundProfile = TableLookup(gpState->mProfileList.mTable, &lookup);
    if (profile != NULL) {
        *profile = foundProfile;
    }
    if (foundProfile != NULL) {
        return 1;
    }
    return 0;
}

void gpiRemoveProfileByID(GPConnection *connection, u32 profileid) {
    GPIConnection *gpState;
    GPIProfile *pProfile;

    gpState = connection->mGpiConnection;
    if (gpiGetProfile(connection, profileid, &pProfile) != 0) {
        TableRemove(gpState->mProfileList.mTable, pProfile);
    }
}

void gpiRemoveProfile(GPConnection *connection, GPIProfile *profile) {
    TableRemove(connection->mGpiConnection->mProfileList.mTable, profile);
}
