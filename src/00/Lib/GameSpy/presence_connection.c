#include "00/Lib/GameSpy/presence_connection.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "scan_text_random.h"
#include "string.h"
#include "print_memory_functions.h"
#include "00/Lib/GameSpy/hash_table.h"
#include "00/Lib/GameSpy/login_connect_close.h"

u32 GpiInitialize(GpConnection *connection, s32 titleNumber, s32 spaceId) {
    GpConnection newConnection;
    u32 result;
    s32 callbackIndex;
    connection->mGpiConnection = NULL;
    newConnection.mGpiConnection = DWCi_GsMalloc(0x490);
    if (newConnection.mGpiConnection == NULL) {
        return 1;
    }
    memset(newConnection.mGpiConnection, 0, sizeof(*newConnection.mGpiConnection));
    newConnection.mGpiConnection->mErrorMessage[0] = 0;
    newConnection.mGpiConnection->mErrorNumber = 0;
    newConnection.mGpiConnection->mInfoCaching = 1;
    newConnection.mGpiConnection->mInfoCachingBuddyOnly = FALSE;
    newConnection.mGpiConnection->mSimulation = 0;
    newConnection.mGpiConnection->mFirewall = FALSE;
    newConnection.mGpiConnection->mProductId = titleNumber;
    newConnection.mGpiConnection->mNamespaceId = spaceId;
    if (GpiInitProfileList(&newConnection) == FALSE) {
        DWCi_GsFree(newConnection.mGpiConnection);
        newConnection.mGpiConnection = NULL;
        return 1;
    }
    newConnection.mGpiConnection->mDiskCache = 0;
    for (callbackIndex = 0; callbackIndex < 6; callbackIndex++) {
        newConnection.mGpiConnection->mCallbacks[callbackIndex].mCallback = NULL;
        newConnection.mGpiConnection->mCallbacks[callbackIndex].mParam = 0;
    }
    newConnection.mGpiConnection->mDebugBuffer = NULL;
    gpiDebug(&newConnection, "\n\n\n\n\n*************\ngpiInitialize\n");
    result = GpiResetConnection(&newConnection);
    if (result != 0) {
        gpiDestroy(&newConnection);
        return result;
    }
    SocketStartUp();
    srand(GetElapsedMilliseconds());
    connection->mGpiConnection = newConnection.mGpiConnection;
    return 0;
}

void gpiDestroy(GpConnection *connection) {
    GpiConnection *gpState;
    gpState = connection->mGpiConnection;
    GpiCloseConnection(connection, 1);
    DWCi_GsFree(gpState->mDebugBuffer);
    gpState->mDebugBuffer = NULL;
    HashtableDelete(gpState->mProfileList.mTable);
    DWCi_GsFree(gpState);
    connection->mGpiConnection = NULL;
}

s32 gpiResetProfile(GpConnection *connection, GpiProfile *profile, void *data) {
    u32 result;
    result = 0u;
    profile->mBuddyStatus = NULL;
    profile->mAuthSig = NULL;
    profile->mRequestCount = result;
    profile->mPeerSig = NULL;
    result = 1u;
    return result;
}
