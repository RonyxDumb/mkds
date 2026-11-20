#include "00/Lib/DWC/login_init.h"
#include "cpu_copy_fill.h"
#include "00/Lib/DWC/login_process.h"

// Returns mPendingStatsRequestCount of gWiFiBuddySync (no NULL test); DWCi_FriendProcess reports an error while this is
// nonzero and PersistThink returns FALSE.
u32 DWCi_GetPersCallbackLevel(void) {
    return gWiFiBuddySync->mPendingStatsRequestCount;
}

// Per login (called by DWC_InitFriendsMatch after the caller zeroed the connection; not once at boot): stores
// gWiFiLogin, zeroes it, sets the state to idle and stores the GP connection, product id, game code, user data and the
// callback pair. Pair of DWCi_ShutdownLogin.
void InitWiFiLogin(WiFiLogin *login, DWCAccUserData *userData, GPConnection *gpConnection, u32 productId, u32 gamecode,
                   void (*resultCallback)(), void *resultCallbackArg) {
    gWiFiLogin = login;
    MI_CpuFill8(login, 0, sizeof(WiFiLogin));
    gWiFiLogin->mGpConnection = gpConnection;
    gWiFiLogin->mState = WIFI_LOGIN_IDLE;
    gWiFiLogin->mProductId = productId;
    gWiFiLogin->mGamecode = gamecode;
    gWiFiLogin->mResultCallback = resultCallback;
    gWiFiLogin->mResultCallbackArg = resultCallbackArg;
    gWiFiLogin->mUserData = userData;
}
