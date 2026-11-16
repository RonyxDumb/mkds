#pragma once

#include "types.h"
#include "friend_data_account_fields.h"
#include "00/Lib/GameSpy/buddy_messages.h"

// Values of WiFiLogin.mState.
enum {
    WIFI_LOGIN_IDLE = 0,
    WIFI_LOGIN_WAIT_AUTH_REPLY = 1,
    WIFI_LOGIN_CONNECT_KNOWN_ID = 2,
    WIFI_LOGIN_CONNECT_NEW_ID = 3,
    WIFI_LOGIN_CHECK_NEW_ID_NAME = 4,
    WIFI_LOGIN_DONE = 5,
};

// The Wi-Fi login: gets the auth token over HTTP, then connects to the GP server and checks the profile (mState).
typedef struct WiFiLogin {
    /* 00 */ GPConnection *mGpConnection;
    // WIFI_LOGIN_*; set by InitWiFiLogin, DWCi_LoginAsync, DWCi_GPConnect (its target state), DWCi_GPConnectCallback,
    // DWCi_GPGetInfoCallback and DWCi_CloseLogin.
    /* 04 */ s32 mState;
    // Product id 0x4d6 (third parameter of DWC_InitFriendsMatch): given to gpInitialize, which stores it
    // as GPIConnection.mProductId and writes it after '\productid\'.
    /* 08 */ u32 mProductId;
    /* 0c */ u32 mGamecode;
    /* 10 */ u32 mPlayerName;
    /* 14 */ u32 mReserved;
    // Set by InitWiFiLogin (DWCi_LoginCallback). Called with (error kind, 0, arg) by DWCi_StopLogin and with (0,
    // profile id, arg) when state 2 succeeds.
    /* 18 */ void (*mResultCallback)();
    /* 1c */ void *mResultCallbackArg;
    /* 20 */ DWCAccUserData *mUserData;
    /* 24 */ u8 pad_24[4];
    // Http (0x1a60 bytes; declared void *) of the running request: made by DWCi_RemoteLogin, freed when the reply
    // or an error ends the request and by DWCi_ShutdownLogin.
    /* 28 */ void *mHttp;
    // u64 tick reading (OS_GetTick) taken when the HTTP request started; while the request is in an error state
    // DWCi_RemoteLoginProcess reports error 2 once (ticks << 6) / 0x82ea, the milliseconds since then, exceeds 10000,
    // and otherwise restarts the request.
    /* 2c */ u64 mRequestStartTick;
    // TRUE from DWCi_GPConnect until the GP connect callback or an error; DWCi_LoginProcess times the connect
    // out while it is TRUE.
    /* 34 */ BOOL mConnectPending;
    // OS_GetTick reading when the GP connect started; (ticks << 6) / 0x82ea is ms, limit 60000 ms (DWCi_LoginProcess).
    /* 38 */ u64 mConnectStartTime;
    /* 40 */ DWCAccFriendData mTempLoginId;
    // First string of the HTTP reply (0x100 buffer): given to the GP connect as its first credential, which
    // gpiSendLogin writes after '\authtoken\'; also passed to StartBuddySync (stats login).
    // The reply's second string (mPartnerChallenge) is the password substitute the library hashes, not
    // the library's '\challenge\' (a random string the library makes).
    /* 4c */ char mAuthToken[0x100];
    // Second string of the HTTP reply (0x100 buffer), the second GP connect credential: the library copies it to
    // GPIConnectData.mPartnerChallenge (when the token and this string are both non-empty) and gpiSendLogin hashes it
    // where it would hash the password. Not the library's '\challenge\' value.
    /* 14c */ char mPartnerChallenge[0x100];
    /* 24c */ char mUsername[9];
    /* 255 */ char mGsbrcd[0xf];
} WiFiLogin;

void DWCi_CloseLogin(void);
